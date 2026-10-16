Route2_MapScripts::
	.byte 0

KalmCityNousar_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

@ ShinyGold: moved from data/maps/KalmCityNousar/scripts.inc (map removed)
KalmCityNousar_EventScript_ItemCarbos::
	finditem ITEM_CARBOS
	end

@ ShinyGold: moved from data/maps/KalmCityNousar/scripts.inc (map removed)
KalmCityNousar_EventScript_ItemElixir::
	finditem ITEM_ELIXIR
	end

@ ShinyGold: moved from data/maps/KalmCityNousar/scripts.inc (map removed)
KalmCityNousar_EventScript_ItemDireHit::
	finditem ITEM_DIRE_HIT
	end

@ ShinyGold: moved from data/maps/KalmCityNousar/scripts.inc (map removed)
KalmCityNousar_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

@ ShinyGold: moved from data/maps/KalmCityNousar/scripts.inc (map removed)
KalmCityNousar_EventScript_ItemRevive::
	finditem ITEM_REVIVE
	end

@ ShinyGold: moved from data/maps/KalmCityNousar/scripts.inc (map removed)
KalmCityNousar_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER
	end

@ ShinyGold: moved from data/maps/KalmCityNousar/scripts.inc (map removed)
KalmCityNousar_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

@ ShinyGold: moved from data/maps/KalmCityNousar/scripts.inc (map removed)
KalmCityNousar_EventScript_BugCatcherEd::
	trainerbattle_single TRAINER_BUG_CATCHER_ED, KalmCityNousar_Text_BugCatcherEdIntro, KalmCityNousar_Text_BugCatcherEdDefeat
	msgbox KalmCityNousar_Text_BugCatcherEd, MSGBOX_AUTOCLOSE
	end

@ ShinyGold: moved from data/maps/KalmCityNousar/scripts.inc (map removed)
KalmCityNousar_EventScript_BugCatcherDoug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, KalmCityNousar_Text_BugCatcherDougIntro, KalmCityNousar_Text_BugCatcherDougDefeat
	msgbox KalmCityNousar_Text_BugCatcherDoug, MSGBOX_AUTOCLOSE
	end

@ ShinyGold: moved from data/maps/KalmCityNousar/scripts.inc (map removed)
KalmCityNousar_EventScript_BugCatcherRob::
	trainerbattle_single TRAINER_BUG_CATCHER_ROB, KalmCityNousar_Text_BugCatcherRobIntro, KalmCityNousar_Text_BugCatcherRobDefeat
	msgbox KalmCityNousar_Text_BugCatcherRob, MSGBOX_AUTOCLOSE
	end

@ ShinyGold: moved from data/maps/KalmCityNousar/scripts.inc (map removed)
KalmCityNousar_EventScript_Sign1::
	msgbox KalmCityNousar_Text_Sign1, MSGBOX_AUTOCLOSE
	end

@ ShinyGold: moved from data/maps/KalmCityNousar/scripts.inc (map removed)
KalmCityNousar_EventScript_Sign2::
	msgbox KalmCityNousar_Text_Sign2, MSGBOX_AUTOCLOSE
	end
