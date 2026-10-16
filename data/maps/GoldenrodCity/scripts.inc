GoldenrodCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodCity_OnFrame
	.byte 0

GoldenrodCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FOUR_ISLAND
	call_if_eq 0x4086, 0, GoldenrodCity_EventScript_OnTransition_1
	call GoldenrodCity_EventScript_OnTransition_2
	end

GoldenrodCity_EventScript_OnTransition_1::
	clearflag 0x097
	return

GoldenrodCity_EventScript_OnTransition_2::
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, GoldenrodCity_EventScript_OnTransition_3
	setobjectxyperm 1, 16, 14

GoldenrodCity_EventScript_OnTransition_3::
	return

GoldenrodCity_OnFrame::
	map_script_2 0x7024, 0, GoldenrodCity_EventScript_FrameScene
	.2byte 0

GoldenrodCity_EventScript_FrameScene::
	setflag 0x136E
	call NewBarkTown_EventScript_FrameScene_1
	call SlowpokeWell_Cave1_EventScript_TeamRocketGrunt_1
	setvar 0x7024, 1
	call GoldenrodCity_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

GoldenrodCity_EventScript_FrameScene_1::
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
	setvar 0x701F, 0
	setvar 0x7020, 0
	setvar 0x7021, 0
	setvar 0x7022, 0
	setvar 0x7023, 0
	setvar 0x7025, 0
	setvar 0x7026, 0
	setvar 0x7027, 0
	setvar 0x7028, 0
	return

GoldenrodCity_EventScript_Woman2::
	call_if_set 0x1241, GoldenrodCity_EventScript_Woman2_1
	msgbox GoldenrodCity_Text_Woman2_1, MSGBOX_NPC
	giveitem ITEM_SILK_SCARF
	msgbox GoldenrodCity_Text_Woman2_2, MSGBOX_NPC
	setflag 0x1241
	clearflag 0x1242
	release
	end

GoldenrodCity_EventScript_Woman2_1::
	msgbox GoldenrodCity_Text_Woman2_3, MSGBOX_NPC
	end

GoldenrodCity_EventScript_WorkerF::
	call_if_set 0x10BF, GoldenrodCity_EventScript_WorkerF_1
	msgbox GoldenrodCity_Text_WorkerF_1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_WorkerF_1::
	msgbox GoldenrodCity_Text_WorkerF_2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_BaldingMan::
	msgbox GoldenrodCity_Text_BaldingMan, MSGBOX_NPC
	end

GoldenrodCity_EventScript_RocketM::
	applymovement 4, GoldenrodCity_Movement_RocketM
	msgbox GoldenrodCity_Text_RocketM_1, MSGBOX_AUTOCLOSE
	msgbox GoldenrodCity_Text_RocketM_2, MSGBOX_NPC
	applymovement 4, GoldenrodCity_Movement_RocketM
	end

GoldenrodCity_Movement_RocketM::
	face_up
	step_end

GoldenrodCity_EventScript_RocketM2::
	msgbox GoldenrodCity_Text_RocketM2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Boy::
	msgbox GoldenrodCity_Text_Boy_1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_RocketM3::
	msgbox GoldenrodCity_Text_RocketM3, MSGBOX_NPC
	end

GoldenrodCity_EventScript_RocketF::
	msgbox GoldenrodCity_Text_RocketF, MSGBOX_NPC
	end

GoldenrodCity_EventScript_RocketF2::
	msgbox GoldenrodCity_Text_RocketF2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Woman22::
	call_if_set 0x10C0, GoldenrodCity_EventScript_Woman22_1
	msgbox GoldenrodCity_Text_Woman22_1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Woman22_1::
	msgbox GoldenrodCity_Text_Woman22_2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_OldMan1::
	msgbox GoldenrodCity_Text_OldMan1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_CrushGirl::
	lock
	faceplayer
	setvar VAR_0x8004, 9
	setvar VAR_0x8005, 4
	special SetFlavorTextFlagFromSpecialVars
	msgbox GoldenrodCity_Text_CrushGirl
	release
	end

GoldenrodCity_EventScript_RocketM4::
	msgbox GoldenrodCity_Text_RocketM4, MSGBOX_NPC
	end

