IndigoPlateau_Interior4_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, IndigoPlateau_Interior4_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IndigoPlateau_Interior4_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, IndigoPlateau_Interior4_OnWarp
	.byte 0

IndigoPlateau_Interior4_OnResume::
	call_if_set 0x115C, IndigoPlateau_Interior4_EventScript_OnResume_1
	setflag 0x115C
	special DoPokemonLeagueLightingEffect
	applymovement LOCALID_PLAYER, IndigoPlateau_Interior4_Movement_OnResume
	delay 64
	end

IndigoPlateau_Interior4_OnWarp::
	@ ShinyGold: overlapping data duplicated from 0x0816296E
	map_script_2 VAR_TEMP_0, 0, IndigoPlateau_Interior4_EventScript_WarpScene
	.2byte 0

IndigoPlateau_Interior4_EventScript_OnResume_1::
	release
	end

IndigoPlateau_Interior4_OnFrame::
	map_script_2 0x4068, 3, IndigoPlateau_Interior4_EventScript_FrameScene7
	.2byte 0

IndigoPlateau_Interior4_EventScript_FrameScene7::
	lockall
	applymovement LOCALID_PLAYER, IndigoPlateau_Interior4_Movement_FrameScene7
	waitmovement 0
	setflag FLAG_TEMP_2
	call IndigoPlateau_Interior4_EventScript_FrameScene7_1
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	setvar 0x4068, 4
	releaseall
	end

IndigoPlateau_Interior4_EventScript_WarpScene::
	@ ShinyGold: overlapping data duplicated from 0x08162978
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

IndigoPlateau_Interior4_Movement_OnResume::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

IndigoPlateau_Interior4_EventScript_FrameScene7_1::
	setmetatile 5, 14, 0x29D, 1
	setmetatile 6, 14, 0x29E, 1
	setmetatile 7, 14, 0x29F, 1
	setmetatile 5, 15, 0x2A5, 1
	setmetatile 6, 15, 0x2A6, 1
	setmetatile 7, 15, 0x2A7, 1
	setmetatile 6, 16, 0x311, 0
	setmetatile 7, 16, 0x311, 0
	return

IndigoPlateau_Interior4_Movement_FrameScene7::
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

IndigoPlateau_Interior4_EventScript_Lorelei::
	call_if_set 0x4BB, IndigoPlateau_Interior4_EventScript_Lorelei_1
	msgbox IndigoPlateau_Interior4_Text_Lorelei_1, MSGBOX_NPC
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	setflag 0x115C
	@ ShinyGold: the stronger rematch behind flag 0x115B is removed; nothing ever set that flag
	goto IndigoPlateau_Interior4_EventScript_Lorelei_3
	end

IndigoPlateau_Interior4_EventScript_Lorelei_1::
	msgbox IndigoPlateau_Interior4_Text_Lorelei_2, MSGBOX_NPC
	end

IndigoPlateau_Interior4_EventScript_Lorelei_3::
	trainerbattle_earlyrival TRAINER_ELITETRAINER_KAREN, 0, IndigoPlateau_Interior4_Text_LoreleiDefeat, IndigoPlateau_Interior4_Text_LoreleiVictory
	setflag 0x4BB
	call PokemonLeague_EventScript_OpenDoor
	msgbox IndigoPlateau_Interior4_Text_Lorelei_2, MSGBOX_NPC
	return
