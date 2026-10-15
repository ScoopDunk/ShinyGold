Unused_G34_M78_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G34_M78_EventScript_GymSign::
	call_if_unset 0x121F, Unused_G34_M72_EventScript_GymSign_1
	msgbox Unused_G34_M72_Text_GymSign_1, MSGBOX_NPC
	msgbox Unused_G34_M78_Text_GymSign, MSGBOX_NPC
	call Unused_G34_M75_EventScript_GymSign_1
	end

Unused_G34_M78_EventScript_DragonTamerMikahil::
	trainerbattle_single TRAINER_DRAGON_TAMER_MIKAHIL, Unused_G34_M78_Text_DragonTamerMikahilIntro, Unused_G34_M78_Text_DragonTamerMikahilDefeat
	msgbox Unused_G34_M78_Text_DragonTamerMikahil, MSGBOX_AUTOCLOSE
	end

Unused_G34_M78_EventScript_CooltrainerFiria::
	trainerbattle_single TRAINER_COOLTRAINER_FIRIA, Unused_G34_M78_Text_CooltrainerFiriaIntro, Unused_G34_M78_Text_CooltrainerFiriaDefeat
	msgbox Unused_G34_M78_Text_CooltrainerFiria, MSGBOX_AUTOCLOSE
	end

Unused_G34_M78_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

Unused_G34_M78_EventScript_ItemWikiBerry::
	finditem ITEM_WIKI_BERRY
	end

Unused_G34_M78_EventScript_Sign::
	msgbox Unused_G34_M72_Text_Sign, MSGBOX_NPC
	setflag 0x121F
	release
	end
