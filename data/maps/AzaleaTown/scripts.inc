AzaleaTown_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AzaleaTown_OnFrame
	.byte 0

AzaleaTown_OnFrame::
	map_script_2 0x7023, 0, AzaleaTown_EventScript_FrameScene
	.2byte 0

AzaleaTown_EventScript_FrameScene::
	setflag 0x136D
	call NewBarkTown_EventScript_FrameScene_1
	call SlowpokeWell_Cave1_EventScript_TeamRocketGrunt_1
	setvar 0x7023, 1
	call AzaleaTown_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

AzaleaTown_EventScript_FrameScene_1::
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
	setvar 0x7024, 0
	setvar 0x7025, 0
	setvar 0x7026, 0
	setvar 0x7027, 0
	setvar 0x7028, 0
	return

AzaleaTown_EventScript_RocketM::
	msgbox AzaleaTown_Text_RocketM, MSGBOX_NPC
	end

AzaleaTown_EventScript_OldMan1::
	call_if_set 0x1055, AzaleaTown_EventScript_OldMan1_1
	msgbox AzaleaTown_Text_OldMan1_1, MSGBOX_NPC
	end

AzaleaTown_EventScript_OldMan1_1::
	msgbox AzaleaTown_Text_OldMan1_2, MSGBOX_NPC
	end

AzaleaTown_EventScript_Woman2::
	msgbox AzaleaTown_Text_Woman2, MSGBOX_NPC
	end

AzaleaTown_EventScript_Rocker::
	msgbox AzaleaTown_Text_Rocker, MSGBOX_NPC
	end

AzaleaTown_EventScript_RocketM2::
	msgbox AzaleaTown_Text_RocketM2, MSGBOX_NPC
	end

AzaleaTown_EventScript_Slowpoke::
	msgbox AzaleaTown_Text_Slowpoke, MSGBOX_NPC
	end

AzaleaTown_EventScript_BaldingMan::
	call_if_set 0x11B1, AzaleaTown_EventScript_BaldingMan_1
	applymovement 17, AzaleaTown_Movement_BaldingMan
	delay 1
	msgbox AzaleaTown_Text_BaldingMan_1, MSGBOX_AUTOCLOSE
	msgbox AzaleaTown_Text_BaldingMan_2, MSGBOX_NPC
	setflag 0x11B1
	giveitem ITEM_RED_ORB
	release
	end

AzaleaTown_EventScript_BaldingMan_1::
	msgbox AzaleaTown_Text_BaldingMan_3, MSGBOX_NPC
	end

AzaleaTown_Movement_BaldingMan::
	face_left
	step_end

AzaleaTown_EventScript_Trigger1::
	call_if_set 0x1061, AzaleaTown_EventScript_Trigger1_1
	setflag 0x1056
	release
	end

AzaleaTown_EventScript_Trigger1_1::
	release
	end

AzaleaTown_EventScript_Trigger2::
	call_if_set 0x1061, AzaleaTown_EventScript_Trigger2_1
	setflag 0x1054
	release
	end

AzaleaTown_EventScript_Trigger2_1::
	release
	end

AzaleaTown_EventScript_Trigger3::
	setflag 0x1059
	release
	end

AzaleaTown_EventScript_Trigger4::
	call_if_set 0x1068, AzaleaTown_EventScript_Trigger4_1
	call_if_unset 0x1055, AzaleaTown_EventScript_Trigger4_1
	setflag 0x1057
	clearflag 0x1056
	release
	applymovement LOCALID_PLAYER, AzaleaTown_Movement_Trigger4_1
	delay 16
	playbgm MUS_ENCOUNTER_RIVAL, 51
	applymovement 6, AzaleaTown_Movement_Trigger4_2
	delay 160
	call AzaleaTown_EventScript_Trigger4_2
	applymovement LOCALID_PLAYER, AzaleaTown_Movement_Trigger4_3
	applymovement 6, AzaleaTown_Movement_Trigger4_4
	delay 80
	end

AzaleaTown_EventScript_Trigger4_1::
	release
	end

