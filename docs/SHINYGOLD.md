# ShinyGold decompilation

This tree is ShinyGold (Faithfully Fixed, Beta 5) ported onto pret/pokefirered. `make` builds
`pokefirered.gba`: ShinyGold with its broken trainer names fixed and wild Pokémon rebuilt from Gold/Silver.

## Branches

| Branch | Contents |
|---|---|
| `master` | The game to work from: the faithful port plus the fixes below |
| `faithful` | The hack ported as-is (only crash-level hack bugs fixed). Use it to see what the hack itself did |
| first commit | Unmodified pret/pokefirered, so `git diff <first commit>` shows everything ShinyGold changes |

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
| Wild Pokémon | `src/data/wild_encounters.json` | See below and `docs/wild_encounters_gs.md` |
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

## Fixes on `master`

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

### Wild Pokémon: pure Gold/Silver
- Every map that corresponds to a Gold/Silver location (115 tables) uses that location's data from pret/pokegold.
  Gold and Silver are merged (Gold as the base, Silver exclusives added, so both versions' Pokémon are catchable in
  one game). ShinyGold has no clock, so morning/day/night tables are blended by hours (6/8/10).
  The G/S encounter rates are used, converted to FireRed's scale.
- Headbutt: the hack uses rock-smash tables on Johto routes as headbutt stand-ins; they now hold the G/S headbutt
  distribution of that route. Real G/S Rock Smash data is used where it exists; other rock-smash tables are removed.
- Areas with no G/S counterpart (61 tables: Safari Zone areas, extra caves, unused maps) keep their tables, but
  every species not found in the wild in Gold or Silver is replaced by a similar one that is, at the same levels.
- 3 tables removed where G/S has no wild Pokémon (Mahogany Town, Route 23, S.S. Aqua).
- Pokédex, species data and IDs stay at 386, so trades and Pokédex completion are unaffected.

Per-map before/after: `docs/wild_encounters_gs.md`. To change the policy, edit `tools/shinygold/lib/gs_wild_apply.py`
(mapping table and substitutions) and rerun it, or edit `src/data/wild_encounters.json` directly.

### Damaged map-script headers
The hack's map tools wrote several map-script headers over older tables. In Cherrygrove/Olivine Pokémon Centers,
New Bark Town's game corner building, Lance's room and two unused maps this left garbage "on frame" tables whose
entries compare out-of-range variables (undefined behaviour that could jump into data). Those garbage entries and
the shadowed duplicate header entries are removed; the real entries (e.g. Lance's room door scene) are kept.

### Hack bugs fixed during the port (both branches)
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
