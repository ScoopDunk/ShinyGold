Unused_G34_M76_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G34_M76_EventScript_GymSign::
	call_if_unset 0x121C, Unused_G34_M72_EventScript_GymSign_1
	msgbox Unused_G34_M72_Text_GymSign_1, MSGBOX_NPC
	msgbox Unused_G34_M76_Text_GymSign, MSGBOX_NPC
	call Unused_G34_M75_EventScript_GymSign_1
	end

Unused_G34_M76_EventScript_SageGen::
	trainerbattle_single TRAINER_SAGE_GEN, Unused_G34_M76_Text_SageGenIntro, Unused_G34_M76_Text_SageGenDefeat
	msgbox Unused_G34_M76_Text_SageGen, MSGBOX_AUTOCLOSE
	end

Unused_G34_M76_EventScript_MediumEris::
	trainerbattle_single TRAINER_MEDIUM_ERIS, Unused_G34_M76_Text_MediumErisIntro, Unused_G34_M76_Text_MediumErisDefeat
	msgbox Unused_G34_M76_Text_MediumEris, MSGBOX_AUTOCLOSE
	end

Unused_G34_M76_EventScript_ItemPersimBerry::
	finditem ITEM_PERSIM_BERRY
	end

Unused_G34_M76_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION
	end

Unused_G34_M76_EventScript_Sign::
	msgbox Unused_G34_M72_Text_Sign, MSGBOX_NPC
	setflag 0x121C
	release
	end
