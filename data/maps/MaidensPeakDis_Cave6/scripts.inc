MaidensPeakDis_Cave6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MaidensPeakDis_Cave6_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MaidensPeakDis_Cave6_OnResume
	.byte 0

MaidensPeakDis_Cave6_OnTransition::
	call_if_set 0x2F3, MaidensPeakDis_Cave6_EventScript_OnTransition_1
	call_if_unset 0x2F3, MaidensPeakDis_Cave6_EventScript_OnTransition_2
	end

MaidensPeakDis_Cave6_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, MaidensPeakDis_Cave6_EventScript_OnResume_1
	end

MaidensPeakDis_Cave6_EventScript_OnTransition_1::
	setvar VAR_TEMP_1, 1
	setflag 0x09C
	return

MaidensPeakDis_Cave6_EventScript_OnTransition_2::
	setvar VAR_TEMP_1, 1
	goto_if_set 0x2F6, EventScript_Return
	setvar VAR_TEMP_1, 0
	clearflag 0x09C
	return

MaidensPeakDis_Cave6_EventScript_OnResume_1::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, 7, EventScript_Return
	removeobject 1
	return

MaidensPeakDis_Cave6_EventScript_Trigger::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lockall
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 35
	special LoopWingFlapSound
	applymovement 1, MaidensPeakDis_Cave6_Movement_Trigger_1
	applymovement LOCALID_CAMERA, MaidensPeakDis_Cave6_Movement_Trigger_2
	waitmovement 0
	delay 50
	setweather WEATHER_NONE
	doweather
	waitse
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 35
	special LoopWingFlapSound
	applymovement LOCALID_CAMERA, MaidensPeakDis_Cave6_Movement_Trigger_3
	applymovement 1, MaidensPeakDis_Cave6_Movement_Trigger_4
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_0x8004, 250
	setvar VAR_0x8005, 70
	setvar VAR_0x8006, 0
	special CreateEnemyEventMon
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	setvar VAR_LAST_TALKED, 1
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, 1, MaidensPeakDis_Cave6_EventScript_Trigger_1
	goto_if_eq VAR_RESULT, 4, MaidensPeakDis_Cave6_EventScript_Trigger_2
	goto_if_eq VAR_RESULT, 5, MaidensPeakDis_Cave6_EventScript_Trigger_2
	setflag 0x2F3
	releaseall
	end

MaidensPeakDis_Cave6_EventScript_Trigger_1::
	setflag 0x2F6
	setvar VAR_0x8004, 250
	goto EventScript_MonFlewAway

MaidensPeakDis_Cave6_EventScript_Trigger_2::
	setvar VAR_0x8004, 250
	goto EventScript_MonFlewAway

MaidensPeakDis_Cave6_Movement_Trigger_1::
	delay_16
	delay_16
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end

MaidensPeakDis_Cave6_Movement_Trigger_2::
	walk_up
	walk_up
	walk_up
	step_end

MaidensPeakDis_Cave6_Movement_Trigger_3::
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

MaidensPeakDis_Cave6_Movement_Trigger_4::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	delay_16
	delay_16
	step_end
