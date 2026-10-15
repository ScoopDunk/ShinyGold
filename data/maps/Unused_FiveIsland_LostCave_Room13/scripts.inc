Unused_FiveIsland_LostCave_Room13_MapScripts::
	@ ShinyGold: overlapping data duplicated from 0x08164CCD
	@ ShinyGold: 11 entries with invalid type(s) 0xE0, 0x08, 0x08, 0x08, 0x16, 0x92, 0xF0, 0x08, 0x1A, 0x4D, 0x5E dropped (inert: the engine skips them)
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Unused_FiveIsland_LostCave_Room13_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x164CFC03
	map_script MAP_SCRIPT_ON_TRANSITION, Unused_FiveIsland_LostCave_Room13_OnTransition
	.byte 0

Unused_FiveIsland_LostCave_Room13_OnTransition::
	call EventScript_TryDarkenRuins
	end

Unused_FiveIsland_LostCave_Room13_OnWarp::
	map_script_2 0x492B, 0x608, 0x1A77A901
	map_script_2 0xA408, 11, 0xB22503A5  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x6D01, 0x52F, 0x80061600
	map_script_2 0x0001, 0xB225, 0x03C70301  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x000F, 0x5E31, 0x0409081A
	map_script_2 0x026C, 0x1731, 0x2E190BFF  @ ShinyGold: can never match
	map_script_2 0xFF1B, 0x61D, 0xFF1E0D0F  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x0915, 0x1E07, 0x1E3103FF  @ ShinyGold: can never match
	map_script_2 0x01FF, 0x305, 0x060D0FFF  @ ShinyGold: can never match
	map_script_2 0x13FF, 0x191B, 0x35311EFF  @ ShinyGold: can never match
	map_script_2 0x0BFF, 0x709, 0x15110EFF  @ ShinyGold: can never match
	map_script_2 0x17FF, 0x1D1F, 0x332EFF16  @ ShinyGold: can never match
	map_script_2 0x393B, 0x2CFF, 0x09FF04FF  @ ShinyGold: can never match
	map_script_2 0x0935, 0x3B1D, 0x1B060D1E  @ ShinyGold: can never match
	map_script_2 0xFF0F, 0x10D, 0x09130016  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x1B01, 0x1B06, 0x3309FF0F  @ ShinyGold: can never match
	map_script_2 0x1606, 0x91E, 0xFF09031B  @ ShinyGold: can never match
	map_script_2 0x010D, 22, 0x1B010913  @ ShinyGold: can never match
	map_script_2 0x1B06, 0xFF0F, 0x1B060905  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x000F, 0x1501, 0xFF093506  @ ShinyGold: can never match
	map_script_2 0x010D, 22, 0x1B010913  @ ShinyGold: can never match
	map_script_2 0x1B06, 0xFF0F, 0x0935010D  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x0B00, 0x91D, 0xFF161301  @ ShinyGold: can never match
	map_script_2 0x1631, 9, 0x092E1917  @ ShinyGold: can never match
	map_script_2 0x2C1D, 0x15FF, 0x1E001E09  @ ShinyGold: can never match
	map_script_2 0x090D, 0x1E00, 0x0FFF192E  @ ShinyGold: can never match
	map_script_2 0x0615, 0x1E1E, 0x1B061D09  @ ShinyGold: can never match
	map_script_2 0xFF0F, 0x1E16, 0x16091B19  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x19FF, 0x91B, 0x001B0600  @ ShinyGold: can never match
	map_script_2 0x091D, 0xFF0B, 0x00091B19  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x1B06, 0x500, 0xFF093115  @ ShinyGold: can never match
	map_script_2 0x1903, 0x1B1B, 0x001E0309  @ ShinyGold: can never match
	map_script_2 0x0D1E, 0xFF09, 0x1E160117  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0xFF2C, 0x2E1E, 0x1D070019  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x0906, 0xB1B, 0x0D16FF16  @ ShinyGold: can never match
	map_script_2 0x1D01, 0x1B06, 0x1917FF0F  @ ShinyGold: can never match
	map_script_2 0x092E, 29, 0x1B091719  @ ShinyGold: can never match
	map_script_2 0x01FF, 0x2E00, 0x190B1B06  @ ShinyGold: can never match
	map_script_2 0x002E, 0x191E, 0x1B0001FF  @ ShinyGold: can never match
	map_script_2 0x2E09, 0x2E00, 0x0B151D19  @ ShinyGold: can never match
	map_script_2 0x1EFF, 0x10D, 0x150F001E  @ ShinyGold: can never match
	map_script_2 0x2E19, 0x2C16, 0x090D1EFF  @ ShinyGold: can never match
	map_script_2 0x1B00, 0x3309, 0x192EFF1E  @ ShinyGold: can never match
	map_script_2 0x151D, 11, 0x1E06012E  @ ShinyGold: can never match
	map_script_2 0xFF16, 0x1907, 0x193B001D  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x2C31, 0x5CFF, 0x00005900
	map_script_2 0x6000, 0x1835, 0x1835A008
	map_script_2 0x2608, VAR_RESULT, 0x0D210039
	map_script_2 0x0180, 0x600, 0x1A93F001  @ ShinyGold: can never match
	map_script_2 0x0F08, 0xB400, 0x09081835  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x0206, 0x55C, 0x00000059  @ ShinyGold: can never match
	map_script_2 0x149D, 0x81C, 0x081835A0  @ ShinyGold: can never match
	map_script_2 0x000F, 0x35B4, 0x06090818  @ ShinyGold: can never match
	map_script_2 0x5C02, 0x5A00, 0x86000000
	map_script_2 0x1837, 0xBD08, 0x26081837  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 VAR_RESULT, 57, 0x01800D21
	map_script_2 0x0600, 0x2E01, 0x0F081A94  @ ShinyGold: can never match
	map_script_2 0xCF00, 0x1837, 0x02060908  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x055C, 90, 0x15880000  @ ShinyGold: can never match
	map_script_2 0x081C, 0x37BD, 0x000F0818  @ ShinyGold: can never match
	map_script_2 0x37CF, 0x818, 0x5C020609  @ ShinyGold: can never match
	map_script_2 0x6900, 0, 0x1834E600
	map_script_2 0x0908, 0x1835, 0x800D2608  @ ShinyGold: can never match
	map_script_2 0x0039, 0xD21, 0x06000180  @ ShinyGold: can never match
	map_script_2 0x6C01, 0x1A94, 0x1C000F08
	map_script_2 0x1835, 0x908, 0x055C0206  @ ShinyGold: can never match
	map_script_2 0x0069, 0, 0x081C147A  @ ShinyGold: can never match
	map_script_2 0x3509, 0x818, 0x351C000F  @ ShinyGold: can never match
	map_script_2 0x0818, 0x609, 0x6A005C02  @ ShinyGold: can never match
	.2byte 0

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
