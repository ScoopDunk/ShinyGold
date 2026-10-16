TinTower_Roof_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

TinTower_Roof_EventScript_Trigger1::
	@ ShinyGold: overlapping data duplicated from 0x0878AF17
	warp MAP_TIN_TOWER_UPPER_FLOORS, 31, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

TinTower_Roof_EventScript_Trigger2::
	call_if_set 0x1128, TinTower_Roof_EventScript_Trigger2_1
	setflag 0x1128
	waitse
	playmoncry SPECIES_HO_OH, 0x200
	.byte 0xFF @ invalid opcode (script stops)

TinTower_Roof_EventScript_Trigger2_1::
	release
	end

TinTower_Roof_EventScript_Trigger4::
	call_if_set 0x1129, TinTower_Roof_EventScript_Trigger4_1
	setflag 0x1129
	applymovement 1, TinTower_Roof_Movement_Trigger4
	delay 128
	goto TinTower_Roof_EventScript_HoOh

TinTower_Roof_EventScript_Trigger4_1::
	release
	end

@ Pure Gold: Ho-Oh on the TIN TOWER roof, Lv 40 holding SACRED ASH, as in Gold (pokegold TinTowerRoof TinTowerHoOh:
@ BATTLETYPE_FORCEITEM). The hack's bytes after Ho-Oh's cry were garbled (a text pointer read as "checkitemtype" and a
@ "gotostd" out of range, which this tree's script engine skips), so its battle (Lv 45) was lost in this tree.
TinTower_Roof_EventScript_HoOh::
	lockall
	waitse
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	msgbox TinTower_Roof_Text_HoOh
	waitmoncry
	delay 10
	setwildbattle SPECIES_HO_OH, 40, ITEM_SACRED_ASH
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	releaseall
	end

TinTower_Roof_Movement_Trigger4::
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

TinTower_Roof_EventScript_Trigger5::
	call_if_set 0x1129, TinTower_Roof_EventScript_Trigger4_1
	setflag 0x1129
	applymovement 1, TinTower_Roof_Movement_Trigger5
	delay 128
	goto TinTower_Roof_EventScript_HoOh

TinTower_Roof_Movement_Trigger5::
	walk_fast_right
	face_down_fast
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

TinTower_Roof_Text_HoOh::
	.string "Shaoooh!$"
