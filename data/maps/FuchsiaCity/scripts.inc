FuchsiaCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_OnFrame
	.byte 0

FuchsiaCity_OnFrame::
	map_script_2 0x7048, 0, FuchsiaCity_EventScript_FrameScene
	.2byte 0

FuchsiaCity_EventScript_FrameScene::
	call CeruleanCity_EventScript_Trigger1
	setflag 0x1367
	setvar 0x7048, 1
	call NewBarkTown_EventScript_FrameScene_1
	end

FuchsiaCity_EventScript_Camper::
	msgbox FuchsiaCity_Text_Camper, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Woman2::
	msgbox FuchsiaCity_Text_Woman2, MSGBOX_NPC
	end

FuchsiaCity_EventScript_ItemRepeatBall::
	finditem ITEM_REPEAT_BALL
	end

FuchsiaCity_EventScript_BaldingMan::
	msgbox FuchsiaCity_Text_BaldingMan, MSGBOX_NPC
	end

FuchsiaCity_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

FuchsiaCity_EventScript_CutTree::
	call_if_set 0x11F5, EventScript_CutTree
	call_if_set 0x11F3, FuchsiaCity_EventScript_CutTree_1
	call EventScript_CutTree
	end

FuchsiaCity_EventScript_CutTree_1::
	msgbox FuchsiaCity_Text_CutTree, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_EventScript_CutTree2::
	call_if_set 0x11F5, EventScript_CutTree
	call_if_set 0x11F6, FuchsiaCity_EventScript_CutTree2_1
	call_if_set 0x11F3, FuchsiaCity_EventScript_CutTree2_2
	call EventScript_CutTree

FuchsiaCity_EventScript_CutTree2_2::
	msgbox FuchsiaCity_Text_CutTree, MSGBOX_AUTOCLOSE
	setflag 0x11F6
	release
	end

FuchsiaCity_EventScript_CutTree2_1::
	msgbox FuchsiaCity_Text_CutTree2_1, MSGBOX_AUTOCLOSE
	delay 80
	msgbox FuchsiaCity_Text_CutTree2_2, MSGBOX_NPC
	applymovement 8, FuchsiaCity_Movement_CutTree2_1
	delay 160
	msgbox FuchsiaCity_Text_CutTree2_3, MSGBOX_NPC
	msgbox FuchsiaCity_Text_CutTree2_4, MSGBOX_NPC
	delay 16
	msgbox FuchsiaCity_Text_CutTree2_5, MSGBOX_NPC
	setobjectxy 7, 46, 0
	applymovement LOCALID_PLAYER, FuchsiaCity_Movement_CutTree2_2
	delay 16
	msgbox FuchsiaCity_Text_CutTree2_6, MSGBOX_NPC
	applymovement 8, FuchsiaCity_Movement_CutTree2_3
	delay 1
	delay 32
	special StartDroughtWeatherBlend
	delay 80
	special StartDroughtWeatherBlend
	delay 112
	applymovement 8, FuchsiaCity_Movement_CutTree2_4
	delay 1
	msgbox FuchsiaCity_Text_CutTree2_7, MSGBOX_NPC
	applymovement 8, FuchsiaCity_Movement_CutTree2_5
	applymovement LOCALID_PLAYER, FuchsiaCity_Movement_CutTree2_6
	delay 128
	delay 80
	warp MAP_ROUTE15_INTERIOR1, 1, 0x26C, 227
	.byte 0xD8 @ invalid opcode (script stops)

FuchsiaCity_Movement_CutTree2_1::
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

FuchsiaCity_Movement_CutTree2_2::
	walk_down
	step_end

FuchsiaCity_Movement_CutTree2_3::
	face_down_fast
	step_end

FuchsiaCity_Movement_CutTree2_4::
	face_up
	step_end

FuchsiaCity_Movement_CutTree2_5::
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
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	set_invisible
	walk_fast_right
	walk_fast_right
	step_end

FuchsiaCity_Movement_CutTree2_6::
	walk_fast_down
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
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

FuchsiaCity_EventScript_Trigger1::
	call_if_set 0x11F3, FuchsiaCity_EventScript_Trigger1_1
	setflag 0x11F2
	setflag 0x11F4
	release
	end

FuchsiaCity_EventScript_Trigger1_1::
	release
	end

FuchsiaCity_EventScript_Trigger4::
	call_if_set 0x11F5, FuchsiaCity_EventScript_Trigger4_1
	call_if_set 0x11F3, FuchsiaCity_EventScript_Trigger4_2
	release
	end

FuchsiaCity_EventScript_Trigger4_1::
	release
	end

FuchsiaCity_EventScript_Trigger4_2::
	msgbox FuchsiaCity_Text_Trigger4, MSGBOX_NPC
	applymovement LOCALID_PLAYER, FuchsiaCity_Movement_Trigger4
	delay 16
	end

FuchsiaCity_Movement_Trigger4::
	walk_down
	step_end

FuchsiaCity_EventScript_Sign1::
	msgbox FuchsiaCity_Text_Sign1, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_EventScript_Sign2::
	msgbox FuchsiaCity_Text_Sign2, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_EventScript_Sign3::
	msgbox FuchsiaCity_Text_Sign3, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_EventScript_Sign4::
	msgbox FuchsiaCity_Text_Sign4, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_EventScript_Sign5::
	msgbox FuchsiaCity_Text_Sign5, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_EventScript_Sign7::
	msgbox FuchsiaCity_Text_Sign7, MSGBOX_AUTOCLOSE
	end
