VermilionCity_Interior17_MapScripts::
	.byte 0

VermilionCity_Interior17_EventScript_Woman3::
	msgbox VermilionCity_Interior17_Text_Woman3, MSGBOX_NPC
	end

VermilionCity_Interior17_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox VermilionCity_Interior17_Text_Pidgey
	waitmoncry
	release
	end

VermilionCity_Interior17_EventScript_Youngster::
	msgbox VermilionCity_Interior17_Text_Youngster, MSGBOX_NPC
	end

VermilionCity_Interior17_EventScript_Sign::
	msgbox VermilionCity_Interior17_Text_Sign, MSGBOX_SIGN
	end
