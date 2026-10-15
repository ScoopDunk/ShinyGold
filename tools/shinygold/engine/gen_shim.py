"""Generate engine/shim/sg_shim.h: LOCAL TEST SHIM (not committed) that defines the cross-worker constants
(hack MAP_ ids, HEAL_LOCATION_ ids, TRAINER_ ids from names.py) so the engine branch builds standalone:
    make -j2 CPP="arm-none-eabi-cpp -include /home/claude/work/engine/shim/sg_shim.h"
Names that already exist in vanilla headers keep their vanilla values (MAP_PALLET_TOWN/MAP_ROUTE2 collide!)."""
import json, re, sys
sys.path.insert(0, '/home/claude/sgx')
from names import heal_location_const, trainer_const
mn = json.load(open('/home/claude/work/map_names.json'))
van = set(re.findall(r'#define (MAP_\w+)', open('/home/claude/wt/engine/include/constants/map_groups.h').read()))
vanheal = open('/home/claude/vanilla/include/constants/heal_locations.h').read()
out = ['// LOCAL TEST SHIM ONLY - not committed.', '#ifndef SG_SHIM_H', '#define SG_SHIM_H']
for key, e in mn.items():
    if e['id'] in van: continue
    g, n = map(int, key.split('.'))
    out.append('#define %s ((%d << 8) | %d)' % (e['id'], g, n))
for v in range(1, 25):
    c = heal_location_const(v)
    if not re.search(r'\b%s\b' % c, vanheal):
        out.append('#define %s %d' % (c, v))
out.append('#define %s %d' % (trainer_const(0x1b6), 0x1b6))
out.append('#endif')
open('/home/claude/work/engine/shim/sg_shim.h', 'w').write('\n'.join(out) + '\n')
