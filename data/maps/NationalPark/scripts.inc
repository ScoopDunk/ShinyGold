NationalPark_MapScripts::
	.byte 0

NationalPark_EventScript_Youngster::
	msgbox NationalPark_Text_Youngster, MSGBOX_NPC
	end

NationalPark_EventScript_BugCatcher::
	msgbox NationalPark_Text_BugCatcher, MSGBOX_NPC
	end

NationalPark_EventScript_Woman2::
	msgbox NationalPark_Text_Woman2, MSGBOX_NPC
	end

NationalPark_EventScript_Meowth::
	msgbox NationalPark_Text_Meowth, MSGBOX_NPC
	waitse
	playmoncry SPECIES_PERSIAN, 0x201
	.byte 0xFF @ invalid opcode (script stops)

NationalPark_EventScript_WorkerF::
	call_if_set 0x1133, NationalPark_EventScript_WorkerF_1
	msgbox NationalPark_Text_WorkerF_1, MSGBOX_NPC
	giveitem ITEM_QUICK_CLAW
	msgbox NationalPark_Text_WorkerF_2, MSGBOX_NPC
	setflag 0x1133
	end

NationalPark_EventScript_WorkerF_1::
	msgbox NationalPark_Text_WorkerF_2, MSGBOX_NPC
	end

NationalPark_EventScript_Pokefan145::
	trainerbattle_single TRAINER_POKEFAN_BEVERLY, NationalPark_Text_Pokefan145Intro, NationalPark_Text_Pokefan145Defeat
	call_if_set 0x1311, NationalPark_EventScript_Pokefan145_1
	setvar 0x700C, 17
	setvar 0x700D, 0
	call_if_set 0x1341, Route35_EventScript_Juggler228_2
	msgbox NationalPark_Text_Pokefan145, MSGBOX_NPC
	setflag 0x1341
	call Route35_EventScript_Juggler228_3
	end

NationalPark_EventScript_Pokefan145_1::
	clearflag 0x1311
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, NationalPark_EventScript_Pokefan145_2
	call_if_set 0x115F, NationalPark_EventScript_Pokefan145_3
	call_if_set FLAG_BADGE07_GET, NationalPark_EventScript_Pokefan145_4
	call_if_set FLAG_BADGE05_GET, NationalPark_EventScript_Pokefan145_5
	trainerbattle_earlyrival TRAINER_POKEFAN_BEVERLY, 0, NationalPark_Text_Pokefan145Defeat, Route35_Text_Juggler228Victory
	release
	end

NationalPark_EventScript_Pokefan145_2::
	trainerbattle_earlyrival TRAINER_POKEFAN_BEVERLY_5, 0, NationalPark_Text_Pokefan145Defeat, Route35_Text_Juggler228Victory
	release
	end

NationalPark_EventScript_Pokefan145_3::
	trainerbattle_earlyrival TRAINER_POKEFAN_BEVERLY_4, 0, NationalPark_Text_Pokefan145Defeat, Route35_Text_Juggler228Victory
	release
	end

NationalPark_EventScript_Pokefan145_4::
	trainerbattle_earlyrival TRAINER_POKEFAN_BEVERLY_3, 0, NationalPark_Text_Pokefan145Defeat, Route35_Text_Juggler228Victory
	release
	end

NationalPark_EventScript_Pokefan145_5::
	trainerbattle_earlyrival TRAINER_POKEFAN_BEVERLY_2, 0, NationalPark_Text_Pokefan145Defeat, Route35_Text_Juggler228Victory
	release
	end

NationalPark_EventScript_Lass::
	msgbox NationalPark_Text_Lass, MSGBOX_NPC
	end

NationalPark_EventScript_Schoolboy480::
	trainerbattle_single TRAINER_SCHOOLBOY_JACK, NationalPark_Text_Schoolboy480Intro, NationalPark_Text_Schoolboy480Defeat
	call_if_set 0x1312, NationalPark_EventScript_Schoolboy480_1
	setvar 0x700C, 18
	setvar 0x700D, 0
	call_if_set 0x1342, Route35_EventScript_Juggler228_2
	msgbox NationalPark_Text_Schoolboy480, MSGBOX_NPC
	setflag 0x1342
	call Route35_EventScript_Juggler228_3
	end

NationalPark_EventScript_Schoolboy480_1::
	clearflag 0x1312
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, NationalPark_EventScript_Schoolboy480_2
	call_if_set 0x030, NationalPark_EventScript_Schoolboy480_3
	call_if_set FLAG_BADGE07_GET, NationalPark_EventScript_Schoolboy480_4
	call_if_set FLAG_BADGE05_GET, NationalPark_EventScript_Schoolboy480_5
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_JACK, 0, NationalPark_Text_Schoolboy480Defeat, Route35_Text_Juggler228Victory
	release
	end

NationalPark_EventScript_Schoolboy480_2::
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_JACK_2, 0, NationalPark_Text_Schoolboy480Defeat, Route35_Text_Juggler228Victory
	release
	end

NationalPark_EventScript_Schoolboy480_3::
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_JACK_5, 0, NationalPark_Text_Schoolboy480Defeat, Route35_Text_Juggler228Victory
	release
	end

NationalPark_EventScript_Schoolboy480_4::
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_JACK_4, 0, NationalPark_Text_Schoolboy480Defeat, Route35_Text_Juggler228Victory
	release
	end

NationalPark_EventScript_Schoolboy480_5::
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_JACK_3, 0, NationalPark_Text_Schoolboy480Defeat, Route35_Text_Juggler228Victory
	release
	end

NationalPark_EventScript_LassKrise::
	trainerbattle_single TRAINER_LASS_KRISE, NationalPark_Text_LassKriseIntro, NationalPark_Text_LassKriseDefeat
	msgbox NationalPark_Text_LassKrise, MSGBOX_AUTOCLOSE
	end

NationalPark_EventScript_PokefanWilliam::
	trainerbattle_single TRAINER_POKEFAN_WILLIAM, NationalPark_Text_PokefanWilliamIntro, NationalPark_Text_PokefanWilliamDefeat
	msgbox NationalPark_Text_PokefanWilliam, MSGBOX_AUTOCLOSE
	end

NationalPark_EventScript_Woman3::
	msgbox NationalPark_Text_Woman3, MSGBOX_NPC
	end

NationalPark_EventScript_GbaKid::
	msgbox NationalPark_Text_GbaKid, MSGBOX_NPC
	end

NationalPark_EventScript_ItemParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

NationalPark_EventScript_ItemTm28::
	finditem ITEM_TM28
	end

NationalPark_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

NationalPark_EventScript_LittleBoy::
	call_if_set 0x1246, NationalPark_EventScript_LittleBoy_1
	msgbox NationalPark_Text_LittleBoy_1, MSGBOX_NPC
	lock
	faceplayer
	giveitem ITEM_MAGNET
	msgbox NationalPark_Text_LittleBoy_2, MSGBOX_NPC
	setflag 0x1246
	release
	end

NationalPark_EventScript_LittleBoy_1::
	msgbox NationalPark_Text_LittleBoy_3, MSGBOX_NPC
	end

NationalPark_EventScript_Sign1::
	msgbox NationalPark_Text_Sign1, MSGBOX_AUTOCLOSE
	end

NationalPark_EventScript_Sign2::
	msgbox NationalPark_Text_Sign2, MSGBOX_AUTOCLOSE
	end

NationalPark_EventScript_Sign3::
	msgbox NationalPark_Text_Sign3, MSGBOX_AUTOCLOSE
	end
