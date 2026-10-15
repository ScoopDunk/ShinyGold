ViridianCity_Interior1_MapScripts::
	.byte 0

ViridianCity_Interior1_EventScript_Picnicker::
	msgbox ViridianCity_Interior1_Text_Picnicker, MSGBOX_NPC
	end

ViridianCity_Interior1_EventScript_FatMan::
	msgbox ViridianCity_Interior1_Text_FatMan, MSGBOX_NPC
	end

ViridianCity_Interior1_EventScript_Spearow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_Interior1_Text_Spearow
	waitmoncry
	release
	end

ViridianCity_Interior1_EventScript_NidoranF::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox ViridianCity_Interior1_Text_NidoranF, MSGBOX_NPC
	waitmoncry
	release
	end

ViridianCity_Interior1_EventScript_Sign::
	msgbox ViridianCity_Interior1_Text_Sign, MSGBOX_SIGN
	end
