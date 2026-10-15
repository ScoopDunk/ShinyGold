ViridianCity_Interior4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_Interior4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ViridianCity_Interior4_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_Interior4_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

ViridianCity_Interior4_EventScript_Gentleman::
	msgbox ViridianCity_Interior4_Text_Gentleman, MSGBOX_NPC
	end

ViridianCity_Interior4_EventScript_Boy::
	msgbox ViridianCity_Interior4_Text_Boy, MSGBOX_NPC
	end

ViridianCity_Interior4_EventScript_Youngster::
	msgbox ViridianCity_Interior4_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_Interior4_EventScript_Trigger1::
	call CeruleanCity_EventScript_Trigger1
	call MtSilver_Interior1_EventScript_Trigger1
	end
