"""ShinyGold map/layout/tileset/heal-location model extracted from the hack ROM.

Builds a Python model of everything the maps worker emits.  All hack-bug handling is centralised here and
recorded in `notes` so the generator/report can list it.

Uses /home/claude/sgx (core.py, maps.py, names.py) read-only.
"""
import sys, os, re, json, struct, collections, functools
sys.path.insert(0, '/home/claude/sgx')
from core import Rom, VANILLA_ROM, VANILLA_DIR, vanilla_symbols, vanilla_addr, vanilla_name_at, lz77_decompress, c_constants
import maps as sgx_maps
import names

MAP_NAMES = json.load(open('/home/claude/work/map_names.json'))

NUM_TILES_IN_PRIMARY = 640
NUM_TILES_IN_SECONDARY = 1024 - 640
NUM_METATILES_IN_PRIMARY = 640
FLAG_HIDDEN_ITEMS_START = 1000

# ------------------------------------------------------------------------------------------------ hack bug fixes
# Layout ids whose width field is 0xFFFFFFFF in the hack (the 24-byte RSE-style layout header written by the
# hack's map tool got its width clobbered).  The real width was recovered from the blockdata extent / row
# autocorrelation (both render as perfectly coherent maps at this width).
LAYOUT_WIDTH_FIX = {390: 62, 401: 29}
# Layout whose struct (and blockdata) was overwritten by script text: replaced by a minimal valid layout.
LAYOUT_OVERWRITTEN = {387}
MINIMAL_LAYOUT = dict(width=8, height=10, primary='gTileset_Building', secondary='gTileset_GenericBuilding1')
# Map headers whose layout pointer is corrupt (layout id / gMapLayouts entry is correct).
BAD_HEADER_LAYOUT_PTR = {(1, 123), (2, 80), (34, 71)}

DIRS = {0: 'none', 1: 'down', 2: 'up', 3: 'left', 4: 'right', 5: 'dive', 6: 'emerge'}
FACING = ['BG_EVENT_PLAYER_FACING_ANY', 'BG_EVENT_PLAYER_FACING_NORTH', 'BG_EVENT_PLAYER_FACING_SOUTH',
          'BG_EVENT_PLAYER_FACING_EAST', 'BG_EVENT_PLAYER_FACING_WEST']


@functools.lru_cache(None)
def _const_files():
    return c_constants()[1]


FLAG_NAME_FIXES = []


def flag_name(v):
    """names.flag_name, but never a constant from outside include/constants/flags.h (names.flag_name(0x20) returns
    FLAG_KINGS_ROCK_AFFECTED from pokemon.h -- reported to the coordinator)."""
    n = names.flag_name(v)
    if n != '0' and not n.startswith('0x') and _const_files().get(n) != 'flags.h':
        FLAG_NAME_FIXES.append((v, n))
        return '0x%03X' % v
    return n


def ptrstr(v):
    return '0x0' if v == 0 else '0x%08X' % v


def boolish(v):
    """JSON value for a raw byte that is normally a bool (keeps non-0/1 values as ints so they round-trip)."""
    return bool(v) if v in (0, 1) else v


@functools.lru_cache(None)
def vanilla_maps():
    """vanilla (group,num) -> (name, json)"""
    mg = json.load(open(os.path.join(VANILLA_DIR, 'data/maps/map_groups.json')))
    out = {}
    for gi, g in enumerate(mg['group_order']):
        for ni, n in enumerate(mg[g]):
            out[(gi, ni)] = (n, json.load(open(os.path.join(VANILLA_DIR, 'data/maps/%s/map.json' % n))))
    return mg, out


# ------------------------------------------------------------------------------------------------ tilesets
class Tileset:
    pass


