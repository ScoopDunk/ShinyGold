#!/usr/bin/env python3
"""ShinyGold data-table port generator (data worker).

Reads the hack ROM and rewrites the decomp data sources in the `data` worktree.
Every output is derived from the pristine vanilla sources in /home/claude/vanilla plus the hack ROM,
so the script is idempotent.

Usage: python3 gen_data.py [WORKTREE]
"""
import sys, os, re, json, struct, collections
sys.path.insert(0, '/home/claude/sgx')
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from core import *
from names import trainer_const, species as species_c, item as item_c, move as move_c

WT = sys.argv[1] if len(sys.argv) > 1 else '/home/claude/wt/data'
VAN = '/home/claude/vanilla'
OUT = '/home/claude/work/data'
H = Rom()
V = Rom(VANILLA_ROM)


def vread(path):
    return open(os.path.join(VAN, path), encoding='utf-8').read()


def wwrite(path, s):
    p = os.path.join(WT, path)
    old = open(p, encoding='utf-8').read() if os.path.exists(p) else None
    if old != s:
        open(p, 'w', encoding='utf-8').write(s)
        print('wrote', path)


def sym(name):
    for a, s, n in vanilla_symbols()[1]:
        if n == name:
            return a, s
    raise KeyError(name)


# ------------------------------------------------------------------ string helpers
def text_body(data, off, maxlen=4096):
    """Return preproc string body (without trailing $) that encodes exactly to data[off:FF]."""
    toks, end = decode_tokens(data, off, maxlen)
    if toks is None:
        raise ValueError('unterminated string at %x' % off)
    body = ''.join(toks)
    if encode_tokens_str(body) + b'\xff' != bytes(data[off:end]):
        body = ''.join('{0x%02X}' % b for b in data[off:end - 1])
    return body


def fixed_text_body(raw):
    """String in a fixed-size field (e.g. trainer name). Returns body or raises if unterminated."""
    if 0xFF not in raw:
        raise ValueError('unterminated fixed string %s' % raw.hex())
    return text_body(raw, 0)


# ------------------------------------------------------------------ constant helpers
VALS, FILES, ORDER = c_constants()


def rev(prefix, file=None, exclude=None):
    return reverse_constants(prefix, file=file, exclude=exclude)


CLASS_C = rev('TRAINER_CLASS_', 'trainers.h', lambda n: n.endswith('_COUNT'))
PIC_C = rev('TRAINER_PIC_', 'trainers.h', lambda n: n.endswith('_COUNT'))
MUSIC_C = rev('TRAINER_ENCOUNTER_MUSIC_', 'trainers.h')
AI_BITS = [(VALS[n], n) for n in ORDER if n.startswith('AI_SCRIPT_') and FILES.get(n) == 'battle_ai.h']
HOLD_C = rev('HOLD_EFFECT_', 'hold_effects.h')
POCKET_C = {1: 'POCKET_ITEMS', 2: 'POCKET_KEY_ITEMS', 3: 'POCKET_POKE_BALLS', 4: 'POCKET_TM_CASE', 5: 'POCKET_BERRY_POUCH'}
EVO_C = rev('EVO_', 'pokemon.h', lambda n: n.startswith('EVO_MODE') or n.startswith('EVOS_'))
BODY_C = rev('BODY_COLOR_', 'pokemon.h')


def class_c(v): return CLASS_C.get(v, str(v))
def pic_c(v): return PIC_C.get(v, str(v))


def ai_c(v):
    if v == 0: return '0'
    parts = []
    rest = v
    for bit, n in AI_BITS:
        if v & bit and (bit & (bit - 1)) == 0:
            parts.append(n); rest &= ~bit
    if rest: parts.append('0x%X' % rest)
    return ' | '.join(parts)


def music_c(v):
    m = MUSIC_C.get(v & 0x7F, str(v & 0x7F))
    return ('F_TRAINER_FEMALE | ' + m) if v & 0x80 else m


def camel(const):
    s = const[len('TRAINER_'):] if const.startswith('TRAINER_') else const
    return ''.join(w[:1] + w[1:].lower() for w in s.split('_'))


# ================================================================== TRAINERS
TR, NT = sym('gTrainers')[0], 743
MONSZ = {0: 8, 1: 16, 2: 8, 3: 16}
MON_TYPE = {0: 'TrainerMonNoItemDefaultMoves', 1: 'TrainerMonNoItemCustomMoves',
            2: 'TrainerMonItemDefaultMoves', 3: 'TrainerMonItemCustomMoves'}
PARTY_MACRO = {0: 'NO_ITEM_DEFAULT_MOVES', 1: 'NO_ITEM_CUSTOM_MOVES', 2: 'ITEM_DEFAULT_MOVES', 3: 'ITEM_CUSTOM_MOVES'}


