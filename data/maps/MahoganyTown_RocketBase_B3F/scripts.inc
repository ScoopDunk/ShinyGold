MahoganyTown_RocketBase_B3F_MapScripts::
	.byte 0

MahoganyTown_RocketBase_B3F_EventScript_RocketM::
	msgbox MahoganyTown_RocketBase_B3F_Text_RocketM, MSGBOX_NPC
	end

MahoganyTown_RocketBase_B3F_EventScript_ItemProtein::
	finditem ITEM_PROTEIN
	end

MahoganyTown_RocketBase_B3F_EventScript_ScientistRoss::
	trainerbattle_single TRAINER_SCIENTIST_ROSS, MahoganyTown_RocketBase_B3F_Text_ScientistRossIntro, MahoganyTown_RocketBase_B3F_Text_ScientistRossDefeat
	msgbox MahoganyTown_RocketBase_B3F_Text_ScientistRoss, MSGBOX_AUTOCLOSE
	end

MahoganyTown_RocketBase_B3F_EventScript_TeamRocketGrunt15::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_15, MahoganyTown_RocketBase_B3F_Text_TeamRocketGrunt15Intro, MahoganyTown_RocketBase_B3F_Text_TeamRocketGrunt15Defeat
	setflag 0x10F5
	msgbox MahoganyTown_RocketBase_B3F_Text_TeamRocketGrunt15, MSGBOX_AUTOCLOSE
	end

MahoganyTown_RocketBase_B3F_EventScript_ScientistMitch::
	trainerbattle_single TRAINER_SCIENTIST_MITCH, MahoganyTown_RocketBase_B3F_Text_ScientistMitchIntro, MahoganyTown_RocketBase_B3F_Text_ScientistMitchDefeat
	msgbox MahoganyTown_RocketBase_B3F_Text_ScientistMitch, MSGBOX_AUTOCLOSE
	end

MahoganyTown_RocketBase_B3F_EventScript_TeamRocketGrunt28::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_28, MahoganyTown_RocketBase_B3F_Text_TeamRocketGrunt28Intro, MahoganyTown_RocketBase_B3F_Text_TeamRocketGrunt28Defeat
	setflag 0x10F6
	msgbox MahoganyTown_RocketBase_B3F_Text_TeamRocketGrunt28, MSGBOX_AUTOCLOSE
	end

MahoganyTown_RocketBase_B3F_EventScript_ItemDireHit::
	finditem ITEM_DIRE_HIT
	end

MahoganyTown_RocketBase_B3F_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

MahoganyTown_RocketBase_B3F_EventScript_Meteorite::
	call_if_unset 0x10F5, MahoganyTown_RocketBase_B3F_EventScript_Meteorite_1
	call_if_unset 0x10F6, MahoganyTown_RocketBase_B3F_EventScript_Meteorite_1
	msgbox MahoganyTown_RocketBase_B3F_Text_Meteorite_1, MSGBOX_NPC
	setflag 0x10FA
	warp MAP_MAHOGANY_TOWN_ROCKET_BASE_B3F, 1, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

MahoganyTown_RocketBase_B3F_EventScript_Meteorite_1::
	msgbox MahoganyTown_RocketBase_B3F_Text_Meteorite_2, MSGBOX_NPC
	end

MahoganyTown_RocketBase_B3F_EventScript_ItemIceHeal::
	finditem ITEM_ICE_HEAL
	end

MahoganyTown_RocketBase_B3F_EventScript_Pidgeot::
	setflag 0x10F9
	msgbox MahoganyTown_RocketBase_B3F_Text_Pidgeot, MSGBOX_NPC
	end

MahoganyTown_RocketBase_B3F_EventScript_Trigger1::
	call_if_set 0x10F8, MahoganyTown_RocketBase_B3F_EventScript_Trigger1_1
	setflag 0x10FB
	setflag 0x10F8
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B3F_Movement_Trigger1_1
	delay 1
	applymovement 1, MahoganyTown_RocketBase_B3F_Movement_Trigger1_2
	msgbox MahoganyTown_RocketBase_B3F_Text_Trigger1, MSGBOX_NPC
	applymovement 1, MahoganyTown_RocketBase_B3F_Movement_Trigger1_3
	delay 0x26C
	end

MahoganyTown_RocketBase_B3F_EventScript_Trigger1_1::
	@ ShinyGold: overlapping data duplicated from 0x08784280
	release
	end

MahoganyTown_RocketBase_B3F_Movement_Trigger1_1::
	face_right
	step_end

MahoganyTown_RocketBase_B3F_Movement_Trigger1_2::
	face_left
	step_end

MahoganyTown_RocketBase_B3F_Movement_Trigger1_3::
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

