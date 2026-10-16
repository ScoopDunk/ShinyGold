Route3_MapScripts::
	@ ShinyGold: overlapping data duplicated from 0x08167F77
	.byte 0

Route3_EventScript_FirebreatherBurt::
	trainerbattle_single TRAINER_FIREBREATHER_BURT, Route3_Text_FirebreatherBurtIntro, Route3_Text_FirebreatherBurtDefeat
	msgbox Route3_Text_FirebreatherBurt, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_FirebreatherOtis::
	trainerbattle_single TRAINER_FIREBREATHER_OTIS, Route3_Text_FirebreatherOtisIntro, Route3_Text_FirebreatherOtisDefeat
	msgbox Route3_Text_FirebreatherOtis, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_YoungsterWarren::
	trainerbattle_single TRAINER_YOUNGSTER_WARREN, Route3_Text_YoungsterWarrenIntro, Route3_Text_YoungsterWarrenDefeat
	msgbox Route3_Text_YoungsterWarren, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_YoungsterJimmy::
	trainerbattle_single TRAINER_YOUNGSTER_JIMMY, Route3_Text_YoungsterJimmyIntro, Route3_Text_YoungsterJimmyDefeat
	msgbox Route3_Text_YoungsterJimmy, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Sign::
	@ ShinyGold: overlapping data duplicated from 0x08167F81
	msgbox Route3_Text_Sign, MSGBOX_SIGN
	end
