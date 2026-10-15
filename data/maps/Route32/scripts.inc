Route32_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route32_OnFrame
	.byte 0

Route32_OnFrame::
	map_script_2 0x7013, 0, Route32_EventScript_FrameScene
	.2byte 0

Route32_EventScript_FrameScene::
	setvar 0x7013, 1
	call Route32_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

Route32_EventScript_FrameScene_1::
	setvar 0x7010, 0
	setvar 0x7011, 0
	setvar 0x7012, 0
	setvar 0x7014, 0
	setvar 0x7015, 0
	setvar 0x7016, 0
	setvar 0x7017, 0
	setvar 0x7018, 0
	setvar 0x7019, 0
	setvar 0x701A, 0
	setvar 0x701B, 0
	setvar 0x701C, 0
	setvar 0x701D, 0
	setvar 0x701E, 0
	setvar 0x701F, 0
	setvar 0x7020, 0
	setvar 0x7021, 0
	setvar 0x7022, 0
	setvar 0x7023, 0
	setvar 0x7024, 0
	setvar 0x7025, 0
	setvar 0x7026, 0
	setvar 0x7027, 0
	setvar 0x7028, 0
	return

Route32_EventScript_CooltrainerM::
	call_if_set 0x1044, Route32_EventScript_CooltrainerM_1
	msgbox Route32_Text_CooltrainerM_1, MSGBOX_NPC
	end

Route32_EventScript_CooltrainerM_1::
	call_if_set FLAG_BADGE01_GET, Route32_EventScript_CooltrainerM_2
	msgbox Route32_Text_CooltrainerM_1, MSGBOX_NPC
	end

Route32_EventScript_CooltrainerM_2::
	call_if_set 0x1050, Route32_EventScript_CooltrainerM_3
	msgbox Route32_Text_CooltrainerM_2, MSGBOX_NPC
	giveitem ITEM_MIRACLE_SEED
	msgbox Route32_Text_CooltrainerM_3, MSGBOX_NPC
	setflag 0x1050
	end

Route32_EventScript_CooltrainerM_3::
	msgbox Route32_Text_CooltrainerM_3, MSGBOX_NPC
	end

Route32_EventScript_BaldingMan::
	call_if_set 0x1078, Route32_EventScript_BaldingMan_1
	msgbox Route32_Text_BaldingMan_1, MSGBOX_NPC
	giveitem ITEM_TM05
	msgbox Route32_Text_BaldingMan_2, MSGBOX_NPC
	setflag 0x1078
	end

Route32_EventScript_BaldingMan_1::
	msgbox Route32_Text_BaldingMan_2, MSGBOX_NPC
	end

Route32_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

Route32_EventScript_ItemGreatBall::
	finditem ITEM_GREAT_BALL
	end

Route32_EventScript_Rocker::
	faceplayer
	msgbox Route32_Text_Rocker_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route32_EventScript_Rocker_1
	msgbox Route32_Text_Rocker_2, MSGBOX_NPC
	end

Route32_EventScript_Rocker_1::
	msgbox Route32_Text_Rocker_3, MSGBOX_NPC
	end

Route32_EventScript_YoungsterAlbert::
	trainerbattle_single TRAINER_YOUNGSTER_ALBERT, Route32_Text_YoungsterAlbertIntro, Route32_Text_YoungsterAlbertDefeat
	msgbox Route32_Text_YoungsterAlbert, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_Picnicker153::
	trainerbattle_single TRAINER_PICNICKER_LIZ, Route32_Text_Picnicker153Intro, Route32_Text_Picnicker153Defeat
	call_if_set 0x1304, Route32_EventScript_Picnicker153_1
	setvar 0x700C, 4
	setvar 0x700D, 0
	call_if_set 0x1334, Route35_EventScript_Juggler228_2
	msgbox Route32_Text_Picnicker153, MSGBOX_NPC
	setflag 0x1334
	call Route35_EventScript_Juggler228_3
	end

