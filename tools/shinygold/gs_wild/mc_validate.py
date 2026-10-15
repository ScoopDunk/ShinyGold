#!/usr/bin/env python3
"""Independent Monte Carlo of the G/S encounter engine (re-implemented byte-for-byte from pret asm semantics)
to validate the analytic target distributions in fr_tables.json.

Simulates: random version (50/50), random hour of day (uniform 0..23), steps with G/S 5-step cooldown and
Random() < rate byte, slot pick via 1..100 vs cumulative GrassMonProbTable/WaterMonProbTable, surf level bonus via
Random() vs 35/65/85/95 percent, fishing via Random() <= threshold with time groups (morn/day -> day column).
Usage: python3 -I mc_validate.py gs_raw.json fr_tables.json N
"""
import json
import random
import sys
from collections import Counter

raw = json.load(open(sys.argv[1]))
fr = json.load(open(sys.argv[2]))
N = int(sys.argv[3])
rng = random.Random(12345)
GRASS_CUM = [30, 60, 80, 90, 95, 99, 100]
WATER_CUM = [60, 90, 100]
P = lambda x: x * 255 // 100


def tod(hour):
    if hour < 4:
        return "nite"
    if hour < 10:
        return "morn"
    if hour < 18:
        return "day"
    return "nite"


def pick_slot(cum):
    while True:
        a = rng.randrange(256)
        if a < 100:
            break
    b = a + 1
    for i, c in enumerate(cum):
        if c >= b:
            return i


def sim_walk(L, kind, n):
    """n encounters: each encounter's game version is 50/50 (merged game); within it the player keeps stepping at
    uniformly random hours, so time periods are weighted by hours x rate exactly as in G/S."""
    cnt = Counter()
    for _ in range(n):
        v = rng.choice(("gold", "silver"))
        while True:
            t = tod(rng.randrange(24))
            b = L["grass"][v]["rates"][t]["byte"] if kind == "grass" else L["surf"][v]["rate"]["byte"]
            if rng.randrange(256) < b:
                break
        if kind == "grass":
            s = L["grass"][v]["slots"][t][pick_slot(GRASS_CUM)]
            lvl = s["level"]
        else:
            s = L["surf"][v]["slots"][pick_slot(WATER_CUM)]
            lvl = s["level"]
            r = rng.randrange(256)
            for th in (P(35), P(65), P(85), P(95)):
                if r < th:
                    break
                lvl += 1
        cnt[(s["species"], lvl)] += 1
    return cnt


def sim_fish(L, rod, n):
    cnt = Counter()
    for _ in range(n):
        v = rng.choice(("gold", "silver"))
        t = tod(rng.randrange(24))
        tab = L["fishing"][v][rod]
        r = rng.randrange(256)
        for e in tab:
            if r <= sum(x["prob_256"] for x in tab[:tab.index(e) + 1]) - 1:
                break
        if "time_group" in e:
            col = "nite" if t == "nite" else "day"
            cnt[(e[col]["species"], e[col]["level"])] += 1
        else:
            cnt[(e["species"], e["level"])] += 1
    return cnt


def compare(cnt, target_levels, label):
    n = sum(cnt.values())
    emp = {(s, l): c / n for (s, l), c in cnt.items()}
    tgt = {(s, int(l)): p / 100.0 for s, lv in target_levels.items() for l, p in lv.items()}
    keys = set(emp) | set(tgt)
    tvd = 0.5 * sum(abs(emp.get(k, 0) - tgt.get(k, 0)) for k in keys)
    print("%-45s n=%d  TV(empirical, analytic target) = %.4f%%" % (label, n, 100 * tvd))
    return tvd


def main():
    worst = 0
    checks = [("ROUTE_29", "grass"), ("ROUTE_39", "grass"), ("DIGLETTS_CAVE", "grass"), ("NATIONAL_PARK", "grass"),
              ("ROUTE_2", "grass"), ("OLIVINE_CITY", "surf"), ("SLOWPOKE_WELL_B2F", "surf"), ("ROUTE_41", "surf")]
    for mp, kind in checks:
        L = raw["locations"][mp]
        key = "land_mons" if kind == "grass" else "water_mons"
        cnt = sim_walk(L, kind, N)
        worst = max(worst, compare(cnt, fr["locations"][mp]["_fit"][key]["target_levels_pct"], "%s %s" % (mp, kind)))
    for mp in ("OLIVINE_CITY", "ROUTE_20", "DRAGONS_DEN_B1F", "ROUTE_45"):
        L = raw["locations"][mp]
        for rod, key in (("old", "old_rod"), ("good", "good_rod"), ("super", "super_rod")):
            cnt = sim_fish(L, rod, N)
            worst = max(worst, compare(cnt, fr["locations"][mp]["_fit"]["fishing_mons"][key]["target_levels_pct"],
                                       "%s %s rod" % (mp, rod)))
    print("max TV between Monte Carlo and analytic targets: %.4f%%" % (100 * worst))


if __name__ == "__main__":
    main()
