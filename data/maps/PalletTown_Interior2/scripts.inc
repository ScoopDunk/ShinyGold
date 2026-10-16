PalletTown_Interior2_MapScripts::
	.byte 0

PalletTown_Interior2_EventScript_ProfOak::
	lock
	faceplayer
	goto_if_unset 0x030, PalletTown_Interior2_EventScript_ProfOak_1
	goto_if_unset 0x02E, PalletTown_Interior2_EventScript_ProfOak_1
	goto_if_unset 0x117F, PalletTown_Interior2_EventScript_ProfOak_1
	goto_if_unset 0x056, PalletTown_Interior2_EventScript_ProfOak_1
	goto_if_unset 0x11F7, PalletTown_Interior2_EventScript_ProfOak_1
	goto_if_unset 0x1181, PalletTown_Interior2_EventScript_ProfOak_1
	goto_if_unset 0x1180, PalletTown_Interior2_EventScript_ProfOak_1
	goto_if_unset 0x117E, PalletTown_Interior2_EventScript_ProfOak_1
	goto_if_unset 0x08B, PalletTown_Interior2_EventScript_ProfOak_2
	msgbox PalletTown_Interior2_Text_ProfOak_1, MSGBOX_AUTOCLOSE
	goto PalletTown_Interior2_EventScript_ProfOak_3

PalletTown_Interior2_EventScript_ProfOak_1::
	msgbox PalletTown_Interior2_Text_ProfOak_2, MSGBOX_AUTOCLOSE
	goto PalletTown_Interior2_EventScript_ProfOak_3

PalletTown_Interior2_EventScript_ProfOak_2::
	msgbox PalletTown_Interior2_Text_ProfOak_3, MSGBOX_AUTOCLOSE
	setflag 0x08B
	goto PalletTown_Interior2_EventScript_ProfOak_3

PalletTown_Interior2_EventScript_ProfOak_3::
	setvar VAR_0x8004, 31
	special BackupHelpContext
	special Script_SetHelpContext
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetPokedexCount
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008
	buffernumberstring STR_VAR_2, VAR_0x8009
	msgbox PalletTown_Interior2_Text_ProfOak_4
	call_if_unset 0x2FF, PalletTown_Interior2_EventScript_ProfOak_4
	call PalletTown_Interior2_EventScript_ProfOak_5
	goto_if_eq VAR_0x800A, 0, PalletTown_Interior2_EventScript_ProfOak_6
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetPokedexCount
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring STR_VAR_1, VAR_0x8008
	buffernumberstring STR_VAR_2, VAR_0x8009
	msgbox PalletTown_Interior2_Text_ProfOak_5, MSGBOX_AUTOCLOSE
	specialvar VAR_RESULT, HasAllMons
	goto_if_eq VAR_RESULT, 0, PalletTown_Interior2_EventScript_ProfOak_7
	goto_if_eq VAR_RESULT, 1, PalletTown_Interior2_EventScript_ProfOak_8
	msgbox PalletTown_Interior2_Text_ProfOak_6, MSGBOX_AUTOCLOSE
	release
	end

PalletTown_Interior2_EventScript_ProfOak_4::
	textcolor NPC_TEXT_COLOR_MALE
	return

PalletTown_Interior2_EventScript_ProfOak_5::
	copyvar VAR_0x8004, VAR_0x8009
	special GetProfOaksRatingMessage
	waitmessage
	call_if_eq VAR_RESULT, 0, PalletTown_Interior2_EventScript_ProfOak_9
	call_if_eq VAR_RESULT, 1, PalletTown_Interior2_EventScript_ProfOak_10
	waitfanfare
	waitbuttonpress
	return

@ ShinyGold fix: only reached by goto, so the old 'return' ended the script with the text box open and Oak locked
PalletTown_Interior2_EventScript_ProfOak_6::
	special RestoreHelpContext
	closemessage
	release
	end

PalletTown_Interior2_EventScript_ProfOak_7::
	msgbox PalletTown_Interior2_Text_ProfOak_7, MSGBOX_NPC
	goto PalletTown_Interior2_EventScript_ProfOak_6

PalletTown_Interior2_EventScript_ProfOak_8::
	setflag 0x2F4
	msgbox PalletTown_Interior2_Text_ProfOak_8, MSGBOX_NPC
	goto PalletTown_Interior2_EventScript_ProfOak_6

PalletTown_Interior2_EventScript_ProfOak_9::
	playfanfare MUS_DEX_RATING
	return

PalletTown_Interior2_EventScript_ProfOak_10::
	playfanfare MUS_EVOLVED
	return

PalletTown_Interior2_EventScript_Scientist::
	msgbox PalletTown_Interior2_Text_Scientist, MSGBOX_NPC
	end

PalletTown_Interior2_EventScript_Scientist2::
	msgbox PalletTown_Interior2_Text_Scientist2, MSGBOX_NPC
	end

PalletTown_Interior2_EventScript_Scientist3::
	msgbox PalletTown_Interior2_Text_Scientist3, MSGBOX_NPC
	end

PalletTown_Interior2_EventScript_RedNormal::
	msgbox PalletTown_Interior2_Text_RedNormal, MSGBOX_SIGN
	end

PalletTown_Interior2_EventScript_Sign1::
	msgbox PalletTown_Interior2_Text_Sign1, MSGBOX_SIGN
	end

PalletTown_Interior2_EventScript_Sign2::
	msgbox PalletTown_Interior2_Text_Sign2, MSGBOX_SIGN
	end
