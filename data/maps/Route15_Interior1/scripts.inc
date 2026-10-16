Route15_Interior1_MapScripts::
	.byte 0

Route15_Interior1_EventScript_Policeman::
	msgbox Route15_Interior1_Text_Policeman, MSGBOX_NPC
	end

Route15_Interior1_EventScript_Trigger1::
	call_if_set 0x11F5, Route15_Interior1_EventScript_Trigger1_1
	call_if_unset 0x11F3, Route15_Interior1_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Route15_Interior1_Movement_Trigger1_1
	delay 16
	call Route15_Interior1_EventScript_Trigger4
	end

Route15_Interior1_EventScript_Trigger1_1::
	release
	end

Route15_Interior1_EventScript_Trigger4::
	@ ShinyGold: overlapping data duplicated from 0x0887F476
	call_if_set 0x11F5, Route15_Interior1_EventScript_Trigger1_1
	call_if_unset 0x11F3, Route15_Interior1_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Route15_Interior1_Movement_Trigger1_2
	applymovement 2, Route15_Interior1_Movement_Trigger1_3
	delay 48
	warp MAP_ROUTE15, 1, 0x26C, 0x1DFF
	end

Route15_Interior1_Movement_Trigger1_1::
	walk_fast_down
	walk_fast_right
	step_end

Route15_Interior1_Movement_Trigger1_2::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route15_Interior1_Movement_Trigger1_3::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	set_invisible
	walk_fast_right
	walk_fast_right
	step_end

Route15_Interior1_EventScript_Trigger2::
	call_if_set 0x11F5, Route15_Interior1_EventScript_Trigger1_1
	call_if_unset 0x11F3, Route15_Interior1_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Route15_Movement_Trigger1_1
	delay 16
	call Route15_Interior1_EventScript_Trigger4
	end

Route15_Interior1_EventScript_Trigger3::
	call_if_set 0x11F5, Route15_Interior1_EventScript_Trigger1_1
	call_if_unset 0x11F3, Route15_Interior1_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Route15_Movement_Trigger2
	delay 16
	call Route15_Interior1_EventScript_Trigger4
	end
