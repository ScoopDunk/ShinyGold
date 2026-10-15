Route16_Interior2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route16_Interior2_OnTransition
	.byte 0

Route16_Interior2_OnTransition::
	clearflag FLAG_SYS_ON_CYCLING_ROAD
	call_if_set FLAG_GOT_BICYCLE, Route16_Interior2_EventScript_OnTransition_1
	end

Route16_Interior2_EventScript_OnTransition_1::
	setvar VAR_TEMP_1, 1
	return

Route16_Interior2_EventScript_Policeman::
	msgbox Route16_Interior2_Text_Policeman, MSGBOX_NPC
	end

Route16_Interior2_EventScript_OldMan1::
	msgbox Route16_Interior2_Text_OldMan1, MSGBOX_NPC
	end

Route16_Interior2_EventScript_Trigger3::
	checkitem ITEM_BICYCLE
	call_if_lt VAR_RESULT, 1, Route16_Interior2_EventScript_Trigger3_1
	release
	end

Route16_Interior2_EventScript_Trigger3_1::
	applymovement LOCALID_PLAYER, Route16_Interior2_Movement_Trigger3_1
	delay 1
	msgbox Route16_Interior2_Text_Trigger3_1, MSGBOX_NPC
	msgbox Route16_Interior2_Text_Trigger3_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Route16_Interior2_Movement_Trigger3_2
	delay 16
	end

Route16_Interior2_Movement_Trigger3_1::
	face_up
	step_end

Route16_Interior2_Movement_Trigger3_2::
	walk_right
	step_end

Route16_Interior2_EventScript_Trigger4::
	checkitem ITEM_BICYCLE
	call_if_lt VAR_RESULT, 1, Route16_Interior2_EventScript_Trigger4_1
	release
	end

Route16_Interior2_EventScript_Trigger4_1::
	applymovement LOCALID_PLAYER, Route16_Interior2_Movement_Trigger3_1
	delay 1
	msgbox Route16_Interior2_Text_Trigger3_1, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Route16_Interior2_Movement_Trigger4
	delay 16
	msgbox Route16_Interior2_Text_Trigger3_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Route16_Interior2_Movement_Trigger3_2
	delay 16
	end

Route16_Interior2_Movement_Trigger4::
	walk_up
	step_end

Route16_Interior2_EventScript_Trigger9::
	checkitem ITEM_BICYCLE
	call_if_lt VAR_RESULT, 1, Route16_Interior2_EventScript_Trigger9_1
	release
	end

Route16_Interior2_EventScript_Trigger9_1::
	applymovement LOCALID_PLAYER, Route16_Interior2_Movement_Trigger3_1
	delay 1
	msgbox Route16_Interior2_Text_Trigger3_1, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Route16_Interior2_Movement_Trigger9
	delay 32
	msgbox Route16_Interior2_Text_Trigger3_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Route16_Interior2_Movement_Trigger3_2
	delay 16
	end

Route16_Interior2_Movement_Trigger9::
	walk_up
	walk_up
	step_end

Route16_Interior2_EventScript_Trigger10::
	checkitem ITEM_BICYCLE
	call_if_lt VAR_RESULT, 1, Route16_Interior2_EventScript_Trigger10_1
	release
	end

Route16_Interior2_EventScript_Trigger10_1::
	applymovement LOCALID_PLAYER, Route16_Interior2_Movement_Trigger3_1
	delay 1
	msgbox Route16_Interior2_Text_Trigger3_1, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Route16_Interior2_Movement_Trigger10
	delay 48
	msgbox Route16_Interior2_Text_Trigger3_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Route16_Interior2_Movement_Trigger3_2
	delay 16
	end

Route16_Interior2_Movement_Trigger10::
	walk_up
	walk_up
	walk_up
	step_end

Route16_Interior2_EventScript_Trigger11::
	checkitem ITEM_BICYCLE
	call_if_lt VAR_RESULT, 1, Route16_Interior2_EventScript_Trigger11_1
	release
	end

Route16_Interior2_EventScript_Trigger11_1::
	applymovement LOCALID_PLAYER, Route16_Interior2_Movement_Trigger3_1
	delay 1
	msgbox Route16_Interior2_Text_Trigger3_1, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Route16_Interior2_Movement_Trigger11
	delay 64
	msgbox Route16_Interior2_Text_Trigger3_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Route16_Interior2_Movement_Trigger3_2
	delay 16
	end

Route16_Interior2_Movement_Trigger11::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
