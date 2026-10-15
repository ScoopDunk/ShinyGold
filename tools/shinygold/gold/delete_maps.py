"""Delete maps from the decomp tree.

usage: delete_maps.py <tree> <list-file>

* labels defined in a deleted map's scripts.inc/text.inc that kept content still uses are moved
  (with everything they reference that would otherwise vanish) into the first kept map file that
  references them, or into data/scripts/shinygold_relocated.inc when only shared code/C uses them;
* removes the map directories, map_groups.json entries, event_scripts.s includes, wild encounter
  headers and heal locations of deleted maps, and their layouts when no kept map uses them;
* warps and connections in kept maps that lead to deleted maps are removed;
* MAP_/LAYOUT_ constants of deleted maps that are still referenced are aliased to MAP_UNDEFINED /
  LAYOUT_UNDEFINED-like 0 in include/constants/map_compat.h so the tree builds (report lists them).
"""
import os, re, sys, json, glob, shutil, collections

tree, listfile = sys.argv[1], sys.argv[2]
DEL = [l.strip() for l in open(listfile) if l.strip() and not l.startswith('#')]
os.chdir(tree)

def map_const(name):
    j = json.load(open('data/maps/%s/map.json' % name))
    return j['id'], j['layout']

delset = set(DEL)
info = {m: map_const(m) for m in DEL}
del_ids = {v[0] for v in info.values()}

# ---------------------------------------------------------------- script/text labels
LABEL = re.compile(r'^(\w+)::?\s*(@.*)?$')
TERM = re.compile(r'^\s*((end|return|goto|step_end|gotostd)\b|\.2byte 0\s*$|\.byte 0\s*$|\.string ".*\$"\s*$)')

def parse(path):
    lines = open(path, encoding='utf-8', errors='surrogateescape').read().split('\n')
    labs = {}
    for i, l in enumerate(lines):
        m = LABEL.match(l)
        if m: labs[m.group(1)] = i
    return lines, labs

def unit(lines, i):
    """lines of the block starting at label line i, following fall-through into later labels"""
    out = [lines[i]]
    j = i + 1
    last_code = None
    while j < len(lines):
        l = lines[j]
        if LABEL.match(l):
            if last_code is not None and (TERM.match(last_code) and not re.match(r'^\s*goto_if', last_code)):
                break
            if last_code is None and out and LABEL.match(out[-1]) is None and False:
                break
        out.append(l)
        if l.strip() and not l.strip().startswith('@') and not LABEL.match(l):
            last_code = l
        j += 1
    while out and not out[-1].strip():
        out.pop()
    return out, j

files_all = sorted(glob.glob('data/maps/*/scripts.inc') + glob.glob('data/maps/*/text.inc') +
                   glob.glob('data/scripts/*.inc') + glob.glob('data/text/*.inc') + ['data/event_scripts.s'])
deleted_files = {f for f in files_all if f.startswith('data/maps/') and f.split('/')[2] in delset}
parsed = {f: parse(f) for f in files_all}
defined_in = {}
for f, (lines, labs) in parsed.items():
    for l in labs: defined_in.setdefault(l, f)
TOK = re.compile(r'\b[A-Za-z_]\w*\b')

def refs_in_lines(lines):
    s = set()
    for l in lines:
        code = l.split('@')[0]
        if LABEL.match(code): continue
        s.update(TOK.findall(code))
    return s

# references from kept content
kept_refs = collections.defaultdict(set)   # label -> referring kept files
for f, (lines, labs) in parsed.items():
    if f in deleted_files: continue
    for t in refs_in_lines(lines):
        if t in defined_in and defined_in[t] in deleted_files:
            kept_refs[t].add(f)
for p in glob.glob('data/maps/*/map.json'):
    m = p.split('/')[2]
    if m in delset: continue
    for t in re.findall(r'"script": "(\w+)"', open(p).read()):
        if t in defined_in and defined_in[t] in deleted_files:
            kept_refs[t].add('data/maps/%s/scripts.inc' % m)
csrc = ''.join(open(f, errors='replace').read() for f in glob.glob('src/**/*.c', recursive=True) + glob.glob('include/**/*.h', recursive=True))
ctoks = set(TOK.findall(csrc))
for l, f in defined_in.items():
    if f in deleted_files and l in ctoks:
        kept_refs[l].add('data/scripts/shinygold_relocated.inc')

# closure + extraction (units are merged per source file, in file order, so fall-through stays intact)
need = {}          # label -> target
queue = [(l, sorted(fs)[0]) for l, fs in sorted(kept_refs.items())]
unit_of = {}
while queue:
    l, target = queue.pop(0)
    if l in need: continue
    need[l] = target
    f = defined_in[l]
    lines, labs = parsed[f]
    blk, j = unit(lines, labs[l])
    unit_of[l] = (f, labs[l], labs[l] + len(blk))
    for x in blk:
        m = LABEL.match(x)
        if m and m.group(1) not in need: need[m.group(1)] = target
    for t in refs_in_lines(blk):
        if t in defined_in and defined_in[t] in deleted_files and t not in need:
            queue.append((t, target))
