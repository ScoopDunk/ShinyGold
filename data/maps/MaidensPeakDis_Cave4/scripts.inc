MaidensPeakDis_Cave4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MaidensPeakDis_Cave4_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MaidensPeakDis_Cave4_OnFrame
	.byte 0

MaidensPeakDis_Cave4_OnTransition::
	call_if_unset 0x2D2, MaidensPeakDis_Cave4_EventScript_OnTransition_1
	call_if_set 0x2D2, MaidensPeakDis_Cave4_EventScript_OnTransition_2
	end

MaidensPeakDis_Cave4_EventScript_OnTransition_1::
	setvar VAR_TEMP_2, 0
	call_if_unset 0x046, MaidensPeakDis_Cave4_EventScript_OnTransition_3
	call_if_unset 0x047, MaidensPeakDis_Cave4_EventScript_OnTransition_3
	call_if_eq VAR_TEMP_2, 2, MaidensPeakDis_Cave4_EventScript_OnTransition_4
	return

MaidensPeakDis_Cave4_EventScript_OnTransition_2::
	setmaplayoutindex LAYOUT_UNUSED_LAYOUT278
	return

MaidensPeakDis_Cave4_OnFrame::
	map_script_2 VAR_TEMP_1, 1, MaidensPeakDis_Cave4_EventScript_FrameScene
	.2byte 0

MaidensPeakDis_Cave4_EventScript_FrameScene::
	lockall
	setvar VAR_TEMP_2, 0
	call_if_unset 0x046, MaidensPeakDis_Cave4_EventScript_OnTransition_3
	call_if_unset 0x047, MaidensPeakDis_Cave4_EventScript_OnTransition_3
	goto_if_eq VAR_TEMP_2, 2, MaidensPeakDis_Cave4_EventScript_FrameScene_1
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_lt VAR_0x8008, 24, MaidensPeakDis_Cave4_EventScript_FrameScene_2
	call_if_ge VAR_0x8008, 24, MaidensPeakDis_Cave4_EventScript_FrameScene_3
	setvar 0x4063, 1
	warp MAP_MAIDENS_PEAK_DIS_CAVE5, 27, 21
	waitstate
	releaseall
	end

MaidensPeakDis_Cave4_EventScript_OnTransition_3::
	addvar VAR_TEMP_2, 1
	return

MaidensPeakDis_Cave4_EventScript_OnTransition_4::
	setflag 0x2D2
	return

MaidensPeakDis_Cave4_EventScript_FrameScene_1::
	setvar VAR_TEMP_1, 0
	releaseall
	end

MaidensPeakDis_Cave4_EventScript_FrameScene_2::
	applymovement LOCALID_PLAYER, MaidensPeakDis_Cave4_Movement_FrameScene_1
	waitmovement 0
	return

MaidensPeakDis_Cave4_EventScript_FrameScene_3::
	applymovement LOCALID_PLAYER, MaidensPeakDis_Cave4_Movement_FrameScene_2
	waitmovement 0
	return

MaidensPeakDis_Cave4_Movement_FrameScene_1::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

MaidensPeakDis_Cave4_Movement_FrameScene_2::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
