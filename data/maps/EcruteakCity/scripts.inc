EcruteakCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EcruteakCity_OnFrame
	.byte 0

EcruteakCity_OnFrame::
	map_script_2 0x7025, 0, EcruteakCity_EventScript_FrameScene
	.2byte 0

EcruteakCity_EventScript_FrameScene::
	setflag 0x136F
	call NewBarkTown_EventScript_FrameScene_1
	setvar 0x7025, 1
	call EcruteakCity_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

EcruteakCity_EventScript_FrameScene_1::
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
	setvar 0x701D, 0
	setvar 0x701E, 0
	setvar 0x701F, 0
	setvar 0x7020, 0
	setvar 0x7021, 0
	setvar 0x7022, 0
	setvar 0x7023, 0
	setvar 0x7024, 0
	setvar 0x7026, 0
	setvar 0x7027, 0
	setvar 0x7028, 0
	return

EcruteakCity_EventScript_Lass::
	msgbox EcruteakCity_Text_Lass, MSGBOX_NPC
	end

EcruteakCity_EventScript_FatMan::
	msgbox EcruteakCity_Text_FatMan, MSGBOX_NPC
	end

EcruteakCity_EventScript_OldMan2::
	msgbox EcruteakCity_Text_OldMan2, MSGBOX_NPC
	end

EcruteakCity_EventScript_Man::
	msgbox EcruteakCity_Text_Man, MSGBOX_NPC
	end

EcruteakCity_EventScript_OldMan1::
	msgbox EcruteakCity_Text_OldMan1, MSGBOX_NPC
	end

EcruteakCity_EventScript_Woman2::
	msgbox EcruteakCity_Text_Woman2, MSGBOX_NPC
	end

EcruteakCity_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION
	end

EcruteakCity_EventScript_PokeManiac::
	call_if_set 0x1245, EcruteakCity_EventScript_PokeManiac_1
	msgbox EcruteakCity_Text_PokeManiac_1, MSGBOX_NPC
	giveitem ITEM_SPELL_TAG
	msgbox EcruteakCity_Text_PokeManiac_2, MSGBOX_NPC
	setflag 0x1245
	clearflag 0x1246
	release
	end

EcruteakCity_EventScript_PokeManiac_1::
	msgbox EcruteakCity_Text_PokeManiac_3, MSGBOX_NPC
	end

EcruteakCity_EventScript_Sign1::
	msgbox EcruteakCity_Text_Sign1, MSGBOX_AUTOCLOSE
	end

EcruteakCity_EventScript_Sign2::
	msgbox EcruteakCity_Text_Sign2, MSGBOX_AUTOCLOSE
	end

EcruteakCity_EventScript_Sign3::
	msgbox EcruteakCity_Text_Sign3, MSGBOX_AUTOCLOSE
	end

EcruteakCity_EventScript_Sign4::
	msgbox EcruteakCity_Text_Sign4, MSGBOX_AUTOCLOSE
	end

EcruteakCity_EventScript_Sign5::
	msgbox EcruteakCity_Text_Sign5, MSGBOX_AUTOCLOSE
	end

EcruteakCity_EventScript_Sign6::
	call_if_unset 0x1027, Route35_EventScript_Sign4_1
	setvar 0x700B, 5
	call_if_eq VAR_FACING, 2, Route35_EventScript_Sign4_2
	release
	end
