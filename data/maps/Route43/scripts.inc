Route43_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route43_OnFrame
	.byte 0

Route43_OnFrame::
	map_script_2 0x701C, 0, Route43_EventScript_FrameScene
	.2byte 0

Route43_EventScript_FrameScene::
	setvar 0x701C, 1
	call Route43_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

Route43_EventScript_FrameScene_1::
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

Route43_EventScript_CamperSpencer::
	trainerbattle_single TRAINER_CAMPER_SPENCER, Route43_Text_CamperSpencerIntro, Route43_Text_CamperSpencerDefeat
	msgbox Route43_Text_CamperSpencer, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Picnicker472::
	trainerbattle_single TRAINER_PICNICKER_TIFFANY, Route43_Text_Picnicker472Intro, Route43_Text_Picnicker472Defeat
	call_if_set 0x1319, Route43_EventScript_Picnicker472_1
	setvar 0x700C, 25
	setvar 0x700D, 0
	call_if_set 0x1349, Route35_EventScript_Juggler228_2
	msgbox Route43_Text_Picnicker472, MSGBOX_NPC
	setflag 0x1349
	call Route35_EventScript_Juggler228_3
	end

Route43_EventScript_Picnicker472_1::
	clearflag 0x1319
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x8888, Route43_EventScript_Picnicker472_2
	call_if_set 0x8888, Route43_EventScript_Picnicker472_3
	call_if_set FLAG_BADGE07_GET, Route43_EventScript_Picnicker472_4
	call_if_set 0x110A, Route43_EventScript_Picnicker472_5
	trainerbattle_earlyrival TRAINER_PICNICKER_TIFFANY, 0, Route43_Text_Picnicker472Defeat, Route35_Text_Juggler228Victory
	release
	end

Route43_EventScript_Picnicker472_2::
	trainerbattle_earlyrival TRAINER_PICNICKER_TIFFANY_2, 0, Route43_Text_Picnicker472Defeat, Route35_Text_Juggler228Victory
	release
	end

Route43_EventScript_Picnicker472_3::
	trainerbattle_earlyrival TRAINER_PICNICKER_TIFFANY_3, 0, Route43_Text_Picnicker472Defeat, Route35_Text_Juggler228Victory
	release
	end

Route43_EventScript_Picnicker472_4::
	trainerbattle_earlyrival TRAINER_PICNICKER_TIFFANY_5, 0, Route43_Text_Picnicker472Defeat, Route35_Text_Juggler228Victory
	release
	end

Route43_EventScript_Picnicker472_5::
	trainerbattle_earlyrival TRAINER_PICNICKER_TIFFANY_4, 0, Route43_Text_Picnicker472Defeat, Route35_Text_Juggler228Victory
	release
	end

Route43_EventScript_Pokemaniac188::
	trainerbattle_single TRAINER_POKEMANIAC_BRENT, Route43_Text_Pokemaniac188Intro, Route43_Text_Pokemaniac188Defeat
	call_if_set 0x1320, Route43_EventScript_Pokemaniac188_1
	setvar 0x700C, 16
	setvar 0x700D, 0
	call_if_set 0x1350, Route35_EventScript_Juggler228_2
	msgbox Route43_Text_Pokemaniac188, MSGBOX_NPC
	setflag 0x1350
	call Route35_EventScript_Juggler228_3
	end

Route43_EventScript_Pokemaniac188_1::
	clearflag 0x1320
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x8888, Route43_EventScript_Pokemaniac188_2
	call_if_set 0x115F, Route43_EventScript_Pokemaniac188_3
	call_if_set FLAG_BADGE07_GET, Route43_EventScript_Pokemaniac188_4
	call_if_set 0x110A, Route43_EventScript_Pokemaniac188_5
	trainerbattle_earlyrival TRAINER_POKEMANIAC_BRENT, 0, Route43_Text_Pokemaniac188Defeat, Route35_Text_Juggler228Victory
	release
	end

Route43_EventScript_Pokemaniac188_2::
	trainerbattle_earlyrival TRAINER_POKEMANIAC_BRENT_2, 0, Route43_Text_Pokemaniac188Defeat, Route35_Text_Juggler228Victory
	release
	end

Route43_EventScript_Pokemaniac188_3::
	trainerbattle_earlyrival TRAINER_POKEMANIAC_BRENT_3, 0, Route43_Text_Pokemaniac188Defeat, Route35_Text_Juggler228Victory
	release
	end

Route43_EventScript_Pokemaniac188_4::
	trainerbattle_earlyrival TRAINER_POKEMANIAC_BRENT_4, 0, Route43_Text_Pokemaniac188Defeat, Route35_Text_Juggler228Victory
	release
	end

Route43_EventScript_Pokemaniac188_5::
	trainerbattle_earlyrival TRAINER_POKEMANIAC_BRENT_5, 0, Route43_Text_Pokemaniac188Defeat, Route35_Text_Juggler228Victory
	release
	end

Route43_EventScript_PokemaniacRon::
	trainerbattle_single TRAINER_POKEMANIAC_RON, Route43_Text_PokemaniacRonIntro, Route43_Text_PokemaniacRonDefeat
	msgbox Route43_Text_PokemaniacRon, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_PokemaniacBen::
	trainerbattle_single TRAINER_POKEMANIAC_BEN, Route43_Text_PokemaniacBenIntro, Route43_Text_PokemaniacBenDefeat
	msgbox Route43_Text_PokemaniacBen, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_FishermanMarvin::
	trainerbattle_single TRAINER_FISHERMAN_MARVIN, Route43_Text_FishermanMarvinIntro, Route43_Text_FishermanMarvinDefeat
	msgbox Route43_Text_FishermanMarvin, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER
	end

Route43_EventScript_Trigger1::
	call_if_set 0x1103, MahoganyTown_Interior1_EventScript_OldAmber
	setflag 0x10D6
	release
	end

Route43_EventScript_Trigger6::
	call_if_set 0x11EA, Route43_EventScript_Trigger6_1
	setflag 0x10DB
	setflag 0x10E0
	release
	end

Route43_EventScript_Trigger6_1::
	call_if_set 0x1103, Route43_EventScript_Trigger6_2
	setflag 0x10DB
	release
	end

Route43_EventScript_Trigger6_2::
	release
	end

Route43_EventScript_Sign1::
	msgbox Route43_Text_Sign1, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Sign3::
	msgbox Route43_Text_Sign3, MSGBOX_AUTOCLOSE
	end
