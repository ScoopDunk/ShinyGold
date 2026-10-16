Route35_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route35_OnFrame
	.byte 0

Route35_OnFrame::
	map_script_2 0x7016, 0, Route35_EventScript_FrameScene
	.2byte 0

Route35_EventScript_FrameScene::
	setvar 0x7016, 1
	call Route35_EventScript_FrameScene_1
	end

Route35_EventScript_FrameScene_1::
	setvar 0x7010, 0
	setvar 0x7011, 0
	setvar 0x7012, 0
	setvar 0x7013, 0
	setvar 0x7014, 0
	setvar 0x7015, 0
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

@ Pure Gold: this used to show the static Raikou, Entei and Suicune at random on Johto's routes. They roam now
@ (src/roamer.c). The towns' frame scripts still call it.
Route35_EventScript_FrameScene_2::
	return

Route35_EventScript_PicnickerKim::
	trainerbattle_single TRAINER_PICNICKER_KIM, Route35_Text_PicnickerKimIntro, Route35_Text_PicnickerKimDefeat
	msgbox Route35_Text_PicnickerKim, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_CamperElliot::
	trainerbattle_single TRAINER_CAMPER_ELLIOT, Route35_Text_CamperElliotIntro, Route35_Text_CamperElliotDefeat
	msgbox Route35_Text_CamperElliot, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerBrooke::
	trainerbattle_single TRAINER_PICNICKER_BROOKE, Route35_Text_PicnickerBrookeIntro, Route35_Text_PicnickerBrookeDefeat
	msgbox Route35_Text_PicnickerBrooke, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_CamperIvan::
	trainerbattle_single TRAINER_CAMPER_IVAN, Route35_Text_CamperIvanIntro, Route35_Text_CamperIvanDefeat
	msgbox Route35_Text_CamperIvan, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_FirebreatherWalt::
	trainerbattle_single TRAINER_FIREBREATHER_WALT, Route35_Text_FirebreatherWaltIntro, Route35_Text_FirebreatherWaltDefeat
	msgbox Route35_Text_FirebreatherWalt, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Juggler228::
	trainerbattle_single TRAINER_JUGGLER_IRWIN, Route35_Text_Juggler228Intro, Route35_Text_Juggler228Defeat
	call_if_set 0x1308, Route35_EventScript_Juggler228_1
	setvar 0x700C, 8
	setvar 0x700D, 0
	call_if_set 0x1338, Route35_EventScript_Juggler228_2
	msgbox Route35_Text_Juggler228_1, MSGBOX_NPC
	setflag 0x1338
	call Route35_EventScript_Juggler228_3
	end

Route35_EventScript_Juggler228_1::
	clearflag 0x1308
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x8888, Route35_EventScript_Juggler228_4
	call_if_set 0x115F, Route35_EventScript_Juggler228_5
	call_if_set 0x110A, Route35_EventScript_Juggler228_6
	call_if_set FLAG_BADGE05_GET, Route35_EventScript_Juggler228_7
	trainerbattle_earlyrival TRAINER_JUGGLER_IRWIN, 0, Route35_Text_Juggler228Defeat, Route35_Text_Juggler228Victory
	release
	end

Route35_EventScript_Juggler228_2::
	call Route35_EventScript_Juggler228_8
	call_if_eq 0x7000, 0, Route35_EventScript_Juggler228_9
	call_if_eq 0x7001, 0, Route35_EventScript_Juggler228_10
	call_if_eq 0x7002, 0, Route35_EventScript_Juggler228_11
	call_if_eq 0x7003, 0, Route35_EventScript_Juggler228_12
	call_if_eq 0x7004, 0, Route35_EventScript_Juggler228_13
	call_if_eq 0x7005, 0, Route35_EventScript_Juggler228_14
	call_if_eq 0x7006, 0, Route35_EventScript_Juggler228_15
	call_if_eq 0x7007, 0, Route35_EventScript_Juggler228_16
	msgbox Route35_Text_Juggler228_3, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_3::
	setvar 0x700D, 1
	msgbox Route35_Text_Juggler228_4, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_2
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_4::
	trainerbattle_earlyrival TRAINER_JUGGLER_IRWIN_3, 0, Route35_Text_Juggler228Defeat, Route35_Text_Juggler228Victory
	release
	end

Route35_EventScript_Juggler228_5::
	trainerbattle_earlyrival TRAINER_JUGGLER_IRWIN_4, 0, Route35_Text_Juggler228Defeat, Route35_Text_Juggler228Victory
	release
	end

Route35_EventScript_Juggler228_6::
	trainerbattle_earlyrival TRAINER_JUGGLER_IRWIN_5, 0, Route35_Text_Juggler228Defeat, Route35_Text_Juggler228Victory
	release
	end

Route35_EventScript_Juggler228_7::
	trainerbattle_earlyrival TRAINER_JUGGLER_IRWIN_2, 0, Route35_Text_Juggler228Defeat, Route35_Text_Juggler228Victory
	release
	end

Route35_EventScript_Juggler228_8::
	goto_if_eq 0x700C, 1, Route35_EventScript_Juggler228_17
	goto_if_eq 0x700C, 2, Route35_EventScript_Juggler228_18
	goto_if_eq 0x700C, 3, Route35_EventScript_Juggler228_19
	goto_if_eq 0x700C, 4, Route35_EventScript_Juggler228_20
	goto_if_eq 0x700C, 5, Route35_EventScript_Juggler228_21
	goto_if_eq 0x700C, 6, Route35_EventScript_Juggler228_22
	goto_if_eq 0x700C, 7, Route35_EventScript_Juggler228_23
	goto_if_eq 0x700C, 8, Route35_EventScript_Juggler228_24
	goto_if_eq 0x700C, 9, Route35_EventScript_Juggler228_25
	goto_if_eq 0x700C, 16, Route35_EventScript_Juggler228_26
	goto_if_eq 0x700C, 17, Route35_EventScript_Juggler228_27
	goto_if_eq 0x700C, 18, Route35_EventScript_Juggler228_28
	goto_if_eq 0x700C, 19, Route35_EventScript_Juggler228_29
	goto_if_eq 0x700C, 20, Route35_EventScript_Juggler228_30
	goto_if_eq 0x700C, 21, Route35_EventScript_Juggler228_31
	goto_if_eq 0x700C, 22, Route35_EventScript_Juggler228_32
	goto_if_eq 0x700C, 23, Route35_EventScript_Juggler228_33
	goto_if_eq 0x700C, 24, Route35_EventScript_Juggler228_34
	goto_if_eq 0x700C, 25, Route35_EventScript_Juggler228_35
	goto_if_eq 0x700C, 32, Route35_EventScript_Juggler228_36
	goto_if_eq 0x700C, 33, Route35_EventScript_Juggler228_37
	goto_if_eq 0x700C, 34, Route35_EventScript_Juggler228_38
	goto_if_eq 0x700C, 35, Route35_EventScript_Juggler228_39
	goto_if_eq 0x700C, 36, Route35_EventScript_Juggler228_40
	goto_if_eq 0x700C, 37, Route35_EventScript_Juggler228_41
	goto_if_eq 0x700C, 38, Route35_EventScript_Juggler228_42
	goto_if_eq 0x700C, 39, Route35_EventScript_Juggler228_43
	goto_if_eq 0x700C, 40, Route35_EventScript_Juggler228_44
	return

Route35_EventScript_Juggler228_9::
	call_if_eq 0x700D, 1, Route35_EventScript_Juggler228_45
	msgbox Route35_Text_Juggler228_6, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_45
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_10::
	call_if_eq 0x700D, 1, Route35_EventScript_Juggler228_46
	msgbox Route35_Text_Juggler228_6, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_46
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_11::
	call_if_eq 0x700D, 1, Route35_EventScript_Juggler228_47
	msgbox Route35_Text_Juggler228_6, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_47
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_12::
	call_if_eq 0x700D, 1, Route35_EventScript_Juggler228_48
	msgbox Route35_Text_Juggler228_6, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_48
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_13::
	call_if_eq 0x700D, 1, Route35_EventScript_Juggler228_49
	msgbox Route35_Text_Juggler228_6, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_49
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_14::
	call_if_eq 0x700D, 1, Route35_EventScript_Juggler228_50
	msgbox Route35_Text_Juggler228_6, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_50
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_15::
	call_if_eq 0x700D, 1, Route35_EventScript_Juggler228_51
	msgbox Route35_Text_Juggler228_6, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_51
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_16::
	call_if_eq 0x700D, 1, Route35_EventScript_Juggler228_52
	msgbox Route35_Text_Juggler228_6, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_52
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_17::
	call_if_eq 0x7000, 1, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 1, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 1, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 1, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 1, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 1, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 1, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 1, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_18::
	call_if_eq 0x7000, 2, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 2, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 2, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 2, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 2, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 2, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 2, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 2, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_19::
	call_if_eq 0x7000, 3, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 3, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 3, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 3, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 3, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 3, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 3, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 3, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_20::
	call_if_eq 0x7000, 4, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 4, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 4, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 4, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 4, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 4, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 4, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 4, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_21::
	call_if_eq 0x7000, 5, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 5, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 5, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 5, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 5, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 5, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 5, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 5, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_22::
	call_if_eq 0x7000, 6, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 6, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 6, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 6, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 6, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 6, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 6, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 6, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_23::
	call_if_eq 0x7000, 7, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 7, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 7, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 7, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 7, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 7, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 7, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 7, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_24::
	call_if_eq 0x7000, 8, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 8, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 8, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 8, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 8, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 8, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 8, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 8, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_25::
	call_if_eq 0x7000, 9, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 9, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 9, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 9, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 9, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 9, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 9, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 9, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_26::
	call_if_eq 0x7000, 16, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 16, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 16, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 16, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 16, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 16, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 16, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 16, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_27::
	call_if_eq 0x7000, 17, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 17, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 17, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 17, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 17, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 17, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 17, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 17, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_28::
	call_if_eq 0x7000, 18, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 18, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 18, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 18, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 18, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 18, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 18, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 18, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_29::
	call_if_eq 0x7000, 19, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 19, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 19, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 19, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 19, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 19, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 19, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 19, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_30::
	call_if_eq 0x7000, 20, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 20, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 20, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 20, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 20, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 20, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 20, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 20, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_31::
	call_if_eq 0x7000, 21, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 21, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 21, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 21, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 21, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 21, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 21, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 21, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_32::
	call_if_eq 0x7000, 22, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 22, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 22, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 22, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 22, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 22, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 22, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 22, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_33::
	call_if_eq 0x7000, 23, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 23, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 23, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 23, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 23, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 23, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 23, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 23, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_34::
	call_if_eq 0x7000, 24, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 24, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 24, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 24, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 24, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 24, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 24, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 24, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_35::
	call_if_eq 0x7000, 25, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 25, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 25, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 25, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 25, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 25, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 25, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 25, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_36::
	call_if_eq 0x7000, 32, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 32, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 32, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 32, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 32, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 32, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 32, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 32, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_37::
	call_if_eq 0x7000, 33, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 33, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 33, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 33, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 33, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 33, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 33, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 33, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_38::
	call_if_eq 0x7000, 34, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 34, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 34, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 34, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 34, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 34, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 34, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 34, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_39::
	call_if_eq 0x7000, 35, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 35, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 35, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 35, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 35, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 35, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 35, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 35, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_40::
	call_if_eq 0x7000, 36, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 36, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 36, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 36, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 36, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 36, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 36, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 36, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_41::
	call_if_eq 0x7000, 37, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 37, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 37, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 37, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 37, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 37, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 37, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 37, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_42::
	call_if_eq 0x7000, 38, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 38, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 38, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 38, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 38, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 38, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 38, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 38, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_43::
	call_if_eq 0x7000, 39, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 39, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 39, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 39, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 39, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 39, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 39, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 39, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_44::
	call_if_eq 0x7000, 40, Route35_EventScript_Juggler228_53
	call_if_eq 0x7001, 40, Route35_EventScript_Juggler228_54
	call_if_eq 0x7002, 40, Route35_EventScript_Juggler228_55
	call_if_eq 0x7003, 40, Route35_EventScript_Juggler228_56
	call_if_eq 0x7004, 40, Route35_EventScript_Juggler228_57
	call_if_eq 0x7005, 40, Route35_EventScript_Juggler228_58
	call_if_eq 0x7006, 40, Route35_EventScript_Juggler228_59
	call_if_eq 0x7007, 40, Route35_EventScript_Juggler228_60
	return

