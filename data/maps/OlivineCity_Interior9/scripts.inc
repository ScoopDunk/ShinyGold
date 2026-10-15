OlivineCity_Interior9_MapScripts::
	.byte 0

OlivineCity_Interior9_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart OlivineCity_Interior9_Items_Clerk
	release
	end

	.align 1
OlivineCity_Interior9_Items_Clerk::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_WAVE_MAIL
	.2byte ITEM_NONE

OlivineCity_Interior9_EventScript_CooltrainerF::
	msgbox OlivineCity_Interior9_Text_CooltrainerF, MSGBOX_NPC
	end

OlivineCity_Interior9_EventScript_Woman2::
	msgbox OlivineCity_Interior9_Text_Woman2, MSGBOX_NPC
	end