AzaleaTown_EventScript_Trigger4_2::
	msgbox AzaleaTown_Text_Trigger4_1, MSGBOX_NPC
	call_if_eq VAR_STARTER_MON, 0, AzaleaTown_EventScript_Trigger4_3
	call_if_eq VAR_STARTER_MON, 1, AzaleaTown_EventScript_Trigger4_4
	call_if_eq VAR_STARTER_MON, 2, AzaleaTown_EventScript_Trigger4_5
	return

AzaleaTown_Movement_Trigger4_1::
	walk_left
	face_right
	emote_exclamation_mark
	step_end

AzaleaTown_Movement_Trigger4_2::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

AzaleaTown_EventScript_Trigger4_3::
	setflag 0x1056
	trainerbattle_earlyrival TRAINER_RIVAL_TERRY, 0, AzaleaTown_Text_Trigger4Defeat, AzaleaTown_Text_Trigger4Victory
	clearflag 0x1056
	call AzaleaTown_EventScript_Trigger4_6
	return

AzaleaTown_EventScript_Trigger4_4::
	setflag 0x1056
	trainerbattle_earlyrival TRAINER_RIVAL_TERRY_2, 0, AzaleaTown_Text_Trigger4Defeat, AzaleaTown_Text_Trigger4Victory
	clearflag 0x1056
	call AzaleaTown_EventScript_Trigger4_6
	return

AzaleaTown_EventScript_Trigger4_5::
	setflag 0x1056
	trainerbattle_earlyrival TRAINER_RIVAL_TERRY_3, 0, AzaleaTown_Text_Trigger4Defeat, AzaleaTown_Text_Trigger4Victory
	clearflag 0x1056
	call AzaleaTown_EventScript_Trigger4_6
	return

AzaleaTown_Movement_Trigger4_3::
	walk_down
	face_up
	step_end

AzaleaTown_Movement_Trigger4_4::
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	set_invisible
	walk_left
	walk_left
	step_end

AzaleaTown_EventScript_Trigger4_6::
	msgbox AzaleaTown_Text_Trigger4_2, MSGBOX_NPC
	setflag 0x1068
	setflag 0x1056
	return

AzaleaTown_EventScript_Trigger5::
	call_if_set 0x1068, AzaleaTown_EventScript_Trigger4_1
	call_if_unset 0x1055, AzaleaTown_EventScript_Trigger4_1
	setflag 0x1057
	clearflag 0x1056
	release
	applymovement LOCALID_PLAYER, AzaleaTown_Movement_Trigger4_1
	delay 16
	playbgm MUS_ENCOUNTER_RIVAL, 51
	applymovement 6, AzaleaTown_Movement_Trigger5_1
	delay 128
	call AzaleaTown_EventScript_Trigger4_2
	applymovement LOCALID_PLAYER, AzaleaTown_Movement_Trigger4_3
	applymovement 6, AzaleaTown_Movement_Trigger5_2
	delay 80
	end

AzaleaTown_Movement_Trigger5_1::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

AzaleaTown_Movement_Trigger5_2::
	walk_left
	walk_left
	walk_down
	walk_left
	set_invisible
	walk_left
	walk_left
	step_end

AzaleaTown_EventScript_Trigger6::
	call_if_set 0x1068, AzaleaTown_EventScript_Trigger4_1
	call_if_unset 0x1055, AzaleaTown_EventScript_Trigger4_1
	setflag 0x1057
	clearflag 0x1056
	release
	applymovement LOCALID_PLAYER, AzaleaTown_Movement_Trigger4_1
	delay 16
	playbgm MUS_ENCOUNTER_RIVAL, 51
	applymovement 6, AzaleaTown_Movement_Trigger6_1
	delay 112
	call AzaleaTown_EventScript_Trigger4_2
	applymovement LOCALID_PLAYER, AzaleaTown_Movement_Trigger6_2
	applymovement 6, AzaleaTown_Movement_Trigger6_3
	delay 48
	end

AzaleaTown_Movement_Trigger6_1::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

AzaleaTown_Movement_Trigger6_2::
	walk_up
	face_down_fast
	step_end

AzaleaTown_Movement_Trigger6_3::
	walk_left
	walk_left
	walk_left
	set_invisible
	walk_left
	walk_left
	step_end