Route35_EventScript_Juggler228_45::
	playfanfare MUS_MOVE_DELETED
	msgbox Route35_Text_Juggler228_7
	waitfanfare
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	copyvar 0x7000, 0x700C
	release
	end

Route35_EventScript_Juggler228_46::
	playfanfare MUS_MOVE_DELETED
	msgbox Route35_Text_Juggler228_7
	waitfanfare
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	copyvar 0x7001, 0x700C
	release
	end

Route35_EventScript_Juggler228_47::
	playfanfare MUS_MOVE_DELETED
	msgbox Route35_Text_Juggler228_7
	waitfanfare
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	copyvar 0x7002, 0x700C
	release
	end

Route35_EventScript_Juggler228_48::
	playfanfare MUS_MOVE_DELETED
	msgbox Route35_Text_Juggler228_7
	waitfanfare
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	copyvar 0x7003, 0x700C
	release
	end

Route35_EventScript_Juggler228_49::
	playfanfare MUS_MOVE_DELETED
	msgbox Route35_Text_Juggler228_7
	waitfanfare
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	copyvar 0x7004, 0x700C
	release
	end

Route35_EventScript_Juggler228_50::
	playfanfare MUS_MOVE_DELETED
	msgbox Route35_Text_Juggler228_7
	waitfanfare
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	copyvar 0x7005, 0x700C
	release
	end

Route35_EventScript_Juggler228_51::
	playfanfare MUS_MOVE_DELETED
	msgbox Route35_Text_Juggler228_7
	waitfanfare
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	copyvar 0x7006, 0x700C
	release
	end

Route35_EventScript_Juggler228_52::
	playfanfare MUS_MOVE_DELETED
	msgbox Route35_Text_Juggler228_7
	waitfanfare
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	copyvar 0x7007, 0x700C
	release
	end

Route35_EventScript_Juggler228_53::
	msgbox Route35_Text_Juggler228_9, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_61
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_54::
	msgbox Route35_Text_Juggler228_9, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_62
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_55::
	msgbox Route35_Text_Juggler228_9, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_63
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_56::
	msgbox Route35_Text_Juggler228_9, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_64
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_57::
	msgbox Route35_Text_Juggler228_9, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_65
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_58::
	msgbox Route35_Text_Juggler228_9, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_66
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_59::
	msgbox Route35_Text_Juggler228_9, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_67
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_60::
	msgbox Route35_Text_Juggler228_9, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Juggler228_68
	msgbox Route35_Text_Juggler228_8, MSGBOX_NPC
	end

Route35_EventScript_Juggler228_61::
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	setvar 0x7000, 0
	release
	end

Route35_EventScript_Juggler228_62::
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	setvar 0x7001, 0
	release
	end

Route35_EventScript_Juggler228_63::
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	setvar 0x7002, 0
	release
	end

Route35_EventScript_Juggler228_64::
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	setvar 0x7003, 0
	release
	end

Route35_EventScript_Juggler228_65::
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	setvar 0x7004, 0
	release
	end

Route35_EventScript_Juggler228_66::
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	setvar 0x7005, 0
	release
	end

Route35_EventScript_Juggler228_67::
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	setvar 0x7006, 0
	release
	end

Route35_EventScript_Juggler228_68::
	msgbox Route35_Text_Juggler228_5, MSGBOX_NPC
	setvar 0x7007, 0
	release
	end

Route35_EventScript_OfficerDirk::
	trainerbattle_single TRAINER_OFFICER_DIRK, Route35_Text_OfficerDirkIntro, Route35_Text_OfficerDirkDefeat
	msgbox Route35_Text_OfficerDirk, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BugCatcher95::
	trainerbattle_single TRAINER_BUG_CATCHER_ARNIE, Route35_Text_BugCatcher95Intro, Route35_Text_BugCatcher95Defeat
	call_if_set 0x1309, Route35_EventScript_BugCatcher95_1
	setvar 0x700C, 9
	setvar 0x700D, 0
	call_if_set 0x1339, Route35_EventScript_Juggler228_2
	msgbox Route35_Text_BugCatcher95, MSGBOX_NPC
	setflag 0x1339
	call Route35_EventScript_Juggler228_3
	end

Route35_EventScript_BugCatcher95_1::
	clearflag 0x1309
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x8888, Route35_EventScript_BugCatcher95_2
	call_if_set 0x115F, Route35_EventScript_BugCatcher95_3
	call_if_set FLAG_BADGE07_GET, Route35_EventScript_BugCatcher95_4
	call_if_set FLAG_BADGE05_GET, Route35_EventScript_BugCatcher95_5
	trainerbattle_earlyrival TRAINER_BUG_CATCHER_ARNIE, 0, Route35_Text_BugCatcher95Defeat, Route35_Text_Juggler228Victory
	release
	end

Route35_EventScript_BugCatcher95_2::
	trainerbattle_earlyrival TRAINER_BUG_CATCHER_ARNIE_5, 0, Route35_Text_BugCatcher95Defeat, Route35_Text_Juggler228Victory
	release
	end

Route35_EventScript_BugCatcher95_3::
	trainerbattle_earlyrival TRAINER_BUG_CATCHER_ARNIE_4, 0, Route35_Text_BugCatcher95Defeat, Route35_Text_Juggler228Victory
	release
	end

Route35_EventScript_BugCatcher95_4::
	trainerbattle_earlyrival TRAINER_BUG_CATCHER_ARNIE_3, 0, Route35_Text_BugCatcher95Defeat, Route35_Text_Juggler228Victory
	release
	end

Route35_EventScript_BugCatcher95_5::
	trainerbattle_earlyrival TRAINER_BUG_CATCHER_ARNIE_2, 0, Route35_Text_BugCatcher95Defeat, Route35_Text_Juggler228Victory
	release
	end

Route35_EventScript_BirdKeeperBryan::
	trainerbattle_single TRAINER_BIRD_KEEPER_BRYAN, Route35_Text_BirdKeeperBryanIntro, Route35_Text_BirdKeeperBryanDefeat
	msgbox Route35_Text_BirdKeeperBryan, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_ItemTm04::
	finditem ITEM_TM04
	end

Route35_EventScript_Sign1::
	msgbox Route35_Text_Sign1, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Sign3::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox Route35_Text_Sign3, MSGBOX_NPC
	giveitem ITEM_LEPPA_BERRY
	releaseall
	special DaisyMassageServices
	end

Route35_EventScript_Sign4::
	call_if_unset 0x1027, Route35_EventScript_Sign4_1
	setvar 0x700B, 0
	call_if_eq VAR_FACING, 2, Route35_EventScript_Sign4_2
	release
	end

Route35_EventScript_Sign4_1::
	setvar 0x700B, 7
	call_if_eq VAR_FACING, 2, Route35_EventScript_Sign4_2
	release
	end

Route35_EventScript_Sign4_2::
	msgbox Route35_Text_Sign4_1
	multichoice 0, 0, MULTICHOICE_TRAINER_CARD_ICON_TINT, 0
	copyvar VAR_0x8009, VAR_RESULT
	switch VAR_RESULT
	call_if_eq VAR_0x8000, 0, Route35_EventScript_Sign4_3
	call_if_eq VAR_0x8000, 1, Route35_EventScript_Sign4_4
	call_if_eq VAR_0x8000, 2, Route35_EventScript_Sign4_5
	call_if_eq VAR_0x8000, 3, Route35_EventScript_Sign4_6
	call_if_eq VAR_0x8000, 127, Route35_EventScript_Sign4_6
	end

Route35_EventScript_Sign4_3::
	call Route35_EventScript_Sign4_7
	msgbox Route35_Text_Sign4_2, MSGBOX_NPC
	call_if_eq 0x700B, 0, Route35_EventScript_Sign4_8
	call_if_eq 0x700B, 1, Route35_EventScript_Sign4_9
	call_if_eq 0x700B, 2, Route35_EventScript_Sign4_10
	call_if_eq 0x700B, 3, Route35_EventScript_Sign4_11
	call_if_eq 0x700B, 4, Route35_EventScript_Sign4_12
	call_if_eq 0x700B, 5, Route35_EventScript_Sign4_13
	call_if_eq 0x700B, 6, Route35_EventScript_Sign4_14
	call_if_eq 0x700B, 7, Route35_EventScript_Sign4_15
	end

Route35_EventScript_Sign4_4::
	call Route35_EventScript_Sign4_7
	msgbox Route35_Text_Sign4_3, MSGBOX_NPC
	call_if_set 0x1151, Route35_EventScript_Sign4_16
	call_if_set 0x1046, Route35_EventScript_Sign4_16
	setvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 175
	copyvar VAR_0x8004, VAR_RESORT_GORGEOUS_REQUESTED_MON
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	call_if_eq VAR_RESULT, 1, Route35_EventScript_Sign4_19
	call_if_set 0x1203, Route35_EventScript_Sign4_20
	call_if_set FLAG_BADGE02_GET, Route35_EventScript_Sign4_16
	call_if_set FLAG_BADGE01_GET, Route35_EventScript_Sign4_21
	call_if_set 0x1025, Route35_EventScript_Sign4_22
	call_if_set 0x1015, Route35_EventScript_Sign4_23
	msgbox Route35_Text_Sign4_4, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_5::
	msgbox Route35_Text_Sign4_1
	multichoice 0, 0, MULTICHOICE_EEVEELUTIONS, 0
	copyvar VAR_0x8009, VAR_RESULT
	switch VAR_RESULT
	call_if_eq VAR_0x8000, 0, Route35_EventScript_Sign4_25
	call_if_eq VAR_0x8000, 1, Route35_EventScript_Sign4_26
	call_if_eq VAR_0x8000, 2, Route35_EventScript_Sign4_27
	call_if_eq VAR_0x8000, 3, Route35_EventScript_Sign4_28
	call_if_eq VAR_0x8000, 4, Route35_EventScript_Sign4_29
	call_if_eq VAR_0x8000, 127, Route35_EventScript_Sign4_6
	end

Route35_EventScript_Sign4_6::
	release
	end

Route35_EventScript_Sign4_7::
	playbgm SE_POKENAV_ON, 51
	msgbox Route35_Text_Sign4_5, MSGBOX_NPC
	return

Route35_EventScript_Sign4_8::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_30
	call_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_31
	call_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_32
	call_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_33
	end

