"""Check that script text fits the field message box.

usage: textwidth.py <tree> [file.inc ...]      (default: every data/maps/*/text.inc and data/text/*.inc)
       textwidth.py <tree> --git [rev]         only text.inc/scripts.inc files changed since rev (default HEAD)

Each line of a .string (split at \\n, \\l, \\p) is measured with the widest of the normal/male/female fonts.
Placeholders count as: {PLAYER}/{RIVAL} 7 chars of width 6, {STR_VAR_n} 10 chars, other {..} codes 0.
Lines over LIMIT pixels are printed. The standard message box text area is 208px; glyphs end with a blank
column, so 210 is the practical limit (the hack's own map text stays within it with a handful of exceptions).
"""
import sys, os, re, glob, subprocess

LIMIT = 210


def widths(tree):
    src = open(os.path.join(tree, 'src/text.c')).read()
    out = []
    for name in ('sFontNormalLatinGlyphWidths', 'sFontMaleLatinGlyphWidths', 'sFontFemaleLatinGlyphWidths'):
        m = re.search(r'%s\[\]\s*=\s*\{(.*?)\};' % name, src, re.S)
        out.append([int(x) for x in re.findall(r'\d+', m.group(1))])
    return [max(t[i] if i < len(t) else 0 for t in out) for i in range(max(len(t) for t in out))]


def charmap(tree):
    cm = {}
    for line in open(os.path.join(tree, 'charmap.txt'), encoding='utf-8'):
        m = re.match(r"'(.+?)'\s*=\s*([0-9A-Fa-f]{2})\s*$", line)
        if m:
            k = m.group(1).replace("\\'", "'")
            cm[k] = int(m.group(2), 16)
    return cm


def measure(s, W, CM):
    w = 0
    i = 0
    while i < len(s):
        if s[i] == '{':
            j = s.index('}', i)
            code = s[i + 1:j]
            if code in ('PLAYER', 'RIVAL'): w += 42
            elif code.startswith('STR_VAR'): w += 60
            i = j + 1
            continue
        c = s[i]
        b = CM.get(c)
        w += W[b] if b is not None and b < len(W) else 6
        i += 1
    return w


def check(path, W, CM):
    bad = []
    lines = open(path, encoding='utf-8', errors='replace').read().split('\n')
    label = None
    buf = ''
    start = 0
    for n, l in enumerate(lines, 1):
        m = re.match(r'^(\w+)::?', l)
        if m: label = m.group(1)
        m = re.match(r'\s*\.string\s+"(.*)"\s*$', l)
        if not m: continue
        s = m.group(1)
        parts = re.split(r'\\[nlp]', s.replace('$', ''))
        for p in parts:
            if not p: continue
            w = measure(p, W, CM)
            if w > LIMIT:
                bad.append('%s:%d: %s: %dpx: "%s"' % (path, n, label, w, p))
    return bad


def main():
    tree = sys.argv[1]
    W, CM = widths(tree), charmap(tree)
    args = sys.argv[2:]
    if args and args[0] == '--git':
        rev = args[1] if len(args) > 1 else 'HEAD'
        out = subprocess.run(['git', '-C', tree, 'diff', '--name-only', rev], capture_output=True, text=True).stdout.split()
        files = [os.path.join(tree, f) for f in out if f.endswith('.inc') and os.path.exists(os.path.join(tree, f))]
    elif args:
        files = args
    else:
        files = sorted(glob.glob(os.path.join(tree, 'data/maps/*/text.inc')) + glob.glob(os.path.join(tree, 'data/text/*.inc')))
    bad = []
    for f in files: bad += check(f, W, CM)
    print('\n'.join(bad))
    print('%d lines too wide (limit %dpx) in %d files' % (len(bad), LIMIT, len(files)))


if __name__ == '__main__':
    main()
