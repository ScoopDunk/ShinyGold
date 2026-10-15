SilphCo_Interior3_MapScripts::
	@ ShinyGold: 1 entry with invalid type(s) 0x6C dropped (inert: the engine skips them)
	.byte 0

SilphCo_Interior3_EventScript_Woman2::
	msgbox SilphCo_Interior3_Text_Woman2, MSGBOX_NPC
	end

SilphCo_Interior3_EventScript_Scientist::
	msgbox SilphCo_Interior3_Text_Scientist, MSGBOX_NPC
	end

SilphCo_Interior3_EventScript_Scientist2::
	call_if_set 0x1193, SilphCo_Interior3_EventScript_Scientist2_1
	setflag 0x1193
	msgbox SilphCo_Interior3_Text_Scientist2_1, MSGBOX_NPC
	giveitem ITEM_TIMER_BALL
	msgbox SilphCo_Interior3_Text_Scientist2_2, MSGBOX_NPC
	end

SilphCo_Interior3_EventScript_Scientist2_1::
	msgbox SilphCo_Interior3_Text_Scientist2_2, MSGBOX_NPC
	end

SilphCo_Interior3_EventScript_Scientist3::
	msgbox SilphCo_Interior3_Text_Scientist3, MSGBOX_NPC
	end

SilphCo_Interior3_EventScript_Scientist4::
	msgbox SilphCo_Interior3_Text_Scientist4, MSGBOX_NPC
	end
