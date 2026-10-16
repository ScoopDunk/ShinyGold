"""Delete tilesets no layout uses (header, graphics/metatile definitions and their files).

usage: prune_tilesets.py <tree>
A tileset is kept if any layout uses it or any C file outside src/data/tilesets/ names it. Symbols and files
that something else still references are kept too. METATILE_ labels and animation code are left alone.
"""
import os, re, sys, json, glob, shutil

os.chdir(sys.argv[1])
L = [l for l in json.load(open('data/layouts/layouts.json'))['layouts'] if l]
used = {l['primary_tileset'] for l in L} | {l['secondary_tileset'] for l in L}
H = 'src/data/tilesets/headers.h'; G = 'src/data/tilesets/graphics.h'; M = 'src/data/tilesets/metatiles.h'
hs = open(H).read()
other = ''.join(open(f, errors='replace').read() for f in glob.glob('src/**/*.[ch]', recursive=True) + glob.glob('include/**/*.h', recursive=True)
                if not f.startswith('src/data/tilesets/'))
dead = [t for t in re.findall(r'const struct Tileset (gTileset_\w+)', hs) if t not in used and not re.search(r'\b%s\b' % t, other)]
syms = set()
for t in dead:
    m = re.search(r'const struct Tileset %s =\n\{\n(.*?)\n\};\n\n?' % t, hs, re.S)
    syms.update(re.findall(r'= (g(?:TilesetTiles|TilesetPalettes|Metatiles|MetatileAttributes)_\w+)', m.group(1)))
    hs = hs.replace(m.group(0), '')
open(H, 'w').write(hs)
rest = hs + other
files = []
for p in (G, M):
    s = open(p).read()
    for sym in sorted(syms):
        if re.search(r'\b%s\b' % sym, rest): continue
        m = re.search(r'^const u(?:16|32) %s\[\](?:\[16\])? = (?:INCBIN_U(?:16|32)\("[^"]+"\);|\{.*?\};)\n\n?' % sym, s, re.S | re.M)
        if not m: continue
        files += re.findall(r'"([^"]+)"', m.group(0))
        s = s.replace(m.group(0), '')
    open(p, 'w').write(s)
left = open(G).read() + open(M).read()
gone = 0
for f in files:
    if f in left: continue
    base = re.sub(r'\.(4bpp|8bpp|gbapal)(\.lz)?$|\.lz$', '', f)
    for cand in glob.glob(base + '.*'):
        os.remove(cand); gone += 1
dirs = {os.path.dirname(f) for f in files}
for d in sorted(dirs, key=len, reverse=True):
    if os.path.isdir(d) and not any(d in x for x in re.findall(r'"([^"]+)"', left)):
        shutil.rmtree(d, ignore_errors=True)
        par = os.path.dirname(d)
        if os.path.isdir(par) and not os.listdir(par): os.rmdir(par)
print('removed tilesets:', ' '.join(t[9:] for t in dead), '| files', gone)
