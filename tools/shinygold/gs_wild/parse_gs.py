#!/usr/bin/env python3
"""Parse pret/pokegold wild-encounter data (Gold and Silver builds) into gs_raw.json.

Usage: python3 -I parse_gs.py <pokegold_dir> <fr_species_h> <out_json>
"""
import json
import os
import re
import subprocess
import sys

POKEGOLD = sys.argv[1]
SPECIES_H = sys.argv[2]
OUT = sys.argv[3]

VERSIONS = ("gold", "silver")
TIMES = ("morn", "day", "nite")


def rd(rel):
    with open(os.path.join(POKEGOLD, rel), encoding="utf-8") as f:
        return f.read()


# ---------------------------------------------------------------- preprocess
def preprocess(text, version):
    """Resolve IF DEF(_GOLD) / ELIF DEF(_SILVER) / ELSE / ENDC for one version."""
    sym = "_GOLD" if version == "gold" else "_SILVER"
    out = []
    stack = []  # each: [active_now, any_branch_taken, parent_active]
    active = True
    for raw in text.splitlines():
        line = raw.split(";", 1)[0].strip()
        m_if = re.match(r"^IF\s+DEF\((\w+)\)$", line, re.I)
        m_elif = re.match(r"^ELIF\s+DEF\((\w+)\)$", line, re.I)
        if m_if:
            cond = m_if.group(1) == sym
            stack.append([active and cond, cond, active])
            active = active and cond
            continue
        if m_elif:
            top = stack[-1]
            cond = (not top[1]) and m_elif.group(1) == sym
            top[0] = top[2] and cond
            top[1] = top[1] or cond
            active = top[0]
            continue
        if re.match(r"^ELSE$", line, re.I):
            top = stack[-1]
            cond = not top[1]
            top[0] = top[2] and cond
            top[1] = True
            active = top[0]
            continue
        if re.match(r"^ENDC$", line, re.I):
            top = stack.pop()
            active = top[2]
            continue
        if re.match(r"^IF\b", line, re.I):
            raise ValueError("unsupported conditional: " + raw)
        if active:
            out.append(raw)
    assert not stack, "unterminated IF"
    return out


def has_conditionals(text):
    return bool(re.search(r"^\s*IF\s+DEF\(_(GOLD|SILVER)\)", text, re.M))


# ---------------------------------------------------------------- expressions
def eval_expr(expr):
    """Evaluate an RGBDS-ish integer expression with 'N percent' (= N * $ff / 100)."""
    e = expr.strip()
    e = re.sub(r"(\d+)\s+percent", lambda m: "(%s*255//100)" % m.group(1), e)
    e = e.replace("$", "0x")
    if not re.fullmatch(r"[0-9a-fx()+\-*/ ]+", e):
        raise ValueError("bad expr " + expr)
    return eval(e)


# ---------------------------------------------------------------- species
def load_gs_species():
    txt = rd("constants/pokemon_constants.asm")
    val = None
    names = {}
    for line in txt.splitlines():
        s = line.split(";")[0].strip()
        m = re.match(r"const_def\s+(\d+)", s)
        if m:
            val = int(m.group(1))
            continue
        m = re.match(r"const\s+(\w+)$", s)
        if m and val is not None:
            names[m.group(1)] = val
            val += 1
            if m.group(1) == "CELEBI":
                break
    return names


def load_fr_species():
    by_val = {}
    with open(SPECIES_H) as f:
        for line in f:
            m = re.match(r"#define (SPECIES_\w+) (\d+)\s*$", line)
            if m:
                v = int(m.group(2))
                if v not in by_val:
                    by_val[v] = m.group(1)
    return by_val


GS_SPECIES = load_gs_species()
FR_BY_VAL = load_fr_species()
assert GS_SPECIES["CELEBI"] == 251


def fr_species(gs_name):
    v = GS_SPECIES[gs_name]
    fr = FR_BY_VAL[v]
    # sanity: names must agree modulo punctuation conventions
    norm = lambda s: s.replace("SPECIES_", "").replace("_", "")
    assert norm(fr) == norm(gs_name), (gs_name, fr)
    return fr


