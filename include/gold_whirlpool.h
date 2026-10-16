#ifndef GUARD_GOLD_WHIRLPOOL_H
#define GUARD_GOLD_WHIRLPOOL_H

// Pure Gold/Silver build: HM06 WHIRLPOOL, which LANCE gives in the Mahogany Rocket base.
// FireRed has no HM for WHIRLPOOL and the item list must not change, so the key item ITEM_DEVON_GOODS,
// which ShinyGold already names "HM WHIRLPOOL", teaches WHIRLPOOL from the KEY ITEMS pocket like an HM
// (reusable, to the POKéMON that can learn HM06 in Gold/Silver). See src/gold_whirlpool.c.

#define ITEM_HM_WHIRLPOOL ITEM_DEVON_GOODS

bool8 IsWhirlpoolHM(u16 itemId);
bool8 CanSpeciesLearnWhirlpoolHM(u16 species);

#endif // GUARD_GOLD_WHIRLPOOL_H
