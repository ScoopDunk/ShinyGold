Route30_Interior2_MapScripts::
	.byte 0

Route30_Interior2_EventScript_Gentleman::
	faceplayer
	call_if_set 0x1127, Route30_Interior2_EventScript_Gentleman_1
	checkitem ITEM_LIFT_KEY
	call_if_eq VAR_RESULT, 1, Route30_Interior2_EventScript_Gentleman_2
	call_if_set 0x1025, Route30_Interior2_EventScript_Gentleman_1
	msgbox Route30_Interior2_Text_Gentleman_1, MSGBOX_NPC
	end

Route30_Interior2_EventScript_Gentleman_1::
	msgbox Route30_Interior2_Text_Gentleman_2, MSGBOX_NPC
	end

Route30_Interior2_EventScript_Gentleman_2::
	msgbox Route30_Interior2_Text_Gentleman_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route30_Interior2_EventScript_Gentleman_3
	msgbox Route30_Interior2_Text_Gentleman_4, MSGBOX_NPC
	end

Route30_Interior2_EventScript_Gentleman_3::
	removeitem ITEM_LIFT_KEY
	giveitem ITEM_EXP_SHARE
	setflag 0x1127
	msgbox Route30_Interior2_Text_Gentleman_2, MSGBOX_NPC
	end

Route30_Interior2_EventScript_Trigger1::
	call_if_set 0x1015, Route30_Interior2_EventScript_Trigger1_1
	msgbox Route30_Interior2_Text_Trigger1_1, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Route30_Interior2_Movement_Trigger1_1
	delay 16
	msgbox Route30_Interior2_Text_Trigger1_2, MSGBOX_NPC
	giveitem ITEM_OAKS_PARCEL
	msgbox Route30_Interior2_Text_Trigger1_3, MSGBOX_NPC
	applymovement 1, Route30_Interior2_Movement_Trigger1_2
	delay 16
	applymovement 1, Route30_Interior2_Movement_Trigger1_3
	applymovement 2, Route30_Interior2_Movement_Trigger1_4
	msgbox Route30_Interior2_Text_Trigger1_4, MSGBOX_NPC
	playbgm MUS_OAK, 51
	applymovement LOCALID_PLAYER, Route30_Interior2_Movement_Trigger1_5
	applymovement 2, Route30_Interior2_Movement_Trigger1_6
	delay 32
	msgbox Route30_Interior2_Text_Trigger1_5, MSGBOX_NPC
	msgbox Route30_Interior2_Text_Trigger1_6, MSGBOX_NPC
	setflag FLAG_SYS_POKEDEX_GET
	special EnableNationalPokedex
	playfanfare MUS_OBTAIN_KEY_ITEM
	msgbox Route30_Interior2_Text_Trigger1_7, MSGBOX_NPC
	waitfanfare
	msgbox Route30_Interior2_Text_Trigger1_8, MSGBOX_NPC
	applymovement 2, Route30_Interior2_Movement_Trigger1_7
	delay 80
	playbgm MUS_SEVII_123, 51
	applymovement LOCALID_PLAYER, Route30_Interior2_Movement_Trigger1_8
	delay 5
	msgbox Route30_Interior2_Text_Trigger1_9, MSGBOX_NPC
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox Route30_Interior2_Text_Trigger1_10, MSGBOX_NPC
	setflag 0x1014
	setflag 0x1015
	release
	end

Route30_Interior2_EventScript_Trigger1_1::
	release
	end

Route30_Interior2_Movement_Trigger1_1::
	walk_left
	walk_up
	step_end

Route30_Interior2_Movement_Trigger1_2::
	face_right
	step_end

Route30_Interior2_Movement_Trigger1_3::
	face_down_fast
	step_end

Route30_Interior2_Movement_Trigger1_4::
	face_left
	step_end

Route30_Interior2_Movement_Trigger1_5::
	face_right
	step_end

Route30_Interior2_Movement_Trigger1_6::
	walk_down
	walk_left
	walk_left
	face_left
	step_end

Route30_Interior2_Movement_Trigger1_7::
	walk_down
	walk_left
	face_down_fast
	set_invisible
	walk_down
Route30_Interior2_Movement_Trigger1_8::
	face_up
	step_end

