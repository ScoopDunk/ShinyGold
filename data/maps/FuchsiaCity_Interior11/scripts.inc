FuchsiaCity_Interior11_MapScripts::
	.byte 0

@ Pure Gold/Silver: the WARDEN is traveling abroad and the SAFARI ZONE is closed (pokegold SafariZoneWardensHome.asm)
FuchsiaCity_Interior11_EventScript_WorkerF::
	goto_if_set FLAG_GOLD_TALKED_TO_WARDENS_GRANDDAUGHTER, FuchsiaCity_Interior11_EventScript_WorkerF_1
	msgbox FuchsiaCity_Interior11_Text_WorkerF, MSGBOX_NPC
	setflag FLAG_GOLD_TALKED_TO_WARDENS_GRANDDAUGHTER
	end

FuchsiaCity_Interior11_EventScript_WorkerF_1::
	msgbox FuchsiaCity_Interior11_Text_WorkerF_2, MSGBOX_NPC
	end

FuchsiaCity_Interior11_EventScript_Sign1::
	msgbox FuchsiaCity_Interior11_Text_Sign1, MSGBOX_SIGN
	end

FuchsiaCity_Interior11_EventScript_Sign2::
	msgbox FuchsiaCity_Interior11_Text_Sign2, MSGBOX_SIGN
	end
