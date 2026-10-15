import sys, os, json, struct, subprocess, concurrent.futures as cf
sys.path.insert(0, '/home/claude/sgx')
from savefile import Save, checksum
from maps import load_map_headers, parse_events, load_layouts, parse_layout
from core import Rom
W = '/home/claude/work/sweep'
base = Save('/home/claude/emu/cmp/base.sav')
r = Rom()
groups, maps = load_map_headers(r)
names = json.load(open('/home/claude/work/map_names.json'))
ROMS = {'hack': '/home/claude/work/shinygold_patched.gba', 'dec': sys.argv[1] if len(sys.argv) > 1 else '/home/claude/shinygold/pokefirered.gba'}
only = set(sys.argv[2].split(',')) if len(sys.argv) > 2 else None
os.makedirs(W + '/saves', exist_ok=True); os.makedirs(W + '/shots', exist_ok=True)
jobs = []
for m in maps:
    key = '%d.%d' % (m.group, m.num)
    if only and key not in only: continue
    ev = parse_events(r, m.events)
    s = Save('/home/claude/emu/cmp/base.sav')
    slot = s.current_slot()
    sec = s.sectors(slot)
    o2 = sec[0][0]; o1 = sec[1][0]
    s.d[o2 + 9] |= 1
    for i in range(0x100): struct.pack_into('<H', s.d, o2 + 0x898 + 2 * i, 0)
    if ev['warps']:
        wid, x, y = 0, ev['warps'][0]['x'], ev['warps'][0]['y']
    else:
        wid, x, y = -1, 5, 5
    struct.pack_into('<bbbxhh', s.d, o1 + 0x0C, m.group, m.num, wid, x, y)
    for sid in (0, 1):
        o = sec[sid][0]
        struct.pack_into('<H', s.d, o + 0xFF6, checksum(s.d[o:o + 0x1000], 0xFF0 if sid else 0xF24))
    sp = '%s/saves/%s.sav' % (W, key)
    s.write(sp)
    for rn, rp in ROMS.items():
        scr = '%s/saves/%s_%s.txt' % (W, key, rn)
        open(scr, 'w').write('loadsav %s\n' % sp + 'wait 100\npress START 5\n' * 12 + 'wait 200\npress A 5\n' + 'w32 0x03005000 0x1234567\nwait 10\n' * 40 + 'shot %s/shots/%s_%s.png\nwait 120\nshot %s/shots/%s_%s_b.png\n' % (W, key, rn, W, key, rn))
        jobs.append((rp, scr))
def run(j):
    return subprocess.run(['/home/claude/emu/gbarun', j[0], j[1]], capture_output=True, text=True, timeout=120).returncode
with cf.ThreadPoolExecutor(3) as ex:
    rc = list(ex.map(run, jobs))
print(len(jobs), 'runs', sum(1 for x in rc if x))
