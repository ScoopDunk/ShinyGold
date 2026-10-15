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
	call_if_set 0x11B0, AzaleaTown_Interior5_EventScript_BaldingMan_3
	msgbox AzaleaTown_Interior5_Text_BaldingMan_2, MSGBOX_NPC
	call AzaleaTown_Interior5_EventScript_BaldingMan_4
	end

AzaleaTown_Interior5_EventScript_BaldingMan_2::
	msgbox AzaleaTown_Interior5_Text_BaldingMan_3, MSGBOX_NPC
	giveitem ITEM_NET_BALL
	msgbox AzaleaTown_Interior5_Text_BaldingMan_2, MSGBOX_NPC
	setflag 0x1065
	end

AzaleaTown_Interior5_EventScript_BaldingMan_3::
	callnative CheckSaveBlockExtStepCounter
	call_if_eq VAR_RESULT, 1, AzaleaTown_Interior5_EventScript_BaldingMan_5
	call AzaleaTown_Interior5_EventScript_BaldingMan_6
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
	call_if_set 0x11AF, AzaleaTown_Interior5_EventScript_BaldingMan_14
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

AzaleaTown_Interior5_EventScript_BaldingMan_5::
	msgbox AzaleaTown_Interior5_Text_BaldingMan_4, MSGBOX_NPC
	applymovement 1, AzaleaTown_Interior5_Movement_BaldingMan_2
	delay 64
	playbgm MUS_NONE, 51
	setflag 0x1058
	setflag 0x11AE
	clearflag 0x11AD
	call_if_eq VAR_FACING, 1, AzaleaTown_Interior5_EventScript_BaldingMan_22
	call_if_eq VAR_FACING, 2, AzaleaTown_Interior5_EventScript_BaldingMan_22
	applymovement 1, AzaleaTown_Interior5_Movement_BaldingMan_3
	delay 80
	playbgm MUS_SEVII_45, 51
	end

AzaleaTown_Interior5_EventScript_BaldingMan_6::
	msgbox AzaleaTown_Interior5_Text_BaldingMan_5, MSGBOX_NPC
	end

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

AzaleaTown_Interior5_EventScript_BaldingMan_14::
	msgbox AzaleaTown_Interior5_Text_BaldingMan_8, MSGBOX_NPC
	msgbox AzaleaTown_Interior5_Text_BaldingMan_9, MSGBOX_NPC
	removeitem ITEM_RED_ORB
	setflag 0x11B0
	setvar VAR_RESULT, 0
	callnative StartSaveBlockExtStepCounter
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

AzaleaTown_Interior5_EventScript_BaldingMan_22::
	applymovement 1, AzaleaTown_Interior5_Movement_BaldingMan_4
	delay 80
	playbgm MUS_SEVII_45, 51
	end

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
	call_if_set 0x11AE, AzaleaTown_Interior5_EventScript_LittleGirl_1
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

AzaleaTown_Interior5_EventScript_BaldingMan2::
	msgbox AzaleaTown_Interior5_Text_BaldingMan2, MSGBOX_NPC
	end
