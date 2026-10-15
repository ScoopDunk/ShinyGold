NewBarkTown_Interior5_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NewBarkTown_Interior5_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

NewBarkTown_Interior5_OnWarp::
	@ ShinyGold: overlapping data duplicated from 0x08171404
	map_script_2 0x4079, 2, NewBarkTown_Interior5_EventScript_WarpScene1
	map_script_2 VAR_CABLE_CLUB_STATE, 8, EventScript_CheckTurnAttendant
	.2byte 0

NewBarkTown_Interior5_EventScript_WarpScene1::
	@ ShinyGold: overlapping data duplicated from 0x08171416
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

NewBarkTown_Interior5_EventScript_Woman2::
	msgbox NewBarkTown_Interior5_Text_Woman2, MSGBOX_NPC
	end
