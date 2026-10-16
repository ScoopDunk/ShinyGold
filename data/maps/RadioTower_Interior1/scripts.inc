RadioTower_Interior1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

@ G/S RadioTower1FLuckyNumberManScript: the LUCKY NUMBER SHOW (src/gold_lucky_number.c).
@ Prizes MASTER BALL, EXP. SHARE and PP UP, one per week (a week is 7 hours of play time here).
RadioTower_Interior1_EventScript_Gentleman::
	lock
	faceplayer
	msgbox RadioTower_Interior1_Text_LuckyNumberAskToPlay
	callnative LuckyNumberShow_BufferNumber
	goto_if_eq VAR_RESULT, TRUE, RadioTower_Interior1_EventScript_LuckyNumberComeAgain
	msgbox RadioTower_Interior1_Text_LuckyNumberThisWeeksId
	msgbox RadioTower_Interior1_Text_LuckyNumberCheckIfMatch
	message RadioTower_Interior1_Text_LuckyNumberDotDotDot
	waitmessage
	playfanfare MUS_DEX_RATING
	waitfanfare
	waitbuttonpress
	callnative LuckyNumberShow_CheckWinners
	goto_if_eq VAR_RESULT, 0, RadioTower_Interior1_EventScript_LuckyNumberNoMatch
	copyvar VAR_0x8006, VAR_RESULT
	call_if_eq VAR_0x8005, FALSE, RadioTower_Interior1_EventScript_LuckyNumberMatchParty
	call_if_eq VAR_0x8005, TRUE, RadioTower_Interior1_EventScript_LuckyNumberMatchPC
	goto_if_eq VAR_0x8006, 1, RadioTower_Interior1_EventScript_LuckyNumberFirstPlace
	goto_if_eq VAR_0x8006, 2, RadioTower_Interior1_EventScript_LuckyNumberSecondPlace
	msgbox RadioTower_Interior1_Text_LuckyNumberWeakMatch
	setvar VAR_0x8004, ITEM_PP_UP
	goto RadioTower_Interior1_EventScript_LuckyNumberGivePrize

RadioTower_Interior1_EventScript_LuckyNumberFirstPlace::
	msgbox RadioTower_Interior1_Text_LuckyNumberPerfectMatch
	setvar VAR_0x8004, ITEM_MASTER_BALL
	goto RadioTower_Interior1_EventScript_LuckyNumberGivePrize

RadioTower_Interior1_EventScript_LuckyNumberSecondPlace::
	msgbox RadioTower_Interior1_Text_LuckyNumberOkayMatch
	setvar VAR_0x8004, ITEM_EXP_SHARE
RadioTower_Interior1_EventScript_LuckyNumberGivePrize::
	checkitemspace VAR_0x8004, 1
	goto_if_eq VAR_RESULT, FALSE, RadioTower_Interior1_EventScript_LuckyNumberNoRoom
	giveitem VAR_0x8004
	callnative LuckyNumberShow_SetPrizeWon
RadioTower_Interior1_EventScript_LuckyNumberComeAgain::
	msgbox RadioTower_Interior1_Text_LuckyNumberComeAgain
	release
	end

RadioTower_Interior1_EventScript_LuckyNumberMatchParty::
	msgbox RadioTower_Interior1_Text_LuckyNumberMatchParty
	return

RadioTower_Interior1_EventScript_LuckyNumberMatchPC::
	msgbox RadioTower_Interior1_Text_LuckyNumberMatchPC
	return

RadioTower_Interior1_EventScript_LuckyNumberNoMatch::
	msgbox RadioTower_Interior1_Text_LuckyNumberNoMatch
	release
	end

RadioTower_Interior1_EventScript_LuckyNumberNoRoom::
	msgbox RadioTower_Interior1_Text_LuckyNumberNoRoom
	release
	end

