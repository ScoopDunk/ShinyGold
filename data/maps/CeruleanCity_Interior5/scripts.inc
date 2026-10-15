CeruleanCity_Interior5_MapScripts::
	.byte 0

CeruleanCity_Interior5_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	.byte 0x96 @ getpokenewsactive (FRLG consumes no argument bytes)
	pokemart CeruleanCity_Interior5_Items_Clerk
	release
	end

	.align 1
CeruleanCity_Interior5_Items_Clerk::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_X_DEFEND
	.2byte ITEM_X_ATTACK
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_WAVE_MAIL
	.2byte ITEM_NONE

CeruleanCity_Interior5_EventScript_CooltrainerF::
	msgbox CeruleanCity_Interior5_Text_CooltrainerF, MSGBOX_NPC
	end

CeruleanCity_Interior5_EventScript_CooltrainerM::
	msgbox CeruleanCity_Interior5_Text_CooltrainerM, MSGBOX_NPC
	end
