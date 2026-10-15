RockTunnel_Cave2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_Cave2_OnTransition
	.byte 0

RockTunnel_Cave2_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROCK_TUNNEL_1F
	end

RockTunnel_Cave2_EventScript_MrFuji::
	msgbox RockTunnel_Cave2_Text_MrFuji, MSGBOX_NPC
	end

RockTunnel_Cave2_EventScript_ItemElixir::
	finditem ITEM_ELIXIR
	end

RockTunnel_Cave2_EventScript_ItemTm47::
	finditem ITEM_TM47
	end

RockTunnel_Cave2_EventScript_ItemXAccuracy::
	finditem ITEM_X_ACCURACY
	end

RockTunnel_Cave2_EventScript_ItemXDefend::
	finditem ITEM_X_DEFEND
	end

RockTunnel_Cave2_EventScript_HikerYuzo::
	trainerbattle_single TRAINER_HIKER_YUZO, RockTunnel_Cave2_Text_HikerYuzoIntro, RockTunnel_Cave2_Text_HikerYuzoDefeat
	msgbox RockTunnel_Cave2_Text_HikerYuzo, MSGBOX_AUTOCLOSE
	end

RockTunnel_Cave2_EventScript_LaprasDoll::
	msgbox RockTunnel_Cave2_Text_LaprasDoll, MSGBOX_NPC
	end

RockTunnel_Cave2_EventScript_Trigger1::
	call_if_set 0x11D7, RockTunnel_Cave2_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, RockTunnel_Cave2_Movement_Trigger1_1
	delay 16
	applymovement 6, RockTunnel_Cave2_Movement_Trigger1_2
	delay 64
	applymovement LOCALID_PLAYER, RockTunnel_Cave2_Movement_Trigger1_3
	delay 1
	msgbox RockTunnel_Cave2_Text_Trigger1, MSGBOX_NPC
	setflag 0x11D7
	setflag 0x11D8
	setflag 0x11D9
	setflag 0x11DB
	release
	end

RockTunnel_Cave2_EventScript_Trigger1_1::
	release
	end

RockTunnel_Cave2_Movement_Trigger1_1::
	walk_right
	step_end

RockTunnel_Cave2_Movement_Trigger1_2::
	face_up
	emote_exclamation_mark
	step_end

RockTunnel_Cave2_Movement_Trigger1_3::
	face_down_fast
	step_end

RockTunnel_Cave2_EventScript_Trigger2::
	call_if_set 0x11DC, RockTunnel_Cave2_EventScript_Trigger2_1
	clearflag 0x11D8
	clearflag 0x11DB
	applymovement LOCALID_PLAYER, RockTunnel_Cave2_Movement_Trigger2_1
	delay 32
	call RockTunnel_Cave2_EventScript_Trigger2_2
	end

RockTunnel_Cave2_EventScript_Trigger2_1::
	release
	end

RockTunnel_Cave2_EventScript_Trigger2_2::
	msgbox RockTunnel_Cave2_Text_Trigger2_1, MSGBOX_NPC
	applymovement 4, RockTunnel_Cave2_Movement_Trigger2_2
	delay 16
	msgbox RockTunnel_Cave2_Text_Trigger2_2, MSGBOX_NPC
	applymovement 4, RockTunnel_Cave2_Movement_Trigger2_3
	delay 16
	msgbox RockTunnel_Cave2_Text_Trigger2_3, MSGBOX_NPC
	applymovement 1, RockTunnel_Cave2_Movement_Trigger2_4
	delay 48
	msgbox RockTunnel_Cave2_Text_Trigger2_4, MSGBOX_NPC
	applymovement 5, RockTunnel_Cave2_Movement_Trigger2_5
	delay 1
	msgbox RockTunnel_Cave2_Text_Trigger2_5, MSGBOX_NPC
	waitse
	playmoncry SPECIES_KANGASKHAN, 0x2028
	nop
	delay 32
	applymovement 1, RockTunnel_Cave2_Movement_Trigger2_6
	applymovement 2, RockTunnel_Cave2_Movement_Trigger2_7
	delay 48
	applymovement 1, RockTunnel_Cave2_Movement_Trigger2_8
	applymovement 5, RockTunnel_Cave2_Movement_Trigger2_9
	delay 96
	msgbox RockTunnel_Cave2_Text_Trigger2_6, MSGBOX_NPC
	delay 32
	applymovement 5, RockTunnel_Cave2_Movement_Trigger2_10
	delay 1
	msgbox RockTunnel_Cave2_Text_Trigger2_7, MSGBOX_NPC
	applymovement LOCALID_PLAYER, RockTunnel_Cave2_Movement_Trigger2_11
	applymovement 1, RockTunnel_Cave2_Movement_Trigger2_12
	delay 96
	msgbox RockTunnel_Cave2_Text_Trigger2_8, MSGBOX_NPC
	applymovement 5, RockTunnel_Cave2_Movement_Trigger2_13
	delay 112
	applymovement LOCALID_PLAYER, RockTunnel_Cave2_Movement_Trigger2_14
	delay 1
	waitse
	playmoncry SPECIES_KANGASKHAN, 0x2028
	nop
	delay 32
	applymovement 3, RockTunnel_Cave2_Movement_Trigger2_15
	delay 112
	msgbox RockTunnel_Cave2_Text_Trigger2_9, MSGBOX_NPC
	waitse
	playmoncry SPECIES_KANGASKHAN, 0x2028
	nop
	delay 32
	applymovement 2, RockTunnel_Cave2_Movement_Trigger2_16
	delay 80
	applymovement 3, RockTunnel_Cave2_Movement_Trigger2_17
	applymovement LOCALID_PLAYER, RockTunnel_Cave2_Movement_Trigger2_18
	delay 1
	msgbox RockTunnel_Cave2_Text_Trigger2_10, MSGBOX_NPC
	applymovement 3, RockTunnel_Cave2_Movement_Trigger2_19
	applymovement LOCALID_PLAYER, RockTunnel_Cave2_Movement_Trigger2_19
	delay 1
	applymovement 2, RockTunnel_Cave2_Movement_Trigger2_20
	delay 64
	waitse
	playmoncry SPECIES_KANGASKHAN, 0x3028
	nop
	delay 48
	setwildbattle SPECIES_KANGASKHAN, 50, ITEM_LEFTOVERS
	special StartSouthernIslandBattle
	delay 96
	applymovement 2, RockTunnel_Cave2_Movement_Trigger2_21
	applymovement 4, RockTunnel_Cave2_Movement_Trigger2_22
	delay 48
	applymovement 3, RockTunnel_Cave2_Movement_Trigger2_17
	applymovement LOCALID_PLAYER, RockTunnel_Cave2_Movement_Trigger2_18
	delay 1
	msgbox RockTunnel_Cave2_Text_Trigger2_11, MSGBOX_NPC
	applymovement 3, RockTunnel_Cave2_Movement_Trigger2_23
	applymovement LOCALID_PLAYER, RockTunnel_Cave2_Movement_Trigger2_24
	delay 160
	setflag 0x11D8
	setflag 0x11D9
	setflag 0x11DA
	setflag 0x11DB
	setflag 0x11DC
	setflag 0x11DF
	call RockTunnel_Cave2_EventScript_Trigger2_3
	release
	end