@functools.lru_cache(None)
def vanilla_tileset_sources():
    """Parse vanilla headers.h / graphics.h / graphics.c / metatiles.h.
    Returns (structs: ordered list of dicts, tiles: sym->(path, file), pals: sym->(dir, file), mt: sym->path)"""
    hdr = open(os.path.join(VANILLA_DIR, 'src/data/tilesets/headers.h')).read()
    structs = []
    for m in re.finditer(r'const struct Tileset (gTileset_\w+) =\s*\{(.*?)\};', hdr, re.S):
        body = m.group(2)
        f = dict(re.findall(r'\.(\w+)\s*=\s*([\w]+),', body))
        f['name'] = m.group(1)
        structs.append(f)
    tiles, pals = {}, {}
    for fn in ['src/data/tilesets/graphics.h', 'src/graphics.c']:
        s = open(os.path.join(VANILLA_DIR, fn)).read()
        for m in re.finditer(r'const u32 (gTilesetTiles_\w+)\[\] = INCBIN_U32\("([^"]+)"\);', s):
            tiles[m.group(1)] = (m.group(2), fn)
        for m in re.finditer(r'const u16 (gTilesetPalettes_\w+)\[\]\[16\] =\s*\{\s*INCBIN_U16\("([^"]+)/palettes/00\.gbapal"\)', s):
            pals[m.group(1)] = (m.group(2), fn)
    mt = {}
    s = open(os.path.join(VANILLA_DIR, 'src/data/tilesets/metatiles.h')).read()
    for m in re.finditer(r'const u(?:16|32) (gMeta\w+)\[\] = INCBIN_U(?:16|32)\("([^"]+)"\);', s):
        mt[m.group(1)] = m.group(2)
    return structs, tiles, pals, mt


def symaddr(name):
    a = vanilla_addr(name)
    if a is None: raise KeyError(name)
    return a


@functools.lru_cache(None)
def symsize(name):
    by, rng = vanilla_symbols()
    for a, s, n in rng:
        if n == name: return s
    raise KeyError(name)


def load_tilesets(r, v, slot_usage):
    """slot_usage: struct addr -> set('P'/'S') from the hack's (used) layouts."""
    structs, tiles, pals, mt = vanilla_tileset_sources()
    out = []
    notes = []
    for st in structs:
        T = Tileset()
        T.name = st['name']
        T.suffix = T.name[len('gTileset_'):]
        T.addr = symaddr(T.name)
        T.van = st
        T.dir = os.path.dirname(mt['gMetatiles_' + T.suffix]) if ('gMetatiles_' + T.suffix) in mt else os.path.dirname(mt[st['metatiles']])
        T.slots = slot_usage.get(T.addr, set())
        T.isCompressed = r.u8(T.addr)
        T.isSecondary = r.u8(T.addr + 1)
        T.van_isCompressed = v.u8(T.addr)
        tp, pp, mp, cb, ap = [r.u32(T.addr + k) for k in (4, 8, 12, 16, 20)]
        vtp, vpp, vmp, vcb, vap = [v.u32(T.addr + k) for k in (4, 8, 12, 16, 20)]
        assert (pp, mp, cb, ap) == (vpp, vmp, vcb, vap), T.name  # only tiles/compression were repointed
        T.callback = st['callback']
        # ---- tiles
        vsym = st['tiles']
        T.tiles_repointed = tp != vtp
        T.tiles_fixed = None
        if not T.tiles_repointed:
            T.tiles_sym = vsym
            T.tiles_path = tiles[vsym][0]
            T.tiles_file = tiles[vsym][1]
            off = tp - 0x08000000
            if T.isCompressed:
                if r.d[off] != 0x10:
                    # hack bug: the tool freed (0xFF-filled) this LZ blob when it repointed a tileset sharing it
                    # (gTileset_SilphCo shared gTilesetTiles_Condominiums).  The engine's MallocAndDecompress then
                    # fails (size 0xFFFFFF) and leaves stale VRAM.  Keep the vanilla tiles (metatiles unchanged).
                    T.tiles_data = lz77_decompress(v.d, off)[0]
                    T.tiles_fixed = 'freed'
                    notes.append('%s: tiles at 0x%X were 0xFF-filled by the hack tool (LZ flag still set) -> '
                                 'kept vanilla %s' % (T.name, tp, vsym))
                else:
                    T.tiles_data = lz77_decompress(r.d, off)[0]
            else:
                T.tiles_data = r.d[off:off + symsize(vsym)]
            T.tiles_compressed = bool(T.isCompressed)
        else:
            assert not T.isCompressed, T.name
            T.tiles_sym = 'gTilesetTiles_' + T.suffix
            T.tiles_path = T.dir + '/tiles.4bpp'
            T.tiles_file = 'src/graphics.c' if T.tiles_sym in tiles and tiles[T.tiles_sym][1] == 'src/graphics.c' \
                else 'src/data/tilesets/graphics.h'
            n = NUM_TILES_IN_PRIMARY if ('P' in T.slots or (not T.slots and not T.isSecondary)) else NUM_TILES_IN_SECONDARY
            off = tp - 0x08000000
            T.tiles_data = r.d[off:off + 32 * n]
            T.tiles_compressed = False
        T.tiles_ptr = tp
        T.num_tiles = len(T.tiles_data) // 32
        # ---- palettes (always 16 palettes, as in the decomp)
        T.pal_sym = st['palettes']
        T.pal_dir = pals[T.pal_sym][0]
        T.pal_data = r.d[pp - 0x08000000:pp - 0x08000000 + 512]
        # ---- metatiles / attributes (in place, vanilla extents)
        T.mt_sym = st['metatiles']; T.attr_sym = st['metatileAttributes']
        T.mt_path = mt[T.mt_sym]; T.attr_path = mt[T.attr_sym]
        T.mt_data = r.d[mp - 0x08000000:mp - 0x08000000 + symsize(T.mt_sym)]
        T.attr_data = r.d[ap - 0x08000000:ap - 0x08000000 + symsize(T.attr_sym)]
        out.append(T)
    return out, notes


