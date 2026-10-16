LakeOfRage_MapScripts::
	.byte 0

LakeOfRage_EventScript_OldMan1::
	msgbox LakeOfRage_Text_OldMan1, MSGBOX_NPC
	end

@ ShinyGold fix: forced-shiny is switched on only while the red GYARADOS is created (setwildbattle makes it), then off
@ again before the battle, so losing the battle can't leave every later Pokémon shiny.
LakeOfRage_EventScript_Psyduck::
	callnative SetForceShinyMons
	setflag 0x11E9
	faceplayer
	waitse
	playmoncry SPECIES_GYARADOS, 0x2800
	waitse
	nop
	delay 48
	setwildbattle SPECIES_GYARADOS, 30
	callnative ClearForceShinyMons
	special StartSouthernIslandBattle
	delay 160
	setflag 0x11EA
	clearflag 0x10E0
	clearflag 0x11E9
	callnative ClearForceShinyMons
	delay 32
	removeobject 4
	call_if_eq VAR_FACING, 1, LakeOfRage_EventScript_Psyduck_1
	call_if_eq VAR_FACING, 2, LakeOfRage_EventScript_Psyduck_2
	call_if_eq VAR_FACING, 3, LakeOfRage_EventScript_Psyduck_3
	call LakeOfRage_EventScript_Psyduck_4
	end

LakeOfRage_EventScript_Psyduck_1::
	applymovement LOCALID_PLAYER, LakeOfRage_Movement_Psyduck_1
	delay 16
	giveitem ITEM_LIFT_KEY
	release
	end

LakeOfRage_EventScript_Psyduck_2::
	applymovement LOCALID_PLAYER, LakeOfRage_Movement_Psyduck_2
	delay 16
	giveitem ITEM_LIFT_KEY
	release
	end

LakeOfRage_EventScript_Psyduck_3::
	applymovement LOCALID_PLAYER, LakeOfRage_Movement_Psyduck_3
	delay 16
	giveitem ITEM_LIFT_KEY
	release
	end

LakeOfRage_EventScript_Psyduck_4::
	applymovement LOCALID_PLAYER, LakeOfRage_Movement_Psyduck_4
	delay 16
	giveitem ITEM_LIFT_KEY
	release
	end

LakeOfRage_Movement_Psyduck_1::
	walk_down
	step_end

LakeOfRage_Movement_Psyduck_2::
	walk_up
	face_down_fast
	step_end

LakeOfRage_Movement_Psyduck_3::
	walk_left
	face_down_fast
	step_end

LakeOfRage_Movement_Psyduck_4::
	walk_right
	face_down_fast
	step_end

LakeOfRage_EventScript_Lass::
	msgbox LakeOfRage_Text_Lass, MSGBOX_NPC
	end

LakeOfRage_EventScript_PokeManiac::
	msgbox LakeOfRage_Text_PokeManiac, MSGBOX_NPC
	end

LakeOfRage_EventScript_FishermanRaymond::
	trainerbattle_single TRAINER_FISHERMAN_RAYMOND, LakeOfRage_Text_FishermanRaymondIntro, LakeOfRage_Text_FishermanRaymondDefeat
	msgbox LakeOfRage_Text_FishermanRaymond, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_FishermanAndre::
	trainerbattle_single TRAINER_FISHERMAN_ANDRE, LakeOfRage_Text_FishermanAndreIntro, LakeOfRage_Text_FishermanAndreDefeat
	msgbox LakeOfRage_Text_FishermanAndre, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_CooltrainerLois::
	trainerbattle_single TRAINER_COOLTRAINER_LOIS, LakeOfRage_Text_CooltrainerLoisIntro, LakeOfRage_Text_CooltrainerLoisDefeat
	msgbox LakeOfRage_Text_CooltrainerLois, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_CooltrainerAaron::
	trainerbattle_single TRAINER_COOLTRAINER_AARON, LakeOfRage_Text_CooltrainerAaronIntro, LakeOfRage_Text_CooltrainerAaronDefeat
	msgbox LakeOfRage_Text_CooltrainerAaron, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER
	end

LakeOfRage_EventScript_ItemTm17::
	finditem ITEM_TM17
	end

LakeOfRage_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

LakeOfRage_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

LakeOfRage_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

LakeOfRage_EventScript_Lance::
	call_if_set 0x10E1, LakeOfRage_EventScript_Lance_1
	setflag 0x10E1
	applymovement 21, LakeOfRage_Movement_Lance_1
	msgbox LakeOfRage_Text_Lance_1, MSGBOX_AUTOCLOSE
	applymovement 21, LakeOfRage_Movement_Lance_2
	lock
	faceplayer
	msgbox LakeOfRage_Text_Lance_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, LakeOfRage_EventScript_Lance_2
	msgbox LakeOfRage_Text_Lance_3, MSGBOX_NPC
	end

LakeOfRage_EventScript_Lance_1::
	faceplayer
	msgbox LakeOfRage_Text_Lance_4, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, LakeOfRage_EventScript_Lance_2
	msgbox LakeOfRage_Text_Lance_3, MSGBOX_NPC
	end

