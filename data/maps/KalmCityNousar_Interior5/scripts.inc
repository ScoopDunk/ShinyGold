KalmCityNousar_Interior5_MapScripts::
	.byte 0

KalmCityNousar_Interior5_EventScript_Clerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart KalmCityNousar_Interior5_Items_Clerk
	msgbox Text_PleaseComeAgain
	release
	end

	.align 1
KalmCityNousar_Interior5_Items_Clerk::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE

KalmCityNousar_Interior5_EventScript_Woman2::
	msgbox KalmCityNousar_Interior5_Text_Woman2, MSGBOX_NPC
	end

KalmCityNousar_Interior5_EventScript_Scientist::
	msgbox KalmCityNousar_Interior5_Text_Scientist, MSGBOX_NPC
	end
