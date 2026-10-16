NewBarkTown_Interior3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Interior3_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NewBarkTown_Interior3_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Interior3_OnFrame
	.byte 0

NewBarkTown_Interior3_OnTransition::
	setflag FLAG_VISITED_OAKS_LAB
	call_if_eq 0x4055, 1, NewBarkTown_Interior3_EventScript_OnTransition_1
	call_if_eq 0x4055, 7, NewBarkTown_Interior3_EventScript_OnTransition_2
	call_if_eq 0x4055, 8, NewBarkTown_Interior3_EventScript_OnTransition_3
	call_if_set 0x247, NewBarkTown_Interior3_EventScript_OnTransition_4
	end

NewBarkTown_Interior3_EventScript_OnTransition_1::
	setobjectxyperm 4, 6, 11
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_UP
	savebgm MUS_OAK
	return

NewBarkTown_Interior3_EventScript_OnTransition_2::
	setobjectxyperm 4, 6, 11
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_UP
	return

NewBarkTown_Interior3_EventScript_OnTransition_3::
	setvar 0x4055, 9
	return

NewBarkTown_Interior3_EventScript_OnTransition_4::
	setflag 0x24F
	return

NewBarkTown_Interior3_OnWarp::
	map_script_2 0x4055, 1, NewBarkTown_Interior3_EventScript_WarpScene
	.2byte 0

NewBarkTown_Interior3_EventScript_WarpScene::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

NewBarkTown_Interior3_OnFrame::
	map_script_2 0x4055, 1, NewBarkTown_Interior3_EventScript_FrameScene1
	map_script_2 0x4055, 7, NewBarkTown_Interior3_EventScript_FrameScene2
	.2byte 0

NewBarkTown_Interior3_EventScript_FrameScene1::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement 4, NewBarkTown_Interior3_Movement_FrameScene1_1
	waitmovement 0
	removeobject 4
	setobjectxyperm 4, 6, 3
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
	clearflag 0x02B
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_FrameScene1_2
	waitmovement 0
	applymovement 8, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	clearflag FLAG_DONT_TRANSITION_MUSIC
	savebgm MUS_DUMMY
	fadedefaultbgm
	msgbox NewBarkTown_Interior3_Text_FrameScene1_1
	closemessage
	delay 60
	msgbox NewBarkTown_Interior3_Text_FrameScene1_2
	closemessage
	delay 30
	applymovement 8, NewBarkTown_Interior3_Movement_FrameScene1_3
	waitmovement 0
	msgbox NewBarkTown_Interior3_Text_FrameScene1_3
	msgbox NewBarkTown_Interior3_Text_FrameScene1_4
	setvar 0x4055, 2
	releaseall
	end

NewBarkTown_Interior3_EventScript_FrameScene2::
	lockall
	setvar VAR_FACING, 2
	textcolor NPC_TEXT_COLOR_MALE
	applymovement 4, NewBarkTown_Interior3_Movement_FrameScene1_1
	waitmovement 0
	removeobject 4
	setobjectxyperm 4, 6, 3
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
	clearflag 0x02B
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_FrameScene1_2
	waitmovement 0
	goto NewBarkTown_Interior3_EventScript_FrameScene2_1

NewBarkTown_Interior3_EventScript_FrameScene2_1::
	msgbox NewBarkTown_Interior3_Text_FrameScene2_1
	closemessage
	call_if_eq VAR_FACING, 2, NewBarkTown_Interior3_EventScript_FrameScene2_2
	call_if_eq VAR_FACING, 1, NewBarkTown_Interior3_EventScript_FrameScene2_3
	call_if_eq VAR_FACING, 4, NewBarkTown_Interior3_EventScript_FrameScene2_4
	call_if_eq VAR_FACING, 3, NewBarkTown_Interior3_EventScript_FrameScene2_4
	msgbox NewBarkTown_Interior3_Text_FrameScene2_2
	fadedefaultbgm
	msgbox NewBarkTown_Interior3_Text_FrameScene2_3
	call_if_eq VAR_FACING, 2, NewBarkTown_Interior3_EventScript_FrameScene2_5
	call_if_eq VAR_FACING, 3, NewBarkTown_Interior3_EventScript_FrameScene2_6
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox NewBarkTown_Interior3_Text_FrameScene2_4
	closemessage
	call EventScript_RestorePrevTextColor
	call_if_eq VAR_FACING, 2, NewBarkTown_Interior3_EventScript_FrameScene2_7
	call_if_eq VAR_FACING, 1, NewBarkTown_Interior3_EventScript_FrameScene2_8
	call_if_eq VAR_FACING, 4, NewBarkTown_Interior3_EventScript_FrameScene2_9
	call_if_eq VAR_FACING, 3, NewBarkTown_Interior3_EventScript_FrameScene2_10
	addobject 9
	addobject 10
	delay 30
	msgbox NewBarkTown_Interior3_Text_FrameScene2_5
	closemessage
	removeobject 9
	removeobject 10
	delay 30
	call_if_eq VAR_FACING, 2, NewBarkTown_Interior3_EventScript_FrameScene2_11
	call_if_eq VAR_FACING, 1, NewBarkTown_Interior3_EventScript_FrameScene2_12
	call_if_eq VAR_FACING, 4, NewBarkTown_Interior3_EventScript_FrameScene2_13
	call_if_eq VAR_FACING, 3, NewBarkTown_Interior3_EventScript_FrameScene2_14
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_KEY_ITEM
	message NewBarkTown_Interior3_Text_FrameScene2_6
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	special EnableNationalPokedex
	msgbox NewBarkTown_Interior3_Text_FrameScene2_7
	msgbox NewBarkTown_Interior3_Text_FrameScene2_8
	closemessage
	playbgm MUS_RIVAL_EXIT, 0
	call_if_eq VAR_FACING, 2, NewBarkTown_Interior3_EventScript_FrameScene2_15
	call_if_eq VAR_FACING, 1, NewBarkTown_Interior3_EventScript_FrameScene2_16
	call_if_eq VAR_FACING, 4, NewBarkTown_Interior3_EventScript_FrameScene2_16
	call_if_eq VAR_FACING, 3, NewBarkTown_Interior3_EventScript_FrameScene2_16
	removeobject 8
	fadedefaultbgm
	setvar 0x4055, 8
	releaseall
	end

