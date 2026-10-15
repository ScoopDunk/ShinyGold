BlackthornCity_Interior9_MapScripts::
	.byte 0

BlackthornCity_Interior9_EventScript_OldWoman::
	msgbox BlackthornCity_Interior9_Text_OldWoman, MSGBOX_NPC
	end

BlackthornCity_Interior9_EventScript_Omanyte::
	msgbox BlackthornCity_Interior9_Text_Omanyte, MSGBOX_NPC
	waitse
	playmoncry SPECIES_OMANYTE, 0x200
	.byte 0xFF @ invalid opcode (script stops)
