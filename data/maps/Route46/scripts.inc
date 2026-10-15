Route46_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route46_OnFrame
	.byte 0

Route46_OnFrame::
	map_script_2 0x701F, 0, Route46_EventScript_FrameScene
	.2byte 0

Route46_EventScript_FrameScene::
	setvar 0x701F, 1
	call Route46_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

Route46_EventScript_FrameScene_1::
	setvar 0x7010, 0
	setvar 0x7011, 0
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

Route46_EventScript_ItemDireHit::
	finditem ITEM_DIRE_HIT
	end

Route46_EventScript_Picnicker116::
	trainerbattle_single TRAINER_PICNICKER_ERIN, Route46_Text_Picnicker116Intro, Route46_Text_Picnicker116Defeat
	call_if_set 0x1316, Route46_EventScript_Picnicker116_1
	setvar 0x700C, 22
	setvar 0x700D, 0
	call_if_set 0x1346, Route35_EventScript_Juggler228_2
	msgbox Route46_Text_Picnicker116, MSGBOX_NPC
	setflag 0x1346
	call Route35_EventScript_Juggler228_3
	end

Route46_EventScript_Picnicker116_1::
	clearflag 0x1316
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x8888, Route46_EventScript_Picnicker116_2
	call_if_set 0x115F, Route46_EventScript_Picnicker116_3
	call_if_set FLAG_BADGE07_GET, Route46_EventScript_Picnicker116_4
	call_if_set 0x110A, Route46_EventScript_Picnicker116_5
	trainerbattle_earlyrival TRAINER_PICNICKER_ERIN, 0, Route46_Text_Picnicker116Defeat, Route35_Text_Juggler228Victory
	release
	end

Route46_EventScript_Picnicker116_2::
	trainerbattle_earlyrival TRAINER_POKEMANIAC_BRENT_5, 0, Route46_Text_Picnicker116Defeat, Route35_Text_Juggler228Victory
	release
	end

Route46_EventScript_Picnicker116_3::
	trainerbattle_earlyrival TRAINER_PICNICKER_ERIN_5, 0, Route46_Text_Picnicker116Defeat, Route35_Text_Juggler228Victory
	release
	end

Route46_EventScript_Picnicker116_4::
	trainerbattle_earlyrival TRAINER_PICNICKER_ERIN_3, 0, Route46_Text_Picnicker116Defeat, Route35_Text_Juggler228Victory
	release
	end

Route46_EventScript_Picnicker116_5::
	trainerbattle_earlyrival TRAINER_PICNICKER_ERIN_2, 0, Route46_Text_Picnicker116Defeat, Route35_Text_Juggler228Victory
	release
	end

Route46_EventScript_CamperTed::
	trainerbattle_single TRAINER_CAMPER_TED, Route46_Text_CamperTedIntro, Route46_Text_CamperTedDefeat
	msgbox Route46_Text_CamperTed, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_HikerBailey::
	trainerbattle_single TRAINER_HIKER_BAILEY, Route46_Text_HikerBaileyIntro, Route46_Text_HikerBaileyDefeat
	msgbox Route46_Text_HikerBailey, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Trigger2::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox Route46_Text_Trigger2, MSGBOX_NPC
	giveitem ITEM_CHERI_BERRY
	releaseall
	special DaisyMassageServices
	end
