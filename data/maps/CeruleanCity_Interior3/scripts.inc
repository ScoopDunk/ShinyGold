CeruleanCity_Interior3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_Interior3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CeruleanCity_Interior3_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_Interior3_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

CeruleanCity_Interior3_EventScript_Gentleman::
	msgbox CeruleanCity_Interior3_Text_Gentleman, MSGBOX_NPC
	end

CeruleanCity_Interior3_EventScript_Camper::
	msgbox CeruleanCity_Interior3_Text_Camper, MSGBOX_NPC
	end

CeruleanCity_Interior3_EventScript_Youngster::
	lock
	faceplayer
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 1
	special SetFlavorTextFlagFromSpecialVars
	msgbox CeruleanCity_Interior3_Text_Youngster
	release
	end

CeruleanCity_Interior3_EventScript_Scientist::
	msgbox CeruleanCity_Interior3_Text_Scientist, MSGBOX_NPC
	end
