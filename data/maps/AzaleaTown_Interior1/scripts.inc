AzaleaTown_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Interior1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

AzaleaTown_Interior1_OnTransition::
	setrespawn HEAL_LOCATION_AZALEA_TOWN
	end