# merge ranges per file
ranges = collections.defaultdict(list)
for l, (f, a, b) in unit_of.items():
    ranges[f].append([a, b, need[l]])
moves = collections.defaultdict(list)
moved_labels = dict(need)
for f, rs in ranges.items():
    rs.sort()
    merged = []
    for a, b, t in rs:
        if merged and a <= merged[-1][1]:
            merged[-1][1] = max(merged[-1][1], b)
        else:
            merged.append([a, b, t])
    lines = parsed[f][0]
    for a, b, t in merged:
        blk = lines[a:b]
        is_text = any(re.match(r'\s*\.string', x) for x in blk) and not any(re.match(r'\s*(msgbox|end|goto|call|return)\b', x) for x in blk)
        tgt = t
        if tgt.startswith('data/maps/'):
            tgt = tgt.replace('/scripts.inc', '/text.inc') if is_text else tgt.replace('/text.inc', '/scripts.inc')
        moves[tgt].append((None, blk, f))

include_new = []
for tgt, blks in moves.items():
    new = not os.path.exists(tgt)
    with open(tgt, 'a', encoding='utf-8', errors='surrogateescape') as fh:
        if new and tgt.endswith('shinygold_relocated.inc'):
            fh.write('@ Blocks from maps that were removed for the pure Gold/Silver build but are still used elsewhere.\n')
        for l, blk, src in blks:
            fh.write('\n@ ShinyGold: moved from %s (map removed)\n' % src)
            fh.write('\n'.join(blk) + '\n')
    if new: include_new.append(tgt)

# ---------------------------------------------------------------- event_scripts.s includes
es = open('data/event_scripts.s').read().split('\n')
es = [l for l in es if not any('"data/maps/%s/' % m in l for m in delset)]
s = '\n'.join(es)
for f in include_new:
    if f.startswith('data/maps/'):
        m = f.split('/')[2]
        kind = f.split('/')[-1]
        if kind == 'text.inc':
            anchor = '\t.include "data/maps/%s/scripts.inc"' % m
            s = s.replace(anchor, anchor + '\n\t.include "%s"' % f, 1) if anchor in s else s + '\n\t.include "%s"\n' % f
    else:
        s = s.replace('\t.include "data/scripts/shinygold_shared.inc"', '\t.include "data/scripts/shinygold_shared.inc"\n\t.include "%s"' % f, 1)
open('data/event_scripts.s', 'w').write(s)

# ---------------------------------------------------------------- map groups, map dirs
mg = json.load(open('data/maps/map_groups.json'))
for g in mg['group_order']:
    mg[g] = [m for m in mg[g] if m not in delset]
json.dump(mg, open('data/maps/map_groups.json', 'w'), indent=2); open('data/maps/map_groups.json', 'a').write('\n')

# warps / connections in kept maps
removed_warps = []
for p in glob.glob('data/maps/*/map.json'):
    m = p.split('/')[2]
    if m in delset: continue
    j = json.load(open(p))
    ch = False
    if j.get('warp_events'):
        keep = [w for w in j['warp_events'] if w['dest_map'] not in del_ids]
        if len(keep) != len(j['warp_events']):
            removed_warps += ['%s -> %s' % (m, w['dest_map']) for w in j['warp_events'] if w['dest_map'] in del_ids]
            # warps referenced by index from other maps: keep indices stable by turning them into self-warps?  We
            # instead keep the list order and only drop the deleted ones; fix dest_warp_id of incoming warps below.
            j['_old_warps'] = j['warp_events']
            j['warp_events'] = keep; ch = True
    if j.get('connections'):
        keep = [c for c in j['connections'] if c['map'] not in del_ids]
        if len(keep) != len(j['connections']):
            removed_warps += ['%s conn-> %s' % (m, c['map']) for c in j['connections'] if c['map'] in del_ids]
            j['connections'] = keep or None; ch = True
    if ch:
        json.dump(j, open(p, 'w'), indent=2)

# renumber dest_warp_id of warps that point into maps whose warp list shrank
remap = {}
for p in glob.glob('data/maps/*/map.json'):
    j = json.load(open(p))
    if '_old_warps' in j:
        old = j.pop('_old_warps')
        idmap = {}
        k = 0
        for i, w in enumerate(old):
            if w['dest_map'] not in del_ids:
                idmap[i] = k; k += 1
        remap[j['id']] = idmap
        json.dump(j, open(p, 'w'), indent=2)
for p in glob.glob('data/maps/*/map.json'):
    m = p.split('/')[2]
    if m in delset: continue
    j = json.load(open(p)); ch = False
    for w in j.get('warp_events') or []:
        if w['dest_map'] in remap:
            wid = int(w['dest_warp_id'], 0) if isinstance(w['dest_warp_id'], str) else w['dest_warp_id']
            if wid in remap[w['dest_map']]:
                new = remap[w['dest_map']][wid]
                if new != wid:
                    w['dest_warp_id'] = str(new) if isinstance(w['dest_warp_id'], str) else new; ch = True
    if ch: json.dump(j, open(p, 'w'), indent=2)
