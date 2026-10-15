CeladonCity_Interior3_MapScripts::
	.byte 0

CeladonCity_Interior3_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart CeladonCity_Interior3_Items_Clerk
	release
	end

	.align 1
CeladonCity_Interior3_Items_Clerk::
	.2byte ITEM_TM10
	.2byte ITEM_TM11
	.2byte ITEM_TM17
	.2byte ITEM_TM18
	.2byte ITEM_TM37
	.2byte ITEM_NONE

CeladonCity_Interior3_EventScript_WorkerM::
	msgbox CeladonCity_Interior3_Text_WorkerM, MSGBOX_NPC
	end

CeladonCity_Interior3_EventScript_GbaKid::
	msgbox CeladonCity_Interior3_Text_GbaKid, MSGBOX_NPC
	end

CeladonCity_Interior3_EventScript_GbaKid2::
	msgbox CeladonCity_Interior3_Text_GbaKid2, MSGBOX_NPC
	end

CeladonCity_Interior3_EventScript_Boy::
	msgbox CeladonCity_Interior3_Text_Boy, MSGBOX_NPC
	end

CeladonCity_Interior3_EventScript_Sign1::
	msgbox CeladonCity_Interior3_Text_Sign1, MSGBOX_SIGN
	end

CeladonCity_Interior3_EventScript_Sign2::
	msgbox CeladonCity_Interior3_Text_Sign2, MSGBOX_SIGN
	end

CeladonCity_Interior3_EventScript_Sign3::
	msgbox CeladonCity_Interior3_Text_Sign3, MSGBOX_SIGN
	end

CeladonCity_Interior3_EventScript_Sign4::
	msgbox CeladonCity_Interior3_Text_Sign4, MSGBOX_SIGN
	end

CeladonCity_Interior3_EventScript_Sign5::
	msgbox CeladonCity_Interior3_Text_Sign5, MSGBOX_SIGN
	end

CeladonCity_Interior3_EventScript_Sign6::
	msgbox CeladonCity_Interior3_Text_Sign6, MSGBOX_SIGN
	end

CeladonCity_Interior3_EventScript_Sign10::
	msgbox CeladonCity_Interior3_Text_Sign10, MSGBOX_SIGN
	end
