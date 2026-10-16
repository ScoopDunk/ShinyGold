Unused_CeladonCity_House1_MapScripts::
	@ ShinyGold: unreachable map, emptied (the slot is kept so map ids stay the same)
	.byte 0

Unused_CeladonCity_House1_EventScript_Beauty::
	lock
	faceplayer
	setptr 98, 0x8E66081A
	msgbox Unused_CeladonCity_House1_Text_Beauty_1, MSGBOX_NPC
	pokemart Unused_CeladonCity_House1_Items_Beauty
	msgbox Unused_CeladonCity_House1_Text_Beauty_2, MSGBOX_NPC
	release
	end

	.align 1
Unused_CeladonCity_House1_Items_Beauty::
	.2byte ITEM_CHERI_BERRY
	.2byte ITEM_CHESTO_BERRY
	.2byte ITEM_PECHA_BERRY
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_ASPEAR_BERRY
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_WIKI_BERRY
	.2byte ITEM_MAGO_BERRY
	.2byte ITEM_AGUAV_BERRY
	.2byte ITEM_IAPAPA_BERRY
	.2byte ITEM_NONE

Unused_CeladonCity_House1_EventScript_Picnicker::
	msgbox Unused_CeladonCity_House1_Text_Picnicker, MSGBOX_NPC
	end

Unused_CeladonCity_House1_EventScript_Lass::
	msgbox Unused_CeladonCity_House1_Text_Lass, MSGBOX_NPC
	end
