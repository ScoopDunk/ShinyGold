# ShinyGold decompilation

This tree is ShinyGold (Faithfully Fixed, Beta 5) ported onto pret/pokefirered. On this branch (`fixed`) `make`
builds `pokefirered.gba` as **ShinyGold Fixed**: the hack with all of its content and its own wild Pokémon, with
its bugs fixed (broken trainer names, crashes, broken scenes; see "Fixes" below).

## Branches

| Branch | Contents |
|---|---|
| `fixed` | ShinyGold Fixed: all of the hack's content and wild Pokémon, with the fixes below |
| `gold` | Pure Gold/Silver: custom content removed, Gold/Silver content restored, wild Pokémon from Gold/Silver |
| `master` | The faithful port with the trainer-name fix and Gold/Silver wild Pokémon (the base of `gold`) |
| `faithful` | The hack ported as-is (only crash-level hack bugs fixed). Use it to see what the hack itself did |
| first commit | Unmodified pret/pokefirered, so `git diff <first commit>` shows everything ShinyGold changes |

Saves: `fixed` and `master` keep the hack's map numbering and save format, so ShinyGold saves continue on them.
`gold` renumbered the maps; start a new game there.

## Building

Same as pokefirered (see `INSTALL.md`): install agbcc into the tree, then `make`. Only the FireRed 1.0 target
(`make` / `pokefirered.gba`) was ported and tested; the LeafGreen and rev1 targets are not maintained.
The ROM keeps FireRed's game code (`BPRE`), title and save format, so it trades with real Gen 3 games.

## Where things are

| Area | Files | Notes |
|---|---|---|
| Maps | `data/maps/*`, `data/layouts/*`, `data/tilesets/*` | 534 maps in 43 groups (473 reachable). Names come from `tools/shinygold/map_names.json`: the map section name plus `_Interior<n>` / `_Cave<n>` / `_Area<n>` for sub-maps, `Unused_*` for unreachable leftovers. The hack reuses FireRed map slots, so some names don't match their old FireRed meaning |
| Vanilla map names | `include/constants/map_compat.h` | Old `MAP_`/`LAYOUT_`/`HEAL_LOCATION_` names used by engine code, aliased to the map in the same slot |
| Event scripts | `data/maps/*/scripts.inc`, `text.inc`, `data/scripts/*`, `data/event_scripts.s` | Generated from the ROM and checked byte-for-byte. `@ ShinyGold:` comments mark oddities (scripts that run into data, duplicated overlapping blocks, dead entries) |
| Save expansion | `src/save_block_ext.c`, `src/event_data.c`, `src/save.c` | JPAN-style: flags 0x900–0x1FFF and vars 0x4100–0x7FFF stored in the unused tails of the save sectors, same on-flash layout as the hack, so ShinyGold saves load |
| Trainers | `src/data/trainers.h`, `src/data/trainer_parties.h`, `include/constants/opponents.h` | Constants named after class + name; old FireRed names kept as aliases at the bottom of `opponents.h` |
| Wild Pokémon | `src/data/wild_encounters.json` | The hack's own 179 tables, byte-equal to ShinyGold (Hoenn species included) |
| Species / items / TMs | `src/data/pokemon/*`, `src/data/items.json`, `src/data/party_menu.h` (TM moves) | 386 species unchanged in number and order; the hack edits 13 base stats entries, evolutions (trade evolutions replaced), 20 TMs, items |
| Region map | `src/region_map.c`, `src/data/region_map/*`, `graphics/region_map/*` | Johto + Kanto map, section names, fly destinations |
| Music | `sound/songs/*.s`, `include/constants/songs.h` | 13 songs replaced by Gold/Silver tracks; song IDs unchanged, `songs.h` notes what each one now plays. Scripts can swap songs through vars 0x7030–0x7035 (`m4aSongNumStart`) |
| Graphics | `graphics/*` | Player, NPC and overworld Pokémon sprites, trainer pics, title screen, Oak speech, trainer card badges |
| Engine changes | grep `ShinyGold` in `src/` and `include/` | Listed below |

## Engine changes (ported from the hack's ASM)

- Save block extension (above); new games start in the player's room at x=1.
- Double battles need two usable party Pokémon (`CreateNPCTrainerParty`).
- Forced-shiny mode toggled by script native `ToggleForceShinyMons` (`SetBoxMonData`); applies to trainer Pokémon too, as in the hack.
- Script-controlled song replacement (vars 0x7030–0x7035) and a step counter used by scripts (`StartSaveBlockExtStepCounter`, `CheckSaveBlockExtStepCounter`).
- 16 badges counted on the main menu and save menu (new trainer card badge graphics); start menu hides BAG while flag 0x856 is set.
- Map preview screens suppressed at certain arrival points; champion mugshot depends on the opponent.
- Multichoice lists `MULTICHOICE_SG_65`..`69`, edited menu strings.
- Hall of Fame continues at heal location 14; help system disabled; flash chip detection always reports the Macronix chip (as the hack: saves may fail on Sanyo-chip carts).
- Title screen, intro, Oak speech (Marill instead of Nidoran♀, new rival names), naming screen and region map as in the hack.

Not ported on purpose: the hack zeroed 7 bytes inside `Task_RunUnionRoom` (over a literal pool and an instruction).
It looks like accidental corruption and could break Union Room trading, so vanilla code is kept.

## Fixes

