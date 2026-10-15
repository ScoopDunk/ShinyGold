#!/usr/bin/env python3
"""Semantic comparison of every gSongTable song between two GBA ROMs (hack vs. built decomp).

For each song-table entry:
  * song-table fields (music player ms/me)
  * header: track count, block count, priority, reverb
  * every track: the control-flow-reachable command stream (running status / PATT / PEND / GOTO /
    REPT / MEMACC jumps followed exactly like the m4a engine), canonicalised so that embedded
    pointers are replaced by the canonical index of their target command -> layout independent
  * instruments: every (VOICE, key) pair that a note/TIE can actually be played with is resolved
    through the song's voicegroup exactly like ply_note does (keysplit table / drum kit lookup) and
    the resulting ToneData is compared field by field; DirectSound samples are compared by their
    WaveData header + all sample bytes, programmable waves by their 16 bytes, CGB tones raw.
  * additionally the 128-entry top level of every used voicegroup is compared for all VOICE
    numbers the song selects.
Prints every difference and a total; exit status 1 if any difference.

usage: check_songs.py HACK.gba BUILT.gba BUILT.elf
"""
import sys, os, subprocess, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from m4a import *

HACK_SONG_TABLE = 0x4a32cc  # hack keeps gSongTable at the vanilla address (verified unchanged)
NSONGS = 347


def elf_symbols(elf):
    out = {}
    for l in subprocess.check_output(['arm-none-eabi-nm', elf], text=True).splitlines():
        p = l.split()
        if len(p) == 3:
            out[p[2]] = int(p[0], 16)
    return out


def canon_track(rom, start):
    """Return (canonical list, uses) for a track."""
    insns, uses = walk_track(rom, start, tolerant=True, simulate=True)
    # deterministic DFS numbering from the start
    ids = {}
    order = []
    stack = [start]
    while stack:
        pc = stack.pop()
        if pc in ids or pc not in insns:
            continue
        ids[pc] = len(order)
        order.append(pc)
        ins = insns[pc]
        succ = []
        if ins.kind not in ('fine', 'goto', 'invalid'):
            succ.append(pc + ins.size)
        if ins.ptr is not None:
            succ.append(ins.ptr)
        for s in reversed(succ):
            stack.append(s)
    # any reachable insn not hit by the DFS (e.g. PEND fallthrough gaps) -> append in address order
    for pc in sorted(insns):
        if pc not in ids:
            ids[pc] = len(order)
            order.append(pc)
    out = []
    for pc in order:
        ins = insns[pc]
        b = bytearray(rom.d[pc:pc + ins.size])
        tgt = None
        if ins.ptr is not None:
            b[ins.ptr_at:ins.ptr_at + 4] = b'PPPP'
            tgt = ids[ins.ptr]
        nxt = ids.get(pc + ins.size) if ins.kind not in ('fine', 'goto', 'invalid') else None
        out.append((ins.kind, bytes(b), tgt, nxt))
    return out, uses


def sample_sig(rom, off):
    if off is None or off + 16 > rom.size:
        return ('badptr',)
    typ, status, freq, loop, size = struct.unpack_from('<HHIII', rom.d, off)
    if typ & 1:  # compressed (not used by songs)
        n = (size + 63) // 64 * 33
    else:
        n = size + 1
    return ('wave', typ, status, freq, loop, size, rom.d[off + 16:off + 16 + n])


def tone_sig(rom, toff, depth=0):
    """Semantic signature of a 12-byte ToneData at toff (pointers resolved)."""
    t = tone_at(rom, toff)
    typ = t['type']
    head = (typ, t['key'], t['length'], t['pan_sweep'])
    adsr = (t['attack'], t['decay'], t['sustain'], t['release'])
    if typ & 0xC0:
        return ('split' if typ & 0x40 else 'rhythm',) + head
    ct = typ & 7
    if ct == 0:  # DirectSound
        return ('ds',) + head + adsr + (sample_sig(rom, t['wav'] - ROM_BASE if rom.is_ptr(t['wav']) else None),)
    if ct == 3:  # programmable wave
        w = t['wav'] - ROM_BASE if rom.is_ptr(t['wav']) else None
        return ('pw',) + head + adsr + ((rom.d[w:w + 16]) if w is not None else ('badptr', t['wav']),)
    return ('cgb',) + head + adsr + (t['wav'],)


def resolve(rom, vg, voice, key):
    """Resolve (voice,key) through voicegroup vg like ply_voice + ply_note.
    Returns list of signatures (top tone, sub tone)."""
    top = vg + 12 * voice
    t = tone_at(rom, top)
    sig = [tone_sig(rom, top)]
    if t['type'] & 0xC0:
        sub = t['wav'] - ROM_BASE
        if t['type'] & 0x40:
            table = struct.unpack_from('<I', t['raw'], 8)[0] - ROM_BASE
            idx = rom.d[table + key]
        else:
            idx = key
        sig.append(('idx', idx))
        sig.append(tone_sig(rom, sub + 12 * idx))
    return sig


