Unused_PokemonLeague_HallOfFame_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Unused_PokemonLeague_HallOfFame_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Unused_PokemonLeague_HallOfFame_OnWarp
	.byte 0

Unused_PokemonLeague_HallOfFame_OnFrame::
	map_script_2 VAR_TEMP_1, 0, Unused_PokemonLeague_HallOfFame_EventScript_FrameScene
	.2byte 0

Unused_PokemonLeague_HallOfFame_EventScript_FrameScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, Unused_PokemonLeague_HallOfFame_Movement_FrameScene
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 18
	msgbox Unused_PokemonLeague_HallOfFame_Text_FrameScene
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	setvar VAR_TEMP_1, 1
	call EventScript_SetDefeatedEliteFourFlagsVars
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
	fadescreenspeed FADE_TO_BLACK, 24
	special EnterHallOfFame
	waitstate
	releaseall
	end

Unused_PokemonLeague_HallOfFame_OnWarp::
	map_script_2 VAR_TEMP_1, 0, Unused_PokemonLeague_HallOfFame_EventScript_WarpScene
	.2byte 0

Unused_PokemonLeague_HallOfFame_EventScript_WarpScene::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

Unused_PokemonLeague_HallOfFame_Movement_FrameScene::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
