"""Helpers to extract hack graphics into decomp source formats and to verify them."""
import os, sys, struct, subprocess, tempfile
sys.path.insert(0, '/home/claude/sgx')
from core import Rom, lz77_decompress

WT = '/home/claude/wt/engine'
GBAGFX = WT + '/tools/gbagfx/gbagfx'
HACK = Rom()
VAN = Rom('/home/claude/work/vanilla_fr10.gba')


def off(p):
    return p - 0x08000000 if p >= 0x08000000 else p


def lz(rom, p):
    return lz77_decompress(rom.d, off(p))


def write_jasc(path, pal_bytes):
    cols = struct.unpack('<%dH' % (len(pal_bytes) // 2), pal_bytes)
    lines = ['JASC-PAL', '0100', str(len(cols))]
    for c in cols:
        r, g, b = c & 31, (c >> 5) & 31, (c >> 10) & 31
        lines.append('%d %d %d' % (r * 8, g * 8, b * 8))
    open(path, 'w', newline='\r\n').write('\n'.join(lines) + '\n')


def gbapal_from_jasc(path):
    out = bytearray()
    lines = open(path).read().split()
    n = int(lines[2])
    vals = list(map(int, lines[3:3 + 3 * n]))
    for i in range(n):
        r, g, b = vals[3 * i:3 * i + 3]
        out += struct.pack('<H', (r >> 3) | ((g >> 3) << 5) | ((b >> 3) << 10))
    return bytes(out)


def tiles_to_png(raw, png_path, pal_path, width_tiles, bpp=4):
    """Write raw tile data as an indexed PNG; verify the PNG converts back to the same bytes."""
    ext = '.4bpp' if bpp == 4 else '.8bpp'
    tsize = 32 if bpp == 4 else 64
    assert len(raw) % tsize == 0
    with tempfile.TemporaryDirectory() as td:
        src = os.path.join(td, 'x' + ext)
        open(src, 'wb').write(raw)
        args = [GBAGFX, src, png_path, '-width', str(width_tiles)]
        if pal_path:
            args += ['-palette', pal_path]
        subprocess.run(args, check=True)
        back = os.path.join(td, 'y' + ext)
        ntiles = len(raw) // tsize
        subprocess.run([GBAGFX, png_path, back, '-num_tiles', str(ntiles)], check=True)
        rb = open(back, 'rb').read()
        assert rb == raw, 'png roundtrip mismatch for %s' % png_path
    return len(raw) // tsize


def gbapal_file(pal_bytes, path):
    """Write a temporary .gbapal for gbagfx -palette."""
    open(path, 'wb').write(pal_bytes)
    return path


def tiles4_to_png_banked(raw, png_path, pal_bytes, width_tiles, tile_banks):
    """4bpp tiles -> 8-bit indexed PNG whose pixel values are bank*16+color (like vanilla multi-palette PNGs).
    gbagfx keeps only the low 4 bits when converting back. Verifies the roundtrip."""
    from PIL import Image
    ntiles = len(raw) // 32
    h_tiles = (ntiles + width_tiles - 1) // width_tiles
    im = Image.new('P', (width_tiles * 8, h_tiles * 8), 0)
    cols = struct.unpack('<%dH' % (len(pal_bytes) // 2), pal_bytes)
    flat = []
    for c in cols:
        flat += [(c & 31) * 8, ((c >> 5) & 31) * 8, ((c >> 10) & 31) * 8]
    flat += [0] * (768 - len(flat))
    im.putpalette(flat)
    px = im.load()
    for t in range(ntiles):
        bank = tile_banks.get(t, 0)
        tx, ty = (t % width_tiles) * 8, (t // width_tiles) * 8
        for y in range(8):
            for x in range(8):
                b = raw[t * 32 + y * 4 + x // 2]
                v = (b >> 4) if (x & 1) else (b & 15)
                px[tx + x, ty + y] = bank * 16 + v
    im.save(png_path)
    with tempfile.TemporaryDirectory() as td:
        back = os.path.join(td, 'y.4bpp')
        subprocess.run([GBAGFX, png_path, back, '-num_tiles', str(ntiles)], check=True)
        assert open(back, 'rb').read() == raw, 'banked png roundtrip mismatch'
    return ntiles


def tilemap_banks(tilemap_bytes_list):
    banks = {}
    for tm in tilemap_bytes_list:
        for i in range(len(tm) // 2):
            e = struct.unpack_from('<H', tm, 2 * i)[0]
            banks.setdefault(e & 0x3FF, e >> 12)
    return banks
