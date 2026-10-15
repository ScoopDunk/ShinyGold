Unused_G34_M81_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G34_M81_EventScript_GymSign::
	call_if_unset 0x1223, Unused_G34_M72_EventScript_GymSign_1
	msgbox Unused_G34_M72_Text_GymSign_1, MSGBOX_NPC
	msgbox Unused_G34_M81_Text_GymSign, MSGBOX_NPC
	call Unused_G34_M72_EventScript_GymSign_2
	end

Unused_G34_M81_EventScript_ItemPpUp::
	finditem ITEM_PP_UP
	end

Unused_G34_M81_EventScript_ItemGanlonBerry::
	finditem ITEM_GANLON_BERRY
	end

Unused_G34_M81_EventScript_Boy::
	msgbox Unused_G34_M81_Text_Boy, MSGBOX_NPC
	end

Unused_G34_M81_EventScript_RsMay::
	msgbox Unused_G34_M81_Text_RsMay, MSGBOX_NPC
	end

Unused_G34_M81_EventScript_TeachyTvHost::
	msgbox Unused_G34_M81_Text_TeachyTvHost, MSGBOX_NPC
	end

Unused_G34_M81_EventScript_Trigger1::
	call_if_set 0x1216, Unused_G34_M80_EventScript_Trigger4_1
	applymovement LOCALID_PLAYER, Unused_G34_M81_Movement_Trigger1_1
	delay 1
	msgbox Unused_G34_M81_Text_Trigger1_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_ARD, 0, Unused_G34_M81_Text_Trigger1Defeat, Unused_G34_M81_Text_Trigger1Victory
	msgbox Unused_G34_M81_Text_Trigger1_2, MSGBOX_NPC
	applymovement 4, Unused_G34_M81_Movement_Trigger1_2
	delay 16
	setobjectxy 5, 8, 11
	setobjectxy 4, 5, 26
	msgbox Unused_G34_M81_Text_Trigger1_3, MSGBOX_NPC
	setflag 0x1216
	clearflag 0x1252
	addobject 10
	removeobject 5
	release
	end

Unused_G34_M81_Movement_Trigger1_1::
	face_right
	step_end

Unused_G34_M81_Movement_Trigger1_2::
	face_down_fast
	face_left
	face_up
	face_right
	face_down_fast
	face_left
	face_up
	face_right
	face_down_fast
	face_left
	face_up
	face_right
	step_end

Unused_G34_M81_EventScript_Trigger2::
	call_if_set 0x1217, Unused_G34_M80_EventScript_Trigger4_1
	msgbox Unused_G34_M81_Text_Trigger2_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_PKMN_THIEF_ASHLEE, 0, Unused_G34_M81_Text_Trigger2Defeat, Unused_G34_M81_Text_Trigger2Victory
	msgbox Unused_G34_M81_Text_Trigger2_2, MSGBOX_NPC
	applymovement 6, Unused_G34_M81_Movement_Trigger1_2
	delay 16
	setobjectxy 7, 10, 13
	setobjectxy 6, 5, 13
	msgbox Unused_G34_M81_Text_Trigger2_3, MSGBOX_NPC
	setflag 0x1217
	clearflag 0x1253
	addobject 11
	removeobject 7
	release
	end

Unused_G34_M81_EventScript_Trigger3::
	call_if_set 0x1218, Unused_G34_M80_EventScript_Trigger4_1
	applymovement LOCALID_PLAYER, Unused_G34_M81_Movement_Trigger1_1
	delay 1
	msgbox Unused_G34_M81_Text_Trigger3_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_CARLOS_6, 0, Unused_G34_M81_Text_Trigger3Defeat, Unused_G34_M81_Text_Trigger3Victory
	msgbox Unused_G34_M81_Text_Trigger3_2, MSGBOX_NPC
	applymovement 8, Unused_G34_M81_Movement_Trigger1_2
	delay 16
	setobjectxy 9, 26, 7
	setobjectxy 8, 28, 7
	msgbox Unused_G34_M81_Text_Trigger3_3, MSGBOX_NPC
	setflag 0x1218
	clearflag 0x1254
	addobject 12
	removeobject 9
	release
	end

Unused_G34_M81_EventScript_Trigger4::
	call_if_unset 0x1216, Unused_G34_M81_EventScript_Trigger4_1
	call_if_set 0x1216, Unused_G34_M81_EventScript_Trigger4_2
	call_if_unset 0x1217, Unused_G34_M81_EventScript_Trigger4_3
	call_if_set 0x1217, Unused_G34_M81_EventScript_Trigger4_4
	call_if_unset 0x1218, Unused_G34_M81_EventScript_Trigger4_5
	call_if_set 0x1218, Unused_G34_M81_EventScript_Trigger4_6
	release
	end

Unused_G34_M81_EventScript_Trigger4_1::
	removeobject 10
	return

Unused_G34_M81_EventScript_Trigger4_2::
	clearflag 0x1252
	release
	return

Unused_G34_M81_EventScript_Trigger4_3::
	removeobject 11
	return

Unused_G34_M81_EventScript_Trigger4_4::
	clearflag 0x1253
	release
	return

Unused_G34_M81_EventScript_Trigger4_5::
	removeobject 12
	return

Unused_G34_M81_EventScript_Trigger4_6::
	clearflag 0x1254
	release
	return

Unused_G34_M81_EventScript_Sign::
	msgbox Unused_G34_M72_Text_Sign, MSGBOX_NPC
	setflag 0x1223
	release
	end
