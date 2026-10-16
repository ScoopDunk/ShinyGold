Route44_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route44_OnFrame
	.byte 0

Route44_OnFrame::
	map_script_2 0x701D, 0, Route44_EventScript_FrameScene
	.2byte 0

Route44_EventScript_FrameScene::
	setvar 0x701D, 1
	call Route44_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

Route44_EventScript_FrameScene_1::
	setvar 0x7010, 0
	setvar 0x7011, 0
	setvar 0x7012, 0
	setvar 0x7013, 0
	setvar 0x7014, 0
	setvar 0x7015, 0
	setvar 0x7016, 0
	setvar 0x7017, 0
	setvar 0x7018, 0
	setvar 0x7019, 0
	setvar 0x701A, 0
	setvar 0x701B, 0
	setvar 0x701C, 0
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

Route44_EventScript_PsychicPhil::
	trainerbattle_single TRAINER_PSYCHIC_PHIL, Route44_Text_PsychicPhilIntro, Route44_Text_PsychicPhilDefeat
	msgbox Route44_Text_PsychicPhil, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_PokemaniacZach::
	trainerbattle_single TRAINER_POKEMANIAC_ZACH, Route44_Text_PokemaniacZachIntro, Route44_Text_PokemaniacZachDefeat
	msgbox Route44_Text_PokemaniacZach, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route44_EventScript_Fisherman244::
	trainerbattle_single TRAINER_FISHERMAN_WILTON, Route44_Text_Fisherman244Intro, Route44_Text_Fisherman244Defeat
	call_if_set 0x1321, Route44_EventScript_Fisherman244_1
	setvar 0x700C, 33
	setvar 0x700D, 0
	call_if_set 0x1351, Route35_EventScript_Juggler228_2
	msgbox Route44_Text_Fisherman244, MSGBOX_NPC
	setflag 0x1351
	call Route35_EventScript_Juggler228_3
	end

Route44_EventScript_Fisherman244_1::
	clearflag 0x1321
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, Route44_EventScript_Fisherman244_2
	call_if_set 0x115F, Route44_EventScript_Fisherman244_3
	call_if_set FLAG_BADGE07_GET, Route44_EventScript_Fisherman244_4
	call_if_set 0x110A, Route44_EventScript_Fisherman244_5
	trainerbattle_earlyrival TRAINER_FISHERMAN_WILTON, 0, Route44_Text_Fisherman244Defeat, Route35_Text_Juggler228Victory
	release
	end

Route44_EventScript_Fisherman244_2::
	trainerbattle_earlyrival TRAINER_FISHERMAN_WILTON_2, 0, Route44_Text_Fisherman244Defeat, Route35_Text_Juggler228Victory
	release
	end

Route44_EventScript_Fisherman244_3::
	trainerbattle_earlyrival TRAINER_FISHERMAN_WILTON_3, 0, Route44_Text_Fisherman244Defeat, Route35_Text_Juggler228Victory
	release
	end

Route44_EventScript_Fisherman244_4::
	trainerbattle_earlyrival TRAINER_FISHERMAN_WILTON_4, 0, Route44_Text_Fisherman244Defeat, Route35_Text_Juggler228Victory
	release
	end

Route44_EventScript_Fisherman244_5::
	trainerbattle_earlyrival TRAINER_FISHERMAN_WILTON_5, 0, Route44_Text_Fisherman244Defeat, Route35_Text_Juggler228Victory
	release
	end

