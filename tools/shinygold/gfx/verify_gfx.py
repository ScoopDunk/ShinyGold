"""Verify that every graphics table/entry owned by the gfx worker resolves to identical data in the built ROM and the hack.

Walks pointer graphs from root tables in parallel in the hack ROM (vanilla symbol addresses) and the built ROM
(addresses from the built ELF). Pointers are matched by symbol name (+offset); where the hack points to data
that has no vanilla symbol (new data) the payloads are compared (LZ77-decompressed when compressed).
Leaf graphics (INCBIN data) are compared byte-for-byte (decompressed for .lz).
"""
import sys, os, re, bisect, struct, subprocess
sys.path.insert(0, '/home/claude/work/gfx/scripts')
from gfxlib import *

BUILT_ROM = sys.argv[1] if len(sys.argv) > 1 else os.path.join(WT, 'pokefirered.gba')
BUILT_ELF = sys.argv[2] if len(sys.argv) > 2 else os.path.join(WT, 'pokefirered.elf')
B = open(BUILT_ROM, 'rb').read()

def load_syms(elf):
    txt = subprocess.run(['arm-none-eabi-nm', '-S', elf], capture_output=True, text=True).stdout
    by = {}; ranges = []; types = {}
    for line in txt.splitlines():
        p = line.split()
        if len(p) != 4: continue
        a, s, t, n = int(p[0], 16), int(p[1], 16), p[2], p[3]
        if not (0x08000000 <= a < 0x09000000) or s == 0: continue
        a -= 0x08000000
        by.setdefault(n, (a, s)); types[n] = t
        ranges.append((a, s, n))
    ranges.sort()
    return by, ranges, types

VS, VR, VT = load_syms(os.path.join(VDIR, 'pokefirered.elf'))
BS, BR, BT = load_syms(BUILT_ELF)
VSTARTS = [r[0] for r in VR]; BSTARTS = [r[0] for r in BR]
IB = incbin_map(WT)

def resolve(ranges, starts, off):
    i = bisect.bisect_right(starts, off) - 1
    # prefer the innermost symbol containing off
    best = None
    j = i
    while j >= 0 and j > i - 8:
        a, s, n = ranges[j]
        if a <= off < a + s:
            if best is None or s < best[2]: best = (n, off - a, s)
        j -= 1
    return (best[0], best[1]) if best else None

def lzdata(d, off):
    try: return decomp(d, off)[0]
    except Exception: return None

KNOWN = {}   # symbol -> explanation for accepted differences
checked = set(); fails = []; UNUSED = set(); stats = {'struct': 0, 'leaf': 0, 'newdata': 0, 'ptr': 0}

def is_leaf(name):
    return name in IB or name.startswith(('gObjectEventPaletteNull',))

def leaf_cmp(name):
    va, vs = VS[name]; ba, bs = BS[name]
    path = IB.get(name, ('', ''))[1]
    stats['leaf'] += 1
    if path.endswith('.lz'):
        hd, bd = lzdata(H, va), lzdata(B, ba)
        if hd != bd:
            if hd is not None and bd is not None and len(hd) > len(bd) and hd[:len(bd)] == bd and not any(hd[len(bd):]):
                KNOWN[name] = 'hack LZ stream has %d trailing zero bytes beyond the %d-byte sheet (dropped)' % (len(hd) - len(bd), len(bd))
                return
            fails.append('LEAF %s (lz) differs' % name)
    else:
        if H[va:va + vs] != B[ba:ba + bs]:
            fails.append('LEAF %s differs (%d vs %d bytes)' % (name, vs, bs))

def payload_cmp(hoff, bname, bdelta, ctx):
    """hack pointer hoff has no vanilla symbol: compare its payload with built symbol payload."""
    stats['newdata'] += 1
    ba, bs = BS[bname]
    path = IB.get(bname, ('', ''))[1]
    if path.endswith('.lz') and bdelta == 0:
        hd, bd = lzdata(H, hoff), lzdata(B, ba)
        if hd != bd:
            if hd and bd and len(hd) > len(bd) and hd[:len(bd)] == bd and not any(hd[len(bd):]):
                KNOWN[bname] = 'trailing zero bytes in hack LZ stream dropped'; return
            fails.append('NEWDATA %s: hack @%07x vs built %s differ' % (ctx, hoff, bname))
    else:
        n = bs - bdelta
        if H[hoff:hoff + n] != B[ba + bdelta:ba + bs]:
            fails.append('NEWDATA %s: hack @%07x vs built %s+%x differ' % (ctx, hoff, bname, bdelta))

