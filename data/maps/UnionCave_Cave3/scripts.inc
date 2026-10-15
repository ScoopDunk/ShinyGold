UnionCave_Cave3_MapScripts::
	.byte 0

UnionCave_Cave3_EventScript_CooltrainerNick::
	trainerbattle_single TRAINER_COOLTRAINER_NICK, UnionCave_Cave3_Text_CooltrainerNickIntro, UnionCave_Cave3_Text_CooltrainerNickDefeat
	msgbox UnionCave_Cave3_Text_CooltrainerNick, MSGBOX_AUTOCLOSE
	end

UnionCave_Cave3_EventScript_CooltrainerGwen::
	trainerbattle_single TRAINER_COOLTRAINER_GWEN, UnionCave_Cave3_Text_CooltrainerGwenIntro, UnionCave_Cave3_Text_CooltrainerGwenDefeat
	msgbox UnionCave_Cave3_Text_CooltrainerGwen, MSGBOX_AUTOCLOSE
	end

UnionCave_Cave3_EventScript_CooltrainerEmma::
	trainerbattle_single TRAINER_COOLTRAINER_EMMA, UnionCave_Cave3_Text_CooltrainerEmmaIntro, UnionCave_Cave3_Text_CooltrainerEmmaDefeat
	msgbox UnionCave_Cave3_Text_CooltrainerEmma, MSGBOX_AUTOCLOSE
	end

UnionCave_Cave3_EventScript_ItemElixir::
	finditem ITEM_ELIXIR
	end

UnionCave_Cave3_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION
	end

UnionCave_Cave3_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

UnionCave_Cave3_EventScript_Lapras::
	setflag 0x10BA
	waitse
	playmoncry SPECIES_LAPRAS, 0x2800
	waitse
	nop
	delay 48
	setwildbattle SPECIES_LAPRAS, 20
	special StartSouthernIslandBattle
	delay 128
	warp MAP_UNION_CAVE_CAVE3, 1, 0x9725, 0x201
	nop1
	special DaisyMassageServices
	end
