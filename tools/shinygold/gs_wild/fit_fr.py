#!/usr/bin/env python3
"""Blend Gold+Silver and morning/day/night G/S wild data into FireRed fixed-rate slot tables.

Usage: python3 -I fit_fr.py <gs_raw.json> <fr_tables.json> <gs_wild_species.json> [--swarm-weight W]
"""
import json
import math
import os
import sys
from collections import defaultdict
from functools import lru_cache

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from rates import best_fr_rate, fr_mean_steps, gs_mean_steps  # noqa: E402

RAW, OUT_TABLES, OUT_SPECIES = sys.argv[1:4]
SWARM_WEIGHT = 0.0
if "--swarm-weight" in sys.argv:
    SWARM_WEIGHT = float(sys.argv[sys.argv.index("--swarm-weight") + 1])

VERSIONS = ("gold", "silver")
TIMES = ("morn", "day", "nite")
HOURS = {"morn": 6, "day": 8, "nite": 10}
FISH_HOURS = {"day": HOURS["morn"] + HOURS["day"], "nite": HOURS["nite"]}  # morn+day use the 'day' column

FR_SLOTS = {
    "land_mons": [20, 20, 10, 10, 10, 10, 5, 5, 4, 4, 1, 1],
    "water_mons": [60, 30, 5, 4, 1],
    "rock_smash_mons": [60, 30, 5, 4, 1],
    "old_rod": [70, 30],
    "good_rod": [60, 20, 20],
    "super_rod": [40, 40, 15, 4, 1],
}
FISHING_RATE_UNUSED = 20  # FR ignores fishingMonsInfo->encounterRate (bite = Random()&1 = 50%, same as G/S 128/256)

raw = json.load(open(RAW))
MECH = raw["mechanics"]
GRASS_PCT = MECH["grass_slot_percent"]
SURF_PCT = MECH["surf_slot_percent"]
SURF_BONUS = [(b["bonus"], b["prob_256"] / 256.0) for b in MECH["surf_level_bonus"]]


# ------------------------------------------------------------------ target distributions
def add(dist, sp, lvl, w):
    if w > 0:
        dist[(sp, lvl)] = dist.get((sp, lvl), 0.0) + w


def grass_target(grass):
    """grass: {version: {rates:{t:{byte}}, slots:{t:[...]}}} -> (dist over (species, level), mean steps)"""
    dist = {}
    enc_per_step = 0.0
    for v in VERSIONS:
        g = grass[v]
        tw = {t: HOURS[t] * g["rates"][t]["byte"] for t in TIMES}  # encounter share ~ hours x rate
        tot = sum(tw.values())
        for t in TIMES:
            enc_per_step += 0.5 * HOURS[t] / 24.0 / gs_mean_steps(g["rates"][t]["byte"])
            if tot == 0:
                continue
            for s, pct in zip(g["slots"][t], GRASS_PCT):
                add(dist, s["species"], s["level"], 0.5 * tw[t] / tot * pct / 100.0)
    return dist, 1.0 / enc_per_step


def surf_target(surf):
    dist = {}
    enc_per_step = 0.0
    for v in VERSIONS:
        w = surf[v]
        enc_per_step += 0.5 / gs_mean_steps(w["rate"]["byte"])
        for s, pct in zip(w["slots"], SURF_PCT):
            for bonus, pb in SURF_BONUS:
                add(dist, s["species"], s["level"] + bonus, 0.5 * pct / 100.0 * pb)
    return dist, 1.0 / enc_per_step


def rod_target(fish, rod):
    """fish: {version: {old/good/super: [...]}} -> dist for one rod, blending day/nite columns."""
    dist = {}
    for v in VERSIONS:
        for e in fish[v][rod]:
            p = e["prob_256"] / 256.0
            if "time_group" in e:
                for col, hrs in FISH_HOURS.items():
                    add(dist, e[col]["species"], e[col]["level"], 0.5 * p * hrs / 24.0)
            else:
                add(dist, e["species"], e["level"], 0.5 * p)
    return dist


def rock_target(rs):
    dist = {}
    for v in VERSIONS:
        for s in rs[v]["slots"]:
            add(dist, s["species"], s["level"], 0.5 * s["percent"] / 100.0)
    return dist


def contest_target(mons):
    dist = {}
    for m in mons:
        n = m["max_level"] - m["min_level"] + 1
        for lvl in range(m["min_level"], m["max_level"] + 1):
            add(dist, m["species"], lvl, m["percent"] / 100.0 / n)
    return dist


def mix(base, other, w):
    out = {}
    for k, p in base.items():
        out[k] = out.get(k, 0.0) + (1 - w) * p
    for k, p in other.items():
        out[k] = out.get(k, 0.0) + w * p
    return out