# ---------------------------------------------------------------- maps
def load_map_constants():
    txt = rd("constants/map_constants.asm")
    group = 0
    groupname = None
    num = 0
    out = {}
    for line in txt.splitlines():
        s = line.split(";")[0].strip()
        m = re.match(r"newgroup\s+(\w+)", s)
        if m:
            group += 1
            groupname = m.group(1)
            num = 0
            continue
        m = re.match(r"map_const\s+(\w+),\s*(\d+),\s*(\d+)", s)
        if m:
            num += 1
            out[m.group(1)] = {"group": group, "group_name": groupname, "num": num,
                               "width": int(m.group(2)), "height": int(m.group(3))}
    return out


def load_map_table():
    """data/maps/maps.asm: label -> tileset, environment, landmark, music, palette, fishgroup."""
    txt = rd("data/maps/maps.asm")
    out = {}
    for line in txt.splitlines():
        s = line.split(";")[0].strip()
        m = re.match(r"map\s+(.*)$", s)
        if m:
            a = [x.strip() for x in m.group(1).split(",")]
            assert len(a) == 8, s
            out[a[0]] = {"tileset": a[1], "environment": a[2], "landmark": a[3],
                         "music": a[4], "fishgroup": a[7]}
    return out


def load_attributes():
    txt = rd("data/maps/attributes.asm")
    label_by_const = {}
    for m in re.finditer(r"^\s*map_attributes\s+(\w+),\s*(\w+),", txt, re.M):
        label_by_const[m.group(2)] = m.group(1)
    return label_by_const


def load_blocks():
    txt = rd("data/maps/blocks.asm")
    pending = []
    out = {}
    for line in txt.splitlines():
        s = line.split(";")[0].strip()
        m = re.match(r"(\w+)_Blocks::?$", s)
        if m:
            pending.append(m.group(1))
            continue
        m = re.match(r'INCBIN\s+"([^"]+)"', s)
        if m:
            for p in pending:
                out[p] = m.group(1)
            pending = []
    return out


def load_collision_consts():
    txt = rd("constants/collision_constants.asm")
    out = {}
    for m in re.finditer(r"DEF\s+COLL_(\w+)\s+EQU\s+\$([0-9a-fA-F]+)", txt):
        out[m.group(1)] = int(m.group(2), 16)
    return out


def load_permissions():
    txt = rd("data/collision/collision_permissions.asm")
    perms = []
    started = False
    for line in txt.splitlines():
        s = line.split(";")[0].strip()
        if s.startswith("CollisionPermissionTable"):
            started = True
            continue
        if started and s.startswith("db "):
            perms.append(s[3:].strip())
    return perms


def load_tileset_collisions():
    """TILESET_* -> list of 4-tuples of collision values per metatile."""
    cc = load_collision_consts()
    tilesets_asm = rd("data/tilesets.asm")
    order = re.findall(r"^\s*tileset\s+(\w+)", tilesets_asm, re.M)  # index 0 = Tileset0
    gfx = rd("gfx/tilesets.asm")
    coll_file = {}
    pending = []
    for line in gfx.splitlines():
        s = line.split(";")[0].strip()
        m = re.match(r"(\w+)Coll::?$", s)
        if m:
            pending.append(m.group(1))
            continue
        m = re.match(r'INCLUDE\s+"(data/tilesets/\w+_collision\.asm)"', s)
        if m:
            for p in pending:
                coll_file[p] = m.group(1)
            pending = []
        elif s and pending and not s.startswith("INCLUDE"):
            pending = []
    # tileset constants
    tc = rd("constants/tileset_constants.asm")
    consts = []
    for line in tc.splitlines():
        s = line.split(";")[0].strip()
        m = re.match(r"const\s+(TILESET_\w+)", s)
        if m:
            consts.append(m.group(1))
    # const_def 1 -> TILESET_JOHTO = 1 ; order[0] is Tileset0
    result = {}
    for i, c in enumerate(consts, start=1):
        name = order[i]
        f = coll_file[name]
        blocks = []
        for line in rd(f).splitlines():
            s = line.split(";")[0].strip()
            m = re.match(r"tilecoll\s+(\w+),\s*(\w+),\s*(\w+),\s*(\w+)", s)
            if m:
                vals = []
                for t in m.groups():
                    if t in cc:
                        vals.append(cc[t])
                    else:
                        vals.append(int(t, 16))
                blocks.append(tuple(vals))
        result[c] = blocks
    return result


