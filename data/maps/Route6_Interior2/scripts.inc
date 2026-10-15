Route6_Interior2_MapScripts::
	.byte 0

Route6_Interior2_EventScript_Policeman::
	goto_if_set 0x1185, Route6_Interior2_EventScript_Policeman_1
	msgbox Route6_Interior2_Text_Policeman_1, MSGBOX_NPC
	end

Route6_Interior2_EventScript_Policeman_1::
	msgbox Route6_Interior2_Text_Policeman_2, MSGBOX_NPC
	end

Route6_Interior2_EventScript_Trigger1::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route6_Interior2_EventScript_Trigger1_1

Route6_Interior2_EventScript_Trigger1_1::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto_if_set 0x2A6, Route6_Interior2_EventScript_Trigger1_2
	msgbox Route6_Interior2_Text_Trigger1_1
	closemessage
	applymovement LOCALID_PLAYER, Route6_Interior2_Movement_Trigger1_1
	waitmovement 0
	releaseall
	end

Route6_Interior2_EventScript_Trigger1_2::
	removeitem ITEM_TEA
	goto Route6_Interior2_EventScript_Trigger1_3

Route6_Interior2_EventScript_Trigger1_3::
	msgbox Route6_Interior2_Text_Trigger1_2
	closemessage
	call_if_eq VAR_TEMP_1, 0, Route6_Interior2_EventScript_Trigger1_4
	call_if_eq VAR_TEMP_1, 1, Route6_Interior2_EventScript_Trigger1_5
	call_if_eq VAR_TEMP_1, 2, Route6_Interior2_EventScript_Trigger1_6
	msgbox Route6_Interior2_Text_Trigger1_3
	setvar 0x4062, 1
	releaseall
	end

Route6_Interior2_Movement_Trigger1_1::
	walk_down
	step_end

Route6_Interior2_EventScript_Trigger1_4::
	applymovement LOCALID_PLAYER, Route6_Interior2_Movement_Trigger1_2
	waitmovement 0
	return

Route6_Interior2_EventScript_Trigger1_5::
	applymovement LOCALID_PLAYER, Route6_Interior2_Movement_Trigger1_3
	waitmovement 0
	return

Route6_Interior2_EventScript_Trigger1_6::
	applymovement LOCALID_PLAYER, Route6_Interior2_Movement_Trigger1_4
	waitmovement 0
	return

Route6_Interior2_Movement_Trigger1_2::
	walk_right
	walk_right
	step_end

Route6_Interior2_Movement_Trigger1_3::
	walk_right
	step_end

Route6_Interior2_Movement_Trigger1_4::
	walk_in_place_right
	step_end

Route6_Interior2_EventScript_Trigger2::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route6_Interior2_EventScript_Trigger1_1

Route6_Interior2_EventScript_Trigger3::
	lockall
	setvar VAR_TEMP_1, 2
	goto Route6_Interior2_EventScript_Trigger1_1
