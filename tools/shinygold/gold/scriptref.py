"""Script reference helper for the gold tree.

usage:
  scriptref.py <tree> who <label>            maps whose events/map scripts reach <label> (through goto/call/.4byte...)
  scriptref.py <tree> refs <label>           files and lines that mention <label>
  scriptref.py <tree> ids <Map>              object local-id references in script code reachable from <Map>'s events,
                                             with the other maps that reach the same block (shared code)
  scriptref.py <tree> rmobj <Map> <n> [...]  delete object events n (1-based local ids) from <Map>/map.json and renumber
                                             the local ids in code reachable from <Map>. Refuses (changes nothing) when a
                                             reference that must change sits in a block other maps also reach, or uses an
                                             explicit map argument. Prints references it cannot check (VAR_LAST_TALKED,
                                             VAR_0x8004-style setvars before specials): review those by hand.

Reachability is token based: a label is reached when its name appears in a reached block. Blocks follow fall-through
into the next label (same rules as delete_maps.py)."""
import os, re, sys, json, glob, collections

LABEL = re.compile(r'^(\w+)::?\s*(@.*)?$')
TERM = re.compile(r'^\s*((end|return|goto|step_end|gotostd)\b|\.2byte 0\s*$|\.byte 0\s*$|\.string ".*\$"\s*$)')
TOK = re.compile(r'\b[A-Za-z_]\w*\b')
IDCMD = re.compile(r'^(\s*)(applymovement|waitmovement|removeobject|addobject|setobjectxy|showobjectat|hideobjectat|turnobject|'
                   r'setobjectxyperm|copyobjectxytoperm|setobjectmovementtype|setobjectsubpriority|resetobjectsubpriority)\s+([^,\s@]+)(.*)$')
SUSPECT = re.compile(r'VAR_LAST_TALKED|setvar VAR_0x800[0-9A-F], \d+\s*$|trainerbattle\w*\s')


class Tree:
    def __init__(self, tree):
        self.tree = tree
        os.chdir(tree)
        self.files = sorted(glob.glob('data/maps/*/scripts.inc') + glob.glob('data/maps/*/text.inc') +
                            glob.glob('data/scripts/*.inc') + glob.glob('data/text/*.inc') + ['data/event_scripts.s'])
        self.lines = {}
        self.labs = {}
        self.defined = {}
        for f in self.files:
            ls = open(f, encoding='utf-8', errors='surrogateescape').read().split('\n')
            self.lines[f] = ls
            for i, l in enumerate(ls):
                m = LABEL.match(l)
                if m:
                    self.labs.setdefault(f, {})[m.group(1)] = i
                    self.defined.setdefault(m.group(1), (f, i))
        self._unit = {}
        self.maps = sorted(p.split('/')[2] for p in glob.glob('data/maps/*/map.json'))

    def unit(self, label):
        """(file, first line, end line) of the block starting at label"""
        if label in self._unit: return self._unit[label]
        f, i = self.defined[label]
        ls = self.lines[f]
        j = i + 1
        last = None
        while j < len(ls):
            l = ls[j]
            if LABEL.match(l) and last is not None and TERM.match(last) and not re.match(r'^\s*goto_if', last):
                break
            if l.strip() and not l.strip().startswith('@') and not LABEL.match(l):
                last = l
            j += 1
        self._unit[label] = (f, i, j)
        return self._unit[label]

    def refs_of_unit(self, label):
        f, i, j = self.unit(label)
        s = set()
        for l in self.lines[f][i:j]:
            code = l.split('@')[0]
            if LABEL.match(code): continue
            s.update(t for t in TOK.findall(code) if t in self.defined)
        return s

    def roots(self, m):
        j = json.load(open('data/maps/%s/map.json' % m))
        r = set()
        for key in ('object_events', 'coord_events', 'bg_events'):
            for e in j.get(key) or []:
                s = e.get('script')
                if s and s in self.defined: r.add(s)
        ms = '%s_MapScripts' % m
        if ms in self.defined: r.add(ms)
        return r

    def closure(self, roots):
        seen = set()
        q = list(roots)
        while q:
            l = q.pop()
            if l in seen: continue
            seen.add(l)
            q.extend(self.refs_of_unit(l) - seen)
        return seen

    def map_closures(self):
        if not hasattr(self, '_mc'):
            self._mc = {m: self.closure(self.roots(m)) for m in self.maps}
        return self._mc

    def who(self, label):
        return sorted(m for m, c in self.map_closures().items() if label in c)

    def blocks(self, labels):
        """unique (file, i, j) blocks of labels; blocks that overlap by fall-through are kept separately"""
        return sorted({self.unit(l) for l in labels})


