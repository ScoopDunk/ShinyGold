SSAqua_Interior5_MapScripts::
	.byte 0

SSAqua_Interior5_EventScript_Trigger1::
	goto_if_unset 0x1178, SSAqua_Interior2_EventScript_Trigger7
	warp MAP_SEA_CAVERN_INTERIOR4, 0, 0x26C, 0x6C00
	end

SSAqua_Interior5_EventScript_Trigger2::
	call_if_unset 0x1178, SSAqua_Interior2_EventScript_Trigger8_1
	call_if_set 0x1179, SSAqua_Interior2_EventScript_Trigger8_1
	msgbox SSAqua_Interior2_Text_Trigger8_1, MSGBOX_NPC
	applymovement 1, SSAqua_Interior2_Movement_Trigger8
	delay 1
	msgbox SSAqua_Interior2_Text_Trigger8_2, MSGBOX_NPC
	setmetatile 19, 1, 0x37C, 1
	applymovement LOCALID_PLAYER, SSAqua_Interior5_Movement_Trigger2_1
	delay 1
	applymovement 2, SSAqua_Interior5_Movement_Trigger2_2
	delay 112
	applymovement LOCALID_PLAYER, SSAqua_Interior5_Movement_Trigger2_3
	delay 64
	applymovement LOCALID_PLAYER, SSAqua_Interior5_Movement_Trigger2_4
	delay 96
	msgbox SSAqua_Interior5_Text_Trigger2_1, MSGBOX_NPC
	applymovement 1, SSAqua_Interior5_Movement_Trigger2_5
	delay 1
	applymovement 2, SSAqua_Interior5_Movement_Trigger2_6
	delay 48
	msgbox SSAqua_Interior5_Text_Trigger2_2, MSGBOX_NPC
	applymovement 2, SSAqua_Interior5_Movement_Trigger2_7
	delay 1
	applymovement 1, SSAqua_Interior5_Movement_Trigger2_8
	delay 48
	setflag 0x1179
	setflag 0x116C
	release
	end

SSAqua_Interior5_Movement_Trigger2_1::
	jump_in_place_up
	emote_double_exclamation_mark
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_Interior5_Movement_Trigger2_2::
	jump_in_place_right
	emote_double_exclamation_mark
	step_end

SSAqua_Interior5_Movement_Trigger2_3::
	emote_question_mark
	step_end

SSAqua_Interior5_Movement_Trigger2_4::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SSAqua_Interior5_Movement_Trigger2_5::
	walk_down
	face_up
	step_end

SSAqua_Interior5_Movement_Trigger2_6::
	walk_fast_right
	face_up
	emote_question_mark
	step_end

SSAqua_Interior5_Movement_Trigger2_7::
	set_invisible
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_Interior5_Movement_Trigger2_8::
	walk_up
	set_invisible
	walk_fast_right
	walk_fast_right
	step_end
