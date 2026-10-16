#include "global.h"
#include "data.h"
#include "event_data.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "string_util.h"
#include "constants/species.h"

// ShinyGold gold: the Radio Tower's LUCKY NUMBER SHOW as in Gold/Silver (pokegold maps/RadioTower1F.asm,
// engine/events/lucky_number.asm). G/S draws a new lucky number every week from the real-time clock; this
// game has no clock, so a "week" here is LUCKY_NUMBER_PLAY_HOURS hours of play time. One prize per week.
// All functions are called from scripts with callnative.

#define LUCKY_NUMBER_PLAY_HOURS 7

static u16 GetLuckyNumberWeek(void)
{
    return gSaveBlock2Ptr->playTimeHours / LUCKY_NUMBER_PLAY_HOURS;
}

// A number from 0 to 65535 that depends on the week and the player's ID.
static u16 GetLuckyNumber(void)
{
    u32 x = (GetLuckyNumberWeek() + 1) * 0x9E3779B1;

    x ^= gSaveBlock2Ptr->playerTrainerId[0] | (gSaveBlock2Ptr->playerTrainerId[1] << 8);
    x ^= x >> 16;
    x *= 0x85EBCA6B;
    x ^= x >> 13;
    x *= 0xC2B2AE35;
    x ^= x >> 16;
    return x;
}

// STR_VAR_1 = this week's lucky number (5 digits). VAR_RESULT = TRUE if this week's prize was already won.
void LuckyNumberShow_BufferNumber(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetLuckyNumber(), STR_CONV_MODE_LEADING_ZEROS, 5);
    gSpecialVar_Result = (VarGet(VAR_GOLD_LUCKY_NUMBER_WEEK) == GetLuckyNumberWeek() + 1);
}

// Number of matching trailing decimal digits (0-5).
static u8 CountMatchingDigits(u16 a, u16 b)
{
    u8 i;

    for (i = 0; i < 5 && a % 10 == b % 10; i++)
    {
        a /= 10;
        b /= 10;
    }
    return i;
}

// G/S prize place for a number of matching digits: 5 -> 1, 3-4 -> 2, 2 -> 3, else 0.
static u8 GetLuckyNumberPlace(u8 digits)
{
    if (digits == 5)
        return 1;
    if (digits >= 3)
        return 2;
    if (digits == 2)
        return 3;
    return 0;
}

// Checks the ID numbers of the party and of every PC box against the lucky number.
// VAR_RESULT = best place (1-3) or 0; STR_VAR_2 = that POKéMON; VAR_0x8005 = TRUE if it is in the PC.
void LuckyNumberShow_CheckWinners(void)
{
    u16 lucky = GetLuckyNumber();
    u8 best = 0, place;
    u16 bestSpecies = SPECIES_NONE;
    bool8 inPC = FALSE;
    u32 i, j;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];

        if (!GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES) || GetMonData(mon, MON_DATA_IS_EGG))
            continue;
        place = GetLuckyNumberPlace(CountMatchingDigits(GetMonData(mon, MON_DATA_OT_ID), lucky));
        if (place != 0 && (best == 0 || place < best))
        {
            best = place;
            bestSpecies = GetMonData(mon, MON_DATA_SPECIES);
            inPC = FALSE;
        }
    }
    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            struct BoxPokemon *mon = GetBoxedMonPtr(i, j);

            if (!GetBoxMonData(mon, MON_DATA_SANITY_HAS_SPECIES) || GetBoxMonData(mon, MON_DATA_IS_EGG))
                continue;
            place = GetLuckyNumberPlace(CountMatchingDigits(GetBoxMonData(mon, MON_DATA_OT_ID), lucky));
            if (place != 0 && (best == 0 || place < best))
            {
                best = place;
                bestSpecies = GetBoxMonData(mon, MON_DATA_SPECIES);
                inPC = TRUE;
            }
        }
    }
    gSpecialVar_Result = best;
    gSpecialVar_0x8005 = inPC;
    if (bestSpecies != SPECIES_NONE)
        StringCopy(gStringVar2, gSpeciesNames[bestSpecies]);
}

// The player got this week's prize.
void LuckyNumberShow_SetPrizeWon(void)
{
    VarSet(VAR_GOLD_LUCKY_NUMBER_WEEK, GetLuckyNumberWeek() + 1);
}
