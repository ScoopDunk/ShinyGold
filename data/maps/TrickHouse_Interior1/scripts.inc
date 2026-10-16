TrickHouse_Interior1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

TrickHouse_Interior1_EventScript_BaldingMan::
	call_if_unset 0x1205, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set FLAG_BADGE02_GET, TrickHouse_Interior1_EventScript_BaldingMan_2
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_EventScript_BaldingMan_1::
	msgbox TrickHouse_Interior1_Text_BaldingMan_1, MSGBOX_NPC
	applymovement 1, TrickHouse_Interior1_Movement_BaldingMan_1
	delay 16
	msgbox TrickHouse_Interior1_Text_BaldingMan_2, MSGBOX_NPC
	applymovement 1, TrickHouse_Interior1_Movement_BaldingMan_2
	delay 48
	release
	end

TrickHouse_Interior1_EventScript_BaldingMan_2::
	call_if_unset 0x1206, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set FLAG_BADGE04_GET, TrickHouse_Interior1_EventScript_BaldingMan_4
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_EventScript_BaldingMan_3::
	msgbox TrickHouse_Interior1_Text_BaldingMan_3, MSGBOX_NPC
	end

TrickHouse_Interior1_EventScript_BaldingMan_4::
	call_if_unset 0x1207, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set FLAG_BADGE05_GET, TrickHouse_Interior1_EventScript_BaldingMan_5
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_Movement_BaldingMan_1::
	jump_in_place_down
	set_invisible
	step_end

TrickHouse_Interior1_Movement_BaldingMan_2::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

TrickHouse_Interior1_EventScript_BaldingMan_5::
	call_if_unset 0x1208, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set FLAG_BADGE06_GET, TrickHouse_Interior1_EventScript_BaldingMan_6
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_EventScript_BaldingMan_6::
	call_if_unset 0x1209, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set FLAG_BADGE08_GET, TrickHouse_Interior1_EventScript_BaldingMan_7
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_EventScript_BaldingMan_7::
	call_if_unset 0x120A, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set FLAG_BADGE07_GET, TrickHouse_Interior1_EventScript_BaldingMan_8
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_EventScript_BaldingMan_8::
	call_if_unset 0x120B, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set 0x115F, TrickHouse_Interior1_EventScript_BaldingMan_9
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_EventScript_BaldingMan_9::
	call_if_unset 0x120C, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set 0x1192, TrickHouse_Interior1_EventScript_BaldingMan_10
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_EventScript_BaldingMan_10::
	call_if_unset 0x120D, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set 0x1181, TrickHouse_Interior1_EventScript_BaldingMan_11
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_EventScript_BaldingMan_11::
	call_if_unset 0x120E, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set 0x11F7, TrickHouse_Interior1_EventScript_BaldingMan_12
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_EventScript_BaldingMan_12::
	call_if_unset 0x120F, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set 0x030, TrickHouse_Interior1_EventScript_BaldingMan_13
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_EventScript_BaldingMan_13::
	call_if_unset 0x1210, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set 0x030, TrickHouse_Interior1_EventScript_BaldingMan_14
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_EventScript_BaldingMan_14::
	call_if_unset 0x1211, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set 0x030, TrickHouse_Interior1_EventScript_BaldingMan_15
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_EventScript_BaldingMan_15::
	call_if_unset 0x1212, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set 0x030, TrickHouse_Interior1_EventScript_BaldingMan_16
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_EventScript_BaldingMan_16::
	call_if_unset 0x1213, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set 0x030, TrickHouse_Interior1_EventScript_BaldingMan_17
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_EventScript_BaldingMan_17::
	call_if_unset 0x1214, TrickHouse_Interior1_EventScript_BaldingMan_1
	call_if_set 0x030, TrickHouse_Interior1_EventScript_BaldingMan_18
	call TrickHouse_Interior1_EventScript_BaldingMan_3
	end

TrickHouse_Interior1_EventScript_BaldingMan_18::
	call_if_unset 0x1215, TrickHouse_Interior1_EventScript_BaldingMan_1
	msgbox TrickHouse_Interior1_Text_BaldingMan_4, MSGBOX_NPC
	end

TrickHouse_Interior1_EventScript_Trigger::
	call_if_set 0x1205, TrickHouse_Interior1_EventScript_Trigger_1
	warp MAP_UNUSED_G34_M72, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_1::
	call_if_set 0x1206, TrickHouse_Interior1_EventScript_Trigger_2
	warp MAP_UNUSED_G34_M73, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_2::
	call_if_set 0x1207, TrickHouse_Interior1_EventScript_Trigger_3
	warp MAP_UNUSED_G34_M74, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_3::
	call_if_set 0x1208, TrickHouse_Interior1_EventScript_Trigger_4
	warp MAP_UNUSED_G34_M76, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_4::
	call_if_set 0x1209, TrickHouse_Interior1_EventScript_Trigger_5
	warp MAP_UNUSED_G34_M75, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_5::
	call_if_set 0x120A, TrickHouse_Interior1_EventScript_Trigger_6
	warp MAP_UNUSED_G34_M77, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_6::
	call_if_set 0x120B, TrickHouse_Interior1_EventScript_Trigger_7
	warp MAP_UNUSED_G34_M78, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_7::
	call_if_set 0x120C, TrickHouse_Interior1_EventScript_Trigger_8
	warp MAP_UNUSED_G34_M82, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_8::
	call_if_set 0x120D, TrickHouse_Interior1_EventScript_Trigger_9
	warp MAP_UNUSED_G34_M79, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_9::
	call_if_set 0x120E, TrickHouse_Interior1_EventScript_Trigger_10
	warp MAP_UNUSED_G34_M80, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_10::
	call_if_set 0x120F, TrickHouse_Interior1_EventScript_Trigger_11
	warp MAP_UNUSED_G34_M81, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_11::
	call_if_set 0x1210, TrickHouse_Interior1_EventScript_Trigger_12
	warp MAP_BATTLE_COLOSSEUM_2P, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_12::
	call_if_set 0x1211, TrickHouse_Interior1_EventScript_Trigger_13
	warp MAP_BATTLE_COLOSSEUM_2P, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_13::
	call_if_set 0x1212, TrickHouse_Interior1_EventScript_Trigger_14
	warp MAP_BATTLE_COLOSSEUM_2P, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_14::
	call_if_set 0x1213, TrickHouse_Interior1_EventScript_Trigger_15
	warp MAP_BATTLE_COLOSSEUM_2P, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_15::
	call_if_set 0x1214, TrickHouse_Interior1_EventScript_Trigger_16
	warp MAP_BATTLE_COLOSSEUM_2P, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_16::
	call_if_set 0x1215, TrickHouse_Interior1_EventScript_Trigger_17
	warp MAP_BATTLE_COLOSSEUM_2P, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TrickHouse_Interior1_EventScript_Trigger_17::
	release
	end