def species_totals(dist):
    t = defaultdict(float)
    for (sp, _), p in dist.items():
        t[sp] += p
    return dict(t)


# ------------------------------------------------------------------ slot fitting
def fit_species_counts(targets_pct, slot_rates):
    """Exact DP: choose how many slots of each rate class every species gets.
    Every species gets >= 1 slot, every slot is used. Cost (lexicographic):
      1) L1 = sum |q_s - P_s|   (2x total-variation distance, percent points)
      2) chi = sum (q_s - P_s)^2 / P_s   (relative error tie-break)
    Returns {species: {rate: count}}."""
    classes = sorted(set(slot_rates), reverse=True)
    avail = tuple(slot_rates.count(c) for c in classes)
    species = sorted(targets_pct, key=lambda s: (-targets_pct[s], s))
    n = len(species)
    assert n <= len(slot_rates)

    # all allocation vectors (per class counts) with at least one slot
    allocs = [()]
    for a in avail:
        allocs = [x + (c,) for x in allocs for c in range(a + 1)]
    allocs = [a for a in allocs if sum(a) > 0]
    alloc_sum = {a: sum(c * r for c, r in zip(a, classes)) for a in allocs}

    def cost(sp, a):
        q = alloc_sum[a]
        P = targets_pct[sp]
        return (round(abs(q - P), 9), (q - P) ** 2 / P)

    @lru_cache(maxsize=None)
    def solve(i, rem):
        if i == n:
            return ((0.0, 0.0), ()) if sum(rem) == 0 else None
        # remaining species each need >= 1 slot
        if sum(rem) < n - i:
            return None
        best = None
        sp = species[i]
        for a in allocs:
            if any(x > y for x, y in zip(a, rem)):
                continue
            nrem = tuple(y - x for x, y in zip(a, rem))
            sub = solve(i + 1, nrem)
            if sub is None:
                continue
            c = cost(sp, a)
            tot = (round(c[0] + sub[0][0], 9), c[1] + sub[0][1])
            if best is None or tot < best[0]:
                best = (tot, (a,) + sub[1])
        return best

    res = solve(0, avail)
    solve.cache_clear()
    assert res is not None
    return {sp: dict(zip(classes, a)) for sp, a in zip(species, res[1])}, res[0]


def place_slots(counts, targets_pct, slot_rates):
    """Map per-class counts to concrete FR slot indices. Within each rate class, more common species first."""
    order = sorted(counts, key=lambda s: (-targets_pct[s], s))
    slot_species = [None] * len(slot_rates)
    for rate in sorted(set(slot_rates), reverse=True):
        idxs = [i for i, r in enumerate(slot_rates) if r == rate]
        for sp in order:
            for _ in range(counts[sp].get(rate, 0)):
                slot_species[idxs.pop(0)] = sp
    assert all(slot_species)
    return slot_species


def _quantile_ranges(levels, rates):
    """Quantile mapping: slot j covers the cumulative-probability interval proportional to its rate; its range is
    min..max of the G/S levels whose probability mass overlaps that interval."""
    tot = sum(p for _, p in levels)
    rtot = float(sum(rates))
    lv_iv = []
    c = 0.0
    for lvl, p in levels:
        lv_iv.append((lvl, c, c + p / tot))
        c += p / tot
    out = []
    c = 0.0
    for r in rates:
        a, b = c, c + r / rtot
        c = b
        hit = [lvl for lvl, x, y in lv_iv if min(b, y) - max(a, x) > 1e-9]
        if not hit:
            hit = [min(lv_iv, key=lambda t: abs((t[1] + t[2]) / 2 - (a + b) / 2))[0]]
        out.append((min(hit), max(hit)))
    return out


def _level_err(levels_t, rates, ranges):
    """L1 between the species' target level distribution and the uniform-in-range mixture FireRed produces."""
    rtot = float(sum(rates))
    prod = defaultdict(float)
    for r, (a, b) in zip(rates, ranges):
        w = r / rtot / (b - a + 1)
        for l in range(a, b + 1):
            prod[l] += w
    keys = set(prod) | set(levels_t)
    return sum(abs(prod.get(l, 0.0) - levels_t.get(l, 0.0)) for l in keys)


