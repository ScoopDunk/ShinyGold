#include "global.h"
#include "characters.h"
#include "data.h"
#include "event_data.h"
#include "item.h"
#include "pokemon.h"
#include "random.h"
#include "script_pokemon_util.h"
#include "string_util.h"
#include "constants/items.h"
#include "constants/species.h"

// ShinyGold gold: the Bug-Catching Contest as in Gold/Silver.
// Encounters: pokegold data/wild/bug_contest_mons.asm and ChooseWildEncounter_BugContest.
// Judging: pokegold engine/events/bug_contest/judging.asm with the contestants of
// data/events/bug_contest_winners.asm who are in the park (the contest map has five of them).
// All functions are called from scripts with callnative.

struct BugContestMon
{
    u8 percent;
    u16 species;
    u8 minLevel;
    u8 maxLevel;
};

static const struct BugContestMon sBugContestMons[] =
{
    {20, SPECIES_CATERPIE,    7, 18},
    {20, SPECIES_WEEDLE,      7, 18},
    {10, SPECIES_METAPOD,     9, 18},
    {10, SPECIES_KAKUNA,      9, 18},
    { 5, SPECIES_BUTTERFREE, 12, 15},
    { 5, SPECIES_BEEDRILL,   12, 15},
    {10, SPECIES_VENONAT,    10, 16},
    {10, SPECIES_PARAS,      10, 17},
    { 5, SPECIES_SCYTHER,    13, 14},
    { 5, SPECIES_PINSIR,     13, 14},
};

struct BugContestant
{
    const u8 *name;
    u16 species[3];
    u16 score[3];
};

static const u8 sName_BugCatcherEd[] = _("BUG CATCHER ED");
static const u8 sName_PokefanWilliam[] = _("POKéFAN WILLIAM");
static const u8 sName_CamperBarry[] = _("CAMPER BARRY");
static const u8 sName_BugCatcherJosh[] = _("BUG CATCHER JOSH");
static const u8 sName_YoungsterSamuel[] = _("YOUNGSTER SAMUEL");

// In the order of pokegold's BugContestantPointers (it decides ties).
static const struct BugContestant sBugContestants[] =
{
    {sName_BugCatcherEd,      {SPECIES_BUTTERFREE, SPECIES_BUTTERFREE, SPECIES_CATERPIE}, {286, 251, 237}},
    {sName_PokefanWilliam,    {SPECIES_PINSIR,     SPECIES_BUTTERFREE, SPECIES_VENONAT},  {332, 324, 321}},
    {sName_CamperBarry,       {SPECIES_PINSIR,     SPECIES_VENONAT,    SPECIES_KAKUNA},   {366, 329, 314}},
    {sName_BugCatcherJosh,    {SPECIES_SCYTHER,    SPECIES_BUTTERFREE, SPECIES_METAPOD},  {326, 292, 282}},
    {sName_YoungsterSamuel,   {SPECIES_WEEDLE,     SPECIES_PINSIR,     SPECIES_CATERPIE}, {270, 282, 251}},
};

#define CONTESTANT_NONE   0
#define CONTESTANT_PLAYER 0xFF

struct BugContestPlace
{
    u8 contestant; // CONTESTANT_NONE, CONTESTANT_PLAYER or 1 + index into sBugContestants
    u16 species;
    u16 score;
};

// [0] = 1st place
static EWRAM_DATA struct BugContestPlace sBugContestPlaces[3] = {0};

// Sets up a scripted wild battle (start it with dowildbattle).
void BugContest_CreateEncounter(void)
{
    u32 i;
    u8 roll = Random() % 100;
    u8 level;
    const struct BugContestMon *mon;

    for (i = 0; i < ARRAY_COUNT(sBugContestMons) - 1 && roll >= sBugContestMons[i].percent; i++)
        roll -= sBugContestMons[i].percent;
    mon = &sBugContestMons[i];
    level = mon->minLevel + Random() % (mon->maxLevel - mon->minLevel + 1);
    CreateScriptedWildMon(mon->species, level, ITEM_NONE);
}