@ G/S RadioTower1FRadioCardWomanScript: five yes/no questions (answers yes, yes, no, yes, no)
RadioTower_Interior1_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_set 0x10C0, RadioTower_Interior1_EventScript_WorkerF_TuneIn
	msgbox RadioTower_Interior1_Text_WorkerF_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RadioTower_Interior1_EventScript_WorkerF_NoQuiz
	msgbox RadioTower_Interior1_Text_WorkerF_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RadioTower_Interior1_EventScript_WorkerF_Wrong
	playse SE_PIN
	waitse
	msgbox RadioTower_Interior1_Text_WorkerF_6, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RadioTower_Interior1_EventScript_WorkerF_Wrong
	playse SE_PIN
	waitse
	msgbox RadioTower_Interior1_Text_WorkerF_7, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RadioTower_Interior1_EventScript_WorkerF_Wrong
	playse SE_PIN
	waitse
	msgbox RadioTower_Interior1_Text_WorkerF_8, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RadioTower_Interior1_EventScript_WorkerF_Wrong
	playse SE_PIN
	waitse
	msgbox RadioTower_Interior1_Text_WorkerF_9, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RadioTower_Interior1_EventScript_WorkerF_Wrong
	playse SE_PIN
	waitse
	msgbox RadioTower_Interior1_Text_WorkerF_10
	giveitem ITEM_TEACHY_TV
	setflag 0x10C0
	msgbox RadioTower_Interior1_Text_WorkerF_11
	release
	end

RadioTower_Interior1_EventScript_WorkerF_TuneIn::
	msgbox RadioTower_Interior1_Text_WorkerF_3
	release
	end

RadioTower_Interior1_EventScript_WorkerF_NoQuiz::
	msgbox RadioTower_Interior1_Text_WorkerF_2
	release
	end

RadioTower_Interior1_EventScript_WorkerF_Wrong::
	playse SE_FAILURE
	waitse
	msgbox RadioTower_Interior1_Text_WorkerF_5
	release
	end

RadioTower_Interior1_EventScript_Man::
	msgbox RadioTower_Interior1_Text_Man, MSGBOX_NPC
	end

RadioTower_Interior1_EventScript_CableClubReceptionist::
	call_if_set 0x110B, RadioTower_Interior1_EventScript_CableClubReceptionist_1
	msgbox RadioTower_Interior1_Text_CableClubReceptionist_1, MSGBOX_NPC
	end

RadioTower_Interior1_EventScript_CableClubReceptionist_1::
	msgbox RadioTower_Interior1_Text_CableClubReceptionist_2, MSGBOX_NPC
	end

RadioTower_Interior1_EventScript_CrushGirl::
	msgbox RadioTower_Interior1_Text_CrushGirl, MSGBOX_NPC
	end

RadioTower_Interior1_EventScript_TeamRocketGrunt19::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_19, RadioTower_Interior1_Text_TeamRocketGrunt19Intro, RadioTower_Interior1_Text_TeamRocketGrunt19Defeat
	msgbox RadioTower_Interior1_Text_TeamRocketGrunt19, MSGBOX_AUTOCLOSE
	end

RadioTower_Interior1_EventScript_Trigger1::
	call_if_set 0x1123, RadioTower_Interior1_EventScript_Trigger1_1
	setflag 0x1132
	release
	end

RadioTower_Interior1_EventScript_Trigger1_1::
	release
	end

RadioTower_Interior1_EventScript_Trigger2::
	call_if_set 0x1123, RadioTower_Interior1_EventScript_Trigger2_1
	call SilphCo_Interior6_EventScript_Trigger1_1
	setvar 0x7024, 0
	release
	end

RadioTower_Interior1_EventScript_Trigger2_1::
	release
	end

RadioTower_Interior1_EventScript_Sign1::
	msgbox RadioTower_Interior1_Text_Sign1, MSGBOX_AUTOCLOSE
	end

RadioTower_Interior1_EventScript_Sign2::
	msgbox RadioTower_Interior1_Text_Sign2, MSGBOX_AUTOCLOSE
	end
