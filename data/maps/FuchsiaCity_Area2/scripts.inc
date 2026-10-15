FuchsiaCity_Area2_MapScripts::
	.byte 0

FuchsiaCity_Area2_EventScript_ItemHpUp::
	finditem ITEM_HP_UP
	end

FuchsiaCity_Area2_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

FuchsiaCity_Area2_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

FuchsiaCity_Area2_EventScript_Sign1::
	msgbox FuchsiaCity_Area2_Text_Sign1, MSGBOX_SIGN
	end

FuchsiaCity_Area2_EventScript_Sign2::
	msgbox FuchsiaCity_Area2_Text_Sign2, MSGBOX_SIGN
	end

FuchsiaCity_Area2_EventScript_Sign3::
	msgbox FuchsiaCity_Area2_Text_Sign3, MSGBOX_SIGN
	end

FuchsiaCity_Area2_EventScript_Sign4::
	msgbox FuchsiaCity_Area2_Text_Sign4, MSGBOX_AUTOCLOSE
	end
