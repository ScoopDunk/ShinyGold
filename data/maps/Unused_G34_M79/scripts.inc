Unused_G34_M79_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G34_M79_EventScript_GymSign::
	call_if_unset 0x1221, Unused_G34_M72_EventScript_GymSign_1
	msgbox Unused_G34_M72_Text_GymSign_1, MSGBOX_NPC
	msgbox Unused_G34_M79_Text_GymSign, MSGBOX_NPC
	call Unused_G34_M72_EventScript_GymSign_2
	end

Unused_G34_M79_EventScript_PsychicZahaad::
	trainerbattle_single TRAINER_PSYCHIC_ZAHAAD, Unused_G34_M79_Text_PsychicZahaadIntro, Unused_G34_M79_Text_PsychicZahaadDefeat
	msgbox Unused_G34_M79_Text_PsychicZahaad, MSGBOX_AUTOCLOSE
	end

Unused_G34_M79_EventScript_MediumSarina::
	trainerbattle_single TRAINER_MEDIUM_SARINA, Unused_G34_M79_Text_MediumSarinaIntro, Unused_G34_M79_Text_MediumSarinaDefeat
	msgbox Unused_G34_M79_Text_MediumSarina, MSGBOX_AUTOCLOSE
	end

Unused_G34_M79_EventScript_ItemAguavBerry::
	finditem ITEM_AGUAV_BERRY
	end

Unused_G34_M79_EventScript_ItemHpUp::
	finditem ITEM_HP_UP
	end

Unused_G34_M79_EventScript_Trigger1::
	call_if_set 0x122A, CeruleanCity_EventScript_Trigger6_1
	checkitem ITEM_SILPH_SCOPE
	call_if_eq VAR_RESULT, 1, Unused_G34_M79_EventScript_Trigger1_1
	setwildbattle SPECIES_HAUNTER, 35
	nop
	special StartMarowakBattle
	delay 128
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_Trigger6
	delay 16
	end

Unused_G34_M79_EventScript_Trigger1_1::
	msgbox CeruleanCity_Text_Trigger6, MSGBOX_AUTOCLOSE
	setwildbattle SPECIES_HAUNTER, 35
	special StartSouthernIslandBattle
	setflag 0x122A
	release
	end

Unused_G34_M79_EventScript_Trigger2::
	call_if_set 0x122C, CeruleanCity_EventScript_Trigger6_1
	checkitem ITEM_SILPH_SCOPE
	call_if_eq VAR_RESULT, 1, Unused_G34_M79_EventScript_Trigger2_1
	setwildbattle SPECIES_HAUNTER, 35
	nop
	special StartMarowakBattle
	delay 128
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_Trigger8
	delay 16
	end

Unused_G34_M79_EventScript_Trigger2_1::
	msgbox CeruleanCity_Text_Trigger6, MSGBOX_AUTOCLOSE
	setwildbattle SPECIES_HAUNTER, 35
	special StartSouthernIslandBattle
	setflag 0x122C
	release
	end

Unused_G34_M79_EventScript_Trigger3::
	call_if_set 0x122D, CeruleanCity_EventScript_Trigger6_1
	checkitem ITEM_SILPH_SCOPE
	call_if_eq VAR_RESULT, 1, Unused_G34_M79_EventScript_Trigger3_1
	setwildbattle SPECIES_DUSKULL, 35
	nop
	special StartMarowakBattle
	delay 128
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_Trigger6
	delay 16
	end

Unused_G34_M79_EventScript_Trigger3_1::
	msgbox CeruleanCity_Text_Trigger6, MSGBOX_AUTOCLOSE
	setwildbattle SPECIES_DUSKULL, 35
	special StartSouthernIslandBattle
	setflag 0x122D
	release
	end

Unused_G34_M79_EventScript_Trigger4::
	call_if_set 0x122B, CeruleanCity_EventScript_Trigger6_1
	checkitem ITEM_SILPH_SCOPE
	call_if_eq VAR_RESULT, 1, Unused_G34_M79_EventScript_Trigger4_1
	setwildbattle SPECIES_GENGAR, 35
	nop
	special StartMarowakBattle
	delay 128
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_Trigger6
	delay 16
	end

Unused_G34_M79_EventScript_Trigger4_1::
	msgbox CeruleanCity_Text_Trigger6, MSGBOX_AUTOCLOSE
	setwildbattle SPECIES_GENGAR, 35
	special StartSouthernIslandBattle
	setflag 0x122B
	release
	end

Unused_G34_M79_EventScript_Trigger5::
	call_if_set 0x122F, CeruleanCity_EventScript_Trigger6_1
	checkitem ITEM_SILPH_SCOPE
	call_if_eq VAR_RESULT, 1, Unused_G34_M79_EventScript_Trigger5_1
	setwildbattle SPECIES_GENGAR, 35
	nop
	special StartMarowakBattle
	delay 128
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_Trigger8
	delay 16
	end

Unused_G34_M79_EventScript_Trigger5_1::
	msgbox CeruleanCity_Text_Trigger6, MSGBOX_AUTOCLOSE
	setwildbattle SPECIES_GENGAR, 35
	special StartSouthernIslandBattle
	setflag 0x122F
	release
	end

Unused_G34_M79_EventScript_Trigger6::
	call_if_set 0x122E, CeruleanCity_EventScript_Trigger6_1
	checkitem ITEM_SILPH_SCOPE
	call_if_eq VAR_RESULT, 1, Unused_G34_M79_EventScript_Trigger6_1
	setwildbattle SPECIES_SABLEYE, 35
	nop
	special StartMarowakBattle
	delay 128
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_Trigger6
	delay 16
	end

Unused_G34_M79_EventScript_Trigger6_1::
	msgbox CeruleanCity_Text_Trigger6, MSGBOX_AUTOCLOSE
	setwildbattle SPECIES_SABLEYE, 35
	special StartSouthernIslandBattle
	setflag 0x122E
	release
	end

Unused_G34_M79_EventScript_Sign::
	msgbox Unused_G34_M72_Text_Sign, MSGBOX_NPC
	setflag 0x1221
	release
	end
