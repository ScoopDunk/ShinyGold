"""Core helpers for the ShinyGold -> pokefirered extraction (sgx).

ROM access, charmap text codec, LZ77, constant tables, vanilla symbol lookup.
"""
import os, re, struct, bisect, json, glob, functools

HACK_ROM = os.environ.get('SG_ROM', '/home/claude/work/shinygold_patched.gba')
VANILLA_ROM = '/home/claude/work/vanilla_fr10.gba'
VANILLA_DIR = '/home/claude/vanilla'          # pristine pokefirered (built)
VANILLA_SYMS = '/home/claude/work/vanilla_syms.txt'


class Rom:
    def __init__(self, path=HACK_ROM):
        self.path = path
        self.d = open(path, 'rb').read()
        self.cov = bytearray(len(self.d))  # coverage map (1 = explained by an extractor)

    def u8(self, o): return self.d[o]
    def s8(self, o): return struct.unpack_from('<b', self.d, o)[0]
    def u16(self, o): return struct.unpack_from('<H', self.d, o)[0]
    def s16(self, o): return struct.unpack_from('<h', self.d, o)[0]
    def u32(self, o): return struct.unpack_from('<I', self.d, o)[0]
    def s32(self, o): return struct.unpack_from('<i', self.d, o)[0]

    def ptr(self, o):
        """Read a ROM pointer at o and return the file offset (or None if NULL/invalid)."""
        p = self.u32(o)
        if 0x08000000 <= p < 0x08000000 + len(self.d):
            return p - 0x08000000
        return None

    @staticmethod
    def is_rom_ptr(v, size=0x1000000):
        return 0x08000000 <= v < 0x08000000 + size

    def mark(self, o, n):
        if o is None: return
        self.cov[o:o + n] = b'\x01' * n


# ---------------------------------------------------------------- symbols
@functools.lru_cache(None)
def vanilla_symbols():
    """addr(file offset) -> list of names; plus sorted list for range lookup."""
    by_addr = {}
    rng = []
    for line in open(VANILLA_SYMS):
        p = line.split()
        a = int(p[0], 16) - 0x08000000
        if len(p) == 4:
            size = int(p[1], 16); typ = p[2]; name = p[3]
        else:
            size = 0; typ = p[1]; name = p[2]
        by_addr.setdefault(a, []).append((name, size, typ))
        rng.append((a, size, name))
    rng.sort()
    return by_addr, rng


def vanilla_name_at(off, prefer=None):
    by_addr, _ = vanilla_symbols()
    names = by_addr.get(off)
    if not names: return None
    if prefer:
        for n, s, t in names:
            if prefer(n): return n
    # prefer global names
    for n, s, t in names:
        if t.isupper() and not n.startswith('.'): return n
    return names[0][0]


def vanilla_addr(name):
    by_addr, rng = vanilla_symbols()
    for a, s, n in rng:
        if n == name: return a
    return None


