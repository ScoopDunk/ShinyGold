Route17_MapScripts::
	.byte 0

Route17_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER
	end

Route17_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

Route17_EventScript_BikerRiley::
	trainerbattle_single TRAINER_BIKER_RILEY, Route17_Text_BikerRileyIntro, Route17_Text_BikerRileyDefeat
	msgbox Route17_Text_BikerRiley, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_BikerJoel::
	trainerbattle_single TRAINER_BIKER_JOEL, Route17_Text_BikerJoelIntro, Route17_Text_BikerJoelDefeat
	msgbox Route17_Text_BikerJoel, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_BikerGlenn::
	trainerbattle_single TRAINER_BIKER_GLENN, Route17_Text_BikerGlennIntro, Route17_Text_BikerGlennDefeat
	msgbox Route17_Text_BikerGlenn, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_BikerCharles::
	trainerbattle_single TRAINER_BIKER_CHARLES, Route17_Text_BikerCharlesIntro, Route17_Text_BikerCharlesDefeat
	msgbox Route17_Text_BikerCharles, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Trigger::
	special ForcePlayerOntoBike
	setflag FLAG_SYS_ON_CYCLING_ROAD
	release
	end
