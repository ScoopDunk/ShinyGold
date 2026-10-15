#!/usr/bin/env python3
"""ShinyGold event-script disassembler / generator.

    python3 sggen.py WORKTREE [--json-dir DIR]

Regenerates, inside WORKTREE (a pokefirered checkout):
  data/maps/<Name>/scripts.inc, data/maps/<Name>/text.inc     (one per hack map, names from map_names.json)
  data/scripts/*.inc, data/text/*.inc                         (vanilla shared files; labels the hack modified in
                                                               place get the hack's definition)
  data/scripts/shinygold_shared.inc, data/text/shinygold_shared.inc   (new hack content reached only from shared code)
  data/scripts/shinygold_compat.inc, data/text/shinygold_compat.inc   (vanilla per-map labels still referenced by C /
                                                               shared scripts, re-emitted from the hack ROM)
  data/event_scripts.s                                        (include list)
and in JSON-DIR (default /home/claude/work/scripts): script_labels.json, natives.json, ram_refs.json,
map_scripts_report.json, chunk_index.json (used by verify.py), coverage data.
Templates for shared files are always taken from the pristine vanilla tree, so re-running is idempotent.
"""
import sys, os, re, json, bisect, collections, argparse, array, glob, shutil
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, '/home/claude/sgx')
from core import *
import names as N
from maps import load_map_headers, parse_events, parse_map_scripts
from sgdecode import *
from sgconst import *
from sginv import Inventory, EV_START, EV_END, LABEL_RE

ROMBASE = 0x08000000
OWN_SHREPL = -1
OWN_COMPAT = 1000000
OWN_SHNEW = 1000001
NULL_SCRIPT_PTRS = {0x08000000}   # AdvanceMap "no script" placeholder (ROM start) -> treated as NULL

DATA_KINDS = ('text', 'braille', 'movement', 'mart', 'decor', 'mapscripts', 'mstable')
KIND_WORD = {'script': 'EventScript', 'text': 'Text', 'braille': 'Text', 'movement': 'Movement', 'mart': 'Items',
             'decor': 'Decor', 'mapscripts': 'MapScripts', 'mstable': 'MapScriptTable'}
MS_TYPES = {1: 'MAP_SCRIPT_ON_LOAD', 2: 'MAP_SCRIPT_ON_FRAME_TABLE', 3: 'MAP_SCRIPT_ON_TRANSITION',
            4: 'MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE', 5: 'MAP_SCRIPT_ON_RESUME', 6: 'MAP_SCRIPT_ON_DIVE_WARP',
            7: 'MAP_SCRIPT_ON_RETURN_TO_FIELD'}
MS_NAMES = {1: 'OnLoad', 2: 'OnFrame', 3: 'OnTransition', 4: 'OnWarp', 5: 'OnResume', 6: 'OnDive',
            7: 'OnReturnToField'}
COND_SUFFIX = {0: 'lt', 1: 'eq', 2: 'gt', 3: 'le', 4: 'ge', 5: 'ne'}


def camel_from_const(c, prefix):
    s = c[len(prefix):] if c.startswith(prefix) else c
    parts = [p for p in s.split('_') if p]
    out = ''
    for p in parts:
        out += p if p.isdigit() else p[0].upper() + p[1:].lower()
    return out or 'X'


class DataItem:
    __slots__ = ('start', 'end', 'kind', 'owner', 'order', 'extra')

    def __init__(self, start, end, kind, owner, order, extra=None):
        self.start = start; self.end = end; self.kind = kind; self.owner = owner; self.order = order
        self.extra = extra


class Dup:
    """A block decoded independently because it overlaps primary data at a different alignment."""
    def __init__(self, addr, kind, owner, order):
        self.addr = addr; self.kind = kind; self.owner = owner; self.order = order
        self.instrs = None; self.end = None; self.name = None


