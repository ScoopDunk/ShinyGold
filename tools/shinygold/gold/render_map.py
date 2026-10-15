"""Render a decomp map layout (FireRed format) to PNG.  render.py <tree> <MapName|LAYOUT_ID> <out.png> [x0 y0 x1 y1] [--grid]"""
import sys, os, re, json, struct
sys.path.insert(0, '/home/claude/sgx')
from PIL import Image, ImageDraw
from core import lz77_decompress

def load_syms(tree):
    syms = {}
    for f in ['src/graphics.c', 'src/data/tilesets/graphics.h', 'src/data/tilesets/metatiles.h']:
        s = open(os.path.join(tree, f)).read()
        for m in re.finditer(r'const u(?:16|32) (gTileset(?:Tiles|Palettes)_\w+|gMetatiles_\w+)\[\](?:\[16\])?\s*=\s*(\{.*?\};|INCBIN_U(?:16|32)\("([^"]+)"\);)', s, re.S):
            name = m.group(1)
            if m.group(3): syms[name] = [m.group(3)]
            else: syms[name] = re.findall(r'"([^"]+)"', m.group(2))
    ts = {}; cur = None
    for line in open(os.path.join(tree, 'src/data/tilesets/headers.h')):
        m = re.match(r'const struct Tileset (gTileset_\w+)', line)
        if m: cur = m.group(1); ts[cur] = {}
        m = re.search(r'\.(tiles|palettes|metatiles|isCompressed) = (\w+)', line)
        if m and cur: ts[cur][m.group(1)] = m.group(2)
    return syms, ts

def read_bin(tree, path):
    if path.endswith('.lz') and os.path.exists(os.path.join(tree, path[:-3])):
        path = path[:-3]
    p = os.path.join(tree, path)
    if os.path.exists(p): d = open(p, 'rb').read()
    else: d = None
    if path.endswith('.lz'):
        if d is None:
            raise FileNotFoundError(p)
        d = lz77_decompress(d, 0)
    return d

class Tileset:
    def __init__(self, tree, sym, syms, ts):
        t = ts[sym]
        self.tiles = read_bin(tree, syms[t['tiles']][0])
        self.pals = []
        for p in syms[t['palettes']]:
            d = read_bin(tree, p)
            self.pals.append([((c & 31) << 3, ((c >> 5) & 31) << 3, ((c >> 10) & 31) << 3) for c in struct.unpack('<16H', d[:32])])
        md = read_bin(tree, syms[t['metatiles']][0])
        self.meta = struct.unpack('<%dH' % (len(md) // 2), md)

def render(tree, layout, out, box=None, grid=False):
    syms, ts = load_syms(tree)
    L = layout
    prim = Tileset(tree, L['primary_tileset'], syms, ts); sec = Tileset(tree, L['secondary_tileset'], syms, ts)
    pals = prim.pals[:7] + sec.pals[7:13] + [[(0, 0, 0)] * 16] * 3
    blk = open(os.path.join(tree, L['blockdata_filepath']), 'rb').read()
    w, h = L['width'], L['height']
    x0, y0, x1, y1 = box or (0, 0, w, h)
    img = Image.new('RGB', ((x1 - x0) * 16, (y1 - y0) * 16))
    px = img.load()
    def tile(tid):
        if tid < 640: data = prim.tiles; i = tid
        else: data = sec.tiles; i = tid - 640
        o = i * 32
        return data[o:o + 32] if o + 32 <= len(data) else bytes(32)
    cache = {}
    def mt_img(mt):
        if mt in cache: return cache[mt]
        meta = prim.meta if mt < 640 else sec.meta
        i = mt if mt < 640 else mt - 640
        ents = meta[i * 8:i * 8 + 8] if i * 8 + 8 <= len(meta) else [0] * 8
        im = [[None] * 16 for _ in range(16)]
        for layer in range(2):
            for q in range(4):
                e = ents[layer * 4 + q]
                tid, hf, vf, pal = e & 0x3FF, (e >> 10) & 1, (e >> 11) & 1, e >> 12
                t = tile(tid)
                ox, oy = (q % 2) * 8, (q // 2) * 8
                for yy in range(8):
                    for xx in range(8):
                        b = t[yy * 4 + xx // 2]; c = (b >> 4) if xx & 1 else (b & 15)
                        if layer == 1 and c == 0: continue
                        sx = 7 - xx if hf else xx; sy = 7 - yy if vf else yy
                        im[oy + sy][ox + sx] = pals[pal][c] if c else (0, 0, 0)
        cache[mt] = im
        return im
    for y in range(y0, y1):
        for x in range(x0, x1):
            if not (0 <= x < w and 0 <= y < h): continue
            v = struct.unpack_from('<H', blk, (y * w + x) * 2)[0]
            im = mt_img(v & 0x3FF)
            for yy in range(16):
                row = im[yy]
                for xx in range(16):
                    if row[xx] is not None: px[(x - x0) * 16 + xx, (y - y0) * 16 + yy] = row[xx]
    if grid:
        d = ImageDraw.Draw(img)
        for x in range(x0, x1):
            if x % 5 == 0: d.line([((x - x0) * 16, 0), ((x - x0) * 16, img.size[1])], fill=(255, 0, 255))
        for y in range(y0, y1):
            if y % 5 == 0: d.line([(0, (y - y0) * 16), (img.size[0], (y - y0) * 16)], fill=(255, 0, 255))
    img.save(out)
    return img

def layout_for(tree, name):
    lay = {l['id']: l for l in json.load(open(os.path.join(tree, 'data/layouts/layouts.json')))['layouts'] if l}
    if name.startswith('LAYOUT_'): return lay[name], None
    j = json.load(open(os.path.join(tree, 'data/maps/%s/map.json' % name)))
    return lay[j['layout']], j

if __name__ == '__main__':
    tree, name, out = sys.argv[1:4]
    rest = [a for a in sys.argv[4:] if not a.startswith('--')]
    box = tuple(int(v) for v in rest[:4]) if len(rest) >= 4 else None
    L, j = layout_for(tree, name)
    img = render(tree, L, out, box, '--grid' in sys.argv)
    if j and '--events' in sys.argv:
        d = ImageDraw.Draw(img)
        x0, y0 = (box or (0, 0))[:2]
        for w in j.get('warp_events') or []:
            d.rectangle([(w['x'] - x0) * 16, (w['y'] - y0) * 16, (w['x'] - x0) * 16 + 15, (w['y'] - y0) * 16 + 15], outline=(255, 0, 0))
        for o in j.get('object_events') or []:
            d.rectangle([(o['x'] - x0) * 16 + 3, (o['y'] - y0) * 16 + 3, (o['x'] - x0) * 16 + 12, (o['y'] - y0) * 16 + 12], outline=(0, 255, 255))
        img.save(out)
    print(img.size)
