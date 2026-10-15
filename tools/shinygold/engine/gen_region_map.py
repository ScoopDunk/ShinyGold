"""Generate the region map data of ShinyGold for the decomp:
src/data/region_map/region_map_sections.json, region_map_layout_*.h, and C snippets for region_map.c.
"""
import sys, json, struct, re, collections
sys.path.insert(0, '/home/claude/sgx'); sys.path.insert(0, '/home/claude/work/engine/tools')
from core import Rom
from names import mapsec_const, map_const, heal_location_const
from ctext import cstr

WT = '/home/claude/wt/engine'
VAN_JSON = '/home/claude/vanilla/src/data/region_map/region_map_sections.json'
H = Rom()
V = Rom('/home/claude/work/vanilla_fr10.gba')

S_MAP_NAMES = 0x3f1cac
S_TOPLEFT = 0x3f1e60
S_DIMS = 0x3f2178
S_LAYOUTS = {'kanto': 0x3f2490, 'sevii_123': 0x3f2724, 'sevii_45': 0x3f29b8, 'sevii_67': 0x3f2c4c}
S_LAYOUT_SYMS = {'kanto': 'Kanto', 'sevii_123': 'Sevii123', 'sevii_45': 'Sevii45', 'sevii_67': 'Sevii67'}
S_SEVII_MAPSECS = 0x3f1aa4
S_FLY = 0x3f2ee0
KANTO_START = 0x58
NUM_NAMED = 0x6D  # 0x58..0xC4
MAPSEC_NONE = 0xC5


def hack_name(i):
    p = H.u32(S_MAP_NAMES + 4 * i) - 0x08000000
    return cstr(H, p)[0]


def gen_json():
    van = json.load(open(VAN_JSON))
    out = []
    for v, e in enumerate(van['map_sections']):
        if KANTO_START <= v < KANTO_START + NUM_NAMED:
            i = v - KANTO_START
            x, y = struct.unpack_from('<HH', H.d, S_TOPLEFT + 4 * i)
            w, h = struct.unpack_from('<HH', H.d, S_DIMS + 4 * i)
            out.append(collections.OrderedDict([('id', mapsec_const(v)), ('name', hack_name(i)),
                                                ('x', x), ('y', y), ('width', w), ('height', h)]))
        else:
            assert e['id'] == mapsec_const(v)
            out.append(e)
    return {'map_sections': out}


def gen_layout(key):
    base = S_LAYOUTS[key]
    lines = ['static const u8 sRegionMapSections_%s[LAYER_COUNT][MAP_HEIGHT][MAP_WIDTH] = {' % S_LAYOUT_SYMS[key]]
    for layer, lname in ((0, 'LAYER_MAP'), (1, 'LAYER_DUNGEON')):
        lines.append('    [%s] =' % lname)
        lines.append('    {')
        for y in range(15):
            row = [mapsec_const(H.u8(base + layer * 15 * 22 + y * 22 + x)) for x in range(22)]
            lines.append('        {' + ', '.join(row) + '},')
        lines.append('    },')
    lines.append('};')
    return '\n'.join(lines) + '\n'


def gen_sevii_mapsecs():
    lines = ['static const u8 sSeviiMapsecs[3][30] = {']
    for r, rname in enumerate(('REGIONMAP_SEVII123', 'REGIONMAP_SEVII45', 'REGIONMAP_SEVII67')):
        lines.append('    [%s - 1] =' % rname)
        lines.append('    {')
        vals = [H.u8(S_SEVII_MAPSECS + 30 * r + k) for k in range(30)]
        # trailing zero padding after MAPSEC_NONE is implicit
        last = max(k for k in range(30) if vals[k] != 0)
        for k in range(last + 1):
            lines.append('        %s,' % mapsec_const(vals[k]))
        lines[-1] = lines[-1].rstrip(',')
        lines.append('    },')
    lines.append('};')
    return '\n'.join(lines) + '\n'


def gen_fly():
    lines = ['static const u8 sMapFlyDestinations[][3] = {']
    n = 0x144 // 3
    for i in range(n):
        g, m, heal = H.d[S_FLY + 3 * i:S_FLY + 3 * i + 3]
        ms = mapsec_const(KANTO_START + i)
        lines.append('    [%-28s - KANTO_MAPSEC_START] = {MAP(%s), %s},' % (ms, map_const(g, m),
                     heal_location_const(heal) if heal else 'HEAL_LOCATION_NONE'))
    lines.append('};')
    return '\n'.join(lines) + '\n'


def vanilla_aliases():
    """#defines for vanilla MAPSEC_ names whose value now has a ShinyGold name."""
    van = json.load(open(VAN_JSON))['map_sections']
    out = []
    for v, e in enumerate(van):
        if e['id'] != mapsec_const(v):
            out.append((e['id'], mapsec_const(v)))
    return out


if __name__ == '__main__':
    j = gen_json()
    open(WT + '/src/data/region_map/region_map_sections.json', 'w').write(json.dumps(j, indent=2, ensure_ascii=False) + '\n')
    for k in S_LAYOUTS:
        open(WT + '/src/data/region_map/region_map_layout_%s.h' % k, 'w').write(gen_layout(k))
    open('/home/claude/work/engine/rm_sevii_mapsecs.c', 'w').write(gen_sevii_mapsecs())
    open('/home/claude/work/engine/rm_fly.c', 'w').write(gen_fly())
    al = vanilla_aliases()
    open('/home/claude/work/engine/rm_aliases.txt', 'w').write('\n'.join('%s %s' % a for a in al) + '\n')
    print('aliases', len(al))
