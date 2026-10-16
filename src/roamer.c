#include "global.h"
#include "event_data.h"
#include "random.h"
#include "overworld.h"
#include "pokemon.h"
#include "quest_log.h"
#include "roamer.h"
#include "save_block_ext.h"
#include "constants/maps.h"
#include "constants/region_map_sections.h"
#include "constants/species.h"

// Pure Gold/Silver: after the Burned Tower scene, Raikou, Entei and Suicune roam the Johto routes at Lv 40,
// as in pret/pokegold:
//   InitRoamMons, UpdateRoamMons, JumpRoamMons, CheckEncounterRoamMon  (engine/overworld/wildmons.asm)
//   BattleEnd_HandleRoamMons                                           (engine/battle/core.asm)
//   RoamMaps                                                           (data/wild/roammon_maps.asm)
//   where the map setup scripts call UpdateRoamMons/JumpRoamMons       (data/maps/setup_scripts.asm)
// FireRed's roamer supported a single Kanto roamer whose location was not saved.
//
// Storage: Raikou is gSaveBlock1Ptr->roamer, Entei and Suicune are gSaveBlockExt.roamers[0..1]. The map of
// each beast and the player's last two maps (pokegold wRoamMons_CurMap/LastMap) are in gSaveBlockExt, so all of
// it is saved, as in G/S. A beast is gone (caught or knocked out) when its 'active' field is FALSE.

#define ROAMER_LEVEL 40

// ShinyGold's flags (outside the W4 range): the Burned Tower scene, and the old static Raikou/Entei/Suicune
// encounters that the roamers replace (set once that beast had been caught or knocked out).
#define FLAG_SG_BURNED_TOWER_BEASTS_FLED   0x10AC
#define FLAG_SG_STATIC_RAIKOU_DONE         0x1234
#define FLAG_SG_STATIC_ENTEI_DONE          0x1235
#define FLAG_SG_STATIC_SUICUNE_DONE        0x1236

struct RoamMap
{
    u16 map;
    u8 numNeighbors;
    u16 neighbors[4];
};

// pokegold RoamMaps: the maps a beast can be on and the maps it can move to from there. Routes 40 and 41 are
// water routes and are missing, as in G/S; gates and other buildings are not part of it.
static const struct RoamMap sRoamMaps[] = {
    { MAP_ROUTE29, 2, { MAP_ROUTE30, MAP_ROUTE46 } },
    { MAP_ROUTE30, 2, { MAP_ROUTE29, MAP_ROUTE31 } },
    { MAP_ROUTE31, 3, { MAP_ROUTE30, MAP_ROUTE32, MAP_ROUTE36 } },
    { MAP_ROUTE32, 3, { MAP_ROUTE36, MAP_ROUTE31, MAP_ROUTE33 } },
    { MAP_ROUTE33, 2, { MAP_ROUTE32, MAP_ROUTE34 } },
    { MAP_ROUTE34, 2, { MAP_ROUTE33, MAP_ROUTE35 } },
    { MAP_ROUTE35, 2, { MAP_ROUTE34, MAP_ROUTE36 } },
    { MAP_ROUTE36, 4, { MAP_ROUTE35, MAP_ROUTE31, MAP_ROUTE32, MAP_ROUTE37 } },
    { MAP_ROUTE37, 3, { MAP_ROUTE36, MAP_ROUTE38, MAP_ROUTE42 } },
    { MAP_ROUTE38, 3, { MAP_ROUTE37, MAP_ROUTE39, MAP_ROUTE42 } },
    { MAP_ROUTE39, 1, { MAP_ROUTE38 } },
    { MAP_ROUTE42, 4, { MAP_ROUTE43, MAP_ROUTE44, MAP_ROUTE37, MAP_ROUTE38 } },
    { MAP_ROUTE43, 2, { MAP_ROUTE42, MAP_ROUTE44 } },
    { MAP_ROUTE44, 3, { MAP_ROUTE42, MAP_ROUTE43, MAP_ROUTE45 } },
    { MAP_ROUTE45, 2, { MAP_ROUTE44, MAP_ROUTE46 } },
    { MAP_ROUTE46, 2, { MAP_ROUTE45, MAP_ROUTE29 } },
};

