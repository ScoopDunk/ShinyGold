GoldenrodCity_Interior7_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

GoldenrodCity_Interior7_EventScript_Gentleman::
	msgbox GoldenrodCity_Interior7_Text_Gentleman, MSGBOX_NPC
	end

GoldenrodCity_Interior7_EventScript_MgDeliveryman::
	call_if_set 0x1185, GoldenrodCity_Interior7_EventScript_MgDeliveryman_1
	msgbox GoldenrodCity_Interior7_Text_MgDeliveryman_1, MSGBOX_NPC
	end

GoldenrodCity_Interior7_EventScript_MgDeliveryman_1::
	msgbox GoldenrodCity_Interior7_Text_MgDeliveryman_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, GoldenrodCity_Interior7_EventScript_MgDeliveryman_2
	msgbox GoldenrodCity_Interior7_Text_MgDeliveryman_3, MSGBOX_NPC
	end

GoldenrodCity_Interior7_EventScript_MgDeliveryman_2::
	call_if_set 0x11CF, GoldenrodCity_Interior7_EventScript_MgDeliveryman_3
	msgbox GoldenrodCity_Interior7_Text_MgDeliveryman_4, MSGBOX_NPC
	end

GoldenrodCity_Interior7_EventScript_MgDeliveryman_3::
	call CeruleanCity_EventScript_Trigger1
	msgbox GoldenrodCity_Interior7_Text_MgDeliveryman_5, MSGBOX_NPC
	applymovement 4, GoldenrodCity_Interior7_Movement_MgDeliveryman_1
	delay 1
	applymovement LOCALID_PLAYER, GoldenrodCity_Interior7_Movement_MgDeliveryman_2
	delay 128
	fadescreen FADE_TO_BLACK
	playbgm MUS_HALL_OF_FAME, 51
	applymovement LOCALID_PLAYER, GoldenrodCity_Interior7_Movement_MgDeliveryman_3
	delay 240
	delay 32
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_PLAYER, GoldenrodCity_Interior7_Movement_MgDeliveryman_4
	delay 208
	warp MAP_SAFFRON_CITY_INTERIOR10, 1, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior7_Movement_MgDeliveryman_1::
	walk_up
	walk_up
	walk_left
	face_right
	step_end

GoldenrodCity_Interior7_Movement_MgDeliveryman_2::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

GoldenrodCity_Interior7_Movement_MgDeliveryman_3::
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

GoldenrodCity_Interior7_Movement_MgDeliveryman_4::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

GoldenrodCity_Interior7_EventScript_Trigger::
	applymovement LOCALID_PLAYER, GoldenrodCity_Interior7_Movement_Trigger_1
	delay 80
	applymovement 4, GoldenrodCity_Interior7_Movement_Trigger_2
	delay 1
	applymovement LOCALID_PLAYER, GoldenrodCity_Interior7_Movement_Trigger_3
	delay 48
	applymovement 4, GoldenrodCity_Interior7_Movement_Trigger_4
	delay 48
	msgbox GoldenrodCity_Interior7_Text_Trigger, MSGBOX_NPC
	end

GoldenrodCity_Interior7_Movement_Trigger_1::
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

GoldenrodCity_Interior7_Movement_Trigger_2::
	walk_down
	walk_left
	face_right
	step_end

GoldenrodCity_Interior7_Movement_Trigger_3::
	walk_down
	walk_down
	walk_down
	face_up
	step_end

GoldenrodCity_Interior7_Movement_Trigger_4::
	walk_right
	walk_up
	face_down_fast
	step_end
