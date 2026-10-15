VermilionCity_Interior15_MapScripts::
	.byte 0

VermilionCity_Interior15_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	.byte 0x96 @ getpokenewsactive (FRLG consumes no argument bytes)
	pokemart VermilionCity_Interior15_Items_Clerk
	release
	end

	.align 1
VermilionCity_Interior15_Items_Clerk::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_WAVE_MAIL
	.2byte ITEM_NONE

VermilionCity_Interior15_EventScript_Rocker::
	msgbox VermilionCity_Interior15_Text_Rocker, MSGBOX_NPC
	end

VermilionCity_Interior15_EventScript_Beauty::
	msgbox VermilionCity_Interior15_Text_Beauty, MSGBOX_NPC
	end
