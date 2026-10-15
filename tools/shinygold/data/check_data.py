#!/usr/bin/env python3
"""Verify that the data tables in the built decomp ROM equal the ShinyGold hack ROM's tables.

Reads table addresses from the built ELF (nm) for the built ROM and from the vanilla symbol list for the hack ROM
(none of these tables were repointed by the hack; party/learnset/description pointers are followed).
Comparison is semantic: strings compared up to their 0xFF terminator, pointers dereferenced, struct padding ignored.

Usage: python3 check_data.py [WORKTREE]   (exit status 1 on any difference)
"""
import sys, os, struct, subprocess, collections
sys.path.insert(0, '/home/claude/sgx')
from core import *

WT = sys.argv[1] if len(sys.argv) > 1 else '/home/claude/wt/data'
H = Rom()
B = Rom(os.path.join(WT, 'pokefirered.gba'))

# ---- symbol tables
bsyms = {}
baddr_name = collections.defaultdict(list)
for l in subprocess.run(['arm-none-eabi-nm', os.path.join(WT, 'pokefirered.elf')], capture_output=True, text=True).stdout.splitlines():
    p = l.split()
    if len(p) != 3: continue
    a = int(p[0], 16)
    if not (0x08000000 <= a < 0x0A000000): continue
    bsyms.setdefault(p[2], a - 0x08000000)
    baddr_name[a - 0x08000000].append(p[2])


def hsym(n):
    a = vanilla_addr(n)
    assert a is not None, n
    return a


def bsym(n):
    return bsyms[n]


def bname(addr):
    """name of built-ROM pointer target (function/data)"""
    if addr == 0: return 'NULL'
    o = (addr & ~1) - 0x08000000
    n = [x for x in baddr_name.get(o, []) if not x.startswith('$')]
    return sorted(n)[0] if n else hex(addr)


def hname(addr):
    if addr == 0: return 'NULL'
    o = (addr & ~1) - 0x08000000
    by, _ = vanilla_symbols()
    n = [x[0] for x in by.get(o, []) if not x[0].startswith('$')]
    return sorted(n)[0] if n else hex(addr)


def s_at(R, off, maxlen=4096):
    """bytes of an FF-terminated string"""
    e = R.d.index(b'\xff', off)
    assert e - off < maxlen + 1
    return bytes(R.d[off:e])


def s_fixed(R, off, n):
    raw = bytes(R.d[off:off + n])
    return raw[:raw.index(0xFF)] if 0xFF in raw else raw


def deref_str(R, p):
    return s_at(R, p - 0x08000000) if p else None


results = []


def compare(name, recs_h, recs_b, show=5):
    diffs = [(i, a, b) for i, (a, b) in enumerate(zip(recs_h, recs_b)) if a != b]
    if len(recs_h) != len(recs_b):
        diffs.append(('len', len(recs_h), len(recs_b)))
    results.append((name, len(recs_h), len(diffs)))
    print('%-28s entries=%4d  differences=%d' % (name, len(recs_h), len(diffs)))
    for d in diffs[:show]:
        print('    ', d)


# ================================================================== trainers
MONSZ = {0: 8, 1: 16, 2: 8, 3: 16}


def trainers(R, base):
    out = []
    for i in range(743):
        o = base + 40 * i
        f = R.u8(o)
        t = dict(flags=f, cls=R.u8(o + 1), music=R.u8(o + 2), pic=R.u8(o + 3), name=s_fixed(R, o + 4, 12),
                 items=[R.u16(o + 16 + 2 * k) for k in range(4)], double=R.u8(o + 24), ai=R.u32(o + 28),
                 size=R.u8(o + 32))
        p = R.u32(o + 36)
        mons = []
        if p:
            po = p - 0x08000000
            for k in range(t['size']):
                m = po + MONSZ[f & 3] * k
                d = (R.u16(m), R.u8(m + 2), R.u16(m + 4))
                q = m + 6
                if f & 2: d += (R.u16(q),); q += 2
                if f & 1: d += tuple(R.u16(q + 2 * j) for j in range(4))
                mons.append(d)
        else:
            mons = None
        t['party'] = mons
        out.append(t)
    return out


compare('gTrainers(+parties)', trainers(H, hsym('gTrainers')), trainers(B, bsym('gTrainers')))
compare('gTrainerClassNames', [s_fixed(H, hsym('gTrainerClassNames') + 13 * i, 13) for i in range(107)],
        [s_fixed(B, bsym('gTrainerClassNames') + 13 * i, 13) for i in range(107)])


def money(R, base):
    out = []
    i = 0
    while True:
        c, v = R.u8(base + 4 * i), R.u8(base + 4 * i + 1)
        out.append((c, v))
        if c == 0xFF: break
        i += 1
    return out


compare('gTrainerMoneyTable', money(H, hsym('gTrainerMoneyTable')), money(B, bsym('gTrainerMoneyTable')))

# ================================================================== pokemon
def raw_entries(R, base, size, n, mask=None):
    out = []
    for i in range(n):
        b = bytes(R.d[base + size * i: base + size * (i + 1)])
        if mask: b = bytes(x for k, x in enumerate(b) if k not in mask)
        out.append(b)
    return out