Route35_EventScript_Sign4_9::
	msgbox Route35_Text_Sign4_6, MSGBOX_NPC
	msgbox Route35_Text_Sign4_7, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_10::
	msgbox Route35_Text_Sign4_8, MSGBOX_NPC
	msgbox Route35_Text_Sign4_7, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_11::
	msgbox Route35_Text_Sign4_9, MSGBOX_NPC
	msgbox Route35_Text_Sign4_7, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_12::
	msgbox Route35_Text_Sign4_10, MSGBOX_NPC
	msgbox Route35_Text_Sign4_7, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_13::
	msgbox Route35_Text_Sign4_11, MSGBOX_NPC
	msgbox Route35_Text_Sign4_7, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_14::
	msgbox Route35_Text_Sign4_12, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_15::
	msgbox Route35_Text_Sign4_13, MSGBOX_NPC
	msgbox Route35_Text_Sign4_7, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_16::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_lt VAR_0x8008, 2, Route35_EventScript_Sign4_34
	goto_if_gt VAR_0x8008, 1, Route35_EventScript_Sign4_35
	end

Route35_EventScript_Sign4_19::
	msgbox Route35_Text_Sign4_15, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_20::
	msgbox Route35_Text_Sign4_16, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_21::
	msgbox Route35_Text_Sign4_17, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_22::
	msgbox Route35_Text_Sign4_18, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_23::
	msgbox Route35_Text_Sign4_19, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_24::
	setvar VAR_0x8000, 127
	playbgm SE_POKENAV_OFF, 51
	msgbox Route35_Text_Sign4_20, MSGBOX_NPC
	release
	end

Route35_EventScript_Sign4_25::
	call_if_eq 0x7000, 1, Route35_EventScript_Sign4_37
	call_if_eq 0x7000, 2, Route35_EventScript_Sign4_38
	call_if_eq 0x7000, 3, Route35_EventScript_Sign4_39
	call_if_eq 0x7000, 4, Route35_EventScript_Sign4_40
	call_if_eq 0x7000, 5, Route35_EventScript_Sign4_41
	call_if_eq 0x7000, 6, Route35_EventScript_Sign4_42
	call_if_eq 0x7000, 7, Route35_EventScript_Sign4_43
	call_if_eq 0x7000, 8, Route35_EventScript_Sign4_44
	call_if_eq 0x7000, 9, Route35_EventScript_Sign4_45
	call_if_eq 0x7000, 16, Route35_EventScript_Sign4_46
	call_if_eq 0x7000, 17, Route35_EventScript_Sign4_47
	call_if_eq 0x7000, 18, Route35_EventScript_Sign4_48
	call_if_eq 0x7000, 19, Route35_EventScript_Sign4_49
	call_if_eq 0x7000, 20, Route35_EventScript_Sign4_50
	call_if_eq 0x7000, 21, Route35_EventScript_Sign4_51
	call_if_eq 0x7000, 22, Route35_EventScript_Sign4_52
	call_if_eq 0x7000, 23, Route35_EventScript_Sign4_53
	call_if_eq 0x7000, 24, Route35_EventScript_Sign4_54
	call_if_eq 0x7000, 25, Route35_EventScript_Sign4_55
	call_if_eq 0x7000, 32, Route35_EventScript_Sign4_56
	call_if_eq 0x7000, 33, Route35_EventScript_Sign4_57
	call_if_eq 0x7000, 34, Route35_EventScript_Sign4_58
	call_if_eq 0x7000, 35, Route35_EventScript_Sign4_59
	call_if_eq 0x7000, 36, Route35_EventScript_Sign4_60
	call_if_eq 0x7000, 37, Route35_EventScript_Sign4_61
	call_if_eq 0x7000, 38, Route35_EventScript_Sign4_62
	call_if_eq 0x7000, 39, Route35_EventScript_Sign4_63
	call_if_eq 0x7000, 40, Route35_EventScript_Sign4_64
	msgbox Route35_Text_Sign4_21, MSGBOX_NPC
	call Route35_EventScript_Sign4_5
	end

Route35_EventScript_Sign4_26::
	call_if_eq 0x7001, 1, Route35_EventScript_Sign4_37
	call_if_eq 0x7001, 2, Route35_EventScript_Sign4_38
	call_if_eq 0x7001, 3, Route35_EventScript_Sign4_39
	call_if_eq 0x7001, 4, Route35_EventScript_Sign4_40
	call_if_eq 0x7001, 5, Route35_EventScript_Sign4_41
	call_if_eq 0x7001, 6, Route35_EventScript_Sign4_42
	call_if_eq 0x7001, 7, Route35_EventScript_Sign4_43
	call_if_eq 0x7001, 8, Route35_EventScript_Sign4_44
	call_if_eq 0x7001, 9, Route35_EventScript_Sign4_45
	call_if_eq 0x7001, 16, Route35_EventScript_Sign4_46
	call_if_eq 0x7001, 17, Route35_EventScript_Sign4_47
	call_if_eq 0x7001, 18, Route35_EventScript_Sign4_48
	call_if_eq 0x7001, 19, Route35_EventScript_Sign4_49
	call_if_eq 0x7001, 20, Route35_EventScript_Sign4_50
	call_if_eq 0x7001, 21, Route35_EventScript_Sign4_51
	call_if_eq 0x7001, 22, Route35_EventScript_Sign4_52
	call_if_eq 0x7001, 23, Route35_EventScript_Sign4_53
	call_if_eq 0x7001, 24, Route35_EventScript_Sign4_54
	call_if_eq 0x7001, 25, Route35_EventScript_Sign4_55
	call_if_eq 0x7001, 32, Route35_EventScript_Sign4_56
	call_if_eq 0x7001, 33, Route35_EventScript_Sign4_57
	call_if_eq 0x7001, 34, Route35_EventScript_Sign4_58
	call_if_eq 0x7001, 35, Route35_EventScript_Sign4_59
	call_if_eq 0x7001, 36, Route35_EventScript_Sign4_60
	call_if_eq 0x7001, 37, Route35_EventScript_Sign4_61
	call_if_eq 0x7001, 38, Route35_EventScript_Sign4_62
	call_if_eq 0x7001, 39, Route35_EventScript_Sign4_63
	call_if_eq 0x7001, 40, Route35_EventScript_Sign4_64
	msgbox Route35_Text_Sign4_21, MSGBOX_NPC
	call Route35_EventScript_Sign4_5
	end

Route35_EventScript_Sign4_27::
	call_if_eq 0x7002, 1, Route35_EventScript_Sign4_37
	call_if_eq 0x7002, 2, Route35_EventScript_Sign4_38
	call_if_eq 0x7002, 3, Route35_EventScript_Sign4_39
	call_if_eq 0x7002, 4, Route35_EventScript_Sign4_40
	call_if_eq 0x7002, 5, Route35_EventScript_Sign4_41
	call_if_eq 0x7002, 6, Route35_EventScript_Sign4_42
	call_if_eq 0x7002, 7, Route35_EventScript_Sign4_43
	call_if_eq 0x7002, 8, Route35_EventScript_Sign4_44
	call_if_eq 0x7002, 9, Route35_EventScript_Sign4_45
	call_if_eq 0x7002, 16, Route35_EventScript_Sign4_46
	call_if_eq 0x7002, 17, Route35_EventScript_Sign4_47
	call_if_eq 0x7002, 18, Route35_EventScript_Sign4_48
	call_if_eq 0x7002, 19, Route35_EventScript_Sign4_49
	call_if_eq 0x7002, 20, Route35_EventScript_Sign4_50
	call_if_eq 0x7002, 21, Route35_EventScript_Sign4_51
	call_if_eq 0x7002, 22, Route35_EventScript_Sign4_52
	call_if_eq 0x7002, 23, Route35_EventScript_Sign4_53
	call_if_eq 0x7002, 24, Route35_EventScript_Sign4_54
	call_if_eq 0x7002, 25, Route35_EventScript_Sign4_55
	call_if_eq 0x7002, 32, Route35_EventScript_Sign4_56
	call_if_eq 0x7002, 33, Route35_EventScript_Sign4_57
	call_if_eq 0x7002, 34, Route35_EventScript_Sign4_58
	call_if_eq 0x7002, 35, Route35_EventScript_Sign4_59
	call_if_eq 0x7002, 36, Route35_EventScript_Sign4_60
	call_if_eq 0x7002, 37, Route35_EventScript_Sign4_61
	call_if_eq 0x7002, 38, Route35_EventScript_Sign4_62
	call_if_eq 0x7002, 39, Route35_EventScript_Sign4_63
	call_if_eq 0x7002, 40, Route35_EventScript_Sign4_64
	msgbox Route35_Text_Sign4_21, MSGBOX_NPC
	call Route35_EventScript_Sign4_5
	end

Route35_EventScript_Sign4_28::
	call_if_eq 0x7003, 1, Route35_EventScript_Sign4_37
	call_if_eq 0x7003, 2, Route35_EventScript_Sign4_38
	call_if_eq 0x7003, 3, Route35_EventScript_Sign4_39
	call_if_eq 0x7003, 4, Route35_EventScript_Sign4_40
	call_if_eq 0x7003, 5, Route35_EventScript_Sign4_41
	call_if_eq 0x7003, 6, Route35_EventScript_Sign4_42
	call_if_eq 0x7003, 7, Route35_EventScript_Sign4_43
	call_if_eq 0x7003, 8, Route35_EventScript_Sign4_44
	call_if_eq 0x7003, 9, Route35_EventScript_Sign4_45
	call_if_eq 0x7003, 16, Route35_EventScript_Sign4_46
	call_if_eq 0x7003, 17, Route35_EventScript_Sign4_47
	call_if_eq 0x7003, 18, Route35_EventScript_Sign4_48
	call_if_eq 0x7003, 19, Route35_EventScript_Sign4_49
	call_if_eq 0x7003, 20, Route35_EventScript_Sign4_50
	call_if_eq 0x7003, 21, Route35_EventScript_Sign4_51
	call_if_eq 0x7003, 22, Route35_EventScript_Sign4_52
	call_if_eq 0x7003, 23, Route35_EventScript_Sign4_53
	call_if_eq 0x7003, 24, Route35_EventScript_Sign4_54
	call_if_eq 0x7003, 25, Route35_EventScript_Sign4_55
	call_if_eq 0x7003, 32, Route35_EventScript_Sign4_56
	call_if_eq 0x7003, 33, Route35_EventScript_Sign4_57
	call_if_eq 0x7003, 34, Route35_EventScript_Sign4_58
	call_if_eq 0x7003, 35, Route35_EventScript_Sign4_59
	call_if_eq 0x7003, 36, Route35_EventScript_Sign4_60
	call_if_eq 0x7003, 37, Route35_EventScript_Sign4_61
	call_if_eq 0x7003, 38, Route35_EventScript_Sign4_62
	call_if_eq 0x7003, 39, Route35_EventScript_Sign4_63
	call_if_eq 0x7003, 40, Route35_EventScript_Sign4_64
	msgbox Route35_Text_Sign4_21, MSGBOX_NPC
	call Route35_EventScript_Sign4_5
	end

Route35_EventScript_Sign4_29::
	msgbox Route35_Text_Sign4_1
	multichoice 0, 0, MULTICHOICE_TRAINER_TOWER_MODE, 0
	copyvar VAR_0x8009, VAR_RESULT
	switch VAR_RESULT
	call_if_eq VAR_0x8000, 0, Route35_EventScript_Sign4_65
	call_if_eq VAR_0x8000, 1, Route35_EventScript_Sign4_66
	call_if_eq VAR_0x8000, 2, Route35_EventScript_Sign4_67
	call_if_eq VAR_0x8000, 3, Route35_EventScript_Sign4_68
	call_if_eq VAR_0x8000, 4, Route35_EventScript_Sign4_6
	call_if_eq VAR_0x8000, 127, Route35_EventScript_Sign4_6
	end

