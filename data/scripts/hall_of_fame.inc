@ ShinyGold: modified in place by the hack
EventScript_SetDefeatedEliteFourFlagsVars::
	clearflag 0x09D
	call SG_EventScript_SetDefeatedEliteFourFlagsVars_1
	special Script_UpdateTrainerFanClubGameClear
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	call_if_eq VAR_RESULT, 0, EventScript_SetReadyTryGiveNationalDexScene
	call EventScript_ResetLegendaries
	return

EventScript_SetReadyTryGiveNationalDexScene::
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 2
	return

EventScript_ResetLegendaries::
	clearflag FLAG_LUGIA_FLEW_AWAY
	clearflag FLAG_HO_OH_FLEW_AWAY
	clearflag FLAG_DEOXYS_FLEW_AWAY
	return

EventScript_ResetEliteFourEnd::
	call EventScript_ResetEliteFour
	end

EventScript_ResetEliteFour::
	clearflag FLAG_DEFEATED_LORELEI
	clearflag FLAG_DEFEATED_BRUNO
	clearflag FLAG_DEFEATED_AGATHA
	clearflag FLAG_DEFEATED_LANCE
	clearflag FLAG_DEFEATED_CHAMP
	cleartrainerflag TRAINER_ELITETRAINER_LANCE
	cleartrainerflag TRAINER_RIVAL_TERRY_13
	cleartrainerflag TRAINER_RIVAL_TERRY_14
	cleartrainerflag TRAINER_RIVAL_TERRY_15
	cleartrainerflag TRAINER_RIVAL_TERRY_16
	cleartrainerflag TRAINER_RIVAL_TERRY_17
	setvar VAR_MAP_SCENE_POKEMON_LEAGUE, 0
	return
