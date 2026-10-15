OlivineCity_Interior5_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OlivineCity_Interior5_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x08171D8D  @ ShinyGold: shadowed by the first entry of this type (never used)
	.byte 0

OlivineCity_Interior5_OnFrame::
	map_script_2 0x149F, 0x2100, 0x00004089  @ ShinyGold: can never match
	map_script_2 0x0107, 0x1D89, 0x2A020817  @ ShinyGold: can never match
	map_script_2 0x0098, 0x8903, 0x97000040  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x171D, 8, 0x00C76900  @ ShinyGold: can never match
	map_script_2 0x024F, 0xED00, 0x51081A75  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	.2byte 0

OlivineCity_Interior5_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

OlivineCity_Interior5_EventScript_FatMan::
	msgbox OlivineCity_Interior5_Text_FatMan, MSGBOX_NPC
	end

OlivineCity_Interior5_EventScript_WorkerF::
	msgbox OlivineCity_Interior5_Text_WorkerF, MSGBOX_NPC
	end

OlivineCity_Interior5_EventScript_Fisher::
	msgbox OlivineCity_Interior5_Text_Fisher, MSGBOX_NPC
	end
