MtSilver_Interior1_MapScripts::
	.byte 0

MtSilver_Interior1_EventScript_Nurse::
	message MtSilver_Interior1_Text_Nurse_1
	waitmessage
	multichoice 19, 8, MULTICHOICE_YES_NO, 2
	switch VAR_RESULT
	case 0, MtSilver_Interior1_EventScript_Nurse_1
	case 1, MtSilver_Interior1_EventScript_Nurse_2
	case 127, MtSilver_Interior1_EventScript_Nurse_2
	end

MtSilver_Interior1_EventScript_Nurse_1::
	message MtSilver_Interior1_Text_Nurse_2
	waitmessage
	call MtSilver_Interior1_EventScript_Nurse_3
	special SetUsedPkmnCenterQuestLogEvent
	goto MtSilver_Interior1_EventScript_Nurse_4

MtSilver_Interior1_EventScript_Nurse_2::
	msgbox MtSilver_Interior1_Text_Nurse_3, MSGBOX_AUTOCLOSE
	return

MtSilver_Interior1_EventScript_Nurse_3::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	return

MtSilver_Interior1_EventScript_Nurse_4::
	message MtSilver_Interior1_Text_Nurse_4
	waitmessage
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	msgbox MtSilver_Interior1_Text_Nurse_3, MSGBOX_AUTOCLOSE
	return

MtSilver_Interior1_EventScript_OldWoman::
	msgbox MtSilver_Interior1_Text_OldWoman, MSGBOX_NPC
	end

MtSilver_Interior1_EventScript_Trigger1::
	call_if_set 0x11E9, MtSilver_Interior1_EventScript_Trigger1_1
	release
	end

MtSilver_Interior1_EventScript_Trigger1_1::
	callnative SG_NATIVE_0x087FFF71
	clearflag 0x11E9
	release
	end
