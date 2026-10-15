VioletCity_Interior5_MapScripts::
	.byte 0

VioletCity_Interior5_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart VioletCity_Interior5_Items_Clerk
	release
	end

	.align 1
VioletCity_Interior5_Items_Clerk::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_DEFEND
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_SPEED
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_NONE

VioletCity_Interior5_EventScript_OldWoman::
	msgbox VioletCity_Interior5_Text_OldWoman, MSGBOX_NPC
	end

VioletCity_Interior5_EventScript_Youngster::
	msgbox VioletCity_Interior5_Text_Youngster, MSGBOX_NPC
	end

VioletCity_Interior5_EventScript_Youngster2::
	msgbox VioletCity_Interior5_Text_Youngster2, MSGBOX_NPC
	end
