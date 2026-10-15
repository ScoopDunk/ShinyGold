FuchsiaCity_Interior1_MapScripts::
	.byte 0

FuchsiaCity_Interior1_EventScript_FatMan::
	call_if_set 0x1201, FuchsiaCity_Interior1_EventScript_FatMan_1
	msgbox FuchsiaCity_Interior1_Text_FatMan_1, MSGBOX_NPC
	lock
	faceplayer
	giveitem ITEM_FIRE_STONE
	setflag 0x1201
	msgbox FuchsiaCity_Interior1_Text_FatMan_2, MSGBOX_NPC
	end

FuchsiaCity_Interior1_EventScript_FatMan_1::
	msgbox FuchsiaCity_Interior1_Text_FatMan_2, MSGBOX_NPC
	end

FuchsiaCity_Interior1_EventScript_Woman1::
	msgbox FuchsiaCity_Interior1_Text_Woman1, MSGBOX_NPC
	end
