#!/usr/bin/env python3
"""Byte-exactness verification of the generated event-script assembly.

    python3 verify.py WORKTREE [--json-dir DIR] [--work DIR]

1. Assembles the real WORKTREE/data/event_scripts.s with the Makefile pipeline (preproc | cpp | preproc -ie | as),
   using stub headers for the generated constants (map/layout/heal/mapsec/trainer ids from the naming contract),
   and checks that every undefined symbol is a known external (C symbol / RAM symbol / native placeholder).
2. Extracts every emitted chunk (per chunk_index.json) verbatim from the generated files, puts each chunk in its
   own section, links every section at its original hack-ROM address (overlapping duplicates in separate link
   layers; external labels resolved to their vanilla / hack addresses) and compares the linked bytes with the
   hack ROM.  Map-script headers whose inert junk entries were dropped are compared semantically.
"""
import sys, os, re, json, struct, subprocess, shutil, argparse, collections
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, '/home/claude/sgx')
from core import *
import names as N
import sgconst

ROMBASE = 0x08000000
MS_TYPES = set(range(1, 8))


def sh(cmd, cwd=None):
    r = subprocess.run(cmd, shell=True, cwd=cwd, capture_output=True, text=True)
    return r.returncode, r.stdout, r.stderr


def write_stubs(inc):
    c = os.path.join(inc, 'constants')
    os.makedirs(c, exist_ok=True)
    mn = json.load(open(N.MAP_NAMES_JSON))
    L = ['#ifndef GUARD_CONSTANTS_MAP_GROUPS_H', '#define GUARD_CONSTANTS_MAP_GROUPS_H']
    for k, v in mn.items():
        g, n = map(int, k.split('.'))
        L.append('#define %s (%d | (%d << 8))' % (v['id'], n, g))
    L.append('#define MAP_GROUPS_COUNT 64')
    L.append('#endif')
    open(os.path.join(c, 'map_groups.h'), 'w').write('\n'.join(L) + '\n')
    L = ['#ifndef GUARD_CONSTANTS_LAYOUTS_H', '#define GUARD_CONSTANTS_LAYOUTS_H']
    for lid, (lab, cid, nm) in sorted(N._layout_names().items()):
        L.append('#define %s %d' % (cid, lid))
    L.append('#endif')
    open(os.path.join(c, 'layouts.h'), 'w').write('\n'.join(L) + '\n')
    L = ['#ifndef GUARD_CONSTANTS_HEAL_LOCATIONS_H', '#define GUARD_CONSTANTS_HEAL_LOCATIONS_H',
         '#define HEAL_LOCATION_NONE 0']
    for i in range(1, 25):
        L.append('#define %s %d' % (N.heal_location_const(i), i))
    L.append('#endif')
    open(os.path.join(c, 'heal_locations.h'), 'w').write('\n'.join(L) + '\n')
    L = ['#ifndef GUARD_CONSTANTS_REGION_MAP_SECTIONS_H', '#define GUARD_CONSTANTS_REGION_MAP_SECTIONS_H']
    seen = set()
    for v, nm in sorted(N._mapsec_table().items()):
        if nm not in seen:
            L.append('#define %s %d' % (nm, v)); seen.add(nm)
    L += ['#define METLOC_SPECIAL_EGG 0xFD', '#define METLOC_IN_GAME_TRADE 0xFE', '#define METLOC_FATEFUL_ENCOUNTER 0xFF',
          '#define MAPSEC_COUNT %d' % (max(N._mapsec_table()) + 1), '#endif']
    open(os.path.join(c, 'region_map_sections.h'), 'w').write('\n'.join(L) + '\n')
    L = ['#ifndef GUARD_CONSTANTS_OPPONENTS_H', '#define GUARD_CONSTANTS_OPPONENTS_H']
    for i in range(0, N.NUM_TRAINERS):
        L.append('#define %s %d' % (N.trainer_const(i), i))
    L += ['#define NUM_TRAINERS %d' % N.NUM_TRAINERS, '#define MAX_TRAINERS_COUNT 768', '#endif']
    open(os.path.join(c, 'opponents.h'), 'w').write('\n'.join(L) + '\n')
    open(os.path.join(c, 'map_event_ids.h'), 'w').write('#ifndef GUARD_MAP_EVENT_IDS_H\n#define GUARD_MAP_EVENT_IDS_H\n#endif\n')
    # multichoice placeholders used by the hack
    menu = open(os.path.join(c, 'menu.h')).read()
    extra = ''.join('#define MULTICHOICE_SG_%d %d\n' % (i, i) for i in range(256))
    menu = menu.replace('#endif', extra + '#endif', 1) if False else menu.rstrip() + '\n' + extra
    open(os.path.join(c, 'menu.h'), 'w').write(menu)


