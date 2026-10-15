CherrygroveCity_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_LOAD, CherrygroveCity_Interior1_OnLoad
	.byte 0

CherrygroveCity_Interior1_OnLoad::
	call_if_ge 0x4076, 5, CherrygroveCity_Interior1_EventScript_OnLoad_1
	call_if_set FLAG_SYS_CAN_LINK_WITH_RS, CherrygroveCity_Interior1_EventScript_OnLoad_2
	end

CherrygroveCity_Interior1_EventScript_OnLoad_1::
	setmetatile 13, 4, 0x35D, 1
	return

CherrygroveCity_Interior1_EventScript_OnLoad_2::
	call CherrygroveCity_Interior1_EventScript_OnLoad_3
	setmetatile 14, 4, 0x35A, 1
	setmetatile 15, 4, 0x35B, 1
	return

CherrygroveCity_Interior1_EventScript_OnLoad_3::
	setmetatile 16, 4, 0x35F, 1
	return

CherrygroveCity_Interior1_EventScript_Beauty::
	msgbox CherrygroveCity_Interior1_Text_Beauty, MSGBOX_NPC
	end

CherrygroveCity_Interior1_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, CherrygroveCity_Interior1_EventScript_Gentleman_1
	msgbox CherrygroveCity_Interior1_Text_Gentleman_1
	release
	end

CherrygroveCity_Interior1_EventScript_Gentleman_1::
	msgbox CherrygroveCity_Interior1_Text_Gentleman_2
	release
	end