// JumpRoamMon picks a map with 'Random & 15', which works because there are exactly 16 maps.
STATIC_ASSERT(ARRAY_COUNT(sRoamMaps) == 16, RoamMapsCount);

static const u16 sRoamerSpecies[NUM_ROAMERS] = {
    [ROAMER_RAIKOU]  = SPECIES_RAIKOU,
    [ROAMER_ENTEI]   = SPECIES_ENTEI,
    [ROAMER_SUICUNE] = SPECIES_SUICUNE,
};

// pokegold InitRoamMons: starting maps.
static const u16 sRoamerStartMaps[NUM_ROAMERS] = {
    [ROAMER_RAIKOU]  = MAP_ROUTE42,
    [ROAMER_ENTEI]   = MAP_ROUTE37,
    [ROAMER_SUICUNE] = MAP_ROUTE38,
};

static EWRAM_DATA u8 sRoamersWarpMode = ROAMERS_WARP_UPDATE;

static struct Roamer *GetRoamer(u32 id)
{
    if (id == ROAMER_RAIKOU)
        return &gSaveBlock1Ptr->roamer;
    return &gSaveBlockExt.roamers[id - 1];
}

static void SetRoamerMap(u32 id, u16 map)
{
    gSaveBlockExt.roamerMaps[id][0] = MAP_GROUP(map);
    gSaveBlockExt.roamerMaps[id][1] = MAP_NUM(map);
}

static bool8 IsMap(u16 map, u8 mapGroup, u8 mapNum)
{
    return MAP_GROUP(map) == mapGroup && MAP_NUM(map) == mapNum;
}

static const struct RoamMap *FindRoamMap(u8 mapGroup, u8 mapNum)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sRoamMaps); i++)
    {
        if (IsMap(sRoamMaps[i].map, mapGroup, mapNum))
            return &sRoamMaps[i];
    }
    return NULL;
}

static s32 GetRoamerIdBySpecies(u16 species)
{
    s32 i;

    for (i = 0; i < NUM_ROAMERS; i++)
    {
        if (sRoamerSpecies[i] == species)
            return i;
    }
    return -1;
}

void ClearRoamerData(void)
{
    u32 i;

    for (i = 0; i < NUM_ROAMERS; i++)
    {
        *GetRoamer(i) = (struct Roamer){};
        gSaveBlockExt.roamerMaps[i][0] = 0;
        gSaveBlockExt.roamerMaps[i][1] = 0;
    }
    gSaveBlockExt.roamerPlayerCurMap[0] = 0;
    gSaveBlockExt.roamerPlayerCurMap[1] = 0;
    gSaveBlockExt.roamerPlayerLastMap[0] = 0;
    gSaveBlockExt.roamerPlayerLastMap[1] = 0;
    sRoamersWarpMode = ROAMERS_WARP_UPDATE;
}

static void InitRoamMon(u32 id)
{
    struct Roamer *roamer = GetRoamer(id);
    struct Pokemon *mon = &gEnemyParty[0];

    // G/S rolls the DVs at the first encounter; rolling IVs and personality now is equivalent.
    CreateMon(mon, sRoamerSpecies[id], ROAMER_LEVEL, USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);
    *roamer = (struct Roamer){};
    roamer->species = sRoamerSpecies[id];
    roamer->level = ROAMER_LEVEL;
    roamer->ivs = GetMonData(mon, MON_DATA_IVS);
    roamer->personality = GetMonData(mon, MON_DATA_PERSONALITY);
    roamer->hp = GetMonData(mon, MON_DATA_MAX_HP);
    roamer->active = TRUE;
    SetRoamerMap(id, sRoamerStartMaps[id]);
}

// Special (pokegold special InitRoamMons): called by the Burned Tower scene after the beasts flee.
void InitRoamMons(void)
{
    u32 i;

    for (i = 0; i < NUM_ROAMERS; i++)
        InitRoamMon(i);
    FlagSet(FLAG_GOLD_ROAMERS_STARTED);
}