def read_trainer(R, i):
    o = TR + 40 * i
    t = dict(id=i, flags=R.u8(o), cls=R.u8(o + 1), music=R.u8(o + 2), pic=R.u8(o + 3), name_raw=bytes(R.d[o + 4:o + 16]),
             items=[R.u16(o + 16 + 2 * k) for k in range(4)], double=R.u8(o + 24), ai=R.u32(o + 28), size=R.u8(o + 32),
             party=R.u32(o + 36))
    mons = []
    if t['party']:
        po = t['party'] - 0x08000000
        for k in range(t['size']):
            m = po + MONSZ[t['flags'] & 3] * k
            d = dict(iv=R.u16(m), lvl=R.u8(m + 2), species=R.u16(m + 4))
            p = m + 6
            if t['flags'] & 2: d['item'] = R.u16(p); p += 2
            if t['flags'] & 1: d['moves'] = [R.u16(p + 2 * j) for j in range(4)]
            mons.append(d)
    t['mons'] = mons
    return t


def class_name(R, c):
    a = sym('gTrainerClassNames')[0]
    return decode_text(R, a + 13 * c, 13)[0]


def vanilla_trainer_refs(names):
    """Vanilla trainer constant names referenced anywhere in the tree except the files this script regenerates."""
    skip = {'include/constants/opponents.h', 'src/data/trainers.h', 'src/data/trainer_parties.h'}
    found = set()
    for root in ('src', 'include', 'data', 'asm'):
        for dp, dn, fn in os.walk(os.path.join(VAN, root)):
            for f in fn:
                if not f.endswith(('.c', '.h', '.inc', '.s', '.json', '.txt')): continue
                rel = os.path.relpath(os.path.join(dp, f), VAN)
                if rel in skip: continue
                txt = open(os.path.join(dp, f), encoding='utf-8', errors='replace').read()
                if 'TRAINER_' not in txt: continue
                found.update(n for n in re.findall(r'\bTRAINER_[A-Z0-9_]+\b', txt) if n in names)
    return found


