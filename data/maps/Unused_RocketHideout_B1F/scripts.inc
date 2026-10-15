Unused_RocketHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Unused_RocketHideout_B1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Unused_RocketHideout_B1F_OnTransition
	.byte 0

Unused_RocketHideout_B1F_OnLoad::
	call_if_not_defeated TRAINER_CLASS25_GRUNT, Unused_RocketHideout_B1F_EventScript_OnLoad_1
	end

Unused_RocketHideout_B1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROCKET_HIDEOUT_B1F
	end

Unused_RocketHideout_B1F_EventScript_OnLoad_1::
	setmetatile 20, 19, 0x2CE, 1
	setmetatile 21, 19, 0x2CF, 1
	setmetatile 20, 20, 0x2D6, 1
	setmetatile 21, 20, 0x2D7, 1
	setmetatile 20, 21, 0x282, 0
	setmetatile 21, 21, 0x282, 0
	return

Unused_RocketHideout_B1F_EventScript_TeamRocketGrunt12::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_12, Unused_RocketHideout_B1F_Text_TeamRocketGrunt12Intro, Unused_RocketHideout_B1F_Text_TeamRocketGrunt12Defeat
	msgbox Unused_RocketHideout_B1F_Text_TeamRocketGrunt12, MSGBOX_AUTOCLOSE
	end

Unused_RocketHideout_B1F_EventScript_TeamRocketGrunt11::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_11, Unused_RocketHideout_B1F_Text_TeamRocketGrunt11Intro, Unused_RocketHideout_B1F_Text_TeamRocketGrunt11Defeat
	msgbox Unused_RocketHideout_B1F_Text_TeamRocketGrunt11, MSGBOX_AUTOCLOSE
	end

Unused_RocketHideout_B1F_EventScript_TeamRocketGrunt13::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_13, Unused_RocketHideout_B1F_Text_TeamRocketGrunt13Intro, Unused_RocketHideout_B1F_Text_TeamRocketGrunt13Defeat
	msgbox Unused_RocketHideout_B1F_Text_TeamRocketGrunt13, MSGBOX_AUTOCLOSE
	end

Unused_RocketHideout_B1F_EventScript_PkmnTrainer360::
	trainerbattle_single TRAINER_PKMN_TRAINER_GRUNT, Unused_RocketHideout_B1F_Text_PkmnTrainer360Intro, Unused_RocketHideout_B1F_Text_PkmnTrainer360Defeat
	msgbox Unused_RocketHideout_B1F_Text_PkmnTrainer360, MSGBOX_AUTOCLOSE
	end

Unused_RocketHideout_B1F_EventScript_Class25362::
	trainerbattle_single TRAINER_CLASS25_GRUNT, Unused_RocketHideout_B1F_Text_Class25362Intro, Unused_RocketHideout_B1F_Text_Class25362Defeat, Unused_RocketHideout_B1F_EventScript_Class25362Continue
	msgbox Unused_RocketHideout_B1F_Text_Class25362, MSGBOX_AUTOCLOSE
	end

Unused_RocketHideout_B1F_EventScript_Class25362Continue::
	call Unused_RocketHideout_B1F_EventScript_Class25362_1
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	release
	end

Unused_RocketHideout_B1F_EventScript_Class25362_1::
	setmetatile 20, 19, 0x282, 0
	setmetatile 21, 19, 0x281, 0
	setmetatile 20, 20, 0x282, 0
	setmetatile 21, 20, 0x281, 0
	setmetatile 20, 21, 0x282, 0
	setmetatile 21, 21, 0x281, 0
	return
