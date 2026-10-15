CeladonCity_Interior6_MapScripts::
	.byte 0

CeladonCity_Interior6_EventScript_Boy::
	msgbox CeladonCity_Interior6_Text_Boy, MSGBOX_NPC
	end

CeladonCity_Interior6_EventScript_PokeManiac::
	msgbox CeladonCity_Interior6_Text_PokeManiac, MSGBOX_NPC
	end

CeladonCity_Interior6_EventScript_Sign1::
	msgbox CeladonCity_Interior6_Text_Sign1, MSGBOX_SIGN
	end

CeladonCity_Interior6_EventScript_Sign2::
	lockall
	message CeladonCity_Interior6_Text_Sign2_1
	waitmessage
	showmoneybox 0, 0
	goto CeladonCity_Interior6_EventScript_Sign2_1

CeladonCity_Interior6_EventScript_Sign2_1::
	multichoice 12, 0, MULTICHOICE_CELADON_VENDING_MACHINE, 0
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, CeladonCity_Interior6_EventScript_Sign2_2
	case 1, CeladonCity_Interior6_EventScript_Sign2_3
	case 2, CeladonCity_Interior6_EventScript_Sign2_4
	msgbox CeladonCity_Interior6_Text_Sign2_2
	goto CeladonCity_Interior6_EventScript_Sign2_5

CeladonCity_Interior6_EventScript_Sign2_2::
	setvar VAR_TEMP_0, 26
	checkmoney 200
	goto CeladonCity_Interior6_EventScript_Sign2_6

CeladonCity_Interior6_EventScript_Sign2_3::
	setvar VAR_TEMP_0, 27
	checkmoney 0x12C
	goto CeladonCity_Interior6_EventScript_Sign2_6

CeladonCity_Interior6_EventScript_Sign2_4::
	setvar VAR_TEMP_0, 28
	checkmoney 0x15E
	goto CeladonCity_Interior6_EventScript_Sign2_6

CeladonCity_Interior6_EventScript_Sign2_5::
	hidemoneybox
	releaseall
	end

CeladonCity_Interior6_EventScript_Sign2_6::
	goto_if_eq VAR_RESULT, 0, CeladonCity_Interior6_EventScript_Sign2_7
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, 0, CeladonCity_Interior6_EventScript_Sign2_8
	call_if_eq VAR_TEMP_1, 0, CeladonCity_Interior6_EventScript_Sign2_9
	call_if_eq VAR_TEMP_1, 1, CeladonCity_Interior6_EventScript_Sign2_10
	call_if_eq VAR_TEMP_1, 2, CeladonCity_Interior6_EventScript_Sign2_11
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox CeladonCity_Interior6_Text_Sign2_3
	additem VAR_TEMP_0
	goto CeladonCity_Interior6_EventScript_Sign2_12

CeladonCity_Interior6_EventScript_Sign2_7::
	msgbox CeladonCity_Interior6_Text_Sign2_4
	goto CeladonCity_Interior6_EventScript_Sign2_5

CeladonCity_Interior6_EventScript_Sign2_8::
	msgbox CeladonCity_Interior6_Text_Sign2_5
	goto CeladonCity_Interior6_EventScript_Sign2_5

CeladonCity_Interior6_EventScript_Sign2_9::
	removemoney 200
	return

CeladonCity_Interior6_EventScript_Sign2_10::
	removemoney 0x12C
	return

CeladonCity_Interior6_EventScript_Sign2_11::
	removemoney 0x15E
	return

CeladonCity_Interior6_EventScript_Sign2_12::
	message CeladonCity_Interior6_Text_Sign2_1
	waitmessage
	goto CeladonCity_Interior6_EventScript_Sign2_1

CeladonCity_Interior6_EventScript_Sign3::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeladonCity_Interior6_EventScript_Sign2
	call_if_eq VAR_0x8008, 1, CeladonCity_Interior6_EventScript_Sign2
	call_if_eq VAR_0x8008, 2, CeladonCity_Interior6_EventScript_Sign2
	call_if_eq VAR_0x8008, 3, CeladonCity_Interior6_EventScript_Sign3_1
	end

CeladonCity_Interior6_EventScript_Sign3_1::
	msgbox CeladonCity_Interior6_Text_Sign3, MSGBOX_NPC
	giveitem ITEM_LEMONADE
	release
	end
