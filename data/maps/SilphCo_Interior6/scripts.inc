SilphCo_Interior6_MapScripts::
	@ ShinyGold: 1 entry with invalid type(s) 0x6C dropped (inert: the engine skips them)
	.byte 0

SilphCo_Interior6_EventScript_TeamRocketGrunt29::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_29_2, SilphCo_Interior6_Text_TeamRocketGrunt29Intro, SilphCo_Interior6_Text_TeamRocketGrunt29Defeat
	msgbox SilphCo_Interior6_Text_TeamRocketGrunt29, MSGBOX_AUTOCLOSE
	end

SilphCo_Interior6_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge 0x4060, 1, SilphCo_Interior6_EventScript_WorkerM_1
	msgbox SilphCo_Interior6_Text_WorkerM_1
	release
	end

SilphCo_Interior6_EventScript_WorkerM_1::
	msgbox SilphCo_Interior6_Text_WorkerM_2
	release
	end

SilphCo_Interior6_EventScript_RocketM::
	lock
	faceplayer
	goto_if_ge 0x4060, 1, SilphCo_Interior6_EventScript_RocketM_1
	msgbox SilphCo_Interior6_Text_RocketM_1
	release
	end

SilphCo_Interior6_EventScript_RocketM_1::
	msgbox SilphCo_Interior6_Text_RocketM_2
	release
	end

SilphCo_Interior6_EventScript_RocketF::
	lock
	faceplayer
	goto_if_ge 0x4060, 1, SilphCo_Interior6_EventScript_RocketF_1
	msgbox SilphCo_Interior6_Text_RocketF_1
	release
	end

SilphCo_Interior6_EventScript_RocketF_1::
	msgbox SilphCo_Interior6_Text_RocketF_2
	release
	end

SilphCo_Interior6_EventScript_Trigger1::
	applymovement LOCALID_PLAYER, SilphCo_Interior6_Movement_Trigger1_1
	delay 16
	call SilphCo_Interior6_EventScript_Trigger2
	end

SilphCo_Interior6_EventScript_Trigger2::
	delay 32
	msgbox SilphCo_Interior6_Text_Trigger1_1, MSGBOX_NPC
	msgbox SilphCo_Interior6_Text_Trigger1_2, MSGBOX_NPC
	msgbox SilphCo_Interior6_Text_Trigger1_3, MSGBOX_NPC
	msgbox SilphCo_Interior6_Text_Trigger1_4, MSGBOX_NPC
	applymovement LOCALID_PLAYER, SilphCo_Interior6_Movement_Trigger1_2
	delay 48
	applymovement 3, SilphCo_Interior6_Movement_Trigger1_3
	delay 1
	applymovement 4, SilphCo_Interior6_Movement_Trigger1_3
	delay 1
	msgbox SilphCo_Interior6_Text_Trigger1_5, MSGBOX_NPC
	msgbox SilphCo_Interior6_Text_Trigger1_6, MSGBOX_NPC
	applymovement 3, SilphCo_Interior6_Movement_Trigger1_4
	delay 1
	applymovement 4, SilphCo_Interior6_Movement_Trigger1_5
	delay 1
	msgbox SilphCo_Interior6_Text_Trigger1_7, MSGBOX_NPC
	applymovement 3, SilphCo_Interior6_Movement_Trigger1_6
	delay 64
	applymovement 3, SilphCo_Interior6_Movement_Trigger1_3
	delay 1
	applymovement 4, SilphCo_Interior6_Movement_Trigger1_3
	delay 1
	msgbox SilphCo_Interior6_Text_Trigger1_8, MSGBOX_NPC
	call SilphCo_Interior6_EventScript_Trigger1_1
	trainerbattle_earlyrival TRAINER_ROCKET_DUO_JESS_AND_JAMIE_4, 0, SilphCo_Interior6_Text_Trigger1Defeat, SilphCo_Interior6_Text_Trigger1Victory
	setflag 0x118E
	setflag 0x118B
	clearflag 0x118C
	call SilphCo_Interior6_EventScript_Trigger1_2
	msgbox SilphCo_Interior6_Text_Trigger1_9, MSGBOX_NPC
	applymovement 3, SilphCo_Interior6_Movement_Trigger1_4
	delay 1
	applymovement 4, SilphCo_Interior6_Movement_Trigger1_5
	delay 1
	msgbox SilphCo_Interior6_Text_Trigger1_10, MSGBOX_NPC
	applymovement 3, SilphCo_Interior6_Movement_Trigger1_3
	delay 1
	applymovement 4, SilphCo_Interior6_Movement_Trigger1_3
	delay 1
	msgbox SilphCo_Interior6_Text_Trigger1_11, MSGBOX_NPC
	warp MAP_SILPH_CO_INTERIOR7, 1, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SilphCo_Interior6_Movement_Trigger1_1::
	walk_right
	face_up
	step_end

SilphCo_Interior6_EventScript_Trigger1_1::
	setvar 0x7030, 0x129
	setvar 0x7033, 0x13C
	release
	return

SilphCo_Interior6_EventScript_Trigger1_2::
	setvar 0x7030, 0x129
	setvar 0x7033, 0x10A
	release
	return

SilphCo_Interior6_Movement_Trigger1_2::
	walk_up
	walk_up
	face_right
	step_end

SilphCo_Interior6_Movement_Trigger1_3::
	face_left
	step_end

SilphCo_Interior6_Movement_Trigger1_4::
	face_down_fast
	step_end

SilphCo_Interior6_Movement_Trigger1_5::
	face_up
	step_end

SilphCo_Interior6_Movement_Trigger1_6::
	face_right
	emote_x
	step_end
