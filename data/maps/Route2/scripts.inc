Route2_MapScripts::
	.byte 0

Route2_EventScript_Trigger1::
	call_if_set 0x11EF, Route2_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Route2_Movement_Trigger1_1
	delay 32
	call Route2_EventScript_Trigger1_2
	end

Route2_EventScript_Trigger1_1::
	release
	end

Route2_EventScript_Trigger1_2::
	msgbox Route2_Text_Trigger1_1, MSGBOX_NPC
	applymovement 8, Route2_Movement_Trigger1_2
	delay 1
	playbgm MUS_ENCOUNTER_BOY, 51
	delay 32
	msgbox Route2_Text_Trigger1_2, MSGBOX_NPC
	delay 32
	msgbox Route2_Text_Trigger1_3, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_PKMN_THIEF_ASHLEE, 0, Route2_Text_Trigger1Defeat, Route2_Text_Trigger1Victory
	setflag 0x11EF
	playbgm MUS_ENCOUNTER_BOY, 51
	msgbox Route2_Text_Trigger1_4, MSGBOX_NPC
	applymovement 8, Route2_Movement_Trigger1_3
	delay 5
	applymovement 9, Route2_Movement_Trigger1_3
	delay 144
	playbgm MUS_ROUTE1, 51
	release
	end

Route2_Movement_Trigger1_1::
	walk_right
	walk_right
	step_end

Route2_Movement_Trigger1_2::
	face_left
	step_end

Route2_Movement_Trigger1_3::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
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

Route2_EventScript_Trigger2::
	call_if_set 0x11EF, Route2_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Route2_Movement_Trigger2
	delay 32
	call Route2_EventScript_Trigger1_2
	end

Route2_Movement_Trigger2::
	walk_up
	walk_right
	step_end

Route2_EventScript_Trigger3::
	call_if_set 0x11EF, Route2_EventScript_Trigger1_1
	call Route2_EventScript_Trigger1_2
	end
