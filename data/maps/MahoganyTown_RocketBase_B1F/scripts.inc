MahoganyTown_RocketBase_B1F_MapScripts::
	.byte 0

MahoganyTown_RocketBase_B1F_EventScript_TeamRocketGrunt20::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_20, MahoganyTown_RocketBase_B1F_Text_TeamRocketGrunt20Intro, MahoganyTown_RocketBase_B1F_Text_TeamRocketGrunt20Defeat
	msgbox MahoganyTown_RocketBase_B1F_Text_TeamRocketGrunt20, MSGBOX_AUTOCLOSE
	end

MahoganyTown_RocketBase_B1F_EventScript_ItemRevive::
	finditem ITEM_REVIVE
	end

MahoganyTown_RocketBase_B1F_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION
	end

MahoganyTown_RocketBase_B1F_EventScript_ItemNugget::
	finditem ITEM_NUGGET
	end

MahoganyTown_RocketBase_B1F_EventScript_ItemXAccuracy::
	finditem ITEM_X_ACCURACY
	end

MahoganyTown_RocketBase_B1F_EventScript_ScientistJed::
	trainerbattle_single TRAINER_SCIENTIST_JED, MahoganyTown_RocketBase_B1F_Text_ScientistJedIntro, MahoganyTown_RocketBase_B1F_Text_ScientistJedDefeat
	msgbox MahoganyTown_RocketBase_B1F_Text_ScientistJed, MSGBOX_AUTOCLOSE
	end

MahoganyTown_RocketBase_B1F_EventScript_Trigger1::
	call_if_set 0x10EC, MahoganyTown_RocketBase_B1F_EventScript_Trigger1_1
	call_if_set 0x10ED, MahoganyTown_RocketBase_B1F_EventScript_Trigger1_1
	playbgm MUS_ENCOUNTER_GYM_LEADER, 51
	clearflag 0x10E7
	release
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B1F_Movement_Trigger1_1
	delay 16
	applymovement 7, MahoganyTown_RocketBase_B1F_Movement_Trigger1_2
	delay 48
	msgbox MahoganyTown_RocketBase_B1F_Text_Trigger1_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_GRUNT_7, 0, MahoganyTown_RocketBase_B1F_Text_Trigger1Defeat1, MahoganyTown_RocketBase_B1F_Text_Trigger1Victory
	playbgm MUS_ENCOUNTER_GYM_LEADER, 51
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B1F_Movement_Trigger1_3
	applymovement 8, MahoganyTown_RocketBase_B1F_Movement_Trigger1_2
	delay 48
	msgbox MahoganyTown_RocketBase_B1F_Text_Trigger1_2, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_GRUNT_14, 0, MahoganyTown_RocketBase_B1F_Text_Trigger1Defeat2, MahoganyTown_RocketBase_B1F_Text_Trigger1Victory
	setflag 0x10E7
	setflag 0x10ED
	warp MAP_MAHOGANY_TOWN_ROCKET_BASE_B1F, 3, 0x1002, 0xED29
	loadbyte 57, 2

MahoganyTown_RocketBase_B1F_EventScript_Trigger1_1::
	release
	end

MahoganyTown_RocketBase_B1F_Movement_Trigger1_1::
	emote_exclamation_mark
	jump_right
	face_left
	step_end

MahoganyTown_RocketBase_B1F_Movement_Trigger1_2::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MahoganyTown_RocketBase_B1F_Movement_Trigger1_3::
	emote_exclamation_mark
	step_end

MahoganyTown_RocketBase_B1F_EventScript_Trigger5::
	call_if_set 0x10EC, MahoganyTown_RocketBase_B1F_EventScript_Trigger1_1
	call_if_set 0x10EE, MahoganyTown_RocketBase_B1F_EventScript_Trigger1_1
	playbgm MUS_ENCOUNTER_GYM_LEADER, 51
	clearflag 0x10E8
	release
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B1F_Movement_Trigger1_1
	delay 16
	applymovement 9, MahoganyTown_RocketBase_B1F_Movement_Trigger5_1
	delay 64
	msgbox MahoganyTown_RocketBase_B1F_Text_Trigger1_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_GRUNT_8, 0, MahoganyTown_RocketBase_B1F_Text_Trigger1Defeat1, MahoganyTown_RocketBase_B1F_Text_Trigger1Victory
	playbgm MUS_ENCOUNTER_GYM_LEADER, 51
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B1F_Movement_Trigger5_2
	applymovement 10, MahoganyTown_RocketBase_B1F_Movement_Trigger5_3
	delay 96
	msgbox MahoganyTown_RocketBase_B1F_Text_Trigger1_2, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_GRUNT_16, 0, MahoganyTown_RocketBase_B1F_Text_Trigger1Defeat2, MahoganyTown_RocketBase_B1F_Text_Trigger1Victory
	setflag 0x10E8
	setflag 0x10EE
	warp MAP_MAHOGANY_TOWN_ROCKET_BASE_B1F, 4, 0x1002, 0xEE29
	loadbyte 57, 2
	compare_ptr_to_local 0x1E1E1E1E, 30
	compare_ptr_to_local 0xFFFFFE03, 255
	cleartrainerflag 65027
	.byte 0xFF @ invalid opcode (script stops)

