#!/usr/bin/env python3
"""Regenerate all ShinyGold map/layout/tileset/heal-location sources into a pokefirered worktree.

usage: python3 generate.py WORKTREE [--temp-scripts]

  --temp-scripts   also (re)create the TEMPORARY scaffolding that lets the tree build before the scripts
                   worker's per-map scripts exist: data/maps_temp/map_scripts_stubs.inc (stub *_MapScripts for
                   new map names), include/constants/maps_temp.h (MAPSEC names, vanilla LOCALID_/MAP_/LAYOUT_/
                   HEAL_LOCATION_ names used only by the vanilla per-map scripts) and the include lines for them in
                   data/event_scripts.s / data/maps.s.

Idempotent: tileset headers are rebuilt from the pristine vanilla sources in /home/claude/vanilla.
"""
import sys, os, re, json, shutil, glob, struct, collections, subprocess
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import sgmaps
from sgmaps import names, VANILLA_DIR, lz77_decompress, symaddr, symsize

TEMP_TAG = 'TEMPORARY (maps worker)'


def wjson(path, obj):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    s = json.dumps(obj, indent=2, ensure_ascii=False) + '\n'
    if os.path.exists(path) and open(path, encoding='utf-8').read() == s: return
    open(path, 'w', encoding='utf-8').write(s)


def wbin(path, data):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    if os.path.exists(path) and open(path, 'rb').read() == data: return
    open(path, 'wb').write(data)


def wtext(path, s):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    if os.path.exists(path) and open(path).read() == s: return
    open(path, 'w').write(s)


# ------------------------------------------------------------------------------------------------ maps
def gen_maps(W, D):
    mg, vmaps = sgmaps.vanilla_maps()
    new_names = set(M.name for M in D['maps'])
    # remove map.json of vanilla maps that are no longer maps (scripts.inc/text.inc are left for the scripts
    # worker, who replaces them; MAP_DIRS only picks up directories containing a map.json)
    for p in glob.glob(os.path.join(W, 'data/maps/*/map.json')):
        nm = os.path.basename(os.path.dirname(p))
        if nm not in new_names:
            os.remove(p)
            for g in ('header.inc', 'events.inc', 'connections.inc'):
                q = os.path.join(os.path.dirname(p), g)
                if os.path.exists(q): os.remove(q)
            d = os.path.dirname(p)
            if not os.listdir(d): os.rmdir(d)
    for M in D['maps']:
        wjson(os.path.join(W, 'data/maps', M.name, 'map.json'), M.json)
    groups = collections.OrderedDict()
    groups['group_order'] = list(mg['group_order'])
    assert len(D['groups']) == len(mg['group_order'])
    for gi, gname in enumerate(mg['group_order']):
        ms = sorted([M for M in D['maps'] if M.group == gi], key=lambda M: M.num)
        assert [M.num for M in ms] == list(range(len(ms)))
        groups[gname] = [M.name for M in ms]
    wjson(os.path.join(W, 'data/maps/map_groups.json'), groups)


# ------------------------------------------------------------------------------------------------ layouts
def gen_layouts(W, D):
    lays = D['layouts']
    keep = set(L.dir for L in lays.values() if L)
    for d in glob.glob(os.path.join(W, 'data/layouts/*/')):
        if os.path.basename(d.rstrip('/')) not in keep:
            shutil.rmtree(d)
    out = []
    for lid in range(1, max(lays) + 1):
        L = lays.get(lid)
        if L is None:
            out.append({})
            continue
        base = 'data/layouts/%s/' % L.dir
        wbin(os.path.join(W, base + 'map.bin'), L.blockdata)
        wbin(os.path.join(W, base + 'border.bin'), L.border)
        e = collections.OrderedDict()
        e['id'] = L.const
        e['name'] = L.label
        e['width'] = L.width
        e['height'] = L.height
        e['border_width'] = L.bw
        e['border_height'] = L.bh
        e['primary_tileset'] = L.primary
        e['secondary_tileset'] = L.secondary
        e['border_filepath'] = base + 'border.bin'
        e['blockdata_filepath'] = base + 'map.bin'
        out.append(e)
    wjson(os.path.join(W, 'data/layouts/layouts.json'),
          collections.OrderedDict([('layouts_table_label', 'gMapLayouts'), ('layouts', out)]))


# ------------------------------------------------------------------------------------------------ tilesets
GRAY = [c for i in range(16) for c in (255 - 17 * i,) * 3]


