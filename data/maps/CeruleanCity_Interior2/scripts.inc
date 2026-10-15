CeruleanCity_Interior2_MapScripts::
	.byte 0

CeruleanCity_Interior2_EventScript_OldMan1::
	msgbox CeruleanCity_Interior2_Text_OldMan1, MSGBOX_NPC
	end

CeruleanCity_Interior2_EventScript_OldWoman::
	msgbox CeruleanCity_Interior2_Text_OldWoman, MSGBOX_NPC
	end

CeruleanCity_Interior2_EventScript_NidoranM::
	msgbox CeruleanCity_Interior2_Text_NidoranM, MSGBOX_NPC
	waitse
	playmoncry SPECIES_NIDORAN_M, 0x200
	.byte 0xFF @ invalid opcode (script stops)

CeruleanCity_Interior2_EventScript_Kangaskhan::
	msgbox CeruleanCity_Interior2_Text_Kangaskhan, MSGBOX_NPC
	waitse
	playmoncry SPECIES_KANGASKHAN, 0x200
	.byte 0xFF @ invalid opcode (script stops)
