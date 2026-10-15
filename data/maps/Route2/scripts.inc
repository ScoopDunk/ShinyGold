Route2_MapScripts::
	.byte 0

Route2_EventScript_Trigger1::
	call_if_set 0x11EF, Route2_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Route2_Movement_Trigger1_1
	delay 32
	call Route2_EventScript_Trigger1_2
	end

Route2_EventScript_Trigger1_1::
	release
	end

Route2_EventScript_Trigger1_2::
	msgbox Route2_Text_Trigger1_1, MSGBOX_NPC
	applymovement 8, Route2_Movement_Trigger1_2
	delay 1
	playbgm MUS_ENCOUNTER_BOY, 51
	delay 32
	msgbox Route2_Text_Trigger1_2, MSGBOX_NPC
	delay 32
	msgbox Route2_Text_Trigger1_3, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_PKMN_THIEF_ASHLEE, 0, Route2_Text_Trigger1Defeat, Route2_Text_Trigger1Victory
	setflag 0x11EF
	playbgm MUS_ENCOUNTER_BOY, 51
	msgbox Route2_Text_Trigger1_4, MSGBOX_NPC
	applymovement 8, Route2_Movement_Trigger1_3
	delay 5
	applymovement 9, Route2_Movement_Trigger1_3
	delay 144
	playbgm MUS_ROUTE1, 51
	release
	end

Route2_Movement_Trigger1_1::
	walk_right
	walk_right
	step_end

Route2_Movement_Trigger1_2::
	face_left
	step_end

Route2_Movement_Trigger1_3::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	set_invisible
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route2_EventScript_Trigger2::
	call_if_set 0x11EF, Route2_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Route2_Movement_Trigger2
	delay 32
	call Route2_EventScript_Trigger1_2
	end

Route2_Movement_Trigger2::
	walk_up
	walk_right
	step_end

Route2_EventScript_Trigger3::
	call_if_set 0x11EF, Route2_EventScript_Trigger1_1
	call Route2_EventScript_Trigger1_2
	end

@ ShinyGold: moved from data/maps/KalmCityNousar/scripts.inc (map removed)
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
