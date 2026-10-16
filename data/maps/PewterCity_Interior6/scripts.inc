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

@ Pure Gold/Silver: Chris's in-game trade (pokegold PewterPokecenter1F.asm, NPC_TRADE_CHRIS: GLOOM for RAPIDASH)
PewterCity_Interior6_EventScript_Chris::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_NIDORAN
	call EventScript_GetInGameTradeSpeciesInfo
	goto_if_set FLAG_GOLD_TRADED_WITH_CHRIS, PewterCity_Interior6_EventScript_ChrisTraded
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PewterCity_Interior6_EventScript_ChrisDeclined
	call EventScript_ChooseMonForInGameTrade
	goto_if_ge VAR_0x8004, PARTY_SIZE, PewterCity_Interior6_EventScript_ChrisDeclined
	call EventScript_GetInGameTradeSpecies
	goto_if_ne VAR_RESULT, VAR_0x8009, PewterCity_Interior6_EventScript_ChrisWrongMon
	call EventScript_DoInGameTrade
	msgbox Trade_Text_HeyThanks
	setflag FLAG_GOLD_TRADED_WITH_CHRIS
	release
	end

PewterCity_Interior6_EventScript_ChrisTraded::
	msgbox Trade_Text_IsntMyOldMonGreat
	release
	end

PewterCity_Interior6_EventScript_ChrisDeclined::
	msgbox Trade_Text_AwwOhWell
	release
	end

PewterCity_Interior6_EventScript_ChrisWrongMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Trade_Text_WhatThatsNoMon
	release
	end

