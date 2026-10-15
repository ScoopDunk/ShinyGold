IlexForest_Interior1_MapScripts::
	.byte 0

IlexForest_Interior1_EventScript_Fearow::
	msgbox IlexForest_Interior1_Text_Fearow, MSGBOX_NPC
	call_if_set 0x1070, IlexForest_Interior1_EventScript_Fearow_1
	call_if_eq VAR_RESULT, 13, IlexForest_Interior1_EventScript_Fearow_2
	call_if_eq VAR_RESULT, 12, IlexForest_Interior1_EventScript_Fearow_3
	call_if_eq VAR_RESULT, 11, IlexForest_Interior1_EventScript_Fearow_4
	call_if_eq VAR_RESULT, 10, IlexForest_Interior1_EventScript_Fearow_5
	call_if_eq VAR_RESULT, 9, IlexForest_Interior1_EventScript_Fearow_6
	call_if_eq VAR_RESULT, 8, IlexForest_Interior1_EventScript_Fearow_7
	call_if_eq VAR_RESULT, 7, IlexForest_Interior1_EventScript_Fearow_8
	call_if_eq VAR_RESULT, 6, IlexForest_Interior1_EventScript_Fearow_9
	call_if_eq VAR_RESULT, 5, IlexForest_Interior1_EventScript_Fearow_10
	call_if_eq VAR_RESULT, 4, IlexForest_Interior1_EventScript_Fearow_11
	call_if_eq VAR_RESULT, 3, IlexForest_Interior1_EventScript_Fearow_12
	call_if_eq VAR_RESULT, 2, IlexForest_Interior1_EventScript_Fearow_13
	applymovement 1, IlexForest_Interior1_Movement_Fearow_1
	end

IlexForest_Interior1_EventScript_Fearow_1::
	warp MAP_ILEX_FOREST_INTERIOR1, 1, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

IlexForest_Interior1_EventScript_Fearow_2::
	setflag 0x1070
	setflag 0x1072
	clearflag 0x1071
	applymovement 1, IlexForest_Interior1_Movement_Fearow_2
	delay 64
	end

IlexForest_Interior1_EventScript_Fearow_3::
	applymovement 1, IlexForest_Interior1_Movement_Fearow_3
	delay 48
	end

IlexForest_Interior1_EventScript_Fearow_4::
	applymovement 1, IlexForest_Interior1_Movement_Fearow_4
	delay 64
	end

IlexForest_Interior1_EventScript_Fearow_5::
	applymovement 1, IlexForest_Interior1_Movement_Fearow_5
	delay 112
	end

IlexForest_Interior1_EventScript_Fearow_6::
	applymovement 1, IlexForest_Interior1_Movement_Fearow_6
	delay 64
	end

IlexForest_Interior1_EventScript_Fearow_7::
	applymovement 1, IlexForest_Interior1_Movement_Fearow_7
	delay 64
	end

IlexForest_Interior1_EventScript_Fearow_8::
	applymovement 1, IlexForest_Interior1_Movement_Fearow_8
	delay 64
	end

IlexForest_Interior1_EventScript_Fearow_9::
	applymovement 1, IlexForest_Interior1_Movement_Fearow_9
	delay 64
	end

IlexForest_Interior1_EventScript_Fearow_10::
	applymovement 1, IlexForest_Interior1_Movement_Fearow_10
	delay 80
	end

IlexForest_Interior1_EventScript_Fearow_11::
	applymovement 1, IlexForest_Interior1_Movement_Fearow_11
	delay 64
	end

IlexForest_Interior1_EventScript_Fearow_12::
	applymovement 1, IlexForest_Interior1_Movement_Fearow_12
	delay 80
	end

IlexForest_Interior1_EventScript_Fearow_13::
	applymovement 1, IlexForest_Interior1_Movement_Fearow_13
	delay 64
	end

IlexForest_Interior1_Movement_Fearow_1::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

IlexForest_Interior1_Movement_Fearow_2::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

IlexForest_Interior1_Movement_Fearow_3::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

IlexForest_Interior1_Movement_Fearow_4::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_Interior1_Movement_Fearow_5::
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

IlexForest_Interior1_Movement_Fearow_6::
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_Interior1_Movement_Fearow_7::
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	step_end

IlexForest_Interior1_Movement_Fearow_8::
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	step_end

IlexForest_Interior1_Movement_Fearow_9::
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	step_end

