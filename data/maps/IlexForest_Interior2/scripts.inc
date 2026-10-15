IlexForest_Interior2_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

IlexForest_Interior2_EventScript_Woman2::
	msgbox IlexForest_Interior2_Text_Woman2, MSGBOX_NPC
	end

IlexForest_Interior2_EventScript_Picnicker::
	call_if_set 0x1077, IlexForest_Interior2_EventScript_Picnicker_1
	msgbox IlexForest_Interior2_Text_Picnicker_1, MSGBOX_NPC
	giveitem ITEM_TM12
	msgbox IlexForest_Interior2_Text_Picnicker_2, MSGBOX_NPC
	setflag 0x1077
	end

IlexForest_Interior2_EventScript_Picnicker_1::
	msgbox IlexForest_Interior2_Text_Picnicker_2, MSGBOX_NPC
	end

IlexForest_Interior2_EventScript_Clefairy::
	msgbox IlexForest_Interior2_Text_Clefairy, MSGBOX_NPC
	waitse
	playmoncry SPECIES_CLEFAIRY, 0x201
	.byte 0xFF @ invalid opcode (script stops)