def _best_ranges(levels, rates, limit=40000):
    """Choose a [min,max] range per slot (endpoints restricted to G/S levels of this species) minimising the level
    L1 error; tie-break: total width, then quantile-mapping order. Exhaustive over per-rate multisets when small,
    otherwise coordinate descent from the quantile solution."""
    from itertools import combinations_with_replacement, product
    tot = sum(p for _, p in levels)
    lt = {l: p / tot for l, p in levels}
    lset = sorted(lt)
    cands = [(a, b) for i, a in enumerate(lset) for b in lset[i:]]
    q = _quantile_ranges(levels, rates)
    if len(lset) == 1:
        return [(lset[0], lset[0])] * len(rates)

    def score(rg):
        return (round(_level_err(lt, rates, rg), 9), sum(b - a for a, b in rg))

    best_rg, best_sc = q, score(q)
    classes = sorted(set(rates), reverse=True)
    idx_by_class = {c: [i for i, r in enumerate(rates) if r == c] for c in classes}
    n_combo = 1
    for c in classes:
        k = len(idx_by_class[c])
        n = len(cands)
        cnt = 1
        for j in range(k):
            cnt = cnt * (n + j) // (j + 1)
        n_combo *= cnt
    if n_combo <= limit:
        per_class = [list(combinations_with_replacement(cands, len(idx_by_class[c]))) for c in classes]
        for choice in product(*per_class):
            rg = [None] * len(rates)
            for c, ch in zip(classes, choice):
                for i, r in zip(idx_by_class[c], ch):
                    rg[i] = r
            sc = score(rg)
            if sc < best_sc:
                best_sc, best_rg = sc, rg
    else:
        rg = list(q)
        improved = True
        while improved:
            improved = False
            for i in range(len(rates)):
                for cnd in cands:
                    if cnd == rg[i]:
                        continue
                    trial = rg[:i] + [cnd] + rg[i + 1:]
                    sc = score(trial)
                    if sc < best_sc:
                        best_sc, rg, improved = sc, trial, True
        best_rg = rg
    # within equal-rate slots, put lower ranges in earlier slots
    out = list(best_rg)
    for c in classes:
        idx = idx_by_class[c]
        for i, r in zip(idx, sorted(out[i] for i in idx)):
            out[i] = r
    return out


def assign_levels(slot_species, slot_rates, dist):
    """Per species, pick level ranges for its slots (see _best_ranges)."""
    out = [None] * len(slot_species)
    for sp in set(slot_species):
        idxs = [i for i, s in enumerate(slot_species) if s == sp]
        levels = sorted((lvl, p) for (s, lvl), p in dist.items() if s == sp)
        ranges = _best_ranges(levels, [slot_rates[i] for i in idxs])
        for i, (a, b) in zip(idxs, ranges):
            out[i] = {"min_level": a, "max_level": b, "species": sp}
    return out


def fr_level_dist(mons, slot_rates):
    """Distribution over (species, level) that FireRed produces from a slot table (uniform level in range)."""
    d = {}
    for m, r in zip(mons, slot_rates):
        n = m["max_level"] - m["min_level"] + 1
        for lvl in range(m["min_level"], m["max_level"] + 1):
            add(d, m["species"], lvl, r / 100.0 / n)
    return d


def tv(p, q):
    keys = set(p) | set(q)
    return 0.5 * sum(abs(p.get(k, 0.0) - q.get(k, 0.0)) for k in keys)


def fit_table(dist, slot_rates, elsewhere=None):
    """dist: {(species, level): prob}. Returns (mons, diagnostics)."""
    tot = sum(dist.values())
    assert abs(tot - 1.0) < 1e-9, tot
    sp_tot = species_totals(dist)
    targets = {s: 100.0 * p for s, p in sp_tot.items()}
    dropped = []
    elsewhere = elsewhere or {}
    while len(targets) > len(slot_rates):
        # More species than FR slots: drop the rarest species that stays obtainable in another regular table.
        # Tiers: 0 = in another table at this same location (other method/rod), 1 = in a regular table at another
        # reachable location, 2 = only in the Bug Contest map table, 3 = nowhere else (never chosen unless forced).
        def tier(sp):
            e = elsewhere.get(sp, {})
            if e.get("same_location"):
                return 0
            if e.get("other_locations"):
                return 1
            if e.get("event_only"):
                return 2
            return 3
        cand = sorted(targets, key=lambda s: (tier(s), targets[s], s))
        d = cand[0]
        e = elsewhere.get(d, {})
        dropped.append({"species": d, "target_pct": round(targets[d], 4), "tier": tier(d),
                        "available_elsewhere": tier(d) < 3,
                        "same_location": e.get("same_location", []),
                        "other_locations": e.get("other_locations", [])[:10],
                        "other_locations_count": len(e.get("other_locations", [])),
                        "event_only": e.get("event_only", [])})
        del targets[d]
    if dropped:
        # renormalise the kept species so the slot DP distributes the full 100%
        s = sum(targets.values())
        fit_targets = {k: v * 100.0 / s for k, v in targets.items()}
    else:
        fit_targets = targets
    counts, cost = fit_species_counts(fit_targets, slot_rates)
    slot_species = place_slots(counts, fit_targets, slot_rates)
    kept = {k: p for k, p in dist.items() if k[0] in fit_targets}
    ks = sum(kept.values())
    kept = {k: p / ks for k, p in kept.items()}
    mons = assign_levels(slot_species, slot_rates, kept)
    fr_sp = defaultdict(float)
    for m, r in zip(mons, slot_rates):
        fr_sp[m["species"]] += r
    target_species = {s: round(100.0 * p, 4) for s, p in sorted(sp_tot.items(), key=lambda kv: -kv[1])}
    species_tv = 0.5 * sum(abs(fr_sp.get(s, 0.0) - 100.0 * sp_tot.get(s, 0.0)) for s in set(fr_sp) | set(sp_tot))
    level_tv = 100.0 * tv(dist, fr_level_dist(mons, slot_rates))
    target_levels = defaultdict(dict)
    for (s, lvl), p in sorted(dist.items()):
        target_levels[s][lvl] = round(100.0 * p, 4)
    diag = {
        "target_species_pct": target_species,
        "fr_species_pct": dict(sorted(fr_sp.items(), key=lambda kv: -kv[1])),
        "species_tv_distance_pct": round(species_tv, 4),
        "species_max_abs_error_pct": round(max(abs(fr_sp.get(s, 0) - 100.0 * sp_tot.get(s, 0))
                                               for s in set(fr_sp) | set(sp_tot)), 4),
        "species_level_tv_distance_pct": round(level_tv, 4),
        "target_levels_pct": dict(target_levels),
        "dropped": dropped,
    }
    return mons, diag


