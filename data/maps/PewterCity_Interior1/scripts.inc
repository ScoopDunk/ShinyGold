PewterCity_Interior1_MapScripts::
	.byte 0

PewterCity_Interior1_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_eq VAR_FACING, 3, PewterCity_Interior1_EventScript_WorkerM_1
	goto_if_eq VAR_FACING, 1, PewterCity_Interior1_EventScript_WorkerM_1
	goto_if_eq VAR_FACING, 2, PewterCity_Interior1_EventScript_WorkerM_1
	msgbox PewterCity_Interior1_Text_WorkerM_1
	release
	end

PewterCity_Interior1_EventScript_WorkerM_1::
	msgbox PewterCity_Interior1_Text_WorkerM_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, PewterCity_Interior1_EventScript_WorkerM_2
	goto_if_eq VAR_RESULT, 0, PewterCity_Interior1_EventScript_WorkerM_3
	end

PewterCity_Interior1_EventScript_WorkerM_2::
	msgbox PewterCity_Interior1_Text_WorkerM_3
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_Interior1_EventScript_WorkerM_3::
	msgbox PewterCity_Interior1_Text_WorkerM_4
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_Interior1_EventScript_OldMan1::
	msgbox PewterCity_Interior1_Text_OldMan1, MSGBOX_NPC
	end

PewterCity_Interior1_EventScript_Scientist::
	lock
	faceplayer
	goto_if_set 0x25E, PewterCity_Interior1_EventScript_Scientist_1
	msgbox PewterCity_Interior1_Text_Scientist_1
	checkitemspace ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, 0, PewterCity_Interior1_EventScript_Scientist_2
	setflag 0x25E
	removeobject 4
	giveitem_msg PewterCity_Interior1_Text_Scientist_2, ITEM_OLD_AMBER, 1, 0x13E
	release
	end

PewterCity_Interior1_EventScript_Scientist_1::
	msgbox PewterCity_Interior1_Text_Scientist_3
	release
	end

PewterCity_Interior1_EventScript_Scientist_2::
	msgbox PewterCity_Interior1_Text_Scientist_4
	release
	end

PewterCity_Interior1_EventScript_OldAmber::
	msgbox PewterCity_Interior1_Text_OldAmber, MSGBOX_NPC
	end

PewterCity_Interior1_EventScript_Scientist2::
	msgbox PewterCity_Interior1_Text_Scientist2, MSGBOX_NPC
	end

PewterCity_Interior1_EventScript_Trigger1::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Interior1_EventScript_Trigger1_1

PewterCity_Interior1_EventScript_Trigger1_1::
	textcolor NPC_TEXT_COLOR_MALE
	showmoneybox 0, 0
	msgbox PewterCity_Interior1_Text_Trigger1_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, PewterCity_Interior1_EventScript_Trigger1_2
	msgbox PewterCity_Interior1_Text_Trigger1_2
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, PewterCity_Interior1_Movement_Trigger1_1
	waitmovement 0
	releaseall
	end

PewterCity_Interior1_EventScript_Trigger1_2::
	checkmoney 50
	goto_if_eq VAR_RESULT, 0, PewterCity_Interior1_EventScript_Trigger1_3
	closemessage
	call_if_eq VAR_TEMP_1, 0, PewterCity_Interior1_EventScript_Trigger1_4
	call_if_eq VAR_TEMP_1, 1, PewterCity_Interior1_EventScript_Trigger1_5
	call_if_eq VAR_TEMP_1, 2, PewterCity_Interior1_EventScript_Trigger1_6
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	waitse
	msgbox PewterCity_Interior1_Text_Trigger1_3
	setvar 0x4061, 1
	hidemoneybox
	releaseall
	end

PewterCity_Interior1_EventScript_Trigger1_3::
	msgbox PewterCity_Interior1_Text_Trigger1_4
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, PewterCity_Interior1_Movement_Trigger1_1
	waitmovement 0
	releaseall
	end

PewterCity_Interior1_EventScript_Trigger1_4::
	applymovement LOCALID_PLAYER, PewterCity_Interior1_Movement_Trigger1_2
	waitmovement 0
	return

PewterCity_Interior1_EventScript_Trigger1_5::
	applymovement LOCALID_PLAYER, PewterCity_Interior1_Movement_Trigger1_3
	waitmovement 0
	return

PewterCity_Interior1_EventScript_Trigger1_6::
	applymovement LOCALID_PLAYER, PewterCity_Interior1_Movement_Trigger1_4
	waitmovement 0
	return

PewterCity_Interior1_Movement_Trigger1_1::
	walk_down
	step_end

PewterCity_Interior1_Movement_Trigger1_2::
	walk_right
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Interior1_Movement_Trigger1_3::
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Interior1_Movement_Trigger1_4::
	delay_8
	walk_in_place_right
	step_end

PewterCity_Interior1_EventScript_Trigger2::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Interior1_EventScript_Trigger1_1

PewterCity_Interior1_EventScript_Trigger3::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Interior1_EventScript_Trigger1_1

PewterCity_Interior1_EventScript_Sign1::
	lockall
	setvar VAR_0x8004, 142
	setvar VAR_0x8005, 10
	setvar VAR_0x8006, 3
	special OpenMuseumFossilPic
	msgbox PewterCity_Interior1_Text_Sign1
	special CloseMuseumFossilPic
	releaseall
	end

PewterCity_Interior1_EventScript_Sign2::
	lockall
	setvar VAR_0x8004, 141
	setvar VAR_0x8005, 10
	setvar VAR_0x8006, 3
	special OpenMuseumFossilPic
	msgbox PewterCity_Interior1_Text_Sign2
	special CloseMuseumFossilPic
	releaseall
	end
