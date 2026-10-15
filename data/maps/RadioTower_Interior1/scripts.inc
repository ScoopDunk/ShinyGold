RadioTower_Interior1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

RadioTower_Interior1_EventScript_Gentleman::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, RadioTower_Interior1_EventScript_Gentleman_1
	call RadioTower_Interior1_EventScript_Gentleman_2
	end

RadioTower_Interior1_EventScript_Gentleman_1::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, RadioTower_Interior1_EventScript_Gentleman_3
	call RadioTower_Interior1_EventScript_Gentleman_2
	end

RadioTower_Interior1_EventScript_Gentleman_2::
	showmoneybox 0, 0
	lock
	faceplayer
	msgbox RadioTower_Interior1_Text_Gentleman_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, RadioTower_Interior1_EventScript_Gentleman_4
	msgbox RadioTower_Interior1_Text_Gentleman_2, MSGBOX_NPC
	textcolor 104
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	releaseall
	end

RadioTower_Interior1_EventScript_Gentleman_3::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, RadioTower_Interior1_EventScript_Gentleman_5
	call RadioTower_Interior1_EventScript_Gentleman_2
	end

RadioTower_Interior1_EventScript_Gentleman_4::
	checkmoney 0x12C
	call_if_eq VAR_RESULT, 0, RadioTower_Interior1_EventScript_Gentleman_6
	removemoney 0x12C
	msgbox RadioTower_Interior1_Text_Gentleman_3, MSGBOX_AUTOCLOSE
	delay 48
	call RadioTower_Interior1_EventScript_Gentleman_7
	end

RadioTower_Interior1_EventScript_Gentleman_5::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, RadioTower_Interior1_EventScript_Gentleman_8
	call RadioTower_Interior1_EventScript_Gentleman_2
	end

RadioTower_Interior1_EventScript_Gentleman_6::
	msgbox RadioTower_Interior1_Text_Gentleman_4, MSGBOX_NPC
	textcolor 104
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	releaseall
	end

RadioTower_Interior1_EventScript_Gentleman_7::
	msgbox RadioTower_Interior1_Text_Gentleman_5, MSGBOX_AUTOCLOSE
	msgbox RadioTower_Interior1_Text_Gentleman_6, MSGBOX_NPC
	textcolor 104
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	releaseall
	end

RadioTower_Interior1_EventScript_Gentleman_8::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, RadioTower_Interior1_EventScript_Gentleman_9
	call_if_eq VAR_0x8008, 1, RadioTower_Interior1_EventScript_Gentleman_10
	call_if_eq VAR_0x8008, 2, RadioTower_Interior1_EventScript_Gentleman_11
	call_if_eq VAR_0x8008, 3, RadioTower_Interior1_EventScript_Gentleman_12
	end

RadioTower_Interior1_EventScript_Gentleman_9::
	showmoneybox 0, 0
	lock
	faceplayer
	msgbox RadioTower_Interior1_Text_Gentleman_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, RadioTower_Interior1_EventScript_Gentleman_13
	msgbox RadioTower_Interior1_Text_Gentleman_2, MSGBOX_NPC
	textcolor 104
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	releaseall
	end

RadioTower_Interior1_EventScript_Gentleman_10::
	showmoneybox 0, 0
	lock
	faceplayer
	msgbox RadioTower_Interior1_Text_Gentleman_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, RadioTower_Interior1_EventScript_Gentleman_14
	msgbox RadioTower_Interior1_Text_Gentleman_2, MSGBOX_NPC
	textcolor 104
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	releaseall
	end

RadioTower_Interior1_EventScript_Gentleman_11::
	showmoneybox 0, 0
	lock
	faceplayer
	msgbox RadioTower_Interior1_Text_Gentleman_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, RadioTower_Interior1_EventScript_Gentleman_15
	msgbox RadioTower_Interior1_Text_Gentleman_2, MSGBOX_NPC
	textcolor 104
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	releaseall
	end

RadioTower_Interior1_EventScript_Gentleman_12::
	showmoneybox 0, 0
	lock
	faceplayer
	msgbox RadioTower_Interior1_Text_Gentleman_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, RadioTower_Interior1_EventScript_Gentleman_16
	msgbox RadioTower_Interior1_Text_Gentleman_2, MSGBOX_NPC
	textcolor 104
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	releaseall
	end

RadioTower_Interior1_EventScript_Gentleman_13::
	checkmoney 0x12C
	call_if_eq VAR_RESULT, 0, RadioTower_Interior1_EventScript_Gentleman_6
	removemoney 0x12C
	msgbox RadioTower_Interior1_Text_Gentleman_3, MSGBOX_AUTOCLOSE
	delay 48
	call RadioTower_Interior1_EventScript_Gentleman_17
	end

RadioTower_Interior1_EventScript_Gentleman_14::
	checkmoney 0x12C
	call_if_eq VAR_RESULT, 0, RadioTower_Interior1_EventScript_Gentleman_6
	removemoney 0x12C
	msgbox RadioTower_Interior1_Text_Gentleman_3, MSGBOX_AUTOCLOSE
	delay 48
	call RadioTower_Interior1_EventScript_Gentleman_18
	end