def water_tile_info():
    """Return {MAP_CONST: True/False} whether map blocks contain any WATER_TILE collision."""
    perms = load_permissions()
    water_colls = {i for i, p in enumerate(perms) if "WATER_TILE" in p}
    tcoll = load_tileset_collisions()
    consts = load_map_constants()
    attrs = load_attributes()
    maptab = load_map_table()
    blocks = load_blocks()
    out = {}
    for const, label in attrs.items():
        mc = consts[const]
        bpath = blocks.get(label)
        if bpath is None:
            out[const] = None
            continue
        with open(os.path.join(POKEGOLD, bpath), "rb") as f:
            data = f.read()
        ts = maptab[label]["tileset"]
        coll = tcoll[ts]
        n = mc["width"] * mc["height"]
        has = False
        for b in data[:n]:
            if b < len(coll) and any(c in water_colls for c in coll[b]):
                has = True
                break
        out[const] = has
    return out


# ---------------------------------------------------------------- wild tables
def parse_wild_file(rel, kind, version):
    lines = preprocess(rd(rel), version)
    tables = []
    cur = None
    for raw in lines:
        s = raw.split(";")[0].strip()
        if not s:
            continue
        m = re.match(r"def_(grass|water)_wildmons\s+(\w+)", s)
        if m:
            cur = {"map": m.group(2), "rates": [], "mons": []}
            continue
        if s.startswith("end_") and cur is not None:
            tables.append(cur)
            cur = None
            continue
        if cur is None:
            continue
        m = re.match(r"db\s+(.*)$", s)
        if not m:
            raise ValueError(raw)
        parts = [p.strip() for p in m.group(1).split(",")]
        if all("percent" in p for p in parts):
            assert not cur["rates"] and not cur["mons"], (rel, cur["map"])
            for p in parts:
                cur["rates"].append({"percent": int(p.split()[0]), "byte": eval_expr(p)})
            continue
        lvl, sp = parts
        cur["mons"].append((int(lvl), sp))
    out = {}
    for t in tables:
        if kind == "grass":
            assert len(t["rates"]) == 3 and len(t["mons"]) == 21, (rel, t["map"], version)
            slots = {}
            for ti, tname in enumerate(TIMES):
                slots[tname] = [
                    {"slot": i, "level": t["mons"][ti * 7 + i][0], "gs_species": t["mons"][ti * 7 + i][1],
                     "species": fr_species(t["mons"][ti * 7 + i][1])}
                    for i in range(7)]
            out[t["map"]] = {"rates": dict(zip(TIMES, t["rates"])), "slots": slots}
        else:
            assert len(t["rates"]) == 1 and len(t["mons"]) == 3, (rel, t["map"], version)
            out[t["map"]] = {"rate": t["rates"][0],
                             "slots": [{"slot": i, "level": t["mons"][i][0], "gs_species": t["mons"][i][1],
                                        "species": fr_species(t["mons"][i][1])} for i in range(3)]}
    return out


def parse_probabilities():
    txt = rd("data/wild/probabilities.asm")
    def table(label):
        sec = txt.split(label + ":", 1)[1]
        vals = []
        for line in sec.splitlines()[1:]:
            s = line.split(";")[0].strip()
            m = re.match(r"mon_prob\s+(\d+),\s*(\d+)", s)
            if m:
                vals.append((int(m.group(1)), int(m.group(2))))
            elif s.startswith("assert_table_length"):
                break
        # cumulative thresholds -> per-slot percent (random 1..100, first threshold >= r)
        probs = []
        prev = 0
        for thr, idx in vals:
            assert idx == len(probs)
            probs.append(thr - prev)
            prev = thr
        assert prev == 100
        return probs
    return table("GrassMonProbTable"), table("WaterMonProbTable")


