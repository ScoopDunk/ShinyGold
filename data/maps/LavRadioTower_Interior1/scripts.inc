LavRadioTower_Interior1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

LavRadioTower_Interior1_EventScript_WorkerM::
	msgbox LavRadioTower_Interior1_Text_WorkerM, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_Gentleman::
	call_if_set 0x11E2, LavRadioTower_Interior1_EventScript_Gentleman_1
	call_if_set 0x1185, LavRadioTower_Interior1_EventScript_Gentleman_2
	msgbox LavRadioTower_Interior1_Text_Gentleman_1, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_Gentleman_1::
	msgbox LavRadioTower_Interior1_Text_Gentleman_2, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_Gentleman_2::
	msgbox LavRadioTower_Interior1_Text_Gentleman_3, MSGBOX_NPC
	checkitem ITEM_TEACHY_TV
	call_if_eq VAR_RESULT, 1, LavRadioTower_Interior1_EventScript_Gentleman_3
	msgbox LavRadioTower_Interior1_Text_Gentleman_4, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_Gentleman_3::
	giveitem ITEM_POKE_FLUTE
	msgbox LavRadioTower_Interior1_Text_Gentleman_2, MSGBOX_NPC
	setflag 0x11E2
	release
	end

LavRadioTower_Interior1_EventScript_Man::
	call_if_set 0x11E2, LavRadioTower_Interior1_EventScript_Man_1
	msgbox LavRadioTower_Interior1_Text_Man_1, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_Man_1::
	msgbox LavRadioTower_Interior1_Text_Man_2, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_CableClubReceptionist::
	msgbox LavRadioTower_Interior1_Text_CableClubReceptionist, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_Policeman::
	msgbox LavRadioTower_Interior1_Text_Policeman, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_Trigger1::
	call_if_set 0x11E0, LavRadioTower_Interior1_EventScript_Trigger1_1
	playbgm MUS_VS_TRAINER, 51
	applymovement LOCALID_PLAYER, LavRadioTower_Interior1_Movement_Trigger1_1
	delay 32
	call LavRadioTower_Interior1_EventScript_Trigger1_2
	end

LavRadioTower_Interior1_EventScript_Trigger1_1::
	release
	end

LavRadioTower_Interior1_EventScript_Trigger1_2::
	msgbox LavRadioTower_Interior1_Text_Trigger1_1, MSGBOX_NPC
	msgbox LavRadioTower_Interior1_Text_Trigger1_2, MSGBOX_NPC
	msgbox LavRadioTower_Interior1_Text_Trigger1_3, MSGBOX_NPC
	msgbox LavRadioTower_Interior1_Text_Trigger1_4, MSGBOX_NPC
	waitse
	playmoncry SPECIES_MIGHTYENA, 0x2028
	nop
	delay 32
	msgbox LavRadioTower_Interior1_Text_Trigger1_5, MSGBOX_NPC
	playse SE_LAVARIDGE_FALL_WARP @ ShinyGold fix: was playbgm (the sound effect replaced the map music until the next map)
	waitse
	playmoncry SPECIES_MIGHTYENA, 0x2805
	waitse
	nop
	delay 48
	msgbox LavRadioTower_Interior1_Text_Trigger1_6, MSGBOX_NPC
	msgbox LavRadioTower_Interior1_Text_Trigger1_7, MSGBOX_NPC
	applymovement LOCALID_PLAYER, LavRadioTower_Interior1_Movement_Trigger1_2
	delay 64
	msgbox LavRadioTower_Interior1_Text_Trigger1_8, MSGBOX_NPC
	msgbox LavRadioTower_Interior1_Text_Trigger1_9, MSGBOX_NPC
	msgbox LavRadioTower_Interior1_Text_Trigger1_10, MSGBOX_NPC
	msgbox LavRadioTower_Interior1_Text_Trigger1_11, MSGBOX_NPC
	applymovement 3, LavRadioTower_Interior1_Movement_Trigger1_3
	applymovement 4, LavRadioTower_Interior1_Movement_Trigger1_4
	delay 16
	msgbox LavRadioTower_Interior1_Text_Trigger1_12, MSGBOX_NPC
	applymovement 3, LavRadioTower_Interior1_Movement_Trigger1_5
	applymovement 4, LavRadioTower_Interior1_Movement_Trigger1_5
	applymovement LOCALID_PLAYER, LavRadioTower_Interior1_Movement_Trigger1_5
	delay 1
	applymovement 5, LavRadioTower_Interior1_Movement_Trigger1_6
	delay 96
	msgbox LavRadioTower_Interior1_Text_Trigger1_13, MSGBOX_NPC
	msgbox LavRadioTower_Interior1_Text_Trigger1_14, MSGBOX_NPC
	applymovement 3, LavRadioTower_Interior1_Movement_Trigger1_7
	delay 16
	applymovement LOCALID_PLAYER, LavRadioTower_Interior1_Movement_Trigger1_8
	delay 64
	msgbox LavRadioTower_Interior1_Text_Trigger1_15, MSGBOX_NPC
	applymovement LOCALID_PLAYER, LavRadioTower_Interior1_Movement_Trigger1_9
	delay 1
	msgbox LavRadioTower_Interior1_Text_Trigger1_16, MSGBOX_NPC
	applymovement LOCALID_PLAYER, LavRadioTower_Interior1_Movement_Trigger1_10
	applymovement 5, LavRadioTower_Interior1_Movement_Trigger1_11
	delay 80
	fadescreen FADE_TO_BLACK
	msgbox LavRadioTower_Interior1_Text_Trigger1_17, MSGBOX_NPC
	playse SE_ORB @ ShinyGold fix: was playbgm (the sound effect replaced the map music until the next map)
	msgbox LavRadioTower_Interior1_Text_Trigger1_18, MSGBOX_NPC
	delay 48
	msgbox LavRadioTower_Interior1_Text_Trigger1_19, MSGBOX_NPC
	applymovement 3, LavRadioTower_Interior1_Movement_Trigger1_12
	applymovement 4, LavRadioTower_Interior1_Movement_Trigger1_12
	delay 48
	fadescreen FADE_FROM_BLACK
	fadedefaultbgm
	delay 32
	msgbox LavRadioTower_Interior1_Text_Trigger1_20, MSGBOX_NPC
	applymovement 5, LavRadioTower_Interior1_Movement_Trigger1_13
	delay 1
	msgbox LavRadioTower_Interior1_Text_Trigger1_21, MSGBOX_NPC
	applymovement 5, LavRadioTower_Interior1_Movement_Trigger1_14
	delay 80
	applymovement LOCALID_PLAYER, LavRadioTower_Interior1_Movement_Trigger1_15
	delay 64
	clearflag 0x11DD
	setflag 0x11DE
	setflag 0x11E0
	applymovement LOCALID_PLAYER, LavRadioTower_Interior1_Movement_Trigger1_16
	delay 48
	warp MAP_LAVENDER_TOWN, 6, 2, 0xE0D5
	.byte 0xE0 @ invalid opcode (script stops)

