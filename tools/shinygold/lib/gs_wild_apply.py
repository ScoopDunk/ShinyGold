"""Rebuild ShinyGold's wild encounters from Gold/Silver.

Input : the faithful port of the hack's tables (src/data/wild_encounters.json) and the Gold+Silver merged,
        time-blended FireRed-format tables (/home/claude/work/gs_wild/fr_tables.json, from pret/pokegold).
Output: new src/data/wild_encounters.json + docs/wild_encounters_gs.md (per-map before/after report).

Policy
 * Maps that correspond to a G/S location get that location's tables (land/water/fishing), including its
   encounter rates; table types G/S doesn't have there are removed, ones it has are added.
 * "Rock smash" tables: the hack uses them on Johto routes as a stand-in for Headbutt trees (Aipom, Heracross,
   Spearow...).  Where G/S has real Rock Smash data it is used; otherwise, if G/S has headbutt trees at that
   location, the G/S headbutt distribution is fitted into FireRed's 5 rock-smash slots; otherwise removed.
 * Hack-only areas (no G/S counterpart) keep their tables, but every species that can't be found in the wild
   in Gold or Silver is replaced by a similar species that can (SUBST below), keeping the slot's levels.
 * Species list, IDs and the 386-species data are untouched.
"""
import json, sys, collections, copy, os
sys.path.insert(0, '/home/claude/sgx')

FR = json.load(open('/home/claude/work/gs_wild/fr_tables.json'))['locations']
GS_SPECIES = set(json.load(open('/home/claude/work/gs_wild/gs_wild_species.json'))['species'])
NAMES = json.load(open('/home/claude/work/map_names.json'))
BYID = {v['id']: v for v in NAMES.values()}

