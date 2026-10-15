"""Deterministic map naming for the ShinyGold decomp.

Produces /home/claude/work/map_names.json:
  { "G.N": {"name": "VioletCity_Interior3", "id": "MAP_VIOLET_CITY_INTERIOR3", "reachable": true,
            "vanilla_name": "...", "vanilla_id": "MAP_..."} }
"""
import json, re, collections, sys
sys.path.insert(0, '/home/claude/sgx')
from maps import *

OUTDOOR = {1, 2, 3, 6}  # TOWN, CITY, ROUTE, OCEAN_ROUTE


def camel(s):
    s = s.replace('’', '').replace("'", '').replace('.', ' ').replace('é', 'e').replace('É', 'E')
    words = re.findall(r'[A-Za-z0-9]+', s)
    out = ''
    for w in words:
        if w.isdigit(): out += w
        else: out += w[0].upper() + w[1:].lower()
    return out


def const_from_name(name):
    # PalletTown_PlayersHouse_1F -> PALLET_TOWN_PLAYERS_HOUSE_1F
    s = re.sub(r'([a-z])([A-Z])', r'\1_\2', name)
    s = re.sub(r'([A-Z])([A-Z][a-z])', r'\1_\2', s)
    s = s.replace('__', '_')
    return 'MAP_' + s.upper()


def build():
    r = Rom()
    groups, maps = load_map_headers(r)
    secnames = mapsec_names(r)
    mg = json.load(open('/home/claude/vanilla/data/maps/map_groups.json'))
    vnames = {}
    for gi, g in enumerate(mg['group_order']):
        for ni, n in enumerate(mg[g]): vnames[(gi, ni)] = n
    vids = {}
    for (g, n), nm in vnames.items():
        j = json.load(open('/home/claude/vanilla/data/maps/%s/map.json' % nm))
        vids[(g, n)] = j['id']
    # graph
    edges = collections.defaultdict(set)
    allm = {(m.group, m.num): m for m in maps}
    for m in maps:
        ev = parse_events(r, m.events)
        for w in ev['warps']:
            edges[(m.group, m.num)].add((w['map_group'], w['map_num']))
        c = parse_connections(r, m.connections)
        if c:
            for x in c['list']:
                edges[(m.group, m.num)].add((x['map_group'], x['map_num']))
    # approximate script warps: scan free-space for warp opcodes
    d = r.d
    script_targets = collections.Counter()
    for op in (0x39, 0x3a, 0x3b, 0x3d, 0x3e, 0x3f, 0xd1, 0xc4):
        for i in range(0x700000, len(d) - 8):
            if d[i] == op:
                g, n = d[i + 1], d[i + 2]
                if (g, n) in allm:
                    # require plausible coords: warpid byte then x,y s16 in small range or 0xFFFF
                    x = d[i + 4] | d[i + 5] << 8; y = d[i + 6] | d[i + 7] << 8
                    if (x < 200 or x == 0xFFFF) and (y < 200 or y == 0xFFFF):
                        script_targets[(g, n)] += 1
    start = (4, 1)
    seen = {start}
    stack = [start]
    seeds = set(k for k, c in script_targets.items())
    for s in seeds:
        if s not in seen: seen.add(s); stack.append(s)
    while stack:
        u = stack.pop()
        for v in edges[u]:
            if v in allm and v not in seen:
                seen.add(v); stack.append(v)
    # naming
    names = {}
    used = collections.Counter()
    by_sec = collections.defaultdict(list)
    for m in maps:
        by_sec[m.mapsec].append(m)
    # primary outdoor map per mapsec
    for sec, ms in by_sec.items():
        base = camel(secnames.get(sec) or 'Mapsec%02X' % sec)
        reach = [m for m in ms if (m.group, m.num) in seen]
        outdoor = [m for m in reach if m.map_type in OUTDOOR]
        sname = (secnames.get(sec) or '')
        pref = {1: 0, 2: 0, 3: 1, 6: 1} if (sname.endswith('TOWN') or sname.endswith('CITY')) else {3: 0, 6: 0, 1: 1, 2: 1}
        outdoor.sort(key=lambda m: (pref.get(m.map_type, 2), 0 if m.group == 3 else 1, m.group, m.num))
        counters = collections.Counter()
        for m in ms:
            key = (m.group, m.num)
            if key not in seen:
                continue
            if outdoor and m is outdoor[0]:
                nm = base
            else:
                kind = {8: 'Interior', 4: 'Cave', 5: 'Underwater', 1: 'Area', 2: 'Area', 3: 'Area', 6: 'Area'}.get(m.map_type, 'Map')
                counters[kind] += 1
                nm = '%s_%s%d' % (base, kind, counters[kind])
            names[key] = nm
    for m in maps:
        key = (m.group, m.num)
        if key in names: continue
        vn = vnames.get(key)
        names[key] = 'Unused_%s' % vn if vn else 'Unused_G%d_M%d' % key
    # the link-group maps keep vanilla names (engine-specific rooms)
    for k in [(0, 0), (0, 1), (0, 2), (0, 3), (0, 4)]:
        names[k] = vnames[k]
    # uniqueness
    seen_names = collections.Counter(names.values())
    assert all(c == 1 for c in seen_names.values()), [n for n, c in seen_names.items() if c > 1]
    out = {}
    for m in maps:
        key = (m.group, m.num)
        nm = names[key]
        cid = vids.get(key) if key[0] == 0 else const_from_name(nm)
        out['%d.%d' % key] = dict(name=nm, id=cid, group=key[0], num=key[1], reachable=key in seen,
                                  mapsec=secnames.get(m.mapsec), map_type=MAP_TYPES.get(m.map_type),
                                  vanilla_name=vnames.get(key), vanilla_id=vids.get(key),
                                  script_warp_target=script_targets.get(key, 0))
    return out


if __name__ == '__main__':
    out = build()
    json.dump(out, open('/home/claude/work/map_names.json', 'w'), indent=1)
    print(len(out), 'maps;', sum(1 for v in out.values() if v['reachable']), 'reachable')
