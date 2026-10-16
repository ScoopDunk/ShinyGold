CinnabarIsland_Interior2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_Interior2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CinnabarIsland_Interior2_OnTransition::
	setrespawn HEAL_LOCATION_CINNABAR_ISLAND
	end

CinnabarIsland_Interior2_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

CinnabarIsland_Interior2_EventScript_FatMan::
	msgbox CinnabarIsland_Interior2_Text_FatMan, MSGBOX_NPC
	end

CinnabarIsland_Interior2_EventScript_CooltrainerF::
	msgbox CinnabarIsland_Interior2_Text_CooltrainerF, MSGBOX_NPC
	end
