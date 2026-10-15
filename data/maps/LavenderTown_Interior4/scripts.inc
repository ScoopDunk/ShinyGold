LavenderTown_Interior4_MapScripts::
	.byte 0

LavenderTown_Interior4_EventScript_Woman3::
	msgbox LavenderTown_Interior4_Text_Woman3, MSGBOX_NPC
	end

LavenderTown_Interior4_EventScript_Cubone::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	msgbox LavenderTown_Interior4_Text_Cubone
	waitmoncry
	release
	end
