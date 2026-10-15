NewBarkTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_OnFrame
	.byte 0

NewBarkTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
	call_if_set 0x291, NewBarkTown_EventScript_OnTransition_1
	call_if_eq 0x4070, 0, NewBarkTown_EventScript_OnTransition_2
	call_if_eq 0x4070, 1, NewBarkTown_EventScript_OnTransition_3
	end

NewBarkTown_EventScript_OnTransition_1::
	goto_if_unset FLAG_OPENED_START_MENU, EventScript_Return
	goto_if_ge 0x4070, 1, EventScript_Return
	setvar 0x4070, 1
	return

NewBarkTown_EventScript_OnTransition_2::
	goto_if_set 0x291, NewBarkTown_EventScript_OnTransition_4
	setobjectxyperm 1, 5, 15
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

NewBarkTown_EventScript_OnTransition_3::
	setvar 0x4070, 2
	return

NewBarkTown_OnFrame::
	map_script_2 0x7020, 0, NewBarkTown_EventScript_FrameScene
	.2byte 0

NewBarkTown_EventScript_FrameScene::
	setflag 0x136B
	call NewBarkTown_EventScript_FrameScene_1
	setvar 0x7020, 1
	call NewBarkTown_EventScript_FrameScene_2
	call Route35_EventScript_FrameScene_2
	end

NewBarkTown_EventScript_OnTransition_4::
	setobjectxyperm 1, 12, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	setvar VAR_TEMP_2, 1
	return

NewBarkTown_EventScript_FrameScene_1::
	call_if_set 0x1360, NewBarkTown_EventScript_FrameScene_3
	call_if_unset 0x1360, NewBarkTown_EventScript_FrameScene_4
	call_if_set 0x1361, NewBarkTown_EventScript_FrameScene_5
	call_if_unset 0x1361, NewBarkTown_EventScript_FrameScene_6
	call_if_set 0x1362, NewBarkTown_EventScript_FrameScene_7
	call_if_unset 0x1362, NewBarkTown_EventScript_FrameScene_8
	call_if_set 0x1363, NewBarkTown_EventScript_FrameScene_9
	call_if_unset 0x1363, NewBarkTown_EventScript_FrameScene_10
	call_if_set 0x1364, NewBarkTown_EventScript_FrameScene_11
	call_if_unset 0x1364, NewBarkTown_EventScript_FrameScene_12
	call_if_set 0x1365, NewBarkTown_EventScript_FrameScene_13
	call_if_unset 0x1365, NewBarkTown_EventScript_FrameScene_14
	call_if_set 0x1366, NewBarkTown_EventScript_FrameScene_15
	call_if_unset 0x1366, NewBarkTown_EventScript_FrameScene_16
	call_if_set 0x1367, NewBarkTown_EventScript_FrameScene_17
	call_if_unset 0x1367, NewBarkTown_EventScript_FrameScene_18
	call_if_set 0x1368, NewBarkTown_EventScript_FrameScene_19
	call_if_unset 0x1368, NewBarkTown_EventScript_FrameScene_20
	call_if_set 0x136A, NewBarkTown_EventScript_FrameScene_21
	call_if_unset 0x136A, NewBarkTown_EventScript_FrameScene_22
	call_if_set 0x136B, NewBarkTown_EventScript_FrameScene_23
	call_if_unset 0x136B, NewBarkTown_EventScript_FrameScene_24
	call_if_set 0x136C, NewBarkTown_EventScript_FrameScene_25
	call_if_unset 0x136C, NewBarkTown_EventScript_FrameScene_26
	call_if_set 0x136D, NewBarkTown_EventScript_FrameScene_27
	call_if_unset 0x136D, NewBarkTown_EventScript_FrameScene_28
	call_if_set 0x136E, NewBarkTown_EventScript_FrameScene_29
	call_if_unset 0x136E, NewBarkTown_EventScript_FrameScene_30
	call_if_set 0x136F, NewBarkTown_EventScript_FrameScene_31
	call_if_unset 0x136F, NewBarkTown_EventScript_FrameScene_32
	call_if_set 0x1370, NewBarkTown_EventScript_FrameScene_33
	call_if_unset 0x1370, NewBarkTown_EventScript_FrameScene_34
	call_if_set 0x1371, NewBarkTown_EventScript_FrameScene_35
	call_if_unset 0x1371, NewBarkTown_EventScript_FrameScene_36
	call_if_set 0x1372, NewBarkTown_EventScript_FrameScene_37
	call_if_unset 0x1372, NewBarkTown_EventScript_FrameScene_38
	call_if_set 0x1373, NewBarkTown_EventScript_FrameScene_39
	call_if_unset 0x1373, NewBarkTown_EventScript_FrameScene_40
	return

