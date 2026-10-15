import sys, struct
sys.path.insert(0, '/home/claude/work/engine/tools')
from verify import *

H = HACK.d
# section tables (MAPSEC_COUNT entries of 2 u16)
for sym, hoff in (('sMapSectionTopLeftCorners', 0x3f1e60), ('sMapSectionDimensions', 0x3f2178)):
    b = built_bytes(sym)
    check(sym + ' bytes == hack', b == H[hoff:hoff + len(b)], 'len %d' % len(b))
for sym, hoff in (('sRegionMapSections_Kanto', 0x3f2490), ('sRegionMapSections_Sevii123', 0x3f2724),
                  ('sRegionMapSections_Sevii45', 0x3f29b8), ('sRegionMapSections_Sevii67', 0x3f2c4c)):
    b = built_bytes(sym)
    check(sym + ' bytes == hack', b == H[hoff:hoff + len(b)], 'len %d' % len(b))
# map names (texts)
n = 0x6D
bad = []
for i in range(n):
    bp = struct.unpack_from('<I', BUILT.d, addr('sMapNames') - 0x08000000 + 4 * i)[0]
    hp = struct.unpack_from('<I', H, 0x3f1cac + 4 * i)[0]
    if text_built(bp) != text_hack(hp):
        bad.append((hex(0x58 + i), text_built(bp), text_hack(hp)))
check('sMapNames texts == hack (%d entries)' % n, not bad, str(bad[:3]))
# dungeon info names / ids / descs
bad = []
for i in range(19):
    bo = addr('sDungeonInfo') - 0x08000000 + 12 * i
    bid, bn, bd = struct.unpack_from('<III', BUILT.d, bo)
    hid, hn, hd = struct.unpack_from('<III', H, 0x3f1b3c + 12 * i)
    if (bid & 0xFF) != (hid & 0xFF) or text_built(bn) != text_hack(hn) or text_built(bd) != text_hack(hd):
        bad.append(i)
check('sDungeonInfo ids/names/descs == hack', not bad, str(bad))
# fly destinations (3 bytes per entry); MAP_PALLET_TOWN/MAP_ROUTE2 name collisions resolve to vanilla
# values in a standalone build, see report
b = built_bytes('sMapFlyDestinations')
h = H[0x3f2ee0:0x3f2ee0 + len(b)]
diff = [i // 3 for i in range(len(b)) if b[i] != h[i]]
diff = sorted(set(diff))
check('sMapFlyDestinations == hack except name-collision entries', all((h[3*i], h[3*i+1]) in ((3, 12), (3, 58)) for i in diff),
      'differing entries: %s' % [hex(0x58 + i) for i in diff])
# effective region selection (InitRegionMapType)
def region_hack(ms):
    hook = [0xa3, 0x9f, 0xac, 0xa6, 0xa8, 0xb5, 0xb7, 0xa7, 0xa4]
    if ms == 0x98: return 1
    if ms in hook: return 3
    if ms <= 0x8d: return 0
    base = 0x3f1aa4
    for j in range(3):
        i = 0
        while H[base + 30 * j + i] != 0xc5:
            if H[base + 30 * j + i] == ms: return j + 1
            i += 1
    return None
def region_built(ms):
    lst = [0xa3, 0x9f, 0xac, 0xa6, 0xa8, 0xb5, 0xb7, 0xa7, 0xa4]
    r = 0
    if ms in lst: r = 3
    if ms == 0x98: return 1
    if r: return r
    if ms < 0x8e: return 0
    a = addr('sSeviiMapsecs') - 0x08000000
    w = size('sSeviiMapsecs') // 3
    for j in range(3):
        i = 0
        while BUILT.d[a + w * j + i] != 0xc5:
            if BUILT.d[a + w * j + i] == ms: return j + 1
            i += 1
    return None
bad = [(hex(m), region_hack(m), region_built(m)) for m in range(0x58, 0xc5) if region_hack(m) != region_built(m)]
check('region map selected per mapsec == hack (0x58-0xC4)', not bad, str(bad))
# graphics
check('sRegionMap_Gfx (decompressed) == hack 0x08891000', lz_built('sRegionMap_Gfx') == lz_hack(0x08891000))
check('sRegionMap_Pal == hack', built_bytes('sRegionMap_Pal') == H[0x3ef2dc:0x3ef2dc + 0xa0])
for sym, p in (('sKanto_Tilemap', 0x08890060), ('sSevii123_Tilemap', 0x08890610), ('sSevii67_Tilemap', 0x08891E70)):
    check(sym + ' == first 1200 bytes of hack tilemap', lz_built(sym) == lz_hack(p)[:1200])
check('sPlayerIcon_Red == hack 0x0882BBE8', lz_built('sPlayerIcon_Red') == lz_hack(0x0882BBE8))
check('sPlayerIcon_Leaf == hack 0x0882BC68', lz_built('sPlayerIcon_Leaf') == lz_hack(0x0882BC68))