compare('gSpeciesInfo', raw_entries(H, hsym('gSpeciesInfo'), 28, 412, {26, 27}),
        raw_entries(B, bsym('gSpeciesInfo'), 28, 412, {26, 27}))


def evos(R, base):
    return [[struct.unpack_from('<HHH', R.d, base + 40 * i + 8 * j) for j in range(5)] for i in range(412)]


compare('gEvolutionTable', evos(H, hsym('gEvolutionTable')), evos(B, bsym('gEvolutionTable')))
compare('sTMHMLearnsets', raw_entries(H, hsym('sTMHMLearnsets'), 8, 412), raw_entries(B, bsym('sTMHMLearnsets'), 8, 412))
compare('sTMHMMoves', raw_entries(H, hsym('sTMHMMoves'), 2, 58), raw_entries(B, bsym('sTMHMMoves'), 2, 58))


def trades(R, base):
    out = []
    for i in range(9):
        o = base + 60 * i
        out.append((s_fixed(R, o, 11), R.u16(o + 12), bytes(R.d[o + 14:o + 21]), R.u32(o + 24), bytes(R.d[o + 28:o + 33]),
                    R.u32(o + 36), R.u16(o + 40), R.u8(o + 42), s_fixed(R, o + 43, 11), R.u8(o + 54), R.u8(o + 55),
                    R.u16(o + 56)))
    return out


compare('sInGameTrades', trades(H, hsym('sInGameTrades')), trades(B, bsym('sInGameTrades')))

# ================================================================== items
def items(R, base, nm):
    out = []
    for i in range(375):
        a = base + 44 * i
        out.append((s_fixed(R, a, 14), R.u16(a + 14), R.u16(a + 16), R.u8(a + 18), R.u8(a + 19),
                    deref_str(R, R.u32(a + 20)), R.u8(a + 24), R.u8(a + 25), R.u8(a + 26), R.u8(a + 27),
                    nm(R.u32(a + 28)), R.u8(a + 32), nm(R.u32(a + 36)), R.u32(a + 40)))
    return out


compare('gItems(+descriptions)', items(H, hsym('gItems'), hname), items(B, bsym('gItems'), bname))


def icons(R, base, nm):
    return [(nm(R.u32(base + 8 * i)), nm(R.u32(base + 8 * i + 4))) for i in range(377)]


compare('sItemIconTable', icons(H, hsym('sItemIconTable'), hname), icons(B, bsym('sItemIconTable'), bname))

# ================================================================== unchanged-by-hack tables (regression guard)
def ptr_strs(R, base, n):
    return [deref_str(R, R.u32(base + 4 * i)) for i in range(n)]


def learnsets(R, base):
    out = []
    for i in range(412):
        p = R.u32(base + 4 * i) - 0x08000000
        ls = []
        while R.u16(p) != 0xFFFF:
            ls.append(R.u16(p)); p += 2
        out.append(ls)
    return out


def item_effects(R, base):
    out = []
    for i in range(163):
        p = R.u32(base + 4 * i)
        out.append(bytes(R.d[p - 0x08000000:p - 0x08000000 + 6]) if p else None)
    return out


def dex(R, base):
    out = []
    for i in range(387):
        o = base + 36 * i
        out.append((bytes(R.d[o:o + 12]), R.u16(o + 12), R.u16(o + 14), deref_str(R, R.u32(o + 16)),
                    deref_str(R, R.u32(o + 20)) if R.u32(o + 20) else None, bytes(R.d[o + 24:o + 36])))
    return out


def egg(R, base):
    out = []
    o = base
    while True:
        v = R.u16(o); out.append(v); o += 2
        if v == 0xFFFF: break
    return out


for nm, size, n in [('gSpeciesNames', 11, 412), ('gMoveNames', 13, 355), ('gBattleMoves', 12, 355), ('gTypeEffectiveness', 1, 336),
                    ('gExperienceTables', 4, 808), ('gAbilityNames', 13, 78), ('sTutorLearnsets', 2, 412),
                    ('gTypeNames', 7, 18), ('sSpeciesToNationalPokedexNum', 2, 411), ('sSpeciesToHoennPokedexNum', 2, 411),
                    ('sHoennToNationalOrder', 2, 411)]:
    compare(nm, raw_entries(H, hsym(nm), size, n), raw_entries(B, bsym(nm), size, n))
compare('gMoveDescriptionPointers', ptr_strs(H, hsym('gMoveDescriptionPointers'), 354), ptr_strs(B, bsym('gMoveDescriptionPointers'), 354))
compare('gAbilityDescriptionPointers', ptr_strs(H, hsym('gAbilityDescriptionPointers'), 78), ptr_strs(B, bsym('gAbilityDescriptionPointers'), 78))
compare('gLevelUpLearnsets', learnsets(H, hsym('gLevelUpLearnsets')), learnsets(B, bsym('gLevelUpLearnsets')))
compare('gItemEffectTable', item_effects(H, hsym('gItemEffectTable')), item_effects(B, bsym('gItemEffectTable')))
compare('gPokedexEntries', dex(H, hsym('gPokedexEntries')), dex(B, bsym('gPokedexEntries')))
compare('gEggMoves', egg(H, hsym('gEggMoves')), egg(B, bsym('gEggMoves')))

total = sum(r[2] for r in results)
print('TOTAL differences:', total)
sys.exit(1 if total else 0)
