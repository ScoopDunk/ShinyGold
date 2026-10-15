MaidensPeakDis_Interior8_MapScripts::
	.byte 0

MaidensPeakDis_Interior8_EventScript_Policeman::
	lock
	faceplayer
	setvar VAR_TEMP_1, 1
	bufferstdstring STR_VAR_1, STDSTRING_BOULDER_BADGE
	goto Route22_NorthEntrance_EventScript_BadgeGuard

MaidensPeakDis_Interior8_EventScript_Trigger::
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_0x8009, 1
	bufferstdstring STR_VAR_1, STDSTRING_BOULDER_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
