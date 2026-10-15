PurityForest_Interior8_MapScripts::
	.byte 0

PurityForest_Interior8_EventScript_Rocker::
	msgbox PurityForest_Interior8_Text_Rocker, MSGBOX_NPC
	end

PurityForest_Interior8_EventScript_Man::
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllKantoMons
	goto_if_eq VAR_RESULT, 1, PurityForest_Interior8_EventScript_Man_1
	msgbox PurityForest_Interior8_Text_Man_1
	release
	end

PurityForest_Interior8_EventScript_Man_1::
	goto PurityForest_Interior8_EventScript_Man_2

PurityForest_Interior8_EventScript_Man_2::
	message PurityForest_Interior8_Text_Man_2
	waitmessage
	delay 60
	goto_if_questlog EventScript_ReleaseEnd
	special ShowDiploma
	waitstate
	release
	end

PurityForest_Interior8_EventScript_PokeManiac::
	msgbox PurityForest_Interior8_Text_PokeManiac, MSGBOX_NPC
	end

PurityForest_Interior8_EventScript_FatMan::
	msgbox PurityForest_Interior8_Text_FatMan, MSGBOX_NPC
	end

PurityForest_Interior8_EventScript_Sign1::
	msgbox PurityForest_Interior8_Text_Sign1, MSGBOX_SIGN
	end

PurityForest_Interior8_EventScript_Sign2::
	msgbox PurityForest_Interior8_Text_Sign2, MSGBOX_SIGN
	end

PurityForest_Interior8_EventScript_Sign3::
	msgbox PurityForest_Interior8_Text_Sign3, MSGBOX_SIGN
	end

PurityForest_Interior8_EventScript_Sign4::
	msgbox PurityForest_Interior8_Text_Sign4, MSGBOX_SIGN
	end
