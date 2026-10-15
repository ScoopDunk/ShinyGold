#!/usr/bin/env python3
"""Coverage analysis for the generated scripts.

    python3 coverage.py [--json-dir DIR]

* pointer scan: every aligned word in the hack ROM that points at a generated label, from outside the generated
  chunks and outside map event/header data -> possible references from code/data (ASM hooks, C tables, specials).
* candidate unreached scripts/texts in hack free space (IPS-written bytes >= 0x71A000 not covered by any chunk).
Writes coverage.json.
"""
import sys, os, json, struct, bisect, collections, argparse, re
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE); sys.path.insert(0, '/home/claude/sgx'); sys.path.insert(0, '/home/claude/tools')
from core import *
from maps import load_map_headers, parse_events, parse_map_scripts, parse_connections
import ips
from sgdecode import decode_instr, text_end

ROMBASE = 0x08000000


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--json-dir', default='/home/claude/work/scripts')
    args = ap.parse_args()
    jd = args.json_dir
    rom = Rom(); d = rom.d
    index = json.load(open(os.path.join(jd, 'chunk_index.json')))
    labels = json.load(open(os.path.join(jd, 'label_addrs.json')))
    cov = bytearray(len(d))
    for c in index:
        for k in range(c['addr'], c['end']):
            cov[k] = 1
    # map structures (headers, events, script headers) as parsed by maps.py
    groups, maps = load_map_headers(rom)
    for m in maps:
        parse_events(rom, m.events)
        parse_connections(rom, m.connections)
    known_struct = rom.cov       # marked by maps.py parsers
    addr_label = {}
    for n, a in labels.items():
        addr_label.setdefault(a, n)
    # vanilla symbols (to name the location of a reference)
    by_addr, rng = vanilla_symbols()
    A = [x[0] for x in rng]

    def where(o):
        if o >= 0x71A000:
            return 'free space 0x%08X' % (o + ROMBASE)
        i = bisect.bisect_right(A, o) - 1
        return '%s+0x%X' % (rng[i][2], o - rng[i][0]) if i >= 0 else hex(o)
    van = open(VANILLA_ROM, 'rb').read()
    refs = collections.defaultdict(list)
    for o in range(0, len(d) - 3, 4):
        v = struct.unpack_from('<I', d, o)[0]
        if v in addr_label and not cov[o] and not known_struct[o]:
            changed = d[o:o + 4] != van[o:o + 4]
            if o < 0x71A000 and not changed:
                continue   # vanilla word, unchanged -> vanilla C/asm reference to a vanilla address
            refs['0x%08X' % v].append(dict(at='0x%08X' % (o + ROMBASE), where=where(o), changed_vanilla_word=o < 0x71A000))
    ext_refs = {k: dict(label=addr_label[int(k, 16)], refs=v) for k, v in sorted(refs.items())}
    print('pointers to generated labels from outside scripts/map data: %d targets' % len(ext_refs))
    for k, v in list(ext_refs.items())[:60]:
        print('  %s %-50s <- %s' % (k, v['label'], ', '.join('%s (%s)' % (r['at'], r['where']) for r in v['refs'][:3])))
    # unreached candidates in IPS-written free space
    recs, _ = ips.parse('/home/claude/work/shinygold.ips')
    written = bytearray(len(d))
    for off, data, rle in recs:
        if off >= 0x71A000:
            for k in range(off, min(off + len(data), len(d))):
                written[k] = 1
    # text candidates: runs ending in 0xFF, mostly letters, not covered
    cands = []
    o = 0x71A000
    letters = set(range(0xA1, 0xEF)) | {0x00, 0xFA, 0xFB, 0xFE, 0xFD, 0xB4, 0xB0, 0xAD, 0xAB, 0xAC, 0xB8}
    while o < len(d):
        if not written[o] or cov[o] or known_struct[o]:
            o += 1; continue
        e = text_end(d, o, 600)
        if e and e - o >= 12 and not any(cov[o:e]) and all(written[o:e]):
            body = d[o:e - 1]
            frac = sum(1 for b in body if b in letters) / len(body)
            if frac > 0.95 and sum(1 for b in body if 0xD5 <= b <= 0xEE) > len(body) * 0.4:
                cands.append(('text', o, e))
                o = e; continue
        o += 1
    # script candidates: lock/faceplayer, lockall, msgbox pattern
    scands = []
    for o in range(0x71A000, len(d) - 8):
        if cov[o] or not written[o] or known_struct[o]:
            continue
        if (d[o] == 0x6A and d[o + 1] == 0x5A) or (d[o] == 0x0F and d[o + 1] == 0x00 and d[o + 5] == 0x08 and d[o + 6] == 0x09):
            if o > 0 and cov[o - 1] == 0 and not (d[o - 1] == 0x6A and d[o] == 0x5A):
                scands.append(o)
    print('uncovered free-space text candidates: %d (%d bytes)' % (len(cands), sum(e - s for k, s, e in cands)))
    print('uncovered free-space script-start candidates: %d' % len(scands))
    out = dict(external_refs=ext_refs,
               text_candidates=[dict(addr='0x%08X' % (s + ROMBASE), len=e - s,
                                     preview=(decode_text(rom, s)[0] or '')[:60]) for k, s, e in cands],
               script_candidates=['0x%08X' % (o + ROMBASE) for o in scands])
    json.dump(out, open(os.path.join(jd, 'coverage.json'), 'w'), indent=1)


if __name__ == '__main__':
    main()
