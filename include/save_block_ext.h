#ifndef GUARD_SAVE_BLOCK_EXT_H
#define GUARD_SAVE_BLOCK_EXT_H

// ShinyGold: save block extension (originally a JPAN-style "save expansion" in the hack).
//
// It holds the flags 0x900-0x1FFF, the variables 0x4100-0x7FFF and a step counter.
// In RAM it uses part of the 16 KB buffer of the disabled help system (see sym_ewram.txt and
// help_system_util.c; the hack used 0x0203C000, which is inside the same buffer).
// In flash it is split over the free space at the end of the last sector of each save block (see SAVEBLOCK_SECTOR_DATA_SIZE in save.h):
//   SaveBlock2 sector        (id  0): gSaveBlockExt bytes 0x000-0x0CB -> sector offsets 0xF24-0xFEF
//   SaveBlock1 last sector   (id  4): gSaveBlockExt bytes 0x0CC-0x323 -> sector offsets 0xD98-0xFEF
//   PC storage last sector   (id 13): gSaveBlockExt bytes 0x324-0xEC3 -> sector offsets 0x450-0xFEF
// This layout is identical to ShinyGold's, so ShinyGold save files load unchanged.
// None of this data is sent over link, so link/trade compatibility is not affected.

#define EXT_FLAGS_START     0x900
#define EXT_FLAGS_END       0x1FFF
#define EXT_FLAGS_SIZE      ((EXT_FLAGS_END + 1 - EXT_FLAGS_START) / 8)

// Variables in this range are not stored at fixed places. Instead, each variable gets an
// (id, value) entry in gSaveBlockExt.vars when it is accessed for the first time.
#define EXT_VARS_START      0x4100
#define EXT_VARS_END        0x7FFF
#define EXT_VARS_CAPACITY   743

struct SaveBlockExtVar
{
    u16 id;
    u16 value;
};

struct SaveBlockExt
{
    /*0x000*/ u8 flags[EXT_FLAGS_SIZE];
    /*0x2E0*/ u16 stepCounter; // see StartSaveBlockExtStepCounter
    // Pure Gold/Silver: the three roaming beasts (src/roamer.c). This was unused space (0x42 bytes, zero in
    // ShinyGold saves, which therefore load with no active roamers). Raikou is gSaveBlock1Ptr->roamer.
    /*0x2E2*/ u8 roamerPlayerCurMap[2];     // pokegold wRoamMons_CurMapGroup/Number: (map group, map num)
    /*0x2E4*/ struct Roamer roamers[2];     // Entei, Suicune
    /*0x31C*/ u8 roamerMaps[3][2];          // current map of Raikou, Entei, Suicune: (map group, map num)
    /*0x322*/ u8 roamerPlayerLastMap[2];    // pokegold wRoamMons_LastMapGroup/Number
    /*0x324*/ u32 numVars;
    /*0x328*/ struct SaveBlockExtVar vars[EXT_VARS_CAPACITY];
}; // size = 0xEC4

#define SAVE_BLOCK_EXT_STEP_COUNTER_MAX 500

extern struct SaveBlockExt gSaveBlockExt;

void ClearSaveBlockExt(void);
u8 *GetSaveBlockExtFlagAddr(u16 flagId);
u16 *GetSaveBlockExtVarPointer(u16 varId);
void SaveBlockExt_WriteToSector(u16 sectorId, u8 *sectorData);
void SaveBlockExt_ReadFromSector(u16 sectorId, const u8 *sectorData);
void SaveBlockExt_UpdateStepCounter(void);

// Script natives (callnative)
void StartSaveBlockExtStepCounter(void);
void CheckSaveBlockExtStepCounter(void);
void StartGsBallStepCounter(void);
void CheckGsBallStepCounter(void);

#endif // GUARD_SAVE_BLOCK_EXT_H