NewBarkTown_Interior3_Movement_FrameScene1_1::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Interior3_Movement_FrameScene1_2::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Interior3_Movement_FrameScene1_3::
	walk_in_place_up
	walk_in_place_up
	step_end

NewBarkTown_Interior3_EventScript_FrameScene2_2::
	setobjectxyperm 8, 5, 10
	addobject 8
	playbgm MUS_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_FrameScene2_1
	applymovement 8, NewBarkTown_Interior3_Movement_FrameScene2_2
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_FrameScene2_3::
	setobjectxyperm 8, 6, 10
	addobject 8
	playbgm MUS_ENCOUNTER_RIVAL, 0
	applymovement 4, Common_Movement_WalkInPlaceFasterDown
	applymovement 8, NewBarkTown_Interior3_Movement_FrameScene2_2
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_FrameScene2_4::
	setobjectxyperm 8, 6, 10
	addobject 8
	playbgm MUS_ENCOUNTER_RIVAL, 0
	applymovement 4, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_FrameScene2_3
	applymovement 8, NewBarkTown_Interior3_Movement_FrameScene2_2
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_FrameScene2_5::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_FrameScene2_6::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_FrameScene2_7::
	applymovement 4, NewBarkTown_Interior3_Movement_FrameScene2_4
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_FrameScene2_8::
	applymovement 4, NewBarkTown_Interior3_Movement_FrameScene2_5
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_FrameScene2_6
	applymovement 8, NewBarkTown_Interior3_Movement_FrameScene2_6
	waitmovement 4
	return

NewBarkTown_Interior3_EventScript_FrameScene2_9::
	applymovement 4, NewBarkTown_Interior3_Movement_FrameScene2_4
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_FrameScene2_7
	waitmovement 4
	return

NewBarkTown_Interior3_EventScript_FrameScene2_10::
	applymovement 4, NewBarkTown_Interior3_Movement_FrameScene2_4
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_FrameScene2_11::
	applymovement 4, NewBarkTown_Interior3_Movement_FrameScene2_8
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_FrameScene2_12::
	applymovement 4, NewBarkTown_Interior3_Movement_FrameScene2_9
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_FrameScene2_13::
	applymovement 4, NewBarkTown_Interior3_Movement_FrameScene2_8
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_FrameScene2_10
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_FrameScene2_14::
	applymovement 4, NewBarkTown_Interior3_Movement_FrameScene2_8
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_FrameScene2_15::
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_FrameScene2_3
	applymovement 8, NewBarkTown_Interior3_Movement_FrameScene2_11
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_FrameScene2_16::
	applymovement 8, NewBarkTown_Interior3_Movement_FrameScene2_11
	waitmovement 0
	return

NewBarkTown_Interior3_Movement_FrameScene2_1::
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

NewBarkTown_Interior3_Movement_FrameScene2_2::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Interior3_Movement_FrameScene2_3::
	delay_4
	walk_in_place_faster_down
	step_end

NewBarkTown_Interior3_Movement_FrameScene2_4::
	walk_up
	walk_left
	walk_in_place_faster_up
	delay_16
	delay_4
	step_end

NewBarkTown_Interior3_Movement_FrameScene2_5::
	walk_left
	walk_left
	walk_up
	delay_16
	delay_4
	step_end

NewBarkTown_Interior3_Movement_FrameScene2_6::
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

NewBarkTown_Interior3_Movement_FrameScene2_7::
	delay_16
	delay_8
	walk_in_place_faster_up
	step_end

NewBarkTown_Interior3_Movement_FrameScene2_8::
	walk_right
	walk_down
	step_end

NewBarkTown_Interior3_Movement_FrameScene2_9::
	walk_down
	walk_right
	step_end

NewBarkTown_Interior3_Movement_FrameScene2_10::
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

NewBarkTown_Interior3_Movement_FrameScene2_11::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_Interior3_EventScript_Scientist::
	call_if_set 0x1015, NewBarkTown_Interior3_EventScript_Scientist_1
	msgbox NewBarkTown_Interior3_Text_Scientist_1, MSGBOX_NPC
	release
	end

NewBarkTown_Interior3_EventScript_Scientist_1::
	msgbox NewBarkTown_Interior3_Text_Scientist_2, MSGBOX_NPC
	end

NewBarkTown_Interior3_EventScript_Scientist2::
	call_if_set 0x1161, NewBarkTown_Interior3_EventScript_Scientist2_1
	call_if_set 0x115F, NewBarkTown_Interior3_EventScript_Scientist2_3
	call_if_set 0x1151, NewBarkTown_Interior3_EventScript_Scientist2_1
	call_if_set 0x114F, NewBarkTown_Interior3_EventScript_Scientist2_4
	call_if_set 0x1044, NewBarkTown_Interior3_EventScript_Scientist2_5
	call_if_set 0x1042, NewBarkTown_Interior3_EventScript_Scientist2_6
	call_if_set 0x1025, NewBarkTown_Interior3_EventScript_Scientist2_7
	call_if_set 0x1015, NewBarkTown_Interior3_EventScript_Scientist2_8
	call_if_eq 0x4055, 2, NewBarkTown_Interior3_EventScript_Scientist2_9
	call_if_eq 0x4055, 3, NewBarkTown_Interior3_EventScript_Scientist2_10
	release
	end

NewBarkTown_Interior3_EventScript_Scientist2_1::
	msgbox NewBarkTown_Interior3_Text_Scientist2_1, MSGBOX_NPC
	end

