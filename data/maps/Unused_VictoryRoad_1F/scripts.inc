Unused_VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Unused_VictoryRoad_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Unused_VictoryRoad_1F_OnTransition
	.byte 0

Unused_VictoryRoad_1F_OnLoad::
	call_if_ne 0x4064, 100, Unused_VictoryRoad_1F_EventScript_OnLoad_1
	end

Unused_VictoryRoad_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VICTORY_ROAD_1F
	end

Unused_VictoryRoad_1F_EventScript_OnLoad_1::
	setmetatile 12, 14, 0x307, 1
	setmetatile 12, 15, 0x317, 1
	return

Unused_VictoryRoad_1F_EventScript_RivalTerry8::
	trainerbattle_single TRAINER_RIVAL_TERRY_8, Unused_VictoryRoad_1F_Text_RivalTerry8Intro, Unused_VictoryRoad_1F_Text_RivalTerry8Defeat
	msgbox Unused_VictoryRoad_1F_Text_RivalTerry8, MSGBOX_AUTOCLOSE
	end

Unused_VictoryRoad_1F_EventScript_PkmnTrainerAmelia2::
	trainerbattle_single TRAINER_PKMN_TRAINER_AMELIA_2, Unused_VictoryRoad_1F_Text_PkmnTrainerAmelia2Intro, Unused_VictoryRoad_1F_Text_PkmnTrainerAmelia2Defeat
	msgbox Unused_VictoryRoad_1F_Text_PkmnTrainerAmelia2, MSGBOX_AUTOCLOSE
	end

Unused_VictoryRoad_1F_EventScript_Trigger::
	lockall
	goto_if_eq 0x4064, 100, Unused_VictoryRoad_1F_EventScript_Trigger_1
	setmetatile 12, 14, 0x2D1, 0
	setmetatile 12, 15, 0x2E1, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm 5
	setvar 0x4064, 100
	releaseall
	end

Unused_VictoryRoad_1F_EventScript_Trigger_1::
	releaseall
	end
