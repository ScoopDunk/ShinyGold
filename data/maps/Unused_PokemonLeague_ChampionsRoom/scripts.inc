Unused_PokemonLeague_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Unused_PokemonLeague_ChampionsRoom_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x08162A02
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x08162B6C
	.byte 0

Unused_PokemonLeague_ChampionsRoom_OnResume::
	release
	applymovement LOCALID_PLAYER, Unused_PokemonLeague_ChampionsRoom_Movement_OnResume
	delay 64
	end

Unused_PokemonLeague_ChampionsRoom_Movement_OnResume::
	walk_up
	walk_up
	walk_up
	step_end
