GoldenrodCity_Interior17_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

GoldenrodCity_Interior17_EventScript_Meteorite::
	release
	end

GoldenrodCity_Interior17_EventScript_BurglarEddie::
	trainerbattle_single TRAINER_BURGLAR_EDDIE, GoldenrodCity_Interior17_Text_BurglarEddieIntro, GoldenrodCity_Interior17_Text_BurglarEddieDefeat
	msgbox GoldenrodCity_Interior17_Text_BurglarEddie, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Interior17_EventScript_ItemRevive::
	finditem ITEM_REVIVE
	end

GoldenrodCity_Interior17_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

GoldenrodCity_Interior17_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

GoldenrodCity_Interior17_EventScript_ItemSmokeBall::
	finditem ITEM_SMOKE_BALL
	end

GoldenrodCity_Interior17_EventScript_BurglarDuncan::
	trainerbattle_single TRAINER_BURGLAR_DUNCAN, GoldenrodCity_Interior17_Text_BurglarDuncanIntro, GoldenrodCity_Interior17_Text_BurglarDuncanDefeat
	msgbox GoldenrodCity_Interior17_Text_BurglarDuncan, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Interior17_EventScript_TeamRocketGrunt29::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_29, GoldenrodCity_Interior17_Text_TeamRocketGrunt29Intro, GoldenrodCity_Interior17_Text_TeamRocketGrunt29Defeat
	msgbox GoldenrodCity_Interior17_Text_TeamRocketGrunt29, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Interior17_EventScript_TeamRocketGrunt22::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_22, GoldenrodCity_Interior17_Text_TeamRocketGrunt22Intro, GoldenrodCity_Interior17_Text_TeamRocketGrunt22Defeat
	msgbox GoldenrodCity_Interior17_Text_TeamRocketGrunt22, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Interior17_EventScript_TeamRocketGrunt30::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_30, GoldenrodCity_Interior17_Text_TeamRocketGrunt30Intro, GoldenrodCity_Interior17_Text_TeamRocketGrunt30Defeat
	msgbox GoldenrodCity_Interior17_Text_TeamRocketGrunt30, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Interior17_EventScript_TeamRocketGrunt36::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_36, GoldenrodCity_Interior17_Text_TeamRocketGrunt36Intro, GoldenrodCity_Interior17_Text_TeamRocketGrunt36Defeat
	msgbox GoldenrodCity_Interior17_Text_TeamRocketGrunt36, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Interior17_EventScript_Trigger1::
	call_if_set 0x110D, GoldenrodCity_Interior17_EventScript_Trigger1_1
	clearflag 0x110E
	applymovement LOCALID_PLAYER, GoldenrodCity_Interior17_Movement_Trigger1_1
	delay 32
	playbgm MUS_NONE, 51
	applymovement 17, GoldenrodCity_Interior17_Movement_Trigger1_2
	delay 128
	call GoldenrodCity_Interior17_EventScript_Trigger1_2
	end

GoldenrodCity_Interior17_EventScript_Trigger1_1::
	release
	end

GoldenrodCity_Interior17_EventScript_Trigger1_2::
	playbgm MUS_ENCOUNTER_RIVAL, 51
	msgbox GoldenrodCity_Interior17_Text_Trigger1_1, MSGBOX_NPC
	call_if_eq VAR_STARTER_MON, 0, GoldenrodCity_Interior17_EventScript_Trigger1_3
	call_if_eq VAR_STARTER_MON, 1, GoldenrodCity_Interior17_EventScript_Trigger1_4
	call_if_eq VAR_STARTER_MON, 2, GoldenrodCity_Interior17_EventScript_Trigger1_5
	end

GoldenrodCity_Interior17_Movement_Trigger1_1::
	walk_left
	face_right
	emote_exclamation_mark
	step_end

GoldenrodCity_Interior17_Movement_Trigger1_2::
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_Interior17_EventScript_Trigger1_3::
	trainerbattle_earlyrival TRAINER_RIVAL_TERRY_7, 0, GoldenrodCity_Interior17_Text_Trigger1Defeat, GoldenrodCity_Interior17_Text_Trigger1Victory
	call GoldenrodCity_Interior17_EventScript_Trigger1_6
	end

GoldenrodCity_Interior17_EventScript_Trigger1_4::
	trainerbattle_earlyrival TRAINER_RIVAL_TERRY_8, 0, GoldenrodCity_Interior17_Text_Trigger1Defeat, GoldenrodCity_Interior17_Text_Trigger1Victory
	call GoldenrodCity_Interior17_EventScript_Trigger1_6
	end

GoldenrodCity_Interior17_EventScript_Trigger1_5::
	trainerbattle_earlyrival TRAINER_RIVAL_TERRY_9, 0, GoldenrodCity_Interior17_Text_Trigger1Defeat, GoldenrodCity_Interior17_Text_Trigger1Victory
	call GoldenrodCity_Interior17_EventScript_Trigger1_6
	end

GoldenrodCity_Interior17_EventScript_Trigger1_6::
	setflag 0x110D
	setflag 0x110E
	msgbox GoldenrodCity_Interior17_Text_Trigger1_2, MSGBOX_NPC
	applymovement 17, GoldenrodCity_Interior17_Movement_Trigger1_3
	delay 144
	end

GoldenrodCity_Interior17_Movement_Trigger1_3::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	set_invisible
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

GoldenrodCity_Interior17_EventScript_Trigger2::
	call_if_set 0x110D, GoldenrodCity_Interior17_EventScript_Trigger1_1
	clearflag 0x110E
	applymovement LOCALID_PLAYER, GoldenrodCity_Interior17_Movement_Trigger1_1
	delay 32
	playbgm MUS_NONE, 51
	applymovement 17, GoldenrodCity_Interior17_Movement_Trigger2
	delay 144
	call GoldenrodCity_Interior17_EventScript_Trigger1_2
	end