NewBarkTown_Interior3_EventScript_Scientist2_3::
	setflag 0x1161
	msgbox NewBarkTown_Interior3_Text_Scientist2_3, MSGBOX_NPC
	giveitem ITEM_SS_TICKET
	msgbox NewBarkTown_Interior3_Text_Scientist2_4, MSGBOX_NPC
	end

NewBarkTown_Interior3_EventScript_Scientist2_4::
	setflag 0x1151
	msgbox NewBarkTown_Interior3_Text_Scientist2_5, MSGBOX_NPC
	giveitem ITEM_MASTER_BALL
	msgbox NewBarkTown_Interior3_Text_Scientist2_6, MSGBOX_NPC
	end

NewBarkTown_Interior3_EventScript_Scientist2_5::
	call_if_set 0x1046, NewBarkTown_Interior3_EventScript_Scientist2_1
	setvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 175
	copyvar VAR_0x8004, VAR_RESORT_GORGEOUS_REQUESTED_MON
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	call_if_lt VAR_RESULT, 1, NewBarkTown_Interior3_EventScript_Scientist2_11
	msgbox NewBarkTown_Interior3_Text_Scientist2_7, MSGBOX_NPC
	applymovement 3, NewBarkTown_Interior3_Movement_Scientist2_1
	delay 64
	msgbox NewBarkTown_Interior3_Text_Scientist2_8, MSGBOX_NPC
	giveitem ITEM_EVERSTONE
	msgbox NewBarkTown_Interior3_Text_Scientist2_9, MSGBOX_NPC
	setflag 0x1046
	end

NewBarkTown_Interior3_EventScript_Scientist2_6::
	msgbox NewBarkTown_Interior3_Text_Scientist2_10, MSGBOX_NPC
	end

NewBarkTown_Interior3_EventScript_Scientist2_7::
	msgbox NewBarkTown_Interior3_Text_Scientist2_11, MSGBOX_NPC
	release
	end

NewBarkTown_Interior3_EventScript_Scientist2_8::
	removeitem ITEM_OAKS_PARCEL
	msgbox NewBarkTown_Interior3_Text_Scientist2_12, MSGBOX_NPC
	applymovement 3, NewBarkTown_Interior3_Movement_Scientist2_2
	msgbox NewBarkTown_Interior3_Text_Scientist2_13, MSGBOX_NPC
	applymovement 3, NewBarkTown_Interior3_Movement_Scientist2_3
	msgbox NewBarkTown_Interior3_Text_Scientist2_14, MSGBOX_NPC
	msgbox NewBarkTown_Interior3_Text_Scientist2_15, MSGBOX_NPC
	setflag 0x1025
	setflag 0x1030
	clearflag 0x1029
	end

NewBarkTown_Interior3_EventScript_Scientist2_9::
	msgbox NewBarkTown_Interior3_Text_Scientist2_16, MSGBOX_AUTOCLOSE
	end

NewBarkTown_Interior3_EventScript_Scientist2_10::
	msgbox NewBarkTown_Interior3_Text_Scientist2_17, MSGBOX_NPC
	end

NewBarkTown_Interior3_EventScript_Scientist2_11::
	msgbox NewBarkTown_Interior3_Text_Scientist2_18, MSGBOX_NPC
	end

NewBarkTown_Interior3_Movement_Scientist2_1::
	emote_exclamation_mark
	step_end

NewBarkTown_Interior3_Movement_Scientist2_2::
	emote_exclamation_mark
	jump_special_up
	step_end

NewBarkTown_Interior3_Movement_Scientist2_3::
	walk_fast_down
	step_end

NewBarkTown_Interior3_EventScript_Scientist3::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_2, NewBarkTown_Interior3_EventScript_Scientist3_1
	goto_if_eq 0x4055, 9, NewBarkTown_Interior3_EventScript_Scientist3_2
	goto_if_eq 0x4055, 8, NewBarkTown_Interior3_EventScript_Scientist3_3
	goto_if_set FLAG_SYS_GAME_CLEAR, NewBarkTown_Interior3_EventScript_Scientist3_4
	goto_if_eq 0x4052, 1, NewBarkTown_Interior3_EventScript_Scientist3_2
	goto_if_eq 0x4055, 6, NewBarkTown_Interior3_EventScript_Scientist3_5
	goto_if_ge 0x4057, 1, NewBarkTown_Interior3_EventScript_Scientist3_6
	goto_if_eq 0x4055, 4, NewBarkTown_Interior3_EventScript_Scientist3_7
	goto_if_eq 0x4055, 3, NewBarkTown_Interior3_EventScript_Scientist3_8
	msgbox NewBarkTown_Interior3_Text_Scientist3_1
	release
	end

NewBarkTown_Interior3_EventScript_Scientist3_1::
	msgbox PokedexRating_Text_ThankYouMadeDreamReality
	release
	end

NewBarkTown_Interior3_EventScript_Scientist3_2::
	call PokedexRating_EventScript_RateInPerson
	goto_if_set 0x2F4, NewBarkTown_Interior3_EventScript_Scientist3_9
	release
	end

NewBarkTown_Interior3_EventScript_Scientist3_3::
	msgbox NewBarkTown_Interior3_Text_Scientist3_2
	release
	end

NewBarkTown_Interior3_EventScript_Scientist3_4::
	call PokedexRating_EventScript_RateInPerson
	closemessage
	goto_if_lt VAR_0x8009, 60, NewBarkTown_Interior3_EventScript_Scientist3_10
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, NewBarkTown_Interior3_EventScript_Scientist3_10
	delay 30
	msgbox NewBarkTown_Interior3_Text_Scientist3_3
	goto NewBarkTown_Interior3_EventScript_FrameScene2_1

NewBarkTown_Interior3_EventScript_Scientist3_5::
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetPokedexCount
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring STR_VAR_1, VAR_0x8008
	buffernumberstring STR_VAR_2, VAR_0x8009
	goto_if_eq VAR_0x8009, 1, NewBarkTown_Interior3_EventScript_Scientist3_11
	goto NewBarkTown_Interior3_EventScript_Scientist3_2

