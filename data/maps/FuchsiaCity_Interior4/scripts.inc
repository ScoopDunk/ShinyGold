FuchsiaCity_Interior4_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_Interior4_OnFrame
	.byte 0

FuchsiaCity_Interior4_OnFrame::
	map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1, FuchsiaCity_Interior4_EventScript_FrameScene1
	map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 2, FuchsiaCity_Interior4_EventScript_FrameScene2
	map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3, FuchsiaCity_Interior4_EventScript_FrameScene3
	.2byte 0

FuchsiaCity_Interior4_EventScript_FrameScene1::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FuchsiaCity_Interior4_Text_FrameScene1
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_FrameScene1
	waitmovement 0
	special ExitSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
	releaseall
	end

FuchsiaCity_Interior4_EventScript_FrameScene2::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FuchsiaCity_Interior4_Text_FrameScene2_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_Interior4_EventScript_FrameScene2_1
	msgbox FuchsiaCity_Interior4_Text_FrameScene2_2
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_FrameScene1
	waitmovement 0
	special ExitSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
	releaseall
	end

FuchsiaCity_Interior4_EventScript_FrameScene3::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_FrameScene3_1
	waitmovement 0
	msgbox FuchsiaCity_Interior4_Text_FrameScene1
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_FrameScene3_2
	waitmovement 0
	special ExitSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
	releaseall
	end

FuchsiaCity_Interior4_EventScript_FrameScene2_1::
	msgbox FuchsiaCity_Interior4_Text_FrameScene2_3
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_FrameScene2
	waitmovement 0
	warp MAP_FUCHSIA_CITY_AREA1, 26, 30
	waitstate
	end

FuchsiaCity_Interior4_Movement_FrameScene1::
	walk_down
	walk_down
	step_end

FuchsiaCity_Interior4_Movement_FrameScene3_1::
	walk_down
	delay_8
	step_end

FuchsiaCity_Interior4_Movement_FrameScene3_2::
	walk_down
	walk_down
	step_end

FuchsiaCity_Interior4_Movement_FrameScene2::
	walk_up
	step_end

FuchsiaCity_Interior4_EventScript_WorkerM::
	lock
	faceplayer
	msgbox FuchsiaCity_Interior4_Text_WorkerM_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_Interior4_EventScript_WorkerM_1
	msgbox FuchsiaCity_Interior4_Text_WorkerM_2
	release
	end

FuchsiaCity_Interior4_EventScript_WorkerM_1::
	msgbox FuchsiaCity_Interior4_Text_WorkerM_3
	release
	end

FuchsiaCity_Interior4_EventScript_WorkerM2::
	msgbox FuchsiaCity_Interior4_Text_WorkerM2, MSGBOX_NPC
	end

FuchsiaCity_Interior4_EventScript_Trigger1::
	call_if_set 0x11F3, FuchsiaCity_Interior4_EventScript_Trigger1_1
	msgbox FuchsiaCity_Interior4_Text_Trigger1_1, MSGBOX_NPC
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_Trigger1_1
	delay 1
	msgbox FuchsiaCity_Interior4_Text_Trigger1_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_Trigger1_2
	delay 16
	call FuchsiaCity_Interior4_EventScript_Trigger1_2
	end

FuchsiaCity_Interior4_EventScript_Trigger1_1::
	lockall
	setvar VAR_TEMP_2, 0
	goto FuchsiaCity_Interior4_EventScript_Trigger1_3

