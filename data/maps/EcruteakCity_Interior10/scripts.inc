EcruteakCity_Interior10_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_Interior10_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EcruteakCity_Interior10_OnTransition::
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY
	end

EcruteakCity_Interior10_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

EcruteakCity_Interior10_EventScript_PokeManiac::
	msgbox EcruteakCity_Interior10_Text_PokeManiac, MSGBOX_NPC
	end

EcruteakCity_Interior10_EventScript_Lass::
	msgbox EcruteakCity_Interior10_Text_Lass, MSGBOX_NPC
	end

EcruteakCity_Interior10_EventScript_BaldingMan::
	msgbox EcruteakCity_Interior10_Text_BaldingMan, MSGBOX_NPC
	end

EcruteakCity_Interior10_EventScript_Trigger1::
	call_if_set 0x10C4, EcruteakCity_Interior10_EventScript_Trigger1_1
	applymovement 5, EcruteakCity_Interior10_Movement_Trigger1_1
	delay 144
	applymovement LOCALID_PLAYER, EcruteakCity_Interior10_Movement_Trigger1_2
	delay 48
	goto EcruteakCity_Interior10_EventScript_Trigger1_2

EcruteakCity_Interior10_EventScript_Trigger1_1::
	release
	end

EcruteakCity_Interior10_EventScript_Trigger1_2::
	applymovement 5, EcruteakCity_Interior10_Movement_Trigger1_3
	clearflag 0x10C3
	setflag 0x10C4
	setflag FLAG_SYS_NOT_SOMEONES_PC
	msgbox EcruteakCity_Interior10_Text_Trigger1, MSGBOX_NPC
	applymovement LOCALID_PLAYER, EcruteakCity_Interior10_Movement_Trigger1_3
	applymovement 5, EcruteakCity_Interior10_Movement_Trigger1_4
	delay 112
	release
	end

EcruteakCity_Interior10_Movement_Trigger1_1::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

EcruteakCity_Interior10_Movement_Trigger1_2::
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

EcruteakCity_Interior10_Movement_Trigger1_3::
	face_down_fast
	step_end

EcruteakCity_Interior10_Movement_Trigger1_4::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	face_down_fast
	set_invisible
	walk_down
	walk_down
	step_end

EcruteakCity_Interior10_EventScript_Trigger2::
	call_if_set 0x10C4, EcruteakCity_Interior10_EventScript_Trigger1_1
	applymovement 5, EcruteakCity_Interior10_Movement_Trigger1_1
	delay 144
	applymovement LOCALID_PLAYER, EcruteakCity_Interior10_Movement_Trigger2
	delay 32
	goto EcruteakCity_Interior10_EventScript_Trigger1_2

EcruteakCity_Interior10_Movement_Trigger2::
	walk_up
	walk_up
	step_end

EcruteakCity_Interior10_EventScript_Trigger3::
	call_if_set 0x10C4, EcruteakCity_Interior10_EventScript_Trigger1_1
	applymovement 5, EcruteakCity_Interior10_Movement_Trigger1_1
	delay 144
	applymovement LOCALID_PLAYER, EcruteakCity_Interior10_Movement_Trigger3
	delay 48
	goto EcruteakCity_Interior10_EventScript_Trigger1_2

EcruteakCity_Interior10_Movement_Trigger3::
	walk_left
	walk_up
	walk_up
	walk_up
	step_end