def gen_trainers():
    hts = [read_trainer(H, i) for i in range(NT)]
    consts = {i: trainer_const(i) for i in range(NT)}
    assert len(set(consts.values())) == NT
    party_sym = {}
    for i in range(1, NT):
        party_sym[i] = 'sParty_' + camel(consts[i])
    assert len(set(party_sym.values())) == NT - 1, 'party symbol collision'
    json.dump({str(i): consts[i] for i in range(NT)}, open(os.path.join(OUT, 'trainer_ids.json'), 'w'), indent=1)

    # vanilla trainer names
    van = collections.OrderedDict()
    for l in vread('include/constants/opponents.h').splitlines():
        m = re.match(r'#define\s+(TRAINER_\w+)\s+(\d+)', l)
        if m: van[m.group(1)] = int(m.group(2))
    van_by_id = {v: k for k, v in van.items()}
    new_ids = {c: i for i, c in consts.items()}

    # ---- opponents.h
    L = ['#ifndef GUARD_CONSTANTS_OPPONENTS_H', '#define GUARD_CONSTANTS_OPPONENTS_H', '',
         '// ShinyGold: trainer IDs keep their vanilla numbers (trainer flags/rematch tables index by them), but every',
         '// slot was rewritten by the hack. Constants are named after the hack\'s trainer class + name',
         '// (see /home/claude/sgx/names.py trainer_const). Vanilla names are kept below as compatibility aliases.', '']
    for i in range(NT):
        L.append('#define %-42s %3d' % (consts[i], i))
    L += ['', '// NOTE: Because each Trainer uses a flag to determine when they are defeated, there is ',
          '//       only space for 25 additional trainers before trainer flag space overflows.',
          '//       MAX_TRAINERS_COUNT can be increased but will take up additional saveblock space', '',
          '#define NUM_TRAINERS                             743',
          '#define MAX_TRAINERS_COUNT                       768', '']
    # aliases
    conflicts = {n: (van[n], new_ids[n]) for n in van if n in new_ids and new_ids[n] != van[n]}
    L.append('// Vanilla FireRed trainer names (same IDs) so unported vanilla code/scripts keep compiling.')
    L.append('// Names that ShinyGold reuses for a different trainer ID cannot be aliased; see the list below.')
    refd = vanilla_trainer_refs(set(van))
    for n, v in van.items():
        if n in new_ids or n not in refd: continue
        L.append('#define %-42s %s' % (n, consts[v]))
    L.append('')
    L.append('// Vanilla names now naming a different trainer ID (vanilla id -> new owner id):')
    for n, (vi, ni) in conflicts.items():
        L.append('//   %-40s vanilla %3d (now %s), reused for %3d' % (n, vi, consts[vi], ni))
    L += ['', '#endif  // GUARD_CONSTANTS_OPPONENTS_H', '']
    wwrite('include/constants/opponents.h', '\n'.join(L))
    json.dump({n: dict(vanilla_id=vi, vanilla_id_new_name=consts[vi], reused_by_id=ni) for n, (vi, ni) in conflicts.items()},
              open(os.path.join(OUT, 'trainer_name_conflicts.json'), 'w'), indent=1)

    # ---- trainer_parties.h
    P = ['// ShinyGold: trainer parties regenerated from the hack ROM (one array per trainer, named after the trainer).',
         '// IVs use the raw 0-255 scale (fixedIV = iv * 31 / 255, stored in a u8): ShinyGold uses 65535 (-> 31) for',
         '// "perfect IV" trainers and 255/250 for near-perfect ones.', '']
    for i in range(1, NT):
        t = hts[i]
        f = t['flags'] & 3
        P.append('static const struct %s %s[] = {' % (MON_TYPE[f], party_sym[i]))
        for m in t['mons']:
            P.append('    {')
            P.append('        .iv = %d,' % m['iv'])
            P.append('        .lvl = %d,' % m['lvl'])
            P.append('        .species = %s,' % species_c(m['species']))
            if f & 2: P.append('        .heldItem = %s,' % item_c(m['item']))
            if f & 1: P.append('        .moves = {%s},' % ', '.join(move_c(x) for x in m['moves']))
            P.append('    },')
        P.append('};')
        P.append('')
    wwrite('src/data/trainer_parties.h', '\n'.join(P))

    # ---- trainers.h
    vt = [read_trainer(V, i) for i in range(NT)]
    T = ['// ShinyGold: regenerated from the hack ROM. Notes on hack data ported as-is:',
         '//  * encounterMusic_gender: the hack\'s trainer editor stored the trainer pic index here for most trainers',
         '//    (bit 7 is still the female flag). Values that are not a TRAINER_ENCOUNTER_MUSIC_* id fall through to',
         '//    the default case of PlayTrainerEncounterMusic().',
         '//  * trainerClass comments give the class name ShinyGold displays (gTrainerClassNames was edited).',
         'const struct Trainer gTrainers[] = {',
         '    [TRAINER_NONE] = {',
         '        .trainerName = _(""),',
         '    },', '']
    assert hts[0]['party'] == 0 and hts[0]['size'] == 0
    for i in range(1, NT):
        t = hts[i]
        f = t['flags'] & 3
        hcls = class_name(H, t['cls'])
        vcls = class_name(V, t['cls'])
        T.append('    [%s] = {' % consts[i])
        cls_line = '        .trainerClass = %s,' % class_c(t['cls'])
        if hcls != vcls:
            cls_line += ' // "%s"' % hcls
        T.append(cls_line)
        T.append('        .encounterMusic_gender = %s,' % music_c(t['music']))
        T.append('        .trainerPic = %s,' % pic_c(t['pic']))
        T.append('        .trainerName = _("%s"),' % fixed_text_body(t['name_raw']))
        its = list(t['items'])
        while its and its[-1] == 0: its.pop()
        T.append('        .items = {%s},' % ', '.join(item_c(x) for x in its))
        T.append('        .doubleBattle = %s,' % {0: 'FALSE', 1: 'TRUE'}.get(t['double'], str(t['double'])))
        T.append('        .aiFlags = %s,' % ai_c(t['ai']))
        if t['size'] == 0:
            T.append('        .party = {NULL}, .partySize = 0, .partyFlags = %d,' % t['flags'])
        else:
            T.append('        .party = %s(%s),' % (PARTY_MACRO[f], party_sym[i]))
        T.append('    },')
        T.append('')
    T.append('};')
    T.append('')
    wwrite('src/data/trainers.h', '\n'.join(T))
    return hts, consts, conflicts


# ------------------------------------------------------------------ trainer name issues
def find_trainerbattles():
    """Scan the hack ROM for trainerbattle (0x5C) script commands. Returns {trainer_id: [offsets]}."""
    d = H.d
    hits = collections.defaultdict(list)
    # arg layout per battle type (pokefirered battle_setup.c): ptr count after the 2-byte local id
    nptr = {0: 2, 1: 3, 2: 3, 3: 1, 4: 3, 5: 2, 6: 4, 7: 3, 8: 4, 9: 2}
    i = 0
    n = len(d)
    while True:
        i = d.find(b'\x5c', i)
        if i < 0 or i + 6 > n: break
        typ = d[i + 1]
        if typ in nptr:
            tid = d[i + 2] | d[i + 3] << 8
            if 0 < tid < NT:
                ok = True
                p = i + 6
                for k in range(nptr[typ]):
                    v = struct.unpack_from('<I', d, p + 4 * k)[0]
                    # type 9 (TRAINER_BATTLE_EARLY_RIVAL) second arg is a flag word; allow 0 for victory text
                    if not (0x08000000 <= v < 0x09000000 or (v == 0 and k > 0)):
                        ok = False; break
                if ok:
                    hits[tid].append((i, typ))
        i += 1
    return hits


