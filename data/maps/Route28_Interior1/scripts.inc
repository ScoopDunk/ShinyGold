Route28_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route28_Interior1_OnTransition
	.byte 0

Route28_Interior1_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POKEMON_TOWER_1F
	end

Route28_Interior1_EventScript_Pidgey::
	waitse
	playmoncry SPECIES_FEAROW, CRY_MODE_ENCOUNTER
	msgbox Route28_Interior1_Text_Pidgey, MSGBOX_NPC
	waitmoncry
	release
	end

Route28_Interior1_EventScript_Lass::
	lock
	faceplayer
	goto_if_set 0x051, Route28_Interior1_EventScript_Lass_1
	msgbox Route28_Interior1_Text_Lass_1, MSGBOX_AUTOCLOSE
	giveitem ITEM_TM47
	setflag 0x051
	release
	end

Route28_Interior1_EventScript_Lass_1::
	msgbox Route28_Interior1_Text_Lass_2, MSGBOX_NPC
	release
	end
