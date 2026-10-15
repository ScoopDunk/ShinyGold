SaffronCity_Interior9_MapScripts::
	.byte 0

SaffronCity_Interior9_EventScript_BaldingMan::
	goto_if_set 0x1186, SaffronCity_Interior9_EventScript_BaldingMan_1
	setflag 0x1186
	msgbox SaffronCity_Interior9_Text_BaldingMan_1, MSGBOX_NPC
	giveitem ITEM_TM29
	msgbox SaffronCity_Interior9_Text_BaldingMan_2, MSGBOX_NPC
	end

SaffronCity_Interior9_EventScript_BaldingMan_1::
	msgbox SaffronCity_Interior9_Text_BaldingMan_2, MSGBOX_NPC
	end