# ---------------------------------------------------------------- charmap / text
class Charmap:
    def __init__(self, path=os.path.join(VANILLA_DIR, 'charmap.txt')):
        self.chars = {}      # str char -> bytes
        self.consts = {}     # NAME -> bytes
        self.escapes = {}
        self.latin_bytes = {}
        in_latin = True
        for raw in open(path, encoding='utf-8'):
            if raw.startswith('@ Hiragana'): in_latin = False
            m = re.match(r"^\s*('(?:\\.|[^'])+'|[A-Za-z_][A-Za-z0-9_]*)\s*=\s*((?:[0-9A-Fa-f]{2}\s*)+)", raw)
            if not m: continue
            lhs = m.group(1); seq = bytes(int(x, 16) for x in m.group(2).split())
            if lhs.startswith("'"):
                inner = lhs[1:-1]
                if inner.startswith('\\') and len(inner) == 2:
                    self.escapes.setdefault(inner[1], seq)
                elif len(inner) == 1:
                    self.chars.setdefault(inner, seq)
                    if in_latin and len(seq) == 1 and inner not in '"\\{}':
                        self.latin_bytes.setdefault(seq[0], inner)
            else:
                self.consts.setdefault(lhs, seq)
        # reverse maps for single bytes: Latin section chars, then single-byte consts in Latin section, then any char
        self.byte_to_char = dict(self.latin_bytes)
        for nm in ['SUPER_ER', 'LV', 'PK', 'UP_ARROW', 'DOWN_ARROW', 'LEFT_ARROW', 'RIGHT_ARROW', 'SUPER_E', 'SUPER_RE']:
            self.byte_to_char.setdefault(self.consts[nm][0], '{%s}' % nm)
        self.multi_seqs = [(self.consts['POKEBLOCK'], '{POKEBLOCK}'), (self.consts['PKMN'], '{PKMN}')]
        for ch, seq in self.chars.items():
            if len(seq) == 1 and seq[0] not in self.byte_to_char:
                if ch in '"\\{}': continue
                self.byte_to_char[seq[0]] = ch
        self.fd_names = {}
        for pref in ['PLAYER', 'STR_VAR_1', 'STR_VAR_2', 'STR_VAR_3', 'KUN', 'RIVAL', 'VERSION', 'EVIL_TEAM',
                     'GOOD_TEAM', 'EVIL_LEADER', 'GOOD_LEADER', 'EVIL_LEGENDARY', 'GOOD_LEGENDARY', 'UNKNOWN_STR']:
            s = self.consts[pref]
            self.fd_names.setdefault(s[1], pref)
        for name, s in self.consts.items():
            if len(s) == 2 and s[0] == 0xFD:
                self.fd_names.setdefault(s[1], name)
        self.color_names = {}
        for name in ['TRANSPARENT', 'WHITE', 'DARK_GRAY', 'LIGHT_GRAY', 'RED', 'LIGHT_RED', 'GREEN', 'LIGHT_GREEN',
                     'BLUE', 'LIGHT_BLUE', 'DYNAMIC_COLOR1', 'DYNAMIC_COLOR2', 'DYNAMIC_COLOR3', 'DYNAMIC_COLOR4',
                     'DYNAMIC_COLOR5', 'DYNAMIC_COLOR6']:
            if name in self.consts: self.color_names.setdefault(self.consts[name][0], name)
        self.sound_names = {}
        for name, s in self.consts.items():
            if (name.startswith('MUS_') or name.startswith('SE_')) and len(s) == 2:
                self.sound_names.setdefault(s, name)
        self.fc_names = {}
        for name in ['NAME_END', 'COLOR', 'HIGHLIGHT', 'SHADOW', 'COLOR_HIGHLIGHT_SHADOW', 'PALETTE', 'FONT', 'RESET_FONT',
                     'PAUSE', 'PAUSE_UNTIL_PRESS', 'WAIT_SE', 'PLAY_BGM', 'ESCAPE', 'SHIFT_RIGHT', 'SHIFT_DOWN',
                     'FILL_WINDOW', 'PLAY_SE', 'CLEAR', 'SKIP', 'CLEAR_TO', 'MIN_LETTER_SPACING', 'JPN', 'ENG',
                     'PAUSE_MUSIC', 'RESUME_MUSIC']:
            s = self.consts.get(name)
            if s and len(s) == 2: self.fc_names[s[1]] = name
        # other multi-byte constants starting with F7..F9 etc
        self.misc_multi = {}
        for name, s in self.consts.items():
            if len(s) == 2 and s[0] in (0xF7, 0xF8, 0xF9):
                self.misc_multi.setdefault(s, name)
        self.single_consts = {}
        for name, s in self.consts.items():
            if len(s) == 1 and s[0] >= 0xF7 and s[0] not in (0xFA, 0xFB, 0xFE, 0xFF):
                self.single_consts.setdefault(s[0], name)


EXT_LEN = [1, 2, 2, 2, 4, 2, 2, 1, 2, 1, 1, 3, 2, 2, 2, 1, 3, 2, 2, 2, 2, 1, 1, 1, 1]


@functools.lru_cache(None)
def charmap():
    return Charmap()


