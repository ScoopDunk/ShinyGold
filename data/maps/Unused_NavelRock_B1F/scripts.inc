Unused_NavelRock_B1F_MapScripts::
	.byte 0

Unused_NavelRock_B1F_EventScript_RocketM::
	msgbox Unused_NavelRock_B1F_Text_RocketM, MSGBOX_NPC
	end

Unused_NavelRock_B1F_EventScript_ItemProtein::
	finditem ITEM_PROTEIN
	end

Unused_NavelRock_B1F_EventScript_ScientistRoss::
	trainerbattle_single TRAINER_SCIENTIST_ROSS, Unused_NavelRock_B1F_Text_ScientistRossIntro, Unused_NavelRock_B1F_Text_ScientistRossDefeat
	msgbox Unused_NavelRock_B1F_Text_ScientistRoss, MSGBOX_AUTOCLOSE
	end

Unused_NavelRock_B1F_EventScript_TeamRocketGrunt15::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_15, Unused_NavelRock_B1F_Text_TeamRocketGrunt15Intro, Unused_NavelRock_B1F_Text_TeamRocketGrunt15Defeat
	setflag 0x10F5
	msgbox Unused_NavelRock_B1F_Text_TeamRocketGrunt15, MSGBOX_AUTOCLOSE
	end

Unused_NavelRock_B1F_EventScript_ScientistMitch::
	trainerbattle_single TRAINER_SCIENTIST_MITCH, Unused_NavelRock_B1F_Text_ScientistMitchIntro, Unused_NavelRock_B1F_Text_ScientistMitchDefeat
	msgbox Unused_NavelRock_B1F_Text_ScientistMitch, MSGBOX_AUTOCLOSE
	end

Unused_NavelRock_B1F_EventScript_TeamRocketGrunt28::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_28, Unused_NavelRock_B1F_Text_TeamRocketGrunt28Intro, Unused_NavelRock_B1F_Text_TeamRocketGrunt28Defeat
	setflag 0x10F6
	msgbox Unused_NavelRock_B1F_Text_TeamRocketGrunt28, MSGBOX_AUTOCLOSE
	end

Unused_NavelRock_B1F_EventScript_ItemDireHit::
	finditem ITEM_DIRE_HIT
	end

Unused_NavelRock_B1F_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

Unused_NavelRock_B1F_EventScript_Meteorite::
	call_if_unset 0x10F5, Unused_NavelRock_B1F_EventScript_Meteorite_1
	call_if_unset 0x10F6, Unused_NavelRock_B1F_EventScript_Meteorite_1
	msgbox Unused_NavelRock_B1F_Text_Meteorite_1, MSGBOX_NPC
	setflag 0x10FA
	warp MAP_UNUSED_NAVEL_ROCK_B1F, 1, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_NavelRock_B1F_EventScript_Meteorite_1::
	msgbox Unused_NavelRock_B1F_Text_Meteorite_2, MSGBOX_NPC
	end

Unused_NavelRock_B1F_EventScript_ItemIceHeal::
	finditem ITEM_ICE_HEAL
	end

Unused_NavelRock_B1F_EventScript_RocketM2::
	msgbox Unused_NavelRock_B1F_Text_RocketM2, MSGBOX_NPC
	end

Unused_NavelRock_B1F_EventScript_RocketF::
	msgbox Unused_NavelRock_B1F_Text_RocketF, MSGBOX_NPC
	end

Unused_NavelRock_B1F_EventScript_Pidgeot::
	setflag 0x10F9
	msgbox Unused_NavelRock_B1F_Text_Pidgeot, MSGBOX_NPC
	end

