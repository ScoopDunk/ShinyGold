OlivineCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OlivineCity_OnFrame
	.byte 0

OlivineCity_OnFrame::
	map_script_2 0x7026, 0, OlivineCity_EventScript_FrameScene
	.2byte 0

OlivineCity_EventScript_FrameScene::
	setflag 0x1371
	call NewBarkTown_EventScript_FrameScene_1
	setvar 0x7026, 1
	call OlivineCity_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

OlivineCity_EventScript_FrameScene_1::
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
	setvar 0x7024, 0
	setvar 0x7025, 0
	setvar 0x7027, 0
	setvar 0x7028, 0
	return

OlivineCity_EventScript_RsBrendan::
	msgbox OlivineCity_Text_RsBrendan, MSGBOX_NPC
	end

OlivineCity_EventScript_Youngster::
	msgbox OlivineCity_Text_Youngster, MSGBOX_NPC
	end

OlivineCity_EventScript_Sailor::
	msgbox OlivineCity_Text_Sailor, MSGBOX_NPC
	end

OlivineCity_EventScript_Sailor2::
	msgbox OlivineCity_Text_Sailor2, MSGBOX_NPC
	end

OlivineCity_EventScript_Trigger1::
	call_if_set 0x10C5, OlivineCity_EventScript_Trigger1_1
	playbgm MUS_ENCOUNTER_RIVAL, 51
	applymovement LOCALID_PLAYER, OlivineCity_Movement_Trigger1_1
	applymovement 1, OlivineCity_Movement_Trigger1_2
	delay 32
	call OlivineCity_EventScript_Trigger1_2
	end

OlivineCity_EventScript_Trigger1_1::
	release
	end

OlivineCity_EventScript_Trigger1_2::
	setflag 0x10C5
	msgbox OlivineCity_Text_Trigger1, MSGBOX_NPC
	applymovement 1, OlivineCity_Movement_Trigger1_3
	delay 240
	playbgm MUS_SEVII_67, 51
	release
	end

OlivineCity_Movement_Trigger1_1::
	emote_exclamation_mark
	step_end

OlivineCity_Movement_Trigger1_2::
	walk_right
	walk_right
	step_end

OlivineCity_Movement_Trigger1_3::
	@ ShinyGold: overlapping data duplicated from 0x0877974F
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	set_invisible
	walk_fast_left
	walk_fast_left
	.byte 0xAD
	.byte 0xAD
	.byte 0xAD
	.byte 0xFB
	.byte 0xD3
	.byte 0xE3
	.byte 0xE9
	face_down
	.byte 0xD5
	.byte 0xDB
	.byte 0xD5
	.byte 0xDD
	.byte 0xE2
	.byte 0xAC
	.byte 0xFB
	.byte 0xCE
	.byte 0xDC
	.byte 0xD9
	.byte 0xE6
	.byte 0xD9
	.byte 0xB4
	.byte 0xE7
	face_down
	.byte 0xE2
	.byte 0xE3
	face_down
	.byte 0xE2
	.byte 0xD9
	.byte 0xD9
	.byte 0xD8
	face_down
	.byte 0xE8
	.byte 0xE3
	face_down
	.byte 0xE4
	.byte 0xD5
	.byte 0xE2
	.byte 0xDD
	.byte 0xD7
	.byte 0xAD
	face_down
	.byte 0xC3
	face_down
	.byte 0xD8
	.byte 0xE3
	.byte 0xE2
	.byte 0xB4
	.byte 0xE8
	step_end

OlivineCity_EventScript_Trigger2::
	call_if_set 0x10C5, OlivineCity_EventScript_Trigger1_1
	playbgm MUS_ENCOUNTER_RIVAL, 51
	applymovement LOCALID_PLAYER, OlivineCity_Movement_Trigger1_1
	applymovement 1, OlivineCity_Movement_Trigger2_1
	delay 48
	call OlivineCity_EventScript_Trigger2_1
	end

OlivineCity_EventScript_Trigger2_1::
	setflag 0x10C5
	msgbox OlivineCity_Text_Trigger1, MSGBOX_NPC
	applymovement 1, OlivineCity_Movement_Trigger2_2
	delay 240
	playbgm MUS_SEVII_67, 51
	release
	end

OlivineCity_Movement_Trigger2_1::
	walk_down
	walk_right
	walk_right
	step_end

OlivineCity_Movement_Trigger2_2::
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	set_invisible
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

OlivineCity_EventScript_Trigger3::
	call_if_set 0x10CF, OlivineCity_EventScript_Trigger3_1
	setflag 0x10C8
	release
	end

OlivineCity_EventScript_Trigger3_1::
	release
	end

OlivineCity_EventScript_Sign1::
	msgbox OlivineCity_Text_Sign1, MSGBOX_AUTOCLOSE
	end

OlivineCity_EventScript_Sign2::
	msgbox OlivineCity_Text_Sign2, MSGBOX_AUTOCLOSE
	end

OlivineCity_EventScript_Sign3::
	msgbox OlivineCity_Text_Sign3, MSGBOX_AUTOCLOSE
	end

OlivineCity_EventScript_Sign4::
	msgbox OlivineCity_Text_Sign4, MSGBOX_AUTOCLOSE
	end
