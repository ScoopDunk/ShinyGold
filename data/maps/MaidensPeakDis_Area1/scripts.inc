MaidensPeakDis_Area1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

MaidensPeakDis_Area1_EventScript_DeoxysN::
	lock
	waitse
	playmoncry SPECIES_DEOXYS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, 2
	setvar VAR_0x8004, 0x19A
	setvar VAR_0x8005, 40
	setvar VAR_0x8006, 0
	special CreateEnemyEventMon
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	fadescreen FADE_TO_BLACK
	removeobject 3
	fadescreen FADE_FROM_BLACK
	setflag 0x1410
	release
	end
