"""Run the headless emulator on a test save and collect screenshots.

usage: emu.py <rom> <save> <outdir> "<cmd>; <cmd>; ..."

The save is continued from the title screen first (CONTINUE), then the commands run. Commands are gbarun commands
(wait N, press KEYS N, hold KEYS N, shot NAME, r8/r16/r32 ADDR, w8/w16/w32 ADDR VAL, dump ADDR LEN FILE, writesav FILE) plus:
  walk DIR N        walk N tiles (DIR = UP/DOWN/LEFT/RIGHT), 16 frames per tile, then a short wait
  a / b / start     press the button once and wait 30 frames
  text N            press A N times, 40 frames apart (advance N text boxes)
  shot NAME         screenshot to <outdir>/NAME.png
At the end <outdir>/montage.png contains all shots (2x, in order).
Make saves with mksave.py. gbarun: /home/claude/emu/gbarun.
"""
import sys, os, subprocess

GBARUN = '/home/claude/emu/gbarun'
CONTINUE = ['wait 100', 'press START 5'] * 12 + ['wait 200', 'press A 5', 'wait 400']


def main():
    rom, sav, out, cmds = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4]
    os.makedirs(out, exist_ok=True)
    lines = ['loadsav %s' % os.path.abspath(sav)] + CONTINUE
    shots = []
    for c in [x.strip() for x in cmds.replace('\n', ';').split(';') if x.strip()]:
        p = c.split()
        k = p[0].lower()
        if k == 'walk':
            n = int(p[2]) if len(p) > 2 else 1
            lines += ['hold %s %d' % (p[1].upper(), 16 * n), 'wait 12']
        elif k in ('a', 'b', 'start', 'select'):
            lines += ['press %s 4' % k.upper(), 'wait 30']
        elif k == 'text':
            for _ in range(int(p[1]) if len(p) > 1 else 1): lines += ['press A 4', 'wait 40']
        elif k == 'shot':
            path = os.path.join(out, p[1] + '.png'); shots.append(path)
            lines.append('shot %s' % path)
        else:
            lines.append(c)
    scr = os.path.join(out, 'run.txt')
    open(scr, 'w').write('\n'.join(lines) + '\n')
    r = subprocess.run([GBARUN, rom, scr], capture_output=True, text=True, timeout=600)
    sys.stdout.write(r.stdout)
    if r.returncode: sys.stderr.write(r.stderr)
    shots = [s for s in shots if os.path.exists(s)]
    if shots:
        from PIL import Image
        ims = [Image.open(s) for s in shots]
        cols = min(4, len(ims))
        rows = (len(ims) + cols - 1) // cols
        w, h = ims[0].size
        m = Image.new('RGB', (cols * (w + 4), rows * (h + 4)), (40, 40, 40))
        for i, im in enumerate(ims):
            m.paste(im, ((i % cols) * (w + 4), (i // cols) * (h + 4)))
        m.resize((m.width * 2, m.height * 2), Image.NEAREST).save(os.path.join(out, 'montage.png'))
        print('montage:', os.path.join(out, 'montage.png'))


if __name__ == '__main__':
    main()
