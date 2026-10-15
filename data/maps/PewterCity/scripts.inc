PewterCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PewterCity_OnFrame
	.byte 0

PewterCity_OnFrame::
	map_script_2 0x7043, 0, PewterCity_EventScript_FrameScene
	.2byte 0

PewterCity_EventScript_FrameScene::
	setflag 0x1362
	setvar 0x7043, 1
	call NewBarkTown_EventScript_FrameScene_1
	end

PewterCity_EventScript_Lass::
	msgbox PewterCity_Text_Lass, MSGBOX_NPC
	end

PewterCity_EventScript_OldMan1::
	checkitem ITEM_MYSTIC_TICKET
	goto_if_eq VAR_RESULT, 1, PewterCity_EventScript_OldMan1_1
	msgbox PewterCity_Text_OldMan1_1, MSGBOX_NPC
	giveitem ITEM_MYSTIC_TICKET
	release
	end

PewterCity_EventScript_OldMan1_1::
	msgbox PewterCity_Text_OldMan1_2, MSGBOX_NPC
	end

PewterCity_EventScript_LittleGirl::
	msgbox PewterCity_Text_LittleGirl, MSGBOX_NPC
	end

PewterCity_EventScript_Boy::
	lock
	faceplayer
	msgbox PewterCity_Text_Boy_1
	closemessage
	playbgm MUS_FOLLOW_ME, 0
	call_if_eq VAR_FACING, 4, PewterCity_EventScript_Boy_1
	msgbox PewterCity_Text_Boy_2
	closemessage
	applymovement 5, PewterCity_Movement_Boy_1
	waitmovement 0
	fadedefaultbgm
	removeobject 5
	clearflag 0x02E
	release
	end

PewterCity_EventScript_Boy_1::
	applymovement LOCALID_PLAYER, PewterCity_Movement_Boy_2
	applymovement 5, PewterCity_Movement_Boy_3
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_Boy_4
	applymovement 5, PewterCity_Movement_Boy_5
	waitmovement 0
	return

PewterCity_Movement_Boy_1::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PewterCity_Movement_Boy_2::
	delay_16
	delay_16
	delay_4
	walk_in_place_faster_down
	step_end

PewterCity_Movement_Boy_3::
	walk_down
	walk_left
	walk_in_place_faster_up
	walk_in_place_up
	step_end

PewterCity_Movement_Boy_4::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_Movement_Boy_5::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_EventScript_Scientist::
	lock
	faceplayer
	setvar VAR_TEMP_1, 0
	call PewterCity_EventScript_Scientist_1
	release
	end

PewterCity_EventScript_Scientist_1::
	textcolor NPC_TEXT_COLOR_MALE
	call_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_Scientist_2
	call_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_Scientist_2
	call_if_eq VAR_TEMP_1, 3, PewterCity_EventScript_Scientist_2
	waitse
	playse SE_PIN
	applymovement 7, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	msgbox PewterCity_Text_Scientist_1
	call_if_eq VAR_TEMP_1, 0, PewterCity_EventScript_Scientist_3
	call_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_Scientist_4
	call_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_Scientist_5
	call_if_eq VAR_TEMP_1, 3, PewterCity_EventScript_Scientist_6
	msgbox PewterCity_Text_Scientist_2
	textcolor NPC_TEXT_COLOR_NEUTRAL

NewBarkTown_Interior1_EventScript_Mom_8::
	playfanfare MUS_OBTAIN_KEY_ITEM
	message PewterCity_Text_Scientist_3
	waitmessage
	waitfanfare
	msgbox PewterCity_Text_Scientist_4
	special DisableMsgBoxWalkaway
	signmsg
	msgbox PewterCity_Text_Scientist_5
	normalmsg
	call EventScript_RestorePrevTextColor
	msgbox PewterCity_Text_Scientist_6
	closemessage
	call_if_eq VAR_TEMP_1, 0, PewterCity_EventScript_Scientist_7
	call_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_Scientist_8
	call_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_Scientist_9
	call_if_eq VAR_TEMP_1, 3, PewterCity_EventScript_Scientist_10
	delay 30
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox PewterCity_Text_Scientist_7
	closemessage
	removeobject 7
	setflag FLAG_SYS_B_DASH
	setvar 0x406C, 2
	return

PewterCity_EventScript_Scientist_2::
	applymovement 7, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PewterCity_EventScript_Scientist_3::
	closemessage
	delay 20
	return

PewterCity_EventScript_Scientist_4::
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PewterCity_EventScript_Scientist_5::
	closemessage
	applymovement 7, PewterCity_Movement_Scientist_1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PewterCity_EventScript_Scientist_6::
	closemessage
	applymovement 7, PewterCity_Movement_Scientist_2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PewterCity_EventScript_Scientist_7::
	applymovement 7, PewterCity_Movement_Scientist_3
	waitmovement 0
	return