def id_refs(T, m):
    """[(file, lineno, cmd, idtoken, rest, sharedmaps)] for code reachable from map m"""
    mc = T.map_closures()
    mine = mc[m]
    out = []
    seen = set()
    for l in sorted(mine):
        f, i, j = T.unit(l)
        for k in range(i, j):
            if (f, k) in seen: continue
            seen.add((f, k))
            line = T.lines[f][k]
            mm = IDCMD.match(line.split('@')[0])
            susp = SUSPECT.search(line.split('@')[0])
            if not mm and not susp: continue
            # which maps reach a label whose block covers this line
            owners = set()
            for lab, ii in T.labs.get(f, {}).items():
                if ii <= k and T.defined[lab][0] == f:
                    uf, ui, uj = T.unit(lab)
                    if ui <= k < uj:
                        owners.update(x for x, c in mc.items() if lab in c)
            shared = sorted(owners - {m})
            if mm:
                out.append((f, k, mm.group(2), mm.group(3), mm.group(4), shared, False))
            else:
                out.append((f, k, 'suspect', '', line.strip(), shared, True))
    return out


def main():
    tree, cmd = sys.argv[1], sys.argv[2]
    T = Tree(tree)
    if cmd == 'who':
        print('\n'.join(T.who(sys.argv[3])))
    elif cmd == 'refs':
        lab = sys.argv[3]
        pat = re.compile(r'\b%s\b' % re.escape(lab))
        for f in T.files + sorted(glob.glob('data/maps/*/map.json')) + sorted(glob.glob('src/**/*.c', recursive=True)):
            for n, l in enumerate(open(f, encoding='utf-8', errors='surrogateescape')):
                if pat.search(l): print('%s:%d: %s' % (f, n + 1, l.rstrip()))
    elif cmd == 'ids':
        m = sys.argv[3]
        for f, k, c, idt, rest, shared, susp in id_refs(T, m):
            tag = 'SUSPECT ' if susp else ''
            print('%s%s:%d: %s %s%s%s' % (tag, f, k + 1, c if not susp else '', idt, rest, ('   [also reached from: %s]' % ', '.join(shared[:8]) + (' ...' if len(shared) > 8 else '')) if shared else ''))
    elif cmd == 'rmobj':
        m = sys.argv[3]
        rm = sorted({int(x) for x in sys.argv[4:]})
        p = 'data/maps/%s/map.json' % m
        j = json.load(open(p))
        objs = j['object_events']
        n = len(objs)
        assert all(1 <= x <= n for x in rm), 'object index out of range (1..%d)' % n
        newid = {}
        k = 0
        for old in range(1, n + 1):
            if old in rm: continue
            k += 1
            newid[old] = k
        edits = []
        problems = []
        for f, ln, c, idt, rest, shared, susp in id_refs(T, m):
            if susp:
                print('REVIEW %s:%d: %s%s' % (f, ln + 1, rest, ('   [shared with %s]' % ', '.join(shared[:5])) if shared else ''))
                continue
            try:
                v = int(idt, 0)
            except ValueError:
                continue  # LOCALID_PLAYER, LOCALID_CAMERA, VAR_... etc
            if v in (0, 0xFF, 0x7F) or v > n: continue
            # explicit map argument -> refers to another map's objects
            args = [a.strip() for a in rest.split(',')]
            if c in ('applymovement', 'waitmovement', 'removeobject', 'addobject') and len(args) >= (3 if c == 'applymovement' else 2):
                problems.append('%s:%d: %s %s%s has an explicit map argument' % (f, ln + 1, c, idt, rest))
                continue
            if c in ('showobjectat', 'hideobjectat', 'setobjectsubpriority', 'resetobjectsubpriority'):
                if not (len(args) >= 2 and args[1] == j['id']):
                    problems.append('%s:%d: %s %s%s uses a map argument' % (f, ln + 1, c, idt, rest))
                    continue
            if v in rm:
                problems.append('%s:%d: %s %d refers to a removed object' % (f, ln + 1, c, v))
                continue
            if newid[v] == v: continue
            if shared:
                problems.append('%s:%d: %s %d -> %d is in a block also reached from %s' % (f, ln + 1, c, v, newid[v], ', '.join(shared[:5])))
                continue
            edits.append((f, ln, idt, str(newid[v])))
        if problems:
            print('NOT CHANGED. Resolve these first (e.g. give this map its own copy of shared blocks, or delete the code that refers to the removed objects):')
            print('\n'.join('  ' + x for x in problems))
            sys.exit(1)
        for f, ln, old, new in edits:
            line = T.lines[f][ln]
            mm = IDCMD.match(line)
            T.lines[f][ln] = '%s%s %s%s' % (mm.group(1), mm.group(2), new, line[mm.end(3):])
        for f in {e[0] for e in edits}:
            open(f, 'w', encoding='utf-8', errors='surrogateescape').write('\n'.join(T.lines[f]))
        j['object_events'] = [o for i, o in enumerate(objs, 1) if i not in rm]
        open(p, 'w').write(json.dumps(j, indent=2, ensure_ascii=False) + '\n')
        print('removed %s from %s; renumbered %d references' % (rm, m, len(edits)))
        for f, ln, old, new in edits: print('  %s:%d: %s -> %s' % (f, ln + 1, old, new))
    else:
        print(__doc__)


if __name__ == '__main__':
    main()
