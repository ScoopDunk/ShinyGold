GoldenrodCity_Interior9_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

GoldenrodCity_Interior9_EventScript_UnusedMaleReceptionist::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart GoldenrodCity_Interior9_Items_UnusedMaleReceptionist
	release
	end

	.align 1
GoldenrodCity_Interior9_Items_UnusedMaleReceptionist::
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_NONE

GoldenrodCity_Interior9_EventScript_Boy::
	msgbox GoldenrodCity_Interior9_Text_Boy, MSGBOX_NPC
	end

GoldenrodCity_Interior9_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart GoldenrodCity_Interior9_Items_Clerk
	release
	end

	.align 1
GoldenrodCity_Interior9_Items_Clerk::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_FAB_MAIL
	.2byte ITEM_NONE

GoldenrodCity_Interior9_EventScript_Gentleman::
	msgbox GoldenrodCity_Interior9_Text_Gentleman, MSGBOX_NPC
	end

GoldenrodCity_Interior9_EventScript_Lass::
	msgbox GoldenrodCity_Interior9_Text_Lass, MSGBOX_NPC
	end

GoldenrodCity_Interior9_EventScript_Trigger::
	setvar VAR_RESULT, 2
	release
	end

GoldenrodCity_Interior9_EventScript_Sign::
	msgbox GoldenrodCity_Interior9_Text_Sign, MSGBOX_AUTOCLOSE
	end
