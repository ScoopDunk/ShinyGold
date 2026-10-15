NewBarkTown_Interior1_MapScripts::
	.byte 0

NewBarkTown_Interior1_EventScript_Mom::
	lock
	faceplayer
	call_if_set 0x1027, NewBarkTown_Interior1_EventScript_Mom_1
	call_if_set 0x1025, NewBarkTown_Interior1_EventScript_Mom_2
	call_if_set 0x258, NewBarkTown_Interior1_EventScript_Mom_3
	call_if_eq 0x4055, 3, NewBarkTown_Interior1_EventScript_Mom_4
	checkplayergender
	goto_if_eq VAR_RESULT, 0, NewBarkTown_Interior1_EventScript_Mom_5
	goto_if_eq VAR_RESULT, 1, NewBarkTown_Interior1_EventScript_Mom_6
	release
	end

NewBarkTown_Interior1_EventScript_Mom_1::
	msgbox NewBarkTown_Interior1_Text_Mom_1, MSGBOX_NPC
	release
	end

NewBarkTown_Interior1_EventScript_Mom_2::
	msgbox NewBarkTown_Interior1_Text_Mom_2, MSGBOX_NPC
	giveitem ITEM_AMULET_COIN
	call NewBarkTown_Interior1_EventScript_Mom_7
	setflag 0x1027
	end

NewBarkTown_Interior1_EventScript_Mom_3::
	msgbox NewBarkTown_Interior1_Text_Mom_3
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox NewBarkTown_Interior1_Text_Mom_4
	release
	end

NewBarkTown_Interior1_EventScript_Mom_4::
	msgbox NewBarkTown_Interior1_Text_Mom_5, MSGBOX_NPC
	end

NewBarkTown_Interior1_EventScript_Mom_5::
	msgbox NewBarkTown_Interior1_Text_Mom_6, MSGBOX_NPC
	return

NewBarkTown_Interior1_EventScript_Mom_6::
	msgbox NewBarkTown_Interior1_Text_Mom_7, MSGBOX_NPC
	return

NewBarkTown_Interior1_EventScript_Mom_7::
	msgbox NewBarkTown_Interior1_Text_Mom_8, MSGBOX_NPC
	call NewBarkTown_Interior1_EventScript_Mom_8
	return

NewBarkTown_Interior1_EventScript_Trigger1::
	call_if_set 0x11D6, NewBarkTown_Interior1_EventScript_Trigger1_1
	call NewBarkTown_Interior1_EventScript_Trigger1_2
	end

NewBarkTown_Interior1_EventScript_Trigger1_1::
	release
	end

NewBarkTown_Interior1_EventScript_Trigger1_2::
	lock
	playbgm MUS_OAK, 51
	applymovement 1, NewBarkTown_Interior1_Movement_Trigger1_1
	delay 64
	msgbox NewBarkTown_Interior1_Text_Trigger1_1, MSGBOX_NPC
	call NewBarkTown_Interior1_EventScript_Trigger1_3
	end

NewBarkTown_Interior1_EventScript_Trigger1_3::
	giveitem ITEM_CONTEST_PASS
	giveitem ITEM_STORAGE_KEY
	msgbox NewBarkTown_Interior1_Text_Trigger1_2, MSGBOX_YESNO
	call_if_lt VAR_RESULT, 1, NewBarkTown_Interior1_EventScript_Trigger1_4
	msgbox NewBarkTown_Interior1_Text_Trigger1_3, MSGBOX_NPC
	applymovement 1, NewBarkTown_Interior1_Movement_Trigger1_2
	delay 64
	playbgm MUS_MYSTERY_GIFT, 51
	setflag 0x11D6
	release
	end

NewBarkTown_Interior1_Movement_Trigger1_1::
	emote_exclamation_mark
	walk_slower_right
	walk_slower_up
	face_player
	step_end

NewBarkTown_Interior1_EventScript_Trigger1_4::
	msgbox NewBarkTown_Interior1_Text_Trigger1_4, MSGBOX_NPC
	msgbox NewBarkTown_Interior1_Text_Trigger1_5, MSGBOX_NPC
	applymovement 1, NewBarkTown_Interior1_Movement_Trigger1_2
	delay 64
	playbgm MUS_MYSTERY_GIFT, 51
	setflag 0x11D6
	release
	end

NewBarkTown_Interior1_Movement_Trigger1_2::
	walk_slower_down
	walk_slower_left
	step_end

NewBarkTown_Interior1_EventScript_Sign::
	lockall
	goto_if_eq VAR_FACING, 2, NewBarkTown_Interior1_EventScript_Sign_1
	msgbox NewBarkTown_Interior1_Text_Sign_1
	releaseall
	end

NewBarkTown_Interior1_EventScript_Sign_1::
	checkplayergender
	call_if_eq VAR_RESULT, 0, NewBarkTown_Interior1_EventScript_Sign_2
	call_if_eq VAR_RESULT, 1, NewBarkTown_Interior1_EventScript_Sign_3
	releaseall
	end

NewBarkTown_Interior1_EventScript_Sign_2::
	msgbox NewBarkTown_Interior1_Text_Sign_2
	return

NewBarkTown_Interior1_EventScript_Sign_3::
	msgbox NewBarkTown_Interior1_Text_Sign_3
	return
