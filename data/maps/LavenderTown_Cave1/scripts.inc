LavenderTown_Cave1_MapScripts::
	@ ShinyGold: map script header pointer was 0x08000000 (invalid)
	.byte 0

LavenderTown_Cave1_EventScript_Gentleman::
	lock
	faceplayer
	msgbox LavenderTown_Cave1_Text_Gentleman_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, LavenderTown_Cave1_EventScript_Gentleman_1
	goto_if_eq VAR_RESULT, 0, LavenderTown_Cave1_EventScript_Gentleman_2
	end

LavenderTown_Cave1_EventScript_Gentleman_1::
	msgbox LavenderTown_Cave1_Text_Gentleman_2
	special ChoosePartyMon
	waitstate
	goto_if_lt VAR_0x8004, 6, LavenderTown_Cave1_EventScript_Gentleman_3
	goto_if_ge VAR_0x8004, 6, LavenderTown_Cave1_EventScript_Gentleman_2
	end

LavenderTown_Cave1_EventScript_Gentleman_2::
	msgbox LavenderTown_Cave1_Text_Gentleman_3
	release
	end

LavenderTown_Cave1_EventScript_Gentleman_3::
	specialvar VAR_RESULT, GetPartyMonSpecies
	goto_if_eq VAR_RESULT, 0x19C, LavenderTown_Cave1_EventScript_Gentleman_4
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, 1, LavenderTown_Cave1_EventScript_Gentleman_5
	specialvar VAR_RESULT, IsMonOTNameNotPlayers
	special BufferMonNickname
	goto_if_eq VAR_RESULT, 1, LavenderTown_Cave1_EventScript_Gentleman_5
	msgbox LavenderTown_Cave1_Text_Gentleman_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, LavenderTown_Cave1_EventScript_Gentleman_6
	goto_if_eq VAR_RESULT, 0, LavenderTown_Cave1_EventScript_Gentleman_2
	end

LavenderTown_Cave1_EventScript_Gentleman_4::
	msgbox LavenderTown_Cave1_Text_Gentleman_5
	release
	end

LavenderTown_Cave1_EventScript_Gentleman_5::
	msgbox LavenderTown_Cave1_Text_Gentleman_6
	release
	end

LavenderTown_Cave1_EventScript_Gentleman_6::
	msgbox LavenderTown_Cave1_Text_Gentleman_7
	call EventScript_ChangePokemonNickname
	specialvar VAR_RESULT, NameRaterWasNicknameChanged
	special BufferMonNickname
	goto_if_eq VAR_RESULT, 1, LavenderTown_Cave1_EventScript_Gentleman_7
	msgbox LavenderTown_Cave1_Text_Gentleman_8
	release
	end

LavenderTown_Cave1_EventScript_Gentleman_7::
	msgbox LavenderTown_Cave1_Text_Gentleman_9
	release
	end
