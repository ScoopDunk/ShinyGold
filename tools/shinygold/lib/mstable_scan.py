"""List effective map-script tables whose live entries point at raw (unlabeled) addresses."""
import os, re, sys, json
root = sys.argv[1]
names = json.load(open('/home/claude/work/map_names.json'))
reach = {v['name']: v.get('reachable') for v in names.values()}
out = []
for m in sorted(os.listdir(os.path.join(root, 'data/maps'))):
    p = os.path.join(root, 'data/maps', m, 'scripts.inc')
    if not os.path.exists(p): continue
    s = open(p).read().split('\n')
    # labels -> line index
    lab = {}
    for i, l in enumerate(s):
        mm = re.match(r'^(\w+)::', l)
        if mm: lab[mm.group(1)] = i
    hdr = lab.get(m + '_MapScripts')
    if hdr is None: continue
    seen = set()
    i = hdr + 1
    while i < len(s) and not s[i].strip().startswith('.byte 0'):
        mm = re.match(r'\s*map_script (MAP_SCRIPT_\w+), (\w+)', s[i])
        i += 1
        if not mm: continue
        t, ptr = mm.groups()
        if t in seen: continue
        seen.add(t)
        if not t.endswith('_TABLE') or ptr not in lab: continue
        j = lab[ptr] + 1
        ents = []
        while not s[j].strip().startswith('.2byte 0'):
            e = re.match(r'\s*map_script_2 (\w+), (\w+), (\w+)(.*)', s[j])
            if e: ents.append(e.groups())
            j += 1
        live_raw = [e for e in ents if re.match(r'0x', e[2]) and 'never match' not in e[3]]
        if live_raw:
            out.append((m, reach.get(m), t, ptr, len(ents), len(live_raw), sum(1 for e in ents if not e[2].startswith('0x'))))
for o in out: print(*o)
