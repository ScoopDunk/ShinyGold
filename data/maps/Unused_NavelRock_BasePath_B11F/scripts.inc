Unused_NavelRock_BasePath_B11F_MapScripts::
	.byte 0

Unused_NavelRock_BasePath_B11F_EventScript_TeamRocketGrunt12::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_12, Unused_NavelRock_BasePath_B11F_Text_TeamRocketGrunt12Intro, Unused_NavelRock_BasePath_B11F_Text_TeamRocketGrunt12Defeat
	msgbox Unused_NavelRock_BasePath_B11F_Text_TeamRocketGrunt12, MSGBOX_AUTOCLOSE
	end

Unused_NavelRock_BasePath_B11F_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

Unused_NavelRock_BasePath_B11F_EventScript_ItemTm46::
	finditem ITEM_TM46
	end

Unused_NavelRock_BasePath_B11F_EventScript_TeamRocketGrunt26::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_26, Unused_NavelRock_BasePath_B11F_Text_TeamRocketGrunt26Intro, Unused_NavelRock_BasePath_B11F_Text_TeamRocketGrunt26Defeat
	msgbox Unused_NavelRock_BasePath_B11F_Text_TeamRocketGrunt26, MSGBOX_AUTOCLOSE
	end

Unused_NavelRock_BasePath_B11F_EventScript_ItemBall::
	release
	end

Unused_NavelRock_BasePath_B11F_EventScript_ItemBall4::
	waitse
	playmoncry SPECIES_ELECTRODE, 0x2800
	waitse
	nop
	delay 48
	clearflag 0x1100
	clearflag 0x1104
	clearflag 0x1103
	setwildbattle SPECIES_ELECTRODE, 23
	special StartSouthernIslandBattle
	delay 128
	setflag 0x1100
	setflag 0x1104
	setflag 0x1103
	setflag 0x1105
	applymovement 11, Unused_NavelRock_BasePath_B11F_Movement_ItemBall4
	delay 64
	end

Unused_NavelRock_BasePath_B11F_Movement_ItemBall4::
	set_invisible
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Unused_NavelRock_BasePath_B11F_EventScript_ItemBall5::
	waitse
	playmoncry SPECIES_ELECTRODE, 0x2800
	waitse
	nop
	delay 48
	clearflag 0x1100
	clearflag 0x1104
	clearflag 0x1103
	setwildbattle SPECIES_ELECTRODE, 23
	special StartSouthernIslandBattle
	delay 128
	setflag 0x1100
	setflag 0x1104
	setflag 0x1103
	setflag 0x1106
	applymovement 12, Unused_NavelRock_BasePath_B11F_Movement_ItemBall4
	delay 64
	end

Unused_NavelRock_BasePath_B11F_EventScript_ItemBall6::
	waitse
	playmoncry SPECIES_ELECTRODE, 0x2800
	waitse
	nop
	delay 48
	clearflag 0x1100
	clearflag 0x1104
	clearflag 0x1103
	setwildbattle SPECIES_ELECTRODE, 23
	special StartSouthernIslandBattle
	delay 128
	setflag 0x1100
	setflag 0x1104
	setflag 0x1103
	setflag 0x1107
	applymovement 13, Unused_NavelRock_BasePath_B11F_Movement_ItemBall4
	delay 64
	end

Unused_NavelRock_BasePath_B11F_EventScript_Meteorite::
	call_if_unset 0x10F9, Unused_NavelRock_BasePath_B11F_EventScript_Meteorite_1
	msgbox Unused_NavelRock_BasePath_B11F_Text_Meteorite_1, MSGBOX_NPC
	setflag 0x10F7
	warp MAP_UNUSED_NAVEL_ROCK_BASE_PATH_B11F, 1, 0x202, 0xF729
	@ ShinyGold fix: the engine keeps running a script during the warp fade, so the hack's leftover bytes
	@ that followed this warp executed (garbage calls, stray text, RAM writes). The script now ends here.
	end