def compare(hack, built, song_table_h, song_table_b, names=None):
    nd = 0
    msgs = []
    th = song_table(hack, song_table_h, NSONGS)
    tb = song_table(built, song_table_b, NSONGS)
    stats = dict(tracks=0, insns=0, uses=0, samples=set())
    for i in range(NSONGS):
        nm = names[i] if names else str(i)
        d = []
        (hh, hms, hme), (bh, bms, bme) = th[i], tb[i]
        if (hms, hme) != (bms, bme):
            d.append('song table ms/me %s vs %s' % ((hms, hme), (bms, bme)))
        H = parse_header(hack, hh)
        B = parse_header(built, bh)
        for k in ('ntracks', 'blocks', 'priority', 'reverb'):
            if H[k] != B[k]:
                d.append('header %s %r vs %r' % (k, H[k], B[k]))
        uses_h, uses_b = set(), set()
        for ti, (a, b) in enumerate(zip(H['tracks'], B['tracks'])):
            ca, ua = canon_track(hack, a)
            cb, ub = canon_track(built, b)
            stats['tracks'] += 1
            stats['insns'] += len(ca)
            if ca != cb:
                # find first difference
                for j, (x, y) in enumerate(zip(ca, cb)):
                    if x != y:
                        d.append('track %d: first stream difference at canonical insn %d: %r vs %r' % (ti + 1, j, x, y))
                        break
                else:
                    d.append('track %d: stream length %d vs %d' % (ti + 1, len(ca), len(cb)))
            if ua != ub:
                d.append('track %d: voice/key usage differs (%d vs %d pairs)' % (ti + 1, len(ua), len(ub)))
            uses_h |= ua
            uses_b |= ub
        # instruments actually played
        vgh, vgb = H['voicegroup'], B['voicegroup']
        if vgh is None or vgb is None:
            if H['voicegroup_raw'] != B['voicegroup_raw']:
                d.append('voicegroup pointer %x vs %x' % (H['voicegroup_raw'], B['voicegroup_raw']))
        else:
            for u in sorted(uses_h & uses_b, key=str):
                if u[0] == 'xcmd':
                    continue  # tone edits are part of the compared stream
                v, k = u
                if v is None:
                    continue  # default tone (square, zeroed) - engine constant
                stats['uses'] += 1
                sh = resolve(hack, vgh, v, k)
                sb = resolve(built, vgb, v, k)
                if sh != sb:
                    d.append('instrument voice %d key %d differs: %r vs %r' % (v, k, short(sh), short(sb)))
                for s in sh:
                    if s[0] == 'ds':
                        stats['samples'].add(hash(s[-1]))
            # top-level entries of every selected voice
            for v in sorted({u[0] for u in uses_h | uses_b if u[0] not in (None, 'xcmd')}):
                if tone_sig(hack, vgh + 12 * v) != tone_sig(built, vgb + 12 * v):
                    d.append('voicegroup entry %d differs' % v)
        if d:
            nd += len(d)
            msgs.append('%3d %s:' % (i, nm))
            msgs.extend('      ' + x for x in d)
    return nd, msgs, stats


SOUND_PREFIXES = ('voicegroup', 'KeySplitTable', 'ProgrammableWaveData_', 'DirectSoundWaveData_', 'Cry_',
                  'gCryTable', 'gCgbScaleTable', 'gClockTable', 'gScaleTable', 'gFreqTable', 'gMPlayTable',
                  'gCgbFreqTable', 'gNoiseTable', 'gCgb3Vol', 'gPcmSamplesPerVBlankTable')
TONE_TABLES = ('voicegroup', 'gCryTable')


def vanilla_rom_symbols():
    out = {}
    for l in open('/home/claude/work/vanilla_syms.txt'):
        p = l.split()
        out.setdefault(p[-1], int(p[0], 16))
    return out


def keysplit_offsets():
    """KeySplitTableN symbols are defined as `. - K` (table indexed by MIDI key); return {name: K}."""
    import re
    out = {}
    for l in open('/home/claude/vanilla/sound/keysplit_tables.inc'):
        m = re.match(r'\s*\.set\s+(KeySplitTable\d+)\s*,\s*\.\s*-\s*(\d+)', l)
        if m:
            out[m.group(1)] = int(m.group(2))
    return out


