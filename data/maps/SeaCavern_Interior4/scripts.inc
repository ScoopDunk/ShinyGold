SeaCavern_Interior4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeaCavern_Interior4_OnTransition
	.byte 0

SeaCavern_Interior4_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SEVEN_ISLAND_SEVAULT_CANYON_TANOBY_KEY
	call_if_set FLAG_SYS_UNLOCKED_TANOBY_RUINS, SeaCavern_Interior4_EventScript_OnTransition_1
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	end

SeaCavern_Interior4_EventScript_OnTransition_1::
	setobjectxyperm 1, 7, 2
	setobjectxyperm 2, 4, 4
	setobjectxyperm 3, 10, 4
	setobjectxyperm 4, 5, 6
	setobjectxyperm 5, 9, 6
	setobjectxyperm 6, 5, 8
	setobjectxyperm 7, 9, 8
	return

SeaCavern_Interior4_EventScript_ItemYellowFlute::
	finditem ITEM_YELLOW_FLUTE
	end

SeaCavern_Interior4_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

SeaCavern_Interior4_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

SeaCavern_Interior4_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

SeaCavern_Interior4_EventScript_ItemIron::
	finditem ITEM_IRON
	end

SeaCavern_Interior4_EventScript_Trigger1::
	warp MAP_SS_AQUA_INTERIOR5, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SeaCavern_Interior4_EventScript_Trigger2::
	warp MAP_SEA_CAVERN_INTERIOR1, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SeaCavern_Interior4_EventScript_Trigger3::
	warp MAP_SEA_CAVERN_INTERIOR4, 3, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SeaCavern_Interior4_EventScript_Trigger4::
	warp MAP_SEA_CAVERN_INTERIOR4, 2, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SeaCavern_Interior4_EventScript_Trigger5::
	warp MAP_SEA_CAVERN_INTERIOR4, 5, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SeaCavern_Interior4_EventScript_Trigger6::
	warp MAP_SEA_CAVERN_INTERIOR4, 4, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SeaCavern_Interior4_EventScript_Trigger7::
	warp MAP_SEA_CAVERN_INTERIOR4, 7, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SeaCavern_Interior4_EventScript_Trigger8::
	warp MAP_SEA_CAVERN_INTERIOR4, 6, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SeaCavern_Interior4_EventScript_Trigger9::
	warp MAP_SEA_CAVERN_INTERIOR4, 9, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SeaCavern_Interior4_EventScript_Trigger10::
	warp MAP_SEA_CAVERN_INTERIOR4, 8, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SeaCavern_Interior4_EventScript_Trigger11::
	warp MAP_SEA_CAVERN_INTERIOR4, 11, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SeaCavern_Interior4_EventScript_Trigger12::
	warp MAP_SEA_CAVERN_INTERIOR4, 10, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)
