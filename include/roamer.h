#ifndef GUARD_ROAMER_H
#define GUARD_ROAMER_H

#include "global.h"

// Pure Gold/Silver: Raikou, Entei and Suicune roam Johto as in pret/pokegold (see roamer.c).
enum
{
    ROAMER_RAIKOU,
    ROAMER_ENTEI,
    ROAMER_SUICUNE,
    NUM_ROAMERS
};

// How the roaming beasts react to the next LoadMapFromWarp (pokegold map setup scripts).
enum
{
    ROAMERS_WARP_UPDATE, // doors, warp tiles, holes, Dig, Escape Rope: UpdateRoamMons
    ROAMERS_WARP_JUMP,   // Fly, Teleport: JumpRoamMons
    ROAMERS_WARP_NONE,   // whiting out, returning from a link room, credits, quest log playback
};

void ClearRoamerData(void);
void InitRoamMons(void);
void UpdateRoamMons(void);
void JumpRoamMons(u8 mapGroup, u8 mapNum);
void SetRoamMonsWarpMode(u8 mode);
void HandleRoamMonsOnWarp(void);
void TryUpdateRoamMonsAfterBattle(void);
bool8 TryStartRoamerEncounter(void);
void UpdateRoamerHPStatus(struct Pokemon *mon);
void SetRoamerInactive(struct Pokemon *mon);
bool8 IsRoamerSpecies(u16 species);
u16 GetRoamerLocationMapSectionId(u16 species);

#endif // GUARD_ROAMER_H