def compare_sound_data(hack, built, hsyms, bsyms):
    """Structural comparison of all instrument/sample data (sound/voice_groups.inc, keysplit tables,
    programmable waves, every DirectSound sample incl. cries, cry tables, m4a tables).  The hack keeps
    this data at the vanilla addresses, so vanilla symbol addresses locate it in the hack ROM; the
    built ROM is located through its ELF.  Each object extends to the next symbol present in both
    symbol tables; pointers inside tone tables are compared symbolically (symbol + offset)."""
    import bisect
    ks = keysplit_offsets()
    lo_h, hi_h = hsyms['gScaleTable'], hsyms['mus_dummy']
    lo_b, hi_b = bsyms['gScaleTable'], bsyms['mus_dummy']

    def real(n, syms):  # address of the object's first real byte
        return syms[n] - ROM_BASE + ks.get(n, 0)

    common = [n for n in hsyms if n in bsyms and lo_h <= hsyms[n] <= hi_h and lo_b <= bsyms[n] <= hi_b]
    names = sorted((n for n in common if n.startswith(SOUND_PREFIXES)), key=lambda n: bsyms[n])
    missing = [n for n in hsyms if n.startswith(SOUND_PREFIXES) and lo_h <= hsyms[n] <= hi_h and n not in bsyms]
    diffs = []
    if missing:
        diffs.append('symbols missing from build: %s' % missing[:10])
    hl = sorted((real(n, hsyms), n) for n in common)
    bl = sorted((real(n, bsyms), n) for n in common)
    ha = [a for a, n in hl]
    ba = [a for a, n in bl]
    if [n for a, n in hl] != [n for a, n in bl]:
        diffs.append('sound data symbol order differs')

    def name_of(lst, addrs, ptr):
        i = bisect.bisect_right(addrs, ptr) - 1
        if i < 0:
            return ('raw', ptr)
        return (lst[i][1], ptr - lst[i][0])

    def extent(addrs, a):
        i = bisect.bisect_right(addrs, a)
        return addrs[i] - a if i < len(addrs) else 64

    nbytes = 0
    for n in names:
        if n == 'gSongTable':
            continue  # compared semantically song by song
        a_h, a_b = real(n, hsyms), real(n, bsyms)
        eh, eb = extent(ha, a_h), extent(ba, a_b)
        if eh != eb:
            diffs.append('%s: extent %d vs %d' % (n, eh, eb))
            continue
        nbytes += eh
        rh, rb = hack.d[a_h:a_h + eh], built.d[a_b:a_b + eb]
        if n.startswith(TONE_TABLES):
            for e in range(0, eh - 11, 12):
                th, tb = bytearray(rh[e:e + 12]), bytearray(rb[e:e + 12])
                ph, pb = [], []
                for fo in (4, 8):
                    vh = struct.unpack_from('<I', th, fo)[0]
                    vb = struct.unpack_from('<I', tb, fo)[0]
                    ph.append(name_of(hl, ha, vh - ROM_BASE) if hack.is_ptr(vh) else ('raw', vh))
                    pb.append(name_of(bl, ba, vb - ROM_BASE) if built.is_ptr(vb) else ('raw', vb))
                if th[:4] != tb[:4] or ph != pb:
                    diffs.append('%s entry %d: %s %s vs %s %s' % (n, e // 12, th.hex(), ph, tb.hex(), pb))
            tail = eh - (eh // 12) * 12
            if tail and rh[-tail:] != rb[-tail:]:
                diffs.append('%s: trailing bytes differ' % n)
        elif rh != rb:
            j = next(k for k in range(eh) if rh[k] != rb[k])
            diffs.append('%s: %d bytes differ, first at +0x%x' % (n, sum(x != y for x, y in zip(rh, rb)), j))
    return diffs, len(names), nbytes


def short(sig):
    out = []
    for s in sig:
        if isinstance(s, tuple) and s and s[0] == 'ds':
            w = s[-1]
            out.append(s[:-1] + ((w[:6] + ('<%d sample bytes, hash %x>' % (len(w[6]), hash(w[6]) & 0xffffffff),)) if len(w) > 6 else w,))
        else:
            out.append(s)
    return out


if __name__ == '__main__':
    import re
    hack = Rom(sys.argv[1])
    built = Rom(sys.argv[2])
    syms = elf_symbols(sys.argv[3])
    st_b = syms['gSongTable'] - ROM_BASE
    names = []
    for l in open('/home/claude/vanilla/sound/song_table.inc'):
        m = re.match(r'\s*song (\w+)', l)
        if m:
            names.append(m.group(1))
    nd, msgs, stats = compare(hack, built, HACK_SONG_TABLE, st_b, names)
    for m in msgs:
        print(m)
    sd, nsym, nbytes = compare_sound_data(hack, built, vanilla_rom_symbols(), syms)
    for m in sd:
        print('sound data: ' + m)
    print('sound data: %d symbols (voicegroups, keysplit tables, prog. waves, samples, cries, m4a tables), '
          '%d bytes compared, %d differences' % (nsym, nbytes, len(sd)))
    nd += len(sd)
    print('songs compared: %d, tracks: %d, reachable commands: %d, (voice,key) instrument resolutions: %d, '
          'distinct DirectSound samples compared: %d' % (NSONGS, stats['tracks'], stats['insns'], stats['uses'],
                                                        len(stats['samples'])))
    print('TOTAL DIFFERENCES: %d' % nd)
    sys.exit(1 if nd else 0)
