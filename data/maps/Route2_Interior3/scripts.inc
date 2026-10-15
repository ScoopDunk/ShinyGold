Route2_Interior3_MapScripts::
	.byte 0

Route2_Interior3_EventScript_Scientist::
	lock
	faceplayer
	call Route14_EventScript_Sign1_2
	goto_if_set FLAG_GOT_HM05, Route2_Interior3_EventScript_Scientist_1
	msgbox Route2_Interior3_Text_Scientist_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route14_EventScript_Sign1_2
	goto_if_lt VAR_0x8006, 10, Aide_EventScript_HaventCaughtEnough
	msgbox Route2_Interior3_Text_Scientist_2
	checkitemspace ITEM_HM05
	goto_if_eq VAR_RESULT, 0, Aide_EventScript_NoRoomForItem
	giveitem_msg Route2_Interior3_Text_Scientist_3, ITEM_HM05
	setflag FLAG_GOT_HM05
	msgbox Route2_Interior3_Text_Scientist_4
	release
	end

Route2_Interior3_EventScript_Scientist_1::
	msgbox Route2_Interior3_Text_Scientist_4
	release
	end

Route2_Interior3_EventScript_Rocker::
	msgbox Route2_Interior3_Text_Rocker, MSGBOX_NPC
	end