# ------------------------------------------------------------------ main
ROD_KEYS = (("old", "old_rod"), ("good", "good_rod"), ("super", "super_rod"))


def build_targets(mp, L):
    """Main (regular) tables for one location: key -> dict(dist, steps, notes, extra)."""
    tabs = {}
    sw = L.get("swarm", {})
    if "grass" in L:
        dist, steps = grass_target(L["grass"])
        notes = []
        if "grass" in sw and SWARM_WEIGHT > 0:
            sdist, ssteps = grass_target(sw["grass"])
            dist = mix(dist, sdist, SWARM_WEIGHT)
            steps = 1.0 / ((1 - SWARM_WEIGHT) / steps + SWARM_WEIGHT / ssteps)
            notes.append("swarm table mixed in at weight %.3f" % SWARM_WEIGHT)
        tabs["land_mons"] = {"dist": dist, "steps": steps, "notes": notes,
                             "extra": {"gs_rate_bytes": {v: {t: L["grass"][v]["rates"][t]["byte"] for t in TIMES}
                                                         for v in VERSIONS}}}
    if mp == raw["bug_contest"]["map"]:
        steps = gs_mean_steps(raw["bug_contest"]["encounter_byte"]["tall_grass"])
        tabs["land_mons"] = {"dist": contest_target(raw["bug_contest"]["mons"]), "steps": steps,
                             "notes": ["Bug Catching Contest (Tue/Thu/Sat) ContestMons; G/S rate 20% per step in tall "
                                       "grass (40% in super-tall grass); levels uniform min..max"], "extra": {}}
    if "surf" in L:
        dist, steps = surf_target(L["surf"])
        notes = []
        if "surf" in sw and SWARM_WEIGHT > 0:
            sdist, ssteps = surf_target(sw["surf"])
            dist = mix(dist, sdist, SWARM_WEIGHT)
            steps = 1.0 / ((1 - SWARM_WEIGHT) / steps + SWARM_WEIGHT / ssteps)
            notes.append("swarm table mixed in at weight %.3f" % SWARM_WEIGHT)
        tabs["water_mons"] = {"dist": dist, "steps": steps, "notes": notes,
                              "extra": {"gs_rate_bytes": {v: L["surf"][v]["rate"]["byte"] for v in VERSIONS}}}
    if "rock_smash" in L:
        tabs["rock_smash_mons"] = {"dist": rock_target(L["rock_smash"]), "steps": None,
                                   "notes": ["G/S RockMonEncounter: 4/10 chance per rock -> FR encounter_rate 40"],
                                   "extra": {}}
    if "fishing" in L:
        for rod, key in ROD_KEYS:
            d = rod_target(L["fishing"], rod)
            notes = []
            if "fishing" in sw and SWARM_WEIGHT > 0:
                d = mix(d, rod_target(sw["fishing"], rod), SWARM_WEIGHT)
                notes.append("swarm group %s mixed in at weight %.3f" % (sw["fishing"]["fish_group"], SWARM_WEIGHT))
            tabs[key] = {"dist": d, "steps": None, "notes": notes, "extra": {}}
    return tabs


def headbutt_effective(hb_v):
    """Per-tree G/S headbutt odds: 5/10 trees 'bad' (10% enc, common), 4/10 'good' (50%, common),
    1/10 'rare' (80%, rare table). Returns (dist over species/level, encounter chance per random tree)."""
    d = {}
    for e in hb_v["common"]:
        add(d, e["species"], e["level"], (0.5 * 0.1 + 0.4 * 0.5) * e["percent"] / 100.0)
    for e in hb_v["rare"]:
        add(d, e["species"], e["level"], 0.1 * 0.8 * e["percent"] / 100.0)
    tot = sum(d.values())
    return {k: v / tot for k, v in d.items()}, tot