Route35_EventScript_Sign4_30::
	msgbox Route35_Text_Sign4_22, MSGBOX_NPC
	msgbox Route35_Text_Sign4_7, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_31::
	msgbox Route35_Text_Sign4_23, MSGBOX_NPC
	msgbox Route35_Text_Sign4_7, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_32::
	msgbox Route35_Text_Sign4_24, MSGBOX_NPC
	msgbox Route35_Text_Sign4_7, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_33::
	msgbox Route35_Text_Sign4_25, MSGBOX_NPC
	msgbox Route35_Text_Sign4_7, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_34::
	msgbox Route35_Text_Sign4_26, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_35::
	msgbox Route35_Text_Sign4_27, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_37::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 1
	msgbox Route35_Text_Sign4_29
	call_if_set 0x1301, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_38::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 2
	msgbox Route35_Text_Sign4_30, MSGBOX_NPC
	call_if_set 0x1302, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_39::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 3
	msgbox Route35_Text_Sign4_31, MSGBOX_NPC
	call_if_set 0x1303, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_40::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 4
	msgbox Route35_Text_Sign4_32, MSGBOX_NPC
	call_if_set 0x1304, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_41::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 5
	msgbox Route35_Text_Sign4_33, MSGBOX_NPC
	call_if_set 0x1305, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_42::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 6
	msgbox Route35_Text_Sign4_34, MSGBOX_NPC
	call_if_set 0x1306, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_43::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 7
	msgbox Route35_Text_Sign4_35, MSGBOX_NPC
	call_if_set 0x1307, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_44::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 8
	msgbox Route35_Text_Sign4_36, MSGBOX_NPC
	call_if_set 0x1308, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_45::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 9
	msgbox Route35_Text_Sign4_37, MSGBOX_NPC
	call_if_set 0x1309, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_46::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 16
	msgbox Route35_Text_Sign4_38, MSGBOX_NPC
	call_if_set 0x1310, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_47::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 17
	msgbox Route35_Text_Sign4_39, MSGBOX_NPC
	call_if_set 0x1311, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_48::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 18
	msgbox Route35_Text_Sign4_40, MSGBOX_NPC
	call_if_set 0x1312, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_49::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 19
	msgbox Route35_Text_Sign4_41, MSGBOX_NPC
	call_if_set 0x1313, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_50::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 20
	msgbox Route35_Text_Sign4_42, MSGBOX_NPC
	call_if_set 0x1314, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_51::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 21
	msgbox Route35_Text_Sign4_43, MSGBOX_NPC
	call_if_set 0x1315, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_52::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 22
	msgbox Route35_Text_Sign4_44, MSGBOX_NPC
	call_if_set 0x1316, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_53::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 23
	msgbox Route35_Text_Sign4_45, MSGBOX_NPC
	call_if_set 0x1317, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_54::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 24
	msgbox Route35_Text_Sign4_46, MSGBOX_NPC
	call_if_set 0x1318, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_55::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 25
	msgbox Route35_Text_Sign4_47, MSGBOX_NPC
	call_if_set 0x1319, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_56::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 32
	msgbox Route35_Text_Sign4_48, MSGBOX_NPC
	call_if_set 0x1320, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_57::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 33
	msgbox Route35_Text_Sign4_49, MSGBOX_NPC
	call_if_set 0x1321, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_58::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 34
	msgbox Route35_Text_Sign4_50, MSGBOX_NPC
	call_if_set 0x1322, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_59::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 35
	msgbox Route35_Text_Sign4_51, MSGBOX_NPC
	call_if_set 0x1323, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_60::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 36
	msgbox Route35_Text_Sign4_52, MSGBOX_NPC
	call_if_set 0x1324, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_61::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 37
	msgbox Route35_Text_Sign4_53, MSGBOX_NPC
	call_if_set 0x1325, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_62::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 38
	msgbox Route35_Text_Sign4_54, MSGBOX_NPC
	call_if_set 0x1326, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_63::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 39
	msgbox Route35_Text_Sign4_55, MSGBOX_NPC
	call_if_set 0x1327, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_64::
	call Route35_EventScript_Sign4_7
	setvar 0x7008, 40
	msgbox Route35_Text_Sign4_56, MSGBOX_NPC
	call_if_set 0x1328, Route35_EventScript_Sign4_69
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route35_EventScript_Sign4_70
	call Route35_EventScript_Sign4_71
	end

Route35_EventScript_Sign4_65::
	call_if_eq 0x7004, 1, Route35_EventScript_Sign4_37
	call_if_eq 0x7004, 2, Route35_EventScript_Sign4_38
	call_if_eq 0x7004, 3, Route35_EventScript_Sign4_39
	call_if_eq 0x7004, 4, Route35_EventScript_Sign4_40
	call_if_eq 0x7004, 5, Route35_EventScript_Sign4_41
	call_if_eq 0x7004, 6, Route35_EventScript_Sign4_42
	call_if_eq 0x7004, 7, Route35_EventScript_Sign4_43
	call_if_eq 0x7004, 8, Route35_EventScript_Sign4_44
	call_if_eq 0x7004, 9, Route35_EventScript_Sign4_45
	call_if_eq 0x7004, 16, Route35_EventScript_Sign4_46
	call_if_eq 0x7004, 17, Route35_EventScript_Sign4_47
	call_if_eq 0x7004, 18, Route35_EventScript_Sign4_48
	call_if_eq 0x7004, 19, Route35_EventScript_Sign4_49
	call_if_eq 0x7004, 20, Route35_EventScript_Sign4_50
	call_if_eq 0x7004, 21, Route35_EventScript_Sign4_51
	call_if_eq 0x7004, 22, Route35_EventScript_Sign4_52
	call_if_eq 0x7004, 23, Route35_EventScript_Sign4_53
	call_if_eq 0x7004, 24, Route35_EventScript_Sign4_54
	call_if_eq 0x7004, 25, Route35_EventScript_Sign4_55
	call_if_eq 0x7004, 32, Route35_EventScript_Sign4_56
	call_if_eq 0x7004, 33, Route35_EventScript_Sign4_57
	call_if_eq 0x7004, 34, Route35_EventScript_Sign4_58
	call_if_eq 0x7004, 35, Route35_EventScript_Sign4_59
	call_if_eq 0x7004, 36, Route35_EventScript_Sign4_60
	call_if_eq 0x7004, 37, Route35_EventScript_Sign4_61
	call_if_eq 0x7004, 38, Route35_EventScript_Sign4_62
	call_if_eq 0x7004, 39, Route35_EventScript_Sign4_63
	call_if_eq 0x7004, 40, Route35_EventScript_Sign4_64
	msgbox Route35_Text_Sign4_21, MSGBOX_NPC
	call Route35_EventScript_Sign4_29
	end

Route35_EventScript_Sign4_66::
	call_if_eq 0x7005, 1, Route35_EventScript_Sign4_37
	call_if_eq 0x7005, 2, Route35_EventScript_Sign4_38
	call_if_eq 0x7005, 3, Route35_EventScript_Sign4_39
	call_if_eq 0x7005, 4, Route35_EventScript_Sign4_40
	call_if_eq 0x7005, 5, Route35_EventScript_Sign4_41
	call_if_eq 0x7005, 6, Route35_EventScript_Sign4_42
	call_if_eq 0x7005, 7, Route35_EventScript_Sign4_43
	call_if_eq 0x7005, 8, Route35_EventScript_Sign4_44
	call_if_eq 0x7005, 9, Route35_EventScript_Sign4_45
	call_if_eq 0x7005, 16, Route35_EventScript_Sign4_46
	call_if_eq 0x7005, 17, Route35_EventScript_Sign4_47
	call_if_eq 0x7005, 18, Route35_EventScript_Sign4_48
	call_if_eq 0x7005, 19, Route35_EventScript_Sign4_49
	call_if_eq 0x7005, 20, Route35_EventScript_Sign4_50
	call_if_eq 0x7005, 21, Route35_EventScript_Sign4_51
	call_if_eq 0x7005, 22, Route35_EventScript_Sign4_52
	call_if_eq 0x7005, 23, Route35_EventScript_Sign4_53
	call_if_eq 0x7005, 24, Route35_EventScript_Sign4_54
	call_if_eq 0x7005, 25, Route35_EventScript_Sign4_55
	call_if_eq 0x7005, 32, Route35_EventScript_Sign4_56
	call_if_eq 0x7005, 33, Route35_EventScript_Sign4_57
	call_if_eq 0x7005, 34, Route35_EventScript_Sign4_58
	call_if_eq 0x7005, 35, Route35_EventScript_Sign4_59
	call_if_eq 0x7005, 36, Route35_EventScript_Sign4_60
	call_if_eq 0x7005, 37, Route35_EventScript_Sign4_61
	call_if_eq 0x7005, 38, Route35_EventScript_Sign4_62
	call_if_eq 0x7005, 39, Route35_EventScript_Sign4_63
	call_if_eq 0x7005, 40, Route35_EventScript_Sign4_64
	msgbox Route35_Text_Sign4_21, MSGBOX_NPC
	call Route35_EventScript_Sign4_29
	end

Route35_EventScript_Sign4_67::
	call_if_eq 0x7006, 1, Route35_EventScript_Sign4_37
	call_if_eq 0x7006, 2, Route35_EventScript_Sign4_38
	call_if_eq 0x7006, 3, Route35_EventScript_Sign4_39
	call_if_eq 0x7006, 4, Route35_EventScript_Sign4_40
	call_if_eq 0x7006, 5, Route35_EventScript_Sign4_41
	call_if_eq 0x7006, 6, Route35_EventScript_Sign4_42
	call_if_eq 0x7006, 7, Route35_EventScript_Sign4_43
	call_if_eq 0x7006, 8, Route35_EventScript_Sign4_44
	call_if_eq 0x7006, 9, Route35_EventScript_Sign4_45
	call_if_eq 0x7006, 16, Route35_EventScript_Sign4_46
	call_if_eq 0x7006, 17, Route35_EventScript_Sign4_47
	call_if_eq 0x7006, 18, Route35_EventScript_Sign4_48
	call_if_eq 0x7006, 19, Route35_EventScript_Sign4_49
	call_if_eq 0x7006, 20, Route35_EventScript_Sign4_50
	call_if_eq 0x7006, 21, Route35_EventScript_Sign4_51
	call_if_eq 0x7006, 22, Route35_EventScript_Sign4_52
	call_if_eq 0x7006, 23, Route35_EventScript_Sign4_53
	call_if_eq 0x7006, 24, Route35_EventScript_Sign4_54
	call_if_eq 0x7006, 25, Route35_EventScript_Sign4_55
	call_if_eq 0x7006, 32, Route35_EventScript_Sign4_56
	call_if_eq 0x7006, 33, Route35_EventScript_Sign4_57
	call_if_eq 0x7006, 34, Route35_EventScript_Sign4_58
	call_if_eq 0x7006, 35, Route35_EventScript_Sign4_59
	call_if_eq 0x7006, 36, Route35_EventScript_Sign4_60
	call_if_eq 0x7006, 37, Route35_EventScript_Sign4_61
	call_if_eq 0x7006, 38, Route35_EventScript_Sign4_62
	call_if_eq 0x7006, 39, Route35_EventScript_Sign4_63
	call_if_eq 0x7006, 40, Route35_EventScript_Sign4_64
	msgbox Route35_Text_Sign4_21, MSGBOX_NPC
	call Route35_EventScript_Sign4_29
	end

