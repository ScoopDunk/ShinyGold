"""Label-level reachability over the generated event scripts (from reachable maps' events/map scripts)."""
import json, re, glob, collections, os
def build(wt='/home/claude/shinygold'):
    names = json.load(open('/home/claude/work/map_names.json'))
    reach_maps = {v['name'] for v in names.values() if v['reachable']}
    body = {}   # label -> text block
    order = []
    files = glob.glob(wt + '/data/maps/*/scripts.inc') + glob.glob(wt + '/data/scripts/*.inc') + glob.glob(wt + '/data/maps/*/text.inc') + glob.glob(wt + '/data/text/*.inc')
    labels_in = collections.defaultdict(list)
    for f in files:
        cur = []
        lines = open(f, encoding='utf-8', errors='replace').read().split('\n')
        blk = []
        for line in lines:
            m = re.match(r'^(\w+)::?\s*$', line)
            if m:
                if blk and not cur:
                    pass
                if blk:
                    # previous block ends; a new label starts a new block unless previous block fell through
                    pass
                cur.append(m.group(1)); continue
            if cur:
                blk.append(line)
                if re.match(r'\s*(end|return|goto\s|step_end|\.string ".*\$"|\.2byte ITEM_NONE)', line) and not line.strip().startswith('goto_if'):
                    for c in cur: body[c] = (f, '\n'.join(blk))
                    cur = []; blk = []
        for c in cur: body[c] = (f, '\n'.join(blk))
    # fallthrough: a label's code continues into the next label if no terminator -> handled by block grouping above
    roots = set()
    for m in reach_maps:
        for fn in ('map.json', 'scripts.inc'):
            p = '%s/data/maps/%s/%s' % (wt, m, fn)
            if not os.path.exists(p): continue
            s = open(p).read()
            if fn == 'map.json':
                roots.update(re.findall(r'"script": "(\w+)"', s))
            else:
                mm = re.search(r'^%s_MapScripts::' % m, s, re.M)
                if mm: roots.add('%s_MapScripts' % m)
    seen = set(); stack = list(roots)
    while stack:
        l = stack.pop()
        if l in seen or l not in body: continue
        seen.add(l)
        for w in re.findall(r'\b[A-Za-z_]\w*\b', body[l][1]):
            if w in body and w not in seen: stack.append(w)
    return seen, body
if __name__ == '__main__':
    seen, body = build()
    print(len(seen), 'reachable labels of', len(body))
