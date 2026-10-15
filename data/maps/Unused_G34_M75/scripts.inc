Unused_G34_M75_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G34_M75_EventScript_GymSign::
	call_if_unset 0x121D, Unused_G34_M72_EventScript_GymSign_1
	msgbox Unused_G34_M72_Text_GymSign_1, MSGBOX_NPC
	msgbox Unused_G34_M75_Text_GymSign, MSGBOX_NPC
	call Unused_G34_M75_EventScript_GymSign_1
	end

Unused_G34_M75_EventScript_GymSign_1::
	msgbox Unused_G34_M72_Text_GymSign_4, MSGBOX_NPC
	setobjectxy 1, 34, 4
	delay 16
	applymovement LOCALID_PLAYER, Unused_G34_M72_Movement_GymSign
	delay 16
	warp MAP_UNUSED_G34_M71, 0, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M75_EventScript_BlackBeltRandy::
	trainerbattle_single TRAINER_BLACK_BELT_RANDY, Unused_G34_M75_Text_BlackBeltRandyIntro, Unused_G34_M75_Text_BlackBeltRandyDefeat
	msgbox Unused_G34_M75_Text_BlackBeltRandy, MSGBOX_AUTOCLOSE
	end

Unused_G34_M75_EventScript_HikerGabriel::
	trainerbattle_single TRAINER_HIKER_GABRIEL, Unused_G34_M75_Text_HikerGabrielIntro, Unused_G34_M75_Text_HikerGabrielDefeat
	msgbox Unused_G34_M75_Text_HikerGabriel, MSGBOX_AUTOCLOSE
	end

Unused_G34_M75_EventScript_ItemLumBerry::
	finditem ITEM_LUM_BERRY
	end

Unused_G34_M75_EventScript_ItemBigMushroom::
	finditem ITEM_BIG_MUSHROOM
	end

Unused_G34_M75_EventScript_Sign::
	msgbox Unused_G34_M72_Text_Sign, MSGBOX_NPC
	setflag 0x121D
	release
	end
