Route14_MapScripts::
	.byte 0

Route14_EventScript_WorkerF::
	msgbox Route14_Text_WorkerF, MSGBOX_NPC
	end

Route14_EventScript_BirdKeeperRoy::
	trainerbattle_single TRAINER_BIRD_KEEPER_ROY, Route14_Text_BirdKeeperRoyIntro, Route14_Text_BirdKeeperRoyDefeat
	msgbox Route14_Text_BirdKeeperRoy, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_PokefanCarter::
	trainerbattle_single TRAINER_POKEFAN_CARTER, Route14_Text_PokefanCarterIntro, Route14_Text_PokefanCarterDefeat
	msgbox Route14_Text_PokefanCarter, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_PokefanTrevor::
	trainerbattle_single TRAINER_POKEFAN_TREVOR, Route14_Text_PokefanTrevorIntro, Route14_Text_PokefanTrevorDefeat
	msgbox Route14_Text_PokefanTrevor, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Beauty::
	lock
	faceplayer
	setvar VAR_0x8008, 4
	call EventScript_GetInGameTradeSpeciesInfo
	goto_if_set 0x124D, Route14_EventScript_Beauty_1
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, Route14_EventScript_Beauty_2
	call EventScript_ChooseMonForInGameTrade
	goto_if_ge VAR_0x8004, 6, Route14_EventScript_Beauty_2
	call EventScript_GetInGameTradeSpecies
	goto_if_ne VAR_RESULT, VAR_0x8009, Route14_EventScript_Beauty_3
	call EventScript_DoInGameTrade
	msgbox Trade_Text_HeyThanks
	setflag 0x124D
	release
	end

Route14_EventScript_Beauty_1::
	msgbox Trade_Text_IsntMyOldMonGreat
	release
	end

Route14_EventScript_Beauty_2::
	msgbox Trade_Text_AwwOhWell
	release
	end

Route14_EventScript_Beauty_3::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Trade_Text_WhatThatsNoMon
	release
	end

Route14_EventScript_Sign1::
	call_if_set 0x1255, Route14_EventScript_Sign1_1
	lock
	faceplayer
	call Route14_EventScript_Sign1_2
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route14_EventScript_Sign1_2
	call_if_lt VAR_0x8006, 200, Route14_EventScript_Sign1_3
	getpartysize
	call_if_lt VAR_RESULT, 6, Route14_EventScript_Sign1_4
	msgbox Route14_Text_Sign1_1, MSGBOX_NPC
	end

Route14_EventScript_Sign1_1::
	msgbox Route14_Text_Sign1_1, MSGBOX_NPC
	end

Route14_EventScript_Sign1_2::
	buffernumberstring STR_VAR_1, 10
	bufferitemname STR_VAR_2, ITEM_HM05
	return

Route14_EventScript_Sign1_3::
	msgbox Route14_Text_Sign1_1, MSGBOX_NPC
	end

Route14_EventScript_Sign1_4::
	msgbox Route14_Text_Sign1_2, MSGBOX_NPC
	playfanfare MUS_SLOTS_WIN
	msgbox Route14_Text_Sign1_3
	waitfanfare
	giveegg SPECIES_JIRACHI
	setflag 0x1255
	release
	end
