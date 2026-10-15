Unused_RocketHideout_B4F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Unused_RocketHideout_B4F_OnLoad
	.byte 0

Unused_RocketHideout_B4F_OnLoad::
	setvar VAR_TEMP_1, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, Unused_RocketHideout_B4F_EventScript_OnLoad_1
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, Unused_RocketHideout_B4F_EventScript_OnLoad_1
	call_if_ne VAR_TEMP_1, 2, Unused_RocketHideout_B4F_EventScript_OnLoad_2
	end

Unused_RocketHideout_B4F_EventScript_OnLoad_1::
	addvar VAR_TEMP_1, 1
	return

Unused_RocketHideout_B4F_EventScript_OnLoad_2::
	setmetatile 17, 12, 0x2CE, 1
	setmetatile 18, 12, 0x2CF, 1
	setmetatile 17, 13, 0x2D6, 1
	setmetatile 18, 13, 0x2D7, 1
	setmetatile 17, 14, 0x282, 0
	setmetatile 18, 14, 0x282, 0
	return

Unused_RocketHideout_B4F_EventScript_TeamRocketExecutive::
	lock
	faceplayer
	setvar VAR_0x8004, 15
	setvar VAR_0x8005, 0
	special SetFlavorTextFlagFromSpecialVars
	message Unused_RocketHideout_B4F_Text_TeamRocketExecutive_1
	waitmessage
	playbgm MUS_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_EXECUTIVE, Unused_RocketHideout_B4F_Text_TeamRocketExecutiveDefeat
	msgbox Unused_RocketHideout_B4F_Text_TeamRocketExecutive_2
	fadescreen FADE_TO_BLACK
	closemessage
	removeobject 1
	addobject 2
	clearflag 0x037
	setflag 0x05F
	setvar VAR_0x8004, 15
	setvar VAR_0x8005, 2
	special UpdatePickStateFromSpecialVar8005
	fadescreen FADE_FROM_BLACK
	release
	end

Unused_RocketHideout_B4F_EventScript_ItemBall::
	lock
	faceplayer
	removeobject 2
	giveitem ITEM_SILPH_SCOPE
	goto_if_eq VAR_RESULT, 0, EventScript_BagIsFull
	release
	end

Unused_RocketHideout_B4F_EventScript_RocketDuo368::
	trainerbattle_single TRAINER_ROCKET_DUO_GRUNT, Unused_RocketHideout_B4F_Text_RocketDuo368Intro, Unused_RocketHideout_B4F_Text_RocketDuo368Defeat, Unused_RocketHideout_B4F_EventScript_RocketDuo368Continue
	msgbox Unused_RocketHideout_B4F_Text_RocketDuo368
	release
	end

Unused_RocketHideout_B4F_EventScript_RocketDuo368Continue::
	msgbox Unused_RocketHideout_B4F_Text_RocketDuo368
	addobject 4
	clearflag 0x036
	release
	end

Unused_RocketHideout_B4F_EventScript_ItemBall2::
	lock
	faceplayer
	setflag 0x2A5
	removeobject 4
	giveitem ITEM_LIFT_KEY
	goto_if_eq VAR_RESULT, 0, EventScript_BagIsFull
	release
	end

Unused_RocketHideout_B4F_EventScript_TeamRocketGrunt17::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_17, Unused_RocketHideout_B4F_Text_TeamRocketGrunt17Intro, Unused_RocketHideout_B4F_Text_TeamRocketGrunt17Defeat, Unused_RocketHideout_B4F_EventScript_TeamRocketGrunt17Continue
	msgbox Unused_RocketHideout_B4F_Text_TeamRocketGrunt17, MSGBOX_AUTOCLOSE
	end

Unused_RocketHideout_B4F_EventScript_TeamRocketGrunt17Continue::
	setvar VAR_TEMP_1, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, Unused_RocketHideout_B4F_EventScript_OnLoad_1
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, Unused_RocketHideout_B4F_EventScript_OnLoad_1
	call_if_eq VAR_TEMP_1, 2, Unused_RocketHideout_B4F_EventScript_TeamRocketGrunt17_1
	call_if_eq VAR_TEMP_1, 2, Unused_RocketHideout_B4F_EventScript_TeamRocketGrunt17_2
	release
	end

Unused_RocketHideout_B4F_EventScript_TeamRocketGrunt17_1::
	setmetatile 17, 12, 0x282, 0
	setmetatile 18, 12, 0x281, 0
	setmetatile 17, 13, 0x282, 0
	setmetatile 18, 13, 0x281, 0
	setmetatile 17, 14, 0x282, 0
	setmetatile 18, 14, 0x281, 0
	return

Unused_RocketHideout_B4F_EventScript_TeamRocketGrunt17_2::
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	return

Unused_RocketHideout_B4F_EventScript_TeamRocketGrunt16::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_16, Unused_RocketHideout_B4F_Text_TeamRocketGrunt16Intro, Unused_RocketHideout_B4F_Text_TeamRocketGrunt16Defeat, Unused_RocketHideout_B4F_EventScript_TeamRocketGrunt16Continue
	msgbox Unused_RocketHideout_B4F_Text_TeamRocketGrunt16, MSGBOX_AUTOCLOSE
	end

Unused_RocketHideout_B4F_EventScript_TeamRocketGrunt16Continue::
	setvar VAR_TEMP_1, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, Unused_RocketHideout_B4F_EventScript_OnLoad_1
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, Unused_RocketHideout_B4F_EventScript_OnLoad_1
	call_if_eq VAR_TEMP_1, 2, Unused_RocketHideout_B4F_EventScript_TeamRocketGrunt17_1
	call_if_eq VAR_TEMP_1, 2, Unused_RocketHideout_B4F_EventScript_TeamRocketGrunt17_2
	release
	end