def setup_root(wt, root):
    if os.path.exists(root):
        shutil.rmtree(root)
    os.makedirs(root)
    for d in ['asm', 'tools', 'charmap.txt', 'data']:
        os.symlink(os.path.join(wt, d), os.path.join(root, d))
    shutil.copytree(os.path.join(wt, 'include'), os.path.join(root, 'include'))
    write_stubs(os.path.join(root, 'include'))


def assemble(root, src, obj):
    asflags = '-mcpu=arm7tdmi --defsym FIRERED=1 --defsym REVISION=0 --defsym ENGLISH=1 --defsym MODERN=0'
    cmd = ('tools/preproc/preproc {src} charmap.txt | arm-none-eabi-cpp -I include - | tools/preproc/preproc -ie {src} charmap.txt '
           '| arm-none-eabi-as {fl} -o {obj}').format(src=src, obj=obj, fl=asflags)
    return sh(cmd, cwd=root)


def external_symbols(json_dir):
    """name -> value for everything a chunk may reference that is not defined by the chunks themselves."""
    out = {}
    by_addr, rng = vanilla_symbols()
    for a, s, n in rng:
        out.setdefault(n, a + ROMBASE)
    # thumb functions: value with thumb bit
    for a, lst in by_addr.items():
        for n, s, t in lst:
            if t in 'Tt':
                out[n] = a + ROMBASE + 1
    for a, s, t, n, sized in sgconst._vanilla_ram_syms():
        out.setdefault(n, a)
    nat = json.load(open(os.path.join(json_dir, 'natives.json')))
    for v, info in nat.items():
        out[info['symbol']] = int(v, 16)
    for p in (sgconst.RAM_SYMS_JSON, sgconst.NATIVE_SYMS_JSON):
        if os.path.exists(p):
            for k, v in json.load(open(p)).items():
                try:
                    out.setdefault(v.split()[0], int(k, 16))
                except Exception:
                    pass
    return out


def resolve(sym, ext):
    m = re.match(r'SG_(?:RAM|NATIVE)_0x([0-9A-Fa-f]+)$', sym)
    if m:
        return int(m.group(1), 16)
    return ext.get(sym)


def read_elf_sections(path):
    d = open(path, 'rb').read()
    shoff = struct.unpack_from('<I', d, 0x20)[0]
    shentsize, shnum, shstrndx = struct.unpack_from('<HHH', d, 0x2E)
    secs = []
    for i in range(shnum):
        o = shoff + i * shentsize
        name, typ, flags, addr, off, size = struct.unpack_from('<IIIIII', d, o)
        secs.append([name, typ, addr, off, size])
    stro = secs[shstrndx][3]
    res = {}
    for name, typ, addr, off, size in secs:
        nm = d[stro + name:d.index(b'\0', stro + name)].decode()
        res[nm] = (addr, d[off:off + size] if typ != 8 else b'\0' * size)
    return res


