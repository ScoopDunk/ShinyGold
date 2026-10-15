MahoganyTown_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MahoganyTown_OnFrame
	.byte 0

MahoganyTown_OnFrame::
	map_script_2 0x7027, 0, MahoganyTown_EventScript_FrameScene
	.2byte 0

MahoganyTown_EventScript_FrameScene::
	setflag 0x1373
	call NewBarkTown_EventScript_FrameScene_1
	call SlowpokeWell_Cave1_EventScript_TeamRocketGrunt_1
	setvar 0x7027, 1
	call MahoganyTown_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

MahoganyTown_EventScript_FrameScene_1::
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
	setvar 0x7026, 0
	setvar 0x7028, 0
	return

MahoganyTown_EventScript_FatMan::
	msgbox MahoganyTown_Text_FatMan, MSGBOX_NPC
	end

MahoganyTown_EventScript_OldMan1::
	msgbox MahoganyTown_Text_OldMan1, MSGBOX_NPC
	end

MahoganyTown_EventScript_BaldingMan::
	showmoneybox 0, 0
	lock
	faceplayer
	msgbox MahoganyTown_Text_BaldingMan_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, MahoganyTown_EventScript_BaldingMan_1
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	nop
	nop1
	releaseall
	return

MahoganyTown_EventScript_BaldingMan_1::
	checkmoney 0x12C
	call_if_eq VAR_RESULT, 0, MahoganyTown_EventScript_BaldingMan_2
	removemoney 0x12C
	updatemoneybox
	msgbox MahoganyTown_Text_BaldingMan_2, MSGBOX_NPC
	giveitem ITEM_FIGY_BERRY
	textcolor 104
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	releaseall
	return

MahoganyTown_EventScript_BaldingMan_2::
	msgbox MahoganyTown_Text_BaldingMan_3, MSGBOX_NPC
	textcolor 104
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	releaseall
	applymovement 3, MahoganyTown_Movement_BaldingMan
	delay 16
	end

MahoganyTown_Movement_BaldingMan::
	walk_fast_up
	face_down_fast
	step_end

MahoganyTown_EventScript_CrushGirl::
	msgbox MahoganyTown_Text_CrushGirl_1, MSGBOX_NPC
	msgbox MahoganyTown_Text_CrushGirl_2, MSGBOX_NPC
	giveitem ITEM_SUPER_POTION, 5
	giveitem ITEM_HYPER_POTION, 2
	giveitem ITEM_ETHER, 2
	giveitem ITEM_REVIVE
	msgbox MahoganyTown_Text_CrushGirl_3, MSGBOX_NPC
	call_if_eq VAR_TEMP_1, 1, MahoganyTown_EventScript_CrushGirl_1
	call_if_eq VAR_TEMP_1, 2, MahoganyTown_EventScript_CrushGirl_2
	end

MahoganyTown_EventScript_CrushGirl_1::
	setflag 0x10E3
	applymovement 4, MahoganyTown_Movement_CrushGirl_1
	delay 144
	end

MahoganyTown_EventScript_CrushGirl_2::
	setflag 0x10E3
	applymovement 4, MahoganyTown_Movement_CrushGirl_2
	delay 160
	end

MahoganyTown_Movement_CrushGirl_1::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	set_invisible
	walk_fast_up
	walk_fast_up
	step_end

MahoganyTown_Movement_CrushGirl_2::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	set_invisible
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

MahoganyTown_EventScript_Lass::
	msgbox MahoganyTown_Text_Lass, MSGBOX_NPC
	end

MahoganyTown_EventScript_Trigger1::
	call_if_set 0x110A, MahoganyTown_EventScript_Trigger1_1
	applymovement 3, MahoganyTown_Movement_Trigger1_1
	delay 32
	applymovement 3, MahoganyTown_Movement_Trigger1_2
	delay 32
	applymovement 3, MahoganyTown_Movement_Trigger1_3
	applymovement LOCALID_PLAYER, MahoganyTown_Movement_Trigger1_4
	delay 32
	call MahoganyTown_EventScript_BaldingMan
	applymovement 3, MahoganyTown_Movement_BaldingMan
	delay 16
	end

MahoganyTown_EventScript_Trigger1_1::
	release
	end

MahoganyTown_Movement_Trigger1_1::
	emote_exclamation_mark
	step_end

MahoganyTown_Movement_Trigger1_2::
	walk_fast_right
	walk_fast_down
	face_left
	step_end

MahoganyTown_Movement_Trigger1_3::
	walk_left
	step_end

MahoganyTown_Movement_Trigger1_4::
	walk_left
	face_right
	step_end

MahoganyTown_EventScript_Trigger2::
	setvar VAR_TEMP_1, 1
	release
	end

MahoganyTown_EventScript_Trigger4::
	setvar VAR_TEMP_1, 2
	release
	end

MahoganyTown_EventScript_Sign1::
	msgbox MahoganyTown_Text_Sign1, MSGBOX_AUTOCLOSE
	end

MahoganyTown_EventScript_Sign2::
	msgbox MahoganyTown_Text_Sign2, MSGBOX_AUTOCLOSE
	end

MahoganyTown_EventScript_Sign3::
	msgbox MahoganyTown_Text_Sign3, MSGBOX_AUTOCLOSE
	end
