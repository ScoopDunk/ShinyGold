Route26_Area1_MapScripts::
	.byte 0

@ G/S DayOfWeekSiblingsHousePokedexScript. The siblings stand where this hack placed them (it has no clock).
Route26_Area1_EventScript_Pokedex::
	lockall
	msgbox Route26_Area1_Text_Pokedex_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route26_Area1_EventScript_Pokedex_End
	msgbox Route26_Area1_Text_Pokedex_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route26_Area1_EventScript_Pokedex_End
	msgbox Route26_Area1_Text_Pokedex_3, MSGBOX_DEFAULT
Route26_Area1_EventScript_Pokedex_End::
	releaseall
	end
