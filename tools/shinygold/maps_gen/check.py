#!/usr/bin/env python3
"""Verify a built ROM's map data against the ShinyGold hack ROM.

usage: python3 check.py WORKTREE   (uses WORKTREE/pokefirered.gba + pokefirered.elf)

Parses both ROMs independently (raw struct bytes, no use of the generator's model): map groups/headers,
connections, events, layouts (dims, blockdata, border, tilesets), tileset structs and their decompressed
tiles / palettes / metatiles / attributes, heal locations and whiteout-respawn tables.
Every difference is listed; differences matching a documented intentional fix are classified as such.
Exit status 1 if any unexplained difference remains.
"""
import sys, os, struct, subprocess, collections, json
sys.path.insert(0, '/home/claude/sgx')
from core import Rom, VANILLA_ROM, vanilla_symbols, lz77_decompress
import maps as sgx_maps

HACK = '/home/claude/work/shinygold_patched.gba'

# ---- documented intentional differences (see REPORT.md) ----
BAD_HEADER_LAYOUT_PTR = {(1, 123), (2, 80), (34, 71)}
LAYOUT_WIDTH_FIX = {390: (-1, 62), 401: (-1, 29)}
LAYOUT_OVERWRITTEN = {387}
GARBAGE_UNUSED_LAYOUTS = {385, 405, 487}
CONDOMINIUMS_TILES_FIX = 'gTileset_Condominiums'
HEAL_EXTRA = {21, 22, 23, 24}


def u8(d, o): return d[o]
def u16(d, o): return struct.unpack_from('<H', d, o)[0]
def s16(d, o): return struct.unpack_from('<h', d, o)[0]
def u32(d, o): return struct.unpack_from('<I', d, o)[0]
def s32(d, o): return struct.unpack_from('<i', d, o)[0]
def P(v): return v - 0x08000000 if 0x08000000 <= v < 0x0A000000 else None


class Img:
    def __init__(self, d, groups_off, group_sizes, layouts_off, syms_by_addr):
        self.d = d; self.groups_off = groups_off; self.group_sizes = group_sizes
        self.layouts_off = layouts_off; self.syms = syms_by_addr

    def headers(self):
        out = {}
        for g, n_maps in enumerate(self.group_sizes):
            gp = P(u32(self.d, self.groups_off + 4 * g))
            for n in range(n_maps):
                out[(g, n)] = P(u32(self.d, gp + 4 * n))
        return out

    def layout_ptr(self, lid):
        return P(u32(self.d, self.layouts_off + 4 * (lid - 1)))


def elf_syms(elf):
    out = {}
    for line in subprocess.run(['arm-none-eabi-nm', '-S', elf], capture_output=True, text=True).stdout.split('\n'):
        p = line.split()
        if len(p) == 4: a, s, t, n = int(p[0], 16), int(p[1], 16), p[2], p[3]
        elif len(p) == 3: a, s, t, n = int(p[0], 16), None, p[1], p[2]
        else: continue
        out.setdefault(n, (a, s))
    return out


