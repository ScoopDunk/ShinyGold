Route10_MapScripts::
	.byte 0

Route10_EventScript_HikerJim::
	trainerbattle_single TRAINER_HIKER_JIM, Route10_Text_HikerJimIntro, Route10_Text_HikerJimDefeat
	msgbox Route10_Text_HikerJim, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_PokefanRobert::
	trainerbattle_single TRAINER_POKEFAN_ROBERT, Route10_Text_PokefanRobertIntro, Route10_Text_PokefanRobertDefeat
	msgbox Route10_Text_PokefanRobert, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Rocker::
	msgbox Route10_Text_Rocker, MSGBOX_NPC
	end

Route10_EventScript_Sign1::
	msgbox Route10_Text_Sign1, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Sign2::
	msgbox Route10_Text_Sign2, MSGBOX_NPC
	setvar 0x7030, 0x129
	setvar 0x7032, 0x12B
	release
	end
