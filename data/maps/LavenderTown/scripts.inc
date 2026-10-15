LavenderTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setflag 0x1364
	setvar 0x7045, 1
	setvar 0x405B, 1
	setflag 0x03D
	end

LavenderTown_EventScript_BaldingMan::
	msgbox LavenderTown_Text_BaldingMan, MSGBOX_NPC
	end

LavenderTown_EventScript_OldMan1::
	msgbox LavenderTown_Text_OldMan1, MSGBOX_NPC
	end

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_Boy, MSGBOX_NPC
	end

LavenderTown_EventScript_Woman2::
	msgbox LavenderTown_Text_Woman2, MSGBOX_NPC
	end

LavenderTown_EventScript_CrushGirl::
	msgbox LavenderTown_Text_CrushGirl, MSGBOX_NPC
	end

LavenderTown_EventScript_Trigger1::
	call_if_set 0x11DE, LavenderTown_EventScript_Trigger1_1
	setflag 0x11DD
	release
	end

LavenderTown_EventScript_Trigger1_1::
	release
	end

LavenderTown_EventScript_Trigger6::
	call_if_set 0x11E1, LavenderTown_EventScript_Trigger6_1
	call_if_unset 0x11E0, LavenderTown_EventScript_Trigger6_1
	applymovement LOCALID_PLAYER, LavenderTown_Movement_Trigger6_1
	delay 32
	msgbox LavenderTown_Text_Trigger6_1, MSGBOX_NPC
	msgbox LavenderTown_Text_Trigger6_2, MSGBOX_NPC
	applymovement 5, LavenderTown_Movement_Trigger6_2
	delay 1
	msgbox LavenderTown_Text_Trigger6_3, MSGBOX_NPC
	setflag 0x11DD
	setflag 0x11E1
	call LavenderTown_EventScript_Trigger6_2
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_AMELIA_2, 0, LavenderTown_Text_Trigger6Defeat, LavenderTown_Text_Trigger6Victory
	msgbox LavenderTown_Text_Trigger6_4, MSGBOX_NPC
	call LavenderTown_EventScript_Trigger6_3
	delay 16
	msgbox LavenderTown_Text_Trigger6_5, MSGBOX_NPC
	applymovement 5, LavenderTown_Movement_Trigger6_3
	delay 160
	end

LavenderTown_EventScript_Trigger6_1::
	release
	end

LavenderTown_EventScript_Trigger6_2::
	setvar 0x7030, 0x129
	setvar 0x7033, 0x12B
	release
	return

LavenderTown_EventScript_Trigger6_3::
	setvar 0x7030, 0x129
	setvar 0x7033, 0x10A
	release
	return

LavenderTown_Movement_Trigger6_1::
	walk_down
	walk_down
	step_end

LavenderTown_Movement_Trigger6_2::
	face_up
	step_end

LavenderTown_Movement_Trigger6_3::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	set_invisible
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	step_end

LavenderTown_EventScript_Sign1::
	msgbox LavenderTown_Text_Sign1, MSGBOX_AUTOCLOSE
	end

LavenderTown_EventScript_Sign2::
	msgbox LavenderTown_Text_Sign2, MSGBOX_AUTOCLOSE
	end

LavenderTown_EventScript_Sign3::
	msgbox LavenderTown_Text_Sign3, MSGBOX_AUTOCLOSE
	end

LavenderTown_EventScript_Sign4::
	msgbox LavenderTown_Text_Sign4, MSGBOX_AUTOCLOSE
	end
