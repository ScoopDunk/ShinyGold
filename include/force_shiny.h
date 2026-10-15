#ifndef GUARD_FORCE_SHINY_H
#define GUARD_FORCE_SHINY_H

// ShinyGold: while this is TRUE, every Pokémon that is created becomes shiny (see SetBoxMonData).
// The hack kept this flag in the unused tail of gStringVar4 (0x02022000). It is not saved.
extern u32 gForceShinyMons;

// Script native (hack routine at 0x087FFF70)
void ToggleForceShinyMons(void);

#endif // GUARD_FORCE_SHINY_H