def parse_fish(version):
    lines = preprocess(rd("data/wild/fish.asm"), version)
    text = "\n".join(lines)
    # FishGroups
    groups = []
    for m in re.finditer(r"fishgroup\s+(.+?),\s*\.(\w+),\s*\.(\w+),\s*\.(\w+)", text):
        groups.append({"bite": eval_expr(m.group(1)), "old": m.group(2), "good": m.group(3), "super": m.group(4)})
    # labelled tables
    tables = {}
    cur_labels = []
    for raw in lines:
        s = raw.split(";")[0].strip()
        if not s:
            continue
        m = re.match(r"\.(\w+):$", s)
        if m:
            if cur_labels and tables.get(cur_labels[-1]):
                cur_labels = []
            cur_labels.append(m.group(1))
            for l in cur_labels:
                tables.setdefault(l, [])
            continue
        if s.startswith("TimeFishGroups"):
            cur_labels = []
            continue
        m = re.match(r"db\s+(.+?),\s*time_group\s+(\d+)$", s)
        if m and cur_labels:
            e = {"threshold": eval_expr(m.group(1)), "time_group": int(m.group(2))}
            for l in cur_labels:
                tables[l].append(e)
            continue
        m = re.match(r"db\s+(.+?),\s*([A-Z_]+),\s*(\d+)$", s)
        if m and cur_labels:
            e = {"threshold": eval_expr(m.group(1)), "gs_species": m.group(2), "level": int(m.group(3))}
            for l in cur_labels:
                tables[l].append(e)
            continue
    # TimeFishGroups
    tfg = []
    sec = text.split("TimeFishGroups:", 1)[1]
    for m in re.finditer(r"db\s+([A-Z_]+),\s*(\d+),\s*([A-Z_]+),\s*(\d+)", sec):
        tfg.append({"day": (m.group(1), int(m.group(2))), "nite": (m.group(3), int(m.group(4)))})
    # FISHGROUP constants order
    cons = []
    for line in rd("constants/map_data_constants.asm").splitlines():
        s = line.split(";")[0].strip()
        m = re.match(r"const\s+(FISHGROUP_\w+)", s)
        if m:
            cons.append(m.group(1))
    assert cons[0] == "FISHGROUP_NONE"
    assert len(groups) == len(cons) - 1

    def resolve(label):
        entries = tables[label]
        prev = -1
        out = []
        for e in entries:
            p = e["threshold"] - prev  # Random byte r (0..255), first entry with r <= threshold
            prev = e["threshold"]
            if "time_group" in e:
                t = tfg[e["time_group"]]
                out.append({"prob_256": p, "time_group": e["time_group"],
                            "day": {"gs_species": t["day"][0], "species": fr_species(t["day"][0]), "level": t["day"][1]},
                            "nite": {"gs_species": t["nite"][0], "species": fr_species(t["nite"][0]), "level": t["nite"][1]}})
            else:
                out.append({"prob_256": p, "gs_species": e["gs_species"], "species": fr_species(e["gs_species"]),
                            "level": e["level"]})
        assert prev == 255, (label, prev)
        return out

    result = {}
    for c, g in zip(cons[1:], groups):
        result[c] = {"bite_byte": g["bite"], "bite_chance": g["bite"] / 256,
                     "old": resolve(g["old"]), "good": resolve(g["good"]), "super": resolve(g["super"]),
                     "labels": {"old": g["old"], "good": g["good"], "super": g["super"]}}
    return result, tfg


