IndigoPlateau_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, IndigoPlateau_Interior1_OnResume
	map_script MAP_SCRIPT_ON_LOAD, IndigoPlateau_Interior1_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_Interior1_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, IndigoPlateau_Interior1_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IndigoPlateau_Interior1_OnFrame
	.byte 0

IndigoPlateau_Interior1_OnResume::
	setvar VAR_0x8004, 0
	call PokemonLeague_EventScript_DoLightingEffect
	end

IndigoPlateau_Interior1_OnLoad::
	call_if_set 0x4B8, IndigoPlateau_Interior1_EventScript_OnLoad_1
	call_if_eq 0x4068, 1, IndigoPlateau_Interior1_EventScript_OnLoad_2
	end

IndigoPlateau_Interior1_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POKEMON_LEAGUE_LORELEIS_ROOM
	end

IndigoPlateau_Interior1_EventScript_OnLoad_1::
	call PokemonLeague_EventScript_SetDoorOpen
	return

IndigoPlateau_Interior1_EventScript_OnLoad_2::
	call PokemonLeague_EventScript_CloseEntry
	return

IndigoPlateau_Interior1_OnWarp::
	map_script_2 VAR_TEMP_1, 0, IndigoPlateau_Interior1_EventScript_WarpScene
	.2byte 0

IndigoPlateau_Interior1_EventScript_WarpScene::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

IndigoPlateau_Interior1_OnFrame::
	map_script_2 0x4068, 0, IndigoPlateau_Interior1_EventScript_FrameScene
	.2byte 0

IndigoPlateau_Interior1_EventScript_FrameScene::
	lockall
	call PokemonLeague_EventScript_EnterRoom
	setvar 0x4068, 1
	releaseall
	end

IndigoPlateau_Interior1_EventScript_Celio::
	call_if_set 0x4B8, IndigoPlateau_Interior1_EventScript_Celio_1
	msgbox IndigoPlateau_Interior1_Text_Celio_1, MSGBOX_NPC
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	@ ShinyGold: the stronger rematch behind flag 0x115B is removed; nothing ever set that flag
	goto IndigoPlateau_Interior1_EventScript_Celio_3
	end

IndigoPlateau_Interior1_EventScript_Celio_1::
	msgbox IndigoPlateau_Interior1_Text_Celio_2, MSGBOX_NPC
	end

IndigoPlateau_Interior1_EventScript_Celio_3::
	trainerbattle_no_intro TRAINER_ELITETRAINER_WILL, IndigoPlateau_Interior1_Text_CelioDefeat
	setflag 0x4B8
	call PokemonLeague_EventScript_OpenDoor
	msgbox IndigoPlateau_Interior1_Text_Celio_2, MSGBOX_NPC
	return

IndigoPlateau_Interior1_EventScript_Trigger1::
	call IndigoPlateau_Interior1_EventScript_Trigger1_1
	release
	end

IndigoPlateau_Interior1_EventScript_Trigger1_1::
	setvar 0x7030, 0x128
	setvar 0x7031, 0x136
	setvar 0x7033, 0x13C
	setvar 0x7034, 0x138
	release
	return
