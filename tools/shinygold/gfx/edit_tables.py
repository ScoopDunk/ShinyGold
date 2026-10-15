"""Apply table-level (C) edits: trainer palette sharing."""
import sys, re, os
sys.path.insert(0, '/home/claude/work/gfx/scripts')
from gfxlib import *
syms, byaddr = elf_syms()
p = os.path.join(WT, 'src/data/trainer_graphics/front_pic_tables.h')
lines = open(p).read().split('\n')
a, s = syms['gTrainerFrontPicPaletteTable']
start = next(i for i, l in enumerate(lines) if 'gTrainerFrontPicPaletteTable[]' in l)
entries = [i for i in range(start, len(lines)) if lines[i].strip().startswith('TRAINER_PAL(')]
assert len(entries) == s // 8, (len(entries), s // 8)
n = 0
for idx, li in enumerate(entries):
    hp, vp = ptr(H, a + 8 * idx), ptr(V, a + 8 * idx)
    assert H[a + 8 * idx + 4:a + 8 * idx + 8] == V[a + 8 * idx + 4:a + 8 * idx + 8]
    vname = byaddr[vp][0]
    m = re.match(r'(\s*TRAINER_PAL\((\w+),\s*)(\w+)(\),?)\s*$', lines[li])
    assert m and m.group(3) == vname, (lines[li], vname)
    if hp == vp: continue
    hname = byaddr[hp][0]
    assert hname.startswith('gTrainerPalette_'), hname
    lines[li] = '%s%s%s // ShinyGold: shares %s (was %s)' % (m.group(1), hname, m.group(4), hname, vname)
    n += 1
open(p, 'w').write('\n'.join(lines))
print('edited', n)