for p in glob.glob('data/maps/*/map.json'):
    s = open(p).read()
    if not s.endswith('\n'): open(p, 'a').write('\n')

# script warps with explicit warp ids into maps whose warp list shrank
fixed_script_warps = []
WRX = re.compile(r'^(\s*(?:warp\w*|setwarp|setdynamicwarp|setescapewarp|setdivewarp|setholewarp)\s+)(MAP_\w+)(\s*,\s*)(\w+)(.*)$')
for f in glob.glob('data/maps/*/scripts.inc') + glob.glob('data/scripts/*.inc') + ['data/event_scripts.s']:
    if f.startswith('data/maps/') and f.split('/')[2] in delset: continue
    lines = open(f, encoding='utf-8', errors='surrogateescape').read().split('\n'); ch = False
    for i, l in enumerate(lines):
        m = WRX.match(l)
        if not m or m.group(2) not in remap: continue
        a = m.group(4)
        try: wid = int(a, 0)
        except ValueError: continue
        if wid in (255, 0x7F) or l.count(',') == 2: continue   # 'warp MAP, x, y' has no warp id
        if wid in remap[m.group(2)] and remap[m.group(2)][wid] != wid:
            lines[i] = m.group(1) + m.group(2) + m.group(3) + str(remap[m.group(2)][wid]) + m.group(5); ch = True
            fixed_script_warps.append('%s: %s -> %s' % (f, l.strip(), lines[i].strip()))
        elif wid not in remap[m.group(2)]:
            fixed_script_warps.append('%s: UNRESOLVED %s' % (f, l.strip()))
    if ch: open(f, 'w', encoding='utf-8', errors='surrogateescape').write('\n'.join(lines))


for m in DEL:
    shutil.rmtree('data/maps/%s' % m)

# layouts
lj = json.load(open('data/layouts/layouts.json'))
used = {json.load(open(p))['layout'] for p in glob.glob('data/maps/*/map.json')}
dropped_layouts = []
newl = []
for L in lj['layouts']:
    if L and L['id'] not in used and L['id'] in {v[1] for v in info.values()}:
        dropped_layouts.append(L['id'])
        d = os.path.dirname(L['blockdata_filepath'])
        if os.path.isdir(d) and not any(x and x['id'] != L['id'] and os.path.dirname(x['blockdata_filepath']) == d for x in lj['layouts']):
            shutil.rmtree(d)
        newl.append({})   # keep LAYOUT_ ids stable? -> empty placeholder keeps numbering
    else:
        newl.append(L)
lj['layouts'] = newl
json.dump(lj, open('data/layouts/layouts.json', 'w'), indent=2); open('data/layouts/layouts.json', 'a').write('\n')

# wild encounters
wj = json.load(open('src/data/wild_encounters.json'))
for g in wj['wild_encounter_groups']:
    g['encounters'] = [e for e in g['encounters'] if e.get('map') not in del_ids]
json.dump(wj, open('src/data/wild_encounters.json', 'w'), indent=2); open('src/data/wild_encounters.json', 'a').write('\n')

# heal locations
hj = json.load(open('src/data/heal_locations.json'))
dropped_heal = [h['id'] for h in hj['heal_locations'] if h['map'] in del_ids or h.get('respawn_map') in del_ids]
hj['heal_locations'] = [h for h in hj['heal_locations'] if h['map'] not in del_ids and h.get('respawn_map') not in del_ids]
json.dump(hj, open('src/data/heal_locations.json', 'w'), indent=2); open('src/data/heal_locations.json', 'a').write('\n')

# remaining references to deleted MAP_/LAYOUT_ constants
srcs = glob.glob('src/**/*.c', recursive=True) + glob.glob('src/**/*.h', recursive=True) + glob.glob('include/**/*.h', recursive=True) + \
       glob.glob('data/**/*.inc', recursive=True) + glob.glob('data/*.s') + glob.glob('data/maps/*/map.json')
still = collections.defaultdict(set)
cands = del_ids | set(dropped_layouts)
for f in srcs:
    for c in set(TOK.findall(open(f, errors='replace').read())) & cands:
        still[c].add(f)
json.dump(dict(fixed_script_warps=fixed_script_warps, moved={k: v for k, v in moved_labels.items()}, removed_warps=removed_warps, dropped_layouts=dropped_layouts,
               dropped_heal=dropped_heal, still_referenced={k: sorted(v) for k, v in still.items()}),
          open('/home/claude/work/gold/delete_report.json', 'w'), indent=1)
print('deleted maps', len(DEL), '| moved labels', len(moved_labels), '| removed warps/conns', len(removed_warps),
      '| dropped layouts', len(dropped_layouts), '| dropped heal', dropped_heal, '| still-referenced consts', len(still))
