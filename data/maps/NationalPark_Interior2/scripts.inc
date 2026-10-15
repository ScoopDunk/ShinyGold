NationalPark_Interior2_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

NationalPark_Interior2_EventScript_Fisher::
	giveitem ITEM_MASTER_BALL
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_GYARADOS, 50
	waitse
	playmoncry SPECIES_GYARADOS, 0x4800
	copyobjectxytoperm 2074
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	special StartLegendaryBattle
	waitstate
	end

NationalPark_Interior2_EventScript_MgDeliveryman::
	msgbox NationalPark_Interior2_Text_MgDeliveryman, MSGBOX_NPC
	end

NationalPark_Interior2_EventScript_MgDeliveryman2::
	msgbox NationalPark_Interior2_Text_MgDeliveryman2, MSGBOX_NPC
	end
