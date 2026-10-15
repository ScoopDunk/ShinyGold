VioletCity_Interior2_MapScripts::
	.byte 0

VioletCity_Interior2_EventScript_FatMan::
	applymovement 1, VioletCity_Interior2_Movement_FatMan
	delay 32
	msgbox VioletCity_Interior2_Text_FatMan_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, VioletCity_Interior2_EventScript_FatMan_1
	msgbox VioletCity_Interior2_Text_FatMan_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, VioletCity_Interior2_EventScript_FatMan_2
	msgbox VioletCity_Interior2_Text_FatMan_3, MSGBOX_NPC
	end

VioletCity_Interior2_EventScript_FatMan_1::
	msgbox VioletCity_Interior2_Text_FatMan_4, MSGBOX_YESNO
	call_if_lt VAR_RESULT, 1, VioletCity_Interior2_EventScript_FatMan_3
	msgbox VioletCity_Interior2_Text_FatMan_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, VioletCity_Interior2_EventScript_FatMan_2
	msgbox VioletCity_Interior2_Text_FatMan_3, MSGBOX_NPC
	end

VioletCity_Interior2_EventScript_FatMan_2::
	msgbox VioletCity_Interior2_Text_FatMan_5, MSGBOX_NPC
	end

VioletCity_Interior2_Movement_FatMan::
	face_up
	face_left
	face_down_fast
	face_right
	face_up
	face_left
	face_down_fast
	face_right
	face_up
	face_left
	face_down_fast
	face_right
	face_player
	step_end

VioletCity_Interior2_EventScript_FatMan_3::
	msgbox VioletCity_Interior2_Text_FatMan_3, MSGBOX_NPC
	end

VioletCity_Interior2_EventScript_Youngster::
	lock
	faceplayer
	msgbox VioletCity_Interior2_Text_Youngster
	closemessage
	applymovement 2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

VioletCity_Interior2_EventScript_Boy::
	lock
	faceplayer
	msgbox VioletCity_Interior2_Text_Boy
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VioletCity_Interior2_EventScript_GbaKid::
	msgbox VioletCity_Interior2_Text_GbaKid, MSGBOX_NPC
	end

VioletCity_Interior2_EventScript_GbaKid2::
	msgbox VioletCity_Interior2_Text_GbaKid2, MSGBOX_NPC
	end

VioletCity_Interior2_EventScript_Sign1::
	lockall
	msgbox VioletCity_Interior2_Text_Sign1_1
	msgbox VioletCity_Interior2_Text_Sign1_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, VioletCity_Interior2_EventScript_Sign1_1
	msgbox VioletCity_Interior2_Text_Sign1_3
	msgbox VioletCity_Interior2_Text_Sign1_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, VioletCity_Interior2_EventScript_Sign1_1
	msgbox VioletCity_Interior2_Text_Sign1_4
	msgbox VioletCity_Interior2_Text_Sign1_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, VioletCity_Interior2_EventScript_Sign1_1
	msgbox VioletCity_Interior2_Text_Sign1_5
	applymovement 2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox VioletCity_Interior2_Text_Sign1_6
	releaseall
	end

VioletCity_Interior2_EventScript_Sign1_1::
	releaseall
	end

VioletCity_Interior2_EventScript_Sign2::
	lockall
	msgbox VioletCity_Interior2_Text_Sign2_1
	goto VioletCity_Interior2_EventScript_Sign2_1

VioletCity_Interior2_EventScript_Sign2_1::
	message VioletCity_Interior2_Text_Sign2_2
	waitmessage
	multichoicegrid 7, 1, MULTICHOICE_TRAINER_SCHOOL_WHITEBOARD, 3, 0
	switch VAR_RESULT
	case 0, VioletCity_Interior2_EventScript_Sign2_2
	case 1, VioletCity_Interior2_EventScript_Sign2_3
	case 2, VioletCity_Interior2_EventScript_Sign2_4
	case 3, VioletCity_Interior2_EventScript_Sign2_5
	case 4, VioletCity_Interior2_EventScript_Sign2_6
	case 5, VioletCity_Interior2_EventScript_Sign2_7
	case 127, VioletCity_Interior2_EventScript_Sign2_7
	end

VioletCity_Interior2_EventScript_Sign2_2::
	msgbox VioletCity_Interior2_Text_Sign2_3
	goto VioletCity_Interior2_EventScript_Sign2_1

VioletCity_Interior2_EventScript_Sign2_3::
	msgbox VioletCity_Interior2_Text_Sign2_4
	goto VioletCity_Interior2_EventScript_Sign2_1

VioletCity_Interior2_EventScript_Sign2_4::
	msgbox VioletCity_Interior2_Text_Sign2_5
	goto VioletCity_Interior2_EventScript_Sign2_1

VioletCity_Interior2_EventScript_Sign2_5::
	msgbox VioletCity_Interior2_Text_Sign2_6
	goto VioletCity_Interior2_EventScript_Sign2_1

VioletCity_Interior2_EventScript_Sign2_6::
	msgbox VioletCity_Interior2_Text_Sign2_7
	goto VioletCity_Interior2_EventScript_Sign2_1

VioletCity_Interior2_EventScript_Sign2_7::
	releaseall
	end
