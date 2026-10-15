RuinsOfAlph_Interior1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

RuinsOfAlph_Interior1_EventScript_RedBike::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

RuinsOfAlph_Interior1_EventScript_BaldingMan::
	msgbox RuinsOfAlph_Interior1_Text_BaldingMan, MSGBOX_NPC
	end

RuinsOfAlph_Interior1_EventScript_Camper::
	msgbox RuinsOfAlph_Interior1_Text_Camper, MSGBOX_NPC
	end

RuinsOfAlph_Interior1_EventScript_MgDeliveryman::
	msgbox RuinsOfAlph_Interior1_Text_MgDeliveryman, MSGBOX_NPC
	end
