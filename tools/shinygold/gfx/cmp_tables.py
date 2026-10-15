"""Compare graphics tables (hack vs vanilla) semantically."""
import sys
sys.path.insert(0, '/home/claude/work/gfx/scripts')
from gfxlib import *
syms, byaddr = elf_syms()

def name_at(off):
    n = byaddr.get(off)
    return n[0] if n else None

def getdata(d, off, lz, size=None):
    if off is None: return None
    if lz:
        try:
            return decomp(d, off)[0]
        except Exception as e:
            return ('ERR', str(e))
    return d[off:off + size]

def cmp_table(tname, stride, ptr_off, lz, rawsize=None, sizefield=None, extra=None):
    a, s = syms[tname]
    n = s // stride
    out = []
    for i in range(n):
        e = a + i * stride
        hv, vv = H[e:e + stride], V[e:e + stride]
        hp, vp = ptr(H, e + ptr_off), ptr(V, e + ptr_off)
        rs = rawsize
        if sizefield is not None:
            rs = u16(V, e + sizefield)
        hd = getdata(H, hp, lz, rs if rs else 0x20)
        vd = getdata(V, vp, lz, rs if rs else 0x20)
        flags = []
        if hv != vv:
            flags.append('ENTRY')
            if hp != vp: flags.append('PTR %s->%s(%s)' % (name_at(vp), hex(hp + 0x08000000) if hp is not None else None, name_at(hp)))
            if hv[4:] != vv[4:]: flags.append('FIELDS %s->%s' % (vv[4:].hex(), hv[4:].hex()))
        if hd != vd:
            flags.append('DATA')
            if isinstance(hd, bytes) and isinstance(vd, bytes) and len(hd) != len(vd):
                flags.append('LEN %d->%d' % (len(vd), len(hd)))
        if flags:
            out.append('%s[%d] (%s): %s' % (tname, i, name_at(vp), ' '.join(flags)))
    return out

res = []
res += cmp_table('gMonFrontPicTable', 8, 0, True)
res += cmp_table('gMonBackPicTable', 8, 0, True)
res += cmp_table('gMonPaletteTable', 8, 0, True)
res += cmp_table('gMonShinyPaletteTable', 8, 0, True)
res += cmp_table('gMonIconTable', 4, 0, False, rawsize=0x400)
res += cmp_table('gMonIconPaletteTable', 8, 0, False, rawsize=0x20)
res += cmp_table('gMonFootprintTable', 4, 0, False, rawsize=0x20)
res += cmp_table('gTrainerFrontPicTable', 8, 0, True)
res += cmp_table('gTrainerFrontPicPaletteTable', 8, 0, True)
res += cmp_table('gTrainerBackPicPaletteTable', 8, 0, True)
res += cmp_table('gTrainerBackPicTable', 8, 0, False, sizefield=4)
res += cmp_table('gTrainerBackPicTable_Red', 8, 0, False, sizefield=4)
res += cmp_table('gTrainerBackPicTable_Leaf', 8, 0, False, sizefield=4)
res += cmp_table('sObjectEventSpritePalettes', 8, 0, False, rawsize=0x20)
for r in res: print(r)
# raw compares of small tables
for t in ['gMonIconPaletteIndices', 'gMonFrontPicCoords', 'gMonBackPicCoords', 'gTrainerFrontPicCoords', 'gTrainerBackPicCoords',
          'gEnemyMonElevation', 'gTrainerFrontAnimsPtrTable', 'gTrainerBackAnimsPtrTable', 'gReflectionEffectPaletteMap',
          'sPlayerReflectionPaletteTags', 'gObjectEventGraphicsInfoPointers', 'gFieldEffectObjectTemplatePointers', 'sItemIconTable']:
    a, s = syms[t]
    diffs = [i for i in range(s) if H[a + i] != V[a + i]]
    print('RAW %s: %d bytes differ %s' % (t, len(diffs), [hex(x) for x in diffs[:20]]))
