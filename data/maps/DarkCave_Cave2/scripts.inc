DarkCave_Cave2_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

@ ShinyGold: moved from data/maps/Unused_PokemonTower_3F/scripts.inc (map removed)
Unused_PokemonTower_3F_EventScript_PokeManiac::
	lock
	faceplayer
	call_if_set 0x1150, Unused_PokemonTower_3F_EventScript_PokeManiac_1
	msgbox Unused_PokemonTower_3F_Text_PokeManiac_1, MSGBOX_NPC
	giveitem ITEM_BLACK_GLASSES
	msgbox Unused_PokemonTower_3F_Text_PokeManiac_2, MSGBOX_NPC
	setflag 0x1150
	release
	end

@ ShinyGold: moved from data/maps/Unused_PokemonTower_3F/scripts.inc (map removed)
Unused_PokemonTower_3F_EventScript_PokeManiac_1::
	msgbox Unused_PokemonTower_3F_Text_PokeManiac_2, MSGBOX_NPC
	end

@ ShinyGold: moved from data/maps/Unused_PokemonTower_3F/scripts.inc (map removed)
Unused_PokemonTower_3F_EventScript_ItemTm35::
	finditem ITEM_TM35
	end

@ ShinyGold: moved from data/maps/Unused_PokemonTower_3F/scripts.inc (map removed)
Unused_PokemonTower_3F_EventScript_ItemRevive::
	finditem ITEM_REVIVE
	end
