MtMortar_Cave4_MapScripts::
	.byte 0

MtMortar_Cave4_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

MtMortar_Cave4_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION
	end

MtMortar_Cave4_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

MtMortar_Cave4_EventScript_BlackBelt::
	call_if_set 0x1163, MtMortar_Cave4_EventScript_BlackBelt_1
	call_if_set 0x1162, MtMortar_Cave4_EventScript_BlackBelt_2
	msgbox MtMortar_Cave4_Text_BlackBelt_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_BLACK_BELT_KIYO, 0, MtMortar_Cave4_Text_BlackBeltDefeat, MtMortar_Cave4_Text_BlackBeltVictory
	setflag 0x1162
	call MtMortar_Cave4_EventScript_BlackBelt_2

MtMortar_Cave4_EventScript_BlackBelt_2::
	msgbox MtMortar_Cave4_Text_BlackBelt_2, MSGBOX_NPC
	getpartysize
	call_if_eq VAR_RESULT, 6, MtMortar_Cave4_EventScript_BlackBelt_3
	setflag 0x1163
	playfanfare SE_M_NIGHTMARE
	msgbox MtMortar_Cave4_Text_BlackBelt_3, MSGBOX_NPC
	msgbox MtMortar_Cave4_Text_BlackBelt_4, MSGBOX_NPC
	.byte 0x79 @ givemon
	.2byte SPECIES_TYROGUE
	.byte 10
	.2byte ITEM_NONE
	.4byte 0x3764000F
	.4byte 0x2090880
	.byte 2
	.byte 0xFF @ invalid opcode (script stops)

MtMortar_Cave4_EventScript_BlackBelt_1::
	msgbox MtMortar_Cave4_Text_BlackBelt_4, MSGBOX_NPC
	end

MtMortar_Cave4_EventScript_BlackBelt_3::
	@ ShinyGold: overlapping data duplicated from 0x08803600
	msgbox MtMortar_Cave4_Text_BlackBelt_5, MSGBOX_NPC
	end
