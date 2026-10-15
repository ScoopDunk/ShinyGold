Unused_FiveIsland_LostCave_Room13_MapScripts::
	@ ShinyGold: overlapping data duplicated from 0x08164CCD
	@ ShinyGold: 11 entries with invalid type(s) 0xE0, 0x08, 0x08, 0x08, 0x16, 0x92, 0xF0, 0x08, 0x1A, 0x4D, 0x5E dropped (inert: the engine skips them)
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x164CFC03
	map_script MAP_SCRIPT_ON_TRANSITION, Unused_FiveIsland_LostCave_Room13_OnTransition
	.byte 0

Unused_FiveIsland_LostCave_Room13_OnTransition::
	call EventScript_TryDarkenRuins
	end

Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	msgbox Unused_FiveIsland_LostCave_Room13_Text_MgDeliveryman_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_2
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1::
	msgbox Unused_FiveIsland_LostCave_Room13_Text_MgDeliveryman_2, MSGBOX_NPC
	call Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_3
	end

Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_2::
	msgbox Unused_FiveIsland_LostCave_Room13_Text_MgDeliveryman_3, MSGBOX_NPC
	giveitem ITEM_ORAN_BERRY
	call Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_4
	end

Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_3::
	copyvar VAR_RESULT, VAR_0x8001
	call_if_eq VAR_RESULT, 0, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_2
	call_if_eq VAR_RESULT, 1, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_5
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_6
	call_if_eq VAR_RESULT, 3, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_7
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_4::
	msgbox Unused_FiveIsland_LostCave_Room13_Text_MgDeliveryman_4, MSGBOX_NPC
	call Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_8
	warp MAP_NATIONAL_PARK_INTERIOR1, 1, 0x4502, 5
	end

Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_5::
	msgbox Unused_FiveIsland_LostCave_Room13_Text_MgDeliveryman_5, MSGBOX_NPC
	giveitem ITEM_SITRUS_BERRY
	call Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_4
	end

Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_6::
	msgbox Unused_FiveIsland_LostCave_Room13_Text_MgDeliveryman_6, MSGBOX_NPC
	giveitem ITEM_EVERSTONE
	call Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_4
	end

Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_7::
	msgbox Unused_FiveIsland_LostCave_Room13_Text_MgDeliveryman_7, MSGBOX_NPC
	giveitem ITEM_SUN_STONE
	call Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_4
	end

Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_8::
	removeitem ITEM_SAFARI_BALL, 5
	goto_if_eq VAR_RESULT, 1, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_9
	removeitem ITEM_SAFARI_BALL, 4
	goto_if_eq VAR_RESULT, 1, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_10
	removeitem ITEM_SAFARI_BALL, 3
	goto_if_eq VAR_RESULT, 1, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_11
	removeitem ITEM_SAFARI_BALL, 2
	goto_if_eq VAR_RESULT, 1, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_12
	removeitem ITEM_SAFARI_BALL
	goto_if_eq VAR_RESULT, 1, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_13
	return

Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_9::
	return

Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_10::
	return

Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_11::
	return

Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_12::
	return

Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_13::
	return

Unused_FiveIsland_LostCave_Room13_EventScript_Youngster::
	msgbox Unused_FiveIsland_LostCave_Room13_Text_Youngster, MSGBOX_NPC
	end

Unused_FiveIsland_LostCave_Room13_EventScript_BugCatcher::
	msgbox Unused_FiveIsland_LostCave_Room13_Text_BugCatcher, MSGBOX_NPC
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Boy::
	msgbox Unused_FiveIsland_LostCave_Room13_Text_Boy, MSGBOX_NPC
	end

Unused_FiveIsland_LostCave_Room13_EventScript_BugCatcher2::
	msgbox Unused_FiveIsland_LostCave_Room13_Text_BugCatcher2, MSGBOX_NPC
	end