NewBarkTown_EventScript_FrameScene_2::
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
	setvar 0x7021, 0
	setvar 0x7022, 0
	setvar 0x7023, 0
	setvar 0x7024, 0
	setvar 0x7025, 0
	setvar 0x7026, 0
	setvar 0x7027, 0
	setvar 0x7028, 0
	return

NewBarkTown_EventScript_FrameScene_3::
	setflag FLAG_WORLD_MAP_PALLET_TOWN
	return

NewBarkTown_EventScript_FrameScene_4::
	clearflag FLAG_WORLD_MAP_PALLET_TOWN
	return

NewBarkTown_EventScript_FrameScene_5::
	setflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	return

NewBarkTown_EventScript_FrameScene_6::
	clearflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	return

NewBarkTown_EventScript_FrameScene_7::
	setflag FLAG_WORLD_MAP_PEWTER_CITY
	return

NewBarkTown_EventScript_FrameScene_8::
	clearflag FLAG_WORLD_MAP_PEWTER_CITY
	return

NewBarkTown_EventScript_FrameScene_9::
	setflag FLAG_WORLD_MAP_CERULEAN_CITY
	return

NewBarkTown_EventScript_FrameScene_10::
	clearflag FLAG_WORLD_MAP_CERULEAN_CITY
	return

NewBarkTown_EventScript_FrameScene_11::
	setflag FLAG_WORLD_MAP_LAVENDER_TOWN
	return

NewBarkTown_EventScript_FrameScene_12::
	clearflag FLAG_WORLD_MAP_LAVENDER_TOWN
	return

NewBarkTown_EventScript_FrameScene_13::
	setflag FLAG_WORLD_MAP_VERMILION_CITY
	return

NewBarkTown_EventScript_FrameScene_14::
	clearflag FLAG_WORLD_MAP_VERMILION_CITY
	return

NewBarkTown_EventScript_FrameScene_15::
	setflag FLAG_WORLD_MAP_CELADON_CITY
	return

NewBarkTown_EventScript_FrameScene_16::
	clearflag FLAG_WORLD_MAP_CELADON_CITY
	return

NewBarkTown_EventScript_FrameScene_17::
	setflag FLAG_WORLD_MAP_FUCHSIA_CITY
	return

NewBarkTown_EventScript_FrameScene_18::
	clearflag FLAG_WORLD_MAP_FUCHSIA_CITY
	return

NewBarkTown_EventScript_FrameScene_19::
	setflag FLAG_WORLD_MAP_CINNABAR_ISLAND
	return

NewBarkTown_EventScript_FrameScene_20::
	clearflag FLAG_WORLD_MAP_CINNABAR_ISLAND
	return

NewBarkTown_EventScript_FrameScene_21::
	setflag FLAG_WORLD_MAP_SAFFRON_CITY
	return

NewBarkTown_EventScript_FrameScene_22::
	clearflag FLAG_WORLD_MAP_SAFFRON_CITY
	return

NewBarkTown_EventScript_FrameScene_23::
	setflag FLAG_WORLD_MAP_ONE_ISLAND
	return

NewBarkTown_EventScript_FrameScene_24::
	clearflag FLAG_WORLD_MAP_ONE_ISLAND
	return

NewBarkTown_EventScript_FrameScene_25::
	setflag FLAG_WORLD_MAP_TWO_ISLAND
	return

NewBarkTown_EventScript_FrameScene_26::
	clearflag FLAG_WORLD_MAP_TWO_ISLAND
	return

NewBarkTown_EventScript_FrameScene_27::
	setflag FLAG_WORLD_MAP_THREE_ISLAND
	return

NewBarkTown_EventScript_FrameScene_28::
	clearflag FLAG_WORLD_MAP_THREE_ISLAND
	return