Route35_EventScript_Sign4_68::
	call_if_eq 0x7007, 1, Route35_EventScript_Sign4_37
	call_if_eq 0x7007, 2, Route35_EventScript_Sign4_38
	call_if_eq 0x7007, 3, Route35_EventScript_Sign4_39
	call_if_eq 0x7007, 4, Route35_EventScript_Sign4_40
	call_if_eq 0x7007, 5, Route35_EventScript_Sign4_41
	call_if_eq 0x7007, 6, Route35_EventScript_Sign4_42
	call_if_eq 0x7007, 7, Route35_EventScript_Sign4_43
	call_if_eq 0x7007, 8, Route35_EventScript_Sign4_44
	call_if_eq 0x7007, 9, Route35_EventScript_Sign4_45
	call_if_eq 0x7007, 16, Route35_EventScript_Sign4_46
	call_if_eq 0x7007, 17, Route35_EventScript_Sign4_47
	call_if_eq 0x7007, 18, Route35_EventScript_Sign4_48
	call_if_eq 0x7007, 19, Route35_EventScript_Sign4_49
	call_if_eq 0x7007, 20, Route35_EventScript_Sign4_50
	call_if_eq 0x7007, 21, Route35_EventScript_Sign4_51
	call_if_eq 0x7007, 22, Route35_EventScript_Sign4_52
	call_if_eq 0x7007, 23, Route35_EventScript_Sign4_53
	call_if_eq 0x7007, 24, Route35_EventScript_Sign4_54
	call_if_eq 0x7007, 25, Route35_EventScript_Sign4_55
	call_if_eq 0x7007, 32, Route35_EventScript_Sign4_56
	call_if_eq 0x7007, 33, Route35_EventScript_Sign4_57
	call_if_eq 0x7007, 34, Route35_EventScript_Sign4_58
	call_if_eq 0x7007, 35, Route35_EventScript_Sign4_59
	call_if_eq 0x7007, 36, Route35_EventScript_Sign4_60
	call_if_eq 0x7007, 37, Route35_EventScript_Sign4_61
	call_if_eq 0x7007, 38, Route35_EventScript_Sign4_62
	call_if_eq 0x7007, 39, Route35_EventScript_Sign4_63
	call_if_eq 0x7007, 40, Route35_EventScript_Sign4_64
	msgbox Route35_Text_Sign4_21, MSGBOX_NPC
	call Route35_EventScript_Sign4_29
	end

Route35_EventScript_Sign4_69::
	call_if_eq 0x7008, 1, Route35_EventScript_Sign4_72
	call_if_eq 0x7008, 2, Route35_EventScript_Sign4_73
	call_if_eq 0x7008, 3, Route35_EventScript_Sign4_74
	call_if_eq 0x7008, 4, Route35_EventScript_Sign4_75
	call_if_eq 0x7008, 5, Route35_EventScript_Sign4_76
	call_if_eq 0x7008, 6, Route35_EventScript_Sign4_77
	call_if_eq 0x7008, 7, Route35_EventScript_Sign4_78
	call_if_eq 0x7008, 8, Route35_EventScript_Sign4_79
	call_if_eq 0x7008, 9, Route35_EventScript_Sign4_80
	call_if_eq 0x7008, 16, Route35_EventScript_Sign4_81
	call_if_eq 0x7008, 17, Route35_EventScript_Sign4_82
	call_if_eq 0x7008, 18, Route35_EventScript_Sign4_83
	call_if_eq 0x7008, 19, Route35_EventScript_Sign4_84
	call_if_eq 0x7008, 20, Route35_EventScript_Sign4_85
	call_if_eq 0x7008, 21, Route35_EventScript_Sign4_86
	call_if_eq 0x7008, 22, Route35_EventScript_Sign4_87
	call_if_eq 0x7008, 23, Route35_EventScript_Sign4_88
	call_if_eq 0x7008, 24, Route35_EventScript_Sign4_89
	call_if_eq 0x7008, 25, Route35_EventScript_Sign4_90
	call_if_eq 0x7008, 32, Route35_EventScript_Sign4_91
	call_if_eq 0x7008, 33, Route35_EventScript_Sign4_92
	call_if_eq 0x7008, 34, Route35_EventScript_Sign4_93
	call_if_eq 0x7008, 35, Route35_EventScript_Sign4_94
	call_if_eq 0x7008, 36, Route35_EventScript_Sign4_95
	call_if_eq 0x7008, 37, Route35_EventScript_Sign4_96
	call_if_eq 0x7008, 38, Route35_EventScript_Sign4_97
	call_if_eq 0x7008, 39, Route35_EventScript_Sign4_98
	call_if_eq 0x7008, 40, Route35_EventScript_Sign4_99
	end

Route35_EventScript_Sign4_70::
	call_if_eq 0x7008, 1, Route35_EventScript_Sign4_100
	call_if_eq 0x7008, 2, Route35_EventScript_Sign4_101
	call_if_eq 0x7008, 3, Route35_EventScript_Sign4_102
	call_if_eq 0x7008, 4, Route35_EventScript_Sign4_103
	call_if_eq 0x7008, 5, Route35_EventScript_Sign4_104
	call_if_eq 0x7008, 6, Route35_EventScript_Sign4_105
	call_if_eq 0x7008, 7, Route35_EventScript_Sign4_106
	call_if_eq 0x7008, 8, Route35_EventScript_Sign4_107
	call_if_eq 0x7008, 9, Route35_EventScript_Sign4_108
	call_if_eq 0x7008, 16, Route35_EventScript_Sign4_109
	call_if_eq 0x7008, 17, Route35_EventScript_Sign4_110
	call_if_eq 0x7008, 18, Route35_EventScript_Sign4_111
	call_if_eq 0x7008, 19, Route35_EventScript_Sign4_112
	call_if_eq 0x7008, 20, Route35_EventScript_Sign4_113
	call_if_eq 0x7008, 21, Route35_EventScript_Sign4_114
	call_if_eq 0x7008, 22, Route35_EventScript_Sign4_115
	call_if_eq 0x7008, 23, Route35_EventScript_Sign4_116
	call_if_eq 0x7008, 24, Route35_EventScript_Sign4_117
	call_if_eq 0x7008, 25, Route35_EventScript_Sign4_118
	call_if_eq 0x7008, 32, Route35_EventScript_Sign4_119
	call_if_eq 0x7008, 33, Route35_EventScript_Sign4_120
	call_if_eq 0x7008, 34, Route35_EventScript_Sign4_121
	call_if_eq 0x7008, 35, Route35_EventScript_Sign4_122
	call_if_eq 0x7008, 36, Route35_EventScript_Sign4_123
	call_if_eq 0x7008, 37, Route35_EventScript_Sign4_124
	call_if_eq 0x7008, 38, Route35_EventScript_Sign4_125
	call_if_eq 0x7008, 39, Route35_EventScript_Sign4_126
	call_if_eq 0x7008, 40, Route35_EventScript_Sign4_127
	end

Route35_EventScript_Sign4_71::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_128
	call Route35_EventScript_Sign4_70
	end

Route35_EventScript_Sign4_72::
	msgbox Route35_Text_Sign4_57, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_73::
	msgbox Route35_Text_Sign4_58, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_74::
	msgbox Route35_Text_Sign4_59, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_75::
	msgbox Route35_Text_Sign4_59, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_76::
	msgbox Route35_Text_Sign4_60, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_77::
	msgbox Route35_Text_Sign4_61, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_78::
	msgbox Route35_Text_Sign4_61, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_79::
	msgbox Route35_Text_Sign4_62, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_80::
	msgbox Route35_Text_Sign4_62, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_81::
	msgbox Route35_Text_Sign4_63, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_82::
	msgbox Route35_Text_Sign4_63, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_83::
	msgbox Route35_Text_Sign4_64, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_84::
	msgbox Route35_Text_Sign4_65, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_85::
	msgbox Route35_Text_Sign4_65, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_86::
	msgbox Route35_Text_Sign4_66, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_87::
	msgbox Route35_Text_Sign4_67, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_88::
	msgbox Route35_Text_Sign4_68, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_89::
	msgbox Route35_Text_Sign4_69, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_90::
	msgbox Route35_Text_Sign4_70, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_91::
	msgbox Route35_Text_Sign4_70, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_92::
	msgbox Route35_Text_Sign4_71, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_93::
	msgbox Route35_Text_Sign4_71, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_94::
	msgbox Route35_Text_Sign4_72, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_95::
	msgbox Route35_Text_Sign4_72, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_96::
	msgbox Route35_Text_Sign4_73, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_97::
	msgbox Route35_Text_Sign4_74, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_98::
	msgbox Route35_Text_Sign4_73, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_99::
	msgbox Route35_Text_Sign4_74, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_100::
	call Route35_EventScript_Sign4_129
	call Route35_EventScript_Sign4_130
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_101::
	call Route35_EventScript_Sign4_132
	call Route35_EventScript_Sign4_133
	call Route35_EventScript_Sign4_134
	end

Route35_EventScript_Sign4_102::
	call Route35_EventScript_Sign4_135
	call Route35_EventScript_Sign4_136
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_103::
	call Route35_EventScript_Sign4_137
	call Route35_EventScript_Sign4_136
	call Route35_EventScript_Sign4_138
	end

Route35_EventScript_Sign4_104::
	call Route35_EventScript_Sign4_139
	call Route35_EventScript_Sign4_140
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_105::
	call Route35_EventScript_Sign4_141
	call Route35_EventScript_Sign4_142
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_106::
	call Route35_EventScript_Sign4_143
	call Route35_EventScript_Sign4_142
	call Route35_EventScript_Sign4_138
	end

Route35_EventScript_Sign4_107::
	call Route35_EventScript_Sign4_144
	call Route35_EventScript_Sign4_145
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_108::
	call Route35_EventScript_Sign4_146
	call Route35_EventScript_Sign4_145
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_109::
	call Route35_EventScript_Sign4_147
	call Route35_EventScript_Sign4_148
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_110::
	call Route35_EventScript_Sign4_149
	call Route35_EventScript_Sign4_148
	call Route35_EventScript_Sign4_138
	end

Route35_EventScript_Sign4_111::
	call Route35_EventScript_Sign4_150
	call Route35_EventScript_Sign4_151
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_112::
	call Route35_EventScript_Sign4_152
	call Route35_EventScript_Sign4_153
	call Route35_EventScript_Sign4_138
	end

Route35_EventScript_Sign4_113::
	call Route35_EventScript_Sign4_154
	call Route35_EventScript_Sign4_153
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_114::
	call Route35_EventScript_Sign4_155
	call Route35_EventScript_Sign4_156
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_115::
	call Route35_EventScript_Sign4_157
	call Route35_EventScript_Sign4_158
	call Route35_EventScript_Sign4_138
	end

Route35_EventScript_Sign4_116::
	call Route35_EventScript_Sign4_159
	call Route35_EventScript_Sign4_160
	end

Route35_EventScript_Sign4_117::
	call Route35_EventScript_Sign4_161
	call Route35_EventScript_Sign4_162
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_118::
	call Route35_EventScript_Sign4_163
	call Route35_EventScript_Sign4_164
	call Route35_EventScript_Sign4_138
	end

