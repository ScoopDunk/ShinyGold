OlivineCity_Interior4_MapScripts::
	.byte 0

OlivineCity_Interior4_EventScript_Fisher::
	call_if_set 0x10C6, OlivineCity_Interior4_EventScript_Fisher_1
	msgbox OlivineCity_Interior4_Text_Fisher_1, MSGBOX_NPC
	msgbox OlivineCity_Interior4_Text_Fisher_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, OlivineCity_Interior4_EventScript_Fisher_2
	msgbox OlivineCity_Interior4_Text_Fisher_3, MSGBOX_NPC
	end

OlivineCity_Interior4_EventScript_Fisher_1::
	msgbox OlivineCity_Interior4_Text_Fisher_4, MSGBOX_NPC
	end

OlivineCity_Interior4_EventScript_Fisher_2::
	setflag 0x10C6
	msgbox OlivineCity_Interior4_Text_Fisher_5, MSGBOX_NPC
	giveitem ITEM_GOOD_ROD
	msgbox OlivineCity_Interior4_Text_Fisher_6, MSGBOX_NPC
	end
