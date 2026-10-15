EcruteakCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EcruteakCity_OnFrame
	.byte 0

EcruteakCity_OnFrame::
	map_script_2 0x7025, 0, EcruteakCity_EventScript_FrameScene
	.2byte 0

EcruteakCity_EventScript_FrameScene::
	setflag 0x136F
	call NewBarkTown_EventScript_FrameScene_1
	setvar 0x7025, 1
	call EcruteakCity_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

EcruteakCity_EventScript_FrameScene_1::
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
	setvar 0x7021, 0
	setvar 0x7022, 0
	setvar 0x7023, 0
	setvar 0x7024, 0
	setvar 0x7026, 0
	setvar 0x7027, 0
	setvar 0x7028, 0
	return

EcruteakCity_EventScript_Lass::
	msgbox EcruteakCity_Text_Lass, MSGBOX_NPC
	end

EcruteakCity_EventScript_FatMan::
	msgbox EcruteakCity_Text_FatMan, MSGBOX_NPC
	end

EcruteakCity_EventScript_OldMan2::
	msgbox EcruteakCity_Text_OldMan2, MSGBOX_NPC
	end

EcruteakCity_EventScript_Man::
	msgbox EcruteakCity_Text_Man, MSGBOX_NPC
	end

EcruteakCity_EventScript_OldMan1::
	msgbox EcruteakCity_Text_OldMan1, MSGBOX_NPC
	end

EcruteakCity_EventScript_Woman2::
	msgbox EcruteakCity_Text_Woman2, MSGBOX_NPC
	end

EcruteakCity_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION
	end

EcruteakCity_EventScript_CooltrainerF::
	msgbox EcruteakCity_Text_CooltrainerF_1, MSGBOX_AUTOCLOSE
	delay 16
	msgbox EcruteakCity_Text_CooltrainerF_2, MSGBOX_AUTOCLOSE
	delay 16
	msgbox EcruteakCity_Text_CooltrainerF_3, MSGBOX_AUTOCLOSE
	delay 16
	msgbox EcruteakCity_Text_CooltrainerF_4, MSGBOX_AUTOCLOSE
	applymovement 8, EcruteakCity_Movement_CooltrainerF_1
	applymovement 9, EcruteakCity_Movement_CooltrainerF_1
	msgbox EcruteakCity_Text_CooltrainerF_5, MSGBOX_NPC
	msgbox EcruteakCity_Text_CooltrainerF_6, MSGBOX_NPC
	delay 16
	msgbox EcruteakCity_Text_CooltrainerF_7, MSGBOX_NPC
	msgbox EcruteakCity_Text_CooltrainerF_8, MSGBOX_NPC
	delay 16
	msgbox EcruteakCity_Text_CooltrainerF_9, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_COOL_COUPLE_DANTE_AND_RINA, 0, EcruteakCity_Text_CooltrainerFDefeat, EcruteakCity_Text_CooltrainerFVictory
	setflag 0x10AA
	msgbox EcruteakCity_Text_CooltrainerF_10, MSGBOX_NPC
	delay 16
	msgbox EcruteakCity_Text_CooltrainerF_11, MSGBOX_NPC
	delay 16
	msgbox EcruteakCity_Text_CooltrainerF_12, MSGBOX_NPC
	applymovement LOCALID_PLAYER, EcruteakCity_Movement_CooltrainerF_2
	delay 16
	applymovement 8, EcruteakCity_Movement_CooltrainerF_3
	applymovement 9, EcruteakCity_Movement_CooltrainerF_3
	delay 240
	release
	end

EcruteakCity_Movement_CooltrainerF_1::
	face_down_fast
	step_end

EcruteakCity_Movement_CooltrainerF_2::
	walk_left
	walk_left
	face_down_fast
	step_end

EcruteakCity_Movement_CooltrainerF_3::
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EcruteakCity_EventScript_PokeManiac::
	call_if_set 0x1245, EcruteakCity_EventScript_PokeManiac_1
	msgbox EcruteakCity_Text_PokeManiac_1, MSGBOX_NPC
	giveitem ITEM_SPELL_TAG
	msgbox EcruteakCity_Text_PokeManiac_2, MSGBOX_NPC
	setflag 0x1245
	clearflag 0x1246
	release
	end

