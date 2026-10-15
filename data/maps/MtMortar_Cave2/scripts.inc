MtMortar_Cave2_MapScripts::
	.byte 0

MtMortar_Cave2_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

MtMortar_Cave2_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION
	end

MtMortar_Cave2_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

MtMortar_Cave2_EventScript_ItemMaxRepel::
	finditem ITEM_MAX_REPEL
	end

MtMortar_Cave2_EventScript_BlackBelt::
	faceplayer
	call_if_set 0x10D2, MtMortar_Cave2_EventScript_BlackBelt_1
	msgbox MtMortar_Cave2_Text_BlackBelt_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, MtMortar_Cave2_EventScript_BlackBelt_2
	msgbox MtMortar_Cave2_Text_BlackBelt_2, MSGBOX_NPC
	end

MtMortar_Cave2_EventScript_BlackBelt_1::
	msgbox MtMortar_Cave2_Text_BlackBelt_3, MSGBOX_NPC
	end

MtMortar_Cave2_EventScript_BlackBelt_2::
	trainerbattle_earlyrival TRAINER_BLACK_BELT_KAZUO, 0, MtMortar_Cave2_Text_BlackBeltDefeat, MtMortar_Cave2_Text_BlackBeltVictory
	msgbox MtMortar_Cave2_Text_BlackBelt_4, MSGBOX_NPC
	giveitem ITEM_PROTEIN
	msgbox MtMortar_Cave2_Text_BlackBelt_5, MSGBOX_NPC
	setflag 0x10D2
	end
