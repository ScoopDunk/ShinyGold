#!/usr/bin/env python3
"""Generate decomp-style song assembly (sound/songs/<song>.s) for the songs ShinyGold re-pointed.

Reads the hack ROM, walks each changed song header -> tracks, disassembles every track into
mid2agb-style `.byte` command lines with labels for all GOTO/PATT/REPT targets, and writes one
.s file per song.  Track byte streams are reproduced exactly (verified later by check_songs.py).
"""
import os, sys, re
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from m4a import *

HACK = '/home/claude/work/shinygold_patched.gba'
VANILLA_DIR = '/home/claude/vanilla'
SONG_TABLE = 0x4a32cc
NSONGS = 347

NOTE_NAMES = ['Cn', 'Cs', 'Dn', 'Ds', 'En', 'Fn', 'Fs', 'Gn', 'Gs', 'An', 'As', 'Bn']
WAIT_NAMES = {i: 'W%02d' % c for i, c in enumerate(CLOCK)}
NOTE_LEN = {i: 'N%02d' % c for i, c in enumerate(CLOCK) if i > 0}
CMD_NAMES = {PRIO: 'PRIO  ', TEMPO: 'TEMPO ', KEYSH: 'KEYSH ', VOICE: 'VOICE ', VOL: 'VOL   ', PAN: 'PAN   ',
             BEND: 'BEND  ', BENDR: 'BENDR ', LFOS: 'LFOS  ', LFODL: 'LFODL ', MOD: 'MOD   ', MODT: 'MODT  ',
             TUNE: 'TUNE  ', XCMD: 'XCMD  ', EOT: 'EOT   ', TIE: 'TIE   '}
MEMACC_OPS = ['mem_set', 'mem_add', 'mem_sub', 'mem_mem_set', 'mem_mem_add', 'mem_mem_sub', 'mem_beq',
              'mem_bne', 'mem_bhi', 'mem_bhs', 'mem_bls', 'mem_blo', 'mem_mem_beq', 'mem_mem_bne',
              'mem_mem_bhi', 'mem_mem_bhs', 'mem_mem_bls', 'mem_mem_blo']
XCMD_NAMES = {8: 'xIECV', 9: 'xIECL'}


