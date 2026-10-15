Unused_G34_M72_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G34_M72_EventScript_GymSign::
	call_if_unset 0x1219, Unused_G34_M72_EventScript_GymSign_1
	msgbox Unused_G34_M72_Text_GymSign_1, MSGBOX_NPC
	msgbox Unused_G34_M72_Text_GymSign_2, MSGBOX_NPC
	call Unused_G34_M72_EventScript_GymSign_2
	end

Unused_G34_M72_EventScript_GymSign_1::
	msgbox Unused_G34_M72_Text_GymSign_3, MSGBOX_NPC
	end

Unused_G34_M72_EventScript_GymSign_2::
	msgbox Unused_G34_M72_Text_GymSign_4, MSGBOX_NPC
	setobjectxy 1, 22, 4
	delay 16
	applymovement LOCALID_PLAYER, Unused_G34_M72_Movement_GymSign
	delay 16
	warp MAP_UNUSED_G34_M71, 0, 0xFE11, 0xFFFF
	checkmonmodernfatefulencounter 0xDDDC
	.byte 0xE7 @ invalid opcode (script stops)

Unused_G34_M72_Movement_GymSign::
	@ ShinyGold: overlapping data duplicated from 0x08889DF0
	walk_up
	step_end

Unused_G34_M72_EventScript_YoungsterFabricio::
	trainerbattle_single TRAINER_YOUNGSTER_FABRICIO, Unused_G34_M72_Text_YoungsterFabricioIntro, Unused_G34_M72_Text_YoungsterFabricioDefeat
	msgbox Unused_G34_M72_Text_YoungsterFabricio, MSGBOX_AUTOCLOSE
	end

Unused_G34_M72_EventScript_LassRaina::
	trainerbattle_single TRAINER_LASS_RAINA, Unused_G34_M72_Text_LassRainaIntro, Unused_G34_M72_Text_LassRainaDefeat
	msgbox Unused_G34_M72_Text_LassRaina, MSGBOX_AUTOCLOSE
	end

Unused_G34_M72_EventScript_ItemSuperPotion::
	finditem ITEM_SUPER_POTION
	end

Unused_G34_M72_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

Unused_G34_M72_EventScript_Sign::
	msgbox Unused_G34_M72_Text_Sign, MSGBOX_NPC
	setflag 0x1219
	release
	end
