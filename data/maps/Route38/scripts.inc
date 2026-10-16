Route38_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route38_OnFrame
	.byte 0

Route38_OnFrame::
	map_script_2 0x7019, 0, Route38_EventScript_FrameScene
	.2byte 0

Route38_EventScript_FrameScene::
	setvar 0x7019, 1
	call Route38_EventScript_FrameScene_1
	end

Route38_EventScript_FrameScene_1::
	setvar 0x7010, 0
	setvar 0x7011, 0
	setvar 0x7012, 0
	setvar 0x7013, 0
	setvar 0x7014, 0
	setvar 0x7015, 0
	setvar 0x7016, 0
	setvar 0x7017, 0
	setvar 0x7018, 0
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

Route38_EventScript_SailorHarry::
	trainerbattle_single TRAINER_SAILOR_HARRY, Route38_Text_SailorHarryIntro, Route38_Text_SailorHarryDefeat
	msgbox Route38_Text_SailorHarry, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_BirdKeeperToby::
	trainerbattle_single TRAINER_BIRD_KEEPER_TOBY, Route38_Text_BirdKeeperTobyIntro, Route38_Text_BirdKeeperTobyDefeat
	msgbox Route38_Text_BirdKeeperToby, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Lass122::
	trainerbattle_single TRAINER_LASS_DANA, Route38_Text_Lass122Intro, Route38_Text_Lass122Defeat
	call_if_set 0x1313, Route38_EventScript_Lass122_1
	setvar 0x700C, 19
	setvar 0x700D, 0
	call_if_set 0x1343, Route35_EventScript_Juggler228_2
	msgbox Route38_Text_Lass122, MSGBOX_NPC
	setflag 0x1343
	call Route35_EventScript_Juggler228_3
	end

Route38_EventScript_Lass122_1::
	clearflag 0x1313
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, Route38_EventScript_Lass122_2
	call_if_set 0x115F, Route38_EventScript_Lass122_3
	call_if_set 0x110A, Route38_EventScript_Lass122_4
	call_if_set FLAG_BADGE05_GET, Route38_EventScript_Lass122_5
	trainerbattle_earlyrival TRAINER_LASS_DANA, 0, Route38_Text_Lass122Defeat, Route35_Text_Juggler228Victory
	release
	end

Route38_EventScript_Lass122_2::
	trainerbattle_earlyrival TRAINER_LASS_DANA_4, 0, Route38_Text_Lass122Defeat, Route35_Text_Juggler228Victory
	release
	end

Route38_EventScript_Lass122_3::
	trainerbattle_earlyrival TRAINER_LASS_DANA_5, 0, Route38_Text_Lass122Defeat, Route35_Text_Juggler228Victory
	release
	end

Route38_EventScript_Lass122_4::
	trainerbattle_earlyrival TRAINER_LASS_DANA_3, 0, Route38_Text_Lass122Defeat, Route35_Text_Juggler228Victory
	release
	end

Route38_EventScript_Lass122_5::
	trainerbattle_earlyrival TRAINER_LASS_DANA_2, 0, Route38_Text_Lass122Defeat, Route35_Text_Juggler228Victory
	release
	end

Route38_EventScript_BeautyValerie::
	trainerbattle_single TRAINER_BEAUTY_VALERIE, Route38_Text_BeautyValerieIntro, Route38_Text_BeautyValerieDefeat
	msgbox Route38_Text_BeautyValerie, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Schoolboy285::
	trainerbattle_single TRAINER_SCHOOLBOY_CHAD, Route38_Text_Schoolboy285Intro, Route38_Text_Schoolboy285Defeat
	call_if_set 0x1314, Route38_EventScript_Schoolboy285_1
	setvar 0x700C, 20
	setvar 0x700D, 0
	call_if_set 0x1344, Route35_EventScript_Juggler228_2
	msgbox Route38_Text_Schoolboy285, MSGBOX_NPC
	setflag 0x1344
	call Route35_EventScript_Juggler228_3
	end

Route38_EventScript_Schoolboy285_1::
	clearflag 0x1314
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, Route38_EventScript_Schoolboy285_2
	call_if_set 0x115F, Route38_EventScript_Schoolboy285_3
	call_if_set 0x110A, Route38_EventScript_Schoolboy285_4
	call_if_set FLAG_BADGE05_GET, Route38_EventScript_Schoolboy285_5
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_CHAD, 0, Route38_Text_Schoolboy285Defeat, Route35_Text_Juggler228Victory
	release
	end

Route38_EventScript_Schoolboy285_2::
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_CHAD_2, 0, Route38_Text_Schoolboy285Defeat, Route35_Text_Juggler228Victory
	end

Route38_EventScript_Schoolboy285_3::
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_CHAD_3, 0, Route38_Text_Schoolboy285Defeat, Route35_Text_Juggler228Victory
	release
	end

Route38_EventScript_Schoolboy285_4::
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_CHAD_4, 0, Route38_Text_Schoolboy285Defeat, Route35_Text_Juggler228Victory
	release
	end

Route38_EventScript_Schoolboy285_5::
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_CHAD_5, 0, Route38_Text_Schoolboy285Defeat, Route35_Text_Juggler228Victory
	release
	end

Route38_EventScript_Man::
	call_if_set 0x1243, Route38_EventScript_Man_1
	msgbox Route38_Text_Man_1, MSGBOX_NPC
	giveitem ITEM_HARD_STONE
	msgbox Route38_Text_Man_2, MSGBOX_NPC
	setflag 0x1243
	clearflag 0x1244
	release
	end

Route38_EventScript_Man_1::
	msgbox Route38_Text_Man_3, MSGBOX_NPC
	end

Route38_EventScript_Trigger1::
	call_if_unset FLAG_BADGE05_GET, Route38_EventScript_Trigger1_1
	setflag 0x10B0
	release
	end

Route38_EventScript_Trigger1_1::
	release
	end

Route38_EventScript_Sign1::
	msgbox Route38_Text_Sign1, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Sign2::
	msgbox Route38_Text_Sign2, MSGBOX_AUTOCLOSE
	end