def main():
    W = sys.argv[1]
    B = open(os.path.join(W, 'pokefirered.gba'), 'rb').read()
    H = open(HACK, 'rb').read()
    V = open(VANILLA_ROM, 'rb').read()
    S = elf_syms(os.path.join(W, 'pokefirered.elf'))
    sym = lambda n: S[n][0] - 0x08000000
    bsyms_by_addr = collections.defaultdict(list)
    for n, (a, s) in S.items():
        if 0x08000000 <= a < 0x0A000000: bsyms_by_addr[a - 0x08000000].append(n)
    vby, vrng = vanilla_symbols()
    vsize = {n: s for a, s, n in vrng}
    vaddr = {n: a for a, s, n in vrng}

    # hack structure
    r = Rom(HACK)
    hgroups, hmaps = sgx_maps.load_map_headers(r)
    hsizes = collections.Counter(m.group for m in hmaps)
    hgs = [hsizes[g] for g in range(len(hgroups))]
    hlay_off = sgx_maps.find_layout_table(r)
    hack = Img(H, sgx_maps.GMAPGROUPS, hgs, hlay_off, None)
    # built structure: group sizes from consecutive gMapGroup_* labels
    gm = sym('gMapGroups')
    gaddrs = [P(u32(B, gm + 4 * g)) for g in range(len(hgs))]
    ends = gaddrs[1:] + [gm]
    bgs = [(e - a) // 4 for a, e in zip(gaddrs, ends)]
    built = Img(B, gm, bgs, sym('gMapLayouts'), None)

    diffs = []      # (category, key, detail, intentional-reason or None)
    def diff(cat, key, detail, why=None): diffs.append((cat, key, detail, why))
    stats = collections.Counter()

    if bgs != hgs:
        # trailing alignment may inflate the last group; compare counts per group strictly
        for g, (a, b) in enumerate(zip(hgs, bgs)):
            if a != b: diff('groups', g, 'map count hack %d built %d' % (a, b))
    hh, bh = hack.headers(), built.headers()
    stats['maps'] = len(hh)
    max_lid = 0
    hack_tilesets, built_tilesets = {}, {}   # name -> addr
    layout_pairs = {}                        # layout id -> (hack layout off, built layout off)
    for key in sorted(hh):
        ho, bo = hh[key], bh.get(key)
        if bo is None: diff('map', key, 'missing in build'); continue
        # ---- header
        hl, bl = u16(H, ho + 0x12), u16(B, bo + 0x12)
        max_lid = max(max_lid, hl)
        if H[ho + 0x10:ho + 0x1C] != B[bo + 0x10:bo + 0x1C]:
            names_ = ['music', 'music', 'layout_id', 'layout_id', 'mapsec', 'cave', 'weather', 'map_type', 'bike', 'flags', 'floor', 'battle']
            for i in range(12):
                if H[ho + 0x10 + i] != B[bo + 0x10 + i]: diff('header', key, '%s %d != %d' % (names_[i], H[ho + 0x10 + i], B[bo + 0x10 + i]))
        stats['headers'] += 1
        hlp, blp = P(u32(H, ho)), P(u32(B, bo))
        if blp != built.layout_ptr(bl): diff('header', key, 'built header layout ptr != gMapLayouts[id-1]')
        if hlp != hack.layout_ptr(hl):
            diff('header', key, 'hack header layout ptr 0x%X != gMapLayouts[%d] (corrupt)' % (u32(H, ho), hl),
                 'corrupt header layout pointer in hack; layout id/table entry used' if key in BAD_HEADER_LAYOUT_PTR else None)
        layout_pairs[hl] = (hack.layout_ptr(hl), built.layout_ptr(bl))
        # ---- connections
        hc, bc = P(u32(H, ho + 0xC)), P(u32(B, bo + 0xC))
        hcl = [] if hc is None else [H[P(u32(H, hc + 4)) + 12 * i:P(u32(H, hc + 4)) + 12 * i + 12] for i in range(s32(H, hc))]
        bcl = [] if bc is None else [B[P(u32(B, bc + 4)) + 12 * i:P(u32(B, bc + 4)) + 12 * i + 12] for i in range(s32(B, bc))]
        if hcl != bcl: diff('connections', key, 'hack %s built %s' % ([x.hex() for x in hcl], [x.hex() for x in bcl]))
        if (hc is None) != (bc is None) and hcl: diff('connections', key, 'NULL-ness differs')
        stats['connections'] += len(hcl)
        # ---- events
        he, be = P(u32(H, ho + 4)), P(u32(B, bo + 4))
        hcnt, bcnt = H[he:he + 4], B[be:be + 4]
        if hcnt != bcnt: diff('events', key, 'counts %s != %s' % (list(hcnt), list(bcnt))); continue
        specs = [(0, 24, [(16, 20)]), (1, 8, []), (2, 16, [(12, 16)]), (3, 12, None)]
        for kind, size, skip in specs:
            hp, bp = P(u32(H, he + 4 + 4 * kind)), P(u32(B, be + 4 + 4 * kind))
            for i in range(hcnt[kind]):
                hr = bytearray(H[hp + size * i:hp + size * (i + 1)]); br = bytearray(B[bp + size * i:bp + size * (i + 1)])
                sk = skip
                if kind == 3:   # bg: script pointer only for signs
                    sk = [(8, 12)] if hr[5] <= 4 else []
                for a, b in sk:
                    hr[a:b] = br[a:b] = b'\0' * (b - a)
                stats[['objects', 'warps', 'coords', 'bgs'][kind]] += 1
                if hr == br: continue
                why = None
                if kind == 0:
                    dif = [k for k in range(24) if hr[k] != br[k]]
                    if hr[2] == 0xFF and set(dif) <= {9, 10, 11, 3, 22, 23}:
                        why = 'clone padding normalized (ignored by engine)'
                    elif hr[2] not in (0, 0xFF) and set(dif) <= {2, 3, 11, 22, 23} and br[2] == 0:
                        why = 'junk object kind/padding normalized (only kind==OBJ_KIND_CLONE is tested; padding unread)'
                    elif set(dif) <= {3, 11, 22, 23}:
                        why = 'object padding normalized'
                diff(['object', 'warp', 'coord', 'bg'][kind], (key, i), 'hack %s built %s' % (hr.hex(), br.hex()), why)
        # clone script fields (bytes 16..19 of clones are excluded above; report normalization)
    # ---- layouts table
    hl_tab = {lid: hack.layout_ptr(lid) for lid in range(1, max_lid + 1)}
    bl_tab = {lid: built.layout_ptr(lid) for lid in range(1, max_lid + 1)}
    used = set(layout_pairs)
    for lid in range(1, max_lid + 1):
        ho, bo = hl_tab[lid], bl_tab[lid]
        if (ho is None) != (bo is None):
            diff('layout_table', lid, 'hack %s built %s' % (ho, bo),
                 'garbage unused layout dropped' if lid in GARBAGE_UNUSED_LAYOUTS and bo is None else None)
            continue
        if ho is None: continue
        stats['layouts'] += 1
        hw, hht, bw, bht = s32(H, ho), s32(H, ho + 4), s32(B, bo), s32(B, bo + 4)
        if lid in LAYOUT_OVERWRITTEN:
            diff('layout', lid, 'struct overwritten by text in hack; minimal layout %dx%d in build' % (bw, bht), 'layout overwritten by text (unreachable map 2.60)')
            continue
        if (hw, hht) != (bw, bht):
            why = 'width -1 in hack (crash); real width recovered' if LAYOUT_WIDTH_FIX.get(lid) == (hw, bw) else None
            diff('layout', lid, 'dims %dx%d != %dx%d' % (hw, hht, bw, bht), why)
        hbw, hbh, bbw, bbh = H[ho + 24], H[ho + 25], B[bo + 24], B[bo + 25]
        hb, bb = P(u32(H, ho + 8)), P(u32(B, bo + 8))
        hm, bm = P(u32(H, ho + 12)), P(u32(B, bo + 12))
        if (hbw, hbh) != (bbw, bbh):
            ok = (bbw, bbh) == (2, 2) and hm - hb == 8 or (bbw, bbh) == (2, 2) and ho % 4
            diff('layout', lid, 'border dims %dx%d -> %dx%d' % (hbw, hbh, bbw, bbh),
                 'garbage border dims (tool wrote a 24-byte header; border data is 2x2)' if ok else None)
        if H[ho + 26:ho + 28] != B[bo + 26:bo + 28]:
            diff('layout', lid, 'tail %s -> %s' % (H[ho + 26:ho + 28].hex(), B[bo + 26:bo + 28].hex()), 'struct padding normalized')
        w, h = bw, bht
        if H[hm:hm + 2 * w * h] != B[bm:bm + 2 * w * h]: diff('layout', lid, 'blockdata differs')
        nb = 2 * bbw * bbh if bbw * bbh else 8
        if H[hb:hb + nb] != B[bb:bb + nb]: diff('layout', lid, 'border data differs')
        stats['blockdata_bytes'] += 2 * w * h
        for k, slot in ((16, 'P'), (20, 'S')):
            ht, bt = P(u32(H, ho + k)), P(u32(B, bo + k))
            hn = (vby.get(ht) or [(None,)])[0][0] if ht is not None else 'NULL'
            hn = next((n for n, s, t in vby.get(ht, []) if n.startswith('gTileset_')), hn) if ht is not None else 'NULL'
            bn = next((n for n in bsyms_by_addr.get(bt, []) if n.startswith('gTileset_')), None) if bt is not None else 'NULL'
            if hn != bn: diff('layout', lid, '%s tileset %s != %s' % (slot, hn, bn))
            if ht is not None and lid in used:
                hack_tilesets.setdefault(hn, (ht, set()))[1].add(slot)
                built_tilesets[bn] = bt
    # ---- tilesets: all referenced by used layouts (with their slots) + every other vanilla tileset struct
    for a, s, n in vrng:
        if n.startswith('gTileset_') and s == 24 and n not in hack_tilesets:
            hack_tilesets[n] = (a, {'S'} if H[a + 1] else {'P'})
            built_tilesets[n] = sym(n)
    for name, (ht, slots) in sorted(hack_tilesets.items()):
        bt = built_tilesets.get(name)
        stats['tilesets'] += 1
        if H[ht:ht + 2] != B[bt:bt + 2]:
            diff('tileset', name, 'flags hack %s built %s' % (H[ht:ht + 2].hex(), B[bt:bt + 2].hex()),
                 'freed LZ tiles replaced by vanilla (compressed) tiles' if name == CONDOMINIUMS_TILES_FIX else None)
        hcb, bcb = u32(H, ht + 16), u32(B, bt + 16)
        hcbn = next((n for n, s, t in vby.get((hcb & ~1) - 0x08000000, [])), None) if hcb else 'NULL'
        bcbn = next((n for n in bsyms_by_addr.get((bcb & ~1) - 0x08000000, [])), None) if bcb else 'NULL'
        if hcbn != bcbn: diff('tileset', name, 'callback %s != %s' % (hcbn, bcbn))
        # tiles as the engine loads them
        nload = 640 if 'P' in slots else 384
        def tiles(d, t, rom):
            p = P(u32(d, t + 4))
            if d[t]:
                if d[p] != 0x10: return None
                return lz77_decompress(d, p)[0]
            return d[p:p + 32 * nload]
        htl, btl = tiles(H, ht, 'h'), tiles(B, bt, 'b')
        if htl is None:
            vtl = lz77_decompress(V, vaddr['gTilesetTiles_Condominiums'])[0]
            diff('tileset', name, 'hack tiles are 0xFF-filled (not LZ); built == vanilla: %s' % (btl == vtl),
                 'freed LZ tiles replaced by vanilla tiles' if name == CONDOMINIUMS_TILES_FIX and btl == vtl else None)
        elif htl != btl:
            diff('tileset', name, 'tiles differ (%d vs %d bytes)' % (len(htl), len(btl)))
        else:
            stats['tile_bytes'] += len(htl)
        # palettes: all 16
        hp, bp = P(u32(H, ht + 8)), P(u32(B, bt + 8))
        if H[hp:hp + 512] != B[bp:bp + 512]: diff('tileset', name, 'palettes differ')
        # metatiles / attributes: hack extents = vanilla symbol sizes (pointers unchanged in the hack)
        for off, kind in ((12, 'Metatiles'), (20, 'MetatileAttributes')):
            hp, bp = P(u32(H, ht + off)), P(u32(B, bt + off))
            vn = next((n for n, s, t in vby.get(hp, []) if n.startswith('g' + kind + '_')), None)
            n = vsize[vn]
            bn = next((x for x in bsyms_by_addr.get(bp, []) if x.startswith('g' + kind + '_')), None)
            bs = S[bn][1] if bn else None
            if bs != n: diff('tileset', name, '%s size %s != %s' % (kind, n, bs))
            if H[hp:hp + n] != B[bp:bp + n]: diff('tileset', name, '%s differ' % kind)
            stats[kind.lower() + '_bytes'] += n
    # ---- heal locations
    HT = 0xA002EC
    bhl = sym('sHealLocations')
    nheal = S['sHealLocations'][1] // 8
    if nheal != 24: diff('heal', None, 'built has %d heal locations' % nheal)
    hwm, hwn = vaddr['sWhiteoutRespawnHealCenterMapIdxs'], vaddr['sWhiteoutRespawnHealerNpcIds']
    bwm, bwn = sym('sWhiteoutRespawnHealCenterMapIdxs'), sym('sWhiteoutRespawnHealerNpcIds')
    for i in range(24):
        if H[HT + 8 * i:HT + 8 * i + 8] != B[bhl + 8 * i:bhl + 8 * i + 8]:
            diff('heal', i + 1, 'location %s != %s' % (H[HT + 8 * i:HT + 8 * i + 8].hex(), B[bhl + 8 * i:bhl + 8 * i + 8].hex()))
        hread = (u16(H, hwm + 4 * i) & 0xFF, u16(H, hwm + 4 * i + 2) & 0xFF, H[hwn + i])
        bread = (u16(B, bwm + 4 * i) & 0xFF, u16(B, bwm + 4 * i + 2) & 0xFF, B[bwn + i])
        stats['heal'] += 1
        if hread != bread:
            diff('heal', i + 1, 'whiteout respawn hack reads %s, built %s' % (hread, bread),
                 'whiteout tables not extended in hack (out-of-bounds read); town PC + nurse chosen' if i + 1 in HEAL_EXTRA else None)

    # ---- output
    unexpected = [d for d in diffs if d[3] is None]
    intentional = [d for d in diffs if d[3] is not None]
    print('compared:', dict(stats))
    byreason = collections.defaultdict(list)
    for c, k, det, why in intentional: byreason[why].append((c, k, det))
    print('\nintentional differences: %d' % len(intentional))
    for why, items in byreason.items():
        print('  [%d] %s' % (len(items), why))
        for c, k, det in items[:200]:
            print('      %s %s: %s' % (c, k, det))
    print('\nUNEXPECTED differences: %d' % len(unexpected))
    for c, k, det, why in unexpected[:300]:
        print('  %s %s: %s' % (c, k, det))
    sys.exit(1 if unexpected else 0)


if __name__ == '__main__':
    main()
