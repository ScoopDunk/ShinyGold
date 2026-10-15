MtSilver_Cave3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_Cave3_OnTransition
	.byte 0

MtSilver_Cave3_OnTransition::
	call_if_eq 0x4080, 1, MtSilver_Cave3_EventScript_OnTransition_1
	end

MtSilver_Cave3_EventScript_OnTransition_1::
	setflag 0x08B
	return

MtSilver_Cave3_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

MtSilver_Cave3_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

MtSilver_Cave3_EventScript_ItemProtein::
	finditem ITEM_PROTEIN
	end

MtSilver_Cave3_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

MtSilver_Cave3_EventScript_Trigger1::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox MtSilver_Cave3_Text_Trigger1_1
	applymovement 1, MtSilver_Cave3_Movement_Trigger1_1
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox MtSilver_Cave3_Text_Trigger1_2
	closemessage
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement 3, Common_Movement_Delay48
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox MtSilver_Cave3_Text_Trigger1_3
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 18
	applymovement 3, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 35
	applymovement 4, MtSilver_Cave3_Movement_Trigger1_2
	applymovement 3, MtSilver_Cave3_Movement_Trigger1_3
	applymovement LOCALID_PLAYER, MtSilver_Cave3_Movement_Trigger1_4
	waitmovement 0
	applymovement 2, MtSilver_Cave3_Movement_Trigger1_1
	waitmovement 0
	playbgm MUS_ENCOUNTER_ROCKET, 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox MtSilver_Cave3_Text_Trigger1_4
	setvar VAR_LAST_TALKED, 4
	trainerbattle_no_intro TRAINER_POKEFAN_ALEX, MtSilver_Cave3_Text_Trigger1Defeat
	applymovement 3, MtSilver_Cave3_Movement_Trigger1_5
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox MtSilver_Cave3_Text_Trigger1_5
	textcolor NPC_TEXT_COLOR_MALE
	msgbox MtSilver_Cave3_Text_Trigger1_6
	textcolor NPC_TEXT_COLOR_FEMALE
	message MtSilver_Cave3_Text_Trigger1_7
	waitmessage
	waitse
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitbuttonpress
	waitmoncry
	applymovement 1, MtSilver_Cave3_Movement_Trigger1_6
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox MtSilver_Cave3_Text_Trigger1_8
	closemessage
	applymovement 3, MtSilver_Cave3_Movement_Trigger1_7
	applymovement LOCALID_PLAYER, MtSilver_Cave3_Movement_Trigger1_8
	applymovement 1, MtSilver_Cave3_Movement_Trigger1_9
	applymovement 2, MtSilver_Cave3_Movement_Trigger1_10
	applymovement 4, MtSilver_Cave3_Movement_Trigger1_11
	waitmovement 0
	removeobject 1
	removeobject 2
	removeobject 4
	delay 50
	applymovement 3, MtSilver_Cave3_Movement_Trigger1_12
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox MtSilver_Cave3_Text_Trigger1_9
	setflag 0x08E
	clearflag 0x08C
	setvar 0x4080, 1
	releaseall
	end

MtSilver_Cave3_Movement_Trigger1_1::
	walk_in_place_down
	step_end

MtSilver_Cave3_Movement_Trigger1_2::
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

MtSilver_Cave3_Movement_Trigger1_3::
	walk_left
	walk_up
	step_end

MtSilver_Cave3_Movement_Trigger1_4::
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

MtSilver_Cave3_Movement_Trigger1_5::
	walk_in_place_up
	step_end

MtSilver_Cave3_Movement_Trigger1_6::
	walk_in_place_fast_down
	step_end

MtSilver_Cave3_Movement_Trigger1_7::
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

MtSilver_Cave3_Movement_Trigger1_8::
	delay_16
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

MtSilver_Cave3_Movement_Trigger1_9::
	walk_right
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

MtSilver_Cave3_Movement_Trigger1_10::
	delay_16
	walk_left
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

MtSilver_Cave3_Movement_Trigger1_11::
	delay_16
	walk_down
	delay_16
	walk_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

MtSilver_Cave3_Movement_Trigger1_12::
	walk_right
	step_end
