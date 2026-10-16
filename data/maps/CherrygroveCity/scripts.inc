CherrygroveCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CherrygroveCity_OnFrame
	.byte 0

CherrygroveCity_OnFrame::
	map_script_2 0x7021, 0, CherrygroveCity_EventScript_FrameScene
	.2byte 0

CherrygroveCity_EventScript_FrameScene::
	setvar 0x7021, 1
	call CherrygroveCity_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

CherrygroveCity_EventScript_FrameScene_1::
	setvar 0x7010, 0
	setvar 0x7011, 0
	setvar 0x7012, 0
	setvar 0x7013, 0
	setvar 0x7014, 0
	setvar 0x7015, 0
	setvar 0x7016, 0
	setvar 0x7017, 0
	setvar 0x7018, 0
	setvar 0x7019, 0
	setvar 0x701A, 0
	setvar 0x701B, 0
	setvar 0x701C, 0
	setvar 0x701D, 0
	setvar 0x701E, 0
	setvar 0x701F, 0
	setvar 0x7020, 0
	setvar 0x7022, 0
	setvar 0x7023, 0
	setvar 0x7024, 0
	setvar 0x7025, 0
	setvar 0x7026, 0
	setvar 0x7027, 0
	setvar 0x7028, 0
	return

CherrygroveCity_EventScript_OldMan1::
	msgbox CherrygroveCity_Text_OldMan1_1, MSGBOX_NPC
	msgbox CherrygroveCity_Text_OldMan1_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, CherrygroveCity_EventScript_OldMan1_1
	msgbox CherrygroveCity_Text_OldMan1_3, MSGBOX_NPC
	end

CherrygroveCity_EventScript_OldMan1_1::
	msgbox CherrygroveCity_Text_OldMan1_4, MSGBOX_NPC
	playbgm MUS_FOLLOW_ME, 51
	call_if_eq VAR_FACING, 3, CherrygroveCity_EventScript_OldMan1_2
	call_if_eq VAR_FACING, 2, CherrygroveCity_EventScript_OldMan1_3
	call CherrygroveCity_EventScript_OldMan1_4
	end

CherrygroveCity_EventScript_OldMan1_2::
	applymovement 1, CherrygroveCity_Movement_OldMan1_1
	applymovement LOCALID_PLAYER, CherrygroveCity_Movement_OldMan1_2
	delay 64
	call CherrygroveCity_EventScript_OldMan1_5
	end

CherrygroveCity_EventScript_OldMan1_3::
	applymovement 1, CherrygroveCity_Movement_OldMan1_3
	applymovement LOCALID_PLAYER, CherrygroveCity_Movement_OldMan1_4
	delay 64
	call CherrygroveCity_EventScript_OldMan1_5
	end

CherrygroveCity_EventScript_OldMan1_4::
	applymovement 1, CherrygroveCity_Movement_OldMan1_5
	applymovement LOCALID_PLAYER, CherrygroveCity_Movement_OldMan1_6
	delay 64
	call CherrygroveCity_EventScript_OldMan1_5
	end

CherrygroveCity_EventScript_OldMan1_5::
	msgbox CherrygroveCity_Text_OldMan1_5, MSGBOX_AUTOCLOSE
	applymovement 1, CherrygroveCity_Movement_OldMan1_7
	applymovement LOCALID_PLAYER, CherrygroveCity_Movement_OldMan1_7
	delay 128
	msgbox CherrygroveCity_Text_OldMan1_6, MSGBOX_AUTOCLOSE
	applymovement 1, CherrygroveCity_Movement_OldMan1_7
	applymovement LOCALID_PLAYER, CherrygroveCity_Movement_OldMan1_7
	delay 112
	msgbox CherrygroveCity_Text_OldMan1_7, MSGBOX_AUTOCLOSE
	applymovement 1, CherrygroveCity_Movement_OldMan1_8
	applymovement LOCALID_PLAYER, CherrygroveCity_Movement_OldMan1_9
	delay 144
	msgbox CherrygroveCity_Text_OldMan1_8, MSGBOX_AUTOCLOSE
	applymovement 1, CherrygroveCity_Movement_OldMan1_10
	applymovement LOCALID_PLAYER, CherrygroveCity_Movement_OldMan1_11
	delay 0x130
	msgbox CherrygroveCity_Text_OldMan1_9, MSGBOX_AUTOCLOSE
	giveitem ITEM_TOWN_MAP
	msgbox CherrygroveCity_Text_OldMan1_10, MSGBOX_AUTOCLOSE
	opendoor 30, 10
	applymovement 1, CherrygroveCity_Movement_OldMan1_12
	delay 64
	closedoor 30, 10
	playbgm MUS_SEVII_123, 51
	clearflag 0x1009
	setflag 0x1010
	end