LakeOfRage_EventScript_Lance_2::
	msgbox LakeOfRage_Text_Lance_5, MSGBOX_NPC
	setflag 0x10E2
	setflag 0x10E0
	clearflag 0x10E3
	clearflag 0x10E5
	warp MAP_LAKE_OF_RAGE, 3, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

LakeOfRage_Movement_Lance_1::
	face_up
	step_end

LakeOfRage_Movement_Lance_2::
	face_player
	step_end

LakeOfRage_EventScript_Boy::
	call_if_set 0x1242, LakeOfRage_EventScript_Boy_1
	msgbox LakeOfRage_Text_Boy_1, MSGBOX_NPC
	giveitem ITEM_BLACK_BELT
	msgbox LakeOfRage_Text_Boy_2, MSGBOX_NPC
	setflag 0x1242
	clearflag 0x1243
	release
	end

LakeOfRage_EventScript_Boy_1::
	msgbox LakeOfRage_Text_Boy_3, MSGBOX_NPC
	end

LakeOfRage_EventScript_Trigger1::
	call_if_set 0x10D9, LakeOfRage_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, LakeOfRage_Movement_Trigger1_1
	delay 80
	call LakeOfRage_EventScript_Trigger1_2
	end

LakeOfRage_EventScript_Trigger1_1::
	release
	end

LakeOfRage_EventScript_Trigger1_2::
	msgbox LakeOfRage_Text_Trigger1_1, MSGBOX_NPC
	msgbox LakeOfRage_Text_Trigger1_2, MSGBOX_NPC
	msgbox LakeOfRage_Text_Trigger1_3, MSGBOX_NPC
	msgbox LakeOfRage_Text_Trigger1_4, MSGBOX_NPC
	applymovement 1, LakeOfRage_Movement_Trigger1_2
	applymovement 2, LakeOfRage_Movement_Trigger1_3
	msgbox LakeOfRage_Text_Trigger1_5, MSGBOX_NPC
	applymovement 1, LakeOfRage_Movement_Trigger1_4
	applymovement 2, LakeOfRage_Movement_Trigger1_4
	msgbox LakeOfRage_Text_Trigger1_6, MSGBOX_NPC
	applymovement 1, LakeOfRage_Movement_Trigger1_5
	msgbox LakeOfRage_Text_Trigger1_7, MSGBOX_NPC
	msgbox LakeOfRage_Text_Trigger1_8, MSGBOX_NPC
	applymovement 1, LakeOfRage_Movement_Trigger1_2
	applymovement 2, LakeOfRage_Movement_Trigger1_3
	msgbox LakeOfRage_Text_Trigger1_9, MSGBOX_NPC
	applymovement 2, LakeOfRage_Movement_Trigger1_6
	msgbox LakeOfRage_Text_Trigger1_10, MSGBOX_NPC
	delay 32
	applymovement 1, LakeOfRage_Movement_Trigger1_7
	applymovement 2, LakeOfRage_Movement_Trigger1_7
	msgbox LakeOfRage_Text_Trigger1_11, MSGBOX_NPC
	applymovement 1, LakeOfRage_Movement_Trigger1_2
	msgbox LakeOfRage_Text_Trigger1_12, MSGBOX_NPC
	msgbox LakeOfRage_Text_Trigger1_13, MSGBOX_NPC
	applymovement 1, LakeOfRage_Movement_Trigger1_7
	msgbox LakeOfRage_Text_Trigger1_14, MSGBOX_NPC
	applymovement 1, LakeOfRage_Movement_Trigger1_8
	applymovement 2, LakeOfRage_Movement_Trigger1_9
	delay 128
	setflag 0x10D9
	end

LakeOfRage_Movement_Trigger1_1::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

LakeOfRage_Movement_Trigger1_2::
	face_right
	step_end

LakeOfRage_Movement_Trigger1_3::
	face_left
	step_end

LakeOfRage_Movement_Trigger1_4::
	face_up
	step_end

LakeOfRage_Movement_Trigger1_5::
	emote_double_exclamation_mark
	step_end

LakeOfRage_Movement_Trigger1_6::
	face_right
	step_end

LakeOfRage_Movement_Trigger1_7::
	face_down_fast
	step_end

LakeOfRage_Movement_Trigger1_8::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

LakeOfRage_Movement_Trigger1_9::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

LakeOfRage_EventScript_Trigger2::
	call_if_set 0x10D9, LakeOfRage_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, LakeOfRage_Movement_Trigger2
	delay 80
	call LakeOfRage_EventScript_Trigger1_2
	end

LakeOfRage_Movement_Trigger2::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LakeOfRage_EventScript_Trigger3::
	call_if_set 0x10D9, LakeOfRage_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, LakeOfRage_Movement_Trigger3
	delay 80
	call LakeOfRage_EventScript_Trigger1_2
	end

LakeOfRage_Movement_Trigger3::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	step_end

LakeOfRage_EventScript_Trigger4::
	call_if_set 0x10D9, LakeOfRage_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, LakeOfRage_Movement_Trigger4
	delay 96
	call LakeOfRage_EventScript_Trigger1_2
	end

LakeOfRage_Movement_Trigger4::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

LakeOfRage_EventScript_Sign1::
	msgbox LakeOfRage_Text_Sign1, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Sign2::
	msgbox LakeOfRage_Text_Sign2, MSGBOX_AUTOCLOSE
	end
