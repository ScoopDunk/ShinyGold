AzaleaTown_Interior5_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

AzaleaTown_Interior5_EventScript_BaldingMan::
	call_if_set 0x1065, AzaleaTown_Interior5_EventScript_BaldingMan_1
	call_if_set 0x1055, AzaleaTown_Interior5_EventScript_BaldingMan_2
	msgbox AzaleaTown_Interior5_Text_BaldingMan_1, MSGBOX_NPC
	applymovement 1, AzaleaTown_Interior5_Movement_BaldingMan_1
	delay 48
	setflag 0x1058
	setflag 0x1063
	end

AzaleaTown_Interior5_EventScript_BaldingMan_1::
	goto_if_eq VAR_GOLD_GS_BALL, GS_BALL_KURT_CHECKING, AzaleaTown_Interior5_EventScript_KurtCheckingGSBall
	@ GS_BALL_NOT_RECEIVED too: a ShinyGold save may have the GS BALL without having been to Goldenrod's POKéMON CENTER
	goto_if_le VAR_GOLD_GS_BALL, GS_BALL_RECEIVED, AzaleaTown_Interior5_EventScript_KurtTryTakeGSBall
AzaleaTown_Interior5_EventScript_KurtMakesBalls::
	msgbox AzaleaTown_Interior5_Text_BaldingMan_2, MSGBOX_NPC
	call AzaleaTown_Interior5_EventScript_BaldingMan_4
	end