NewBarkTown_Interior3_EventScript_Scientist3_6::
	msgbox NewBarkTown_Interior3_Text_Scientist3_4
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message NewBarkTown_Interior3_Text_Scientist3_5
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	removeitem ITEM_OAKS_PARCEL
	msgbox NewBarkTown_Interior3_Text_Scientist3_6
	playbgm MUS_ENCOUNTER_RIVAL, 0
	msgbox NewBarkTown_Interior3_Text_Scientist3_7
	closemessage
	call_if_eq VAR_FACING, 2, NewBarkTown_Interior3_EventScript_Scientist3_12
	call_if_eq VAR_FACING, 1, NewBarkTown_Interior3_EventScript_Scientist3_13
	call_if_eq VAR_FACING, 4, NewBarkTown_Interior3_EventScript_Scientist3_14
	call_if_eq VAR_FACING, 3, NewBarkTown_Interior3_EventScript_Scientist3_14
	fadedefaultbgm
	msgbox NewBarkTown_Interior3_Text_Scientist3_8
	closemessage
	delay 30
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_FACING, 1, NewBarkTown_Interior3_EventScript_Scientist3_15
	call_if_eq VAR_FACING, 4, NewBarkTown_Interior3_EventScript_Scientist3_16
	call_if_eq VAR_FACING, 3, NewBarkTown_Interior3_EventScript_Scientist3_17
	call_if_eq VAR_FACING, 2, NewBarkTown_Interior3_EventScript_Scientist3_18
	msgbox NewBarkTown_Interior3_Text_Scientist3_9
	closemessage
	call_if_eq VAR_FACING, 2, NewBarkTown_Interior3_EventScript_Scientist3_19
	call_if_eq VAR_FACING, 1, NewBarkTown_Interior3_EventScript_Scientist3_20
	call_if_eq VAR_FACING, 4, NewBarkTown_Interior3_EventScript_Scientist3_21
	call_if_eq VAR_FACING, 3, NewBarkTown_Interior3_EventScript_Scientist3_22
	msgbox NewBarkTown_Interior3_Text_Scientist3_10
	closemessage
	delay 40
	msgbox NewBarkTown_Interior3_Text_Scientist3_11
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	removeobject 9
	delay 10
	removeobject 10
	delay 25
	call_if_eq VAR_FACING, 2, NewBarkTown_Interior3_EventScript_FrameScene2_11
	call_if_eq VAR_FACING, 1, NewBarkTown_Interior3_EventScript_FrameScene2_12
	call_if_eq VAR_FACING, 4, NewBarkTown_Interior3_EventScript_FrameScene2_13
	call_if_eq VAR_FACING, 3, NewBarkTown_Interior3_EventScript_FrameScene2_14
	delay 10
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_KEY_ITEM
	message NewBarkTown_Interior3_Text_Scientist3_12
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setvar 0x407C, 1
	msgbox NewBarkTown_Interior3_Text_Scientist3_13
	giveitem_msg NewBarkTown_Interior3_Text_Scientist3_14, ITEM_POKE_BALL, 5
	msgbox NewBarkTown_Interior3_Text_Scientist3_15
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 1
	special SetFlavorTextFlagFromSpecialVars
	msgbox NewBarkTown_Interior3_Text_Scientist3_16
	msgbox NewBarkTown_Interior3_Text_Scientist3_17
	call_if_eq VAR_FACING, 2, NewBarkTown_Interior3_EventScript_Scientist3_23
	call_if_eq VAR_FACING, 1, NewBarkTown_Interior3_EventScript_Scientist3_24
	call_if_eq VAR_FACING, 4, NewBarkTown_Interior3_EventScript_Scientist3_25
	call_if_eq VAR_FACING, 3, NewBarkTown_Interior3_EventScript_Scientist3_25
	msgbox NewBarkTown_Interior3_Text_Scientist3_18
	closemessage
	playbgm MUS_RIVAL_EXIT, 0
	call_if_eq VAR_FACING, 2, NewBarkTown_Interior3_EventScript_FrameScene2_15
	call_if_eq VAR_FACING, 1, NewBarkTown_Interior3_EventScript_FrameScene2_16
	call_if_eq VAR_FACING, 4, NewBarkTown_Interior3_EventScript_FrameScene2_16
	call_if_eq VAR_FACING, 3, NewBarkTown_Interior3_EventScript_FrameScene2_16
	removeobject 8
	fadedefaultbgm
	setvar 0x4055, 6
	setvar 0x4057, 2
	setvar 0x4051, 1
	setvar 0x4058, 1
	setvar 0x4054, 1
	release
	end

NewBarkTown_Interior3_EventScript_Scientist3_7::
	msgbox NewBarkTown_Interior3_Text_Scientist3_19
	release
	end

NewBarkTown_Interior3_EventScript_Scientist3_8::
	msgbox NewBarkTown_Interior3_Text_Scientist3_20
	release
	end

NewBarkTown_Interior3_EventScript_Scientist3_9::
	closemessage
	delay 40
	message PokedexRating_Text_Wroooaaarrr
	waitmessage
	call_if_eq VAR_FACING, 2, NewBarkTown_Interior3_EventScript_Scientist3_26
	call_if_eq VAR_FACING, 1, NewBarkTown_Interior3_EventScript_Scientist3_27
	call_if_eq VAR_FACING, 4, NewBarkTown_Interior3_EventScript_Scientist3_28
	call_if_eq VAR_FACING, 3, NewBarkTown_Interior3_EventScript_Scientist3_29
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	closemessage
	delay 70
	msgbox PokedexRating_Text_ThankYouMadeDreamReality
	setflag FLAG_TEMP_2
	release
	end

NewBarkTown_Interior3_EventScript_Scientist3_10::
	release
	end

NewBarkTown_Interior3_EventScript_Scientist3_11::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	goto_if_set 0x24F, NewBarkTown_Interior3_EventScript_Scientist3_3
	goto_if_set 0x247, NewBarkTown_Interior3_EventScript_Scientist3_30
	checkitem ITEM_POKE_BALL
	goto_if_eq VAR_RESULT, 0, NewBarkTown_Interior3_EventScript_Scientist3_31
	goto NewBarkTown_Interior3_EventScript_Scientist3_3

