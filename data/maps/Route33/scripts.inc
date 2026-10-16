Route33_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route33_OnFrame
	.byte 0

Route33_OnFrame::
	map_script_2 0x7014, 0, Route33_EventScript_FrameScene
	.2byte 0

Route33_EventScript_FrameScene::
	setvar 0x7014, 1
	call Route33_EventScript_FrameScene_1
	end

Route33_EventScript_FrameScene_1::
	setvar 0x7010, 0
	setvar 0x7011, 0
	setvar 0x7012, 0
	setvar 0x7013, 0
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

Route33_EventScript_Hiker163::
	trainerbattle_single TRAINER_HIKER_ANTHONY, Route33_Text_Hiker163Intro, Route33_Text_Hiker163Defeat
	call_if_set 0x1305, Route33_EventScript_Hiker163_1
	setvar 0x700C, 5
	setvar 0x700D, 0
	call_if_set 0x1335, Route35_EventScript_Juggler228_2
	msgbox Route33_Text_Hiker163, MSGBOX_NPC
	setflag 0x1335
	call Route35_EventScript_Juggler228_3
	end

Route33_EventScript_Hiker163_1::
	clearflag 0x1305
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, Route33_EventScript_Hiker163_2
	call_if_set 0x115F, Route33_EventScript_Hiker163_3
	call_if_set 0x110A, Route33_EventScript_Hiker163_4
	call_if_set FLAG_BADGE05_GET, Route33_EventScript_Hiker163_5
	trainerbattle_earlyrival TRAINER_HIKER_ANTHONY, 0, Route33_Text_Hiker163Defeat, Route35_Text_Juggler228Victory
	release
	end

Route33_EventScript_Hiker163_2::
	trainerbattle_earlyrival TRAINER_HIKER_ANTHONY_3, 0, Route33_Text_Hiker163Defeat, Route35_Text_Juggler228Victory
	release
	end

Route33_EventScript_Hiker163_3::
	trainerbattle_earlyrival TRAINER_HIKER_ANTHONY_4, 0, Route33_Text_Hiker163Defeat, Route35_Text_Juggler228Victory
	release
	end

Route33_EventScript_Hiker163_4::
	trainerbattle_earlyrival TRAINER_HIKER_ANTHONY_5, 0, Route33_Text_Hiker163Defeat, Route35_Text_Juggler228Victory
	release
	end

Route33_EventScript_Hiker163_5::
	trainerbattle_earlyrival TRAINER_HIKER_ANTHONY_2, 0, Route33_Text_Hiker163Defeat, Route35_Text_Juggler228Victory
	release
	end

Route33_EventScript_Sign2::
	msgbox Route33_Text_Sign2, MSGBOX_AUTOCLOSE
	end
