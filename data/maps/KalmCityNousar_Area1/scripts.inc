KalmCityNousar_Area1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KalmCityNousar_Area1_OnTransition
	.byte 0

KalmCityNousar_Area1_OnTransition::
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
	end

KalmCityNousar_Area1_EventScript_CooltrainerF::
	msgbox KalmCityNousar_Area1_Text_CooltrainerF, MSGBOX_NPC
	end

KalmCityNousar_Area1_EventScript_Man::
	msgbox KalmCityNousar_Area1_Text_Man, MSGBOX_NPC
	end

KalmCityNousar_Area1_EventScript_Rocker::
	msgbox KalmCityNousar_Area1_Text_Rocker, MSGBOX_NPC
	end

KalmCityNousar_Area1_EventScript_Camper::
	msgbox KalmCityNousar_Area1_Text_Camper, MSGBOX_NPC
	end

KalmCityNousar_Area1_EventScript_Beauty::
	msgbox KalmCityNousar_Area1_Text_Beauty, MSGBOX_NPC
	end

KalmCityNousar_Area1_EventScript_FatMan::
	msgbox KalmCityNousar_Area1_Text_FatMan, MSGBOX_NPC
	end

KalmCityNousar_Area1_EventScript_Sign2::
	msgbox KalmCityNousar_Area1_Text_Sign2, MSGBOX_SIGN
	end

KalmCityNousar_Area1_EventScript_Sign3::
	msgbox KalmCityNousar_Area1_Text_Sign3, MSGBOX_SIGN
	end
