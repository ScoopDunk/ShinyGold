PalletTown_Interior3_MapScripts::
	.byte 0

PalletTown_Interior3_EventScript_Mom::
	lock
	faceplayer
	goto_if_set 0x05E, PalletTown_Interior3_EventScript_Mom_1
	msgbox PalletTown_Interior3_Text_Mom_1, MSGBOX_AUTOCLOSE
	release
	end

PalletTown_Interior3_EventScript_Mom_1::
	msgbox PalletTown_Interior3_Text_Mom_2, MSGBOX_AUTOCLOSE
	release
	end

PalletTown_Interior3_EventScript_Sign1::
	msgbox PalletTown_Interior3_Text_Sign1, MSGBOX_SIGN
	end

PalletTown_Interior3_EventScript_Sign2::
	msgbox PalletTown_Interior3_Text_Sign2, MSGBOX_SIGN
	end