def main():
    locs = raw["locations"]
    targets = {mp: build_targets(mp, L) for mp, L in locs.items()}
    # global index of where each species appears in a regular table
    avail = defaultdict(set)
    for mp, tabs in targets.items():
        if not locs[mp]["reachable_in_gs"]:
            continue
        for key, t in tabs.items():
            for sp in species_totals(t["dist"]):
                avail[sp].add((mp, key))
    event_maps = {raw["bug_contest"]["map"]}

    out_locs = {}
    for mp, L in locs.items():
        tabs = targets[mp]
        if not tabs and "headbutt" not in L and "swarm" not in L:
            continue
        T = {"name": L["name"], "map_const": mp, "pret_map_group": L["map_group_name"], "pret_map_num": L["map_num"],
             "region": L["region"], "environment": L["environment"], "reachable_in_gs": L["reachable_in_gs"]}
        fit = {}
        fitted = {}
        for key, t in tabs.items():
            slots = FR_SLOTS[key]
            elsewhere = {}
            for sp in species_totals(t["dist"]):
                others = avail[sp] - {(mp, key)}
                elsewhere[sp] = {
                    "same_location": sorted(k for m2, k in others if m2 == mp),
                    "other_locations": sorted("%s:%s" % (m2, k) for m2, k in others
                                              if m2 != mp and m2 not in event_maps),
                    "event_only": sorted("%s:%s" % (m2, k) for m2, k in others if m2 in event_maps),
                }
            mons, diag = fit_table(t["dist"], slots, elsewhere)
            diag["notes"] = t["notes"]
            diag.update(t["extra"])
            if t["steps"] is not None:
                rate, fr_steps = best_fr_rate(t["steps"])
                diag["gs_mean_steps_between_encounters"] = round(t["steps"], 3)
                diag["fr_mean_steps_between_encounters"] = round(fr_steps, 3)
            elif key == "rock_smash_mons":
                rate = round(100 * L["rock_smash"]["encounter_chance"])
            else:
                rate = FISHING_RATE_UNUSED
            fitted[key] = (rate, mons)
            fit[key] = diag
        for key in ("land_mons", "water_mons", "rock_smash_mons"):
            if key in fitted:
                T[key] = {"encounter_rate": fitted[key][0], "mons": fitted[key][1]}
        if "old_rod" in fitted:
            T["fishing_mons"] = {"encounter_rate": FISHING_RATE_UNUSED,
                                 "mons": fitted["old_rod"][1] + fitted["good_rod"][1] + fitted["super_rod"][1]}
            fit["fishing_mons"] = {"fish_group": L["fishing"]["fish_group"],
                                   "old_rod": fit.pop("old_rod"), "good_rod": fit.pop("good_rod"),
                                   "super_rod": fit.pop("super_rod")}
        if fit:
            T["_fit"] = fit

        # ---- optional extras (not FireRed table types): swarm-only tables and headbutt suggestion
        extra = {}
        sw = L.get("swarm", {})
        if sw:
            sx = {"note": "G/S phone-triggered swarm: replaces this map's table for the day. Standalone FR-format "
                          "table(s) in case a swarm mechanic is implemented; main tables use swarm_weight=%.3f"
                          % SWARM_WEIGHT}
            if "grass" in sw:
                d, st = grass_target(sw["grass"])
                m, dg = fit_table(d, FR_SLOTS["land_mons"])
                sx["land_mons"] = {"encounter_rate": best_fr_rate(st)[0], "mons": m,
                                   "species_tv_distance_pct": dg["species_tv_distance_pct"]}
            if "surf" in sw:
                d, st = surf_target(sw["surf"])
                m, dg = fit_table(d, FR_SLOTS["water_mons"])
                sx["water_mons"] = {"encounter_rate": best_fr_rate(st)[0], "mons": m,
                                    "species_tv_distance_pct": dg["species_tv_distance_pct"]}
            if "fishing" in sw:
                mm = []
                for rod, key in ROD_KEYS:
                    m, dg = fit_table(rod_target(sw["fishing"], rod), FR_SLOTS[key])
                    mm += m
                sx["fishing_mons"] = {"encounter_rate": FISHING_RATE_UNUSED, "mons": mm,
                                      "fish_group": sw["fishing"]["fish_group"]}
            extra["swarm"] = sx
        if "headbutt" in L and L["headbutt"]["usable"]:
            d = {}
            chance = 0
            for v in VERSIONS:
                dv, ch = headbutt_effective(L["headbutt"][v])
                chance += 0.5 * ch
                for k, p in dv.items():
                    add(d, k[0], k[1], 0.5 * p)
            m, dg = fit_table(d, FR_SLOTS["land_mons"])
            extra["headbutt"] = {"note": "FireRed has no headbutt. Suggested 12-slot (land-format) table from the G/S "
                                         "%s set blended Gold/Silver 50/50 over tree types; G/S chance of an "
                                         "encounter per random tree = %.1f%%" % (L["headbutt"]["set"], 100 * chance),
                                 "tree_set": L["headbutt"]["set"], "encounter_chance_per_tree": round(chance, 4),
                                 "mons": m, "target_species_pct": dg["target_species_pct"],
                                 "species_tv_distance_pct": dg["species_tv_distance_pct"]}
        if extra:
            T["_extra"] = extra
        if fit or extra:
            out_locs[mp] = T

    # ------------------------------------------------------------------ validation
    problems = []
    all_targets = set(avail)
    got_global = set()
    for mp, T in out_locs.items():
        for key, slots in (("land_mons", FR_SLOTS["land_mons"]), ("water_mons", FR_SLOTS["water_mons"]),
                           ("rock_smash_mons", FR_SLOTS["rock_smash_mons"]),
                           ("fishing_mons", FR_SLOTS["old_rod"] + FR_SLOTS["good_rod"] + FR_SLOTS["super_rod"])):
            if key not in T:
                continue
            mons = T[key]["mons"]
            if len(mons) != len(slots) or sum(slots) != (100 if key != "fishing_mons" else 300):
                problems.append((mp, key, "slot count/rates"))
            got_global |= {m["species"] for m in mons}
            for m in mons:
                if not (1 <= m["min_level"] <= m["max_level"] <= 100):
                    problems.append((mp, key, "bad levels %s" % m))
            diags = ([T["_fit"][key]] if key != "fishing_mons" else
                     [T["_fit"][key][k] for _, k in ROD_KEYS])
            sub = ([mons] if key != "fishing_mons" else [mons[0:2], mons[2:5], mons[5:10]])
            for dg, mm in zip(diags, sub):
                tgt = set(dg["target_species_pct"])
                got = {m["species"] for m in mm}
                if not got <= tgt:
                    problems.append((mp, key, "species not in G/S target: %s" % (got - tgt)))
                missing = tgt - got - {x["species"] for x in dg["dropped"]}
                if missing:
                    problems.append((mp, key, "missing species %s" % missing))
                for x in dg["dropped"]:
                    if not x["available_elsewhere"]:
                        problems.append((mp, key, "dropped species with no other source " + x["species"]))
                # every species gets >=1 slot unless dropped; check exact rates
                fr = defaultdict(float)
                for m in mm:
                    fr[m["species"]] += 0
    dropped_all = []
    for mp, T in out_locs.items():
        for key, dg in T.get("_fit", {}).items():
            dl = [dg] if key != "fishing_mons" else [dg[k] for _, k in ROD_KEYS]
            for d in dl:
                for x in d["dropped"]:
                    dropped_all.append({"location": mp, "table": key, **x})
    global_missing = sorted(all_targets - got_global)
    if global_missing:
        problems.append(("GLOBAL", "obtainability", global_missing))

    meta = {
        "source": raw["source"],
        "fr_slot_rates": FR_SLOTS,
        "fr_fishing_groups": {"old_rod": [0, 1], "good_rod": [2, 3, 4], "super_rod": [5, 6, 7, 8, 9]},
        "blend": {
            "versions": "Gold 50% / Silver 50%",
            "time_weights_hours": HOURS,
            "time_weighting": "within a version, period t weighted by hours_t x G/S encounter byte_t (share of "
                              "encounters met walking uniformly round the clock); identical to pure hour weighting "
                              "whenever morn/day/nite rates are equal",
            "fishing_time_weights_hours": FISH_HOURS,
            "surf_levels": "G/S adds +0/+1/+2/+3/+4 to surf levels with prob 89/76/51/26/14 of 256; included in target",
            "swarm_weight": SWARM_WEIGHT,
        },
        "encounter_rate_conversion": "land/water: integer FR rate r whose expected steps between encounters "
                                     "(FR cooldown minSteps=8-r/10 with 5% leak, buff +r per failed roll, 1600 scale) "
                                     "is closest in log space to the G/S expectation (4 blocked steps after map "
                                     "load/battle + 256/byte), blended as encounters-per-step over versions/time "
                                     "periods. rock smash: G/S 40% per rock -> 40. fishing: FR field unused "
                                     "(bite 50% = G/S 128/256) -> 20.",
        "fit_objective": "exact DP over slot-count allocations; every species with nonzero probability gets >=1 slot; "
                         "minimise L1 species error, tie-break sum (q-p)^2/p; levels by quantile mapping per species",
        "validation_problems": problems,
        "dropped_species": dropped_all,
        "species_only_via_special_methods": sorted(
            set(build_species_info_cache()) - all_targets),
    }
    json.dump({"_meta": meta, "locations": out_locs}, open(OUT_TABLES, "w"), indent=1)
    json.dump(gs_species_info_out(build_species_info_cache()), open(OUT_SPECIES, "w"), indent=1)
    print("locations", len(out_locs), "problems", problems)
    print("dropped", dropped_all)


