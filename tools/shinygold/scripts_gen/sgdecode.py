"""Decoders for event scripts and script data, mirroring the FRLG engine (src/scrcmd.c, src/battle_setup.c)."""
import struct

T = True  # terminator marker

# arg kinds:
#  raw:     b h w
#  values:  flag var vh item qty species species_raw move move_raw song heal trainer localid std cond strvar
#           special mc fade dir mvtype gfx gamestat textcolor stepcb mapsec stdstring crymode weather layout
#           fldeff item_raw
#  compound: map (2 bytes: group, num), warp (map + b warpid + vh x + vh y)
#  pointers: script text movement mart decor braille native ram loadword vptr
OPS = {
    0x00: ('nop', []), 0x01: ('nop1', []), 0x02: ('end', [], T), 0x03: ('return', [], T),
    0x04: ('call', ['script']), 0x05: ('goto', ['script'], T),
    0x06: ('goto_if', ['cond', 'script']), 0x07: ('call_if', ['cond', 'script']),
    0x08: ('gotostd', ['std'], T), 0x09: ('callstd', ['std']),
    0x0a: ('gotostd_if', ['cond', 'std']), 0x0b: ('callstd_if', ['cond', 'std']),
    0x0c: ('returnram', [], T), 0x0d: ('endram', [], T), 0x0e: ('setmysteryeventstatus', ['b']),
    0x0f: ('loadword', ['b', 'loadword']), 0x10: ('loadbyte', ['b', 'b']), 0x11: ('setptr', ['b', 'ram']),
    0x12: ('loadbytefromptr', ['b', 'ram']), 0x13: ('setptrbyte', ['b', 'ram']), 0x14: ('copylocal', ['b', 'b']),
    0x15: ('copybyte', ['ram', 'ram']), 0x16: ('setvar', ['var', 'h']), 0x17: ('addvar', ['var', 'h']),
    0x18: ('subvar', ['var', 'vh']), 0x19: ('copyvar', ['var', 'var']), 0x1a: ('setorcopyvar', ['var', 'vh']),
    0x1b: ('compare_local_to_local', ['b', 'b']), 0x1c: ('compare_local_to_value', ['b', 'b']),
    0x1d: ('compare_local_to_ptr', ['b', 'ram']), 0x1e: ('compare_ptr_to_local', ['ram', 'b']),
    0x1f: ('compare_ptr_to_value', ['ram', 'b']), 0x20: ('compare_ptr_to_ptr', ['ram', 'ram']),
    0x21: ('compare_var_to_value', ['var', 'h']), 0x22: ('compare_var_to_var', ['var', 'var']),
    0x23: ('callnative', ['native']), 0x24: ('gotonative', ['native']),
    0x25: ('special', ['special']), 0x26: ('specialvar', ['var', 'special']), 0x27: ('waitstate', []),
    0x28: ('delay', ['h']), 0x29: ('setflag', ['flag']), 0x2a: ('clearflag', ['flag']), 0x2b: ('checkflag', ['flag']),
    0x2c: ('initclock', None),  # engine consumes no args in FRLG
    0x2d: ('dotimebasedevents', []), 0x2e: ('gettime', []), 0x2f: ('playse', ['song']), 0x30: ('waitse', []),
    0x31: ('playfanfare', ['song']), 0x32: ('waitfanfare', []), 0x33: ('playbgm', ['song', 'b']),
    0x34: ('savebgm', ['song']), 0x35: ('fadedefaultbgm', []), 0x36: ('fadenewbgm', ['song']),
    0x37: ('fadeoutbgm', ['b']), 0x38: ('fadeinbgm', ['b']),
    0x39: ('warp', ['warp']), 0x3a: ('warpsilent', ['warp']), 0x3b: ('warpdoor', ['warp']), 0x3c: ('warphole', ['map']),
    0x3d: ('warpteleport', ['warp']), 0x3e: ('setwarp', ['warp']), 0x3f: ('setdynamicwarp', ['warp']),
    0x40: ('setdivewarp', ['warp']), 0x41: ('setholewarp', ['warp']),
    0x42: ('getplayerxy', ['var', 'var']), 0x43: ('getpartysize', []),
    0x44: ('additem', ['item', 'vh']), 0x45: ('removeitem', ['item', 'vh']), 0x46: ('checkitemspace', ['item', 'vh']),
    0x47: ('checkitem', ['item', 'vh']), 0x48: ('checkitemtype', ['item']), 0x49: ('addpcitem', ['item', 'vh']),
    0x4a: ('checkpcitem', ['item', 'vh']), 0x4b: ('adddecoration', ['vh']), 0x4c: ('removedecoration', ['vh']),
    0x4d: ('checkdecor', ['vh']), 0x4e: ('checkdecorspace', ['vh']),
    0x4f: ('applymovement', ['localid', 'movement']), 0x50: ('applymovementat', ['localid', 'movement', 'map']),
    0x51: ('waitmovement', ['localid']), 0x52: ('waitmovementat', ['localid', 'map']),
    0x53: ('removeobject', ['localid']), 0x54: ('removeobjectat', ['localid', 'map']),
    0x55: ('addobject', ['localid']), 0x56: ('addobjectat', ['localid', 'map']),
    0x57: ('setobjectxy', ['localid', 'vh', 'vh']), 0x58: ('showobjectat', ['localid', 'map']),
    0x59: ('hideobjectat', ['localid', 'map']), 0x5a: ('faceplayer', []), 0x5b: ('turnobject', ['localid', 'dir']),
    0x5c: ('trainerbattle', 'TB'), 0x5d: ('dotrainerbattle', []),
    0x5e: ('gotopostbattlescript', [], T), 0x5f: ('gotobeatenscript', [], T),
    0x60: ('checktrainerflag', ['trainer']), 0x61: ('settrainerflag', ['trainer']), 0x62: ('cleartrainerflag', ['trainer']),
    0x63: ('setobjectxyperm', ['localid', 'vh', 'vh']), 0x64: ('copyobjectxytoperm', ['localid']),
    0x65: ('setobjectmovementtype', ['localid', 'mvtype']), 0x66: ('waitmessage', []), 0x67: ('message', ['text']),
    0x68: ('closemessage', []), 0x69: ('lockall', []), 0x6a: ('lock', []), 0x6b: ('releaseall', []), 0x6c: ('release', []),
    0x6d: ('waitbuttonpress', []), 0x6e: ('yesnobox', ['b', 'b']), 0x6f: ('multichoice', ['b', 'b', 'mc', 'b']),
    0x70: ('multichoicedefault', ['b', 'b', 'mc', 'b', 'b']), 0x71: ('multichoicegrid', ['b', 'b', 'mc', 'b', 'b']),
    0x72: ('drawbox', []), 0x73: ('erasebox', ['b', 'b', 'b', 'b']), 0x74: ('drawboxtext', None),
    0x75: ('showmonpic', ['species', 'b', 'b']), 0x76: ('hidemonpic', []), 0x77: ('showcontestpainting', ['b']),
    0x78: ('braillemessage', ['braille']), 0x79: ('givemon', ['species', 'b', 'item', 'w', 'w', 'b']),
    0x7a: ('giveegg', ['species']), 0x7b: ('setmonmove', ['b', 'b', 'move_raw']), 0x7c: ('checkpartymove', ['move_raw']),
    0x7d: ('bufferspeciesname', ['strvar', 'species']), 0x7e: ('bufferleadmonspeciesname', ['strvar']),
    0x7f: ('bufferpartymonnick', ['strvar', 'vh']), 0x80: ('bufferitemname', ['strvar', 'item']),
    0x81: ('bufferdecorationname', ['strvar', 'vh']), 0x82: ('buffermovename', ['strvar', 'move']),
    0x83: ('buffernumberstring', ['strvar', 'vh']), 0x84: ('bufferstdstring', ['strvar', 'stdstring']),
    0x85: ('bufferstring', ['strvar', 'text']), 0x86: ('pokemart', ['mart']), 0x87: ('pokemartdecoration', ['decor']),
    0x88: ('pokemartdecoration2', ['decor']), 0x89: ('playslotmachine', ['vh']), 0x8a: ('setberrytree', None),
    0x8b: ('choosecontestmon', []), 0x8c: ('startcontest', []), 0x8d: ('showcontestresults', []),
    0x8e: ('contestlinktransfer', []), 0x8f: ('random', ['vh']), 0x90: ('addmoney', ['w', 'b']),
    0x91: ('removemoney', ['w', 'b']), 0x92: ('checkmoney', ['w', 'b']), 0x93: ('showmoneybox', ['b', 'b', 'b']),
    0x94: ('hidemoneybox', None), 0x95: ('updatemoneybox', ['b', 'b', 'b']), 0x96: ('getpokenewsactive', None),
    0x97: ('fadescreen', ['fade']), 0x98: ('fadescreenspeed', ['fade', 'b']), 0x99: ('setflashlevel', ['vh']),
    0x9a: ('animateflash', ['b']), 0x9b: ('messageautoscroll', ['text']), 0x9c: ('dofieldeffect', ['fldeff']),
    0x9d: ('setfieldeffectargument', ['b', 'vh']), 0x9e: ('waitfieldeffect', ['fldeff']), 0x9f: ('setrespawn', ['heal']),
    0xa0: ('checkplayergender', []), 0xa1: ('playmoncry', ['species', 'crymode']),
    0xa2: ('setmetatile', ['vh', 'vh', 'vh', 'vh']), 0xa3: ('resetweather', []), 0xa4: ('setweather', ['weather']),
    0xa5: ('doweather', []), 0xa6: ('setstepcallback', ['stepcb']), 0xa7: ('setmaplayoutindex', ['layout']),
    0xa8: ('setobjectsubpriority', ['localid', 'map', 'b']), 0xa9: ('resetobjectsubpriority', ['localid', 'map']),
    0xaa: ('createvobject', ['gfx', 'b', 'vh', 'vh', 'b', 'dir']), 0xab: ('turnvobject', ['b', 'dir']),
    0xac: ('opendoor', ['vh', 'vh']), 0xad: ('closedoor', ['vh', 'vh']), 0xae: ('waitdooranim', []),
    0xaf: ('setdooropen', ['vh', 'vh']), 0xb0: ('setdoorclosed', ['vh', 'vh']), 0xb1: ('addelevmenuitem', None),
    0xb2: ('showelevmenu', []), 0xb3: ('checkcoins', ['var']), 0xb4: ('addcoins', ['vh']), 0xb5: ('removecoins', ['vh']),
    0xb6: ('setwildbattle', ['species_raw', 'b', 'item_raw']), 0xb7: ('dowildbattle', []),
    0xb8: ('setvaddress', ['w']), 0xb9: ('vgoto', ['w'], T), 0xba: ('vcall', ['w']),
    0xbb: ('vgoto_if', ['cond', 'w']), 0xbc: ('vcall_if', ['cond', 'w']), 0xbd: ('vmessage', ['w']),
    0xbe: ('vbuffermessage', ['w']), 0xbf: ('vbufferstring', ['strvar', 'w']),
    0xc0: ('showcoinsbox', ['b', 'b']), 0xc1: ('hidecoinsbox', ['b', 'b']), 0xc2: ('updatecoinsbox', ['b', 'b']),
    0xc3: ('incrementgamestat', ['gamestat']), 0xc4: ('setescapewarp', ['warp']), 0xc5: ('waitmoncry', []),
    0xc6: ('bufferboxname', ['strvar', 'vh']), 0xc7: ('textcolor', ['textcolor']), 0xc8: ('loadhelp', ['text']),
    0xc9: ('unloadhelp', []), 0xca: ('signmsg', []), 0xcb: ('normalmsg', []), 0xcc: ('comparestat', ['gamestat', 'w']),
    0xcd: ('setmonmodernfatefulencounter', ['vh']), 0xce: ('checkmonmodernfatefulencounter', ['vh']),
    0xcf: ('trywondercardscript', []), 0xd0: ('setworldmapflag', ['flag']), 0xd1: ('warpspinenter', ['warp']),
    0xd2: ('setmonmetlocation', ['vh', 'mapsec']), 0xd3: ('getbraillestringwidth', ['braille']),
    0xd4: ('bufferitemnameplural', ['strvar', 'item', 'vh']),
}

