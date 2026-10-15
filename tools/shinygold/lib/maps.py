"""Map / layout / event / connection parsing for ShinyGold."""
import json, os, re, collections
from core import *

GMAPGROUPS = 0x3526a8           # vanilla gMapGroups (hack edits entries in place)
LAYOUT_TABLE_REFS = [0x55194]   # GetMapLayout literal (vanilla code), reads gMapLayouts

MAP_TYPES = {0: 'MAP_TYPE_NONE', 1: 'MAP_TYPE_TOWN', 2: 'MAP_TYPE_CITY', 3: 'MAP_TYPE_ROUTE', 4: 'MAP_TYPE_UNDERGROUND',
             5: 'MAP_TYPE_UNDERWATER', 6: 'MAP_TYPE_OCEAN_ROUTE', 7: 'MAP_TYPE_UNKNOWN', 8: 'MAP_TYPE_INDOOR',
             9: 'MAP_TYPE_SECRET_BASE'}


class Layout:
    pass


class MapH:
    pass


def find_layout_table(rom):
    # the literal used by GetMapLayout(): ldr r1,=gMapLayouts
    # search literal pool after 0x55194 for a pointer in the hack region
    for o in range(0x55190, 0x551b0, 4):
        p = rom.u32(o)
        if Rom.is_rom_ptr(p):
            return p - 0x08000000
    raise RuntimeError('no layout table')


def parse_layout(rom, off):
    L = Layout()
    L.off = off
    L.width = rom.s32(off); L.height = rom.s32(off + 4)
    L.border = rom.ptr(off + 8); L.map = rom.ptr(off + 12)
    L.primary = rom.ptr(off + 16); L.secondary = rom.ptr(off + 20)
    L.bw = rom.u8(off + 24); L.bh = rom.u8(off + 25)
    L.raw_tail = rom.d[off + 26:off + 28]
    rom.mark(off, 28)
    L.blockdata = rom.d[L.map:L.map + 2 * L.width * L.height]
    L.borderdata = rom.d[L.border:L.border + 2 * L.bw * L.bh]
    rom.mark(L.map, 2 * L.width * L.height); rom.mark(L.border, 2 * L.bw * L.bh)
    return L


def load_layouts(rom, max_id):
    T = find_layout_table(rom)
    layouts = {}
    for i in range(max_id):
        p = rom.u32(T + 4 * i)
        rom.mark(T + 4 * i, 4)
        if p == 0:
            layouts[i + 1] = None; continue
        if not Rom.is_rom_ptr(p):
            layouts[i + 1] = None; continue
        layouts[i + 1] = p - 0x08000000
    return T, layouts


def load_map_headers(rom):
    groups = []
    for gi in range(64):
        p = rom.u32(GMAPGROUPS + 4 * gi)
        if not Rom.is_rom_ptr(p): break
        groups.append(p - 0x08000000)
    group_starts = set(groups) | {GMAPGROUPS}
    T = find_layout_table(rom)
    maps = []
    for gi, gp in enumerate(groups):
        n = 0
        while True:
            o = gp + 4 * n
            if n > 0 and o in group_starts: break
            q = rom.u32(o)
            if not Rom.is_rom_ptr(q): break
            h = q - 0x08000000
            lp, ep, sp, cp = [rom.u32(h + 4 * k) for k in range(4)]
            lid = rom.u16(h + 0x12)
            if not (Rom.is_rom_ptr(lp) and Rom.is_rom_ptr(ep) and (sp == 0 or Rom.is_rom_ptr(sp)) and (cp == 0 or Rom.is_rom_ptr(cp))):
                break
            if not (1 <= lid <= 1024) or not Rom.is_rom_ptr(rom.u32(T + 4 * (lid - 1))):
                break
            bad_layout_ptr = rom.u32(T + 4 * (lid - 1)) != lp
            if bad_layout_ptr:
                lp = rom.u32(T + 4 * (lid - 1))
            m = MapH()
            m.group, m.num, m.hdr = gi, n, h
            m.bad_layout_ptr = bad_layout_ptr
            m.layout_ptr = lp - 0x08000000; m.events = ep - 0x08000000
            m.scripts = sp - 0x08000000 if sp else None
            m.connections = cp - 0x08000000 if cp else None
            m.music = rom.u16(h + 0x10); m.layout_id = lid
            m.mapsec = rom.u8(h + 0x14); m.cave = rom.u8(h + 0x15); m.weather = rom.u8(h + 0x16)
            m.map_type = rom.u8(h + 0x17); m.bike = rom.u8(h + 0x18); m.flags = rom.u8(h + 0x19)
            m.floor = rom.s8(h + 0x1A); m.battle = rom.u8(h + 0x1B)
            rom.mark(o, 4); rom.mark(h, 28)
            maps.append(m)
            n += 1
    rom.mark(GMAPGROUPS, 4 * len(groups))
    return groups, maps