_SPINFO = None


def build_species_info_cache():
    global _SPINFO
    if _SPINFO is None:
        _SPINFO = build_species_info(raw["locations"])
    return _SPINFO


# ------------------------------------------------------------------ species info
def build_species_info(locs):
    """species -> list of occurrences {location, method, versions, times, share, levels}"""
    info = defaultdict(list)

    def rec(sp, **kw):
        info[sp].append(kw)

    for mp, L in locs.items():
        base = {"location": mp, "name": L["name"], "region": L["region"], "environment": L["environment"],
                "reachable_in_gs": L["reachable_in_gs"]}
        if "grass" in L:
            dist, _ = grass_target(L["grass"])
            per = occurrences_grass(L["grass"])
            for sp, p in species_totals(dist).items():
                lv = sorted({l for (s, l) in dist if s == sp})
                rec(sp, method=WALK_METHOD.get(L["environment"], "dungeon"),
                    share_pct=round(100 * p, 3), levels=[lv[0], lv[-1]], **per[sp], **base)
        if "surf" in L:
            dist, _ = surf_target(L["surf"])
            vers = defaultdict(set)
            for v in VERSIONS:
                for s in L["surf"][v]["slots"]:
                    vers[s["species"]].add(v)
            for sp, p in species_totals(dist).items():
                lv = sorted({l for (s, l) in dist if s == sp})
                rec(sp, method="surf", share_pct=round(100 * p, 3), levels=[lv[0], lv[-1]],
                    versions=sorted(vers[sp]), times=list(TIMES), **base)
        if "fishing" in L:
            for rod in ("old", "good", "super"):
                d = rod_target(L["fishing"], rod)
                for sp, p in species_totals(d).items():
                    lv = sorted({l for (s, l) in d if s == sp})
                    times = set()
                    for e in L["fishing"]["gold"][rod]:
                        if "time_group" in e:
                            if e["day"]["species"] == sp:
                                times |= {"morn", "day"}
                            if e["nite"]["species"] == sp:
                                times.add("nite")
                        elif e["species"] == sp:
                            times |= set(TIMES)
                    rec(sp, method=rod + "_rod", share_pct=round(100 * p, 3), levels=[lv[0], lv[-1]],
                        versions=list(VERSIONS), times=sorted(times, key=TIMES.index), **base)
        if "rock_smash" in L:
            d = rock_target(L["rock_smash"])
            for sp, p in species_totals(d).items():
                lv = sorted({l for (s, l) in d if s == sp})
                rec(sp, method="rock_smash", share_pct=round(100 * p, 3), levels=[lv[0], lv[-1]],
                    versions=list(VERSIONS), times=list(TIMES), **base)
        if "headbutt" in L and L["headbutt"]["usable"]:
            for v in VERSIONS:
                hb = L["headbutt"][v]
                eff = defaultdict(float)
                for e in hb["common"]:
                    eff[e["species"]] += (0.5 * 0.1 + 0.4 * 0.5) * e["percent"] / 100.0
                for e in hb["rare"]:
                    eff[e["species"]] += 0.1 * 0.8 * e["percent"] / 100.0
                tot = sum(eff.values())
                for sp, p in eff.items():
                    lvls = sorted({e["level"] for e in hb["common"] + hb["rare"] if e["species"] == sp})
                    rec(sp, method="headbutt", share_pct=round(100 * p / tot, 3), levels=[lvls[0], lvls[-1]],
                        versions=[v], times=list(TIMES), **base)
        sw = L.get("swarm", {})
        if "grass" in sw:
            dist, _ = grass_target(sw["grass"])
            per = occurrences_grass(sw["grass"])
            for sp, p in species_totals(dist).items():
                lv = sorted({l for (s, l) in dist if s == sp})
                rec(sp, method="swarm_grass", share_pct=round(100 * p, 3), levels=[lv[0], lv[-1]], **per[sp], **base)
        if "surf" in sw:
            dist, _ = surf_target(sw["surf"])
            for sp, p in species_totals(dist).items():
                lv = sorted({l for (s, l) in dist if s == sp})
                rec(sp, method="swarm_surf", share_pct=round(100 * p, 3), levels=[lv[0], lv[-1]],
                    versions=list(VERSIONS), times=list(TIMES), **base)
        if "fishing" in sw:
            for rod in ("old", "good", "super"):
                d = rod_target(sw["fishing"], rod)
                for sp, p in species_totals(d).items():
                    lv = sorted({l for (s, l) in d if s == sp})
                    rec(sp, method="swarm_" + rod + "_rod", share_pct=round(100 * p, 3), levels=[lv[0], lv[-1]],
                        versions=list(VERSIONS), times=list(TIMES), **base)
    for m in raw["bug_contest"]["mons"]:
        L = locs[raw["bug_contest"]["map"]]
        rec(m["species"], method="bug_contest", share_pct=m["percent"], levels=[m["min_level"], m["max_level"]],
            versions=list(VERSIONS), times=list(TIMES), location=raw["bug_contest"]["map"], name=L["name"],
            region="johto", environment="ROUTE", reachable_in_gs=True)
    return info


