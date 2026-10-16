OlivineCity_Interior5_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_Interior5_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

@ ShinyGold fix: the hack turned this Pokémon Center's FireRed transition script into a dead table, which
@ also dropped its setrespawn, so healing here never updated the white-out/Teleport point.
OlivineCity_Interior5_OnTransition::
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	end

OlivineCity_Interior5_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

OlivineCity_Interior5_EventScript_FatMan::
	msgbox OlivineCity_Interior5_Text_FatMan, MSGBOX_NPC
	end

OlivineCity_Interior5_EventScript_WorkerF::
	msgbox OlivineCity_Interior5_Text_WorkerF, MSGBOX_NPC
	end

OlivineCity_Interior5_EventScript_Fisher::
	msgbox OlivineCity_Interior5_Text_Fisher, MSGBOX_NPC
	end