GoldenrodCity_EventScript_RocketF3::
	msgbox GoldenrodCity_Text_RocketF3, MSGBOX_NPC
	end

GoldenrodCity_EventScript_TeachyTvHost::
	msgbox GoldenrodCity_Text_TeachyTvHost_1, MSGBOX_NPC
	applymovement 15, GoldenrodCity_Movement_TeachyTvHost_1
	msgbox GoldenrodCity_Text_TeachyTvHost_2, MSGBOX_NPC
	call_if_eq VAR_TEMP_1, 1, GoldenrodCity_EventScript_TeachyTvHost_1
	call_if_eq VAR_TEMP_1, 2, GoldenrodCity_EventScript_TeachyTvHost_2
	call_if_eq VAR_TEMP_1, 3, GoldenrodCity_EventScript_TeachyTvHost_2
	end

GoldenrodCity_EventScript_TeachyTvHost_1::
	applymovement 15, GoldenrodCity_Movement_TeachyTvHost_2
	delay 192
	setflag 0x1091
	release
	end

GoldenrodCity_EventScript_TeachyTvHost_2::
	applymovement 15, GoldenrodCity_Movement_TeachyTvHost_3
	delay 192
	setflag 0x1091
	release
	end

GoldenrodCity_Movement_TeachyTvHost_1::
	emote_question_mark
	step_end

GoldenrodCity_Movement_TeachyTvHost_2::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

GoldenrodCity_Movement_TeachyTvHost_3::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

GoldenrodCity_EventScript_Youngster::
	msgbox GoldenrodCity_Text_Youngster, MSGBOX_NPC
	end

GoldenrodCity_EventScript_RocketM5::
	msgbox GoldenrodCity_Text_RocketM5, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Trigger1::
	call_if_set 0x10BE, GoldenrodCity_EventScript_Trigger1_1
	setflag 0x10BC
	setflag 0x10BD
	release
	end

GoldenrodCity_EventScript_Trigger1_1::
	call_if_set 0x10BF, GoldenrodCity_EventScript_Trigger1_2
	setflag 0x10BD
	release
	end

GoldenrodCity_EventScript_Trigger1_2::
	release
	end

GoldenrodCity_EventScript_Trigger5::
	call_if_set 0x10C4, GoldenrodCity_EventScript_Trigger5_1
	setflag 0x10C3
	release
	end

GoldenrodCity_EventScript_Trigger5_1::
	release
	end

GoldenrodCity_EventScript_Trigger6::
	call_if_set 0x109A, GoldenrodCity_EventScript_Trigger6_1
	setflag 0x109A
	setflag 0x1099
	end

GoldenrodCity_EventScript_Trigger6_1::
	release
	end

GoldenrodCity_EventScript_Trigger7::
	call_if_set 0x1091, GoldenrodCity_EventScript_Trigger7_1
	setvar VAR_TEMP_1, 1
	release
	end

GoldenrodCity_EventScript_Trigger7_1::
	release
	end

GoldenrodCity_EventScript_Trigger8::
	call_if_set 0x1091, GoldenrodCity_EventScript_Trigger7_1
	setvar VAR_TEMP_1, 3
	release
	end

GoldenrodCity_EventScript_Trigger10::
	call_if_set 0x1091, GoldenrodCity_EventScript_Trigger7_1
	setvar VAR_TEMP_1, 2
	release
	end

GoldenrodCity_EventScript_Sign1::
	msgbox GoldenrodCity_Text_Sign1, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_EventScript_Sign2::
	msgbox GoldenrodCity_Text_Sign2, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_EventScript_Sign3::
	msgbox GoldenrodCity_Text_Sign3, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_EventScript_Sign4::
	msgbox GoldenrodCity_Text_Sign4, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_EventScript_Sign6::
	msgbox GoldenrodCity_Text_Sign6, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_EventScript_Sign7::
	msgbox GoldenrodCity_Text_Sign7, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_EventScript_Sign8::
	msgbox GoldenrodCity_Text_Sign8, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_EventScript_Sign9::
	msgbox GoldenrodCity_Text_Sign9, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_EventScript_Sign10::
	call_if_unset 0x1027, Route35_EventScript_Sign4_1
	setvar 0x700B, 4
	call_if_eq VAR_FACING, 2, Route35_EventScript_Sign4_2
	release
	end
