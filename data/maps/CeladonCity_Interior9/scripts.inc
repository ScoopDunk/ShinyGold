CeladonCity_Interior9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_Interior9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CeladonCity_Interior9_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY
	end

CeladonCity_Interior9_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

CeladonCity_Interior9_EventScript_Gentleman::
	msgbox CeladonCity_Interior9_Text_Gentleman, MSGBOX_NPC
	end

CeladonCity_Interior9_EventScript_CooltrainerF::
	msgbox CeladonCity_Interior9_Text_CooltrainerF, MSGBOX_NPC
	end

CeladonCity_Interior9_EventScript_PokeManiac::
	msgbox CeladonCity_Interior9_Text_PokeManiac, MSGBOX_NPC
	end