def struct_cmp(name, depth=0):
    if name in checked: return
    checked.add(name)
    if name not in VS and name not in BS:
        UNUSED.add(name); return
    if name not in VS or name not in BS:
        fails.append('MISSING symbol %s (vanilla %s built %s)' % (name, name in VS, name in BS)); return
    t = VT.get(name, 'r')
    if t in 'tT': return  # code: matched by name only
    if is_leaf(name):
        leaf_cmp(name); return
    va, vs = VS[name]; ba, bs = BS[name]
    stats['struct'] += 1
    if vs != bs:
        fails.append('SIZE %s %x vs %x' % (name, vs, bs)); return
    k = 0
    while k < vs:
        vw = struct.unpack_from('<I', V, va + k)[0] if k + 4 <= vs else None
        if vw is not None and (va + k) % 4 == 0 and 0x08000000 <= vw < 0x08eb0b20 and resolve(VR, VSTARTS, vw - 0x08000000):
            hw = struct.unpack_from('<I', H, va + k)[0]
            bw = struct.unpack_from('<I', B, ba + k)[0]
            stats['ptr'] += 1
            rb = resolve(BR, BSTARTS, bw - 0x08000000) if 0x08000000 <= bw < 0x09000000 else None
            if not (0x08000000 <= hw < 0x09000000):
                if hw != bw: fails.append('PTR %s+%x: hack %08x built %08x' % (name, k, hw, bw))
            else:
                rh = resolve(VR, VSTARTS, hw - 0x08000000)
                if rh is not None and rh[0].endswith('_End') is False and rh == rb:
                    struct_cmp(rh[0], depth + 1)
                elif rh is not None and rb is not None and rh == rb:
                    struct_cmp(rh[0], depth + 1)
                elif rb is None:
                    fails.append('PTR %s+%x: built %08x unresolved (hack %s)' % (name, k, bw, rh))
                elif rh is None:
                    payload_cmp(hw - 0x08000000, rb[0], rb[1], '%s+%x' % (name, k))
                else:
                    # different symbols: acceptable only if payloads equal (e.g. aliasing)
                    fails.append('PTR %s+%x: hack -> %s+%x, built -> %s+%x' % (name, k, rh[0], rh[1], rb[0], rb[1]))
            k += 4
        else:
            if H[va + k] != B[ba + k]:
                fails.append('BYTE %s+%x: hack %02x built %02x' % (name, k, H[va + k], B[ba + k]))
            k += 1

ROOTS = ['gMonFrontPicTable', 'gMonBackPicTable', 'gMonPaletteTable', 'gMonShinyPaletteTable', 'gMonIconTable',
         'gMonIconPaletteTable', 'gMonIconPaletteIndices', 'gMonFootprintTable', 'gMonFrontPicCoords', 'gMonBackPicCoords',
         'gTrainerFrontPicTable', 'gTrainerFrontPicPaletteTable', 'gTrainerFrontPicCoords', 'gTrainerFrontAnimsPtrTable',
         'gTrainerBackPicTable', 'gTrainerBackPicPaletteTable', 'gTrainerBackPicCoords', 'gTrainerBackAnimsPtrTable',
         'gTrainerBackPicTable_Red', 'gTrainerBackPicTable_Leaf',
         'gObjectEventGraphicsInfoPointers', 'sObjectEventSpritePalettes', 'sPlayerReflectionPaletteTags',
         'gReflectionEffectPaletteMap', 'gFieldEffectObjectTemplatePointers', 'gSpritePalette_GeneralFieldEffect0',
         'gSpritePalette_GeneralFieldEffect1', 'sItemIconTable', 'sGfx_Emoticons', 'sRival_Gfx']
# every data symbol defined in the object-event / field-effect data headers and field_effect.c
for f in ['src/data/object_events/object_event_graphics.h', 'src/data/object_events/object_event_pic_tables.h',
          'src/data/object_events/object_event_graphics_info.h', 'src/data/field_effects/field_effect_objects.h',
          'src/data/graphics/items.h', 'src/data/graphics/trainers.h', 'src/data/graphics/pokemon.h']:
    s = open(os.path.join(WT, f)).read()
    for n in re.findall(r'^(?:static\s+)?const\s+(?:struct\s+)?\w+\s+(?:\*\s*const\s+)?(\w+)\s*(?:\[[^\]]*\])?\s*=', s, re.M):
        if n not in ROOTS: ROOTS.append(n)

# Symbols the hack no longer references (table pointers moved away). Their bytes in the hack ROM are stale or
# were overwritten in place, so they are not compared as live data.
ORPHANS = set()
def collect_orphans():
    for t, stride in [('gTrainerFrontPicTable', 8), ('gTrainerFrontPicPaletteTable', 8), ('gMonFrontPicTable', 8), ('sItemIconTable', 4)]:
        a, s = VS[t]
        for k in range(0, s, stride):
            vp, hp = ptr(V, a + k), ptr(H, a + k)
            if vp != hp and H.find(struct.pack('<I', vp + 0x08000000)) < 0:
                ORPHANS.add(resolve(VR, VSTARTS, vp)[0])
collect_orphans()
ORPHANS.discard(None)

for r in ROOTS:
    if r in ORPHANS: continue
    struct_cmp(r)

# naming-screen rival icon palette (anonymous rodata struct inside NamingScreen_CreateRivalIcon)
hp = ptr(H, 0x3e23c8); htag = u16(H, 0x3e23cc)
hname = resolve(VR, VSTARTS, hp)
pat = struct.pack('<IH', BS[hname[0]][0] + 0x08000000, htag)
found = B.find(pat)
nm_ok = found >= 0 and (VS['sRival_Gfx'] and True)
print('naming screen rival palette: hack -> %s (tag %#x); built ROM struct %s' % (hname[0], htag, ('found @%07x' % found) if found >= 0 else 'NOT FOUND'))
if found < 0: fails.append('naming screen rival palette struct not found')

print('roots: %d, structs compared: %d, pointers matched: %d, leaf graphics compared: %d, new-data payloads compared: %d'
      % (len(ROOTS), stats['struct'], stats['ptr'], stats['leaf'], stats['newdata']))
print('orphaned vanilla symbols (no longer referenced by the hack, skipped):', ', '.join(sorted(ORPHANS)))
print('declared but not linked in either ROM (unused, skipped):', ', '.join(sorted(UNUSED)))
for k, v in sorted(KNOWN.items()):
    print('ACCEPTED %s: %s' % (k, v))
for f in fails: print('FAIL', f)
print('RESULT: %d differences' % len(fails))
sys.exit(1 if fails else 0)
