MtSteel_Cave1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

MtSteel_Cave1_EventScript_BurglarFredrick::
	trainerbattle_single TRAINER_BURGLAR_FREDRICK, MtSteel_Cave1_Text_BurglarFredrickIntro, MtSteel_Cave1_Text_BurglarFredrickDefeat
	msgbox MtSteel_Cave1_Text_BurglarFredrick, MSGBOX_AUTOCLOSE
	end

MtSteel_Cave1_EventScript_ItemIron::
	finditem ITEM_IRON
	end

MtSteel_Cave1_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

MtSteel_Cave1_EventScript_Zapdos::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGISTEEL, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setwildbattle SPECIES_REGISTEEL, 50
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	fadescreen FADE_TO_BLACK
	removeobject 14
	fadescreen FADE_FROM_BLACK
	setflag 0x140D
	release
	end
