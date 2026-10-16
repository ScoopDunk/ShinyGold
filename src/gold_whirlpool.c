#include "global.h"
#include "gold_whirlpool.h"
#include "constants/items.h"
#include "constants/species.h"

// Pure Gold/Silver build: HM06 WHIRLPOOL (see include/gold_whirlpool.h).

// The POKéMON that can learn HM06 WHIRLPOOL in Gold/Silver (pokegold data/pokemon/base_stats/*.asm).
static const u16 sWhirlpoolHMSpecies[] = {
    SPECIES_AZUMARILL,
    SPECIES_BLASTOISE,
    SPECIES_CHINCHOU,
    SPECIES_CLOYSTER,
    SPECIES_CORSOLA,
    SPECIES_CROCONAW,
    SPECIES_DEWGONG,
    SPECIES_DRAGONITE,
    SPECIES_FERALIGATR,
    SPECIES_GOLDUCK,
    SPECIES_GYARADOS,
    SPECIES_HORSEA,
    SPECIES_KABUTOPS,
    SPECIES_KINGDRA,
    SPECIES_KINGLER,
    SPECIES_KRABBY,
    SPECIES_LANTURN,
    SPECIES_LAPRAS,
    SPECIES_LUGIA,
    SPECIES_MANTINE,
    SPECIES_MARILL,
    SPECIES_MEW,
    SPECIES_OCTILLERY,
    SPECIES_OMANYTE,
    SPECIES_OMASTAR,
    SPECIES_POLITOED,
    SPECIES_POLIWAG,
    SPECIES_POLIWHIRL,
    SPECIES_POLIWRATH,
    SPECIES_PSYDUCK,
    SPECIES_QUAGSIRE,
    SPECIES_QWILFISH,
    SPECIES_REMORAID,
    SPECIES_SEADRA,
    SPECIES_SEEL,
    SPECIES_SHELLDER,
    SPECIES_SLOWKING,
    SPECIES_SQUIRTLE,
    SPECIES_STARMIE,
    SPECIES_STARYU,
    SPECIES_SUICUNE,
    SPECIES_TENTACOOL,
    SPECIES_TENTACRUEL,
    SPECIES_TOTODILE,
    SPECIES_VAPOREON,
    SPECIES_WARTORTLE,
    SPECIES_WOOPER,
};

bool8 IsWhirlpoolHM(u16 itemId)
{
    return itemId == ITEM_HM_WHIRLPOOL;
}

bool8 CanSpeciesLearnWhirlpoolHM(u16 species)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sWhirlpoolHMSpecies); i++)
    {
        if (sWhirlpoolHMSpecies[i] == species)
            return TRUE;
    }
    return FALSE;
}
