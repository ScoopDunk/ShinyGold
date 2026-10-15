Unused_G2_M70_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G2_M70_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

Unused_G2_M70_EventScript_Man::
	msgbox Unused_G2_M70_Text_Man, MSGBOX_NPC
	end

Unused_G2_M70_EventScript_Woman3::
	msgbox Unused_G2_M70_Text_Woman3, MSGBOX_NPC
	end

Unused_G2_M70_EventScript_Gentleman::
	msgbox Unused_G2_M70_Text_Gentleman, MSGBOX_NPC
	end
