PewterCity_Interior6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_Interior6_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PewterCity_Interior6_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY
	end

PewterCity_Interior6_EventScript_Jigglypuff::
	lock
	faceplayer
	fadeoutbgm 0
	playbgm MUS_JIGGLYPUFF, 0
	message PewterCity_Interior6_Text_Jigglypuff
	waitmessage
	delay 0x1C7
	playbgm MUS_POKE_CENTER, 1
	release
	end

PewterCity_Interior6_EventScript_Gentleman::
	msgbox PewterCity_Interior6_Text_Gentleman, MSGBOX_NPC
	end

PewterCity_Interior6_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

PewterCity_Interior6_EventScript_LittleGirl::
	msgbox PewterCity_Interior6_Text_LittleGirl, MSGBOX_NPC
	end

PewterCity_Interior6_EventScript_GbaKid::
	lock
	msgbox PewterCity_Interior6_Text_GbaKid
	release
	end

PewterCity_Interior6_EventScript_Woman1::
	msgbox PewterCity_Interior6_Text_Woman1, MSGBOX_NPC
	end
