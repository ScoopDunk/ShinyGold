CeruleanCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeruleanCity_OnFrame
	.byte 0

CeruleanCity_OnFrame::
	map_script_2 0x7044, 0, CeruleanCity_EventScript_FrameScene
	.2byte 0

CeruleanCity_EventScript_FrameScene::
	setflag 0x1363
	setvar 0x7044, 1
	call NewBarkTown_EventScript_FrameScene_1
	end

CeruleanCity_EventScript_FatMan::
	msgbox CeruleanCity_Text_FatMan, MSGBOX_NPC
	end

CeruleanCity_EventScript_Woman2::
	msgbox CeruleanCity_Text_Woman2_1, MSGBOX_NPC
	applymovement 2, CeruleanCity_Movement_Woman2
	msgbox CeruleanCity_Text_Woman2_2, MSGBOX_AUTOCLOSE
	msgbox CeruleanCity_Text_Woman2_3, MSGBOX_AUTOCLOSE
	waitse
	playmoncry SPECIES_SLOWPOKE, 0x3028
	nop
	delay 48
	msgbox CeruleanCity_Text_Woman2_4, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Movement_Woman2::
	face_left
	step_end

CeruleanCity_EventScript_Slowpoke::
	msgbox CeruleanCity_Text_Woman2_3, MSGBOX_NPC
	waitse
	playmoncry SPECIES_SLOWPOKE, 0x200
	.byte 0xFF @ invalid opcode (script stops)

CeruleanCity_EventScript_Boy::
	call_if_set 0x1185, CeruleanCity_EventScript_Boy_1
	msgbox CeruleanCity_Text_Boy_1, MSGBOX_NPC
	end

CeruleanCity_EventScript_Boy_1::
	msgbox CeruleanCity_Text_Boy_2, MSGBOX_NPC
	end

CeruleanCity_EventScript_Slowbro::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_Slowbro_1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_Slowbro_2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_Slowbro_3
	call_if_eq VAR_0x8008, 3, CeruleanCity_EventScript_Slowbro_4
	release
	end

CeruleanCity_EventScript_Slowbro_1::
	msgbox CeruleanCity_Text_Slowbro_1
	return

CeruleanCity_EventScript_Slowbro_2::
	msgbox CeruleanCity_Text_Slowbro_2
	return

CeruleanCity_EventScript_Slowbro_3::
	msgbox CeruleanCity_Text_Slowbro_3
	return

CeruleanCity_EventScript_Slowbro_4::
	msgbox CeruleanCity_Text_Slowbro_4
	return

CeruleanCity_EventScript_Lass::
	lock
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_Lass_1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_Lass_2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_Lass_3
	waitmessage
	delay 40
	playse SE_PIN
	applymovement 5, Common_Movement_QuestionMark
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_Lass_4
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_Lass_5
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_Lass_6
	release
	end

CeruleanCity_EventScript_Lass_1::
	message CeruleanCity_Text_Lass_1
	return

CeruleanCity_EventScript_Lass_2::
	message CeruleanCity_Text_Lass_2
	return

CeruleanCity_EventScript_Lass_3::
	message CeruleanCity_Text_Lass_3
	return

CeruleanCity_EventScript_Lass_4::
	msgbox CeruleanCity_Text_Lass_4
	return

CeruleanCity_EventScript_Lass_5::
	msgbox CeruleanCity_Text_Lass_5
	return

CeruleanCity_EventScript_Lass_6::
	msgbox CeruleanCity_Text_Lass_6
	return

CeruleanCity_EventScript_Man::
	msgbox CeruleanCity_Text_Man, MSGBOX_NPC
	end

CeruleanCity_EventScript_WorkerM::
	msgbox CeruleanCity_Text_WorkerM_1, MSGBOX_NPC
	playfanfare MUS_SS_ANNE
	delay 16
	playfanfare MUS_SS_ANNE
	delay 32
	playfanfare MUS_SS_ANNE
	applymovement 8, CeruleanCity_Movement_WorkerM
	delay 64
	msgbox CeruleanCity_Text_WorkerM_2, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Movement_WorkerM::
	emote_exclamation_mark
	face_left
	step_end

CeruleanCity_EventScript_ItemSootheBell::
	finditem ITEM_SOOTHE_BELL
	end

CeruleanCity_EventScript_Trigger1::
	setvar 0x7030, 0x129
	setvar 0x7031, 0x12A
	setvar 0x7033, 0x10A
	setvar 0x7034, 0x154
	release
	return

CeruleanCity_EventScript_Trigger3::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm 8, 24, 0
	goto CeruleanCity_EventScript_Trigger3_1

