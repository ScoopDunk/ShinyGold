Route6_MapScripts::
	.byte 0

Route6_EventScript_RsMay::
	applymovement 2, Route6_Movement_RsMay_1
	delay 1
	applymovement 3, Route6_Movement_RsMay_2
	delay 1
	msgbox Route6_Text_RsMay_1, MSGBOX_AUTOCLOSE
	applymovement 2, Route6_Movement_RsMay_3
	delay 1
	applymovement 3, Route6_Movement_RsMay_3
	delay 1
	msgbox Route6_Text_RsMay_2, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_PKMN_THIEF_ASHLEE_2, 0, Route6_Text_RsMayDefeat, Route6_Text_RsMayVictory
	setflag 0x1190
	setflag 0x118D
	msgbox Route6_Text_RsMay_3, MSGBOX_NPC
	applymovement 2, Route6_Movement_RsMay_4
	delay 5
	applymovement 3, Route6_Movement_RsMay_5
	delay 144
	applymovement LOCALID_PLAYER, Route6_Movement_RsMay_6
	delay 16
	msgbox Route6_Text_RsMay_4, MSGBOX_AUTOCLOSE
	giveitem ITEM_SCANNER
	delay 32
	msgbox Route6_Text_RsMay_5, MSGBOX_AUTOCLOSE
	end

Route6_Movement_RsMay_1::
	face_up
	step_end

Route6_Movement_RsMay_2::
	face_down_fast
	step_end

Route6_Movement_RsMay_3::
	face_right
	emote_exclamation_mark
	step_end

Route6_Movement_RsMay_4::
	jump_2_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	set_invisible
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route6_Movement_RsMay_5::
	walk_down
	jump_2_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	set_invisible
	walk_fast_up
	walk_fast_up
	step_end

Route6_Movement_RsMay_6::
	walk_left
	step_end

Route6_EventScript_Trigger1::
	call_if_set 0x1191, Route6_EventScript_Trigger1_1
	setflag 0x1190
	release
	end

Route6_EventScript_Trigger1_1::
	release
	end

Route6_EventScript_Sign::
	msgbox Route6_Text_Sign, MSGBOX_AUTOCLOSE
	end
