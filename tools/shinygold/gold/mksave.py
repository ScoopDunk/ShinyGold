"""Make a test battery save for the gold tree (ShinyGold save layout).

usage: mksave.py <tree> <base.sav> <out.sav> [options]
  --map NAME X Y         continue at map NAME (map dir name or MAP_ constant) at tile X,Y
  --flag F [F ...]       set flags (FLAG_ names, numbers like 0x1007; 0x900-0x1FFF go to the save block extension)
  --clearflag F [...]    clear flags
  --var V=N [...]        set vars (VAR_ names or numbers; 0x4100-0x7FFF go to the extension)
  --mon SPECIES:LEVEL[:MOVE,MOVE,...] [...]   party (replaces the party); IVs 31, Hardy nature, full HP/PP
  --item ITEM[:QTY] [...]   add to the bag (pocket picked from the item's data)
  --money N
  --badges N             set FLAG_BADGE01_GET.. for the first N badges
  --dump                 print location, party, set flags in a range, ext vars (after edits)

The base save must already be a ShinyGold/gold save (e.g. /home/claude/emu/cmp/base.sav, made after the intro).
"""
import sys, os, re, json, struct, argparse

SIG = 0x08012025
# checksummed data size per sector id (ShinyGold uses 0xFF0 bytes of each save block sector)
SIZES = {0: 0xF24, 1: 0xFF0, 2: 0xFF0, 3: 0xFF0, 4: 0xD98}
for i in range(5, 13): SIZES[i] = 0xFF0
SIZES[13] = 0x450
SB1_SECTORS = (1, 2, 3, 4)
EXT_PARTS = ((0, 0xF24, 0x000, 0xCC), (4, 0xD98, 0xCC, 0x258), (13, 0x450, 0x324, 0xBA0))  # sector, offset, ext start, length


def checksum(b):
    s = 0
    for i in range(0, len(b), 4): s = (s + struct.unpack_from('<I', b, i)[0]) & 0xFFFFFFFF
    return ((s >> 16) + (s & 0xFFFF)) & 0xFFFF


class Consts:
    def __init__(self, tree):
        self.d = {}
        import glob
        first = ['include/constants/flags.h', 'include/constants/vars.h', 'include/constants/species.h', 'include/constants/moves.h',
                 'include/constants/items.h', 'include/constants/global.h']
        files = [os.path.join(tree, f) for f in first] + sorted(glob.glob(os.path.join(tree, 'include/constants/*.h')))
        for f in files:
            for line in open(f, encoding='utf-8', errors='replace'):
                m = re.match(r'#define\s+(\w+)\s+(.+?)\s*(//.*)?$', line)
                if m and '(' not in m.group(1): self.d.setdefault(m.group(1), m.group(2))

    def val(self, name, depth=0):
        if isinstance(name, int): return name
        name = name.strip()
        try: return int(name, 0)
        except ValueError: pass
        if name not in self.d: raise KeyError(name)
        expr = self.d[name]
        expr = re.sub(r'\b([A-Za-z_]\w*)\b', lambda m: str(self.val(m.group(1), depth + 1)), expr)
        expr = expr.replace('/', '//')
        return int(eval(expr, {}, {}))