### Trainer names (517 trainers)
- `NNTRAINER/K` placeholders (136) are the hack's Gold/Silver phone-rematch trainers: contact NN, rematch tier K.
  Every tier now has the Gold/Silver name of that contact (Youngster JOEY, Bug Catcher WADE, ...), matched against
  pret/pokegold parties.
- `-EDIT-`, `-EDITG-` and empty names: the Gold/Silver name when the party matches a G/S trainer exactly, the
  rival name (`SILVER`) for rival-class trainers, otherwise the FireRed name of that slot (those battles still run
  FireRed's own scripts).
- Stray trailing `!` and padding spaces removed (352). `???` names are kept on purpose (unnamed rival battles,
  mystery trainers, as in Gold/Silver).
- Two blank trainer class names filled in (`TEAM ROCKET`, `SCHOOL KID`).
- Constants and party symbols renamed to match (165). Every change, with the old name and the reason, is in
  `tools/shinygold/trainer_name_fixes.json`.

### Wild Pokémon
The hack's own tables, unchanged (the `master` and `gold` branches rebuild them from Gold/Silver instead).

### Damaged map-script headers
The hack's map tools wrote several map-script headers over older tables. In Cherrygrove/Olivine Pokémon Centers,
New Bark Town's game corner building, Lance's room and two unused maps this left garbage "on frame" tables whose
entries compare out-of-range variables (undefined behaviour that could jump into data). Those garbage entries and
the shadowed duplicate header entries are removed; the real entries (e.g. Lance's room door scene) are kept.

### Scripts the port had lost
The engine skips `gotostd N` when N is past the end of the std script table and keeps running the next bytes;
the scripts generator treated every `gotostd` as the end of a script, so three scripts ran differently from the hack:
- Tin Tower roof: Ho-Oh's battle (Lv 45) never started. Restored as the hack meant it (its "Gyaoo!" message was
  damaged): cry, "Gyaoo!", Ho-Oh Lv 45 holding SACRED ASH.
- Olivine port: the sailor's step trigger ended at once, so the player could walk past him to the S.S. Aqua at
  any time. The hack's block is back, with the ticket check and the boarding offer it calls when the ship is in.
- Trick House prize room: after the last prize the hack runs into a placeholder address; the farewell is explicit.

### Other hack bugs fixed
- Phone contact 35 crashed the game once the player had the seventh badge (a pointer outside the ROM).
- White-out after healing in Cherrygrove or New Bark Town left the player in the black outside the Pokémon Center
  (FireRed's One Island coordinates for that map slot). The player now respawns two tiles below the nurse in every
  Pokémon Center layout, and Lavender Town uses its own Pokémon Center instead of an unreachable FireRed one.
- Route 19: six invisible FireRed swimmers stacked on one water tile could start battles when surfing past.
- FireRed leftovers: the Viridian old-man catching tutorial (with a Radio-Visio gift) fired in the dead-end niche
  at the north edge of Viridian; "HOLA!" test triggers in Cherrygrove; a duplicate Guide Gent outside his house's
  walls; a Goldenrod boy's Lorelei/Icefall Cave line; the Olivine rival's "sky at night" talk text.
- The Olivine rival's exit movement ran into text bytes; the Slowpoke Well Rocket's loss text started in the
  middle of another line.
- Names: Ecruteak Gym's Sage PING is JEFFREY, Hiker RUSELL is RUSSELL; the male Rocket in the Goldenrod warehouse
  no longer uses the female sprite and pic.
- The S.S. Aqua no longer shows the Rocket Hideout map preview. Typos: VERMILION, DIGLETT'S, SEAFOAM ISLANDS.

### Hack bugs fixed during the port (all branches)
- Save extension: link/trade saves skipped the extension (turning off after a trade lost it); the save-failed
  screen overwrote it; no bounds check on the var table; the load hook copied garbage from invalid sectors; the
  forced-shiny flag lived inside `gStringVar4`.
- Maps: corrupt layout pointers (maps 1.123, 2.80, 34.71), a layout with width -1 (crash), a layout overwritten
  by text, garbage border sizes, freed tiles still in use.

### Hack quirks kept (documented in code)
- 171 scripts run into `0xFF` and 13 into invalid opcodes; the engine simply stops there, as in the hack.
- Music: the enlarged `mus_slow_pallet` header overwrites the start of `mus_teachy_tv_menu` track 1, and 32 bytes
  of an unused drum sample are overwritten.
- Marill's palette entry is tagged as Nidoran♀'s (Oak speech swap).
- The third song-swap pair never fires unless var 0x7031 is 0xFFFF; the first `sSeviiMapsecs` list has no
  terminator; several map section names were blanked in place.

## Trading with real games

Link, trade, Cable Club, Union Room and PC storage code is identical to FireRed; species, item and move counts
and IDs are unchanged. The hack sets `FLAG_SYS_CAN_LINK_WITH_RS` at Blackthorn and enables the National Dex in
Elm's lab / Route 30, so trading with Ruby/Sapphire/Emerald and FireRed/LeafGreen works as in FireRed.
Custom content stays within vanilla limits (no new species, moves or items).

## How the port was verified

- Event scripts: every generated block reassembled and compared byte-for-byte with the hack at its original
  address (0 mismatches, 11,693 labels at their original addresses).
- Maps, tilesets, trainers, parties, items, species, TMs, graphics, music, wild tables (on `faithful`):
  compared with the hack's data, 0 differences.
- Emulator: every map (534) loaded in the hack and in the rebuilt ROM from the same save, screenshots compared.
- Tools for all of this: `tools/shinygold/` (see its README).
