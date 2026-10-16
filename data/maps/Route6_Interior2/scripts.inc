Route6_Interior2_MapScripts::
	.byte 0

Route6_Interior2_EventScript_Policeman::
	goto_if_set 0x1185, Route6_Interior2_EventScript_Policeman_1
	msgbox Route6_Interior2_Text_Policeman_1, MSGBOX_NPC
	end

Route6_Interior2_EventScript_Policeman_1::
	msgbox Route6_Interior2_Text_Policeman_2, MSGBOX_NPC
	end
