LakeOfRage_Interior2_MapScripts::
	.byte 0

LakeOfRage_Interior2_EventScript_FatMan::
	call_if_set 0x10DE, LakeOfRage_Interior2_EventScript_FatMan_1
	msgbox LakeOfRage_Interior2_Text_FatMan_1, MSGBOX_NPC
	giveitem ITEM_TM10
	msgbox LakeOfRage_Interior2_Text_FatMan_2, MSGBOX_NPC
	setflag 0x10DE
	end

LakeOfRage_Interior2_EventScript_FatMan_1::
	msgbox LakeOfRage_Interior2_Text_FatMan_3, MSGBOX_NPC
	end