def write_tiles_png(path, data):
    from PIL import Image
    n = len(data) // 32
    rows = (n + 15) // 16
    w, h = 128, rows * 8
    px = bytearray(w * h)
    for t in range(n):
        tx, ty = (t % 16) * 8, (t // 16) * 8
        for y in range(8):
            for x in range(4):
                b = data[32 * t + 4 * y + x]
                px[(ty + y) * w + tx + 2 * x] = b & 0xF
                px[(ty + y) * w + tx + 2 * x + 1] = b >> 4
    im = Image.frombytes('P', (w, h), bytes(px))
    im.putpalette(GRAY)
    os.makedirs(os.path.dirname(path), exist_ok=True)
    tmp = path + '.tmp.png'
    im.save(tmp, bits=4, optimize=False)
    if os.path.exists(path):
        old = Image.open(path)
        if old.mode == 'P' and old.size == im.size and old.tobytes() == im.tobytes():
            os.remove(tmp); return False
    os.replace(tmp, path)
    return True


def pal_text(data):
    lines = ['JASC-PAL', '0100', '16']
    for i in range(16):
        c = struct.unpack_from('<H', data, 2 * i)[0]
        r, g, b = c & 31, (c >> 5) & 31, (c >> 10) & 31
        lines.append('%d %d %d' % (r * 255 // 31, g * 255 // 31, b * 255 // 31))
    return '\r\n'.join(lines) + '\r\n'


def gen_tilesets(W, D):
    v = D['vrom']
    changed = collections.defaultdict(list)
    structs, vtiles, vpals, vmt = sgmaps.vanilla_tileset_sources()
    rules = {}       # tiles 4bpp path -> num_tiles
    new_defs = []    # new graphics.h definitions
    tiles_path_override = {}   # symbol -> new INCBIN path
    for T in D['tilesets']:
        # --- tiles
        if T.tiles_repointed:
            pngp = os.path.join(W, T.tiles_path[:-len('.4bpp')] + '.png')
            write_tiles_png(pngp, T.tiles_data)
            changed['tiles_repointed'].append(T.name)
            rules[T.tiles_path] = T.num_tiles
            if T.tiles_sym in vtiles:
                tiles_path_override[T.tiles_sym] = T.tiles_path
            else:
                new_defs.append('// ShinyGold: %s got its own (uncompressed) tiles; vanilla shared %s\n'
                                'const u32 %s[] = INCBIN_U32("%s");\n' % (T.name, T.van['tiles'], T.tiles_sym, T.tiles_path))
        elif not T.tiles_fixed:
            vpath = vtiles[T.tiles_sym][0]
            voff = symaddr(T.tiles_sym)
            vdata = lz77_decompress(v.d, voff)[0] if T.tiles_compressed else v.d[voff:voff + symsize(T.tiles_sym)]
            if vdata != T.tiles_data:
                base = vpath[:-len('.4bpp.lz')] if vpath.endswith('.lz') else vpath[:-len('.4bpp')]
                write_tiles_png(os.path.join(W, base + '.png'), T.tiles_data)
                rules[base + '.4bpp'] = T.num_tiles
                changed['tiles_inplace'].append(T.name)
        # --- palettes
        voff = symaddr(T.pal_sym)
        for i in range(16):
            hp = T.pal_data[32 * i:32 * i + 32]
            if hp != v.d[voff + 32 * i:voff + 32 * i + 32]:
                wtext(os.path.join(W, T.pal_dir, 'palettes/%02d.pal' % i), pal_text(hp))
                changed['palettes'].append('%s/%02d' % (T.pal_sym, i))
        # --- metatiles / attributes
        for sym, path, data in ((T.mt_sym, T.mt_path, T.mt_data), (T.attr_sym, T.attr_path, T.attr_data)):
            voff = symaddr(sym)
            if data != v.d[voff:voff + symsize(sym)]:
                wbin(os.path.join(W, path), data)
                changed['metatiles'].append(sym)
    changed['palettes'] = sorted(set(changed['palettes']))
    changed['metatiles'] = sorted(set(changed['metatiles']))

    # headers.h: rebuilt from vanilla with the hack's isCompressed / tiles symbol
    hdr = open(os.path.join(VANILLA_DIR, 'src/data/tilesets/headers.h')).read()
    byname = {T.name: T for T in D['tilesets']}

    def fix_struct(m):
        T = byname[m.group(1)]
        body = m.group(2)
        comp = 'TRUE' if T.tiles_compressed else 'FALSE'
        if comp != ('TRUE' if T.van_isCompressed else 'FALSE') or T.tiles_sym != T.van['tiles']:
            body = re.sub(r'\.isCompressed = \w+,', '.isCompressed = %s, // ShinyGold: tiles repointed to uncompressed data' % comp, body)
        body = re.sub(r'\.tiles = \w+,', '.tiles = %s,' % T.tiles_sym, body)
        return 'const struct Tileset %s =\n{%s};' % (m.group(1), body)
    hdr = re.sub(r'const struct Tileset (gTileset_\w+) =\n\{(.*?)\};', fix_struct, hdr, flags=re.S)
    wtext(os.path.join(W, 'src/data/tilesets/headers.h'), hdr)

    # graphics.h: rebuilt from vanilla with new INCBIN paths and new symbols
    gh = open(os.path.join(VANILLA_DIR, 'src/data/tilesets/graphics.h')).read()
    gc_path = os.path.join(W, 'src/graphics.c')
    gc = open(gc_path).read()
    for sym, path in tiles_path_override.items():
        pat = r'(const u32 %s\[\] = INCBIN_U32\(")[^"]+("\);)' % sym
        if re.search(pat, gh):
            gh = re.sub(pat, r'\g<1>%s\g<2>' % path, gh)
        else:
            assert re.search(pat, gc), sym
            gc = re.sub(pat, r'\g<1>%s\g<2>' % path, gc)
    if new_defs:
        gh = gh.rstrip('\n') + '\n\n' + '\n'.join(new_defs)
    wtext(os.path.join(W, 'src/data/tilesets/graphics.h'), gh)
    wtext(gc_path, gc)

    # tileset_rules.mk: num_tiles for every tiles.4bpp whose content we wrote
    mk_path = os.path.join(W, 'tileset_rules.mk')
    mk = open(os.path.join(VANILLA_DIR, 'tileset_rules.mk')).read()
    for path, n in sorted(rules.items()):
        rel = path[len('data/tilesets/'):]
        pat = r'(\$\(TILESETGFXDIR\)/%s: %%\.4bpp: %%\.png\n\t\$\(GFX\) \$< \$@ -num_tiles )(\d+)( -Wnum_tiles)' % re.escape(rel)
        if re.search(pat, mk):
            mk = re.sub(pat, r'\g<1>%d\g<3>' % n, mk)
        else:
            mk = mk.rstrip('\n') + '\n\n$(TILESETGFXDIR)/%s: %%.4bpp: %%.png\n\t$(GFX) $< $@ -num_tiles %d -Wnum_tiles\n' % (rel, n)
    wtext(mk_path, mk)
    return changed


# ------------------------------------------------------------------------------------------------ heal locations
def gen_heal(W, D):
    j = collections.OrderedDict([('heal_locations', [h['json'] for h in D['heals']])])
    wjson(os.path.join(W, 'src/data/heal_locations.json'), j)


# ------------------------------------------------------------------------------------------------ compat headers
SCAN_EXCLUDE = {'include/constants/map_groups.h', 'include/constants/layouts.h', 'include/constants/map_event_ids.h',
                'include/constants/map_compat.h', 'include/constants/maps_temp.h', 'include/constants/heal_locations.h',
                'src/data/heal_locations.h', 'src/data/heal_locations.json'}


def git_ignored(W):
    r = subprocess.run(['git', '-C', W, 'ls-files', '--others', '--ignored', '--exclude-standard'], capture_output=True, text=True)
    return set(r.stdout.split('\n'))


def scan_tokens(W, roots, exts, exclude=SCAN_EXCLUDE):
    """MAP_/LAYOUT_/HEAL_LOCATION_/LOCALID_ tokens per file (skipping generated, git-ignored files)."""
    ign = git_ignored(W)
    toks = collections.defaultdict(set)
    for root in roots:
        base = os.path.join(W, root)
        files = [base] if os.path.isfile(base) else [os.path.join(dp, f) for dp, dn, fn in os.walk(base) for f in fn]
        for p in files:
            rel = os.path.relpath(p, W)
            if rel in exclude or rel in ign or not p.endswith(exts): continue
            s = open(p, errors='replace').read()
            for t in set(re.findall(r'\b(?:MAP|LAYOUT|HEAL_LOCATION|LOCALID)_[A-Z0-9_]+\b', s)):
                toks[t].add(rel)
    return toks


def vanilla_name_tables():
    mg, vmaps = sgmaps.vanilla_maps()
    vmap = {j['id']: gn for gn, (n, j) in vmaps.items()}
    vlay = {}
    for i, l in enumerate(json.load(open(os.path.join(VANILLA_DIR, 'data/layouts/layouts.json')))['layouts']):
        if l: vlay[l['id']] = i + 1
    vheal = {}
    for i, h in enumerate(json.load(open(os.path.join(VANILLA_DIR, 'src/data/heal_locations.json')))['heal_locations']):
        vheal[h['id']] = i + 1
    vloc = {}
    for gn, (n, j) in vmaps.items():
        for i, o in enumerate(j['object_events']):
            if o.get('local_id'): vloc[o['local_id']] = i + 1
        for i, w in enumerate(j['warp_events']):
            if w.get('warp_id'): vloc[w['warp_id']] = i
    return vmap, vlay, vheal, vloc


def alias_defs(tokens, D, already=set()):
    """-> (lines, conflicts, unknown)"""
    vmap, vlay, vheal, vloc = vanilla_name_tables()
    new_map = set(M.id for M in D['maps']) | {'MAP_DYNAMIC', 'MAP_UNDEFINED', 'MAP_GROUPS_COUNT'}
    new_lay = set(L.const for L in D['layouts'].values() if L)
    new_heal = set(h['json']['id'] for h in D['heals']) | {'HEAL_LOCATION_NONE', 'NUM_HEAL_LOCATIONS'}
    lines, conflicts, unknown = collections.OrderedDict(), [], []
    for t in sorted(tokens):
        if t in already: continue
        if t in vmap:
            g, n = vmap[t]
            new = names.map_const(g, n)
            if new == t: continue
            if t in new_map: conflicts.append((t, '%d.%d' % (g, n), new)); continue
            lines[t] = new
        elif t in vlay:
            new = names.layout_const(vlay[t])
            if new == t: continue
            if t in new_lay: conflicts.append((t, vlay[t], new)); continue
            lines[t] = new
        elif t in vheal:
            new = names.heal_location_const(vheal[t])
            if new == t: continue
            if t in new_heal: conflicts.append((t, vheal[t], new)); continue
            lines[t] = new
        elif t.startswith('LOCALID_'):
            continue
        elif t in new_map or t in new_lay or t in new_heal:
            continue
        else:
            unknown.append(t)
    return lines, conflicts, unknown


def gen_compat(W, D):
    toks = scan_tokens(W, ['src', 'include', 'data/scripts', 'asm'], ('.c', '.h', '.inc', '.s', '.json', '.txt'))
    for f in glob.glob(os.path.join(W, 'data/*.s')) + glob.glob(os.path.join(W, 'data/*.inc')):
        for t, fs in scan_tokens(W, [os.path.relpath(f, W)], ('.s', '.inc')).items(): toks[t] |= fs
    lines, conflicts, unknown = alias_defs(toks, D)
    out = ['#ifndef GUARD_CONSTANTS_MAP_COMPAT_H', '#define GUARD_CONSTANTS_MAP_COMPAT_H', '',
           '// ShinyGold: compatibility aliases (generated by the maps worker, gen/generate.py).',
           '// The hack keeps vanilla map group/num numbering but its maps have new names.  Engine code, shared',
           '// scripts and data that still use a vanilla MAP_/LAYOUT_/HEAL_LOCATION_ name get the map/layout/heal',
           '// location with the SAME group/num (resp. id) as in vanilla FireRed, so behavior is unchanged.', '']
    sect = {'MAP_': 'Maps (same group/num)', 'LAYOUT_': 'Layouts (same layout id)', 'HEAL_LOCATION_': 'Heal locations (same id)'}
    for pre, title in sect.items():
        out.append('// %s' % title)
        for t, new in lines.items():
            if t.startswith(pre):
                out.append('#define %-48s %s' % (t, new))
        out.append('')
    out.append('// Object local ids that engine code special-cases (the vanilla object is gone from the hack map, the value is kept)')
    for nm, (val, why) in sorted(D['localid_compat'].items()):
        out.append('#define %-48s %d // %s' % (nm, val, why))
    out += ['', '#endif // GUARD_CONSTANTS_MAP_COMPAT_H', '']
    wtext(os.path.join(W, 'include/constants/map_compat.h'), '\n'.join(out))
    conflict_refs = {c[0]: sorted(toks[c[0]]) for c in conflicts}
    return lines, conflicts, conflict_refs, unknown


def gen_temp(W, D, compat_lines):
    """TEMPORARY scaffolding so the tree builds with the vanilla per-map scripts still in place."""
    # stub map scripts for map names without a scripts.inc defining <Name>_MapScripts
    es = os.path.join(W, 'data/event_scripts.s')
    s = open(es).read()
    included = set(re.findall(r'\.include "data/maps/(\w+)/scripts\.inc"', s))
    stubs = [M.name for M in D['maps'] if M.name not in included]
    st = ['@ %s: stub map script headers for maps whose real scripts the scripts worker generates.' % TEMP_TAG,
          '@ Delete this file (and its .include in data/event_scripts.s) at integration.', '']
    for n in stubs:
        st.append('%s_MapScripts::\n\t.byte 0\n' % n)
    wtext(os.path.join(W, 'data/maps_temp/map_scripts_stubs.inc'), '\n'.join(st))
    # constants used only by the vanilla per-map scripts
    toks = scan_tokens(W, ['data/maps'], ('.inc',), exclude=set())
    lines, conflicts, unknown = alias_defs(toks, D, already=set(compat_lines))
    vmap, vlay, vheal, vloc = vanilla_name_tables()
    defined_loc = set(D['localid_compat'])
    for M in D['maps']:
        for o in M.json['object_events']:
            if o.get('local_id'): defined_loc.add(o['local_id'])
    out = ['#ifndef GUARD_CONSTANTS_MAPS_TEMP_H', '#define GUARD_CONSTANTS_MAPS_TEMP_H', '',
           '// %s: lets the tree build before the scripts worker\'s output exists.' % TEMP_TAG,
           '// Delete this header and its #include lines (data/event_scripts.s, data/maps.s) at integration.', '']
    out.append('// Region map sections named after the hack (names.mapsec_const) that the vanilla enum lacks')
    van_secs = [e['id'] for e in json.load(open(os.path.join(W, 'src/data/region_map/region_map_sections.json')))['map_sections']]
    for val in range(0, 0xC5):
        nm = names.mapsec_const(val)
        if nm not in van_secs and not nm.startswith('0x'):
            out.append('#define %-40s 0x%02X' % (nm, val))
    out.append('')
    out.append('// Vanilla names used only by the vanilla per-map scripts')
    for t, new in lines.items():
        out.append('#define %-48s %s' % (t, new))
    out.append('')
    out.append('// Vanilla object/warp local ids used by the vanilla scripts')
    for nm, val in sorted(vloc.items()):
        if nm in defined_loc: continue
        out.append('#define %-48s %d' % (nm, val))
    out += ['', '#endif // GUARD_CONSTANTS_MAPS_TEMP_H', '']
    wtext(os.path.join(W, 'include/constants/maps_temp.h'), '\n'.join(out))
    # include lines
    inc = '#include "constants/maps_temp.h" // %s\n' % TEMP_TAG
    if 'maps_temp.h' not in s:
        s = s.replace('#include "constants/mystery_gift.h"\n', '#include "constants/mystery_gift.h"\n' + inc)
    if 'maps_temp/map_scripts_stubs.inc' not in s:
        s = s.replace('gStdScriptsEnd::\n', 'gStdScriptsEnd::\n\n\t.include "data/maps_temp/map_scripts_stubs.inc" @ %s\n' % TEMP_TAG, 1)
    open(es, 'w').write(s)
    ms = os.path.join(W, 'data/maps.s')
    s = open(ms).read()
    if 'maps_temp.h' not in s:
        s = s.replace('#include "constants/region_map_sections.h"\n', '#include "constants/region_map_sections.h"\n' + inc)
        open(ms, 'w').write(s)
    return stubs, conflicts, unknown


def ensure_code_hooks(W):
    """One-time source edits this data depends on (they live on the maps branch; re-applied idempotently)."""
    mj = open(os.path.join(W, 'tools/mapjson/mapjson.cpp')).read()
    mi = open(os.path.join(W, 'asm/macros/map.inc')).read()
    missing = []
    if 'explicit_local_id' not in mj: missing.append('tools/mapjson/mapjson.cpp: explicit_local_id support')
    if 'event_flag=0' not in mi: missing.append('asm/macros/map.inc: clone_event event_flag argument')
    if 'connection_none' not in mi: missing.append('asm/macros/map.inc: connection_none')
    if missing:
        sys.exit('missing code changes from the maps branch:\n  ' + '\n  '.join(missing))
    hooks = [('include/constants/maps.h', '#include "constants/map_types.h"\n',
              '#include "constants/map_compat.h"\n'),
             ('src/data/heal_locations.constants.json.txt', None,
              '// ShinyGold: vanilla HEAL_LOCATION_ name aliases\n#include "constants/map_compat.h"\n\n'),
             ('src/trainer_tower.c', '#include "constants/layouts.h"\n',
              '#include "constants/maps.h" // ShinyGold: vanilla LAYOUT_ name aliases (constants/map_compat.h)\n')]
    for f, after, line in hooks:
        p = os.path.join(W, f)
        s = open(p).read()
        if 'map_compat.h' in s or (f.endswith('trainer_tower.c') and 'constants/maps.h' in s): continue
        if after is None:
            s = s.replace('#endif // GUARD_CONSTANTS_HEAL_LOCATIONS_H', line + '#endif // GUARD_CONSTANTS_HEAL_LOCATIONS_H')
        else:
            assert after in s, f
            s = s.replace(after, after + line, 1)
        open(p, 'w').write(s)


def fix_conflicts(W, conflicts, refs):
    """Vanilla MAP_ names that now name a DIFFERENT map (e.g. MAP_PALLET_TOWN is the hack's 3.12) cannot be
    aliased; rewrite C references to the map at the vanilla group/num.  JSON data files are only reported."""
    rep = {c[0]: c[2] for c in conflicts}
    done, left = [], []
    for name, files in refs.items():
        for f in files:
            if not f.endswith(('.c', '.h')):
                left.append((name, f)); continue
            p = os.path.join(W, f)
            lines = open(p).read().split('\n')
            for i, l in enumerate(lines):
                hit = [k for k in rep if re.search(r'\b%s\b' % k, l)]
                if hit:
                    for k in hit: l = re.sub(r'\b%s\b' % k, rep[k], l)
                    # (the comment must not contain the vanilla token itself, so re-running stays idempotent)
                    lines[i] = l + ' // ShinyGold: same group/num as vanilla %s' % '/'.join(h[4:] for h in hit)
            open(p, 'w').write('\n'.join(lines))
            done.append((name, f))
    return done, left


def main():
    W = os.path.abspath(sys.argv[1])
    temp = '--temp-scripts' in sys.argv
    ensure_code_hooks(W)
    D = sgmaps.load_all()
    gen_maps(W, D)
    gen_layouts(W, D)
    changed = gen_tilesets(W, D)
    gen_heal(W, D)
    lines, conflicts, conflict_refs, unknown = gen_compat(W, D)
    renamed, unrenamed = fix_conflicts(W, conflicts, conflict_refs)
    summary = dict(renamed_conflicts=renamed, unrenamed_conflicts=unrenamed, maps=len(D['maps']), layouts=sum(1 for l in D['layouts'].values() if l),
                   tileset_changes={k: v for k, v in changed.items()}, compat_aliases=len(lines),
                   compat_conflicts=conflicts, conflict_refs=conflict_refs, compat_unknown=unknown)
    if temp:
        stubs, tconf, tunk = gen_temp(W, D, lines)
        summary.update(temp_stubs=len(stubs), temp_conflicts=tconf, temp_unknown=tunk)
    json.dump(summary, open('/home/claude/work/maps/gen_summary.json', 'w'), indent=1)
    # machine-readable notes for the report / other workers
    van_secs = set(e['id'] for e in json.load(open(os.path.join(VANILLA_DIR, 'src/data/region_map/region_map_sections.json')))['map_sections'])
    used_secs = sorted(set(M.json['region_map_section'] for M in D['maps']))
    notes = dict(map_notes={k: v for k, v in D['map_notes'].items()},
                 layout_notes={k: v for k, v in D['lay_notes'].items()},
                 tileset_notes=D['ts_notes'], flag_name_fixes=sgmaps.FLAG_NAME_FIXES,
                 mapsec_used_not_in_vanilla=[m for m in used_secs if m not in van_secs],
                 localid_compat=D['localid_compat'],
                 heal=[dict(id=h['json']['id'], map=h['json']['map'], hack_reads=h['hack_read'], chosen=h['chosen']) for h in D['heals']])
    json.dump(notes, open('/home/claude/work/maps/notes.json', 'w'), indent=1, default=str)
    print(json.dumps({k: (v if not isinstance(v, dict) else {kk: len(vv) for kk, vv in v.items()}) for k, v in summary.items()}, indent=1))


if __name__ == '__main__':
    main()
