AzaleaTown_Interior4_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

AzaleaTown_Interior4_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart AzaleaTown_Interior4_Items_Clerk
	release
	end

	.align 1
AzaleaTown_Interior4_Items_Clerk::
	.2byte ITEM_CHARCOAL
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_TROPIC_MAIL
	.2byte ITEM_NONE

AzaleaTown_Interior4_EventScript_CooltrainerM::
	msgbox AzaleaTown_Interior4_Text_CooltrainerM, MSGBOX_NPC
	end

AzaleaTown_Interior4_EventScript_LittleBoy::
	msgbox AzaleaTown_Interior4_Text_LittleBoy, MSGBOX_NPC
	end
