#include "global.h"
#include "event_data.h"
#include "pokemon_storage_system.h"
#include "save.h"
#include "save_block_ext.h"

// ShinyGold: save block extension, see save_block_ext.h.

// Placed by sym_ewram.txt into the space of the disabled help system's tile backup buffer (see help_system_util.c).
EWRAM_DATA struct SaveBlockExt gSaveBlockExt = {0};

// Size of the part of gSaveBlockExt stored in the free space of the last sector of each save block.
#define EXT_SIZE_SAVEBLOCK2 (SAVEBLOCK_SECTOR_DATA_SIZE - sizeof(struct SaveBlock2))
#define EXT_SIZE_SAVEBLOCK1 (SAVEBLOCK_SECTOR_DATA_SIZE * (SECTOR_ID_SAVEBLOCK1_END - SECTOR_ID_SAVEBLOCK1_START + 1) - sizeof(struct SaveBlock1))
#define EXT_SIZE_PKMN_STORAGE (SAVEBLOCK_SECTOR_DATA_SIZE * (SECTOR_ID_PKMN_STORAGE_END - SECTOR_ID_PKMN_STORAGE_START + 1) - sizeof(struct PokemonStorage))

// The on-flash layout must match ShinyGold's exactly.
STATIC_ASSERT(sizeof(struct SaveBlockExt) == 0xEC4, SaveBlockExtSize);
STATIC_ASSERT(offsetof(struct SaveBlockExt, stepCounter) == 0x2E0, SaveBlockExtStepCounterOffset);
STATIC_ASSERT(offsetof(struct SaveBlockExt, roamerPlayerCurMap) == 0x2E2, SaveBlockExtRoamerPlayerCurMapOffset);
STATIC_ASSERT(offsetof(struct SaveBlockExt, roamers) == 0x2E4, SaveBlockExtRoamersOffset);
STATIC_ASSERT(offsetof(struct SaveBlockExt, roamerMaps) == 0x31C, SaveBlockExtRoamerMapsOffset);
STATIC_ASSERT(offsetof(struct SaveBlockExt, roamerPlayerLastMap) == 0x322, SaveBlockExtRoamerPlayerLastMapOffset);
STATIC_ASSERT(offsetof(struct SaveBlockExt, numVars) == 0x324, SaveBlockExtNumVarsOffset);
STATIC_ASSERT(EXT_SIZE_SAVEBLOCK2 == 0xCC, SaveBlockExtSaveBlock2Size);
STATIC_ASSERT(EXT_SIZE_SAVEBLOCK1 == 0x258, SaveBlockExtSaveBlock1Size);
STATIC_ASSERT(EXT_SIZE_PKMN_STORAGE == 0xBA0, SaveBlockExtPkmnStorageSize);
STATIC_ASSERT(EXT_SIZE_SAVEBLOCK2 + EXT_SIZE_SAVEBLOCK1 + EXT_SIZE_PKMN_STORAGE == sizeof(struct SaveBlockExt), SaveBlockExtFitsInSaveSectors);

void ClearSaveBlockExt(void)
{
    memset(&gSaveBlockExt, 0, sizeof(gSaveBlockExt));
}

u8 *GetSaveBlockExtFlagAddr(u16 flagId)
{
    if (flagId < EXT_FLAGS_START || flagId > EXT_FLAGS_END)
        return NULL;
    return &gSaveBlockExt.flags[(flagId - EXT_FLAGS_START) / 8];
}

u16 *GetSaveBlockExtVarPointer(u16 varId)
{
    u32 i;

    if (varId < EXT_VARS_START || varId > EXT_VARS_END)
        return NULL;

    for (i = 0; i != gSaveBlockExt.numVars; i++)
    {
        if (gSaveBlockExt.vars[i].id == varId)
            return &gSaveBlockExt.vars[i].value;
    }

    // Not used yet, add a new entry. Its value is whatever is left in the table (0 after a new game).
    if (i >= EXT_VARS_CAPACITY)
    {
        // The hack does not check this and would write past the end of the table (into RAM that is
        // never saved). Treat the variable as nonexistent instead (VarGet/VarSet handle NULL).
        return NULL;
    }
    gSaveBlockExt.vars[i].id = varId;
    gSaveBlockExt.numVars = i + 1;
    return &gSaveBlockExt.vars[i].value;
}

// Returns the part of gSaveBlockExt that is stored in the given sector of the save slot, or NULL.
static u8 *GetSaveBlockExtChunk(u16 sectorId, u16 *size)
{
    switch (sectorId)
    {
    case SECTOR_ID_SAVEBLOCK2:
        *size = EXT_SIZE_SAVEBLOCK2;
        return (u8 *)&gSaveBlockExt;
    case SECTOR_ID_SAVEBLOCK1_END:
        *size = EXT_SIZE_SAVEBLOCK1;
        return (u8 *)&gSaveBlockExt + EXT_SIZE_SAVEBLOCK2;
    case SECTOR_ID_PKMN_STORAGE_END:
        *size = EXT_SIZE_PKMN_STORAGE;
        return (u8 *)&gSaveBlockExt + EXT_SIZE_SAVEBLOCK2 + EXT_SIZE_SAVEBLOCK1;
    default:
        *size = 0;
        return NULL;
    }
}

// The chunk is stored at the end of the sector's data area, right after the save block data.
// It is not covered by the sector checksum (same as in the hack).
void SaveBlockExt_WriteToSector(u16 sectorId, u8 *sectorData)
{
    u16 size;
    u8 *chunk = GetSaveBlockExtChunk(sectorId, &size);

    if (chunk != NULL)
        memcpy(sectorData + SAVEBLOCK_SECTOR_DATA_SIZE - size, chunk, size);
}

void SaveBlockExt_ReadFromSector(u16 sectorId, const u8 *sectorData)
{
    u16 size;
    u8 *chunk = GetSaveBlockExtChunk(sectorId, &size);

    if (chunk != NULL)
        memcpy(chunk, sectorData + SAVEBLOCK_SECTOR_DATA_SIZE - size, size);
}

// Called for every step (from RunMassageCooldownStepCounter). The counter only runs after
// StartSaveBlockExtStepCounter set it to 1, and stops at SAVE_BLOCK_EXT_STEP_COUNTER_MAX.
void SaveBlockExt_UpdateStepCounter(void)
{
    if (gSaveBlockExt.stepCounter != 0 && gSaveBlockExt.stepCounter < SAVE_BLOCK_EXT_STEP_COUNTER_MAX)
        gSaveBlockExt.stepCounter++;
}

// Script native (hack routine at 0x0882883C): starts the step counter.
void StartSaveBlockExtStepCounter(void)
{
    gSaveBlockExt.stepCounter = 1;
}

// Script native (hack routine at 0x0882884C): VAR_RESULT = TRUE once the player walked enough steps.
void CheckSaveBlockExtStepCounter(void)
{
    if (gSaveBlockExt.stepCounter >= SAVE_BLOCK_EXT_STEP_COUNTER_MAX)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}
