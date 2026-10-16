Unused_G1_M123_MapScripts::
	@ ShinyGold: unreachable map, emptied (the slot is kept so map ids stay the same)
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