# ------------------------------------------------------------------------------------------------ layouts
class Layout:
    pass


def load_layouts(r, v, maps, ts_by_addr):
    max_id = max(m.layout_id for m in maps)
    T, lays = sgx_maps.load_layouts(Rom(), max_id)
    used = collections.defaultdict(list)
    for m in maps: used[m.layout_id].append((m.group, m.num))
    out = {}
    notes = collections.defaultdict(list)
    for lid in range(1, max_id + 1):
        off = lays.get(lid)
        if off is None:
            out[lid] = None
            continue
        L = Layout()
        L.id = lid; L.off = off
        L.const = names.layout_const(lid)
        L.dir = names.layout_dirname(lid)
        L.label = L.dir + '_Layout'
        L.used_by = used.get(lid, [])
        if lid in LAYOUT_OVERWRITTEN:
            mn = MINIMAL_LAYOUT
            L.width, L.height = mn['width'], mn['height']
            L.bw = L.bh = 2
            L.primary, L.secondary = mn['primary'], mn['secondary']
            L.blockdata = b'\0\0' * (L.width * L.height)
            L.border = b'\0\0' * 4
            L.fixed = 'overwritten'
            notes['overwritten'].append(lid)
            out[lid] = L
            continue
        w, h = r.s32(off), r.s32(off + 4)
        bp, mp, pp, sp = r.u32(off + 8), r.u32(off + 12), r.u32(off + 16), r.u32(off + 20)
        bw, bh = r.u8(off + 24), r.u8(off + 25)
        tail = r.d[off + 26:off + 28]
        valid_ts = lambda p: p == 0 or (p - 0x08000000) in ts_by_addr
        L.fixed = None
        if lid in LAYOUT_WIDTH_FIX:
            notes['width'].append((lid, w, LAYOUT_WIDTH_FIX[lid]))
            w = LAYOUT_WIDTH_FIX[lid]
            L.fixed = 'width'
        ok = (1 <= w <= 0x400 and 1 <= h <= 0x400 and Rom.is_rom_ptr(bp) and Rom.is_rom_ptr(mp)
              and valid_ts(pp) and valid_ts(sp))
        if not ok:
            assert not L.used_by, lid
            notes['garbage_unused'].append(lid)
            out[lid] = None
            continue
        L.width, L.height = w, h
        L.primary = ts_by_addr[pp - 0x08000000].name if pp else 'NULL'
        L.secondary = ts_by_addr[sp - 0x08000000].name if sp else 'NULL'
        bpo, mpo = bp - 0x08000000, mp - 0x08000000
        L.raw_bw, L.raw_bh = bw, bh
        L.vanilla_struct = off < 0x71A000 and r.d[off:off + 28] == v.d[off:off + 28]
        # Border dims: the hack's map tool wrote 24-byte (RSE-style) layout headers for new layouts, so the FRLG
        # border width/height bytes are whatever data follows (object events, wild data...).  The tool always
        # wrote a 2x2 border (8 bytes directly before the blockdata).
        if L.vanilla_struct:
            pass   # untouched vanilla layout (incl. the unused RS leftovers with 0x0 border dims)
        elif (bw, bh) != (2, 2) and not ((bw, bh) == (3, 2) and mpo - bpo == 12):
            if mpo - bpo == 8 or (bw * bh == 0):
                notes['border'].append((lid, bw, bh))
                bw = bh = 2
            else:
                # unaligned/odd unused layouts: still a 2x2 border by construction
                notes['border'].append((lid, bw, bh))
                bw = bh = 2
        if tail != b'\0\0':
            notes['tail'].append((lid, tail.hex()))
        L.bw, L.bh = bw, bh
        L.blockdata = r.d[mpo:mpo + 2 * w * h]
        L.border = r.d[bpo:bpo + (2 * bw * bh if bw * bh else 8)]
        L.unaligned = off % 4 != 0
        if L.unaligned: notes['unaligned'].append(lid)
        out[lid] = L
    return T, out, notes


