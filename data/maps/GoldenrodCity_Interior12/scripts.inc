GoldenrodCity_Interior12_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

GoldenrodCity_Interior12_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart GoldenrodCity_Interior12_Items_Clerk
	release
	end

	.align 1
GoldenrodCity_Interior12_Items_Clerk::
	.2byte ITEM_TM40
	.2byte ITEM_TM41
	.2byte ITEM_TM42
	.2byte ITEM_TM02
	.2byte ITEM_NONE

GoldenrodCity_Interior12_EventScript_BlackBelt::
	lock
	faceplayer
	setvar VAR_0x8008, 1
	call EventScript_GetInGameTradeSpeciesInfo
	goto_if_set 0x1249, GoldenrodCity_Interior12_EventScript_BlackBelt_1
	msgbox Trade_Text_DoYouHaveMonWouldYouTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_Interior12_EventScript_BlackBelt_2
	call EventScript_ChooseMonForInGameTrade
	goto_if_ge VAR_0x8004, 6, GoldenrodCity_Interior12_EventScript_BlackBelt_2
	call EventScript_GetInGameTradeSpecies
	goto_if_ne VAR_RESULT, VAR_0x8009, GoldenrodCity_Interior12_EventScript_BlackBelt_3
	call EventScript_DoInGameTrade
	msgbox Trade_Text_Thanks
	setflag 0x1249
	release
	end

GoldenrodCity_Interior12_EventScript_BlackBelt_1::
	msgbox Trade_Text_HasTradedMonGrownStronger
	release
	end

GoldenrodCity_Interior12_EventScript_BlackBelt_2::
	msgbox Trade_Text_WellIfYouDontWantTo
	release
	end

GoldenrodCity_Interior12_EventScript_BlackBelt_3::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Trade_Text_ThisIsntMon
	release
	end

GoldenrodCity_Interior12_EventScript_CrushGirl::
	msgbox GoldenrodCity_Interior12_Text_CrushGirl, MSGBOX_NPC
	end

GoldenrodCity_Interior12_EventScript_Hiker::
	msgbox GoldenrodCity_Interior12_Text_Hiker, MSGBOX_NPC
	end

GoldenrodCity_Interior12_EventScript_Woman1::
	msgbox GoldenrodCity_Interior12_Text_Woman1, MSGBOX_NPC
	end

GoldenrodCity_Interior12_EventScript_Woman2::
	call_if_set 0x1088, GoldenrodCity_Interior12_EventScript_Woman2_1
	msgbox GoldenrodCity_Interior12_Text_Woman2_1, MSGBOX_NPC
	specialvar VAR_RESULT, GetLeadMonFriendship
	switch VAR_RESULT
	call_if_lt VAR_0x8000, 2, GoldenrodCity_Interior12_EventScript_Woman2_2
	call_if_gt VAR_0x8000, 4, GoldenrodCity_Interior12_EventScript_Woman2_3
	msgbox GoldenrodCity_Interior12_Text_Woman2_2, MSGBOX_NPC
	end

GoldenrodCity_Interior12_EventScript_Woman2_1::
	msgbox GoldenrodCity_Interior12_Text_Woman2_3, MSGBOX_NPC
	end

GoldenrodCity_Interior12_EventScript_Woman2_2::
	setflag 0x1088
	msgbox GoldenrodCity_Interior12_Text_Woman2_4, MSGBOX_NPC
	giveitem ITEM_TM21
	msgbox GoldenrodCity_Interior12_Text_Woman2_3, MSGBOX_NPC
	end

GoldenrodCity_Interior12_EventScript_Woman2_3::
	setflag 0x1088
	msgbox GoldenrodCity_Interior12_Text_Woman2_5, MSGBOX_NPC
	giveitem ITEM_TM27
	msgbox GoldenrodCity_Interior12_Text_Woman2_3, MSGBOX_NPC
	end

GoldenrodCity_Interior12_EventScript_Trigger::
	setvar VAR_RESULT, 5
	release
	end

GoldenrodCity_Interior12_EventScript_Sign::
	msgbox GoldenrodCity_Interior12_Text_Sign, MSGBOX_AUTOCLOSE
	end