def note_name(k):
    if k >= 24:
        return '%s%d' % (NOTE_NAMES[k % 12], k // 12 - 2)
    return '%sM%d' % (NOTE_NAMES[k % 12], 2 - k // 12)


def song_names():
    out = []
    for l in open(os.path.join(VANILLA_DIR, 'sound/song_table.inc')):
        m = re.match(r'\s*song (\w+)', l)
        if m:
            out.append(m.group(1))
    return out


def vanilla_voicegroup_names():
    """file offset -> voicegroupNNN (from the vanilla symbol list)."""
    out = {}
    for l in open('/home/claude/work/vanilla_syms.txt'):
        p = l.split()
        if p[-1].startswith('voicegroup'):
            out[int(p[0], 16) - ROM_BASE] = p[-1]
    return out


def linear_track(rom, start, reach):
    """Linear disassembly of a track from `start`.  Continues past the reachable span while the
    bytes still decode as commands up to the first FINE after the last reachable byte (mid2agb puts
    `_B2: Wxx FINE` after the loop GOTO).  Returns list of Insn."""
    last = max(o + reach[o].size for o in reach)
    out = []
    pc = start
    running = None
    while True:
        ins, running = decode_insn(rom, pc, running)
        out.append(ins)
        pc += ins.size
        if pc >= last:
            # trailing unreachable bytes: take them only if they form `[waits] FINE`
            tail = []
            q = pc
            ok = False
            r2 = running
            while q < last + 16:
                try:
                    t, r2 = decode_insn(rom, q, r2)
                except ValueError:
                    break
                tail.append(t)
                q += t.size
                if t.kind == 'fine':
                    ok = True
                    break
                if t.kind != 'wait':
                    break
            if ok:
                out.extend(tail)
            break
    # sanity: every reachable insn is a linear boundary with the same size
    lin = {i.off: i for i in out}
    for o, i in reach.items():
        if o not in lin or lin[o].size != i.size:
            raise ValueError('linear/flow mismatch at %x' % o)
    return out


def fmt_value(cmd, v, label):
    if cmd in (PAN, BEND, TUNE):
        if v < 0x80:
            return 'c_v%+d' % (v - 64)
        return '%d' % v
    if cmd == VOL:
        return '%d*%s_mvl/mxv' % (v, label) if v < 0x80 else '%d' % v
    if cmd == TEMPO:
        return '%d*%s_tbs/2' % (v * 2, label)
    if cmd == KEYSH:
        s = v - 256 if v >= 128 else v
        return '%s_key%+d' % (label, s)
    return '%d' % v


class Emitter:
    def __init__(self, label):
        self.label = label
        self.lines = []

    def w(self, s=''):
        self.lines.append(s)


def gen_song(rom, idx, name, vgnames, comment=None):
    hoff = song_table(rom, SONG_TABLE, NSONGS)[idx][0]
    hd = parse_header(rom, hoff)
    label = name
    reach_all = {}
    tracks = []
    for ti, t in enumerate(hd['tracks']):
        reach = walk_track(rom, t)
        lin = linear_track(rom, t, reach)
        tracks.append((t, reach, lin))
    # every pointer target must lie inside some track of this song
    all_lin = {}
    for t, reach, lin in tracks:
        for i in lin:
            all_lin[i.off] = i
    targets = {}
    for t, reach, lin in tracks:
        for i in lin:
            if i.ptr is not None:
                if i.ptr not in all_lin:
                    raise ValueError('%s: pointer target %x not an insn boundary' % (name, i.ptr))
                targets.setdefault(i.ptr, set()).add(i.kind)

    # label assignment
    labels = {}
    for ti, (t, reach, lin) in enumerate(tracks):
        tn = ti + 1
        labels[t] = '%s_%d' % (label, tn)
    for ti, (t, reach, lin) in enumerate(tracks):
        tn = ti + 1
        # tick positions for measure numbering
        pat_len = {}
        tick = 0
        ticks = {}
        nb = 0
        for i in lin:
            ticks[i.off] = tick
            if i.kind == 'wait':
                tick += CLOCK[i.cmd - 0x80]
        # PATT durations are ignored for numbering (patterns are defined inline at first use)
        used = set(labels.values())
        for i in lin:
            if i.off in targets and i.off not in labels:
                kinds = targets[i.off]
                if 'goto' in kinds:
                    nb += 1
                    cand = '%s_%d_B%d' % (label, tn, nb)
                else:
                    cand = '%s_%d_%03d' % (label, tn, ticks[i.off] // 96)
                base = cand
                k = 1
                while cand in used:
                    k += 1
                    cand = '%s_%d' % (base, k)
                labels[i.off] = cand
                used.add(cand)

    e = Emitter(label)
    e.w('\t.include "MPlayDef.s"')
    e.w()
    if comment:
        for c in comment:
            e.w(('@ ' + c).rstrip())
        e.w()
    vg = hd['voicegroup']
    e.w('\t.equ\t%s_grp, %s' % (label, vgnames[vg]))
    e.w('\t.equ\t%s_pri, %d' % (label, hd['priority']))
    if hd['reverb'] & 0x80:
        e.w('\t.equ\t%s_rev, reverb_set+%d' % (label, hd['reverb'] & 0x7f))
    else:
        e.w('\t.equ\t%s_rev, %d' % (label, hd['reverb']))
    e.w('\t.equ\t%s_mvl, 127' % label)
    e.w('\t.equ\t%s_key, 0' % label)
    e.w('\t.equ\t%s_tbs, 1' % label)
    e.w('\t.equ\t%s_exg, 0' % label)
    e.w('\t.equ\t%s_cmp, 1' % label)
    e.w()
    e.w('\t.section .rodata')
    e.w('\t.global\t%s' % label)
    e.w('\t.align\t2')

    for ti, (t, reach, lin) in enumerate(tracks):
        tn = ti + 1
        e.w()
        e.w('@**************** Track %d ****************@' % tn)
        e.w()
        tick = 0
        measure = -1
        for i in lin:
            if i.off == t:
                e.w('%s:' % labels[i.off])
            m = tick // 96
            if m != measure and i.kind != 'pend':
                measure = m
                e.w('@ %03d   ----------------------------------------' % m)
            if i.off in labels and i.off != t:
                e.w('%s:' % labels[i.off])
            emit_insn(e, i, labels, label)
            if i.kind == 'wait':
                tick += CLOCK[i.cmd - 0x80]
    e.w()
    e.w('@******************************************************@')
    e.w('\t.align\t2')
    e.w()
    e.w('%s:' % label)
    e.w('\t.byte\t%d\t@ NumTrks' % hd['ntracks'])
    e.w('\t.byte\t%d\t@ NumBlks' % hd['blocks'])
    e.w('\t.byte\t%s_pri\t@ Priority' % label)
    e.w('\t.byte\t%s_rev\t@ Reverb.' % label)
    e.w()
    e.w('\t.word\t%s_grp' % label)
    e.w()
    for ti, (t, reach, lin) in enumerate(tracks):
        e.w('\t.word\t%s' % labels[t])
    e.w()
    e.w('\t.end')
    return '\n'.join(e.lines) + '\n', hd, tracks


def emit_insn(e, i, labels, label):
    k = i.kind
    if k == 'wait':
        e.w('\t.byte\t%s' % WAIT_NAMES[i.cmd - 0x80])
        return
    if k == 'fine':
        if i.cmd == FINE and i.explicit:
            e.w('\t.byte\tFINE')
        else:
            e.w('\t.byte\t0x%02x' % i.cmd)
        return
    if k == 'pend':
        e.w('\t.byte\tPEND')
        return
    if k in ('goto', 'patt'):
        e.w('\t.byte\t%s' % ('GOTO' if k == 'goto' else 'PATT'))
        e.w('\t .word\t%s' % labels[i.ptr])
        return
    if k == 'rept':
        e.w('\t.byte\tREPT  , %d' % i.args[0])
        e.w('\t .word\t%s' % labels[i.ptr])
        return
    if k in ('memacc', 'memacc_jump'):
        op, addr, data = i.args
        e.w('\t.byte\tMEMACC, %s, 0x%02X, %d' % (MEMACC_OPS[op] if op < len(MEMACC_OPS) else str(op), addr, data))
        if k == 'memacc_jump':
            e.w('\t .word\t%s' % labels[i.ptr])
        return
    if k == 'port':
        assert i.explicit
        e.w('\t.byte\t0x%02x, %d, %d\t@ PORT' % (i.cmd, i.args[0], i.args[1]))
        return
    if k == 'arg1':
        val = fmt_value(i.cmd, i.args[0], label)
        if i.cmd in (PRIO, TEMPO, KEYSH):
            assert i.explicit
            e.w('\t.byte\t%s, %s' % (CMD_NAMES[i.cmd], val))
        elif i.explicit:
            e.w('\t.byte\t\t%s, %s' % (CMD_NAMES[i.cmd], val))
        else:
            e.w('\t.byte\t\t        %s' % val)
        return
    if k == 'xcmd':
        sub = i.args[0]
        subn = XCMD_NAMES.get(sub, '0x%02x' % sub)
        rest = ''.join(' , %d' % a for a in i.args[1:])
        if i.explicit:
            e.w('\t.byte\t\tXCMD  , %s%s' % (subn, rest))
        else:
            e.w('\t.byte\t\t        %s%s' % (subn, rest))
        return
    if k == 'eot':
        a = ''
        if i.args:
            a = ', ' + note_name(i.args[0])
        if i.explicit:
            e.w('\t.byte\t\tEOT   %s' % a)
        else:
            e.w('\t.byte\t\t        %s' % note_name(i.args[0]))
        return
    if k == 'note':
        parts = []
        if len(i.args) >= 1:
            parts.append(note_name(i.args[0]))
        if len(i.args) >= 2:
            parts.append('v%03d' % i.args[1])
        if len(i.args) >= 3:
            g = i.args[2]
            parts.append('gtp%d' % g if 1 <= g <= 3 else '%d' % g)
        op = 'TIE   ' if i.cmd == TIE else NOTE_LEN[i.cmd - TIE]
        if len(op) < 6:
            op = op + ' ' * (6 - len(op))
        if i.explicit:
            if parts:
                e.w('\t.byte\t\t%s, %s' % (op, ' , '.join(parts)))
            else:
                e.w('\t.byte\t\t%s' % op)
        else:
            e.w('\t.byte\t\t        %s' % ' , '.join(parts))
        return
    raise ValueError('cannot emit %r' % i)


# What each re-pointed song plays in ShinyGold.  "GSC" identifications were made by matching the
# tracks' melodies (transposition-invariant interval sequences, top voice of chords) against
# pret/pokecrystal's audio/music/*.asm and agree with where the hack uses the song.
DESCRIPTIONS = {
    'mus_vs_champion': ['Now a different battle theme (not identified: no melodic match in GSC or FRLG music).',
                        "Used through the hack's music-swap scripts (VAR 0x7030/0x7033) in place of",
                        'MUS_VS_TRAINER / MUS_VS_GYM_LEADER for a few special trainer battles.'],
    'mus_poke_tower': ['Now Gold/Silver/Crystal "Sprout Tower" (map music of the Sprout Tower maps).'],
    'mus_rival_exit': ['Now a battle theme (not identified: no melodic match in GSC or FRLG music).',
                       "Used through the hack's music-swap scripts in place of MUS_VS_TRAINER /",
                       'MUS_VS_GYM_LEADER, mostly for Team Rocket battles.'],
    'mus_poke_jump': ['Now Gold/Silver/Crystal "Goldenrod City" (map music of Goldenrod City).'],
    'mus_union_room': ['Now Gold/Silver/Crystal "Route 2" (Kanto route theme; map music of the Union Room',
                       'and Route 2).'],
    'mus_net_center': ['Now Gold/Silver/Crystal "Lighthouse" (map music of the Lighthouse and Mt. Silver).'],
    'mus_berry_pick': ['Now an unidentified theme (no melodic match in GSC or FRLG music); map music of',
                       'a Trick House interior and some unused maps.'],
    'mus_sevii_cave': ['Now Gold/Silver/Crystal "Dark Cave" (map music of Dark Cave, Ice Path, Slowpoke Well...).'],
    'mus_teachy_tv_show': ['Now an unidentified theme (no melodic match in GSC or FRLG music); map music of an',
                           'Ecruteak City interior.'],
    'mus_sevii_dungeon': ['Now Gold/Silver/Crystal "Victory Road" (map music of Victory Road and some caves).'],
    'mus_sevii_123': ['Now Gold/Silver/Crystal "Cherrygrove City" (also used for Mahogany Town, as in GSC).'],
    'mus_trainer_tower': ['Now a battle theme (not identified: no melodic match in GSC or FRLG music).',
                          "Used through the hack's music-swap scripts in place of MUS_VS_TRAINER for a set of",
                          "'PKMN TRAINER' battles; also the map music of a Lighthouse interior."],
    'mus_slow_pallet': ['Now a battle theme (not identified: no melodic match in GSC or FRLG music).',
                        "Used through the hack's music-swap scripts in place of MUS_VS_TRAINER for one",
                        "'PKMN TRAINER' battle."],
}

if __name__ == '__main__':
    rom = Rom(HACK)
    names = song_names()
    vgn = vanilla_voicegroup_names()
    outdir = sys.argv[1]
    which = sys.argv[2:]
    for nm in which:
        idx = names.index(nm)
        hoff = song_table(rom, SONG_TABLE, NSONGS)[idx][0]
        hd0 = parse_header(rom, hoff)
        van = parse_header(Rom('/home/claude/work/vanilla_fr10.gba'), hoff)
        lo = min(hd0['tracks'])
        comment = ['ShinyGold: ' + DESCRIPTIONS[nm][0]] + DESCRIPTIONS[nm][1:] + [
            '',
            'The hack edited this song header in place (keeping the song ID) to point at new track data',
            'it inserted at 0x%08X; voicegroup changed from %s to %s, %d -> %d tracks.' % (
                ROM_BASE + lo, vgn[van['voicegroup']], vgn[hd0['voicegroup']], van['ntracks'], hd0['ntracks']),
            "Disassembled from the hack ROM (no MIDI source exists).  Labels replace the hack's",
            "absolute pointers; the byte stream of every track is identical to the hack's.",
            '`_mvl` is 127, so `VOL , N*_mvl/mxv` emits N unchanged (edit _mvl to rescale volumes).',
        ]
        src, hd, tracks = gen_song(rom, idx, nm, vgn, comment)
        open(os.path.join(outdir, nm + '.s'), 'w').write(src)
        print(nm, hd['ntracks'], 'tracks', vgn[hd['voicegroup']])