AzaleaTown_EventScript_Trigger7::
	call_if_set 0x1068, AzaleaTown_EventScript_Trigger4_1
	call_if_unset 0x1055, AzaleaTown_EventScript_Trigger4_1
	setflag 0x1057
	clearflag 0x1056
	release
	applymovement LOCALID_PLAYER, AzaleaTown_Movement_Trigger4_1
	delay 16
	playbgm MUS_ENCOUNTER_RIVAL, 51
	applymovement 6, AzaleaTown_Movement_Trigger7_1
	delay 128
	call AzaleaTown_EventScript_Trigger4_2
	applymovement LOCALID_PLAYER, AzaleaTown_Movement_Trigger6_2
	applymovement 6, AzaleaTown_Movement_Trigger7_2
	delay 80
	end

AzaleaTown_Movement_Trigger7_1::
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

AzaleaTown_Movement_Trigger7_2::
	walk_left
	walk_left
	walk_up
	walk_left
	set_invisible
	walk_left
	walk_left
	step_end

AzaleaTown_EventScript_Trigger8::
	call_if_set 0x11B0, AzaleaTown_EventScript_Trigger8_1
	call_if_unset 0x1065, AzaleaTown_EventScript_Trigger8_2
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	call_if_set 0x1138, AzaleaTown_EventScript_Trigger8_3
	call_if_set 0x1139, AzaleaTown_EventScript_Trigger8_3
	call_if_set 0x113A, AzaleaTown_EventScript_Trigger8_3
	call_if_set 0x113B, AzaleaTown_EventScript_Trigger8_3
	call_if_set 0x113C, AzaleaTown_EventScript_Trigger8_3
	call_if_set 0x113D, AzaleaTown_EventScript_Trigger8_3
	call_if_set 0x113E, AzaleaTown_EventScript_Trigger8_3
	call_if_set 0x11AF, AzaleaTown_EventScript_Trigger8_3
	setflag 0x1137
	clearflag 0x1058
	release
	end

AzaleaTown_EventScript_Trigger8_1::
	release
	end

AzaleaTown_EventScript_Trigger8_2::
	setflag 0x1137
	release
	end

AzaleaTown_EventScript_Trigger8_3::
	callnative CheckSaveBlockExtStepCounter
	call_if_eq VAR_RESULT, 1, AzaleaTown_EventScript_Trigger8_4
	setflag 0x1058
	clearflag 0x1137
	release
	end

AzaleaTown_EventScript_Trigger8_4::
	setflag 0x1137
	clearflag 0x1058
	release
	end

AzaleaTown_EventScript_Trigger9::
	call_if_set 0x11AE, AzaleaTown_EventScript_Trigger8_1
	setflag 0x11AD
	release
	end

AzaleaTown_EventScript_Sign1::
	msgbox AzaleaTown_Text_Sign1, MSGBOX_AUTOCLOSE
	end

AzaleaTown_EventScript_Sign2::
	msgbox AzaleaTown_Text_Sign2, MSGBOX_AUTOCLOSE
	end

AzaleaTown_EventScript_Sign3::
	msgbox AzaleaTown_Text_Sign3, MSGBOX_AUTOCLOSE
	end

AzaleaTown_EventScript_Sign4::
	msgbox AzaleaTown_Text_Sign4, MSGBOX_AUTOCLOSE
	end

AzaleaTown_EventScript_Sign5::
	msgbox AzaleaTown_Text_Sign5, MSGBOX_AUTOCLOSE
	end

AzaleaTown_EventScript_Sign6::
	msgbox AzaleaTown_Text_Sign6, MSGBOX_AUTOCLOSE
	end

AzaleaTown_EventScript_Sign7::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox AzaleaTown_Text_Sign7, MSGBOX_NPC
	giveitem ITEM_UP_GRADE
	releaseall
	special DaisyMassageServices
	end

AzaleaTown_EventScript_Sign8::
	call_if_unset 0x1027, Route35_EventScript_Sign4_1
	setvar 0x700B, 3
	call_if_eq VAR_FACING, 2, Route35_EventScript_Sign4_2
	release
	end

@ ShinyGold: moved from data/maps/GreenPlains/scripts.inc (map removed)
GreenPlains_EventScript_Sign3_1::
	msgbox GreenPlains_Text_Sign3_2, MSGBOX_NPC
	end
