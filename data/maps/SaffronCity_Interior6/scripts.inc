SaffronCity_Interior6_MapScripts::
	.byte 0

SaffronCity_Interior6_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	.byte 0x96 @ getpokenewsactive (FRLG consumes no argument bytes)
	pokemart SaffronCity_Interior6_Items_Clerk
	release
	end

	.align 1
SaffronCity_Interior6_Items_Clerk::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_FAB_MAIL
	.2byte ITEM_NONE

SaffronCity_Interior6_EventScript_Man::
	msgbox SaffronCity_Interior6_Text_Man, MSGBOX_NPC
	end

SaffronCity_Interior6_EventScript_Lass::
	msgbox SaffronCity_Interior6_Text_Lass, MSGBOX_NPC
	end
