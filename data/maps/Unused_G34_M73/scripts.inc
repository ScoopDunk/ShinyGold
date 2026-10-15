Unused_G34_M73_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G34_M73_EventScript_GymSign::
	call_if_unset 0x121A, Unused_G34_M72_EventScript_GymSign_1
	msgbox Unused_G34_M72_Text_GymSign_1, MSGBOX_NPC
	msgbox Unused_G34_M73_Text_GymSign, MSGBOX_NPC
	call Unused_G34_M72_EventScript_GymSign_2
	end

Unused_G34_M73_EventScript_CamperRaoul::
	trainerbattle_single TRAINER_CAMPER_RAOUL, Unused_G34_M73_Text_CamperRaoulIntro, Unused_G34_M73_Text_CamperRaoulDefeat
	msgbox Unused_G34_M73_Text_CamperRaoul, MSGBOX_AUTOCLOSE
	end

Unused_G34_M73_EventScript_PicnickerCarrie::
	trainerbattle_single TRAINER_PICNICKER_CARRIE, Unused_G34_M73_Text_PicnickerCarrieIntro, Unused_G34_M73_Text_PicnickerCarrieDefeat
	msgbox Unused_G34_M73_Text_PicnickerCarrie, MSGBOX_AUTOCLOSE
	end

Unused_G34_M73_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER
	end

Unused_G34_M73_EventScript_ItemOranBerry::
	finditem ITEM_ORAN_BERRY
	end

Unused_G34_M73_EventScript_Sign::
	msgbox Unused_G34_M72_Text_Sign, MSGBOX_NPC
	setflag 0x121A
	release
	end