def parse_header(b):
    ents = []
    p = 0
    while p < len(b) and b[p] != 0:
        ents.append((b[p], struct.unpack_from('<I', b, p + 1)[0]))
        p += 5
    return ents, p + 1


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('worktree')
    ap.add_argument('--json-dir', default='/home/claude/work/scripts')
    ap.add_argument('--work', default='/home/claude/work/scripts/verify')
    args = ap.parse_args()
    wt = os.path.abspath(args.worktree)
    root = args.work
    rom = Rom().d
    setup_root(wt, root)
    ext = external_symbols(args.json_dir)
    report = {}

    # ---------------------------------------------------------------- 1) assemble the real event_scripts.s
    rc, out, err = assemble(root, 'data/event_scripts.s', 'event_scripts.o')
    errs = [l for l in err.splitlines() if 'Error' in l or 'error' in l]
    print('assemble data/event_scripts.s: rc=%d, %d error lines' % (rc, len(errs)))
    for l in errs[:30]:
        print('   ', l)
    report['event_scripts_assemble_rc'] = rc
    report['event_scripts_errors'] = errs
    undefined = []
    if rc == 0:
        rc2, o2, e2 = sh('arm-none-eabi-nm -u event_scripts.o', cwd=root)
        und = [l.split()[-1] for l in o2.splitlines() if l.strip()]
        unresolved = [s for s in und if resolve(s, ext) is None]
        placeholders = [s for s in und if s.startswith('SG_')]
        print('  undefined symbols: %d (C/RAM/vanilla: %d, SG placeholders: %d, unknown: %d)' % (
            len(und), len(und) - len(placeholders) - len(unresolved), len(placeholders), len(unresolved)))
        for s in unresolved[:40]:
            print('    unknown:', s)
        report['event_scripts_undefined'] = und
        report['event_scripts_unknown'] = unresolved
        vo = os.path.join(VANILLA_DIR, 'build/firered/data/event_scripts.o')
        if os.path.exists(vo):
            rcv, ov, ev_ = sh('arm-none-eabi-nm -u %s' % vo)
            vund = set(l.split()[-1] for l in ov.splitlines() if l.strip())
            new_ext = sorted(set(und) - vund)
            print('  externals not already needed by vanilla event_scripts.o: %s' % (new_ext or 'none'))
            report['new_externals_vs_vanilla'] = new_ext
        # duplicate / size sanity
        rc3, o3, e3 = sh('arm-none-eabi-size -A event_scripts.o', cwd=root)
        m = re.search(r'script_data\s+(\d+)', o3)
        print('  script_data size: %s bytes' % (m.group(1) if m else '?'))

    # ---------------------------------------------------------------- 2) chunk-by-chunk byte comparison
    index = json.load(open(os.path.join(args.json_dir, 'chunk_index.json')))
    label_addrs = json.load(open(os.path.join(args.json_dir, 'label_addrs.json')))
    hdr = []
    for line in open(os.path.join(wt, 'data/event_scripts.s'), encoding='utf-8'):
        if line.startswith('#include') or re.match(r'\s*\.include "asm/', line) or re.match(r'\s*\.set (TRUE|FALSE)', line):
            hdr.append(line.rstrip('\n'))
    hdr += ['\t.section .discard_specials,"aw",%progbits', '\t.include "data/specials.inc"']
    files = {}

    def chunk_text(k):
        c = index[k]
        f = c['file']
        if f not in files:
            files[f] = open(os.path.join(wt, f), encoding='utf-8').read().split('\n')
        lines = files[f][c['line']:c['line'] + c['nlines']]
        if c['addr'] % 2 and lines and lines[0].strip() == '.align 1':
            lines = lines[1:]
        return ['\t.section .sg%d,"aw",%%progbits' % k] + lines

    # layers of non-overlapping chunks (overlapping duplicates are linked separately)
    order = sorted(range(len(index)), key=lambda k: (index[k]['addr'], index[k]['end']))
    layers = []
    for k in order:
        c = index[k]
        for L in layers:
            if L['end'] <= c['addr']:
                L['end'] = c['end']; L['items'].append(k)
                break
        else:
            layers.append(dict(end=c['end'], items=[k]))
    mism = []
    label_mism = []
    labels_checked = [0]
    checked = nbytes = sem = 0
    all_missing = set()
    for li, L in enumerate(layers):
        src = 'layer%d.s' % li
        body = []
        for k in L['items']:
            body.extend(chunk_text(k))
        open(os.path.join(root, src), 'w', encoding='utf-8').write('\n'.join(hdr + body) + '\n')
        rc, out, err = assemble(root, src, 'layer%d.o' % li)
        if rc != 0:
            print('layer %d assembly FAILED' % li)
            print('\n'.join(err.splitlines()[:40]))
            sys.exit(1)
        rc2, o2, e2 = sh('arm-none-eabi-nm -u layer%d.o' % li, cwd=root)
        und = sorted(set(l.split()[-1] for l in o2.splitlines() if l.strip()))
        defs = []
        for s_ in und:
            v = label_addrs.get(s_)
            if v is None:
                v = resolve(s_, ext)
            if v is None:
                if not s_.startswith('STR_VAR_'):
                    all_missing.add(s_)
                v = 0
            defs.append('%s = 0x%08X;' % (s_, v))
        ld = ['SECTIONS {']
        for k in L['items']:
            ld.append('  .sg%d 0x%08X : { layer%d.o(.sg%d) }' % (k, index[k]['addr'] + ROMBASE, li, k))
        ld.append('  /DISCARD/ : { *(*) }')
        ld.append('}')
        ld.extend(defs)
        open(os.path.join(root, 'layer%d.ld' % li), 'w').write('\n'.join(ld) + '\n')
        rc, out, err = sh('arm-none-eabi-ld -T layer%d.ld -o layer%d.elf layer%d.o' % (li, li, li), cwd=root)
        if rc != 0:
            print('link layer %d failed:' % li, err[:3000])
            sys.exit(1)
        secs = read_elf_sections(os.path.join(root, 'layer%d.elf' % li))
        # every label defined by the generated chunks must sit at its original hack address
        rc3, o3, e3 = sh('arm-none-eabi-nm -g --defined-only layer%d.elf' % li, cwd=root)
        for line in o3.splitlines():
            p = line.split()
            if len(p) == 3 and p[1] not in 'aA' and p[2] in label_addrs:
                labels_checked[0] += 1
                if int(p[0], 16) != label_addrs[p[2]]:
                    label_mism.append((p[2], p[0], '%08X' % label_addrs[p[2]]))
        for k in L['items']:
            c = index[k]
            a, b = c['addr'], c['end']
            sec = secs.get('.sg%d' % k)
            got = sec[1] if sec else b''
            want = rom[a:b]
            checked += 1
            if c['semantic']:
                g, gl = parse_header(got)
                w, wl = parse_header(want)
                ok = g == [e for e in w if e[0] in MS_TYPES] and gl == len(got)
                sem += 1
            else:
                ok = got == want
                nbytes += len(want)
            if not ok:
                diff = next((i for i in range(min(len(got), len(want))) if got[i] != want[i]), min(len(got), len(want)))
                mism.append(dict(file=c['file'], line=c['line'] + 1, addr='0x%08X' % (a + ROMBASE), kind=c['kind'],
                                 size_got=len(got), size_want=len(want), first_diff=diff,
                                 got=got[max(0, diff - 4):diff + 12].hex(), want=want[max(0, diff - 4):diff + 12].hex()))
    if all_missing:
        print('unresolvable externals in chunk test (linked as 0):', sorted(all_missing)[:60])
    print('chunks checked: %d in %d link layers; %d bytes compared exactly, %d headers compared semantically; '
          'MISMATCHES: %d' % (checked, len(layers), nbytes, sem, len(mism)))
    print('labels checked at their original addresses: %d; misplaced: %d' % (labels_checked[0], len(label_mism)))
    for m in label_mism[:20]:
        print('   ', m)
    for m in mism[:40]:
        print('   ', m)
    report.update(dict(chunks_checked=checked, layers=len(layers), bytes_compared=nbytes, semantic_headers=sem,
                       mismatches=mism, unresolved_in_chunks=sorted(all_missing), labels_checked=labels_checked[0],
                       labels_misplaced=label_mism))
    json.dump(report, open(os.path.join(args.json_dir, 'verify_report.json'), 'w'), indent=1)
    sys.exit(1 if mism or label_mism or rc else 0)


if __name__ == '__main__':
    main()
