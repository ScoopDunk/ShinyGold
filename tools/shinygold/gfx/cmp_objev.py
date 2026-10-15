"""Deep compare of object event graphics infos and field effect templates."""
import sys
sys.path.insert(0, '/home/claude/work/gfx/scripts')
from gfxlib import *
syms, byaddr = elf_syms()
def nm(off):
    if off is None: return 'NULL'
    n = byaddr.get(off)
    return n[0] if n else hex(off + 0x08000000)

def cmp_images(hp, vp, n, label):
    out = []
    for i in range(n):
        he, ve = hp + 8 * i, vp + 8 * i
        hdp, vdp = ptr(H, he), ptr(V, ve)
        hs, vs = u16(H, he + 4), u16(V, ve + 4)
        if hdp != vdp or hs != vs:
            out.append('  %s frame %d: ptr %s->%s size %x->%x' % (label, i, nm(vdp), nm(hdp), vs, hs))
        if 0 and H[hdp:hdp + hs] != V[vdp:vdp + vs]:
            out.append('  %s frame %d data differs (%s)' % (label, i, nm(vdp)))
    return out

a, s = syms['gObjectEventGraphicsInfoPointers']
seen = set()
for gid in range(s // 4):
    hi, vi = ptr(H, a + 4 * gid), ptr(V, a + 4 * gid)
    lines = []
    if hi != vi: lines.append('  info ptr %s -> %s' % (nm(vi), nm(hi)))
    hb, vb = H[hi:hi + 0x24], V[vi:vi + 0x24]
    if hb != vb:
        lines.append('  info bytes differ: ' + ' '.join('@%x:%02x->%02x' % (k, vb[k], hb[k]) for k in range(0x24) if hb[k] != vb[k]))
    # images: count unknown; use anim tables? use vanilla symbol size of images table
    himg, vimg = ptr(H, hi + 0x1c), ptr(V, vi + 0x1c)
    vimgname = nm(vimg)
    nimg = syms.get(vimgname, (0, 0))[1] // 8 if vimgname in syms else 1
    if himg != vimg: lines.append('  images ptr %s -> %s' % (vimgname, nm(himg)))
    if (vimg, himg) not in seen:
        seen.add((vimg, himg))
        lines += cmp_images(himg, vimg, nimg, vimgname)
    for off, what in [(0x10, 'oam'), (0x14, 'subspr'), (0x18, 'anims'), (0x20, 'affine')]:
        hp_, vp_ = ptr(H, hi + off), ptr(V, vi + off)
        if hp_ != vp_: lines.append('  %s ptr %s -> %s' % (what, nm(vp_), nm(hp_)))
    if lines:
        print('GFX %d %s' % (gid, nm(vi)))
        print('\n'.join(lines))

print('==== field effects')
a, s = syms['gFieldEffectObjectTemplatePointers']
for i in range(s // 4):
    ht, vt = ptr(H, a + 4 * i), ptr(V, a + 4 * i)
    lines = []
    if vt is None: continue
    if H[vt:vt + 0x18] != V[vt:vt + 0x18]:
        lines.append('  template bytes differ ' + ' '.join('@%x' % k for k in range(0x18) if H[vt + k] != V[vt + k]))
    # SpriteTemplate: u16 tileTag, u16 paletteTag, oam, anims, images, affineAnims, callback
    himg, vimg = ptr(H, ht + 0xc), ptr(V, vt + 0xc)
    if vimg is not None:
        vimgname = nm(vimg)
        nimg = syms.get(vimgname, (0, 8))[1] // 8
        lines += cmp_images(himg, vimg, nimg, vimgname)
    if lines:
        print('FE %d %s' % (i, nm(vt)))
        print('\n'.join(lines))
