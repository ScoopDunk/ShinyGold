"""Shared helpers for the gfx worker."""
import sys, os, re, struct, bisect, functools, subprocess
sys.path.insert(0, '/home/claude/sgx')
from core import lz77_decompress, is_lz77

HACK = '/home/claude/work/shinygold_patched.gba'
VAN = '/home/claude/work/vanilla_fr10.gba'
VDIR = '/home/claude/vanilla'
WT = '/home/claude/wt/gfx'

H = open(HACK, 'rb').read()
V = open(VAN, 'rb').read()


def u16(d, o): return struct.unpack_from('<H', d, o)[0]
def u32(d, o): return struct.unpack_from('<I', d, o)[0]
def ptr(d, o):
    p = u32(d, o)
    return p - 0x08000000 if 0x08000000 <= p < 0x09000000 else None


@functools.lru_cache(None)
def elf_syms(elf=os.path.join(VDIR, 'pokefirered.elf')):
    """name -> (addr_off, size) for ROM data/text symbols."""
    out = {}
    byaddr = {}
    txt = subprocess.run(['arm-none-eabi-nm', '-S', elf], capture_output=True, text=True).stdout
    for line in txt.splitlines():
        p = line.split()
        if len(p) == 4:
            a, s, t, n = int(p[0], 16), int(p[1], 16), p[2], p[3]
        elif len(p) == 3:
            a, t, n = int(p[0], 16), p[1], p[2]; s = 0
        else:
            continue
        if not (0x08000000 <= a < 0x09000000): continue
        out.setdefault(n, (a - 0x08000000, s))
        byaddr.setdefault(a - 0x08000000, []).append(n)
    return out, byaddr


INCBIN_RE = re.compile(r'(?:static\s+)?const\s+(?:u8|u16|u32)\s+(\w+)\s*\[[^\]]*\]\s*=\s*INCBIN_U(?:8|16|32)\(\s*"([^"]+)"\s*\)')


@functools.lru_cache(None)
def incbin_map(root=VDIR):
    """symbol -> (srcfile, path) for simple 'const T sym[] = INCBIN_Ux("path");' declarations."""
    out = {}
    for dp, dn, fn in os.walk(os.path.join(root, 'src')):
        for f in fn:
            if not f.endswith(('.c', '.h')): continue
            p = os.path.join(dp, f)
            s = open(p, errors='replace').read()
            for m in INCBIN_RE.finditer(s):
                out.setdefault(m.group(1), (os.path.relpath(p, root), m.group(2)))
    return out


def decomp(d, off):
    return lz77_decompress(d, off)
