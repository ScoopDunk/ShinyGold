Unused_G34_M53_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G34_M53_EventScript_Trigger1::
	@ ShinyGold: overlapping data duplicated from 0x0878AF17
	warp MAP_UNUSED_G34_M52, 31, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M53_EventScript_Trigger2::
	call_if_set 0x1128, Unused_G34_M53_EventScript_Trigger2_1
	setflag 0x1128
	waitse
	playmoncry SPECIES_HO_OH, 0x200
	.byte 0xFF @ invalid opcode (script stops)

Unused_G34_M53_EventScript_Trigger2_1::
	release
	end

Unused_G34_M53_EventScript_Trigger4::
	call_if_set 0x1129, Unused_G34_M53_EventScript_Trigger4_1
	setflag 0x1129
	applymovement 1, Unused_G34_M53_Movement_Trigger4
	delay 128
	waitse
	playmoncry SPECIES_HO_OH, 0x5028
	nop
	nop
	checkitemtype 0x1A64
	gotostd 102

Unused_G34_M53_EventScript_Trigger4_1::
	release
	end

Unused_G34_M53_Movement_Trigger4::
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

Unused_G34_M53_EventScript_Trigger5::
	call_if_set 0x1129, Unused_G34_M53_EventScript_Trigger4_1
	setflag 0x1129
	applymovement 1, Unused_G34_M53_Movement_Trigger5
	delay 128
	waitse
	playmoncry SPECIES_HO_OH, 0x5028
	nop
	nop
	checkitemtype 0x1A64
	gotostd 102

Unused_G34_M53_Movement_Trigger5::
	walk_fast_right
	face_down_fast
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end
