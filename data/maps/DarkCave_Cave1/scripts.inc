DarkCave_Cave1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

DarkCave_Cave1_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

DarkCave_Cave1_EventScript_BlackBelt::
	faceplayer
	call_if_set 0x1079, DarkCave_Cave1_EventScript_BlackBelt_1
	msgbox DarkCave_Cave1_Text_BlackBelt_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, DarkCave_Cave1_EventScript_BlackBelt_2
	msgbox DarkCave_Cave1_Text_BlackBelt_2, MSGBOX_NPC
	end

DarkCave_Cave1_EventScript_BlackBelt_1::
	msgbox DarkCave_Cave1_Text_BlackBelt_3, MSGBOX_NPC
	end

DarkCave_Cave1_EventScript_BlackBelt_2::
	trainerbattle_earlyrival TRAINER_BLACK_BELT_HIKARU, 0, DarkCave_Cave1_Text_BlackBeltDefeat, DarkCave_Cave1_Text_BlackBeltVictory
	msgbox DarkCave_Cave1_Text_BlackBelt_4, MSGBOX_NPC
	giveitem ITEM_TM04
	msgbox DarkCave_Cave1_Text_BlackBelt_5, MSGBOX_NPC
	setflag 0x1079
	end

DarkCave_Cave1_EventScript_ItemElixir::
	finditem ITEM_ELIXIR
	end

DarkCave_Cave1_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

DarkCave_Cave1_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION
	end