Unused_NavelRock_B1F_EventScript_Trigger1::
	call_if_set 0x10F8, Unused_NavelRock_B1F_EventScript_Trigger1_1
	setflag 0x10FB
	setflag 0x10F8
	applymovement LOCALID_PLAYER, Unused_NavelRock_B1F_Movement_Trigger1_1
	delay 1
	applymovement 1, Unused_NavelRock_B1F_Movement_Trigger1_2
	msgbox Unused_NavelRock_B1F_Text_Trigger1, MSGBOX_NPC
	applymovement 1, Unused_NavelRock_B1F_Movement_Trigger1_3
	delay 0x26C
	end

Unused_NavelRock_B1F_EventScript_Trigger1_1::
	@ ShinyGold: overlapping data duplicated from 0x08784280
	release
	end

Unused_NavelRock_B1F_Movement_Trigger1_1::
	face_right
	step_end

Unused_NavelRock_B1F_Movement_Trigger1_2::
	face_left
	step_end

Unused_NavelRock_B1F_Movement_Trigger1_3::
	walk_down
	walk_left
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
	step_end

Unused_NavelRock_B1F_EventScript_Trigger2::
	call_if_set 0x10F8, Unused_NavelRock_B1F_EventScript_Trigger1_1
	setflag 0x10FB
	setflag 0x10F8
	applymovement LOCALID_PLAYER, Unused_NavelRock_B1F_Movement_Trigger2
	delay 1
	msgbox Unused_NavelRock_B1F_Text_Trigger1, MSGBOX_NPC
	applymovement 1, Unused_NavelRock_B1F_Movement_Trigger1_3
	delay 176
	end

Unused_NavelRock_B1F_Movement_Trigger2::
	face_down_fast
	step_end

Unused_NavelRock_B1F_EventScript_Trigger3::
	call_if_set 0x10FC, Unused_NavelRock_B1F_EventScript_Trigger3_1
	clearflag 0x10FB
	applymovement LOCALID_PLAYER, Unused_NavelRock_B1F_Movement_Trigger3_1
	delay 16
	playbgm MUS_NONE, 51
	applymovement 10, Unused_NavelRock_B1F_Movement_Trigger3_2
	delay 144
	playbgm MUS_ENCOUNTER_RIVAL, 51
	setflag 0x10FB
	setflag 0x10FC
	msgbox Unused_NavelRock_B1F_Text_Trigger3, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Unused_NavelRock_B1F_Movement_Trigger3_3
	applymovement 10, Unused_NavelRock_B1F_Movement_Trigger3_4
	delay 144
	playbgm MUS_ROCKET_HIDEOUT, 51
	end

Unused_NavelRock_B1F_EventScript_Trigger3_1::
	release
	end

Unused_NavelRock_B1F_Movement_Trigger3_1::
	walk_right
	emote_exclamation_mark
	face_left
	step_end

Unused_NavelRock_B1F_Movement_Trigger3_2::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

Unused_NavelRock_B1F_Movement_Trigger3_3::
	jump_right
	face_left
	step_end

Unused_NavelRock_B1F_Movement_Trigger3_4::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	set_invisible
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Unused_NavelRock_B1F_EventScript_Trigger4::
	call_if_set 0x10FD, Unused_NavelRock_B1F_EventScript_Trigger4_1
	setflag 0x10FD
	applymovement 13, Unused_NavelRock_B1F_Movement_Trigger4_1
	applymovement 14, Unused_NavelRock_B1F_Movement_Trigger4_2
	delay 16
	msgbox Unused_NavelRock_B1F_Text_Trigger4_1, MSGBOX_NPC
	playbgm MUS_ENCOUNTER_BOY, 51
	msgbox Unused_NavelRock_B1F_Text_Trigger4_2, MSGBOX_NPC
	msgbox Unused_NavelRock_B1F_Text_Trigger4_3, MSGBOX_NPC
	msgbox Unused_NavelRock_B1F_Text_Trigger4_4, MSGBOX_NPC
	msgbox Unused_NavelRock_B1F_Text_Trigger4_3, MSGBOX_NPC
	msgbox Unused_NavelRock_B1F_Text_Trigger4_5, MSGBOX_NPC
	msgbox Unused_NavelRock_B1F_Text_Trigger4_6, MSGBOX_NPC
	msgbox Unused_NavelRock_B1F_Text_Trigger4_7, MSGBOX_NPC
	msgbox Unused_NavelRock_B1F_Text_Trigger4_3, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_ROCKET_DUO_JESS_AND_JAMIE_2, 0, Unused_NavelRock_B1F_Text_Trigger4Defeat, Unused_NavelRock_B1F_Text_Trigger4Victory
	msgbox Unused_NavelRock_B1F_Text_Trigger4_8, MSGBOX_NPC
	msgbox Unused_NavelRock_B1F_Text_Trigger4_9, MSGBOX_NPC
	msgbox Unused_NavelRock_B1F_Text_Trigger4_10, MSGBOX_NPC
	end

