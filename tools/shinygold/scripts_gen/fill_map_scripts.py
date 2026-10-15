#!/usr/bin/env python3
"""Replace raw script pointers in data/maps/*/map.json with the generated script labels.

    python3 fill_map_scripts.py WORKTREE [--labels /home/claude/work/scripts/script_labels.json] [--check]

The maps worker writes event scripts as raw ROM pointers ("script": "0x0871C280").  This tool rewrites every
"script" string value that is a ROM pointer into the label defined by the generated scripts.inc files.
0x08000000 (AdvanceMap's "no script" placeholder = ROM start, which would run the ROM header as a script) is
written as "0x0" (NULL).  Pointers without a label are left unchanged and reported.
Only the matching string values are edited (textual substitution), so the file formatting is preserved.
"""
import sys, os, re, json, glob, argparse

PTR_RE = re.compile(r'("script"\s*:\s*")(0x0?8[0-9A-Fa-f]{6}|0x0*|0x[0-9A-Fa-f]{1,8})(")')
NULL_PTRS = {0x08000000}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('worktree')
    ap.add_argument('--labels', default='/home/claude/work/scripts/script_labels.json')
    ap.add_argument('--check', action='store_true', help='report only, do not write')
    args = ap.parse_args()
    labels = {int(k, 16): v for k, v in json.load(open(args.labels)).items()}
    changed_files = 0
    replaced = 0
    unresolved = []
    for path in sorted(glob.glob(os.path.join(args.worktree, 'data/maps/*/map.json'))):
        text = open(path, encoding='utf-8').read()

        def rep(m):
            nonlocal replaced
            raw = m.group(2)
            try:
                v = int(raw, 16)
            except ValueError:
                return m.group(0)
            if v == 0:
                return m.group(0)
            if v in NULL_PTRS:
                replaced += 1
                return m.group(1) + '0x0' + m.group(3)
            lab = labels.get(v)
            if lab is None:
                unresolved.append((os.path.relpath(path, args.worktree), raw))
                return m.group(0)
            replaced += 1
            return m.group(1) + lab + m.group(3)
        new = PTR_RE.sub(rep, text)
        if new != text:
            changed_files += 1
            if not args.check:
                open(path, 'w', encoding='utf-8').write(new)
    print('%s %d script pointers in %d map.json files' % ('would replace' if args.check else 'replaced', replaced, changed_files))
    if unresolved:
        print('%d pointers without a label (left as raw values):' % len(unresolved))
        for p, r in unresolved[:50]:
            print('   ', p, r)
    return 0


if __name__ == '__main__':
    sys.exit(main())
