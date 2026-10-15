CeladonCity_Interior2_MapScripts::
	.byte 0

CeladonCity_Interior2_EventScript_Youngster::
	msgbox CeladonCity_Interior2_Text_Youngster, MSGBOX_NPC
	end

CeladonCity_Interior2_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart CeladonCity_Interior2_Items_Clerk
	release
	end

	.align 1
CeladonCity_Interior2_Items_Clerk::
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE

CeladonCity_Interior2_EventScript_Clerk2::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart CeladonCity_Interior2_Items_Clerk2
	release
	end

	.align 1
CeladonCity_Interior2_Items_Clerk2::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_NONE

CeladonCity_Interior2_EventScript_BaldingMan::
	msgbox CeladonCity_Interior2_Text_BaldingMan, MSGBOX_NPC
	end

CeladonCity_Interior2_EventScript_Sign::
	msgbox CeladonCity_Interior2_Text_Sign, MSGBOX_SIGN
	end
