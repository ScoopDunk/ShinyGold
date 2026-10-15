Route26_Area1_MapScripts::
	.byte 0

Route26_Area1_EventScript_Clipboard::
	msgbox Route26_Area1_Text_Clipboard_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route26_Area1_EventScript_Clipboard_1
	releaseall
	end

Route26_Area1_EventScript_Clipboard_1::
	msgbox Route26_Area1_Text_Clipboard_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route26_Area1_EventScript_Clipboard_2
	releaseall
	end

Route26_Area1_EventScript_Clipboard_2::
	msgbox Route26_Area1_Text_Clipboard_3, MSGBOX_AUTOCLOSE
	msgbox Route26_Area1_Text_Clipboard_4, MSGBOX_AUTOCLOSE
	msgbox Route26_Area1_Text_Clipboard_5, MSGBOX_AUTOCLOSE
	msgbox Route26_Area1_Text_Clipboard_6, MSGBOX_AUTOCLOSE
	msgbox Route26_Area1_Text_Clipboard_7, MSGBOX_AUTOCLOSE
	msgbox Route26_Area1_Text_Clipboard_8, MSGBOX_AUTOCLOSE
	end