def script_owners():
    """Map script entry offsets -> owning map name (object/coord/bg events + map script headers)."""
    from maps import load_map_headers, parse_events, parse_map_scripts
    from names import map_name
    R = Rom()
    groups, maps = load_map_headers(R)
    owner = {}
    for m in maps:
        mn = map_name(m.group, m.num) or '%d.%d' % (m.group, m.num)
        try:
            ev = parse_events(R, m.events)
        except Exception:
            continue
        for k, o in enumerate(ev['objects']):
            if 0x08000000 <= o['script'] < 0x09000000:
                owner.setdefault(o['script'] - 0x08000000, []).append('%s object %d (local id %d)' % (mn, k + 1, o['local_id']))
        for k, c in enumerate(ev['coords']):
            if 0x08000000 <= c['script'] < 0x09000000:
                owner.setdefault(c['script'] - 0x08000000, []).append('%s coord event %d' % (mn, k))
        for k, b in enumerate(ev['bgs']):
            if b['kind'] < 5 and 0x08000000 <= b['arg'] < 0x09000000:
                owner.setdefault(b['arg'] - 0x08000000, []).append('%s bg event %d' % (mn, k))
        try:
            ms = parse_map_scripts(R, m.scripts) or []
        except Exception:
            ms = []
        for e in ms:
            if 'table' in e:
                for x in e['table']:
                    if 0x08000000 <= x['script'] < 0x09000000:
                        owner.setdefault(x['script'] - 0x08000000, []).append('%s map script type %d' % (mn, e['type']))
            elif 0x08000000 <= e['ptr'] < 0x09000000:
                owner.setdefault(e['ptr'] - 0x08000000, []).append('%s map script type %d' % (mn, e['type']))
    return owner


def gen_name_issues(hts, consts):
    hits = find_trainerbattles()
    owner = script_owners()
    starts = sorted(owner)
    import bisect

    def where(off):
        if off in owner:
            return owner[off]
        k = bisect.bisect_right(starts, off) - 1
        out = []
        if k >= 0 and off - starts[k] < 0x300:
            out = ['near %s (+0x%X)' % (s, off - starts[k]) for s in owner[starts[k]]]
        vn = None
        if off < 0x71A000:
            _, rng = vanilla_symbols()
            # nearest vanilla symbol at or before off
            lo = bisect.bisect_right([r[0] for r in rng], off) - 1
            if lo >= 0: vn = rng[lo][2]
        if vn: out.append('vanilla area, after symbol %s' % vn)
        if not out: out.append('not attributed to a map event entry (reached via call/goto from another script, or unused)')
        return out

    issues = []
    for t in hts[1:]:
        raw = t['name_raw']
        name = decode_text(H, TR + 40 * t['id'] + 4, 12)[0]
        st = name.strip() if name is not None else None
        cats = []
        if name is None: cats.append('unterminated')
        elif name == '': cats.append('empty')
        elif st == '': cats.append('only_spaces')
        else:
            if 'EDIT' in st: cats.append('placeholder_edit')
            if '???' in st: cats.append('placeholder_question_marks')
            if re.match(r'^\d+TRAINER/\d+$', st): cats.append('placeholder_ntrainer')
            if st.endswith('!'): cats.append('trailing_exclamation')
            if name != name.rstrip(): cats.append('trailing_spaces')
            if name != name.lstrip(): cats.append('leading_spaces')
            if not cats and not re.match(r"^[A-Z][A-Z.&'’ é♂♀-]*$", st): cats.append('odd_characters')
        if not cats: continue
        uses = []
        for off, typ in hits.get(t['id'], []):
            uses.append(dict(offset='0x%X' % (off + 0x08000000), battle_type=typ, location=where(off)))
        issues.append(dict(id=t['id'], const=consts[t['id']], cls=t['cls'], cls_const=class_c(t['cls']),
                           class_name=class_name(H, t['cls']), name=name, name_bytes=raw.hex(), categories=cats,
                           party=[dict(species=species_c(m['species']), lvl=m['lvl']) for m in t['mons']],
                           trainerbattle_refs=uses))
    json.dump(issues, open(os.path.join(OUT, 'trainer_name_issues.json'), 'w'), indent=1, ensure_ascii=False)
    c = collections.Counter(x for i in issues for x in i['categories'])
    print('trainer name issues:', len(issues), dict(c))
    unused = [i['id'] for i in issues if not i['trainerbattle_refs']]
    print('  of which with no trainerbattle reference found:', len(unused))
    # all trainers: script refs summary (useful to coordinator)
    allrefs = {consts[i]: ['0x%X' % (o + 0x08000000) for o, _ in hits.get(i, [])] for i in range(1, NT)}
    json.dump(allrefs, open(os.path.join(OUT, 'trainer_script_refs.json'), 'w'), indent=1)
    return issues


