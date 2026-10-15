"""Regenerate the decomp's PNG/PAL sources from ShinyGold data.

Usage: python3 port_gfx.py [--dry]
Writes into the gfx worktree. Each job is verified by forward-converting with the exact Makefile command
and comparing against the hack's (decompressed) bytes.
"""
import sys, os, re, subprocess, shutil, struct, tempfile, json
sys.path.insert(0, '/home/claude/work/gfx/scripts')
from gfxlib import *
from PIL import Image

GBAGFX = os.path.join(WT, 'tools/gbagfx/gbagfx')
TMP = '/home/claude/work/gfx/tmp'
os.makedirs(TMP, exist_ok=True)
syms, byaddr = elf_syms()
ib = incbin_map()
DRY = '--dry' in sys.argv

def sym(n): return syms[n][0]
def run(cmd):
    r = subprocess.run(cmd, cwd=WT, capture_output=True, text=True)
    if r.returncode != 0:
        raise RuntimeError('%s failed: %s %s' % (cmd, r.stdout, r.stderr))
    return r

# ------------------------------------------------------------------ hack data helpers
def hack_lz(off):
    return decomp(H, off)[0]

def tbl_ptr(table, idx, stride=8, d=H):
    return ptr(d, sym(table) + idx * stride)

def hack_trainer_front(idx):
    return hack_lz(tbl_ptr('gTrainerFrontPicTable', idx))[:0x800]

def hack_trainer_front_pal(idx):
    return hack_lz(tbl_ptr('gTrainerFrontPicPaletteTable', idx))

def hack_mon_front(sp):
    return hack_lz(tbl_ptr('gMonFrontPicTable', sp))

def hack_mon_pal(sp):
    return hack_lz(tbl_ptr('gMonPaletteTable', sp))

# object-event palette by tag (hack)
def hack_objev_pal_by_tag(tag):
    a = sym('sObjectEventSpritePalettes')
    i = 0
    while True:
        p = ptr(H, a + 8 * i); t = u16(H, a + 8 * i + 4)
        if p is None: return None
        if t == tag: return H[p:p + 32]
        i += 1