GoldenrodCity_Interior17_Movement_Trigger2::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_Interior17_EventScript_Trigger3::
	call SlowpokeWell_Cave1_EventScript_TeamRocketGrunt_1
	release
	end

GoldenrodCity_Interior17_EventScript_Sign1::
	msgbox GoldenrodCity_Interior17_Text_Sign1_1, MSGBOX_NPC
	call_if_set 0x1110, GoldenrodCity_Interior17_EventScript_Sign1_1
	msgbox GoldenrodCity_Interior17_Text_Sign1_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, GoldenrodCity_Interior17_EventScript_Sign1_2
	releaseall
	release
	end

GoldenrodCity_Interior17_EventScript_Sign1_1::
	msgbox GoldenrodCity_Interior17_Text_Sign1_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, GoldenrodCity_Interior17_EventScript_Sign1_3
	releaseall
	release
	end

GoldenrodCity_Interior17_EventScript_Sign1_2::
	setflag 0x1110
	setflag 0x1115
	setflag 0x111B
	setflag 0x111A
	setflag 0x1117
	clearflag 0x111C
	clearflag 0x1113
	clearflag 0x1114
	clearflag 0x111D
	warp MAP_GOLDENROD_CITY_INTERIOR17, 2, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior17_EventScript_Sign1_3::
	clearflag 0x1110
	clearflag 0x1115
	clearflag 0x111B
	clearflag 0x111A
	clearflag 0x1117
	warp MAP_GOLDENROD_CITY_INTERIOR17, 2, 0x26C, 0x1429
	@ ShinyGold fix: the engine keeps running a script during the warp fade, so the hack's leftover bytes
	@ that followed this warp executed (garbage calls, stray text, RAM writes). The script now ends here.
	end

GoldenrodCity_Interior17_EventScript_Sign2::
	msgbox GoldenrodCity_Interior17_Text_Sign2, MSGBOX_NPC
	call_if_set 0x1111, GoldenrodCity_Interior17_EventScript_Sign2_1
	msgbox GoldenrodCity_Interior17_Text_Sign1_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, GoldenrodCity_Interior17_EventScript_Sign2_2
	releaseall
	release
	end

GoldenrodCity_Interior17_EventScript_Sign2_1::
	msgbox GoldenrodCity_Interior17_Text_Sign1_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, GoldenrodCity_Interior17_EventScript_Sign2_3
	releaseall
	release
	end

GoldenrodCity_Interior17_EventScript_Sign2_2::
	setflag 0x1111
	setflag 0x1114
	setflag 0x1116
	setflag 0x1118
	setflag 0x1119
	clearflag 0x111B
	clearflag 0x111D
	clearflag 0x1115
	warp MAP_GOLDENROD_CITY_INTERIOR17, 3, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior17_EventScript_Sign2_3::
	clearflag 0x1111
	clearflag 0x1114
	clearflag 0x1116
	clearflag 0x1118
	clearflag 0x1119
	warp MAP_GOLDENROD_CITY_INTERIOR17, 3, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior17_EventScript_Sign3::
	msgbox GoldenrodCity_Interior17_Text_Sign3, MSGBOX_NPC
	call_if_set 0x1112, GoldenrodCity_Interior17_EventScript_Sign3_1
	msgbox GoldenrodCity_Interior17_Text_Sign1_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, GoldenrodCity_Interior17_EventScript_Sign3_2
	releaseall
	release
	end

GoldenrodCity_Interior17_EventScript_Sign3_1::
	msgbox GoldenrodCity_Interior17_Text_Sign1_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, GoldenrodCity_Interior17_EventScript_Sign3_3
	releaseall
	release
	end

GoldenrodCity_Interior17_EventScript_Sign3_2::
	setflag 0x1112
	setflag 0x1113
	setflag 0x111C
	setflag 0x111D
	clearflag 0x111A
	clearflag 0x1117
	clearflag 0x1119
	warp MAP_GOLDENROD_CITY_INTERIOR17, 4, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior17_EventScript_Sign3_3::
	clearflag 0x1112
	clearflag 0x1113
	clearflag 0x111C
	clearflag 0x111D
	warp MAP_GOLDENROD_CITY_INTERIOR17, 4, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior17_EventScript_Sign4::
	msgbox GoldenrodCity_Interior17_Text_Sign4, MSGBOX_NPC
	call_if_set 0x111E, GoldenrodCity_Interior17_EventScript_Sign4_1
	msgbox GoldenrodCity_Interior17_Text_Sign1_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, GoldenrodCity_Interior17_EventScript_Sign4_2
	releaseall
	release
	end

GoldenrodCity_Interior17_EventScript_Sign4_1::
	msgbox GoldenrodCity_Interior17_Text_Sign1_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, GoldenrodCity_Interior17_EventScript_Sign4_3
	releaseall
	release
	end

GoldenrodCity_Interior17_EventScript_Sign4_2::
	setflag 0x111E
	setflag 0x1115
	setflag 0x111A
	setflag 0x111D
	clearflag 0x1113
	clearflag 0x1114
	clearflag 0x1116
	clearflag 0x1117
	clearflag 0x1118
	clearflag 0x1119
	clearflag 0x111B
	clearflag 0x111C
	warp MAP_GOLDENROD_CITY_INTERIOR17, 5, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

GoldenrodCity_Interior17_EventScript_Sign4_3::
	clearflag 0x111E
	clearflag 0x1115
	clearflag 0x111A
	clearflag 0x111D
	warp MAP_GOLDENROD_CITY_INTERIOR17, 5, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)
