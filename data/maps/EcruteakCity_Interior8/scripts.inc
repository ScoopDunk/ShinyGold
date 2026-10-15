EcruteakCity_Interior8_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

EcruteakCity_Interior8_EventScript_OldMan1::
	checkitem ITEM_AURORA_TICKET
	call_if_eq VAR_RESULT, 1, EcruteakCity_Interior8_EventScript_OldMan1_1
	msgbox EcruteakCity_Interior8_Text_OldMan1_1, MSGBOX_NPC
	end

EcruteakCity_Interior8_EventScript_OldMan1_1::
	setflag 0x1040
	msgbox EcruteakCity_Interior8_Text_OldMan1_2, MSGBOX_NPC
	applymovement 1, EcruteakCity_Interior8_Movement_OldMan1
	delay 16
	end

EcruteakCity_Interior8_Movement_OldMan1::
	face_up
	set_invisible
	walk_fast_up
	walk_fast_up
	step_end

EcruteakCity_Interior8_EventScript_Trigger::
	warp MAP_UNUSED_G34_M52, 0, 0x3402, 0x3900
	compare_var_to_var 0x0126, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)
