PurityForest_Interior11_MapScripts::
	.byte 0

PurityForest_Interior11_EventScript_Scientist::
	lock
	faceplayer
	call PurityForest_Interior11_EventScript_Scientist_1
	goto_if_set 0x252, PurityForest_Interior11_EventScript_Scientist_2
	msgbox PurityForest_Interior11_Text_Scientist_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call PurityForest_Interior11_EventScript_Scientist_1
	goto_if_lt VAR_0x8006, 30, Aide_EventScript_HaventCaughtEnough
	msgbox PurityForest_Interior11_Text_Scientist_2
	checkitemspace ITEM_ITEMFINDER
	goto_if_eq VAR_RESULT, 0, Aide_EventScript_NoRoomForItem
	giveitem_msg PurityForest_Interior11_Text_Scientist_3, ITEM_ITEMFINDER
	setflag 0x252
	msgbox PurityForest_Interior11_Text_Scientist_4
	release
	end

PurityForest_Interior11_EventScript_Scientist_1::
	buffernumberstring STR_VAR_1, 30
	bufferitemname STR_VAR_2, ITEM_ITEMFINDER
	return

PurityForest_Interior11_EventScript_Scientist_2::
	msgbox PurityForest_Interior11_Text_Scientist_4
	release
	end

PurityForest_Interior11_EventScript_Sign1::
	lockall
	goto_if_set 0x253, PurityForest_Interior11_EventScript_Sign1_1
	msgbox PurityForest_Interior11_Text_Sign1_1
	releaseall
	end

PurityForest_Interior11_EventScript_Sign1_1::
	msgbox PurityForest_Interior11_Text_Sign1_2
	releaseall
	end

PurityForest_Interior11_EventScript_Sign2::
	msgbox PurityForest_Interior11_Text_Sign2, MSGBOX_SIGN
	end
