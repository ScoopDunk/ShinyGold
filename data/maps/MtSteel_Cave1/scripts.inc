MtSteel_Cave1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

MtSteel_Cave1_EventScript_HikerBenjamin::
	trainerbattle_single TRAINER_HIKER_BENJAMIN, MtSteel_Cave1_Text_HikerBenjaminIntro, MtSteel_Cave1_Text_HikerBenjaminDefeat
	msgbox MtSteel_Cave1_Text_HikerBenjamin, MSGBOX_AUTOCLOSE
	end

MtSteel_Cave1_EventScript_LassSanae::
	trainerbattle_single TRAINER_LASS_SANAE, MtSteel_Cave1_Text_LassSanaeIntro, MtSteel_Cave1_Text_LassSanaeDefeat
	msgbox MtSteel_Cave1_Text_LassSanae, MSGBOX_AUTOCLOSE
	end

MtSteel_Cave1_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_YOUNGSTER_IAN, MtSteel_Cave1_Text_YoungsterIanIntro, MtSteel_Cave1_Text_YoungsterIanDefeat
	msgbox MtSteel_Cave1_Text_YoungsterIan, MSGBOX_AUTOCLOSE
	end

MtSteel_Cave1_EventScript_YoungsterJosh::
	trainerbattle_single TRAINER_YOUNGSTER_JOSH, MtSteel_Cave1_Text_YoungsterJoshIntro, MtSteel_Cave1_Text_YoungsterJoshDefeat
	msgbox MtSteel_Cave1_Text_YoungsterJosh, MSGBOX_AUTOCLOSE
	end

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

MtSteel_Cave1_EventScript_Sign::
	msgbox MtSteel_Cave1_Text_Sign, MSGBOX_SIGN
	end
