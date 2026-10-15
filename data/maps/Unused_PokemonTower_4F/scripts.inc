Unused_PokemonTower_4F_MapScripts::
	.byte 0

Unused_PokemonTower_4F_EventScript_MediumJody::
	trainerbattle_single TRAINER_MEDIUM_JODY, Unused_PokemonTower_4F_Text_MediumJodyIntro, Unused_PokemonTower_4F_Text_MediumJodyDefeat
	msgbox Unused_PokemonTower_4F_Text_MediumJody, MSGBOX_AUTOCLOSE
	end

Unused_PokemonTower_4F_EventScript_MgDeliveryman::
	msgbox Unused_PokemonTower_4F_Text_MgDeliveryman, MSGBOX_NPC
	end

Unused_PokemonTower_4F_EventScript_Boy::
	msgbox Unused_PokemonTower_4F_Text_Boy, MSGBOX_NPC
	end

Unused_PokemonTower_4F_EventScript_MgDeliveryman2::
	msgbox Unused_PokemonTower_4F_Text_MgDeliveryman2_1, MSGBOX_NPC
	msgbox Unused_PokemonTower_4F_Text_MgDeliveryman2_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Unused_PokemonTower_4F_EventScript_MgDeliveryman2_1
	msgbox Unused_PokemonTower_4F_Text_MgDeliveryman2_3, MSGBOX_NPC
	end

Unused_PokemonTower_4F_EventScript_MgDeliveryman2_1::
	getpartysize
	call_if_lt VAR_RESULT, 2, Unused_PokemonTower_4F_EventScript_MgDeliveryman2_2
	msgbox Unused_PokemonTower_4F_Text_MgDeliveryman2_4, MSGBOX_NPC
	end

Unused_PokemonTower_4F_EventScript_MgDeliveryman2_2::
	setflag 0x109B
	setflag 0x1099
	clearflag 0x1098
	msgbox Unused_PokemonTower_4F_Text_MgDeliveryman2_5, MSGBOX_NPC
	giveitem ITEM_SAFARI_BALL, 5
	msgbox Unused_PokemonTower_4F_Text_MgDeliveryman2_6, MSGBOX_NPC
	warp MAP_UNUSED_G2_M88, 0, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)
