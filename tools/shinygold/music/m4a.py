"""M4A (Sappy / MP2000) song structure parser for GBA ROMs.

Used by the ShinyGold music port: inventory of changed songs, song-asm generation and the
semantic checker.  All offsets are ROM file offsets (address - 0x08000000).
"""
import struct

ROM_BASE = 0x08000000

# command bytes
W00 = 0x80
FINE, GOTO, PATT, PEND, REPT = 0xB1, 0xB2, 0xB3, 0xB4, 0xB5
MEMACC, PRIO, TEMPO, KEYSH, VOICE, VOL, PAN, BEND, BENDR = 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1
LFOS, LFODL, MOD, MODT, TUNE = 0xC2, 0xC3, 0xC4, 0xC5, 0xC8
PORT, XCMD, EOT, TIE = 0xCC, 0xCD, 0xCE, 0xCF

# commands that end a track (ply_fine) -- 0xB1 and the unused slots that map to ply_fine
FINE_CMDS = {0xB1, 0xB6, 0xB7, 0xB8, 0xC6, 0xC7, 0xC9, 0xCA, 0xCB}
ONE_ARG = {PRIO, TEMPO, KEYSH, VOICE, VOL, PAN, BEND, BENDR, LFOS, LFODL, MOD, MODT, TUNE}
# xcmd sub-command -> number of argument bytes
XCMD_ARGS = {0: 0, 1: 4, 2: 1, 3: 0, 4: 1, 5: 1, 6: 1, 7: 1, 8: 1, 9: 1, 10: 1, 11: 1, 12: 2, 13: 4}

CLOCK = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
         28, 30, 32, 36, 40, 42, 44, 48, 52, 54, 56, 60, 64, 66, 68, 72, 76, 78, 80, 84, 88, 90, 92, 96]


class Rom:
    def __init__(self, path_or_bytes):
        if isinstance(path_or_bytes, (bytes, bytearray)):
            self.d = bytes(path_or_bytes)
        else:
            self.d = open(path_or_bytes, 'rb').read()
        self.size = len(self.d)

    def u8(self, o): return self.d[o]
    def u16(self, o): return struct.unpack_from('<H', self.d, o)[0]
    def u32(self, o): return struct.unpack_from('<I', self.d, o)[0]

    def is_ptr(self, v):
        return ROM_BASE <= v < ROM_BASE + self.size

    def ptr(self, o):
        v = self.u32(o)
        return v - ROM_BASE if self.is_ptr(v) else None


class Insn:
    """One decoded track command.  `ptr` = file offset of an embedded pointer target (or None);
    `ptr_at` = offset (relative to insn start) of the 4-byte pointer."""
    __slots__ = ('off', 'size', 'cmd', 'explicit', 'args', 'ptr', 'ptr_at', 'kind')

    def __init__(self, off, size, cmd, explicit, args, ptr=None, ptr_at=None, kind=None):
        self.off, self.size, self.cmd, self.explicit, self.args = off, size, cmd, explicit, args
        self.ptr, self.ptr_at, self.kind = ptr, ptr_at, kind

    def __repr__(self):
        return 'Insn(%x,%d,%02x,%s,%s,%s)' % (self.off, self.size, self.cmd, self.explicit, self.args,
                                             hex(self.ptr) if self.ptr is not None else None)


def decode_insn(rom, off, running):
    """Decode one command at `off` given the current running status.
    Returns (Insn, new_running_status).  Raises ValueError on undecodable data."""
    d = rom.d
    b = d[off]
    explicit = b >= 0x80
    if explicit:
        cmd = b
        p = off + 1
        if cmd >= 0xBD:
            running = cmd
    else:
        if running is None or running < 0xBD:
            raise ValueError('running status byte %02x at %x without running status' % (b, off))
        cmd = running
        p = off
    if cmd >= TIE:  # notes / TIE: up to 3 optional args (key, velocity, gate)
        args = []
        if d[p] < 0x80:
            args.append(d[p]); p += 1
            if d[p] < 0x80:
                args.append(d[p]); p += 1
                if d[p] < 0x80:
                    args.append(d[p]); p += 1
        return Insn(off, p - off, cmd, explicit, args, kind='note'), running
    if cmd <= 0xB0:
        return Insn(off, 1, cmd, True, [], kind='wait'), running
    if cmd in FINE_CMDS:
        return Insn(off, p - off, cmd, explicit, [], kind='fine'), running
    if cmd == GOTO or cmd == PATT:
        tgt = rom.ptr(p)
        if tgt is None:
            raise ValueError('bad pointer at %x' % p)
        return Insn(off, p + 4 - off, cmd, explicit, [], tgt, p - off, kind='goto' if cmd == GOTO else 'patt'), running
    if cmd == PEND:
        return Insn(off, p - off, cmd, explicit, [], kind='pend'), running
    if cmd == REPT:
        cnt = d[p]
        tgt = rom.ptr(p + 1)
        if tgt is None:
            raise ValueError('bad REPT pointer at %x' % (p + 1))
        return Insn(off, p + 5 - off, cmd, explicit, [cnt], tgt, p + 1 - off, kind='rept'), running
    if cmd == MEMACC:
        op, addr, data = d[p], d[p + 1], d[p + 2]
        if 6 <= op <= 17:
            tgt = rom.ptr(p + 3)
            if tgt is None:
                raise ValueError('bad MEMACC pointer at %x' % (p + 3))
            return Insn(off, p + 7 - off, cmd, explicit, [op, addr, data], tgt, p + 3 - off, kind='memacc_jump'), running
        return Insn(off, p + 3 - off, cmd, explicit, [op, addr, data], kind='memacc'), running
    if cmd in ONE_ARG:
        return Insn(off, p + 1 - off, cmd, explicit, [d[p]], kind='arg1'), running
    if cmd == PORT:
        return Insn(off, p + 2 - off, cmd, explicit, [d[p], d[p + 1]], kind='port'), running
    if cmd == XCMD:
        sub = d[p]
        if sub not in XCMD_ARGS:
            raise ValueError('bad XCMD sub %02x at %x' % (sub, p))
        n = XCMD_ARGS[sub]
        args = [sub] + list(d[p + 1:p + 1 + n])
        return Insn(off, p + 1 + n - off, cmd, explicit, args, kind='xcmd'), running
    if cmd == EOT:
        args = []
        if d[p] < 0x80:
            args.append(d[p]); p += 1
        return Insn(off, p - off, cmd, explicit, args, kind='eot'), running
    raise ValueError('unknown cmd %02x at %x' % (cmd, off))


