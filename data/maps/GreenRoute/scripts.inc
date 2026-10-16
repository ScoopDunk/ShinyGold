GreenRoute_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

GreenRoute_EventScript_BirdKeeperHiro::
	trainerbattle_single TRAINER_BIRD_KEEPER_HIRO, GreenRoute_Text_BirdKeeperHiroIntro, FiveIsland_MemorialPillar_Text_HaroldDefeat
	msgbox FiveIsland_MemorialPillar_Text_HaroldPostBattle, MSGBOX_AUTOCLOSE
	end

GreenRoute_EventScript_ItemStarPiece::
	finditem ITEM_STAR_PIECE
	end
