Route15_Interior2_MapScripts::
	.byte 0

Route15_Interior2_EventScript_Sign1::
	lockall
	msgbox Route15_Interior2_Text_Sign1
	showmonpic SPECIES_ARTICUNO, 10, 3
	delay 20
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, 144
	special SetSeenMon
	releaseall
	end

Route15_Interior2_EventScript_Sign2::
	msgbox Route15_Interior2_Text_Sign2, MSGBOX_SIGN
	end
