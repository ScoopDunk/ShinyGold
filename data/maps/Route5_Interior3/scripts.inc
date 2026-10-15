Route5_Interior3_MapScripts::
	.byte 0

Route5_Interior3_EventScript_Policeman::
	msgbox Route5_Interior3_Text_Policeman, MSGBOX_NPC
	end

Route5_Interior3_EventScript_Trigger1::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route5_Interior3_EventScript_Trigger1_1

Route5_Interior3_EventScript_Trigger1_1::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto_if_set 0x2A6, Route5_Interior3_EventScript_Trigger1_2
	msgbox Route5_Interior3_Text_Trigger1_1
	closemessage
	applymovement LOCALID_PLAYER, Route5_Interior3_Movement_Trigger1_1
	waitmovement 0
	releaseall
	end

Route5_Interior3_EventScript_Trigger1_2::
	removeitem ITEM_TEA
	goto Route5_Interior3_EventScript_Trigger1_3

Route5_Interior3_EventScript_Trigger1_3::
	msgbox Route5_Interior3_Text_Trigger1_2
	closemessage
	call_if_eq VAR_TEMP_1, 0, Route5_Interior3_EventScript_Trigger1_4
	call_if_eq VAR_TEMP_1, 1, Route5_Interior3_EventScript_Trigger1_5
	call_if_eq VAR_TEMP_1, 2, Route5_Interior3_EventScript_Trigger1_6
	msgbox Route5_Interior3_Text_Trigger1_3
	setvar 0x4062, 1
	releaseall
	end

Route5_Interior3_Movement_Trigger1_1::
	walk_up
	step_end

Route5_Interior3_EventScript_Trigger1_4::
	applymovement LOCALID_PLAYER, Route5_Interior3_Movement_Trigger1_2
	waitmovement 0
	return

Route5_Interior3_EventScript_Trigger1_5::
	applymovement LOCALID_PLAYER, Route5_Interior3_Movement_Trigger1_3
	waitmovement 0
	return

Route5_Interior3_EventScript_Trigger1_6::
	applymovement LOCALID_PLAYER, Route5_Interior3_Movement_Trigger1_4
	waitmovement 0
	return

Route5_Interior3_Movement_Trigger1_2::
	walk_in_place_left
	step_end

Route5_Interior3_Movement_Trigger1_3::
	walk_left
	step_end

Route5_Interior3_Movement_Trigger1_4::
	walk_left
	walk_left
	step_end

Route5_Interior3_EventScript_Trigger2::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route5_Interior3_EventScript_Trigger1_1

Route5_Interior3_EventScript_Trigger3::
	lockall
	setvar VAR_TEMP_1, 2
	goto Route5_Interior3_EventScript_Trigger1_1
