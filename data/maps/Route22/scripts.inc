Route22_MapScripts::
	.byte 0

Route22_EventScript_Trigger1::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route22_EventScript_Trigger1_1

Route22_EventScript_Trigger1_1::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_ENCOUNTER_RIVAL, 0
	addobject 1
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_Trigger1_2
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_Trigger1_2
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_Trigger1_3
	delay 6
	msgbox Route22_Text_Trigger1_1
	call_if_eq VAR_STARTER_MON, 2, Route22_EventScript_Trigger1_4
	call_if_eq VAR_STARTER_MON, 1, Route22_EventScript_Trigger1_5
	call_if_eq VAR_STARTER_MON, 0, Route22_EventScript_Trigger1_6
	msgbox Route22_Text_Trigger1_2
	closemessage
	delay 10
	playbgm MUS_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_Trigger1_7
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_Trigger1_7
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_Trigger1_8
	fadedefaultbgm
	removeobject 1
	setvar 0x4054, 2
	releaseall
	end

Route22_EventScript_Trigger1_2::
	applymovement 1, Route22_Movement_Trigger1_1
	waitmovement 0
	return

Route22_EventScript_Trigger1_3::
	applymovement 1, Route22_Movement_Trigger1_2
	applymovement LOCALID_PLAYER, Route22_Movement_Trigger1_3
	waitmovement 0
	return

Route22_EventScript_Trigger1_4::
	trainerbattle_earlyrival TRAINER_RIVAL_SILVER_7, 0, Route22_Text_Trigger1Defeat, Route22_Text_Trigger1Victory
	return

Route22_EventScript_Trigger1_5::
	trainerbattle_earlyrival TRAINER_LEADER_CHUCK, 0, Route22_Text_Trigger1Defeat, Route22_Text_Trigger1Victory
	return

Route22_EventScript_Trigger1_6::
	trainerbattle_earlyrival TRAINER_LEADER_JASMINE, 0, Route22_Text_Trigger1Defeat, Route22_Text_Trigger1Victory
	return

Route22_EventScript_Trigger1_7::
	applymovement 1, Route22_Movement_Trigger1_4
	waitmovement 0
	return

Route22_EventScript_Trigger1_8::
	applymovement 1, Route22_Movement_Trigger1_5
	waitmovement 0
	return

Route22_Movement_Trigger1_1::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route22_Movement_Trigger1_2::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

Route22_Movement_Trigger1_3::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_up
	step_end

Route22_Movement_Trigger1_4::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route22_Movement_Trigger1_5::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route22_EventScript_Trigger2::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm 1, 25, 5
	goto Route22_EventScript_Trigger1_1

Route22_EventScript_Trigger3::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm 1, 25, 5
	goto Route22_EventScript_Trigger1_1

Route22_EventScript_Trigger4::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route22_EventScript_Trigger4_1

Route22_EventScript_Trigger4_1::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_ENCOUNTER_RIVAL, 0
	addobject 1
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_Trigger4_2
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_Trigger4_2
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_Trigger4_3
	msgbox Route22_Text_Trigger4_1
	setvar VAR_LAST_TALKED, 1
	call_if_eq VAR_STARTER_MON, 2, Route22_EventScript_Trigger4_4
	call_if_eq VAR_STARTER_MON, 1, Route22_EventScript_Trigger4_5
	call_if_eq VAR_STARTER_MON, 0, Route22_EventScript_Trigger4_6
	msgbox Route22_Text_Trigger4_2
	closemessage
	delay 10
	playbgm MUS_RIVAL_EXIT, 0
	applymovement 1, Route22_Movement_Trigger4
	waitmovement 0
	fadedefaultbgm
	removeobject 1
	setvar 0x4054, 4
	releaseall
	end

Route22_EventScript_Trigger4_2::
	applymovement 1, Route22_Movement_Trigger1_1
	waitmovement 0
	return

Route22_EventScript_Trigger4_3::
	applymovement 1, Route22_Movement_Trigger1_2
	applymovement LOCALID_PLAYER, Route22_Movement_Trigger1_3
	waitmovement 0
	return

Route22_EventScript_Trigger4_4::
	trainerbattle_no_intro TRAINER_RIVAL_TERRY_10, Route22_Text_Trigger4Defeat
	return

Route22_EventScript_Trigger4_5::
	trainerbattle_no_intro TRAINER_RIVAL_TERRY_11, Route22_Text_Trigger4Defeat
	return

Route22_EventScript_Trigger4_6::
	trainerbattle_no_intro TRAINER_RIVAL_TERRY_12, Route22_Text_Trigger4Defeat
	return

Route22_Movement_Trigger4::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route22_EventScript_Trigger5::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm 1, 25, 5
	goto Route22_EventScript_Trigger4_1

Route22_EventScript_Trigger6::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm 1, 25, 5
	goto Route22_EventScript_Trigger4_1

Route22_EventScript_Sign::
	msgbox Route22_Text_Sign, MSGBOX_SIGN
	end
