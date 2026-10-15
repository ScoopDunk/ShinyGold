EcruteakCity_Cave1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

EcruteakCity_Cave1_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

EcruteakCity_Cave1_EventScript_ItemBurnHeal::
	finditem ITEM_BURN_HEAL
	end

EcruteakCity_Cave1_EventScript_ItemHpUp::
	finditem ITEM_HP_UP
	end

EcruteakCity_Cave1_EventScript_ItemTm50::
	finditem ITEM_TM50
	end

EcruteakCity_Cave1_EventScript_ItemNugget::
	finditem ITEM_NUGGET
	end

EcruteakCity_Cave1_EventScript_Man::
	call_if_set 0x11B4, EcruteakCity_Cave1_EventScript_Man_1
	call_if_set 0x11B7, EcruteakCity_Cave1_EventScript_Man_2
	setflag 0x11B7
	msgbox EcruteakCity_Cave1_Text_Man_1, MSGBOX_NPC
	lock
	faceplayer
	msgbox EcruteakCity_Cave1_Text_Man_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, EcruteakCity_Cave1_EventScript_Man_3
	msgbox EcruteakCity_Cave1_Text_Man_3, MSGBOX_NPC
	end

EcruteakCity_Cave1_EventScript_Man_1::
	msgbox EcruteakCity_Cave1_Text_Man_4, MSGBOX_NPC
	end

EcruteakCity_Cave1_EventScript_Man_2::
	msgbox EcruteakCity_Cave1_Text_Man_5, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, EcruteakCity_Cave1_EventScript_Man_3
	msgbox EcruteakCity_Cave1_Text_Man_3, MSGBOX_NPC

EcruteakCity_Cave1_EventScript_Man_3::
	msgbox EcruteakCity_Cave1_Text_Man_6, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_LEADER_MORTY, 0, EcruteakCity_Cave1_Text_ManDefeat, EcruteakCity_Cave1_Text_ManVictory
	setflag 0x11B4
	msgbox EcruteakCity_Cave1_Text_Man_7, MSGBOX_NPC
	playfanfare MUS_SLOTS_JACKPOT
	lock
	faceplayer
	msgbox EcruteakCity_Cave1_Text_Man_8, MSGBOX_AUTOCLOSE
	waitfanfare
	removeitem ITEM_POKEBLOCK_CASE
	giveitem ITEM_SILPH_SCOPE
	msgbox EcruteakCity_Cave1_Text_Man_9, MSGBOX_NPC
	end

EcruteakCity_Cave1_EventScript_Trigger::
	call_if_set 0x10AC, EcruteakCity_Cave1_EventScript_Trigger_1
	setflag 0x10AC
	playbgm MUS_NONE, 51
	applymovement 7, EcruteakCity_Cave1_Movement_Trigger_1
	delay 32
	waitse
	playmoncry SPECIES_RAIKOU, 0x3028
	nop
	delay 48
	applymovement 8, EcruteakCity_Cave1_Movement_Trigger_1
	delay 32
	waitse
	playmoncry SPECIES_ENTEI, 0x3028
	nop
	delay 48
	applymovement 9, EcruteakCity_Cave1_Movement_Trigger_1
	delay 32
	waitse
	playmoncry SPECIES_SUICUNE, 0x3028
	nop
	delay 48
	applymovement 7, EcruteakCity_Cave1_Movement_Trigger_2
	delay 128
	applymovement 8, EcruteakCity_Cave1_Movement_Trigger_3
	delay 144
	applymovement 9, EcruteakCity_Cave1_Movement_Trigger_4
	delay 96
	playbgm MUS_MT_MOON, 51
	release
	end

EcruteakCity_Cave1_EventScript_Trigger_1::
	release
	end

EcruteakCity_Cave1_Movement_Trigger_1::
	jump_in_place_down
	step_end

EcruteakCity_Cave1_Movement_Trigger_2::
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	set_invisible
	walk_fast_up
	walk_fast_up
	step_end

EcruteakCity_Cave1_Movement_Trigger_3::
	jump_2_down
	jump_2_down
	jump_2_down
	jump_2_down
	set_invisible
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

EcruteakCity_Cave1_Movement_Trigger_4::
	jump_2_left
	jump_2_left
	jump_2_left
	set_invisible
	walk_fast_up
	walk_fast_up
	step_end
