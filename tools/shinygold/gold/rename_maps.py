"""Rename maps in the decomp tree (map dir, MAP_ constant, layout, labels).

usage: rename_maps.py <tree> Old=New [Old=New ...]

For each map: moves data/maps/Old -> data/maps/New and data/layouts/<its layout dir> -> data/layouts/New,
sets map.json name/id and the layout id/name/paths, and replaces the tokens everywhere in data/, src/, include/:
  Old (as a label prefix or word)  -> New
  MAP_OLD                          -> MAP_NEW
  LAYOUT_OLD                       -> LAYOUT_NEW
Aliases in include/constants/map_compat.h that would become '#define X X' are dropped.
Generated files (events.inc, header.inc, connections.inc, map_groups.h, layouts.h ...) are left to the build.
"""
import os, re, sys, json, glob, subprocess

tree = sys.argv[1]
pairs = [a.split('=') for a in sys.argv[2:]]
os.chdir(tree)


def const(name):
    # CamelCase -> CAMEL_CASE; digit runs stay attached (B1F -> B1F, Interior10 -> INTERIOR10)
    s = re.sub(r'(?<=[a-z])(?=[A-Z])|(?<=[A-Z0-9])(?=[A-Z][a-z])', '_', name)
    return s.upper()


lay = json.load(open('data/layouts/layouts.json'))
subs = []
for old, new in pairs:
    assert os.path.isdir('data/maps/' + old), old
    assert not os.path.exists('data/maps/' + new), new
    j = json.load(open('data/maps/%s/map.json' % old))
    old_id, old_layout = j['id'], j['layout']
    new_id = 'MAP_' + const(new)
    new_layout = 'LAYOUT_' + const(new)
    users = [m for m in os.listdir('data/maps') if os.path.isfile('data/maps/%s/map.json' % m) and json.load(open('data/maps/%s/map.json' % m))['layout'] == old_layout]
    rename_layout = users == [old]
    subs.append((re.compile(r'\b%s\b' % re.escape(old_id)), new_id))
    if rename_layout:
        subs.append((re.compile(r'\b%s\b' % re.escape(old_layout)), new_layout))
    subs.append((re.compile(r'\b%s(?=\b|_)' % re.escape(old)), new))
    subprocess.run(['git', 'mv', 'data/maps/' + old, 'data/maps/' + new], check=True)
    if rename_layout:
        for L in lay['layouts']:
            if L and L.get('id') == old_layout:
                d = os.path.dirname(L['blockdata_filepath'])
                nd = 'data/layouts/' + new
                if d != nd and os.path.isdir(d):
                    subprocess.run(['git', 'mv', d, nd], check=True)
                for k in ('blockdata_filepath', 'border_filepath'):
                    L[k] = L[k].replace(d + '/', nd + '/')
                L['name'] = new + '_Layout'
    print('%s -> %s  (%s -> %s%s)' % (old, new, old_id, new_id, ', layout renamed' if rename_layout else ', layout shared: kept'))
open('data/layouts/layouts.json', 'w').write(json.dumps(lay, indent=2, ensure_ascii=False) + '\n')

GEN = re.compile(r'(events|header|connections)\.inc$|constants/(map_groups|layouts)\.h$|data/maps/(headers|groups|connections|events)\.inc$|layouts_table\.inc$|data/layouts/layouts\.inc$')
files = subprocess.run(['git', 'ls-files', 'data', 'src', 'include', 'asm', 'ld_script.ld', 'sym_ewram.txt'], capture_output=True, text=True).stdout.split()
changed = 0
for f in files:
    if GEN.search(f) or not os.path.isfile(f): continue
    if not f.endswith(('.inc', '.s', '.c', '.h', '.json', '.txt', '.ld')): continue
    s = open(f, encoding='utf-8', errors='surrogateescape').read()
    t = s
    for rx, rep in subs: t = rx.sub(rep, t)
    if f == 'include/constants/map_compat.h':
        t = '\n'.join(l for l in t.split('\n') if not re.match(r'#define\s+(\w+)\s+\1\s*(//.*)?$', l))
    if t != s:
        open(f, 'w', encoding='utf-8', errors='surrogateescape').write(t)
        changed += 1
print('files changed:', changed)
