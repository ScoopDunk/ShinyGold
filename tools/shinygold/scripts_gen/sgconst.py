"""Constant / symbol rendering for the ShinyGold script disassembler.

All map/flag/var/trainer/... names come from the shared naming contract (/home/claude/sgx/names.py).
RAM and native-function references are resolved against the vanilla ELF and (if present) the engine
worker's symbol files.
"""
import os, re, json, bisect, functools, subprocess, sys
sys.path.insert(0, '/home/claude/sgx')
from core import *
import names as N

ENGINE_DIR = '/home/claude/work/engine'
RAM_SYMS_JSON = os.path.join(ENGINE_DIR, 'ram_symbols.json')
NATIVE_SYMS_JSON = os.path.join(ENGINE_DIR, 'native_symbols.json')
VANILLA_ELF = os.path.join(VANILLA_DIR, 'pokefirered.elf')


def fmt_num(v):
    if v < 0x100:
        return str(v)
    return '0x%X' % v


def hexw(v):
    return '0x%X' % v


def is_var(v):
    return 0x4000 <= v <= 0x40FF or 0x8000 <= v <= 0x8014


@functools.lru_cache(None)
def _rev_prefix(prefix, fname=None, exclude_suffix=('_COUNT', '_START', '_END')):
    vals, files, order = c_constants()
    rev = {}
    for n in order:
        if n not in vals or not n.startswith(prefix):
            continue
        if fname and files.get(n) != fname:
            continue
        if any(n.endswith(s) for s in exclude_suffix):
            continue
        rev.setdefault(vals[n], n)
    return rev


def const_or_num(prefix, v, fname=None):
    n = _rev_prefix(prefix, fname).get(v)
    return n if n else fmt_num(v)


STD_NAMES = {0: 'STD_OBTAIN_ITEM', 1: 'STD_FIND_ITEM', 2: 'MSGBOX_NPC', 3: 'MSGBOX_SIGN', 4: 'MSGBOX_DEFAULT',
             5: 'MSGBOX_YESNO', 6: 'MSGBOX_AUTOCLOSE', 7: 'STD_OBTAIN_DECORATION', 8: 'STD_PUT_ITEM_AWAY',
             9: 'STD_RECEIVED_ITEM'}
FADE_NAMES = {0: 'FADE_FROM_BLACK', 1: 'FADE_TO_BLACK', 2: 'FADE_FROM_WHITE', 3: 'FADE_TO_WHITE'}
DIR_NAMES = {0: 'DIR_NONE', 1: 'DIR_SOUTH', 2: 'DIR_NORTH', 3: 'DIR_WEST', 4: 'DIR_EAST'}
STRVAR_NAMES = {0: 'STR_VAR_1', 1: 'STR_VAR_2', 2: 'STR_VAR_3'}


def localid(v):
    if is_var(v):
        return N.var_name(v)
    if v == 255:
        return 'LOCALID_PLAYER'
    if v == 127:
        return 'LOCALID_CAMERA'
    return str(v)


def var_or(v, f):
    if is_var(v):
        return N.var_name(v)
    return f(v)


def special_name(i):
    sl = specials_list()
    return sl[i] if i < len(sl) else None


# ------------------------------------------------------------------ RAM symbols
@functools.lru_cache(None)
def _vanilla_ram_syms():
    out = subprocess.run(['arm-none-eabi-nm', '-n', '-S', VANILLA_ELF], capture_output=True, text=True).stdout
    syms = []
    for line in out.splitlines():
        p = line.split()
        if len(p) == 4:
            a, s, t, n = int(p[0], 16), int(p[1], 16), p[2], p[3]
        elif len(p) == 3:
            a, s, t, n = int(p[0], 16), 0, p[1], p[2]
        else:
            continue
        if not (0x02000000 <= a < 0x04000000):
            continue
        if n.startswith('$') or t in 'aA' or n.endswith('_START') or n.endswith('_END'):
            continue
        syms.append((a, s, t, n))
    syms.sort()
    # fill missing sizes with distance to next symbol
    res = []
    for i, (a, s, t, n) in enumerate(syms):
        if s == 0:
            nxt = next((x[0] for x in syms[i + 1:] if x[0] > a), a + 1)
            s = nxt - a
            sized = False
        else:
            sized = True
        res.append((a, s, t, n, sized))
    return res


@functools.lru_cache(None)
def _engine_ram():
    if os.path.exists(RAM_SYMS_JSON):
        d = json.load(open(RAM_SYMS_JSON))
        out = {}
        for k, v in d.items():
            try:
                out[int(k, 16)] = v
            except ValueError:
                pass
        return out
    return {}


@functools.lru_cache(None)
def _engine_native():
    if os.path.exists(NATIVE_SYMS_JSON):
        d = json.load(open(NATIVE_SYMS_JSON))
        out = {}
        for k, v in d.items():
            try:
                out[int(k, 16)] = v
            except ValueError:
                pass
        return out
    return {}


def ram_symbol(addr):
    """Return (expr, kind) for a RAM address. kind: 'vanilla', 'engine', 'placeholder', 'other'."""
    eng = _engine_ram()
    if addr in eng:
        return eng[addr], 'engine'
    # engine file may give base symbols with sizes as "name" only; also accept containing ranges "name+off"
    syms = _vanilla_ram_syms()
    A = [s[0] for s in syms]
    i = bisect.bisect_right(A, addr) - 1
    # prefer a global sized symbol that contains addr
    cands = []
    j = i
    while j >= 0 and j > i - 64:
        a, s, t, n, sized = syms[j]
        if a <= addr < a + s and t.isupper():
            cands.append((0 if sized else 1, a, n))
        j -= 1
    in_hack_ram = 0x0203C000 <= addr < 0x0203CEC4 or 0x02022000 <= addr < 0x02022000 + 0x100
    if cands and not in_hack_ram:
        cands.sort(key=lambda x: (x[0], -x[1]))
        _, a, n = cands[0]
        return (n if a == addr else '%s + 0x%X' % (n, addr - a)), 'vanilla'
    if 0x02000000 <= addr < 0x04000000:
        return 'SG_RAM_0x%08X' % addr, 'placeholder'
    return None, 'other'


def native_symbol(val):
    """val is the raw 32-bit native pointer. Returns (expr, kind)."""
    eng = _engine_native()
    if val in eng:
        return eng[val], 'engine'
    if (val | 1) in eng:
        return eng[val | 1], 'engine'
    if (val & ~1) in eng:
        return eng[val & ~1], 'engine'
    off = (val & ~1) - 0x08000000
    if 0 <= off < 0x71A000:
        by_addr, rng = vanilla_symbols()
        names = by_addr.get(off)
        if names:
            for n, s, t in names:
                if t in 'Tt' and not n.startswith('$'):
                    if t == 'T':
                        return n, 'vanilla'
            # static function: not linkable from asm
    return 'SG_NATIVE_0x%08X' % val, 'placeholder'
