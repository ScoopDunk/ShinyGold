Route39_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route39_OnFrame
	.byte 0

Route39_OnFrame::
	map_script_2 0x701A, 0, Route39_EventScript_FrameScene
	.2byte 0

Route39_EventScript_FrameScene::
	setvar 0x701A, 1
	call Route39_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

Route39_EventScript_FrameScene_1::
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

Route39_EventScript_PsychicNorman::
	trainerbattle_single TRAINER_PSYCHIC_NORMAN, Route39_Text_PsychicNormanIntro, Route39_Text_PsychicNormanDefeat
	msgbox Route39_Text_PsychicNorman, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_Pokefan154::
	trainerbattle_single TRAINER_POKEFAN_154, Route39_Text_Pokefan154Intro, Route39_Text_Pokefan154Defeat
	call_if_set 0x1315, Route39_EventScript_Pokefan154_1
	setvar 0x700C, 21
	setvar 0x700D, 0
	call_if_set 0x1345, Route35_EventScript_Juggler228_2
	msgbox Route39_Text_Pokefan154, MSGBOX_NPC
	setflag 0x1345
	call Route35_EventScript_Juggler228_3
	end

Route39_EventScript_Pokefan154_1::
	clearflag 0x1315
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x8888, Route39_EventScript_Pokefan154_2
	call_if_set 0x115F, Route39_EventScript_Pokefan154_3
	call_if_set FLAG_BADGE07_GET, Route39_EventScript_Pokefan154_4
	call_if_set FLAG_BADGE05_GET, Route39_EventScript_Pokefan154_5
	trainerbattle_earlyrival TRAINER_POKEFAN_154, 0, Route39_Text_Pokefan154Defeat, Route35_Text_Juggler228Victory
	release
	end

Route39_EventScript_Pokefan154_2::
	trainerbattle_earlyrival TRAINER_POKEFAN_648, 0, Route39_Text_Pokefan154Defeat, Route35_Text_Juggler228Victory
	release
	end

Route39_EventScript_Pokefan154_3::
	trainerbattle_earlyrival TRAINER_POKEFAN_642, 0, Route39_Text_Pokefan154Defeat, Route35_Text_Juggler228Victory
	release
	end

Route39_EventScript_Pokefan154_4::
	trainerbattle_earlyrival TRAINER_POKEFAN_641, 0, Route39_Text_Pokefan154Defeat, Route35_Text_Juggler228Victory
	release
	end

Route39_EventScript_Pokefan154_5::
	trainerbattle_earlyrival TRAINER_POKEFAN_640, 0, Route39_Text_Pokefan154Defeat, Route35_Text_Juggler228Victory
	release
	end

Route39_EventScript_PokefanRuth::
	trainerbattle_single TRAINER_POKEFAN_RUTH, Route39_Text_PokefanRuthIntro, Route39_Text_PokefanRuthDefeat
	msgbox Route39_Text_PokefanRuth, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_SailorEugene::
	trainerbattle_single TRAINER_SAILOR_EUGENE, Route39_Text_SailorEugeneIntro, Route39_Text_SailorEugeneDefeat
	msgbox Route39_Text_SailorEugene, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_Slowbro::
	msgbox Route39_Text_Slowbro, MSGBOX_NPC
	waitse
	playmoncry SPECIES_MILTANK, 0x200
	.byte 0xFF @ invalid opcode (script stops)

Route39_EventScript_ItemNugget::
	finditem ITEM_NUGGET
	end

Route39_EventScript_Sign1::
	msgbox Route39_Text_Sign1, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_Sign2::
	msgbox Route39_Text_Sign2, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_Sign3::
	msgbox Route39_Text_Sign3, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_Sign4::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox Route39_Text_Sign4, MSGBOX_NPC
	giveitem ITEM_CHESTO_BERRY
	releaseall
	special DaisyMassageServices
	end