# ------------------------------------------------------------------------------------------------ maps
class MapInfo:
    pass


def obj_json(r, o, i, notes, key):
    raw = o['raw']
    kind = o['kind']
    d = collections.OrderedDict()
    lid = o['local_id']
    if kind == 0xFF:
        tgt_local = raw[8]
        tgt_num = struct.unpack_from('<H', raw, 12)[0]
        tgt_grp = struct.unpack_from('<H', raw, 14)[0]
        script = struct.unpack_from('<I', raw, 16)[0]
        flag = struct.unpack_from('<H', raw, 20)[0]
        d['type'] = 'clone'
        d['graphics_id'] = names.obj_gfx(o['gfx'])
        d['x'] = o['x']; d['y'] = o['y']
        d['target_local_id'] = tgt_local
        d['target_map'] = names.map_const(tgt_grp, tgt_num)
        if flag:
            # TrySpawnObjectEvents checks the clone template's own flagId before resolving the clone
            d['flag'] = flag_name(flag)
        junk = [raw[3], raw[9], raw[10], raw[11], raw[22], raw[23]]
        if any(junk) or script:
            notes['clone_junk'].append((key, i, raw[9:12].hex(), ptrstr(script)))
    else:
        if kind != 0:
            notes['junk_kind'].append((key, i, kind))
        if raw[3] or raw[11] or raw[22] or raw[23]:
            notes['obj_padding'].append((key, i, raw[3], raw[11], raw[22:24].hex()))
        d['type'] = 'object'
        d['graphics_id'] = names.obj_gfx(o['gfx'])
        d['x'] = o['x']; d['y'] = o['y']
        d['elevation'] = o['elevation']
        d['movement_type'] = names.movement_type(o['movement'])
        d['movement_range_x'] = o['range_byte'] & 0xF
        d['movement_range_y'] = o['range_byte'] >> 4
        d['trainer_type'] = names.trainer_type(o['trainer_type'])
        d['trainer_sight_or_berry_tree_id'] = str(o['sight'])
        d['script'] = ptrstr(o['script'])
        d['flag'] = flag_name(o['flag'])
    if lid != i + 1:
        d['explicit_local_id'] = lid
        notes['explicit_local_id'].append((key, i, lid))
    return d


# Vanilla LOCALID_ names that engine C code (src/) needs, keyed by vanilla map; assigned to the hack's object
# with the same local id when the hack map keeps the same object, otherwise defined in map_compat.h.
C_LOCALIDS = ['LOCALID_SS_ANNE', 'LOCALID_BIRTH_ISLAND_EXTERIOR_ROCK'] + ['LOCALID_UNION_ROOM_PLAYER_%d' % i for i in range(1, 9)]


def c_localid_plan(r, maps_by_key):
    """returns (assign: {(g,n,index): name}, compat_defines: {name: (value, comment)})"""
    mg, vmaps = vanilla_maps()
    assign, compat = {}, {}
    for (g, n), (vname, vj) in vmaps.items():
        for i, o in enumerate(vj['object_events']):
            nm = o.get('local_id')
            if nm not in C_LOCALIDS: continue
            m = maps_by_key.get((g, n))
            ev = sgx_maps.parse_events(r, m.events)
            same = False
            if i < len(ev['objects']):
                h = ev['objects'][i]
                vg = c_constants()[0].get(o['graphics_id'])
                same = (h['local_id'] == i + 1 and h['gfx'] == vg and (h['x'], h['y']) == (o['x'], o['y']))
            if same:
                assign[(g, n, i)] = nm
            else:
                compat[nm] = (i + 1, 'vanilla %s object %d; engine code special-cases this local id on %s'
                              % (vname, i + 1, names.map_const(g, n)))
    return assign, compat


