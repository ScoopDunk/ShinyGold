SSAqua_Interior2_MapScripts::
	.byte 0

SSAqua_Interior2_EventScript_Sailor::
	call_if_set 0x11A9, SSAqua_Interior2_EventScript_Sailor_1
	call_if_set 0x1164, SSAqua_Interior2_EventScript_Sailor_2
	msgbox SSAqua_Interior2_Text_Sailor_1, MSGBOX_NPC
	end

SSAqua_Interior2_EventScript_Sailor_1::
	call_if_unset 0x1165, SSAqua_Interior2_EventScript_Sailor_3
	msgbox SSAqua_Interior2_Text_Sailor_2, MSGBOX_NPC
	call SSAqua_Interior2_EventScript_Sailor_4
	warp MAP_OLIVINE_CITY_AREA1, 1, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SSAqua_Interior2_EventScript_Sailor_2::
	call_if_set 0x1165, SSAqua_Interior2_EventScript_Sailor_5
	msgbox SSAqua_Interior2_Text_Sailor_3, MSGBOX_NPC
	end

SSAqua_Interior2_EventScript_Sailor_3::
	msgbox SSAqua_Interior2_Text_Sailor_4, MSGBOX_NPC
	call SSAqua_Interior2_EventScript_Sailor_6
	warp MAP_VERMILION_CITY_AREA1, 1, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SSAqua_Interior2_EventScript_Sailor_4::
	setflag 0x1196
	setflag 0x1197
	setflag 0x1198
	setflag 0x1199
	setflag 0x119A
	setflag 0x119B
	setflag 0x119C
	setflag 0x119D
	setflag 0x119E
	setflag 0x119F
	clearflag 0x1165
	special DaisyMassageServices
	return

SSAqua_Interior2_EventScript_Sailor_5::
	msgbox SSAqua_Interior2_Text_Sailor_5, MSGBOX_NPC
	end

SSAqua_Interior2_EventScript_Sailor_6::
	setflag 0x11A0
	setflag 0x11A1
	setflag 0x11A2
	setflag 0x11A3
	setflag 0x11A4
	setflag 0x11A5
	setflag 0x11A6
	setflag 0x11A7
	setflag 0x11A8
	special DaisyMassageServices
	return

SSAqua_Interior2_EventScript_Gentleman::
	msgbox SSAqua_Interior2_Text_Gentleman, MSGBOX_NPC
	end

SSAqua_Interior2_EventScript_Sailor2::
	msgbox SSAqua_Interior2_Text_Sailor2, MSGBOX_NPC
	end

SSAqua_Interior2_EventScript_Sailor3::
	msgbox SSAqua_Interior2_Text_Sailor3, MSGBOX_NPC
	end

SSAqua_Interior2_EventScript_Trigger1::
	call_if_set 0x1164, SSAqua_Interior2_EventScript_Trigger1_1
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 9
	setvar VAR_0x8007, 2
	special ShakeScreen
	delay 30
	playfanfare MUS_DUMMY
	setflag 0x1164
	call_if_set 0x1165, SSAqua_Interior2_EventScript_Trigger1_2
	msgbox SSAqua_Interior2_Text_Trigger1_1, MSGBOX_AUTOCLOSE
	call SSAqua_Interior2_EventScript_Trigger1_3
	end

SSAqua_Interior2_EventScript_Trigger1_1::
	release
	end

SSAqua_Interior2_EventScript_Trigger1_2::
	msgbox SSAqua_Interior2_Text_Trigger1_2, MSGBOX_AUTOCLOSE
	call SSAqua_Interior2_EventScript_Trigger1_3
	end

SSAqua_Interior2_EventScript_Trigger1_3::
	call_if_unset 0x1177, SSAqua_Interior2_EventScript_Trigger1_4
	call_if_unset 0x1165, SSAqua_Interior2_EventScript_Trigger1_5
	call_if_set 0x1165, SSAqua_Interior2_EventScript_Trigger1_6
	end

SSAqua_Interior2_EventScript_Trigger1_4::
	clearflag 0x1176
	setflag 0x1174
	setflag 0x1175
	end

SSAqua_Interior2_EventScript_Trigger1_5::
	clearflag 0x1174
	setflag 0x1175
	setflag 0x1176
	end

SSAqua_Interior2_EventScript_Trigger1_6::
	clearflag 0x1175
	setflag 0x1174
	setflag 0x1176
	end

SSAqua_Interior2_EventScript_Trigger3::
	call_if_set 0x1172, SSAqua_Interior2_EventScript_Trigger3_1
	call_if_unset 0x1170, SSAqua_Interior2_EventScript_Trigger3_1
	call SSAqua_Interior2_EventScript_Trigger3_2
	end

SSAqua_Interior2_EventScript_Trigger3_1::
	release
	end

