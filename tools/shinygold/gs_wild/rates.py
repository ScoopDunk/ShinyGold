"""Encounter-rate models for Gold/Silver and FireRed (expected steps between encounters)."""

GS_COOLDOWN_BLOCKED_STEPS = 4  # SetUpFiveStepWildEncounterCooldown: 5 -> first 4 steps blocked


def gs_mean_steps(rate_byte):
    """G/S: after map (re)load the first 4 steps can't encounter; then each step Random(0..255) < byte."""
    if rate_byte <= 0:
        return float("inf")
    return GS_COOLDOWN_BLOCKED_STEPS + 256.0 / rate_byte


def fr_min_steps(rate):
    if rate >= 80:
        return 0
    if rate < 10:
        return 8
    return 8 - rate // 10


def fr_mean_steps(rate, max_steps=20000, eps=1e-13):
    """FireRed (src/wild_encounter.c, no flute/cleanse tag/ability/bike, uniform terrain):
    after an encounter stepsSinceLastEncounter=0, encounterRateBuff=0.
    Each step: if stepsSince < minSteps: stepsSince++, and only 5% of steps continue to the rate test.
    Rate test: (WildEncounterRandom() % 1600) < min(1600, rate*16 + buff*16/200); on failure buff += rate.
    """
    if rate <= 0:
        return float("inf")
    ms = fr_min_steps(rate)
    # state: (stepsSince capped at ms, number of failed rate tests k) -> probability mass
    states = {(0, 0): 1.0}
    expect = 0.0
    alive = 1.0
    step = 0
    while alive > eps and step < max_steps:
        step += 1
        new = {}
        for (s, k), m in states.items():
            if s < ms:
                s2 = s + 1
                # 95%: gate fails, no test
                new[(s2, k)] = new.get((s2, k), 0.0) + m * 0.95
                mt = m * 0.05
            else:
                s2 = s
                mt = m
            thr = min(1600, rate * 16 + (k * rate) * 16 // 200)
            p = thr / 1600.0
            expect += step * mt * p
            new[(s2, k + 1)] = new.get((s2, k + 1), 0.0) + mt * (1 - p)
        states = new
        alive = sum(states.values())
    return expect + alive * step


def best_fr_rate(target_mean_steps, lo=1, hi=100):
    """Integer FR encounter_rate whose expected steps-between-encounters is closest (in log space)."""
    import math
    best = None
    for r in range(lo, hi + 1):
        e = fr_mean_steps(r)
        d = abs(math.log(e) - math.log(target_mean_steps))
        if best is None or d < best[0]:
            best = (d, r, e)
    return best[1], best[2]


if __name__ == "__main__":
    for r in list(range(1, 31)) + [40, 50]:
        print(r, fr_min_steps(r), round(fr_mean_steps(r), 2))
    for pct in (2, 4, 6, 8, 10, 20):
        b = pct * 255 // 100
        e = gs_mean_steps(b)
        print("G/S", pct, "% byte", b, "mean", round(e, 2), "-> FR", best_fr_rate(e))
