CeladonCity_Interior5_MapScripts::
	.byte 0

CeladonCity_Interior5_EventScript_Gentleman::
	msgbox CeladonCity_Interior5_Text_Gentleman, MSGBOX_NPC
	end

CeladonCity_Interior5_EventScript_Sailor::
	msgbox CeladonCity_Interior5_Text_Sailor, MSGBOX_NPC
	end

CeladonCity_Interior5_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart CeladonCity_Interior5_Items_Clerk
	release
	end

	.align 1
CeladonCity_Interior5_Items_Clerk::
	.2byte ITEM_HP_UP
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_CALCIUM
	.2byte ITEM_NONE

CeladonCity_Interior5_EventScript_Clerk2::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart CeladonCity_Interior5_Items_Clerk2
	release
	end

	.align 1
CeladonCity_Interior5_Items_Clerk2::
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_NONE

CeladonCity_Interior5_EventScript_Beauty::
	msgbox CeladonCity_Interior5_Text_Beauty, MSGBOX_NPC
	end

CeladonCity_Interior5_EventScript_Sign::
	msgbox CeladonCity_Interior5_Text_Sign, MSGBOX_SIGN
	end