NewBarkTown_Interior3_EventScript_Scientist3_12::
	setobjectxyperm 8, 5, 10
	addobject 8
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_FrameScene2_1
	applymovement 8, NewBarkTown_Interior3_Movement_FrameScene2_2
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_13::
	setobjectxyperm 8, 6, 10
	addobject 8
	applymovement 4, Common_Movement_WalkInPlaceFasterDown
	applymovement 8, NewBarkTown_Interior3_Movement_FrameScene2_2
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_14::
	setobjectxyperm 8, 6, 10
	addobject 8
	applymovement 4, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_FrameScene2_3
	applymovement 8, NewBarkTown_Interior3_Movement_FrameScene2_2
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_15::
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	delay 15
	applymovement 4, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_16::
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	delay 15
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement 4, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_17::
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	delay 15
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement 4, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_18::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_19::
	applymovement 4, NewBarkTown_Interior3_Movement_Scientist3_1
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_20::
	applymovement 4, NewBarkTown_Interior3_Movement_Scientist3_2
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_FrameScene2_6
	applymovement 8, NewBarkTown_Interior3_Movement_FrameScene2_6
	waitmovement 4
	return

NewBarkTown_Interior3_EventScript_Scientist3_21::
	applymovement 4, NewBarkTown_Interior3_Movement_Scientist3_1
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_FrameScene2_7
	waitmovement 4
	return

NewBarkTown_Interior3_EventScript_Scientist3_22::
	applymovement 4, NewBarkTown_Interior3_Movement_Scientist3_1
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_23::
	applymovement 8, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_24::
	applymovement 8, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_25::
	applymovement 8, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_26::
	applymovement 4, NewBarkTown_Interior3_Movement_Scientist3_3
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_27::
	applymovement 4, NewBarkTown_Interior3_Movement_Scientist3_4
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_28::
	applymovement 4, NewBarkTown_Interior3_Movement_Scientist3_5
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_29::
	applymovement 4, NewBarkTown_Interior3_Movement_Scientist3_6
	waitmovement 0
	return

NewBarkTown_Interior3_EventScript_Scientist3_30::
	msgbox NewBarkTown_Interior3_Text_Scientist3_21
	release
	end

NewBarkTown_Interior3_EventScript_Scientist3_31::
	goto_if_ge 0x4054, 2, NewBarkTown_Interior3_EventScript_Scientist3_32
	goto NewBarkTown_Interior3_EventScript_Scientist3_3

NewBarkTown_Interior3_EventScript_Scientist3_32::
	msgbox NewBarkTown_Interior3_Text_Scientist3_22
	giveitem_msg NewBarkTown_Interior3_Text_Scientist3_14, ITEM_POKE_BALL, 5
	setflag 0x247
	release
	end

NewBarkTown_Interior3_Movement_Scientist3_1::
	walk_up
	walk_left
	delay_16
	walk_in_place_faster_down
	step_end

NewBarkTown_Interior3_Movement_Scientist3_2::
	walk_left
	walk_left
	walk_up
	delay_16
	walk_in_place_faster_right
	step_end

NewBarkTown_Interior3_Movement_Scientist3_3::
	walk_in_place_down
	walk_in_place_fast_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_fast_down
	walk_in_place_down
	step_end

NewBarkTown_Interior3_Movement_Scientist3_4::
	walk_in_place_up
	walk_in_place_fast_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_fast_up
	walk_in_place_up
	step_end

NewBarkTown_Interior3_Movement_Scientist3_5::
	walk_in_place_left
	walk_in_place_fast_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_fast_left
	walk_in_place_left
	step_end

NewBarkTown_Interior3_Movement_Scientist3_6::
	walk_in_place_right
	walk_in_place_fast_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_fast_right
	walk_in_place_right
	step_end

NewBarkTown_Interior3_EventScript_ItemBall::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 152
	call_if_ge 0x4055, 3, NewBarkTown_Interior3_EventScript_ItemBall_1
	call_if_eq 0x4055, 2, NewBarkTown_Interior3_EventScript_ItemBall_2
	msgbox NewBarkTown_Interior3_Text_ItemBall_1, MSGBOX_AUTOCLOSE
	release
	end

NewBarkTown_Interior3_EventScript_ItemBall_1::
	msgbox NewBarkTown_Interior3_Text_ItemBall_2, MSGBOX_NPC
	end

NewBarkTown_Interior3_EventScript_ItemBall_2::
	applymovement 3, NewBarkTown_Interior3_Movement_ItemBall_1
	delay 1
	showmonpic VAR_TEMP_2, 10, 3
	call_if_eq VAR_TEMP_1, 0, NewBarkTown_Interior3_EventScript_ItemBall_3
	call_if_eq VAR_TEMP_1, 1, NewBarkTown_Interior3_EventScript_ItemBall_4
	call_if_eq VAR_TEMP_1, 2, NewBarkTown_Interior3_EventScript_ItemBall_5
	end

NewBarkTown_Interior3_EventScript_ItemBall_3::
	msgbox NewBarkTown_Interior3_Text_ItemBall_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, NewBarkTown_Interior3_EventScript_ItemBall_6
	hidemonpic
	msgbox NewBarkTown_Interior3_Text_ItemBall_4, MSGBOX_NPC
	release
	end

NewBarkTown_Interior3_EventScript_ItemBall_4::
	msgbox NewBarkTown_Interior3_Text_ItemBall_5, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, NewBarkTown_Interior3_EventScript_ItemBall_6
	hidemonpic
	msgbox NewBarkTown_Interior3_Text_ItemBall_4, MSGBOX_NPC
	release
	end

NewBarkTown_Interior3_EventScript_ItemBall_5::
	msgbox NewBarkTown_Interior3_Text_ItemBall_6, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, NewBarkTown_Interior3_EventScript_ItemBall_6
	hidemonpic
	msgbox NewBarkTown_Interior3_Text_ItemBall_4, MSGBOX_NPC
	release
	end