Route32_EventScript_Picnicker153_1::
	clearflag 0x1304
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x8888, Route32_EventScript_Picnicker153_2
	call_if_set 0x110A, Route32_EventScript_Picnicker153_3
	call_if_set FLAG_BADGE05_GET, Route32_EventScript_Picnicker153_4
	call_if_set FLAG_BADGE04_GET, Route32_EventScript_Picnicker153_5
	trainerbattle_earlyrival TRAINER_PICNICKER_LIZ, 0, Route32_Text_Picnicker153Defeat, Route35_Text_Juggler228Victory
	release
	end

Route32_EventScript_Picnicker153_2::
	trainerbattle_earlyrival TRAINER_PICNICKER_LIZ_3, 0, Route32_Text_Picnicker153Defeat, Route35_Text_Juggler228Victory
	release
	end

Route32_EventScript_Picnicker153_3::
	trainerbattle_earlyrival TRAINER_PICNICKER_LIZ_4, 0, Route32_Text_Picnicker153Defeat, Route35_Text_Juggler228Victory
	release
	end

Route32_EventScript_Picnicker153_4::
	trainerbattle_earlyrival TRAINER_PICNICKER_LIZ_5, 0, Route32_Text_Picnicker153Defeat, Route35_Text_Juggler228Victory
	release
	end

Route32_EventScript_Picnicker153_5::
	trainerbattle_earlyrival TRAINER_PICNICKER_LIZ_2, 0, Route32_Text_Picnicker153Defeat, Route35_Text_Juggler228Victory
	release
	end

Route32_EventScript_CamperRoland::
	trainerbattle_single TRAINER_CAMPER_ROLAND, Route32_Text_CamperRolandIntro, Route32_Text_CamperRolandDefeat
	msgbox Route32_Text_CamperRoland, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FishermanHenry::
	trainerbattle_single TRAINER_FISHERMAN_HENRY, Route32_Text_FishermanHenryIntro, Route32_Text_FishermanHenryDefeat
	msgbox Route32_Text_FishermanHenry, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FishermanJustin::
	trainerbattle_single TRAINER_FISHERMAN_JUSTIN, Route32_Text_FishermanJustinIntro, Route32_Text_FishermanJustinDefeat
	msgbox Route32_Text_FishermanJustin, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_BirdKeeperPeter::
	trainerbattle_single TRAINER_BIRD_KEEPER_PETER, Route32_Text_BirdKeeperPeterIntro, Route32_Text_BirdKeeperPeterDefeat
	msgbox Route32_Text_BirdKeeperPeter, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterGordon::
	trainerbattle_single TRAINER_YOUNGSTER_GORDON, Route32_Text_YoungsterGordonIntro, Route32_Text_YoungsterGordonDefeat
	msgbox Route32_Text_YoungsterGordon, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_Fisherman146::
	trainerbattle_single TRAINER_FISHERMAN_RALPH, Route32_Text_Fisherman146Intro, Route32_Text_Fisherman146Defeat
	call_if_set 0x1303, Route32_EventScript_Fisherman146_1
	setvar 0x700C, 3
	setvar 0x700D, 0
	call_if_set 0x1333, Route35_EventScript_Juggler228_2
	msgbox Route32_Text_Fisherman146, MSGBOX_NPC
	setflag 0x1333
	call Route35_EventScript_Juggler228_3
	end

Route32_EventScript_Fisherman146_1::
	clearflag 0x1303
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x8888, Route32_EventScript_Fisherman146_2
	call_if_set FLAG_BADGE07_GET, Route32_EventScript_Fisherman146_3
	call_if_set FLAG_BADGE05_GET, Route32_EventScript_Fisherman146_4
	call_if_set FLAG_BADGE04_GET, Route32_EventScript_Fisherman146_5
	trainerbattle_earlyrival TRAINER_FISHERMAN_RALPH, 0, Route32_Text_Fisherman146Defeat, Route35_Text_Juggler228Victory
	release
	end

Route32_EventScript_Fisherman146_2::
	trainerbattle_earlyrival TRAINER_FISHERMAN_RALPH_5, 0, Route32_Text_Fisherman146Defeat, Route35_Text_Juggler228Victory
	release
	end

