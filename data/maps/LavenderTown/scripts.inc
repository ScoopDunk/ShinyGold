LavenderTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setflag 0x1364
	setvar 0x7045, 1
	setvar 0x405B, 1
	setflag 0x03D
	end

LavenderTown_EventScript_BaldingMan::
	msgbox LavenderTown_Text_BaldingMan, MSGBOX_NPC
	end

LavenderTown_EventScript_OldMan1::
	msgbox LavenderTown_Text_OldMan1, MSGBOX_NPC
	end

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_Boy, MSGBOX_NPC
	end

LavenderTown_EventScript_Woman2::
	msgbox LavenderTown_Text_Woman2, MSGBOX_NPC
	end

LavenderTown_EventScript_Trigger6_3::
	setvar 0x7030, 0x129
	setvar 0x7033, 0x10A
	release
	return

LavenderTown_EventScript_Sign1::
	msgbox LavenderTown_Text_Sign1, MSGBOX_AUTOCLOSE
	end

LavenderTown_EventScript_Sign2::
	msgbox LavenderTown_Text_Sign2, MSGBOX_AUTOCLOSE
	end

LavenderTown_EventScript_Sign3::
	msgbox LavenderTown_Text_Sign3, MSGBOX_AUTOCLOSE
	end

LavenderTown_EventScript_Sign4::
	msgbox LavenderTown_Text_Sign4, MSGBOX_AUTOCLOSE
	end
