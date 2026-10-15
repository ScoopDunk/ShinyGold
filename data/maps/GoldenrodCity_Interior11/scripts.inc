GoldenrodCity_Interior11_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

GoldenrodCity_Interior11_EventScript_UnusedMaleReceptionist::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart GoldenrodCity_Interior11_Items_UnusedMaleReceptionist
	release
	end

	.align 1
GoldenrodCity_Interior11_Items_UnusedMaleReceptionist::
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE

GoldenrodCity_Interior11_EventScript_GbaKid::
	msgbox GoldenrodCity_Interior11_Text_GbaKid, MSGBOX_NPC
	end

GoldenrodCity_Interior11_EventScript_LittleBoy::
	msgbox GoldenrodCity_Interior11_Text_LittleBoy, MSGBOX_NPC
	end

GoldenrodCity_Interior11_EventScript_WorkerM::
	msgbox GoldenrodCity_Interior11_Text_WorkerM, MSGBOX_NPC
	end

GoldenrodCity_Interior11_EventScript_Trigger::
	setvar VAR_RESULT, 4
	release
	end

GoldenrodCity_Interior11_EventScript_Sign::
	msgbox GoldenrodCity_Interior11_Text_Sign, MSGBOX_AUTOCLOSE
	end
