PurityForest_Interior12_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PurityForest_Interior12_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PurityForest_Interior12_OnFrame
	.byte 0

PurityForest_Interior12_OnTransition::
	special ValidateEReaderTrainer
	call_if_eq VAR_RESULT, 0, PurityForest_Interior12_EventScript_OnTransition_1
	call_if_ne 0x4074, 0, PurityForest_Interior12_EventScript_OnTransition_2
	end

PurityForest_Interior12_EventScript_OnTransition_1::
	setvar VAR_TEMP_1, 1
	setobjectxyperm 1, 4, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	setmaplayoutindex LAYOUT_UNUSED_LAYOUT264
	return

PurityForest_Interior12_EventScript_OnTransition_2::
	setobjectxyperm 1, 3, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_RIGHT
	return

PurityForest_Interior12_OnFrame::
	map_script_2 0x4074, 1, PurityForest_Interior12_EventScript_FrameScene1
	map_script_2 0x4074, 2, PurityForest_Interior12_EventScript_FrameScene1
	map_script_2 0x4074, 3, PurityForest_Interior12_EventScript_FrameScene1
	.2byte 0

PurityForest_Interior12_EventScript_FrameScene1::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_PLAYER, PurityForest_Interior12_Movement_FrameScene1_1
	waitmovement 0
	applymovement 1, PurityForest_Interior12_Movement_FrameScene1_2
	waitmovement 0
	copyobjectxytoperm 1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call_if_eq 0x4074, 1, PurityForest_Interior12_EventScript_FrameScene1_1
	call_if_eq 0x4074, 2, PurityForest_Interior12_EventScript_FrameScene1_2
	call_if_eq 0x4074, 3, PurityForest_Interior12_EventScript_FrameScene1_3
	special LoadPlayerParty
	setvar 0x4074, 0
	releaseall
	end

PurityForest_Interior12_EventScript_FrameScene1_1::
	msgbox PurityForest_Interior12_Text_FrameScene1_1
	return

PurityForest_Interior12_EventScript_FrameScene1_2::
	msgbox PurityForest_Interior12_Text_FrameScene1_2
	return

PurityForest_Interior12_EventScript_FrameScene1_3::
	msgbox PurityForest_Interior12_Text_FrameScene1_3
	return

PurityForest_Interior12_Movement_FrameScene1_1::
	walk_down
	step_end

PurityForest_Interior12_Movement_FrameScene1_2::
	walk_right
	walk_in_place_faster_down
	step_end

PurityForest_Interior12_EventScript_Woman1::
	msgbox PurityForest_Interior12_Text_Woman1, MSGBOX_NPC
	end

PurityForest_Interior12_EventScript_WorkerF::
	msgbox PurityForest_Interior12_Text_WorkerF, MSGBOX_NPC
	end

PurityForest_Interior12_EventScript_Lass::
	msgbox PurityForest_Interior12_Text_Lass, MSGBOX_NPC
	end