Route35_EventScript_Sign4_119::
	call Route35_EventScript_Sign4_165
	call Route35_EventScript_Sign4_166
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_120::
	call Route35_EventScript_Sign4_167
	call Route35_EventScript_Sign4_168
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_121::
	call Route35_EventScript_Sign4_169
	call Route35_EventScript_Sign4_168
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_122::
	call Route35_EventScript_Sign4_170
	call Route35_EventScript_Sign4_171
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_123::
	call Route35_EventScript_Sign4_172
	call Route35_EventScript_Sign4_171
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_124::
	call Route35_EventScript_Sign4_173
	call Route35_EventScript_Sign4_174
	call Route35_EventScript_Sign4_138
	end

Route35_EventScript_Sign4_125::
	call Route35_EventScript_Sign4_175
	call Route35_EventScript_Sign4_176
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_126::
	call Route35_EventScript_Sign4_177
	call Route35_EventScript_Sign4_174
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_127::
	call Route35_EventScript_Sign4_178
	call Route35_EventScript_Sign4_176
	call Route35_EventScript_Sign4_138
	end

Route35_EventScript_Sign4_128::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_179
	call Route35_EventScript_Sign4_70
	end

Route35_EventScript_Sign4_129::
	goto_if_unset FLAG_BADGE05_GET, Route35_EventScript_Sign4_180
	goto_if_set FLAG_BADGE05_GET, Route35_EventScript_Sign4_181
	return

Route35_EventScript_Sign4_130::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_182
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_183
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_184
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_185
	return

Route35_EventScript_Sign4_131::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_186
	call_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_187
	call_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_188
	call_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_189
	end

Route35_EventScript_Sign4_132::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_190
	goto_if_gt VAR_0x8008, 0, Route35_EventScript_Sign4_191
	return

Route35_EventScript_Sign4_133::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_192
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_193
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_194
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_195
	return

Route35_EventScript_Sign4_134::
	call_if_set 0x1098, Route35_EventScript_Sign4_196
	call Route35_EventScript_Sign4_131
	end

Route35_EventScript_Sign4_135::
	goto_if_unset FLAG_BADGE07_GET, Route35_EventScript_Sign4_197
	goto_if_set FLAG_BADGE07_GET, Route35_EventScript_Sign4_198
	return

Route35_EventScript_Sign4_136::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_199
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_200
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_201
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_202
	return

Route35_EventScript_Sign4_137::
	goto_if_unset FLAG_BADGE04_GET, Route35_EventScript_Sign4_203
	goto_if_set FLAG_BADGE05_GET, Route35_EventScript_Sign4_204
	goto_if_set FLAG_BADGE04_GET, Route35_EventScript_Sign4_205
	return

Route35_EventScript_Sign4_138::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_206
	call_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_207
	call_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_208
	call_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_209
	end

Route35_EventScript_Sign4_139::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_lt VAR_0x8008, 2, Route35_EventScript_Sign4_210
	goto_if_gt VAR_0x8008, 1, Route35_EventScript_Sign4_211
	return

Route35_EventScript_Sign4_140::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_212
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_213
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_214
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_215
	return

Route35_EventScript_Sign4_141::
	goto_if_unset 0x115F, Route35_EventScript_Sign4_216
	goto_if_set 0x115F, Route35_EventScript_Sign4_217
	return

Route35_EventScript_Sign4_142::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_218
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_219
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_220
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_221
	return

Route35_EventScript_Sign4_143::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_222
	goto_if_gt VAR_0x8008, 0, Route35_EventScript_Sign4_223
	return

Route35_EventScript_Sign4_144::
	goto_if_unset 0x115F, Route35_EventScript_Sign4_224
	goto_if_set 0x115F, Route35_EventScript_Sign4_225
	return

Route35_EventScript_Sign4_145::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_226
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_227
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_228
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_229
	return

Route35_EventScript_Sign4_146::
	goto_if_unset FLAG_BADGE07_GET, Route35_EventScript_Sign4_230
	goto_if_set FLAG_BADGE07_GET, Route35_EventScript_Sign4_231
	return

Route35_EventScript_Sign4_147::
	setvar 0x7009, 114
	return

Route35_EventScript_Sign4_148::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_232
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_233
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_234
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_235
	return

Route35_EventScript_Sign4_149::
	goto_if_unset FLAG_BADGE07_GET, Route35_EventScript_Sign4_236
	goto_if_set FLAG_BADGE07_GET, Route35_EventScript_Sign4_237
	return

Route35_EventScript_Sign4_150::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_lt VAR_0x8008, 2, Route35_EventScript_Sign4_238
	goto_if_gt VAR_0x8008, 1, Route35_EventScript_Sign4_239
	return

Route35_EventScript_Sign4_151::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_240
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_241
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_242
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_243
	return

Route35_EventScript_Sign4_152::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_lt VAR_0x8008, 2, Route35_EventScript_Sign4_244
	goto_if_gt VAR_0x8008, 1, Route35_EventScript_Sign4_245
	return

Route35_EventScript_Sign4_153::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_246
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_247
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_248
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_249
	return

Route35_EventScript_Sign4_154::
	setvar 0x7009, 122
	return

Route35_EventScript_Sign4_155::
	goto_if_unset 0x8888, Route35_EventScript_Sign4_250
	goto_if_set 0x8888, Route35_EventScript_Sign4_251
	return

Route35_EventScript_Sign4_156::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_252
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_253
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_254
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_255
	return

Route35_EventScript_Sign4_157::
	goto_if_unset 0x115F, Route35_EventScript_Sign4_256
	goto_if_set 0x115F, Route35_EventScript_Sign4_257
	return

Route35_EventScript_Sign4_158::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_258
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_259
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_260
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_261
	return

Route35_EventScript_Sign4_159::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_lt VAR_0x8008, 2, Route35_EventScript_Sign4_262
	goto_if_gt VAR_0x8008, 1, Route35_EventScript_Sign4_263
	return

Route35_EventScript_Sign4_160::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_lt VAR_0x8008, 2, Route35_EventScript_Sign4_264
	call_if_gt VAR_0x8008, 1, Route35_EventScript_Sign4_265
	end

Route35_EventScript_Sign4_161::
	setvar 0x7009, 211
	return

Route35_EventScript_Sign4_162::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_266
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_267
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_268
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_269
	return

Route35_EventScript_Sign4_163::
	goto_if_unset 0x115F, Route35_EventScript_Sign4_270
	goto_if_set 0x115F, Route35_EventScript_Sign4_271
	return

Route35_EventScript_Sign4_164::
	.byte 0xFF @ invalid opcode (script stops)

Route35_EventScript_Sign4_165::
	setvar 0x7009, 108
	return

Route35_EventScript_Sign4_166::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_272
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_273
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_274
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_275
	return

Route35_EventScript_Sign4_167::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_276
	goto_if_gt VAR_0x8008, 0, Route35_EventScript_Sign4_277
	return

Route35_EventScript_Sign4_168::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_278
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_279
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_280
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_281
	return

Route35_EventScript_Sign4_169::
	goto_if_unset 0x115F, Route35_EventScript_Sign4_282
	goto_if_set 0x115F, Route35_EventScript_Sign4_283
	return

Route35_EventScript_Sign4_170::
	goto_if_unset FLAG_BADGE07_GET, Route35_EventScript_Sign4_284
	@ ShinyGold fix: the hack's pointer here is 0x09163337 (outside the ROM): the block for "badge 7 set" was
	@ assembled over the last two bytes of this pointer. It was meant to be 0x08883337, the "setvar 0x7009, 68"
	@ right after Sign4_284, so phone contact 35 crashed the game once the player had the seventh badge.
	goto_if_set FLAG_BADGE07_GET, Route35_EventScript_Sign4_170_1
	return

Route35_EventScript_Sign4_170_1::
	setvar 0x7009, 68
	return

Route35_EventScript_Sign4_171::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_285
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_286
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_287
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_288
	return

Route35_EventScript_Sign4_172::
	goto_if_unset 0x8888, Route35_EventScript_Sign4_289
	goto_if_set 0x8888, Route35_EventScript_Sign4_290
	return

Route35_EventScript_Sign4_173::
	setvar 0x7009, 78
	return

Route35_EventScript_Sign4_174::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_291
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_292
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_293
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_294
	return

Route35_EventScript_Sign4_175::
	setvar 0x7009, 83
	return

Route35_EventScript_Sign4_176::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_295
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_296
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_297
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_298
	return

Route35_EventScript_Sign4_177::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_299
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_300
	goto_if_gt VAR_0x8008, 1, Route35_EventScript_Sign4_301
	return

Route35_EventScript_Sign4_178::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_302
	goto_if_gt VAR_0x8008, 0, Route35_EventScript_Sign4_303
	return

Route35_EventScript_Sign4_179::
	call_if_eq 0x7008, 1, Route35_EventScript_Sign4_304
	call_if_eq 0x7008, 2, Route35_EventScript_Sign4_305
	call_if_eq 0x7008, 3, Route35_EventScript_Sign4_306
	call_if_eq 0x7008, 4, Route35_EventScript_Sign4_307
	call_if_eq 0x7008, 5, Route35_EventScript_Sign4_308
	call_if_eq 0x7008, 6, Route35_EventScript_Sign4_309
	call_if_eq 0x7008, 7, Route35_EventScript_Sign4_310
	call_if_eq 0x7008, 8, Route35_EventScript_Sign4_311
	call_if_eq 0x7008, 9, Route35_EventScript_Sign4_312
	call_if_eq 0x7008, 16, Route35_EventScript_Sign4_313
	call_if_eq 0x7008, 17, Route35_EventScript_Sign4_314
	call_if_eq 0x7008, 18, Route35_EventScript_Sign4_315
	call_if_eq 0x7008, 19, Route35_EventScript_Sign4_316
	call_if_eq 0x7008, 20, Route35_EventScript_Sign4_317
	call_if_eq 0x7008, 21, Route35_EventScript_Sign4_318
	call_if_eq 0x7008, 22, Route35_EventScript_Sign4_319
	call_if_eq 0x7008, 23, Route35_EventScript_Sign4_320
	call_if_eq 0x7008, 24, Route35_EventScript_Sign4_321
	call_if_eq 0x7008, 25, Route35_EventScript_Sign4_322
	call_if_eq 0x7008, 32, Route35_EventScript_Sign4_323
	call_if_eq 0x7008, 33, Route35_EventScript_Sign4_324
	call_if_eq 0x7008, 34, Route35_EventScript_Sign4_325
	call_if_eq 0x7008, 35, Route35_EventScript_Sign4_326
	call_if_eq 0x7008, 36, Route35_EventScript_Sign4_327
	call_if_eq 0x7008, 37, Route35_EventScript_Sign4_328
	call_if_eq 0x7008, 38, Route35_EventScript_Sign4_329
	call_if_eq 0x7008, 39, Route35_EventScript_Sign4_330
	call_if_eq 0x7008, 40, Route35_EventScript_Sign4_331
	end

Route35_EventScript_Sign4_180::
	setvar 0x7009, 19
	return

Route35_EventScript_Sign4_181::
	setvar 0x7009, 20
	return

Route35_EventScript_Sign4_182::
	setvar 0x700A, 10
	return

Route35_EventScript_Sign4_183::
	setvar 0x700A, 16
	return

Route35_EventScript_Sign4_184::
	setvar 0x700A, 19
	return

Route35_EventScript_Sign4_185::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_332
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_333
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_334
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_335
	return

