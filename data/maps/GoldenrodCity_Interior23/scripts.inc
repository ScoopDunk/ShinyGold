GoldenrodCity_Interior23_MapScripts::
	.byte 0

GoldenrodCity_Interior23_EventScript_WorkerF::
	call_if_set 0x10C4, GoldenrodCity_Interior23_EventScript_WorkerF_1
	msgbox GoldenrodCity_Interior23_Text_WorkerF_1, MSGBOX_NPC
	end

GoldenrodCity_Interior23_EventScript_WorkerF_1::
	msgbox GoldenrodCity_Interior23_Text_WorkerF_2, MSGBOX_NPC
	end

GoldenrodCity_Interior23_EventScript_Woman1::
	msgbox GoldenrodCity_Interior23_Text_Woman1, MSGBOX_NPC
	end

GoldenrodCity_Interior23_EventScript_Bill::
	call_if_set 0x10A2, GoldenrodCity_Interior23_EventScript_Bill_1
	faceplayer
	msgbox GoldenrodCity_Interior23_Text_Bill_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, GoldenrodCity_Interior23_EventScript_Bill_2
	msgbox GoldenrodCity_Interior23_Text_Bill_2, MSGBOX_NPC
	end

GoldenrodCity_Interior23_EventScript_Bill_1::
	msgbox GoldenrodCity_Interior23_Text_Bill_3, MSGBOX_NPC
	end

GoldenrodCity_Interior23_EventScript_Bill_2::
	msgbox GoldenrodCity_Interior23_Text_Bill_4, MSGBOX_NPC
	getpartysize
	call_if_lt VAR_RESULT, 6, GoldenrodCity_Interior23_EventScript_Bill_3
	msgbox GoldenrodCity_Interior23_Text_Bill_5, MSGBOX_NPC
	end

GoldenrodCity_Interior23_EventScript_Bill_3::
	setflag 0x10A2
	playfanfare MUS_SLOTS_WIN
	msgbox GoldenrodCity_Interior23_Text_Bill_6, MSGBOX_NPC
	msgbox GoldenrodCity_Interior23_Text_Bill_7, MSGBOX_NPC
	.byte 0x79 @ givemon
	.2byte SPECIES_EEVEE
	.byte 20
	.2byte ITEM_NONE
	.4byte 0xFFFFFF02
	.4byte 0xFFFFFFFF
	.byte 255
	.byte 0xFF @ invalid opcode (script stops)
