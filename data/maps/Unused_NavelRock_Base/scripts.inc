Unused_NavelRock_Base_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Unused_NavelRock_Base_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Unused_NavelRock_Base_OnResume
	.byte 0

Unused_NavelRock_Base_OnTransition::
	call_if_set 0x2F2, Unused_NavelRock_Base_EventScript_OnTransition_1
	call_if_unset 0x2F2, Unused_NavelRock_Base_EventScript_OnTransition_2
	end

Unused_NavelRock_Base_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, Unused_NavelRock_Base_EventScript_OnResume_1
	end

Unused_NavelRock_Base_EventScript_OnTransition_1::
	setflag 0x09B
	return

Unused_NavelRock_Base_EventScript_OnTransition_2::
	goto_if_set 0x2F5, EventScript_Return
	clearflag 0x09B
	return

Unused_NavelRock_Base_EventScript_OnResume_1::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, 7, EventScript_Return
	removeobject 1
	return

Unused_NavelRock_Base_EventScript_Lugia::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	waitse
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 2
	special ShakeScreen
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 2
	special ShakeScreen
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	setvar VAR_0x8004, 249
	setvar VAR_0x8005, 70
	setvar VAR_0x8006, 0
	special CreateEnemyEventMon
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, 1, Unused_NavelRock_Base_EventScript_Lugia_1
	goto_if_eq VAR_RESULT, 4, Unused_NavelRock_Base_EventScript_Lugia_2
	goto_if_eq VAR_RESULT, 5, Unused_NavelRock_Base_EventScript_Lugia_2
	setflag 0x2F2
	release
	end

Unused_NavelRock_Base_EventScript_Lugia_1::
	setflag 0x2F5
	setvar VAR_0x8004, 249
	goto EventScript_MonFlewAway

Unused_NavelRock_Base_EventScript_Lugia_2::
	setvar VAR_0x8004, 249
	goto EventScript_MonFlewAway
