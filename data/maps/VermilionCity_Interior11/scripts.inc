VermilionCity_Interior11_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Interior11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VermilionCity_Interior11_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionCity_Interior11_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

VermilionCity_Interior11_EventScript_LittleBoy::
	msgbox VermilionCity_Interior11_Text_LittleBoy, MSGBOX_NPC
	end

VermilionCity_Interior11_EventScript_Fisher::
	msgbox VermilionCity_Interior11_Text_Fisher, MSGBOX_NPC
	end

VermilionCity_Interior11_EventScript_Youngster::
	msgbox VermilionCity_Interior11_Text_Youngster, MSGBOX_NPC
	end

VermilionCity_Interior11_EventScript_Sailor::
	msgbox VermilionCity_Interior11_Text_Sailor, MSGBOX_NPC
	end
