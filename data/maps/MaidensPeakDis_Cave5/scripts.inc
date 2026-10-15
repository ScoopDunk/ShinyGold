MaidensPeakDis_Cave5_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MaidensPeakDis_Cave5_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MaidensPeakDis_Cave5_OnResume
	map_script MAP_SCRIPT_ON_LOAD, MaidensPeakDis_Cave5_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MaidensPeakDis_Cave5_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MaidensPeakDis_Cave5_OnFrame
	.byte 0

MaidensPeakDis_Cave5_OnTransition::
	call_if_unset 0x2BE, MaidensPeakDis_Cave5_EventScript_OnTransition_1
	call_if_unset 0x2D3, MaidensPeakDis_Cave5_EventScript_OnTransition_2
	call_if_set 0x2D3, MaidensPeakDis_Cave5_EventScript_OnTransition_3
	end

MaidensPeakDis_Cave5_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, MaidensPeakDis_Cave5_EventScript_OnResume_1
	end

MaidensPeakDis_Cave5_OnLoad::
	setvar VAR_TEMP_2, 0
	call_if_unset 0x04C, MaidensPeakDis_Cave5_EventScript_OnLoad_1
	call_if_unset 0x04D, MaidensPeakDis_Cave5_EventScript_OnLoad_1
	goto_if_eq VAR_TEMP_2, 2, MaidensPeakDis_Cave5_EventScript_OnLoad_2
	end

MaidensPeakDis_Cave5_EventScript_OnTransition_1::
	clearflag 0x082
	return

MaidensPeakDis_Cave5_EventScript_OnTransition_2::
	setvar VAR_TEMP_2, 0
	call_if_unset 0x04C, MaidensPeakDis_Cave5_EventScript_OnLoad_1
	call_if_unset 0x04D, MaidensPeakDis_Cave5_EventScript_OnLoad_1
	call_if_eq VAR_TEMP_2, 2, MaidensPeakDis_Cave5_EventScript_OnTransition_4
	return

MaidensPeakDis_Cave5_EventScript_OnTransition_3::
	setmaplayoutindex LAYOUT_UNUSED_LAYOUT279
	return

MaidensPeakDis_Cave5_EventScript_OnResume_1::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, 7, EventScript_Return
	removeobject VAR_LAST_TALKED
	return

MaidensPeakDis_Cave5_EventScript_OnLoad_1::
	addvar VAR_TEMP_2, 1
	return

MaidensPeakDis_Cave5_EventScript_OnLoad_2::
	setmetatile 12, 14, 0x12B, 0
	setmetatile 13, 14, 0x12B, 0
	end

MaidensPeakDis_Cave5_OnWarp::
	map_script_2 0x4063, 1, MaidensPeakDis_Cave5_EventScript_WarpScene
	.2byte 0

MaidensPeakDis_Cave5_EventScript_WarpScene::
	turnobject LOCALID_PLAYER, DIR_NORTH
	special ForcePlayerToStartSurfing
	end

MaidensPeakDis_Cave5_OnFrame::
	map_script_2 0x4063, 1, MaidensPeakDis_Cave5_EventScript_FrameScene1
	map_script_2 VAR_TEMP_1, 1, MaidensPeakDis_Cave5_EventScript_FrameScene2
	.2byte 0

MaidensPeakDis_Cave5_EventScript_FrameScene1::
	lockall
	applymovement LOCALID_PLAYER, MaidensPeakDis_Cave5_Movement_FrameScene1
	waitmovement 0
	setvar 0x4063, 0
	releaseall
	end

MaidensPeakDis_Cave5_EventScript_FrameScene2::
	lockall
	setvar VAR_TEMP_2, 0
	call_if_unset 0x04C, MaidensPeakDis_Cave5_EventScript_OnLoad_1
	call_if_unset 0x04D, MaidensPeakDis_Cave5_EventScript_OnLoad_1
	goto_if_eq VAR_TEMP_2, 2, MaidensPeakDis_Cave5_EventScript_FrameScene2_1
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_lt VAR_0x8008, 9, MaidensPeakDis_Cave5_EventScript_FrameScene2_2
	call_if_ge VAR_0x8008, 9, MaidensPeakDis_Cave5_EventScript_FrameScene2_3
	special SeafoamIslandsB4F_CurrentDumpsPlayerOnLand
	setvar VAR_TEMP_1, 0
	releaseall
	end

MaidensPeakDis_Cave5_EventScript_OnTransition_4::
	setflag 0x2D3
	return

MaidensPeakDis_Cave5_EventScript_FrameScene2_1::
	setvar VAR_TEMP_1, 0
	releaseall
	end

MaidensPeakDis_Cave5_EventScript_FrameScene2_2::
	applymovement LOCALID_PLAYER, MaidensPeakDis_Cave5_Movement_FrameScene2_1
	waitmovement 0
	return

MaidensPeakDis_Cave5_EventScript_FrameScene2_3::
	applymovement LOCALID_PLAYER, MaidensPeakDis_Cave5_Movement_FrameScene2_2
	waitmovement 0
	return

MaidensPeakDis_Cave5_Movement_FrameScene1::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

MaidensPeakDis_Cave5_Movement_FrameScene2_1::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

MaidensPeakDis_Cave5_Movement_FrameScene2_2::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

MaidensPeakDis_Cave5_EventScript_Articuno::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_ARTICUNO, 50
	waitse
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	message Text_Gyaoo
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, 1, MaidensPeakDis_Cave5_EventScript_Articuno_1
	goto_if_eq VAR_RESULT, 4, MaidensPeakDis_Cave5_EventScript_Articuno_2
	goto_if_eq VAR_RESULT, 5, MaidensPeakDis_Cave5_EventScript_Articuno_2
	setflag 0x2BE
	release
	end

MaidensPeakDis_Cave5_EventScript_Articuno_1::
	setflag 0x2BE
	goto EventScript_RemoveStaticMon

MaidensPeakDis_Cave5_EventScript_Articuno_2::
	setvar VAR_0x8004, 144
	goto EventScript_MonFlewAway

MaidensPeakDis_Cave5_EventScript_Trigger1::
	lockall
	applymovement LOCALID_PLAYER, MaidensPeakDis_Cave5_Movement_Trigger1
	waitmovement 0
	releaseall
	end

MaidensPeakDis_Cave5_Movement_Trigger1::
	walk_up
	step_end

MaidensPeakDis_Cave5_EventScript_Sign1::
	msgbox MaidensPeakDis_Cave5_Text_Sign1, MSGBOX_SIGN
	end

MaidensPeakDis_Cave5_EventScript_Sign2::
	msgbox MaidensPeakDis_Cave5_Text_Sign2, MSGBOX_SIGN
	end
