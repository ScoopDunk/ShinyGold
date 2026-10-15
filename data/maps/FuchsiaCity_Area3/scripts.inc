FuchsiaCity_Area3_MapScripts::
	.byte 0

FuchsiaCity_Area3_EventScript_ItemXSpecial::
	finditem ITEM_X_SPECIAL
	end

FuchsiaCity_Area3_EventScript_ItemThunderStone::
	finditem ITEM_THUNDER_STONE
	end

FuchsiaCity_Area3_EventScript_ItemTwistedSpoon::
	finditem ITEM_TWISTED_SPOON
	end

FuchsiaCity_Area3_EventScript_Boy::
	call_if_set 0x1202, FuchsiaCity_Area3_EventScript_Boy_1
	setflag 0x1202
	msgbox FuchsiaCity_Area3_Text_Boy_1, MSGBOX_NPC
	end

FuchsiaCity_Area3_EventScript_Boy_1::
	msgbox FuchsiaCity_Area3_Text_Boy_2, MSGBOX_NPC
	end

FuchsiaCity_Area3_EventScript_Sign1::
	msgbox FuchsiaCity_Area3_Text_Sign1, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Area3_EventScript_Sign2::
	msgbox FuchsiaCity_Area3_Text_Sign2, MSGBOX_SIGN
	end

FuchsiaCity_Area3_EventScript_Sign3::
	msgbox FuchsiaCity_Area3_Text_Sign3, MSGBOX_AUTOCLOSE
	end