Unused_NavelRock_BasePath_B11F_EventScript_Meteorite_1::
	msgbox Unused_NavelRock_BasePath_B11F_Text_Meteorite_2, MSGBOX_NPC
	end

Unused_NavelRock_BasePath_B11F_EventScript_TeamRocketGrunt27::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_27, Unused_NavelRock_BasePath_B11F_Text_TeamRocketGrunt27Intro, Unused_NavelRock_BasePath_B11F_Text_TeamRocketGrunt27Defeat
	msgbox Unused_NavelRock_BasePath_B11F_Text_TeamRocketGrunt27, MSGBOX_AUTOCLOSE
	end

Unused_NavelRock_BasePath_B11F_EventScript_Lance::
	call_if_unset 0x1105, Unused_NavelRock_BasePath_B11F_EventScript_Lance_1
	call_if_unset 0x1106, Unused_NavelRock_BasePath_B11F_EventScript_Lance_1
	call_if_unset 0x1107, Unused_NavelRock_BasePath_B11F_EventScript_Lance_1
	msgbox Unused_NavelRock_BasePath_B11F_Text_Lance_1, MSGBOX_NPC
	playfanfare MUS_SLOTS_WIN
	msgbox Unused_NavelRock_BasePath_B11F_Text_Lance_2, MSGBOX_NPC
	msgbox Unused_NavelRock_BasePath_B11F_Text_Lance_3, MSGBOX_NPC
	applymovement 17, Unused_NavelRock_BasePath_B11F_Movement_Lance_1
	msgbox Unused_NavelRock_BasePath_B11F_Text_Lance_4, MSGBOX_AUTOCLOSE
	applymovement 17, Unused_NavelRock_BasePath_B11F_Movement_Lance_2
	delay 160
	setflag 0x1102
	setflag 0x10EC
	setflag 0x10E3
	clearflag 0x10DB
	.byte 0x79 @ givemon
	.2byte SPECIES_CLAMPERL
	.byte 25
	.2byte ITEM_NONE
	.4byte 0xFFFF026C
	.4byte 0xFFFFFFFF
	.byte 255
	.byte 0xFF @ invalid opcode (script stops)

Unused_NavelRock_BasePath_B11F_EventScript_Lance_1::
	setflag 0x1104
	applymovement LOCALID_PLAYER, Unused_NavelRock_BasePath_B11F_Movement_Lance_3
	msgbox Unused_NavelRock_BasePath_B11F_Text_Lance_5, MSGBOX_NPC
	msgbox Unused_NavelRock_BasePath_B11F_Text_Lance_6, MSGBOX_NPC
	applymovement 17, Unused_NavelRock_BasePath_B11F_Movement_Lance_4
	applymovement LOCALID_PLAYER, Unused_NavelRock_BasePath_B11F_Movement_Lance_4
	delay 64
	applymovement 17, Unused_NavelRock_BasePath_B11F_Movement_Lance_5
	delay 64
	applymovement 17, Unused_NavelRock_BasePath_B11F_Movement_Lance_6
	delay 48
	applymovement 17, Unused_NavelRock_BasePath_B11F_Movement_Lance_7
	delay 48
	msgbox Unused_NavelRock_BasePath_B11F_Text_Lance_7, MSGBOX_NPC
	applymovement 17, Unused_NavelRock_BasePath_B11F_Movement_Lance_8
	delay 112
	applymovement LOCALID_PLAYER, Unused_NavelRock_BasePath_B11F_Movement_Lance_9
	delay 64
	end

