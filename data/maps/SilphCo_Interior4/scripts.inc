SilphCo_Interior4_MapScripts::
	@ ShinyGold: 1 entry with invalid type(s) 0x6C dropped (inert: the engine skips them)
	.byte 0

SilphCo_Interior4_EventScript_OfficerIzawa::
	trainerbattle_single TRAINER_OFFICER_IZAWA, SilphCo_Interior4_Text_OfficerIzawaIntro, SilphCo_Interior4_Text_OfficerIzawaDefeat
	msgbox SilphCo_Interior4_Text_OfficerIzawa, MSGBOX_AUTOCLOSE
	end

SilphCo_Interior4_EventScript_Trigger1::
	setvar VAR_RESULT, 1
	release
	end

SilphCo_Interior4_EventScript_Sign1::
	msgbox SilphCo_Interior4_Text_Sign1, MSGBOX_AUTOCLOSE
	end

SilphCo_Interior4_EventScript_Sign2::
	msgbox SilphCo_Interior4_Text_Sign2, MSGBOX_AUTOCLOSE
	end

SilphCo_Interior4_EventScript_Sign3::
	msgbox SilphCo_Interior4_Text_Sign3, MSGBOX_AUTOCLOSE
	end

SilphCo_Interior4_EventScript_Sign4::
	msgbox SilphCo_Interior4_Text_Sign4, MSGBOX_AUTOCLOSE
	end

SilphCo_Interior4_EventScript_Sign5::
	msgbox SilphCo_Interior4_Text_Sign5, MSGBOX_AUTOCLOSE
	end

SilphCo_Interior4_EventScript_Sign13::
	msgbox SilphCo_Interior4_Text_Sign13, MSGBOX_AUTOCLOSE
	end