CherrygroveCity_Movement_OldMan1_1::
	walk_left
	walk_left
	walk_up
	walk_left
	face_up
	step_end

CherrygroveCity_Movement_OldMan1_2::
	walk_left
	walk_left
	walk_left
	walk_up
	face_up
	step_end

CherrygroveCity_Movement_OldMan1_3::
	walk_left
	walk_left
	walk_up
	walk_left
	face_up
	step_end

CherrygroveCity_Movement_OldMan1_4::
	walk_up
	walk_left
	walk_left
	walk_up
	face_up
	step_end

CherrygroveCity_Movement_OldMan1_5::
	walk_left
	walk_left
	walk_up
	walk_left
	face_up
	step_end

CherrygroveCity_Movement_OldMan1_6::
	walk_down
	walk_up
	walk_left
	walk_up
	face_up
	step_end

CherrygroveCity_Movement_OldMan1_7::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

CherrygroveCity_Movement_OldMan1_8::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	face_left
	step_end

CherrygroveCity_Movement_OldMan1_9::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	face_left
	step_end

CherrygroveCity_Movement_OldMan1_10::
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
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_left
	step_end

CherrygroveCity_Movement_OldMan1_11::
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
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

CherrygroveCity_Movement_OldMan1_12::
	walk_up
	set_invisible
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

CherrygroveCity_EventScript_Boy::
	call_if_set 0x1042, CherrygroveCity_EventScript_Boy_1
	msgbox CherrygroveCity_Text_Boy_1, MSGBOX_NPC
	end

CherrygroveCity_EventScript_Boy_1::
	msgbox CherrygroveCity_Text_Boy_2, MSGBOX_NPC
	end

CherrygroveCity_EventScript_Woman1::
	call_if_set 0x1042, CherrygroveCity_EventScript_Woman1_1
	msgbox CherrygroveCity_Text_Woman1_1, MSGBOX_NPC
	end

CherrygroveCity_EventScript_Woman1_1::
	msgbox CherrygroveCity_Text_Woman1_2, MSGBOX_NPC
	end

CherrygroveCity_EventScript_Fisher::
	call_if_set 0x10B9, CherrygroveCity_EventScript_Fisher_1
	setflag 0x10B9
	msgbox CherrygroveCity_Text_Fisher_1, MSGBOX_NPC
	giveitem ITEM_MYSTIC_WATER
	msgbox CherrygroveCity_Text_Fisher_2, MSGBOX_NPC
	end

CherrygroveCity_EventScript_Fisher_1::
	msgbox CherrygroveCity_Text_Fisher_2, MSGBOX_NPC
	end

CherrygroveCity_EventScript_Trigger1::
	call_if_set 0x1010, CherrygroveCity_EventScript_Trigger1_1
	setflag 0x1009
	release
	end

CherrygroveCity_EventScript_Trigger1_1::
	release
	end

CherrygroveCity_EventScript_Trigger3::
	call_if_unset 0x1015, CherrygroveCity_EventScript_Trigger3_1
	call_if_set 0x1020, CherrygroveCity_EventScript_Trigger3_1
	playbgm MUS_ENCOUNTER_RIVAL, 51
	applymovement LOCALID_PLAYER, CherrygroveCity_Movement_Trigger3_1
	applymovement 5, CherrygroveCity_Movement_Trigger3_2
	delay 64
	msgbox CherrygroveCity_Text_Trigger3_1, MSGBOX_NPC
	goto_if_eq VAR_STARTER_MON, 0, CherrygroveCity_EventScript_Trigger3_2
	goto_if_eq VAR_STARTER_MON, 1, CherrygroveCity_EventScript_Trigger3_3
	goto_if_eq VAR_STARTER_MON, 2, CherrygroveCity_EventScript_Trigger3_4

CherrygroveCity_EventScript_Trigger3_1::
	release
	end

CherrygroveCity_EventScript_Trigger3_2::
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_326, 0, CherrygroveCity_Text_Trigger3Defeat, Route22_Text_Trigger1Victory
	setflag 0x1020
	setflag 0x1018
	msgbox CherrygroveCity_Text_Trigger3_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, CherrygroveCity_Movement_Trigger3_3
	applymovement 5, CherrygroveCity_Movement_Trigger3_4
	delay 80
	setobjectxy 5, 0x95C, 0x147
	nop
	nop
	.byte 0xEA @ invalid opcode (script stops)

CherrygroveCity_EventScript_Trigger3_3::
	@ ShinyGold: overlapping data duplicated from 0x08740B60
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_327, 0, CherrygroveCity_Text_Trigger3Defeat, Route22_Text_Trigger1Victory
	setflag 0x1020
	setflag 0x1018
	msgbox CherrygroveCity_Text_Trigger3_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, CherrygroveCity_Movement_Trigger3_3
	applymovement 5, CherrygroveCity_Movement_Trigger3_4
	delay 80
	setobjectxy 5, 0x95C, 0x148
	nop
	nop
	.byte 0xEA @ invalid opcode (script stops)

