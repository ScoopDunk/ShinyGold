Unused_G1_M123_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G1_M123_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

Unused_G1_M123_EventScript_GbaKid::
	msgbox Unused_G1_M123_Text_GbaKid, MSGBOX_NPC
	end

Unused_G1_M123_EventScript_BugCatcher::
	msgbox Unused_G1_M123_Text_BugCatcher, MSGBOX_NPC
	end
