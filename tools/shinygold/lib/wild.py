"""Extract the hack's wild encounter tables (gWildMonHeaders, repointed to 0x087CA898) into
pokefirered's src/data/wild_encounters.json format."""
import json, sys, collections
sys.path.insert(0, '/home/claude/sgx')
from core import *
import names as N

HEADERS = 0x7CA898
FIELDS = [
    {"type": "land_mons", "encounter_rates": [20, 20, 10, 10, 10, 10, 5, 5, 4, 4, 1, 1]},
    {"type": "water_mons", "encounter_rates": [60, 30, 5, 4, 1]},
    {"type": "rock_smash_mons", "encounter_rates": [60, 30, 5, 4, 1]},
    {"type": "fishing_mons", "encounter_rates": [70, 30, 60, 20, 20, 40, 40, 15, 4, 1],
     "groups": {"old_rod": [0, 1], "good_rod": [2, 3, 4], "super_rod": [5, 6, 7, 8, 9]}},
]
COUNTS = {'land_mons': 12, 'water_mons': 5, 'rock_smash_mons': 5, 'fishing_mons': 10}


def read_info(r, ptr, n):
    if ptr == 0: return None
    o = ptr - 0x08000000
    rate = r.u8(o)
    mp = r.ptr(o + 4)
    mons = []
    for i in range(n):
        q = mp + 4 * i
        mons.append(dict(min_level=r.u8(q), max_level=r.u8(q + 1), species=N.species(r.u16(q + 2))))
    return dict(encounter_rate=rate, mons=mons)


def extract(rom_path=HACK_ROM, headers=HEADERS):
    r = Rom(rom_path)
    out = []
    labels = collections.Counter()
    o = headers
    while True:
        g, m = r.u8(o), r.u8(o + 1)
        if g == 0xFF and m == 0xFF: break
        e = {"map": N.map_const(g, m)}
        nm = N.map_name(g, m) or 'G%dM%d' % (g, m)
        labels[nm] += 1
        e["base_label"] = 's' + nm + ('' if labels[nm] == 1 else '_%d' % labels[nm])
        for k, t in enumerate(['land_mons', 'water_mons', 'rock_smash_mons', 'fishing_mons']):
            info = read_info(r, r.u32(o + 4 + 4 * k), COUNTS[t])
            if info: e[t] = info
        out.append(e)
        o += 20
    return out


def to_json(encounters):
    return {"wild_encounter_groups": [{"label": "gWildMonHeaders", "for_maps": True, "fields": FIELDS,
                                       "encounters": encounters}]}


if __name__ == '__main__':
    enc = extract()
    json.dump(to_json(enc), open(sys.argv[1], 'w'), indent=2)
    print(len(enc), 'headers')
