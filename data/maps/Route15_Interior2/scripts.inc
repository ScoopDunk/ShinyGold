Route15_Interior2_MapScripts::
	.byte 0

Route15_Interior2_EventScript_Scientist::
	lock
	faceplayer
	call Route15_Interior2_EventScript_Scientist_1
	goto_if_set 0x256, Route15_Interior2_EventScript_Scientist_2
	msgbox Route15_Interior2_Text_Scientist_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route15_Interior2_EventScript_Scientist_1
	goto_if_lt VAR_0x8006, 50, Aide_EventScript_HaventCaughtEnough
	msgbox Route15_Interior2_Text_Scientist_2
	checkitemspace ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, 0, Aide_EventScript_NoRoomForItem
	giveitem_msg Route15_Interior2_Text_Scientist_3, ITEM_EXP_SHARE
	setflag 0x256
	msgbox Route15_Interior2_Text_Scientist_4
	release
	end

Route15_Interior2_EventScript_Scientist_1::
	buffernumberstring STR_VAR_1, 50
	bufferitemname STR_VAR_2, ITEM_EXP_SHARE
	return

Route15_Interior2_EventScript_Scientist_2::
	msgbox Route15_Interior2_Text_Scientist_4
	release
	end

Route15_Interior2_EventScript_Sign1::
	lockall
	msgbox Route15_Interior2_Text_Sign1
	showmonpic SPECIES_ARTICUNO, 10, 3
	delay 20
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, 144
	special SetSeenMon
	releaseall
	end

Route15_Interior2_EventScript_Sign2::
	msgbox Route15_Interior2_Text_Sign2, MSGBOX_SIGN
	end
