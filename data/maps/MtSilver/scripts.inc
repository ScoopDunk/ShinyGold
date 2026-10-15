MtSilver_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MtSilver_OnLoad
	.byte 0

MtSilver_OnLoad::
	call_if_set FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE, MtSilver_EventScript_OnLoad_1
	end

MtSilver_EventScript_OnLoad_1::
	setmetatile 24, 24, 0x358, 0
	return

MtSilver_EventScript_Scientist::
	lock
	msgbox MtSilver_Text_Scientist_1
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MtSilver_Text_Scientist_2
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MtSilver_EventScript_Sign::
	msgbox MtSilver_Text_Sign, MSGBOX_SIGN
	end
