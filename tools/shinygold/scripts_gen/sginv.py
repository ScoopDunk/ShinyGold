"""Inventory of vanilla event-script labels (shared files vs per-map files), their addresses, extents and kinds."""
import os, re, glob, bisect, functools, sys
sys.path.insert(0, '/home/claude/sgx')
from core import *

EV_START = 0x15f9b4            # event_scripts.o script_data start (file offset)
EV_END = 0x15f9b4 + 0x66f36    # end

LABEL_RE = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*)::?\s*(@.*)?$')


@functools.lru_cache(None)
def movement_macro_names():
    out = set(['step_end'])
    for line in open(os.path.join(VANILLA_DIR, 'asm/macros/movement.inc')):
        m = re.match(r'\s*create_movement_action\s+(\w+)', line)
        if m:
            out.add(m.group(1))
    return out


def classify_first_line(line):
    s = line.strip()
    if s.startswith('.string'):
        return 'text'
    if s.startswith('.braille'):
        return 'braille'
    w = s.split()[0] if s else ''
    if w in movement_macro_names():
        return 'movement'
    if w in ('.2byte', '.align', '.byte', '.4byte'):
        return 'data'
    if w in ('map_script', 'map_script_2'):
        return 'mapscripts'
    return 'script'


def parse_label_file(path):
    """Return list of (label, kind, lineno) in file order."""
    out = []
    lines = open(path, encoding='utf-8').read().split('\n')
    i = 0
    while i < len(lines):
        m = LABEL_RE.match(lines[i])
        if m and not lines[i].startswith(('\t', ' ', '.')):
            name = m.group(1)
            # find first content line
            kind = 'script'
            j = i + 1
            while j < len(lines):
                s = lines[j].strip()
                if not s or s.startswith('@'):
                    j += 1; continue
                if LABEL_RE.match(lines[j]) and not lines[j].startswith(('\t', ' ')):
                    j += 1; continue   # consecutive label -> same content
                kind = classify_first_line(lines[j])
                break
            out.append((name, kind, i))
        i += 1
    return out


def event_scripts_includes(path=os.path.join(VANILLA_DIR, 'data/event_scripts.s')):
    incs = []
    for line in open(path):
        m = re.match(r'\s*\.include\s+"([^"]+)"', line)
        if m:
            incs.append(m.group(1))
    return incs


class Inventory:
    def __init__(self, hack, van):
        self.hack = hack
        self.van = van
        by_addr, rng = vanilla_symbols()
        self.sym_addr = {}
        for a, s, n in rng:
            self.sym_addr.setdefault(n, a)
        # sorted addresses of all symbols within event_scripts region (for extents)
        self.ev_addrs = sorted(set(a for a, s, n in rng if EV_START <= a < EV_END))
        self.shared = {}      # name -> dict(addr, file, kind, end, changed)
        self.permap = {}      # name -> dict(addr, file, kind, mapdir)
        self.shared_files = []  # in include order
        incs = event_scripts_includes()
        # inline content of event_scripts.s is shared too
        files = [('data/event_scripts.s', 'shared')]
        for inc in incs:
            if inc.startswith('data/maps/'):
                files.append((inc, 'permap'))
            elif inc.startswith('data/scripts/') or inc.startswith('data/text/'):
                files.append((inc, 'shared'))
        for f, typ in files:
            p = os.path.join(VANILLA_DIR, f)
            for name, kind, ln in parse_label_file(p):
                a = self.sym_addr.get(name)
                if a is None:
                    continue
                if f == 'data/event_scripts.s' and kind in ('data',) and name.startswith(('gS', 'gSpecial')):
                    pass
                info = dict(name=name, addr=a, file=f, kind=kind, line=ln)
                if typ == 'shared':
                    if f not in self.shared_files:
                        self.shared_files.append(f)
                    self.shared[name] = info
                else:
                    info['mapdir'] = f.split('/')[2]
                    self.permap[name] = info
        for d in (self.shared, self.permap):
            for name, info in d.items():
                a = info['addr']
                i = bisect.bisect_right(self.ev_addrs, a)
                end = self.ev_addrs[i] if i < len(self.ev_addrs) else EV_END
                info['end'] = end
                info['changed'] = hack[a:end] != van[a:end]
        # address -> shared label name (first in file order)
        self.shared_at = {}
        for f in self.shared_files:
            for name, info in sorted(self.shared.items(), key=lambda kv: kv[1]['line']):
                if info['file'] == f:
                    self.shared_at.setdefault(info['addr'], name)
        self.permap_at = {}
        for name, info in self.permap.items():
            self.permap_at.setdefault(info['addr'], []).append(name)

    def file_labels(self, f):
        return sorted([i for i in self.shared.values() if i['file'] == f], key=lambda i: i['line'])
