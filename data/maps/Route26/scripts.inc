Route26_MapScripts::
	@ ShinyGold fix: FireRed's Birth Island (Deoxys) map scripts removed; they uncovered part of the region map
	.byte 0

Route26_EventScript_FishermanScott::
	trainerbattle_single TRAINER_FISHERMAN_SCOTT, Route26_Text_FishermanScottIntro, Route26_Text_FishermanScottDefeat
	msgbox Route26_Text_FishermanScott, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_PsychicRichard::
	trainerbattle_single TRAINER_PSYCHIC_RICHARD, Route26_Text_PsychicRichardIntro, Route26_Text_PsychicRichardDefeat
	msgbox Route26_Text_PsychicRichard, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_CooltrainerJoyce::
	trainerbattle_single TRAINER_COOLTRAINER_JOYCE, Route26_Text_CooltrainerJoyceIntro, Route26_Text_CooltrainerJoyceDefeat
	msgbox Route26_Text_CooltrainerJoyce, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Cooltrainer302::
	trainerbattle_single TRAINER_COOLTRAINER_GAVEN_3, Route26_Text_Cooltrainer302Intro, Route26_Text_Cooltrainer302Defeat
	call_if_set 0x1327, Route26_EventScript_Cooltrainer302_1
	setvar 0x700C, 39
	setvar 0x700D, 0
	call_if_set 0x1357, Route35_EventScript_Juggler228_2
	msgbox Route26_Text_Cooltrainer302, MSGBOX_NPC
	setflag 0x1357
	call Route35_EventScript_Juggler228_3
	end

Route26_EventScript_Cooltrainer302_1::
	clearflag 0x1327
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, Route26_EventScript_Cooltrainer302_2
	call_if_set 0x1177, Route26_EventScript_Cooltrainer302_3
	call_if_set 0x115F, Route26_EventScript_Cooltrainer302_4
	call_if_set FLAG_BADGE07_GET, Route26_EventScript_Cooltrainer302_5
	trainerbattle_earlyrival TRAINER_COOLTRAINER_GAVEN_3, 0, Route26_Text_Cooltrainer302Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_Cooltrainer302_2::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_GAVEN_2, 0, Route26_Text_Cooltrainer302Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_Cooltrainer302_3::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_GAVEN, 0, Route26_Text_Cooltrainer302Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_Cooltrainer302_4::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_GAVEN_5, 0, Route26_Text_Cooltrainer302Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_Cooltrainer302_5::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_GAVEN_4, 0, Route26_Text_Cooltrainer302Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_CooltrainerJake::
	trainerbattle_single TRAINER_COOLTRAINER_JAKE, Route26_Text_CooltrainerJakeIntro, Route26_Text_CooltrainerJakeDefeat
	msgbox Route26_Text_CooltrainerJake, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

Route26_EventScript_Cooltrainer518::
	trainerbattle_single TRAINER_COOLTRAINER_BETH, Route26_Text_Cooltrainer518Intro, Route26_Text_Cooltrainer518Defeat
	call_if_set 0x1325, Route26_EventScript_Cooltrainer518_1
	setvar 0x700C, 37
	setvar 0x700D, 0
	call_if_set 0x1355, Route35_EventScript_Juggler228_2
	msgbox Route26_Text_Cooltrainer518, MSGBOX_NPC
	setflag 0x1355
	call Route35_EventScript_Juggler228_3
	end

Route26_EventScript_Cooltrainer518_1::
	clearflag 0x1325
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x1177, Route26_EventScript_Cooltrainer518_2
	call_if_set 0x115F, Route26_EventScript_Cooltrainer518_3
	trainerbattle_earlyrival TRAINER_COOLTRAINER_BETH, 0, Route26_Text_Cooltrainer518Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_Cooltrainer518_2::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_BETH_3, 0, Route26_Text_Cooltrainer518Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_Cooltrainer518_3::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_BETH_2, 0, Route26_Text_Cooltrainer518Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_Sign1::
	msgbox Route26_Text_Sign1, MSGBOX_AUTOCLOSE
	end
