VermilionCity_Interior8_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

VermilionCity_Interior8_EventScript_Gentleman::
	lock
	faceplayer
	msgbox VermilionCity_Interior8_Text_Gentleman_1, MSGBOX_AUTOCLOSE
	random 5
	switch VAR_RESULT
	call_if_eq VAR_0x8000, 0, VermilionCity_Interior8_EventScript_Gentleman_1
	call_if_eq VAR_0x8000, 1, VermilionCity_Interior8_EventScript_Gentleman_2
	call_if_eq VAR_0x8000, 2, VermilionCity_Interior8_EventScript_Gentleman_3
	call_if_eq VAR_0x8000, 3, VermilionCity_Interior8_EventScript_Gentleman_4
	call_if_eq VAR_0x8000, 4, VermilionCity_Interior8_EventScript_Gentleman_5
	msgbox VermilionCity_Interior8_Text_Gentleman_2, MSGBOX_AUTOCLOSE
	cleartrainerflag TRAINER_YOUNGSTER_DESTIN_2
	cleartrainerflag TRAINER_LASS_KIA
	cleartrainerflag TRAINER_JUGGLER_MASON
	cleartrainerflag TRAINER_PKMN_RANGER_MADELINE
	cleartrainerflag TRAINER_BLACK_BELT_SHEA_2
	cleartrainerflag TRAINER_PSYCHIC_RODETTE_2
	cleartrainerflag TRAINER_SCIENTIST_RYAN
	warp MAP_VERMILION_CITY_INTERIOR9, 0, 255, 255
	waitstate
	release
	end

VermilionCity_Interior8_EventScript_Gentleman_1::
	giveitem ITEM_RARE_CANDY
	return

VermilionCity_Interior8_EventScript_Gentleman_2::
	giveitem ITEM_NUGGET
	return

VermilionCity_Interior8_EventScript_Gentleman_3::
	giveitem ITEM_PP_MAX
	return

VermilionCity_Interior8_EventScript_Gentleman_4::
	giveitem ITEM_MAX_ELIXIR
	return

VermilionCity_Interior8_EventScript_Gentleman_5::
	giveitem ITEM_MAX_REVIVE
	return
