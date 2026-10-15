DiglettsCave_Cave2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DiglettsCave_Cave2_OnTransition
	.byte 0

DiglettsCave_Cave2_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_DIGLETTS_CAVE_B1F
	end

DiglettsCave_Cave2_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

DiglettsCave_Cave2_EventScript_Youngster::
	call_if_set 0x11EF, DiglettsCave_Cave2_EventScript_Youngster_1
	delay 1
	msgbox DiglettsCave_Cave2_Text_Youngster_1, MSGBOX_NPC
	end

DiglettsCave_Cave2_EventScript_Youngster_1::
	msgbox DiglettsCave_Cave2_Text_Youngster_2, MSGBOX_NPC
	giveitem ITEM_LAX_INCENSE
	msgbox DiglettsCave_Cave2_Text_Youngster_3, MSGBOX_NPC
	msgbox DiglettsCave_Cave2_Text_Youngster_4, MSGBOX_NPC
	removeobject 2
	setflag 0x11F1
	release
	end
