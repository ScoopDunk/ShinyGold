SilphCo_Interior2_MapScripts::
	@ ShinyGold: 1 entry with invalid type(s) 0x6C dropped (inert: the engine skips them)
	.byte 0

SilphCo_Interior2_EventScript_Trigger::
	setvar VAR_RESULT, 0
	release
	end

SilphCo_Interior2_EventScript_Sign1::
	msgbox SilphCo_Interior2_Text_Sign1, MSGBOX_AUTOCLOSE
	end

SilphCo_Interior2_EventScript_Sign2::
	msgbox SilphCo_Interior2_Text_Sign2, MSGBOX_AUTOCLOSE
	end
