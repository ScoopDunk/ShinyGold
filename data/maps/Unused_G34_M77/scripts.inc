Unused_G34_M77_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G34_M77_EventScript_GymSign::
	call_if_unset 0x121E, Unused_G34_M72_EventScript_GymSign_1
	msgbox Unused_G34_M72_Text_GymSign_1, MSGBOX_NPC
	msgbox Unused_G34_M77_Text_GymSign, MSGBOX_NPC
	call Unused_G34_M75_EventScript_GymSign_1
	end

Unused_G34_M77_EventScript_FishermanPhil::
	trainerbattle_single TRAINER_FISHERMAN_PHIL, Unused_G34_M77_Text_FishermanPhilIntro, Unused_G34_M77_Text_FishermanPhilDefeat
	msgbox Unused_G34_M77_Text_FishermanPhil, MSGBOX_AUTOCLOSE
	end

Unused_G34_M77_EventScript_PokemaniacMarco::
	trainerbattle_single TRAINER_POKEMANIAC_MARCO, Unused_G34_M77_Text_PokemaniacMarcoIntro, Unused_G34_M77_Text_PokemaniacMarcoDefeat
	msgbox Unused_G34_M77_Text_PokemaniacMarco, MSGBOX_AUTOCLOSE
	end

Unused_G34_M77_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

Unused_G34_M77_EventScript_ItemSitrusBerry::
	finditem ITEM_SITRUS_BERRY
	end

Unused_G34_M77_EventScript_Sign::
	msgbox Unused_G34_M72_Text_Sign, MSGBOX_NPC
	setflag 0x121E
	release
	end
