"""Delete script/text/movement blocks nothing can reach any more.

usage: prune_labels.py <tree> [--dry]

Prunable files: data/maps/*/scripts.inc and text.inc (except the vanilla link-room maps) and the hack's own
data/scripts/shinygold_*.inc. A block runs from a label to the next label. A block is kept when its label is
reached, or when the block before it is kept and doesn't end in a terminator (fall-through). Roots: every
"script" in a map.json, every <Map>_MapScripts header, and every identifier that appears in C sources/headers
or in any other assembly/include file. Tokens inside kept blocks reach further labels. Unknown endings count as
fall-through, so the pass errs on keeping things. Repeats until nothing changes (a removal can orphan more).
"""
import os, re, sys, json, glob

tree = sys.argv[1]; dry = '--dry' in sys.argv
os.chdir(tree)
LINK = {'BattleColosseum_2P', 'TradeCenter', 'RecordCorner', 'BattleColosseum_4P', 'UnionRoom'}
LABEL = re.compile(r'^(\w+)::?\s*(?:@.*)?$')
TOK = re.compile(r'\b[A-Za-z_]\w*\b')
TERM = re.compile(r'^\s*(end|return|goto\s+\w+|gotostd\b.*|step_end|\.2byte 0|\.byte 0)\s*(@.*)?$')
STR_END = re.compile(r'^\s*\.string\s+".*\$"\s*(@.*)?$')

def prunable():
    fs = []
    for f in sorted(glob.glob('data/maps/*/scripts.inc') + glob.glob('data/maps/*/text.inc')):
        if f.split('/')[2] not in LINK: fs.append(f)
    return fs + sorted(glob.glob('data/scripts/shinygold_*.inc'))

def code(l):
    return l.split('@')[0] if '"' not in l else l   # strings may contain '@'

def blocks(lines):
    """[(label or None, start, end)] covering the file; block 0 is the preamble before the first label"""
    out = []; cur = (None, 0)
    for i, l in enumerate(lines):
        m = LABEL.match(l)
        if m:
            out.append((cur[0], cur[1], i)); cur = (m.group(1), i)
    out.append((cur[0], cur[1], len(lines)))
    return out

def ends_flow(lines, a, b):
    last = None
    for l in lines[a:b]:
        s = l.strip()
        if not s or s.startswith('@') or LABEL.match(l): continue
        last = l
    if last is None: return False
    if STR_END.match(last): return True
    if TERM.match(last):
        if re.match(r'^\s*\.(2)?byte 0', last):
            # only a terminator after a map script table
            prev = [l.strip() for l in lines[a:b] if l.strip() and not l.strip().startswith('@') and not LABEL.match(l)]
            return len(prev) >= 1 and (len(prev) == 1 or re.match(r'map_script', prev[-2] if len(prev) > 1 else ''))
        return True
    return False

total = 0
for rnd in range(10):
    files = prunable()
    data = {f: open(f, encoding='utf-8', errors='surrogateescape').read().split('\n') for f in files}
    where = {}
    B = {}
    for f, lines in data.items():
        B[f] = blocks(lines)
        for k, (lab, a, b) in enumerate(B[f]):
            if lab: where[lab] = (f, k)
    roots = set()
    for p in glob.glob('data/maps/*/map.json'):
        j = json.load(open(p))
        roots.add(j['name'] + '_MapScripts')
        for t in ('object_events', 'coord_events', 'bg_events'):
            for e in j.get(t) or []:
                if e.get('script'): roots.add(e['script'])
    others = [f for f in glob.glob('src/**/*.[ch]', recursive=True) + glob.glob('include/**/*.h', recursive=True)
              + glob.glob('data/**/*.inc', recursive=True) + glob.glob('data/**/*.s', recursive=True) + glob.glob('asm/**/*.inc', recursive=True)
              if f not in data and '/maps/' not in f.replace('data/maps/map_groups', '')]
    others += [f for f in glob.glob('data/maps/*/*.inc') if f not in data and not f.endswith('events.inc')]
    for f in others:
        roots.update(TOK.findall(open(f, encoding='utf-8', errors='replace').read()))
    keep = set(); stack = [where[r] for r in roots if r in where]
    while stack:
        f, k = stack.pop()
        if (f, k) in keep: continue
        keep.add((f, k))
        lab, a, b = B[f][k]
        for l in data[f][a + 1:b] if lab else data[f][a:b]:
            for t in TOK.findall(code(l)):
                if t in where and where[t] not in keep: stack.append(where[t])
        if k + 1 < len(B[f]) and not ends_flow(data[f], a, b):
            stack.append((f, k + 1))
    removed = 0
    for f, lines in data.items():
        dele = set()
        for k, (lab, a, b) in enumerate(B[f]):
            if lab and (f, k) not in keep:
                dele.update(range(a, b))
                # comment lines right above the label belong to it
                j = a - 1
                while j >= 0 and (lines[j].strip().startswith('@')) and not LABEL.match(lines[j]):
                    dele.add(j); j -= 1
                removed += 1
        if dele and not dry:
            new = [l for i, l in enumerate(lines) if i not in dele]
            txt = re.sub(r'\n{3,}', '\n\n', '\n'.join(new)).strip('\n')
            open(f, 'w', encoding='utf-8', errors='surrogateescape').write(txt + '\n' if txt else '')
    total += removed
    print('round', rnd + 1, 'removed blocks', removed)
    if not removed or dry: break
print('total removed blocks', total)
