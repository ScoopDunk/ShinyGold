CeladonCity_Interior4_MapScripts::
	.byte 0

CeladonCity_Interior4_EventScript_Man::
	msgbox CeladonCity_Interior4_Text_Man, MSGBOX_NPC
	end

CeladonCity_Interior4_EventScript_Rocker::
	msgbox CeladonCity_Interior4_Text_Rocker, MSGBOX_NPC
	end

CeladonCity_Interior4_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart CeladonCity_Interior4_Items_Clerk
	release
	end

	.align 1
CeladonCity_Interior4_Items_Clerk::
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_FAB_MAIL
	.2byte ITEM_HARBOR_MAIL
	.2byte ITEM_NONE

CeladonCity_Interior4_EventScript_Sign::
	msgbox CeladonCity_Interior4_Text_Sign, MSGBOX_SIGN
	end
