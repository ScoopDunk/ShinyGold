Route9_MapScripts::
	.byte 0

Route9_EventScript_PicnickerEdna::
	trainerbattle_single TRAINER_PICNICKER_EDNA, Route9_Text_PicnickerEdnaIntro, Route9_Text_PicnickerEdnaDefeat
	msgbox Route9_Text_PicnickerEdna, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_CamperDean::
	trainerbattle_single TRAINER_CAMPER_DEAN, Route9_Text_CamperDeanIntro, Route9_Text_CamperDeanDefeat
	msgbox Route9_Text_CamperDean, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_HikerTim::
	trainerbattle_single TRAINER_HIKER_TIM, Route9_Text_HikerTimIntro, Route9_Text_HikerTimDefeat
	msgbox Route9_Text_HikerTim, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_HikerSidney::
	trainerbattle_single TRAINER_HIKER_SIDNEY, Route9_Text_HikerSidneyIntro, Route9_Text_HikerSidneyDefeat
	msgbox Route9_Text_HikerSidney, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_ItemEther::
	finditem ITEM_ETHER
	end

Route9_EventScript_PicnickerHeidi::
	trainerbattle_single TRAINER_PICNICKER_HEIDI, Route9_Text_PicnickerHeidiIntro, Route9_Text_PicnickerHeidiDefeat
	msgbox Route9_Text_PicnickerHeidi, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_CamperSid::
	trainerbattle_single TRAINER_CAMPER_SID, Route9_Text_CamperSidIntro, Route9_Text_CamperSidDefeat
	msgbox Route9_Text_CamperSid, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sign::
	msgbox Route9_Text_Sign, MSGBOX_AUTOCLOSE
	end
