PewterCity_Interior4_MapScripts::
	.byte 0

PewterCity_Interior4_EventScript_Youngster::
	msgbox PewterCity_Interior4_Text_Youngster, MSGBOX_NPC
	end

PewterCity_Interior4_EventScript_Boy::
	msgbox PewterCity_Interior4_Text_Boy, MSGBOX_NPC
	end

PewterCity_Interior4_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart PewterCity_Interior4_Items_Clerk
	msgbox Text_PleaseComeAgain
	release
	end

	.align 1
PewterCity_Interior4_Items_Clerk::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_NONE