PewterCity_EventScript_Scientist_8::
	applymovement 7, PewterCity_Movement_Scientist_4
	waitmovement 0
	return

PewterCity_EventScript_Scientist_9::
	applymovement 7, PewterCity_Movement_Scientist_5
	waitmovement 0
	return

PewterCity_EventScript_Scientist_10::
	applymovement 7, PewterCity_Movement_Scientist_6
	waitmovement 0
	return

PewterCity_Movement_Scientist_1::
	delay_4
	walk_down
	step_end

PewterCity_Movement_Scientist_2::
	delay_4
	walk_down
	walk_down
	step_end

PewterCity_Movement_Scientist_3::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PewterCity_Movement_Scientist_4::
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PewterCity_Movement_Scientist_5::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PewterCity_Movement_Scientist_6::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PewterCity_EventScript_Trigger1::
	lockall
	setvar VAR_TEMP_1, 0
	goto PewterCity_EventScript_Trigger1_1

PewterCity_EventScript_Trigger1_1::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox PewterCity_Text_Boy_1
	closemessage
	playbgm MUS_FOLLOW_ME, 0
	call_if_eq VAR_TEMP_1, 0, PewterCity_EventScript_Trigger1_2
	call_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_Trigger1_3
	call_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_Trigger1_4
	msgbox PewterCity_Text_Boy_2
	closemessage
	applymovement 5, PewterCity_Movement_Boy_1
	waitmovement 0
	fadedefaultbgm
	removeobject 5
	clearflag 0x02E
	releaseall
	end

PewterCity_EventScript_Trigger1_2::
	applymovement 5, PewterCity_Movement_Trigger1_1
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_Trigger1_2
	applymovement 5, PewterCity_Movement_Trigger1_3
	waitmovement 0
	return

PewterCity_EventScript_Trigger1_3::
	applymovement 5, PewterCity_Movement_Trigger1_4
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_Trigger1_5
	applymovement 5, PewterCity_Movement_Trigger1_6
	waitmovement 0
	return

PewterCity_EventScript_Trigger1_4::
	applymovement 5, PewterCity_Movement_Trigger1_7
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_Trigger1_8
	applymovement 5, PewterCity_Movement_Trigger1_9
	waitmovement 0
	return

PewterCity_Movement_Trigger1_1::
	walk_left
	walk_down
	walk_in_place_faster_right
	walk_in_place_right
	step_end

PewterCity_Movement_Trigger1_2::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_Movement_Trigger1_3::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_Movement_Trigger1_4::
	walk_down
	walk_in_place_down
	step_end

PewterCity_Movement_Trigger1_5::
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_Movement_Trigger1_6::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_Movement_Trigger1_7::
	walk_down
	walk_down
	walk_in_place_down
	step_end

PewterCity_Movement_Trigger1_8::
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_Movement_Trigger1_9::
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_EventScript_Trigger2::
	lockall
	setvar VAR_TEMP_1, 1
	goto PewterCity_EventScript_Trigger1_1

PewterCity_EventScript_Trigger3::
	lockall
	setvar VAR_TEMP_1, 2
	goto PewterCity_EventScript_Trigger1_1

PewterCity_EventScript_Trigger4::
	lockall
	setvar VAR_TEMP_1, 3
	goto PewterCity_EventScript_Trigger1_1

PewterCity_EventScript_Trigger5::
	lockall
	setvar VAR_TEMP_1, 1
	call PewterCity_EventScript_Scientist_1
	releaseall
	end

PewterCity_EventScript_Trigger6::
	lockall
	setvar VAR_TEMP_1, 2
	call PewterCity_EventScript_Scientist_1
	releaseall
	end

PewterCity_EventScript_Trigger7::
	lockall
	setvar VAR_TEMP_1, 3
	call PewterCity_EventScript_Scientist_1
	releaseall
	end

PewterCity_EventScript_Sign1::
	msgbox PewterCity_Text_Sign1, MSGBOX_SIGN
	end

PewterCity_EventScript_Sign2::
	msgbox PewterCity_Text_Sign2, MSGBOX_SIGN
	end

PewterCity_EventScript_Sign3::
	msgbox PewterCity_Text_Sign3, MSGBOX_SIGN
	end

PewterCity_EventScript_Sign4::
	msgbox PewterCity_Text_Sign4, MSGBOX_SIGN
	end

PewterCity_EventScript_Sign5::
	msgbox PewterCity_Text_Sign5, MSGBOX_SIGN
	end
