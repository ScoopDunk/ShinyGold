#include "global.h"
#include "force_shiny.h"

// ShinyGold: see force_shiny.h.
// Placed by sym_ewram.txt into the space of the disabled help system's tile backup buffer (see help_system_util.c).
EWRAM_DATA u32 gForceShinyMons = 0;

void ToggleForceShinyMons(void)
{
    gForceShinyMons ^= 1;
}

// ShinyGold fix: explicit on/off natives. The hack only had the toggle, and losing the Lake of Rage Gyarados battle
// skipped the "off" toggle, so every Pokémon made afterwards was shiny until the game was reset.
void SetForceShinyMons(void)
{
    gForceShinyMons = TRUE;
}

void ClearForceShinyMons(void)
{
    gForceShinyMons = FALSE;
}
