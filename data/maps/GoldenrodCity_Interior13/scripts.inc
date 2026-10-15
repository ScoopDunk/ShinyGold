GoldenrodCity_Interior13_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

GoldenrodCity_Interior13_EventScript_CooltrainerF::
	msgbox GoldenrodCity_Interior13_Text_CooltrainerF, MSGBOX_NPC
	end

GoldenrodCity_Interior13_EventScript_CooltrainerM::
	msgbox GoldenrodCity_Interior13_Text_CooltrainerM, MSGBOX_NPC
	end

GoldenrodCity_Interior13_EventScript_Trigger1::
	setvar VAR_RESULT, 6
	release
	end

GoldenrodCity_Interior13_EventScript_Sign1::
	msgbox GoldenrodCity_Interior13_Text_Sign1, MSGBOX_AUTOCLOSE
	end
