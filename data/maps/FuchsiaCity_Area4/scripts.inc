FuchsiaCity_Area4_MapScripts::
	.byte 0

FuchsiaCity_Area4_EventScript_ItemRevive::
	finditem ITEM_REVIVE
	end

FuchsiaCity_Area4_EventScript_ItemTm33::
	finditem ITEM_TM33
	end

FuchsiaCity_Area4_EventScript_Sign1::
	msgbox FuchsiaCity_Area4_Text_Sign1, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Area4_EventScript_Sign2::
	msgbox FuchsiaCity_Area4_Text_Sign2, MSGBOX_SIGN
	end