Unused_FiveIsland_LostCave_Room13_EventScript_BaldingMan::
	msgbox Unused_FiveIsland_LostCave_Room13_Text_BaldingMan, MSGBOX_NPC
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger1::
	call_if_set 0x109B, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger1_1
	call_if_set 0x109C, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger1_2
	call_if_set 0x109D, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger1_3
	call_if_set 0x109E, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger1_4
	call_if_set 0x109F, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger1_5
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger1_1::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109D
	clearflag 0x109B
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_PARAS, 13
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger1_2::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109B
	clearflag 0x109C
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_WURMPLE, 10
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger1_3::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109F
	clearflag 0x109D
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_PARAS, 12
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger1_4::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109C
	clearflag 0x109E
	setvar VAR_0x8001, 1
	setwildbattle SPECIES_WEEDLE, 18
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger1_5::
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger4::
	call_if_set 0x109D, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger4_1
	call_if_set 0x109E, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger4_2
	call_if_set 0x109B, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger4_3
	call_if_set 0x109F, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger4_4
	call_if_set 0x109C, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger4_5
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger4_1::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109F
	clearflag 0x109D
	setvar VAR_0x8001, 2
	setwildbattle SPECIES_METAPOD, 16
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger4_2::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109C
	clearflag 0x109E
	setvar VAR_0x8001, 2
	setwildbattle SPECIES_SCYTHER, 13
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger4_3::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109D
	clearflag 0x109B
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_METAPOD, 10
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger4_4::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109E
	clearflag 0x109F
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_CATERPIE, 15
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger4_5::
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger7::
	call_if_set 0x109E, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger7_1
	call_if_set 0x109B, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger7_2
	call_if_set 0x109D, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger7_3
	call_if_set 0x109F, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger7_4
	call_if_set 0x109C, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger7_5
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger7_1::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109B
	clearflag 0x109E
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_VENONAT, 12
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger7_2::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109D
	clearflag 0x109B
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_KAKUNA, 11
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger7_3::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109E
	clearflag 0x109D
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_WEEDLE, 13
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger7_4::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109C
	clearflag 0x109F
	setvar VAR_0x8001, 2
	setwildbattle SPECIES_PINSIR, 13
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger7_5::
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger10::
	call_if_set 0x109D, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger10_1
	call_if_set 0x109C, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger10_2
	call_if_set 0x109B, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger10_3
	call_if_set 0x109F, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger10_4
	call_if_set 0x109E, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger10_5
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger10_1::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109F
	clearflag 0x109D
	setvar VAR_0x8001, 3
	setwildbattle SPECIES_BUTTERFREE, 15
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger10_2::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109B
	clearflag 0x109C
	setvar VAR_0x8001, 1
	setwildbattle SPECIES_METAPOD, 14
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger10_3::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109D
	clearflag 0x109B
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_VENONAT, 10
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger10_4::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109E
	clearflag 0x109F
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_WEEDLE, 8
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger10_5::
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger13::
	call_if_set 0x109B, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger13_1
	call_if_set 0x109D, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger13_2
	call_if_set 0x109F, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger13_3
	call_if_set 0x109E, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger13_4
	call_if_set 0x109C, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger13_5
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger13_1::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109E
	clearflag 0x109B
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_WEEDLE, 11
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger13_2::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109C
	clearflag 0x109D
	setvar VAR_0x8001, 0
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger13_3::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109B
	clearflag 0x109F
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_METAPOD, 11
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger13_4::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109D
	clearflag 0x109E
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_WURMPLE, 12
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger13_5::
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger16::
	call_if_set 0x109F, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger16_1
	call_if_set 0x109E, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger16_2
	call_if_set 0x109D, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger16_3
	call_if_set 0x109C, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger16_4
	call_if_set 0x109B, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger16_5
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger16_1::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109B
	clearflag 0x109F
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_CATERPIE, 9
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger16_2::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109F
	clearflag 0x109E
	setvar VAR_0x8001, 2
	setwildbattle SPECIES_BUTTERFREE, 13
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger16_3::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109C
	clearflag 0x109D
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_PARAS, 11
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger16_4::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109D
	clearflag 0x109C
	setvar VAR_0x8001, 3
	setwildbattle SPECIES_SCYTHER, 14
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger16_5::
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger19::
	call_if_set 0x109C, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger19_1
	call_if_set 0x109F, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger19_2
	call_if_set 0x109B, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger19_3
	call_if_set 0x109E, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger19_4
	call_if_set 0x109D, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger19_5
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger19_1::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109F
	clearflag 0x109C
	setvar VAR_0x8001, 2
	setwildbattle SPECIES_SURSKIT, 8
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger19_2::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109D
	clearflag 0x109F
	setvar VAR_0x8001, 1
	setwildbattle SPECIES_BUTTERFREE, 12
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger19_3::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109E
	clearflag 0x109B
	setvar VAR_0x8001, 1
	setwildbattle SPECIES_CATERPIE, 18
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger19_4::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109C
	clearflag 0x109E
	setvar VAR_0x8001, 3
	setwildbattle SPECIES_BEEDRILL, 15
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger19_5::
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger23::
	call_if_set 0x109E, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger23_1
	call_if_set 0x109D, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger23_2
	call_if_set 0x109C, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger23_3
	call_if_set 0x109F, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger23_4
	call_if_set 0x109B, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger23_5
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger23_1::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109B
	clearflag 0x109E
	setvar VAR_0x8001, 2
	setwildbattle SPECIES_PARAS, 17
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger23_2::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109C
	clearflag 0x109D
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_WEEDLE, 16
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger23_3::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109D
	clearflag 0x109C
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_SILCOON, 12
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger23_4::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109E
	clearflag 0x109F
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_PARAS, 15
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger23_5::
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger26::
	call_if_set 0x109F, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger26_1
	call_if_set 0x109B, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger26_2
	call_if_set 0x109E, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger26_3
	call_if_set 0x109C, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger26_4
	call_if_set 0x109D, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger26_5
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger26_1::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109D
	clearflag 0x109F
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_CATERPIE, 16
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger26_2::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109F
	clearflag 0x109B
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_KAKUNA, 12
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger26_3::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109C
	clearflag 0x109E
	setvar VAR_0x8001, 1
	setwildbattle SPECIES_SILCOON, 13
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger26_4::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109B
	clearflag 0x109C
	setvar VAR_0x8001, 2
	setwildbattle SPECIES_KAKUNA, 16
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger26_5::
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger29::
	call_if_set 0x109C, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger29_1
	call_if_set 0x109B, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger29_2
	call_if_set 0x109F, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger29_3
	call_if_set 0x109D, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger29_4
	call_if_set 0x109E, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger29_5
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger29_1::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109F
	clearflag 0x109C
	setvar VAR_0x8001, 1
	setwildbattle SPECIES_KAKUNA, 14
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger29_2::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109E
	clearflag 0x109B
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_CATERPIE, 14
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger29_3::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109D
	clearflag 0x109F
	setvar VAR_0x8001, 1
	setwildbattle SPECIES_VENONAT, 15
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger29_4::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109C
	clearflag 0x109D
	setvar VAR_0x8001, 1
	setwildbattle SPECIES_PARAS, 16
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger29_5::
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger33::
	call_if_set 0x109F, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger33_1
	call_if_set 0x109D, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger33_2
	call_if_set 0x109E, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger33_3
	call_if_set 0x109B, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger33_4
	call_if_set 0x109C, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger33_5
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger33_1::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109C
	clearflag 0x109F
	setvar VAR_0x8001, 1
	setwildbattle SPECIES_BEEDRILL, 13
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger33_2::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109F
	clearflag 0x109D
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_VENONAT, 13
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger33_3::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109B
	clearflag 0x109E
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_WURMPLE, 7
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger33_4::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109E
	clearflag 0x109B
	setvar VAR_0x8001, 2
	setwildbattle SPECIES_BEEDRILL, 14
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger33_5::
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger36::
	call_if_set 0x109E, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger36_1
	call_if_set 0x109B, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger36_2
	call_if_set 0x109D, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger36_3
	call_if_set 0x109C, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger36_4
	call_if_set 0x109F, Unused_FiveIsland_LostCave_Room13_EventScript_Trigger36_5
	release
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger36_1::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109D
	clearflag 0x109E
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_CATERPIE, 10
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger36_2::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109E
	clearflag 0x109B
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_WURMPLE, 16
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger36_3::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109C
	clearflag 0x109D
	setvar VAR_0x8001, 3
	setwildbattle SPECIES_PINSIR, 14
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger36_4::
	getpartysize
	call_if_eq VAR_RESULT, 2, Unused_FiveIsland_LostCave_Room13_EventScript_MgDeliveryman_1
	setflag 0x109B
	clearflag 0x109C
	setvar VAR_0x8001, 0
	setwildbattle SPECIES_BEEDRILL, 12
	special StartSouthernIslandBattle
	end

Unused_FiveIsland_LostCave_Room13_EventScript_Trigger36_5::
	release
	end
