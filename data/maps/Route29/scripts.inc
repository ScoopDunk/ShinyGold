Route29_MapScripts::
	@ ShinyGold: overlapping data duplicated from 0x0816876B
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route29_OnFrame
	.byte 0

Route29_OnFrame::
	map_script_2 0x7010, 0, Route29_EventScript_FrameScene
	.2byte 0

Route29_EventScript_FrameScene::
	setvar 0x7010, 1
	call Route29_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

Route29_EventScript_FrameScene_1::
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
	setvar 0x7026, 0
	setvar 0x7027, 0
	setvar 0x7028, 0
	return

Route29_EventScript_Trigger1::
	goto_if_set 0x1007, Unused_G2_M68_EventScript_Trigger1_1
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Unused_G2_M68_Text_Trigger1_1, MSGBOX_NPC
	applymovement 2, Route29_Movement_Trigger1_1
	delay 144
	call Route44_EventScript_PkmnTrainerCarlos3_1
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_194, 0, Unused_G2_M68_Text_Trigger1Defeat, Unused_G2_M68_Text_Trigger1Defeat
	setflag 0x1007
	delay 32
	call Route44_EventScript_PkmnTrainerCarlos3_2
	msgbox Unused_G2_M68_Text_Trigger1_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Route29_Movement_Trigger1_2
	applymovement 2, Unused_G2_M68_Movement_Trigger1_3
	delay 224
	release
	end

Route29_Movement_Trigger1_1::
	walk_fast_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route29_Movement_Trigger1_2::
	walk_down
	face_up
	step_end

Route29_EventScript_Trigger2::
	goto_if_set 0x1007, Unused_G2_M68_EventScript_Trigger1_1
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Unused_G2_M68_Text_Trigger1_1, MSGBOX_NPC
	applymovement 2, Unused_G2_M68_Movement_Trigger1_1
	delay 144
	call Route44_EventScript_PkmnTrainerCarlos3_1
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_194, 0, Unused_G2_M68_Text_Trigger1Defeat, Unused_G2_M68_Text_Trigger1Defeat
	setflag 0x1007
	delay 32
	call Route44_EventScript_PkmnTrainerCarlos3_2
	msgbox Unused_G2_M68_Text_Trigger1_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Unused_G2_M68_Movement_Trigger1_2
	applymovement 2, Unused_G2_M68_Movement_Trigger1_3
	delay 224
	release
	end
