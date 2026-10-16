Lighthouse_Interior2_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Lighthouse_Interior2_EventScript_Woman3::
	msgbox Lighthouse_Interior2_Text_Woman3, MSGBOX_NPC
	end

Lighthouse_Interior2_EventScript_Sailor::
	msgbox Lighthouse_Interior2_Text_Sailor, MSGBOX_NPC
	end

Lighthouse_Interior2_EventScript_Sailor261::
	trainerbattle_single TRAINER_SAILOR_HUEY_2, Lighthouse_Interior2_Text_Sailor261Intro, Lighthouse_Interior2_Text_Sailor261Defeat
	call_if_set 0x1317, Lighthouse_Interior2_EventScript_Sailor261_1
	setvar 0x700C, 23
	setvar 0x700D, 0
	call_if_set 0x1347, Route35_EventScript_Juggler228_2
	msgbox Lighthouse_Interior2_Text_Sailor261, MSGBOX_NPC
	setflag 0x1347
	call Route35_EventScript_Juggler228_3
	end

Lighthouse_Interior2_EventScript_Sailor261_1::
	clearflag 0x1317
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, Lighthouse_Interior2_EventScript_Sailor261_2
	call_if_set 0x115F, Lighthouse_Interior2_EventScript_Sailor261_3
	call_if_set FLAG_BADGE07_GET, Lighthouse_Interior2_EventScript_Sailor261_4
	call_if_set 0x110A, Lighthouse_Interior2_EventScript_Sailor261_5
	trainerbattle_earlyrival TRAINER_SAILOR_HUEY_2, 0, Lighthouse_Interior2_Text_Sailor261Defeat, Route35_Text_Juggler228Victory
	release
	end

Lighthouse_Interior2_EventScript_Sailor261_2::
	trainerbattle_earlyrival TRAINER_SAILOR_HUEY_4, 0, Lighthouse_Interior2_Text_Sailor261Defeat, Route35_Text_Juggler228Victory
	release
	end

Lighthouse_Interior2_EventScript_Sailor261_3::
	trainerbattle_earlyrival TRAINER_SAILOR_HUEY_5, 0, Lighthouse_Interior2_Text_Sailor261Defeat, Route35_Text_Juggler228Victory
	release
	end

Lighthouse_Interior2_EventScript_Sailor261_4::
	trainerbattle_earlyrival TRAINER_SAILOR_HUEY_6, 0, Lighthouse_Interior2_Text_Sailor261Defeat, Route35_Text_Juggler228Victory
	release
	end

Lighthouse_Interior2_EventScript_Sailor261_5::
	trainerbattle_earlyrival TRAINER_SAILOR_HUEY_3, 0, Lighthouse_Interior2_Text_Sailor261Defeat, Route35_Text_Juggler228Victory
	release
	end

Lighthouse_Interior2_EventScript_GentlemanAlfred::
	trainerbattle_single TRAINER_GENTLEMAN_ALFRED, Lighthouse_Interior2_Text_GentlemanAlfredIntro, Lighthouse_Interior2_Text_GentlemanAlfredDefeat
	msgbox Lighthouse_Interior2_Text_GentlemanAlfred, MSGBOX_AUTOCLOSE
	end

Lighthouse_Interior2_EventScript_BirdKeeperTheo::
	trainerbattle_single TRAINER_BIRD_KEEPER_THEO, Lighthouse_Interior2_Text_BirdKeeperTheoIntro, Lighthouse_Interior2_Text_BirdKeeperTheoDefeat
	msgbox Lighthouse_Interior2_Text_BirdKeeperTheo, MSGBOX_AUTOCLOSE
	end

Lighthouse_Interior2_EventScript_GentlemanPreston::
	trainerbattle_single TRAINER_GENTLEMAN_PRESTON, Lighthouse_Interior2_Text_GentlemanPrestonIntro, Lighthouse_Interior2_Text_GentlemanPrestonDefeat
	msgbox Lighthouse_Interior2_Text_GentlemanPreston, MSGBOX_AUTOCLOSE
	end

Lighthouse_Interior2_EventScript_LassConnie::
	trainerbattle_single TRAINER_LASS_CONNIE, Lighthouse_Interior2_Text_LassConnieIntro, Lighthouse_Interior2_Text_LassConnieDefeat
	msgbox Lighthouse_Interior2_Text_LassConnie, MSGBOX_AUTOCLOSE
	end

Lighthouse_Interior2_EventScript_SailorKent::
	trainerbattle_single TRAINER_SAILOR_KENT, Lighthouse_Interior2_Text_SailorKentIntro, Lighthouse_Interior2_Text_SailorKentDefeat
	msgbox Lighthouse_Interior2_Text_SailorKent, MSGBOX_AUTOCLOSE
	end

Lighthouse_Interior2_EventScript_BirdKeeperDenis::
	trainerbattle_single TRAINER_BIRD_KEEPER_DENIS, Lighthouse_Interior2_Text_BirdKeeperDenisIntro, Lighthouse_Interior2_Text_BirdKeeperDenisDefeat
	msgbox Lighthouse_Interior2_Text_BirdKeeperDenis, MSGBOX_AUTOCLOSE
	end

