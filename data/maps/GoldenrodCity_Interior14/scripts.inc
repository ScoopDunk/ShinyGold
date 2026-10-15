GoldenrodCity_Interior14_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

GoldenrodCity_Interior14_EventScript_Trigger1::
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior14_EventScript_Trigger1_1
	call_if_eq VAR_RESULT, 1, GoldenrodCity_Interior14_EventScript_Trigger1_2
	call_if_eq VAR_RESULT, 2, GoldenrodCity_Interior14_EventScript_Trigger1_3
	call_if_eq VAR_RESULT, 3, GoldenrodCity_Interior14_EventScript_Trigger1_4
	call_if_eq VAR_RESULT, 4, GoldenrodCity_Interior14_EventScript_Trigger1_5
	call_if_eq VAR_RESULT, 5, GoldenrodCity_Interior14_EventScript_Trigger1_6
	warp MAP_GOLDENROD_CITY_INTERIOR13, 1, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior14_EventScript_Trigger1_1::
	warp MAP_GOLDENROD_CITY_INTERIOR15, 0, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior14_EventScript_Trigger1_2::
	@ ShinyGold: overlapping data duplicated from 0x0874E570
	warp MAP_GOLDENROD_CITY_INTERIOR8, 2, 0xFF02, 0x39FF
	compare_var_to_var 0x001C, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior14_EventScript_Trigger1_3::
	warp MAP_GOLDENROD_CITY_INTERIOR9, 2, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior14_EventScript_Trigger1_4::
	@ ShinyGold: overlapping data duplicated from 0x0874E560
	warp MAP_GOLDENROD_CITY_INTERIOR10, 2, 0xFF02, 0x39FF
	compare_var_to_var 0x0216, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior14_EventScript_Trigger1_5::
	warp MAP_GOLDENROD_CITY_INTERIOR11, 2, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior14_EventScript_Trigger1_6::
	@ ShinyGold: overlapping data duplicated from 0x0874E550
	warp MAP_GOLDENROD_CITY_INTERIOR12, 2, 0xFF02, 0x39FF
	compare_var_to_var 0x0218, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior14_EventScript_Sign::
	copyvar VAR_0x8001, VAR_RESULT
	msgbox GoldenrodCity_Interior14_Text_Sign_1, MSGBOX_NPC
	multichoice 14, 0, MULTICHOICE_SEVII_NAVEL_BIRTH, 0
	copyvar VAR_0x8009, VAR_RESULT
	switch VAR_RESULT
	call_if_eq VAR_0x8000, 0, GoldenrodCity_Interior14_EventScript_Sign_1
	call_if_eq VAR_0x8000, 1, GoldenrodCity_Interior14_EventScript_Sign_2
	call_if_eq VAR_0x8000, 2, GoldenrodCity_Interior14_EventScript_Sign_3
	call_if_eq VAR_0x8000, 3, GoldenrodCity_Interior14_EventScript_Sign_4
	call_if_eq VAR_0x8000, 127, GoldenrodCity_Interior14_EventScript_Sign_4
	end

GoldenrodCity_Interior14_EventScript_Sign_1::
	msgbox GoldenrodCity_Interior14_Text_Sign_2, MSGBOX_NPC
	setvar VAR_RESULT, 0
	end

GoldenrodCity_Interior14_EventScript_Sign_2::
	msgbox GoldenrodCity_Interior14_Text_Sign_3, MSGBOX_NPC
	setvar VAR_RESULT, 6
	end

GoldenrodCity_Interior14_EventScript_Sign_3::
	multichoice 14, 0, MULTICHOICE_DEPT_STORE_ELEVATOR, 0
	copyvar VAR_0x8009, VAR_RESULT
	switch VAR_RESULT
	call_if_eq VAR_0x8000, 0, GoldenrodCity_Interior14_EventScript_Sign_5
	call_if_eq VAR_0x8000, 1, GoldenrodCity_Interior14_EventScript_Sign_6
	call_if_eq VAR_0x8000, 2, GoldenrodCity_Interior14_EventScript_Sign_7
	call_if_eq VAR_0x8000, 3, GoldenrodCity_Interior14_EventScript_Sign_8
	call_if_eq VAR_0x8000, 4, GoldenrodCity_Interior14_EventScript_Sign_9
	call_if_eq VAR_0x8000, 5, GoldenrodCity_Interior14_EventScript_Sign_4
	call_if_eq VAR_0x8000, 127, GoldenrodCity_Interior14_EventScript_Sign_4
	end

GoldenrodCity_Interior14_EventScript_Sign_4::
	copyvar VAR_RESULT, VAR_0x8001
	end

GoldenrodCity_Interior14_EventScript_Sign_5::
	msgbox GoldenrodCity_Interior14_Text_Sign_4, MSGBOX_NPC
	setvar VAR_RESULT, 5
	end

GoldenrodCity_Interior14_EventScript_Sign_6::
	msgbox GoldenrodCity_Interior14_Text_Sign_5, MSGBOX_NPC
	setvar VAR_RESULT, 4
	end

GoldenrodCity_Interior14_EventScript_Sign_7::
	msgbox GoldenrodCity_Interior14_Text_Sign_6, MSGBOX_NPC
	setvar VAR_RESULT, 3
	end

GoldenrodCity_Interior14_EventScript_Sign_8::
	msgbox GoldenrodCity_Interior14_Text_Sign_7, MSGBOX_NPC
	setvar VAR_RESULT, 2
	end

GoldenrodCity_Interior14_EventScript_Sign_9::
	msgbox GoldenrodCity_Interior14_Text_Sign_8, MSGBOX_NPC
	setvar VAR_RESULT, 1
	end
