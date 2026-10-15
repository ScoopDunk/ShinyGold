Route39_Interior2_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Route39_Interior2_EventScript_Slowbro::
	call_if_set 0x10B1, Route39_Interior2_EventScript_Slowbro_1
	call_if_set 0x10B8, Route39_Interior2_EventScript_Slowbro_2
	call_if_set 0x10B7, Route39_Interior2_EventScript_Slowbro_3
	call_if_set 0x10B6, Route39_Interior2_EventScript_Slowbro_4
	call_if_set 0x10B5, Route39_Interior2_EventScript_Slowbro_5
	call_if_set 0x10B4, Route39_Interior2_EventScript_Slowbro_6
	call_if_set 0x10B3, Route39_Interior2_EventScript_Slowbro_7
	call Route39_Interior2_EventScript_Slowbro_8
	end

Route39_Interior2_EventScript_Slowbro_1::
	msgbox Route39_Interior2_Text_Slowbro_1, MSGBOX_NPC
	waitse
	playmoncry SPECIES_MILTANK, 0x202
	.byte 0xFF @ invalid opcode (script stops)

Route39_Interior2_EventScript_Slowbro_2::
	msgbox Route39_Interior2_Text_Slowbro_2, MSGBOX_NPC
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_FAINT
	checkitem ITEM_ORAN_BERRY
	call_if_eq VAR_RESULT, 1, Route39_Interior2_EventScript_Slowbro_9
	end

Route39_Interior2_EventScript_Slowbro_3::
	msgbox Route39_Interior2_Text_Slowbro_2, MSGBOX_NPC
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_FAINT
	checkitem ITEM_ORAN_BERRY
	call_if_eq VAR_RESULT, 1, Route39_Interior2_EventScript_Slowbro_10
	end

Route39_Interior2_EventScript_Slowbro_4::
	msgbox Route39_Interior2_Text_Slowbro_2, MSGBOX_NPC
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_FAINT
	checkitem ITEM_ORAN_BERRY
	call_if_eq VAR_RESULT, 1, Route39_Interior2_EventScript_Slowbro_11
	end

Route39_Interior2_EventScript_Slowbro_5::
	msgbox Route39_Interior2_Text_Slowbro_2, MSGBOX_NPC
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_FAINT
	checkitem ITEM_ORAN_BERRY
	call_if_eq VAR_RESULT, 1, Route39_Interior2_EventScript_Slowbro_12
	end

Route39_Interior2_EventScript_Slowbro_6::
	msgbox Route39_Interior2_Text_Slowbro_2, MSGBOX_NPC
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_FAINT
	checkitem ITEM_ORAN_BERRY
	call_if_eq VAR_RESULT, 1, Route39_Interior2_EventScript_Slowbro_13
	end

Route39_Interior2_EventScript_Slowbro_7::
	msgbox Route39_Interior2_Text_Slowbro_2, MSGBOX_NPC
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_FAINT
	checkitem ITEM_ORAN_BERRY
	call_if_eq VAR_RESULT, 1, Route39_Interior2_EventScript_Slowbro_14
	end

Route39_Interior2_EventScript_Slowbro_8::
	msgbox Route39_Interior2_Text_Slowbro_2, MSGBOX_NPC
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_FAINT
	checkitem ITEM_ORAN_BERRY
	call_if_eq VAR_RESULT, 1, Route39_Interior2_EventScript_Slowbro_15
	end

Route39_Interior2_EventScript_Slowbro_9::
	msgbox Route39_Interior2_Text_Slowbro_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route39_Interior2_EventScript_Slowbro_16
	msgbox Route39_Interior2_Text_Slowbro_4, MSGBOX_NPC
	end

Route39_Interior2_EventScript_Slowbro_10::
	msgbox Route39_Interior2_Text_Slowbro_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route39_Interior2_EventScript_Slowbro_17
	msgbox Route39_Interior2_Text_Slowbro_4, MSGBOX_NPC
	end

Route39_Interior2_EventScript_Slowbro_11::
	msgbox Route39_Interior2_Text_Slowbro_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route39_Interior2_EventScript_Slowbro_18
	msgbox Route39_Interior2_Text_Slowbro_4, MSGBOX_NPC
	end

Route39_Interior2_EventScript_Slowbro_12::
	msgbox Route39_Interior2_Text_Slowbro_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route39_Interior2_EventScript_Slowbro_19
	msgbox Route39_Interior2_Text_Slowbro_4, MSGBOX_NPC
	end

Route39_Interior2_EventScript_Slowbro_13::
	msgbox Route39_Interior2_Text_Slowbro_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route39_Interior2_EventScript_Slowbro_20
	msgbox Route39_Interior2_Text_Slowbro_4, MSGBOX_NPC
	end

Route39_Interior2_EventScript_Slowbro_14::
	msgbox Route39_Interior2_Text_Slowbro_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route39_Interior2_EventScript_Slowbro_21
	msgbox Route39_Interior2_Text_Slowbro_4, MSGBOX_NPC
	end

Route39_Interior2_EventScript_Slowbro_15::
	msgbox Route39_Interior2_Text_Slowbro_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route39_Interior2_EventScript_Slowbro_22
	msgbox Route39_Interior2_Text_Slowbro_4, MSGBOX_NPC
	end

Route39_Interior2_EventScript_Slowbro_16::
	setflag 0x10B1
	playfanfare MUS_HEAL
	removeitem ITEM_ORAN_BERRY
	msgbox Route39_Interior2_Text_Slowbro_5, MSGBOX_NPC
	msgbox Route39_Interior2_Text_Slowbro_6, MSGBOX_NPC
	end

Route39_Interior2_EventScript_Slowbro_17::
	setflag 0x10B8
	removeitem ITEM_ORAN_BERRY
	msgbox Route39_Interior2_Text_Slowbro_5, MSGBOX_NPC
	end

Route39_Interior2_EventScript_Slowbro_18::
	setflag 0x10B7
	removeitem ITEM_ORAN_BERRY
	msgbox Route39_Interior2_Text_Slowbro_5, MSGBOX_NPC
	msgbox Route39_Interior2_Text_Slowbro_7, MSGBOX_NPC
	end

Route39_Interior2_EventScript_Slowbro_19::
	setflag 0x10B6
	removeitem ITEM_ORAN_BERRY
	msgbox Route39_Interior2_Text_Slowbro_5, MSGBOX_NPC
	end

Route39_Interior2_EventScript_Slowbro_20::
	setflag 0x10B5
	removeitem ITEM_ORAN_BERRY
	msgbox Route39_Interior2_Text_Slowbro_5, MSGBOX_NPC
	msgbox Route39_Interior2_Text_Slowbro_8, MSGBOX_NPC
	end

Route39_Interior2_EventScript_Slowbro_21::
	setflag 0x10B4
	removeitem ITEM_ORAN_BERRY
	msgbox Route39_Interior2_Text_Slowbro_5, MSGBOX_NPC
	end

Route39_Interior2_EventScript_Slowbro_22::
	setflag 0x10B3
	removeitem ITEM_ORAN_BERRY
	msgbox Route39_Interior2_Text_Slowbro_5, MSGBOX_NPC
	end

Route39_Interior2_EventScript_LittleGirl::
	call_if_set 0x10B1, Route39_Interior2_EventScript_LittleGirl_1
	msgbox Route39_Interior2_Text_LittleGirl_1, MSGBOX_NPC
	end

Route39_Interior2_EventScript_LittleGirl_1::
	msgbox Route39_Interior2_Text_LittleGirl_2, MSGBOX_NPC
	end