Route35_EventScript_Sign4_186::
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x7009
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_75, MSGBOX_NPC
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x700A
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_76, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_187::
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x7009
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_75, MSGBOX_NPC
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x700A
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_77, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_188::
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x7009
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_78, MSGBOX_NPC
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x700A
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_76, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_189::
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x7009
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_78, MSGBOX_NPC
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x700A
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_77, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_190::
	goto_if_unset FLAG_BADGE02_GET, Route35_EventScript_Sign4_336
	goto_if_set FLAG_BADGE05_GET, Route35_EventScript_Sign4_337
	goto_if_set FLAG_BADGE02_GET, Route35_EventScript_Sign4_338
	return

Route35_EventScript_Sign4_191::
	goto_if_unset FLAG_BADGE02_GET, Route35_EventScript_Sign4_339
	goto_if_set FLAG_BADGE05_GET, Route35_EventScript_Sign4_340
	goto_if_set FLAG_BADGE02_GET, Route35_EventScript_Sign4_341
	return

Route35_EventScript_Sign4_192::
	setvar 0x700A, 10
	return

Route35_EventScript_Sign4_193::
	setvar 0x700A, 16
	return

Route35_EventScript_Sign4_194::
	setvar 0x700A, 19
	return

Route35_EventScript_Sign4_195::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_342
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_343
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_344
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_345
	return

Route35_EventScript_Sign4_196::
	msgbox Route35_Text_Sign4_79, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_197::
	setvar 0x7009, 118
	return

Route35_EventScript_Sign4_198::
	setvar 0x7009, 119
	return

Route35_EventScript_Sign4_199::
	setvar 0x700A, 19
	return

Route35_EventScript_Sign4_200::
	setvar 0x700A, 187
	return

Route35_EventScript_Sign4_201::
	setvar 0x700A, 69
	return

Route35_EventScript_Sign4_202::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_346
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_347
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_348
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_349
	return

Route35_EventScript_Sign4_203::
	setvar 0x7009, 29
	return

Route35_EventScript_Sign4_204::
	setvar 0x7009, 31
	return

Route35_EventScript_Sign4_205::
	setvar 0x7009, 30
	return

Route35_EventScript_Sign4_206::
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x7009
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_80, MSGBOX_NPC
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x700A
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_81, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_207::
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x7009
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_80, MSGBOX_NPC
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x700A
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_82, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_208::
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x7009
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_83, MSGBOX_NPC
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x700A
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_81, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_209::
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x7009
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_83, MSGBOX_NPC
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x700A
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_82, MSGBOX_NPC
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_210::
	goto_if_unset 0x110A, Route35_EventScript_Sign4_350
	goto_if_set 0x115F, Route35_EventScript_Sign4_351
	goto_if_set 0x110A, Route35_EventScript_Sign4_352
	return

Route35_EventScript_Sign4_211::
	goto_if_unset FLAG_BADGE05_GET, Route35_EventScript_Sign4_353
	goto_if_set 0x110A, Route35_EventScript_Sign4_354
	goto_if_set FLAG_BADGE05_GET, Route35_EventScript_Sign4_355
	return

Route35_EventScript_Sign4_212::
	setvar 0x700A, 187
	return

Route35_EventScript_Sign4_213::
	setvar 0x700A, 19
	return

Route35_EventScript_Sign4_214::
	setvar 0x700A, 21
	return

Route35_EventScript_Sign4_215::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_356
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_357
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_358
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_359
	return

Route35_EventScript_Sign4_216::
	setvar 0x7009, 54
	return

Route35_EventScript_Sign4_217::
	setvar 0x7009, 55
	return

Route35_EventScript_Sign4_218::
	setvar 0x700A, 19
	return

Route35_EventScript_Sign4_219::
	setvar 0x700A, 16
	return

Route35_EventScript_Sign4_220::
	setvar 0x700A, 163
	return

Route35_EventScript_Sign4_221::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_360
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_361
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_362
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_363
	return

Route35_EventScript_Sign4_222::
	goto_if_unset FLAG_BADGE05_GET, Route35_EventScript_Sign4_364
	goto_if_set 0x115F, Route35_EventScript_Sign4_365
	goto_if_set FLAG_BADGE05_GET, Route35_EventScript_Sign4_366
	return

Route35_EventScript_Sign4_223::
	goto_if_unset 0x110A, Route35_EventScript_Sign4_367
	goto_if_set 0x115F, Route35_EventScript_Sign4_368
	goto_if_set 0x110A, Route35_EventScript_Sign4_369
	return

Route35_EventScript_Sign4_224::
	setvar 0x7009, 100
	return

Route35_EventScript_Sign4_225::
	setvar 0x7009, 101
	return

Route35_EventScript_Sign4_226::
	setvar 0x700A, 32
	return

Route35_EventScript_Sign4_227::
	setvar 0x700A, 29
	return

Route35_EventScript_Sign4_228::
	setvar 0x700A, 96
	return

Route35_EventScript_Sign4_229::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_370
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_371
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_372
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_373
	return

Route35_EventScript_Sign4_230::
	setvar 0x7009, 48
	return

Route35_EventScript_Sign4_231::
	setvar 0x7009, 49
	return

Route35_EventScript_Sign4_232::
	setvar 0x700A, 10
	return

Route35_EventScript_Sign4_233::
	setvar 0x700A, 16
	return

Route35_EventScript_Sign4_234::
	setvar 0x700A, 11
	return

Route35_EventScript_Sign4_235::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_374
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_375
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_376
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_377
	return

Route35_EventScript_Sign4_236::
	setvar 0x7009, 209
	return

Route35_EventScript_Sign4_237::
	setvar 0x7009, 210
	return

Route35_EventScript_Sign4_238::
	goto_if_unset 0x110A, Route35_EventScript_Sign4_378
	goto_if_set 0x110A, Route35_EventScript_Sign4_379
	return

Route35_EventScript_Sign4_239::
	goto_if_unset 0x110A, Route35_EventScript_Sign4_380
	goto_if_set 0x115F, Route35_EventScript_Sign4_381
	goto_if_set 0x110A, Route35_EventScript_Sign4_382
	return

Route35_EventScript_Sign4_240::
	setvar 0x700A, 32
	return

Route35_EventScript_Sign4_241::
	setvar 0x700A, 29
	return

Route35_EventScript_Sign4_242::
	setvar 0x700A, 16
	return

Route35_EventScript_Sign4_243::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_383
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_384
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_385
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_386
	return

Route35_EventScript_Sign4_244::
	goto_if_unset 0x115F, Route35_EventScript_Sign4_387
	goto_if_set 0x115F, Route35_EventScript_Sign4_388
	return

Route35_EventScript_Sign4_245::
	goto_if_unset 0x110A, Route35_EventScript_Sign4_389
	goto_if_set 0x110A, Route35_EventScript_Sign4_390
	return

Route35_EventScript_Sign4_246::
	setvar 0x700A, 19
	return

Route35_EventScript_Sign4_247::
	setvar 0x700A, 20
	return

Route35_EventScript_Sign4_248::
	setvar 0x700A, 81
	return

Route35_EventScript_Sign4_249::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_391
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_392
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_393
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_394
	return

Route35_EventScript_Sign4_250::
	setvar 0x7009, 25
	return

Route35_EventScript_Sign4_251::
	setvar 0x7009, 26
	return

Route35_EventScript_Sign4_252::
	setvar 0x700A, 19
	return

Route35_EventScript_Sign4_253::
	setvar 0x700A, 20
	return

Route35_EventScript_Sign4_254::
	setvar 0x700A, 81
	return

Route35_EventScript_Sign4_255::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_395
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_396
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_397
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_398
	return

Route35_EventScript_Sign4_256::
	setvar 0x7009, 77
	return

Route35_EventScript_Sign4_257::
	setvar 0x7009, 78
	return

Route35_EventScript_Sign4_258::
	setvar 0x700A, 19
	return

Route35_EventScript_Sign4_259::
	setvar 0x700A, 16
	return

Route35_EventScript_Sign4_260::
	setvar 0x700A, 21
	return

Route35_EventScript_Sign4_261::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_399
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_400
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_401
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_402
	return

Route35_EventScript_Sign4_262::
	goto_if_unset 0x110A, Route35_EventScript_Sign4_403
	goto_if_set 0x115F, Route35_EventScript_Sign4_404
	goto_if_set 0x110A, Route35_EventScript_Sign4_405
	return

Route35_EventScript_Sign4_263::
	goto_if_unset FLAG_BADGE07_GET, Route35_EventScript_Sign4_406
	goto_if_set FLAG_BADGE07_GET, Route35_EventScript_Sign4_407
	return

Route35_EventScript_Sign4_264::
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x7009
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_75, MSGBOX_NPC
	release
	end

Route35_EventScript_Sign4_265::
	copyvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 0x7009
	special SampleResortGorgeousMonAndReward
	msgbox Route35_Text_Sign4_78, MSGBOX_NPC
	release
	end

Route35_EventScript_Sign4_266::
	setvar 0x700A, 56
	return

Route35_EventScript_Sign4_267::
	setvar 0x700A, 179
	return

Route35_EventScript_Sign4_268::
	setvar 0x700A, 21
	return

Route35_EventScript_Sign4_269::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_408
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_409
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_410
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_411
	return

Route35_EventScript_Sign4_270::
	setvar 0x7009, 35
	return

Route35_EventScript_Sign4_271::
	setvar 0x7009, 36
	return

Route35_EventScript_Sign4_272::
	setvar 0x700A, 180
	return

Route35_EventScript_Sign4_273::
	setvar 0x700A, 17
	return

Route35_EventScript_Sign4_274::
	setvar 0x700A, 164
	return

Route35_EventScript_Sign4_275::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_412
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_413
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_414
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_415
	return

Route35_EventScript_Sign4_276::
	setvar 0x7009, 119
	return

Route35_EventScript_Sign4_277::
	goto_if_unset 0x115F, Route35_EventScript_Sign4_416
	goto_if_set 0x115F, Route35_EventScript_Sign4_417
	return

Route35_EventScript_Sign4_278::
	setvar 0x700A, 114
	return

Route35_EventScript_Sign4_279::
	setvar 0x700A, 69
	return

Route35_EventScript_Sign4_280::
	setvar 0x700A, 70
	return

Route35_EventScript_Sign4_281::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_418
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_419
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_420
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_421
	return

Route35_EventScript_Sign4_282::
	setvar 0x7009, 17
	return

Route35_EventScript_Sign4_283::
	setvar 0x7009, 18
	return

Route35_EventScript_Sign4_284::
	@ ShinyGold: overlapping data duplicated from 0x08883330
	setvar 0x7009, 67
	return

Route35_EventScript_Sign4_285::
	setvar 0x700A, 74
	return

Route35_EventScript_Sign4_286::
	setvar 0x700A, 75
	return

Route35_EventScript_Sign4_287::
	setvar 0x700A, 207
	return

Route35_EventScript_Sign4_288::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_422
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_423
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_424
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_425
	return

Route35_EventScript_Sign4_289::
	setvar 0x7009, 95
	return

Route35_EventScript_Sign4_290::
	setvar 0x7009, 208
	return

Route35_EventScript_Sign4_291::
	setvar 0x700A, 84
	return

Route35_EventScript_Sign4_292::
	setvar 0x700A, 28
	return

Route35_EventScript_Sign4_293::
	setvar 0x700A, 77
	return

Route35_EventScript_Sign4_294::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_426
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_427
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_428
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_429
	return

Route35_EventScript_Sign4_295::
	setvar 0x700A, 84
	return

