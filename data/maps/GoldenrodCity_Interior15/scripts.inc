GoldenrodCity_Interior15_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

GoldenrodCity_Interior15_EventScript_Machoke::
	msgbox GoldenrodCity_Interior15_Text_Machoke, MSGBOX_NPC
	waitse
	playmoncry SPECIES_MACHOP, 0x201
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior15_EventScript_Rocker::
	msgbox GoldenrodCity_Interior15_Text_Rocker, MSGBOX_NPC
	end

GoldenrodCity_Interior15_EventScript_BlackBelt::
	msgbox GoldenrodCity_Interior15_Text_BlackBelt, MSGBOX_NPC
	end

GoldenrodCity_Interior15_EventScript_BaldingMan::
	msgbox GoldenrodCity_Interior15_Text_BaldingMan, MSGBOX_NPC
	end

GoldenrodCity_Interior15_EventScript_ItemEther::
	finditem ITEM_ETHER
	end

GoldenrodCity_Interior15_EventScript_ItemBurnHeal::
	finditem ITEM_BURN_HEAL
	end

GoldenrodCity_Interior15_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

GoldenrodCity_Interior15_EventScript_ItemAmuletCoin::
	finditem ITEM_AMULET_COIN
	end

GoldenrodCity_Interior15_EventScript_Trigger1::
	setvar VAR_RESULT, 0
	release
	end
