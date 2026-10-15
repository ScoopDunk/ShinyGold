CherrygroveCity_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CherrygroveCity_Interior1_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_LOAD, CherrygroveCity_Interior1_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x08170CA7  @ ShinyGold: shadowed by the first entry of this type (never used)
	.byte 0

CherrygroveCity_Interior1_OnLoad::
	call_if_ge 0x4076, 5, CherrygroveCity_Interior1_EventScript_OnLoad_1
	call_if_set FLAG_SYS_CAN_LINK_WITH_RS, CherrygroveCity_Interior1_EventScript_OnLoad_2
	end

CherrygroveCity_Interior1_OnFrame::
	map_script_2 0x0E9F, 0x2100, 0x00064076  @ ShinyGold: can never match
	map_script_2 0x0107, 0xC73, 0x76210817  @ ShinyGold: can never match
	map_script_2 0x0040, 0x700, 0x170C7901  @ ShinyGold: can never match
	map_script_2 0x2108, 0x4076, 0x01070002
	map_script_2 0x0C90, 0x817, 0x40761602  @ ShinyGold: can never match
	map_script_2 0x0007, 0x6303, 0x00090002
	map_script_2 0x0008, 0x265, 0x03630700  @ ShinyGold: can never match
	map_script_2 0x0F00, 0x600, 0x00036500  @ ShinyGold: can never match
	map_script_2 0x0307, 0x263, 0x07000E00  @ ShinyGold: can never match
	map_script_2 0x6500, 2, 0x00036309
	map_script_2 0x000E, 8, 0x09000365  @ ShinyGold: can never match
	map_script_2 0x7603, 64, 0x170CB100
	map_script_2 0x0008, 0x6900, 0xFF4F00C7
	map_script_2 0x7D00, 0x170E, 0x00024F08
	map_script_2 0x0E86, 0x817, 0x0F000051  @ ShinyGold: can never match
	map_script_2 0xDE00, 0x1A0C, 0x4F040908  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x00FF, 0x75EB, 0x0051081A
	map_script_2 0x2F00, 21, 0xDB00034F  @ ShinyGold: can never match
	map_script_2 0x1A75, 0x5108, 0x034F0000
	map_script_2 0xE700, 0x1A75, 0x00005108  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x034F, 0xDD00, 0x51081A75  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	.2byte 0

CherrygroveCity_Interior1_EventScript_OnLoad_1::
	setmetatile 13, 4, 0x35D, 1
	return

CherrygroveCity_Interior1_EventScript_OnLoad_2::
	call CherrygroveCity_Interior1_EventScript_OnLoad_3
	setmetatile 14, 4, 0x35A, 1
	setmetatile 15, 4, 0x35B, 1
	return

CherrygroveCity_Interior1_EventScript_OnLoad_3::
	setmetatile 16, 4, 0x35F, 1
	return

CherrygroveCity_Interior1_EventScript_Beauty::
	msgbox CherrygroveCity_Interior1_Text_Beauty, MSGBOX_NPC
	end

CherrygroveCity_Interior1_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, CherrygroveCity_Interior1_EventScript_Gentleman_1
	msgbox CherrygroveCity_Interior1_Text_Gentleman_1
	release
	end

CherrygroveCity_Interior1_EventScript_Gentleman_1::
	msgbox CherrygroveCity_Interior1_Text_Gentleman_2
	release
	end
