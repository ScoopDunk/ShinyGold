CeladonCity_Interior12_MapScripts::
	.byte 0

CeladonCity_Interior12_EventScript_Gentleman::
	msgbox CeladonCity_Interior12_Text_Gentleman, MSGBOX_NPC
	end

CeladonCity_Interior12_EventScript_PokeManiac::
	msgbox CeladonCity_Interior12_Text_PokeManiac, MSGBOX_NPC
	end

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist::
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_1
	showcoinsbox 0, 0
	multichoice 14, 0, MULTICHOICE_GAME_CORNER_BATTLE_ITEM_PRIZES, 0
	copyvar VAR_0x8009, VAR_RESULT
	switch VAR_RESULT
	call_if_eq VAR_0x8000, 0, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_1
	call_if_eq VAR_0x8000, 1, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_2
	call_if_eq VAR_0x8000, 2, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_3
	call_if_eq VAR_0x8000, 3, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_4
	call_if_eq VAR_0x8000, 4, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_5
	call_if_eq VAR_0x8000, 5, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_6
	call_if_eq VAR_0x8000, 127, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_6
	end

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_1::
	msgbox CeladonCity_Interior12_Text_UnusedMaleReceptionist_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_6
	goto CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_6

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_2::
	msgbox CeladonCity_Interior12_Text_UnusedMaleReceptionist_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_6
	goto CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_7

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_3::
	msgbox CeladonCity_Interior12_Text_UnusedMaleReceptionist_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_6
	goto CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_8

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_4::
	msgbox CeladonCity_Interior12_Text_UnusedMaleReceptionist_4, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_6
	goto CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_9

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_5::
	msgbox CeladonCity_Interior12_Text_UnusedMaleReceptionist_5, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist_6
	goto CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_10

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_6::
	checkcoins VAR_TEMP_1
	call_if_ge VAR_TEMP_1, 0x3E7, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_11
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_7, MSGBOX_NPC
	hidecoinsbox 2, 255
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_7::
	checkcoins VAR_TEMP_1
	call_if_ge VAR_TEMP_1, 0xD05, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_12
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_7, MSGBOX_NPC
	hidecoinsbox 2, 255
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_8::
	checkcoins VAR_TEMP_1
	call_if_ge VAR_TEMP_1, 0x1A0A, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_13
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_7, MSGBOX_NPC
	hidecoinsbox 2, 255
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_9::
	checkcoins VAR_TEMP_1
	call_if_ge VAR_TEMP_1, 0x22B8, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_14
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_7, MSGBOX_NPC
	hidecoinsbox 2, 255
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_10::
	checkcoins VAR_TEMP_1
	call_if_ge VAR_TEMP_1, 0x270F, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_15
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_7, MSGBOX_NPC
	hidecoinsbox 2, 255
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_11::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_SHOP
	loadword 0, 0x6B01
	hidecoinsbox 0, 0
	removecoins 0x3E7
	nop
	nop
	msgbox CeladonCity_Interior12_Text_UnusedMaleReceptionist_6, MSGBOX_NPC
	.byte 0x79 @ givemon
	.2byte SPECIES_CASTFORM
	.byte 5
	.2byte ITEM_NONE
	.4byte 0xFFFFFF02
	.4byte 0xFFFFFFFF
	.byte 255
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_12::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_SHOP
	loadword 0, 0x6B01
	hidecoinsbox 0, 0
	removecoins 0xD05
	nop
	nop
	msgbox CeladonCity_Interior12_Text_UnusedMaleReceptionist_7, MSGBOX_NPC
	.byte 0x79 @ givemon
	.2byte SPECIES_MR_MIME
	.byte 5
	.2byte ITEM_NONE
	.4byte 0xFFFFFF02
	.4byte 0xFFFFFFFF
	.byte 255
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_13::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_SHOP
	loadword 0, 0x6B01
	hidecoinsbox 0, 0
	removecoins 0x1A0A
	nop
	nop
	msgbox CeladonCity_Interior12_Text_UnusedMaleReceptionist_8, MSGBOX_NPC
	.byte 0x79 @ givemon
	.2byte SPECIES_EEVEE
	.byte 5
	.2byte ITEM_NONE
	.4byte 0xFFFFFF02
	.4byte 0xFFFFFFFF
	.byte 255
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_14::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_SHOP
	loadword 0, 0x6B01
	hidecoinsbox 0, 0
	removecoins 0x22B8
	nop
	nop
	msgbox CeladonCity_Interior12_Text_UnusedMaleReceptionist_9, MSGBOX_NPC
	.byte 0x79 @ givemon
	.2byte SPECIES_BAGON
	.byte 5
	.2byte ITEM_NONE
	.4byte 0xFFFFFF02
	.4byte 0xFFFFFFFF
	.byte 255
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist_15::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_SHOP
	loadword 0, 0x6B01
	hidecoinsbox 0, 0
	removecoins 0x270F
	nop
	nop
	msgbox CeladonCity_Interior12_Text_UnusedMaleReceptionist_10, MSGBOX_NPC
	.byte 0x79 @ givemon
	.2byte SPECIES_PORYGON
	.byte 5
	.2byte ITEM_NONE
	.4byte 0xD9DC02
	.4byte 0xEDD5EB
	.byte 232
	.byte 0xE3 @ invalid opcode (script stops)

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2::
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_1
	showcoinsbox 0, 0
	multichoice 14, 0, MULTICHOICE_SEAGALLOP_123, 0
	copyvar VAR_0x8009, VAR_RESULT
	switch VAR_RESULT
	call_if_eq VAR_0x8000, 0, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_1
	call_if_eq VAR_0x8000, 1, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_2
	call_if_eq VAR_0x8000, 2, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_3
	call_if_eq VAR_0x8000, 3, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_6
	call_if_eq VAR_0x8000, 127, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_6
	end

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_1::
	msgbox CeladonCity_Interior12_Text_UnusedMaleReceptionist2_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_6
	goto CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_4

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_2::
	msgbox CeladonCity_Interior12_Text_UnusedMaleReceptionist2_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_6
	goto CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_5

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_3::
	msgbox CeladonCity_Interior12_Text_UnusedMaleReceptionist2_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior1_EventScript_CableClubReceptionist2_6
	goto CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_6

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_4::
	checkcoins VAR_TEMP_1
	call_if_ge VAR_TEMP_1, 0x5DC, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_7
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_7, MSGBOX_NPC
	hidecoinsbox 2, 255
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_5::
	checkcoins VAR_TEMP_1
	call_if_ge VAR_TEMP_1, 0xDAC, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_8
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_7, MSGBOX_NPC
	hidecoinsbox 2, 255
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_6::
	checkcoins VAR_TEMP_1
	call_if_ge VAR_TEMP_1, 0x1D4C, CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_9
	msgbox GoldenrodCity_Interior1_Text_CableClubReceptionist_7, MSGBOX_NPC
	hidecoinsbox 2, 255
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_7::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_SHOP
	loadword 0, 0x6B01
	hidecoinsbox 0, 0
	removecoins 0x5DC
	nop
	nop
	giveitem ITEM_TM32
	release
	end

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_8::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_SHOP
	loadword 0, 0x6B01
	hidecoinsbox 0, 0
	removecoins 0xDAC
	nop
	nop
	giveitem ITEM_TM29
	release
	end

CeladonCity_Interior12_EventScript_UnusedMaleReceptionist2_9::
	updatemoneybox
	updatecoinsbox 0, 5
	playse SE_SHOP
	loadword 0, 0x6B01
	hidecoinsbox 0, 0
	removecoins 0x1D4C
	nop
	nop
	giveitem ITEM_TM15
	release
	end