FuchsiaCity_Interior4_EventScript_Trigger1_2::
	msgbox FuchsiaCity_Interior4_Text_Trigger1_3, MSGBOX_NPC
	delay 16
	msgbox FuchsiaCity_Interior4_Text_Trigger1_4, MSGBOX_NPC
	delay 48
	msgbox FuchsiaCity_Interior4_Text_Trigger1_5, MSGBOX_NPC
	applymovement 4, FuchsiaCity_Interior4_Movement_Trigger1_3
	applymovement 3, FuchsiaCity_Interior4_Movement_Trigger1_4
	delay 80
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_Trigger1_5
	applymovement 3, FuchsiaCity_Interior4_Movement_Trigger1_6
	applymovement 4, FuchsiaCity_Interior4_Movement_Trigger1_6
	delay 16
	setobjectxy 3, 0, 9
	setobjectxy 4, 1, 9
	setobjectxy 6, 3, 5
	setobjectxy 5, 5, 5
	playbgm MUS_ENCOUNTER_BOY, 51
	msgbox FuchsiaCity_Interior4_Text_Trigger1_6, MSGBOX_NPC
	applymovement 5, FuchsiaCity_Interior4_Movement_Trigger1_7
	applymovement 6, FuchsiaCity_Interior4_Movement_Trigger1_8
	delay 64
	setflag 0x11F3
	clearflag 0x11F4
	clearflag FLAG_SYS_POKEMON_GET
	setflag 0x856
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_Trigger1_9
	delay 48
	warp MAP_FUCHSIA_CITY, 9, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

FuchsiaCity_Interior4_EventScript_Trigger1_3::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FuchsiaCity_Interior4_Text_Trigger1_7
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmoneybox 0, 0
	msgbox FuchsiaCity_Interior4_Text_Trigger1_8, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_Interior4_EventScript_Trigger1_4
	msgbox FuchsiaCity_Interior4_Text_Trigger1_9
	goto FuchsiaCity_Interior4_EventScript_Trigger1_5

FuchsiaCity_Interior4_Movement_Trigger1_1::
	face_right
	step_end

FuchsiaCity_Interior4_Movement_Trigger1_2::
	walk_right
	step_end

FuchsiaCity_Interior4_EventScript_Trigger1_4::
	call FuchsiaCity_Interior4_EventScript_Trigger1_6
	checkmoney 0x1F4
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_Interior4_EventScript_Trigger1_7
	removemoney 0x1F4
	updatemoneybox
	msgbox FuchsiaCity_Interior4_Text_Trigger1_10
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message FuchsiaCity_Interior4_Text_Trigger1_11
	waitfanfare
	call EventScript_RestorePrevTextColor
	msgbox FuchsiaCity_Interior4_Text_Trigger1_12
	closemessage
	hidemoneybox
	call_if_eq VAR_TEMP_2, 0, FuchsiaCity_Interior4_EventScript_Trigger1_8
	call_if_eq VAR_TEMP_2, 1, FuchsiaCity_Interior4_EventScript_Trigger1_9
	call_if_eq VAR_TEMP_2, 2, FuchsiaCity_Interior4_EventScript_Trigger1_10
	special EnterSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 2
	warp MAP_FUCHSIA_CITY_AREA1, 26, 30
	waitstate
	end

FuchsiaCity_Interior4_EventScript_Trigger1_5::
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_Trigger1_10
	waitmovement 0
	releaseall
	end

FuchsiaCity_Interior4_Movement_Trigger1_3::
	walk_up
	jump_2_right
	face_up
	step_end

FuchsiaCity_Interior4_Movement_Trigger1_4::
	walk_fast_down
	walk_fast_down
	jump_2_left
	face_up
	step_end

FuchsiaCity_Interior4_Movement_Trigger1_5::
	face_down_fast
	step_end

FuchsiaCity_Interior4_Movement_Trigger1_6::
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
	face_up
	step_end

FuchsiaCity_Interior4_Movement_Trigger1_7::
	walk_fast_down
	walk_fast_down
	set_invisible
	walk_fast_down
	walk_fast_down
	step_end

FuchsiaCity_Interior4_Movement_Trigger1_8::
	walk_fast_down
	walk_fast_down
	walk_fast_right
	face_down_fast
	set_invisible
	walk_fast_down
	walk_fast_down
	step_end

FuchsiaCity_Interior4_Movement_Trigger1_9::
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

FuchsiaCity_Interior4_EventScript_Trigger1_6::
	getpartysize
	goto_if_ne VAR_RESULT, 6, EventScript_Return
	specialvar VAR_RESULT, IsThereRoomInAnyBoxForMorePokemon
	goto_if_eq VAR_RESULT, 1, EventScript_Return
	msgbox SafariZone_Text_ExcuseMeYourPCBoxIsFull
	goto FuchsiaCity_Interior4_EventScript_Trigger1_5

