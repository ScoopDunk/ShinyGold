FuchsiaCity_Interior9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_Interior9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FuchsiaCity_Interior9_OnTransition::
	setrespawn HEAL_LOCATION_FUCHSIA_CITY
	end

FuchsiaCity_Interior9_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

FuchsiaCity_Interior9_EventScript_Rocker::
	msgbox FuchsiaCity_Interior9_Text_Rocker, MSGBOX_NPC
	end

FuchsiaCity_Interior9_EventScript_Woman2::
	@ ShinyGold: overlapping data duplicated from 0x0887E660
	msgbox FuchsiaCity_Interior9_Text_Woman2_1, MSGBOX_NPC
	applymovement 3, FuchsiaCity_Interior7_Movement_CamperBarry_1
	delay 48
	setobjectxy 3, 4, 10
	setobjectxy 5, 4, 4
	msgbox FuchsiaCity_Interior9_Text_Woman2_2, MSGBOX_NPC
	applymovement 5, FuchsiaCity_Interior7_Movement_CamperBarry_1
	delay 48
	setobjectxy 5, 4, 10
	setobjectxy 3, 4, 4
	nop1
	end

FuchsiaCity_Interior9_EventScript_Lass::
	msgbox FuchsiaCity_Interior9_Text_Lass, MSGBOX_NPC
	end
