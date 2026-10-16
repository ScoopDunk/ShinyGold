TinTower_UpperFloors_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

TinTower_UpperFloors_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

TinTower_UpperFloors_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

TinTower_UpperFloors_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

TinTower_UpperFloors_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

TinTower_UpperFloors_EventScript_ItemSuperPotion::
	finditem ITEM_SUPER_POTION
	end

TinTower_UpperFloors_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

TinTower_UpperFloors_EventScript_ItemCarbos::
	finditem ITEM_CARBOS
	end

TinTower_UpperFloors_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

TinTower_UpperFloors_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

TinTower_UpperFloors_EventScript_ItemNugget::
	finditem ITEM_NUGGET
	end

TinTower_UpperFloors_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

TinTower_UpperFloors_EventScript_ItemFullRestore2::
	finditem ITEM_FULL_RESTORE
	end

TinTower_UpperFloors_EventScript_Trigger1::
	@ ShinyGold: overlapping data duplicated from 0x0878AD17
	warp MAP_ECRUTEAK_CITY_INTERIOR8, 1, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger2::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 3, 0xFF02, 0x39FF
	compare_var_to_var 0x0134, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger3::
	@ ShinyGold: overlapping data duplicated from 0x0878AD27
	warp MAP_TIN_TOWER_UPPER_FLOORS, 1, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger4::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 4, 0xFF02, 0x39FF
	compare_var_to_var 0x0234, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger5::
	@ ShinyGold: overlapping data duplicated from 0x0878AD37
	warp MAP_TIN_TOWER_UPPER_FLOORS, 2, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger6::
	applymovement LOCALID_PLAYER, TinTower_UpperFloors_Movement_Trigger6
	delay 32
	end

TinTower_UpperFloors_Movement_Trigger6::
	jump_2_right
	step_end

TinTower_UpperFloors_EventScript_Trigger8::
	applymovement LOCALID_PLAYER, TinTower_UpperFloors_Movement_Trigger8
	delay 32
	end

TinTower_UpperFloors_Movement_Trigger8::
	jump_2_left
	step_end

TinTower_UpperFloors_EventScript_Trigger13::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 8, 0xFF02, 0x39FF
	compare_var_to_var 0x0534, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger14::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 9, 0xFF02, 0x39FF
	compare_var_to_var 0x0634, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger15::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 10, 0xFF02, 0x39FF
	compare_var_to_var 0x0734, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger16::
	applymovement LOCALID_PLAYER, TinTower_UpperFloors_Movement_Trigger16
	delay 32
	end

TinTower_UpperFloors_Movement_Trigger16::
	jump_2_down
	step_end

TinTower_UpperFloors_EventScript_Trigger25::
	@ ShinyGold: overlapping data duplicated from 0x0878AD47
	warp MAP_TIN_TOWER_UPPER_FLOORS, 5, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger26::
	@ ShinyGold: overlapping data duplicated from 0x0878AD57
	warp MAP_TIN_TOWER_UPPER_FLOORS, 6, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger27::
	@ ShinyGold: overlapping data duplicated from 0x0878AD67
	warp MAP_TIN_TOWER_UPPER_FLOORS, 7, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger28::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 12, 0xFF02, 0x39FF
	compare_var_to_var 0x0B34, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger46::
	@ ShinyGold: overlapping data duplicated from 0x0878AD77
	warp MAP_TIN_TOWER_UPPER_FLOORS, 11, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger47::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 14, 0xFF02, 0x39FF
	compare_var_to_var 0x0D34, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger50::
	@ ShinyGold: overlapping data duplicated from 0x0878AD87
	warp MAP_TIN_TOWER_UPPER_FLOORS, 13, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger51::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 16, 0xFF02, 0x39FF
	compare_var_to_var 0x0F34, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger52::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 19, 0xFF02, 0x39FF
	compare_var_to_var 0x1134, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger53::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 20, 0xFF02, 0x39FF
	compare_var_to_var 0x1234, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger54::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 22, 0xFF02, 0x39FF
	compare_var_to_var 0x1534, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger61::
	@ ShinyGold: overlapping data duplicated from 0x0878ADA7
	warp MAP_TIN_TOWER_UPPER_FLOORS, 17, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger62::
	@ ShinyGold: overlapping data duplicated from 0x0878ADC7
	warp MAP_TIN_TOWER_UPPER_FLOORS, 21, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger63::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 24, 0xFF02, 0x39FF
	compare_var_to_var 0x1734, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger64::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 26, 0xFF02, 0x39FF
	compare_var_to_var 0x1934, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger65::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 29, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger70::
	@ ShinyGold: overlapping data duplicated from 0x0878AD97
	warp MAP_TIN_TOWER_UPPER_FLOORS, 15, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger71::
	@ ShinyGold: overlapping data duplicated from 0x0878ADB7
	warp MAP_TIN_TOWER_UPPER_FLOORS, 18, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger72::
	@ ShinyGold: overlapping data duplicated from 0x0878ADD7
	warp MAP_TIN_TOWER_UPPER_FLOORS, 23, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger73::
	@ ShinyGold: overlapping data duplicated from 0x0878ADE7
	warp MAP_TIN_TOWER_UPPER_FLOORS, 25, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger74::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 28, 0xFF02, 0x39FF
	compare_var_to_var 0x1B34, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger75::
	@ ShinyGold: overlapping data duplicated from 0x0878ADF7
	warp MAP_TIN_TOWER_UPPER_FLOORS, 27, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger76::
	@ ShinyGold: overlapping data duplicated from 0x0878AE00
	warp MAP_TIN_TOWER_UPPER_FLOORS, 30, 0xFF02, 0x39FF
	compare_var_to_var 0x1D34, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

TinTower_UpperFloors_EventScript_Trigger84::
	warp MAP_TIN_TOWER_ROOF, 0, 0xFF02, 0x39FF
	compare_var_to_var 0x1F34, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)
