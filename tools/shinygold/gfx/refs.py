import sys, struct
sys.path.insert(0, '/home/claude/work/gfx/scripts')
from gfxlib import *
syms, byaddr = elf_syms()
for n in sys.argv[1:]:
    a = syms[n][0] + 0x08000000
    pat = struct.pack('<I', a)
    def find(d):
        res = []; i = d.find(pat)
        while i >= 0:
            res.append(i); i = d.find(pat, i + 1)
        return res
    print(n, hex(a), 'vanilla refs', [hex(x) for x in find(V)], 'hack refs', [hex(x) for x in find(H)])
