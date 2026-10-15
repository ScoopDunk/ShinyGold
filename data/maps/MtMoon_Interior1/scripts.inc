MtMoon_Interior1_MapScripts::
	.byte 0

MtMoon_Interior1_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BICYCLE, MtMoon_Interior1_EventScript_Man_1
	goto_if_set 0x241, MtMoon_Interior1_EventScript_Man_2
	showmoneybox 0, 0
	message MtMoon_Interior1_Text_Man_1
	waitmessage
	multichoice 11, 0, MULTICHOICE_BIKE_SHOP, 0
	switch VAR_RESULT
	case 0, MtMoon_Interior1_EventScript_Man_3
	case 1, MtMoon_Interior1_EventScript_Man_4
	case 127, MtMoon_Interior1_EventScript_Man_4
	end

MtMoon_Interior1_EventScript_Man_1::
	msgbox MtMoon_Interior1_Text_Man_2
	release
	end

MtMoon_Interior1_EventScript_Man_2::
	msgbox MtMoon_Interior1_Text_Man_3
	msgreceiveditem MtMoon_Interior1_Text_Man_4, ITEM_BICYCLE, 1, 0x13E
	setflag FLAG_GOT_BICYCLE
	additem ITEM_BICYCLE
	removeitem ITEM_BIKE_VOUCHER
	msgbox MtMoon_Interior1_Text_Man_5
	release
	end

MtMoon_Interior1_EventScript_Man_3::
	msgbox MtMoon_Interior1_Text_Man_6
	goto MtMoon_Interior1_EventScript_Man_4

MtMoon_Interior1_EventScript_Man_4::
	msgbox MtMoon_Interior1_Text_Man_5
	hidemoneybox
	release
	end

MtMoon_Interior1_EventScript_Lass::
	msgbox MtMoon_Interior1_Text_Lass, MSGBOX_NPC
	end

MtMoon_Interior1_EventScript_OldMan1::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart MtMoon_Interior1_Items_OldMan1
	msgbox Text_PleaseComeAgain
	release
	end

	.align 1
MtMoon_Interior1_Items_OldMan1::
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_SODA_POP
	.2byte ITEM_LEMONADE
	.2byte ITEM_REPEL
	.2byte ITEM_MECH_MAIL
	.2byte ITEM_NONE

MtMoon_Interior1_EventScript_Sign1::
	msgbox MtMoon_Interior1_Text_Sign1, MSGBOX_SIGN
	end