Lighthouse_Interior2_EventScript_SailorTerrell::
	trainerbattle_single TRAINER_SAILOR_TERRELL, Lighthouse_Interior2_Text_SailorTerrellIntro, Lighthouse_Interior2_Text_SailorTerrellDefeat
	msgbox Lighthouse_Interior2_Text_SailorTerrell, MSGBOX_AUTOCLOSE
	end

Lighthouse_Interior2_EventScript_SailorErnest::
	trainerbattle_single TRAINER_SAILOR_ERNEST, Lighthouse_Interior2_Text_SailorErnestIntro, Lighthouse_Interior2_Text_SailorErnestDefeat
	msgbox Lighthouse_Interior2_Text_SailorErnest, MSGBOX_AUTOCLOSE
	end

Lighthouse_Interior2_EventScript_ItemEther::
	finditem ITEM_ETHER
	end

Lighthouse_Interior2_EventScript_ItemTm34::
	finditem ITEM_TM34
	end

Lighthouse_Interior2_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

Lighthouse_Interior2_EventScript_ItemGreatBall::
	finditem ITEM_GREAT_BALL
	end

Lighthouse_Interior2_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION
	end

Lighthouse_Interior2_EventScript_ItemSuperPotion::
	finditem ITEM_SUPER_POTION
	end

Lighthouse_Interior2_EventScript_Lass::
	checkitem ITEM_TEA
	call_if_eq VAR_RESULT, 1, Lighthouse_Interior2_EventScript_Lass_1
	call_if_set 0x10C9, Lighthouse_Interior2_EventScript_Lass_2
	setflag 0x10C9
	msgbox Lighthouse_Interior2_Text_Lass_1, MSGBOX_NPC
	end

Lighthouse_Interior2_EventScript_Lass_1::
	faceplayer
	msgbox Lighthouse_Interior2_Text_Lass_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Lighthouse_Interior2_EventScript_Lass_3
	msgbox Lighthouse_Interior2_Text_Lass_3, MSGBOX_NPC
	applymovement 18, Lighthouse_Interior2_Movement_Lass_1
	applymovement 19, Lighthouse_Interior2_Movement_Lass_2
	msgbox Lighthouse_Interior2_Text_Lass_4, MSGBOX_AUTOCLOSE
	end

Lighthouse_Interior2_EventScript_Lass_2::
	msgbox Lighthouse_Interior2_Text_Lass_5, MSGBOX_NPC
	end

Lighthouse_Interior2_EventScript_Lass_3::
	removeitem ITEM_TEA
	msgbox Lighthouse_Interior2_Text_Lass_6, MSGBOX_NPC
	playbgm MUS_NONE, 51
	applymovement 18, Lighthouse_Interior2_Movement_Lass_1
	applymovement 19, Lighthouse_Interior2_Movement_Lass_2
	delay 16
	playbgm MUS_HEAL, 50
	delay 128
	msgbox Lighthouse_Interior2_Text_Lass_7, MSGBOX_AUTOCLOSE
	msgbox Lighthouse_Interior2_Text_Lass_8, MSGBOX_AUTOCLOSE
	waitse
	playmoncry SPECIES_AMPHAROS, 0x2028
	nop
	delay 32
	applymovement 19, Lighthouse_Interior2_Movement_Lass_3
	delay 64
	playbgm MUS_NET_CENTER, 51
	msgbox Lighthouse_Interior2_Text_Lass_9, MSGBOX_NPC
	call_if_eq VAR_TEMP_1, 1, Lighthouse_Interior2_EventScript_Lass_4
	applymovement 18, Lighthouse_Interior2_Movement_Lass_4
	delay 144
	clearflag 0x10C8
	setflag 0x10CF
	end

Lighthouse_Interior2_EventScript_Lass_4::
	applymovement 18, Lighthouse_Interior2_Movement_Lass_5
	delay 144
	clearflag 0x10C8
	setflag 0x10CF
	end

Lighthouse_Interior2_Movement_Lass_1::
	face_right
	step_end

Lighthouse_Interior2_Movement_Lass_2::
	face_left
	step_end

Lighthouse_Interior2_Movement_Lass_3::
	jump_in_place_left
	jump_in_place_left
	step_end

Lighthouse_Interior2_Movement_Lass_4::
	walk_slow_up
	walk_slow_up
	walk_slow_right
	walk_slow_up
	walk_slow_up
	walk_slow_up
	set_invisible
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Lighthouse_Interior2_Movement_Lass_5::
	walk_slow_down
	walk_slow_right
	walk_slow_down
	walk_slow_down
	walk_slow_down
	set_invisible
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Lighthouse_Interior2_EventScript_Nidorino::
	call_if_set 0x10CF, Lighthouse_Interior2_EventScript_Nidorino_1
	msgbox Lighthouse_Interior2_Text_Nidorino, MSGBOX_NPC
	waitse
	playmoncry SPECIES_AMPHAROS, 0x205
	.byte 0xFF @ invalid opcode (script stops)

Lighthouse_Interior2_EventScript_Nidorino_1::
	msgbox Lighthouse_Interior2_Text_Lass_8, MSGBOX_NPC
	waitse
	playmoncry SPECIES_AMPHAROS, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

Lighthouse_Interior2_EventScript_Trigger1::
	setvar VAR_TEMP_1, 1
	release
	end

Lighthouse_Interior2_EventScript_Trigger2::
	setvar VAR_TEMP_1, 2
	release
	end
