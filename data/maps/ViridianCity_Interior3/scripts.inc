ViridianCity_Interior3_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

ViridianCity_Interior3_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart ViridianCity_Interior3_Items_Clerk
	msgbox Text_PleaseComeAgain
	release
	end

	.align 1
ViridianCity_Interior3_Items_Clerk::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_RETRO_MAIL
	.2byte ITEM_NONE

ViridianCity_Interior3_EventScript_Youngster::
	msgbox ViridianCity_Interior3_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_Interior3_EventScript_Woman1::
	msgbox ViridianCity_Interior3_Text_Woman1, MSGBOX_NPC
	end
