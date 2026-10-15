CeladonCity_Interior18_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

CeladonCity_Interior18_EventScript_FatMan::
	msgbox CeladonCity_Interior18_Text_FatMan, MSGBOX_NPC
	end

CeladonCity_Interior18_EventScript_Scientist::
	msgbox CeladonCity_Interior18_Text_Scientist, MSGBOX_NPC
	end

CeladonCity_Interior18_EventScript_PokeManiac::
	msgbox CeladonCity_Interior18_Text_PokeManiac, MSGBOX_NPC
	end

CeladonCity_Interior18_EventScript_Sign::
	msgbox CeladonCity_Interior18_Text_Sign, MSGBOX_AUTOCLOSE
	end

@ ShinyGold: moved from data/maps/PurityForest_Interior8/scripts.inc (map removed)
PurityForest_Interior8_EventScript_Man::
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllKantoMons
	goto_if_eq VAR_RESULT, 1, PurityForest_Interior8_EventScript_Man_1
	msgbox PurityForest_Interior8_Text_Man_1
	release
	end

@ ShinyGold: moved from data/maps/PurityForest_Interior8/scripts.inc (map removed)
PurityForest_Interior8_EventScript_Man_1::
	goto PurityForest_Interior8_EventScript_Man_2

@ ShinyGold: moved from data/maps/PurityForest_Interior8/scripts.inc (map removed)
PurityForest_Interior8_EventScript_Man_2::
	message PurityForest_Interior8_Text_Man_2
	waitmessage
	delay 60
	goto_if_questlog EventScript_ReleaseEnd
	special ShowDiploma
	waitstate
	release
	end