# ------------------------------------------------------------------ compat edits for reused vanilla names
def fix_conflicting_refs(consts, conflicts):
    """C code / shared scripts that reference a vanilla trainer name which ShinyGold reuses for another ID:
    rewrite them to the new name of the *same numeric ID* so behaviour stays identical (the hack did not touch
    these tables, they still index by vanilla ID)."""
    files = ['src/vs_seeker.c', 'src/fame_checker.c', 'data/scripts/set_gym_trainers.inc', 'data/scripts/trainers.inc',
             'src/battle_setup.c', 'data/scripts/hall_of_fame.inc']
    for f in files:
        s = vread(f)
        n = 0

        def rep(m):
            nonlocal n
            name = m.group(0)
            if name in conflicts:
                n += 1
                return consts[conflicts[name][0]]
            return name
        s2 = re.sub(r'\bTRAINER_[A-Z0-9_]+\b', rep, s)
        if n:
            print('  %s: %d conflicting refs renamed' % (f, n))
        wwrite(f, s2)


# ================================================================== TRAINER CLASS NAMES / MONEY
def gen_class_names():
    a = sym('gTrainerClassNames')[0]
    s = vread('src/data/text/trainer_class_names.h')
    out = []
    for line in s.splitlines():
        m = re.match(r'(\s*\[(TRAINER_CLASS_\w+)\]\s*= )_\("(.*)"\),$', line)
        if m:
            c = VALS[m.group(2)]
            hb = text_body(H.d, a + 13 * c, 13)
            vb = text_body(V.d, a + 13 * c, 13)
            if hb != vb:
                line = '%s_("%s"), // ShinyGold: was "%s"' % (m.group(1), hb, vb)
        out.append(line)
    wwrite('src/data/text/trainer_class_names.h', '\n'.join(out) + '\n')


