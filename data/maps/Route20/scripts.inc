Route20_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Route20_EventScript_SwimmerFNicole2::
	trainerbattle_single TRAINER_SWIMMER_F_NICOLE_2, Route20_Text_SwimmerFNicole2Intro, Route20_Text_SwimmerFNicole2Defeat
	msgbox Route20_Text_SwimmerFNicole2, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_SwimmerFLori::
	trainerbattle_single TRAINER_SWIMMER_F_LORI, Route20_Text_SwimmerFLoriIntro, Route20_Text_SwimmerFLoriDefeat
	msgbox Route20_Text_SwimmerFLori, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_SwimmerMCameron::
	trainerbattle_single TRAINER_SWIMMER_M_CAMERON, Route20_Text_SwimmerMCameronIntro, Route20_Text_SwimmerMCameronDefeat
	msgbox Route20_Text_SwimmerMCameron, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_Sign1::
	msgbox Route20_Text_Sign1, MSGBOX_SIGN
	end
