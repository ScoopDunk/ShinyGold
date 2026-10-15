CherrygroveCity_Interior5_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

CherrygroveCity_Interior5_EventScript_Clerk::
	call_if_set 0x1026, CherrygroveCity_Interior5_EventScript_Clerk_1
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart CherrygroveCity_Interior5_Items_Clerk_1
	release
	end

CherrygroveCity_Interior5_EventScript_Clerk_1::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart CherrygroveCity_Interior5_Items_Clerk_2
	release
	end

	.align 1
CherrygroveCity_Interior5_Items_Clerk_1::
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE

	.align 1
CherrygroveCity_Interior5_Items_Clerk_2::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE

CherrygroveCity_Interior5_EventScript_Rocker::
	call_if_set 0x1026, CherrygroveCity_Interior5_EventScript_Rocker_1
	msgbox CherrygroveCity_Interior5_Text_Rocker_1, MSGBOX_NPC
	end

CherrygroveCity_Interior5_EventScript_Rocker_1::
	msgbox CherrygroveCity_Interior5_Text_Rocker_2, MSGBOX_NPC
	end

CherrygroveCity_Interior5_EventScript_Boy::
	msgbox CherrygroveCity_Interior5_Text_Boy, MSGBOX_NPC
	end
