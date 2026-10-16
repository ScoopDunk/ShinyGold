#ifndef GUARD_CONSTANTS_GOLD_LEGENDARIES_H
#define GUARD_CONSTANTS_GOLD_LEGENDARIES_H

// Pure Gold/Silver build: flags and vars for the legendary beasts, GS Ball and Celebi (worker W4).
// Reserved: flags 0x1C80-0x1CBF (save block extension), vars 0x45C0-0x45FF (save block extension).
// Nothing else in the tree uses these numbers.

// Roaming beasts (src/roamer.c): set by special InitRoamMons (Burned Tower scene). Saves from before the
// beasts roamed have the Burned Tower flag but not this one; roamer.c starts their beasts on the next map change.
#define FLAG_GOLD_ROAMERS_STARTED               0x1C80

// GS Ball event, as in Crystal (pokecrystal GoldenrodPokecenter1F, KurtsHouse, AzaleaTown, IlexForest,
// Route34IlexForestGate). Object hide flags; the map scripts set or clear them on every map load.
#define FLAG_GOLD_HIDE_GS_BALL_RECEPTIONIST     0x1C81  // Goldenrod POKéMON CENTER 1F: link receptionist
#define FLAG_GOLD_HIDE_AZALEA_KURT              0x1C82  // Azalea Town: Kurt waiting outside his house
#define FLAG_GOLD_HIDE_ILEX_KURT                0x1C83  // Ilex Forest: Kurt after Celebi was caught
#define FLAG_GOLD_HIDE_ILEX_CELEBI              0x1C84  // Ilex Forest: Celebi flying to the shrine
#define FLAG_GOLD_HIDE_ILEX_LASS                0x1C85  // Ilex Forest: lass (only while the forest is restless)
#define FLAG_GOLD_HIDE_ILEX_GATE_LASS           0x1C86  // Route 34 gate: lass (away while the forest is restless)
#define FLAG_GOLD_HIDE_ILEX_GATE_TEACHER        0x1C87  // Route 34 gate: teacher at her usual place
#define FLAG_GOLD_HIDE_ILEX_GATE_TEACHER_DOOR   0x1C88  // Route 34 gate: teacher blocking the way into the forest

// VAR_GOLD_GS_BALL: progress of the GS Ball event.
#define VAR_GOLD_GS_BALL                        0x45C0
#define GS_BALL_NOT_RECEIVED      0  // the player has not entered the HALL OF FAME / not been to Goldenrod's POKéMON CENTER yet
#define GS_BALL_RECEIVED          1  // Crystal EVENT_GOT_GS_BALL_FROM_GOLDENROD_POKEMON_CENTER + EVENT_CAN_GIVE_GS_BALL_TO_KURT
#define GS_BALL_KURT_CHECKING     2  // EVENT_GAVE_GS_BALL_TO_KURT; Kurt works on it for 500 steps (VAR_GOLD_GS_BALL_STEPS,
                                     // a stand-in for G/S's daily ENGINE_KURT_MAKING_BALLS)
#define GS_BALL_KURT_OUTSIDE      3  // EVENT_FOREST_IS_RESTLESS: Kurt ran out and waits in Azalea Town with the GS Ball
#define GS_BALL_RETURNED          4  // ENGINE_FOREST_IS_RESTLESS: the player has the GS Ball back, the forest is restless
#define GS_BALL_USED              5  // the GS Ball was put in the Ilex Forest shrine (Celebi event done)

// Steps walked while Kurt checks the GS Ball (its own counter, so it never shares the Apricorn ball timer).
#define VAR_GOLD_GS_BALL_STEPS                  0x45C1

#endif // GUARD_CONSTANTS_GOLD_LEGENDARIES_H
