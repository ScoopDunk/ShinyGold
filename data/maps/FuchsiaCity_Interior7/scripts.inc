FuchsiaCity_Interior7_MapScripts::
	.byte 0

FuchsiaCity_Interior7_EventScript_CooltrainerF::
	applymovement 1, FuchsiaCity_Interior7_Movement_CooltrainerF_1
	delay 32
	setobjectxy 13, 14, 8
	setobjectxy 1, 5, 23
	applymovement 13, FuchsiaCity_Interior7_Movement_CooltrainerF_2
	delay 1
	msgbox FuchsiaCity_Interior7_Text_CooltrainerF, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_CAMPER_BARRY, 0, FuchsiaCity_Interior7_Text_CooltrainerFDefeat, FuchsiaCity_Interior7_Text_CooltrainerFVictory
	setflag 0x11FA
	release
	end

FuchsiaCity_Interior7_Movement_CooltrainerF_1::
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

FuchsiaCity_Interior7_Movement_CooltrainerF_2::
	face_player
	step_end

FuchsiaCity_Interior7_EventScript_CooltrainerF2::
	applymovement 2, FuchsiaCity_Interior7_Movement_CooltrainerF_1
	delay 32
	setobjectxy 9, 8, 4
	setobjectxy 2, 5, 23
	applymovement 9, FuchsiaCity_Interior7_Movement_CooltrainerF_2
	delay 1
	msgbox FuchsiaCity_Interior7_Text_CooltrainerF2, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_PICNICKER_CINDY, 0, FuchsiaCity_Interior7_Text_CooltrainerF2Defeat, FuchsiaCity_Interior7_Text_CooltrainerFVictory
	setflag 0x11F9
	release
	end

FuchsiaCity_Interior7_EventScript_Koga::
	call_if_set 0x1200, FuchsiaCity_Interior7_EventScript_Koga_1
	call_if_set 0x11F7, FuchsiaCity_Interior7_EventScript_Koga_2
	msgbox FuchsiaCity_Interior7_Text_Koga_1, MSGBOX_NPC
	end

FuchsiaCity_Interior7_EventScript_Koga_1::
	msgbox FuchsiaCity_Interior7_Text_Koga_2, MSGBOX_NPC
	end

FuchsiaCity_Interior7_EventScript_Koga_2::
	msgbox FuchsiaCity_Interior7_Text_Koga_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, FuchsiaCity_Interior7_EventScript_Koga_3
	msgbox FuchsiaCity_Interior7_Text_Koga_4, MSGBOX_NPC
	end

FuchsiaCity_Interior7_EventScript_Koga_3::
	msgbox FuchsiaCity_Interior7_Text_Koga_5, MSGBOX_NPC
	call LavenderTown_EventScript_Trigger6_2
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_KOGA, 0, FuchsiaCity_Interior7_Text_KogaDefeat, FuchsiaCity_Interior7_Text_KogaVictory
	setflag 0x1200
	call LavenderTown_EventScript_Trigger6_3
	msgbox FuchsiaCity_Interior7_Text_Koga_6, MSGBOX_NPC
	giveitem ITEM_CHOICE_BAND
	msgbox FuchsiaCity_Interior7_Text_Koga_7, MSGBOX_NPC
	end

FuchsiaCity_Interior7_EventScript_Lass::
	msgbox FuchsiaCity_Interior7_Text_Lass, MSGBOX_NPC
	end

FuchsiaCity_Interior7_EventScript_CooltrainerF3::
	applymovement 5, FuchsiaCity_Interior7_Movement_CooltrainerF_1
	delay 32
	setobjectxy 15, 12, 2
	setobjectxy 5, 5, 23
	applymovement 15, FuchsiaCity_Interior7_Movement_CooltrainerF_2
	delay 1
	msgbox FuchsiaCity_Interior7_Text_CooltrainerF3, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_LASS_ALICE, 0, FuchsiaCity_Interior7_Text_CooltrainerF3Defeat, FuchsiaCity_Interior7_Text_CooltrainerFVictory
	setflag 0x11FB
	release
	end

FuchsiaCity_Interior7_EventScript_CooltrainerF4::
	applymovement 6, FuchsiaCity_Interior7_Movement_CooltrainerF_1
	delay 32
	setobjectxy 4, 8, 12
	setobjectxy 6, 5, 23
	applymovement 4, FuchsiaCity_Interior7_Movement_CooltrainerF_2
	delay 1
	msgbox FuchsiaCity_Interior7_Text_CooltrainerF4, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_LASS_LINDA, 0, FuchsiaCity_Interior7_Text_CooltrainerF4Defeat, FuchsiaCity_Interior7_Text_CooltrainerFVictory
	setflag 0x11F8
	release
	end

FuchsiaCity_Interior7_EventScript_CooltrainerF5::
	applymovement 7, FuchsiaCity_Interior7_Movement_CooltrainerF_1
	delay 32
	applymovement 6, FuchsiaCity_Interior7_Movement_CooltrainerF_2
	delay 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	special UpdatePickStateFromSpecialVar8005
	call Unused_CeruleanCity_Gym_EventScript_Misty_1
	trainerbattle_single TRAINER_LEADER_JANINE_2, FuchsiaCity_Interior7_Text_CooltrainerF5Intro, FuchsiaCity_Interior7_Text_CooltrainerF5Defeat, FuchsiaCity_Interior7_EventScript_CooltrainerF5Continue, NO_MUSIC
	msgbox FuchsiaCity_Interior7_Text_CooltrainerF5_1, MSGBOX_NPC
	end

FuchsiaCity_Interior7_EventScript_CooltrainerF5Continue::
	setflag 0x11F7
	call LavenderTown_EventScript_Trigger6_3
	msgbox FuchsiaCity_Interior7_Text_CooltrainerF5_2, MSGBOX_NPC
	giveitem ITEM_TM06
	msgbox FuchsiaCity_Interior7_Text_CooltrainerF5_1, MSGBOX_NPC
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
