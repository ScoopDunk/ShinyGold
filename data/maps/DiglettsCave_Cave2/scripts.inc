DiglettsCave_Cave2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DiglettsCave_Cave2_OnTransition
	.byte 0

DiglettsCave_Cave2_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_DIGLETTS_CAVE_B1F
	end

DiglettsCave_Cave2_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end
