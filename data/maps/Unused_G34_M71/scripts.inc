Unused_G34_M71_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G34_M71_EventScript_BaldingMan::
	call_if_unset 0x1205, Unused_G34_M71_EventScript_BaldingMan_1
	call_if_unset 0x1206, Unused_G34_M71_EventScript_BaldingMan_2
	call_if_unset 0x1207, Unused_G34_M71_EventScript_BaldingMan_3
	call_if_unset 0x1208, Unused_G34_M71_EventScript_BaldingMan_4
	call_if_unset 0x1209, Unused_G34_M71_EventScript_BaldingMan_5
	call_if_unset 0x120A, Unused_G34_M71_EventScript_BaldingMan_6
	call_if_unset 0x120B, Unused_G34_M71_EventScript_BaldingMan_7
	call_if_unset 0x120C, Unused_G34_M71_EventScript_BaldingMan_8
	call_if_unset 0x120D, Unused_G34_M71_EventScript_BaldingMan_9
	call_if_unset 0x120E, Unused_G34_M71_EventScript_BaldingMan_10
	call_if_unset 0x120F, Unused_G34_M71_EventScript_BaldingMan_11
	call_if_unset 0x1210, Unused_G34_M71_EventScript_BaldingMan_12
	call_if_unset 0x1211, Unused_G34_M71_EventScript_BaldingMan_12
	call_if_unset 0x1212, Unused_G34_M71_EventScript_BaldingMan_12
	call_if_unset 0x1213, Unused_G34_M71_EventScript_BaldingMan_12
	call_if_unset 0x1214, Unused_G34_M71_EventScript_BaldingMan_12
	call_if_unset 0x1215, Unused_G34_M71_EventScript_BaldingMan_12
	release
	end

Unused_G34_M71_EventScript_BaldingMan_1::
	setflag 0x1205
	msgbox Unused_G34_M71_Text_BaldingMan_1, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_2, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_3, MSGBOX_NPC
	giveitem ITEM_GREAT_BALL
	call Unused_G34_M71_EventScript_BaldingMan_13
	end

Unused_G34_M71_EventScript_BaldingMan_2::
	setflag 0x1206
	msgbox Unused_G34_M71_Text_BaldingMan_1, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_4, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_3, MSGBOX_NPC
	giveitem ITEM_FULL_HEAL
	call Unused_G34_M71_EventScript_BaldingMan_13
	end

Unused_G34_M71_EventScript_BaldingMan_3::
	setflag 0x1207
	msgbox Unused_G34_M71_Text_BaldingMan_1, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_5, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_3, MSGBOX_NPC
	giveitem ITEM_REPEAT_BALL
	call Unused_G34_M71_EventScript_BaldingMan_13
	end

Unused_G34_M71_EventScript_BaldingMan_4::
	setflag 0x1208
	msgbox Unused_G34_M71_Text_BaldingMan_1, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_6, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_3, MSGBOX_NPC
	giveitem ITEM_FULL_RESTORE
	call Unused_G34_M71_EventScript_BaldingMan_13
	end

Unused_G34_M71_EventScript_BaldingMan_5::
	setflag 0x1209
	msgbox Unused_G34_M71_Text_BaldingMan_1, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_7, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_3, MSGBOX_NPC
	giveitem ITEM_RARE_CANDY
	call Unused_G34_M71_EventScript_BaldingMan_13
	end

Unused_G34_M71_EventScript_BaldingMan_6::
	setflag 0x120A
	msgbox Unused_G34_M71_Text_BaldingMan_1, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_8, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_3, MSGBOX_NPC
	giveitem ITEM_ZINC
	call Unused_G34_M71_EventScript_BaldingMan_13
	end

Unused_G34_M71_EventScript_BaldingMan_7::
	setflag 0x120B
	msgbox Unused_G34_M71_Text_BaldingMan_1, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_9, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_3, MSGBOX_NPC
	giveitem ITEM_LUXURY_BALL
	call Unused_G34_M71_EventScript_BaldingMan_13
	end

Unused_G34_M71_EventScript_BaldingMan_8::
	setflag 0x120C
	msgbox Unused_G34_M71_Text_BaldingMan_1, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_10, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_3, MSGBOX_NPC
	giveitem ITEM_MOON_STONE
	call Unused_G34_M71_EventScript_BaldingMan_13
	end

Unused_G34_M71_EventScript_BaldingMan_9::
	setflag 0x120D
	msgbox Unused_G34_M71_Text_BaldingMan_1, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_11, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_3, MSGBOX_NPC
	giveitem ITEM_MENTAL_HERB
	call Unused_G34_M71_EventScript_BaldingMan_13
	end

Unused_G34_M71_EventScript_BaldingMan_10::
	setflag 0x120E
	msgbox Unused_G34_M71_Text_BaldingMan_1, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_12, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_3, MSGBOX_NPC
	giveitem ITEM_HP_UP
	call Unused_G34_M71_EventScript_BaldingMan_13
	end

Unused_G34_M71_EventScript_BaldingMan_11::
	setflag 0x120F
	msgbox Unused_G34_M71_Text_BaldingMan_1, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_13, MSGBOX_NPC
	msgbox Unused_G34_M71_Text_BaldingMan_3, MSGBOX_NPC
	giveitem ITEM_LIGHT_BALL
	call Unused_G34_M71_EventScript_BaldingMan_13
	end

Unused_G34_M71_EventScript_BaldingMan_12::
	gotostd 64

Unused_G34_M71_EventScript_BaldingMan_13::
	msgbox Unused_G34_M71_Text_BaldingMan_14, MSGBOX_NPC
	applymovement 1, TrickHouse_Interior1_Movement_BaldingMan_1
	delay 16
	msgbox TrickHouse_Interior1_Text_BaldingMan_2, MSGBOX_NPC
	call Unused_G34_M71_EventScript_BaldingMan_14
	end

Unused_G34_M71_EventScript_BaldingMan_14::
	goto_if_eq VAR_FACING, 4, Unused_G34_M71_EventScript_BaldingMan_15
	goto_if_eq VAR_FACING, 1, Unused_G34_M71_EventScript_BaldingMan_16
	call Unused_G34_M71_EventScript_BaldingMan_17
	end

Unused_G34_M71_EventScript_BaldingMan_15::
	applymovement LOCALID_PLAYER, Unused_G34_M71_Movement_BaldingMan_1
	delay 89
	warp MAP_ROUTE36, 3, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M71_EventScript_BaldingMan_16::
	applymovement LOCALID_PLAYER, Unused_G34_M71_Movement_BaldingMan_2
	delay 89
	warp MAP_ROUTE36, 3, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M71_EventScript_BaldingMan_17::
	applymovement LOCALID_PLAYER, Unused_G34_M71_Movement_BaldingMan_3
	delay 62
	warp MAP_ROUTE36, 3, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M71_Movement_BaldingMan_1::
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	face_down_fast
	walk_down
	step_end

Unused_G34_M71_Movement_BaldingMan_2::
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

Unused_G34_M71_Movement_BaldingMan_3::
	walk_down
	walk_down
	walk_down
	walk_right
	face_down_fast
	step_end
