ViridianCity_Interior5_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_Interior5_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ViridianCity_Interior5_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

ViridianCity_Interior5_OnFrame::
	map_script_2 0x407C, 1, CableClub_EventScript_Tutorial
	map_script_2 VAR_CABLE_CLUB_STATE, 1, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, 2, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, 5, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, 3, CableClub_EventScript_ExitTradeCenter
	map_script_2 VAR_CABLE_CLUB_STATE, 6, CableClub_EventScript_ExitUnionRoom
	map_script_2 VAR_CABLE_CLUB_STATE, 7, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, 8, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

ViridianCity_Interior5_OnWarp::
	map_script_2 VAR_CABLE_CLUB_STATE, 1, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, 2, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, 5, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, 3, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, 6, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, 7, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, 8, EventScript_CheckTurnAttendant
	.2byte 0