SIZES = {'b': 1, 'h': 2, 'w': 4, 'map': 2, 'warp': 7, 'cond': 1, 'std': 1, 'strvar': 1, 'mc': 1, 'fade': 1, 'dir': 1,
         'mvtype': 1, 'gfx': 1, 'gamestat': 1, 'textcolor': 1, 'stepcb': 1, 'mapsec': 1}
for _k in ['script', 'text', 'movement', 'mart', 'decor', 'braille', 'native', 'ram', 'loadword', 'vptr']:
    SIZES[_k] = 4
PTR_KINDS = {'script', 'text', 'movement', 'mart', 'decor', 'braille'}

# trainerbattle pointer roles per type (mirrors BattleSetup_ConfigureTrainerBattle; unknown types -> SINGLE params)
TB_PTRS = {
    0: [('text', 'Intro'), ('text', 'Defeat')],
    1: [('text', 'Intro'), ('text', 'Defeat'), ('script', 'Continue')],
    2: [('text', 'Intro'), ('text', 'Defeat'), ('script', 'Continue')],
    3: [('text', 'Defeat')],
    4: [('text', 'Intro'), ('text', 'Defeat'), ('text', 'NotEnoughMons')],
    5: [('text', 'Intro'), ('text', 'Defeat')],
    6: [('text', 'Intro'), ('text', 'Defeat'), ('text', 'NotEnoughMons'), ('script', 'Continue')],
    7: [('text', 'Intro'), ('text', 'Defeat'), ('text', 'NotEnoughMons')],
    8: [('text', 'Intro'), ('text', 'Defeat'), ('text', 'NotEnoughMons'), ('script', 'Continue')],
    9: [('text', 'Defeat'), ('text', 'Victory')],
}


