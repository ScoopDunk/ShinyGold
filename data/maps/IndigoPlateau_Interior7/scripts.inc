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
	setflag 0x115E
	call IndigoPlateau_Interior7_EventScript_Trigger1_2
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
	applymovement 3, IndigoPlateau_Interior7_Movement_MaryInterview
	delay 64
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
	warp MAP_INDIGO_PLATEAU_HALL_OF_FAME, 0, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

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

IndigoPlateau_Interior7_Movement_MaryInterview::
	walk_up
	walk_left
	walk_left
	face_up
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
