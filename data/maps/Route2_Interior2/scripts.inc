Route2_Interior2_MapScripts::
	.byte 0

Route2_Interior2_EventScript_FatMan::
	call_if_set 0x1204, Route2_Interior2_EventScript_FatMan_1
	msgbox Route2_Interior2_Text_FatMan_1, MSGBOX_NPC
	lock
	faceplayer
	giveitem ITEM_NUGGET
	msgbox Route2_Interior2_Text_FatMan_2, MSGBOX_NPC
	setflag 0x1204
	release
	end

Route2_Interior2_EventScript_FatMan_1::
	msgbox Route2_Interior2_Text_FatMan_2, MSGBOX_NPC
	end

Route2_Interior2_EventScript_GbaKid::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	call EventScript_GetInGameTradeSpeciesInfo
	goto_if_set 0x1248, Route2_Interior2_EventScript_GbaKid_1
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, Route2_Interior2_EventScript_GbaKid_2
	call EventScript_ChooseMonForInGameTrade
	goto_if_ge VAR_0x8004, 6, Route2_Interior2_EventScript_GbaKid_2
	call EventScript_GetInGameTradeSpecies
	goto_if_ne VAR_RESULT, VAR_0x8009, Route2_Interior2_EventScript_GbaKid_3
	call EventScript_DoInGameTrade
	msgbox Trade_Text_HeyThanks
	setflag 0x1248
	release
	end

Route2_Interior2_EventScript_GbaKid_1::
	msgbox Trade_Text_IsntMyOldMonGreat
	release
	end

Route2_Interior2_EventScript_GbaKid_2::
	msgbox Trade_Text_AwwOhWell
	release
	end

Route2_Interior2_EventScript_GbaKid_3::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Trade_Text_WhatThatsNoMon
	release
	end
