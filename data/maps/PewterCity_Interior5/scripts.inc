PewterCity_Interior5_MapScripts::
	.byte 0

PewterCity_Interior5_EventScript_BaldingMan::
	msgbox PewterCity_Interior5_Text_BaldingMan, MSGBOX_NPC
	end

PewterCity_Interior5_EventScript_LittleBoy::
	lock
	msgbox PewterCity_Interior5_Text_LittleBoy_1
	call PewterCity_Interior5_EventScript_LittleBoy_1
	release
	end

PewterCity_Interior5_EventScript_LittleBoy_1::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	waitse
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
	msgbox PewterCity_Interior5_Text_LittleBoy_2
	waitmoncry
	call EventScript_RestorePrevTextColor
	return

PewterCity_Interior5_EventScript_NidoranM::
	lock
	faceplayer
	call PewterCity_Interior5_EventScript_LittleBoy_1
	applymovement 3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