def tb_ptrs(t):
    return TB_PTRS.get(t, TB_PTRS[0])


class Instr:
    __slots__ = ('addr', 'op', 'size', 'name', 'args', 'term', 'raw', 'tbtype')

    def __init__(self, addr, op, name):
        self.addr = addr; self.op = op; self.name = name
        self.args = []; self.term = False; self.raw = False; self.size = 1; self.tbtype = None

    def refs(self):
        """(kind, value, role) for pointer args."""
        out = []
        for a in self.args:
            k, v = a[0], a[1]
            if k in PTR_KINDS or k in ('native', 'ram', 'loadword'):
                out.append((k, v, a[2] if len(a) > 2 else None))
        return out


def is_rom_ptr(v, romlen):
    return 0x08000000 <= v < 0x08000000 + romlen


def decode_instr(d, addr):
    """Decode one script command at file offset addr. Returns Instr or None if it runs past the ROM end."""
    if addr >= len(d):
        return None
    op = d[addr]
    spec = OPS.get(op)
    if spec is None:
        ins = Instr(addr, op, None)
        ins.term = True; ins.raw = True
        return ins
    name, args = spec[0], spec[1]
    ins = Instr(addr, op, name)
    ins.term = len(spec) > 2 and spec[2]
    p = addr + 1
    if args is None:          # FRLG no-op that consumes no argument bytes (macro would emit some)
        ins.raw = True
        ins.size = 1
        return ins
    if args == 'TB':
        if p + 5 > len(d):
            return None
        t = d[p]; tr = d[p + 1] | d[p + 2] << 8; lid = d[p + 3] | d[p + 4] << 8
        ins.tbtype = t
        ins.args = [('b', t), ('trainer_raw', tr), ('h', lid)]
        p += 5
        for kind, role in tb_ptrs(t):
            if p + 4 > len(d):
                return None
            ins.args.append((kind, struct.unpack_from('<I', d, p)[0], role))
            p += 4
        ins.size = p - addr
        return ins
    for k in args:
        if k == 'map':
            if p + 2 > len(d): return None
            ins.args.append(('map', (d[p], d[p + 1]))); p += 2
        elif k == 'warp':
            if p + 7 > len(d): return None
            ins.args.append(('warp', (d[p], d[p + 1], d[p + 2], d[p + 3] | d[p + 4] << 8, d[p + 5] | d[p + 6] << 8)))
            p += 7
        else:
            n = SIZES.get(k, 2)
            if p + n > len(d): return None
            if n == 1: v = d[p]
            elif n == 2: v = d[p] | d[p + 1] << 8
            else: v = struct.unpack_from('<I', d, p)[0]
            ins.args.append((k, v)); p += n
    ins.size = p - addr
    return ins


