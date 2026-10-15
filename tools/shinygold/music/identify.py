#!/usr/bin/env python3
"""Identify the hack's new songs by melodic matching against Pokemon Crystal's music (pret/pokecrystal).

Pitch sequences (transposition-invariant interval n-grams) of every hack track are compared with
every GSC channel.  Output: best candidates per song with scores.
"""
import os, re, sys, glob
from collections import Counter
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from m4a import *

NOTES = {'C_': 0, 'C#': 1, 'D_': 2, 'D#': 3, 'E_': 4, 'F_': 5, 'F#': 6, 'G_': 7, 'G#': 8, 'A_': 9, 'A#': 10, 'B_': 11}
MAXN = 400
NG = 5


def parse_gsc(path):
    lines = [l.split(';')[0].rstrip() for l in open(path)]
    labels = {}
    cur_global = None
    body = []
    for l in lines:
        m = re.match(r'^(\.?\w+):', l.strip())
        if m:
            lab = m.group(1)
            if lab.startswith('.'):
                lab = cur_global + lab
            else:
                cur_global = lab
            labels[lab] = len(body)
            continue
        if l.strip():
            body.append((cur_global, l.strip()))
    chans = [l.split(',')[1].strip() for g, l in body if l.startswith('channel ') and ',' in l]
    out = {}
    for ch in chans:
        if ch not in labels:
            continue
        seq = []
        pc = labels[ch]
        octave = 4
        transpose = 0
        stack = []
        loops = {}
        steps = 0
        while pc < len(body) and len(seq) < MAXN and steps < 20000:
            steps += 1
            g, l = body[pc]
            parts = re.split(r'[\s,]+', l)
            op = parts[0]
            pc += 1

            def lab(x):
                return g + x if x.startswith('.') else x
            if op == 'octave':
                octave = int(parts[1])
            elif op == 'transpose':
                transpose = int(parts[1]) * 12 + int(parts[2])
            elif op == 'note':
                seq.append(octave * 12 + NOTES[parts[1]] + transpose)
            elif op == 'sound_call':
                stack.append(pc)
                pc = labels.get(lab(parts[1]), len(body))
            elif op == 'sound_ret':
                if not stack:
                    break
                pc = stack.pop()
            elif op == 'sound_loop':
                cnt = int(parts[1])
                key = pc
                if cnt == 0:
                    break  # infinite loop -> end of first pass
                n = loops.get(key, cnt) - 1
                if n > 0:
                    loops[key] = n
                    pc = labels.get(lab(parts[2]), len(body))
                else:
                    loops.pop(key, None)
            elif op == 'sound_jump':
                break
        out[ch] = seq
    return out


def hack_track_seq(rom, start):
    seq = []
    pc = start
    running = None
    stack = []
    key = 60
    chord = []
    steps = 0
    while len(seq) < MAXN and steps < 20000:
        steps += 1
        ins, running = decode_insn(rom, pc, running)
        k = ins.kind
        if k == 'note':
            if ins.args:
                key = ins.args[0]
            chord.append(key)
        if k == 'wait' and ins.cmd > 0x80 and chord:
            seq.append(max(chord))   # skyline: top note of each simultaneous group
            chord = []
        if k in ('fine', 'goto'):
            break
        if k == 'patt':
            stack.append(pc + ins.size)
            pc = ins.ptr
            continue
        if k == 'pend' and stack:
            pc = stack.pop()
            continue
        pc += ins.size
    return seq


def grams(seq):
    seq = [p for i, p in enumerate(seq) if i == 0 or p != seq[i - 1]]   # collapse repeated notes
    iv = [((b - a + 5) % 12) - 5 for a, b in zip(seq, seq[1:])]         # octave-equivalent intervals
    out = set()
    for i in range(len(iv) - NG + 1):
        g = tuple(iv[i:i + NG])
        if len(set(g)) >= 3:      # ignore trivial (repeated-note / two-value) figures
            out.add(g)
    return Counter({g: 1 for g in out})


def score(a, b):
    if not a or not b:
        return 0.0
    return len(set(a) & set(b)) / len(a)


if __name__ == '__main__':
    import gen_songs
    rom = Rom('/home/claude/work/shinygold_patched.gba')
    names = gen_songs.song_names()
    gsc = {}
    for p in sorted(glob.glob('/home/claude/work/music/ext/pokecrystal/audio/music/*.asm')):
        nm = os.path.basename(p)[:-4]
        try:
            chans = parse_gsc(p)
        except Exception as e:
            print('skip', nm, e)
            continue
        gsc[nm] = [grams(s) for c, s in chans.items() if len(s) > NG]
    table = song_table(rom, 0x4a32cc, 347)
    for nm in sys.argv[1:]:
        idx = names.index(nm)
        hd = parse_header(rom, table[idx][0])
        tracks = [grams(hack_track_seq(rom, t)) for t in hd['tracks']]
        res = []
        for g, chs in gsc.items():
            tot = 0
            for tg in tracks:
                if sum(tg.values()) < 8:
                    continue
                tot += max([score(tg, c) for c in chs] + [0])
            res.append((tot, g))
        res.sort(reverse=True)
        print('%-20s' % nm, '  '.join('%s %.2f' % (g, s) for s, g in res[:4]))