EcruteakCity_EventScript_PokeManiac_1::
	msgbox EcruteakCity_Text_PokeManiac_3, MSGBOX_NPC
	end

EcruteakCity_EventScript_Trigger1::
	call_if_set 0x11B4, EcruteakCity_EventScript_Trigger1_1
	checkitem ITEM_POKEBLOCK_CASE
	call_if_eq VAR_RESULT, 1, EcruteakCity_EventScript_Trigger1_2
	clearflag 0x11B5
	release
	end

EcruteakCity_EventScript_Trigger1_1::
	clearflag 0x11B5
	release
	end

EcruteakCity_EventScript_Trigger1_2::
	setflag 0x11B5
	release
	end

EcruteakCity_EventScript_Trigger2::
	call_if_set 0x11B4, EcruteakCity_EventScript_Trigger2_1
	checkitem ITEM_POKEBLOCK_CASE
	call_if_eq VAR_RESULT, 1, EcruteakCity_EventScript_Trigger2_2
	setflag 0x11B6
	release
	end

EcruteakCity_EventScript_Trigger2_1::
	setflag 0x11B6
	release
	end

EcruteakCity_EventScript_Trigger2_2::
	clearflag 0x11B6
	release
	end

EcruteakCity_EventScript_Trigger3::
	call_if_set 0x10AD, EcruteakCity_EventScript_Trigger3_1
	applymovement LOCALID_PLAYER, EcruteakCity_Movement_Trigger3_1
	delay 32
	goto EcruteakCity_EventScript_Trigger6

EcruteakCity_EventScript_Trigger3_1::
	release
	.byte 0xFF @ invalid opcode (script stops)

EcruteakCity_EventScript_Trigger6::
	call_if_set 0x10AD, EcruteakCity_EventScript_Trigger3_1
	setflag 0x10AD
	textcolor NPC_TEXT_COLOR_MALE
	msgbox EcruteakCity_Text_Trigger3_1, MSGBOX_NPC
	call Route44_EventScript_TeachyTvHost_1
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_CARLOS_4, 0, EcruteakCity_Text_Trigger3Defeat, EcruteakCity_Text_Trigger3Defeat
	msgbox EcruteakCity_Text_Trigger3_2, MSGBOX_NPC
	call Route44_EventScript_TeachyTvHost_2
	applymovement 10, EcruteakCity_Movement_Trigger3_2
	delay 144
	release
	end

EcruteakCity_Movement_Trigger3_1::
	walk_up
	walk_right
	step_end

EcruteakCity_Movement_Trigger3_2::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	set_invisible
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

EcruteakCity_EventScript_Trigger5::
	call_if_set 0x10AD, EcruteakCity_EventScript_Trigger3_1
	applymovement LOCALID_PLAYER, EcruteakCity_Movement_Trigger5
	delay 32
	goto EcruteakCity_EventScript_Trigger6

EcruteakCity_Movement_Trigger5::
	walk_right
	walk_right
	step_end

EcruteakCity_EventScript_Sign1::
	msgbox EcruteakCity_Text_Sign1, MSGBOX_AUTOCLOSE
	end

EcruteakCity_EventScript_Sign2::
	msgbox EcruteakCity_Text_Sign2, MSGBOX_AUTOCLOSE
	end

EcruteakCity_EventScript_Sign3::
	msgbox EcruteakCity_Text_Sign3, MSGBOX_AUTOCLOSE
	end

EcruteakCity_EventScript_Sign4::
	msgbox EcruteakCity_Text_Sign4, MSGBOX_AUTOCLOSE
	end

EcruteakCity_EventScript_Sign5::
	msgbox EcruteakCity_Text_Sign5, MSGBOX_AUTOCLOSE
	end

EcruteakCity_EventScript_Sign6::
	call_if_unset 0x1027, Route35_EventScript_Sign4_1
	setvar 0x700B, 5
	call_if_eq VAR_FACING, 2, Route35_EventScript_Sign4_2
	release
	end
