Route4_MapScripts::
	.byte 0

Route4_EventScript_PicnickerHope::
	trainerbattle_single TRAINER_PICNICKER_HOPE, Route4_Text_PicnickerHopeIntro, Route4_Text_PicnickerHopeDefeat
	msgbox Route4_Text_PicnickerHope, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_ItemHpUp::
	finditem ITEM_HP_UP
	end

Route4_EventScript_BirdKeeperHank::
	trainerbattle_single TRAINER_BIRD_KEEPER_HANK, Route4_Text_BirdKeeperHankIntro, Route4_Text_BirdKeeperHankDefeat
	msgbox Route4_Text_BirdKeeperHank, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sign::
	msgbox Route4_Text_Sign, MSGBOX_SIGN
	end
