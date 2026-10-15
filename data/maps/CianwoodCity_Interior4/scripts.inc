CianwoodCity_Interior4_MapScripts::
	.byte 0

CianwoodCity_Interior4_EventScript_Man::
	call_if_set 0x10CB, CianwoodCity_Interior4_EventScript_Man_1
	lock
	faceplayer
	msgbox CianwoodCity_Interior4_Text_Man_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, CianwoodCity_Interior4_EventScript_Man_2
	msgbox CianwoodCity_Interior4_Text_Man_2, MSGBOX_NPC
	end

CianwoodCity_Interior4_EventScript_Man_1::
	msgbox CianwoodCity_Interior4_Text_Man_3, MSGBOX_NPC
	end

CianwoodCity_Interior4_EventScript_Man_2::
	getpartysize
	call_if_lt VAR_RESULT, 6, CianwoodCity_Interior4_EventScript_Man_3
	msgbox CianwoodCity_Interior4_Text_Man_4, MSGBOX_NPC
	end

CianwoodCity_Interior4_EventScript_Man_3::
	setflag 0x10CB
	playfanfare SE_M_NIGHTMARE
	msgbox CianwoodCity_Interior4_Text_Man_5, MSGBOX_NPC
	.byte 0x79 @ givemon
	.2byte SPECIES_SHUCKLE
	.byte 15
	.2byte ITEM_ORAN_BERRY
	.4byte 0xCC800002
	.4byte 0x2090877
	.byte 2
	.byte 0xFF @ invalid opcode (script stops)
