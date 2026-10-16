"""Turn unreachable maps into empty stubs, keeping every map id (so saves keep loading on the right map).

usage: stub_maps.py <tree> <list-file>

For each listed map:
* map.json keeps its id/name/music/weather/type, gets the shared empty layout LAYOUT_EMPTY_STUB (1x1),
  MAPSEC_NONE, and no events or connections;
* its <Map>_MapScripts header becomes `.byte 0` (the script and text labels it used are left in place for
  prune_labels.py, which deletes whatever nothing else reaches);
* its wild encounter headers are removed;
* connections from kept maps into a stub are removed, and so are warps in kept maps that lead into a stub
  (they sit on non-warp tiles, otherwise the map would be reachable); warp ids pointing past a removed warp
  are renumbered, as in delete_maps.py;
* layouts used only by stubs become {} placeholders (layout ids stay stable) and their files are deleted.
"""
import os, re, sys, json, glob, shutil

tree, listfile = sys.argv[1], sys.argv[2]
STUB = [l.strip() for l in open(listfile) if l.strip() and not l.startswith('#')]
os.chdir(tree)
stubset = set(STUB)
info = {m: json.load(open('data/maps/%s/map.json' % m)) for m in STUB}
stub_ids = {j['id'] for j in info.values()}
old_layouts = {j['layout'] for j in info.values()}

def dump(p, j):
    open(p, 'w').write(json.dumps(j, indent=2, ensure_ascii=False) + '\n')

# ---------------------------------------------------------------- shared empty layout
lj = json.load(open('data/layouts/layouts.json'))
if not any(L and L['id'] == 'LAYOUT_EMPTY_STUB' for L in lj['layouts']):
    os.makedirs('data/layouts/EmptyStub', exist_ok=True)
    open('data/layouts/EmptyStub/map.bin', 'wb').write(bytes([0x01, 0x04]))      # metatile 1, collision 1
    open('data/layouts/EmptyStub/border.bin', 'wb').write(bytes([0x01, 0x04]) * 4)
    L = {'id': 'LAYOUT_EMPTY_STUB', 'name': 'EmptyStub_Layout', 'width': 1, 'height': 1, 'border_width': 2,
         'border_height': 2, 'primary_tileset': 'gTileset_General', 'secondary_tileset': 'gTileset_PalletTown',
         'border_filepath': 'data/layouts/EmptyStub/border.bin', 'blockdata_filepath': 'data/layouts/EmptyStub/map.bin'}
    slot = next((i for i, x in enumerate(lj['layouts']) if not x), None)   # reuse an empty slot: ids stay stable
    if slot is None: lj['layouts'].append(L)
    else: lj['layouts'][slot] = L

# ---------------------------------------------------------------- stub map.json + map script header
for m, j in info.items():
    keep = {k: j[k] for k in ('id', 'name', 'music', 'requires_flash', 'weather', 'map_type', 'allow_cycling',
                              'allow_escaping', 'allow_running', 'show_map_name', 'floor_number', 'battle_scene') if k in j}
    s = dict(id=keep['id'], name=keep['name'], layout='LAYOUT_EMPTY_STUB')
    s.update({k: v for k, v in keep.items() if k not in s})
    s['region_map_section'] = 'MAPSEC_NONE'
    s['show_map_name'] = False
    s.update(connections=None, object_events=[], warp_events=[], coord_events=[], bg_events=[])
    order = ['id', 'name', 'layout', 'music', 'region_map_section', 'requires_flash', 'weather', 'map_type',
             'allow_cycling', 'allow_escaping', 'allow_running', 'show_map_name', 'floor_number', 'battle_scene',
             'connections', 'object_events', 'warp_events', 'coord_events', 'bg_events']
    dump('data/maps/%s/map.json' % m, {k: s[k] for k in order if k in s})
    p = 'data/maps/%s/scripts.inc' % m
    lines = open(p, encoding='utf-8', errors='surrogateescape').read().split('\n')
    lab = '%s_MapScripts::' % m
    i = next(k for k, l in enumerate(lines) if l.strip().startswith(lab))
    k = i + 1
    while k < len(lines) and not re.match(r'^\s*\.byte 0\s*$', lines[k]):
        if re.match(r'^\w+::', lines[k]): k -= 1; break     # header shared with the next label: split it off
        k += 1
    lines[i:k + 1] = [lines[i], '\t@ ShinyGold: unreachable map, emptied (the slot is kept so map ids stay the same)', '\t.byte 0']
    open(p, 'w', encoding='utf-8', errors='surrogateescape').write('\n'.join(lines))

# ---------------------------------------------------------------- connections / warps into stubs
# warp indices something still arrives at (kept warps or script warps): those warps stay, as landing spots
targeted = {}
for p in glob.glob('data/maps/*/map.json'):
    if p.split('/')[2] in stubset: continue
    for w in json.load(open(p)).get('warp_events') or []:
        try: targeted.setdefault(w['dest_map'], set()).add(int(str(w['dest_warp_id']), 0))
        except ValueError: pass
