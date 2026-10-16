VermilionCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
	.byte 0

VermilionCity_OnFrame::
	map_script_2 0x7046, 0, VermilionCity_EventScript_FrameScene
	.2byte 0

VermilionCity_EventScript_FrameScene::
	setflag 0x1365
	setvar 0x7046, 1
	call NewBarkTown_EventScript_FrameScene_1
	end

VermilionCity_EventScript_Woman2::
	msgbox VermilionCity_Text_Woman2, MSGBOX_NPC
	end

VermilionCity_EventScript_Man::
	msgbox VermilionCity_Text_Man, MSGBOX_NPC
	end

VermilionCity_EventScript_Snorlax::
	checkitem ITEM_POKE_FLUTE
	call_if_eq VAR_RESULT, 1, VermilionCity_EventScript_Snorlax_1
	msgbox VermilionCity_Text_Snorlax_1, MSGBOX_NPC
	end

VermilionCity_EventScript_Snorlax_1::
	msgbox VermilionCity_Text_Snorlax_1, MSGBOX_NPC
	msgbox VermilionCity_Text_Snorlax_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, VermilionCity_EventScript_Snorlax_2
	release
	end

VermilionCity_EventScript_Snorlax_2::
	setflag 0x11EC
	playfanfare MUS_POKE_FLUTE
	msgbox VermilionCity_Text_Snorlax_3
	waitfanfare
	msgbox VermilionCity_Text_Snorlax_4, MSGBOX_NPC
	waitse
	playmoncry SPECIES_SNORLAX, 0x3028
	nop
	delay 48
	setwildbattle SPECIES_SNORLAX, 50, ITEM_LEFTOVERS
	special StartLegendaryBattle
	delay 128
	warp MAP_VERMILION_CITY, 1, 0x26C, 0xC6CC
	vgoto_if 210, 0xE7DD00
	.byte 0xE7 @ invalid opcode (script stops)

VermilionCity_EventScript_BaldingMan::
	msgbox VermilionCity_Text_BaldingMan, MSGBOX_NPC
	end

VermilionCity_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

VermilionCity_EventScript_Sign1::
	msgbox VermilionCity_Text_Sign1, MSGBOX_AUTOCLOSE
	end

VermilionCity_EventScript_Sign2::
	msgbox VermilionCity_Text_Sign2, MSGBOX_AUTOCLOSE
	end

VermilionCity_EventScript_Sign3::
	msgbox VermilionCity_Text_Sign3, MSGBOX_AUTOCLOSE
	end

VermilionCity_EventScript_Sign4::
	msgbox VermilionCity_Text_Sign4, MSGBOX_AUTOCLOSE
	end

VermilionCity_EventScript_Sign5::
	msgbox VermilionCity_Text_Sign5, MSGBOX_AUTOCLOSE
	end

VermilionCity_EventScript_Sign6::
	msgbox VermilionCity_Text_Sign6, MSGBOX_AUTOCLOSE
	end

VermilionCity_EventScript_Sign7::
	msgbox VermilionCity_Text_Sign7, MSGBOX_NPC
	end
