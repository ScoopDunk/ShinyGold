# ShinyGold extraction and verification tools

These are the scripts that produced this tree from the ShinyGold ROM and checked the result. They are not
needed to build or modify the game; they are kept so the port can be audited or redone.

They were written for a one-off workspace and contain hard-coded paths (`/home/claude/...`). To rerun them,
edit the constants at the top of `lib/core.py` (`HACK_ROM`, `VANILLA_ROM`, `VANILLA_DIR`) and the paths at the
top of each script. Inputs:

| Input | What |
|---|---|
| hack ROM | FireRed (U) 1.0 + `ShinyGold_Faithfully_Fixed_Beta5.ips` |
| vanilla ROM | FireRed (U) 1.0, sha1 `41cb23d8dccc8ebd7c649cd8fbb58eeace6e2fdc` |
| vanilla tree | a built pret/pokefirered checkout (symbols in `pokefirered.map`/`.sym`) |
| pokegold | pret/pokegold at `ef0201d8` (Gold/Silver wild data and trainer parties) |
| mGBA 0.10.3 | `libmgba.a`, for the emulator checks |

## Layout

| Folder | Purpose |
|---|---|
| `lib/` | Shared library: ROM access, text/charmap, map headers, naming (`naming.py` -> `map_names.json`), constant names (`names.py`), wild tables (`wild.py`), save files. Also the fix scripts applied on top of the faithful port: `fix_trainer_names.py`, `gs_wild_apply.py`, `fix_map_script_tables.py` |
| `scripts_gen/` | Event script / text / movement generator. `run.sh <tree> --fill-maps` regenerates `data/maps/*/scripts.inc`, `text.inc`, shared script files and `data/event_scripts.s`, then verifies every block byte-for-byte against the hack at its original address. Afterwards restore `data/text/new_game_intro.inc` (hand-edited engine text) with git |
| `maps_gen/` | Maps, layouts, tilesets, connections, heal locations (`generate.py <tree>`) |
| `data/` | Trainers, parties, classes, items, TMs, evolutions, in-game trades (`gen_data.py`) and table comparers |
| `gfx/` | Graphics port and byte comparison of decompressed graphics |
| `music/` | Song disassembly (`gen_songs.py`) and the semantic song/voicegroup checker |
| `engine/` | Helpers used while porting the ASM hooks (region map generator, RAM/symbol checks) |
| `gs_wild/` | Gold/Silver wild data: parse pokegold, merge Gold+Silver, blend morning/day/night, fit into FireRed slots |
| `verify/` | `gbarun.c` (headless mGBA runner) and `sweep.py` (loads every map in both ROMs and compares screenshots) |
| `map_names.json` | Map naming used everywhere (group.num -> name, constant, map section, reachability) |
| `trainer_name_fixes.json` | Every trainer name change with the old name and the reason |

Build `gbarun` with the same defines mGBA was built with, otherwise `struct mCore` layouts mismatch:

```
DEFS="-DUSE_ZLIB -DUSE_PTHREADS -DUSE_PNG -DUSE_MINIZIP -DUSE_LZMA -DUSE_GDB_STUB -DUSE_DEBUGGERS -DM_CORE_GBA \
      -DM_CORE_GB -DENABLE_SCRIPTING -DBUILD_STATIC -D_GNU_SOURCE -DHAVE_STRDUP -DHAVE_STRNDUP \
      -DHAVE_LOCALTIME_R -DHAVE_VASPRINTF -DHAVE_STRLCPY"
gcc -O2 -o gbarun gbarun.c $DEFS -I<mgba>/include -I<mgba>/build/include <mgba>/build/libmgba.a -lpng -lz -lm -lpthread
```
