#!/usr/bin/env python3
"""Summarize problems.json / coverage.json into problem_summary.txt (included in REPORT.md)."""
import json, os, re, sys, collections, argparse

CATS = [
    ('rom_start', r'0x08000000 \(ROM start\)', 'event / header script pointer is 0x08000000 (AdvanceMap "none"); emitted/mapped as NULL'),
    ('invalid_ptr', r'invalid (script|text|movement|mart|mstable|mapscripts|braille) pointer', 'pointer outside the ROM (kept as raw value)'),
    ('dup', r'duplicated', 'block overlaps other data at a different alignment (emitted as a separate copy)'),
    ('opcode', r'invalid script opcode', 'script runs into an invalid opcode (engine stops the script there)'),
    ('ff', r'runs into 0xFF', 'script runs into 0xFF free space (engine stops the script; usually a missing end after warp)'),
    ('never', r'can never match', 'map-script table entry that can never match (pointer not followed)'),
    ('shadow', r'shadowed', 'map-script header entry shadowed by an earlier entry of the same type'),
    ('header', r'map script header|bad map script table|unterminated', 'damaged map-script header / table'),
    ('mart', r'misaligned mart', 'mart item list at an odd address (engine reads only the low byte of each item)'),
]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--json-dir', default='/home/claude/work/scripts')
    args = ap.parse_args()
    jd = args.json_dir
    probs = json.load(open(os.path.join(jd, 'problems.json')))
    mn = json.load(open('/home/claude/work/map_names.json'))
    reach = {v['name']: v['reachable'] for v in mn.values()}
    out = ['| category | occurrences | maps (reachable) | maps (unreachable / other) |', '|---|---|---|---|']
    details = []
    for key, rx, desc in CATS:
        n = 0
        rm, um = [], []
        for owner, lst in probs.items():
            hits = [m for m in lst if re.search(rx, m)]
            if not hits:
                continue
            n += len(hits)
            (rm if reach.get(owner) else um).append(owner)
        out.append('| %s | %d | %d | %d |' % (desc, n, len(rm), len(um)))
        if rm:
            details.append('* **%s** — reachable maps: %s' % (desc, ', '.join(sorted(rm))))
    cov = json.load(open(os.path.join(jd, 'coverage.json')))
    s = '\n'.join(out) + '\n\n' + '\n'.join(details) + '\n'
    s += '\nCoverage: %d uncovered free-space text candidates (%d bytes), %d uncovered script-start candidates.\n' % (
        len(cov['text_candidates']), sum(t['len'] for t in cov['text_candidates']), len(cov['script_candidates']))
    open(os.path.join(jd, 'problem_summary.txt'), 'w').write(s)
    print(s)


if __name__ == '__main__':
    main()
