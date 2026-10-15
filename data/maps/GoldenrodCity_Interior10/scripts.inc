GoldenrodCity_Interior10_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

GoldenrodCity_Interior10_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	contestlinktransfer
	pokemart GoldenrodCity_Interior10_Items_Clerk
	release
	end

	.align 1
GoldenrodCity_Interior10_Items_Clerk::
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_DEFEND
	.2byte ITEM_X_ATTACK
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE

GoldenrodCity_Interior10_EventScript_CooltrainerM::
	msgbox GoldenrodCity_Interior10_Text_CooltrainerM, MSGBOX_NPC
	end

GoldenrodCity_Interior10_EventScript_Rocker::
	msgbox GoldenrodCity_Interior10_Text_Rocker, MSGBOX_NPC
	end

GoldenrodCity_Interior10_EventScript_Trigger::
	setvar VAR_RESULT, 3
	release
	end

GoldenrodCity_Interior10_EventScript_Sign::
	msgbox GoldenrodCity_Interior10_Text_Sign, MSGBOX_AUTOCLOSE
	end
