CeladonCity_Interior8_MapScripts::
	.byte 0

CeladonCity_Interior8_EventScript_PokeManiac::
	call_if_set 0x11E5, CeladonCity_Interior8_EventScript_PokeManiac_1
	msgbox CeladonCity_Interior8_Text_PokeManiac_1, MSGBOX_NPC
	msgbox CeladonCity_Interior8_Text_PokeManiac_2, MSGBOX_NPC
	giveitem ITEM_TM03
	msgbox CeladonCity_Interior8_Text_PokeManiac_3, MSGBOX_NPC
	setflag 0x11E5
	release
	end

CeladonCity_Interior8_EventScript_PokeManiac_1::
	msgbox CeladonCity_Interior8_Text_PokeManiac_3, MSGBOX_NPC
	end