def occurrences_grass(grass):
    per = defaultdict(lambda: {"versions": set(), "times": set()})
    for v in VERSIONS:
        for t in TIMES:
            for s in grass[v]["slots"][t]:
                per[s["species"]]["versions"].add(v)
                per[s["species"]]["times"].add(t)
    return {sp: {"versions": sorted(x["versions"]), "times": sorted(x["times"], key=TIMES.index)}
            for sp, x in per.items()}


WALK_METHOD = {"ROUTE": "grass", "TOWN": "grass", "CAVE": "cave", "DUNGEON": "dungeon"}
TABLE_METHODS = {"grass", "cave", "dungeon", "surf", "old_rod", "good_rod", "super_rod", "rock_smash"}


def gs_species_info_out(info):
    species = {}
    for sp in sorted(info):
        occ = sorted(info[sp], key=lambda o: -o["share_pct"])
        methods = sorted({o["method"] for o in occ})
        versions = sorted({v for o in occ for v in o["versions"]})
        reach = [o for o in occ if o["reachable_in_gs"]]
        table_occ = [o for o in reach if o["method"] in TABLE_METHODS]
        special_only = not table_occ
        # typical habitat: prefer regular table methods; rank by share, then lowest level (earliest)
        pool = table_occ or reach or occ
        best = sorted(pool, key=lambda o: (-o["share_pct"], o["levels"][0]))[0]
        lv_lo = min(o["levels"][0] for o in pool)
        lv_hi = max(o["levels"][1] for o in pool)
        env_counts = defaultdict(float)
        for o in pool:
            env_counts[(o["method"], o["environment"])] += o["share_pct"]
        habitat = sorted(env_counts.items(), key=lambda kv: -kv[1])[0][0]
        times = sorted({t for o in pool for t in o["times"]}, key=TIMES.index)
        species[sp] = {
            "versions": versions,
            "version_exclusive": versions[0] if len(versions) == 1 else None,
            "methods": methods,
            "only_via_special": special_only,  # swarm / headbutt / bug contest only
            "times": times,
            "typical": {
                "method": habitat[0], "environment": habitat[1],
                "region": best["region"],
                "best_location": best["location"], "best_location_share_pct": best["share_pct"],
                "level_range": [lv_lo, lv_hi],
                "best_location_levels": best["levels"],
            },
            "locations": [{k: o[k] for k in ("location", "method", "share_pct", "levels", "versions", "times")}
                          for o in occ],
        }
    special = {s: v["methods"] for s, v in species.items() if v["only_via_special"]}
    # habitat index: method -> region -> species -> level range / locations (reachable maps only)
    index = {}
    for sp in sorted(info):
        for o in info[sp]:
            if not o["reachable_in_gs"]:
                continue
            e = index.setdefault(o["method"], {}).setdefault(o["region"], {}).setdefault(
                sp, {"min_level": 999, "max_level": 0, "max_share_pct": 0.0, "locations": []})
            e["min_level"] = min(e["min_level"], o["levels"][0])
            e["max_level"] = max(e["max_level"], o["levels"][1])
            e["max_share_pct"] = max(e["max_share_pct"], o["share_pct"])
            if o["location"] not in e["locations"]:
                e["locations"].append(o["location"])
    return {"_meta": {"source": raw["source"], "count": len(species),
                      "note": "species obtainable in the wild in Gold or Silver via grass/cave walking, surf, old/good/"
                              "super rod, rock smash, headbutt (FOREST/CANYON trees only; CITY/NONE sets give no "
                              "encounters), phone swarms and the Bug Catching Contest. Roaming legendaries and static/"
                              "gift Pokemon are not included. share_pct = share of encounters of that method at that "
                              "location (G/S 50/50, time-blended).",
                      "only_via_special_methods": special,
                      "fr_species_constants": sorted(species)},
            "species": species,
            "habitat_index": index}


if __name__ == "__main__":
    main()