// Saves from before the beasts roamed: the Burned Tower scene has played, but InitRoamMons never ran. Start the
// beasts now, except those that the old static encounters already removed.
static void TryInitRoamMonsForOldSave(void)
{
    if (FlagGet(FLAG_GOLD_ROAMERS_STARTED) || !FlagGet(FLAG_SG_BURNED_TOWER_BEASTS_FLED))
        return;
    InitRoamMons();
    if (FlagGet(FLAG_SG_STATIC_RAIKOU_DONE))
        GetRoamer(ROAMER_RAIKOU)->active = FALSE;
    if (FlagGet(FLAG_SG_STATIC_ENTEI_DONE))
        GetRoamer(ROAMER_ENTEI)->active = FALSE;
    if (FlagGet(FLAG_SG_STATIC_SUICUNE_DONE))
        GetRoamer(ROAMER_SUICUNE)->active = FALSE;
}

// pokegold _BackUpMapIndices
static void BackUpMapIndices(u8 mapGroup, u8 mapNum)
{
    gSaveBlockExt.roamerPlayerLastMap[0] = gSaveBlockExt.roamerPlayerCurMap[0];
    gSaveBlockExt.roamerPlayerLastMap[1] = gSaveBlockExt.roamerPlayerCurMap[1];
    gSaveBlockExt.roamerPlayerCurMap[0] = mapGroup;
    gSaveBlockExt.roamerPlayerCurMap[1] = mapNum;
}

// pokegold JumpRoamMon: to any roam map other than the player's map.
static void JumpRoamMon(u32 id, u8 mapGroup, u8 mapNum)
{
    u16 map;

    do
    {
        map = sRoamMaps[Random() % ARRAY_COUNT(sRoamMaps)].map;
    } while (IsMap(map, mapGroup, mapNum));
    SetRoamerMap(id, map);
}

