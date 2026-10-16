BlackthornCity_Interior3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_Interior3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BlackthornCity_Interior3_OnTransition::
	@ ShinyGold fix: the hack had this Pokémon Center set the other town's fly flag and heal point (Teleport
	@ went to the other town, Fly to Blackthorn opened before the Ice Path).
	setworldmapflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_2
	end

BlackthornCity_Interior3_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

BlackthornCity_Interior3_EventScript_Gentleman::
	msgbox BlackthornCity_Interior3_Text_Gentleman, MSGBOX_NPC
	end

BlackthornCity_Interior3_EventScript_Woman1::
	msgbox BlackthornCity_Interior3_Text_Woman1, MSGBOX_NPC
	end

BlackthornCity_Interior3_EventScript_CooltrainerM::
	msgbox BlackthornCity_Interior3_Text_CooltrainerM, MSGBOX_NPC
	end
