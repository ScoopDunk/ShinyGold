CinnabarIsland_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CinnabarIsland_OnFrame
	.byte 0

CinnabarIsland_OnFrame::
	map_script_2 0x7049, 0, CinnabarIsland_EventScript_FrameScene
	.2byte 0

CinnabarIsland_EventScript_FrameScene::
	setflag 0x1368
	setvar 0x7049, 1
	call NewBarkTown_EventScript_FrameScene_1
	end

CinnabarIsland_EventScript_Blue::
	msgbox CinnabarIsland_Text_Blue, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	setflag 0x055
	clearflag 0x06B
	removeobject 1
	fadescreen FADE_FROM_BLACK
	release
	end

CinnabarIsland_EventScript_OldMan1::
	msgbox CinnabarIsland_Text_OldMan1, MSGBOX_NPC
	end

CinnabarIsland_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

CinnabarIsland_EventScript_Trigger::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	msgbox CinnabarIsland_Text_Trigger
	closemessage
	applymovement LOCALID_PLAYER, CinnabarIsland_Movement_Trigger
	waitmovement 0
	releaseall
	end

CinnabarIsland_Movement_Trigger::
	walk_down
	step_end

CinnabarIsland_EventScript_Sign1::
	msgbox CinnabarIsland_Text_Sign1, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_Sign2::
	msgbox CinnabarIsland_Text_Sign2, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_Sign3::
	msgbox CinnabarIsland_Text_Sign3, MSGBOX_SIGN
	end