RadioTower_Interior1_EventScript_Gentleman_15::
	checkmoney 0x12C
	call_if_eq VAR_RESULT, 0, RadioTower_Interior1_EventScript_Gentleman_6
	removemoney 0x12C
	msgbox RadioTower_Interior1_Text_Gentleman_3, MSGBOX_AUTOCLOSE
	delay 48
	call RadioTower_Interior1_EventScript_Gentleman_19
	end

RadioTower_Interior1_EventScript_Gentleman_16::
	checkmoney 0x12C
	call_if_eq VAR_RESULT, 0, RadioTower_Interior1_EventScript_Gentleman_6
	removemoney 0x12C
	msgbox RadioTower_Interior1_Text_Gentleman_3, MSGBOX_AUTOCLOSE
	delay 48
	call RadioTower_Interior1_EventScript_Gentleman_20
	end

RadioTower_Interior1_EventScript_Gentleman_17::
	msgbox RadioTower_Interior1_Text_Gentleman_7, MSGBOX_AUTOCLOSE
	msgbox RadioTower_Interior1_Text_Gentleman_8, MSGBOX_NPC
	giveitem ITEM_FULL_RESTORE
	textcolor 104
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	releaseall
	end

RadioTower_Interior1_EventScript_Gentleman_18::
	msgbox RadioTower_Interior1_Text_Gentleman_9, MSGBOX_AUTOCLOSE
	msgbox RadioTower_Interior1_Text_Gentleman_10, MSGBOX_NPC
	giveitem ITEM_PP_UP
	textcolor 104
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	releaseall
	end

RadioTower_Interior1_EventScript_Gentleman_19::
	msgbox RadioTower_Interior1_Text_Gentleman_11, MSGBOX_AUTOCLOSE
	msgbox RadioTower_Interior1_Text_Gentleman_12, MSGBOX_NPC
	giveitem ITEM_HP_UP
	textcolor 104
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	releaseall
	end

RadioTower_Interior1_EventScript_Gentleman_20::
	msgbox RadioTower_Interior1_Text_Gentleman_13, MSGBOX_AUTOCLOSE
	msgbox RadioTower_Interior1_Text_Gentleman_14, MSGBOX_NPC
	giveitem ITEM_MAX_REVIVE
	textcolor 104
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	releaseall
	end

RadioTower_Interior1_EventScript_WorkerF::
	call_if_set 0x10C0, RadioTower_Interior1_EventScript_WorkerF_1
	msgbox RadioTower_Interior1_Text_WorkerF_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, RadioTower_Interior1_EventScript_WorkerF_2
	msgbox RadioTower_Interior1_Text_WorkerF_2, MSGBOX_NPC
	end

RadioTower_Interior1_EventScript_WorkerF_1::
	msgbox RadioTower_Interior1_Text_WorkerF_3, MSGBOX_NPC
	end

RadioTower_Interior1_EventScript_WorkerF_2::
	msgbox RadioTower_Interior1_Text_WorkerF_4, MSGBOX_YESNO
	call_if_lt VAR_RESULT, 1, RadioTower_Interior1_EventScript_WorkerF_3
	msgbox RadioTower_Interior1_Text_WorkerF_5, MSGBOX_NPC
	end

RadioTower_Interior1_EventScript_WorkerF_3::
	msgbox RadioTower_Interior1_Text_WorkerF_6, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, RadioTower_Interior1_EventScript_WorkerF_4
	msgbox RadioTower_Interior1_Text_WorkerF_5, MSGBOX_NPC
	end

RadioTower_Interior1_EventScript_WorkerF_4::
	msgbox RadioTower_Interior1_Text_WorkerF_7, MSGBOX_YESNO
	call_if_lt VAR_RESULT, 1, RadioTower_Interior1_EventScript_WorkerF_5
	msgbox RadioTower_Interior1_Text_WorkerF_5, MSGBOX_NPC
	end

RadioTower_Interior1_EventScript_WorkerF_5::
	msgbox RadioTower_Interior1_Text_WorkerF_8, MSGBOX_YESNO
	call_if_lt VAR_RESULT, 1, RadioTower_Interior1_EventScript_WorkerF_6
	msgbox RadioTower_Interior1_Text_WorkerF_5, MSGBOX_NPC
	end

RadioTower_Interior1_EventScript_WorkerF_6::
	msgbox RadioTower_Interior1_Text_WorkerF_9, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, RadioTower_Interior1_EventScript_WorkerF_7
	msgbox RadioTower_Interior1_Text_WorkerF_5, MSGBOX_NPC
	end

RadioTower_Interior1_EventScript_WorkerF_7::
	msgbox RadioTower_Interior1_Text_WorkerF_10, MSGBOX_NPC
	giveitem ITEM_TEACHY_TV
	msgbox RadioTower_Interior1_Text_WorkerF_11, MSGBOX_NPC
	setflag 0x10C0
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
