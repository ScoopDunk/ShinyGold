SeaCavern_Interior2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeaCavern_Interior2_OnTransition
	.byte 0

SeaCavern_Interior2_OnTransition::
	call EventScript_TryDarkenRuins
	end

SeaCavern_Interior2_EventScript_Trigger::
	call_if_set 0x1177, SeaCavern_Interior2_EventScript_Trigger_1
	applymovement LOCALID_PLAYER, SeaCavern_Interior2_Movement_Trigger_1
	delay 80
	applymovement 1, SeaCavern_Interior2_Movement_Trigger_2
	delay 16
	playfanfare MUS_SLOTS_JACKPOT
	msgbox SeaCavern_Interior2_Text_Trigger, MSGBOX_AUTOCLOSE
	waitfanfare
	giveitem ITEM_RED_ORB
	release
	applymovement LOCALID_PLAYER, SeaCavern_Interior2_Movement_Trigger_3
	delay 64
	waitse
	playmoncry SPECIES_AGGRON, 0x2800
	waitse
	nop
	delay 48
	setwildbattle SPECIES_AGGRON, 60
	nop
	special StartLegendaryBattle
	applymovement 2, SeaCavern_Interior2_Movement_Trigger_4
	delay 32
	setflag 0x1177
	release
	end

SeaCavern_Interior2_EventScript_Trigger_1::
	release
	end

SeaCavern_Interior2_Movement_Trigger_1::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SeaCavern_Interior2_Movement_Trigger_2::
	set_invisible
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeaCavern_Interior2_Movement_Trigger_3::
	face_down_fast
	step_end

SeaCavern_Interior2_Movement_Trigger_4::
	set_invisible
	walk_up
	walk_up
	step_end