SSAqua_Interior2_EventScript_Trigger3_2::
	msgbox SSAqua_Interior2_Text_Trigger3_1, MSGBOX_AUTOCLOSE
	clearflag 0x116A
	applymovement LOCALID_PLAYER, SSAqua_Interior2_Movement_Trigger3_1
	delay 16
	applymovement 8, SSAqua_Interior2_Movement_Trigger3_2
	delay 1
	applymovement 7, SSAqua_Interior2_Movement_Trigger3_3
	delay 192
	msgbox SSAqua_Interior2_Text_Trigger3_2, MSGBOX_NPC
	delay 16
	msgbox SSAqua_Interior2_Text_Trigger3_3, MSGBOX_NPC
	playbgm MUS_NONE, 51
	msgbox SSAqua_Interior2_Text_Trigger3_4, MSGBOX_NPC
	applymovement 8, SSAqua_Interior2_Movement_Trigger3_4
	delay 16
	msgbox SSAqua_Interior2_Text_Trigger3_5, MSGBOX_NPC
	applymovement 8, SSAqua_Interior2_Movement_Trigger3_5
	delay 1
	msgbox SSAqua_Interior2_Text_Trigger3_6, MSGBOX_NPC
	applymovement 7, SSAqua_Interior2_Movement_Trigger3_6
	delay 1
	applymovement 8, SSAqua_Interior2_Movement_Trigger3_6
	delay 16
	clearflag 0x116B
	applymovement LOCALID_PLAYER, SSAqua_Interior2_Movement_Trigger3_7
	delay 1
	playbgm MUS_ENCOUNTER_BOY, 51
	msgbox SSAqua_Interior2_Text_Trigger3_7, MSGBOX_NPC
	msgbox SSAqua_Interior2_Text_Trigger3_8, MSGBOX_NPC
	msgbox SSAqua_Interior2_Text_Trigger3_9, MSGBOX_NPC
	playbgm MUS_NONE, 51
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 9
	setvar VAR_0x8007, 2
	special ShakeScreen
	delay 1
	msgbox SSAqua_Interior2_Text_Trigger3_10, MSGBOX_NPC
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 9
	setvar VAR_0x8007, 2
	special ShakeScreen
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 9
	setvar VAR_0x8007, 2
	special ShakeScreen
	delay 1
	msgbox SSAqua_Interior2_Text_Trigger3_11, MSGBOX_NPC
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 9
	setvar VAR_0x8007, 2
	special ShakeScreen
	delay 30
	applymovement LOCALID_PLAYER, SSAqua_Interior2_Movement_Trigger3_8
	delay 1
	applymovement 10, SSAqua_Interior2_Movement_Trigger3_9
	delay 1
	applymovement 9, SSAqua_Interior2_Movement_Trigger3_10
	delay 1
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 15
	setvar VAR_0x8005, 15
	setvar VAR_0x8006, 15
	setvar VAR_0x8007, 5
	special ShakeScreen
	delay 32
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 15
	setvar VAR_0x8005, 15
	setvar VAR_0x8006, 15
	setvar VAR_0x8007, 5
	special ShakeScreen
	delay 64
	playse SE_LAVARIDGE_FALL_WARP @ ShinyGold fix: was playbgm (the sound effect replaced the map music until the next map)
	delay 16
	playse SE_LAVARIDGE_FALL_WARP @ ShinyGold fix: was playbgm (the sound effect replaced the map music until the next map)
	delay 16
	fadescreen FADE_TO_BLACK
	playse SE_LAVARIDGE_FALL_WARP @ ShinyGold fix: was playbgm (the sound effect replaced the map music until the next map)
	delay 16
	playse SE_LAVARIDGE_FALL_WARP @ ShinyGold fix: was playbgm (the sound effect replaced the map music until the next map)
	delay 16
	playse SE_LAVARIDGE_FALL_WARP @ ShinyGold fix: was playbgm (the sound effect replaced the map music until the next map)
	delay 16
	playse SE_LAVARIDGE_FALL_WARP @ ShinyGold fix: was playbgm (the sound effect replaced the map music until the next map)
	delay 16
	playse SE_LAVARIDGE_FALL_WARP @ ShinyGold fix: was playbgm (the sound effect replaced the map music until the next map)
	delay 16
	msgbox SSAqua_Interior2_Text_Trigger3_12, MSGBOX_AUTOCLOSE
	clearflag 0x116D
	call SSAqua_Interior2_EventScript_Trigger3_3
	warp MAP_SS_AQUA_INTERIOR6, 2, 0x26C, 0x26C
	.byte 0xFF @ invalid opcode (script stops)

SSAqua_Interior2_EventScript_Trigger3_3::
	setflag 0x1172
	setflag 0x1173
	setflag 0x1174
	setflag 0x1175
	setflag 0x1176
	setflag 0x116B
	setflag 0x1171
	setflag 0x116A
	return

SSAqua_Interior2_Movement_Trigger3_1::
	walk_up
	emote_question_mark
	step_end

SSAqua_Interior2_Movement_Trigger3_2::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAqua_Interior2_Movement_Trigger3_3::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

