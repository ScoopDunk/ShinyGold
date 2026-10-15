Route8_MapScripts::
	.byte 0

Route8_EventScript_SuperNerdTom::
	trainerbattle_single TRAINER_SUPER_NERD_TOM, Route8_Text_SuperNerdTomIntro, Route8_Text_SuperNerdTomDefeat
	msgbox Route8_Text_SuperNerdTom, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_SuperNerdSam::
	trainerbattle_single TRAINER_SUPER_NERD_SAM, Route8_Text_SuperNerdSamIntro, Route8_Text_SuperNerdSamDefeat
	msgbox Route8_Text_SuperNerdSam, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_BikerDwayne::
	trainerbattle_single TRAINER_BIKER_DWAYNE, Route8_Text_BikerDwayneIntro, Route8_Text_BikerDwayneDefeat
	msgbox Route8_Text_BikerDwayne, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_BikerHarris::
	trainerbattle_single TRAINER_BIKER_HARRIS, Route8_Text_BikerHarrisIntro, Route8_Text_BikerHarrisDefeat
	msgbox Route8_Text_BikerHarris, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_BikerZeke::
	trainerbattle_single TRAINER_BIKER_ZEKE, Route8_Text_BikerZekeIntro, Route8_Text_BikerZekeDefeat
	msgbox Route8_Text_BikerZeke, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Sign2::
	msgbox Route8_Text_Sign2, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Sign3::
	msgbox Route8_Text_Sign3, MSGBOX_AUTOCLOSE
	end
