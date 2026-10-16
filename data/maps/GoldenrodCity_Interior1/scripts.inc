GoldenrodCity_Interior1_MapScripts::
	.byte 0

GoldenrodCity_Interior1_EventScript_BaldingMan::
	msgbox GoldenrodCity_Interior1_Text_BaldingMan, MSGBOX_NPC
	end

GoldenrodCity_Interior1_EventScript_Beauty::
	msgbox GoldenrodCity_Interior1_Text_Beauty, MSGBOX_NPC
	end

GoldenrodCity_Interior1_EventScript_Gentleman::
	msgbox GoldenrodCity_Interior1_Text_Gentleman, MSGBOX_NPC
	end

GoldenrodCity_Interior1_EventScript_Rocker::
	msgbox GoldenrodCity_Interior1_Text_Rocker, MSGBOX_NPC
	end

GoldenrodCity_Interior1_EventScript_Man::
	msgbox GoldenrodCity_Interior1_Text_Man, MSGBOX_NPC
	end

GoldenrodCity_Interior1_EventScript_Woman3::
	msgbox GoldenrodCity_Interior1_Text_Woman3, MSGBOX_NPC
	end

GoldenrodCity_Interior1_EventScript_WorkerM::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	showmoneybox 0, 0
	showcoinsbox 0, 5
	message GoldenrodCity_Interior1_Text_WorkerM_1
	waitmessage
	multichoice 13, 0, MULTICHOICE_GAME_CORNER_COIN_PURCHASE_COUNTER, 0
	copyvar VAR_0x8009, VAR_RESULT
	switch VAR_RESULT
	case 0, GoldenrodCity_Interior1_EventScript_WorkerM_1
	case 1, GoldenrodCity_Interior1_EventScript_WorkerM_1
	case 2, GoldenrodCity_Interior1_EventScript_WorkerM_2
	case 127, GoldenrodCity_Interior1_EventScript_WorkerM_2
	end

GoldenrodCity_Interior1_EventScript_WorkerM_1::
	goto_if_unset 0x243, GoldenrodCity_Interior1_EventScript_WorkerM_3
	goto_if_eq VAR_0x8009, 0, GoldenrodCity_Interior1_EventScript_WorkerM_4
	goto_if_eq VAR_0x8009, 1, GoldenrodCity_Interior1_EventScript_WorkerM_5
	end

GoldenrodCity_Interior1_EventScript_WorkerM_2::
	msgbox GoldenrodCity_Interior1_Text_WorkerM_2
	goto GoldenrodCity_Interior1_EventScript_WorkerM_6

GoldenrodCity_Interior1_EventScript_WorkerM_3::
	msgbox GoldenrodCity_Interior1_Text_WorkerM_3
	goto GoldenrodCity_Interior1_EventScript_WorkerM_6

GoldenrodCity_Interior1_EventScript_WorkerM_4::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, 0x26DE, GoldenrodCity_Interior1_EventScript_WorkerM_7
	checkmoney 0x3E8
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_WorkerM_8
	addcoins 50
	removemoney 0x3E8
	goto GoldenrodCity_Interior1_EventScript_WorkerM_9

GoldenrodCity_Interior1_EventScript_WorkerM_5::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, 0x251C, GoldenrodCity_Interior1_EventScript_WorkerM_7
	checkmoney 0x2710
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_WorkerM_8
	addcoins 0x1F4
	removemoney 0x2710
	goto GoldenrodCity_Interior1_EventScript_WorkerM_9

GoldenrodCity_Interior1_EventScript_WorkerM_6::
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GoldenrodCity_Interior1_EventScript_WorkerM_7::
	msgbox GoldenrodCity_Interior1_Text_WorkerM_4
	goto GoldenrodCity_Interior1_EventScript_WorkerM_6

GoldenrodCity_Interior1_EventScript_WorkerM_8::
	msgbox GoldenrodCity_Interior1_Text_WorkerM_5
	goto GoldenrodCity_Interior1_EventScript_WorkerM_6

GoldenrodCity_Interior1_EventScript_WorkerM_9::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_SHOP
	msgbox GoldenrodCity_Interior1_Text_WorkerM_6
	goto GoldenrodCity_Interior1_EventScript_WorkerM_6

