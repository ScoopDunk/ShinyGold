SSAqua_Interior15_MapScripts::
	.byte 0

SSAqua_Interior15_EventScript_Gentleman::
	lock
	faceplayer
	message SSAqua_Interior15_Text_Gentleman
	waitmessage
	setvar VAR_0x8004, 143
	special SetSeenMon
	showmonpic SPECIES_SNORLAX, 10, 3
	waitbuttonpress
	hidemonpic
	release
	end