// pokegold UpdateRoamMons.Update: usually to a neighbouring map, but never to the map the player was on before
// the previous one (wRoamMons_LastMap); each try has a 1/32 chance of jumping to a random map instead.
static void UpdateRoamMon(u32 id)
{
    const struct RoamMap *roamMap = FindRoamMap(gSaveBlockExt.roamerMaps[id][0], gSaveBlockExt.roamerMaps[id][1]);
    u32 rand;
    u16 map;

    if (roamMap == NULL)
        return;

    while (TRUE)
    {
        rand = Random() & 0x1F;
        if (rand == 0)
        {
            JumpRoamMon(id, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
            return;
        }
        rand &= 3;
        if (rand >= roamMap->numNeighbors)
            continue;
        map = roamMap->neighbors[rand];
        if (IsMap(map, gSaveBlockExt.roamerPlayerLastMap[0], gSaveBlockExt.roamerPlayerLastMap[1]))
            continue;
        SetRoamerMap(id, map);
        return;
    }
}

// pokegold UpdateRoamMons: after walking to another map through a map connection, a door, a warp or a hole,
// and after battles (see battle_main.c).
void UpdateRoamMons(void)
{
    u32 i;

    TryInitRoamMonsForOldSave();
    for (i = 0; i < NUM_ROAMERS; i++)
    {
        if (GetRoamer(i)->active)
            UpdateRoamMon(i);
    }
    BackUpMapIndices(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
}

// pokegold JumpRoamMons: each beast jumps to a random map. Used when continuing a saved game (with the map the
// game continues on) and when flying or teleporting (with the map the player leaves).
void JumpRoamMons(u8 mapGroup, u8 mapNum)
{
    u32 i;

    TryInitRoamMonsForOldSave();
    for (i = 0; i < NUM_ROAMERS; i++)
    {
        if (GetRoamer(i)->active)
            JumpRoamMon(i, mapGroup, mapNum);
    }
    BackUpMapIndices(mapGroup, mapNum);
}

void SetRoamMonsWarpMode(u8 mode)
{
    sRoamersWarpMode = mode;
}

// Called by LoadMapFromWarp, after the player arrived on the new map.
void HandleRoamMonsOnWarp(void)
{
    u8 mode = sRoamersWarpMode;

    sRoamersWarpMode = ROAMERS_WARP_UPDATE;
    if (QL_IS_PLAYBACK_STATE)
        return;
    if (mode == ROAMERS_WARP_UPDATE)
        UpdateRoamMons();
    else if (mode == ROAMERS_WARP_JUMP)
        JumpRoamMons(gLastUsedWarp.mapGroup, gLastUsedWarp.mapNum);
}

// pokegold BattleEnd_HandleRoamMons, for battles against anything but a roaming beast: 1/16 chance that the
// beasts move.
void TryUpdateRoamMonsAfterBattle(void)
{
    if ((Random() % 16) == 0)
        UpdateRoamMons();
}

static bool8 IsRoamerOnCurrentMap(u32 id)
{
    return GetRoamer(id)->active
        && gSaveBlockExt.roamerMaps[id][0] == gSaveBlock1Ptr->location.mapGroup
        && gSaveBlockExt.roamerMaps[id][1] == gSaveBlock1Ptr->location.mapNum;
}

static void CreateRoamerMonInstance(u32 id)
{
    struct Roamer *roamer = GetRoamer(id);
    struct Pokemon *mon = &gEnemyParty[0];
    u16 hp = roamer->hp;

    ZeroEnemyPartyMons();
    CreateMonWithIVsPersonality(mon, roamer->species, roamer->level, roamer->ivs, roamer->personality);
    // G/S keeps only the HP between battles (0 means full HP); the status condition is not kept.
    if (hp != 0)
        SetMonData(mon, MON_DATA_HP, &hp);
}

// pokegold CheckEncounterRoamMon: called for land encounters (not on water) once the wild encounter rate check
// has passed. With a 100/256 chance one beast is picked at random (the low two bits: 0 = none, so 75/256 in all,
// 25/256 per beast); it is met if it is on the player's map.
bool8 TryStartRoamerEncounter(void)
{
    u32 rand = Random() % 256;
    u32 id;

    if (rand >= 100 || (rand & 3) == 0)
        return FALSE;
    id = (rand & 3) - 1;
    if (!IsRoamerOnCurrentMap(id))
        return FALSE;
    CreateRoamerMonInstance(id);
    return TRUE;
}

// After a battle against a beast that was not caught or knocked out (it fled, the player ran or lost): it keeps
// its HP, and all beasts move on (pokegold BattleEnd_HandleRoamMons).
void UpdateRoamerHPStatus(struct Pokemon *mon)
{
    s32 id = GetRoamerIdBySpecies(GetMonData(mon, MON_DATA_SPECIES));

    if (id >= 0)
    {
        GetRoamer(id)->hp = GetMonData(mon, MON_DATA_HP);
        GetRoamer(id)->status = 0;
    }
    UpdateRoamMons();
}

// The beast was caught or knocked out: it is gone for good.
void SetRoamerInactive(struct Pokemon *mon)
{
    s32 id = GetRoamerIdBySpecies(GetMonData(mon, MON_DATA_SPECIES));

    if (id >= 0)
    {
        GetRoamer(id)->active = FALSE;
        GetRoamer(id)->hp = 0;
        gSaveBlockExt.roamerMaps[id][0] = 0;
        gSaveBlockExt.roamerMaps[id][1] = 0;
    }
}

bool8 IsRoamerSpecies(u16 species)
{
    return GetRoamerIdBySpecies(species) >= 0;
}

// Pokédex area screen (pokegold FindNest .RoamMon1-3): where the beast of this species is now.
u16 GetRoamerLocationMapSectionId(u16 species)
{
    s32 id = GetRoamerIdBySpecies(species);
    u8 mapGroup, mapNum;

    if (id < 0 || !GetRoamer(id)->active)
        return MAPSEC_NONE;
    mapGroup = gSaveBlockExt.roamerMaps[id][0];
    mapNum = gSaveBlockExt.roamerMaps[id][1];
    if (FindRoamMap(mapGroup, mapNum) == NULL)
        return MAPSEC_NONE;
    return Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->regionMapSectionId;
}
