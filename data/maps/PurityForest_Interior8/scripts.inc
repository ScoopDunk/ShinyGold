PurityForest_Interior8_MapScripts::
	@ ShinyGold: unreachable map, emptied (the slot is kept so map ids stay the same)
	.byte 0

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
