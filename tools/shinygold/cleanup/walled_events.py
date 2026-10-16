"""List events the player can never touch because they are sealed inside impassable tiles.

usage: walled_events.py <tree> [reach.json]

An object or sign/hidden item counts as walled when its tile and all four neighbours are impassable; a coord
trigger when its own tile is impassable. Tiles are impassable when they have collision bits set (collision bits set) or outside the map. The player can't stand next to it (so can't talk to it,
read it or be spotted by it: a trainer's line of sight needs passable tiles) and can't step on it.
Skipped: maps whose scripts change metatiles (setmetatile) or move objects (setobjectxy*, copyobjectxytoperm),
and coords that are also warp landing spots. Prints one line per event: map kind index x y script.
"""
import os, re, sys, json, glob, struct

tree = sys.argv[1]
reach = set(json.load(open(sys.argv[2]))['reach']) if len(sys.argv) > 2 else None
os.chdir(tree)
attr = {}
for line in open('src/data/tilesets/metatiles.h'):
    m = re.match(r'const u32 (gMetatileAttributes_\w+)\[\] = INCBIN_U32\("([^"]+)"\)', line)
    if m: attr[m.group(1)] = m.group(2)
lay = {L['id']: L for L in json.load(open('data/layouts/layouts.json'))['layouts'] if L}
ts = {}; cur = None
for line in open('src/data/tilesets/headers.h'):
    m = re.match(r'const struct Tileset (gTileset_\w+)', line)
    if m: cur = m.group(1)
    m = re.search(r'\.metatileAttributes = (gMetatileAttributes_\w+)', line)
    if m and cur: ts[cur] = attr[m.group(1)]
_ac = {}
def attrs(sym):
    if sym not in _ac:
        d = open(ts[sym], 'rb').read(); _ac[sym] = struct.unpack('<%dI' % (len(d) // 4), d)
    return _ac[sym]
MB_COUNTER = next(int(v, 0) for k, v in re.findall(r'#define (MB_\w+)\s+(0x[0-9A-Fa-f]+|\d+)', open('include/constants/metatile_behaviors.h').read()) if k == 'MB_COUNTER')

def scripts_text(m):
    p = 'data/maps/%s/scripts.inc' % m
    return open(p, errors='replace').read() if os.path.exists(p) else ''

# script labels -> maps that use them (by map.json script fields), to catch shared code that moves objects
uses = {}
for p in glob.glob('data/maps/*/map.json'):
    j = json.load(open(p))
    for k in ('object_events', 'coord_events', 'bg_events'):
        for e in j.get(k) or []:
            if e.get('script'): uses.setdefault(e['script'], set()).add(j['name'])
alltext = {f: open(f, errors='replace').read() for f in glob.glob('data/maps/*/scripts.inc') + glob.glob('data/scripts/*.inc')}
MOVERS = re.compile(r'^\s*(setmetatile|setobjectxy|setobjectxyperm|copyobjectxytoperm|setmaplayoutindex)\b', re.M)
risky = set()
for f, t in alltext.items():
    if not MOVERS.search(t): continue
    if f.startswith('data/maps/'): risky.add(f.split('/')[2])
    # labels in this file used by other maps' events
    for lab in re.findall(r'^(\w+)::', t, re.M):
        for m in uses.get(lab, ()): risky.add(m)

out = []
for p in sorted(glob.glob('data/maps/*/map.json')):
    j = json.load(open(p)); m = j['name']
    if reach is not None and m not in reach: continue
    if m in risky: continue
    L = lay.get(j['layout'])
    if not L: continue
    blk = open(L['blockdata_filepath'], 'rb').read(); w, h = L['width'], L['height']
    pa, sa = attrs(L['primary_tileset']), attrs(L['secondary_tileset'])
    conn = {c['direction'] for c in j.get('connections') or []}
    def col(x, y):
        if not (0 <= x < w and 0 <= y < h):
            # past an edge with a connection the neighbouring map may be walkable
            if (y < 0 and 'up' in conn) or (y >= h and 'down' in conn) or (x < 0 and 'left' in conn) or (x >= w and 'right' in conn):
                return 0
            return 1
        return (struct.unpack_from('<H', blk, (y * w + x) * 2)[0] >> 10) & 3
    def beh(x, y):
        if not (0 <= x < w and 0 <= y < h): return 0
        mt = struct.unpack_from('<H', blk, (y * w + x) * 2)[0] & 0x3FF
        a = pa[mt] if mt < 640 else (sa[mt - 640] if mt - 640 < len(sa) else 0)
        return a & 0x1FF
    def sealed(x, y, obj=False):
        if not all(col(a, b) for a, b in ((x, y), (x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1))): return False
        if obj:   # NPCs can be talked to across a counter
            for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                if beh(x + dx, y + dy) == MB_COUNTER and not col(x + 2 * dx, y + 2 * dy): return False
        return True
    land = {(e['x'], e['y']) for e in j.get('warp_events') or []}
    for k, kind in (('object_events', 'obj'), ('bg_events', 'bg'), ('coord_events', 'coord')):
        for i, e in enumerate(j.get(k) or []):
            x, y = e['x'], e['y']
            if kind == 'coord' and (x, y) in land: continue
            dead = col(x, y) != 0 if kind == 'coord' else sealed(x, y, kind == 'obj')   # nobody walks onto a wall
            if dead:
                out.append('%s %s %d %d %d %s %s' % (m, kind, i, x, y, e.get('script'), e.get('flag', e.get('var', ''))))
print('\n'.join(out))
print('#', len(out), 'walled events; skipped maps with setmetatile/object moves:', len(risky), file=sys.stderr)
