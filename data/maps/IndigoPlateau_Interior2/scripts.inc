IndigoPlateau_Interior2_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, IndigoPlateau_Interior2_OnResume
	map_script MAP_SCRIPT_ON_LOAD, IndigoPlateau_Interior2_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, IndigoPlateau_Interior2_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IndigoPlateau_Interior2_OnFrame
	.byte 0

IndigoPlateau_Interior2_OnResume::
	setvar VAR_0x8004, 1
	call PokemonLeague_EventScript_DoLightingEffect
	end

IndigoPlateau_Interior2_OnLoad::
	call_if_set 0x4B9, IndigoPlateau_Interior2_EventScript_OnLoad_1
	call_if_eq 0x4068, 2, IndigoPlateau_Interior2_EventScript_OnLoad_2
	end

IndigoPlateau_Interior2_EventScript_OnLoad_1::
	call PokemonLeague_EventScript_SetDoorOpen
	return

IndigoPlateau_Interior2_EventScript_OnLoad_2::
	call PokemonLeague_EventScript_CloseEntry
	return

IndigoPlateau_Interior2_OnWarp::
	map_script_2 VAR_TEMP_1, 0, IndigoPlateau_Interior2_EventScript_WarpScene
	.2byte 0

IndigoPlateau_Interior2_EventScript_WarpScene::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

IndigoPlateau_Interior2_OnFrame::
	map_script_2 0x4068, 1, IndigoPlateau_Interior2_EventScript_FrameScene
	.2byte 0

IndigoPlateau_Interior2_EventScript_FrameScene::
	lockall
	call PokemonLeague_EventScript_EnterRoom
	setvar 0x4068, 2
	releaseall
	end

IndigoPlateau_Interior2_EventScript_Koga::
	call_if_set 0x4B9, IndigoPlateau_Interior2_EventScript_Koga_1
	msgbox IndigoPlateau_Interior2_Text_Koga_1, MSGBOX_NPC
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	@ ShinyGold: the stronger rematch behind flag 0x115B is removed; nothing ever set that flag
	goto IndigoPlateau_Interior2_EventScript_Koga_3
	end

IndigoPlateau_Interior2_EventScript_Koga_1::
	msgbox IndigoPlateau_Interior2_Text_Koga_2, MSGBOX_NPC
	end

IndigoPlateau_Interior2_EventScript_Koga_3::
	trainerbattle_earlyrival TRAINER_ELITETRAINER_KOGA, 0, IndigoPlateau_Interior2_Text_KogaDefeat, IndigoPlateau_Interior2_Text_KogaVictory
	setflag 0x4B9
	call PokemonLeague_EventScript_OpenDoor
	msgbox IndigoPlateau_Interior2_Text_Koga_2, MSGBOX_NPC
	return
