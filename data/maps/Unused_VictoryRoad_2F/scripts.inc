Unused_VictoryRoad_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Unused_VictoryRoad_2F_OnLoad
	.byte 0

Unused_VictoryRoad_2F_OnLoad::
	call_if_ne 0x4065, 100, Unused_VictoryRoad_2F_EventScript_OnLoad_1
	call_if_ne 0x4066, 100, Unused_VictoryRoad_2F_EventScript_OnLoad_2
	end

Unused_VictoryRoad_2F_EventScript_OnLoad_1::
	setmetatile 13, 10, 0x307, 1
	setmetatile 13, 11, 0x317, 1
	return

Unused_VictoryRoad_2F_EventScript_OnLoad_2::
	setmetatile 33, 16, 0x307, 1
	setmetatile 33, 17, 0x317, 1
	return

Unused_VictoryRoad_2F_EventScript_CamperSpencer::
	trainerbattle_single TRAINER_CAMPER_SPENCER, Unused_VictoryRoad_2F_Text_CamperSpencerIntro, Unused_VictoryRoad_2F_Text_CamperSpencerDefeat
	msgbox Unused_VictoryRoad_2F_Text_CamperSpencer, MSGBOX_AUTOCLOSE
	end

Unused_VictoryRoad_2F_EventScript_HikerErik::
	trainerbattle_single TRAINER_HIKER_ERIK, Unused_VictoryRoad_2F_Text_HikerErikIntro, Unused_VictoryRoad_2F_Text_HikerErikDefeat
	msgbox Unused_VictoryRoad_2F_Text_HikerErik, MSGBOX_AUTOCLOSE
	end

Unused_VictoryRoad_2F_EventScript_JugglerHorton::
	trainerbattle_single TRAINER_JUGGLER_HORTON, Unused_VictoryRoad_2F_Text_JugglerHortonIntro, Unused_VictoryRoad_2F_Text_JugglerHortonDefeat
	msgbox Unused_VictoryRoad_2F_Text_JugglerHorton, MSGBOX_AUTOCLOSE
	end

Unused_VictoryRoad_2F_EventScript_MediumSarina::
	trainerbattle_single TRAINER_MEDIUM_SARINA, Unused_VictoryRoad_2F_Text_MediumSarinaIntro, Unused_VictoryRoad_2F_Text_MediumSarinaDefeat
	msgbox Unused_VictoryRoad_2F_Text_MediumSarina, MSGBOX_AUTOCLOSE
	end

Unused_VictoryRoad_2F_EventScript_JugglerGregory::
	trainerbattle_single TRAINER_JUGGLER_GREGORY, Unused_VictoryRoad_2F_Text_JugglerGregoryIntro, Unused_VictoryRoad_2F_Text_JugglerGregoryDefeat
	msgbox Unused_VictoryRoad_2F_Text_JugglerGregory, MSGBOX_AUTOCLOSE
	end

Unused_VictoryRoad_2F_EventScript_Trigger1::
	lockall
	goto_if_eq 0x4065, 100, Unused_VictoryRoad_2F_EventScript_Trigger1_1
	setmetatile 13, 10, 0x2D1, 0
	setmetatile 13, 11, 0x2E1, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm 11
	setvar 0x4065, 100
	releaseall
	end

Unused_VictoryRoad_2F_EventScript_Trigger1_1::
	releaseall
	end

Unused_VictoryRoad_2F_EventScript_Trigger2::
	lockall
	goto_if_eq 0x4066, 100, Unused_VictoryRoad_2F_EventScript_Trigger2_1
	setmetatile 33, 16, 0x2D1, 0
	setmetatile 33, 17, 0x2E1, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm 12
	setvar 0x4066, 100
	releaseall
	end

Unused_VictoryRoad_2F_EventScript_Trigger2_1::
	releaseall
	end