MahoganyTown_RocketBase_B1F_Movement_Trigger5_1::
	@ ShinyGold: overlapping data duplicated from 0x08783890
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_right
	step_end

MahoganyTown_RocketBase_B1F_Movement_Trigger5_2::
	@ ShinyGold: overlapping data duplicated from 0x0878389C
	emote_exclamation_mark
	face_right
	step_end

MahoganyTown_RocketBase_B1F_Movement_Trigger5_3::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	step_end

MahoganyTown_RocketBase_B1F_EventScript_Trigger9::
	call_if_set 0x10EC, MahoganyTown_RocketBase_B1F_EventScript_Trigger1_1
	call_if_set 0x10EF, MahoganyTown_RocketBase_B1F_EventScript_Trigger1_1
	playbgm MUS_ENCOUNTER_GYM_LEADER, 51
	clearflag 0x10E9
	release
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B1F_Movement_Trigger9_1
	delay 16
	applymovement 11, MahoganyTown_RocketBase_B1F_Movement_Trigger9_2
	delay 48
	msgbox MahoganyTown_RocketBase_B1F_Text_Trigger1_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_GRUNT_9, 0, MahoganyTown_RocketBase_B1F_Text_Trigger1Defeat1, MahoganyTown_RocketBase_B1F_Text_Trigger1Victory
	playbgm MUS_ENCOUNTER_GYM_LEADER, 51
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B1F_Movement_Trigger5_2
	applymovement 12, MahoganyTown_RocketBase_B1F_Movement_Trigger9_3
	delay 112
	msgbox MahoganyTown_RocketBase_B1F_Text_Trigger1_2, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_GRUNT_17, 0, MahoganyTown_RocketBase_B1F_Text_Trigger1Defeat2, MahoganyTown_RocketBase_B1F_Text_Trigger1Victory
	setflag 0x10E9
	setflag 0x10EF
	warp MAP_MAHOGANY_TOWN_ROCKET_BASE_B1F, 5, 0x1002, 0xEF29
	loadbyte 57, 2
	cleartrainerflag 65104
	.byte 0xFF @ invalid opcode (script stops)

MahoganyTown_RocketBase_B1F_Movement_Trigger9_1::
	@ ShinyGold: overlapping data duplicated from 0x08783930
	emote_exclamation_mark
	jump_left
	step_end

MahoganyTown_RocketBase_B1F_Movement_Trigger9_2::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MahoganyTown_RocketBase_B1F_Movement_Trigger9_3::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	step_end

MahoganyTown_RocketBase_B1F_EventScript_Trigger13::
	call_if_set 0x10EC, MahoganyTown_RocketBase_B1F_EventScript_Trigger1_1
	call_if_set 0x10F1, MahoganyTown_RocketBase_B1F_EventScript_Trigger1_1
	playbgm MUS_ENCOUNTER_GYM_LEADER, 51
	clearflag 0x10EB
	release
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B1F_Movement_Trigger9_1
	delay 16
	applymovement 15, MahoganyTown_RocketBase_B1F_Movement_Trigger13_1
	delay 80
	msgbox MahoganyTown_RocketBase_B1F_Text_Trigger1_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_GRUNT_11, 0, MahoganyTown_RocketBase_B1F_Text_Trigger1Defeat1, MahoganyTown_RocketBase_B1F_Text_Trigger1Victory
	playbgm MUS_ENCOUNTER_GYM_LEADER, 51
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B1F_Movement_Trigger5_2
	applymovement 16, MahoganyTown_RocketBase_B1F_Movement_Trigger13_2
	delay 64
	msgbox MahoganyTown_RocketBase_B1F_Text_Trigger1_2, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_GRUNT_24, 0, MahoganyTown_RocketBase_B1F_Text_Trigger1Defeat2, MahoganyTown_RocketBase_B1F_Text_Trigger1Victory
	setflag 0x10EB
	setflag 0x10F1
	warp MAP_MAHOGANY_TOWN_ROCKET_BASE_B1F, 7, 0x1002, 0xF129
	loadbyte 57, 2
	compare_local_to_ptr 29, 0x1D1D1D1D
	compare_ptr_to_ptr 0xFEFE2020, 0xFFFFFFFF
	.byte 0xFF @ invalid opcode (script stops)