def objev_pic_palettes():
    """vanilla pic symbol -> hack palette bytes, via hack graphics infos referencing the pic."""
    out = {}
    a, s = syms['gObjectEventGraphicsInfoPointers']
    for gid in range(s // 4):
        info = ptr(H, a + 4 * gid)
        tag = u16(H, info + 2)
        imgs = ptr(H, info + 0x1c)
        nm = byaddr.get(imgs, ['?'])[0]
        n = syms.get(nm, (0, 8))[1] // 8
        for k in range(n):
            dp = ptr(H, imgs + 8 * k)
            # map frame pointer back to containing pic symbol
            for pn, (pa, ps) in pic_syms.items():
                if pa <= dp < pa + ps:
                    out.setdefault(pn, hack_objev_pal_by_tag(tag))
    return out

pic_syms = {n: syms[n] for n in ib if n.startswith(('gObjectEventPic_', 'gFieldEffectObjectPic_')) and n in syms}

# vanilla palette lookup by colours (for embedded PNG palettes)
def all_vanilla_palettes():
    out = {}
    for n, (src, path) in ib.items():
        if n not in syms: continue
        a, s = syms[n]
        if path.endswith('.gbapal'):
            data = V[a:a + s]
        elif path.endswith('.gbapal.lz'):
            try: data = decomp(V, a)[0]
            except Exception: continue
        else: continue
        for k in range(0, len(data) - 31, 32):
            key = tuple(u16(data, k + 2 * j) & 0x7fff for j in range(16))
            out.setdefault(key, (n, a, k, path.endswith('.lz')))
    return out
VPALS = all_vanilla_palettes()

def png_palette_key(png):
    im = Image.open(png)
    p = im.getpalette()[:48]
    p += [0] * (48 - len(p))
    return tuple((p[3 * j] >> 3) | ((p[3 * j + 1] >> 3) << 5) | ((p[3 * j + 2] >> 3) << 10) for j in range(16))

def fallback_palette(png):
    key = png_palette_key(png)
    hit = VPALS.get(key)
    if not hit: return None, None
    n, a, k, lz = hit
    data = decomp(H, a)[0] if lz else H[a:a + syms[n][1]]
    return data[k:k + 32], n

# ------------------------------------------------------------------ make commands
_cmd_cache = {}
def make_cmds(targets):
    r = subprocess.run(['make', '-n', '-B'] + targets, cwd=WT, capture_output=True, text=True)
    cmds = [l.split() for l in r.stdout.splitlines() if l.startswith('tools/gbagfx/gbagfx')]
    for c in cmds:
        _cmd_cache[c[2]] = c
    return cmds

# ------------------------------------------------------------------ job execution
results = []

def write_png_job(target4bpp, data, pal, note=''):
    """target4bpp: path of .4bpp (relative, no .lz). data: raw tile bytes. pal: 32-byte gbapal for display."""
    png = target4bpp[:-5] + '.png'
    cmd = _cmd_cache[target4bpp]
    flags = cmd[3:]
    mw = int(flags[flags.index('-mwidth') + 1]) if '-mwidth' in flags else 1
    mh = int(flags[flags.index('-mheight') + 1]) if '-mheight' in flags else 1
    old = Image.open(os.path.join(WT, png))
    wtiles = old.size[0] // 8
    if pal is None:
        pal, pname = fallback_palette(os.path.join(WT, png))
        note += ' pal=%s' % pname
    base = os.path.join(TMP, target4bpp.replace('/', '__'))
    open(base + '.hack.4bpp', 'wb').write(data)
    rev = [GBAGFX, base + '.hack.4bpp', base + '.png', '-width', str(wtiles), '-mwidth', str(mw), '-mheight', str(mh), '-object']
    if pal is not None:
        open(base + '.pal.gbapal', 'wb').write(pal)
        rev += ['-palette', base + '.pal.gbapal']
    else:
        # keep the existing embedded palette: write it out as gbapal
        run([GBAGFX, os.path.join(WT, png), base + '.pal.gbapal'])
        rev += ['-palette', base + '.pal.gbapal']
    run(rev)
    new = Image.open(base + '.png')
    if new.size != old.size:
        note += ' SIZE %s->%s' % (old.size, new.size)
    # forward check with exact make flags
    run([GBAGFX, base + '.png', base + '.check.4bpp'] + flags)
    chk = open(base + '.check.4bpp', 'rb').read()
    ok = chk == data
    if ok and not DRY:
        shutil.copy(base + '.png', os.path.join(WT, png))
    results.append((png, ok, len(data), note.strip()))

def write_pal_job(targetgbapal, data, note=''):
    """targetgbapal: .gbapal path built from .pal (JASC)."""
    pal = targetgbapal[:-7] + '.pal'
    if any(u16(data, i) & 0x8000 for i in range(0, len(data), 2)):
        note += ' BIT15'
    base = os.path.join(TMP, targetgbapal.replace('/', '__'))
    open(base + '.hack.gbapal', 'wb').write(data)
    run([GBAGFX, base + '.hack.gbapal', base + '.pal'])
    run([GBAGFX, base + '.pal', base + '.check.gbapal'])
    chk = open(base + '.check.gbapal', 'rb').read()
    ok = chk == data
    if ok and not DRY:
        shutil.copy(base + '.pal', os.path.join(WT, pal))
    results.append((pal, ok, len(data), note.strip()))


def main():
    MINE_PREFIX = ('graphics/object_events/', 'graphics/field_effects/', 'graphics/misc/emoticons', 'graphics/naming_screen/',
                   'graphics/pokemon/', 'graphics/trainers/', 'graphics/items/')
    jobs = []  # (kind, target, data, pal, note)
    # 1. In-place edited INCBIN symbols that are still live in the hack
    orphaned = {'gTrainerFrontPic_Red'}  # repointed to new data; handled below
    objpals = objev_pic_palettes()
    tf_index = {}
    a, s = syms['gTrainerFrontPicTable']
    for i in range(s // 8):
        tf_index.setdefault(byaddr[ptr(V, a + 8 * i)][0], i)
    mf_index = {}
    a, s = syms['gMonFrontPicTable']
    for i in range(s // 8):
        p = ptr(V, a + 8 * i)
        mf_index.setdefault(byaddr[p][0], i)
    tb_pal_index = {}
    a, s = syms['gTrainerBackPicPaletteTable']
    for i in range(s // 8):
        tb_pal_index[byaddr[ptr(V, a + 8 * i)][0]] = i

    for name, (src, path) in sorted(ib.items()):
        if name not in syms or name in orphaned: continue
        if not path.startswith(MINE_PREFIX): continue
        a, s = syms[name]
        if H[a:a + s] == V[a:a + s]: continue
        if path.endswith('.lz'):
            data = decomp(H, a)[0]
            tgt = path[:-3]
        else:
            data = H[a:a + s]
            tgt = path
        note = name
        if tgt.endswith('.4bpp'):
            pal = None
            if name in tf_index:
                i = tf_index[name]
                if len(data) > 0x800:
                    note += ' (hack LZ stream holds %d bytes; trailing %d zero bytes beyond the 0x800 sheet dropped)' % (len(data), len(data) - 0x800)
                    assert data[0x800:] == bytes(len(data) - 0x800)
                data = data[:0x800]
                pal = hack_trainer_front_pal(i)
            elif name in mf_index:
                pal = hack_mon_pal(mf_index[name])
            elif name in objpals:
                pal = objpals[name]
            elif name.startswith('gTrainerBackPic_'):
                pal = hack_lz(tbl_ptr('gTrainerBackPicPaletteTable', 0 if 'Red' in name else 1))
            elif name == 'gItemIcon_PokeblockCase':
                pal = hack_lz(ptr(H, sym('sItemIconTable') + 8 * 273 + 4))
            elif name == 'sRival_Gfx':
                pal = H[sym('gObjectEventPal_NpcWhite'):sym('gObjectEventPal_NpcWhite') + 32]
            jobs.append(('png', tgt, data, pal, note))
        elif tgt.endswith('.gbapal'):
            jobs.append(('pal', tgt, data, None, note))
        else:
            raise RuntimeError('unhandled %s %s' % (name, path))

    # 2. Table entries repointed to brand-new data (vanilla data orphaned -> replace the source image)
    for sp_name, sp in [('Chikorita', 152), ('Cyndaquil', 155), ('Totodile', 158)]:
        jobs.append(('png', ib['gMonFrontPic_' + sp_name][1][:-3], hack_mon_front(sp), hack_mon_pal(sp),
                     'gMonFrontPic_%s (repointed to new data @%07x)' % (sp_name, tbl_ptr('gMonFrontPicTable', sp))))
    for tname in ['EliteFourBruno', 'EliteFourAgatha', 'Red']:
        i = tf_index['gTrainerFrontPic_' + tname]
        jobs.append(('png', ib['gTrainerFrontPic_' + tname][1][:-3], hack_trainer_front(i), hack_trainer_front_pal(i),
                     'gTrainerFrontPic_%s (repointed to new data @%07x)' % (tname, tbl_ptr('gTrainerFrontPicTable', i))))

    make_cmds([j[1] for j in jobs])
    for kind, tgt, data, pal, note in jobs:
        if kind == 'png':
            write_png_job(tgt, data, pal, note)
        else:
            write_pal_job(tgt, data, note)
    bad = 0
    for png, ok, n, note in results:
        print('%-4s %-70s %6d  %s' % ('OK' if ok else 'FAIL', png, n, note))
        bad += not ok
    print('%d jobs, %d failed' % (len(results), bad))
    json.dump([r[0] for r in results if r[1]], open('/home/claude/work/gfx/out/ported_files.json', 'w'), indent=1)

main()
