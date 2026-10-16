CeladonCity_Interior11_MapScripts::
	@ ShinyGold: 1 entry with invalid type(s) 0x6C dropped (inert: the engine skips them)
	.byte 0

CeladonCity_Interior11_EventScript_WorkerF::
	msgbox CeladonCity_Interior11_Text_WorkerF, MSGBOX_NPC
	end

CeladonCity_Interior11_EventScript_OldMan1::
	msgbox CeladonCity_Interior11_Text_OldMan1, MSGBOX_NPC
	end

CeladonCity_Interior11_EventScript_GymGuy::
	msgbox CeladonCity_Interior11_Text_GymGuy, MSGBOX_NPC
	end

CeladonCity_Interior11_EventScript_FatMan::
	call_if_set 0x11E6, CeladonCity_Interior11_EventScript_FatMan_1
	msgbox CeladonCity_Interior11_Text_FatMan_1, MSGBOX_NPC
	playfanfare MUS_SS_ANNE
	msgbox CeladonCity_Interior11_Text_FatMan_2, MSGBOX_AUTOCLOSE
	msgbox CeladonCity_Interior11_Text_FatMan_3, MSGBOX_NPC
	addcoins 18
	setflag 0x11E6
	release
	end

CeladonCity_Interior11_EventScript_FatMan_1::
	msgbox CeladonCity_Interior11_Text_FatMan_3, MSGBOX_NPC
	end

CeladonCity_Interior11_EventScript_Fisher2::
	msgbox CeladonCity_Interior11_Text_Fisher2, MSGBOX_NPC
	end

CeladonCity_Interior11_EventScript_BaldingMan::
	msgbox CeladonCity_Interior11_Text_BaldingMan, MSGBOX_NPC
	end

CeladonCity_Interior11_EventScript_CooltrainerF::
	msgbox CeladonCity_Interior11_Text_CooltrainerF, MSGBOX_NPC
	end

CeladonCity_Interior11_EventScript_Trigger1::
	call_if_set 0x11E7, CeladonCity_Interior11_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, CeladonCity_Interior11_Movement_Trigger1_1
	delay 16
	call CeladonCity_Interior11_EventScript_Trigger1_2
	end

CeladonCity_Interior11_EventScript_Trigger1_1::
	release
	end

CeladonCity_Interior11_EventScript_Trigger1_2::
	msgbox CeladonCity_Interior11_Text_Trigger1_1, MSGBOX_NPC
	applymovement 11, CeladonCity_Interior11_Movement_Trigger1_2
	delay 64
	msgbox CeladonCity_Interior11_Text_Trigger1_2, MSGBOX_NPC
	applymovement 11, CeladonCity_Interior11_Movement_Trigger1_3
	applymovement 3, CeladonCity_Interior11_Movement_Trigger1_4
	delay 1
	msgbox CeladonCity_Interior11_Text_Trigger1_3, MSGBOX_NPC
	msgbox CeladonCity_Interior11_Text_Trigger1_4, MSGBOX_NPC
	applymovement 11, CeladonCity_Interior11_Movement_Trigger1_5
	applymovement 3, CeladonCity_Interior11_Movement_Trigger1_5
	delay 1
	msgbox CeladonCity_Interior11_Text_Trigger1_5, MSGBOX_NPC
	delay 32
	msgbox CeladonCity_Interior11_Text_Trigger1_6, MSGBOX_NPC
	call SilphCo_Interior6_EventScript_Trigger1_1
	trainerbattle_earlyrival TRAINER_ROCKET_DUO_JESS_AND_JAMIE_3, 0, CeladonCity_Interior11_Text_Trigger1Defeat, CeladonCity_Interior11_Text_Trigger1Victory
	setflag 0x11E7
	call SilphCo_Interior6_EventScript_Trigger1_2
	msgbox CeladonCity_Interior11_Text_Trigger1_7, MSGBOX_NPC
	warp MAP_CELADON_CITY_INTERIOR11, 1, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior11_Movement_Trigger1_1::
	walk_right
	face_up
	step_end

CeladonCity_Interior11_Movement_Trigger1_2::
	emote_question_mark
	step_end

CeladonCity_Interior11_Movement_Trigger1_3::
	face_left
	step_end

CeladonCity_Interior11_Movement_Trigger1_4::
	face_right
	step_end

CeladonCity_Interior11_Movement_Trigger1_5::
	face_down_fast
	step_end

CeladonCity_Interior11_EventScript_Trigger2::
	call_if_set 0x11E7, CeladonCity_Interior11_EventScript_Trigger1_1
	call CeladonCity_Interior11_EventScript_Trigger1_2
	end

CeladonCity_Interior11_EventScript_Trigger3::
	call_if_set 0x11E7, CeladonCity_Interior11_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, CeladonCity_Interior11_Movement_Trigger3
	delay 16
	call CeladonCity_Interior11_EventScript_Trigger1_2
	end

CeladonCity_Interior11_Movement_Trigger3::
	walk_left
	face_up
	step_end

CeladonCity_Interior11_EventScript_Trigger4::
	call_if_set 0x11E7, CeladonCity_Interior11_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, CeladonCity_Interior11_Movement_Trigger4
	delay 32
	call CeladonCity_Interior11_EventScript_Trigger1_2
	end

CeladonCity_Interior11_Movement_Trigger4::
	walk_left
	walk_left
	face_up
	step_end

CeladonCity_Interior11_EventScript_Sign15::
	lockall
	setvar VAR_0x8004, 14
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

CeladonCity_Interior11_EventScript_Sign23::
	msgbox CeladonCity_Interior11_Text_Sign23, MSGBOX_AUTOCLOSE
	end
