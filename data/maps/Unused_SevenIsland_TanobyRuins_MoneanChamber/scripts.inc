Unused_SevenIsland_TanobyRuins_MoneanChamber_MapScripts::
	@ ShinyGold: overlapping data duplicated from 0x08164CCF
	@ ShinyGold: 1 entry with invalid type(s) 0x88 dropped (inert: the engine skips them)
	.byte 0

Unused_SevenIsland_TanobyRuins_MoneanChamber_EventScript_Beauty::
	call_if_set 0x1136, Unused_SevenIsland_TanobyRuins_MoneanChamber_EventScript_Beauty_1
	call_if_set 0x1135, Unused_SevenIsland_TanobyRuins_MoneanChamber_EventScript_Beauty_2
	msgbox Unused_SevenIsland_TanobyRuins_MoneanChamber_Text_Beauty_1, MSGBOX_NPC
	msgbox Unused_SevenIsland_TanobyRuins_MoneanChamber_Text_Beauty_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Unused_SevenIsland_TanobyRuins_MoneanChamber_EventScript_Beauty_3
	msgbox Unused_SevenIsland_TanobyRuins_MoneanChamber_Text_Beauty_3, MSGBOX_NPC
	end

Unused_SevenIsland_TanobyRuins_MoneanChamber_EventScript_Beauty_1::
	msgbox Unused_SevenIsland_TanobyRuins_MoneanChamber_Text_Beauty_4, MSGBOX_NPC
	end

Unused_SevenIsland_TanobyRuins_MoneanChamber_EventScript_Beauty_2::
	getpartysize
	call_if_lt VAR_RESULT, 6, Unused_SevenIsland_TanobyRuins_MoneanChamber_EventScript_Beauty_4
	msgbox Unused_SevenIsland_TanobyRuins_MoneanChamber_Text_Beauty_5, MSGBOX_NPC
	end

Unused_SevenIsland_TanobyRuins_MoneanChamber_EventScript_Beauty_3::
	msgbox Unused_SevenIsland_TanobyRuins_MoneanChamber_Text_Beauty_6, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_LASS_SANAE, 0, Unused_SevenIsland_TanobyRuins_MoneanChamber_Text_BeautyDefeat, Unused_SevenIsland_TanobyRuins_MoneanChamber_Text_BeautyVictory
	msgbox Unused_SevenIsland_TanobyRuins_MoneanChamber_Text_Beauty_7, MSGBOX_NPC
	setflag 0x1135
	call Unused_SevenIsland_TanobyRuins_MoneanChamber_EventScript_Beauty_2
	end

Unused_SevenIsland_TanobyRuins_MoneanChamber_EventScript_Beauty_4::
	setflag 0x1136
	playfanfare SE_M_NIGHTMARE
	msgbox Unused_SevenIsland_TanobyRuins_MoneanChamber_Text_Beauty_8, MSGBOX_NPC
	.byte 0x79 @ givemon
	.2byte SPECIES_TREECKO
	.byte 1
	.2byte ITEM_ORAN_BERRY
	.4byte 0x2090802
	.4byte 0xFFFFFF02
	.byte 255
	.byte 0xFF @ invalid opcode (script stops)

Unused_SevenIsland_TanobyRuins_MoneanChamber_EventScript_Pikachu::
	msgbox Unused_SevenIsland_TanobyRuins_MoneanChamber_Text_Pikachu, MSGBOX_NPC
	waitse
	playmoncry SPECIES_PIKACHU, 0x200
	.byte 0xFF @ invalid opcode (script stops)

Unused_SevenIsland_TanobyRuins_MoneanChamber_EventScript_Pidgeot::
	msgbox Unused_SevenIsland_TanobyRuins_MoneanChamber_Text_Pidgeot, MSGBOX_NPC
	waitse
	playmoncry SPECIES_PIDGEOTTO, 0x200
	.byte 0xFF @ invalid opcode (script stops)

Unused_SevenIsland_TanobyRuins_MoneanChamber_EventScript_Chansey::
	msgbox Unused_SevenIsland_TanobyRuins_MoneanChamber_Text_Chansey, MSGBOX_NPC
	waitse
	playmoncry SPECIES_CHANSEY, 0x200
	.byte 0xFF @ invalid opcode (script stops)

Unused_SevenIsland_TanobyRuins_MoneanChamber_EventScript_Trigger::
	warp MAP_NATIONAL_PARK, 2, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)
