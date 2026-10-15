Route35_Interior1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Route35_Interior1_EventScript_Fisher::
	msgbox Route35_Interior1_Text_Fisher, MSGBOX_NPC
	end

Route35_Interior1_EventScript_Woman3::
	call_if_set 0x1095, Route35_Interior1_EventScript_Woman3_1
	msgbox Route35_Interior1_Text_Woman3_1, MSGBOX_NPC
	end

Route35_Interior1_EventScript_Woman3_1::
	msgbox Route35_Interior1_Text_Woman3_2, MSGBOX_NPC
	end

Route35_Interior1_EventScript_MgDeliveryman::
	call_if_set 0x10A1, Route35_Interior1_EventScript_MgDeliveryman_1
	call_if_set 0x10A0, Route35_Interior1_EventScript_MgDeliveryman_2
	call_if_set 0x1096, Route35_Interior1_EventScript_MgDeliveryman_3
	msgbox Route35_Interior1_Text_MgDeliveryman_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route35_Interior1_EventScript_MgDeliveryman_4
	msgbox Route35_Interior1_Text_MgDeliveryman_2, MSGBOX_NPC
	end

Route35_Interior1_EventScript_MgDeliveryman_1::
	msgbox Route35_Interior1_Text_MgDeliveryman_3, MSGBOX_NPC
	end

Route35_Interior1_EventScript_MgDeliveryman_2::
	setflag 0x10A1
	msgbox Route35_Interior1_Text_MgDeliveryman_4, MSGBOX_NPC
	giveitem ITEM_HP_UP
	msgbox Route35_Interior1_Text_MgDeliveryman_3, MSGBOX_NPC
	end

Route35_Interior1_EventScript_MgDeliveryman_3::
	msgbox Route35_Interior1_Text_MgDeliveryman_5, MSGBOX_NPC
	end

Route35_Interior1_EventScript_MgDeliveryman_4::
	msgbox Route35_Interior1_Text_MgDeliveryman_6, MSGBOX_NPC
	getpartysize
	call_if_lt VAR_RESULT, 6, Route35_Interior1_EventScript_MgDeliveryman_5
	msgbox Route35_Interior1_Text_MgDeliveryman_7, MSGBOX_NPC
	end

Route35_Interior1_EventScript_MgDeliveryman_5::
	setflag 0x1096
	playfanfare SE_M_NIGHTMARE
	msgbox Route35_Interior1_Text_MgDeliveryman_8, MSGBOX_NPC
	.byte 0x79 @ givemon
	.2byte SPECIES_SPEAROW
	.byte 10
	.2byte ITEM_LETTER
	.4byte 0x2020202
	.4byte 0x2090877
	.byte 2
	end
