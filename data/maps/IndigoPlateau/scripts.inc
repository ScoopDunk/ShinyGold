IndigoPlateau_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IndigoPlateau_OnFrame
	.byte 0

IndigoPlateau_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_INDIGO_PLATEAU_EXTERIOR
	call_if_eq VAR_MAP_SCENE_INDIGO_PLATEAU_EXTERIOR, 1, IndigoPlateau_EventScript_OnTransition_1
	end

IndigoPlateau_EventScript_OnTransition_1::
	playbgm MUS_CREDITS, 0
	return

IndigoPlateau_OnFrame::
	map_script_2 VAR_MAP_SCENE_INDIGO_PLATEAU_EXTERIOR, 1, IndigoPlateau_EventScript_FrameScene
	.2byte 0

IndigoPlateau_EventScript_FrameScene::
	lockall
	delay 105
	opendoor 11, 6
	waitdooranim
	special SpawnCameraObject
	addobject 1
	applymovement 1, IndigoPlateau_Movement_FrameScene_1
	applymovement LOCALID_PLAYER, IndigoPlateau_Movement_FrameScene_2
	waitmovement 0
	closedoor 11, 6
	waitdooranim
	applymovement LOCALID_PLAYER, IndigoPlateau_Movement_FrameScene_3
	applymovement 1, IndigoPlateau_Movement_FrameScene_4
	waitmovement 0
	delay 100
	opendoor 11, 6
	waitdooranim
	addobject 2
	applymovement 2, IndigoPlateau_Movement_FrameScene_5
	waitmovement 0
	closedoor 11, 6
	waitdooranim
	delay 160
	applymovement LOCALID_PLAYER, IndigoPlateau_Movement_FrameScene_6
	applymovement 2, IndigoPlateau_Movement_FrameScene_7
	waitmovement 0
	delay 100
	applymovement LOCALID_PLAYER, IndigoPlateau_Movement_FrameScene_8
	waitmovement 0
	delay 155
	applymovement LOCALID_PLAYER, IndigoPlateau_Movement_FrameScene_9
	waitmovement 0
	delay 90
	applymovement LOCALID_PLAYER, IndigoPlateau_Movement_FrameScene_10
	waitmovement 0
	applymovement LOCALID_PLAYER, IndigoPlateau_Movement_FrameScene_11
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_MAP_SCENE_INDIGO_PLATEAU_EXTERIOR, 0
	removeobject 1
	removeobject 2
	special DoCredits
	waitstate
	releaseall
	end

IndigoPlateau_Movement_FrameScene_1::
	walk_fast_down
	step_end

IndigoPlateau_Movement_FrameScene_2::
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

IndigoPlateau_Movement_FrameScene_3::
	delay_16
	delay_4
	walk_in_place_faster_down
	step_end

IndigoPlateau_Movement_FrameScene_4::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

IndigoPlateau_Movement_FrameScene_5::
	walk_down
	step_end

IndigoPlateau_Movement_FrameScene_6::
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

IndigoPlateau_Movement_FrameScene_7::
	walk_in_place_faster_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

IndigoPlateau_Movement_FrameScene_8::
	walk_right
	delay_16
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

IndigoPlateau_Movement_FrameScene_9::
	walk_in_place_faster_up
	step_end

IndigoPlateau_Movement_FrameScene_10::
	walk_in_place_faster_down
	step_end

IndigoPlateau_Movement_FrameScene_11::
	player_run_down
	player_run_down
	player_run_down
	player_run_down
	player_run_down
	player_run_down
	step_end

IndigoPlateau_EventScript_Trigger1::
	setvar 0x7030, 0x10A
	setvar 0x7031, 0x154
	setvar 0x7033, 0x129
	setvar 0x7034, 0x12A
	release
	return