NewBarkTown_Interior3_Movement_ItemBall_1::
	face_right
	step_end

NewBarkTown_Interior3_EventScript_ItemBall_6::
	hidemonpic
	msgbox NewBarkTown_Interior3_Text_ItemBall_7, MSGBOX_NPC
	copyvar VAR_STARTER_MON, VAR_TEMP_1
	setflag FLAG_SYS_POKEMON_GET
	givemon VAR_TEMP_2, 5, ITEM_ORAN_BERRY
	nop
	playfanfare MUS_OBTAIN_KEY_ITEM
	call_if_eq VAR_TEMP_1, 0, NewBarkTown_Interior3_EventScript_ItemBall_7
	goto_if_eq VAR_TEMP_1, 1, NewBarkTown_Interior3_EventScript_ItemBall_8
	goto_if_eq VAR_TEMP_1, 2, NewBarkTown_Interior3_EventScript_ItemBall_9
	end

NewBarkTown_Interior3_EventScript_ItemBall_7::
	removeobject 5
	msgbox NewBarkTown_Interior3_Text_ItemBall_8
	waitfanfare
	call NewBarkTown_Interior3_EventScript_ItemBall_10
	end

NewBarkTown_Interior3_EventScript_ItemBall_8::
	removeobject 6
	msgbox NewBarkTown_Interior3_Text_ItemBall_9
	waitfanfare
	call NewBarkTown_Interior3_EventScript_ItemBall_11
	end

NewBarkTown_Interior3_EventScript_ItemBall_9::
	removeobject 7
	msgbox NewBarkTown_Interior3_Text_ItemBall_10
	waitfanfare
	call NewBarkTown_Interior3_EventScript_ItemBall_12
	end

NewBarkTown_Interior3_EventScript_ItemBall_10::
	msgbox NewBarkTown_Interior3_Text_ItemBall_11, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, NewBarkTown_Interior3_EventScript_ItemBall_13
	call NewBarkTown_Interior3_EventScript_ItemBall_14
	end

NewBarkTown_Interior3_EventScript_ItemBall_11::
	msgbox NewBarkTown_Interior3_Text_ItemBall_12, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, NewBarkTown_Interior3_EventScript_ItemBall_13
	call NewBarkTown_Interior3_EventScript_ItemBall_14
	end

NewBarkTown_Interior3_EventScript_ItemBall_12::
	msgbox NewBarkTown_Interior3_Text_ItemBall_13, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, NewBarkTown_Interior3_EventScript_ItemBall_13
	call NewBarkTown_Interior3_EventScript_ItemBall_14
	end

NewBarkTown_Interior3_EventScript_ItemBall_13::
	setvar VAR_0x8004, 0
	call EventScript_ChangePokemonNickname
	setvar 0x4055, 3
	call NewBarkTown_Interior3_EventScript_ItemBall_15
	end

NewBarkTown_Interior3_EventScript_ItemBall_14::
	setvar 0x4055, 3
	call NewBarkTown_Interior3_EventScript_ItemBall_15
	end

NewBarkTown_Interior3_EventScript_ItemBall_15::
	releaseall
	call_if_eq VAR_TEMP_1, 0, NewBarkTown_Interior3_EventScript_ItemBall_16
	call_if_eq VAR_TEMP_1, 1, NewBarkTown_Interior3_EventScript_ItemBall_17
	call NewBarkTown_Interior3_EventScript_ItemBall_18
	end

NewBarkTown_Interior3_EventScript_ItemBall_16::
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_ItemBall_2
	delay 80
	call NewBarkTown_Interior3_EventScript_ItemBall_19
	end

NewBarkTown_Interior3_EventScript_ItemBall_17::
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_ItemBall_3
	delay 64
	call NewBarkTown_Interior3_EventScript_ItemBall_19
	end

NewBarkTown_Interior3_EventScript_ItemBall_18::
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_ItemBall_4
	delay 48
	call NewBarkTown_Interior3_EventScript_ItemBall_19
	end

NewBarkTown_Interior3_EventScript_ItemBall_19::
	applymovement 3, NewBarkTown_Interior3_Movement_ItemBall_5
	delay 1
	msgbox NewBarkTown_Interior3_Text_ItemBall_14, MSGBOX_NPC
	applymovement 3, NewBarkTown_Interior3_Movement_ItemBall_6
	delay 1
	msgbox NewBarkTown_Interior3_Text_ItemBall_15, MSGBOX_NPC
	applymovement 3, NewBarkTown_Interior3_Movement_ItemBall_5
	delay 1
	msgbox NewBarkTown_Interior3_Text_ItemBall_16, MSGBOX_NPC
	playfanfare MUS_DEX_RATING
	msgbox NewBarkTown_Interior3_Text_ItemBall_17
	waitfanfare
	msgbox NewBarkTown_Interior3_Text_ItemBall_18, MSGBOX_NPC
	end

NewBarkTown_Interior3_Movement_ItemBall_2::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Interior3_Movement_ItemBall_3::
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Interior3_Movement_ItemBall_4::
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Interior3_Movement_ItemBall_5::
	face_down_fast
	step_end

NewBarkTown_Interior3_Movement_ItemBall_6::
	face_left
	step_end

NewBarkTown_Interior3_EventScript_ItemBall2::
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 158
	call_if_ge 0x4055, 3, NewBarkTown_Interior3_EventScript_ItemBall_1
	call_if_eq 0x4055, 2, NewBarkTown_Interior3_EventScript_ItemBall_2
	msgbox NewBarkTown_Interior3_Text_ItemBall_1, MSGBOX_AUTOCLOSE
	release
	end