def parse_treemons(version):
    lines = preprocess(rd("data/wild/treemons.asm"), version)
    sets_order = []
    started = False
    for raw in lines:
        s = raw.split(";")[0].strip()
        if s.startswith("TreeMons:"):
            started = True
            continue
        if started:
            m = re.match(r"dw\s+(\w+)", s)
            if m:
                sets_order.append(m.group(1))
            elif s.startswith("assert_table_length"):
                break
    tables = {}
    cur = []
    data = {}
    for raw in lines:
        s = raw.split(";")[0].strip()
        if not s:
            continue
        m = re.match(r"(TreeMonSet_\w+):$", s)
        if m:
            if cur and any(data[cur[-1]]):
                cur = []
            cur.append(m.group(1))
            for c in cur:
                data.setdefault(c, [[]])
            continue
        if not cur:
            continue
        if s == "db -1":
            for c in cur:
                data[c].append([])
            continue
        m = re.match(r"db\s+(\d+),\s*(\w+),\s*(\d+)$", s)
        if m:
            for c in cur:
                data[c][-1].append({"percent": int(m.group(1)), "gs_species": m.group(2),
                                    "species": fr_species(m.group(2)), "level": int(m.group(3))})
    for k in data:
        data[k] = [t for t in data[k] if t]
    tc = []
    for line in rd("constants/pokemon_data_constants.asm").splitlines():
        s = line.split(";")[0].strip()
        m = re.match(r"const\s+(TREEMON_SET_\w+)", s)
        if m:
            tc.append(m.group(1))
    sets = {}
    for c, lbl in zip(tc, sets_order):
        sets[c] = {"label": lbl, "tables": data[lbl]}
    return sets


def parse_treemon_maps():
    txt = rd("data/wild/treemon_maps.asm")
    tree, rock = [], []
    cur = None
    for line in txt.splitlines():
        s = line.split(";")[0].strip()
        if s.startswith("TreeMonMaps"):
            cur = tree
        elif s.startswith("RockMonMaps"):
            cur = rock
        m = re.match(r"treemon_map\s+(\w+),\s*(\w+)", s)
        if m and cur is not None:
            cur.append((m.group(1), m.group(2)))
    return tree, rock


def parse_contest():
    txt = rd("data/wild/bug_contest_mons.asm")
    out = []
    for m in re.finditer(r"db\s+(-?\d+),\s*(\w+),\s*(\d+),\s*(\d+)", txt):
        pct = int(m.group(1))
        if pct < 0:
            break
        out.append({"percent": pct, "gs_species": m.group(2), "species": fr_species(m.group(2)),
                    "min_level": int(m.group(3)), "max_level": int(m.group(4))})
    assert sum(e["percent"] for e in out) == 100
    return out


def parse_swarm_triggers():
    txt = rd("engine/phone/scripts/trainers.asm")
    grass = re.findall(r"^\s*swarm\s+(\w+)", txt, re.M)
    fish = re.findall(r"setval\s+(FISHSWARM_\w+)", txt)
    return grass, fish


def reachable_maps():
    """BFS over warp_events, script warps and map connections starting from the player's house."""
    import glob
    attrs = load_attributes()
    label_to_const = {v: k for k, v in attrs.items()}
    edges = {}
    for path in glob.glob(os.path.join(POKEGOLD, "maps", "*.asm")):
        label = os.path.basename(path)[:-4]
        src = label_to_const.get(label)
        if src is None:
            continue
        # drop warps that pret documents as inaccessible (e.g. Fuchsia -> beta Safari Zone gate)
        txt = "\n".join(l for l in open(path, encoding="utf-8").read().splitlines() if "inaccessible" not in l)
        tg = set(re.findall(r"^\s*warp_event\s+\d+,\s*\d+,\s*(\w+),", txt, re.M))
        tg |= set(re.findall(r"^\s*warp\s+(\w+),", txt, re.M))
        tg |= set(re.findall(r"^\s*warpfacing\s+\w+,\s*(\w+),", txt, re.M))
        edges.setdefault(src, set()).update(t for t in tg if t in attrs)
    cur = None
    for line in rd("data/maps/attributes.asm").splitlines():
        s = line.split(";")[0].strip()
        m = re.match(r"map_attributes\s+\w+,\s*(\w+),", s)
        if m:
            cur = m.group(1)
            continue
        m = re.match(r"connection\s+\w+,\s*\w+,\s*(\w+),", s)
        if m and cur:
            edges.setdefault(cur, set()).add(m.group(1))
    # LAST_MAP warps return to the previous map; treat them as bidirectional by adding reverse edges
    seen = {"PLAYERS_HOUSE_2F"}
    todo = ["PLAYERS_HOUSE_2F"]
    while todo:
        m = todo.pop()
        for t in edges.get(m, ()):
            if t not in seen:
                seen.add(t)
                todo.append(t)
    return seen


