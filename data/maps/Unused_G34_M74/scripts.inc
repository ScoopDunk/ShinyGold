Unused_G34_M74_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G34_M74_EventScript_GymSign::
	call_if_unset 0x121B, Unused_G34_M72_EventScript_GymSign_1
	msgbox Unused_G34_M72_Text_GymSign_1, MSGBOX_NPC
	msgbox Unused_G34_M74_Text_GymSign, MSGBOX_NPC
	call Unused_G34_M72_EventScript_GymSign_2
	end

Unused_G34_M74_EventScript_BeautySera::
	trainerbattle_single TRAINER_BEAUTY_SERA, Unused_G34_M74_Text_BeautySeraIntro, Unused_G34_M74_Text_BeautySeraDefeat
	msgbox Unused_G34_M74_Text_BeautySera, MSGBOX_AUTOCLOSE
	end

Unused_G34_M74_EventScript_LassRemi::
	trainerbattle_single TRAINER_LASS_REMI, Unused_G34_M74_Text_LassRemiIntro, Unused_G34_M74_Text_LassRemiDefeat
	msgbox Unused_G34_M74_Text_LassRemi, MSGBOX_AUTOCLOSE
	end

Unused_G34_M74_EventScript_ItemRevive::
	finditem ITEM_REVIVE
	end

Unused_G34_M74_EventScript_ItemLeppaBerry::
	finditem ITEM_LEPPA_BERRY
	end

Unused_G34_M74_EventScript_Sign::
	msgbox Unused_G34_M72_Text_Sign, MSGBOX_NPC
	setflag 0x121B
	release
	end