static u16 GetPlayerContestScore(u16 *species)
{
    struct Pokemon *mon;
    u16 score;
    u8 count = CalculatePlayerPartyCount();

    // The player enters with one POKéMON; the bug caught in the contest is the second one.
    if (count < 2)
    {
        *species = SPECIES_NONE;
        return 0;
    }
    mon = &gPlayerParty[count - 1];
    *species = GetMonData(mon, MON_DATA_SPECIES);
    score = GetMonData(mon, MON_DATA_MAX_HP) * 4;
    score += GetMonData(mon, MON_DATA_ATK);
    score += GetMonData(mon, MON_DATA_DEF);
    score += GetMonData(mon, MON_DATA_SPEED);
    score += GetMonData(mon, MON_DATA_SPATK);
    score += GetMonData(mon, MON_DATA_SPDEF);
    // G/S adds bit 1 of each DV (DV = IV / 2): Spd 1, Spc 4, Atk 8, Def 16 points.
    if (GetMonData(mon, MON_DATA_SPEED_IV) & 4)
        score += 1;
    if (GetMonData(mon, MON_DATA_SPATK_IV) & 4)
        score += 4;
    if (GetMonData(mon, MON_DATA_ATK_IV) & 4)
        score += 8;
    if (GetMonData(mon, MON_DATA_DEF_IV) & 4)
        score += 16;
    score += GetMonData(mon, MON_DATA_HP) / 8;
    if (GetMonData(mon, MON_DATA_HELD_ITEM) != ITEM_NONE)
        score += 1;
    return score;
}

static void PlaceContestant(u8 contestant, u16 species, u16 score)
{
    if (score >= sBugContestPlaces[0].score)
    {
        sBugContestPlaces[2] = sBugContestPlaces[1];
        sBugContestPlaces[1] = sBugContestPlaces[0];
        sBugContestPlaces[0].contestant = contestant;
        sBugContestPlaces[0].species = species;
        sBugContestPlaces[0].score = score;
    }
    else if (score >= sBugContestPlaces[1].score)
    {
        sBugContestPlaces[2] = sBugContestPlaces[1];
        sBugContestPlaces[1].contestant = contestant;
        sBugContestPlaces[1].species = species;
        sBugContestPlaces[1].score = score;
    }
    else if (score >= sBugContestPlaces[2].score)
    {
        sBugContestPlaces[2].contestant = contestant;
        sBugContestPlaces[2].species = species;
        sBugContestPlaces[2].score = score;
    }
}

// Judges the contest. VAR_RESULT = the player's place (1-3), or 0.
void BugContest_Judge(void)
{
    u32 i;
    u16 species, score;

    memset(sBugContestPlaces, 0, sizeof(sBugContestPlaces));
    for (i = 0; i < ARRAY_COUNT(sBugContestants); i++)
    {
        u8 pick = Random() % 3;
        PlaceContestant(i + 1, sBugContestants[i].species[pick], sBugContestants[i].score[pick] + (Random() & 7));
    }
    score = GetPlayerContestScore(&species);
    if (species != SPECIES_NONE)
        PlaceContestant(CONTESTANT_PLAYER, species, score);

    gSpecialVar_Result = 0;
    for (i = 0; i < 3; i++)
    {
        if (sBugContestPlaces[i].contestant == CONTESTANT_PLAYER)
            gSpecialVar_Result = i + 1;
    }
}

// For place VAR_0x8004 (1-3): STR_VAR_1 = the winner, STR_VAR_2 = the POKéMON, STR_VAR_3 = the score.
void BugContest_BufferPlace(void)
{
    const struct BugContestPlace *place = &sBugContestPlaces[(gSpecialVar_0x8004 - 1) % 3];

    if (place->contestant == CONTESTANT_PLAYER)
        StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
    else if (place->contestant != CONTESTANT_NONE)
        StringCopy(gStringVar1, sBugContestants[place->contestant - 1].name);
    else
        gStringVar1[0] = EOS;
    StringCopy(gStringVar2, gSpeciesNames[place->species]);
    ConvertIntToDecimalStringN(gStringVar3, place->score, STR_CONV_MODE_LEFT_ALIGN, 3);
}

// The contest's PARK BALLS (SAFARI BALLs) are not kept, as in G/S.
void BugContest_TakeParkBalls(void)
{
    while (CheckBagHasItem(ITEM_SAFARI_BALL, 1))
        RemoveBagItem(ITEM_SAFARI_BALL, 1);
}