def parse_roamers():
    wm = rd("engine/overworld/wildmons.asm")
    init = wm.split("InitRoamMons:", 1)[1].split("\n\n\n", 1)[0]
    species = re.findall(r"ld a, (RAIKOU|ENTEI|SUICUNE)\n\s*ld \[wRoamMon\dSpecies\]", init)
    level = int(re.search(r"ld a, (\d+)\n\s*ld \[wRoamMon1Level\]", init).group(1))
    maps = re.findall(r"^\s*roam_map\s+(\w+)", rd("data/wild/roammon_maps.asm"), re.M)
    return {"species": [fr_species(x) for x in species], "level": level, "maps": maps,
            "note": "not table encounters; listed for completeness (excluded from gs_wild_species)"}


def human_name(const):
    return const.replace("_", " ")


# ---------------------------------------------------------------- main
def main():
    commit = subprocess.check_output(["git", "-C", POKEGOLD, "rev-parse", "HEAD"]).decode().strip()
    commit_date = subprocess.check_output(["git", "-C", POKEGOLD, "log", "-1", "--format=%cI"]).decode().strip()
    consts = load_map_constants()
    attrs = load_attributes()
    maptab = load_map_table()
    water = water_tile_info()
    grass_probs, water_probs = parse_probabilities()

    files = {
        "grass": ["data/wild/johto_grass.asm", "data/wild/kanto_grass.asm"],
        "water": ["data/wild/johto_water.asm", "data/wild/kanto_water.asm"],
        "swarm_grass": ["data/wild/swarm_grass.asm"],
        "swarm_water": ["data/wild/swarm_water.asm"],
    }
    region_of = {}
    parsed = {k: {v: {} for v in VERSIONS} for k in files}
    for k, fl in files.items():
        for v in VERSIONS:
            for f in fl:
                kind = "grass" if "grass" in k else "water"
                d = parse_wild_file(f, kind, v)
                for mp in d:
                    if k in ("grass", "water"):
                        assert mp not in parsed[k][v], (k, mp)
                        region_of[mp] = "johto" if "johto" in f else "kanto"
                parsed[k][v].update(d)
    conditional_files = sorted(f for fl in files.values() for f in fl if has_conditionals(rd(f)))
    for extra in ("data/wild/fish.asm", "data/wild/treemons.asm", "data/wild/treemon_maps.asm",
                  "data/wild/bug_contest_mons.asm"):
        if has_conditionals(rd(extra)):
            conditional_files.append(extra)

    fish = {v: parse_fish(v)[0] for v in VERSIONS}
    tfg = parse_fish("gold")[1]
    trees = {v: parse_treemons(v) for v in VERSIONS}
    tree_maps, rock_maps = parse_treemon_maps()
    contest = parse_contest()
    swarm_grass_maps, fish_swarms = parse_swarm_triggers()

    # Engine facts verified from source (asserted where cheaply checkable)
    wm = rd("engine/overworld/wildmons.asm")
    assert "cp 35 percent" in wm and "cp 95 percent" in wm  # surf level bonus
    rtc = rd("engine/rtc/rtc.asm")
    assert "0400-0959 morn | 1000-1759 day | 1800-0359 nite" in rtc
    fishasm = rd("engine/events/fish.asm")
    assert "cp NITE_F" in fishasm
    tm = rd("engine/events/treemons.asm")
    assert "; 40% chance of an encounter" in tm

    surf_bonus = []  # P(level += k)
    thr = [eval_expr("35 percent"), eval_expr("65 percent"), eval_expr("85 percent"), eval_expr("95 percent")]
    prev = 0
    for k, t in enumerate(thr):
        surf_bonus.append({"bonus": k, "prob_256": t - prev})
        prev = t
    surf_bonus.append({"bonus": 4, "prob_256": 256 - prev})

    # fishing swarm groups
    fishswarm_map = {"FISHGROUP_QWILFISH": "FISHGROUP_QWILFISH_SWARM", "FISHGROUP_REMORAID": "FISHGROUP_REMORAID_SWARM"}

    # build location list
    locs = {}

    def loc(mp):
        if mp not in locs:
            label = attrs[mp]
            mt = maptab[label]
            mc = consts[mp]
            locs[mp] = {"map_const": mp, "name": human_name(mp), "pret_label": label,
                        "map_group": mc["group"], "map_group_name": mc["group_name"], "map_num": mc["num"],
                        "region": region_of.get(mp), "environment": mt["environment"], "landmark": mt["landmark"],
                        "tileset": mt["tileset"], "fish_group": mt["fishgroup"], "has_water_tiles": water.get(mp)}
        return locs[mp]

    for v in VERSIONS:
        for mp, d in parsed["grass"][v].items():
            loc(mp).setdefault("grass", {})[v] = d
        for mp, d in parsed["water"][v].items():
            loc(mp).setdefault("surf", {})[v] = d
        for mp, d in parsed["swarm_grass"][v].items():
            loc(mp).setdefault("swarm", {}).setdefault("grass", {})[v] = d
        for mp, d in parsed["swarm_water"][v].items():
            loc(mp).setdefault("swarm", {}).setdefault("surf", {})[v] = d

    # fishing: any map with a fishgroup != NONE and fishable (WATER_TILE) tiles
    for mp, label in attrs.items():
        fg = maptab[label]["fishgroup"]
        if fg == "FISHGROUP_NONE" or not water.get(mp):
            continue
        L = loc(mp)
        L["fishing"] = {"fish_group": fg}
        for v in VERSIONS:
            L["fishing"][v] = {"old": fish[v][fg]["old"], "good": fish[v][fg]["good"], "super": fish[v][fg]["super"],
                               "bite_byte": fish[v][fg]["bite_byte"]}
        if fg in fishswarm_map:
            sg = fishswarm_map[fg]
            L.setdefault("swarm", {})["fishing"] = {"fish_group": sg}
            for v in VERSIONS:
                L["swarm"]["fishing"][v] = {"old": fish[v][sg]["old"], "good": fish[v][sg]["good"],
                                            "super": fish[v][sg]["super"], "bite_byte": fish[v][sg]["bite_byte"]}

    # headbutt / rock smash
    usable_tree_sets = {"TREEMON_SET_FOREST", "TREEMON_SET_CANYON"}  # GetTreeMons ignores NONE, UNUSED, CITY
    tree_rare_chance = {"bad": 0.10, "good": 0.50, "rare": 0.80}
    for mp, st in tree_maps:
        L = loc(mp)
        L["headbutt"] = {"set": st, "usable": st in usable_tree_sets}
        for v in VERSIONS:
            tabs = trees[v][st]["tables"]
            L["headbutt"][v] = {"common": tabs[0], "rare": tabs[1] if len(tabs) > 1 else None}
    for mp, st in rock_maps:
        L = loc(mp)
        L["rock_smash"] = {"set": st, "encounter_chance": 0.40}
        for v in VERSIONS:
            L["rock_smash"][v] = {"slots": trees[v][st]["tables"][0]}

    reach = reachable_maps()
    for mp in locs:
        L = locs[mp]
        L["reachable_in_gs"] = mp in reach
        if "swarm" in L:
            L["swarm"]["triggered_by_phone"] = (mp in swarm_grass_maps) or ("fishing" in L["swarm"])
        if L.get("region") is None:
            # derive region from landmark ordering: Kanto landmarks start at LANDMARK_PALLET_TOWN
            pass

    # region for maps only in fishing/headbutt lists: use landmark constant order
    lm = []
    for line in rd("constants/landmark_constants.asm").splitlines():
        s = line.split(";")[0].strip()
        m = re.match(r"const\s+(LANDMARK_\w+)", s)
        if m:
            lm.append(m.group(1))
    kanto_start = lm.index("LANDMARK_PALLET_TOWN")
    for L in locs.values():
        idx = lm.index(L["landmark"]) if L["landmark"] in lm else -1
        reg = "kanto" if idx >= kanto_start else "johto"
        if L.get("region") is None:
            L["region"] = reg
        L["landmark_region"] = reg

    out = {
        "source": {"repo": "https://github.com/pret/pokegold", "commit": commit, "commit_date": commit_date,
                   "files": sorted({f for fl in files.values() for f in fl} | {
                       "data/wild/fish.asm", "data/wild/probabilities.asm", "data/wild/treemons.asm",
                       "data/wild/treemon_maps.asm", "data/wild/bug_contest_mons.asm",
                       "engine/overworld/wildmons.asm", "engine/events/fish.asm", "engine/events/treemons.asm",
                       "engine/rtc/rtc.asm", "data/maps/maps.asm", "data/maps/attributes.asm",
                       "data/maps/blocks.asm", "data/collision/collision_permissions.asm",
                       "data/tilesets/*_collision.asm", "constants/*.asm"}),
                   "version_conditional_files": conditional_files},
        "mechanics": {
            "percent_macro": "N percent = N * 255 // 100 (byte); encounter roll = Random(0..255) < byte",
            "time_of_day": {"morn": {"hours": "04:00-09:59", "n_hours": 6},
                            "day": {"hours": "10:00-17:59", "n_hours": 8},
                            "nite": {"hours": "18:00-03:59", "n_hours": 10},
                            "source": "engine/rtc/rtc.asm TimesOfDay + constants/misc_constants.asm MORN_HOUR=4 DAY_HOUR=10 NITE_HOUR=18"},
            "grass_slot_percent": grass_probs,
            "surf_slot_percent": water_probs,
            "surf_level_bonus": surf_bonus,
            "grass_level_bonus": "none (fixed levels)",
            "fishing": "bite if Random < bite_byte (128 -> 50%); slot = first entry with Random(0..255) <= threshold; "
                       "time_group entries use 'day' species for MORN and DAY, 'nite' species for NITE",
            "fish_time_group_weights": {"day": 14, "nite": 10},
            "headbutt": "only TREEMON_SET_FOREST/CANYON produce encounters (NONE/UNUSED/CITY sets ignored by GetTreeMons); "
                        "per tree score: bad 50% of trees -> 10% chance (common table), good 40% -> 50% (common), "
                        "rare 10% -> 80% (rare table); slot = Random(0..99) vs cumulative percent",
            "rock_smash": "40% chance per smashed rock, then slot by percent",
            "encounter_cooldown": "5-step cooldown on map entry/after battle (first 4 steps cannot encounter)",
        },
        "time_fish_groups": tfg,
        "fish_groups": fish["gold"],
        "fish_groups_identical_gold_silver": fish["gold"] == fish["silver"],
        "treemon_sets": trees,
        "bug_contest": {"map": "NATIONAL_PARK_BUG_CONTEST", "encounter_byte": {"tall_grass": eval_expr("20 percent"),
                        "super_tall_grass": eval_expr("40 percent")}, "mons": contest},
        "roamers": parse_roamers(),
        "swarm_maps_grass": swarm_grass_maps,
        "fish_swarms": fish_swarms,
        "locations": dict(sorted(locs.items(), key=lambda kv: (kv[1]["map_group"], kv[1]["map_num"]))),
    }
    with open(OUT, "w") as f:
        json.dump(out, f, indent=1)
    print("locations:", len(locs))
    print("conditional files:", conditional_files)
    print("fish identical:", out["fish_groups_identical_gold_silver"])


if __name__ == "__main__":
    main()
