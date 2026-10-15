VermilionCity_Interior2_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

VermilionCity_Interior2_EventScript_LassKia::
	trainerbattle_single TRAINER_LASS_KIA, VermilionCity_Interior2_Text_LassKiaIntro, VermilionCity_Interior2_Text_LassKiaDefeat
	msgbox VermilionCity_Interior2_Text_LassKia, MSGBOX_AUTOCLOSE
	end