def load_maps(r):
    groups, maps = sgx_maps.load_map_headers(r)
    notes = collections.defaultdict(list)
    maps_by_key = {(m.group, m.num): m for m in maps}
    assign, compat = c_localid_plan(r, maps_by_key)
    out = []
    for m in maps:
        key = '%d.%d' % (m.group, m.num)
        e = MAP_NAMES[key]
        M = MapInfo()
        M.group, M.num, M.key = m.group, m.num, key
        M.name, M.id = e['name'], e['id']
        M.layout_id = m.layout_id
        M.hdr = m.hdr
        M.raw = m
        if m.bad_layout_ptr:
            notes['bad_layout_ptr'].append((key, r.u32(m.hdr)))
        assert m.bad_layout_ptr == ((m.group, m.num) in BAD_HEADER_LAYOUT_PTR), key
        if m.scripts is None: notes['null_map_scripts'].append(key)
        assert m.flags & ~7 == 0
        j = collections.OrderedDict()
        j['id'] = M.id
        j['name'] = M.name
        j['layout'] = names.layout_const(m.layout_id)
        j['music'] = names.song(m.music)
        j['region_map_section'] = names.mapsec_const(m.mapsec)
        j['requires_flash'] = boolish(m.cave)
        j['weather'] = names.weather(m.weather)
        j['map_type'] = names.map_type(m.map_type)
        j['allow_cycling'] = boolish(m.bike)
        j['allow_escaping'] = bool(m.flags & 1)
        j['allow_running'] = bool(m.flags & 2)
        j['show_map_name'] = bool(m.flags & 4)
        j['floor_number'] = m.floor
        j['battle_scene'] = names.battle_scene(m.battle)
        # connections
        cn = sgx_maps.parse_connections(r, m.connections)
        conns = []
        if cn is not None:
            if cn['count'] == 0: notes['empty_connections'].append(key)
            for c in cn['list']:
                assert c['pad'] == b'\0\0\0' and c['pad2'] == b'\0\0'
                conns.append(collections.OrderedDict([('map', names.map_const(c['map_group'], c['map_num'])),
                                                      ('offset', c['offset']), ('direction', DIRS[c['direction']])]))
                if c['direction'] == 0: notes['none_connections'].append((key, names.map_const(c['map_group'], c['map_num'])))
        j['connections'] = conns if conns else None
        ev = sgx_maps.parse_events(r, m.events)
        objs = []
        for i, o in enumerate(ev['objects']):
            d = obj_json(r, o, i, notes, key)
            if (m.group, m.num, i) in assign:
                d2 = collections.OrderedDict([('local_id', assign[(m.group, m.num, i)])])
                d2.update(d); d = d2
            objs.append(d)
        j['object_events'] = objs
        warps = []
        for w in ev['warps']:
            warps.append(collections.OrderedDict([('x', w['x']), ('y', w['y']), ('elevation', w['elevation']),
                                                  ('dest_map', names.map_const(w['map_group'], w['map_num'])),
                                                  ('dest_warp_id', 'WARP_ID_DYNAMIC' if (w['warp_id'] == 0x7F and
                                                   (w['map_group'], w['map_num']) == (0x7F, 0x7F)) else str(w['warp_id']))]))
        j['warp_events'] = warps
        coords = []
        for c in ev['coords']:
            assert c['pad5'] == 0 and c['pad10'] == 0
            d = collections.OrderedDict()
            # (24 placeholder triggers have a NULL script; FRLG treats those as dummied-out weather events)
            if c['script'] == 0: notes['null_script_coord'].append(key)
            d['type'] = 'trigger'
            d['x'] = c['x']; d['y'] = c['y']; d['elevation'] = c['elevation']
            d['var'] = names.var_name(c['var'])
            d['var_value'] = str(c['value'])
            d['script'] = ptrstr(c['script'])
            coords.append(d)
        j['coord_events'] = coords
        bgs = []
        for b in ev['bgs']:
            assert b['pad6'] == 0
            d = collections.OrderedDict()
            k = b['kind']
            if k <= 4:
                d['type'] = 'sign'
                d['x'] = b['x']; d['y'] = b['y']; d['elevation'] = b['elevation']
                d['player_facing_dir'] = FACING[k]
                d['script'] = ptrstr(b['arg'])
            elif k == 7:
                a = b['arg']
                d['type'] = 'hidden_item'
                d['x'] = b['x']; d['y'] = b['y']; d['elevation'] = b['elevation']
                d['item'] = names.item(a & 0xFFFF)
                d['flag'] = flag_name(FLAG_HIDDEN_ITEMS_START + ((a >> 16) & 0xFF))
                d['quantity'] = (a >> 24) & 0x7F
                d['underfoot'] = bool(a >> 31)
            else:
                raise ValueError('bg kind %d in %s' % (k, key))
            bgs.append(d)
        j['bg_events'] = bgs
        M.json = j
        out.append(M)
    return groups, out, notes, compat


