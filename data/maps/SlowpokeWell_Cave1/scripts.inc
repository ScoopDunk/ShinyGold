SlowpokeWell_Cave1_MapScripts::
	.byte 0

SlowpokeWell_Cave1_EventScript_BaldingMan::
	msgbox SlowpokeWell_Cave1_Text_BaldingMan, MSGBOX_NPC
	end

SlowpokeWell_Cave1_EventScript_TeamRocketGrunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_4, SlowpokeWell_Cave1_Text_TeamRocketGrunt4Intro, SlowpokeWell_Cave1_Text_TeamRocketGrunt4Defeat
	msgbox SlowpokeWell_Cave1_Text_TeamRocketGrunt4, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_Cave1_EventScript_TeamRocketGrunt6::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_6, SlowpokeWell_Cave1_Text_TeamRocketGrunt6Intro, SlowpokeWell_Cave1_Text_TeamRocketGrunt6Defeat
	msgbox SlowpokeWell_Cave1_Text_TeamRocketGrunt6, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_Cave1_EventScript_Slowpoke::
	faceplayer
	msgbox SlowpokeWell_Cave1_Text_Slowpoke_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, SlowpokeWell_Cave1_EventScript_Slowpoke_1
	msgbox SlowpokeWell_Cave1_Text_Slowpoke_2, MSGBOX_NPC
	end

SlowpokeWell_Cave1_EventScript_Slowpoke_1::
	msgbox SlowpokeWell_Cave1_Text_Slowpoke_3, MSGBOX_NPC
	end

SlowpokeWell_Cave1_EventScript_TeamRocketGrunt5::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_5, SlowpokeWell_Cave1_Text_TeamRocketGrunt5Intro, SlowpokeWell_Cave1_Text_TeamRocketGrunt5Defeat
	msgbox SlowpokeWell_Cave1_Text_TeamRocketGrunt5, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_Cave1_EventScript_Slowpoke2::
	msgbox SlowpokeWell_Cave1_Text_Slowpoke2, MSGBOX_NPC
	end

SlowpokeWell_Cave1_EventScript_RocketM::
	msgbox SlowpokeWell_Cave1_Text_RocketM_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_GRUNT, 0, SlowpokeWell_Cave1_Text_RocketMDefeat, SlowpokeWell_Cave1_Text_RocketMVictory
	msgbox SlowpokeWell_Cave1_Text_RocketM_2, MSGBOX_NPC
	call SlowpokeWell_Cave1_EventScript_RocketM_1
	setflag 0x1061
	clearflag 0x1059
	warp MAP_SLOWPOKE_WELL_CAVE1, 2, 0x2028, 0x900
	goto_if_gt 0x06090020
	end

SlowpokeWell_Cave1_EventScript_RocketM_1::
	setvar 0x7030, 0x13C
	setvar 0x7033, 0x129
	release
	return

SlowpokeWell_Cave1_EventScript_ItemSuperPotion::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_Cave1_EventScript_ItemBigPearl::
	finditem ITEM_BIG_PEARL
	end

SlowpokeWell_Cave1_EventScript_Trigger1::
	goto_if_set 0x1062, SlowpokeWell_Cave1_EventScript_Trigger1_1
	goto_if_unset 0x1061, SlowpokeWell_Cave1_EventScript_Trigger1_1
	applymovement 13, SlowpokeWell_Cave1_Movement_Trigger1_1
	delay 112
	applymovement 13, SlowpokeWell_Cave1_Movement_Trigger1_2
	delay 144
	applymovement 13, SlowpokeWell_Cave1_Movement_Trigger1_3
	delay 5
	msgbox SlowpokeWell_Cave1_Text_Trigger1, MSGBOX_NPC
	clearflag 0x1058
	setflag 0x1055
	setflag 0x1059
	setflag 0x1074
	setflag 0x1062
	clearflag 0x1054
	clearflag 0x1070
	clearflag 0x1073
	warp MAP_AZALEA_TOWN_INTERIOR5, 0, 0x6C02, 0x1002
	call_if_eq 0x026C9530
	call_if_unset 0x1061, 0x622B9530
	loadbyte 7, 1
	setdivewarp ((149 << 8) | 43), 98, 0x610, 0x4701
	.byte 0x95 @ updatemoneybox
	.byte 116
	.byte 8
	.byte 43
	settrainerflag 1552
	nop
	checkitem 0x7495, 0x4F08
	endram

SlowpokeWell_Cave1_EventScript_Trigger1_1::
	@ ShinyGold: overlapping data duplicated from 0x08749547
	release
	end

SlowpokeWell_Cave1_Movement_Trigger1_1::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

SlowpokeWell_Cave1_Movement_Trigger1_2::
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

SlowpokeWell_Cave1_Movement_Trigger1_3::
	face_down_fast
	step_end

SlowpokeWell_Cave1_EventScript_Trigger2::
	@ ShinyGold: overlapping data duplicated from 0x08749557
	goto_if_set 0x1062, SlowpokeWell_Cave1_EventScript_Trigger1_1
	goto_if_unset 0x1061, SlowpokeWell_Cave1_EventScript_Trigger1_1
	applymovement 13, SlowpokeWell_Cave1_Movement_Trigger1_1
	delay 112
	applymovement 13, SlowpokeWell_Cave1_Movement_Trigger2
	delay 128
	applymovement 13, SlowpokeWell_Cave1_Movement_Trigger1_3
	delay 5
	msgbox SlowpokeWell_Cave1_Text_Trigger1, MSGBOX_NPC
	clearflag 0x1058
	setflag 0x1055
	setflag 0x1059
	setflag 0x1074
	setflag 0x1062
	clearflag 0x1054
	clearflag 0x1070
	clearflag 0x1073
	warp MAP_AZALEA_TOWN_INTERIOR5, 0, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SlowpokeWell_Cave1_Movement_Trigger2::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

SlowpokeWell_Cave1_EventScript_Trigger3::
	call_if_set 0x1061, SlowpokeWell_Cave1_EventScript_Trigger3_1
	call SilphCo_Interior6_EventScript_Trigger1_1
	setvar 0x7023, 0
	release
	end

SlowpokeWell_Cave1_EventScript_Trigger3_1::
	release
	end
