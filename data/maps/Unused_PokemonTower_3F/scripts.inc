Unused_PokemonTower_3F_MapScripts::
	.byte 0

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

Unused_PokemonTower_3F_EventScript_PokeManiac_1::
	msgbox Unused_PokemonTower_3F_Text_PokeManiac_2, MSGBOX_NPC
	end

Unused_PokemonTower_3F_EventScript_ItemTm35::
	finditem ITEM_TM35
	end

Unused_PokemonTower_3F_EventScript_ItemRevive::
	finditem ITEM_REVIVE
	end
