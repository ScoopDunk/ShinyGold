import sys, os, glob
from PIL import Image, ImageDraw
TMP='/home/claude/work/gfx/tmp'
pat = sys.argv[1]; out = sys.argv[2]; scale = int(sys.argv[3]) if len(sys.argv) > 3 else 2; cols = int(sys.argv[4]) if len(sys.argv) > 4 else 4
files = sorted(f for f in glob.glob(os.path.join(TMP, '*.png')) if pat in f)
pairs = []
for f in files:
    rel = os.path.basename(f).replace('__', '/')[:-4].replace('.4bpp', '') + '.png'
    old = Image.open(os.path.join('/home/claude/vanilla', rel)).convert('RGBA')
    new = Image.open(f).convert('RGBA')
    pairs.append((rel, old, new))
cw = max(o.size[0] + n.size[0] for _, o, n in pairs) * scale + 12
ch = max(max(o.size[1], n.size[1]) for _, o, n in pairs) * scale + 14
rows = (len(pairs) + cols - 1) // cols
img = Image.new('RGBA', (cw * cols, ch * rows), (200, 200, 220, 255))
d = ImageDraw.Draw(img)
for k, (rel, o, n) in enumerate(pairs):
    x, y = (k % cols) * cw, (k // cols) * ch
    d.text((x, y), rel.split('/')[-1][:22], fill=(0, 0, 0, 255))
    img.paste(o.resize((o.size[0] * scale, o.size[1] * scale), Image.NEAREST), (x, y + 12))
    img.paste(n.resize((n.size[0] * scale, n.size[1] * scale), Image.NEAREST), (x + o.size[0] * scale + 4, y + 12))
img.save(out)
print(out, img.size)
