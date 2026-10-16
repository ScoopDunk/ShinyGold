Route45_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route45_OnFrame
	.byte 0

Route45_OnFrame::
	map_script_2 0x701E, 0, Route45_EventScript_FrameScene
	.2byte 0

Route45_EventScript_FrameScene::
	setvar 0x701E, 1
	call Route45_EventScript_FrameScene_1
	end

Route45_EventScript_FrameScene_1::
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

Route45_EventScript_ItemElixir::
	finditem ITEM_ELIXIR
	end

Route45_EventScript_HikerErik::
	trainerbattle_single TRAINER_HIKER_ERIK, Route45_Text_HikerErikIntro, Route45_Text_HikerErikDefeat
	msgbox Route45_Text_HikerErik, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_CooltrainerRyan::
	trainerbattle_single TRAINER_COOLTRAINER_RYAN, Route45_Text_CooltrainerRyanIntro, Route45_Text_CooltrainerRyanDefeat
	msgbox Route45_Text_CooltrainerRyan, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Hiker172::
	trainerbattle_single TRAINER_HIKER_PARRY_3, Route45_Text_Hiker172Intro, Route45_Text_Hiker172Defeat
	call_if_set 0x1324, Route45_EventScript_Hiker172_1
	setvar 0x700C, 36
	setvar 0x700D, 0
	call_if_set 0x1354, Route35_EventScript_Juggler228_2
	msgbox Route45_Text_Hiker172, MSGBOX_NPC
	setflag 0x1354
	call Route35_EventScript_Juggler228_3
	end

Route45_EventScript_Hiker172_1::
	clearflag 0x1324
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, Route45_EventScript_Hiker172_2
	call_if_set 0x115F, Route45_EventScript_Hiker172_3
	call_if_set FLAG_BADGE07_GET, Route45_EventScript_Hiker172_4
	trainerbattle_earlyrival TRAINER_HIKER_PARRY_3, 0, Route45_Text_Hiker172Defeat, Route35_Text_Juggler228Victory
	release
	end

Route45_EventScript_Hiker172_2::
	trainerbattle_earlyrival TRAINER_HIKER_PARRY_2, 0, Route45_Text_Hiker172Defeat, Route35_Text_Juggler228Victory
	release
	end

Route45_EventScript_Hiker172_3::
	trainerbattle_earlyrival TRAINER_HIKER_PARRY_4, 0, Route45_Text_Hiker172Defeat, Route35_Text_Juggler228Victory
	release
	end

Route45_EventScript_Hiker172_4::
	trainerbattle_earlyrival TRAINER_HIKER_PARRY, 0, Route45_Text_Hiker172Defeat, Route35_Text_Juggler228Victory
	release
	end

Route45_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

Route45_EventScript_CooltrainerKelly::
	trainerbattle_single TRAINER_COOLTRAINER_KELLY, Route45_Text_CooltrainerKellyIntro, Route45_Text_CooltrainerKellyDefeat
	msgbox Route45_Text_CooltrainerKelly, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_ItemXSpecial::
	finditem ITEM_X_SPECIAL
	end

Route45_EventScript_BlackBelt316::
	trainerbattle_single TRAINER_BLACK_BELT_KENJI, Route45_Text_BlackBelt316Intro, Route45_Text_BlackBelt316Defeat
	call_if_set 0x1323, Route45_EventScript_BlackBelt316_1
	setvar 0x700C, 35
	setvar 0x700D, 0
	call_if_set 0x1353, Route35_EventScript_Juggler228_2
	msgbox Route45_Text_BlackBelt316, MSGBOX_NPC
	setflag 0x1353
	call Route35_EventScript_Juggler228_3
	end

Route45_EventScript_BlackBelt316_1::
	clearflag 0x1323
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, Route45_EventScript_BlackBelt316_2
	call_if_set 0x115F, Route45_EventScript_BlackBelt316_3
	call_if_set FLAG_BADGE07_GET, Route45_EventScript_BlackBelt316_4
	call_if_set 0x110A, Route45_EventScript_BlackBelt316_5
	trainerbattle_earlyrival TRAINER_BLACK_BELT_KENJI, 0, Route45_Text_BlackBelt316Defeat, Route35_Text_Juggler228Victory
	release
	end

Route45_EventScript_BlackBelt316_2::
	trainerbattle_earlyrival TRAINER_BLACK_BELT_KENJI_2, 0, Route45_Text_BlackBelt316Defeat, Route35_Text_Juggler228Victory
	release
	end

Route45_EventScript_BlackBelt316_3::
	trainerbattle_earlyrival TRAINER_BLACK_BELT_KENJI_4, 0, Route45_Text_BlackBelt316Defeat, Route35_Text_Juggler228Victory
	release
	end

Route45_EventScript_BlackBelt316_4::
	trainerbattle_earlyrival TRAINER_BLACK_BELT_KENJI_5, 0, Route45_Text_BlackBelt316Defeat, Route35_Text_Juggler228Victory
	release
	end

Route45_EventScript_BlackBelt316_5::
	trainerbattle_earlyrival TRAINER_BLACK_BELT_KENJI_6, 0, Route45_Text_BlackBelt316Defeat, Route35_Text_Juggler228Victory
	release
	end

Route45_EventScript_HikerTimothy::
	trainerbattle_single TRAINER_HIKER_TIMOTHY, Route45_Text_HikerTimothyIntro, Route45_Text_HikerTimothyDefeat
	msgbox Route45_Text_HikerTimothy, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_ItemRevive::
	finditem ITEM_REVIVE
	end

Route45_EventScript_HikerMichael::
	trainerbattle_single TRAINER_HIKER_MICHAEL, Route45_Text_HikerMichaelIntro, Route45_Text_HikerMichaelDefeat
	msgbox Route45_Text_HikerMichael, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_ItemPpUp::
	finditem ITEM_PP_UP
	end

Route45_EventScript_Sign1::
	msgbox Route45_Text_Sign1, MSGBOX_NPC
	end
