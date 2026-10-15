SilphCo_Interior5_MapScripts::
	@ ShinyGold: 1 entry with invalid type(s) 0x6C dropped (inert: the engine skips them)
	.byte 0

SilphCo_Interior5_EventScript_Man::
	msgbox SilphCo_Interior5_Text_Man, MSGBOX_NPC
	end

SilphCo_Interior5_EventScript_Scientist::
	msgbox SilphCo_Interior5_Text_Scientist, MSGBOX_NPC
	end

SilphCo_Interior5_EventScript_Gentleman::
	msgbox SilphCo_Interior5_Text_Gentleman, MSGBOX_NPC
	end

SilphCo_Interior5_EventScript_Scientist2::
	msgbox SilphCo_Interior5_Text_Scientist2, MSGBOX_NPC
	end

SilphCo_Interior5_EventScript_Scientist3::
	msgbox SilphCo_Interior5_Text_Scientist3, MSGBOX_NPC
	end

SilphCo_Interior5_EventScript_Scientist4::
	msgbox SilphCo_Interior5_Text_Scientist4, MSGBOX_NPC
	end

SilphCo_Interior5_EventScript_Policeman::
	msgbox SilphCo_Interior5_Text_Policeman, MSGBOX_NPC
	end

SilphCo_Interior5_EventScript_Trigger1::
	setvar VAR_RESULT, 0
	release
	end

SilphCo_Interior5_EventScript_Trigger2::
	setvar VAR_RESULT, 1
	release
	end
