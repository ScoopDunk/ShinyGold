VioletCity_Interior3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_Interior3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VioletCity_Interior3_OnTransition::
	setrespawn HEAL_LOCATION_VIOLET_CITY
	end

VioletCity_Interior3_EventScript_Man::
	msgbox VioletCity_Interior3_Text_Man, MSGBOX_NPC
	end

VioletCity_Interior3_EventScript_Scientist::
	goto_if_set 0x1045, VioletCity_Interior3_EventScript_Scientist_1
	msgbox VioletCity_Interior3_Text_Scientist_1, MSGBOX_NPC
	setflag 0x1045
	goto VioletCity_Interior3_EventScript_Scientist_1

VioletCity_Interior3_EventScript_Scientist_1::
	faceplayer
	msgbox VioletCity_Interior3_Text_Scientist_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, VioletCity_Interior3_EventScript_Scientist_2
	msgbox VioletCity_Interior3_Text_Scientist_3, MSGBOX_NPC
	end

VioletCity_Interior3_EventScript_Scientist_2::
	getpartysize
	goto_if_lt VAR_RESULT, 6, VioletCity_Interior3_EventScript_Scientist_3
	msgbox VioletCity_Interior3_Text_Scientist_4, MSGBOX_NPC
	end

VioletCity_Interior3_EventScript_Scientist_3::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_SLOTS_WIN
	msgbox VioletCity_Interior3_Text_Scientist_5, MSGBOX_NPC
	waitfanfare
	giveegg SPECIES_TOGEPI
	textcolor NPC_TEXT_COLOR_MALE
	msgbox VioletCity_Interior3_Text_Scientist_6, MSGBOX_NPC
	applymovement 5, VioletCity_Interior3_Movement_Scientist
	delay 144
	setflag 0x1044
	setflag 0x1203
	release
	end

VioletCity_Interior3_Movement_Scientist::
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	set_invisible
	walk_down
	walk_down
	step_end
