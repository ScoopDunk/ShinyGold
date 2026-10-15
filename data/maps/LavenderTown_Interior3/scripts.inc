LavenderTown_Interior3_MapScripts::
	.byte 0

LavenderTown_Interior3_EventScript_Lass::
	msgbox LavenderTown_Interior3_Text_Lass, MSGBOX_NPC
	end

LavenderTown_Interior3_EventScript_Pidgey::
	msgbox LavenderTown_Interior3_Text_Pidgey, MSGBOX_NPC
	waitse
	playmoncry SPECIES_PIDGEY, 0x200
	.byte 0xFF @ invalid opcode (script stops)

LavenderTown_Interior3_EventScript_Meowth::
	msgbox LavenderTown_Interior3_Text_Meowth, MSGBOX_NPC
	waitse
	playmoncry SPECIES_MEOWTH, 0x200
	.byte 0xFF @ invalid opcode (script stops)

LavenderTown_Interior3_EventScript_LittleBoy::
	msgbox LavenderTown_Interior3_Text_LittleBoy, MSGBOX_NPC
	end

LavenderTown_Interior3_EventScript_Man::
	msgbox LavenderTown_Interior3_Text_Man, MSGBOX_NPC
	end

LavenderTown_Interior3_EventScript_NidoranM::
	msgbox LavenderTown_Interior3_Text_NidoranM, MSGBOX_NPC
	waitse
	playmoncry SPECIES_NIDORAN_M, 0x200
	.byte 0xFF @ invalid opcode (script stops)

LavenderTown_Interior3_EventScript_Sign1::
	lockall
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 2
	special SetFlavorTextFlagFromSpecialVars
	msgbox LavenderTown_Interior3_Text_Sign1
	releaseall
	end

LavenderTown_Interior3_EventScript_Sign2::
	msgbox LavenderTown_Interior3_Text_Sign2, MSGBOX_SIGN
	end
