VermilionCity_Interior16_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Interior16_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Interior16_OnTransition
	.byte 0

VermilionCity_Interior16_OnLoad::
	call_if_set FLAG_TEMP_1, VermilionCity_Interior16_EventScript_OnLoad_1
	call_if_set 0x264, VermilionCity_Interior16_EventScript_OnLoad_2
	end

VermilionCity_Interior16_OnTransition::
	call VermilionCity_Interior16_EventScript_OnTransition_1
	end

VermilionCity_Interior16_EventScript_OnLoad_1::
	setmetatile 3, 6, 0x2BB, 1
	setmetatile 4, 6, 0x2BC, 1
	setmetatile 5, 6, 0x2BD, 1
	setmetatile 6, 6, 0x2BE, 1
	setmetatile 7, 6, 0x2BF, 1
	setmetatile 3, 7, 0x2C3, 1
	setmetatile 4, 7, 0x2C4, 1
	setmetatile 5, 7, 0x2C5, 1
	setmetatile 6, 7, 0x2C6, 1
	setmetatile 7, 7, 0x2C7, 1
	return

VermilionCity_Interior16_EventScript_OnLoad_2::
	setmetatile 3, 6, 0x293, 1
	setmetatile 4, 6, 0x294, 0
	setmetatile 5, 6, 0x281, 0
	setmetatile 6, 6, 0x295, 0
	setmetatile 7, 6, 0x296, 1
	setmetatile 3, 7, 0x29B, 1
	setmetatile 4, 7, 0x29C, 0
	setmetatile 5, 7, 0x281, 0
	setmetatile 6, 7, 0x29D, 0
	setmetatile 7, 7, 0x29E, 1
	return

VermilionCity_Interior16_EventScript_OnTransition_1::
	goto_if_set 0x264, EventScript_Return
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, VAR_0x8004
	copyvar VAR_TEMP_1, VAR_0x8005
	return

VermilionCity_Interior16_EventScript_LeaderLtSurge::
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	special UpdatePickStateFromSpecialVar8005
	call CeruleanCity_Gym_EventScript_LeaderMisty_1
	trainerbattle_single TRAINER_LEADER_LT_SURGE, VermilionCity_Interior16_Text_LeaderLtSurgeIntro, VermilionCity_Interior16_Text_LeaderLtSurgeDefeat, VermilionCity_Interior16_EventScript_LeaderLtSurgeContinue, NO_MUSIC
	msgbox VermilionCity_Interior16_Text_LeaderLtSurge_1, MSGBOX_NPC
	end

VermilionCity_Interior16_EventScript_LeaderLtSurgeContinue::
	setflag 0x117E
	call LavenderTown_EventScript_Trigger6_3
	msgbox VermilionCity_Interior16_Text_LeaderLtSurge_2, MSGBOX_NPC
	delay 16
	msgbox VermilionCity_Interior16_Text_LeaderLtSurge_3, MSGBOX_NPC
	end

VermilionCity_Interior16_EventScript_JugglerHorton::
	trainerbattle_single TRAINER_JUGGLER_HORTON, VermilionCity_Interior16_Text_JugglerHortonIntro, VermilionCity_Interior16_Text_JugglerHortonDefeat
	msgbox VermilionCity_Interior16_Text_JugglerHorton, MSGBOX_AUTOCLOSE
	end

VermilionCity_Interior16_EventScript_GuitaristVincent::
	trainerbattle_single TRAINER_GUITARIST_VINCENT, VermilionCity_Interior16_Text_GuitaristVincentIntro, VermilionCity_Interior16_Text_GuitaristVincentDefeat
	msgbox VermilionCity_Interior16_Text_GuitaristVincent, MSGBOX_AUTOCLOSE
	end

VermilionCity_Interior16_EventScript_GymGuy::
	goto_if_set 0x117E, VermilionCity_Interior16_EventScript_GymGuy_1
	msgbox VermilionCity_Interior16_Text_GymGuy_1, MSGBOX_NPC
	end

VermilionCity_Interior16_EventScript_GymGuy_1::
	msgbox VermilionCity_Interior16_Text_GymGuy_2, MSGBOX_NPC
	end

VermilionCity_Interior16_EventScript_GentlemanGregory::
	trainerbattle_single TRAINER_GENTLEMAN_GREGORY, VermilionCity_Interior16_Text_GentlemanGregoryIntro, VermilionCity_Interior16_Text_GentlemanGregoryDefeat
	msgbox VermilionCity_Interior16_Text_GentlemanGregory, MSGBOX_AUTOCLOSE
	end

VermilionCity_Interior16_EventScript_Sign1::
	goto_if_set 0x117E, VermilionCity_Interior16_EventScript_Sign1_1
	msgbox VermilionCity_Interior16_Text_Sign1_1, MSGBOX_AUTOCLOSE
	end

VermilionCity_Interior16_EventScript_Sign1_1::
	msgbox VermilionCity_Interior16_Text_Sign1_2, MSGBOX_AUTOCLOSE
	end

VermilionCity_Interior16_EventScript_Sign3::
	msgbox VermilionCity_Interior16_Text_Sign3, MSGBOX_AUTOCLOSE
	end
