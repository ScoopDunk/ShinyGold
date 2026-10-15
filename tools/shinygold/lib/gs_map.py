"""Propose a mapping hack wild-header map -> Gold/Silver location (pret constant)."""
import json, re, sys, collections
sys.path.insert(0, '/home/claude/sgx')

FR = json.load(open('/home/claude/work/gs_wild/fr_tables.json'))['locations']
NAMES = json.load(open('/home/claude/work/map_names.json'))
BYID = {v['id']: v for v in NAMES.values()}

FAMILIES = {
    'UNION CAVE': ['UNION_CAVE_1F', 'UNION_CAVE_B1F', 'UNION_CAVE_B2F'],
    'DARK CAVE': ['DARK_CAVE_VIOLET_ENTRANCE', 'DARK_CAVE_BLACKTHORN_ENTRANCE'],
    'ICE PATH': ['ICE_PATH_1F', 'ICE_PATH_B1F', 'ICE_PATH_B2F_MAHOGANY_SIDE', 'ICE_PATH_B2F_BLACKTHORN_SIDE', 'ICE_PATH_B3F'],
    'MT. MORTAR': ['MOUNT_MORTAR_1F_OUTSIDE', 'MOUNT_MORTAR_1F_INSIDE', 'MOUNT_MORTAR_2F_INSIDE', 'MOUNT_MORTAR_B1F'],
    'WHIRL ISLANDS': ['WHIRL_ISLAND_NW', 'WHIRL_ISLAND_NE', 'WHIRL_ISLAND_SW', 'WHIRL_ISLAND_CAVE', 'WHIRL_ISLAND_SE',
                      'WHIRL_ISLAND_B1F', 'WHIRL_ISLAND_B2F', 'WHIRL_ISLAND_LUGIA_CHAMBER'],
    'SLOWPOKE WELL': ['SLOWPOKE_WELL_B1F', 'SLOWPOKE_WELL_B2F'],
    'MT. SILVER': ['SILVER_CAVE_OUTSIDE', 'SILVER_CAVE_ROOM_1', 'SILVER_CAVE_ROOM_2', 'SILVER_CAVE_ROOM_3', 'SILVER_CAVE_ITEM_ROOMS'],
    'VICTORY ROAD': ['VICTORY_ROAD'], 'ROCK TUNNEL': ['ROCK_TUNNEL_1F', 'ROCK_TUNNEL_B1F'],
    'DIGLETT’S CAVE': ['DIGLETTS_CAVE'], 'MT. MOON': ['MOUNT_MOON'], 'TOHJO FALLS': ['TOHJO_FALLS'],
    'RUINS OF ALPH': ['RUINS_OF_ALPH_OUTSIDE', 'RUINS_OF_ALPH_INNER_CHAMBER'], 'ILEX FOREST': ['ILEX_FOREST'],
    'NATIONAL PARK': ['NATIONAL_PARK'], 'DRAGON’S DEN': ['DRAGONS_DEN_B1F'], 'SPROUT TOWER': ['SPROUT_TOWER_2F', 'SPROUT_TOWER_3F'],
    'LAKE OF RAGE': ['LAKE_OF_RAGE'],
}
TOWNS = {'NEW BARK TOWN': 'NEW_BARK_TOWN', 'CHERRYGROVE CITY': 'CHERRYGROVE_CITY', 'VIOLET CITY': 'VIOLET_CITY',
         'AZALEA TOWN': 'AZALEA_TOWN', 'GOLDENROD CITY': 'GOLDENROD_CITY', 'ECRUTEAK CITY': 'ECRUTEAK_CITY',
         'OLIVINE CITY': 'OLIVINE_CITY', 'CIANWOOD CITY': 'CIANWOOD_CITY', 'MAHOGANY TOWN': None, 'BLACKTHORN CITY': 'BLACKTHORN_CITY',
         'PALLET TOWN': 'PALLET_TOWN', 'VIRIDIAN CITY': 'VIRIDIAN_CITY', 'PEWTER CITY': None, 'CERULEAN CITY': 'CERULEAN_CITY',
         'LAVENDER TOWN': None, 'VERMILION CITY': 'VERMILION_CITY', 'CELADON CITY': 'CELADON_CITY', 'FUCHSIA CITY': 'FUCHSIA_CITY',
         'CINNABAR ISLAND': 'CINNABAR_ISLAND', 'SAFFRON CITY': None, 'INDIGO PLATEAU': None}


def species_of(tab):
    return collections.Counter(m['species'] for m in tab['mons']) if tab else collections.Counter()


def sim(enc, loc):
    """Similarity of a hack header to a G/S location: species overlap of land (+water) tables and level closeness."""
    s = 0
    for t in ('land_mons', 'water_mons'):
        a = set(species_of(enc.get(t))); b = set(species_of(loc.get(t)))
        if a or b:
            s += len(a & b) / max(1, len(a | b))
    la = [m['min_level'] for m in enc.get('land_mons', {}).get('mons', [])]
    lb = [m['min_level'] for m in loc.get('land_mons', {}).get('mons', [])]
    if la and lb:
        s -= abs(sum(la) / len(la) - sum(lb) / len(lb)) / 50
    return s


def propose(encounters):
    out = []
    for e in encounters:
        m = BYID.get(e['map'], {})
        sec = m.get('mapsec') or ''
        name = m.get('name', '')
        land = e.get('land_mons')
        cand = None; why = ''
        if land and all(x['species'] == 'SPECIES_UNOWN' for x in land['mons']):
            cand, why = 'RUINS_OF_ALPH_INNER_CHAMBER', 'Unown chamber (vanilla Tanoby chamber slot)'
        elif re.match(r'^ROUTE (\d+)$', sec) and name == sec.title().replace(' ', ''):
            n = int(sec.split()[1])
            k = 'ROUTE_%d' % n
            if n == 10: k = 'ROUTE_10_NORTH'
            cand, why = (k, 'route by name') if k in FR else (None, 'G/S route has no wild data')
        elif sec in TOWNS and '_' not in name:
            cand, why = TOWNS[sec], 'town by name'
        elif sec in FAMILIES:
            fam = FAMILIES[sec]
            scored = sorted(((sim(e, FR[k]), k) for k in fam if k in FR), reverse=True)
            if scored:
                cand, why = scored[0][1], 'family %s, best fingerprint %.2f (next %s)' % (sec, scored[0][0], scored[1:2])
        out.append(dict(map=e['map'], name=name, mapsec=sec, reachable=m.get('reachable'), gs=cand, why=why,
                        tables=[t for t in ('land_mons', 'water_mons', 'rock_smash_mons', 'fishing_mons') if t in e]))
    return out


if __name__ == '__main__':
    enc = json.load(open(sys.argv[1]))['wild_encounter_groups'][0]['encounters']
    for p in propose(enc):
        print('%-40s %-18s %-5s %-30s %s %s' % (p['map'], p['mapsec'], p['reachable'], p['gs'], ','.join(t[:4] for t in p['tables']), p['why']))