@ Pure Gold: the GS Ball, as in Crystal (pokecrystal KurtsHouse Kurt1 .CanGiveGSBallToKurt, .GaveGSBallToKurt and
@ Kurt2). KURT keeps the GS BALL for 500 steps (a stand-in for G/S's daily ENGINE_KURT_MAKING_BALLS). The GS Ball
@ has its own counter (VAR_GOLD_GS_BALL_STEPS) so it never restarts the APRICORN BALL wait, or the other way round;
@ meanwhile he works at his desk (object 3).
AzaleaTown_Interior5_EventScript_KurtTryTakeGSBall::
	@ a BALL made from an APRICORN comes first
	goto_if_set 0x1138, AzaleaTown_Interior5_EventScript_KurtMakesBalls
	goto_if_set 0x1139, AzaleaTown_Interior5_EventScript_KurtMakesBalls
	goto_if_set 0x113A, AzaleaTown_Interior5_EventScript_KurtMakesBalls
	goto_if_set 0x113B, AzaleaTown_Interior5_EventScript_KurtMakesBalls
	goto_if_set 0x113C, AzaleaTown_Interior5_EventScript_KurtMakesBalls
	goto_if_set 0x113D, AzaleaTown_Interior5_EventScript_KurtMakesBalls
	goto_if_set 0x113E, AzaleaTown_Interior5_EventScript_KurtMakesBalls
	checkitem ITEM_RED_ORB
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_Interior5_EventScript_KurtMakesBalls
	msgbox AzaleaTown_Interior5_Text_KurtWhatIsThat, MSGBOX_NPC
	removeitem ITEM_RED_ORB
	setvar VAR_GOLD_GS_BALL, GS_BALL_KURT_CHECKING
	callnative StartGsBallStepCounter
	end

AzaleaTown_Interior5_EventScript_KurtCheckingGSBall::
	callnative CheckGsBallStepCounter
	goto_if_eq VAR_RESULT, TRUE, AzaleaTown_Interior5_EventScript_KurtGSBallShakes
	lock
	faceplayer
	msgbox AzaleaTown_Interior5_Text_KurtImCheckingItNow
	msgbox AzaleaTown_Interior5_Text_KurtAhHaISee
	release
	end

AzaleaTown_Interior5_EventScript_KurtGSBallShakes::
	lock
	faceplayer
	msgbox AzaleaTown_Interior5_Text_BaldingMan_4
	closemessage
	setvar VAR_GOLD_GS_BALL, GS_BALL_KURT_OUTSIDE
	fadeoutbgm 0
	delay 20
	applymovement 1, AzaleaTown_Interior5_Movement_BaldingMan_2
	waitmovement 0
	goto_if_eq VAR_FACING, DIR_SOUTH, AzaleaTown_Interior5_EventScript_KurtRunsOutAroundPlayer
	goto_if_eq VAR_FACING, DIR_NORTH, AzaleaTown_Interior5_EventScript_KurtRunsOutAroundPlayer
	applymovement 1, AzaleaTown_Interior5_Movement_BaldingMan_3
	goto AzaleaTown_Interior5_EventScript_KurtHasLeftTheBuilding

AzaleaTown_Interior5_EventScript_KurtRunsOutAroundPlayer::
	applymovement 1, AzaleaTown_Interior5_Movement_BaldingMan_4
AzaleaTown_Interior5_EventScript_KurtHasLeftTheBuilding::
	waitmovement 0
	playse SE_EXIT
	removeobject 1
	fadedefaultbgm
	release
	end

AzaleaTown_Interior5_EventScript_BaldingMan_2::
	msgbox AzaleaTown_Interior5_Text_BaldingMan_3, MSGBOX_NPC
	giveitem ITEM_NET_BALL
	msgbox AzaleaTown_Interior5_Text_BaldingMan_2, MSGBOX_NPC
	setflag 0x1065
	end

AzaleaTown_Interior5_EventScript_BaldingMan_4::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	call_if_set 0x1138, AzaleaTown_Interior5_EventScript_BaldingMan_7
	call_if_set 0x1139, AzaleaTown_Interior5_EventScript_BaldingMan_8
	call_if_set 0x113A, AzaleaTown_Interior5_EventScript_BaldingMan_9
	call_if_set 0x113B, AzaleaTown_Interior5_EventScript_BaldingMan_10
	call_if_set 0x113C, AzaleaTown_Interior5_EventScript_BaldingMan_11
	call_if_set 0x113D, AzaleaTown_Interior5_EventScript_BaldingMan_12
	call_if_set 0x113E, AzaleaTown_Interior5_EventScript_BaldingMan_13
	checkitem ITEM_UP_GRADE
	call_if_ge VAR_RESULT, 1, AzaleaTown_Interior5_EventScript_BaldingMan_15
	checkitem ITEM_GREEN_SCARF
	call_if_ge VAR_RESULT, 1, AzaleaTown_Interior5_EventScript_BaldingMan_16
	checkitem ITEM_DEEP_SEA_TOOTH
	call_if_ge VAR_RESULT, 1, AzaleaTown_Interior5_EventScript_BaldingMan_17
	checkitem ITEM_RED_SCARF
	call_if_ge VAR_RESULT, 1, AzaleaTown_Interior5_EventScript_BaldingMan_18
	checkitem ITEM_PINK_SCARF
	call_if_ge VAR_RESULT, 1, AzaleaTown_Interior5_EventScript_BaldingMan_19
	checkitem ITEM_BLUE_SCARF
	call_if_ge VAR_RESULT, 1, AzaleaTown_Interior5_EventScript_BaldingMan_20
	checkitem ITEM_YELLOW_SCARF
	call_if_ge VAR_RESULT, 1, AzaleaTown_Interior5_EventScript_BaldingMan_21
	end

AzaleaTown_Interior5_Movement_BaldingMan_1::
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	set_invisible
	walk_fast_down
	step_end

AzaleaTown_Interior5_EventScript_BaldingMan_7::
	callnative CheckSaveBlockExtStepCounter
	call_if_eq VAR_RESULT, 0, AzaleaTown_Interior5_EventScript_BaldingMan_23
	msgbox AzaleaTown_Interior5_Text_BaldingMan_6, MSGBOX_NPC
	giveitem ITEM_DIVE_BALL
	msgbox AzaleaTown_Interior5_Text_BaldingMan_7, MSGBOX_NPC
	clearflag 0x1138
	end

AzaleaTown_Interior5_EventScript_BaldingMan_8::
	callnative CheckSaveBlockExtStepCounter
	call_if_eq VAR_RESULT, 0, AzaleaTown_Interior5_EventScript_BaldingMan_23
	msgbox AzaleaTown_Interior5_Text_BaldingMan_6, MSGBOX_NPC
	giveitem ITEM_LUXURY_BALL
	msgbox AzaleaTown_Interior5_Text_BaldingMan_7, MSGBOX_NPC
	clearflag 0x1139
	end

AzaleaTown_Interior5_EventScript_BaldingMan_9::
	callnative CheckSaveBlockExtStepCounter
	call_if_eq VAR_RESULT, 0, AzaleaTown_Interior5_EventScript_BaldingMan_23
	msgbox AzaleaTown_Interior5_Text_BaldingMan_6, MSGBOX_NPC
	giveitem ITEM_TIMER_BALL
	msgbox AzaleaTown_Interior5_Text_BaldingMan_7, MSGBOX_NPC
	clearflag 0x113A
	end

AzaleaTown_Interior5_EventScript_BaldingMan_10::
	callnative CheckSaveBlockExtStepCounter
	call_if_eq VAR_RESULT, 0, AzaleaTown_Interior5_EventScript_BaldingMan_23
	msgbox AzaleaTown_Interior5_Text_BaldingMan_6, MSGBOX_NPC
	giveitem ITEM_NEST_BALL
	msgbox AzaleaTown_Interior5_Text_BaldingMan_7, MSGBOX_NPC
	clearflag 0x113B
	end

AzaleaTown_Interior5_EventScript_BaldingMan_11::
	callnative CheckSaveBlockExtStepCounter
	call_if_eq VAR_RESULT, 0, AzaleaTown_Interior5_EventScript_BaldingMan_23
	msgbox AzaleaTown_Interior5_Text_BaldingMan_6, MSGBOX_NPC
	giveitem ITEM_REPEAT_BALL
	msgbox AzaleaTown_Interior5_Text_BaldingMan_7, MSGBOX_NPC
	clearflag 0x113C
	end

AzaleaTown_Interior5_EventScript_BaldingMan_12::
	callnative CheckSaveBlockExtStepCounter
	call_if_eq VAR_RESULT, 0, AzaleaTown_Interior5_EventScript_BaldingMan_23
	msgbox AzaleaTown_Interior5_Text_BaldingMan_6, MSGBOX_NPC
	giveitem ITEM_NET_BALL
	msgbox AzaleaTown_Interior5_Text_BaldingMan_7, MSGBOX_NPC
	clearflag 0x113D
	end

AzaleaTown_Interior5_EventScript_BaldingMan_13::
	callnative CheckSaveBlockExtStepCounter
	call_if_eq VAR_RESULT, 0, AzaleaTown_Interior5_EventScript_BaldingMan_23
	msgbox AzaleaTown_Interior5_Text_BaldingMan_6, MSGBOX_NPC
	giveitem ITEM_PREMIER_BALL
	msgbox AzaleaTown_Interior5_Text_BaldingMan_7, MSGBOX_NPC
	clearflag 0x113E
	end

AzaleaTown_Interior5_EventScript_BaldingMan_15::
	msgbox AzaleaTown_Interior5_Text_BaldingMan_10, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, AzaleaTown_Interior5_EventScript_BaldingMan_24
	releaseall
	return

AzaleaTown_Interior5_EventScript_BaldingMan_16::
	msgbox AzaleaTown_Interior5_Text_BaldingMan_11, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, AzaleaTown_Interior5_EventScript_BaldingMan_25
	releaseall
	return

AzaleaTown_Interior5_EventScript_BaldingMan_17::
	msgbox AzaleaTown_Interior5_Text_BaldingMan_12, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, AzaleaTown_Interior5_EventScript_BaldingMan_26
	releaseall
	return

AzaleaTown_Interior5_EventScript_BaldingMan_18::
	msgbox AzaleaTown_Interior5_Text_BaldingMan_13, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, AzaleaTown_Interior5_EventScript_BaldingMan_27
	releaseall
	return

AzaleaTown_Interior5_EventScript_BaldingMan_19::
	msgbox AzaleaTown_Interior5_Text_BaldingMan_14, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, AzaleaTown_Interior5_EventScript_BaldingMan_28
	releaseall
	return

AzaleaTown_Interior5_EventScript_BaldingMan_20::
	msgbox AzaleaTown_Interior5_Text_BaldingMan_15, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, AzaleaTown_Interior5_EventScript_BaldingMan_29
	releaseall
	return

AzaleaTown_Interior5_EventScript_BaldingMan_21::
	msgbox AzaleaTown_Interior5_Text_BaldingMan_16, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, AzaleaTown_Interior5_EventScript_BaldingMan_30
	releaseall
	return

AzaleaTown_Interior5_EventScript_BaldingMan_23::
	msgbox AzaleaTown_Interior5_Text_BaldingMan_17, MSGBOX_NPC
	end

AzaleaTown_Interior5_EventScript_BaldingMan_24::
	setflag 0x1138
	removeitem ITEM_UP_GRADE
	msgbox AzaleaTown_Interior5_Text_BaldingMan_17, MSGBOX_NPC
	setvar VAR_RESULT, 0
	callnative StartSaveBlockExtStepCounter
	end

AzaleaTown_Interior5_EventScript_BaldingMan_25::
	setflag 0x1139
	removeitem ITEM_GREEN_SCARF
	msgbox AzaleaTown_Interior5_Text_BaldingMan_17, MSGBOX_NPC
	setvar VAR_RESULT, 0
	callnative StartSaveBlockExtStepCounter
	end

AzaleaTown_Interior5_EventScript_BaldingMan_26::
	setflag 0x113A
	removeitem ITEM_DEEP_SEA_TOOTH
	msgbox AzaleaTown_Interior5_Text_BaldingMan_17, MSGBOX_NPC
	setvar VAR_RESULT, 0
	callnative StartSaveBlockExtStepCounter
	end

AzaleaTown_Interior5_EventScript_BaldingMan_27::
	setflag 0x113B
	removeitem ITEM_RED_SCARF
	msgbox AzaleaTown_Interior5_Text_BaldingMan_17, MSGBOX_NPC
	setvar VAR_RESULT, 0
	callnative StartSaveBlockExtStepCounter
	end

AzaleaTown_Interior5_EventScript_BaldingMan_28::
	setflag 0x113C
	removeitem ITEM_PINK_SCARF
	msgbox AzaleaTown_Interior5_Text_BaldingMan_17, MSGBOX_NPC
	setvar VAR_RESULT, 0
	callnative StartSaveBlockExtStepCounter
	end

AzaleaTown_Interior5_EventScript_BaldingMan_29::
	setflag 0x113D
	removeitem ITEM_BLUE_SCARF
	msgbox AzaleaTown_Interior5_Text_BaldingMan_17, MSGBOX_NPC
	setvar VAR_RESULT, 0
	callnative StartSaveBlockExtStepCounter
	end

AzaleaTown_Interior5_EventScript_BaldingMan_30::
	setflag 0x113E
	removeitem ITEM_YELLOW_SCARF
	msgbox AzaleaTown_Interior5_Text_BaldingMan_17, MSGBOX_NPC
	setvar VAR_RESULT, 0
	callnative StartSaveBlockExtStepCounter
	end

AzaleaTown_Interior5_Movement_BaldingMan_2::
	emote_exclamation_mark
	step_end

AzaleaTown_Interior5_Movement_BaldingMan_3::
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_down
	set_invisible
	walk_fast_down
	walk_fast_down
	step_end

AzaleaTown_Interior5_Movement_BaldingMan_4::
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	set_invisible
	walk_fast_down
	walk_fast_down
	step_end

AzaleaTown_Interior5_EventScript_LittleGirl::
	goto_if_eq VAR_GOLD_GS_BALL, GS_BALL_KURT_OUTSIDE, AzaleaTown_Interior5_EventScript_LittleGirl_1
	goto_if_eq VAR_GOLD_GS_BALL, GS_BALL_RETURNED, AzaleaTown_Interior5_EventScript_LittleGirl_1
	goto_if_eq VAR_GOLD_GS_BALL, GS_BALL_KURT_CHECKING, AzaleaTown_Interior5_EventScript_LittleGirlGSBall
	call_if_set 0x1055, AzaleaTown_Interior5_EventScript_LittleGirl_2
	call_if_set 0x1058, AzaleaTown_Interior5_EventScript_LittleGirl_1
	msgbox AzaleaTown_Interior5_Text_LittleGirl_1, MSGBOX_NPC
	end

AzaleaTown_Interior5_EventScript_LittleGirl_1::
	msgbox AzaleaTown_Interior5_Text_LittleGirl_2, MSGBOX_NPC
	end

AzaleaTown_Interior5_EventScript_LittleGirl_2::
	msgbox AzaleaTown_Interior5_Text_LittleGirl_3, MSGBOX_NPC
	end

AzaleaTown_Interior5_EventScript_LittleGirlGSBall::
	msgbox AzaleaTown_Interior5_Text_LittleGirlGSBall, MSGBOX_NPC
	end

AzaleaTown_Interior5_EventScript_BaldingMan2::
	goto_if_eq VAR_GOLD_GS_BALL, GS_BALL_KURT_CHECKING, AzaleaTown_Interior5_EventScript_Kurt2CheckingGSBall
	msgbox AzaleaTown_Interior5_Text_BaldingMan2, MSGBOX_NPC
	end

AzaleaTown_Interior5_EventScript_Kurt2CheckingGSBall::
	lock
	faceplayer
	msgbox AzaleaTown_Interior5_Text_KurtImCheckingItNow
	msgbox AzaleaTown_Interior5_Text_KurtAhHaISee
	release
	end
