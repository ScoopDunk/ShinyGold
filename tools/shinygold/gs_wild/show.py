"""Pretty-print fitted FR tables vs G/S targets for given locations."""
import json, sys
f = json.load(open(sys.argv[1]))
RATES = {"land_mons": [20,20,10,10,10,10,5,5,4,4,1,1], "water_mons": [60,30,5,4,1], "rock_smash_mons": [60,30,5,4,1],
         "fishing_mons": [70,30,60,20,20,40,40,15,4,1]}
for mp in sys.argv[2:]:
    T = f["locations"][mp]
    print("==", mp, T["name"])
    for key in ("land_mons", "water_mons", "rock_smash_mons", "fishing_mons"):
        if key not in T:
            continue
        print(" ", key, "encounter_rate", T[key]["encounter_rate"])
        for m, r in zip(T[key]["mons"], RATES[key]):
            print("    %3d%%  %-20s L%d-%d" % (r, m["species"][8:], m["min_level"], m["max_level"]))
        dg = T["_fit"][key]
        subs = [dg] if key != "fishing_mons" else [dg[k] for k in ("old_rod", "good_rod", "super_rod")]
        for d in subs:
            tg = d["target_species_pct"]; fr = d["fr_species_pct"]
            print("    target vs FR:", ", ".join("%s %.2f/%g" % (s[8:], tg[s], fr.get(s, 0)) for s in tg),
                  "| TV %.2f%% lvlTV %.2f%%" % (d["species_tv_distance_pct"], d["species_level_tv_distance_pct"]))
            if "gs_mean_steps_between_encounters" in d:
                print("    steps G/S %.2f FR %.2f" % (d["gs_mean_steps_between_encounters"], d["fr_mean_steps_between_encounters"]))
            if d["dropped"]:
                print("    DROPPED:", [(x["species"], x["target_pct"]) for x in d["dropped"]])
