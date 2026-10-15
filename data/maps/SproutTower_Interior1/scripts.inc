SproutTower_Interior1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

SproutTower_Interior1_EventScript_Woman2::
	msgbox SproutTower_Interior1_Text_Woman2, MSGBOX_NPC
	end

SproutTower_Interior1_EventScript_OldMan2::
	msgbox SproutTower_Interior1_Text_OldMan2, MSGBOX_NPC
	end

SproutTower_Interior1_EventScript_ItemParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

SproutTower_Interior1_EventScript_OldMan1::
	msgbox SproutTower_Interior1_Text_OldMan1, MSGBOX_NPC
	end

SproutTower_Interior1_EventScript_OldWoman::
	msgbox SproutTower_Interior1_Text_OldWoman, MSGBOX_NPC
	end

SproutTower_Interior1_EventScript_SageChow::
	trainerbattle_single TRAINER_SAGE_CHOW, SproutTower_Interior1_Text_SageChowIntro, SproutTower_Interior1_Text_SageChowDefeat
	msgbox SproutTower_Interior1_Text_SageChow, MSGBOX_AUTOCLOSE
	end

SproutTower_Interior1_EventScript_Trigger1::
	warp MAP_SPROUT_TOWER_INTERIOR2, 0, 0xFF02, 0x39FF
	end

SproutTower_Interior1_EventScript_Trigger2::
	warp MAP_SPROUT_TOWER_INTERIOR2, 1, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SproutTower_Interior1_EventScript_Trigger3::
	warp MAP_SPROUT_TOWER_INTERIOR2, 2, 0xFF02, 0x39FF
	end