# ------------------------------------------------------------------------------------------------ heal locations
HEAL_TABLE = 0xA002EC
NUM_HEAL = 24
VANILLA_NUM_HEAL = 20
# Hack bug: the whiteout tables (sWhiteoutRespawnHealCenterMapIdxs / sWhiteoutRespawnHealerNpcIds) were not
# extended for heal locations 21..24; the engine reads past them (see heal_locations()).  Chosen replacements:
# the Pokemon Center (+ nurse local id) of the heal location's town.
EXTRA_RESPAWN = {21: (32, 0, 1),   # Cherrygrove City -> CherrygroveCity_Interior1 (PC), nurse local id 1
                 22: (21, 0, 1),   # Blackthorn City  -> BlackthornCity_Interior3 (PC), nurse 1
                 23: (16, 0, 1),   # Mahogany Town    -> MahoganyTown_Interior3 (PC), nurse 1
                 24: (12, 4, 2)}   # Kalm City Nousar -> KalmCityNousar_Interior4 (PC), nurse 2


def heal_locations(r):
    wm = symaddr('sWhiteoutRespawnHealCenterMapIdxs')
    wn = symaddr('sWhiteoutRespawnHealerNpcIds')
    out = []
    for i in range(1, NUM_HEAL + 1):
        o = HEAL_TABLE + 8 * (i - 1)
        g, n, x, y = r.s8(o), r.s8(o + 1), r.s16(o + 2), r.s16(o + 4)
        assert r.u16(o + 6) == 0
        # what the hack's SetWhiteoutRespawnWarpAndHealerNpc actually reads (strb of u16 -> low byte)
        rg, rn = r.u16(wm + 4 * (i - 1)) & 0xFF, r.u16(wm + 4 * (i - 1) + 2) & 0xFF
        npc = r.u8(wn + i - 1)
        e = collections.OrderedDict()
        e['id'] = names.heal_location_const(i)
        e['map'] = names.map_const(g, n)
        e['x'] = x; e['y'] = y
        hack_read = (rg, rn, npc)
        if i <= VANILLA_NUM_HEAL:
            e['respawn_map'] = names.map_const(rg, rn)
            e['respawn_npc'] = npc
            chosen = hack_read
        else:
            cg, cn_, cnpc = EXTRA_RESPAWN[i]
            e['respawn_map'] = names.map_const(cg, cn_)
            e['respawn_npc'] = cnpc
            chosen = (cg, cn_, cnpc)
        out.append(dict(json=e, idx=i, map=(g, n), xy=(x, y), hack_read=hack_read, chosen=chosen))
    return out


# ------------------------------------------------------------------------------------------------ everything
def load_all():
    r = Rom()
    v = Rom(VANILLA_ROM)
    groups, maps, map_notes, localid_compat = load_maps(r)
    # tileset slot usage by used layouts
    max_id = max(M.layout_id for M in maps)
    Tt, lays = sgx_maps.load_layouts(Rom(), max_id)
    used_ids = set(M.layout_id for M in maps)
    slot_usage = collections.defaultdict(set)
    for lid in used_ids:
        off = lays.get(lid)
        if off is None or lid in LAYOUT_OVERWRITTEN: continue
        for k, s in ((16, 'P'), (20, 'S')):
            p = r.u32(off + k)
            if p: slot_usage[p - 0x08000000].add(s)
    tilesets, ts_notes = load_tilesets(r, v, slot_usage)
    ts_by_addr = {T.addr: T for T in tilesets}
    table, layouts, lay_notes = load_layouts(r, v, [M.raw for M in maps], ts_by_addr)
    heals = heal_locations(r)
    return dict(rom=r, vrom=v, groups=groups, maps=maps, map_notes=map_notes, localid_compat=localid_compat,
                tilesets=tilesets, ts_notes=ts_notes, layouts=layouts, lay_notes=lay_notes, heals=heals,
                layout_table=table)


if __name__ == '__main__':
    D = load_all()
    print(len(D['maps']), 'maps', sum(1 for l in D['layouts'].values() if l), 'layouts')
    for k, v in D['map_notes'].items(): print('map note', k, len(v), v[:6])
    for k, v in D['lay_notes'].items(): print('layout note', k, len(v), v[:8])
    print(D['ts_notes'])
    print(D['localid_compat'])
    for h in D['heals']: print(h['json']['id'], h['hack_read'], h['chosen'])
    for T in D['tilesets']:
        if T.tiles_repointed or T.tiles_fixed: print(T.name, T.tiles_sym, T.tiles_path, T.num_tiles, T.slots)
