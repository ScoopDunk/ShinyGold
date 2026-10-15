"""Verification helpers: compare data in the built decomp ROM against the hack ROM."""
import sys, subprocess, struct, functools
sys.path.insert(0, '/home/claude/sgx'); sys.path.insert(0, '/home/claude/work/engine/tools')
from core import Rom, lz77_decompress
from ctext import cstr

ELF = '/home/claude/wt/engine/pokefirered.elf'
BUILT = Rom('/home/claude/wt/engine/pokefirered.gba')
HACK = Rom()


@functools.lru_cache(None)
def syms():
    out = subprocess.run(['arm-none-eabi-nm', '-S', ELF], capture_output=True, text=True).stdout
    d = {}
    for l in out.splitlines():
        p = l.split()
        if len(p) == 4:
            d.setdefault(p[3], (int(p[0], 16), int(p[1], 16)))
        elif len(p) == 3:
            d.setdefault(p[2], (int(p[0], 16), 0))
    return d


def addr(name):
    return syms()[name][0]


def size(name):
    return syms()[name][1]


def built_bytes(name, n=None):
    a, s = syms()[name]
    n = s if n is None else n
    return BUILT.d[a - 0x08000000:a - 0x08000000 + n]


def lz_built(name):
    return lz77_decompress(BUILT.d, addr(name) - 0x08000000)[0]


def lz_hack(ptr):
    return lz77_decompress(HACK.d, ptr - 0x08000000)[0]


def text_built(ptr):
    return cstr(BUILT, ptr - 0x08000000)[0]


def text_hack(ptr):
    return cstr(HACK, ptr - 0x08000000)[0]


RESULTS = []


def check(label, ok, detail=''):
    RESULTS.append((label, ok, detail))
    print('%-60s %s %s' % (label, 'OK' if ok else 'FAIL', detail))
    return ok
