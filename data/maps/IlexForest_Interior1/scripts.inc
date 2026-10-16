IlexForest_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IlexForest_Interior1_OnTransition
	.byte 0

@ Pure Gold: the GS Ball event, as in Crystal (pokecrystal IlexForest). KURT (object 29) and CELEBI (object 30) only
@ appear in the shrine scene; the lass (object 28) is here while the forest is restless (EVENT_ILEX_FOREST_LASS).
IlexForest_Interior1_OnTransition::
	setflag FLAG_GOLD_HIDE_ILEX_KURT
	setflag FLAG_GOLD_HIDE_ILEX_CELEBI
	setflag FLAG_GOLD_HIDE_ILEX_LASS
	goto_if_eq VAR_GOLD_GS_BALL, GS_BALL_RETURNED, IlexForest_Interior1_EventScript_ShowLass
	end

IlexForest_Interior1_EventScript_ShowLass::
	clearflag FLAG_GOLD_HIDE_ILEX_LASS
	end

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

@ Pure Gold: the ILEX FOREST shrine, as in Crystal (pokecrystal IlexForestShrineScript): with the GS BALL that KURT
@ gave back, CELEBI appears (Lv 30); if it is caught, KURT comes to thank the player.
IlexForest_Interior1_EventScript_Sign1::
	lockall
	goto_if_ne VAR_GOLD_GS_BALL, GS_BALL_RETURNED, IlexForest_Interior1_EventScript_Shrine
	checkitem ITEM_RED_ORB
	goto_if_eq VAR_RESULT, FALSE, IlexForest_Interior1_EventScript_Shrine
	msgbox IlexForest_Interior1_Text_Sign1_1
	msgbox IlexForest_Interior1_Text_Sign1_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, IlexForest_Interior1_EventScript_ShrineEnd
	removeitem ITEM_RED_ORB
	setvar VAR_GOLD_GS_BALL, GS_BALL_USED
	removeobject 28
	msgbox IlexForest_Interior1_Text_InsertGSBall
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	fadeoutbgm 0
	delay 30
	getplayerxy VAR_0x8004, VAR_0x8005
	setobjectxyperm 30, VAR_0x8004, 34
	clearflag FLAG_GOLD_HIDE_ILEX_CELEBI
	addobject 30
	applymovement 30, IlexForest_Interior1_Movement_CelebiAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	removeobject 30
	setwildbattle SPECIES_CELEBI, 30
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, IlexForest_Interior1_EventScript_ShrineEnd
	delay 20
	clearflag FLAG_GOLD_HIDE_ILEX_KURT
	addobject 29
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 20, IlexForest_Interior1_EventScript_KurtComesToRightSide
	applymovement 29, IlexForest_Interior1_Movement_KurtComes
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox IlexForest_Interior1_Text_KurtCaughtCelebi
	closemessage
	applymovement 29, IlexForest_Interior1_Movement_KurtLeaves
	goto IlexForest_Interior1_EventScript_KurtHasLeft

IlexForest_Interior1_EventScript_KurtComesToRightSide::
	applymovement 29, IlexForest_Interior1_Movement_KurtComesToRightSide
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox IlexForest_Interior1_Text_KurtCaughtCelebi
	closemessage
	applymovement 29, IlexForest_Interior1_Movement_KurtLeavesFromRightSide
IlexForest_Interior1_EventScript_KurtHasLeft::
	waitmovement 0
	removeobject 29
	releaseall
	end

IlexForest_Interior1_EventScript_Shrine::
	msgbox IlexForest_Interior1_Text_Sign1_1
IlexForest_Interior1_EventScript_ShrineEnd::
	releaseall
	end

IlexForest_Interior1_Movement_CelebiAppears::
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

IlexForest_Interior1_Movement_KurtComes::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

IlexForest_Interior1_Movement_KurtComesToRightSide::
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

IlexForest_Interior1_Movement_KurtLeaves::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

IlexForest_Interior1_Movement_KurtLeavesFromRightSide::
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

IlexForest_Interior1_EventScript_Sign2::
	msgbox IlexForest_Interior1_Text_Sign2, MSGBOX_AUTOCLOSE
	end
