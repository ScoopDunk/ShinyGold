CeruleanCity_Interior6_MapScripts::
	.byte 0

CeruleanCity_Interior6_EventScript_Woman3::
	msgbox CeruleanCity_Interior6_Text_Woman3, MSGBOX_NPC
	end

CeruleanCity_Interior6_EventScript_BaldingMan::
	msgbox CeruleanCity_Interior6_Text_BaldingMan, MSGBOX_NPC
	end

CeruleanCity_Interior6_EventScript_Cubone::
	msgbox CeruleanCity_Interior6_Text_Cubone, MSGBOX_NPC
	waitse
	playmoncry SPECIES_CUBONE, 0x200
	.byte 0xD9 @ invalid opcode (script stops)
