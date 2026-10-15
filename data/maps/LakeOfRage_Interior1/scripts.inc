LakeOfRage_Interior1_MapScripts::
	.byte 0

LakeOfRage_Interior1_EventScript_Fisher::
	call_if_unset 0x1103, LakeOfRage_Interior1_EventScript_Fisher_1
	lock
	faceplayer
	special QuestLog_CutRecording
	setvar VAR_0x8004, 129
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	call_if_eq VAR_RESULT, 0, LakeOfRage_Interior1_EventScript_Fisher_2
	special GetHeracrossSizeRecordInfo
	msgbox LakeOfRage_Interior1_Text_Fisher_1, MSGBOX_NPC
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	special CompareMagikarpSize
	call_if_eq VAR_RESULT, 1, LakeOfRage_Interior1_EventScript_Fisher_3
	call_if_eq VAR_RESULT, 2, LakeOfRage_Interior1_EventScript_Fisher_4
	call_if_eq VAR_RESULT, 3, LakeOfRage_Interior1_EventScript_Fisher_5
	call_if_eq VAR_RESULT, 4, LakeOfRage_Interior1_EventScript_Fisher_6
	release
	end

LakeOfRage_Interior1_EventScript_Fisher_1::
	call_if_set 0x10DC, LakeOfRage_Interior1_EventScript_Fisher_7
	msgbox LakeOfRage_Interior1_Text_Fisher_2, MSGBOX_NPC
	setflag 0x10DC
	end

LakeOfRage_Interior1_EventScript_Fisher_2::
	msgbox LakeOfRage_Interior1_Text_Fisher_3, MSGBOX_NPC
	end

LakeOfRage_Interior1_EventScript_Fisher_3::
	msgbox LakeOfRage_Interior1_Text_Fisher_4, MSGBOX_NPC
	end

LakeOfRage_Interior1_EventScript_Fisher_4::
	msgbox LakeOfRage_Interior1_Text_Fisher_5, MSGBOX_NPC
	end

LakeOfRage_Interior1_EventScript_Fisher_5::
	msgbox LakeOfRage_Interior1_Text_Fisher_6, MSGBOX_NPC
	giveitem ITEM_ETHER
	msgbox LakeOfRage_Interior1_Text_Fisher_7, MSGBOX_NPC
	end

LakeOfRage_Interior1_EventScript_Fisher_6::
	msgbox LakeOfRage_Interior1_Text_Fisher_8, MSGBOX_NPC
	end

LakeOfRage_Interior1_EventScript_Fisher_7::
	msgbox LakeOfRage_Interior1_Text_Fisher_9, MSGBOX_NPC
	end

LakeOfRage_Interior1_EventScript_Sign::
	lockall
	goto_if_set 0x2D9, LakeOfRage_Interior1_EventScript_Sign_1
	msgbox LakeOfRage_Interior1_Text_Sign_1
	releaseall
	end

LakeOfRage_Interior1_EventScript_Sign_1::
	special GetHeracrossSizeRecordInfo
	msgbox LakeOfRage_Interior1_Text_Sign_2
	releaseall
	end
