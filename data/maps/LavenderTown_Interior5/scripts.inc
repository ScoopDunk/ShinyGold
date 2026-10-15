LavenderTown_Interior5_MapScripts::
	.byte 0

LavenderTown_Interior5_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart LavenderTown_Interior5_Items_Clerk
	release
	end

	.align 1
LavenderTown_Interior5_Items_Clerk::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_NONE

LavenderTown_Interior5_EventScript_BaldingMan::
	msgbox LavenderTown_Interior5_Text_BaldingMan, MSGBOX_NPC
	end

LavenderTown_Interior5_EventScript_CooltrainerM::
	msgbox LavenderTown_Interior5_Text_CooltrainerM, MSGBOX_NPC
	end

LavenderTown_Interior5_EventScript_BaldingMan2::
	msgbox LavenderTown_Interior5_Text_BaldingMan2, MSGBOX_NPC
	end
