SilphCo_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_Interior1_OnTransition
	.byte 0

SilphCo_Interior1_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SILPH_CO_1F
	end

@ Pure Gold/Silver: SILPH CO. 1F as in G/S (pokegold SilphCo1F.asm). The officer's UP-GRADE souvenir is
@ left out: this hack has no UP-GRADE item (the item slot is an APRICORN and PORYGON evolves by level).
SilphCo_Interior1_EventScript_WorkerF::
	msgbox SilphCo_Interior1_Text_WorkerF, MSGBOX_NPC
	end

SilphCo_Interior1_EventScript_Officer::
	msgbox SilphCo_Interior1_Text_Officer, MSGBOX_NPC
	end

SilphCo_Interior1_EventScript_Sign::
	msgbox SilphCo_Interior1_Text_Sign, MSGBOX_AUTOCLOSE
	end
