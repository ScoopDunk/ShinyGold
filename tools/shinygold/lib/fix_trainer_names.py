"""Fix ShinyGold's broken trainer names in the decomp tree.

Rules (documented in docs/SHINYGOLD.md):
  * "NNTRAINER/K" placeholders are the hack's Gold/Silver phone-rematch trainers (contact NN, rematch tier K):
    every tier gets the Gold/Silver name of that phone contact (matched against pret/pokegold parties).
  * "-EDIT-", "-EDITG-" and empty names: Gold/Silver name when the party matches a G/S trainer exactly,
    the rival's name for rival-class trainers, otherwise the vanilla FireRed name of that slot
    (those battles still run the vanilla FireRed trainer script/text).
  * Stray trailing "!" and trailing spaces are removed.
  * "???" names are kept (mystery trainers / the unnamed first rival battles, as in Gold/Silver).
  * The two blank trainer class names get names.
Trainer constants and party symbols are renamed to match the fixed names.
"""
import sys, re, json, os, collections
sys.path.insert(0, '/home/claude/sgx')
from core import *
import names as N
from gs_trainers import parse_parties, best_matches, score

TRAINERS_OFF, CLASS_OFF = 0x23EAC8, 0x23E558
EXACT_OVERRIDES = {
    # id: (name, reason)
    329: ('SILVER', 'rival class (name is replaced by the rival name in battle)'),
    427: ('SILVER', 'rival class'), 428: ('SILVER', 'rival class'), 429: ('SILVER', 'rival class'),
    430: ('SILVER', 'rival class'), 431: ('SILVER', 'rival class'),
    475: ('JESS&JAMIE', 'Team Rocket duo party; same name as the hack\'s other ROCKET DUO trainer'),
    603: ('PARRY', 'G/S Hiker Parry (Route 45 phone contact) party'),
    606: ('KENJI', 'G/S Black Belt Kenji rematch party'),
}
CLASS_FIX = {'TRAINER_CLASS_AQUA_LEADER': 'TEAM ROCKET', 'TRAINER_CLASS_SCHOOL_KID': 'SCHOOL KID'}


def ident(s):
    s = s.replace('♂', '_M').replace('♀', '_F').replace('é', 'E').replace('&', '_AND_').replace('{PKMN}', 'PKMN')
    return '_'.join(re.findall(r'[A-Za-z0-9]+', s)).upper()


def compute():
    r = Rom(); v = Rom(VANILLA_ROM)
    P = parse_parties()
    cls = lambda R, c: decode_text(R, CLASS_OFF + 13 * c)[0]
    hack = {}
    for i in range(1, 743):
        o = TRAINERS_OFF + 40 * i
        c = r.u8(o + 1)
        n = r.u8(o + 0x20); pf = r.u8(o); mp = r.ptr(o + 0x24)
        sz = 8 if pf in (0, 2) else 16
        party = [(N.species(r.u16(mp + sz * k + 4)), r.u16(mp + sz * k + 2)) for k in range(n)] if mp else []
        hack[i] = dict(cls=c, cname=cls(r, c), name=decode_text(r, o + 4, 12)[0], party=party,
                       vname=decode_text(v, o + 4, 12)[0])
    fixes = {}
    # phone rematch groups
    phone = collections.defaultdict(list)
    for i, t in hack.items():
        m = re.match(r'^\s*(\d+)TRAINER/(\d+)$', t['name'])
        if m: phone[int(m.group(1))].append((int(m.group(2)), i))
    for nn, tiers in phone.items():
        tiers.sort()
        nm = None
        for k, i in tiers:
            bm = best_matches(hack[i]['cname'], hack[i]['party'], P, 1)
            if bm and bm[0][0] >= 0.99:
                nm = bm[0][1]['name']; break
        assert nm, nn
        for k, i in tiers:
            fixes[i] = (nm, 'G/S phone contact #%d, rematch tier %d' % (nn, k))
    for i, t in hack.items():
        if i in fixes: continue
        nm = t['name']
        if i in EXACT_OVERRIDES:
            fixes[i] = EXACT_OVERRIDES[i]; continue
        if nm.strip() in ('-EDIT-', '-EDITG-', ''):
            bm = sorted(((score(t['party'], p['mons']), p) for p in P), key=lambda x: -x[0])
            if bm and bm[0][0] >= 0.99 and bm[0][1]['name'] not in ('?',):
                fixes[i] = (bm[0][1]['name'], 'exact G/S party match (%s)' % bm[0][1]['group'])
            else:
                fixes[i] = (t['vname'].strip(), 'vanilla FireRed name of this trainer slot')
            continue
        clean = nm.rstrip(' ').rstrip('!').rstrip(' ')
        if clean != nm:
            fixes[i] = (clean, 'removed stray trailing characters')
    return hack, fixes