NewBarkTown_EventScript_FrameScene_29::
	setflag FLAG_WORLD_MAP_FOUR_ISLAND
	return

NewBarkTown_EventScript_FrameScene_30::
	clearflag FLAG_WORLD_MAP_FOUR_ISLAND
	return

NewBarkTown_EventScript_FrameScene_31::
	setflag FLAG_WORLD_MAP_FIVE_ISLAND
	return

NewBarkTown_EventScript_FrameScene_32::
	clearflag FLAG_WORLD_MAP_FIVE_ISLAND
	return

NewBarkTown_EventScript_FrameScene_33::
	setflag FLAG_WORLD_MAP_SEVEN_ISLAND
	return

NewBarkTown_EventScript_FrameScene_34::
	clearflag FLAG_WORLD_MAP_SEVEN_ISLAND
	return

NewBarkTown_EventScript_FrameScene_35::
	setflag FLAG_WORLD_MAP_SIX_ISLAND
	return

NewBarkTown_EventScript_FrameScene_36::
	clearflag FLAG_WORLD_MAP_SIX_ISLAND
	return

NewBarkTown_EventScript_FrameScene_37::
	setflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
	return

NewBarkTown_EventScript_FrameScene_38::
	clearflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
	return

NewBarkTown_EventScript_FrameScene_39::
	setflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	return

NewBarkTown_EventScript_FrameScene_40::
	clearflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	return

NewBarkTown_EventScript_RsBrendan::
	applymovement 6, NewBarkTown_Movement_RsBrendan_1
	delay 1
	msgbox NewBarkTown_Text_RsBrendan_1, MSGBOX_AUTOCLOSE
	msgbox NewBarkTown_Text_RsBrendan_2, MSGBOX_NPC
	applymovement 6, NewBarkTown_Movement_RsBrendan_2
	applymovement LOCALID_PLAYER, NewBarkTown_Movement_RsBrendan_3
	end

NewBarkTown_Movement_RsBrendan_1::
	face_right
	step_end

NewBarkTown_Movement_RsBrendan_2::
	walk_fast_left
	walk_fast_right
	step_end

NewBarkTown_Movement_RsBrendan_3::
	jump_2_down
	step_end

NewBarkTown_EventScript_FatMan::
	msgbox NewBarkTown_Text_FatMan, MSGBOX_NPC
	end

NewBarkTown_EventScript_Lass::
	call_if_set 0x1027, NewBarkTown_EventScript_Lass_1
	call_if_eq 0x4055, 3, NewBarkTown_EventScript_Lass_2
	msgbox NewBarkTown_Text_Lass_1, MSGBOX_NPC
	release
	end

NewBarkTown_EventScript_Lass_1::
	msgbox NewBarkTown_Text_Lass_2, MSGBOX_NPC
	end

NewBarkTown_EventScript_Lass_2::
	msgbox NewBarkTown_Text_Lass_3, MSGBOX_NPC
	release
	end

NewBarkTown_EventScript_Pikachu::
	msgbox NewBarkTown_Text_Pikachu_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, NewBarkTown_EventScript_Pikachu_1
	msgbox NewBarkTown_Text_Pikachu_2, MSGBOX_NPC
	end

NewBarkTown_EventScript_Pikachu_1::
	getpartysize
	call_if_lt VAR_RESULT, 6, NewBarkTown_EventScript_Pikachu_2
	msgbox NewBarkTown_Text_Pikachu_3, MSGBOX_NPC
	end

NewBarkTown_EventScript_Pikachu_2::
	setflag 0x1134
	playfanfare SE_M_NIGHTMARE
	msgbox NewBarkTown_Text_Pikachu_4, MSGBOX_NPC
	applymovement 5, NewBarkTown_Movement_Pikachu
	delay 16
	.byte 0x79 @ givemon
	.2byte SPECIES_PIKACHU
	.byte 10
	.2byte ITEM_NONE
	.4byte 0xFFFFFF02
	.4byte 0xFFFFFFFF
	.byte 255
	.byte 0xFF @ invalid opcode (script stops)

NewBarkTown_Movement_Pikachu::
	walk_fast_right
	walk_fast_down
	step_end

