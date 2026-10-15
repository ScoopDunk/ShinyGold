SproutTower_Interior2_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_EventScript_ItemXDefend::
	finditem ITEM_X_DEFEND
	end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_EventScript_SageEdmond::
	trainerbattle_single TRAINER_SAGE_EDMOND, KalmCityNousar_Interior3_Text_SageEdmondIntro, KalmCityNousar_Interior3_Text_SageEdmondDefeat
	msgbox KalmCityNousar_Interior3_Text_SageEdmond, MSGBOX_AUTOCLOSE
	end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_EventScript_SageNico::
	trainerbattle_single TRAINER_SAGE_NICO, KalmCityNousar_Interior3_Text_SageNicoIntro, KalmCityNousar_Interior3_Text_SageNicoDefeat
	msgbox KalmCityNousar_Interior3_Text_SageNico, MSGBOX_AUTOCLOSE
	end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_EventScript_SageJin::
	trainerbattle_single TRAINER_SAGE_JIN, KalmCityNousar_Interior3_Text_SageJinIntro, KalmCityNousar_Interior3_Text_SageJinDefeat
	msgbox KalmCityNousar_Interior3_Text_SageJin, MSGBOX_AUTOCLOSE
	end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_EventScript_SageNeal::
	trainerbattle_single TRAINER_SAGE_NEAL, KalmCityNousar_Interior3_Text_SageNealIntro, KalmCityNousar_Interior3_Text_SageNealDefeat
	msgbox KalmCityNousar_Interior3_Text_SageNeal, MSGBOX_AUTOCLOSE
	end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_EventScript_SageTroy::
	trainerbattle_single TRAINER_SAGE_TROY, KalmCityNousar_Interior3_Text_SageTroyIntro, KalmCityNousar_Interior3_Text_SageTroyDefeat
	msgbox KalmCityNousar_Interior3_Text_SageTroy, MSGBOX_AUTOCLOSE
	end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_EventScript_SageLi::
	call_if_set 0x11D5, KalmCityNousar_Interior3_EventScript_SageLi_1
	msgbox KalmCityNousar_Interior3_Text_SageLi_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_SAGE_LI, 0, KalmCityNousar_Interior3_Text_SageLiDefeat, KalmCityNousar_Interior3_Text_SageLiVictory
	setflag 0x11D5
	msgbox KalmCityNousar_Interior3_Text_SageLi_2, MSGBOX_NPC
	giveitem ITEM_HM05
	msgbox KalmCityNousar_Interior3_Text_SageLi_3, MSGBOX_NPC
	end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_EventScript_SageLi_1::
	msgbox KalmCityNousar_Interior3_Text_SageLi_4, MSGBOX_NPC
	end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_EventScript_Trigger1::
	@ ShinyGold: overlapping data duplicated from 0x087435B7
	warp MAP_SPROUT_TOWER_INTERIOR1, 1, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

KalmCityNousar_Interior3_EventScript_Trigger2::
	@ ShinyGold: overlapping data duplicated from 0x087435C0
	warp MAP_SPROUT_TOWER_INTERIOR1, 1, 0xFF02, 0x39FF
	end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_EventScript_Trigger3::
	@ ShinyGold: overlapping data duplicated from 0x087435D7
	warp MAP_SPROUT_TOWER_INTERIOR1, 2, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

KalmCityNousar_Interior3_EventScript_Trigger4::
	warp MAP_SPROUT_TOWER_INTERIOR2, 4, 0xFF02, 0x39FF
	end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_EventScript_Trigger5::
	@ ShinyGold: overlapping data duplicated from 0x087435E7
	warp MAP_SPROUT_TOWER_INTERIOR2, 3
	.byte 0xFF @ invalid opcode (script stops)

KalmCityNousar_Interior3_EventScript_Trigger6::
	call_if_set 0x11D2, KalmCityNousar_Interior3_EventScript_Trigger6_1
	playbgm MUS_NONE, 51
	applymovement LOCALID_PLAYER, KalmCityNousar_Interior3_Movement_Trigger6_1
	delay 16
	applymovement LOCALID_PLAYER, KalmCityNousar_Interior3_Movement_Trigger6_2
	applymovement 10, KalmCityNousar_Interior3_Movement_Trigger6_3
	delay 80
	msgbox KalmCityNousar_Interior3_Text_Trigger6_1, MSGBOX_NPC
	playbgm MUS_ENCOUNTER_RIVAL, 51
	applymovement 10, KalmCityNousar_Interior3_Movement_Trigger6_4
	delay 48
	msgbox KalmCityNousar_Interior3_Text_Trigger6_2, MSGBOX_NPC
	applymovement 10, KalmCityNousar_Interior3_Movement_Trigger6_5
	delay 16
	msgbox KalmCityNousar_Interior3_Text_Trigger6_3, MSGBOX_NPC
	applymovement 10, KalmCityNousar_Interior3_Movement_Trigger6_6
	delay 80
	playbgm MUS_POKE_TOWER, 51
	setflag 0x11D2
	release
	end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_EventScript_Trigger6_1::
	release
	end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_Movement_Trigger6_1::
	emote_exclamation_mark
	step_end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_Movement_Trigger6_2::
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_Movement_Trigger6_3::
	walk_up
	step_end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_Movement_Trigger6_4::
	emote_exclamation_mark
	walk_down
	walk_right
	step_end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_Movement_Trigger6_5::
	face_up
	step_end

@ ShinyGold: moved from data/maps/KalmCityNousar_Interior3/scripts.inc (map removed)
KalmCityNousar_Interior3_Movement_Trigger6_6::
	set_invisible
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
