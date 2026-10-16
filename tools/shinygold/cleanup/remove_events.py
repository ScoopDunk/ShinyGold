"""Remove map events by index without disturbing anything that refers to the rest.

usage: remove_events.py <tree> <list-file>
list lines: <Map> obj|bg|coord <0-based index> [anything else]   ('#' comments allowed)

Objects keep their local ids: every object after a removed one that relied on its position for its id gets
"explicit_local_id" set to the id it had, so no script, save or flag reference changes meaning.
"""
import os, sys, json, collections

tree, lst = sys.argv[1], sys.argv[2]
os.chdir(tree)
rm = collections.defaultdict(lambda: collections.defaultdict(set))
for l in open(lst):
    l = l.split('#')[0].split()
    if len(l) < 3: continue
    rm[l[0]][l[1]].add(int(l[2]))
KEY = {'obj': 'object_events', 'bg': 'bg_events', 'coord': 'coord_events'}
n = collections.Counter()
for m, kinds in sorted(rm.items()):
    p = 'data/maps/%s/map.json' % m
    j = json.load(open(p))
    for kind, idx in kinds.items():
        evs = j.get(KEY[kind]) or []
        assert all(0 <= i < len(evs) for i in idx), (m, kind, sorted(idx), len(evs))
        if kind == 'obj':
            for i, o in enumerate(evs):
                if i not in idx and 'explicit_local_id' not in o and any(r < i for r in idx):
                    o['explicit_local_id'] = i + 1
        j[KEY[kind]] = [e for i, e in enumerate(evs) if i not in idx]
        n[kind] += len(idx)
    open(p, 'w').write(json.dumps(j, indent=2, ensure_ascii=False) + '\n')
print('removed', dict(n), 'from', len(rm), 'maps')
