Route31_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route31_OnFrame
	.byte 0

Route31_OnFrame::
	map_script_2 0x7012, 0, Route31_EventScript_FrameScene
	.2byte 0

Route31_EventScript_FrameScene::
	setvar 0x7012, 1
	call Route31_EventScript_FrameScene_1
	end

Route31_EventScript_FrameScene_1::
	setvar 0x7010, 0
	setvar 0x7011, 0
	setvar 0x7013, 0
	setvar 0x7014, 0
	setvar 0x7015, 0
	setvar 0x7016, 0
	setvar 0x7017, 0
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

Route31_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL
	end

Route31_EventScript_Man::
	msgbox Route31_Text_Man, MSGBOX_NPC
	end

Route31_EventScript_FatMan::
	call_if_set 0x10A0, Route31_EventScript_FatMan_1
	checkitem ITEM_LETTER
	call_if_eq VAR_RESULT, 1, Route31_EventScript_FatMan_2
	msgbox Route31_Text_FatMan_1, MSGBOX_NPC
	end

Route31_EventScript_FatMan_1::
	msgbox Route31_Text_FatMan_2, MSGBOX_NPC
	end

Route31_EventScript_FatMan_2::
	setflag 0x10A0
	msgbox Route31_Text_FatMan_3, MSGBOX_NPC
	giveitem ITEM_TM46
	removeitem ITEM_LETTER
	msgbox Route31_Text_FatMan_4, MSGBOX_NPC
	end

Route31_EventScript_Youngster::
	msgbox Route31_Text_Youngster, MSGBOX_NPC
	end

Route31_EventScript_BugCatcher309::
	trainerbattle_single TRAINER_BUG_CATCHER_WADE, Route31_Text_BugCatcher309Intro, Route31_Text_BugCatcher309Defeat
	call_if_set 0x1302, Route31_EventScript_BugCatcher309_1
	setvar 0x700C, 2
	setvar 0x700D, 0
	call_if_set 0x1332, Route35_EventScript_Juggler228_2
	msgbox Route31_Text_BugCatcher309, MSGBOX_NPC
	setflag 0x1332
	call Route35_EventScript_Juggler228_3
	end

Route31_EventScript_BugCatcher309_1::
	clearflag 0x1302
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, Route31_EventScript_BugCatcher309_2
	call_if_set 0x110A, Route31_EventScript_BugCatcher309_3
	call_if_set FLAG_BADGE05_GET, Route31_EventScript_BugCatcher309_4
	call_if_set FLAG_BADGE02_GET, Route31_EventScript_BugCatcher309_5
	trainerbattle_earlyrival TRAINER_BUG_CATCHER_WADE, 0, Route31_Text_BugCatcher309Defeat, Route35_Text_Juggler228Victory
	release
	end

Route31_EventScript_BugCatcher309_2::
	trainerbattle_earlyrival TRAINER_BUG_CATCHER_WADE_4, 0, Route31_Text_BugCatcher309Defeat, Route35_Text_Juggler228Victory
	release
	end

Route31_EventScript_BugCatcher309_3::
	trainerbattle_earlyrival TRAINER_BUG_CATCHER_WADE_5, 0, Route31_Text_BugCatcher309Defeat, Route35_Text_Juggler228Victory
	release
	end

Route31_EventScript_BugCatcher309_4::
	trainerbattle_earlyrival TRAINER_BUG_CATCHER_WADE_3, 0, Route31_Text_BugCatcher309Defeat, Route35_Text_Juggler228Victory
	release
	end

Route31_EventScript_BugCatcher309_5::
	trainerbattle_earlyrival TRAINER_BUG_CATCHER_WADE_2, 0, Route31_Text_BugCatcher309Defeat, Route35_Text_Juggler228Victory
	release
	end

Route31_EventScript_Sign1::
	msgbox Route31_Text_Sign1, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_Sign2::
	msgbox Route31_Text_Sign2, MSGBOX_AUTOCLOSE
	end

@ ShinyGold: moved from data/maps/GreenPlains/scripts.inc (map removed)
GreenPlains_EventScript_Sign5::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox GreenPlains_Text_Sign5, MSGBOX_NPC
	giveitem ITEM_PERSIM_BERRY
	releaseall
	special DaisyMassageServices
	end
