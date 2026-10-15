Route1_MapScripts::
	.byte 0

Route1_EventScript_CooltrainerQuinn::
	trainerbattle_single TRAINER_COOLTRAINER_QUINN, Route1_Text_CooltrainerQuinnIntro, Route1_Text_CooltrainerQuinnDefeat
	msgbox Route1_Text_CooltrainerQuinn, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_SchoolboyDanny::
	trainerbattle_single TRAINER_SCHOOLBOY_DANNY, Route1_Text_SchoolboyDannyIntro, Route1_Text_SchoolboyDannyDefeat
	msgbox Route1_Text_SchoolboyDanny, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Sign::
	msgbox Route1_Text_Sign, MSGBOX_SIGN
	end
