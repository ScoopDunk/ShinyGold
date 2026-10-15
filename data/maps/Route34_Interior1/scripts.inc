Route34_Interior1_MapScripts::
	.byte 0

Route34_Interior1_EventScript_OldWoman::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, 1, Route34_Interior1_EventScript_OldWoman_1
	goto_if_eq VAR_RESULT, 2, Route34_Interior1_EventScript_OldWoman_2
	goto_if_eq VAR_RESULT, 3, Route34_Interior1_EventScript_OldWoman_3
	msgbox DayCare_Text_WouldYouLikeUsToRaiseMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, Route34_Interior1_EventScript_OldWoman_4
	msgbox DayCare_Text_FineThenComeAgain
	release
	end

Route34_Interior1_EventScript_OldWoman_1::
	msgbox DayCare_Text_HusbandWasLookingForYou
	release
	end

Route34_Interior1_EventScript_OldWoman_2::
	msgbox DayCare_Text_GoodToSeeYou
	setvar VAR_0x8004, 0
	call Route34_Interior1_EventScript_OldWoman_5
	msgbox DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, Route34_Interior1_EventScript_OldWoman_4
	msgbox DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, Route34_Interior1_EventScript_OldWoman_6
	goto Route34_Interior1_EventScript_OldWoman_7

Route34_Interior1_EventScript_OldWoman_3::
	msgbox DayCare_Text_GoodToSeeYou
	setvar VAR_0x8004, 0
	call Route34_Interior1_EventScript_OldWoman_5
	setvar VAR_0x8004, 1
	call Route34_Interior1_EventScript_OldWoman_5
	msgbox DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, Route34_Interior1_EventScript_OldWoman_6
	msgbox DayCare_Text_ComeAgain
	release
	end

Route34_Interior1_EventScript_OldWoman_4::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route34_Interior1_EventScript_OldWoman_8
	msgbox DayCare_Text_WhichMonShouldWeRaise
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_ge VAR_0x8004, 6, Route34_Interior1_EventScript_OldWoman_7
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route34_Interior1_EventScript_OldWoman_9
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox DayCare_Text_WellRaiseYourMon
	waitmoncry
	special StoreSelectedPokemonInDaycare
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, 2, Route34_Interior1_EventScript_OldWoman_10
	release
	end

Route34_Interior1_EventScript_OldWoman_5::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route34_Interior1_EventScript_OldWoman_11
	return

Route34_Interior1_EventScript_OldWoman_6::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, 6, Route34_Interior1_EventScript_OldWoman_12
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, 2, Route34_Interior1_EventScript_OldWoman_13
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, 2, Route34_Interior1_EventScript_OldWoman_7
	goto Route34_Interior1_EventScript_OldWoman_13

Route34_Interior1_EventScript_OldWoman_7::
	msgbox DayCare_Text_ComeAgain
	release
	end

Route34_Interior1_EventScript_OldWoman_8::
	msgbox DayCare_Text_YouHaveJustOneMon
	release
	end

Route34_Interior1_EventScript_OldWoman_9::
	msgbox DayCare_Text_WhatWillYouBattleWith
	release
	end

Route34_Interior1_EventScript_OldWoman_10::
	msgbox DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, Route34_Interior1_EventScript_OldWoman_4
	goto Route34_Interior1_EventScript_OldWoman_7

Route34_Interior1_EventScript_OldWoman_11::
	msgbox DayCare_Text_YourMonHasGrownXLevels
	return

Route34_Interior1_EventScript_OldWoman_12::
	msgbox DayCare_Text_YourPartyIsFull
	release
	end

Route34_Interior1_EventScript_OldWoman_13::
	special GetDaycareCost
	msgbox DayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, Route34_Interior1_EventScript_OldWoman_14
	goto Route34_Interior1_EventScript_OldWoman_7

Route34_Interior1_EventScript_OldWoman_14::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route34_Interior1_EventScript_OldWoman_15
	msgbox DayCare_Text_NotEnoughMoney
	release
	end

Route34_Interior1_EventScript_OldWoman_15::
	applymovement 1, Route34_Interior1_Movement_OldWoman
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_RS_SHOP
	msgbox DayCare_Text_HeresYourMon
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox DayCare_Text_TookBackMon
	call EventScript_RestorePrevTextColor
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, 2, Route34_Interior1_EventScript_OldWoman_16
	goto Route34_Interior1_EventScript_OldWoman_7

Route34_Interior1_EventScript_OldWoman_16::
	msgbox DayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, Route34_Interior1_EventScript_OldWoman_6
	goto Route34_Interior1_EventScript_OldWoman_7

Route34_Interior1_Movement_OldWoman::
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_up
	walk_slower_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slower_down
	step_end