RockTunnel_Cave2_Movement_Trigger2_1::
	walk_down
	walk_left
	step_end

RockTunnel_Cave2_EventScript_Trigger2_3::
	call_if_set 0x1180, RockTunnel_Cave2_EventScript_Trigger2_4
	setflag 0x1251
	release
	end

RockTunnel_Cave2_Movement_Trigger2_2::
	walk_left
	face_right
	step_end

RockTunnel_Cave2_Movement_Trigger2_3::
	walk_slow_right
	step_end

RockTunnel_Cave2_Movement_Trigger2_4::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	face_right
	step_end

RockTunnel_Cave2_Movement_Trigger2_5::
	face_right
	step_end

RockTunnel_Cave2_Movement_Trigger2_6::
	emote_double_exclamation_mark
	jump_in_place_left
	step_end

RockTunnel_Cave2_Movement_Trigger2_7::
	walk_slow_right
	walk_slow_right
	step_end

RockTunnel_Cave2_Movement_Trigger2_8::
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	face_left
	step_end

RockTunnel_Cave2_Movement_Trigger2_9::
	face_left
	step_end

RockTunnel_Cave2_Movement_Trigger2_10::
	face_right
	step_end

RockTunnel_Cave2_Movement_Trigger2_11::
	walk_fast_down
	face_up
	step_end

RockTunnel_Cave2_Movement_Trigger2_12::
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	set_invisible
	walk_fast_left
	walk_fast_left
	step_end

RockTunnel_Cave2_Movement_Trigger2_13::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	set_invisible
	walk_fast_left
	walk_fast_left
	step_end

RockTunnel_Cave2_Movement_Trigger2_14::
	face_left
	step_end

RockTunnel_Cave2_Movement_Trigger2_15::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

RockTunnel_Cave2_Movement_Trigger2_16::
	walk_slow_down
	walk_slow_right
	walk_slow_right
	step_end

RockTunnel_Cave2_Movement_Trigger2_17::
	face_down_fast
	step_end

RockTunnel_Cave2_Movement_Trigger2_18::
	face_up
	step_end

RockTunnel_Cave2_Movement_Trigger2_19::
	face_left
	step_end

RockTunnel_Cave2_Movement_Trigger2_20::
	walk_slow_right
	walk_slow_right
	step_end

RockTunnel_Cave2_Movement_Trigger2_21::
	set_invisible
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RockTunnel_Cave2_Movement_Trigger2_22::
	set_invisible
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RockTunnel_Cave2_Movement_Trigger2_23::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	set_invisible
	walk_fast_up
	walk_fast_up
	step_end

RockTunnel_Cave2_Movement_Trigger2_24::
	face_left
	step_end

RockTunnel_Cave2_EventScript_Trigger2_4::
	setflag 0x11C4
	release
	end

RockTunnel_Cave2_EventScript_Trigger3::
	call_if_set 0x11DC, RockTunnel_Cave2_EventScript_Trigger2_1
	clearflag 0x11D8
	clearflag 0x11DB
	applymovement LOCALID_PLAYER, RockTunnel_Cave2_Movement_Trigger3
	delay 16
	call RockTunnel_Cave2_EventScript_Trigger2_2
	end

RockTunnel_Cave2_Movement_Trigger3::
	walk_left
	step_end

RockTunnel_Cave2_EventScript_Trigger4::
	call_if_set 0x11DC, RockTunnel_Cave2_EventScript_Trigger1_1
	clearflag 0x11D9
	release
	end