def walk_track(rom, start, tolerant=False, simulate=False):
    """Control-flow decode of a track.  Returns dict off -> Insn of every reachable command.
    Running status is tracked per path (state = (pc, running, call stack)).

    tolerant: an undecodable command (e.g. a byte < 0x80 with no running status) becomes a 1-byte
              Insn of kind 'invalid' that ends the path (the engine stalls / misbehaves there).
    simulate: additionally track the selected VOICE and the current key and return
              (insns, uses) where uses = set of (voice, key) for every note/TIE that can play
              (voice None = the default tone before any VOICE command)."""
    insns = {}
    seen = set()
    uses = set()
    work = [(start, None, (), None, 0)]
    while work:
        pc, running, stack, voice, key = work.pop()
        while True:
            st = (pc, running, stack, voice, key) if simulate else (pc, running, stack)
            if st in seen:
                break
            seen.add(st)
            try:
                ins, running = decode_insn(rom, pc, running)
            except ValueError:
                if not tolerant:
                    raise
                insns[pc] = Insn(pc, 1, rom.d[pc], False, [rom.d[pc]], kind='invalid')
                break
            old = insns.get(pc)
            if old is not None and (old.size != ins.size or old.kind != ins.kind):
                raise ValueError('conflicting decode at %x' % pc)
            insns[pc] = ins
            k = ins.kind
            if simulate:
                if k == 'arg1' and ins.cmd == VOICE:
                    voice = ins.args[0]
                elif k == 'note':
                    if ins.args:
                        key = ins.args[0]
                    uses.add((voice, key))
                elif k == 'eot' and ins.args:
                    key = ins.args[0]
                elif k == 'xcmd' and ins.args[0] in (1, 2, 4, 5, 6, 7, 10, 11):
                    uses.add(('xcmd', tuple(ins.args)))
            if k == 'fine':
                break
            if k == 'goto':
                pc = ins.ptr
                continue
            if k == 'patt':
                if len(stack) < 3:
                    work.append((ins.ptr, running, stack + (pc + ins.size,), voice, key))
                break  # (pattern overflow -> ply_fine)
            if k == 'pend':
                if stack:
                    pc = stack[-1]; stack = stack[:-1]
                    continue
                pc += ins.size  # PEND at level 0 is a no-op
                continue
            if k in ('rept', 'memacc_jump'):
                work.append((ins.ptr, running, stack, voice, key))
                pc += ins.size
                continue
            pc += ins.size
    if simulate:
        return insns, uses
    return insns


def parse_header(rom, off):
    n, blocks, prio, rev = rom.d[off:off + 4]
    vg = rom.ptr(off + 4)
    tracks = [rom.ptr(off + 8 + 4 * i) for i in range(n)]
    return dict(off=off, ntracks=n, blocks=blocks, priority=prio, reverb=rev, voicegroup=vg,
                voicegroup_raw=rom.u32(off + 4), tracks=tracks, size=8 + 4 * n)


def song_table(rom, table_off, count):
    out = []
    for i in range(count):
        o = table_off + 8 * i
        out.append((rom.ptr(o), rom.u16(o + 4), rom.u16(o + 6)))
    return out


# ------------------------------------------------------------------ voices
TONE_DS = {0x00, 0x08, 0x10, 0x18, 0x20, 0x28, 0x30, 0x38}


def tone_at(rom, off):
    t = rom.d[off:off + 12]
    return dict(type=t[0], key=t[1], length=t[2], pan_sweep=t[3], wav=rom.u32(off + 4),
                attack=t[8], decay=t[9], sustain=t[10], release=t[11], raw=bytes(t))


def wave_data(rom, off):
    """DirectSound sample: header (type, status, freq, loopStart, size) + data."""
    typ, status, freq, loop, size = struct.unpack_from('<HHIII', rom.d, off)
    return dict(type=typ, status=status, freq=freq, loop=loop, size=size)


def wave_bytes(rom, off, compressed=False):
    w = wave_data(rom, off)
    if compressed or (w['type'] & 1):
        # DPCM-compressed: 33 bytes per 64 samples
        n = (w['size'] + 63) // 64 * 33
    else:
        n = w['size'] + 1  # engine reads one extra sample for interpolation
    return rom.d[off:off + 16 + n]
