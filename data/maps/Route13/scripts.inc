Route13_MapScripts::
	.byte 0

Route13_EventScript_ItemCalcium::
	finditem ITEM_CALCIUM
	end

Route13_EventScript_HikerKenny::
	trainerbattle_single TRAINER_HIKER_KENNY, Route13_Text_HikerKennyIntro, Route13_Text_HikerKennyDefeat
	msgbox Route13_Text_HikerKenny, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_BirdKeeperPerry::
	trainerbattle_single TRAINER_BIRD_KEEPER_PERRY, Route13_Text_BirdKeeperPerryIntro, Route13_Text_BirdKeeperPerryDefeat
	msgbox Route13_Text_BirdKeeperPerry, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_BirdKeeperBret::
	trainerbattle_single TRAINER_BIRD_KEEPER_BRET, Route13_Text_BirdKeeperBretIntro, Route13_Text_BirdKeeperBretDefeat
	msgbox Route13_Text_BirdKeeperBret, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_PokefanJoshua::
	trainerbattle_single TRAINER_POKEFAN_JOSHUA, Route13_Text_PokefanJoshuaIntro, Route13_Text_PokefanJoshuaDefeat
	msgbox Route13_Text_PokefanJoshua, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_PokefanAlex::
	trainerbattle_single TRAINER_POKEFAN_ALEX, Route13_Text_PokefanAlexIntro, Route13_Text_PokefanAlexDefeat
	msgbox Route13_Text_PokefanAlex, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Sign1::
	msgbox Route13_Text_Sign1, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Sign2::
	msgbox Route13_Text_Sign2, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Sign3::
	msgbox Route13_Text_Sign3, MSGBOX_AUTOCLOSE
	end
