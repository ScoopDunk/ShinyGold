CianwoodCity_Interior6_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

CianwoodCity_Interior6_EventScript_Clerk::
	call_if_set 0x10CC, CianwoodCity_Interior6_EventScript_Clerk_1
	call_if_set 0x10C9, CianwoodCity_Interior6_EventScript_Clerk_2
	lock
	faceplayer
	msgbox CianwoodCity_Interior6_Text_Clerk_1, MSGBOX_NPC
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart CianwoodCity_Interior6_Items_Clerk
	msgbox CianwoodCity_Interior6_Text_Clerk_2, MSGBOX_NPC
	release
	end

CianwoodCity_Interior6_EventScript_Clerk_1::
	lock
	faceplayer
	msgbox CianwoodCity_Interior6_Text_Clerk_1, MSGBOX_NPC
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart CianwoodCity_Interior6_Items_Clerk
	msgbox CianwoodCity_Interior6_Text_Clerk_2, MSGBOX_NPC
	release
	end

CianwoodCity_Interior6_EventScript_Clerk_2::
	setflag 0x10CC
	msgbox CianwoodCity_Interior6_Text_Clerk_3, MSGBOX_NPC
	giveitem ITEM_TEA
	msgbox CianwoodCity_Interior6_Text_Clerk_4, MSGBOX_NPC
	end

	.align 1
CianwoodCity_Interior6_Items_Clerk::
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_NONE
