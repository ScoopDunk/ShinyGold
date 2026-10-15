NewBarkTown_Interior5_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Interior5_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, 0x08171404
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x0817141B
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

NewBarkTown_Interior5_OnFrame::
	map_script_2 0xFB2B, 0x702, 0x1713EF01
	map_script_2 0x0208, 0x163, 0x02000600  @ ShinyGold: can never match
	map_script_2 0x6500, 1, 0x00036508
	map_script_2 0x1601, 0x4079, 0x79030004
	map_script_2 0x0240, 0x1600, 0x6F081714  @ ShinyGold: can never match
	map_script_2 0x0840, 0x2700, 0x00081BB2  @ ShinyGold: can never match
	map_script_2 0x5B00, 255, 0x40790202
	.2byte 0

NewBarkTown_Interior5_EventScript_Woman2::
	msgbox NewBarkTown_Interior5_Text_Woman2, MSGBOX_NPC
	end