CeruleanCity_EventScript_Trigger3_1::
	textcolor NPC_TEXT_COLOR_MALE
	setvar 0x4054, 2
	playbgm MUS_ENCOUNTER_RIVAL, 0
	addobject 8
	applymovement 8, CeruleanCity_Movement_Trigger3_1
	waitmovement 0
	msgbox CeruleanCity_Text_Trigger3_1
	setvar VAR_LAST_TALKED, 8
	call_if_eq VAR_STARTER_MON, 2, CeruleanCity_EventScript_Trigger3_2
	call_if_eq VAR_STARTER_MON, 1, CeruleanCity_EventScript_Trigger3_3
	call_if_eq VAR_STARTER_MON, 0, CeruleanCity_EventScript_Trigger3_4
	setvar VAR_0x8004, 13
	setvar VAR_0x8005, 0
	special SetFlavorTextFlagFromSpecialVars
	msgbox CeruleanCity_Text_Trigger3_2
	closemessage
	playbgm MUS_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, CeruleanCity_EventScript_Trigger3_5
	call_if_eq VAR_TEMP_1, 1, CeruleanCity_EventScript_Trigger3_5
	call_if_eq VAR_TEMP_1, 2, CeruleanCity_EventScript_Trigger3_6
	msgbox CeruleanCity_Text_Trigger3_3
	setvar 0x4052, 1
	setflag FLAG_GOT_FAME_CHECKER
	giveitem ITEM_FAME_CHECKER
	msgbox CeruleanCity_Text_Trigger3_4
	closemessage
	applymovement 8, CeruleanCity_Movement_Trigger3_2
	waitmovement 0
	fadedefaultbgm
	removeobject 8
	releaseall
	end

CeruleanCity_EventScript_Trigger3_2::
	trainerbattle_no_intro TRAINER_RIVAL_TERRY, CeruleanCity_Text_Trigger3Defeat
	return

CeruleanCity_EventScript_Trigger3_3::
	trainerbattle_no_intro TRAINER_RIVAL_TERRY_2, CeruleanCity_Text_Trigger3Defeat
	return

CeruleanCity_EventScript_Trigger3_4::
	trainerbattle_no_intro TRAINER_RIVAL_TERRY_3, CeruleanCity_Text_Trigger3Defeat
	return

CeruleanCity_EventScript_Trigger3_5::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_Trigger3_3
	applymovement 8, CeruleanCity_Movement_Trigger3_4
	waitmovement 0
	return

CeruleanCity_EventScript_Trigger3_6::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_Trigger3_5
	applymovement 8, CeruleanCity_Movement_Trigger3_6
	waitmovement 0
	return

CeruleanCity_Movement_Trigger3_1::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Movement_Trigger3_2::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Movement_Trigger3_3::
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_Trigger3_4::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_Trigger3_5::
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_Trigger3_6::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_EventScript_Trigger10::
	call_if_set 0x11C3, CeruleanCity_EventScript_Trigger10_1
	call_if_set 0x11BF, CeruleanCity_EventScript_Trigger10_2
	setflag 0x11C0
	setflag 0x11C2
	setflag 0x272
	call CeruleanCity_EventScript_Trigger10_3
	release
	end

CeruleanCity_EventScript_Trigger10_1::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_Trigger10_1
	delay 1
	opendoor 31, 21
	delay 32
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_Trigger10_2
	delay 32
	closedoor 31, 21
	delay 48
	warp MAP_CERULEAN_CITY_INTERIOR7, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

CeruleanCity_EventScript_Trigger10_2::
	setflag 0x11C2
	call CeruleanCity_EventScript_Trigger10_3
	release
	end

CeruleanCity_EventScript_Trigger10_3::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_Trigger10_1
	delay 1
	opendoor 31, 21
	delay 32
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_Trigger10_2
	delay 32
	closedoor 31, 21
	delay 48
	warp MAP_UNUSED_CERULEAN_CITY_GYM, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

CeruleanCity_Movement_Trigger10_1::
	face_up
	step_end

CeruleanCity_Movement_Trigger10_2::
	walk_up
	set_invisible
	step_end

CeruleanCity_EventScript_Sign1::
	msgbox CeruleanCity_Text_Sign1, MSGBOX_AUTOCLOSE
	end

CeruleanCity_EventScript_Sign2::
	msgbox CeruleanCity_Text_Sign2, MSGBOX_AUTOCLOSE
	end

CeruleanCity_EventScript_Sign3::
	msgbox CeruleanCity_Text_Sign3, MSGBOX_AUTOCLOSE
	end

CeruleanCity_EventScript_Sign4::
	msgbox CeruleanCity_Text_Sign4, MSGBOX_AUTOCLOSE
	end

CeruleanCity_EventScript_Sign5::
	msgbox CeruleanCity_Text_Sign5, MSGBOX_AUTOCLOSE
	end

@ Pure Gold/Silver: the old bike shop is closed (pokegold CeruleanCity.asm, CeruleanLockedDoor)
CeruleanCity_EventScript_LockedDoor::
	msgbox CeruleanCity_Text_LockedDoor, MSGBOX_SIGN
	end
