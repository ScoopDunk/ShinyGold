import sys
sys.path.insert(0, '/home/claude/work/gfx/scripts')
from gfxlib import *
syms, byaddr = elf_syms()
ib = incbin_map()
rows = []
for name, (src, path) in sorted(ib.items(), key=lambda kv: syms.get(kv[0], (0, 0))[0]):
    if name not in syms:
        continue
    a, s = syms[name]
    if s == 0: continue
    if H[a:a + s] == V[a:a + s]:
        continue
    nb = sum(1 for i in range(s) if H[a + i] != V[a + i])
    info = ''
    if path.endswith('.lz'):
        try:
            hv, hl = decomp(H, a)
            vv, vl = decomp(V, a)
            info = 'lz hackcomp=%d vancomp=%d decomp_eq=%s hsize=%d vsize=%d%s' % (hl, vl, hv == vv, len(hv), len(vv), ' OVERFLOW' if hl > s else '')
        except Exception as e:
            info = 'lz hack-not-lz (%s)' % e
    print('%07x %5x %4d %-45s %-40s %s %s' % (a, s, nb, name, path, info, src))