def parse_events(rom, off):
    ev = {}
    nobj, nwarp, ncoord, nbg = rom.d[off:off + 4]
    po, pw, pc, pb = [rom.ptr(off + 4 + 4 * k) for k in range(4)]
    rom.mark(off, 20)
    objs = []
    for i in range(nobj):
        o = po + 24 * i
        e = dict(local_id=rom.u8(o), gfx=rom.u8(o + 1), kind=rom.u8(o + 2), pad3=rom.u8(o + 3),
                 x=rom.s16(o + 4), y=rom.s16(o + 6), elevation=rom.u8(o + 8), movement=rom.u8(o + 9),
                 range_byte=rom.u8(o + 10), pad11=rom.u8(o + 11), trainer_type=rom.u16(o + 12),
                 sight=rom.u16(o + 14), script=rom.u32(o + 16), flag=rom.u16(o + 20), pad22=rom.u16(o + 22),
                 raw=rom.d[o:o + 24])
        objs.append(e)
    if nobj: rom.mark(po, 24 * nobj)
    warps = []
    for i in range(nwarp):
        o = pw + 8 * i
        warps.append(dict(x=rom.s16(o), y=rom.s16(o + 2), elevation=rom.u8(o + 4), warp_id=rom.u8(o + 5),
                          map_num=rom.u8(o + 6), map_group=rom.u8(o + 7)))
    if nwarp: rom.mark(pw, 8 * nwarp)
    coords = []
    for i in range(ncoord):
        o = pc + 16 * i
        coords.append(dict(x=rom.s16(o), y=rom.s16(o + 2), elevation=rom.u8(o + 4), pad5=rom.u8(o + 5),
                           var=rom.u16(o + 6), value=rom.u16(o + 8), pad10=rom.u16(o + 10), script=rom.u32(o + 12),
                           raw=rom.d[o:o + 16]))
    if ncoord: rom.mark(pc, 16 * ncoord)
    bgs = []
    for i in range(nbg):
        o = pb + 12 * i
        bgs.append(dict(x=rom.s16(o), y=rom.s16(o + 2), elevation=rom.u8(o + 4), kind=rom.u8(o + 5),
                        pad6=rom.u16(o + 6), arg=rom.u32(o + 8), raw=rom.d[o:o + 12]))
    if nbg: rom.mark(pb, 12 * nbg)
    ev['objects'], ev['warps'], ev['coords'], ev['bgs'] = objs, warps, coords, bgs
    ev['ptrs'] = (po, pw, pc, pb)
    return ev


def parse_connections(rom, off):
    if off is None: return None
    n = rom.u32(off); lp = rom.ptr(off + 4)
    rom.mark(off, 8)
    out = []
    if lp is None: return dict(count=n, ptr=None, list=[])
    for i in range(n):
        o = lp + 12 * i
        out.append(dict(direction=rom.u8(o), pad=rom.d[o + 1:o + 4], offset=rom.s32(o + 4), map_group=rom.u8(o + 8),
                        map_num=rom.u8(o + 9), pad2=rom.d[o + 10:o + 12]))
    rom.mark(lp, 12 * n)
    return dict(count=n, ptr=lp, list=out)


def parse_map_scripts(rom, off):
    """Map script header: list of (type, ptr); type 0 terminates. Types 2,4 (ON_FRAME/ON_WARP_INTO) are tables."""
    if off is None: return None
    out = []
    o = off
    while True:
        t = rom.u8(o)
        if t == 0:
            rom.mark(o, 1)
            break
        p = rom.u32(o + 1)
        rom.mark(o, 5)
        entry = dict(type=t, ptr=p)
        if t in (2, 4) and Rom.is_rom_ptr(p):
            tab = []
            q = p - 0x08000000
            while True:
                var = rom.u16(q)
                if var == 0:
                    rom.mark(q, 2)
                    break
                val = rom.u16(q + 2); sp = rom.u32(q + 4)
                tab.append(dict(var=var, value=val, script=sp))
                rom.mark(q, 8)
                q += 8
            entry['table'] = tab
        out.append(entry)
        o += 5
    return out


def mapsec_names(rom):
    # sMapNames in vanilla, table of pointers indexed by mapsec - MAPSEC_PALLET_TOWN (0x58)
    T = vanilla_addr('sMapNames')
    out = {}
    for i in range(0xC5 - 0x58):
        p = rom.ptr(T + 4 * i)
        out[0x58 + i] = decode_text(rom, p)[0] if p is not None else None
    return out