LavRadioTower_Interior1_Movement_Trigger1_1::
	walk_right
	walk_up
	step_end

LavRadioTower_Interior1_Movement_Trigger1_2::
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

LavRadioTower_Interior1_Movement_Trigger1_3::
	face_down_fast
	emote_question_mark
	step_end

LavRadioTower_Interior1_Movement_Trigger1_4::
	face_up
	emote_question_mark
	step_end

LavRadioTower_Interior1_Movement_Trigger1_5::
	face_down_fast
	step_end

LavRadioTower_Interior1_Movement_Trigger1_6::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

LavRadioTower_Interior1_Movement_Trigger1_7::
	walk_right
	walk_down
	step_end

LavRadioTower_Interior1_Movement_Trigger1_8::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	face_up
	step_end

LavRadioTower_Interior1_Movement_Trigger1_9::
	face_down_fast
	step_end

LavRadioTower_Interior1_Movement_Trigger1_10::
	face_up
	step_end

LavRadioTower_Interior1_Movement_Trigger1_11::
	walk_left
	walk_up
	walk_up
	walk_right
	face_up
	step_end

LavRadioTower_Interior1_Movement_Trigger1_12::
	set_invisible
	walk_fast_left
	walk_fast_left
	step_end

LavRadioTower_Interior1_Movement_Trigger1_13::
	face_down_fast
	step_end

LavRadioTower_Interior1_Movement_Trigger1_14::
	walk_right
	walk_down
	walk_down
	walk_down
	set_invisible
	walk_fast_down
	walk_fast_down
	step_end

LavRadioTower_Interior1_Movement_Trigger1_15::
	face_down_fast
	emote_question_mark
	step_end

LavRadioTower_Interior1_Movement_Trigger1_16::
	walk_right
	walk_down
	walk_down
	step_end

LavRadioTower_Interior1_EventScript_Trigger2::
	call_if_set 0x11E0, LavRadioTower_Interior1_EventScript_Trigger1_1
	playbgm MUS_VS_TRAINER, 51
	call LavRadioTower_Interior1_EventScript_Trigger1_2
	end

LavRadioTower_Interior1_EventScript_Trigger3::
	call_if_set 0x11E0, LavRadioTower_Interior1_EventScript_Trigger1_1
	playbgm MUS_VS_TRAINER, 51
	applymovement LOCALID_PLAYER, LavRadioTower_Interior1_Movement_Trigger3
	delay 32
	call LavRadioTower_Interior1_EventScript_Trigger1_2
	end

LavRadioTower_Interior1_Movement_Trigger3::
	walk_left
	walk_up
	step_end

LavRadioTower_Interior1_EventScript_Sign1::
	msgbox LavRadioTower_Interior1_Text_Sign1, MSGBOX_AUTOCLOSE
	end

LavRadioTower_Interior1_EventScript_Sign2::
	msgbox LavRadioTower_Interior1_Text_Sign2, MSGBOX_AUTOCLOSE
	end
