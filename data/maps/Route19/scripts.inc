Route19_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route19_OnLoad
	.byte 0

Route19_OnLoad::
	goto_if_set 0x056, Route19_EventScript_OnLoad_1
	end

Route19_EventScript_OnLoad_1::
	setmetatile 8, 5, 217, 0
	setmetatile 9, 5, 217, 0
	setmetatile 10, 5, 217, 0
	setmetatile 11, 5, 217, 0
	setmetatile 12, 5, 217, 0
	setmetatile 13, 5, 217, 0
	setmetatile 8, 6, 143, 1
	setmetatile 9, 6, 143, 1
	setmetatile 10, 6, 143, 1
	setmetatile 11, 6, 143, 1
	setmetatile 12, 6, 143, 1
	setmetatile 13, 6, 143, 1
	setmetatile 6, 7, 217, 0
	setmetatile 7, 7, 217, 0
	setmetatile 6, 8, 143, 1
	setmetatile 7, 8, 143, 1
	setmetatile 12, 9, 217, 0
	setmetatile 13, 9, 217, 0
	setmetatile 12, 10, 143, 1
	setmetatile 13, 10, 143, 1
	setmetatile 14, 7, 183, 1
	setmetatile 14, 8, 183, 1
	setmetatile 15, 7, 217, 0
	setmetatile 15, 8, 217, 0
	end

Route19_EventScript_Fisher::
	lock
	faceplayer
	goto_if_set 0x056, Route19_EventScript_Fisher_1
	msgbox Route19_Text_Fisher_1, MSGBOX_NPC
	release
	end

Route19_EventScript_Fisher_1::
	msgbox Route19_Text_Fisher_2, MSGBOX_NPC
	release
	end

Route19_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set 0x056, Route19_EventScript_FatMan_1
	msgbox Route19_Text_FatMan_1, MSGBOX_NPC
	release
	end

Route19_EventScript_FatMan_1::
	msgbox Route19_Text_FatMan_2, MSGBOX_NPC
	release
	end

Route19_EventScript_SwimmerMJerome::
	trainerbattle_single TRAINER_SWIMMER_M_JEROME, Route19_Text_SwimmerMJeromeIntro, Route19_Text_SwimmerMJeromeDefeat
	msgbox Route19_Text_SwimmerMJerome, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_SwimmerMHarold::
	trainerbattle_single TRAINER_SWIMMER_M_HAROLD, Route19_Text_SwimmerMHaroldIntro, Route19_Text_SwimmerMHaroldDefeat
	msgbox Route19_Text_SwimmerMHarold, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_SwimmerMTucker::
	trainerbattle_single TRAINER_SWIMMER_M_TUCKER, Route19_Text_SwimmerMTuckerIntro, Route19_Text_SwimmerMTuckerDefeat
	msgbox Route19_Text_SwimmerMTucker, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_SwimmerFDawn::
	trainerbattle_single TRAINER_SWIMMER_F_DAWN, Route19_Text_SwimmerFDawnIntro, Route19_Text_SwimmerFDawnDefeat
	msgbox Route19_Text_SwimmerFDawn, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Sign1::
	msgbox Route19_Text_Sign1, MSGBOX_SIGN
	end

Route19_EventScript_Sign2::
	msgbox Route19_Text_Sign2, MSGBOX_SIGN
	end
