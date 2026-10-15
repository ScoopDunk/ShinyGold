VioletCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VioletCity_OnFrame
	.byte 0

VioletCity_OnFrame::
	map_script_2 0x7022, 0, VioletCity_EventScript_FrameScene
	.2byte 0

VioletCity_EventScript_FrameScene::
	setflag 0x136C
	call NewBarkTown_EventScript_FrameScene_1
	setvar 0x7022, 1
	call VioletCity_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

VioletCity_EventScript_FrameScene_1::
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
	setvar 0x7023, 0
	setvar 0x7024, 0
	setvar 0x7025, 0
	setvar 0x7026, 0
	setvar 0x7027, 0
	setvar 0x7028, 0
	return

VioletCity_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION
	end

VioletCity_EventScript_OldMan1::
	msgbox VioletCity_Text_OldMan1, MSGBOX_NPC
	end

VioletCity_EventScript_Beauty::
	lock
	faceplayer
	setvar VAR_0x8004, 10
	setvar VAR_0x8005, 4
	special SetFlavorTextFlagFromSpecialVars
	msgbox VioletCity_Text_Beauty
	release
	end

VioletCity_EventScript_FatMan::
	applymovement 4, VioletCity_Movement_FatMan_1
	delay 32
	msgbox VioletCity_Text_FatMan_1, MSGBOX_NPC
	msgbox VioletCity_Text_FatMan_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, VioletCity_EventScript_FatMan_1
	msgbox VioletCity_Text_FatMan_3, MSGBOX_NPC
	playbgm MUS_FOLLOW_ME, 51
	applymovement 4, VioletCity_Movement_FatMan_2
	applymovement LOCALID_PLAYER, VioletCity_Movement_FatMan_2
	delay 192
	playbgm MUS_SEVII_67, 51
	applymovement 4, VioletCity_Movement_FatMan_3
	applymovement LOCALID_PLAYER, VioletCity_Movement_FatMan_4
	delay 2
	msgbox VioletCity_Text_FatMan_4, MSGBOX_NPC
	applymovement 4, VioletCity_Movement_FatMan_5
	delay 64
	setflag 0x11D3
	clearflag 0x11D4
	release
	end

VioletCity_EventScript_FatMan_1::
	msgbox VioletCity_Text_FatMan_5, MSGBOX_NPC
	end

VioletCity_Movement_FatMan_1::
	face_up
	face_left
	face_down_fast
	face_right
	face_up
	face_left
	face_down_fast
	face_right
	face_up
	face_left
	face_down_fast
	face_right
	face_player
	step_end

VioletCity_Movement_FatMan_2::
	walk_fast_down
	walk_fast_down
	face_up
	face_left
	face_down_fast
	face_right
	face_up
	face_left
	face_down_fast
	face_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_up
	face_left
	face_down_fast
	face_right
	face_up
	face_left
	face_down_fast
	face_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_up
	face_left
	face_down_fast
	face_right
	face_up
	face_left
	face_down_fast
	face_right
	step_end

VioletCity_Movement_FatMan_3::
	face_player
	step_end

VioletCity_Movement_FatMan_4::
	face_up
	step_end

VioletCity_Movement_FatMan_5::
	face_up
	face_left
	face_down_fast
	face_right
	face_up
	face_left
	face_down_fast
	face_right
	walk_up
	set_invisible
	walk_up
	step_end

VioletCity_EventScript_Youngster::
	msgbox VioletCity_Text_Youngster, MSGBOX_NPC
	end

VioletCity_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

VioletCity_EventScript_ItemPpUp::
	finditem ITEM_PP_UP
	end

VioletCity_EventScript_Boy::
	msgbox VioletCity_Text_Boy, MSGBOX_NPC
	end

VioletCity_EventScript_WorkerF::
	call_if_set 0x1240, VioletCity_EventScript_WorkerF_1
	msgbox VioletCity_Text_WorkerF_1, MSGBOX_NPC
	giveitem ITEM_SHARP_BEAK
	msgbox VioletCity_Text_WorkerF_2, MSGBOX_NPC
	setflag 0x1240
	clearflag 0x1241
	release
	end

VioletCity_EventScript_WorkerF_1::
	msgbox VioletCity_Text_WorkerF_3, MSGBOX_NPC
	end

VioletCity_EventScript_Trigger1::
	call_if_set 0x11D3, VioletCity_EventScript_Trigger1_1
	setflag 0x11D4
	release
	end

VioletCity_EventScript_Trigger1_1::
	release
	end

VioletCity_EventScript_Trigger2::
	call_if_unset FLAG_BADGE01_GET, VioletCity_EventScript_Trigger2_1
	call_if_set 0x1042, VioletCity_EventScript_Trigger2_1
	call Route30_EventScript_Trigger3_2
	msgbox VioletCity_Text_Trigger2, MSGBOX_NPC
	setflag 0x1042
	setflag 0x1043
	clearflag 0x1044
	release
	end

VioletCity_EventScript_Trigger2_1::
	release
	end

VioletCity_EventScript_Trigger5::
	call_if_set 0x1043, VioletCity_EventScript_Trigger5_1
	setflag 0x1044
	setflag 0x1241
	setflag 0x1242
	setflag 0x1243
	setflag 0x1244
	setflag 0x1245
	setflag 0x1246
	release
	end

VioletCity_EventScript_Trigger5_1::
	release
	end

VioletCity_EventScript_Sign1::
	msgbox VioletCity_Text_Sign1, MSGBOX_SIGN
	end

VioletCity_EventScript_Sign2::
	msgbox VioletCity_Text_Sign2, MSGBOX_SIGN
	end

VioletCity_EventScript_Sign3::
	msgbox VioletCity_Text_Sign3, MSGBOX_SIGN
	end

VioletCity_EventScript_Sign4::
	msgbox VioletCity_Text_Sign4, MSGBOX_AUTOCLOSE
	end

VioletCity_EventScript_Sign5::
	call_if_unset 0x1027, Route35_EventScript_Sign4_1
	setvar 0x700B, 2
	call_if_eq VAR_FACING, 2, Route35_EventScript_Sign4_2
	release
	end
