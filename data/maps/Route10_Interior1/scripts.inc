Route10_Interior1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Route10_Interior1_EventScript_Nurse::
	lock
	faceplayer
	message Text_WelcomeWantToHealPkmn
	waitmessage
	multichoice 19, 8, MULTICHOICE_YES_NO, 2
	switch VAR_RESULT
	case 0, Route10_Interior1_EventScript_Nurse_1
	case 1, EventScript_PkmnCenterNurse_Goodbye
	case 127, EventScript_PkmnCenterNurse_Goodbye
	release
	end

Route10_Interior1_EventScript_Nurse_1::
	message Text_TakeYourPkmnForFewSeconds
	waitmessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	message Text_RestoredPkmnToFullHealth
	waitmessage
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	msgbox Text_WeHopeToSeeYouAgain
	release
	end

Route10_Interior1_EventScript_Gentleman::
	msgbox Route10_Interior1_Text_Gentleman, MSGBOX_NPC
	end

Route10_Interior1_EventScript_Lass::
	msgbox Route10_Interior1_Text_Lass, MSGBOX_NPC
	end

Route10_Interior1_EventScript_Scientist::
	call_if_set 0x1185, Route10_Interior1_EventScript_Scientist_1
	msgbox Route10_Interior1_Text_Scientist_1, MSGBOX_NPC
	end

Route10_Interior1_EventScript_Scientist_1::
	msgbox Route10_Interior1_Text_Scientist_2, MSGBOX_NPC
	end
