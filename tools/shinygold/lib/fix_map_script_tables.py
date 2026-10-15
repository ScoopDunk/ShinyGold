"""ShinyGold fix: clean up map-script headers/tables the hack wrote over older data.

  * header entries shadowed by an earlier entry of the same type are removed (the engine only uses the first);
  * entries of map-script tables that point at raw addresses (garbage decoded from the overwritten data) are
    removed - they either can never match or would jump into non-script data;
  * tables left empty, and the unused maps' tables that point into unrelated data, are removed with their
    header entry.
"""
import os, re, sys
DROP_WHOLE = {('Unused_PokemonLeague_ChampionsRoom', 'MAP_SCRIPT_ON_FRAME_TABLE'),
              ('Unused_FiveIsland_LostCave_Room13', 'MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE')}


def fix_file(m, p):
    s = open(p).read().split('\n')
    lab = {re.match(r'^(\w+)::', l).group(1): i for i, l in enumerate(s) if re.match(r'^(\w+)::', l)}
    hdr = lab.get(m + '_MapScripts')
    if hdr is None: return []
    drop = set(); notes = []
    seen = set()
    i = hdr + 1
    while not s[i].strip().startswith('.byte 0'):
        mm = re.match(r'\s*map_script (MAP_SCRIPT_\w+), (\w+)', s[i])
        if mm:
            t, ptr = mm.groups()
            if t in seen:
                drop.add(i); notes.append('shadowed %s %s' % (t, ptr))
            else:
                seen.add(t)
                if t.endswith('_TABLE') and ptr in lab:
                    j = lab[ptr] + 1; ents = []; raw = []
                    while not s[j].strip().startswith('.2byte 0'):
                        e = re.match(r'\s*map_script_2 (\w+), (\w+), (\w+)', s[j])
                        if e:
                            ents.append(j)
                            if e.group(3).startswith('0x'): raw.append(j)
                        j += 1
                    whole = (m, t) in DROP_WHOLE or len(raw) == len(ents)
                    if whole:
                        drop.add(i)
                        k = lab[ptr]
                        drop.update(range(k, j + 1))
                        if j + 1 < len(s) and s[j + 1].strip() == '': drop.add(j + 1)
                        notes.append('removed %s table %s (%d entries)' % (t, ptr, len(ents)))
                    elif raw:
                        drop.update(raw)
                        notes.append('removed %d garbage entries from %s' % (len(raw), ptr))
        i += 1
    if drop:
        s = [l for k, l in enumerate(s) if k not in drop]
        open(p, 'w').write('\n'.join(s))
    return notes


if __name__ == '__main__':
    root = sys.argv[1]
    for m in sorted(os.listdir(os.path.join(root, 'data/maps'))):
        p = os.path.join(root, 'data/maps', m, 'scripts.inc')
        if os.path.exists(p):
            n = fix_file(m, p)
            if n: print(m, '; '.join(n))
