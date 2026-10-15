"""For layouts whose garbage border dims were normalized to 2x2: does the hack's effective border (engine
GetBorderBlockAt with the garbage dims) differ from the normalized one in the area the camera can show, and
can the camera actually get there (passable tiles near the map edge)?"""
import sys, struct, json
sys.path.insert(0, '/home/claude/work/maps/gen')
import sgmaps
D = sgmaps.load_all()
r = D['rom']
mn = sgmaps.MAP_NAMES
reach = {}
for M in D['maps']:
    reach.setdefault(M.layout_id, []).append((M.key, M.name, mn[M.key]['reachable']))
def mod(a, b):
    if b == 0: return 0          # libgcc __modsi3 divide-by-zero path returns 0
    q = abs(a) % abs(b)
    return -q if a < 0 else q    # C semantics
rows = []
for lid, bw, bh in D['lay_notes']['border']:
    L = D['layouts'][lid]
    if L is None or lid not in reach: continue
    off = L.off
    bp = r.ptr(off + 8)
    w, h = L.width, L.height
    def hack_border(x, y):
        xp = mod(x + 8 * bw, bw) if bw else 0
        yp = mod(y + 8 * bh, bh) if bh else 0
        i = xp + yp * bw
        return struct.unpack_from('<H', r.d, bp + 2 * i)[0] & 0x3FF
    def norm_border(x, y):
        i = (x % 2) + 2 * (y % 2)
        return struct.unpack_from('<H', L.border, 2 * i)[0] & 0x3FF
    differ = False
    for y in range(-6, h + 6):
        for x in range(-8, w + 8):
            if 0 <= x < w and 0 <= y < h: continue
            if hack_border(x, y) != norm_border(x, y): differ = True
    blocks = struct.unpack_from('<%dH' % (w * h), L.blockdata)
    # flood fill from the warps of the maps using this layout over passable tiles
    seen = set(); todo = []
    for M in D['maps']:
        if M.layout_id != lid: continue
        for wv in M.json['warp_events']:
            if 0 <= wv['x'] < w and 0 <= wv['y'] < h: todo.append((wv['x'], wv['y']))
    while todo:
        x, y = todo.pop()
        if (x, y) in seen or not (0 <= x < w and 0 <= y < h): continue
        seen.add((x, y))
        for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            nx, ny = x + dx, y + dy
            if 0 <= nx < w and 0 <= ny < h and (blocks[ny * w + nx] >> 10) & 3 == 0: todo.append((nx, ny))
    near = sum(1 for (x, y) in seen if x < 7 or x >= w - 7 or y < 5 or y >= h - 5)
    rows.append((lid, bw, bh, differ, near, reach[lid]))
vis = [x for x in rows if x[3] and x[4] and any(rr[2] for rr in x[5])]
print('normalized layouts used by maps: %d; effective border differs: %d; differs AND passable tiles within camera range of an edge on a reachable map: %d' % (len(rows), sum(1 for x in rows if x[3]), len(vis)))
for x in vis: print('  layout %d dims %dx%d reachable-tiles-near-edge %d maps %s' % (x[0], x[1], x[2], x[4], x[5]))
