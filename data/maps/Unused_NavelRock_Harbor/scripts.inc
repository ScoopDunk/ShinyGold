Unused_NavelRock_Harbor_MapScripts::
	.byte 0

Unused_NavelRock_Harbor_EventScript_Sailor::
	lock
	faceplayer
	message Unused_NavelRock_Harbor_Text_Sailor
	waitmessage
	setvar VAR_0x8004, 9
	multichoice 20, 8, MULTICHOICE_SEAGALLOP_VERMILION, 0
	switch VAR_RESULT
	case 0, EventScript_SailToVermilionCity
	case 1, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end
