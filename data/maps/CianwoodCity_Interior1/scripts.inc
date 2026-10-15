CianwoodCity_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodCity_Interior1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CianwoodCity_Interior1_OnTransition::
	setrespawn HEAL_LOCATION_CIANWOOD_CITY
	end

CianwoodCity_Interior1_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

CianwoodCity_Interior1_EventScript_GymGuy::
	call_if_set FLAG_BADGE03_GET, CianwoodCity_Interior1_EventScript_GymGuy_1
	msgbox CianwoodCity_Interior1_Text_GymGuy_1, MSGBOX_NPC
	end

CianwoodCity_Interior1_EventScript_GymGuy_1::
	msgbox CianwoodCity_Interior1_Text_GymGuy_2, MSGBOX_NPC
	end

CianwoodCity_Interior1_EventScript_Sailor::
	msgbox CianwoodCity_Interior1_Text_Sailor, MSGBOX_NPC
	end

CianwoodCity_Interior1_EventScript_Lass::
	msgbox CianwoodCity_Interior1_Text_Lass, MSGBOX_NPC
	end
