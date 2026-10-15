Unused_SSAnne_B1F_Room5_MapScripts::
	.byte 0

Unused_SSAnne_B1F_Room5_EventScript_Boy::
	msgbox Unused_SSAnne_B1F_Room5_Text_Boy, MSGBOX_NPC
	end

Unused_SSAnne_B1F_Room5_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
	msgbox Unused_SSAnne_B1F_Room5_Text_Machoke
	waitmoncry
	release
	end