Route32_EventScript_Fisherman146_3::
	trainerbattle_earlyrival TRAINER_FISHERMAN_RALPH_4, 0, Route32_Text_Fisherman146Defeat, Route35_Text_Juggler228Victory
	release
	end

Route32_EventScript_Fisherman146_4::
	trainerbattle_earlyrival TRAINER_FISHERMAN_RALPH_3, 0, Route32_Text_Fisherman146Defeat, Route35_Text_Juggler228Victory
	release
	end

Route32_EventScript_Fisherman146_5::
	trainerbattle_earlyrival TRAINER_FISHERMAN_RALPH_2, 0, Route32_Text_Fisherman146Defeat, Route35_Text_Juggler228Victory
	release
	end

Route32_EventScript_ItemSuperPotion::
	finditem ITEM_SUPER_POTION
	end

Route32_EventScript_ItemGreatBall2::
	finditem ITEM_GREAT_BALL
	end

Route32_EventScript_Trigger1::
	call_if_set 0x1044, Route32_EventScript_Trigger1_1
	applymovement 1, Route32_Movement_Trigger1_1
	applymovement LOCALID_PLAYER, Route32_Movement_Trigger1_2
	delay 5
	msgbox Route32_Text_Trigger1, MSGBOX_NPC
	applymovement 1, Route32_Movement_Trigger1_3
	applymovement LOCALID_PLAYER, Route32_Movement_Trigger1_4
	delay 16
	msgbox Route32_Text_CooltrainerM_1, MSGBOX_NPC
	applymovement 1, Route32_Movement_Trigger1_5
	delay 16
	end

Route32_EventScript_Trigger1_1::
	call_if_set FLAG_BADGE01_GET, Route32_EventScript_Trigger1_2
	applymovement 1, Route32_Movement_Trigger1_1
	applymovement LOCALID_PLAYER, Route32_Movement_Trigger1_2
	delay 5
	msgbox Route32_Text_Trigger1, MSGBOX_NPC
	applymovement 1, Route32_Movement_Trigger1_3
	applymovement LOCALID_PLAYER, Route32_Movement_Trigger1_4
	delay 16
	msgbox Route32_Text_CooltrainerM_1, MSGBOX_NPC
	applymovement 1, Route32_Movement_Trigger1_5
	delay 16
	end

Route32_EventScript_Trigger1_2::
	release
	end

Route32_Movement_Trigger1_1::
	face_left
	step_end

Route32_Movement_Trigger1_2::
	face_right
	step_end

Route32_Movement_Trigger1_3::
	walk_fast_left
	walk_up
	step_end

Route32_Movement_Trigger1_4::
	walk_up
	walk_up
	face_down_fast
	step_end

Route32_Movement_Trigger1_5::
	walk_fast_down
	walk_fast_right
	face_left
	step_end

Route32_EventScript_Trigger2::
	call_if_set 0x1051, Route32_EventScript_Trigger2_1
	applymovement LOCALID_PLAYER, Route32_Movement_Trigger2_1
	applymovement 6, Route32_Movement_Trigger2_2
	msgbox Route32_Text_Rocker_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route32_EventScript_Trigger2_2
	msgbox Route32_Text_Rocker_2, MSGBOX_NPC
	setflag 0x1051
	end

Route32_EventScript_Trigger2_1::
	release
	end

Route32_EventScript_Trigger2_2::
	msgbox Route32_Text_Rocker_3, MSGBOX_NPC
	setflag 0x1051
	end

Route32_Movement_Trigger2_1::
	face_up
	step_end

Route32_Movement_Trigger2_2::
	face_down_fast
	step_end

Route32_EventScript_Trigger3::
	call_if_set 0x1053, Route32_EventScript_Trigger3_1
	setflag 0x1052
	release
	end

Route32_EventScript_Trigger3_1::
	release
	end

Route32_EventScript_Sign1::
	msgbox Route32_Text_Sign1, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_Sign2::
	msgbox Route32_Text_Sign2, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_Sign3::
	msgbox Route32_Text_Sign3, MSGBOX_NPC
	end
