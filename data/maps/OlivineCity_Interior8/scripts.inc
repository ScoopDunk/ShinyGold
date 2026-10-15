OlivineCity_Interior8_MapScripts::
	.byte 0

OlivineCity_Interior8_EventScript_Fisher::
	lock
	faceplayer
	setvar VAR_0x8008, 3
	call EventScript_GetInGameTradeSpeciesInfo
	goto_if_set 0x124A, OlivineCity_Interior8_EventScript_Fisher_1
	msgbox OlivineCity_Interior8_Text_Fisher_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, OlivineCity_Interior8_EventScript_Fisher_2
	call EventScript_ChooseMonForInGameTrade
	goto_if_ge VAR_0x8004, 6, OlivineCity_Interior8_EventScript_Fisher_2
	call EventScript_GetInGameTradeSpecies
	goto_if_ne VAR_RESULT, VAR_0x8009, OlivineCity_Interior8_EventScript_Fisher_3
	call EventScript_DoInGameTrade
	msgbox OlivineCity_Interior8_Text_Fisher_2
	setflag 0x124A
	release
	end

OlivineCity_Interior8_EventScript_Fisher_1::
	msgbox OlivineCity_Interior8_Text_Fisher_3
	release
	end

OlivineCity_Interior8_EventScript_Fisher_2::
	msgbox OlivineCity_Interior8_Text_Fisher_4
	release
	end

OlivineCity_Interior8_EventScript_Fisher_3::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox OlivineCity_Interior8_Text_Fisher_5
	release
	end
