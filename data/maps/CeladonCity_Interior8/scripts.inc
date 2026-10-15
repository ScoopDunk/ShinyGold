CeladonCity_Interior8_MapScripts::
	.byte 0

CeladonCity_Interior8_EventScript_PokeManiac::
	call_if_set 0x11E5, CeladonCity_Interior8_EventScript_PokeManiac_1
	msgbox CeladonCity_Interior8_Text_PokeManiac_1, MSGBOX_NPC
	msgbox CeladonCity_Interior8_Text_PokeManiac_2, MSGBOX_NPC
	giveitem ITEM_TM03
	msgbox CeladonCity_Interior8_Text_PokeManiac_3, MSGBOX_NPC
	setflag 0x11E5
	release
	end

CeladonCity_Interior8_EventScript_PokeManiac_1::
	msgbox CeladonCity_Interior8_Text_PokeManiac_3, MSGBOX_NPC
	end

CeladonCity_Interior8_EventScript_ItemBall::
	lock
	faceplayer
	setvar VAR_TEMP_1, 133
	givemon SPECIES_EEVEE, 25
	goto_if_eq VAR_RESULT, 0, CeladonCity_Interior8_EventScript_ItemBall_1
	goto_if_eq VAR_RESULT, 1, CeladonCity_Interior8_EventScript_ItemBall_2
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
	release
	end

CeladonCity_Interior8_EventScript_ItemBall_1::
	removeobject 2
	playfanfare MUS_LEVEL_UP
	message CeladonCity_Interior8_Text_ItemBall
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, CeladonCity_Interior8_EventScript_ItemBall_3
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto CeladonCity_Interior8_EventScript_ItemBall_3

CeladonCity_Interior8_EventScript_ItemBall_2::
	removeobject 2
	playfanfare MUS_LEVEL_UP
	message CeladonCity_Interior8_Text_ItemBall
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, CeladonCity_Interior8_EventScript_ItemBall_4
	call EventScript_NameReceivedBoxMon
	goto CeladonCity_Interior8_EventScript_ItemBall_4

CeladonCity_Interior8_EventScript_ItemBall_3::
	setflag 0x263
	release
	end

CeladonCity_Interior8_EventScript_ItemBall_4::
	call EventScript_TransferredToPC
	goto CeladonCity_Interior8_EventScript_ItemBall_3

CeladonCity_Interior8_EventScript_Sign1::
	lockall
	msgbox CeladonCity_Interior8_Text_Sign1_1
	message CeladonCity_Interior8_Text_Sign1_2
	waitmessage
	setvar VAR_0x8004, 4
	multichoice 0, 0, MULTICHOICE_LINKED_DIRECT_UNION, 0
	switch VAR_RESULT
	case 0, CeladonCity_Interior8_EventScript_Sign1_1
	case 1, CeladonCity_Interior8_EventScript_Sign1_2
	case 2, CeladonCity_Interior8_EventScript_Sign1_3
	case 3, CeladonCity_Interior8_EventScript_Sign1_4
	case 127, CeladonCity_Interior8_EventScript_Sign1_4
	end

CeladonCity_Interior8_EventScript_Sign1_1::
	msgbox CeladonCity_Interior8_Text_Sign1_3
	goto CeladonCity_Interior8_EventScript_Sign1_5

CeladonCity_Interior8_EventScript_Sign1_2::
	msgbox CeladonCity_Interior8_Text_Sign1_4
	goto CeladonCity_Interior8_EventScript_Sign1_5

CeladonCity_Interior8_EventScript_Sign1_3::
	msgbox CeladonCity_Interior8_Text_Sign1_5
	goto CeladonCity_Interior8_EventScript_Sign1_5

CeladonCity_Interior8_EventScript_Sign1_4::
	releaseall
	end

CeladonCity_Interior8_EventScript_Sign1_5::
	message CeladonCity_Interior8_Text_Sign1_2
	waitmessage
	multichoice 0, 0, MULTICHOICE_LINKED_DIRECT_UNION, 0
	switch VAR_RESULT
	case 0, CeladonCity_Interior8_EventScript_Sign1_1
	case 1, CeladonCity_Interior8_EventScript_Sign1_2
	case 2, CeladonCity_Interior8_EventScript_Sign1_3
	case 3, CeladonCity_Interior8_EventScript_Sign1_4
	case 127, CeladonCity_Interior8_EventScript_Sign1_4
	end

CeladonCity_Interior8_EventScript_Sign3::
	msgbox CeladonCity_Interior8_Text_Sign3, MSGBOX_SIGN
	end
