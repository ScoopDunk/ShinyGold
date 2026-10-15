Unused_G34_M52_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G34_M52_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

Unused_G34_M52_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

Unused_G34_M52_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

Unused_G34_M52_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

Unused_G34_M52_EventScript_ItemSuperPotion::
	finditem ITEM_SUPER_POTION
	end

Unused_G34_M52_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

Unused_G34_M52_EventScript_ItemCarbos::
	finditem ITEM_CARBOS
	end

Unused_G34_M52_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

Unused_G34_M52_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

Unused_G34_M52_EventScript_ItemNugget::
	finditem ITEM_NUGGET
	end

Unused_G34_M52_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

Unused_G34_M52_EventScript_ItemFullRestore2::
	finditem ITEM_FULL_RESTORE
	end

Unused_G34_M52_EventScript_Trigger1::
	@ ShinyGold: overlapping data duplicated from 0x0878AD17
	warp MAP_ECRUTEAK_CITY_INTERIOR8, 1, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger2::
	warp MAP_UNUSED_G34_M52, 3, 0xFF02, 0x39FF
	compare_var_to_var 0x0134, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger3::
	@ ShinyGold: overlapping data duplicated from 0x0878AD27
	warp MAP_UNUSED_G34_M52, 1, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger4::
	warp MAP_UNUSED_G34_M52, 4, 0xFF02, 0x39FF
	compare_var_to_var 0x0234, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger5::
	@ ShinyGold: overlapping data duplicated from 0x0878AD37
	warp MAP_UNUSED_G34_M52, 2, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger6::
	applymovement LOCALID_PLAYER, Unused_G34_M52_Movement_Trigger6
	delay 32
	end

Unused_G34_M52_Movement_Trigger6::
	jump_2_right
	step_end

Unused_G34_M52_EventScript_Trigger8::
	applymovement LOCALID_PLAYER, Unused_G34_M52_Movement_Trigger8
	delay 32
	end

Unused_G34_M52_Movement_Trigger8::
	jump_2_left
	step_end

Unused_G34_M52_EventScript_Trigger13::
	warp MAP_UNUSED_G34_M52, 8, 0xFF02, 0x39FF
	compare_var_to_var 0x0534, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger14::
	warp MAP_UNUSED_G34_M52, 9, 0xFF02, 0x39FF
	compare_var_to_var 0x0634, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger15::
	warp MAP_UNUSED_G34_M52, 10, 0xFF02, 0x39FF
	compare_var_to_var 0x0734, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger16::
	applymovement LOCALID_PLAYER, Unused_G34_M52_Movement_Trigger16
	delay 32
	end

Unused_G34_M52_Movement_Trigger16::
	jump_2_down
	step_end

Unused_G34_M52_EventScript_Trigger25::
	@ ShinyGold: overlapping data duplicated from 0x0878AD47
	warp MAP_UNUSED_G34_M52, 5, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger26::
	@ ShinyGold: overlapping data duplicated from 0x0878AD57
	warp MAP_UNUSED_G34_M52, 6, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger27::
	@ ShinyGold: overlapping data duplicated from 0x0878AD67
	warp MAP_UNUSED_G34_M52, 7, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger28::
	warp MAP_UNUSED_G34_M52, 12, 0xFF02, 0x39FF
	compare_var_to_var 0x0B34, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger46::
	@ ShinyGold: overlapping data duplicated from 0x0878AD77
	warp MAP_UNUSED_G34_M52, 11, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger47::
	warp MAP_UNUSED_G34_M52, 14, 0xFF02, 0x39FF
	compare_var_to_var 0x0D34, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger50::
	@ ShinyGold: overlapping data duplicated from 0x0878AD87
	warp MAP_UNUSED_G34_M52, 13, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger51::
	warp MAP_UNUSED_G34_M52, 16, 0xFF02, 0x39FF
	compare_var_to_var 0x0F34, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger52::
	warp MAP_UNUSED_G34_M52, 19, 0xFF02, 0x39FF
	compare_var_to_var 0x1134, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger53::
	warp MAP_UNUSED_G34_M52, 20, 0xFF02, 0x39FF
	compare_var_to_var 0x1234, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger54::
	warp MAP_UNUSED_G34_M52, 22, 0xFF02, 0x39FF
	compare_var_to_var 0x1534, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger61::
	@ ShinyGold: overlapping data duplicated from 0x0878ADA7
	warp MAP_UNUSED_G34_M52, 17, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger62::
	@ ShinyGold: overlapping data duplicated from 0x0878ADC7
	warp MAP_UNUSED_G34_M52, 21, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger63::
	warp MAP_UNUSED_G34_M52, 24, 0xFF02, 0x39FF
	compare_var_to_var 0x1734, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger64::
	warp MAP_UNUSED_G34_M52, 26, 0xFF02, 0x39FF
	compare_var_to_var 0x1934, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger65::
	warp MAP_UNUSED_G34_M52, 29, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger70::
	@ ShinyGold: overlapping data duplicated from 0x0878AD97
	warp MAP_UNUSED_G34_M52, 15, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger71::
	@ ShinyGold: overlapping data duplicated from 0x0878ADB7
	warp MAP_UNUSED_G34_M52, 18, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger72::
	@ ShinyGold: overlapping data duplicated from 0x0878ADD7
	warp MAP_UNUSED_G34_M52, 23, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger73::
	@ ShinyGold: overlapping data duplicated from 0x0878ADE7
	warp MAP_UNUSED_G34_M52, 25, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger74::
	warp MAP_UNUSED_G34_M52, 28, 0xFF02, 0x39FF
	compare_var_to_var 0x1B34, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger75::
	@ ShinyGold: overlapping data duplicated from 0x0878ADF7
	warp MAP_UNUSED_G34_M52, 27, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger76::
	@ ShinyGold: overlapping data duplicated from 0x0878AE00
	warp MAP_UNUSED_G34_M52, 30, 0xFF02, 0x39FF
	compare_var_to_var 0x1D34, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M52_EventScript_Trigger84::
	warp MAP_UNUSED_G34_M53, 0, 0xFF02, 0x39FF
	compare_var_to_var 0x1F34, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)
