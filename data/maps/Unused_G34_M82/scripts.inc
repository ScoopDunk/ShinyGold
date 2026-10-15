Unused_G34_M82_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G34_M82_EventScript_GymSign::
	call_if_unset 0x1220, Unused_G34_M72_EventScript_GymSign_1
	msgbox Unused_G34_M72_Text_GymSign_1, MSGBOX_NPC
	msgbox Unused_G34_M82_Text_GymSign, MSGBOX_NPC
	call Unused_G34_M72_EventScript_GymSign_2
	end

Unused_G34_M82_EventScript_CooltrainerRezo::
	trainerbattle_single TRAINER_COOLTRAINER_REZO, Unused_G34_M82_Text_CooltrainerRezoIntro, Unused_G34_M82_Text_CooltrainerRezoDefeat
	msgbox Unused_G34_M82_Text_CooltrainerRezo, MSGBOX_AUTOCLOSE
	end

Unused_G34_M82_EventScript_ItemMagoBerry::
	finditem ITEM_MAGO_BERRY
	end

Unused_G34_M82_EventScript_CooltrainerReika::
	trainerbattle_single TRAINER_COOLTRAINER_REIKA, Unused_G34_M82_Text_CooltrainerReikaIntro, Unused_G34_M82_Text_CooltrainerReikaDefeat
	msgbox Unused_G34_M82_Text_CooltrainerReika, MSGBOX_AUTOCLOSE
	end

Unused_G34_M82_EventScript_ItemNugget::
	finditem ITEM_NUGGET
	end

Unused_G34_M82_EventScript_Sign::
	msgbox Unused_G34_M72_Text_Sign, MSGBOX_NPC
	setflag 0x1220
	release
	end