MahoganyTown_RocketBase_B3F_EventScript_Trigger2::
	call_if_set 0x10F8, MahoganyTown_RocketBase_B3F_EventScript_Trigger1_1
	setflag 0x10FB
	setflag 0x10F8
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B3F_Movement_Trigger2
	delay 1
	msgbox MahoganyTown_RocketBase_B3F_Text_Trigger1, MSGBOX_NPC
	applymovement 1, MahoganyTown_RocketBase_B3F_Movement_Trigger1_3
	delay 176
	end

MahoganyTown_RocketBase_B3F_Movement_Trigger2::
	face_down_fast
	step_end

MahoganyTown_RocketBase_B3F_EventScript_Trigger3::
	call_if_set 0x10FC, MahoganyTown_RocketBase_B3F_EventScript_Trigger3_1
	clearflag 0x10FB
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B3F_Movement_Trigger3_1
	delay 16
	playbgm MUS_NONE, 51
	applymovement 10, MahoganyTown_RocketBase_B3F_Movement_Trigger3_2
	delay 144
	playbgm MUS_ENCOUNTER_RIVAL, 51
	setflag 0x10FB
	setflag 0x10FC
	msgbox MahoganyTown_RocketBase_B3F_Text_Trigger3, MSGBOX_NPC
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B3F_Movement_Trigger3_3
	applymovement 10, MahoganyTown_RocketBase_B3F_Movement_Trigger3_4
	delay 144
	playbgm MUS_ROCKET_HIDEOUT, 51
	end

MahoganyTown_RocketBase_B3F_EventScript_Trigger3_1::
	release
	end

MahoganyTown_RocketBase_B3F_Movement_Trigger3_1::
	walk_right
	emote_exclamation_mark
	face_left
	step_end

MahoganyTown_RocketBase_B3F_Movement_Trigger3_2::
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

MahoganyTown_RocketBase_B3F_Movement_Trigger3_3::
	jump_right
	face_left
	step_end

MahoganyTown_RocketBase_B3F_Movement_Trigger3_4::
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

MahoganyTown_RocketBase_B3F_EventScript_Trigger5::
	call_if_set 0x10FE, MahoganyTown_RocketBase_B3F_EventScript_Trigger5_1
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B3F_Movement_Trigger5_1
	delay 160
	call MahoganyTown_RocketBase_B3F_EventScript_Trigger5_2
	end

MahoganyTown_RocketBase_B3F_EventScript_Trigger5_1::
	release
	end

MahoganyTown_RocketBase_B3F_EventScript_Trigger5_2::
	setflag 0x10FE
	applymovement 13, MahoganyTown_RocketBase_B3F_Movement_Trigger5_2
	delay 32
	msgbox MahoganyTown_RocketBase_B3F_Text_Trigger5_1, MSGBOX_NPC
	applymovement 13, MahoganyTown_RocketBase_B3F_Movement_Trigger5_3
	delay 16
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_EXECUTIVE_2, 0, MahoganyTown_RocketBase_B3F_Text_Trigger5Defeat, MahoganyTown_RocketBase_B3F_Text_Trigger5Victory
	msgbox MahoganyTown_RocketBase_B3F_Text_Trigger5_2, MSGBOX_NPC
	applymovement 13, MahoganyTown_RocketBase_B3F_Movement_Trigger5_4
	delay 64
	applymovement 13, MahoganyTown_RocketBase_B3F_Movement_Trigger5_5
	delay 0x110
	end

MahoganyTown_RocketBase_B3F_Movement_Trigger5_1::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

MahoganyTown_RocketBase_B3F_Movement_Trigger5_2::
	emote_exclamation_mark
	face_down_fast
	step_end

MahoganyTown_RocketBase_B3F_Movement_Trigger5_3::
	walk_down
	step_end

MahoganyTown_RocketBase_B3F_Movement_Trigger5_4::
	walk_fast_right
	walk_fast_right
	jump_2_left
	face_right
	step_end

MahoganyTown_RocketBase_B3F_Movement_Trigger5_5::
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

MahoganyTown_RocketBase_B3F_EventScript_Trigger6::
	call_if_set 0x10FE, MahoganyTown_RocketBase_B3F_EventScript_Trigger5_1
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B3F_Movement_Trigger6
	delay 128
	call MahoganyTown_RocketBase_B3F_EventScript_Trigger5_2
	end

MahoganyTown_RocketBase_B3F_Movement_Trigger6::
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

MahoganyTown_RocketBase_B3F_EventScript_Trigger7::
	call_if_set 0x10FE, MahoganyTown_RocketBase_B3F_EventScript_Trigger5_1
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B3F_Movement_Trigger7
	delay 160
	call MahoganyTown_RocketBase_B3F_EventScript_Trigger5_2
	end

MahoganyTown_RocketBase_B3F_Movement_Trigger7::
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end
