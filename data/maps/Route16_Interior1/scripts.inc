Route16_Interior1_MapScripts::
	.byte 0

Route16_Interior1_EventScript_Man::
	msgbox Route16_Interior1_Text_Man, MSGBOX_NPC
	end

Route16_Interior1_EventScript_Fearow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FEAROW, CRY_MODE_NORMAL
	msgbox Route16_Interior1_Text_Fearow
	waitmoncry
	release
	end
