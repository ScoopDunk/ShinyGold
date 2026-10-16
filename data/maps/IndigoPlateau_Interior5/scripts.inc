IndigoPlateau_Interior5_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_Interior5_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

IndigoPlateau_Interior5_OnTransition::
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	end

IndigoPlateau_Interior5_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart IndigoPlateau_Interior5_Items_Clerk
	release
	end

	.align 1
IndigoPlateau_Interior5_Items_Clerk::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_NONE

IndigoPlateau_Interior5_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

IndigoPlateau_Interior5_EventScript_Pidgeot::
	msgbox IndigoPlateau_Interior5_Text_Pidgeot, MSGBOX_NPC
	waitse
	playmoncry SPECIES_PIDGEOT, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

IndigoPlateau_Interior5_EventScript_OldMan1::
	lock
	faceplayer
	call IndigoPlateau_Interior5_EventScript_OldMan1_1
	msgbox IndigoPlateau_Interior5_Text_OldMan1_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, IndigoPlateau_Interior5_EventScript_OldMan1_2
	msgbox IndigoPlateau_Interior5_Text_OldMan1_2, MSGBOX_NPC
	end

IndigoPlateau_Interior5_EventScript_OldMan1_1::
	setvar 0x7031, 0x138
	setvar 0x7034, 0x136
	release
	return

IndigoPlateau_Interior5_EventScript_OldMan1_2::
	@ ShinyGold: overlapping data duplicated from 0x08801BB0
	msgbox IndigoPlateau_Interior5_Text_OldMan1_3, MSGBOX_NPC
	warp MAP_NEW_BARK_TOWN, 4, 0xFF02, 0xFFFF
	end

IndigoPlateau_Interior5_EventScript_CooltrainerM::
	msgbox IndigoPlateau_Interior5_Text_CooltrainerM, MSGBOX_NPC
	end

IndigoPlateau_Interior5_EventScript_Trigger1::
	lock
	clearflag 0x115C
	setflag 0x115D
	goto_if_unset 0x084, IndigoPlateau_Interior5_EventScript_Trigger1_1
	goto_if_set FLAG_WONDER_CARD_UNUSED_5, IndigoPlateau_Interior5_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, IndigoPlateau_Interior5_Movement_Trigger1_1
	waitmovement 0
	addobject 5
	applymovement 5, IndigoPlateau_Interior5_Movement_Trigger1_2
	waitmovement 0
	playbgm MUS_ENCOUNTER_RIVAL, 51
	msgbox IndigoPlateau_Interior5_Text_Trigger1_1, MSGBOX_NPC
	call_if_eq VAR_STARTER_MON, 0, IndigoPlateau_Interior5_EventScript_Trigger1_2
	call_if_eq VAR_STARTER_MON, 1, IndigoPlateau_Interior5_EventScript_Trigger1_3
	call_if_eq VAR_STARTER_MON, 2, IndigoPlateau_Interior5_EventScript_Trigger1_4
	playbgm MUS_ENCOUNTER_RIVAL, 51
	applymovement 5, IndigoPlateau_Interior5_Movement_Trigger1_3
	waitmovement 0
	fadedefaultbgm
	removeobject 5
	setflag FLAG_WONDER_CARD_UNUSED_5
	release
	end

IndigoPlateau_Interior5_EventScript_Trigger1_1::
	release
	end

IndigoPlateau_Interior5_EventScript_Trigger1_2::
	trainerbattle_earlyrival TRAINER_RIVAL_SILVER_4, 0, IndigoPlateau_Interior5_Text_Trigger1Defeat, IndigoPlateau_Interior5_Text_Trigger1Victory
	msgbox IndigoPlateau_Interior5_Text_Trigger1_2, MSGBOX_NPC
	return

IndigoPlateau_Interior5_EventScript_Trigger1_3::
	trainerbattle_earlyrival TRAINER_RIVAL_SILVER_5, 0, IndigoPlateau_Interior5_Text_Trigger1Defeat, IndigoPlateau_Interior5_Text_Trigger1Victory
	msgbox IndigoPlateau_Interior5_Text_Trigger1_2, MSGBOX_NPC
	return

IndigoPlateau_Interior5_EventScript_Trigger1_4::
	trainerbattle_earlyrival TRAINER_RIVAL_SILVER_6, 0, IndigoPlateau_Interior5_Text_Trigger1Defeat, IndigoPlateau_Interior5_Text_Trigger1Victory
	msgbox IndigoPlateau_Interior5_Text_Trigger1_2, MSGBOX_NPC
	return

IndigoPlateau_Interior5_Movement_Trigger1_1::
	emote_exclamation_mark
	face_down_fast
	step_end

IndigoPlateau_Interior5_Movement_Trigger1_2::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

IndigoPlateau_Interior5_Movement_Trigger1_3::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

IndigoPlateau_Interior5_EventScript_Trigger2::
	call_if_set 0x1360, MtSilver_Interior1_EventScript_Trigger1
	clearflag FLAG_WORLD_MAP_PALLET_TOWN
	call IndigoPlateau_Interior5_EventScript_OldMan1_1
	call MtSilver_Interior1_EventScript_Trigger1
	end