def decode_tokens(data, start, maxlen=4096):
    """Decode a 0xFF-terminated string. Returns (tokens, end_offset_exclusive_after_FF).
    tokens: list of str pieces in preproc syntax (without the final '$')."""
    cm = charmap()
    toks = []
    i = start
    lim = min(len(data), start + maxlen)
    while i < lim:
        b = data[i]
        if b == 0xFF:
            return toks, i + 1
        if b == 0xFE: toks.append('\\n'); i += 1; continue
        if b == 0xFA: toks.append('\\l'); i += 1; continue
        if b == 0xFB: toks.append('\\p'); i += 1; continue
        if b == 0xFD:
            if i + 1 >= lim: break
            c = data[i + 1]
            n = cm.fd_names.get(c)
            toks.append('{%s}' % n if n else '{0xFD}{0x%02X}' % c)
            i += 2; continue
        if b == 0xFC:
            if i + 1 >= lim: break
            c = data[i + 1]
            ln = EXT_LEN[c] if c < len(EXT_LEN) else 1
            if c >= len(EXT_LEN):
                toks.append('{0xFC}{0x%02X}' % c); i += 2; continue
            args = data[i + 2:i + 1 + ln]
            if any(a == 0xFF for a in args):
                # malformed; emit raw and keep going byte by byte
                toks.append('{0xFC}'); i += 1; continue
            name = cm.fc_names.get(c)
            if name is None:
                toks.append('{0xFC}{0x%02X}%s' % (c, ''.join('{0x%02X}' % a for a in args)))
            elif c in (1, 2, 3) and args[0] in cm.color_names:
                toks.append('{%s %s}' % (name, cm.color_names[args[0]]))
            elif c == 4 and all(a in cm.color_names for a in args):
                toks.append('{%s %s}' % (name, ' '.join(cm.color_names[a] for a in args)))
            elif c in (0xB, 0x10):
                s = bytes(args)
                sn = cm.sound_names.get(s)
                toks.append('{%s %s}' % (name, sn) if sn else '{%s 0x%04X}' % (name, args[0] | (args[1] << 8)))
            elif c == 0xC and args[0] == 0xFB and 'TALL_PLUS' in cm.consts:
                toks.append('{TALL_PLUS}')
            elif ln == 1:
                toks.append('{%s}' % name)
            else:
                toks.append('{%s %s}' % (name, ' '.join('0x%02X' % a for a in args)))
            i += 1 + ln; continue
        if b in (0xF7, 0xF8, 0xF9) and i + 1 < lim:
            s = bytes(data[i:i + 2])
            if s in cm.misc_multi:
                toks.append('{%s}' % cm.misc_multi[s]); i += 2; continue
        hit = None
        for seq, tok in cm.multi_seqs:
            if data[i:i + len(seq)] == seq: hit = (seq, tok); break
        if hit:
            toks.append(hit[1]); i += len(hit[0]); continue
        ch = cm.byte_to_char.get(b)
        if ch is not None:
            toks.append(ch)
        elif b in cm.single_consts:
            toks.append('{%s}' % cm.single_consts[b])
        else:
            toks.append('{0x%02X}' % b)
        i += 1
    return None, i


def encode_tokens_str(s):
    """Encode a preproc-syntax string body (as produced by decode) back to bytes; for verification."""
    cm = charmap()
    out = bytearray()
    i = 0
    while i < len(s):
        c = s[i]
        if c == '{':
            j = s.index('}', i)
            inner = s[i + 1:j].split()
            for t in inner:
                if t.startswith('0x'):
                    h = t[2:]
                    v = int(h, 16)
                    if len(h) == 2: out.append(v)
                    elif len(h) == 4: out += struct.pack('<H', v)
                    elif len(h) == 8: out += struct.pack('<I', v)
                    else: raise ValueError(t)
                elif t.isdigit():
                    v = int(t); out.append(v)
                else:
                    out += cm.consts[t]
            i = j + 1
        elif c == '\\':
            out += cm.escapes[s[i + 1]]; i += 2
        else:
            out += cm.chars[c]; i += 1
    return bytes(out)


def string_lines(toks):
    """Group tokens into .string lines, splitting after \\n, \\l, \\p. Final line ends with '$'."""
    lines = []
    cur = ''
    for t in toks:
        cur += t
        if t in ('\\n', '\\l', '\\p'):
            lines.append(cur); cur = ''
    lines.append(cur + '$')
    return lines


def decode_text(rom, off, maxlen=4096):
    toks, end = decode_tokens(rom.d, off, maxlen)
    if toks is None: return None, end
    return ''.join(toks), end


def text_asm(rom, off, label, maxlen=4096, glob_label=True):
    toks, end = decode_tokens(rom.d, off, maxlen)
    if toks is None:
        raise ValueError('unterminated string at %x' % off)
    body = ''.join(toks)
    enc = encode_tokens_str(body) + b'\xff'
    if enc != rom.d[off:end]:
        # fall back to fully raw representation
        toks = ['{0x%02X}' % b for b in rom.d[off:end - 1]]
    lines = string_lines(toks)
    out = ['%s%s' % (label, '::' if glob_label else ':')]
    for l in lines:
        out.append('\t.string "%s"' % l)
    return '\n'.join(out) + '\n', end