MahoganyTown_RocketBase_B1F_Movement_Trigger13_1::
	@ ShinyGold: overlapping data duplicated from 0x08783A70
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MahoganyTown_RocketBase_B1F_Movement_Trigger13_2::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

MahoganyTown_RocketBase_B1F_EventScript_Trigger16::
	call_if_set 0x10EC, MahoganyTown_RocketBase_B1F_EventScript_Trigger1_1
	call_if_set 0x10F0, MahoganyTown_RocketBase_B1F_EventScript_Trigger1_1
	playbgm MUS_ENCOUNTER_GYM_LEADER, 51
	clearflag 0x10EA
	release
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B1F_Movement_Trigger1_1
	delay 16
	applymovement 13, MahoganyTown_RocketBase_B1F_Movement_Trigger16_1
	delay 48
	msgbox MahoganyTown_RocketBase_B1F_Text_Trigger1_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_GRUNT_10, 0, MahoganyTown_RocketBase_B1F_Text_Trigger1Defeat1, MahoganyTown_RocketBase_B1F_Text_Trigger1Victory
	playbgm MUS_ENCOUNTER_GYM_LEADER, 51
	applymovement LOCALID_PLAYER, MahoganyTown_RocketBase_B1F_Movement_Trigger5_2
	applymovement 14, MahoganyTown_RocketBase_B1F_Movement_Trigger16_2
	delay 112
	msgbox MahoganyTown_RocketBase_B1F_Text_Trigger1_2, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_GRUNT_18, 0, MahoganyTown_RocketBase_B1F_Text_Trigger1Defeat2, MahoganyTown_RocketBase_B1F_Text_Trigger1Victory
	setflag 0x10EA
	setflag 0x10F0
	warp MAP_MAHOGANY_TOWN_ROCKET_BASE_B1F, 6, 0x1002, 0xF029
	loadbyte 57, 2
	compare_ptr_to_ptr 0x20202020, 0xFFFE2020
	.byte 0xFF @ invalid opcode (script stops)

MahoganyTown_RocketBase_B1F_Movement_Trigger16_1::
	@ ShinyGold: overlapping data duplicated from 0x087839D0
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MahoganyTown_RocketBase_B1F_Movement_Trigger16_2::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

MahoganyTown_RocketBase_B1F_EventScript_Trigger19::
	setwildbattle SPECIES_GEODUDE, 21
	special StartSouthernIslandBattle
	end

MahoganyTown_RocketBase_B1F_EventScript_Trigger20::
	setwildbattle SPECIES_VOLTORB, 23
	special StartSouthernIslandBattle
	end

MahoganyTown_RocketBase_B1F_EventScript_Trigger21::
	setwildbattle SPECIES_KOFFING, 21
	special StartSouthernIslandBattle
	end

MahoganyTown_RocketBase_B1F_EventScript_Trigger22::
	setflag 0x10E7
	setflag 0x10E8
	setflag 0x10E9
	setflag 0x10EA
	setflag 0x10EB
	setflag 0x10F2
	setflag 0x10FB
	setflag 0x1101
	setflag 0x1102
	call_if_set 0x1103, MahoganyTown_RocketBase_B1F_EventScript_Trigger22_1
	call SilphCo_Interior6_EventScript_Trigger1_1
	setvar 0x7027, 0
	release
	end

MahoganyTown_RocketBase_B1F_EventScript_Trigger22_1::
	release
	end

MahoganyTown_RocketBase_B1F_EventScript_Sign::
	call_if_set 0x10EC, MahoganyTown_RocketBase_B1F_EventScript_Sign_1
	setflag 0x10EC
	msgbox MahoganyTown_RocketBase_B1F_Text_Sign_1, MSGBOX_NPC
	end

MahoganyTown_RocketBase_B1F_EventScript_Sign_1::
	msgbox MahoganyTown_RocketBase_B1F_Text_Sign_2, MSGBOX_NPC
	end
