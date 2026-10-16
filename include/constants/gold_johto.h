#ifndef GUARD_CONSTANTS_GOLD_JOHTO_H
#define GUARD_CONSTANTS_GOLD_JOHTO_H

// Pure Gold/Silver build: flags and vars for the Johto story and the Bug-Catching Contest (worker W3).
// Reserved: flags 0x1C40-0x1C7F (save block extension), vars 0x4580-0x45BF (save block extension).
// Nothing else in the tree uses these numbers.

// Radio Tower LUCKY NUMBER SHOW (src/gold_lucky_number.c): 1 + the play-time "week" whose prize was won.
#define VAR_GOLD_LUCKY_NUMBER_WEEK 0x4580

#endif // GUARD_CONSTANTS_GOLD_JOHTO_H
