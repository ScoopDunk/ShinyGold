FuchsiaCity_Interior7_MapScripts::
	.byte 0

FuchsiaCity_Interior7_EventScript_CamperBarry::
	applymovement 1, FuchsiaCity_Interior7_Movement_CamperBarry_1
	delay 32
	setobjectxy 12, 14, 8
	setobjectxy 1, 5, 23
	applymovement 12, FuchsiaCity_Interior7_Movement_CamperBarry_2
	delay 1
	msgbox FuchsiaCity_Interior7_Text_CamperBarry, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_CAMPER_BARRY, 0, FuchsiaCity_Interior7_Text_CamperBarryDefeat, FuchsiaCity_Interior7_Text_CamperBarryVictory
	setflag 0x11FA
	release
	end

FuchsiaCity_Interior7_Movement_CamperBarry_1::
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
	face_up
	face_left
	face_down_fast
	face_right
	face_down_fast
	step_end

FuchsiaCity_Interior7_Movement_CamperBarry_2::
	face_player
	step_end

FuchsiaCity_Interior7_EventScript_PicnickerCindy::
	applymovement 2, FuchsiaCity_Interior7_Movement_CamperBarry_1
	delay 32
	setobjectxy 8, 8, 4
	setobjectxy 2, 5, 23
	applymovement 8, FuchsiaCity_Interior7_Movement_CamperBarry_2
	delay 1
	msgbox FuchsiaCity_Interior7_Text_PicnickerCindy, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_PICNICKER_CINDY, 0, FuchsiaCity_Interior7_Text_PicnickerCindyDefeat, FuchsiaCity_Interior7_Text_CamperBarryVictory
	setflag 0x11F9
	release
	end

FuchsiaCity_Interior7_EventScript_Lass::
	msgbox FuchsiaCity_Interior7_Text_Lass, MSGBOX_NPC
	end

FuchsiaCity_Interior7_EventScript_LassAlice::
	applymovement 4, FuchsiaCity_Interior7_Movement_CamperBarry_1
	delay 32
	setobjectxy 14, 12, 2
	setobjectxy 4, 5, 23
	applymovement 14, FuchsiaCity_Interior7_Movement_CamperBarry_2
	delay 1
	msgbox FuchsiaCity_Interior7_Text_LassAlice, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_LASS_ALICE, 0, FuchsiaCity_Interior7_Text_LassAliceDefeat, FuchsiaCity_Interior7_Text_CamperBarryVictory
	setflag 0x11FB
	release
	end

FuchsiaCity_Interior7_EventScript_LassLinda::
	applymovement 5, FuchsiaCity_Interior7_Movement_CamperBarry_1
	delay 32
	setobjectxy 3, 8, 12
	setobjectxy 5, 5, 23
	applymovement 3, FuchsiaCity_Interior7_Movement_CamperBarry_2
	delay 1
	msgbox FuchsiaCity_Interior7_Text_LassLinda, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_LASS_LINDA, 0, FuchsiaCity_Interior7_Text_LassLindaDefeat, FuchsiaCity_Interior7_Text_CamperBarryVictory
	setflag 0x11F8
	release
	end

FuchsiaCity_Interior7_EventScript_LeaderJanine2::
	applymovement 6, FuchsiaCity_Interior7_Movement_CamperBarry_1
	delay 32
	applymovement 5, FuchsiaCity_Interior7_Movement_CamperBarry_2
	delay 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	special UpdatePickStateFromSpecialVar8005
	call Unused_CeruleanCity_Gym_EventScript_LeaderMisty_1
	trainerbattle_single TRAINER_LEADER_JANINE_2, FuchsiaCity_Interior7_Text_LeaderJanine2Intro, FuchsiaCity_Interior7_Text_LeaderJanine2Defeat, FuchsiaCity_Interior7_EventScript_LeaderJanine2Continue, NO_MUSIC
	msgbox FuchsiaCity_Interior7_Text_LeaderJanine2_1, MSGBOX_NPC
	end

FuchsiaCity_Interior7_EventScript_LeaderJanine2Continue::
	setflag 0x11F7
	call LavenderTown_EventScript_Trigger6_3
	msgbox FuchsiaCity_Interior7_Text_LeaderJanine2_2, MSGBOX_NPC
	giveitem ITEM_TM06
	msgbox FuchsiaCity_Interior7_Text_LeaderJanine2_1, MSGBOX_NPC
	end

FuchsiaCity_Interior7_EventScript_GymGuy::
	call_if_set 0x11F7, FuchsiaCity_Interior7_EventScript_GymGuy_1
	msgbox FuchsiaCity_Interior7_Text_GymGuy_1, MSGBOX_NPC
	end

FuchsiaCity_Interior7_EventScript_GymGuy_1::
	msgbox FuchsiaCity_Interior7_Text_GymGuy_2, MSGBOX_NPC
	end

FuchsiaCity_Interior7_EventScript_Picnicker::
	msgbox FuchsiaCity_Interior7_Text_Picnicker, MSGBOX_NPC
	end

FuchsiaCity_Interior7_EventScript_Camper::
	msgbox FuchsiaCity_Interior7_Text_Camper, MSGBOX_NPC
	end

FuchsiaCity_Interior7_EventScript_Lass3::
	msgbox FuchsiaCity_Interior7_Text_Lass3, MSGBOX_NPC
	end

FuchsiaCity_Interior7_EventScript_Trigger1::
	call_if_unset 0x11F8, FuchsiaCity_Interior7_EventScript_Trigger1_1
	clearflag 0x11FC
	call FuchsiaCity_Interior7_EventScript_Trigger1_2
	end

FuchsiaCity_Interior7_EventScript_Trigger1_1::
	setflag 0x11FC
	call FuchsiaCity_Interior7_EventScript_Trigger1_2
	end

FuchsiaCity_Interior7_EventScript_Trigger1_2::
	call_if_unset 0x11F9, FuchsiaCity_Interior7_EventScript_Trigger1_3
	clearflag 0x11FD
	call FuchsiaCity_Interior7_EventScript_Trigger1_4
	end

FuchsiaCity_Interior7_EventScript_Trigger1_3::
	setflag 0x11FD
	call FuchsiaCity_Interior7_EventScript_Trigger1_4
	end

FuchsiaCity_Interior7_EventScript_Trigger1_4::
	call_if_unset 0x11FA, FuchsiaCity_Interior7_EventScript_Trigger1_5
	clearflag 0x11FE
	call FuchsiaCity_Interior7_EventScript_Trigger1_6
	end

FuchsiaCity_Interior7_EventScript_Trigger1_5::
	setflag 0x11FE
	call FuchsiaCity_Interior7_EventScript_Trigger1_6
	end

FuchsiaCity_Interior7_EventScript_Trigger1_6::
	call_if_unset 0x11FB, FuchsiaCity_Interior7_EventScript_Trigger1_7
	clearflag 0x11FF
	release
	end

FuchsiaCity_Interior7_EventScript_Trigger1_7::
	setflag 0x11FF
	release
	end

FuchsiaCity_Interior7_EventScript_Sign1::
	call_if_set 0x11F7, FuchsiaCity_Interior7_EventScript_Sign1_1
	msgbox FuchsiaCity_Interior7_Text_Sign1_1, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Interior7_EventScript_Sign1_1::
	msgbox FuchsiaCity_Interior7_Text_Sign1_2, MSGBOX_AUTOCLOSE
	end