IlexForest_Interior1_Movement_Fearow_10::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_Interior1_Movement_Fearow_11::
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_Interior1_Movement_Fearow_12::
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_Interior1_Movement_Fearow_13::
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_Interior1_EventScript_Boy::
	call_if_set 0x1072, IlexForest_Interior1_EventScript_Boy_1
	msgbox IlexForest_Interior1_Text_Boy_1, MSGBOX_NPC
	end

IlexForest_Interior1_EventScript_Boy_1::
	msgbox IlexForest_Interior1_Text_Boy_2, MSGBOX_NPC
	end

IlexForest_Interior1_EventScript_Fearow2::
	msgbox IlexForest_Interior1_Text_Fearow2, MSGBOX_NPC
	waitse
	playmoncry SPECIES_FARFETCHD, 0x201
	.byte 0xFF @ invalid opcode (script stops)

IlexForest_Interior1_EventScript_Rocker::
	call_if_set 0x1073, IlexForest_Interior1_EventScript_Rocker_1
	clearflag 0x1074
	setflag 0x1073
	setflag 0x1071
	msgbox IlexForest_Interior1_Text_Rocker_1, MSGBOX_NPC
	giveitem ITEM_HM01
	msgbox IlexForest_Interior1_Text_Rocker_2, MSGBOX_NPC
	end

IlexForest_Interior1_EventScript_Rocker_1::
	msgbox IlexForest_Interior1_Text_Rocker_3, MSGBOX_NPC
	end

IlexForest_Interior1_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

IlexForest_Interior1_EventScript_ItemSuperPotion::
	finditem ITEM_SUPER_POTION
	end

IlexForest_Interior1_EventScript_ItemRevive::
	finditem ITEM_REVIVE
	end

IlexForest_Interior1_EventScript_CooltrainerM::
	call_if_set 0x10D4, IlexForest_Interior1_EventScript_CooltrainerM_1
	msgbox IlexForest_Interior1_Text_CooltrainerM_1, MSGBOX_NPC
	giveitem ITEM_TM02
	setflag 0x10D4
	msgbox IlexForest_Interior1_Text_CooltrainerM_2, MSGBOX_NPC
	end

IlexForest_Interior1_EventScript_CooltrainerM_1::
	msgbox IlexForest_Interior1_Text_CooltrainerM_2, MSGBOX_NPC
	end

IlexForest_Interior1_EventScript_Lass::
	msgbox IlexForest_Interior1_Text_Lass, MSGBOX_NPC
	end

IlexForest_Interior1_EventScript_Celebi::
	release
	end

IlexForest_Interior1_EventScript_CrushGirl::
	call_if_set 0x1244, IlexForest_Interior1_EventScript_CrushGirl_1
	msgbox IlexForest_Interior1_Text_CrushGirl_1, MSGBOX_NPC
	lock
	faceplayer
	giveitem ITEM_POISON_BARB
	msgbox IlexForest_Interior1_Text_CrushGirl_2, MSGBOX_NPC
	setflag 0x1244
	clearflag 0x1245
	release
	end

IlexForest_Interior1_EventScript_CrushGirl_1::
	msgbox IlexForest_Interior1_Text_CrushGirl_3, MSGBOX_NPC
	end

IlexForest_Interior1_EventScript_Trigger1::
	call_if_set 0x1072, IlexForest_Interior1_EventScript_Trigger1_1
	setflag 0x1071
	release
	end

IlexForest_Interior1_EventScript_Trigger1_1::
	release
	end

IlexForest_Interior1_EventScript_Trigger2::
	setvar VAR_RESULT, 10
	release
	end

IlexForest_Interior1_EventScript_Trigger3::
	setvar VAR_RESULT, 1
	release
	end

IlexForest_Interior1_EventScript_Trigger4::
	call_if_set 0x1055, IlexForest_Interior1_EventScript_Trigger4_1
	setflag 0x1073
	setflag 0x1070
	release
	end

IlexForest_Interior1_EventScript_Trigger4_1::
	release
	end

IlexForest_Interior1_EventScript_Trigger5::
	setvar VAR_RESULT, 11
	release
	end

IlexForest_Interior1_EventScript_Trigger6::
	setflag 0x11B2
	release
	end

IlexForest_Interior1_EventScript_Trigger8::
	setvar VAR_RESULT, 9
	release
	end

IlexForest_Interior1_EventScript_Trigger9::
	setvar VAR_RESULT, 8
	release
	end

IlexForest_Interior1_EventScript_Trigger10::
	setvar VAR_RESULT, 7
	release
	end

