IndigoPlateau_Interior7_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

IndigoPlateau_Interior7_EventScript_Trigger1::
	playbgm MUS_NONE, 51
	applymovement LOCALID_PLAYER, IndigoPlateau_Interior7_Movement_Trigger1_1
	delay 112
	clearflag 0x115D
	applymovement LOCALID_PLAYER, IndigoPlateau_Interior7_Movement_Trigger1_2
	delay 16
	msgbox IndigoPlateau_Interior7_Text_Trigger1_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_ELITETRAINER_LANCE, 0, IndigoPlateau_Interior7_Text_Trigger1Defeat1, IndigoPlateau_Interior7_Text_Trigger1Victory1
	playbgm MUS_NONE, 51
	msgbox IndigoPlateau_Interior7_Text_Trigger1_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, IndigoPlateau_Interior7_Movement_Trigger1_3
	delay 1
	applymovement 1, IndigoPlateau_Interior7_Movement_Trigger1_4
	delay 64
	playbgm MUS_MYSTERY_GIFT, 51
	applymovement 3, IndigoPlateau_Interior7_Movement_Trigger1_5
	delay 128
	msgbox IndigoPlateau_Interior7_Text_Trigger1_3, MSGBOX_NPC
	applymovement 3, IndigoPlateau_Interior7_Movement_Trigger1_6
	delay 1
	applymovement 2, IndigoPlateau_Interior7_Movement_Trigger1_7
	delay 144
	applymovement 3, IndigoPlateau_Interior7_Movement_Trigger1_8
	delay 1
	msgbox IndigoPlateau_Interior7_Text_Trigger1_4, MSGBOX_NPC
	playbgm MUS_NONE, 51
	msgbox IndigoPlateau_Interior7_Text_Trigger1_5, MSGBOX_NPC
	applymovement 4, IndigoPlateau_Interior7_Movement_Trigger1_9
	delay 96
	applymovement 3, IndigoPlateau_Interior7_Movement_Trigger1_10
	delay 5
	applymovement 4, IndigoPlateau_Interior7_Movement_Trigger1_11
	delay 48
	applymovement 3, IndigoPlateau_Interior7_Movement_Trigger1_12
	delay 1
	applymovement 1, IndigoPlateau_Interior7_Movement_Trigger1_13
	delay 1
	applymovement LOCALID_PLAYER, IndigoPlateau_Interior7_Movement_Trigger1_14
	delay 1
	playbgm MUS_SLOW_PALLET, 51
	msgbox IndigoPlateau_Interior7_Text_Trigger1_6, MSGBOX_NPC
	msgbox IndigoPlateau_Interior7_Text_Trigger1_7, MSGBOX_NPC
	call IndigoPlateau_Interior7_EventScript_Trigger1_1
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_CARLOS_5, 0, IndigoPlateau_Interior7_Text_Trigger1Defeat2, IndigoPlateau_Interior7_Text_Trigger1Victory2
	setflag 0x115E
	playbgm MUS_NONE, 51
	call IndigoPlateau_Interior7_EventScript_Trigger1_2
	msgbox IndigoPlateau_Interior7_Text_Trigger1_8, MSGBOX_NPC
	msgbox IndigoPlateau_Interior7_Text_Trigger1_9, MSGBOX_NPC
	applymovement 4, IndigoPlateau_Interior7_Movement_Trigger1_15
	delay 128
	playbgm MUS_MYSTERY_GIFT, 51
	applymovement 3, IndigoPlateau_Interior7_Movement_Trigger1_16
	delay 64
	applymovement LOCALID_PLAYER, IndigoPlateau_Interior7_Movement_Trigger1_17
	delay 1
	msgbox IndigoPlateau_Interior7_Text_Trigger1_10, MSGBOX_NPC
	applymovement 1, IndigoPlateau_Interior7_Movement_Trigger1_18
	delay 48
	applymovement LOCALID_PLAYER, IndigoPlateau_Interior7_Movement_Trigger1_19
	delay 1
	msgbox IndigoPlateau_Interior7_Text_Trigger1_11, MSGBOX_NPC
	applymovement 1, IndigoPlateau_Interior7_Movement_Trigger1_20
	delay 1
	applymovement LOCALID_PLAYER, IndigoPlateau_Interior7_Movement_Trigger1_21
	delay 128
	applymovement 3, IndigoPlateau_Interior7_Movement_Trigger1_22
	delay 128
	msgbox IndigoPlateau_Interior7_Text_Trigger1_12, MSGBOX_NPC
	applymovement 3, IndigoPlateau_Interior7_Movement_Trigger1_23
	delay 112
	warp MAP_UNUSED_POKEMON_LEAGUE_HALL_OF_FAME, 0, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

IndigoPlateau_Interior7_EventScript_Trigger1_1::
	setvar 0x7030, 0x129
	setvar 0x7033, 0x159
	release
	return

IndigoPlateau_Interior7_EventScript_Trigger1_2::
	setvar 0x7030, 0x159
	setvar 0x7033, 0x129
	release
	return

IndigoPlateau_Interior7_Movement_Trigger1_1::
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_2::
	walk_up
	face_right
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_3::
	face_down_fast
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_4::
	face_down_fast
	emote_exclamation_mark
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_5::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_6::
	face_down_fast
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_7::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_8::
	face_left
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_9::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_10::
	emote_double_exclamation_mark
	walk_fast_right
	face_left
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_11::
	walk_up
	walk_up
	walk_up
	face_left
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_12::
	face_up
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_13::
	face_left
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_14::
	face_right
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_15::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_16::
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_17::
	face_down_fast
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_18::
	walk_left
	walk_left
	walk_left
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_19::
	face_right
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_20::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_21::
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_22::
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	emote_exclamation_mark
	step_end

IndigoPlateau_Interior7_Movement_Trigger1_23::
	walk_fast_right
	walk_fast_right
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_left
	walk_fast_left
	face_up
	step_end

IndigoPlateau_Interior7_EventScript_Trigger2::
	setptr 17, 0x11111111
	setptr 254, 0xFFFFFFFF
	.byte 0xFF @ invalid opcode (script stops)

IndigoPlateau_Interior7_EventScript_Trigger3::
	call IndigoPlateau_Interior7_EventScript_Trigger3_1
	release
	end

IndigoPlateau_Interior7_EventScript_Trigger3_1::
	setvar 0x7030, 0x128
	setvar 0x7031, 0x136
	setvar 0x7033, 0x12B
	setvar 0x7034, 0x138
	release
	return