def new_consts(hack, fixes, old, reserved):
    """Keep every constant whose name does not change; give renamed trainers fresh names that avoid both
    the kept names and the vanilla compatibility aliases in opponents.h."""
    out = {0: 'TRAINER_NONE'}
    changed = []
    for i in range(1, 743):
        if i in fixes and ident(fixes[i][0]) != ident(hack[i]['name']) and fixes[i][0] not in ('???',):
            changed.append(i)
        else:
            out[i] = old[i]
    used = set(out.values()) | set(reserved)
    for i in changed:
        name = fixes[i][0]
        base = 'TRAINER_' + ident(hack[i]['cname'] or 'CLASS%d' % hack[i]['cls']) + '_' + ident(name)
        c = base; k = 2
        while c in used:
            c = '%s_%d' % (base, k); k += 1
        used.add(c); out[i] = c
    return out


def camel(const):
    return ''.join(w.capitalize() for w in const[len('TRAINER_'):].split('_'))


def apply(wt, dry=False):
    hack, fixes = compute()
    old = {i: N.trainer_const(i) for i in range(743)}
    opp = open(os.path.join(wt, 'include/constants/opponents.h')).read()
    reserved = set(re.findall(r'^#define\s+(TRAINER_\w+)\s+TRAINER_\w+\s*$', opp, re.M))
    new = new_consts(hack, fixes, old, reserved)
    ren = {old[i]: new[i] for i in range(743) if old[i] != new[i]}
    # 1. names in trainers.h
    p = os.path.join(wt, 'src/data/trainers.h')
    s = open(p, encoding='utf-8').read()
    for i, (nm, why) in fixes.items():
        pat = re.compile(r'(\[%s\] = \{.*?\.trainerName = _\(")([^"]*)("\),)' % re.escape(old[i]), re.S)
        m = pat.search(s)
        assert m, old[i]
        s = s[:m.start(2)] + nm + '"),  // ShinyGold fix: was "%s" (%s)' % (m.group(2), why) + s[m.end(3):]
    open(p, 'w', encoding='utf-8').write(s)
    # 2. class names
    p = os.path.join(wt, 'src/data/text/trainer_class_names.h')
    s = open(p, encoding='utf-8').read()
    for c, nm in CLASS_FIX.items():
        s = re.sub(r'(\[%s\]\s*= _\(")("\),)' % c, r'\g<1>%s\2 // ShinyGold fix: class name was blank' % nm, s)
    open(p, 'w', encoding='utf-8').write(s)
    # 3. rename constants and party symbols everywhere (word-boundary replace)
    sym = {}
    for o, n in ren.items():
        sym[o] = n
        sym['sParty_' + camel(o)] = 'sParty_' + camel(n)
    rx = re.compile(r'\b(' + '|'.join(re.escape(k) for k in sorted(sym, key=len, reverse=True)) + r')\b')
    changed = 0
    for root in ['src', 'include', 'data']:
        for dp, dn, fn in os.walk(os.path.join(wt, root)):
            for f in fn:
                if not f.endswith(('.c', '.h', '.inc', '.s', '.json', '.txt')): continue
                fp = os.path.join(dp, f)
                t = open(fp, encoding='utf-8', errors='surrogateescape').read()
                t2 = rx.sub(lambda m: sym[m.group(1)], t)
                if t2 != t:
                    open(fp, 'w', encoding='utf-8', errors='surrogateescape').write(t2); changed += 1
    json.dump(dict(fixes={str(i): dict(const=new[i], old_const=old[i], name=f[0], was=hack[i]['name'], why=f[1])
                          for i, f in sorted(fixes.items())}),
              open('/home/claude/work/trainer_name_fixes.json', 'w'), indent=1)
    print(len(fixes), 'names fixed;', len(ren), 'constants renamed;', changed, 'files touched')


if __name__ == '__main__':
    apply(sys.argv[1])