IlexForest_Interior1_EventScript_Trigger11::
	setvar VAR_RESULT, 12
	release
	end

IlexForest_Interior1_EventScript_Trigger12::
	setvar VAR_RESULT, 3
	release
	end

IlexForest_Interior1_EventScript_Trigger13::
	setvar VAR_RESULT, 2
	release
	end

IlexForest_Interior1_EventScript_Trigger14::
	setvar VAR_RESULT, 13
	release
	end

IlexForest_Interior1_EventScript_Trigger16::
	setvar VAR_RESULT, 4
	release
	end

IlexForest_Interior1_EventScript_Trigger17::
	setvar VAR_RESULT, 5
	release
	end

IlexForest_Interior1_EventScript_Trigger18::
	setvar VAR_RESULT, 6
	release
	end

IlexForest_Interior1_EventScript_Trigger19::
	call_if_unset 0x11B2, IlexForest_Interior1_EventScript_Trigger19_1
	release
	end

IlexForest_Interior1_EventScript_Trigger19_1::
	applymovement LOCALID_PLAYER, IlexForest_Interior1_Movement_Trigger19_1
	delay 16
	applymovement 50, IlexForest_Interior1_Movement_Trigger19_2
	delay 16
	applymovement 29, IlexForest_Interior1_Movement_Trigger19_3
	delay 192
	msgbox IlexForest_Interior1_Text_Trigger19, MSGBOX_NPC
	applymovement 29, IlexForest_Interior1_Movement_Trigger19_4
	delay 208
	setflag 0x11B2
	release
	end

IlexForest_Interior1_Movement_Trigger19_1::
	walk_down
	step_end

IlexForest_Interior1_Movement_Trigger19_2::
	set_invisible
	walk_fast_left
	walk_fast_left
	step_end

IlexForest_Interior1_Movement_Trigger19_3::
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

IlexForest_Interior1_Movement_Trigger19_4::
	walk_down
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
	set_invisible
	walk_left
	walk_left
	walk_left
	step_end

IlexForest_Interior1_EventScript_Sign1::
	call_if_set 0x11B3, IlexForest_Interior1_EventScript_Sign1_1
	call_if_set 0x11B1, IlexForest_Interior1_EventScript_Sign1_2
	msgbox IlexForest_Interior1_Text_Sign1_1, MSGBOX_AUTOCLOSE
	end

IlexForest_Interior1_EventScript_Sign1_1::
	msgbox IlexForest_Interior1_Text_Sign1_1, MSGBOX_AUTOCLOSE
	end

IlexForest_Interior1_EventScript_Sign1_2::
	msgbox IlexForest_Interior1_Text_Sign1_1, MSGBOX_NPC
	msgbox IlexForest_Interior1_Text_Sign1_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, IlexForest_Interior1_EventScript_Sign1_3
	release
	end

IlexForest_Interior1_EventScript_Sign1_3::
	release
	playbgm MUS_NONE, 51
	setobjectxy 30, 24, 34
	delay 16
	setobjectxy 30, 31, 21
	delay 16
	setobjectxy 30, 24, 34
	delay 32
	setobjectxy 30, 31, 21
	delay 32
	setobjectxy 30, 24, 34
	delay 48
	setobjectxy 30, 31, 21
	delay 80
	setobjectxy 30, 17, 36
	delay 16
	setobjectxy 30, 31, 21
	delay 16
	setobjectxy 30, 17, 36
	delay 32
	setobjectxy 30, 31, 21
	delay 32
	setobjectxy 30, 17, 36
	delay 48
	setobjectxy 30, 31, 21
	delay 80
	setobjectxy 30, 18, 39
	delay 16
	setobjectxy 30, 31, 21
	delay 16
	setobjectxy 30, 18, 39
	delay 32
	setobjectxy 30, 31, 21
	delay 32
	setobjectxy 30, 18, 39
	delay 96
	waitse
	playmoncry SPECIES_CELEBI, 0x2800
	waitse
	nop
	delay 48
	removeitem ITEM_RED_ORB
	setwildbattle SPECIES_CELEBI, 30
	nop
	special StartLegendaryBattle
	delay 128
	setflag 0x11AD
	clearflag 0x11AE
	clearflag 0x11B2
	setflag 0x11B3
	clearflag 0x11AF
	clearflag 0x11B0
	warp MAP_ILEX_FOREST_INTERIOR1, 3, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

IlexForest_Interior1_EventScript_Sign2::
	msgbox IlexForest_Interior1_Text_Sign2, MSGBOX_AUTOCLOSE
	end