NewBarkTown_Interior3_EventScript_ItemBall3::
	setvar VAR_TEMP_1, 2
	setvar VAR_TEMP_2, 155
	call_if_ge 0x4055, 3, NewBarkTown_Interior3_EventScript_ItemBall_1
	call_if_eq 0x4055, 2, NewBarkTown_Interior3_EventScript_ItemBall_2
	msgbox NewBarkTown_Interior3_Text_ItemBall_1, MSGBOX_AUTOCLOSE
	release
	end

NewBarkTown_Interior3_EventScript_Blue::
	lock
	faceplayer
	goto_if_eq 0x4055, 3, NewBarkTown_Interior3_EventScript_Blue_1
	goto_if_eq 0x4055, 2, NewBarkTown_Interior3_EventScript_Blue_2
	msgbox NewBarkTown_Interior3_Text_Blue_1
	release
	end

NewBarkTown_Interior3_EventScript_Blue_1::
	msgbox NewBarkTown_Interior3_Text_Blue_2
	release
	end

NewBarkTown_Interior3_EventScript_Blue_2::
	msgbox NewBarkTown_Interior3_Text_Blue_3
	release
	end

NewBarkTown_Interior3_EventScript_Pokedex::
	msgbox NewBarkTown_Interior3_Text_Pokedex, MSGBOX_NPC
	end

NewBarkTown_Interior3_EventScript_Trigger1::
	call_if_eq 0x4055, 2, NewBarkTown_Interior3_EventScript_Trigger1_1
	release
	end

NewBarkTown_Interior3_EventScript_Trigger1_1::
	msgbox NewBarkTown_Interior3_Text_Trigger1, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_Trigger1
	end

NewBarkTown_Interior3_Movement_Trigger1::
	walk_up
	step_end

NewBarkTown_Interior3_EventScript_Trigger4::
	call_if_unset 0x1015, NewBarkTown_Interior3_EventScript_Trigger4_1
	call_if_set 0x1023, NewBarkTown_Interior3_EventScript_Trigger4_1
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_Trigger4_1
	delay 117
	applymovement 11, NewBarkTown_Interior3_Movement_Trigger4_2
	msgbox NewBarkTown_Interior3_Text_Trigger4, MSGBOX_NPC
	applymovement 11, NewBarkTown_Interior3_Movement_Trigger4_3
	delay 144
	setflag 0x1021
	setflag 0x1023
	end

NewBarkTown_Interior3_EventScript_Trigger4_1::
	release
	end

NewBarkTown_Interior3_Movement_Trigger4_1::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_up
	step_end

NewBarkTown_Interior3_Movement_Trigger4_2::
	face_down_fast
	step_end

NewBarkTown_Interior3_Movement_Trigger4_3::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	walk_down
	walk_down
	step_end

NewBarkTown_Interior3_EventScript_Trigger5::
	call_if_unset 0x1015, NewBarkTown_Interior3_EventScript_Trigger4_1
	call_if_set 0x1023, NewBarkTown_Interior3_EventScript_Trigger4_1
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_Trigger5
	delay 85
	applymovement 11, NewBarkTown_Interior3_Movement_Trigger4_2
	msgbox NewBarkTown_Interior3_Text_Trigger4, MSGBOX_NPC
	applymovement 11, NewBarkTown_Interior3_Movement_Trigger4_3
	delay 144
	setflag 0x1021
	setflag 0x1023
	end

NewBarkTown_Interior3_Movement_Trigger5::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_up
	step_end

NewBarkTown_Interior3_EventScript_Trigger6::
	call_if_unset 0x1015, NewBarkTown_Interior3_EventScript_Trigger4_1
	call_if_set 0x1023, NewBarkTown_Interior3_EventScript_Trigger4_1
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_Trigger6
	delay 117
	applymovement 11, NewBarkTown_Interior3_Movement_Trigger4_2
	msgbox NewBarkTown_Interior3_Text_Trigger4, MSGBOX_NPC
	applymovement 11, NewBarkTown_Interior3_Movement_Trigger4_3
	delay 144
	setflag 0x1021
	setflag 0x1023
	end

NewBarkTown_Interior3_Movement_Trigger6::
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_up
	step_end

NewBarkTown_Interior3_EventScript_Trigger7::
	call_if_set 0x1003, NewBarkTown_Interior3_EventScript_Trigger7_1
	call_if_eq 0x4055, 3, NewBarkTown_Interior3_EventScript_Trigger7_1
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_Trigger7
	delay 144
	msgbox NewBarkTown_Interior3_Text_Trigger7, MSGBOX_AUTOCLOSE
	setflag 0x1003
	setvar 0x4055, 2
	end

NewBarkTown_Interior3_EventScript_Trigger7_1::
	release
	end

NewBarkTown_Interior3_Movement_Trigger7::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_up
	step_end

NewBarkTown_Interior3_EventScript_Trigger8::
	call_if_set 0x1003, NewBarkTown_Interior3_EventScript_Trigger7_1
	call_if_eq 0x4055, 3, NewBarkTown_Interior3_EventScript_Trigger7_1
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_Trigger8
	delay 128
	msgbox NewBarkTown_Interior3_Text_Trigger7, MSGBOX_AUTOCLOSE
	setflag 0x1003
	setvar 0x4055, 2
	end

NewBarkTown_Interior3_Movement_Trigger8::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_up
	step_end

NewBarkTown_Interior3_EventScript_Trigger9::
	call_if_set 0x1003, NewBarkTown_Interior3_EventScript_Trigger7_1
	call_if_eq 0x4055, 3, NewBarkTown_Interior3_EventScript_Trigger7_1
	applymovement LOCALID_PLAYER, NewBarkTown_Interior3_Movement_Trigger9
	delay 144
	msgbox NewBarkTown_Interior3_Text_Trigger7, MSGBOX_AUTOCLOSE
	setflag 0x1003
	setvar 0x4055, 2
	end

NewBarkTown_Interior3_Movement_Trigger9::
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_up
	step_end

NewBarkTown_Interior3_EventScript_Trigger10::
	goto_if_set 0x1025, NewBarkTown_Interior3_EventScript_Trigger10_1
	goto_if_eq 0x4055, 3, NewBarkTown_Interior3_EventScript_Trigger10_2
	release
	end