NewBarkTown_EventScript_Trigger1::
	goto_if_eq 0x4055, 3, NewBarkTown_EventScript_Trigger1_1
	playbgm MUS_FOLLOW_ME, 51
	msgbox NewBarkTown_Text_Trigger1_1, MSGBOX_AUTOCLOSE
	applymovement 3, NewBarkTown_Movement_Trigger1_1
	delay 160
	applymovement LOCALID_PLAYER, NewBarkTown_Movement_Trigger1_2
	delay 1
	msgbox NewBarkTown_Text_Trigger1_2, MSGBOX_AUTOCLOSE
	applymovement 3, NewBarkTown_Movement_Trigger1_3
	applymovement LOCALID_PLAYER, NewBarkTown_Movement_Trigger1_4
	delay 128
	msgbox NewBarkTown_Text_Trigger1_3, MSGBOX_AUTOCLOSE
	playbgm MUS_MYSTERY_GIFT, 108

NewBarkTown_EventScript_Trigger1_1::
	release
	end

NewBarkTown_Movement_Trigger1_1::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down_fast
	step_end

NewBarkTown_Movement_Trigger1_2::
	face_up
	step_end

NewBarkTown_Movement_Trigger1_3::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_left
	step_end

NewBarkTown_Movement_Trigger1_4::
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

NewBarkTown_EventScript_Trigger2::
	goto_if_eq 0x4055, 3, NewBarkTown_EventScript_Trigger2_1
	playbgm MUS_FOLLOW_ME, 51
	msgbox NewBarkTown_Text_Trigger2_1, MSGBOX_NPC
	applymovement 3, NewBarkTown_Movement_Trigger2_1
	delay 128
	applymovement LOCALID_PLAYER, NewBarkTown_Movement_Trigger2_2
	delay 1
	msgbox NewBarkTown_Text_Trigger2_2, MSGBOX_NPC
	applymovement 3, NewBarkTown_Movement_Trigger2_3
	applymovement LOCALID_PLAYER, NewBarkTown_Movement_Trigger2_4
	delay 128
	msgbox NewBarkTown_Text_Trigger1_3, MSGBOX_NPC
	playbgm MUS_MYSTERY_GIFT, 108

NewBarkTown_EventScript_Trigger2_1::
	release
	end

NewBarkTown_Movement_Trigger2_1::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_left
	step_end

NewBarkTown_Movement_Trigger2_2::
	face_right
	step_end

NewBarkTown_Movement_Trigger2_3::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_left
	step_end

NewBarkTown_Movement_Trigger2_4::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

NewBarkTown_EventScript_Trigger3::
	call_if_set 0x115F, NewBarkTown_EventScript_Trigger3_1
	call_if_unset 0x115E, NewBarkTown_EventScript_Trigger3_2
	call Route30_EventScript_Trigger3_2
	call NewBarkTown_EventScript_Trigger3_3
	msgbox NewBarkTown_Text_Trigger3, MSGBOX_AUTOCLOSE
	setflag 0x115F
	setflag 0x1098
	clearflag 0x1099
	release
	end

NewBarkTown_EventScript_Trigger3_1::
	release
	end

NewBarkTown_EventScript_Trigger3_2::
	call_if_set 0x1022, NewBarkTown_EventScript_Trigger3_4
	setflag 0x1021
	release
	end

NewBarkTown_EventScript_Trigger3_3::
	setvar 0x7031, 0x136
	setvar 0x7034, 0x136
	release
	return

NewBarkTown_EventScript_Trigger3_4::
	release
	end

NewBarkTown_EventScript_Trigger6::
	goto_if_unset 0x11EC, NewBarkTown_EventScript_Trigger6_1
	setflag 0x1152
	release
	end

NewBarkTown_EventScript_Trigger6_1::
	clearflag FLAG_WORLD_MAP_PALLET_TOWN
	clearflag 0x1360
	setflag 0x1152
	release
	end

NewBarkTown_EventScript_Sign1::
	msgbox NewBarkTown_Text_Sign1, MSGBOX_SIGN
	end

NewBarkTown_EventScript_Sign2::
	msgbox NewBarkTown_Text_Sign2, MSGBOX_SIGN
	end

NewBarkTown_EventScript_Sign3::
	msgbox NewBarkTown_Text_Sign3, MSGBOX_NPC
	end

NewBarkTown_EventScript_Sign4::
	msgbox NewBarkTown_Text_Sign4, MSGBOX_NPC
	end