CherrygroveCity_EventScript_Trigger3_4::
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_328, 0, CherrygroveCity_Text_Trigger3Defeat, Route22_Text_Trigger1Victory
	setflag 0x1020
	setflag 0x1018
	msgbox CherrygroveCity_Text_Trigger3_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, CherrygroveCity_Movement_Trigger3_3
	applymovement 5, CherrygroveCity_Movement_Trigger3_4
	delay 80
	setobjectxy 5, 0xADAD, 0xFBAD
	textcolor 237
	nop
	.byte 0xE2 @ invalid opcode (script stops)

CherrygroveCity_Movement_Trigger3_1::
	emote_exclamation_mark
	step_end

CherrygroveCity_Movement_Trigger3_2::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CherrygroveCity_Movement_Trigger3_3::
	walk_fast_down
	face_up
	step_end

CherrygroveCity_Movement_Trigger3_4::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CherrygroveCity_EventScript_Trigger4::
	call_if_unset 0x1015, CherrygroveCity_EventScript_Trigger3_1
	call_if_set 0x1020, CherrygroveCity_EventScript_Trigger3_1
	playbgm MUS_ENCOUNTER_RIVAL, 51
	applymovement LOCALID_PLAYER, CherrygroveCity_Movement_Trigger3_1
	applymovement 5, CherrygroveCity_Movement_Trigger4_1
	delay 64
	msgbox CherrygroveCity_Text_Trigger3_1, MSGBOX_NPC
	goto_if_eq VAR_STARTER_MON, 0, CherrygroveCity_EventScript_Trigger4_1
	goto_if_eq VAR_STARTER_MON, 1, CherrygroveCity_EventScript_Trigger4_2
	goto_if_eq VAR_STARTER_MON, 2, CherrygroveCity_EventScript_Trigger4_3

CherrygroveCity_EventScript_Trigger4_1::
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_326, 0, CherrygroveCity_Text_Trigger3Defeat, Route22_Text_Trigger1Victory
	setflag 0x1020
	setflag 0x1018
	msgbox CherrygroveCity_Text_Trigger3_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, CherrygroveCity_Movement_Trigger4_2
	applymovement 5, CherrygroveCity_Movement_Trigger4_3
	delay 96
	setobjectxy 5, 0x95C, 0x147
	nop
	nop
	.byte 0xEA @ invalid opcode (script stops)

CherrygroveCity_EventScript_Trigger4_2::
	@ ShinyGold: overlapping data duplicated from 0x08740CB0
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_327, 0, CherrygroveCity_Text_Trigger3Defeat, Route22_Text_Trigger1Victory
	setflag 0x1020
	setflag 0x1018
	msgbox CherrygroveCity_Text_Trigger3_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, CherrygroveCity_Movement_Trigger4_2
	applymovement 5, CherrygroveCity_Movement_Trigger4_3
	delay 96
	setobjectxy 5, 0x95C, 0x148
	nop
	nop
	.byte 0xEA @ invalid opcode (script stops)

CherrygroveCity_EventScript_Trigger4_3::
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_328, 0, CherrygroveCity_Text_Trigger3Defeat, Route22_Text_Trigger1Victory
	setflag 0x1020
	setflag 0x1018
	msgbox CherrygroveCity_Text_Trigger3_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, CherrygroveCity_Movement_Trigger4_2
	applymovement 5, CherrygroveCity_Movement_Trigger4_3
	delay 96
	setobjectxy 5, 0x41E, 254
	return

CherrygroveCity_Movement_Trigger4_2::
	@ ShinyGold: overlapping data duplicated from 0x08740D10
	walk_fast_up
	face_down_fast
	step_end

CherrygroveCity_Movement_Trigger4_1::
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CherrygroveCity_Movement_Trigger4_3::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CherrygroveCity_EventScript_Sign1::
	msgbox CherrygroveCity_Text_Sign1, MSGBOX_AUTOCLOSE
	end

CherrygroveCity_EventScript_Sign2::
	msgbox CherrygroveCity_Text_Sign2, MSGBOX_AUTOCLOSE
	end

CherrygroveCity_EventScript_Sign3::
	call_if_unset 0x1025, CherrygroveCity_EventScript_Sign3_1
	call_if_unset 0x1027, Route35_EventScript_Sign4_1
	setvar 0x700B, 1
	call_if_eq VAR_FACING, 2, Route35_EventScript_Sign4_2
	release
	end

CherrygroveCity_EventScript_Sign3_1::
	setvar 0x700B, 6
	call_if_eq VAR_FACING, 2, Route35_EventScript_Sign4_2
	release
	end
