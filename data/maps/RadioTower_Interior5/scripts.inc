RadioTower_Interior5_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

RadioTower_Interior5_EventScript_TeamRocketExecutive::
	trainerbattle_single TRAINER_TEAM_ROCKET_EXECUTIVE, RadioTower_Interior5_Text_TeamRocketExecutiveIntro, RadioTower_Interior5_Text_TeamRocketExecutiveDefeat
	msgbox RadioTower_Interior5_Text_TeamRocketExecutive, MSGBOX_AUTOCLOSE
	end

RadioTower_Interior5_EventScript_Gentleman::
	msgbox RadioTower_Interior5_Text_Gentleman, MSGBOX_NPC
	end

RadioTower_Interior5_EventScript_Gentleman2::
	msgbox RadioTower_Interior5_Text_Gentleman2_1, MSGBOX_NPC
	giveitem ITEM_AURORA_TICKET
	msgbox RadioTower_Interior5_Text_Gentleman2_2, MSGBOX_NPC
	setflag 0x1124
	applymovement 4, RadioTower_Interior5_Movement_Gentleman2
	delay 32
	end

RadioTower_Interior5_Movement_Gentleman2::
	face_left
	set_invisible
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RadioTower_Interior5_EventScript_Man::
	msgbox RadioTower_Interior5_Text_Man, MSGBOX_NPC
	end

RadioTower_Interior5_EventScript_Gentleman3::
	msgbox RadioTower_Interior5_Text_Gentleman3, MSGBOX_NPC
	end

RadioTower_Interior5_EventScript_Trigger1::
	call_if_set 0x110C, RadioTower_Interior5_EventScript_Trigger1_1
	applymovement 3, RadioTower_Interior5_Movement_Trigger1_1
	applymovement LOCALID_PLAYER, RadioTower_Interior5_Movement_Trigger1_2
	delay 1
	msgbox RadioTower_Interior5_Text_Trigger1_1, MSGBOX_NPC
	applymovement 3, RadioTower_Interior5_Movement_Trigger1_3
	delay 32
	playbgm MUS_ENCOUNTER_GYM_LEADER, 51
	msgbox RadioTower_Interior5_Text_Trigger1_2, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_EXECUTIVE_4, 0, RadioTower_Interior5_Text_Trigger1Defeat, RadioTower_Interior5_Text_Trigger1Victory
	setflag 0x110C
	playbgm MUS_ENCOUNTER_GYM_LEADER, 51
	msgbox RadioTower_Interior5_Text_Gentleman, MSGBOX_NPC
	giveitem ITEM_CARD_KEY
	releaseall
	end

RadioTower_Interior5_EventScript_Trigger1_1::
	release
	end

RadioTower_Interior5_Movement_Trigger1_1::
	emote_exclamation_mark
	step_end

RadioTower_Interior5_Movement_Trigger1_2::
	face_down_fast
	step_end

RadioTower_Interior5_Movement_Trigger1_3::
	walk_left
	walk_up
	step_end

RadioTower_Interior5_EventScript_Trigger2::
	@ ShinyGold: overlapping data duplicated from 0x0878A070
	call_if_set 0x1123, RadioTower_Interior5_EventScript_Trigger2_1
	applymovement LOCALID_PLAYER, RadioTower_Interior5_Movement_Trigger2_1
	delay 80
	applymovement 1, RadioTower_Interior5_Movement_Trigger2_2
	playbgm MUS_ENCOUNTER_GYM_LEADER, 51
	msgbox RadioTower_Interior5_Text_Trigger2_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_EXECUTIVE_6, 0, RadioTower_Interior5_Text_Trigger2Defeat, RadioTower_Interior5_Text_Trigger2Victory
	playbgm MUS_NONE, 51
	msgbox RadioTower_Interior5_Text_Trigger2_2, MSGBOX_NPC
	setflag 0x10BC
	setflag 0x10BD
	clearflag 0x110B
	clearflag 0x1124
	clearflag 0x10E4
	clearflag 0x112A
	clearflag 0x1132
	setflag 0x1123
	warp MAP_RADIO_TOWER_INTERIOR5, 2, 0x202, 0xFFFF
	msgbox RadioTower_Interior5_Text_Gentleman2_1, MSGBOX_NPC
	setorcopyvar VAR_0x8000, 0x173
	setorcopyvar VAR_0x8001, 15
	bufferitemname 163, 0x878
	callstd MSGBOX_NPC
	giveitem ITEM_AURORA_TICKET
	msgbox RadioTower_Interior5_Text_Gentleman2_2, MSGBOX_NPC
	setflag 0x1124
	applymovement 4, RadioTower_Interior5_Movement_Gentleman2
	delay 32
	end

RadioTower_Interior5_EventScript_Trigger2_1::
	release
	end

RadioTower_Interior5_Movement_Trigger2_1::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RadioTower_Interior5_Movement_Trigger2_2::
	face_right
	emote_question_mark
	step_end

RadioTower_Interior5_EventScript_Sign1::
	msgbox RadioTower_Interior5_Text_Sign1, MSGBOX_AUTOCLOSE
	end

RadioTower_Interior5_EventScript_Sign2::
	msgbox RadioTower_Interior5_Text_Sign2, MSGBOX_AUTOCLOSE
	end
