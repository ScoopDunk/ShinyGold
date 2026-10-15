"""Parse pret/pokegold trainer parties and match ShinyGold trainers to their Gold/Silver identities."""
import re, sys, json, collections
sys.path.insert(0, '/home/claude/sgx')
from core import *

PG = '/home/claude/work/gs_wild_src/pokegold'


def species_map():
    # pokegold species constant -> FR SPECIES_ name (same national dex names; a few spellings differ)
    special = {'NIDORAN_F': 'NIDORAN_F', 'NIDORAN_M': 'NIDORAN_M', 'MR__MIME': 'MR_MIME', 'FARFETCH_D': 'FARFETCHD',
               'HO_OH': 'HO_OH'}
    return lambda s: 'SPECIES_' + special.get(s, s)


def parse_parties():
    sm = species_map()
    out = []
    group = None
    cur = None
    for line in open(PG + '/data/trainers/parties.asm'):
        line = line.split(';')[0].rstrip()
        m = re.match(r'^(\w+)Group:', line)
        if m:
            group = m.group(1); continue
        m = re.match(r'\s*db "([^"]*)@", (TRAINERTYPE_\w+)', line)
        if m:
            cur = dict(group=group, name=m.group(1), type=m.group(2), mons=[])
            out.append(cur); continue
        m = re.match(r'\s*db -1', line)
        if m:
            cur = None; continue
        m = re.match(r'\s*db\s+(\d+),\s*(\w+)', line)
        if m and cur is not None:
            cur['mons'].append((int(m.group(1)), sm(m.group(2))))
    return out


def norm_class(s):
    s = s.upper().replace('{PKMN}', 'POKEMON').replace('POKé', 'POKE').replace('é', 'E').replace('♂', 'M').replace('♀', 'F')
    return re.sub(r'[^A-Z]', '', s)


GROUP_CLASS = {  # pokegold group -> normalized display class name used in G/S
}


def score(hmons, gmons):
    """Similarity between hack party [(species, lvl)] and G/S party."""
    hs = collections.Counter(s for s, l in hmons)
    gs = collections.Counter(s for l, s in gmons)
    inter = sum((hs & gs).values())
    union = sum((hs | gs).values())
    sp = inter / union if union else 0
    # level closeness on matched species
    lv = 0
    if inter:
        hl = sorted(l for s, l in hmons); gl = sorted(l for l, s in gmons)
        n = min(len(hl), len(gl))
        lv = sum(abs(a - b) for a, b in zip(hl[:n], gl[:n])) / n
    return sp - 0.01 * lv


HACK_TO_GROUPS = {
    'POKEFAN': ['PokefanM', 'PokefanF'], 'COOLTRAINER': ['CooltrainerM', 'CooltrainerF'], 'FISHERMAN': ['Fisher'],
    'BLACKBELT': ['Blackbelt'], 'POKEMANIAC': ['Pokemaniac'], 'TEAMROCKET': ['GruntM', 'GruntF', 'ExecutiveM', 'ExecutiveF'],
    'ROCKETDUO': ['GruntM', 'GruntF', 'ExecutiveM', 'ExecutiveF'], 'SWIMMERM': ['SwimmerM'], 'SWIMMERF': ['SwimmerF'],
    'PKMNTRAINER': ['PKMNTrainer', 'Rival1', 'Rival2', 'Red', 'Blue'], 'POKEMONTRAINER': ['PKMNTrainer', 'Rival1', 'Rival2'],
    'RIVAL': ['Rival1', 'Rival2'], 'CHAMPION': ['Rival1', 'Rival2', 'Champion'], 'EXECUTIVE': ['ExecutiveM', 'ExecutiveF'],
}


def candidate_groups(hack_class, all_groups):
    n = norm_class(hack_class)
    if n in HACK_TO_GROUPS: return HACK_TO_GROUPS[n]
    g = [x for x in all_groups if norm_class(x) == n]
    return g or list(all_groups)


def best_matches(hack_class, hmons, parties, k=3):
    groups = set(p['group'] for p in parties)
    cg = set(candidate_groups(hack_class, groups))
    scored = sorted(((score(hmons, p['mons']), p) for p in parties if p['group'] in cg), key=lambda x: -x[0])
    return scored[:k]