WX = re.compile(r'^\s*(?:warp\w*|setwarp|setdynamicwarp|setescapewarp|setdivewarp|setholewarp)\s+(MAP_\w+)\s*,\s*(\w+)\s*,')
for f in glob.glob('data/maps/*/scripts.inc') + glob.glob('data/scripts/*.inc'):
    if f.startswith('data/maps/') and f.split('/')[2] in stubset: continue
    for l in open(f, encoding='utf-8', errors='surrogateescape'):
        mm = WX.match(l)
        if mm and l.split('@')[0].count(',') >= 3:
            try: targeted.setdefault(mm.group(1), set()).add(int(mm.group(2), 0))
            except ValueError: pass

remap, removed = {}, []
for p in sorted(glob.glob('data/maps/*/map.json')):
    m = p.split('/')[2]
    if m in stubset: continue
    j = json.load(open(p)); ch = False
    if j.get('connections'):
        keep = [c for c in j['connections'] if c['map'] not in stub_ids]
        if len(keep) != len(j['connections']):
            removed += ['%s connection -> %s' % (m, c['map']) for c in j['connections'] if c['map'] in stub_ids]
            j['connections'] = keep or None; ch = True
    if j.get('warp_events'):
        old = j['warp_events']
        tg = targeted.get(j['id'], set())
        keep = [w for i, w in enumerate(old) if w['dest_map'] not in stub_ids or i in tg]
        if len(keep) != len(old):
            removed += ['%s warp %d -> %s' % (m, i, w['dest_map']) for i, w in enumerate(old) if w['dest_map'] in stub_ids and i not in tg]
            idmap, k = {}, 0
            for i, w in enumerate(old):
                if w['dest_map'] not in stub_ids or i in tg: idmap[i] = k; k += 1
            remap[j['id']] = idmap
            j['warp_events'] = keep; ch = True
    if ch: dump(p, j)
unresolved = []
for p in sorted(glob.glob('data/maps/*/map.json')):
    j = json.load(open(p)); ch = False
    for w in j.get('warp_events') or []:
        if w['dest_map'] in remap:
            wid = int(str(w['dest_warp_id']), 0)
            if wid in remap[w['dest_map']] and remap[w['dest_map']][wid] != wid:
                w['dest_warp_id'] = str(remap[w['dest_map']][wid]); ch = True
            elif wid not in remap[w['dest_map']] and wid not in (0x7F, 0xFF):
                unresolved.append('%s -> %s warp %d' % (j['name'], w['dest_map'], wid))
    if ch: dump(p, j)
WRX = re.compile(r'^(\s*(?:warp\w*|setwarp|setdynamicwarp|setescapewarp|setdivewarp|setholewarp)\s+)(MAP_\w+)(\s*,\s*)(\w+)(.*)$')
for f in glob.glob('data/maps/*/scripts.inc') + glob.glob('data/scripts/*.inc'):
    lines = open(f, encoding='utf-8', errors='surrogateescape').read().split('\n'); ch = False
    for i, l in enumerate(lines):
        mm = WRX.match(l)
        if not mm or mm.group(2) not in remap or l.count(',') == 2: continue
        try: wid = int(mm.group(4), 0)
        except ValueError: continue
        if wid in (0x7F, 0xFF): continue
        if wid in remap[mm.group(2)] and remap[mm.group(2)][wid] != wid:
            lines[i] = mm.group(1) + mm.group(2) + mm.group(3) + str(remap[mm.group(2)][wid]) + mm.group(5); ch = True
        elif wid not in remap[mm.group(2)]:
            unresolved.append('%s: %s' % (f, l.strip()))
    if ch: open(f, 'w', encoding='utf-8', errors='surrogateescape').write('\n'.join(lines))

# ---------------------------------------------------------------- layouts only stubs used
used = {json.load(open(p))['layout'] for p in glob.glob('data/maps/*/map.json')}
dropped = []
for i, L in enumerate(lj['layouts']):
    if L and L['id'] in old_layouts and L['id'] not in used:
        dropped.append(L['id'])
        d = os.path.dirname(L['blockdata_filepath'])
        if os.path.isdir(d) and not any(x and x['id'] != L['id'] and os.path.dirname(x['blockdata_filepath']) == d
                                        for x in lj['layouts']):
            shutil.rmtree(d)
        lj['layouts'][i] = {}
dump('data/layouts/layouts.json', lj)

# ---------------------------------------------------------------- wild encounters
wj = json.load(open('src/data/wild_encounters.json'))
nw = 0
for g in wj['wild_encounter_groups']:
    n0 = len(g['encounters'])
    g['encounters'] = [e for e in g['encounters'] if e.get('map') not in stub_ids]
    nw += n0 - len(g['encounters'])
dump('src/data/wild_encounters.json', wj)

print('stubbed', len(STUB), '| removed warps/connections', len(removed), '| dropped layouts', len(dropped),
      '| wild headers', nw)
for r in removed: print('  ', r)
for u in unresolved: print('  UNRESOLVED', u)