# hack map -> G/S location (pret constant).  None = hack-only area (sanitize).  'REMOVE' = G/S has no wild Pokemon here.
MAPPING = {
    # Johto routes / towns
    'MAP_ROUTE29': 'ROUTE_29', 'MAP_ROUTE30': 'ROUTE_30', 'MAP_ROUTE31': 'ROUTE_31', 'MAP_ROUTE32': 'ROUTE_32',
    'MAP_ROUTE33': 'ROUTE_33', 'MAP_ROUTE34': 'ROUTE_34', 'MAP_ROUTE35': 'ROUTE_35', 'MAP_ROUTE36': 'ROUTE_36',
    'MAP_ROUTE37': 'ROUTE_37', 'MAP_ROUTE38': 'ROUTE_38', 'MAP_ROUTE39': 'ROUTE_39', 'MAP_ROUTE40': 'ROUTE_40',
    'MAP_ROUTE41': 'ROUTE_41', 'MAP_ROUTE42': 'ROUTE_42', 'MAP_ROUTE43': 'ROUTE_43', 'MAP_ROUTE44': 'ROUTE_44',
    'MAP_ROUTE45': 'ROUTE_45', 'MAP_ROUTE46': 'ROUTE_46', 'MAP_ROUTE26': 'ROUTE_26', 'MAP_ROUTE27': 'ROUTE_27',
    'MAP_NEW_BARK_TOWN': 'NEW_BARK_TOWN', 'MAP_CHERRYGROVE_CITY': 'CHERRYGROVE_CITY', 'MAP_VIOLET_CITY': 'VIOLET_CITY',
    'MAP_AZALEA_TOWN': 'AZALEA_TOWN', 'MAP_GOLDENROD_CITY': 'GOLDENROD_CITY', 'MAP_ECRUTEAK_CITY': 'ECRUTEAK_CITY',
    'MAP_OLIVINE_CITY': 'OLIVINE_CITY', 'MAP_OLIVINE_CITY_AREA1': 'OLIVINE_PORT', 'MAP_CIANWOOD_CITY': 'CIANWOOD_CITY',
    'MAP_MAHOGANY_TOWN': 'REMOVE', 'MAP_BLACKTHORN_CITY': 'BLACKTHORN_CITY', 'MAP_LAKE_OF_RAGE': 'LAKE_OF_RAGE',
    # Johto dungeons
    'MAP_KALM_CITY_NOUSAR_INTERIOR3': 'SPROUT_TOWER_2F', 'MAP_SPROUT_TOWER_INTERIOR2': 'SPROUT_TOWER_3F', 'MAP_UNION_CAVE_CAVE1': 'UNION_CAVE_1F',
    'MAP_UNION_CAVE_CAVE2': 'UNION_CAVE_B1F', 'MAP_UNION_CAVE_CAVE3': 'UNION_CAVE_B2F',
    'MAP_RUINS_OF_ALPH': 'RUINS_OF_ALPH_OUTSIDE', 'MAP_ROUTE46_CAVE1': 'RUINS_OF_ALPH_INNER_CHAMBER',
    'MAP_ROUTE35_CAVE1': 'RUINS_OF_ALPH_INNER_CHAMBER', 'MAP_ROUTE33_CAVE1': 'RUINS_OF_ALPH_INNER_CHAMBER',
    'MAP_UNUSED_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER': 'RUINS_OF_ALPH_INNER_CHAMBER',
    'MAP_SLOWPOKE_WELL_CAVE1': 'SLOWPOKE_WELL_B1F', 'MAP_SLOWPOKE_WELL_CAVE2': 'SLOWPOKE_WELL_B2F',
    'MAP_ILEX_FOREST_INTERIOR1': 'ILEX_FOREST', 'MAP_NATIONAL_PARK': 'NATIONAL_PARK',
    'MAP_ECRUTEAK_CITY_INTERIOR1': 'BURNED_TOWER_1F', 'MAP_ECRUTEAK_CITY_CAVE1': 'BURNED_TOWER_B1F',
    'MAP_DARK_CAVE_CAVE1': 'DARK_CAVE_VIOLET_ENTRANCE', 'MAP_DARK_CAVE_CAVE2': 'DARK_CAVE_BLACKTHORN_ENTRANCE',
    'MAP_MT_MORTAR_CAVE1': 'MOUNT_MORTAR_1F_OUTSIDE', 'MAP_MT_MORTAR_CAVE2': 'MOUNT_MORTAR_1F_INSIDE',
    'MAP_MT_MORTAR_CAVE3': 'MOUNT_MORTAR_2F_INSIDE', 'MAP_MT_MORTAR_CAVE4': 'MOUNT_MORTAR_B1F',
    'MAP_WHIRL_ISLANDS_CAVE1': 'WHIRL_ISLAND_SW', 'MAP_WHIRL_ISLANDS_CAVE6': 'WHIRL_ISLAND_NW',
    'MAP_WHIRL_ISLANDS_CAVE7': 'WHIRL_ISLAND_NE', 'MAP_WHIRL_ISLANDS_CAVE8': 'WHIRL_ISLAND_SE',
    'MAP_WHIRL_ISLANDS_CAVE2': 'WHIRL_ISLAND_CAVE', 'MAP_WHIRL_ISLANDS_CAVE3': 'WHIRL_ISLAND_B1F',
    'MAP_WHIRL_ISLANDS_CAVE5': 'WHIRL_ISLAND_B2F', 'MAP_WHIRL_ISLANDS_CAVE4': 'WHIRL_ISLAND_LUGIA_CHAMBER',
    'MAP_ICE_PATH_CAVE1': 'ICE_PATH_1F', 'MAP_ICE_PATH_CAVE2': 'ICE_PATH_B1F', 'MAP_ICE_PATH_CAVE3': 'ICE_PATH_B2F_MAHOGANY_SIDE',
    'MAP_ICE_PATH_CAVE4': 'ICE_PATH_B3F', 'MAP_ICE_PATH_CAVE5': 'ICE_PATH_B2F_BLACKTHORN_SIDE',
    'MAP_ICE_PATH_CAVE6': 'ICE_PATH_B2F_BLACKTHORN_SIDE', 'MAP_DRAGONS_DEN_CAVE4': 'DRAGONS_DEN_B1F',
    'MAP_TOHJO_FALLS_CAVE1': 'TOHJO_FALLS', 'MAP_MT_SILVER': 'SILVER_CAVE_OUTSIDE', 'MAP_MT_SILVER_CAVE3': 'SILVER_CAVE_ROOM_1',
    'MAP_MT_SILVER_CAVE2': 'SILVER_CAVE_ROOM_2', 'MAP_MT_SILVER_CAVE1': 'SILVER_CAVE_ROOM_3',
    'MAP_VICTORY_ROAD_CAVE1': 'VICTORY_ROAD', 'MAP_VICTORY_ROAD_CAVE2': 'VICTORY_ROAD', 'MAP_VICTORY_ROAD_CAVE3': 'VICTORY_ROAD',
    'MAP_VICTORY_ROAD_CAVE4': 'VICTORY_ROAD', 'MAP_SS_AQUA_INTERIOR1': 'REMOVE',
    # Kanto
    'MAP_ROUTE1': 'ROUTE_1', 'MAP_ROUTE2': 'ROUTE_2', 'MAP_ROUTE3': 'ROUTE_3', 'MAP_ROUTE4': 'ROUTE_4', 'MAP_ROUTE5': 'ROUTE_5',
    'MAP_ROUTE6': 'ROUTE_6', 'MAP_ROUTE7': 'ROUTE_7', 'MAP_ROUTE8': 'ROUTE_8', 'MAP_ROUTE9': 'ROUTE_9', 'MAP_ROUTE10': 'ROUTE_10_NORTH',
    'MAP_ROUTE11': 'ROUTE_11', 'MAP_ROUTE12': 'ROUTE_12', 'MAP_ROUTE13': 'ROUTE_13', 'MAP_ROUTE14': 'ROUTE_14',
    'MAP_ROUTE15': 'ROUTE_15', 'MAP_ROUTE16': 'ROUTE_16', 'MAP_ROUTE17': 'ROUTE_17', 'MAP_ROUTE18': 'ROUTE_18',
    'MAP_ROUTE19': 'ROUTE_19', 'MAP_ROUTE20': 'ROUTE_20', 'MAP_ROUTE21': 'ROUTE_21', 'MAP_ROUTE22': 'ROUTE_22',
    'MAP_ROUTE23': 'REMOVE', 'MAP_ROUTE24': 'ROUTE_24', 'MAP_ROUTE25': 'ROUTE_25', 'MAP_ROUTE28': 'ROUTE_28',
    'MAP_PALLET_TOWN': 'PALLET_TOWN', 'MAP_VIRIDIAN_CITY': 'VIRIDIAN_CITY', 'MAP_CERULEAN_CITY': 'CERULEAN_CITY',
    'MAP_CERULEAN_CITY_INTERIOR7': 'CERULEAN_GYM', 'MAP_VERMILION_CITY': 'VERMILION_CITY', 'MAP_VERMILION_CITY_AREA1': 'VERMILION_PORT',
    'MAP_CELADON_CITY': 'CELADON_CITY', 'MAP_FUCHSIA_CITY': 'FUCHSIA_CITY', 'MAP_CINNABAR_ISLAND': 'CINNABAR_ISLAND',
    'MAP_DIGLETTS_CAVE_CAVE2': 'DIGLETTS_CAVE', 'MAP_MT_MOON_CAVE1': 'MOUNT_MOON', 'MAP_ROCK_TUNNEL_CAVE2': 'ROCK_TUNNEL_1F',
    'MAP_ROCK_TUNNEL_CAVE3': 'ROCK_TUNNEL_B1F',
}

