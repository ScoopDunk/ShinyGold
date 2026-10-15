Route43_Interior1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Route43_Interior1_EventScript_RocketM::
	msgbox Route43_Interior1_Text_RocketM, MSGBOX_NPC
	end

Route43_Interior1_EventScript_MgDeliveryman::
	call_if_set 0x1108, Route43_Interior1_EventScript_MgDeliveryman_1
	setflag 0x1108
	msgbox Route43_Interior1_Text_MgDeliveryman_1, MSGBOX_NPC
	giveitem ITEM_TM36
	releaseall
	end

Route43_Interior1_EventScript_MgDeliveryman_1::
	msgbox Route43_Interior1_Text_MgDeliveryman_2, MSGBOX_NPC
	end

Route43_Interior1_EventScript_Trigger1::
	call_if_unset 0x10D6, MahoganyTown_Interior1_EventScript_OldAmber
	applymovement 1, Route43_Interior1_Movement_Trigger1_1
	delay 48
	playbgm MUS_SILPH, 51
	applymovement LOCALID_PLAYER, Route43_Interior1_Movement_Trigger1_2
	applymovement 1, Route43_Interior1_Movement_Trigger1_3
	applymovement 2, Route43_Interior1_Movement_Trigger1_4
	delay 48
	call Route43_Interior1_EventScript_Trigger1_1
	applymovement 1, Route43_Interior1_Movement_Trigger1_5
	applymovement 2, Route43_Interior1_Movement_Trigger1_6
	delay 32
	playbgm MUS_SEVII_ROUTE, 51
	end

Route43_Interior1_EventScript_Trigger1_1::
	msgbox Route43_Interior1_Text_Trigger1_1, MSGBOX_NPC
	checkmoney 0x3E8
	goto_if_eq VAR_RESULT, 0, Route43_Interior1_EventScript_Trigger1_2
	removemoney 0x3E8
	updatemoneybox
	msgbox Route43_Interior1_Text_Trigger1_2, MSGBOX_NPC
	clearflag 0x10D6
	return

Route43_Interior1_Movement_Trigger1_1::
	emote_exclamation_mark
	step_end

Route43_Interior1_Movement_Trigger1_2::
	walk_right
	walk_up
	step_end

Route43_Interior1_Movement_Trigger1_3::
	walk_fast_right
	walk_fast_down
	step_end

Route43_Interior1_Movement_Trigger1_4::
	walk_fast_down
	walk_fast_down
	step_end

Route43_Interior1_EventScript_Trigger1_2::
	msgbox Route43_Interior1_Text_Trigger1_3, MSGBOX_NPC
	removemoney 0x3E8
	updatemoneybox
	clearflag 0x10D6
	return

Route43_Interior1_Movement_Trigger1_5::
	walk_fast_up
	walk_fast_left
	face_down_fast
	step_end

Route43_Interior1_Movement_Trigger1_6::
	walk_fast_up
	walk_fast_up
	step_end

Route43_Interior1_EventScript_Trigger2::
	call_if_unset 0x10D6, MahoganyTown_Interior1_EventScript_OldAmber
	applymovement 1, Route43_Interior1_Movement_Trigger1_1
	delay 48
	playbgm MUS_SILPH, 51
	applymovement 1, Route43_Interior1_Movement_Trigger1_3
	applymovement 2, Route43_Interior1_Movement_Trigger1_4
	delay 48
	call Route43_Interior1_EventScript_Trigger1_1
	applymovement 1, Route43_Interior1_Movement_Trigger1_5
	applymovement 2, Route43_Interior1_Movement_Trigger1_6
	delay 32
	playbgm MUS_SEVII_ROUTE, 51
	end

Route43_Interior1_EventScript_Trigger3::
	call_if_unset 0x10D6, MahoganyTown_Interior1_EventScript_OldAmber
	applymovement 1, Route43_Interior1_Movement_Trigger1_1
	delay 48
	playbgm MUS_SILPH, 51
	applymovement LOCALID_PLAYER, Route43_Interior1_Movement_Trigger3
	applymovement 1, Route43_Interior1_Movement_Trigger1_3
	applymovement 2, Route43_Interior1_Movement_Trigger1_4
	delay 48
	call Route43_Interior1_EventScript_Trigger1_1
	applymovement 1, Route43_Interior1_Movement_Trigger1_5
	applymovement 2, Route43_Interior1_Movement_Trigger1_6
	delay 32
	playbgm MUS_SEVII_ROUTE, 51
	end

Route43_Interior1_Movement_Trigger3::
	walk_left
	walk_up
	step_end

Route43_Interior1_EventScript_Trigger4::
	call_if_unset 0x10D6, MahoganyTown_Interior1_EventScript_OldAmber
	applymovement 2, Route43_Interior1_Movement_Trigger1_1
	delay 48
	playbgm MUS_SILPH, 51
	applymovement LOCALID_PLAYER, Route43_Interior1_Movement_Trigger4_1
	applymovement 2, Route43_Interior1_Movement_Trigger4_2
	applymovement 1, Route43_Interior1_Movement_Trigger1_6
	delay 48
	call Route43_Interior1_EventScript_Trigger1_1
	applymovement 2, Route43_Interior1_Movement_Trigger4_3
	applymovement 1, Route43_Interior1_Movement_Trigger1_4
	delay 32
	playbgm MUS_SEVII_ROUTE, 51
	end

Route43_Interior1_Movement_Trigger4_1::
	walk_right
	walk_down
	step_end

Route43_Interior1_Movement_Trigger4_2::
	walk_fast_left
	walk_fast_up
	step_end

Route43_Interior1_Movement_Trigger4_3::
	walk_fast_down
	walk_fast_right
	face_up
	step_end

Route43_Interior1_EventScript_Trigger5::
	call_if_unset 0x10D6, MahoganyTown_Interior1_EventScript_OldAmber
	applymovement 2, Route43_Interior1_Movement_Trigger1_1
	delay 48
	playbgm MUS_SILPH, 51
	applymovement 2, Route43_Interior1_Movement_Trigger4_2
	applymovement 1, Route43_Interior1_Movement_Trigger1_6
	delay 48
	call Route43_Interior1_EventScript_Trigger1_1
	applymovement 2, Route43_Interior1_Movement_Trigger4_3
	applymovement 1, Route43_Interior1_Movement_Trigger1_4
	delay 32
	playbgm MUS_SEVII_ROUTE, 51
	end

Route43_Interior1_EventScript_Trigger6::
	call_if_unset 0x10D6, MahoganyTown_Interior1_EventScript_OldAmber
	applymovement 2, Route43_Interior1_Movement_Trigger1_1
	delay 48
	playbgm MUS_SILPH, 51
	applymovement LOCALID_PLAYER, Route43_Interior1_Movement_Trigger6
	applymovement 2, Route43_Interior1_Movement_Trigger4_2
	applymovement 1, Route43_Interior1_Movement_Trigger1_6
	delay 48
	call Route43_Interior1_EventScript_Trigger1_1
	applymovement 2, Route43_Interior1_Movement_Trigger4_3
	applymovement 1, Route43_Interior1_Movement_Trigger1_4
	delay 32
	playbgm MUS_SEVII_ROUTE, 51
	end

Route43_Interior1_Movement_Trigger6::
	walk_left
	walk_down
	step_end
