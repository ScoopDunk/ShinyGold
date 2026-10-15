Route37_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route37_OnFrame
	.byte 0

Route37_OnFrame::
	map_script_2 0x7018, 0, Route37_EventScript_FrameScene
	.2byte 0

Route37_EventScript_FrameScene::
	setvar 0x7018, 1
	call Route37_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

Route37_EventScript_FrameScene_1::
	setvar 0x7010, 0
	setvar 0x7011, 0
	setvar 0x7012, 0
	setvar 0x7013, 0
	setvar 0x7014, 0
	setvar 0x7015, 0
	setvar 0x7016, 0
	setvar 0x7017, 0
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

Route37_EventScript_TwinsAnnAndAnne::
	trainerbattle_single TRAINER_TWINS_ANN_AND_ANNE, Route37_Text_TwinsAnnAndAnneIntro, Route37_Text_TwinsAnnAndAnneDefeat
	msgbox Route37_Text_TwinsAnnAndAnne, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_TwinsAnnAndAnne2::
	trainerbattle_single TRAINER_TWINS_ANN_AND_ANNE, Route37_Text_TwinsAnnAndAnne2Intro, Route37_Text_TwinsAnnAndAnneDefeat
	msgbox Route37_Text_TwinsAnnAndAnne2, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_PsychicGreg::
	trainerbattle_single TRAINER_PSYCHIC_GREG, Route37_Text_PsychicGregIntro, Route37_Text_PsychicGregDefeat
	msgbox Route37_Text_PsychicGreg, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_ItemEther::
	finditem ITEM_ETHER
	end

Route37_EventScript_Trigger1::
	call_if_set 0x10AE, Route37_EventScript_Trigger1_1
	setflag 0x10AD
	release
	end

Route37_EventScript_Trigger1_1::
	release
	end

Route37_EventScript_Sign1::
	msgbox Route37_Text_Sign1, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_Sign2::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox Route37_Text_Sign2, MSGBOX_NPC
	giveitem ITEM_RED_SCARF
	releaseall
	special DaisyMassageServices
	end
