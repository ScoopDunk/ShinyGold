EcruteakCity_Interior9_MapScripts::
	.byte 0

EcruteakCity_Interior9_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart EcruteakCity_Interior9_Items_Clerk
	release
	end

	.align 1
EcruteakCity_Interior9_Items_Clerk::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_NONE

EcruteakCity_Interior9_EventScript_OldWoman::
	msgbox EcruteakCity_Interior9_Text_OldWoman, MSGBOX_NPC
	end

EcruteakCity_Interior9_EventScript_Rocker::
	msgbox EcruteakCity_Interior9_Text_Rocker, MSGBOX_NPC
	end