SSAqua_Interior2_Movement_Trigger3_4::
	face_left
	emote_exclamation_mark
	step_end

SSAqua_Interior2_Movement_Trigger3_5::
	face_down_fast
	step_end

SSAqua_Interior2_Movement_Trigger3_6::
	face_left
	face_up
	face_right
	face_down_fast
	face_left
	face_up
	face_right
	face_down_fast
	face_left
	face_up
	face_right
	face_down_fast
	face_left
	face_up
	face_right
	face_down_fast
	set_invisible
	step_end

SSAqua_Interior2_Movement_Trigger3_7::
	walk_fast_down
	face_up
	step_end

SSAqua_Interior2_Movement_Trigger3_8::
	jump_special_down
	jump_special_left
	set_invisible
	step_end

SSAqua_Interior2_Movement_Trigger3_9::
	jump_2_down
	jump_left
	jump_down
	set_invisible
	step_end

SSAqua_Interior2_Movement_Trigger3_10::
	jump_left
	jump_down
	jump_left
	jump_2_down
	set_invisible
	step_end

SSAqua_Interior2_EventScript_Trigger4::
	call_if_set 0x1166, SSAqua_Interior2_EventScript_Trigger4_1
	applymovement 2, SSAqua_Interior2_Movement_Trigger4_1
	delay 58
	applymovement LOCALID_PLAYER, SSAqua_Interior2_Movement_Trigger4_2
	delay 1
	applymovement 2, SSAqua_Interior2_Movement_Trigger4_2
	delay 32
	call SSAqua_Interior2_EventScript_Trigger4_2
	end

SSAqua_Interior2_EventScript_Trigger4_1::
	release
	end

SSAqua_Interior2_EventScript_Trigger4_2::
	applymovement LOCALID_PLAYER, SSAqua_Interior2_Movement_Trigger4_3
	delay 1
	msgbox SSAqua_Interior2_Text_Trigger4_1, MSGBOX_NPC
	msgbox SSAqua_Interior2_Text_Trigger4_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, SSAqua_Interior2_Movement_Trigger4_4
	delay 1
	applymovement 3, SSAqua_Interior2_Movement_Trigger4_5
	delay 1
	applymovement 4, SSAqua_Interior2_Movement_Trigger4_5
	delay 192
	msgbox SSAqua_Interior2_Text_Trigger4_3, MSGBOX_NPC
	applymovement 3, SSAqua_Interior2_Movement_Trigger4_6
	delay 1
	applymovement 4, SSAqua_Interior2_Movement_Trigger4_6
	delay 192
	applymovement LOCALID_PLAYER, SSAqua_Interior2_Movement_Trigger4_3
	delay 1
	msgbox SSAqua_Interior2_Text_Trigger4_4, MSGBOX_NPC
	applymovement 2, SSAqua_Interior2_Movement_Trigger4_7
	delay 160
	setflag 0x1166
	release
	end

SSAqua_Interior2_Movement_Trigger4_1::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_Interior2_Movement_Trigger4_2::
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_Interior2_Movement_Trigger4_3::
	face_left
	step_end

SSAqua_Interior2_Movement_Trigger4_4::
	face_right
	step_end

SSAqua_Interior2_Movement_Trigger4_5::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SSAqua_Interior2_Movement_Trigger4_6::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_Interior2_Movement_Trigger4_7::
	walk_fast_down
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
	walk_fast_down
	set_invisible
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_Interior2_EventScript_Trigger5::
	call_if_set 0x1166, SSAqua_Interior2_EventScript_Trigger4_1
	applymovement 2, SSAqua_Interior2_Movement_Trigger5
	delay 66
	applymovement LOCALID_PLAYER, SSAqua_Interior2_Movement_Trigger4_2
	delay 1
	applymovement 2, SSAqua_Interior2_Movement_Trigger4_2
	delay 32
	call SSAqua_Interior2_EventScript_Trigger4_2
	end

SSAqua_Interior2_Movement_Trigger5::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_Interior2_EventScript_Trigger6::
	call_if_set 0x1172, SSAqua_Interior2_EventScript_Trigger3_1
	call_if_unset 0x1170, SSAqua_Interior2_EventScript_Trigger3_1
	applymovement LOCALID_PLAYER, SSAqua_Interior2_Movement_Trigger6
	delay 32
	call SSAqua_Interior2_EventScript_Trigger3_2
	end

SSAqua_Interior2_Movement_Trigger6::
	walk_up
	walk_up
	step_end

SSAqua_Interior2_EventScript_Trigger7::
	applymovement LOCALID_PLAYER, SSAqua_Interior2_Movement_Trigger7
	delay 16
	release
	end

SSAqua_Interior2_Movement_Trigger7::
	walk_down
	step_end

SSAqua_Interior2_EventScript_Trigger8_1::
	release
	end

SSAqua_Interior2_Movement_Trigger8::
	face_up
	step_end
