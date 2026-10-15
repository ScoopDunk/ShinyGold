Route18_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_Interior1_OnTransition
	.byte 0

Route18_Interior1_OnTransition::
	clearflag FLAG_SYS_ON_CYCLING_ROAD
	call_if_set FLAG_GOT_BICYCLE, Route18_Interior1_EventScript_OnTransition_1
	end

Route18_Interior1_EventScript_OnTransition_1::
	setvar VAR_TEMP_1, 1
	return

Route18_Interior1_EventScript_Policeman::
	msgbox Route18_Interior1_Text_Policeman, MSGBOX_NPC
	end
