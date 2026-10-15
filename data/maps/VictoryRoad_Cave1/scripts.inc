VictoryRoad_Cave1_MapScripts::
	@ ShinyGold: 1 entry with invalid type(s) 0x6C dropped (inert: the engine skips them)
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_Cave1_OnTransition
	.byte 0

VictoryRoad_Cave1_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POKEMON_MANSION_1F
	end

VictoryRoad_Cave1_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

VictoryRoad_Cave1_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

VictoryRoad_Cave1_EventScript_Trigger1::
	setflag 0x1159
	release
	end

VictoryRoad_Cave1_EventScript_Trigger3::
	call_if_set 0x115A, VictoryRoad_Cave1_EventScript_Trigger3_1
	clearflag 0x1159
	applymovement LOCALID_PLAYER, VictoryRoad_Cave1_Movement_Trigger3_1
	delay 64
	playbgm MUS_NONE, 51
	applymovement 3, VictoryRoad_Cave1_Movement_Trigger3_2
	delay 112
	playbgm MUS_ENCOUNTER_RIVAL, 51
	msgbox VictoryRoad_Cave1_Text_Trigger3_1, MSGBOX_NPC
	call_if_eq VAR_STARTER_MON, 0, VictoryRoad_Cave1_EventScript_Trigger3_2
	call_if_eq VAR_STARTER_MON, 1, VictoryRoad_Cave1_EventScript_Trigger3_3
	call_if_eq VAR_STARTER_MON, 2, VictoryRoad_Cave1_EventScript_Trigger3_4
	end

VictoryRoad_Cave1_EventScript_Trigger3_1::
	release
	end

VictoryRoad_Cave1_EventScript_Trigger3_2::
	trainerbattle_earlyrival TRAINER_RIVAL_TERRY_10, 0, VictoryRoad_Cave1_Text_Trigger3Defeat, VictoryRoad_Cave1_Text_Trigger3Victory
	call VictoryRoad_Cave1_EventScript_Trigger3_5
	end

VictoryRoad_Cave1_EventScript_Trigger3_3::
	trainerbattle_earlyrival TRAINER_RIVAL_TERRY_11, 0, VictoryRoad_Cave1_Text_Trigger3Defeat, VictoryRoad_Cave1_Text_Trigger3Victory
	call VictoryRoad_Cave1_EventScript_Trigger3_5
	end

VictoryRoad_Cave1_EventScript_Trigger3_4::
	trainerbattle_earlyrival TRAINER_RIVAL_TERRY_12, 0, VictoryRoad_Cave1_Text_Trigger3Defeat, VictoryRoad_Cave1_Text_Trigger3Victory
	call VictoryRoad_Cave1_EventScript_Trigger3_5
	end

VictoryRoad_Cave1_Movement_Trigger3_1::
	walk_down
	emote_exclamation_mark
	step_end

VictoryRoad_Cave1_Movement_Trigger3_2::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

VictoryRoad_Cave1_EventScript_Trigger3_5::
	playbgm MUS_NONE, 51
	msgbox VictoryRoad_Cave1_Text_Trigger3_2, MSGBOX_NPC
	playbgm MUS_ENCOUNTER_RIVAL, 51
	applymovement 3, VictoryRoad_Cave1_Movement_Trigger3_3
	delay 128
	playbgm MUS_SEVII_DUNGEON, 51
	setflag 0x1159
	setflag 0x115A
	release
	end

VictoryRoad_Cave1_Movement_Trigger3_3::
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end