GoldenrodCity_Interior1_EventScript_CableClubReceptionist::
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_1
	showcoinsbox 0, 0
	multichoice 14, 0, MULTICHOICE_GAME_CORNER_POKEMON_PRIZES, 0
	copyvar VAR_0x8009, VAR_RESULT
	switch VAR_RESULT
	call_if_eq VAR_0x8000, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_1
	call_if_eq VAR_0x8000, 1, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_2
	call_if_eq VAR_0x8000, 2, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_3
	call_if_eq VAR_0x8000, 3, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_6
	call_if_eq VAR_0x8000, 127, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_6
	end

GoldenrodCity_Interior1_EventScript_CableClubReceptionist_1::
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_6
	goto GoldenrodCity_Interior1_EventScript_CableClubReceptionist_7

GoldenrodCity_Interior1_EventScript_CableClubReceptionist_2::
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_6
	goto GoldenrodCity_Interior1_EventScript_CableClubReceptionist_8

GoldenrodCity_Interior1_EventScript_CableClubReceptionist_3::
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_4, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_6
	goto GoldenrodCity_Interior1_EventScript_CableClubReceptionist_9

GoldenrodCity_Interior1_EventScript_CableClubReceptionist_6::
	hidecoinsbox 104, 148
	nop
	nop1
	releaseall
	end

GoldenrodCity_Interior1_EventScript_CableClubReceptionist_7::
	checkcoins VAR_TEMP_1
	call_if_ge VAR_TEMP_1, 200, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_12
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_7, MSGBOX_NPC
	hidecoinsbox 2, 148
	nop
	nop
	hidecoinsbox 0, 5
	release
	end

GoldenrodCity_Interior1_EventScript_CableClubReceptionist_8::
	checkcoins VAR_TEMP_1
	call_if_ge VAR_TEMP_1, 0x2BC, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_13
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_7, MSGBOX_NPC
	hidecoinsbox 2, 255
	@ ShinyGold fix: ended in a condition-table read out of range and an invalid opcode, leaving the NPC locked
	release
	end

GoldenrodCity_Interior1_EventScript_CableClubReceptionist_9::
	checkcoins VAR_TEMP_1
	call_if_ge VAR_TEMP_1, 0x834, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_14
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_7, MSGBOX_NPC
	hidecoinsbox 2, 255
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior1_EventScript_CableClubReceptionist_12::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_SHOP
	loadword 0, 0x6B01
	hidecoinsbox 0, 0
	removecoins 200
	nop
	nop
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_8, MSGBOX_NPC
	.byte 0x79 @ givemon
	.2byte SPECIES_ABRA
	.byte 10
	.2byte ITEM_NONE
	.4byte 0xFF020002
	.4byte 0xFFFFFFFF
	.byte 255
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior1_EventScript_CableClubReceptionist_13::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_SHOP
	loadword 0, 0x6B01
	hidecoinsbox 0, 0
	removecoins 0x2BC
	nop
	nop
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_9, MSGBOX_NPC
	.byte 0x79 @ givemon
	.2byte SPECIES_EKANS
	.byte 10
	.2byte ITEM_NONE
	.4byte 0xFFFFFF02
	.4byte 0xFFFFFFFF
	.byte 255
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior1_EventScript_CableClubReceptionist_14::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_SHOP
	loadword 0, 0x6B01
	hidecoinsbox 0, 0
	removecoins 0x834
	nop
	nop
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_10, MSGBOX_NPC
	.byte 0x79 @ givemon
	.2byte SPECIES_DRATINI
	.byte 10
	.2byte ITEM_NONE
	.4byte 0xFFFFFF02
	.4byte 0xFFFFFFFF
	.byte 255
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior1_EventScript_CableClubReceptionist2::
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_1
	showcoinsbox 0, 0
	multichoice 14, 0, MULTICHOICE_GAME_CORNER_TMPRIZES, 0
	copyvar VAR_0x8009, VAR_RESULT
	switch VAR_RESULT
	call_if_eq VAR_0x8000, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_1
	call_if_eq VAR_0x8000, 1, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_2
	call_if_eq VAR_0x8000, 2, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_3
	call_if_eq VAR_0x8000, 3, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_6
	call_if_eq VAR_0x8000, 127, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_6
	end

GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_1::
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist2_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_6
	goto GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_7

GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_2::
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist2_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_6
	goto GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_8

GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_3::
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist2_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_6
	goto GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_9

GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_6::
	hidecoinsbox 104, 148
	nop
	nop1
	releaseall
	end

GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_7::
	checkcoins VAR_TEMP_1
	call_if_ge VAR_TEMP_1, 0x157C, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_12
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_7, MSGBOX_NPC
	hidecoinsbox 2, 255
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_8::
	checkcoins VAR_TEMP_1
	call_if_ge VAR_TEMP_1, 0x157C, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_13
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_7, MSGBOX_NPC
	hidecoinsbox 2, 255
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_9::
	checkcoins VAR_TEMP_1
	call_if_ge VAR_TEMP_1, 0x157C, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_14
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_7, MSGBOX_NPC
	hidecoinsbox 2, 255
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_12::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_SHOP
	loadword 0, 0x6B01
	hidecoinsbox 0, 0
	removecoins 0x157C
	nop
	nop
	giveitem ITEM_TM25
	release
	end

GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_13::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_SHOP
	loadword 0, 0x6B01
	hidecoinsbox 0, 0
	removecoins 0x157C
	nop
	nop
	giveitem ITEM_TM14
	release
	end

GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_14::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_SHOP
	loadword 0, 0x6B01
	hidecoinsbox 0, 0
	removecoins 0x157C
	nop
	nop
	giveitem ITEM_TM38
	release
	end

GoldenrodCity_Interior1_EventScript_Sign1::
	lockall
	setvar VAR_0x8004, 0
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign1_1::
	goto_if_unset 0x243, GoldenrodCity_Interior1_EventScript_Sign1_2
	msgbox GoldenrodCity_Interior1_Text_Sign1_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_Sign1_3
	setfieldeffectargument 0, 255
	setfieldeffectargument 1, 10
	setfieldeffectargument 2, 14
	dofieldeffect FLDEFF_SMILEY_FACE_ICON
	waitfieldeffect FLDEFF_SMILEY_FACE_ICON
	specialvar VAR_RESULT, GetRandomSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GoldenrodCity_Interior1_EventScript_Sign1_2::
	msgbox GoldenrodCity_Interior1_Text_Sign1_2
	releaseall
	end

GoldenrodCity_Interior1_EventScript_Sign1_3::
	releaseall
	end

GoldenrodCity_Interior1_EventScript_Sign2::
	lockall
	setvar VAR_0x8004, 1
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign3::
	lockall
	setvar VAR_0x8004, 2
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign5::
	lockall
	setvar VAR_0x8004, 3
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign6::
	lockall
	setvar VAR_0x8004, 8
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign7::
	lockall
	setvar VAR_0x8004, 7
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign8::
	lockall
	setvar VAR_0x8004, 6
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign9::
	lockall
	setvar VAR_0x8004, 5
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign10::
	msgbox GoldenrodCity_Interior1_Text_Sign10, MSGBOX_SIGN
	end

GoldenrodCity_Interior1_EventScript_Sign11::
	lockall
	setvar VAR_0x8004, 12
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign13::
	lockall
	setvar VAR_0x8004, 11
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign14::
	lockall
	setvar VAR_0x8004, 10
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign15::
	lockall
	setvar VAR_0x8004, 9
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign16::
	lockall
	setvar VAR_0x8004, 17
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign17::
	lockall
	setvar VAR_0x8004, 16
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign18::
	msgbox GoldenrodCity_Interior1_Text_Sign18, MSGBOX_SIGN
	end

GoldenrodCity_Interior1_EventScript_Sign20::
	lockall
	setvar VAR_0x8004, 13
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign21::
	lockall
	setvar VAR_0x8004, 21
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign22::
	lockall
	setvar VAR_0x8004, 20
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign23::
	lockall
	setvar VAR_0x8004, 19
	goto GoldenrodCity_Interior1_EventScript_Sign1_1

GoldenrodCity_Interior1_EventScript_Sign24::
	msgbox GoldenrodCity_Interior1_Text_Sign24, MSGBOX_SIGN
	end
