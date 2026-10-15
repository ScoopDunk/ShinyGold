BlackthornCity_Interior5_MapScripts::
	.byte 0

BlackthornCity_Interior5_EventScript_Beauty::
	lock
	faceplayer
	setvar VAR_0x8008, 5
	call EventScript_GetInGameTradeSpeciesInfo
	goto_if_set 0x124B, BlackthornCity_Interior5_EventScript_Beauty_1
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, BlackthornCity_Interior5_EventScript_Beauty_2
	call EventScript_ChooseMonForInGameTrade
	goto_if_ge VAR_0x8004, 6, BlackthornCity_Interior5_EventScript_Beauty_2
	call EventScript_GetInGameTradeSpecies
	goto_if_ne VAR_RESULT, VAR_0x8009, BlackthornCity_Interior5_EventScript_Beauty_3
	call EventScript_DoInGameTrade
	msgbox Trade_Text_HeyThanks
	setflag 0x124B
	release
	end

BlackthornCity_Interior5_EventScript_Beauty_1::
	msgbox Trade_Text_IsntMyOldMonGreat
	release
	end

BlackthornCity_Interior5_EventScript_Beauty_2::
	msgbox Trade_Text_AwwOhWell
	release
	end

BlackthornCity_Interior5_EventScript_Beauty_3::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Trade_Text_WhatThatsNoMon
	release
	end
