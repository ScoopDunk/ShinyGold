#ifndef GUARD_CONSTANTS_GOLD_KANTO_H
#define GUARD_CONSTANTS_GOLD_KANTO_H

// Pure Gold/Silver build: flags and vars for the Kanto story and the S.S. Aqua (worker W2).
// Reserved: flags 0x1C00-0x1C3F (save block extension), vars 0x4540-0x457F (save block extension).
// Nothing else in the tree uses these numbers.

// Power Plant: 1 = the officer's phone call about the shady character in Cerulean is pending
// (set when the player first talks to the manager), 2 = done or no longer needed (the Cerulean Gym scene ran).
#define VAR_GOLD_POWER_PLANT_SCENE      0x4540

// S.S. Aqua, first trip: 1 = the granddaughter reunion scene in her grandpa's cabin is pending
// (set when the player finds her in the captain's cabin), 0 = none.
#define VAR_GOLD_SS_AQUA_SCENE          0x4541

// Fuchsia, Warden's home: the Warden's granddaughter told the player why the SAFARI ZONE closed
// (pokegold EVENT_TALKED_TO_WARDENS_GRANDDAUGHTER).
#define FLAG_GOLD_TALKED_TO_WARDENS_GRANDDAUGHTER   0x1C00

// Pewter Pokémon Center: traded GLOOM for Chris's RAPIDASH (pokegold NPC_TRADE_CHRIS)
#define FLAG_GOLD_TRADED_WITH_CHRIS     0x1C01

#endif // GUARD_CONSTANTS_GOLD_KANTO_H
