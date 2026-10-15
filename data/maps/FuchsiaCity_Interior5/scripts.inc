FuchsiaCity_Interior5_MapScripts::
	.byte 0

FuchsiaCity_Interior5_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart FuchsiaCity_Interior5_Items_Clerk
	release
	end

	.align 1
FuchsiaCity_Interior5_Items_Clerk::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_RETRO_MAIL
	.2byte ITEM_NONE

FuchsiaCity_Interior5_EventScript_FatMan::
	msgbox FuchsiaCity_Interior5_Text_FatMan, MSGBOX_NPC
	end

FuchsiaCity_Interior5_EventScript_Picnicker::
	msgbox FuchsiaCity_Interior5_Text_Picnicker, MSGBOX_NPC
	end
