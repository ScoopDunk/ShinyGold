VioletCity_Interior6_MapScripts::
	.byte 0

VioletCity_Interior6_EventScript_Woman3::
	msgbox VioletCity_Interior6_Text_Woman3, MSGBOX_NPC
	end

VioletCity_Interior6_EventScript_Lass::
	lock
	faceplayer
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 1
	special SetFlavorTextFlagFromSpecialVars
	msgbox VioletCity_Interior6_Text_Lass
	release
	end

VioletCity_Interior6_EventScript_Pidgeot::
	msgbox VioletCity_Interior6_Text_Pidgeot, MSGBOX_NPC
	end
