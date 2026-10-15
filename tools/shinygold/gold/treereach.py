"""Reachability over a decomp tree (map names), warps checked against tile behaviors.
usage: treereach.py <tree> [start_map]  -> prints unreachable maps; writes <tree-independent> json to stdout path arg 3"""
import json, re, os, struct, sys, glob, collections
sys.path.insert(0, '/home/claude/work/custom')
tree = sys.argv[1]; start = sys.argv[2] if len(sys.argv) > 2 else 'NewBarkTown_Interior2'
os.chdir(tree)
mb = {}
for line in open('include/constants/metatile_behaviors.h'):
    m = re.match(r'#define (MB_\w+)\s+(0x[0-9A-Fa-f]+|\d+)', line)
    if m: mb[m.group(1)] = int(m.group(2), 0)
WARP = {mb[k] for k in mb if re.search(r'(WARP|DOOR|LADDER|ESCALATOR)', k) and k != 'MB_INDOOR_ENCOUNTER'}
attr = {}
for line in open('src/data/tilesets/metatiles.h'):
    m = re.match(r'const u32 (gMetatileAttributes_\w+)\[\] = INCBIN_U32\("([^"]+)"\)', line)
    if m: attr[m.group(1)] = m.group(2)
ts = {}; cur = None
for line in open('src/data/tilesets/headers.h'):
    m = re.match(r'const struct Tileset (gTileset_\w+)', line)
    if m: cur = m.group(1)
    m = re.search(r'\.metatileAttributes = (gMetatileAttributes_\w+)', line)
    if m and cur: ts[cur] = attr[m.group(1)]
def attrs(sym):
    d = open(ts[sym], 'rb').read(); return struct.unpack('<%dI' % (len(d) // 4), d)
MTL = {}
for line in open('include/constants/metatile_labels.h'):
    m = re.match(r'#define (METATILE_\w+)\s+(0x[0-9A-Fa-f]+|\d+)', line)
    if m: MTL[m.group(1)] = int(m.group(2), 0)
lay = {l['id']: l for l in json.load(open('data/layouts/layouts.json'))['layouts'] if l}
maps = {}
for p in glob.glob('data/maps/*/map.json'):
    j = json.load(open(p)); maps[j['name']] = j
byid = {j['id']: n for n, j in maps.items()}
from reach import load, reach
import reach as R
R.SG = tree
body, owner = load()
def beh_fn(j):
    L = lay[j['layout']]
    blk = open(L['blockdata_filepath'], 'rb').read(); w, h = L['width'], L['height']
    p = attrs(L['primary_tileset']); s = attrs(L['secondary_tileset'])
    def mtb(mt): return ((p[mt] if mt < 640 else (s[mt - 640] if mt - 640 < len(s) else 0)) & 0x1FF)
    def beh(x, y):
        if not (0 <= x < w and 0 <= y < h): return None
        return mtb(struct.unpack_from('<H', blk, (y * w + x) * 2)[0] & 0x3FF)
    return beh, mtb
def scripts_of(n):
    j = maps[n]
    roots = ['%s_MapScripts' % n] + [e['script'] for k in ('object_events', 'coord_events', 'bg_events') for e in (j.get(k) or []) if e.get('script')]
    return reach(roots, body)
WRX = re.compile(r'\s*(warp\w*|setwarp|setdynamicwarp|setescapewarp|setdivewarp|setholewarp)\s+(MAP_\w+)')
SMT = re.compile(r'\s*setmetatile\s+(\w+),\s*(\w+),\s*(\w+)')
def edges(n):
    j = maps[n]; out = set()
    beh, mtb = beh_fn(j)
    R_ = scripts_of(n)
    sets = {}
    for l in R_:
        for line in body[l]:
            m = WRX.match(line)
            if m and m.group(2) in byid: out.add((byid[m.group(2)], 'script:' + l))
            m = SMT.match(line)
            if m:
                try:
                    x, y, mt = (int(v, 0) if re.match(r'^(0x)?[0-9A-Fa-f]+$', v) else MTL[v] for v in m.groups())
                    sets[(x, y)] = mtb(mt & 0x3FF)
                except (KeyError, ValueError): pass
    for w in j.get('warp_events') or []:
        d = byid.get(w['dest_map'])
        if d and (beh(w['x'], w['y']) in WARP or sets.get((w['x'], w['y'])) in WARP): out.add((d, 'warp'))
    for c in j.get('connections') or []:
        d = byid.get(c['map'])
        if not d or c['direction'] in ('none', 'dive', 'emerge'): continue
        back = [x for x in (maps[d].get('connections') or []) if x['map'] == j['id'] and x['direction'] not in ('none',)]
        if back: out.add((d, 'conn'))
    return out
E = {n: edges(n) for n in maps}
seen = {start}; q = [start]; via = {start: None}
while q:
    k = q.pop(0)
    for d, how in sorted(E[k]):
        if d not in seen: seen.add(d); via[d] = (k, how); q.append(d)
un = sorted(set(maps) - seen)
print('maps', len(maps), 'reachable', len(seen), 'unreachable', len(un))
print(' '.join(un))
if len(sys.argv) > 3:
    json.dump(dict(reach=sorted(seen), via=via, edges={k: sorted(v) for k, v in E.items()}), open(sys.argv[3], 'w'))
