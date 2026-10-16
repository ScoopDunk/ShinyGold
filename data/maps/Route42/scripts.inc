Route42_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route42_OnFrame
	.byte 0

Route42_OnFrame::
	map_script_2 0x701B, 0, Route42_EventScript_FrameScene
	.2byte 0

Route42_EventScript_FrameScene::
	setvar 0x701B, 1
	call Route42_EventScript_FrameScene_1
	end

Route42_EventScript_FrameScene_1::
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

Route42_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route42_EventScript_ItemSuperPotion::
	finditem ITEM_SUPER_POTION
	end

Route42_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

Route42_EventScript_Fisherman465::
	trainerbattle_single TRAINER_FISHERMAN_CHRIS, Route42_Text_Fisherman465Intro, Route42_Text_Fisherman465Defeat
	call_if_set 0x1318, Route42_EventScript_Fisherman465_1
	setvar 0x700C, 24
	setvar 0x700D, 0
	call_if_set 0x1348, Route35_EventScript_Juggler228_2
	msgbox Route42_Text_Fisherman465, MSGBOX_NPC
	setflag 0x1348
	call Route35_EventScript_Juggler228_3
	end

Route42_EventScript_Fisherman465_1::
	clearflag 0x1318
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x8888, Route42_EventScript_Fisherman465_2
	call_if_set 0x115F, Route42_EventScript_Fisherman465_3
	call_if_set FLAG_BADGE07_GET, Route42_EventScript_Fisherman465_4
	call_if_set FLAG_BADGE05_GET, Route42_EventScript_Fisherman465_5
	trainerbattle_earlyrival TRAINER_FISHERMAN_CHRIS, 0, Route42_Text_Fisherman465Defeat, Route35_Text_Juggler228Victory
	release
	end

Route42_EventScript_Fisherman465_2::
	trainerbattle_earlyrival TRAINER_FISHERMAN_CHRIS_2, 0, Route42_Text_Fisherman465Defeat, Route35_Text_Juggler228Victory
	release
	end

Route42_EventScript_Fisherman465_3::
	trainerbattle_earlyrival TRAINER_FISHERMAN_CHRIS_3, 0, Route42_Text_Fisherman465Defeat, Route35_Text_Juggler228Victory
	release
	end

Route42_EventScript_Fisherman465_4::
	trainerbattle_earlyrival TRAINER_FISHERMAN_CHRIS_4, 0, Route42_Text_Fisherman465Defeat, Route35_Text_Juggler228Victory
	release
	end

Route42_EventScript_Fisherman465_5::
	trainerbattle_earlyrival TRAINER_FISHERMAN_CHRIS_5, 0, Route42_Text_Fisherman465Defeat, Route35_Text_Juggler228Victory
	release
	end

Route42_EventScript_PokemaniacShane::
	trainerbattle_single TRAINER_POKEMANIAC_SHANE, Route42_Text_PokemaniacShaneIntro, Route42_Text_PokemaniacShaneDefeat
	msgbox Route42_Text_PokemaniacShane, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_HikerBenjamin::
	trainerbattle_single TRAINER_HIKER_BENJAMIN, Route42_Text_HikerBenjaminIntro, Route42_Text_HikerBenjaminDefeat
	msgbox Route42_Text_HikerBenjamin, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Trigger1::
	call_if_set 0x11EA, Route42_EventScript_Trigger1_1
	setflag 0x10E3
	setflag 0x10E4
	setflag 0x10E5
	setflag 0x112A
	setflag 0x10DB
	release
	end

Route42_EventScript_Trigger1_1::
	release
	end

Route42_EventScript_Sign1::
	msgbox Route42_Text_Sign1, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Sign2::
	msgbox Route42_Text_Sign2, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Sign5::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox Route42_Text_Sign5, MSGBOX_NPC
	giveitem ITEM_PINK_SCARF
	releaseall
	special DaisyMassageServices
	end

Route42_EventScript_Sign6::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox Route42_Text_Sign6, MSGBOX_NPC
	giveitem ITEM_GREEN_SCARF
	releaseall
	special DaisyMassageServices
	end

Route42_EventScript_Sign7::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox Route42_Text_Sign7, MSGBOX_NPC
	giveitem ITEM_YELLOW_SCARF
	releaseall
	special DaisyMassageServices
	end
