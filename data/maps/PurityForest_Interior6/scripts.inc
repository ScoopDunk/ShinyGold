PurityForest_Interior6_MapScripts::
	.byte 0

PurityForest_Interior6_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox PurityForest_Interior6_Text_Meowth
	waitmoncry
	release
	end

PurityForest_Interior6_EventScript_Clefairy::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	msgbox PurityForest_Interior6_Text_Clefairy
	waitmoncry
	release
	end

PurityForest_Interior6_EventScript_NidoranF::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_NORMAL
	msgbox PurityForest_Interior6_Text_NidoranF
	waitmoncry
	release
	end

PurityForest_Interior6_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set 0x2F8, PurityForest_Interior6_EventScript_OldWoman_1
	goto_if_set FLAG_SYS_GAME_CLEAR, PurityForest_Interior6_EventScript_OldWoman_2
	goto_if_set 0x2A6, PurityForest_Interior6_EventScript_OldWoman_1
	msgbox PurityForest_Interior6_Text_OldWoman_1
	setflag 0x2A6
	giveitem ITEM_TEA
	goto_if_eq VAR_RESULT, 0, EventScript_BagIsFull
	msgbox PurityForest_Interior6_Text_OldWoman_2
	release
	end

PurityForest_Interior6_EventScript_OldWoman_1::
	msgbox PurityForest_Interior6_Text_OldWoman_3
	release
	end

PurityForest_Interior6_EventScript_OldWoman_2::
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 4
	special SetFlavorTextFlagFromSpecialVars
	setflag 0x2F8
	msgbox PurityForest_Interior6_Text_OldWoman_4
	release
	end

PurityForest_Interior6_EventScript_Sign1::
	msgbox PurityForest_Interior6_Text_Sign1, MSGBOX_SIGN
	end