def gen_money():
    a, size = sym('gTrainerMoneyTable')
    s = vread('src/battle_main.c')
    start = s.index('const struct TrainerMoney gTrainerMoneyTable[] =')
    end = s.index('};', start) + 2
    L = ['const struct TrainerMoney gTrainerMoneyTable[] =', '{']
    for i in range(size // 4):
        c, v = H.u8(a + 4 * i), H.u8(a + 4 * i + 1)
        vc, vv = V.u8(a + 4 * i), V.u8(a + 4 * i + 1)
        cc = '0xFF' if c == 0xFF else class_c(c)
        line = '    {%s, %d},' % (cc if c != 0xFF else ' 0xFF', v)
        if (c, v) != (vc, vv):
            line += ' // ShinyGold: was %d' % vv if c == vc else ' // ShinyGold: was {%s, %d}' % (class_c(vc), vv)
        L.append(line)
        if c == 0xFF: break
    L.append('};')
    wwrite('src/battle_main.c', s[:start] + '\n'.join(L) + s[end:])


# ================================================================== POKEMON DATA
SI_FIELDS = ['baseHP', 'baseAttack', 'baseDefense', 'baseSpeed', 'baseSpAttack', 'baseSpDefense', 'type1', 'type2',
             'catchRate', 'expYield', 'evs', 'itemCommon', 'itemRare', 'genderRatio', 'eggCycles', 'friendship',
             'growthRate', 'eggGroup1', 'eggGroup2', 'ability1', 'ability2', 'safariZoneFleeRate', 'colorbyte']


def si(R, i):
    a = sym('gSpeciesInfo')[0] + 28 * i
    return dict(zip(SI_FIELDS, struct.unpack_from('<6B2BBBH2HBBBBBBBBBB', R.d, a)))


def gen_species_info():
    s = vread('src/data/pokemon/species_info.h')
    lines = s.split('\n')
    # locate blocks
    idx = {}
    cur = None
    for k, l in enumerate(lines):
        m = re.match(r'\s*\[(SPECIES_\w+)\]\s*=\s*$', l)
        if m: cur = m.group(1); idx[cur] = k
    for i in range(412):
        h, v = si(H, i), si(V, i)
        if h == v: continue
        sc = species_c(i)
        k = idx[sc]
        changes = []
        j = k
        while not lines[j].strip().startswith('},'):
            l = lines[j]
            for fld, hv, vv, fmt in [
                    ('itemCommon', h['itemCommon'], v['itemCommon'], item_c),
                    ('itemRare', h['itemRare'], v['itemRare'], item_c),
                    ('friendship', h['friendship'], v['friendship'], str),
                    ('bodyColor', h['colorbyte'] & 0x7F, v['colorbyte'] & 0x7F, lambda x: BODY_C.get(x, str(x))),
                    ('noFlip', h['colorbyte'] >> 7, v['colorbyte'] >> 7, lambda x: 'TRUE' if x else 'FALSE')]:
                if hv != vv and re.match(r'\s*\.%s = ' % fld, l):
                    lines[j] = re.sub(r'(\.%s = )[^,]+,.*' % fld, r'\g<1>%s, // ShinyGold: was %s' % (fmt(hv), fmt(vv)), l)
                    changes.append(fld)
            j += 1
        other = [f for f in SI_FIELDS if h[f] != v[f] and f not in ('itemCommon', 'itemRare', 'friendship', 'colorbyte')]
        assert not other, (sc, other)
        print('  species_info %s: %s' % (sc, changes))
    wwrite('src/data/pokemon/species_info.h', '\n'.join(lines))


def evo_list(R, i):
    a = sym('gEvolutionTable')[0] + 40 * i
    return [struct.unpack_from('<HHH', R.d, a + 8 * j) for j in range(5)]


ITEM_PARAM_EVOS = {6, 7}


def evo_str(e):
    meth, param, tgt = e
    mc = EVO_C.get(meth, str(meth))
    pc = item_c(param) if meth in ITEM_PARAM_EVOS else str(param)
    return '{%s, %s, %s}' % (mc, pc, species_c(tgt))


def gen_evolution():
    s = vread('src/data/pokemon/evolution.h')
    lines = s.split('\n')
    out = []
    k = 0
    changed = {species_c(i): i for i in range(412) if evo_list(H, i) != evo_list(V, i)}
    done = set()
    while k < len(lines):
        l = lines[k]
        m = re.match(r'(\s*)\[(SPECIES_\w+)\](\s*)= \{', l)
        if m and m.group(2) in changed:
            # skip the full entry (ends with '}},')
            while not lines[k].rstrip().endswith('}},'):
                k += 1
            i = changed[m.group(2)]
            evs = [e for e in evo_list(H, i) if e[0]]
            vevs = [e for e in evo_list(V, i) if e[0]]
            assert evo_list(H, i)[len(evs):] == [(0, 0, 0)] * (5 - len(evs))
            prefix = '%s[%s]%s= {' % (m.group(1), m.group(2), m.group(3))
            pad = ' ' * len(prefix)
            out.append('%s// ShinyGold: was %s' % (m.group(1), ', '.join(evo_str(e) for e in vevs)))
            for j, e in enumerate(evs):
                out.append((prefix if j == 0 else pad) + evo_str(e) + ('},' if j == len(evs) - 1 else ','))
            done.add(m.group(2))
            k += 1
            continue
        out.append(l)
        k += 1
    missing = set(changed) - done
    assert not missing, missing  # species that had no vanilla entry would need inserting
    wwrite('src/data/pokemon/evolution.h', '\n'.join(out))


def gen_tmhm():
    a = sym('sTMHMLearnsets')[0]
    tm = sym('sTMHMMoves')[0]
    # names: TM01_<MOVE> using the hack's TM moves
    tmnames = []
    for k in range(58):
        mv = move_c(H.u16(tm + 2 * k))[len('MOVE_'):]
        tmnames.append(('TM%02d_' % (k + 1) if k < 50 else 'HM%02d_' % (k - 49)) + mv)
    L = ['#define TMHM_LEARNSET(moves) {(u32)(moves), ((u64)(moves) >> 32)}',
         '#define TMHM(tmhm) ((u64)1 << (ITEM_##tmhm - ITEM_TM01))', '',
         '// This table determines which TMs and HMs a species is capable of learning.',
         '// Each entry is a 64-bit bit array spread across two 32-bit values, with',
         '// each bit corresponding to a machine.',
         '// ShinyGold: regenerated from the hack (20 TMs teach different moves, compatibility rewritten for most species).',
         'static const u32 sTMHMLearnsets[][2] =', '{']
    w = max(len(species_c(i)) for i in range(412)) + 2
    for i in range(412):
        bits = H.u32(a + 8 * i) | (H.u32(a + 8 * i + 4) << 32)
        sc = species_c(i)
        head = '    %-*s = TMHM_LEARNSET(' % (w, '[%s]' % sc)
        set_ = [tmnames[b] for b in range(58) if bits >> b & 1]
        if not set_:
            L.append(head + '0),')
        else:
            pad = ' ' * (len(head) - 2)
            for j, n in enumerate(set_):
                L.append((head if j == 0 else pad + '| ') + 'TMHM(%s)' % n + ('),' if j == len(set_) - 1 else ''))
        L.append('')
    L.append('};')
    wwrite('src/data/pokemon/tmhm_learnsets.h', '\n'.join(L) + '\n')
    return tmnames


def gen_tm_moves_and_aliases(tmnames):
    tm = sym('sTMHMMoves')[0]
    s = vread('src/data/party_menu.h')
    start = s.index('static const u16 sTMHMMoves[] =')
    end = s.index('};', start) + 2
    L = ['static const u16 sTMHMMoves[] =', '{']
    for k in range(58):
        h, v = H.u16(tm + 2 * k), V.u16(tm + 2 * k)
        line = '    %s,' % move_c(h)
        if h != v: line += ' // ShinyGold: was %s' % move_c(v)
        L.append(line)
    L.append('};')
    wwrite('src/data/party_menu.h', s[:start] + '\n'.join(L) + s[end:])
    # item constant aliases ITEM_TMxx_<MOVE>
    s = vread('include/constants/items.h')
    lines = s.split('\n')
    out = []
    first = True
    for l in lines:
        m = re.match(r'#define (ITEM_(TM|HM)\d\d)_\w+ (ITEM_(TM|HM)\d\d)$', l)
        if m:
            if first:
                out.append('// ShinyGold: TM/HM aliases are named after the moves the hack\'s machines teach (sTMHMMoves).')
                for k, n in enumerate(tmnames):
                    out.append('#define ITEM_%s ITEM_%s' % (n, n[:4]))
                out.append('')
                out.append('// ShinyGold: TM01 teaches DYNAMICPUNCH in the hack; vanilla alias kept for party_menu.c.')
                out.append('#define ITEM_TM01_FOCUS_PUNCH ITEM_TM01')
                first = False
            continue
        out.append(l)
    wwrite('include/constants/items.h', '\n'.join(out))


def gen_trades():
    a = sym('sInGameTrades')[0]
    s = vread('src/data/ingame_trades.h')
    names = ['INGAME_TRADE_MR_MIME', 'INGAME_TRADE_JYNX', 'INGAME_TRADE_NIDORAN', 'INGAME_TRADE_FARFETCHD',
             'INGAME_TRADE_NIDORINOA', 'INGAME_TRADE_LICKITUNG', 'INGAME_TRADE_ELECTRODE', 'INGAME_TRADE_TANGELA',
             'INGAME_TRADE_SEEL']
    for i, nm in enumerate(names):
        o = a + 60 * i
        if H.d[o:o + 60] == V.d[o:o + 60]: continue
        R = H
        g = 'MALE' if R.u8(o + 54) == 0 else ('FEMALE' if R.u8(o + 54) == 1 else str(R.u8(o + 54)))
        body = ['    [%s] = ' % nm, '    {',
                '        // ShinyGold: trade rewritten by the hack',
                '        .nickname = _("%s"),' % text_body(R.d, o, 11),
                '        .species = %s,' % species_c(R.u16(o + 12)),
                '        .ivs = {%s},' % ', '.join(str(x) for x in R.d[o + 14:o + 20]),
                '        .abilityNum = %d,' % R.u8(o + 20),
                '        .otId = %d,' % R.u32(o + 24),
                '        .conditions = {%s},' % ', '.join(str(x) for x in R.d[o + 28:o + 33]),
                '        .personality = 0x%08x,' % R.u32(o + 36),
                '        .heldItem = %s,' % item_c(R.u16(o + 40)),
                '        .mailNum = %d,' % R.u8(o + 42),
                '        .otName = _("%s"),' % text_body(R.d, o + 43, 11),
                '        .otGender = %s,' % g,
                '        .sheen = %d,' % R.u8(o + 55),
                '        .requestedSpecies = %s' % species_c(R.u16(o + 56)),
                '    }, ']
        # replace existing entry: from '[NAME] =' to the closing '    }, ' at the same indent
        st = s.index('    [%s] = ' % nm)
        en = s.index('\n    }, ', st) + len('\n    }, ')
        s = s[:st] + '\n'.join(body) + s[en:]
    wwrite('src/data/ingame_trades.h', s)


# ================================================================== ITEMS
def item_fields(R, i):
    a = sym('gItems')[0] + 44 * i
    return dict(name=bytes(R.d[a:a + 14]), id=R.u16(a + 14), price=R.u16(a + 16), he=R.u8(a + 18), hep=R.u8(a + 19),
                desc=R.u32(a + 20), imp=R.u8(a + 24), reg=R.u8(a + 25), pocket=R.u8(a + 26), type=R.u8(a + 27),
                fuf=R.u32(a + 28), bu=R.u8(a + 32), buf=R.u32(a + 36), sec=R.u32(a + 40))


def func_name(addr):
    if addr == 0: return 'NULL'
    n = vanilla_name_at((addr & ~1) - 0x08000000)
    assert n, hex(addr)
    return n


ITEM_TYPE_NAMES = {}


def gen_items():
    j = json.load(open(os.path.join(VAN, 'src/data/items.json'), encoding='utf-8'))
    items = j['items']
    changed = []
    for i, it in enumerate(items):
        h, v = item_fields(H, i), item_fields(V, i)
        if h == v and text_body(H.d, h['desc'] - 0x08000000) == text_body(V.d, v['desc'] - 0x08000000):
            continue
        ch = []
        hn = text_body(h['name'], 0)
        if h['name'][:h['name'].index(0xFF) + 1] != v['name'][:v['name'].index(0xFF) + 1]:
            it['english'] = hn; ch.append('name')
        if h['price'] != v['price']: it['price'] = h['price']; ch.append('price')
        if h['he'] != v['he']: it['holdEffect'] = HOLD_C.get(h['he'], h['he']); ch.append('holdEffect')
        if h['hep'] != v['hep']: it['holdEffectParam'] = h['hep']; ch.append('holdEffectParam')
        if h['imp'] != v['imp']: it['importance'] = h['imp']; ch.append('importance')
        if h['reg'] != v['reg']: it['registrability'] = h['reg']; ch.append('registrability')
        if h['pocket'] != v['pocket']: it['pocket'] = POCKET_C[h['pocket']]; ch.append('pocket')
        if h['type'] != v['type']:
            # json uses enum names for ITEM_TYPE_* (values start at 1 for ITEM_TYPE_FIELD? check include/item.h)
            it['type'] = ITEM_TYPE(h['type']); ch.append('type')
        if h['fuf'] != v['fuf']: it['fieldUseFunc'] = func_name(h['fuf']); ch.append('fieldUseFunc')
        if h['bu'] != v['bu']: it['battleUsage'] = h['bu']; ch.append('battleUsage')
        if h['buf'] != v['buf']: it['battleUseFunc'] = func_name(h['buf']); ch.append('battleUseFunc')
        if h['sec'] != v['sec']: it['secondaryId'] = h['sec']; ch.append('secondaryId')
        assert h['id'] == v['id']
        do = h['desc'] - 0x08000000
        if it['pocket'] == 'POCKET_TM_CASE':
            dn = vanilla_name_at(do, prefer=lambda n: n.startswith('gMoveDescription_'))
            assert dn and dn.startswith('gMoveDescription_'), (i, hex(do))
            mid = dn[len('gMoveDescription_'):]
            if mid != it['moveId']: it['moveId'] = mid; ch.append('moveId')
        else:
            hd = text_body(H.d, do)
            if hd != text_body(V.d, v['desc'] - 0x08000000):
                it['description_english'] = hd; ch.append('description')
        changed.append((i, it['itemId'], ch))
    # textual edit of the vanilla JSON (keeps the file's mixed escaping style; only changed fields differ)
    lines = vread('src/data/items.json').split('\n')
    vj = json.load(open(os.path.join(VAN, 'src/data/items.json'), encoding='utf-8'))['items']
    k = 0
    for i, it in enumerate(items):
        while '"itemId": "%s"' % it['itemId'] not in lines[k]:
            k += 1
        st = k
        while not lines[st].strip().startswith('{'): st -= 1
        en = k
        while not lines[en].strip().startswith('}'): en += 1
        for key, val in it.items():
            if vj[i].get(key) == val: continue
            for q in range(st, en):
                m = re.match(r'(\s*)"%s": (.*?)(,?)$' % key, lines[q])
                if m:
                    lines[q] = '%s"%s": %s%s' % (m.group(1), key, json.dumps(val, ensure_ascii=(key == 'english')), m.group(3))
                    break
            else:
                raise KeyError((it['itemId'], key))
        k = en
    s = '\n'.join(lines)
    assert json.loads(s)['items'] == items
    wwrite('src/data/items.json', s)
    for c in changed: print('  item', c)
    return changed


def ITEM_TYPE(v):
    src = open(os.path.join(VAN, 'include/item.h')).read()
    m = re.search(r'enum\s*\{([^}]*ITEM_TYPE_BAG_MENU[^}]*)\}', src)
    body = m.group(1)
    names = []
    for x in body.split('\n'):
        x = x.split('//')[0].strip().rstrip(',')
        if not x: continue
        if '=' in x:
            n, val = [y.strip() for y in x.split('=')]
            names.append((n, int(val, 0)))
        else:
            names.append((x, names[-1][1] + 1 if names else 0))
    for n, val in names:
        if val == v: return n
    return v


def gen_item_icons():
    a = sym('sItemIconTable')[0]
    s = vread('src/data/item_icon_table.h')
    lines = s.split('\n')
    # entries are in item order; find by index via [ITEM_X] designators
    for i in range(377):
        for k in (0, 4):
            h, v = H.u32(a + 8 * i + k), V.u32(a + 8 * i + k)
            if h == v: continue
            hn = vanilla_name_at(h - 0x08000000)
            vn = vanilla_name_at(v - 0x08000000)
            assert hn and vn
            ic = item_c(i)
            for j, l in enumerate(lines):
                if re.match(r'\s*\[%s\]\s*=' % re.escape(ic), l):
                    assert vn in l
                    lines[j] = l.replace(vn, hn) + ' // ShinyGold: was %s' % vn
                    print('  item icon', ic, vn, '->', hn)
    wwrite('src/data/item_icon_table.h', '\n'.join(lines))


if __name__ == '__main__':
    hts, consts, conflicts = gen_trainers()
    fix_conflicting_refs(consts, conflicts)
    gen_class_names()
    gen_money()
    gen_species_info()
    gen_evolution()
    tmnames = gen_tmhm()
    gen_tm_moves_and_aliases(tmnames)
    gen_trades()
    gen_items()
    gen_item_icons()
    gen_name_issues(hts, consts)