Route44_EventScript_FishermanEdgar::
	trainerbattle_single TRAINER_FISHERMAN_EDGAR, Route44_Text_FishermanEdgarIntro, Route44_Text_FishermanEdgarDefeat
	msgbox Route44_Text_FishermanEdgar, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_CooltrainerCybil::
	trainerbattle_single TRAINER_COOLTRAINER_CYBIL, Route44_Text_CooltrainerCybilIntro, Route44_Text_CooltrainerCybilDefeat
	msgbox Route44_Text_CooltrainerCybil, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_CooltrainerAllen::
	trainerbattle_single TRAINER_COOLTRAINER_ALLEN, Route44_Text_CooltrainerAllenIntro, Route44_Text_CooltrainerAllenDefeat
	msgbox Route44_Text_CooltrainerAllen, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_BirdKeeper99::
	trainerbattle_single TRAINER_BIRD_KEEPER_VANCE, Route44_Text_BirdKeeper99Intro, Route44_Text_BirdKeeper99Defeat
	call_if_set 0x1322, Route44_EventScript_BirdKeeper99_1
	setvar 0x700C, 34
	setvar 0x700D, 0
	call_if_set 0x1352, Route35_EventScript_Juggler228_2
	msgbox Route44_Text_BirdKeeper99, MSGBOX_NPC
	setflag 0x1352
	call Route35_EventScript_Juggler228_3
	end

Route44_EventScript_BirdKeeper99_1::
	clearflag 0x1322
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, Route44_EventScript_BirdKeeper99_2
	call_if_set 0x115F, Route44_EventScript_BirdKeeper99_3
	call_if_set FLAG_BADGE07_GET, Route44_EventScript_BirdKeeper99_4
	call_if_set 0x110A, Route44_EventScript_BirdKeeper99_5
	trainerbattle_earlyrival TRAINER_BIRD_KEEPER_VANCE, 0, Route44_Text_BirdKeeper99Defeat, Route35_Text_Juggler228Victory
	release
	end

Route44_EventScript_BirdKeeper99_2::
	trainerbattle_earlyrival TRAINER_BIRD_KEEPER_VANCE_2, 0, Route44_Text_BirdKeeper99Defeat, Route35_Text_Juggler228Victory
	release
	end

Route44_EventScript_BirdKeeper99_3::
	trainerbattle_earlyrival TRAINER_BIRD_KEEPER_VANCE_3, 0, Route44_Text_BirdKeeper99Defeat, Route35_Text_Juggler228Victory
	release
	end

Route44_EventScript_BirdKeeper99_4::
	trainerbattle_earlyrival TRAINER_BIRD_KEEPER_VANCE_5, 0, Route44_Text_BirdKeeper99Defeat, Route35_Text_Juggler228Victory
	release
	end

Route44_EventScript_BirdKeeper99_5::
	trainerbattle_earlyrival TRAINER_BIRD_KEEPER_VANCE_4, 0, Route44_Text_BirdKeeper99Defeat, Route35_Text_Juggler228Victory
	release
	end

Route44_EventScript_PkmnTrainerCarlos3::
	setflag 0x112B
	msgbox Route44_Text_PkmnTrainerCarlos3_1, MSGBOX_NPC
	call Route44_EventScript_PkmnTrainerCarlos3_1
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_CARLOS_3, 0, Route44_Text_PkmnTrainerCarlos3Defeat, Route44_Text_PkmnTrainerCarlos3Victory
	msgbox Route44_Text_PkmnTrainerCarlos3_2, MSGBOX_NPC
	call Route44_EventScript_PkmnTrainerCarlos3_2
	applymovement 9, Route44_Movement_PkmnTrainerCarlos3
	delay 240
	release
	end

Route44_EventScript_PkmnTrainerCarlos3_1::
	setvar 0x7030, 0x129
	setvar 0x7033, 0x158
	release
	return

Route44_EventScript_PkmnTrainerCarlos3_2::
	setvar 0x7030, 0x158
	setvar 0x7033, 0x129
	release
	return

Route44_Movement_PkmnTrainerCarlos3::
	face_down_fast
	jump_2_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route44_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

Route44_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER
	end

Route44_EventScript_Sign1::
	msgbox Route44_Text_Sign1, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Sign2::
	msgbox Route44_Text_Sign2, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Sign3::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox Route44_Text_Sign3, MSGBOX_NPC
	giveitem ITEM_RAWST_BERRY
	releaseall
	special DaisyMassageServices
	end
