CeladonCity_Interior16_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

CeladonCity_Interior16_EventScript_Clefairy::
	msgbox CeladonCity_Interior16_Text_Clefairy, MSGBOX_NPC
	waitse
	playmoncry SPECIES_CLEFAIRY, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior16_EventScript_NidoranF::
	msgbox CeladonCity_Interior16_Text_NidoranF, MSGBOX_NPC
	waitse
	playmoncry SPECIES_NIDORAN_F, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior16_EventScript_OldWoman::
	msgbox CeladonCity_Interior16_Text_OldWoman, MSGBOX_NPC
	end

CeladonCity_Interior16_EventScript_Meowth::
	msgbox CeladonCity_Interior16_Text_Meowth, MSGBOX_NPC
	waitse
	playmoncry SPECIES_MEOWTH, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_Interior16_EventScript_Sign::
	msgbox CeladonCity_Interior16_Text_Sign, MSGBOX_AUTOCLOSE
	end
