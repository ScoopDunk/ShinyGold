SSAqua_Interior2_MapScripts::
	.byte 0

@ Pure Gold/Silver: the sailor at the gangway lets the player off once the ship has arrived
@ (pokegold FastShip1F.asm, FastShip1FSailor1Script)
SSAqua_Interior2_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set 0x11A9, SSAqua_Interior2_EventScript_Sailor_1
	goto_if_set 0x1164, SSAqua_Interior2_EventScript_Sailor_2
	msgbox SSAqua_Interior2_Text_Sailor_1
	release
	end

SSAqua_Interior2_EventScript_Sailor_1::
	goto_if_unset 0x1165, SSAqua_Interior2_EventScript_Sailor_3
	msgbox SSAqua_Interior2_Text_Sailor_2
	closemessage
	call SSAqua_Interior2_EventScript_Sailor_4
	warp MAP_OLIVINE_CITY_AREA1, 1
	waitstate
	release
	end

SSAqua_Interior2_EventScript_Sailor_2::
	goto_if_set 0x1165, SSAqua_Interior2_EventScript_Sailor_5
	msgbox SSAqua_Interior2_Text_Sailor_3
	release
	end

SSAqua_Interior2_EventScript_Sailor_3::
	msgbox SSAqua_Interior2_Text_Sailor_4
	closemessage
	call SSAqua_Interior2_EventScript_Sailor_6
	setflag 0x1177
	warp MAP_VERMILION_CITY_AREA1, 1
	waitstate
	release
	end

@ Arrival in OLIVINE CITY: the westbound passengers can be battled again on the next trip
SSAqua_Interior2_EventScript_Sailor_4::
	setflag 0x1196
	setflag 0x1197
	setflag 0x1198
	setflag 0x1199
	setflag 0x119A
	setflag 0x119B
	setflag 0x119C
	setflag 0x119D
	setflag 0x119E
	setflag 0x119F
	clearflag 0x1165
	return

SSAqua_Interior2_EventScript_Sailor_5::
	msgbox SSAqua_Interior2_Text_Sailor_5
	release
	end

@ Arrival in VERMILION CITY: the eastbound passengers can be battled again on the next trip
SSAqua_Interior2_EventScript_Sailor_6::
	setflag 0x11A0
	setflag 0x11A1
	setflag 0x11A2
	setflag 0x11A3
	setflag 0x11A4
	setflag 0x11A5
	setflag 0x11A6
	setflag 0x11A7
	setflag 0x11A8
	return

SSAqua_Interior2_EventScript_Gentleman::
	msgbox SSAqua_Interior2_Text_Gentleman, MSGBOX_NPC
	end

SSAqua_Interior2_EventScript_Sailor2::
	goto_if_set 0x1177, SSAqua_Interior2_EventScript_Sailor2_1
	msgbox SSAqua_Interior2_Text_Sailor2, MSGBOX_NPC
	end

SSAqua_Interior2_EventScript_Sailor2_1::
	msgbox SSAqua_Interior2_Text_Sailor2_2, MSGBOX_NPC
	end

SSAqua_Interior2_EventScript_Sailor3::
	msgbox SSAqua_Interior2_Text_Sailor3, MSGBOX_NPC
	end

SSAqua_Interior2_EventScript_Trigger1::
	call_if_set 0x1164, SSAqua_Interior2_EventScript_Trigger1_1
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 9
	setvar VAR_0x8007, 2
	special ShakeScreen
	delay 30
	playfanfare MUS_DUMMY
	setflag 0x1164
	call_if_set 0x1165, SSAqua_Interior2_EventScript_Trigger1_2
	msgbox SSAqua_Interior2_Text_Trigger1_1, MSGBOX_AUTOCLOSE
	call SSAqua_Interior2_EventScript_Trigger1_3
	end

SSAqua_Interior2_EventScript_Trigger1_1::
	release
	end

SSAqua_Interior2_EventScript_Trigger1_2::
	msgbox SSAqua_Interior2_Text_Trigger1_2, MSGBOX_AUTOCLOSE
	call SSAqua_Interior2_EventScript_Trigger1_3
	end

SSAqua_Interior2_EventScript_Trigger1_3::
	call_if_unset 0x1177, SSAqua_Interior2_EventScript_Trigger1_4
	call_if_unset 0x1165, SSAqua_Interior2_EventScript_Trigger1_5
	call_if_set 0x1165, SSAqua_Interior2_EventScript_Trigger1_6
	end

SSAqua_Interior2_EventScript_Trigger1_4::
	clearflag 0x1176
	setflag 0x1174
	setflag 0x1175
	end

SSAqua_Interior2_EventScript_Trigger1_5::
	clearflag 0x1174
	setflag 0x1175
	setflag 0x1176
	end

SSAqua_Interior2_EventScript_Trigger1_6::
	clearflag 0x1175
	setflag 0x1174
	setflag 0x1176
	end

SSAqua_Interior2_EventScript_Trigger4::
	call_if_set 0x1166, SSAqua_Interior2_EventScript_Trigger4_1
	applymovement 2, SSAqua_Interior2_Movement_Trigger4_1
	delay 58
	applymovement LOCALID_PLAYER, SSAqua_Interior2_Movement_Trigger4_2
	delay 1
	applymovement 2, SSAqua_Interior2_Movement_Trigger4_2
	delay 32
	call SSAqua_Interior2_EventScript_Trigger4_2
	end

SSAqua_Interior2_EventScript_Trigger4_1::
	release
	end

@ Pure Gold/Silver: the worried grandpa bumps into the player and runs off (pokegold FastShip1F.asm, WorriedGrandpaScene)
SSAqua_Interior2_EventScript_Trigger4_2::
	applymovement LOCALID_PLAYER, SSAqua_Interior2_Movement_Trigger4_3
	waitmovement 0
	msgbox SSAqua_Interior2_Text_Trigger4_1
	closemessage
	applymovement LOCALID_PLAYER, SSAqua_Interior2_Movement_Trigger4_4
	applymovement 2, SSAqua_Interior2_Movement_Trigger4_7
	waitmovement 2
	removeobject 2
	setflag 0x1166
	release
	end

SSAqua_Interior2_Movement_Trigger4_1::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_Interior2_Movement_Trigger4_2::
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_Interior2_Movement_Trigger4_3::
	face_left
	step_end

SSAqua_Interior2_Movement_Trigger4_4::
	face_right
	step_end

SSAqua_Interior2_Movement_Trigger4_7::
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	set_invisible
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_Interior2_EventScript_Trigger5::
	call_if_set 0x1166, SSAqua_Interior2_EventScript_Trigger4_1
	applymovement 2, SSAqua_Interior2_Movement_Trigger5
	delay 66
	applymovement LOCALID_PLAYER, SSAqua_Interior2_Movement_Trigger4_2
	delay 1
	applymovement 2, SSAqua_Interior2_Movement_Trigger4_2
	delay 32
	call SSAqua_Interior2_EventScript_Trigger4_2
	end

SSAqua_Interior2_Movement_Trigger5::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end
