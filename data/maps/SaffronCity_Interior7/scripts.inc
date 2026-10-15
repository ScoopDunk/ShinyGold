SaffronCity_Interior7_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_Interior7_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SaffronCity_Interior7_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	end

SaffronCity_Interior7_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

SaffronCity_Interior7_EventScript_Hiker::
	call_if_set 0x1185, SaffronCity_Interior7_EventScript_Hiker_1
	msgbox SaffronCity_Interior7_Text_Hiker_1, MSGBOX_NPC
	end

SaffronCity_Interior7_EventScript_Hiker_1::
	msgbox SaffronCity_Interior7_Text_Hiker_2, MSGBOX_NPC
	end

SaffronCity_Interior7_EventScript_Youngster::
	msgbox SaffronCity_Interior7_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_Interior7_EventScript_Beauty::
	msgbox SaffronCity_Interior7_Text_Beauty, MSGBOX_NPC
	end