# replacement for species that are not wild in Gold/Silver (key -> land/default, water/fishing context override)
SUBST = {
    'ABSOL': 'SNEASEL', 'ARON': 'GEODUDE', 'AZURILL': 'MARILL', 'BALTOY': 'NATU', 'BANETTE': 'HAUNTER', 'BARBOACH': 'WOOPER',
    'BEAUTIFLY': 'BUTTERFREE', 'BLISSEY': 'CHANSEY', 'BRELOOM': 'PARAS', 'BULBASAUR': 'ODDISH', 'CACNEA': 'SUNKERN',
    'CAMERUPT': 'MAGMAR', 'CARVANHA': 'QWILFISH', 'CASTFORM': 'SEEL', 'CLAMPERL': 'SHELLDER', 'CLOYSTER': 'SHELLDER',
    'CORPHISH': 'KRABBY', 'CRAWDAUNT': 'KINGLER', 'DEWGONG': 'SEEL', 'DUSKULL': 'GASTLY', 'DUSTOX': 'VENOMOTH',
    'ELECTRIKE': 'MAREEP', 'ELECTRODE': 'VOLTORB', 'GENGAR': 'HAUNTER', 'GOLEM': 'GRAVELER', 'GRANBULL': 'SNUBBULL',
    'GULPIN': 'GRIMER', 'HOUNDOOM': 'HOUNDOUR', 'IGGLYBUFF': 'JIGGLYPUFF', 'ILLUMISE': 'LEDYBA', 'JUMPLUFF': 'SKIPLOOM',
    'KECLEON': 'AIPOM', 'KIRLIA': 'KADABRA', 'LAIRON': 'GRAVELER', 'LAPRAS': 'TENTACRUEL', 'LINOONE': 'FURRET',
    'LOMBRE': 'POLIWHIRL', 'LOTAD': 'POLIWAG', 'LOUDRED': 'JIGGLYPUFF', 'LUNATONE': 'CLEFAIRY', 'LUVDISC': 'GOLDEEN',
    'MAGCARGO': 'SLUGMA', 'MAGNETON': 'MAGNEMITE', 'MAKUHITA': 'MACHOP', 'MASQUERAIN': 'YANMA', 'MAWILE': 'SNUBBULL',
    'MEDITITE': 'MANKEY', 'MIGHTYENA': 'HOUNDOUR', 'MINUN': 'PIKACHU', 'MUDKIP': 'WOOPER', 'NINCADA': 'PARAS',
    'NINJASK': 'YANMA', 'NOSEPASS': 'GEODUDE', 'NUMEL': 'SLUGMA', 'NUZLEAF': 'WEEPINBELL', 'PARASECT': 'PARAS',
    'PILOSWINE': 'SWINUB', 'PLUSLE': 'PIKACHU', 'POLIWRATH': 'POLIWHIRL', 'POOCHYENA': 'HOUNDOUR', 'PUPITAR': 'LARVITAR',
    'RALTS': 'ABRA', 'RELICANTH': 'QWILFISH', 'ROSELIA': 'ODDISH', 'SABLEYE': 'GASTLY', 'SCIZOR': 'SCYTHER',
    'SEALEO': 'SEEL', 'SEEDOT': 'SUNKERN', 'SEVIPER': 'ARBOK', 'SHARPEDO': 'QWILFISH', 'SHEDINJA': 'PINECO',
    'SHIFTRY': 'WEEPINBELL', 'SHROOMISH': 'PARAS', 'SHUPPET': 'GASTLY', 'SKITTY': 'MEOWTH', 'SLAKING': 'URSARING',
    'SLAKOTH': 'TEDDIURSA', 'SLOWKING': 'SLOWBRO', 'SMOOCHUM': 'JYNX', 'SNORUNT': 'DELIBIRD', 'SOLROCK': 'GRAVELER',
    'SPHEAL': 'SEEL', 'SPINDA': 'SENTRET', 'SPOINK': 'DROWZEE', 'SQUIRTLE': 'POLIWAG', 'STEELIX': 'ONIX',
    'SURSKIT': 'YANMA', 'SWABLU': 'HOOTHOOT', 'SWALOT': 'MUK', 'SWELLOW': 'PIDGEOTTO', 'TAILLOW': 'PIDGEY',
    'TORCHIC': 'GROWLITHE', 'TORKOAL': 'SLUGMA', 'TRAPINCH': 'SANDSHREW', 'TROPIUS': 'TANGELA', 'VIGOROTH': 'PRIMEAPE',
    'VILEPLUME': 'GLOOM', 'VOLBEAT': 'LEDYBA', 'WAILMER': 'TENTACOOL', 'WAILORD': 'TENTACRUEL', 'WHISCASH': 'QUAGSIRE',
    'WHISMUR': 'JIGGLYPUFF', 'WINGULL': 'PIDGEY', 'WURMPLE': 'CATERPIE', 'WYNAUT': 'WOBBUFFET', 'ZANGOOSE': 'SANDSLASH',
    'ZIGZAGOON': 'SENTRET',
}
SUBST_WATER = {'SURSKIT': 'POLIWAG', 'MASQUERAIN': 'POLIWHIRL', 'WINGULL': 'TENTACOOL', 'SQUIRTLE': 'POLIWAG',
               'LOTAD': 'POLIWAG', 'BARBOACH': 'WOOPER', 'MUDKIP': 'WOOPER', 'SPHEAL': 'SEEL'}
