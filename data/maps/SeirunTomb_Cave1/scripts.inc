SeirunTomb_Cave1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeirunTomb_Cave1_OnTransition
	.byte 0

SeirunTomb_Cave1_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_ALTERING_CAVE
	end

SeirunTomb_Cave1_EventScript_Articuno::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setwildbattle SPECIES_KYOGRE, 50
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	setflag 0x1414
	release
	end
