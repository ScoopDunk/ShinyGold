Unused_SevenIsland_House_Room2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Unused_SevenIsland_House_Room2_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Unused_SevenIsland_House_Room2_OnFrame
	.byte 0

Unused_SevenIsland_House_Room2_OnTransition::
	special SetEReaderTrainerGfxId
	end

Unused_SevenIsland_House_Room2_OnFrame::
	map_script_2 VAR_TEMP_1, 0, Unused_SevenIsland_House_Room2_EventScript_FrameScene
	.2byte 0

Unused_SevenIsland_House_Room2_EventScript_FrameScene::
	lockall
	applymovement LOCALID_PLAYER, Unused_SevenIsland_House_Room2_Movement_FrameScene_1
	waitmovement 0
	special BufferEReaderTrainerGreeting
	loadword 0, gStringVar4
	callstd MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	special StartSpecialBattle
	waitstate
	call_if_eq VAR_RESULT, 3, Unused_SevenIsland_House_Room2_EventScript_FrameScene_1
	call_if_eq VAR_RESULT, 1, Unused_SevenIsland_House_Room2_EventScript_FrameScene_2
	call_if_eq VAR_RESULT, 2, Unused_SevenIsland_House_Room2_EventScript_FrameScene_3
	closemessage
	special HealPlayerParty
	applymovement LOCALID_PLAYER, Unused_SevenIsland_House_Room2_Movement_FrameScene_2
	waitmovement 0
	special LoadPlayerParty
	setvar VAR_TEMP_1, 1
	warp MAP_PURITY_FOREST_INTERIOR12, 4, 1
	waitstate
	releaseall
	end

Unused_SevenIsland_House_Room2_EventScript_FrameScene_1::
	setvar 0x4074, 3
	msgbox Unused_SevenIsland_House_Room2_Text_FrameScene
	return

Unused_SevenIsland_House_Room2_EventScript_FrameScene_2::
	setvar 0x4074, 1
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	return

Unused_SevenIsland_House_Room2_EventScript_FrameScene_3::
	setvar 0x4074, 2
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	return

Unused_SevenIsland_House_Room2_Movement_FrameScene_1::
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

Unused_SevenIsland_House_Room2_Movement_FrameScene_2::
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end