# ------------------------------------------------------------------ data decoders
def text_end(d, off, maxlen=0x2000):
    """Return end (exclusive, after 0xFF) of a string starting at off, or None."""
    lim = min(len(d), off + maxlen)
    i = off
    while i < lim:
        if d[i] == 0xFF:
            return i + 1
        i += 1
    return None


def movement_end(d, off, maxlen=0x400):
    lim = min(len(d), off + maxlen)
    i = off
    while i < lim:
        if d[i] == 0xFE:
            return i + 1
        i += 1
    return None


def u16list_end(d, off, maxlen=0x400):
    lim = min(len(d) - 1, off + maxlen)
    i = off
    while i < lim:
        if d[i] == 0 and d[i + 1] == 0:
            return i + 2
        i += 2
    return None


BRAILLE_ENC = {}
_br = dict(SPACE=0x00, A=0x01, C=0x03, COMMA=0x04, B=0x05, I=0x06, F=0x07, E=0x09, D=0x0B, COLON=0x0C, H=0x0D,
           J=0x0E, G=0x0F, APOSTROPHE=0x10, K=0x11, SLASH=0x12, M=0x13, SEMICOLON=0x14, L=0x15, S=0x16, P=0x17,
           O=0x19, N=0x1B, EXCL_MARK=0x1C, R=0x1D, T=0x1E, Q=0x1F, PERIOD=0x2C, W=0x2E, HYPHEN=0x30, U=0x31, X=0x33,
           QUESTION_MARK=0x34, V=0x35, Z=0x39, NUMBER=0x3A, Y=0x3B, PAREN=0x3C)