Unused_NavelRock_BasePath_B11F_Movement_Lance_1::
	face_down_fast
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Lance_2::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	set_invisible
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Lance_3::
	face_up
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Lance_4::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Lance_5::
	walk_left
	walk_left
	walk_left
	face_up
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Lance_6::
	walk_right
	walk_right
	face_up
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Lance_7::
	walk_right
	face_down_fast
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Lance_8::
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Lance_9::
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Unused_NavelRock_BasePath_B11F_EventScript_Trigger1::
	call_if_set 0x10F3, Unused_NavelRock_BasePath_B11F_EventScript_Trigger1_1
	setflag 0x10F3
	applymovement LOCALID_PLAYER, Unused_NavelRock_BasePath_B11F_Movement_Trigger1_1
	delay 1
	applymovement 1, Unused_NavelRock_BasePath_B11F_Movement_Trigger1_2
	msgbox Unused_NavelRock_BasePath_B11F_Text_Trigger1_1, MSGBOX_NPC
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox Unused_NavelRock_BasePath_B11F_Text_Trigger1_2, MSGBOX_NPC
	applymovement 1, Unused_NavelRock_BasePath_B11F_Movement_Trigger1_3
	delay 160
	end

Unused_NavelRock_BasePath_B11F_EventScript_Trigger1_1::
	release
	end

Unused_NavelRock_BasePath_B11F_Movement_Trigger1_1::
	face_right
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Trigger1_2::
	face_left
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Trigger1_3::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	set_invisible
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Unused_NavelRock_BasePath_B11F_EventScript_Trigger2::
	call_if_set 0x10F3, Unused_NavelRock_BasePath_B11F_EventScript_Trigger1_1
	setflag 0x10F3
	applymovement LOCALID_PLAYER, Unused_NavelRock_BasePath_B11F_Movement_Trigger2_1
	delay 1
	applymovement 1, Unused_NavelRock_BasePath_B11F_Movement_Trigger2_2
	msgbox Unused_NavelRock_BasePath_B11F_Text_Trigger1_1, MSGBOX_NPC
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox Unused_NavelRock_BasePath_B11F_Text_Trigger1_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Unused_NavelRock_BasePath_B11F_Movement_Trigger2_3
	delay 16
	applymovement 1, Unused_NavelRock_BasePath_B11F_Movement_Trigger1_3
	delay 176
	end

Unused_NavelRock_BasePath_B11F_Movement_Trigger2_1::
	face_up
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Trigger2_2::
	face_down_fast
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Trigger2_3::
	walk_left
	face_right
	step_end

Unused_NavelRock_BasePath_B11F_EventScript_Trigger3::
	call_if_set 0x1100, Unused_NavelRock_BasePath_B11F_EventScript_Trigger3_1
	msgbox Unused_NavelRock_BasePath_B11F_Text_Trigger3_1, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Unused_NavelRock_BasePath_B11F_Movement_Trigger3_1
	delay 48
	clearflag 0x10F2
	clearflag 0x1101
	applymovement LOCALID_PLAYER, Unused_NavelRock_BasePath_B11F_Movement_Trigger3_2
	delay 32
	playbgm MUS_ENCOUNTER_GYM_LEADER, 51
	applymovement 3, Unused_NavelRock_BasePath_B11F_Movement_Trigger3_3
	delay 112
	applymovement LOCALID_PLAYER, Unused_NavelRock_BasePath_B11F_Movement_Trigger3_4
	applymovement 4, Unused_NavelRock_BasePath_B11F_Movement_Trigger3_5
	delay 80
	msgbox Unused_NavelRock_BasePath_B11F_Text_Trigger3_2, MSGBOX_NPC
	delay 16
	waitse
	playmoncry SPECIES_DRAGONITE, 0x2800
	waitse
	nop
	applymovement LOCALID_PLAYER, Unused_NavelRock_BasePath_B11F_Movement_Trigger3_6
	applymovement 3, Unused_NavelRock_BasePath_B11F_Movement_Trigger3_7
	delay 16
	applymovement 4, Unused_NavelRock_BasePath_B11F_Movement_Trigger3_8
	delay 16
	applymovement 16, Unused_NavelRock_BasePath_B11F_Movement_Trigger3_9
	delay 128
	msgbox Unused_NavelRock_BasePath_B11F_Text_Trigger3_3, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Unused_NavelRock_BasePath_B11F_Movement_Trigger3_10
	applymovement 3, Unused_NavelRock_BasePath_B11F_Movement_Trigger3_11
	delay 32
	msgbox Unused_NavelRock_BasePath_B11F_Text_Trigger3_4, MSGBOX_NPC
	applymovement 3, Unused_NavelRock_BasePath_B11F_Movement_Trigger3_12
	applymovement 4, Unused_NavelRock_BasePath_B11F_Movement_Trigger3_12
	delay 16
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_EXECUTIVE_3, 0, Unused_NavelRock_BasePath_B11F_Text_Trigger3Defeat, Unused_NavelRock_BasePath_B11F_Text_Trigger3Victory
	setflag 0x1100
	setflag 0x10F2
	setflag 0x1103
	setflag 0x1101
	clearflag 0x1102
	clearflag 0x10D6
	msgbox Unused_NavelRock_BasePath_B11F_Text_Trigger3_5, MSGBOX_NPC
	delay 16
	warp MAP_UNUSED_NAVEL_ROCK_BASE_PATH_B11F, 6, 0x5702, 0x878
	@ ShinyGold fix: the engine keeps running a script during the warp fade, so the hack's leftover bytes
	@ that followed this warp executed (garbage calls, stray text, RAM writes). The script now ends here.
	end