FuchsiaCity_Interior4_EventScript_Trigger1_7::
	msgbox FuchsiaCity_Interior4_Text_Trigger1_13
	goto FuchsiaCity_Interior4_EventScript_Trigger1_5

FuchsiaCity_Interior4_EventScript_Trigger1_8::
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_Trigger1_11
	waitmovement 0
	return

FuchsiaCity_Interior4_EventScript_Trigger1_9::
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_Trigger1_12
	waitmovement 0
	return

FuchsiaCity_Interior4_EventScript_Trigger1_10::
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_Trigger1_13
	waitmovement 0
	return

FuchsiaCity_Interior4_Movement_Trigger1_10::
	walk_down
	step_end

FuchsiaCity_Interior4_Movement_Trigger1_11::
	walk_up
	walk_up
	step_end

FuchsiaCity_Interior4_Movement_Trigger1_12::
	walk_up
	walk_left
	walk_up
	step_end

FuchsiaCity_Interior4_Movement_Trigger1_13::
	walk_up
	walk_right
	walk_up
	step_end

FuchsiaCity_Interior4_EventScript_Trigger2::
	call_if_set 0x11F3, FuchsiaCity_Interior4_EventScript_Trigger2_1
	msgbox FuchsiaCity_Interior4_Text_Trigger1_1, MSGBOX_NPC
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_Trigger1_1
	delay 1
	msgbox FuchsiaCity_Interior4_Text_Trigger1_2, MSGBOX_NPC
	delay 16
	call FuchsiaCity_Interior4_EventScript_Trigger2_2
	end

FuchsiaCity_Interior4_EventScript_Trigger2_1::
	lockall
	setvar VAR_TEMP_2, 1
	goto FuchsiaCity_Interior4_EventScript_Trigger1_3

FuchsiaCity_Interior4_EventScript_Trigger2_2::
	msgbox FuchsiaCity_Interior4_Text_Trigger1_3, MSGBOX_NPC
	delay 16
	msgbox FuchsiaCity_Interior4_Text_Trigger1_4, MSGBOX_NPC
	delay 48
	msgbox FuchsiaCity_Interior4_Text_Trigger1_5, MSGBOX_NPC
	applymovement 4, FuchsiaCity_Interior4_Movement_Trigger1_3
	applymovement 3, FuchsiaCity_Interior4_Movement_Trigger1_4
	delay 80
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_Trigger1_5
	applymovement 3, FuchsiaCity_Interior4_Movement_Trigger1_6
	applymovement 4, FuchsiaCity_Interior4_Movement_Trigger1_6
	delay 16
	setobjectxy 3, 0, 9
	setobjectxy 4, 1, 9
	setobjectxy 6, 3, 5
	setobjectxy 5, 5, 5
	playbgm MUS_ENCOUNTER_BOY, 51
	msgbox FuchsiaCity_Interior4_Text_Trigger1_6, MSGBOX_NPC
	applymovement 5, FuchsiaCity_Interior4_Movement_Trigger1_7
	applymovement 6, FuchsiaCity_Interior4_Movement_Trigger1_8
	delay 64
	setflag 0x11F3
	clearflag 0x11F4
	clearflag FLAG_SYS_POKEMON_GET
	setflag 0x856
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_Trigger1_9
	delay 48
	warp MAP_FUCHSIA_CITY, 18, 8
	waitstate
	end

FuchsiaCity_Interior4_EventScript_Trigger3::
	call_if_set 0x11F3, FuchsiaCity_Interior4_EventScript_Trigger3_1
	msgbox FuchsiaCity_Interior4_Text_Trigger1_1, MSGBOX_NPC
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_Trigger1_1
	delay 1
	msgbox FuchsiaCity_Interior4_Text_Trigger1_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, FuchsiaCity_Interior4_Movement_Trigger3
	delay 32
	call FuchsiaCity_Interior4_EventScript_Trigger2_2
	end

FuchsiaCity_Interior4_EventScript_Trigger3_1::
	lockall
	setvar VAR_TEMP_2, 2
	goto FuchsiaCity_Interior4_EventScript_Trigger1_3

FuchsiaCity_Interior4_Movement_Trigger3::
	walk_right
	walk_right
	step_end
