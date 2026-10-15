"""Port ObjectEventGraphicsInfo field changes (paletteTag / paletteSlot / other bitfields)."""
import sys, re, os
sys.path.insert(0, '/home/claude/work/gfx/scripts')
from gfxlib import *
syms, byaddr = elf_syms()
src = open(os.path.join(WT, 'src/event_object_movement.c')).read()
TAGS = {int(v, 16): n for n, v in re.findall(r'#define\s+(OBJ_EVENT_PAL_TAG_\w+)\s+(0x[0-9A-Fa-f]+)', src)}
hdr = open(os.path.join(WT, 'include/event_object_movement.h')).read()
enum = re.search(r'enum\s*\{\s*(PALSLOT_PLAYER,.*?)\}', hdr, re.S).group(1)
SLOTS = [x.strip() for x in enum.split(',') if x.strip()]
p = os.path.join(WT, 'src/data/object_events/object_event_graphics_info.h')
txt = open(p).read()
a, s = syms['gObjectEventGraphicsInfoPointers']
done = set()
for gid in range(s // 4):
    vi, hi = ptr(V, a + 4 * gid), ptr(H, a + 4 * gid)
    assert vi == hi
    if V[vi:vi + 0x24] == H[vi:vi + 0x24] or vi in done: continue
    done.add(vi)
    name = byaddr[vi][0]
    diff = [k for k in range(0x24) if V[vi + k] != H[vi + k]]
    assert set(diff) <= {2, 0xc}, (name, diff)
    m = re.search(r'(const struct ObjectEventGraphicsInfo %s = \{\n)(.*?)(\n\};)' % name, txt, re.S)
    body = m.group(2)
    if 2 in diff:
        ot, nt = u16(V, vi + 2), u16(H, vi + 2)
        body, k = re.subn(r'(\.paletteTag = )%s,' % TAGS[ot], r'\g<1>%s, // ShinyGold: was %s' % (TAGS[nt], TAGS[ot]), body)
        assert k == 1
    if 0xc in diff:
        ob, nb = V[vi + 0xc], H[vi + 0xc]
        assert (ob & 0xf0) == (nb & 0xf0), name
        os_, ns = SLOTS[ob & 0xf], SLOTS[nb & 0xf]
        body, k = re.subn(r'(\.paletteSlot = )%s,' % os_, r'\g<1>%s, // ShinyGold: was %s' % (ns, os_), body)
        assert k == 1
    txt = txt[:m.start(2)] + body + txt[m.end(2):]
    print(name, diff)
open(p, 'w').write(txt)