for _c in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
    BRAILLE_ENC[_c] = _br[_c]; BRAILLE_ENC[_c.lower()] = _br[_c]
for _i, _c in enumerate('1234567890'):
    BRAILLE_ENC[_c] = _br['ABCDEFGHIJ'[_i]]
BRAILLE_ENC.update({' ': 0x00, ',': 0x04, '.': 0x2C, '?': 0x34, '!': 0x1C, ':': 0x0C, ';': 0x14, '-': 0x30,
                    '/': 0x12, '(': 0x3C, ')': 0x3C, "'": 0x10, '#': 0x3A})


def braille_encode(s):
    out = bytearray()
    in_num = False
    i = 0
    while i < len(s):
        if s[i] == '\\' and s[i + 1] == 'n':
            out.append(0xFE); i += 2; continue
        c = s[i]
        if c == '$':
            out.append(0xFF); i += 1; continue
        if not in_num and '0' <= c <= '9':
            in_num = True; out.append(0x3A)
        elif in_num and BRAILLE_ENC[c] == 0:
            in_num = False
        out.append(BRAILLE_ENC[c]); i += 1
    return bytes(out)


def braille_decode(data):
    """data includes the final 0xFF. Returns a .braille string body or None."""
    rev = {}
    for c in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ ,.?!:;-/(\'':
        rev.setdefault(BRAILLE_ENC[c], c)
    digits = {BRAILLE_ENC[c]: c for c in '1234567890'}
    s = ''
    i = 0
    in_num = False
    body = data[:-1]
    while i < len(body):
        b = body[i]
        if b == 0xFE:
            s += '\\n'; i += 1; continue
        if b == 0x3A and not in_num and i + 1 < len(body) and body[i + 1] in digits:
            in_num = True; i += 1; continue
        if in_num:
            if b == 0:
                in_num = False; s += ' '; i += 1; continue
            if b in digits:
                s += digits[b]; i += 1; continue
        if b == 0x3A:
            s += '#'; i += 1; continue
        if b not in rev:
            return None
        s += rev[b]; i += 1
    s += '$'
    try:
        if braille_encode(s) != bytes(data):
            return None
    except KeyError:
        return None
    return s