for k, v in list(SUBST.items()):
    assert 'SPECIES_' + v in GS_SPECIES, (k, v)
for k, v in SUBST_WATER.items():
    assert 'SPECIES_' + v in GS_SPECIES, (k, v)

TYPES = ('land_mons', 'water_mons', 'rock_smash_mons', 'fishing_mons')
RS_RATES = [60, 30, 5, 4, 1]


def fit5(pct):
    """Fit a species-share dict into the 5 rock-smash slots (60/30/5/4/1), largest shares first, every species >=1 slot
    when possible; returns list of species per slot."""
    sp = sorted(pct.items(), key=lambda x: -x[1])[:5]
    best = None
    import itertools
    n = len(sp)
    for assign in itertools.product(range(n), repeat=5):
        if len(set(assign)) < n: continue
        share = collections.Counter()
        for slot, i in zip(RS_RATES, assign): share[i] += slot
        err = sum(abs(share[i] - sp[i][1]) for i in range(n))
        key = (err, assign)
        if best is None or key < best: best = key
    return [sp[i][0] for i in best[1]]


def headbutt_table(loc, rate):
    hb = FR[loc]['_extra']['headbutt']
    pct = hb['target_species_pct']
    lv = collections.defaultdict(list)
    for m in hb['mons']:
        lv[m['species']] += [m['min_level'], m['max_level']]
    slots = fit5(pct)
    return dict(encounter_rate=rate, mons=[dict(min_level=min(lv[s]), max_level=max(lv[s]), species=s) for s in slots])