Route30_Interior2_EventScript_Trigger2::
	call_if_set 0x1015, Route30_Interior2_EventScript_Trigger1_1
	msgbox Route30_Interior2_Text_Trigger1_1, MSGBOX_NPC
	msgbox Route30_Interior2_Text_Trigger1_2, MSGBOX_NPC
	giveitem ITEM_OAKS_PARCEL
	msgbox Route30_Interior2_Text_Trigger1_3, MSGBOX_NPC
	applymovement 1, Route30_Interior2_Movement_Trigger1_2
	delay 16
	applymovement 1, Route30_Interior2_Movement_Trigger1_3
	applymovement 2, Route30_Interior2_Movement_Trigger1_4
	msgbox Route30_Interior2_Text_Trigger1_4, MSGBOX_NPC
	playbgm MUS_OAK, 51
	applymovement LOCALID_PLAYER, Route30_Interior2_Movement_Trigger1_5
	applymovement 2, Route30_Interior2_Movement_Trigger1_6
	delay 32
	msgbox Route30_Interior2_Text_Trigger1_5, MSGBOX_NPC
	msgbox Route30_Interior2_Text_Trigger1_6, MSGBOX_NPC
	setflag FLAG_SYS_POKEDEX_GET
	special EnableNationalPokedex
	playfanfare MUS_OBTAIN_KEY_ITEM
	msgbox Route30_Interior2_Text_Trigger1_7, MSGBOX_NPC
	waitfanfare
	msgbox Route30_Interior2_Text_Trigger1_8, MSGBOX_NPC
	applymovement 2, Route30_Interior2_Movement_Trigger1_7
	delay 80
	playbgm MUS_SEVII_123, 51
	applymovement LOCALID_PLAYER, Route30_Interior2_Movement_Trigger1_8
	delay 5
	msgbox Route30_Interior2_Text_Trigger1_9, MSGBOX_NPC
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox Route30_Interior2_Text_Trigger1_10, MSGBOX_NPC
	setflag 0x1014
	setflag 0x1015
	end

Route30_Interior2_EventScript_Trigger3::
	call_if_set 0x1015, Route30_Interior2_EventScript_Trigger1_1
	msgbox Route30_Interior2_Text_Trigger1_1, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Route30_Interior2_Movement_Trigger3
	delay 16
	msgbox Route30_Interior2_Text_Trigger1_2, MSGBOX_NPC
	giveitem ITEM_OAKS_PARCEL
	msgbox Route30_Interior2_Text_Trigger1_3, MSGBOX_NPC
	applymovement 1, Route30_Interior2_Movement_Trigger1_2
	delay 16
	applymovement 1, Route30_Interior2_Movement_Trigger1_3
	applymovement 2, Route30_Interior2_Movement_Trigger1_4
	msgbox Route30_Interior2_Text_Trigger1_4, MSGBOX_NPC
	playbgm MUS_OAK, 51
	applymovement LOCALID_PLAYER, Route30_Interior2_Movement_Trigger1_5
	applymovement 2, Route30_Interior2_Movement_Trigger1_6
	delay 32
	msgbox Route30_Interior2_Text_Trigger1_5, MSGBOX_NPC
	msgbox Route30_Interior2_Text_Trigger1_6, MSGBOX_NPC
	setflag FLAG_SYS_POKEDEX_GET
	special EnableNationalPokedex
	playfanfare MUS_OBTAIN_KEY_ITEM
	msgbox Route30_Interior2_Text_Trigger1_7, MSGBOX_NPC
	waitfanfare
	msgbox Route30_Interior2_Text_Trigger1_8, MSGBOX_NPC
	applymovement 2, Route30_Interior2_Movement_Trigger1_7
	delay 80
	playbgm MUS_SEVII_123, 51
	applymovement LOCALID_PLAYER, Route30_Interior2_Movement_Trigger1_8
	delay 5
	msgbox Route30_Interior2_Text_Trigger1_9, MSGBOX_NPC
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox Route30_Interior2_Text_Trigger1_10, MSGBOX_NPC
	setflag 0x1014
	setflag 0x1015
	release
	end

Route30_Interior2_Movement_Trigger3::
	walk_right
	walk_up
	step_end

Route30_Interior2_EventScript_Sign::
	msgbox Route30_Interior2_Text_Sign, MSGBOX_SIGN
	end
