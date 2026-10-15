SaffronCity_Interior10_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

SaffronCity_Interior10_EventScript_Woman3::
	msgbox SaffronCity_Interior10_Text_Woman3, MSGBOX_NPC
	end

SaffronCity_Interior10_EventScript_Scientist::
	call_if_set 0x1185, SaffronCity_Interior10_EventScript_Scientist_1
	msgbox SaffronCity_Interior10_Text_Scientist_1, MSGBOX_NPC
	end

SaffronCity_Interior10_EventScript_Scientist_1::
	msgbox SaffronCity_Interior10_Text_Scientist_2, MSGBOX_NPC
	end

SaffronCity_Interior10_EventScript_Woman1::
	msgbox SaffronCity_Interior10_Text_Woman1, MSGBOX_NPC
	end

SaffronCity_Interior10_EventScript_MgDeliveryman::
	call_if_set 0x1185, SaffronCity_Interior10_EventScript_MgDeliveryman_1
	msgbox SaffronCity_Interior10_Text_MgDeliveryman_1, MSGBOX_NPC
	end

SaffronCity_Interior10_EventScript_MgDeliveryman_1::
	msgbox SaffronCity_Interior10_Text_MgDeliveryman_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, SaffronCity_Interior10_EventScript_MgDeliveryman_2
	msgbox GoldenrodCity_Interior7_Text_MgDeliveryman_3, MSGBOX_NPC
	end

SaffronCity_Interior10_EventScript_MgDeliveryman_2::
	call_if_set 0x11CF, SaffronCity_Interior10_EventScript_MgDeliveryman_3
	msgbox GoldenrodCity_Interior7_Text_MgDeliveryman_4, MSGBOX_NPC
	end

SaffronCity_Interior10_EventScript_MgDeliveryman_3::
	call IndigoPlateau_EventScript_Trigger1
	msgbox GoldenrodCity_Interior7_Text_MgDeliveryman_5, MSGBOX_NPC
	applymovement 4, GoldenrodCity_Interior7_Movement_MgDeliveryman_1
	delay 1
	applymovement LOCALID_PLAYER, GoldenrodCity_Interior7_Movement_MgDeliveryman_2
	delay 128
	fadescreen FADE_TO_BLACK
	playbgm MUS_HALL_OF_FAME, 51
	applymovement LOCALID_PLAYER, SaffronCity_Interior10_Movement_MgDeliveryman_1
	delay 144
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_PLAYER, SaffronCity_Interior10_Movement_MgDeliveryman_2
	delay 208
	warp MAP_GOLDENROD_CITY_INTERIOR7, 1, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SaffronCity_Interior10_Movement_MgDeliveryman_1::
	set_invisible
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

SaffronCity_Interior10_Movement_MgDeliveryman_2::
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

SaffronCity_Interior10_EventScript_Trigger::
	applymovement LOCALID_PLAYER, GoldenrodCity_Interior7_Movement_Trigger_1
	delay 80
	applymovement 4, GoldenrodCity_Interior7_Movement_Trigger_2
	delay 1
	applymovement LOCALID_PLAYER, GoldenrodCity_Interior7_Movement_Trigger_3
	delay 48
	applymovement 4, GoldenrodCity_Interior7_Movement_Trigger_4
	delay 48
	msgbox SaffronCity_Interior10_Text_Trigger, MSGBOX_NPC
	end