def sanitize(tab, kind, notes):
    out = copy.deepcopy(tab)
    common = collections.Counter(m['species'] for m in tab['mons'] if m['species'] in GS_SPECIES).most_common(1)
    for m in out['mons']:
        s = m['species']
        if s in GS_SPECIES: continue
        k = s[len('SPECIES_'):]
        if k == 'NONE':
            new = common[0][0] if common else 'SPECIES_RATTATA'
        else:
            new = 'SPECIES_' + (SUBST_WATER.get(k) if kind in ('water_mons', 'fishing_mons') and k in SUBST_WATER else SUBST[k])
        notes.append('%s %s -> %s' % (kind.split('_')[0], k, new[8:]))
        m['species'] = new
    return out


def apply(encounters):
    report = []
    out = []
    for e in encounters:
        e2 = {k: v for k, v in e.items() if k not in TYPES}
        target = MAPPING.get(e['map'])
        notes = []
        if target == 'REMOVE':
            notes.append('G/S has no wild Pokemon here: all tables removed')
        elif target:
            loc = FR[target]
            for t in ('land_mons', 'water_mons', 'fishing_mons'):
                if t in loc:
                    e2[t] = {'encounter_rate': loc[t]['encounter_rate'], 'mons': loc[t]['mons']}
            if 'rock_smash_mons' in loc:
                e2['rock_smash_mons'] = {'encounter_rate': loc['rock_smash_mons']['encounter_rate'], 'mons': loc['rock_smash_mons']['mons']}
                notes.append('rock smash: G/S rock smash table')
            elif 'rock_smash_mons' in e and 'headbutt' in loc.get('_extra', {}):
                e2['rock_smash_mons'] = headbutt_table(target, e['rock_smash_mons']['encounter_rate'])
                notes.append('rock smash (hack headbutt stand-in): G/S headbutt trees')
            elif 'rock_smash_mons' in e:
                notes.append('rock smash table removed (none in G/S)')
            notes.append('tables from G/S %s' % target)
        else:
            for t in TYPES:
                if t in e:
                    e2[t] = sanitize(e[t], t, notes)
            if not notes: notes.append('hack-only area, already G/S species only')
            else: notes.insert(0, 'hack-only area, sanitized')
        out.append(e2)
        report.append((e, e2, target, notes))
    return out, report


def species_summary(e):
    parts = []
    for t in TYPES:
        if t in e:
            c = collections.Counter(m['species'][8:].title() for m in e[t]['mons'])
            parts.append('%s: %s' % ({'land_mons': 'grass', 'water_mons': 'surf', 'rock_smash_mons': 'rock', 'fishing_mons': 'fish'}[t],
                                     ', '.join(sorted(c))))
    return '; '.join(parts) or '—'


def main(wt):
    p = os.path.join(wt, 'src/data/wild_encounters.json')
    j = json.load(open(p))
    enc = j['wild_encounter_groups'][0]['encounters']
    new, report = apply(enc)
    j['wild_encounter_groups'][0]['encounters'] = new
    json.dump(j, open(p, 'w'), indent=2)
    open(p, 'a').write('\n')
    # report
    L = ['# Wild encounters: Gold/Silver rebuild', '',
         'Generated by `tools/shinygold/gs_wild_apply.py`. Gold and Silver tables are merged (Silver exclusives added) and',
         'morning/day/night are blended by hours (6/8/10); see the policy at the top of the script.', '',
         '| Map | G/S location | Before (hack) | After | Notes |', '|---|---|---|---|---|']
    for e, e2, target, notes in report:
        L.append('| %s | %s | %s | %s | %s |' % (e['map'][4:], target or 'hack-only', species_summary(e), species_summary(e2), '; '.join(notes)))
    os.makedirs(os.path.join(wt, 'docs'), exist_ok=True)
    open(os.path.join(wt, 'docs/wild_encounters_gs.md'), 'w').write('\n'.join(L) + '\n')
    # leftovers check
    bad = [(e['map'], m['species']) for e in new for t in TYPES for m in e.get(t, {}).get('mons', []) if m['species'] not in GS_SPECIES]
    print('non-G/S species left:', bad)
    used = set(MAPPING.values()) - {'REMOVE'}
    print('G/S locations not used:', sorted(k for k in FR if k not in used))


if __name__ == '__main__':
    main(sys.argv[1])
