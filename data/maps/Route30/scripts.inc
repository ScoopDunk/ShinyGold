Route30_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route30_OnFrame
	.byte 0

Route30_OnFrame::
	map_script_2 0x7011, 0, Route30_EventScript_FrameScene
	.2byte 0

Route30_EventScript_FrameScene::
	setvar 0x7011, 1
	call Route30_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

Route30_EventScript_FrameScene_1::
	setvar 0x7010, 0
	setvar 0x7012, 0
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

Route30_EventScript_BugCatcherDon::
	trainerbattle_single TRAINER_BUG_CATCHER_DON, Route30_Text_BugCatcherDonIntro, Route30_Text_BugCatcherDonDefeat
	msgbox Route30_Text_BugCatcherDon, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Man::
	msgbox Route30_Text_Man, MSGBOX_NPC
	end

Route30_EventScript_Youngster::
	playbgm MUS_VS_WILD, 51
	msgbox Route30_Text_Youngster_1, MSGBOX_AUTOCLOSE
	applymovement 4, Route30_Movement_Youngster_1
	msgbox Route30_Text_Youngster_2, MSGBOX_NPC
	applymovement 3, Route30_Movement_Youngster_2
	applymovement 5, Route30_Movement_Youngster_3
	playbgm MUS_ROUTE24, 51
	end

Route30_Movement_Youngster_1::
	walk_fast_up
	walk_fast_down
	face_up
	step_end

Route30_Movement_Youngster_2::
	face_up
	step_end

Route30_Movement_Youngster_3::
	walk_fast_down
	walk_fast_up
	face_down_fast
	step_end

Route30_EventScript_Youngster89::
	trainerbattle_single TRAINER_YOUNGSTER_JOEY_2, Route30_Text_Youngster89Intro, Route30_Text_Youngster89Defeat
	call_if_set 0x1301, Route30_EventScript_Youngster89_1
	setvar 0x700C, 1
	setvar 0x700D, 0
	call_if_set 0x1331, Route35_EventScript_Juggler228_2
	msgbox Route30_Text_Youngster89, MSGBOX_NPC
	setflag 0x1331
	call Route35_EventScript_Juggler228_3
	end

Route30_EventScript_Youngster89_1::
	clearflag 0x1301
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x8888, Route30_EventScript_Youngster89_2
	call_if_set FLAG_BADGE07_GET, Route30_EventScript_Youngster89_3
	call_if_set FLAG_BADGE05_GET, Route30_EventScript_Youngster89_4
	call_if_set FLAG_BADGE02_GET, Route30_EventScript_Youngster89_5
	trainerbattle_earlyrival TRAINER_YOUNGSTER_JOEY_2, 0, Route30_Text_Youngster89Defeat, Route35_Text_Juggler228Victory
	release
	end

Route30_EventScript_Youngster89_2::
	trainerbattle_earlyrival TRAINER_YOUNGSTER_JOEY_6, 0, Route30_Text_Youngster89Defeat, Route35_Text_Juggler228Victory
	release
	end

Route30_EventScript_Youngster89_3::
	trainerbattle_earlyrival TRAINER_YOUNGSTER_JOEY_5, 0, Route30_Text_Youngster89Defeat, Route35_Text_Juggler228Victory
	release
	end

Route30_EventScript_Youngster89_4::
	trainerbattle_earlyrival TRAINER_YOUNGSTER_JOEY_4, 0, Route30_Text_Youngster89Defeat, Route35_Text_Juggler228Victory
	release
	end

Route30_EventScript_Youngster89_5::
	trainerbattle_earlyrival TRAINER_YOUNGSTER_JOEY_3, 0, Route30_Text_Youngster89Defeat, Route35_Text_Juggler228Victory
	release
	end

Route30_EventScript_Woman1::
	msgbox Route30_Text_Woman1, MSGBOX_NPC
	end

Route30_EventScript_YoungsterMikey::
	trainerbattle_single TRAINER_YOUNGSTER_MIKEY, Route30_Text_YoungsterMikeyIntro, Route30_Text_YoungsterMikeyDefeat
	msgbox Route30_Text_YoungsterMikey, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Trigger1::
	call_if_set 0x1030, Route30_EventScript_Trigger1_1
	setflag 0x1029
	release
	end

Route30_EventScript_Trigger1_1::
	release
	end

Route30_EventScript_Trigger3::
	call_if_unset 0x1015, Route30_EventScript_Trigger3_1
	call_if_set 0x1016, Route30_EventScript_Trigger3_1
	call Route30_EventScript_Trigger3_2
	msgbox Route30_Text_Trigger3_1, MSGBOX_NPC
	call Route30_EventScript_Trigger3_3
	release
	end

Route30_EventScript_Trigger3_1::
	release
	end

Route30_EventScript_Trigger3_2::
	playbgm SE_DEX_SEARCH, 51
	delay 96
	playbgm SE_SUCCESS, 51
	msgbox Route30_Text_Trigger3_2, MSGBOX_NPC
	return

Route30_EventScript_Trigger3_3::
	setflag 0x1016
	setflag 0x1019
	setflag 0x1022
	clearflag 0x1018
	clearflag 0x1021
	call_if_eq VAR_STARTER_MON, 0, Route30_EventScript_Trigger3_4
	call_if_eq VAR_STARTER_MON, 1, Route30_EventScript_Trigger3_5
	call Route30_EventScript_Trigger3_6
	end

Route30_EventScript_Trigger3_4::
	setflag 0x02A
	release
	end

Route30_EventScript_Trigger3_5::
	setflag 0x028
	release
	end

Route30_EventScript_Trigger3_6::
	setflag 0x029
	release
	end

Route30_EventScript_Trigger6::
	call_if_set 0x1247, Route30_EventScript_Trigger6_1
	call_if_set 0x1027, Route30_EventScript_Trigger6_1
	playbgm SE_DEX_SEARCH, 51
	delay 96
	playbgm SE_SUCCESS, 51
	msgbox Route30_Text_Trigger6_1, MSGBOX_NPC
	msgbox Route30_Text_Trigger6_2, MSGBOX_NPC
	setflag 0x1247
	release
	end

Route30_EventScript_Trigger6_1::
	release
	end

Route30_EventScript_Sign1::
	msgbox Route30_Text_Sign1, MSGBOX_NPC
	end

Route30_EventScript_Sign2::
	msgbox Route30_Text_Sign2, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Sign3::
	msgbox Route30_Text_Sign3, MSGBOX_NPC
	end

Route30_EventScript_Sign4::
	msgbox Route30_Text_Sign4, MSGBOX_NPC
	end

Route30_EventScript_Sign5::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox Route30_Text_Sign5, MSGBOX_NPC
	giveitem ITEM_ORAN_BERRY
	releaseall
	special DaisyMassageServices
	end

Route30_EventScript_Sign6::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox Route30_Text_Sign6, MSGBOX_NPC
	giveitem ITEM_PECHA_BERRY
	releaseall
	special DaisyMassageServices
	end
