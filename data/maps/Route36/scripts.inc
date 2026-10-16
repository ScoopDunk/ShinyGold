Route36_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route36_OnFrame
	.byte 0

Route36_OnFrame::
	map_script_2 0x7017, 0, Route36_EventScript_FrameScene
	.2byte 0

Route36_EventScript_FrameScene::
	setvar 0x7017, 1
	call Route36_EventScript_FrameScene_1
	end

Route36_EventScript_FrameScene_1::
	setvar 0x7010, 0
	setvar 0x7011, 0
	setvar 0x7012, 0
	setvar 0x7013, 0
	setvar 0x7014, 0
	setvar 0x7015, 0
	setvar 0x7016, 0
	setvar 0x7018, 0
	setvar 0x7019, 0
	setvar 0x701A, 0
	setvar 0x701B, 0
	setvar 0x701C, 0
	setvar 0x701D, 0
	setvar 0x701E, 0
	setvar 0x701F, 0
	setvar 0x7020, 0
	setvar 0x7021, 0
	setvar 0x7022, 0
	setvar 0x7023, 0
	setvar 0x7024, 0
	setvar 0x7025, 0
	setvar 0x7026, 0
	setvar 0x7027, 0
	setvar 0x7028, 0
	return

Route36_EventScript_Woman2::
	call_if_set 0x1095, Route36_EventScript_Woman2_1
	msgbox Route36_Text_Woman2_1, MSGBOX_NPC
	end

Route36_EventScript_Woman2_1::
	msgbox Route36_Text_Woman2_2, MSGBOX_NPC
	end

Route36_EventScript_FatMan::
	call_if_set 0x1095, Route36_EventScript_FatMan_1
	msgbox Route36_Text_FatMan_1, MSGBOX_NPC
	end

Route36_EventScript_FatMan_1::
	call_if_set 0x1097, Route36_EventScript_FatMan_2
	msgbox Route36_Text_FatMan_2, MSGBOX_NPC
	giveitem ITEM_HM06
	msgbox Route36_Text_FatMan_3, MSGBOX_NPC
	setflag 0x1097
	end

Route36_EventScript_FatMan_2::
	msgbox Route36_Text_FatMan_3, MSGBOX_NPC
	end

Route36_EventScript_Fossil::
	call_if_set 0x1094, Route36_EventScript_Fossil_1
	msgbox Route36_Text_Fossil_1, MSGBOX_NPC
	end

Route36_EventScript_Fossil_1::
	msgbox Route36_Text_Fossil_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route36_EventScript_Fossil_2
	release
	end

Route36_EventScript_Fossil_2::
	setflag 0x1095
	setflag 0x1098
	clearflag 0x1099
	msgbox Route36_Text_Fossil_3, MSGBOX_NPC
	delay 48
	delay 48
	setwildbattle SPECIES_SUDOWOODO, 20
	special StartSouthernIslandBattle
	delay 128
	warp MAP_ROUTE36, 2, 0x202, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Route36_EventScript_PsychicMark::
	trainerbattle_single TRAINER_PSYCHIC_MARK, Route36_Text_PsychicMarkIntro, Route36_Text_PsychicMarkDefeat
	msgbox Route36_Text_PsychicMark, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Schoolboy306::
	trainerbattle_single TRAINER_SCHOOLBOY_ALAN, Route36_Text_Schoolboy306Intro, Route36_Text_Schoolboy306Defeat
	call_if_set 0x1310, Route36_EventScript_Schoolboy306_1
	setvar 0x700C, 16
	setvar 0x700D, 0
	call_if_set 0x1340, Route35_EventScript_Juggler228_2
	msgbox Route36_Text_Schoolboy306, MSGBOX_NPC
	setflag 0x1340
	call Route35_EventScript_Juggler228_3
	end

Route36_EventScript_Schoolboy306_1::
	clearflag 0x1310
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x8888, Route36_EventScript_Schoolboy306_2
	call_if_set 0x115F, Route36_EventScript_Schoolboy306_3
	call_if_set 0x110A, Route36_EventScript_Schoolboy306_4
	call_if_set FLAG_BADGE05_GET, Route36_EventScript_Schoolboy306_5
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_ALAN, 0, Route36_Text_Schoolboy306Defeat, Route35_Text_Juggler228Victory
	release
	end

Route36_EventScript_Schoolboy306_2::
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_ALAN_2, 0, Route36_Text_Schoolboy306Defeat, Route35_Text_Juggler228Victory
	release
	end

Route36_EventScript_Schoolboy306_3::
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_ALAN_3, 0, Route36_Text_Schoolboy306Defeat, Route35_Text_Juggler228Victory
	release
	end

Route36_EventScript_Schoolboy306_4::
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_ALAN_4, 0, Route36_Text_Schoolboy306Defeat, Route35_Text_Juggler228Victory
	release
	end

Route36_EventScript_Schoolboy306_5::
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_ALAN_5, 0, Route36_Text_Schoolboy306Defeat, Route35_Text_Juggler228Victory
	release
	end

Route36_EventScript_Sign1::
	msgbox Route36_Text_Sign1, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Sign2::
	msgbox Route36_Text_Sign2, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Sign3::
	msgbox Route36_Text_Sign3, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Sign4::
	msgbox Route36_Text_Sign4, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Sign5::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox Route36_Text_Sign5, MSGBOX_NPC
	giveitem ITEM_ASPEAR_BERRY
	releaseall
	special DaisyMassageServices
	end

Route36_EventScript_Sign7::
	msgbox Route36_Text_Sign7, MSGBOX_AUTOCLOSE
	end