class Gen:
    def __init__(self, wt, json_dir):
        self.wt = wt
        self.json_dir = json_dir
        self.rom = Rom()
        self.d = self.rom.d
        self.vd = open(VANILLA_ROM, 'rb').read()
        self.inv = Inventory(self.d, self.vd)
        self.mapnames = json.load(open(N.MAP_NAMES_JSON))
        groups, maps = load_map_headers(self.rom)
        self.maps = maps
        self.map_index = {(m.group, m.num): i for i, m in enumerate(maps)}
        self.map_name = {i: self.mapnames['%d.%d' % (m.group, m.num)]['name'] for i, m in enumerate(maps)}
        # discovery state
        self.ins = {}                  # addr -> Instr (primary)
        self.ins_owner = {}
        self.ins_order = {}
        self.items = {}                # start -> DataItem
        self.occ = array.array('i', bytes(4 * len(self.d)))  # start+1 of covering primary item
        self.dups = {}                 # (addr, kind) -> Dup
        self.entries = {}              # (addr, kind) -> dict(names=[], root=(prefix, short), role, order, owner)
        self.ext = {}                  # (addr, kind) -> external vanilla label name
        self.queue = collections.deque()
        self.order = 0
        self.problems = collections.defaultdict(list)   # owner-key -> list of strings
        self.shrepl_roots = set()
        self.natives = collections.defaultdict(set)
        self.rams = collections.defaultdict(set)
        self.ctx_of_entry = {}
        self.map_entry_ptrs = {}       # raw pointer -> (kind, map index)
        self.used_names = set()
        self.vanilla_c_syms = None

    # ------------------------------------------------------------------ helpers
    def owner_name(self, o):
        if o == OWN_SHREPL: return 'shared-modified'
        if o == OWN_COMPAT: return 'compat'
        if o == OWN_SHNEW: return 'shared-new'
        return self.map_name[o]

    def problem(self, ctx, msg):
        self.problems[ctx].append(msg)

    def next_order(self):
        self.order += 1
        return self.order

    def valid_rom(self, p):
        return ROMBASE <= p < ROMBASE + len(self.d)

    # ------------------------------------------------------------------ requests
    def request(self, ptr, kind, ctx, root, name=None, role=None, src=None):
        """Request a label for ROM pointer `ptr` of `kind`. Decoding is queued."""
        if ptr == 0:
            return
        if not self.valid_rom(ptr):
            self.problem(ctx, 'invalid %s pointer 0x%08X%s' % (kind, ptr, (' from 0x%08X' % src) if src else ''))
            return
        a = ptr - ROMBASE
        key = (a, kind)
        # vanilla shared label?
        sh = self.inv.shared_at.get(a)
        if sh and ctx not in (OWN_COMPAT, OWN_SHREPL) and kind != 'mapscripts':
            info = self.inv.shared[sh]
            if self.kind_compatible(info['kind'], kind):
                self.ext[key] = sh
                if info['changed']:
                    self.shrepl_roots.add(sh)
                return
        if name is None and kind in ('text', 'braille', 'movement', 'mart') and a < 0x71A000 and not (EV_START <= a < EV_END):
            n = self.c_symbol_at(a)
            if n:
                self.ext[key] = n
                return
        e = self.entries.get(key)
        if e is None:
            e = dict(names=[], root=root, role=role, order=self.next_order(), owner=ctx)
            self.entries[key] = e
            self.queue.append((a, kind, ctx, root))
        if name:
            vanilla = ctx in (OWN_COMPAT, OWN_SHREPL)
            # other maps reusing an already-named script do not add aliases (only <Map>_MapScripts must exist)
            if vanilla or kind == 'mapscripts' or (not any(not v for n, v in e['names']) and e['owner'] == ctx):
                if (name, vanilla) not in e['names']:
                    e['names'].append((name, vanilla))

    def kind_compatible(self, vkind, kind):
        if vkind == kind: return True
        if vkind in ('text', 'braille') and kind in ('text', 'braille'): return vkind == kind
        if vkind == 'data' and kind in ('mart', 'decor'): return True
        return False

    def c_symbol_at(self, a):
        if self.vanilla_c_syms is None:
            by_addr, rng = vanilla_symbols()
            self.vanilla_c_syms = {}
            for addr, lst in by_addr.items():
                for n, s, t in lst:
                    if t in 'DR' and not n.startswith('$') and not n.startswith('.'):
                        self.vanilla_c_syms.setdefault(addr, n)
        return self.vanilla_c_syms.get(a)

    # ------------------------------------------------------------------ discovery
    def run_queue(self):
        while self.queue:
            a, kind, ctx, root = self.queue.popleft()
            if kind == 'script':
                self.decode_script(a, ctx, root)
            elif kind == 'mapscripts':
                self.decode_mapscripts(a, ctx, root)
            elif kind == 'mstable':
                self.decode_mstable(a, ctx, root)
            else:
                self.decode_data(a, kind, ctx, root)

    def child_ctx(self, ctx):
        return OWN_SHNEW if ctx == OWN_SHREPL else ctx

    def queue_refs(self, I, ctx, root):
        c = self.child_ctx(ctx)
        for a in I.args:
            k, v = a[0], a[1]
            role = a[2] if len(a) > 2 else None
            if k in PTR_KINDS:
                if v in NULL_SCRIPT_PTRS and k == 'script':
                    self.problem(ctx, 'script pointer 0x08000000 (ROM start) at 0x%08X' % (I.addr + ROMBASE))
                    continue
                if 0x02000000 <= v < 0x04000000:
                    self.rams[v].add(I.addr)
                    continue
                self.request(v, k, c, root, role=role, src=I.addr + ROMBASE)
            elif k == 'loadword':
                if a is I.args[1] and I.args[0][1] == 0 and self.valid_rom(v):
                    self.request(v, 'text', c, root, src=I.addr + ROMBASE)
                elif 0x02000000 <= v < 0x04000000:
                    self.rams[v].add(I.addr)
            elif k == 'native':
                self.natives[v].add(I.addr)
            elif k == 'ram':
                if self.valid_rom(v):
                    pass
                else:
                    self.rams[v].add(I.addr)

    def decode_script(self, a, ctx, root):
        if a in self.ins:
            return
        if self.occ[a]:
            self.make_dup(a, 'script', ctx, root, 'entry inside other data')
            return
        tent = []
        p = a
        while True:
            if p in self.ins:
                break
            if p >= len(self.d) or self.occ[p]:
                return self.make_dup(a, 'script', ctx, root, 'runs into other data at 0x%08X' % (p + ROMBASE))
            I = decode_instr(self.d, p)
            if I is None:
                return self.make_dup(a, 'script', ctx, root, 'runs off ROM')
            for k in range(p + 1, p + I.size):
                if self.occ[k]:
                    return self.make_dup(a, 'script', ctx, root, 'overlaps other data at 0x%08X' % (k + ROMBASE))
            tent.append(I)
            if I.term:
                break
            p += I.size
            if len(tent) > 4000:
                return self.make_dup(a, 'script', ctx, root, 'no terminator')
        for I in tent:
            self.ins[I.addr] = I
            self.ins_owner[I.addr] = ctx
            self.ins_order[I.addr] = self.next_order()
            for k in range(I.addr, I.addr + I.size):
                self.occ[k] = I.addr + 1
            if I.raw and I.name is None:
                if I.op == 0xFF:
                    self.problem(ctx, 'note: script runs into 0xFF (stops) at 0x%08X' % (I.addr + ROMBASE))
                else:
                    self.problem(ctx, 'invalid script opcode 0x%02X at 0x%08X' % (I.op, I.addr + ROMBASE))
        for I in tent:
            self.queue_refs(I, ctx, root)

    def data_end(self, a, kind):
        if kind in ('text', 'braille'):
            return text_end(self.d, a)
        if kind == 'movement':
            return movement_end(self.d, a)
        if kind in ('mart', 'decor'):
            return u16list_end(self.d, a)
        return None

    def decode_data(self, a, kind, ctx, root):
        end = self.data_end(a, kind)
        if end is None:
            self.problem(ctx, 'unterminated %s at 0x%08X' % (kind, a + ROMBASE))
            self.entries[(a, kind)]['bad'] = True
            return
        if self.occ[a]:
            s = self.occ[a] - 1
            it = self.items.get(s)
            if it and it.kind == kind and it.end == end and (kind not in ('mart', 'decor') or (a - s) % 2 == 0):
                return   # same item, or suffix of it: internal label
            return self.make_dup(a, kind, ctx, root, 'inside other data')
        absorbed = []
        for k in range(a, end):
            if self.occ[k]:
                s = self.occ[k] - 1
                it = self.items.get(s)
                if it and it.kind == kind and it.end == end and s == k and (kind not in ('mart', 'decor') or (s - a) % 2 == 0):
                    absorbed.append(it)
                    break
                return self.make_dup(a, kind, ctx, root, 'overlaps other data at 0x%08X' % (k + ROMBASE))
        owner = ctx
        order = self.next_order()
        for it in absorbed:
            owner = min(owner, it.owner)
            order = min(order, it.order)
            del self.items[it.start]
        it = DataItem(a, end, kind, owner, order)
        self.items[a] = it
        for k in range(a, end):
            self.occ[k] = a + 1
        if kind == 'mart' and a % 2:
            self.problem(ctx, 'misaligned mart list at 0x%08X' % (a + ROMBASE))

    def parse_header(self, a):
        """Engine view of a map-script header: 5-byte entries until type 0."""
        out = []
        p = a
        while p < len(self.d):
            t = self.d[p]
            if t == 0:
                return out, p + 1
            if p + 5 > len(self.d):
                return out, None
            out.append((p, t, int.from_bytes(self.d[p + 1:p + 5], 'little')))
            p += 5
            if len(out) > 64:
                return out, None
        return out, None

    def decode_mapscripts(self, a, ctx, root):
        if a in self.items and self.items[a].kind == 'mapscripts':
            return
        ents, end = self.parse_header(a)
        if end is None:
            self.problem(ctx, 'unterminated map script header at 0x%08X' % (a + ROMBASE))
            self.entries[(a, 'mapscripts')]['bad'] = True
            return
        if any(self.occ[k] for k in range(a, end)):
            self.problem(ctx, 'map script header at 0x%08X overlaps other data' % (a + ROMBASE))
            self.make_dup(a, 'mapscripts', ctx, root, 'overlap')
            return
        it = DataItem(a, end, 'mapscripts', ctx, self.next_order(), extra=ents)
        self.items[a] = it
        for k in range(a, end):
            self.occ[k] = a + 1
        self.header_refs(ents, ctx, root)

    def header_refs(self, ents, ctx, root):
        prefix = root[0]
        seen = collections.Counter()
        for p, t, ptr in ents:
            if t in MS_TYPES:
                seen[t] += 1
                if seen[t] > 1:
                    self.problem(ctx, 'map script header entry type %d at 0x%08X is shadowed by an earlier one (dead)' % (t, p + ROMBASE))
                    continue
                nm = '%s_%s' % (prefix, MS_NAMES[t]) + ('' if seen[t] == 1 else str(seen[t]))
                if ptr in NULL_SCRIPT_PTRS or ptr == 0:
                    self.problem(ctx, 'map script type %d has NULL/ROM-start pointer 0x%08X' % (t, ptr))
                    continue
                if t in (2, 4):
                    self.request(ptr, 'mstable', ctx, (prefix, MS_NAMES[t], root[2]), name=nm if root[2] else None)
                else:
                    self.request(ptr, 'script', ctx, (prefix, MS_NAMES[t], root[2]), name=nm if root[2] else None)

    def parse_mstable(self, a):
        """Entries of a map script table as the engine reads them (stops at a 0 var). -> (entries, end) or (.., None)"""
        ents = []
        p = a
        while p + 2 <= len(self.d):
            var = self.d[p] | self.d[p + 1] << 8
            if var == 0:
                return ents, p + 2
            if p + 8 > len(self.d) or len(ents) >= 256:
                return ents, None
            ents.append((p, var, self.d[p + 2] | self.d[p + 3] << 8, int.from_bytes(self.d[p + 4:p + 8], 'little')))
            p += 8
        return ents, None

    def decode_mstable(self, a, ctx, root):
        if a in self.items and self.items[a].kind == 'mstable':
            return
        ents, end = self.parse_mstable(a)
        if end is None:
            self.problem(ctx, 'bad map script table at 0x%08X' % (a + ROMBASE))
            self.entries[(a, 'mstable')]['bad'] = True
            return
        if any(self.occ[k] for k in range(a, end)):
            self.make_dup(a, 'mstable', ctx, root, 'overlap')
            return
        it = DataItem(a, end, 'mstable', ctx, self.next_order(), extra=ents)
        self.items[a] = it
        for k in range(a, end):
            self.occ[k] = a + 1
        self.mstable_refs(a, ents, ctx, root)

    def mstable_refs(self, a, ents, ctx, root):
        prefix, short = root[0], root[1]
        word = 'FrameScene' if short == 'OnFrame' else 'WarpScene' if short == 'OnWarp' else short
        for i, (q, var, val, sp) in enumerate(ents):
            if not self.mstable_entry_live(var, val):
                if self.valid_rom(sp):
                    self.problem(ctx, 'map script table 0x%08X entry %d can never match (var 0x%X vs 0x%X); pointer not followed'
                                 % (a + ROMBASE, i, var, val))
                continue
            if sp in NULL_SCRIPT_PTRS or sp == 0:
                self.problem(ctx, 'map script table entry with NULL/ROM-start script')
                continue
            nm = '%s_EventScript_%s%s' % (prefix, word, '' if len(ents) == 1 else str(i + 1))
            self.request(sp, 'script', ctx, (prefix, '%s%s' % (word, '' if len(ents) == 1 else str(i + 1)), root[2]),
                         name=nm if root[2] else None)

    @staticmethod
    def mstable_entry_live(var, val):
        # VarGet(x) returns x itself for x < VARS_START; anything >= 0x4000 reads memory (even out of range)
        return var >= 0x4000 or val >= 0x4000 or var == val

    def make_dup(self, a, kind, ctx, root, why):
        key = (a, kind)
        if key in self.dups:
            return
        D = Dup(a, kind, ctx, self.entries[key]['order'] if key in self.entries else self.next_order())
        self.dups[key] = D
        self.problem(ctx, 'duplicated %s block at 0x%08X (%s)' % (kind, a + ROMBASE, why))
        if kind == 'script':
            lst = []
            p = a
            while True:
                I = decode_instr(self.d, p)
                if I is None:
                    break
                lst.append(I)
                if I.term or len(lst) > 4000:
                    break
                p += I.size
            D.instrs = lst
            D.end = p + (lst[-1].size if lst else 0)
            for I in lst:
                self.queue_refs(I, ctx, root)
        elif kind == 'mapscripts':
            ents, end = self.parse_header(a)
            D.instrs = ents; D.end = end
            self.header_refs(ents, ctx, root)
        elif kind == 'mstable':
            # a map script table overlapping other data (the hack points headers into the middle of old tables)
            ents, end = self.parse_mstable(a)
            if end is None:
                del self.dups[key]
                self.entries[key]['bad'] = True
                return
            D.instrs = ents; D.end = end
            self.mstable_refs(a, ents, ctx, root)
        else:
            D.end = self.data_end(a, kind)
            if D.end is None:
                del self.dups[key]
                self.entries[key]['bad'] = True

    # ------------------------------------------------------------------ C references repointed by the hack
    MAPDATA_RANGES = [(0x2D50F4, 0x2D50F4 + 0x7DDF8), (0x3AE094, 0x3AE094 + 0x1134C)]  # vanilla maps.o / map_events.o

    def compute_moved_labels(self):
        """Vanilla event-script labels whose every reference from vanilla code/data (outside event scripts and map
        data) was repointed by the hack to one new address X: the label is then defined at X ("moved"), so the C code
        keeps working unchanged.  Labels with only some references repointed are reported."""
        import struct
        by_val = {}
        for d in (self.inv.shared, self.inv.permap):
            for n, i in d.items():
                by_val.setdefault(i['addr'] + ROMBASE, []).append(n)
        excl = [(EV_START, EV_END)] + self.MAPDATA_RANGES
        refs = collections.defaultdict(list)
        vd, d = self.vd, self.d
        for o in range(0, 0x71A000, 4):
            if any(a <= o < b for a, b in excl):
                continue
            val = struct.unpack_from('<I', vd, o)[0]
            if val in by_val:
                refs[val].append((o, struct.unpack_from('<I', d, o)[0]))
        self.moved = {}
        self.partially_repointed = {}
        for val, lst in refs.items():
            new = set(nv for o, nv in lst)
            if new == {val}:
                continue
            names = by_val[val]
            if len(new) == 1 and self.valid_rom(next(iter(new))):
                for n in names:
                    if n in self.inv.shared or n in self.compat:
                        self.moved[n] = next(iter(new))
            else:
                for n in names:
                    self.partially_repointed[n] = sorted('0x%08X' % x for x in new)
        for n in self.moved:
            if n in self.inv.shared:
                a = self.inv.shared[n]['addr']
                if self.inv.shared_at.get(a) == n:
                    del self.inv.shared_at[a]

    # ------------------------------------------------------------------ entry points
    def discover(self):
        # 1) maps in group/num order
        self.map_events = {}
        for i, m in enumerate(self.maps):
            P = self.map_name[i]
            ctx = i
            ev = parse_events(self.rom, m.events)
            self.map_events[i] = ev
            hp = m.scripts + ROMBASE if m.scripts is not None else 0
            if hp in NULL_SCRIPT_PTRS:
                self.problem(ctx, 'map script header pointer is 0x08000000 (ROM start); treated as empty')
            elif hp:
                self.request(hp, 'mapscripts', ctx, (P, 'MapScripts', True), name='%s_MapScripts' % P)
            self.run_queue()
            # objects
            used = collections.Counter()
            for o in ev['objects']:
                if o['kind'] == 1:
                    continue
                sp = o['script']
                if sp == 0:
                    continue
                if sp in NULL_SCRIPT_PTRS:
                    self.problem(ctx, 'object local id %d script is 0x08000000 (ROM start) -> NULL' % o['local_id'])
                    continue
                short = self.object_short_name(o)
                used[short] += 1
                if used[short] > 1:
                    short = '%s%d' % (short, used[short])
                self.request(sp, 'script', ctx, (P, short, True), name='%s_EventScript_%s' % (P, short))
                self.run_queue()
            for k, c in enumerate(ev['coords']):
                sp = c['script']
                if sp == 0:
                    continue
                if sp in NULL_SCRIPT_PTRS:
                    self.problem(ctx, 'coord event %d script is 0x08000000 (ROM start) -> NULL' % k)
                    continue
                short = 'Trigger%d' % (k + 1) if len(ev['coords']) > 1 else 'Trigger'
                self.request(sp, 'script', ctx, (P, short, True), name='%s_EventScript_%s' % (P, short))
                self.run_queue()
            signs = [b for b in ev['bgs'] if b['kind'] < 5]
            for k, b in enumerate(signs):
                sp = b['arg']
                if sp == 0:
                    continue
                if sp in NULL_SCRIPT_PTRS:
                    self.problem(ctx, 'bg event %d script is 0x08000000 (ROM start) -> NULL' % k)
                    continue
                short = 'Sign%d' % (k + 1) if len(signs) > 1 else 'Sign'
                self.request(sp, 'script', ctx, (P, short, True), name='%s_EventScript_%s' % (P, short))
                self.run_queue()
        # 2) compat labels (vanilla per-map labels referenced by C code / shared scripts)
        self.compute_compat()
        self.compute_moved_labels()
        for name in sorted(self.compat, key=lambda n: self.inv.permap[n]['addr']):
            info = self.inv.permap[name]
            kind = info['kind']
            if kind == 'data':
                kind = 'mart'
            pre, short = self.split_label(name)
            addr = self.moved.get(name, info['addr'] + ROMBASE)
            self.request(addr, kind, OWN_COMPAT, (pre, short, False), name=name)
            self.run_queue()
        # 3) shared labels modified in place by the hack
        done = set()
        while True:
            todo = sorted(self.shrepl_roots | set(n for n, i in self.inv.shared.items() if i['changed'])
                          | set(n for n in self.moved if n in self.inv.shared))
            todo = [n for n in todo if n not in done]
            if not todo:
                break
            for name in todo:
                done.add(name)
                info = self.inv.shared[name]
                kind = info['kind']
                if kind == 'data':
                    kind = 'mart'
                pre, short = self.split_label(name)
                addr = self.moved.get(name, info['addr'] + ROMBASE)
                self.request(addr, kind, OWN_SHREPL, (pre, short, False), name=name)
                self.run_queue()
        # 4) extra entry points (pointers from hack code), see coverage pass
        for ptr, kind, name in getattr(self, 'extra_entries', []):
            pre, short = self.split_label(name)
            self.request(ptr, kind, OWN_SHNEW, (pre, short, False), name=name)
            self.run_queue()

    def split_label(self, name):
        for kw in ('_EventScript_', '_Text_', '_Movement_', '_Items_', '_MapScripts', '_OnTransition', '_OnFrame',
                   '_OnLoad', '_OnResume', '_OnWarp'):
            if kw in name:
                i = name.index(kw)
                return name[:i], name[i + len(kw):] or kw.strip('_')
        for kw in ('EventScript_', 'Text_', 'Movement_', 'Std_', 'Common_EventScript_', 'Common_Movement_',
                   'Common_Text_', 'gText_', 'Braille_Text_'):
            if name.startswith(kw):
                return 'SG', name[len(kw):]
        return 'SG', name

    def object_short_name(self, o):
        sp = o['script'] - ROMBASE
        if 0 <= sp < len(self.d):
            # a trainerbattle among the first straight-line commands names the object after the trainer
            p = sp
            for _ in range(12):
                I = decode_instr(self.d, p)
                if I is None:
                    break
                if I.op == 0x5c and I.tbtype is not None:
                    tc = N.trainer_const(I.args[1][1])
                    if tc.startswith('TRAINER_') and tc != 'TRAINER_NONE':
                        return camel_from_const(tc, 'TRAINER_')
                    break
                if I.term:
                    break
                p += I.size
            # item ball: setorcopyvar 0x8000, item; setorcopyvar 0x8001, n; callstd STD_FIND_ITEM
            if self.d[sp] == 0x1a and self.d[sp + 1:sp + 3] == b'\x00\x80' and self.d[sp + 5] == 0x1a \
                    and self.d[sp + 10] == 0x09 and self.d[sp + 11] == 1:
                it = self.d[sp + 3] | self.d[sp + 4] << 8
                return 'Item' + camel_from_const(N.item(it), 'ITEM_')
        g = N.obj_gfx(o['gfx'])
        if g.startswith('OBJ_EVENT_GFX_VAR_'):
            return 'Npc'
        return camel_from_const(g, 'OBJ_EVENT_GFX_')

    # ------------------------------------------------------------------ compat
    def compute_compat(self):
        """Vanilla per-map labels referenced from C code / headers / shared asm in the worktree."""
        perm = self.inv.permap
        words = re.compile(r'\b[A-Za-z_]\w*\b')
        srcs = []
        for root in ['src', 'include', 'asm']:
            for dp, dn, fn in os.walk(os.path.join(self.wt, root)):
                for f in fn:
                    if f.endswith(('.c', '.h', '.inc', '.s')):
                        srcs.append(os.path.join(dp, f))
        for f in glob.glob(os.path.join(self.wt, 'data', '*.s')):
            if os.path.basename(f) != 'event_scripts.s':
                srcs.append(f)
        # shared vanilla files (templates) + inline part of event_scripts.s
        for f in self.inv.shared_files:
            srcs.append(os.path.join(VANILLA_DIR, f))
        refs = collections.defaultdict(set)
        for f in srcs:
            try:
                s = open(f, encoding='utf-8', errors='replace').read()
            except IsADirectoryError:
                continue
            if f.endswith('.s') or f.endswith('.inc'):
                s = re.sub(r'@[^\n]*', '', s)
            for w in set(words.findall(s)):
                if w in perm:
                    refs[w].add(os.path.relpath(f, self.wt) if f.startswith(self.wt) else f)
        self.compat = {}
        self.compat_refs = refs
        for w, fs in refs.items():
            # references only from shared files whose label is being replaced don't count; resolved later
            self.compat[w] = sorted(fs)

    # ------------------------------------------------------------------ chains / chunks
    def build_chunks(self):
        """Group primary instructions into fallthrough chains; data items are their own chunks."""
        addrs = sorted(self.ins)
        nxt = {}
        has_prev = set()
        for a in addrs:
            I = self.ins[a]
            b = a + I.size
            if not I.term and b in self.ins:
                nxt[a] = b
                has_prev.add(b)
        chains = []
        for a in addrs:
            if a in has_prev:
                continue
            lst = [a]
            while lst[-1] in nxt:
                lst.append(nxt[lst[-1]])
            chains.append(lst)
        self.chunks = []
        for lst in chains:
            owner = min(self.ins_owner[x] for x in lst)
            order = min(self.ins_order[x] for x in lst)
            # entries order
            for x in lst:
                e = self.entries.get((x, 'script'))
                if e:
                    order = min(order, e['order'])
            self.chunks.append(dict(kind='script', start=lst[0], end=lst[-1] + self.ins[lst[-1]].size, instrs=lst,
                                    owner=owner, order=order))
        for it in self.items.values():
            order = it.order
            for (a, k), e in self.entries.items():
                pass
            self.chunks.append(dict(kind=it.kind, start=it.start, end=it.end, item=it, owner=it.owner, order=it.order))
        for key, D in self.dups.items():
            if D.end is None:
                continue
            self.chunks.append(dict(kind=D.kind, start=D.addr, end=D.end, dup=D, owner=D.owner, order=D.order))
        # owners of chunks containing modified-shared labels must be OWN_SHREPL
        self.chunk_at = {}
        for c in self.chunks:
            if 'dup' not in c:
                self.chunk_at[c['start']] = c

    # ------------------------------------------------------------------ naming
    def assign_names(self):
        used = self.used_names
        used.update(self.inv.shared.keys())
        used.update(self.compat.keys())
        by_addr, rng = vanilla_symbols()
        for a, s, n in rng:
            if not (EV_START <= a < EV_END):
                used.add(n)
        # collect label requests at primary positions
        self.labels = collections.defaultdict(list)     # addr -> [names] (primary)
        self.dup_names = {}
        counters = collections.Counter()
        totals = collections.Counter()
        ents = sorted(self.entries.items(), key=lambda kv: kv[1]['order'])
        for (a, kind), e in ents:
            if not e['names'] and not e.get('bad'):
                pre, short = e['root'][0], e['root'][1]
                kw = KIND_WORD[kind]
                totals[(pre, kw, short, e['role'])] += 1

        def uniq(n):
            n = re.sub(r'[^A-Za-z0-9_]', '_', n)
            if n not in used:
                used.add(n)
                return n
            k = 2
            while '%s_%d' % (n, k) in used:
                k += 1
            n2 = '%s_%d' % (n, k)
            used.add(n2)
            return n2

        self.entry_name = {}
        for (a, kind), e in ents:
            if e.get('bad'):
                continue
            names = []
            for n, vanilla in e['names']:
                if vanilla:
                    names.append(n)          # vanilla label kept as is (already in `used`)
                else:
                    names.append(uniq(n))
            if not names:
                pre, short = e['root'][0], e['root'][1]
                kw = KIND_WORD[kind]
                role = e['role']
                key = (pre, kw, short, role)
                counters[key] += 1
                if role:
                    base = '%s_%s_%s%s' % (pre, kw, short, role)
                    if totals[key] > 1:
                        base += str(counters[key])
                elif kind == 'script' or totals[key] > 1:
                    base = '%s_%s_%s_%d' % (pre, kw, short, counters[key])
                else:
                    base = '%s_%s_%s' % (pre, kw, short)
                names.append(uniq(base))
            self.entry_name[(a, kind)] = names
            if (a, kind) in self.dups:
                self.dup_names[(a, kind)] = names
            else:
                self.labels[a].extend(n for n in names if n not in self.labels[a])

    def label_for(self, ptr, kind):
        """Render a pointer argument of `kind`."""
        if ptr == 0:
            return '0'
        if ptr in NULL_SCRIPT_PTRS and kind == 'script':
            return '0x%08X' % ptr
        if 0x02000000 <= ptr < 0x04000000:
            r = self.render_ram(ptr)
            if kind in ('text', 'braille') and re.match(r'^[A-Za-z_]\w*$', r):
                return r          # e.g. a string buffer such as gStringVar4
            return '0x%08X' % ptr
        if not self.valid_rom(ptr):
            return '0x%08X' % ptr
        a = ptr - ROMBASE
        key = (a, kind)
        if key in self.ext:
            return self.ext[key]
        if key in self.dup_names:
            return self.dup_names[key][0]
        if key in self.entry_name:
            return self.entry_name[key][0]
        return '0x%08X' % ptr

    def render_ram(self, v, placeholder_ok=False):
        """RAM address -> symbol. Placeholders (SG_RAM_*) only for the hack's own RAM areas and only where the
        argument really is a RAM pointer; anything else (garbage decoded from overlapping data) stays numeric."""
        s, k = ram_symbol(v)
        if k in ('vanilla', 'engine'):
            return s
        if k == 'placeholder' and placeholder_ok and (0x0203C000 <= v < 0x0203D000 or 0x02022000 <= v < 0x02022100):
            return s
        return '0x%08X' % v

    # ------------------------------------------------------------------ rendering values
    def rv(self, kind, v):
        if kind == 'b': return fmt_num(v)
        if kind == 'h': return fmt_num(v)
        if kind == 'w': return fmt_num(v) if v < 0x10000 else '0x%X' % v
        if kind == 'flag': return N.flag_name(v)
        if kind == 'var': return N.var_name(v)
        if kind == 'vh': return var_or(v, fmt_num)
        if kind == 'item': return var_or(v, N.item)
        if kind == 'item_raw': return N.item(v)
        if kind == 'species': return var_or(v, N.species)
        if kind == 'species_raw': return N.species(v)
        if kind == 'move': return var_or(v, N.move)
        if kind == 'move_raw': return N.move(v)
        if kind == 'song': return N.song(v)
        if kind == 'heal': return var_or(v, N.heal_location_const)
        if kind == 'trainer': return var_or(v, N.trainer_const)
        if kind == 'trainer_raw': return N.trainer_const(v)
        if kind == 'localid': return localid(v)
        if kind == 'std': return STD_NAMES.get(v, fmt_num(v))
        if kind == 'cond': return fmt_num(v)
        if kind == 'strvar': return STRVAR_NAMES.get(v, fmt_num(v))
        if kind == 'mc': return N.multichoice_const(v)
        if kind == 'fade': return FADE_NAMES.get(v, fmt_num(v))
        if kind == 'dir': return DIR_NAMES.get(v, fmt_num(v))
        if kind == 'mvtype': return N.movement_type(v)
        if kind == 'gfx': return N.obj_gfx(v)
        if kind == 'gamestat': return const_or_num('GAME_STAT_', v, 'game_stat.h')
        if kind == 'textcolor': return const_or_num('NPC_TEXT_COLOR_', v)
        if kind == 'stepcb': return const_or_num('STEP_CB_', v, 'field_tasks.h')
        if kind == 'mapsec': return N.mapsec_const(v)
        if kind == 'stdstring': return var_or(v, lambda x: const_or_num('STDSTRING_', x, 'menu.h'))
        if kind == 'crymode': return var_or(v, lambda x: const_or_num('CRY_MODE_', x, 'sound.h'))
        if kind == 'weather': return var_or(v, N.weather)
        if kind == 'layout': return var_or(v, N.layout_const)
        if kind == 'fldeff': return var_or(v, lambda x: const_or_num('FLDEFF_', x, 'field_effects.h'))
        if kind == 'map': return N.map_const(v[0], v[1])
        if kind in PTR_KINDS: return self.label_for(v, kind)
        if kind == 'native': return native_symbol(v)[0]
        if kind == 'ram':
            if 0x02000000 <= v < 0x04000000:
                return self.render_ram(v, placeholder_ok=True)
            if self.valid_rom(v):
                n = self.c_symbol_at(v - ROMBASE)
                return n if n else '0x%08X' % v
            return '0x%08X' % v
        if kind == 'loadword':
            if self.valid_rom(v):
                return self.label_for(v, 'text')
            if 0x02000000 <= v < 0x04000000:
                return self.render_ram(v)
            return fmt_num(v) if v < 0x10000 else '0x%X' % v
        raise ValueError(kind)

    def raw_lines(self, I):
        """Fallback rendering as data directives (exact bytes)."""
        out = ['\t.byte 0x%02X @ %s' % (I.op, I.name or 'invalid opcode')]
        if I.name is None or I.raw:
            return out
        if I.op == 0x5c:
            t = I.args[0][1]
            out.append('\t.byte %d' % t)
            out.append('\t.2byte %s' % self.rv('trainer_raw', I.args[1][1]))
            out.append('\t.2byte %s' % fmt_num(I.args[2][1]))
            for a in I.args[3:]:
                out.append('\t.4byte %s' % self.rv(a[0], a[1]))
            return out
        for a in I.args:
            k, v = a[0], a[1]
            if k == 'map':
                out.append('\tmap %s' % self.rv('map', v))
            elif k == 'warp':
                out.append('\tmap %s' % N.map_const(v[0], v[1]))
                out.append('\t.byte %d' % v[2])
                out.append('\t.2byte %s, %s' % (var_or(v[3], fmt_num), var_or(v[4], fmt_num)))
            else:
                n = SIZES.get(k, 2)
                d = {1: '.byte', 2: '.2byte', 4: '.4byte'}[n]
                if k == 'special':
                    s = fmt_num(v)
                else:
                    s = self.rv(k, v)
                out.append('\t%s %s' % (d, s))
        return out

    def render_instr(self, I):
        """Render a single instruction (no multi-instruction sugar)."""
        if I.name is None:
            return ['\t.byte 0x%02X @ invalid opcode (script stops)' % I.op]
        if I.raw:
            return ['\t.byte 0x%02X @ %s (FRLG consumes no argument bytes)' % (I.op, I.name)]
        op = I.op
        A = [a[1] for a in I.args]
        K = [a[0] for a in I.args]
        nm = I.name
        if op == 0x5c:
            return self.render_trainerbattle(I)
        if op in (0x25, 0x26):
            sid = A[-1]
            sn = special_name(sid)
            if sn is None:
                return self.raw_lines(I)
            if op == 0x25:
                return ['\tspecial %s' % sn]
            return ['\tspecialvar %s, %s' % (self.rv('var', A[0]), sn)]
        if K and K[0] == 'warp':
            g, n, wid, x, y = A[0]
            m = N.map_const(g, n)
            xs, ys = var_or(x, fmt_num), var_or(y, fmt_num)
            if op == 0x41:  # setholewarp: defaults a=0, b=0
                if wid == 0xFF and x == 0 and y == 0:
                    return ['\t%s %s' % (nm, m)]
                return ['\t%s %s, %d, %s, %s' % (nm, m, wid, xs, ys)]
            if wid == 0xFF and x == 0xFFFF and y == 0xFFFF:
                return ['\t%s %s' % (nm, m)]
            if x == 0xFFFF and y == 0xFFFF:
                return ['\t%s %s, %d' % (nm, m, wid)]
            if wid == 0xFF:
                return ['\t%s %s, %s, %s' % (nm, m, xs, ys)]
            return ['\t%s %s, %d, %s, %s' % (nm, m, wid, xs, ys)]
        if op in (0x50, 0x52, 0x54, 0x56):
            base = {0x50: 'applymovement', 0x52: 'waitmovement', 0x54: 'removeobject', 0x56: 'addobject'}[op]
            args = [self.rv(k, v) for k, v in zip(K, A)]
            return ['\t%s %s' % (base, ', '.join(args))]
        if op == 0x79:   # givemon species, level, item, 0, 0, 0
            if A[3] == 0 and A[4] == 0 and A[5] == 0:
                s = '\tgivemon %s, %d' % (self.rv('species', A[0]), A[1])
                if A[2] != 0:
                    s += ', %s' % self.rv('item', A[2])
                return [s]
            return self.raw_lines(I)
        if op == 0x95:   # updatemoneybox: macro emits 0, 0, disable
            if A[0] == 0 and A[1] == 0:
                return ['\tupdatemoneybox' + ('' if A[2] == 0 else ' %d' % A[2])]
            return self.raw_lines(I)
        if op == 0xb6:
            s = '\tsetwildbattle %s, %d' % (self.rv('species_raw', A[0]), A[1])
            if A[2]:
                s += ', %s' % self.rv('item_raw', A[2])
            return [s]
        if op in (0x90, 0x91, 0x92):
            s = '\t%s %s' % (nm, self.rv('w', A[0]))
            if A[1]:
                s += ', %d' % A[1]
            return [s]
        if op == 0x93:
            s = '\tshowmoneybox %d, %d' % (A[0], A[1])
            if A[2]:
                s += ', %d' % A[2]
            return [s]
        if op in (0x44, 0x45, 0x46, 0x47, 0x49, 0x4a):
            s = '\t%s %s' % (nm, self.rv('item', A[0]))
            if A[1] != 1:
                s += ', %s' % self.rv('vh', A[1])
            return [s]
        if op == 0x21:   # compare_var_to_value
            if is_var(A[1]):
                return ['\tcompare_var_to_value %s, %s' % (self.rv('var', A[0]), fmt_num(A[1]))]
            return ['\tcompare %s, %s' % (self.rv('var', A[0]), fmt_num(A[1]))]
        if op == 0x22:
            if is_var(A[1]):
                return ['\tcompare %s, %s' % (self.rv('var', A[0]), self.rv('var', A[1]))]
            return ['\tcompare_var_to_var %s, %s' % (self.rv('var', A[0]), self.rv('var', A[1]))]
        if op in (0x06, 0x07) and A[0] in COND_SUFFIX:
            return ['\t%s_%s %s' % ('goto_if' if op == 6 else 'call_if', COND_SUFFIX[A[0]], self.rv('script', A[1]))]
        if op == 0x67 and A[0] == 0:
            return ['\tmessage 0']
        args = [self.rv(k, v) for k, v in zip(K, A)]
        return ['\t%s%s' % (nm, (' ' + ', '.join(args)) if args else '')]

    def render_trainerbattle(self, I):
        t = I.args[0][1]
        tr = self.rv('trainer_raw', I.args[1][1])
        lid = I.args[2][1]
        ptrs = [self.rv(a[0], a[1]) for a in I.args[3:]]
        P = ptrs
        if t not in TB_PTRS:
            return self.raw_lines(I) + ['\t@ ShinyGold: unknown trainerbattle type %d (engine treats it like SINGLE)' % t]
        if lid == 0:
            if t == 0: return ['\ttrainerbattle_single %s, %s, %s' % (tr, P[0], P[1])]
            if t == 2 and P[2] != '0': return ['\ttrainerbattle_single %s, %s, %s, %s' % (tr, P[0], P[1], P[2])]
            if t == 1 and P[2] != '0': return ['\ttrainerbattle_single %s, %s, %s, %s, NO_MUSIC' % (tr, P[0], P[1], P[2])]
            if t == 4: return ['\ttrainerbattle_double %s, %s, %s, %s' % (tr, P[0], P[1], P[2])]
            if t == 6 and P[3] != '0': return ['\ttrainerbattle_double %s, %s, %s, %s, %s' % (tr, P[0], P[1], P[2], P[3])]
            if t == 8 and P[3] != '0': return ['\ttrainerbattle_double %s, %s, %s, %s, %s, NO_MUSIC' % (tr, P[0], P[1], P[2], P[3])]
            if t == 5: return ['\ttrainerbattle_rematch %s, %s, %s' % (tr, P[0], P[1])]
            if t == 7: return ['\ttrainerbattle_rematch_double %s, %s, %s, %s' % (tr, P[0], P[1], P[2])]
            if t == 3: return ['\ttrainerbattle_no_intro %s, %s' % (tr, P[0])]
        if t == 9:
            return ['\ttrainerbattle_earlyrival %s, %d, %s, %s' % (tr, lid, P[0], P[1])]
        tname = const_or_num('TRAINER_BATTLE_', t, 'battle_setup.h')
        return ['\ttrainerbattle %s, %s, %d, %s' % (tname, tr, lid, ', '.join(P))]

    # ------------------------------------------------------------------ sugar
    def render_seq(self, instrs, labeled):
        """Render a list of Instr (a chain) with readable sugar; returns list of (addr, lines)."""
        out = []
        i = 0
        n = len(instrs)
        prev_switch = False

        def free(j):   # instr j (>0 within a pattern) must not carry a label
            return j < n and instrs[j].addr not in labeled

        def is_op(j, op):
            return j < n and instrs[j].op == op and not instrs[j].raw

        while i < n:
            I = instrs[i]
            A = [a[1] for a in I.args]
            done = False
            # msgreceiveditem / giveitem_msg
            if is_op(i, 0x44) and free(i + 1) and is_op(i + 1, 0x0f) and instrs[i + 1].args[0][1] == 0:
                r = self.match_msgreceived(instrs, i + 1, labeled)
                if r:
                    j, msg, item, amt, fan = r
                    if (A[0], A[1]) == (item, amt):
                        s = '\tgiveitem_msg %s, %s' % (msg, self.rv('item', item))
                        s += self.opt_args([(amt, 1, self.rv('vh', amt)), (fan, 257, self.rv('vh', fan))])
                        out.append((I.addr, [s])); i = j; continue
            if is_op(i, 0x0f) and A[0] == 0:
                r = self.match_msgreceived(instrs, i, labeled)
                if r:
                    j, msg, item, amt, fan = r
                    s = '\tmsgreceiveditem %s, %s' % (msg, self.rv('item', item))
                    s += self.opt_args([(amt, 1, self.rv('vh', amt)), (fan, 257, self.rv('vh', fan))])
                    out.append((I.addr, [s])); i = j; continue
                if free(i + 1) and is_op(i + 1, 0x09) and 2 <= instrs[i + 1].args[0][1] <= 6:
                    t = instrs[i + 1].args[0][1]
                    s = '\tmsgbox %s' % self.rv('loadword', A[1])
                    if t != 4:
                        s += ', %s' % STD_NAMES[t]
                    if self.valid_rom(A[1]) or A[1] == 0:
                        out.append((I.addr, [s])); i += 2; continue
            # giveitem / finditem / putitemaway
            if is_op(i, 0x1a) and A[0] == 0x8000 and free(i + 1) and is_op(i + 1, 0x1a) and instrs[i + 1].args[0][1] == 0x8001 \
                    and free(i + 2) and is_op(i + 2, 0x09) and instrs[i + 2].args[0][1] in (0, 1, 8):
                std = instrs[i + 2].args[0][1]
                amt = instrs[i + 1].args[1][1]
                mac = {0: 'giveitem', 1: 'finditem', 8: 'putitemaway'}[std]
                s = '\t%s %s' % (mac, self.rv('item', A[1]))
                if amt != 1:
                    s += ', %s' % self.rv('vh', amt)
                out.append((I.addr, [s])); i += 3; continue
            # goto_if_questlog
            if is_op(i, 0x25) and special_name(A[0]) == 'GetQuestLogState' and free(i + 1) and is_op(i + 1, 0x21) \
                    and instrs[i + 1].args[0][1] == 0x800D and instrs[i + 1].args[1][1] == 2 and free(i + 2) \
                    and is_op(i + 2, 0x06) and instrs[i + 2].args[0][1] == 1:
                out.append((I.addr, ['\tgoto_if_questlog %s' % self.rv('script', instrs[i + 2].args[1][1])]))
                i += 3; continue
            # checkflag + goto_if/call_if TRUE/FALSE
            if is_op(i, 0x2b) and free(i + 1) and (is_op(i + 1, 0x06) or is_op(i + 1, 0x07)) and instrs[i + 1].args[0][1] in (0, 1):
                J = instrs[i + 1]
                base = 'goto_if' if J.op == 6 else 'call_if'
                s = '\t%s_%s %s, %s' % (base, 'set' if J.args[0][1] == 1 else 'unset', self.rv('flag', A[0]),
                                        self.rv('script', J.args[1][1]))
                out.append((I.addr, [s])); i += 2; continue
            # checktrainerflag + goto_if/call_if
            if is_op(i, 0x60) and free(i + 1) and (is_op(i + 1, 0x06) or is_op(i + 1, 0x07)) and instrs[i + 1].args[0][1] in (0, 1):
                J = instrs[i + 1]
                base = 'goto_if' if J.op == 6 else 'call_if'
                s = '\t%s_%s %s, %s' % (base, 'defeated' if J.args[0][1] == 1 else 'not_defeated',
                                        self.rv('trainer', A[0]), self.rv('script', J.args[1][1]))
                out.append((I.addr, [s])); i += 2; continue
            # switch / case
            if is_op(i, 0x19) and A[0] == 0x8000:
                out.append((I.addr, ['\tswitch %s' % self.rv('var', A[1])]))
                prev_switch = True; i += 1; continue
            if prev_switch and is_op(i, 0x21) and A[0] == 0x8000 and not is_var(A[1]) and free(i + 1) and is_op(i + 1, 0x06) \
                    and instrs[i + 1].args[0][1] == 1:
                out.append((I.addr, ['\tcase %s, %s' % (fmt_num(A[1]), self.rv('script', instrs[i + 1].args[1][1]))]))
                i += 2; continue
            prev_switch = False
            # compare + goto_if/call_if
            if (is_op(i, 0x21) and not is_var(A[1]) or is_op(i, 0x22) and is_var(A[1])) and free(i + 1) \
                    and (is_op(i + 1, 0x06) or is_op(i + 1, 0x07)) and instrs[i + 1].args[0][1] in COND_SUFFIX:
                J = instrs[i + 1]
                base = 'goto_if' if J.op == 6 else 'call_if'
                rhs = fmt_num(A[1]) if I.op == 0x21 else self.rv('var', A[1])
                s = '\t%s_%s %s, %s, %s' % (base, COND_SUFFIX[J.args[0][1]], self.rv('var', A[0]), rhs,
                                            self.rv('script', J.args[1][1]))
                out.append((I.addr, [s])); i += 2; continue
            # hidemoneybox: macro emits 0x94 0x00 0x00 (two nops in FRLG)
            if I.op == 0x94 and free(i + 1) and is_op(i + 1, 0x00) and free(i + 2) and is_op(i + 2, 0x00):
                out.append((I.addr, ['\thidemoneybox'])); i += 3; continue
            out.append((I.addr, self.render_instr(I)))
            i += 1
        return out

    def opt_args(self, lst):
        """lst: [(value, default, rendered)] trailing optional args; emit up to the last non-default."""
        last = -1
        for k, (v, dflt, r) in enumerate(lst):
            if v != dflt:
                last = k
        return ''.join(', %s' % r for v, dflt, r in lst[:last + 1])

    def match_msgreceived(self, instrs, i, labeled):
        n = len(instrs)
        if i + 4 >= n:
            return None
        seq = instrs[i:i + 5]
        if any(x.addr in labeled for x in seq[1:]) or any(x.raw for x in seq):
            return None
        if not (seq[0].op == 0x0f and seq[0].args[0][1] == 0):
            return None
        for k, var in zip((1, 2, 3), (0x8000, 0x8001, 0x8002)):
            if seq[k].op != 0x1a or seq[k].args[0][1] != var:
                return None
        if seq[4].op != 0x09 or seq[4].args[0][1] != 9:
            return None
        if not self.valid_rom(seq[0].args[1][1]) and seq[0].args[1][1] != 0:
            return None
        return (i + 5, self.rv('loadword', seq[0].args[1][1]), seq[1].args[1][1], seq[2].args[1][1], seq[3].args[1][1])

    # ------------------------------------------------------------------ data rendering
    def render_text_lines(self, start, end, labels_at, kind):
        """labels_at: {addr: [names]} for positions in (start, end). Returns lines (no leading label for start)."""
        out = []
        cuts = sorted(a for a in labels_at if start < a < end)
        bounds = [start] + cuts + [end]
        for si in range(len(bounds) - 1):
            a, b = bounds[si], bounds[si + 1]
            if si > 0:
                for nm in labels_at[a]:
                    out.append('%s::' % nm)
            final = b == end
            seg = self.d[a:b] if final else self.d[a:b] + b'\xff'
            if kind == 'braille':
                s = braille_decode(seg) if final else None
                if s is None:
                    out.append('\t.byte ' + ', '.join('0x%02X' % x for x in self.d[a:b]))
                else:
                    out.append('\t.braille "%s"' % s)
                continue
            toks, e = decode_tokens(seg, 0, len(seg) + 1)
            body = ''.join(toks) if toks is not None else None
            ok = False
            if body is not None:
                try:
                    ok = encode_tokens_str(body) + b'\xff' == seg
                except Exception:
                    ok = False
            if not ok:
                toks = ['{0x%02X}' % x for x in seg[:-1]]
            lines = string_lines(toks)
            if not final:
                lines[-1] = lines[-1][:-1]   # drop '$'
                if lines[-1] == '':
                    lines.pop()
            for l in lines:
                out.append('\t.string "%s"' % l)
        return out

    def render_movement_lines(self, start, end, labels_at):
        mv = movement_names()
        out = []
        for a in range(start, end):
            if a != start and a in labels_at:
                for nm in labels_at[a]:
                    out.append('%s::' % nm)
            b = self.d[a]
            out.append('\t%s' % mv[b] if b in mv else '\t.byte 0x%02X' % b)
        return out

    def render_u16list_lines(self, start, end, labels_at, kind):
        out = []
        for a in range(start, end, 2):
            if a != start and a in labels_at:
                for nm in labels_at[a]:
                    out.append('%s::' % nm)
            v = self.d[a] | self.d[a + 1] << 8
            out.append('\t.2byte %s' % (N.item(v) if kind == 'mart' else fmt_num(v)))
        return out

    def render_header_lines(self, ents):
        out = []
        dropped = [e for e in ents if e[1] not in MS_TYPES]
        if dropped:
            out.append('\t@ ShinyGold: %d entr%s with invalid type(s) %s dropped (inert: the engine skips them)' % (
                len(dropped), 'y' if len(dropped) == 1 else 'ies', ', '.join('0x%02X' % e[1] for e in dropped)))
        seen = set()
        for p, t, ptr in ents:
            if t not in MS_TYPES:
                continue
            kind = 'mstable' if t in (2, 4) else 'script'
            note = '  @ ShinyGold: shadowed by the first entry of this type (never used)' if t in seen else ''
            seen.add(t)
            out.append('\tmap_script %s, %s%s' % (MS_TYPES[t], self.label_for(ptr, kind), note))
        out.append('\t.byte 0')
        return out

    def render_mstable_lines(self, ents):
        out = []
        for p, var, val, sp in ents:
            lab = self.label_for(sp, 'script')
            dead = '' if self.mstable_entry_live(var, val) else '  @ ShinyGold: can never match'
            if var == val and var < 0x4000:
                dead = '  @ ShinyGold: always matches (constant operands)'
            elif any(x >= 0x8015 for x in (var, val)) and self.mstable_entry_live(var, val):
                dead = '  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)'
            out.append('\tmap_script_2 %s, %s, %s%s' % (N.var_name(var), var_or(val, fmt_num), lab, dead))
        out.append('\t.2byte 0')
        return out

    def chunk_lines(self, c):
        """Render chunk c -> (lines, verify_info)."""
        lines = []
        kind = c['kind']
        if 'dup' in c:
            D = c['dup']
            names = self.dup_names.get((D.addr, kind), ['SG_Dup_%08X' % (D.addr + ROMBASE)])
            for nm in names:
                lines.append('%s::' % nm)
            lines.append('\t@ ShinyGold: overlapping data duplicated from 0x%08X' % (D.addr + ROMBASE))
            if kind == 'script':
                for a, ls in self.render_seq(D.instrs, set()):
                    lines.extend(ls)
            elif kind == 'mapscripts':
                lines.extend(self.render_header_lines(D.instrs))
            elif kind == 'mstable':
                lines.extend(self.render_mstable_lines(D.instrs))
            elif kind in ('text', 'braille'):
                lines.extend(self.render_text_lines(D.addr, D.end, {}, kind))
            elif kind == 'movement':
                lines.extend(self.render_movement_lines(D.addr, D.end, {}))
            else:
                lines.extend(self.render_u16list_lines(D.addr, D.end, {}, kind))
            semantic = kind == 'mapscripts' and any(e[1] not in MS_TYPES for e in D.instrs)
            return lines, semantic
        start, end = c['start'], c['end']
        labels_at = self.labels_in(start, end)
        semantic = False
        if kind in ('mart', 'decor'):
            lines.append('\t.align 1')
        for nm in labels_at.get(start, []):
            lines.append('%s::' % nm)
        if kind == 'script':
            instrs = [self.ins[a] for a in c['instrs']]
            labeled = set(labels_at)
            for a, ls in self.render_seq(instrs, labeled):
                if a != start and a in labels_at:
                    lines.append('')
                    for nm in labels_at[a]:
                        lines.append('%s::' % nm)
                lines.extend(ls)
        elif kind in ('text', 'braille'):
            lines.extend(self.render_text_lines(start, end, labels_at, kind))
        elif kind == 'movement':
            lines.extend(self.render_movement_lines(start, end, labels_at))
        elif kind in ('mart', 'decor'):
            lines.extend(self.render_u16list_lines(start, end, labels_at, kind))
        elif kind == 'mapscripts':
            ents = c['item'].extra
            lines.extend(self.render_header_lines(ents))
            semantic = any(e[1] not in MS_TYPES for e in ents)
        elif kind == 'mstable':
            lines.extend(self.render_mstable_lines(c['item'].extra))
        return lines, semantic

    # ------------------------------------------------------------------ output
    def emit(self):
        wt = self.wt
        index = []   # verification index: dict(file, line, addr, end, semantic, kind)
        files = collections.defaultdict(list)    # relpath -> list of lines
        # group chunks by owner
        by_owner = collections.defaultdict(list)
        for c in self.chunks:
            by_owner[c['owner']].append(c)
        for o in by_owner:
            by_owner[o].sort(key=lambda c: (c['order'], c['start']))

        def put(path, c):
            lines, semantic = self.chunk_lines(c)
            L = files[path]
            if L:
                L.append('')
            index.append(dict(file=path, line=len(L), nlines=len(lines), addr=c['start'], end=c['end'], kind=c['kind'],
                              semantic=semantic, dup='dup' in c))
            L.extend(lines)

        # per-map files
        self.map_files = {}
        for i, m in enumerate(self.maps):
            P = self.map_name[i]
            sp = 'data/maps/%s/scripts.inc' % P
            tp = 'data/maps/%s/text.inc' % P
            files[sp]  # ensure exists
            chunks = by_owner.get(i, [])
            # make sure every map has <P>_MapScripts
            hdr = [c for c in chunks if c['kind'] == 'mapscripts']
            others = [c for c in chunks if c['kind'] != 'mapscripts']
            for c in hdr:
                put(sp, c)
            ms_label = '%s_MapScripts' % P
            if not self.label_defined(ms_label):
                h = m.scripts
                if h is not None and (h, 'mapscripts') in self.entry_name:
                    pass  # defined elsewhere (shared header) -> alias handled via labels
                else:
                    L = files[sp]
                    if L:
                        L.append('')
                    why = 'NULL' if h is None else '0x%08X (invalid)' % (h + ROMBASE)
                    L.extend(['%s::' % ms_label, '\t@ ShinyGold: map script header pointer was %s' % why, '\t.byte 0'])
            for c in others:
                if c['kind'] in ('text', 'braille'):
                    put(tp, c)
                else:
                    put(sp, c)
            self.map_files[i] = (sp, tp)
        for c in by_owner.get(OWN_SHNEW, []):
            put('data/text/shinygold_shared.inc' if c['kind'] in ('text', 'braille') else 'data/scripts/shinygold_shared.inc', c)
        for c in by_owner.get(OWN_COMPAT, []):
            put('data/text/shinygold_compat.inc' if c['kind'] in ('text', 'braille') else 'data/scripts/shinygold_compat.inc', c)
        # shared files with in-place replacements
        shrepl_chunks = by_owner.get(OWN_SHREPL, [])
        self.write_shared_files(shrepl_chunks, files, index)
        self.files = files
        self.index = index

    def labels_in(self, start, end):
        if not hasattr(self, '_lab_sorted'):
            self._lab_sorted = sorted(a for a in self.labels if self.labels[a])
        L = self._lab_sorted
        i = bisect.bisect_left(L, start)
        out = {}
        while i < len(L) and L[i] < end:
            out[L[i]] = self.labels[L[i]]
            i += 1
        return out

    def label_defined(self, name):
        for a, ns in self.labels.items():
            if name in ns:
                return True
        for ns in self.dup_names.values():
            if name in ns:
                return True
        return False

    def write_shared_files(self, shrepl_chunks, files, index):
        """Copy vanilla shared files, replacing blocks of labels that now live in hack-modified chunks."""
        # which vanilla shared labels are defined by generated chunks (any owner)?
        defined_by_chunk = {}
        for a, ns in self.labels.items():
            for n in ns:
                if n in self.inv.shared:
                    defined_by_chunk[n] = a
        for ns in self.dup_names.values():
            for n in ns:
                if n in self.inv.shared:
                    defined_by_chunk[n] = None
        # chunk placement: a SHREPL chunk is placed at the block of the first shared label it defines
        place = {}
        for c in shrepl_chunks:
            names = []
            if 'dup' in c:
                names = [n for n in self.dup_names.get((c['dup'].addr, c['kind']), []) if n in self.inv.shared]
            else:
                for a in sorted(self.labels):
                    if c['start'] <= a < c['end']:
                        names += [n for n in self.labels[a] if n in self.inv.shared]
            if not names:
                files['data/scripts/shinygold_shared.inc']  # fallback
                continue
            first = min(names, key=lambda n: (self.inv.shared[n]['file'], self.inv.shared[n]['line']))
            if self.inv.shared[first]['file'] == 'data/event_scripts.s':
                lines, semantic = self.chunk_lines(c)
                L = files['data/scripts/shinygold_shared.inc']
                if L:
                    L.append('')
                index.append(dict(file='data/scripts/shinygold_shared.inc', line=len(L), nlines=len(lines), addr=c['start'],
                                  end=c['end'], kind=c['kind'], semantic=semantic, dup='dup' in c))
                L.extend(lines)
                continue
            place[first] = c
        self.shared_replaced = sorted(defined_by_chunk)
        for f in self.inv.shared_files:
            if f == 'data/event_scripts.s':
                continue
            src = open(os.path.join(VANILLA_DIR, f), encoding='utf-8').read().split('\n')
            labs = [i for i in self.inv.file_labels(f)]
            if not any(l['name'] in defined_by_chunk for l in labs):
                continue
            out = self.replace_blocks(f, src, defined_by_chunk, place, index, files)
            files[f] = out
        # event_scripts.s inline labels
        f = 'data/event_scripts.s'
        self.event_scripts_inline_repl = [l for l in self.inv.file_labels(f) if l['name'] in defined_by_chunk]

    def block_ranges(self, src):
        """Return {label: (first_line, last_line_inclusive)} for each top-level label block."""
        starts = []
        for i, line in enumerate(src):
            m = LABEL_RE.match(line)
            if m and not line.startswith(('\t', ' ')):
                starts.append((i, m.group(1)))
        res = {}
        for k, (i, name) in enumerate(starts):
            j = starts[k + 1][0] if k + 1 < len(starts) else len(src)
            # consecutive labels share content: block of a label directly followed by another label is just its line
            e = j - 1
            while e > i and (not src[e].strip() or src[e].strip().startswith('@') or
                             re.match(r'\s*\.include', src[e])):
                e -= 1
            res[name] = (i, e)
        return res

    def replace_blocks(self, f, src, defined_by_chunk, place, index, files):
        blocks = self.block_ranges(src)
        out = []
        skip_until = -1
        i = 0
        repl_at = {}
        drop = set()
        for name, (a, b) in blocks.items():
            if name in defined_by_chunk:
                drop.update(range(a, b + 1))
                if name in place:
                    repl_at[a] = name
        for i, line in enumerate(src):
            if i in repl_at:
                c = place[repl_at[i]]
                lines, semantic = self.chunk_lines(c)
                out.append('@ ShinyGold: modified in place by the hack')
                index.append(dict(file=f, line=len(out), nlines=len(lines), addr=c['start'], end=c['end'], kind=c['kind'],
                                  semantic=semantic, dup='dup' in c))
                out.extend(lines)
                continue
            if i in drop:
                continue
            out.append(line)
        return out

    def write_all(self):
        wt = self.wt
        # remove vanilla per-map script/text files that are not regenerated
        new_paths = set(self.files)
        for p in glob.glob(os.path.join(wt, 'data/maps/*/scripts.inc')) + glob.glob(os.path.join(wt, 'data/maps/*/text.inc')):
            rel = os.path.relpath(p, wt)
            if rel not in new_paths:
                os.remove(p)
        for rel, lines in self.files.items():
            p = os.path.join(wt, rel)
            os.makedirs(os.path.dirname(p), exist_ok=True)
            text = '\n'.join(lines).rstrip('\n') + '\n'
            if rel in self.inv.shared_files:
                text = self.rewrite_constants(text)
            if rel.startswith('data/maps/') and not lines:
                text = ''
            with open(p, 'w', encoding='utf-8') as fh:
                fh.write(text)
        # all other vanilla shared files: pristine copy with generated-constant names rewritten (idempotent)
        for f in self.inv.shared_files:
            if f == 'data/event_scripts.s' or f in self.files:
                continue
            text = open(os.path.join(VANILLA_DIR, f), encoding='utf-8').read()
            open(os.path.join(wt, f), 'w', encoding='utf-8').write(self.rewrite_constants(text))
        self.write_event_scripts()

    def vanilla_generated_consts(self):
        """Names defined by vanilla *generated* headers (maps, layouts, heal locations, mapsecs, local ids) and
        opponents.h, mapped to the name the ShinyGold naming contract gives the same value."""
        if hasattr(self, '_vgc'):
            return self._vgc
        out = {}
        inc = os.path.join(VANILLA_DIR, 'include/constants')
        def defs(fn):
            res = {}
            in_enum = False
            nextv = 0
            for line in open(os.path.join(inc, fn), encoding='utf-8'):
                line = line.split('//')[0]
                if re.match(r'\s*enum\b', line):
                    in_enum = True; nextv = 0; continue
                if in_enum:
                    if '}' in line:
                        in_enum = False; continue
                    m = re.match(r'\s*(\w+)\s*(=\s*([^,]+))?,?', line)
                    if m and m.group(1):
                        if m.group(3):
                            try:
                                nextv = int(eval(m.group(3).strip(), {'__builtins__': {}}))
                            except Exception:
                                pass
                        res[m.group(1)] = str(nextv)
                        nextv += 1
                    continue
                m = re.match(r'#define\s+(\w+)\s+(.+?)\s*$', line)
                if m:
                    res[m.group(1)] = m.group(2)
            return res
        def ev(expr, table):
            expr = re.sub(r'\b([A-Z_][A-Z0-9_]*)\b', lambda mm: '(%s)' % table[mm.group(1)] if mm.group(1) in table else mm.group(1), expr)
            return int(eval(expr, {'__builtins__': {}}))
        for fn, prefix, f in [('map_groups.h', 'MAP_', lambda v: N.map_const(v >> 8, v & 0xFF)),
                              ('layouts.h', 'LAYOUT_', N.layout_const),
                              ('heal_locations.h', 'HEAL_LOCATION_', N.heal_location_const),
                              ('region_map_sections.h', 'MAPSEC_', N.mapsec_const),
                              ('opponents.h', 'TRAINER_', N.trainer_const),
                              ('map_event_ids.h', 'LOCALID_', str)]:
            t = defs(fn)
            for name, expr in t.items():
                if not name.startswith(prefix) or name.startswith('GUARD') or 'COUNT' in name or name.startswith('MAP_GROUP'):
                    continue
                try:
                    v = ev(expr, t)
                except Exception:
                    continue
                out[name] = f(v)
        self._vgc = out
        return out

    def rewrite_constants(self, text):
        tab = self.vanilla_generated_consts()
        return re.sub(r'\b(?:MAP|LAYOUT|HEAL_LOCATION|MAPSEC|TRAINER|LOCALID)_[A-Za-z0-9_]+\b',
                      lambda m: tab.get(m.group(0), m.group(0)), text)

    def write_event_scripts(self):
        src = open(os.path.join(VANILLA_DIR, 'data/event_scripts.s'), encoding='utf-8').read().split('\n')
        # inline-label replacement (rare)
        blocks = self.block_ranges(src)
        drop = set()
        repl_at = {}
        for l in self.event_scripts_inline_repl:
            a, b = blocks[l['name']]
            drop.update(range(a, b + 1))
        out = []
        maps_scripts_done = maps_text_done = False
        for i, line in enumerate(src):
            m = re.match(r'\s*\.include\s+"data/maps/([^/]+)/(scripts|text)\.inc"', line)
            if m:
                if m.group(2) == 'scripts' and not maps_scripts_done:
                    for k in range(len(self.maps)):
                        out.append('\t.include "%s"' % self.map_files[k][0])
                    maps_scripts_done = True
                elif m.group(2) == 'text' and not maps_text_done:
                    for k in range(len(self.maps)):
                        tp = self.map_files[k][1]
                        if self.files.get(tp):
                            out.append('\t.include "%s"' % tp)
                    maps_text_done = True
                continue
            if i in drop:
                continue
            out.append(line)
        while out and not out[-1].strip():
            out.pop()
        out.append('')
        out.append('@ ShinyGold: new shared content and vanilla per-map labels kept for C code / shared scripts')
        for f in ['data/scripts/shinygold_shared.inc', 'data/scripts/shinygold_compat.inc',
                  'data/text/shinygold_shared.inc', 'data/text/shinygold_compat.inc']:
            if self.files.get(f):
                out.append('\t.include "%s"' % f)
        open(os.path.join(self.wt, 'data/event_scripts.s'), 'w', encoding='utf-8').write(
            self.rewrite_constants('\n'.join(out) + '\n'))

    # ------------------------------------------------------------------ JSON side outputs
    def write_json(self):
        jd = self.json_dir
        os.makedirs(jd, exist_ok=True)
        labels = {}
        # event / map-script pointers first, resolved with the right kind
        for i, m in enumerate(self.maps):
            evs = self.map_events[i]
            ptrs = [o['script'] for o in evs['objects'] if o['kind'] != 1]
            ptrs += [c['script'] for c in evs['coords']]
            ptrs += [b['arg'] for b in evs['bgs'] if b['kind'] < 5]
            for p in ptrs:
                if p and p not in NULL_SCRIPT_PTRS and self.valid_rom(p):
                    lab = self.label_for(p, 'script')
                    if not lab.startswith('0x'):
                        labels.setdefault('0x%08X' % p, lab)
            if m.scripts is not None:
                lab = self.label_for(m.scripts + ROMBASE, 'mapscripts')
                if not lab.startswith('0x'):
                    labels.setdefault('0x%08X' % (m.scripts + ROMBASE), lab)
        for a in sorted(self.labels):
            if self.labels[a]:
                labels['0x%08X' % (a + ROMBASE)] = self.labels[a][0]
        for (a, k), ns in sorted(self.dup_names.items()):
            labels.setdefault('0x%08X' % (a + ROMBASE), ns[0])
        for (a, k), n in sorted(self.ext.items()):
            labels.setdefault('0x%08X' % (a + ROMBASE), n)
        # map event pointers -> labels (explicit)
        ev = {}
        for i, m in enumerate(self.maps):
            evs = self.map_events[i]
            P = self.map_name[i]
            lst = []
            for o in evs['objects']:
                if o['kind'] != 1 and o['script']:
                    lst.append(('object', o['local_id'], o['script']))
            for k, c in enumerate(evs['coords']):
                lst.append(('coord', k, c['script']))
            for k, b in enumerate(evs['bgs']):
                if b['kind'] < 5:
                    lst.append(('bg', k, b['arg']))
            ent = []
            for typ, idx, p in lst:
                ent.append(dict(type=typ, index=idx, ptr='0x%08X' % p, label=self.event_label(p)))
            ev[P] = dict(group=m.group, num=m.num, map_scripts='%s_MapScripts' % P, events=ent)
        json.dump(labels, open(os.path.join(jd, 'script_labels.json'), 'w'), indent=1, sort_keys=True)
        la = {}
        for a, ns in self.labels.items():
            for n in ns:
                la[n] = a + ROMBASE
        for (a, k), ns in self.dup_names.items():
            for n in ns:
                la.setdefault(n, a + ROMBASE)
        json.dump(la, open(os.path.join(jd, 'label_addrs.json'), 'w'), indent=0, sort_keys=True)
        json.dump(ev, open(os.path.join(jd, 'map_event_scripts.json'), 'w'), indent=1)
        nat = {}
        for v, srcs in sorted(self.natives.items()):
            s, k = native_symbol(v)
            nat['0x%08X' % v] = dict(symbol=s, resolved_by=k, thumb=bool(v & 1),
                                     callers=sorted(self.addr_label(a) for a in srcs),
                                     ram_literals=self.native_ram_literals(v))
        json.dump(nat, open(os.path.join(jd, 'natives.json'), 'w'), indent=1)
        ram = {}
        for v, srcs in sorted(self.rams.items()):
            s, k = ram_symbol(v)
            if not (0x02000000 <= v < 0x04000000):
                continue    # garbage decoded from overlapping/unterminated scripts
            if k not in ('vanilla', 'engine') and not (0x0203C000 <= v < 0x0203D000 or 0x02022000 <= v < 0x02022100):
                continue    # RAM-looking garbage
            ram['0x%08X' % v] = dict(symbol=s, resolved_by=k, users=sorted(self.addr_label(a) for a in srcs))
        json.dump(ram, open(os.path.join(jd, 'ram_refs.json'), 'w'), indent=1)
        probs = {}
        for o, lst in sorted(self.problems.items(), key=lambda kv: kv[0]):
            probs[self.owner_name(o)] = sorted(set(lst))
        json.dump(probs, open(os.path.join(jd, 'problems.json'), 'w'), indent=1)
        json.dump(self.index, open(os.path.join(jd, 'chunk_index.json'), 'w'), indent=0)
        json.dump(dict(compat={n: self.compat[n] for n in sorted(self.compat)},
                       shared_replaced=self.shared_replaced,
                       moved={n: '0x%08X' % x for n, x in sorted(self.moved.items())},
                       partially_repointed=self.partially_repointed),
                  open(os.path.join(jd, 'vanilla_labels.json'), 'w'), indent=1)

    def native_ram_literals(self, v):
        """RAM addresses loaded via literal pools in the first instructions of a Thumb native (informational)."""
        out = []
        a = (v & ~1) - ROMBASE
        if not (v & 1) or not (0 <= a < len(self.d)):
            return out
        for p in range(a, min(a + 0x60, len(self.d) - 1), 2):
            h = self.d[p] | self.d[p + 1] << 8
            if (h >> 11) == 0b01001:
                lit = ((p + 4) & ~3) + (h & 0xFF) * 4
                if lit + 4 <= len(self.d):
                    val = int.from_bytes(self.d[lit:lit + 4], 'little')
                    if 0x02000000 <= val < 0x04000000:
                        s, k = ram_symbol(val)
                        e = '0x%08X' % val + ('' if k == 'placeholder' else ' (%s)' % s)
                        if e not in out:
                            out.append(e)
            if h == 0x4770 or (h & 0xFF00) == 0xBD00:   # bx lr / pop {..., pc}
                break
        return out

    def event_label(self, p):
        if p == 0 or p in NULL_SCRIPT_PTRS:
            return '0x0'
        if not self.valid_rom(p):
            return '0x%08X' % p
        return self.label_for(p, 'script')

    def addr_label(self, a):
        """Nearest preceding label for a script address (for reports)."""
        best = None
        for (x, k), ns in self.entry_name.items():
            if k == 'script' and x <= a and (best is None or x > best[0]):
                best = (x, ns[0])
        return '%s+0x%X' % (best[1], a - best[0]) if best and a != best[0] else (best[1] if best else '0x%08X' % (a + ROMBASE))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('worktree')
    ap.add_argument('--json-dir', default='/home/claude/work/scripts')
    ap.add_argument('--extra-entries', default=os.path.join(HERE, 'extra_entries.json'))
    ap.add_argument('--no-write', action='store_true')
    args = ap.parse_args()
    g = Gen(os.path.abspath(args.worktree), args.json_dir)
    if os.path.exists(args.extra_entries):
        g.extra_entries = [(int(k, 16), v['kind'], v['name']) for k, v in json.load(open(args.extra_entries)).items()]
    g.discover()
    g.build_chunks()
    g.assign_names()
    g.emit()
    if not args.no_write:
        g.write_all()
    g.write_json()
    print('instructions %d, data items %d, dups %d, chunks %d, files %d' % (
        len(g.ins), len(g.items), len(g.dups), len(g.chunks), len(g.files)))
    return g


if __name__ == '__main__':
    main()