# ---------------------------------------------------------------- LZ77
def lz77_decompress(data, off):
    """GBA BIOS LZ77 (type 0x10). Returns (bytes, compressed_length)."""
    if data[off] != 0x10:
        raise ValueError('not LZ77 at %x' % off)
    size = data[off + 1] | (data[off + 2] << 8) | (data[off + 3] << 16)
    out = bytearray()
    i = off + 4
    while len(out) < size:
        flags = data[i]; i += 1
        for bit in range(8):
            if len(out) >= size: break
            if flags & (0x80 >> bit):
                b1, b2 = data[i], data[i + 1]; i += 2
                ln = (b1 >> 4) + 3
                disp = ((b1 & 0xF) << 8 | b2) + 1
                for _ in range(ln):
                    out.append(out[-disp])
            else:
                out.append(data[i]); i += 1
    return bytes(out[:size]), i - off


def is_lz77(data, off, max_size=0x40000):
    if off is None or off + 4 > len(data) or data[off] != 0x10: return False
    size = data[off + 1] | (data[off + 2] << 8) | (data[off + 3] << 16)
    if size == 0 or size > max_size: return False
    try:
        lz77_decompress(data, off)
        return True
    except Exception:
        return False


# ---------------------------------------------------------------- constants
_DEFINE_RE = re.compile(r'^\s*#define\s+([A-Za-z_][A-Za-z0-9_]*)\s+(.+?)\s*(//.*)?$')


@functools.lru_cache(None)
def c_constants(root=VANILLA_DIR):
    """Parse include/constants/*.h into name -> int (best effort)."""
    raw = {}
    order = []
    for path in sorted(glob.glob(os.path.join(root, 'include/constants/*.h'))):
        for line in open(path, encoding='utf-8', errors='replace'):
            m = _DEFINE_RE.match(line)
            if not m: continue
            name, val = m.group(1), m.group(2)
            val = val.split('//')[0].strip()
            if '(' in name: continue
            if name not in raw:
                raw[name] = (val, os.path.basename(path)); order.append(name)
    vals = {}

    def ev(name, depth=0):
        if name in vals: return vals[name]
        if depth > 50 or name not in raw: raise KeyError(name)
        expr = raw[name][0]
        expr2 = re.sub(r'\b([0-9]+)[uU][lL]?\b', r'\1', expr)
        expr2 = re.sub(r'\b(0x[0-9A-Fa-f]+)[uU]\b', r'\1', expr2)
        def rep(m):
            t = m.group(0)
            if re.match(r'^0x', t) or t.isdigit(): return t
            return str(ev(t, depth + 1))
        expr3 = re.sub(r'\b[A-Za-z_][A-Za-z0-9_]*\b', rep, expr2)
        expr3 = expr3.replace('/', '//')
        v = int(eval(expr3, {'__builtins__': {}}))
        vals[name] = v
        return v
    for n in order:
        try: ev(n)
        except Exception: pass
    files = {n: raw[n][1] for n in vals}
    return vals, files, order


def reverse_constants(prefix, file=None, exclude=None, root=VANILLA_DIR):
    vals, files, order = c_constants(root)
    rev = {}
    for n in order:
        if n not in vals: continue
        if not n.startswith(prefix): continue
        if file and files.get(n) != file: continue
        if exclude and exclude(n): continue
        rev.setdefault(vals[n], n)
    return rev


@functools.lru_cache(None)
def specials_list(root=VANILLA_DIR):
    out = []
    for line in open(os.path.join(root, 'data/specials.inc')):
        m = re.match(r'\s*def_special\s+(\w+)', line)
        if m: out.append(m.group(1))
    return out


@functools.lru_cache(None)
def movement_names(root=VANILLA_DIR):
    vals, _, _ = c_constants(root)
    rev = {}
    for line in open(os.path.join(root, 'asm/macros/movement.inc')):
        m = re.match(r'\s*create_movement_action\s+(\w+),\s*(\w+)', line)
        if m:
            v = vals.get(m.group(2))
            if v is None:
                try: v = int(m.group(2), 0)
                except ValueError: continue
            rev.setdefault(v, m.group(1))
    return rev