Route35_EventScript_Sign4_296::
	setvar 0x700A, 20
	return

Route35_EventScript_Sign4_297::
	setvar 0x700A, 195
	return

Route35_EventScript_Sign4_298::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, Route35_EventScript_Sign4_430
	goto_if_eq VAR_0x8008, 1, Route35_EventScript_Sign4_431
	goto_if_eq VAR_0x8008, 2, Route35_EventScript_Sign4_432
	goto_if_eq VAR_0x8008, 3, Route35_EventScript_Sign4_433
	return

Route35_EventScript_Sign4_299::
	setvar 0x7009, 71
	return

Route35_EventScript_Sign4_300::
	setvar 0x7009, 99
	return

Route35_EventScript_Sign4_301::
	setvar 0x7009, 136
	return

Route35_EventScript_Sign4_302::
	setvar 0x7009, 31
	return

Route35_EventScript_Sign4_303::
	setvar 0x7009, 121
	return

Route35_EventScript_Sign4_304::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_57, MSGBOX_NPC
	setflag 0x1301
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_305::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_58, MSGBOX_NPC
	setflag 0x1302
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_306::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_59, MSGBOX_NPC
	setflag 0x1303
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_307::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_59, MSGBOX_NPC
	setflag 0x1304
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_308::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_60, MSGBOX_NPC
	setflag 0x1305
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_309::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_61, MSGBOX_NPC
	setflag 0x1306
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_310::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_61, MSGBOX_NPC
	setflag 0x1307
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_311::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_62, MSGBOX_NPC
	setflag 0x1308
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_312::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_62, MSGBOX_NPC
	setflag 0x1309
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_313::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_63, MSGBOX_NPC
	setflag 0x1310
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_314::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_63, MSGBOX_NPC
	setflag 0x1311
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_315::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_64, MSGBOX_NPC
	setflag 0x1312
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_316::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_65, MSGBOX_NPC
	setflag 0x1313
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_317::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_65, MSGBOX_NPC
	setflag 0x1314
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_318::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_66, MSGBOX_NPC
	setflag 0x1315
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_319::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_67, MSGBOX_NPC
	setflag 0x1316
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_320::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_68, MSGBOX_NPC
	setflag 0x1317
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_321::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_69, MSGBOX_NPC
	setflag 0x1318
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_322::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_70, MSGBOX_NPC
	setflag 0x1319
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_323::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_70, MSGBOX_NPC
	setflag 0x1320
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_324::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_71, MSGBOX_NPC
	setflag 0x1321
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_325::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_71, MSGBOX_NPC
	setflag 0x1322
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_326::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_72, MSGBOX_NPC
	setflag 0x1323
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_327::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_72, MSGBOX_NPC
	setflag 0x1324
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_328::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_73, MSGBOX_NPC
	setflag 0x1325
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_329::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_74, MSGBOX_NPC
	setflag 0x1326
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_330::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_73, MSGBOX_NPC
	setflag 0x1327
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_331::
	msgbox Route35_Text_Sign4_84, MSGBOX_NPC
	msgbox Route35_Text_Sign4_74, MSGBOX_NPC
	setflag 0x1328
	special DaisyMassageServices
	call Route35_EventScript_Sign4_24
	end

Route35_EventScript_Sign4_332::
	setvar 0x700A, 163
	return

Route35_EventScript_Sign4_333::
	setvar 0x700A, 167
	return

Route35_EventScript_Sign4_334::
	setvar 0x700A, 13
	return

Route35_EventScript_Sign4_335::
	setvar 0x700A, 165
	return

Route35_EventScript_Sign4_336::
	setvar 0x7009, 13
	return

Route35_EventScript_Sign4_337::
	setvar 0x7009, 15
	return

Route35_EventScript_Sign4_338::
	setvar 0x7009, 14
	return

Route35_EventScript_Sign4_339::
	setvar 0x7009, 10
	return

Route35_EventScript_Sign4_340::
	setvar 0x7009, 12
	return

Route35_EventScript_Sign4_341::
	setvar 0x7009, 11
	return

Route35_EventScript_Sign4_342::
	setvar 0x700A, 69
	return

Route35_EventScript_Sign4_343::
	setvar 0x700A, 163
	return

Route35_EventScript_Sign4_344::
	setvar 0x700A, 167
	return

Route35_EventScript_Sign4_345::
	setvar 0x700A, 13
	return

Route35_EventScript_Sign4_346::
	setvar 0x700A, 179
	return

Route35_EventScript_Sign4_347::
	setvar 0x700A, 194
	return

Route35_EventScript_Sign4_348::
	setvar 0x700A, 41
	return

Route35_EventScript_Sign4_349::
	setvar 0x700A, 23
	return

Route35_EventScript_Sign4_350::
	setvar 0x7009, 74
	return

Route35_EventScript_Sign4_351::
	setvar 0x7009, 76
	return

Route35_EventScript_Sign4_352::
	setvar 0x7009, 75
	return

Route35_EventScript_Sign4_353::
	setvar 0x7009, 66
	return

Route35_EventScript_Sign4_354::
	setvar 0x7009, 68
	return

Route35_EventScript_Sign4_355::
	setvar 0x7009, 67
	return

Route35_EventScript_Sign4_356::
	setvar 0x700A, 41
	return

Route35_EventScript_Sign4_357::
	setvar 0x700A, 41
	return

Route35_EventScript_Sign4_358::
	setvar 0x700A, 19
	return

Route35_EventScript_Sign4_359::
	setvar 0x700A, 23
	return

Route35_EventScript_Sign4_360::
	setvar 0x700A, 96
	return

Route35_EventScript_Sign4_361::
	setvar 0x700A, 19
	return

Route35_EventScript_Sign4_362::
	setvar 0x700A, 63
	return

Route35_EventScript_Sign4_363::
	setvar 0x700A, 132
	return

Route35_EventScript_Sign4_364::
	setvar 0x7009, 1
	return

Route35_EventScript_Sign4_365::
	setvar 0x7009, 3
	return

Route35_EventScript_Sign4_366::
	setvar 0x7009, 2
	return

Route35_EventScript_Sign4_367::
	setvar 0x7009, 187
	return

Route35_EventScript_Sign4_368::
	setvar 0x7009, 189
	return

Route35_EventScript_Sign4_369::
	setvar 0x7009, 188
	return

Route35_EventScript_Sign4_370::
	setvar 0x700A, 63
	return

Route35_EventScript_Sign4_371::
	setvar 0x700A, 16
	return

Route35_EventScript_Sign4_372::
	setvar 0x700A, 163
	return

Route35_EventScript_Sign4_373::
	setvar 0x700A, 193
	return

Route35_EventScript_Sign4_374::
	setvar 0x700A, 163
	return

Route35_EventScript_Sign4_375::
	setvar 0x700A, 191
	return

Route35_EventScript_Sign4_376::
	setvar 0x700A, 13
	return

Route35_EventScript_Sign4_377::
	setvar 0x700A, 14
	return

Route35_EventScript_Sign4_378::
	setvar 0x7009, 100
	return

Route35_EventScript_Sign4_379::
	setvar 0x7009, 101
	return

Route35_EventScript_Sign4_380::
	setvar 0x7009, 43
	return

Route35_EventScript_Sign4_381::
	setvar 0x7009, 45
	return

Route35_EventScript_Sign4_382::
	setvar 0x7009, 44
	return

Route35_EventScript_Sign4_383::
	setvar 0x700A, 163
	return

Route35_EventScript_Sign4_384::
	setvar 0x700A, 58
	return

Route35_EventScript_Sign4_385::
	setvar 0x700A, 234
	return

Route35_EventScript_Sign4_386::
	setvar 0x700A, 37
	return

Route35_EventScript_Sign4_387::
	setvar 0x7009, 180
	return

Route35_EventScript_Sign4_388::
	setvar 0x7009, 181
	return

Route35_EventScript_Sign4_389::
	setvar 0x7009, 54
	return

Route35_EventScript_Sign4_390::
	setvar 0x7009, 55
	return

Route35_EventScript_Sign4_391::
	setvar 0x700A, 83
	return

Route35_EventScript_Sign4_392::
	setvar 0x700A, 128
	return

Route35_EventScript_Sign4_393::
	setvar 0x700A, 241
	return

Route35_EventScript_Sign4_394::
	setvar 0x700A, 209
	return

Route35_EventScript_Sign4_395::
	setvar 0x700A, 83
	return

Route35_EventScript_Sign4_396::
	setvar 0x700A, 128
	return

Route35_EventScript_Sign4_397::
	setvar 0x700A, 241
	return

Route35_EventScript_Sign4_398::
	setvar 0x700A, 52
	return

Route35_EventScript_Sign4_399::
	setvar 0x700A, 74
	return

Route35_EventScript_Sign4_400::
	setvar 0x700A, 19
	return

Route35_EventScript_Sign4_401::
	setvar 0x700A, 74
	return

Route35_EventScript_Sign4_402::
	setvar 0x700A, 39
	return

Route35_EventScript_Sign4_403::
	setvar 0x7009, 60
	return

Route35_EventScript_Sign4_404::
	setvar 0x7009, 186
	return

Route35_EventScript_Sign4_405::
	setvar 0x7009, 61
	return

Route35_EventScript_Sign4_406::
	setvar 0x7009, 61
	return

Route35_EventScript_Sign4_407::
	setvar 0x7009, 62
	return

Route35_EventScript_Sign4_408::
	setvar 0x700A, 21
	return

Route35_EventScript_Sign4_409::
	setvar 0x700A, 41
	return

Route35_EventScript_Sign4_410::
	setvar 0x700A, 56
	return

Route35_EventScript_Sign4_411::
	setvar 0x700A, 180
	return

Route35_EventScript_Sign4_412::
	setvar 0x700A, 48
	return

Route35_EventScript_Sign4_413::
	setvar 0x700A, 203
	return

Route35_EventScript_Sign4_414::
	setvar 0x700A, 17
	return

Route35_EventScript_Sign4_415::
	setvar 0x700A, 164
	return

Route35_EventScript_Sign4_416::
	setvar 0x7009, 118
	return

Route35_EventScript_Sign4_417::
	setvar 0x7009, 119
	return

Route35_EventScript_Sign4_418::
	setvar 0x700A, 108
	return

Route35_EventScript_Sign4_419::
	setvar 0x700A, 108
	return

Route35_EventScript_Sign4_420::
	setvar 0x700A, 70
	return

Route35_EventScript_Sign4_421::
	setvar 0x700A, 114
	return

Route35_EventScript_Sign4_422::
	setvar 0x700A, 216
	return

Route35_EventScript_Sign4_423::
	setvar 0x700A, 75
	return

Route35_EventScript_Sign4_424::
	setvar 0x700A, 231
	return

Route35_EventScript_Sign4_425::
	setvar 0x700A, 227
	return

Route35_EventScript_Sign4_426::
	setvar 0x700A, 20
	return

Route35_EventScript_Sign4_427::
	setvar 0x700A, 195
	return

Route35_EventScript_Sign4_428::
	setvar 0x700A, 85
	return

Route35_EventScript_Sign4_429::
	setvar 0x700A, 24
	return

Route35_EventScript_Sign4_430::
	setvar 0x700A, 77
	return

Route35_EventScript_Sign4_431::
	setvar 0x700A, 28
	return

Route35_EventScript_Sign4_432::
	setvar 0x700A, 84
	return

Route35_EventScript_Sign4_433::
	setvar 0x700A, 24
	return