Unused_NavelRock_B1F_EventScript_Trigger4_1::
	release
	end

Unused_NavelRock_B1F_Movement_Trigger4_1::
	walk_right
	face_down_fast
	step_end

Unused_NavelRock_B1F_Movement_Trigger4_2::
	walk_left
	walk_left
	face_down_fast
	step_end

Unused_NavelRock_B1F_EventScript_Trigger5::
	call_if_set 0x10FE, Unused_NavelRock_B1F_EventScript_Trigger5_1
	applymovement LOCALID_PLAYER, Unused_NavelRock_B1F_Movement_Trigger5_1
	delay 160
	call Unused_NavelRock_B1F_EventScript_Trigger5_2
	end

Unused_NavelRock_B1F_EventScript_Trigger5_1::
	release
	end

Unused_NavelRock_B1F_EventScript_Trigger5_2::
	setflag 0x10FE
	applymovement 15, Unused_NavelRock_B1F_Movement_Trigger5_2
	delay 32
	msgbox Unused_NavelRock_B1F_Text_Trigger5_1, MSGBOX_NPC
	applymovement 15, Unused_NavelRock_B1F_Movement_Trigger5_3
	delay 16
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_EXECUTIVE_2, 0, Unused_NavelRock_B1F_Text_Trigger5Defeat, Unused_NavelRock_B1F_Text_Trigger5Victory
	msgbox Unused_NavelRock_B1F_Text_Trigger5_2, MSGBOX_NPC
	applymovement 15, Unused_NavelRock_B1F_Movement_Trigger5_4
	delay 64
	applymovement 15, Unused_NavelRock_B1F_Movement_Trigger5_5
	delay 0x110
	end

Unused_NavelRock_B1F_Movement_Trigger5_1::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

Unused_NavelRock_B1F_Movement_Trigger5_2::
	emote_exclamation_mark
	face_down_fast
	step_end

Unused_NavelRock_B1F_Movement_Trigger5_3::
	walk_down
	step_end

Unused_NavelRock_B1F_Movement_Trigger5_4::
	walk_fast_right
	walk_fast_right
	jump_2_left
	face_right
	step_end

Unused_NavelRock_B1F_Movement_Trigger5_5::
	walk_slow_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_right
	set_invisible
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Unused_NavelRock_B1F_EventScript_Trigger6::
	call_if_set 0x10FE, Unused_NavelRock_B1F_EventScript_Trigger5_1
	applymovement LOCALID_PLAYER, Unused_NavelRock_B1F_Movement_Trigger6
	delay 128
	call Unused_NavelRock_B1F_EventScript_Trigger5_2
	end

Unused_NavelRock_B1F_Movement_Trigger6::
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

Unused_NavelRock_B1F_EventScript_Trigger7::
	call_if_set 0x10FE, Unused_NavelRock_B1F_EventScript_Trigger5_1
	applymovement LOCALID_PLAYER, Unused_NavelRock_B1F_Movement_Trigger7
	delay 160
	call Unused_NavelRock_B1F_EventScript_Trigger5_2
	end

Unused_NavelRock_B1F_Movement_Trigger7::
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end
