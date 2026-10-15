SaffronCity_Interior2_MapScripts::
	.byte 0

SaffronCity_Interior2_EventScript_BaldingMan::
	msgbox SaffronCity_Interior2_Text_BaldingMan, MSGBOX_NPC
	end

SaffronCity_Interior2_EventScript_Woman3::
	call_if_set 0x1185, SaffronCity_Interior2_EventScript_Woman3_1
	msgbox SaffronCity_Interior2_Text_Woman3_1, MSGBOX_NPC
	end

SaffronCity_Interior2_EventScript_Woman3_1::
	msgbox SaffronCity_Interior2_Text_Woman3_2, MSGBOX_NPC
	end

SaffronCity_Interior2_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox SaffronCity_Interior2_Text_Chansey
	waitmoncry
	release
	end

SaffronCity_Interior2_EventScript_Trigger1::
	goto_if_set 0x1187, SaffronCity_Interior2_EventScript_Trigger1_1
	setflag 0x1188
	release
	end

SaffronCity_Interior2_EventScript_Trigger1_1::
	release
	end
