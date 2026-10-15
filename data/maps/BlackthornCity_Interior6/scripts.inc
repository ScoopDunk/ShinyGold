BlackthornCity_Interior6_MapScripts::
	.byte 0

BlackthornCity_Interior6_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart BlackthornCity_Interior6_Items_Clerk
	release
	end

	.align 1
BlackthornCity_Interior6_Items_Clerk::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_DEFEND
	.2byte ITEM_X_ATTACK
	.2byte ITEM_NONE

BlackthornCity_Interior6_EventScript_BlackBelt::
	msgbox BlackthornCity_Interior6_Text_BlackBelt, MSGBOX_NPC
	end

BlackthornCity_Interior6_EventScript_Camper::
	msgbox BlackthornCity_Interior6_Text_Camper, MSGBOX_NPC
	end

BlackthornCity_Interior6_EventScript_Hiker::
	msgbox BlackthornCity_Interior6_Text_Hiker, MSGBOX_NPC
	end
