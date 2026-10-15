Route7_Interior1_MapScripts::
	.byte 0

Route7_Interior1_EventScript_Policeman::
	msgbox Route7_Interior1_Text_Policeman, MSGBOX_NPC
	end

Route7_Interior1_EventScript_Trigger1::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route7_Interior1_EventScript_Trigger1_1

Route7_Interior1_EventScript_Trigger1_1::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto_if_set 0x2A6, Route7_Interior1_EventScript_Trigger1_2
	msgbox Route7_Interior1_Text_Trigger1_1
	closemessage
	applymovement LOCALID_PLAYER, Route7_Interior1_Movement_Trigger1_1
	waitmovement 0
	releaseall
	end

Route7_Interior1_EventScript_Trigger1_2::
	removeitem ITEM_TEA
	goto Route7_Interior1_EventScript_Trigger1_3

Route7_Interior1_EventScript_Trigger1_3::
	msgbox Route7_Interior1_Text_Trigger1_2
	closemessage
	call_if_eq VAR_TEMP_1, 0, Route7_Interior1_EventScript_Trigger1_4
	call_if_eq VAR_TEMP_1, 1, Route7_Interior1_EventScript_Trigger1_5
	call_if_eq VAR_TEMP_1, 2, Route7_Interior1_EventScript_Trigger1_6
	msgbox Route7_Interior1_Text_Trigger1_3
	setvar 0x4062, 1
	releaseall
	end

Route7_Interior1_Movement_Trigger1_1::
	walk_left
	step_end

Route7_Interior1_EventScript_Trigger1_4::
	applymovement LOCALID_PLAYER, Route7_Interior1_Movement_Trigger1_2
	waitmovement 0
	return

Route7_Interior1_EventScript_Trigger1_5::
	applymovement LOCALID_PLAYER, Route7_Interior1_Movement_Trigger1_3
	waitmovement 0
	return

Route7_Interior1_EventScript_Trigger1_6::
	applymovement LOCALID_PLAYER, Route7_Interior1_Movement_Trigger1_4
	waitmovement 0
	return

Route7_Interior1_Movement_Trigger1_2::
	walk_in_place_up
	step_end

Route7_Interior1_Movement_Trigger1_3::
	walk_up
	step_end

Route7_Interior1_Movement_Trigger1_4::
	walk_up
	walk_up
	step_end

Route7_Interior1_EventScript_Trigger2::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route7_Interior1_EventScript_Trigger1_1

Route7_Interior1_EventScript_Trigger3::
	lockall
	setvar VAR_TEMP_1, 2
	goto Route7_Interior1_EventScript_Trigger1_1