NewBarkTown_Interior3_EventScript_Trigger10_1::
	call_if_set 0x1026, NewBarkTown_Interior3_EventScript_Trigger10_3
	applymovement 1, NewBarkTown_Interior3_Movement_Trigger10_1
	delay 16
	msgbox NewBarkTown_Interior3_Text_Trigger10_1, MSGBOX_AUTOCLOSE
	faceplayer
	lock
	giveitem ITEM_POKE_BALL, 5
	msgbox NewBarkTown_Interior3_Text_Trigger10_2, MSGBOX_AUTOCLOSE
	setflag 0x1026
	release
	end

NewBarkTown_Interior3_EventScript_Trigger10_2::
	call_if_set 0x1006, NewBarkTown_Interior3_EventScript_Trigger10_4
	setflag 0x1006
	applymovement 1, NewBarkTown_Interior3_Movement_Trigger10_2
	delay 16
	msgbox NewBarkTown_Interior3_Text_Trigger10_3, MSGBOX_NPC
	faceplayer
	lock
	giveitem ITEM_POTION
	msgbox NewBarkTown_Interior3_Text_Trigger10_4, MSGBOX_NPC
	end

NewBarkTown_Interior3_EventScript_Trigger10_3::
	release
	end

NewBarkTown_Interior3_EventScript_Trigger10_4::
	release
	end

NewBarkTown_Interior3_Movement_Trigger10_1::
	walk_right
	face_up
	step_end

NewBarkTown_Interior3_Movement_Trigger10_2::
	walk_right
	face_up
	step_end

NewBarkTown_Interior3_EventScript_Trigger11::
	goto_if_set 0x1025, NewBarkTown_Interior3_EventScript_Trigger11_1
	goto_if_eq 0x4055, 3, NewBarkTown_Interior3_EventScript_Trigger11_2
	release
	end

NewBarkTown_Interior3_EventScript_Trigger11_1::
	call_if_set 0x1026, NewBarkTown_Interior3_EventScript_Trigger10_3
	applymovement 1, NewBarkTown_Interior3_Movement_Trigger11_1
	delay 16
	msgbox NewBarkTown_Interior3_Text_Trigger10_1, MSGBOX_AUTOCLOSE
	faceplayer
	lock
	giveitem ITEM_POKE_BALL, 5
	msgbox NewBarkTown_Interior3_Text_Trigger10_2, MSGBOX_AUTOCLOSE
	setflag 0x1026
	release
	end

NewBarkTown_Interior3_EventScript_Trigger11_2::
	call_if_set 0x1006, NewBarkTown_Interior3_EventScript_Trigger10_4
	setflag 0x1006
	applymovement 1, NewBarkTown_Interior3_Movement_Trigger11_2
	delay 16
	msgbox NewBarkTown_Interior3_Text_Trigger10_3, MSGBOX_NPC
	faceplayer
	lock
	giveitem ITEM_POTION
	msgbox NewBarkTown_Interior3_Text_Trigger10_4, MSGBOX_NPC
	end

NewBarkTown_Interior3_Movement_Trigger11_1::
	walk_right
	walk_right
	face_up
	step_end

NewBarkTown_Interior3_Movement_Trigger11_2::
	walk_right
	walk_right
	face_up
	step_end

NewBarkTown_Interior3_EventScript_Trigger12::
	goto_if_set 0x1025, NewBarkTown_Interior3_EventScript_Trigger12_1
	goto_if_eq 0x4055, 3, NewBarkTown_Interior3_EventScript_Trigger12_2
	release
	end

NewBarkTown_Interior3_EventScript_Trigger12_1::
	call_if_set 0x1026, NewBarkTown_Interior3_EventScript_Trigger10_3
	applymovement 1, NewBarkTown_Interior3_Movement_Trigger12_1
	delay 32
	msgbox NewBarkTown_Interior3_Text_Trigger10_1, MSGBOX_AUTOCLOSE
	faceplayer
	lock
	giveitem ITEM_POKE_BALL, 5
	msgbox NewBarkTown_Interior3_Text_Trigger10_2, MSGBOX_AUTOCLOSE
	setflag 0x1026
	release
	end

NewBarkTown_Interior3_EventScript_Trigger12_2::
	call_if_set 0x1006, NewBarkTown_Interior3_EventScript_Trigger10_4
	setflag 0x1006
	applymovement 1, NewBarkTown_Interior3_Movement_Trigger12_2
	delay 32
	msgbox NewBarkTown_Interior3_Text_Trigger10_3, MSGBOX_NPC
	faceplayer
	lock
	giveitem ITEM_POTION
	msgbox NewBarkTown_Interior3_Text_Trigger10_4, MSGBOX_NPC
	end

NewBarkTown_Interior3_Movement_Trigger12_1::
	walk_right
	walk_right
	walk_right
	face_up
	step_end

NewBarkTown_Interior3_Movement_Trigger12_2::
	walk_right
	walk_right
	walk_right
	face_up
	step_end

NewBarkTown_Interior3_EventScript_Sign1::
	msgbox NewBarkTown_Interior3_Text_Sign1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, NewBarkTown_Interior3_EventScript_Sign1_1
	releaseall
	release
	end

NewBarkTown_Interior3_EventScript_Sign1_1::
	closemessage
	call EventScript_OutOfCenterPartyHeal
	end

NewBarkTown_Interior3_EventScript_Sign3::
	msgbox NewBarkTown_Interior3_Text_Sign3, MSGBOX_SIGN
	end

NewBarkTown_Interior3_EventScript_Sign4::
	lockall
	goto_if_ge 0x4055, 6, NewBarkTown_Interior3_EventScript_Sign4_1
	msgbox NewBarkTown_Interior3_Text_Sign4_1
	releaseall
	end

NewBarkTown_Interior3_EventScript_Sign4_1::
	msgbox NewBarkTown_Interior3_Text_Sign4_2
	releaseall
	end
