Route12_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	.byte 0

Route12_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, Route12_EventScript_OnResume_1
	end

Route12_EventScript_OnResume_1::
	removeobject VAR_LAST_TALKED
	return

Route12_EventScript_FishermanKyle::
	trainerbattle_single TRAINER_FISHERMAN_KYLE, Route12_Text_FishermanKyleIntro, Route12_Text_FishermanKyleDefeat
	msgbox Route12_Text_FishermanKyle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_FishermanMartin::
	trainerbattle_single TRAINER_FISHERMAN_MARTIN, Route12_Text_FishermanMartinIntro, Route12_Text_FishermanMartinDefeat
	msgbox Route12_Text_FishermanMartin, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_FishermanStephen::
	trainerbattle_single TRAINER_FISHERMAN_STEPHEN, Route12_Text_FishermanStephenIntro, Route12_Text_FishermanStephenDefeat
	msgbox Route12_Text_FishermanStephen, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_FishermanBarney::
	trainerbattle_single TRAINER_FISHERMAN_BARNEY, Route12_Text_FishermanBarneyIntro, Route12_Text_FishermanBarneyDefeat
	msgbox Route12_Text_FishermanBarney, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_ItemCalcium::
	finditem ITEM_CALCIUM
	end

Route12_EventScript_ItemNugget::
	finditem ITEM_NUGGET
	end

Route12_EventScript_ItemElixir::
	finditem ITEM_ELIXIR
	end

Route12_EventScript_Sign1::
	msgbox Route12_Text_Sign1, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Sign2::
	msgbox Route12_Text_Sign2, MSGBOX_AUTOCLOSE
	end