Unused_NavelRock_BasePath_B11F_EventScript_Trigger3_1::
	release
	end

Unused_NavelRock_BasePath_B11F_Movement_Trigger3_1::
	face_down_fast
	emote_exclamation_mark
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Trigger3_2::
	walk_down
	walk_down
	walk_down
	face_right
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Trigger3_3::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_left
	walk_fast_left
	face_down_fast
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Trigger3_4::
	face_up
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Trigger3_5::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Trigger3_6::
	face_left
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Trigger3_7::
	walk_fast_right
	walk_fast_right
	face_left
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Trigger3_8::
	walk_fast_left
	walk_fast_up
	face_left
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Trigger3_9::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Trigger3_10::
	face_right
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Trigger3_11::
	walk_slow_down
	face_left
	step_end

Unused_NavelRock_BasePath_B11F_Movement_Trigger3_12::
	walk_fast_left
	step_end

Unused_NavelRock_BasePath_B11F_EventScript_Trigger4::
	call_if_set 0x1104, Unused_NavelRock_BasePath_B11F_EventScript_Trigger3_1
	call_if_unset 0x1103, Unused_NavelRock_BasePath_B11F_EventScript_Trigger3_1
	applymovement LOCALID_PLAYER, Unused_NavelRock_BasePath_B11F_Movement_Trigger4
	delay 16
	end

Unused_NavelRock_BasePath_B11F_Movement_Trigger4::
	walk_right
	face_up
	step_end

Unused_NavelRock_BasePath_B11F_EventScript_Trigger5::
	call_if_set 0x1104, Unused_NavelRock_BasePath_B11F_EventScript_Trigger3_1
	call_if_unset 0x1103, Unused_NavelRock_BasePath_B11F_EventScript_Trigger3_1
	applymovement LOCALID_PLAYER, Unused_NavelRock_BasePath_B11F_Movement_Trigger5
	delay 16
	end

Unused_NavelRock_BasePath_B11F_Movement_Trigger5::
	walk_left
	face_up
	step_end

Unused_NavelRock_BasePath_B11F_EventScript_Trigger6::
	call_if_unset 0x1105, Unused_NavelRock_BasePath_B11F_EventScript_Trigger6_1
	call_if_unset 0x1106, Unused_NavelRock_BasePath_B11F_EventScript_Trigger6_1
	call_if_unset 0x1107, Unused_NavelRock_BasePath_B11F_EventScript_Trigger6_1
	release
	end

Unused_NavelRock_BasePath_B11F_EventScript_Trigger6_1::
	msgbox Unused_NavelRock_BasePath_B11F_Text_Trigger6, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Unused_NavelRock_BasePath_B11F_Movement_Trigger6
	end

Unused_NavelRock_BasePath_B11F_Movement_Trigger6::
	walk_left
	step_end
