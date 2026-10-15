GoldenrodCity_Interior19_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_Interior19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

GoldenrodCity_Interior19_OnTransition::
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
	end

@ ShinyGold: moved from data/maps/Unused_G2_M70/scripts.inc (map removed)
Unused_G2_M70_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

@ ShinyGold: moved from data/maps/Unused_G2_M70/scripts.inc (map removed)
Unused_G2_M70_EventScript_Man::
	msgbox Unused_G2_M70_Text_Man, MSGBOX_NPC
	end

@ ShinyGold: moved from data/maps/Unused_G2_M70/scripts.inc (map removed)
Unused_G2_M70_EventScript_Woman3::
	msgbox Unused_G2_M70_Text_Woman3, MSGBOX_NPC
	end

@ ShinyGold: moved from data/maps/Unused_G2_M70/scripts.inc (map removed)
Unused_G2_M70_EventScript_Gentleman::
	msgbox Unused_G2_M70_Text_Gentleman, MSGBOX_NPC
	end
