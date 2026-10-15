MahoganyTown_Interior1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

MahoganyTown_Interior1_EventScript_RedSurf::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart MahoganyTown_Interior1_Items_RedSurf
	release
	end

	.align 1
MahoganyTown_Interior1_Items_RedSurf::
	.2byte ITEM_FIGY_BERRY
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_REVIVE
	.2byte ITEM_TROPIC_MAIL
	.2byte ITEM_NONE

MahoganyTown_Interior1_EventScript_PokeManiac::
	call_if_set 0x10E6, MahoganyTown_Interior1_EventScript_PokeManiac_1
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart MahoganyTown_Interior1_Items_PokeManiac
	release
	end

MahoganyTown_Interior1_EventScript_PokeManiac_1::
	msgbox MahoganyTown_Interior1_Text_PokeManiac, MSGBOX_NPC
	end

	.align 1
MahoganyTown_Interior1_Items_PokeManiac::
	.2byte ITEM_TINY_MUSHROOM
	.2byte ITEM_RED_SHARD
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_NONE

MahoganyTown_Interior1_EventScript_Rocker::
	call_if_set 0x10E6, MahoganyTown_Interior1_EventScript_Rocker_1
	msgbox MahoganyTown_Interior1_Text_Rocker_1, MSGBOX_NPC
	end

MahoganyTown_Interior1_EventScript_Rocker_1::
	msgbox MahoganyTown_Interior1_Text_Rocker_2, MSGBOX_NPC
	end

MahoganyTown_Interior1_EventScript_OldAmber::
	release
	end

MahoganyTown_Interior1_EventScript_Trigger1::
	call_if_set 0x10E6, MahoganyTown_Interior1_EventScript_Trigger1_1
	call_if_unset 0x10E2, MahoganyTown_Interior1_EventScript_Trigger1_1
	msgbox MahoganyTown_Interior1_Text_Trigger1_1, MSGBOX_NPC
	waitse
	playmoncry SPECIES_DRAGONITE, 0x2800
	waitse
	nop
	applymovement 4, MahoganyTown_Interior1_Movement_Trigger1_1
	delay 48
	applymovement LOCALID_PLAYER, MahoganyTown_Interior1_Movement_Trigger1_2
	delay 48
	call MahoganyTown_Interior1_EventScript_Trigger1_2
	end

MahoganyTown_Interior1_EventScript_Trigger1_1::
	release
	end

MahoganyTown_Interior1_EventScript_Trigger1_2::
	setflag 0x10E5
	setflag 0x10E6
	clearflag 0x10BC
	setflag 0x10BE
	applymovement 3, MahoganyTown_Interior1_Movement_Trigger1_3
	msgbox MahoganyTown_Interior1_Text_Trigger1_2, MSGBOX_NPC
	applymovement 3, MahoganyTown_Interior1_Movement_Trigger1_4
	applymovement LOCALID_PLAYER, MahoganyTown_Interior1_Movement_Trigger1_4
	delay 64
	applymovement 2, MahoganyTown_Interior1_Movement_Trigger1_5
	delay 16
	applymovement 3, MahoganyTown_Interior1_Movement_Trigger1_6
	applymovement LOCALID_PLAYER, MahoganyTown_Interior1_Movement_Trigger1_7
	delay 64
	msgbox MahoganyTown_Interior1_Text_Trigger1_3, MSGBOX_NPC
	applymovement 5, MahoganyTown_Interior1_Movement_Trigger1_8
	applymovement 2, MahoganyTown_Interior1_Movement_Trigger1_9
	delay 32
	applymovement 3, MahoganyTown_Interior1_Movement_Trigger1_10
	msgbox MahoganyTown_Interior1_Text_Trigger1_4, MSGBOX_NPC
	applymovement 3, MahoganyTown_Interior1_Movement_Trigger1_11
	delay 48
	release
	end

MahoganyTown_Interior1_Movement_Trigger1_1::
	jump_special_left
	face_right
	step_end

MahoganyTown_Interior1_Movement_Trigger1_2::
	walk_right
	walk_right
	walk_up
	step_end

MahoganyTown_Interior1_Movement_Trigger1_3::
	face_down_fast
	step_end

MahoganyTown_Interior1_Movement_Trigger1_4::
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

MahoganyTown_Interior1_Movement_Trigger1_5::
	walk_fast_left
	face_right
	step_end

MahoganyTown_Interior1_Movement_Trigger1_6::
	walk_slow_up
	walk_slow_right
	walk_slow_right
	step_end

MahoganyTown_Interior1_Movement_Trigger1_7::
	walk_slow_up
	walk_slow_up
	walk_slow_right
	step_end

MahoganyTown_Interior1_Movement_Trigger1_8::
	walk_slower_up
	step_end

MahoganyTown_Interior1_Movement_Trigger1_9::
	emote_exclamation_mark
	step_end

MahoganyTown_Interior1_Movement_Trigger1_10::
	face_left
	step_end

MahoganyTown_Interior1_Movement_Trigger1_11::
	walk_slow_right
	set_invisible
	walk_fast_right
	walk_fast_right
	step_end

MahoganyTown_Interior1_EventScript_Trigger2::
	call_if_set 0x10E6, MahoganyTown_Interior1_EventScript_Trigger1_1
	call_if_unset 0x10E2, MahoganyTown_Interior1_EventScript_Trigger1_1
	msgbox MahoganyTown_Interior1_Text_Trigger1_1, MSGBOX_NPC
	waitse
	playmoncry SPECIES_DRAGONITE, 0x2800
	waitse
	nop
	applymovement 4, MahoganyTown_Interior1_Movement_Trigger1_1
	delay 48
	applymovement LOCALID_PLAYER, MahoganyTown_Interior1_Movement_Trigger2
	delay 32
	call MahoganyTown_Interior1_EventScript_Trigger1_2
	end

MahoganyTown_Interior1_Movement_Trigger2::
	walk_right
	face_up
	step_end

MahoganyTown_Interior1_EventScript_Trigger3::
	call_if_set 0x10E6, MahoganyTown_Interior1_EventScript_Trigger1_1
	call_if_unset 0x10E2, MahoganyTown_Interior1_EventScript_Trigger1_1
	msgbox MahoganyTown_Interior1_Text_Trigger1_1, MSGBOX_NPC
	waitse
	playmoncry SPECIES_DRAGONITE, 0x2800
	waitse
	nop
	applymovement 4, MahoganyTown_Interior1_Movement_Trigger1_1
	delay 48
	applymovement LOCALID_PLAYER, MahoganyTown_Interior1_Movement_Trigger3
	delay 16
	call MahoganyTown_Interior1_EventScript_Trigger1_2
	end

MahoganyTown_Interior1_Movement_Trigger3::
	walk_up
	step_end

MahoganyTown_Interior1_EventScript_Trigger4::
	warp MAP_UNUSED_NAVEL_ROCK_BASE_PATH_B10F, 0, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)