class SaveFile:
    def __init__(self, path):
        self.d = bytearray(open(path, 'rb').read())
        self.slot = self._current_slot()
        self.off = {}
        for i in range(14):
            o = (self.slot * 14 + i) * 0x1000
            sid = struct.unpack_from('<H', self.d, o + 0xFF4)[0]
            self.off[sid] = o

    def _current_slot(self):
        best = None
        for slot in (0, 1):
            ctr = set(); ok = 0
            for i in range(14):
                o = (slot * 14 + i) * 0x1000
                sid, cs, sig, c = struct.unpack_from('<HHII', self.d, o + 0xFF4)
                if sig == SIG: ok += 1; ctr.add(c)
            if ok == 14 and (best is None or max(ctr) > best[1]): best = (slot, max(ctr))
        assert best, 'no complete save slot'
        return best[0]

    # SaveBlock1 / SaveBlock2 byte access
    def sb1(self, off):
        sec, o = divmod(off, 0xFF0)
        return self.off[SB1_SECTORS[sec]] + o

    def sb2(self, off):
        return self.off[0] + off

    def ext(self, b):
        for sid, so, es, ln in EXT_PARTS:
            if es <= b < es + ln: return self.off[sid] + so + (b - es)
        raise IndexError(b)

    def rd(self, fmt, addr): return struct.unpack_from(fmt, self.d, addr)
    def wr(self, fmt, addr, *v): struct.pack_into(fmt, self.d, addr, *v)

    def sb1_bytes(self, off, n): return bytes(self.d[self.sb1(off + i)] for i in range(n))
    def sb1_write(self, off, data):
        for i, b in enumerate(data): self.d[self.sb1(off + i)] = b

    def fix(self):
        for sid, o in self.off.items():
            self.wr('<H', o + 0xFF6, checksum(self.d[o:o + SIZES[sid]]))

    def save(self, path):
        self.fix()
        open(path, 'wb').write(self.d)

    # flags/vars
    def flag_addr(self, f):
        if 0x900 <= f <= 0x1FFF: return self.ext((f - 0x900) // 8), f % 8
        return self.sb1(0xEE0 + f // 8), f % 8

    def set_flag(self, f, on=True):
        a, bit = self.flag_addr(f)
        if on: self.d[a] |= 1 << bit
        else: self.d[a] &= ~(1 << bit) & 0xFF

    def get_flag(self, f):
        a, bit = self.flag_addr(f)
        return bool(self.d[a] >> bit & 1)

    def ext_vars(self):
        n = self.rd('<I', self.ext(0x324))[0]
        return [(self.rd('<H', self.ext(0x328 + 4 * i))[0], self.rd('<H', self.ext(0x328 + 4 * i + 2))[0]) for i in range(n)]

    def set_var(self, v, val):
        if 0x4000 <= v < 0x4100:
            self.wr('<H', self.sb1(0x1000 + 2 * (v - 0x4000)), val); return
        assert 0x4100 <= v <= 0x7FFF, hex(v)
        ev = self.ext_vars()
        for i, (vid, _) in enumerate(ev):
            if vid == v:
                self.wr('<H', self.ext(0x328 + 4 * i + 2), val); return
        i = len(ev)
        self.wr('<H', self.ext(0x328 + 4 * i), v); self.wr('<H', self.ext(0x328 + 4 * i + 2), val)
        self.wr('<I', self.ext(0x324), i + 1)


def map_ids(tree):
    mg = json.load(open(os.path.join(tree, 'data/maps/map_groups.json')))
    out = {}
    for g, grp in enumerate(mg['group_order']):
        for n, name in enumerate(mg[grp]):
            j = json.load(open(os.path.join(tree, 'data/maps', name, 'map.json')))
            out[name] = out[j['id']] = (g, n)
    return out


def species_data(tree):
    txt = open(os.path.join(tree, 'src/data/pokemon/species_info.h')).read()
    out = {}
    for m in re.finditer(r'\[(SPECIES_\w+)\]\s*=\s*\{(.*?)\n    \}', txt, re.S):
        body = m.group(2)
        g = lambda k: re.search(r'\.%s = (\w+)' % k, body)
        try:
            out[m.group(1)] = dict(stats=[int(g(k).group(1)) for k in ('baseHP', 'baseAttack', 'baseDefense', 'baseSpeed', 'baseSpAttack', 'baseSpDefense')],
                                   growth=g('growthRate').group(1), friendship=int(g('friendship').group(1)) if g('friendship') and g('friendship').group(1).isdigit() else 70)
        except AttributeError:
            pass
    return out


def move_pp(tree):
    txt = open(os.path.join(tree, 'src/data/battle_moves.h')).read()
    return {m.group(1): int(m.group(2)) for m in re.finditer(r'\[(MOVE_\w+)\]\s*=\s*\{.*?\.pp = (\d+)', txt, re.S)}


def learnset(tree, species):
    """last 4 level-up moves at or below level"""
    ptrs = open(os.path.join(tree, 'src/data/pokemon/level_up_learnset_pointers.h')).read()
    m = re.search(r'\[%s\]\s*=\s*(\w+)' % species, ptrs)
    if not m: return None
    ls = open(os.path.join(tree, 'src/data/pokemon/level_up_learnsets.h')).read()
    mm = re.search(r'%s\[\]\s*=\s*\{(.*?)\};' % m.group(1), ls, re.S)
    return [(int(a), b) for a, b in re.findall(r'LEVEL_UP_MOVE\(\s*(\d+),\s*(MOVE_\w+)\)', mm.group(1))]


def exp_for(growth, n):
    if growth == 'GROWTH_MEDIUM_FAST': return n ** 3
    if growth == 'GROWTH_SLOW': return 5 * n ** 3 // 4
    if growth == 'GROWTH_FAST': return 4 * n ** 3 // 5
    if growth == 'GROWTH_MEDIUM_SLOW': return max(0, 6 * n ** 3 // 5 - 15 * n * n + 100 * n - 140)
    if growth == 'GROWTH_ERRATIC':
        if n <= 50: return (100 - n) * n ** 3 // 50
        if n <= 68: return (150 - n) * n ** 3 // 100
        if n <= 98: return ((1911 - 10 * n) // 3) * n ** 3 // 500
        return (160 - n) * n ** 3 // 100
    if growth == 'GROWTH_FLUCTUATING':
        if n <= 15: return ((n + 1) // 3 + 24) * n ** 3 // 50
        if n <= 36: return (n + 14) * n ** 3 // 50
        return ((n // 2) + 32) * n ** 3 // 50
    return n ** 3


CHAR = {**{chr(ord('A') + i): 0xBB + i for i in range(26)}, **{chr(ord('a') + i): 0xD5 + i for i in range(26)}, ' ': 0, '.': 0xAD, '-': 0xAE}


def encode(s, n):
    b = [CHAR.get(c, 0) for c in s[:n]]
    return bytes(b + [0xFF] * (n - len(b)))


def make_mon(C, tree, spec, otid, otname, sd, pp):
    parts = spec.split(':')
    sp = parts[0] if parts[0].startswith('SPECIES_') else 'SPECIES_' + parts[0].upper()
    lvl = int(parts[1]) if len(parts) > 1 else 50
    if len(parts) > 2:
        moves = [x if x.startswith('MOVE_') else 'MOVE_' + x.upper() for x in parts[2].split(',')][:4]
    else:
        ls = learnset(tree, sp) or []
        moves = []
        for l, mv in ls:
            if l <= lvl and mv not in moves: moves.append(mv)
        moves = moves[-4:] or ['MOVE_TACKLE']
    info = sd[sp]
    sid = C.val(sp)
    pers = 0
    sub_g = struct.pack('<HHIBBH', sid, 0, exp_for(info['growth'], lvl), 0, info['friendship'], 0)
    mids = [C.val(m) for m in moves] + [0] * (4 - len(moves))
    pps = [pp.get(m, 10) for m in moves] + [0] * (4 - len(moves))
    sub_a = struct.pack('<4H4B', *mids, *pps)
    sub_e = bytes(12)
    ivs = 31 | 31 << 5 | 31 << 10 | 31 << 15 | 31 << 20 | 31 << 25
    origin = (lvl & 0x7F) | (4 << 7) | (4 << 11)  # met level, game FR, Poke Ball
    sub_m = struct.pack('<BBHII', 0, 0xFF, origin, ivs, 0)
    data = sub_g + sub_a + sub_e + sub_m  # personality 0 -> order G A E M
    cs = sum(struct.unpack('<24H', data)) & 0xFFFF
    key = pers ^ otid
    enc = b''.join(struct.pack('<I', struct.unpack_from('<I', data, i)[0] ^ key) for i in range(0, 48, 4))
    name = sp[8:].replace('_', ' ')
    box = struct.pack('<II', pers, otid) + encode(name, 10) + bytes([2, 0x02]) + otname[:7] + bytes([0]) + struct.pack('<HH', cs, 0) + enc
    assert len(box) == 80, len(box)
    b = info['stats']
    hp = (2 * b[0] + 31) * lvl // 100 + lvl + 10
    st = [(2 * x + 31) * lvl // 100 + 5 for x in b[1:]]
    party = struct.pack('<IBBHH5H', 0, lvl, 0xFF, hp, hp, *st)
    return box + party


POCKET = {'POCKET_ITEMS': (0x310, 42), 'POCKET_KEY_ITEMS': (0x3B8, 30), 'POCKET_POKE_BALLS': (0x430, 13), 'POCKET_TM_CASE': (0x464, 58), 'POCKET_BERRY_POUCH': (0x54C, 43)}


def item_pocket(tree, item):
    js = os.path.join(tree, 'src/data/items.json')
    if os.path.exists(js):
        for it in json.load(open(js))['items']:
            if it.get('itemId') == item: return it.get('pocket')
    return 'POCKET_KEY_ITEMS' if 'KEY' in item else 'POCKET_ITEMS'


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('tree'); ap.add_argument('base'); ap.add_argument('out')
    ap.add_argument('--map', nargs=3)
    ap.add_argument('--flag', nargs='*', default=[]); ap.add_argument('--clearflag', nargs='*', default=[])
    ap.add_argument('--var', nargs='*', default=[]); ap.add_argument('--mon', nargs='*', default=None)
    ap.add_argument('--item', nargs='*', default=[]); ap.add_argument('--money', type=int)
    ap.add_argument('--badges', type=int); ap.add_argument('--dump', action='store_true')
    a = ap.parse_args()
    C = Consts(a.tree)
    S = SaveFile(a.base)
    if a.map:
        ids = map_ids(a.tree)
        g, n = ids[a.map[0]]
        x, y = int(a.map[1]), int(a.map[2])
        for off in (0x04, 0x0C):
            S.sb1_write(off, struct.pack('<bbbxhh', g, n, -1, x, y))
        S.sb1_write(0, struct.pack('<hh', x, y))
        S.d[S.sb2(9)] |= 1
        for i in range(0x100): S.wr('<H', S.sb2(0x898 + 2 * i), 0)
    for f in a.flag: S.set_flag(C.val(f))
    for f in a.clearflag: S.set_flag(C.val(f), False)
    if a.badges is not None:
        base = C.val('FLAG_BADGE01_GET')
        for i in range(8): S.set_flag(base + i, i < a.badges)
    for v in a.var:
        k, val = v.split('=')
        S.set_var(C.val(k), C.val(val))
    if a.money is not None:
        key = S.rd('<I', S.sb2(0xF20))[0]
        S.sb1_write(0x290, struct.pack('<I', a.money ^ key))
    if a.mon is not None:
        sd = species_data(a.tree); pp = move_pp(a.tree)
        otid = struct.unpack('<I', bytes(S.d[S.sb2(0x0A) + i] for i in range(4)))[0]
        otname = bytes(S.d[S.sb2(0) + i] for i in range(7))
        mons = [make_mon(C, a.tree, m, otid, otname, sd, pp) for m in a.mon[:6]]
        S.sb1_write(0x34, bytes([len(mons)]))
        blob = b''.join(mons) + bytes(100 * (6 - len(mons)))
        S.sb1_write(0x38, blob)
        S.set_flag(C.val('FLAG_SYS_POKEMON_GET'))
    if a.item:
        key = S.rd('<I', S.sb2(0xF20))[0] & 0xFFFF
        for it in a.item:
            name, _, q = it.partition(':')
            name = name if name.startswith('ITEM_') else 'ITEM_' + name.upper()
            q = int(q or 1)
            off, cnt = POCKET.get(item_pocket(a.tree, name) or 'POCKET_ITEMS', POCKET['POCKET_ITEMS'])
            iid = C.val(name)
            for i in range(cnt):
                cur = struct.unpack('<HH', S.sb1_bytes(off + 4 * i, 4))
                if cur[0] in (0, iid):
                    old = (cur[1] ^ key) if cur[0] == iid else 0
                    S.sb1_write(off + 4 * i, struct.pack('<HH', iid, (old + q) ^ key))
                    break
    if a.dump:
        print('location', struct.unpack('<bbbxhh', S.sb1_bytes(0x04, 8)), 'continue', struct.unpack('<bbbxhh', S.sb1_bytes(0x0C, 8)))
        print('party', S.sb1_bytes(0x34, 1)[0])
        print('ext vars', [(hex(i), v) for i, v in S.ext_vars()])
    S.save(a.out)


if __name__ == '__main__':
    main()
