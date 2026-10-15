	.include "MPlayDef.s"

@ ShinyGold: Now a different battle theme (not identified: no melodic match in GSC or FRLG music).
@ Used through the hack's music-swap scripts (VAR 0x7030/0x7033) in place of
@ MUS_VS_TRAINER / MUS_VS_GYM_LEADER for a few special trainer battles.
@
@ The hack edited this song header in place (keeping the song ID) to point at new track data
@ it inserted at 0x08A07490; voicegroup changed from voicegroup158 to voicegroup011, 10 -> 9 tracks.
@ Disassembled from the hack ROM (no MIDI source exists).  Labels replace the hack's
@ absolute pointers; the byte stream of every track is identical to the hack's.
@ `_mvl` is 127, so `VOL , N*_mvl/mxv` emits N unchanged (edit _mvl to rescale volumes).

	.equ	mus_vs_champion_grp, voicegroup011
	.equ	mus_vs_champion_pri, 0
	.equ	mus_vs_champion_rev, reverb_set+50
	.equ	mus_vs_champion_mvl, 127
	.equ	mus_vs_champion_key, 0
	.equ	mus_vs_champion_tbs, 1
	.equ	mus_vs_champion_exg, 0
	.equ	mus_vs_champion_cmp, 1

	.section .rodata
	.global	mus_vs_champion
	.align	2

@**************** Track 1 ****************@

mus_vs_champion_1:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_vs_champion_key+0
	.byte	TEMPO , 190*mus_vs_champion_tbs/2
	.byte		VOICE , 1
	.byte		PAN   , c_v+13
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 87*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W84
	.byte		N08   , Bn3 , v127
	.byte	W08
	.byte		        Fn4
	.byte	W04
@ 001   ----------------------------------------
	.byte	W04
	.byte		        Bn4
	.byte	W08
	.byte		VOL   , 59*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v+32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N24   , Dn5
	.byte	W24
	.byte		PAN   , c_v-16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N24   , Cs5
	.byte	W24
	.byte		PAN   , c_v+32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N24   , Cn5
	.byte	W24
	.byte		PAN   , c_v-16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N24   , Bn4
	.byte	W12
@ 002   ----------------------------------------
	.byte	W12
	.byte		PAN   , c_v+32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N24   , As4
	.byte	W24
	.byte		PAN   , c_v-16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N24   , An4
	.byte	W24
	.byte		PAN   , c_v+32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N24   , Gs4
	.byte	W24
	.byte		VOICE , 56
	.byte		VOL   , 90*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v+12
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , En4
	.byte	W06
	.byte		        Fn4
	.byte	W06
@ 003   ----------------------------------------
	.byte		        En4
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		VOL   , 90*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v+16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N06   , An4
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        An4 , v084
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        An4 , v044
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        An4 , v020
	.byte	W12
@ 004   ----------------------------------------
mus_vs_champion_1_B1:
	.byte		        An3
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W12
	.byte		VOL   , 79*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N02   , An4 , v116
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N03   , En4 , v127
	.byte	W06
	.byte		        Fn4
	.byte	W06
@ 007   ----------------------------------------
	.byte		        En4
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		N06   , An4
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        An4 , v084
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        An4 , v044
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        An4 , v020
	.byte	W12
@ 008   ----------------------------------------
	.byte		        An3
	.byte	W96
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W12
	.byte		N02   , Gs4 , v116
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N03   , Gs4 , v127
	.byte	W06
	.byte		        An4
	.byte	W06
@ 011   ----------------------------------------
	.byte		        Gs4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		N06   , Bn4
	.byte	W12
	.byte		        Bn3
	.byte	W12
	.byte		        Bn4 , v084
	.byte	W12
	.byte		        Bn3
	.byte	W12
	.byte		        Bn4 , v044
	.byte	W12
	.byte		        Bn3
	.byte	W12
	.byte		        Bn4 , v020
	.byte	W12
@ 012   ----------------------------------------
	.byte		        Bn3
	.byte	W96
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
	.byte	W96
@ 019   ----------------------------------------
	.byte	W96
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W96
@ 022   ----------------------------------------
	.byte	W96
@ 023   ----------------------------------------
	.byte	W96
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W84
	.byte		VOL   , 68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v-16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W12
@ 033   ----------------------------------------
	.byte		VOICE , 1
	.byte		N06   , En4 , v127
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		N12   , Gs4
	.byte	W12
	.byte		        Cs4
	.byte	W22
	.byte		PAN   , c_v+4
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W02
	.byte		N32   , Cs5
	.byte	W36
	.byte		PAN   , c_v+24
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N24   , En5
	.byte	W12
@ 034   ----------------------------------------
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		VOICE , 48
	.byte		N06   , En4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		N24   , Gs4
	.byte	W12
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , Fs4
	.byte	W12
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , En4
	.byte	W12
@ 035   ----------------------------------------
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Ds4
	.byte	W12
	.byte		        En4
	.byte	W12
	.byte		        Ds4
	.byte	W12
	.byte		        Cs4
	.byte	W12
	.byte		N44   , Ds4
	.byte	W12
	.byte		VOL   , 65*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        64*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        58*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        53*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        50*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        47*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 036   ----------------------------------------
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        38*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W72
	.byte		        68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v-12
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W12
@ 037   ----------------------------------------
	.byte		VOICE , 1
	.byte		N06   
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		N12   , Fs4
	.byte	W12
	.byte		        Bn3
	.byte	W22
	.byte		PAN   , c_v+6
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W02
	.byte		N32   , Bn4
	.byte	W36
	.byte		PAN   , c_v+16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N24   , Ds5
	.byte	W12
@ 038   ----------------------------------------
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		VOICE , 48
	.byte		N06   , Ds4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		N24   , Fs4
	.byte	W12
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , Bn4
	.byte	W12
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , An4
	.byte	W12
@ 039   ----------------------------------------
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Gs4
	.byte	W12
	.byte		        An4
	.byte	W12
	.byte		        Gs4
	.byte	W12
	.byte		        Fs4
	.byte	W12
	.byte		N44   , Gs4
	.byte	W12
	.byte		VOL   , 64*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        57*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        55*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        53*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        49*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        44*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 040   ----------------------------------------
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        38*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        31*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W72
	.byte		        90*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
@ 041   ----------------------------------------
	.byte		VOICE , 56
	.byte		N06   
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		N12   , Cs5
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
@ 042   ----------------------------------------
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , En5
	.byte	W24
	.byte		        Ds5
	.byte	W12
@ 043   ----------------------------------------
	.byte	W12
	.byte		VOICE , 48
	.byte		VOL   , 54*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N44   , Dn5
	.byte	W48
	.byte		        Cs5
	.byte	W36
@ 044   ----------------------------------------
	.byte	W12
	.byte		        Cn5
	.byte	W48
	.byte		        Bn4
	.byte	W36
@ 045   ----------------------------------------
	.byte	W12
	.byte		N24   , Dn5
	.byte	W24
	.byte		        Cs5
	.byte	W24
	.byte		        Cn5
	.byte	W24
	.byte		        Bn4
	.byte	W12
@ 046   ----------------------------------------
	.byte	W12
	.byte		N06   , Dn5
	.byte	W06
	.byte		        Cs5
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        As4
	.byte	W06
	.byte		        An4
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		        Cs4
	.byte	W06
@ 047   ----------------------------------------
	.byte		        Bn3
	.byte	W06
	.byte		        Gn3
	.byte	W90
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W84
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		N06   , An4
	.byte	W06
@ 060   ----------------------------------------
	.byte		        Bn4
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		PAN   , c_v-1
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N06   , En5
	.byte	W18
	.byte		N03   , An4
	.byte	W06
	.byte		N68   
	.byte	W24
	.byte		VOL   , 53*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        52*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        51*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        49*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        47*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        38*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        38*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 061   ----------------------------------------
	.byte		        32*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        30*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , En5
	.byte	W24
	.byte		        Dn5
	.byte	W24
	.byte		        Cn5
	.byte	W24
	.byte		        Dn5
	.byte	W12
@ 062   ----------------------------------------
	.byte	W12
	.byte		N06   , Bn4
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        An4
	.byte	W06
	.byte		N68   , Bn4
	.byte	W24
	.byte		VOL   , 53*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        53*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        51*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        50*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        49*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        46*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        44*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        42*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        38*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 063   ----------------------------------------
	.byte		        30*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        28*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        25*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W78
	.byte		N06   , Gn4
	.byte	W06
@ 064   ----------------------------------------
	.byte		        An4
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        Dn5
	.byte	W18
	.byte		N03   , Gn4
	.byte	W06
	.byte		N68   
	.byte	W24
	.byte		VOL   , 52*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        49*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        39*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        38*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        36*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        32*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        30*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 065   ----------------------------------------
	.byte		        27*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        21*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        19*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , Bn4
	.byte	W24
	.byte		        Gn4
	.byte	W24
	.byte		        Gn5
	.byte	W24
	.byte		        Fn5
	.byte	W12
@ 066   ----------------------------------------
	.byte	W12
	.byte		N06   , En5
	.byte	W06
	.byte		        Fn5
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		        Dn5
	.byte	W06
	.byte		N44   , En5
	.byte	W24
	.byte		VOL   , 50*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        47*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        36*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        31*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        25*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
@ 067   ----------------------------------------
	.byte	W84
	.byte		N08   , An4
	.byte	W08
	.byte		        Bn4
	.byte	W04
@ 068   ----------------------------------------
	.byte	W04
	.byte		        Cn5
	.byte	W08
	.byte		N06   , En5
	.byte	W18
	.byte		N03   , An4
	.byte	W06
	.byte		N68   
	.byte	W60
@ 069   ----------------------------------------
	.byte	W12
	.byte		PAN   , c_v-22
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Fn3
	.byte	W12
	.byte		        Cn3
	.byte	W24
	.byte		        Fn3
	.byte	W24
	.byte		        An3
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , An4
	.byte	W08
	.byte		        Bn4
	.byte	W04
@ 070   ----------------------------------------
	.byte	W04
	.byte		        Cn5
	.byte	W08
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N06   , En5
	.byte	W18
	.byte		N03   , An4
	.byte	W06
	.byte		N68   
	.byte	W60
@ 071   ----------------------------------------
	.byte	W12
	.byte		PAN   , c_v-22
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Fs3
	.byte	W12
	.byte		        Cn3
	.byte	W24
	.byte		        Fs3
	.byte	W24
	.byte		        An3
	.byte	W24
@ 072   ----------------------------------------
	.byte		        Cn4
	.byte	W12
	.byte		PAN   , c_v-1
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W84
@ 073   ----------------------------------------
	.byte	W84
	.byte		VOL   , 90*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v+13
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , En4
	.byte	W06
	.byte		        Fn4
	.byte	W06
@ 074   ----------------------------------------
	.byte		        En4
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 90*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v+16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N06   , An4
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        An4 , v084
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        An4 , v044
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        An4 , v020
	.byte	W12
@ 075   ----------------------------------------
	.byte	GOTO
	 .word	mus_vs_champion_1_B1
	.byte	W06
	.byte	FINE

@**************** Track 2 ****************@

mus_vs_champion_2:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_vs_champion_key+0
	.byte		VOICE , 56
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 80*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W84
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Gs3 , v127
	.byte	W06
	.byte		        An3
	.byte	W06
@ 003   ----------------------------------------
	.byte		        Gs3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		VOL   , 80*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N06   , En4
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        En4 , v084
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        En4 , v044
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        En4 , v020
	.byte	W12
@ 004   ----------------------------------------
mus_vs_champion_2_B1:
	.byte		        En3
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W84
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W12
	.byte		        c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 80*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N02   , En4 , v116
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N03   , Gs3 , v127
	.byte	W06
	.byte		        An3
	.byte	W06
@ 007   ----------------------------------------
	.byte		        Gs3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		N06   , En4
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N06   , En4 , v084
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        En4 , v044
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        En4 , v020
	.byte	W12
@ 008   ----------------------------------------
	.byte		        En3
	.byte	W96
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W12
	.byte		N02   , En4 , v116
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N03   , En4 , v127
	.byte	W06
	.byte		        Fn4
	.byte	W06
@ 011   ----------------------------------------
	.byte		        En4
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		N06   , Gs4
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Gs4 , v084
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Gs4 , v044
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Gs4 , v020
	.byte	W12
@ 012   ----------------------------------------
	.byte		        Gs3
	.byte	W96
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W12
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N04   , Bn3 , v127
	.byte	W04
	.byte		        Ds4
	.byte	W04
	.byte		        Fs4
	.byte	W04
	.byte		        An4
	.byte	W04
	.byte		        Bn4
	.byte	W04
	.byte		        Cs5
	.byte	W04
	.byte		        Ds5
	.byte	W04
	.byte		        Fs5
	.byte	W04
	.byte		        An5
	.byte	W04
	.byte		        Bn5
	.byte	W03
	.byte		PAN   , c_v+16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W01
	.byte		N04   , Cs6
	.byte	W04
	.byte		        Ds6
	.byte	W04
	.byte		PAN   , c_v+31
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N04   , Fs6
	.byte	W04
	.byte		        Ds6
	.byte	W04
	.byte		        Cs6
	.byte	W04
	.byte		        Bn5
	.byte	W04
	.byte		        An5
	.byte	W04
	.byte		        Fs5
	.byte	W04
	.byte		PAN   , c_v-16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N04   , Ds5
	.byte	W04
	.byte		        Cs5
	.byte	W04
	.byte		        Bn4
	.byte	W04
@ 015   ----------------------------------------
	.byte		PAN   , c_v-23
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N04   , An4
	.byte	W04
	.byte		        Fs4
	.byte	W04
	.byte		        Ds4
	.byte	W04
	.byte		VOL   , 59*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v+4
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W12
	.byte		VOICE , 48
	.byte		N32   , En4
	.byte	W24
	.byte		VOL   , 49*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        25*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W01
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
	.byte		        60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Fs4
	.byte	W24
	.byte		        Gs4
	.byte	W12
@ 016   ----------------------------------------
	.byte	W12
	.byte		        An4
	.byte	W12
	.byte		N32   , Gs4
	.byte	W24
	.byte		VOL   , 49*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        25*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W01
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
	.byte		        60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , An4
	.byte	W24
	.byte		N24   , Bn4
	.byte	W12
@ 017   ----------------------------------------
	.byte	W12
	.byte		N92   , Gs4
	.byte	W48
	.byte		VOL   , 55*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        53*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        37*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        36*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        31*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 018   ----------------------------------------
	.byte		        30*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        21*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N92   , En4
	.byte	W48
	.byte		VOL   , 55*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        53*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        37*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        36*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        31*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 019   ----------------------------------------
	.byte		        30*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        21*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		N32   
	.byte	W24
	.byte		VOL   , 48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        35*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        27*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W01
	.byte		        20*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
	.byte		        60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Fs4
	.byte	W24
	.byte		N24   , Gs4
	.byte	W12
@ 020   ----------------------------------------
	.byte	W12
	.byte		N12   , An4
	.byte	W12
	.byte		N24   , Gs4
	.byte	W24
	.byte		N12   , An4
	.byte	W24
	.byte		N32   , Bn4
	.byte	W24
@ 021   ----------------------------------------
	.byte		VOL   , 48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        37*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        30*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        25*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		VOICE , 60
	.byte		PAN   , c_v+7
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En4
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 022   ----------------------------------------
	.byte	W24
	.byte		N32   , Bn3
	.byte	W24
	.byte		VOL   , 60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        53*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        35*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W01
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
	.byte		        68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En4
	.byte	W24
	.byte		        Bn3
	.byte	W12
@ 023   ----------------------------------------
	.byte	W12
	.byte		        En4
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 024   ----------------------------------------
	.byte	W24
	.byte		N32   , Bn3
	.byte	W24
	.byte		VOL   , 60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        53*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        35*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W01
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
	.byte		        68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En4
	.byte	W24
	.byte		        Fs4
	.byte	W12
@ 025   ----------------------------------------
	.byte	W12
	.byte		        En4
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		        Ds4
	.byte	W12
@ 026   ----------------------------------------
	.byte		        Cs4
	.byte	W24
	.byte		N32   , Ds4
	.byte	W24
	.byte		VOL   , 60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        53*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        35*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W01
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
	.byte		        68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En4
	.byte	W24
	.byte		N24   , Fs4
	.byte	W12
@ 027   ----------------------------------------
	.byte	W12
	.byte		N92   , Gs4
	.byte	W48
	.byte		VOL   , 60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        58*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        55*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        54*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        53*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        50*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        46*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        38*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        31*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 028   ----------------------------------------
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        19*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        14*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W72
	.byte		        59*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v-25
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W12
@ 029   ----------------------------------------
	.byte		N06   , An2
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		N12   , Cs3
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 030   ----------------------------------------
mus_vs_champion_2_030:
	.byte	W24
	.byte		N12   , Cs3 , v127
	.byte	W36
	.byte		        Bn2
	.byte	W24
	.byte		N24   , Dn3
	.byte	W12
	.byte	PEND
@ 031   ----------------------------------------
mus_vs_champion_2_031:
	.byte	W12
	.byte		N12   , Cs3 , v127
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 032   ----------------------------------------
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		        Dn3
	.byte	W24
	.byte		N24   , Bn2
	.byte	W12
@ 033   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_2_031
	.byte	PATT
	 .word	mus_vs_champion_2_030
mus_vs_champion_2_033:
	.byte	W12
	.byte		N12   , Bn2 , v127
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 034   ----------------------------------------
	.byte	W24
	.byte		N32   , Fs2
	.byte	W36
	.byte		N24   , Bn2
	.byte	W24
	.byte		        Ds3
	.byte	W12
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_2_033
	.byte	W12
	.byte		N12   , Bn2 , v127
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   , Cn3
	.byte	W12
@ 036   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_2_031
	.byte	W24
	.byte		N12   , Cs3 , v127
	.byte	W36
	.byte		N24   , Dn3
	.byte	W24
	.byte		        Bn2
	.byte	W12
@ 037   ----------------------------------------
	.byte	W12
	.byte		N12   , Gs4
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
@ 038   ----------------------------------------
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , An4
	.byte	W24
	.byte		        Gs4
	.byte	W12
@ 039   ----------------------------------------
	.byte	W96
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W12
	.byte		PAN   , c_v+4
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 59*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		VOICE , 48
	.byte		N32   , Cn4
	.byte	W24
	.byte		VOL   , 49*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        25*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W01
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
	.byte		        60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Dn4
	.byte	W24
	.byte		        En4
	.byte	W12
@ 044   ----------------------------------------
	.byte	W12
	.byte		        Fn4
	.byte	W12
	.byte		N32   , En4
	.byte	W24
	.byte		VOL   , 49*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        25*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W01
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
	.byte		        60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Fn4
	.byte	W24
	.byte		N24   , Gn4
	.byte	W12
@ 045   ----------------------------------------
	.byte	W12
	.byte		N92   , En4
	.byte	W48
	.byte		VOL   , 55*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        53*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        37*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        36*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        31*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 046   ----------------------------------------
	.byte		        30*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        21*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N92   , Cn4
	.byte	W48
	.byte		VOL   , 55*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        53*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        37*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        36*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        31*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 047   ----------------------------------------
	.byte		        30*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        21*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		N32   
	.byte	W24
	.byte		VOL   , 48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        35*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        27*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W01
	.byte		        20*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
	.byte		        60*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Dn4
	.byte	W24
	.byte		N24   , En4
	.byte	W12
@ 048   ----------------------------------------
	.byte	W12
	.byte		N12   , Fn4
	.byte	W12
	.byte		N24   , En4
	.byte	W24
	.byte		N12   , Fn4
	.byte	W24
	.byte		N32   , Gn4
	.byte	W24
@ 049   ----------------------------------------
	.byte		VOL   , 48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        37*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        30*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        25*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		VOICE , 60
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn5
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 050   ----------------------------------------
	.byte	W24
	.byte		N32   , Gn4
	.byte	W24
	.byte		VOL   , 47*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        38*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        27*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        20*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn5
	.byte	W24
	.byte		        Gn4
	.byte	W12
@ 051   ----------------------------------------
	.byte	W12
	.byte		        Cn5
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 052   ----------------------------------------
	.byte	W24
	.byte		N32   , Gn4
	.byte	W24
	.byte		VOL   , 47*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        38*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        27*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        20*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn5
	.byte	W24
	.byte		        Dn5
	.byte	W12
@ 053   ----------------------------------------
	.byte	W12
	.byte		        Cn5
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		        Bn4
	.byte	W12
@ 054   ----------------------------------------
	.byte		        An4
	.byte	W24
	.byte		N32   , Bn4
	.byte	W24
	.byte		VOL   , 47*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        38*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        27*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        20*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn5
	.byte	W24
	.byte		N92   , Dn5
	.byte	W12
@ 055   ----------------------------------------
	.byte	W36
	.byte		VOL   , 53*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        51*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        49*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        47*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        39*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        38*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        32*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        29*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        25*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        21*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        19*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        15*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
@ 056   ----------------------------------------
mus_vs_champion_2_056:
	.byte	W12
	.byte		PAN   , c_v+32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W84
	.byte	PEND
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W60
	.byte		N06   , Gn3 , v120
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Fs3
	.byte	W06
	.byte		N44   , Gn3
	.byte	W12
@ 059   ----------------------------------------
	.byte	W48
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N44   
	.byte	W36
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_2_056
	.byte	W96
@ 061   ----------------------------------------
	.byte	W84
	.byte		N04   , An4 , v116
	.byte	W08
	.byte		N04   
	.byte	W04
@ 062   ----------------------------------------
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W32
	.byte		N04   , Gn4
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N44   
	.byte	W24
	.byte		VOL   , 51*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        46*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 063   ----------------------------------------
	.byte		        36*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        30*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W84
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte	W12
	.byte		VOICE , 1
	.byte		PAN   , c_v-30
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 63*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N08   , Bn3 , v112
	.byte	W08
	.byte		        Fn4
	.byte	W08
	.byte		        Bn4
	.byte	W08
	.byte		PAN   , c_v+16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , As3
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        As4
	.byte	W08
	.byte		PAN   , c_v-28
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , An3
	.byte	W08
	.byte		        Ds4
	.byte	W08
	.byte		        An4
	.byte	W08
	.byte		PAN   , c_v+16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , Gs3
	.byte	W08
	.byte		        Dn4
	.byte	W04
@ 068   ----------------------------------------
	.byte	W04
	.byte		        Gs4
	.byte	W08
	.byte		PAN   , c_v-30
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , Gn3
	.byte	W08
	.byte		        Cs4
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		PAN   , c_v+16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , Fs3
	.byte	W08
	.byte		        Cn4
	.byte	W08
	.byte		        Fs4
	.byte	W08
	.byte		PAN   , c_v-27
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , Fn3
	.byte	W08
	.byte		        Bn3
	.byte	W08
	.byte		        Fn4
	.byte	W08
	.byte		VOICE , 56
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 78*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N03   , Gs3 , v127
	.byte	W06
	.byte		        An3
	.byte	W06
@ 069   ----------------------------------------
	.byte		        Gs3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		VOL   , 80*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N06   , En4
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        En4 , v084
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        En4 , v044
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        En4 , v020
	.byte	W12
@ 070   ----------------------------------------
	.byte	GOTO
	 .word	mus_vs_champion_2_B1
	.byte	W06
	.byte	FINE

@**************** Track 3 ****************@

mus_vs_champion_3:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_vs_champion_key+0
	.byte		VOICE , 33
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 90*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , Fs1 , v056
	.byte	W08
	.byte		        Cn2
	.byte	W08
	.byte		        Fs2
	.byte	W08
	.byte		        Fn1
	.byte	W08
	.byte		        Bn1
	.byte	W08
	.byte		        Fn2
	.byte	W08
	.byte		        En1
	.byte	W08
	.byte		        As1
	.byte	W08
	.byte		        En2
	.byte	W08
	.byte		        Ds1
	.byte	W08
	.byte		        An1
	.byte	W04
@ 002   ----------------------------------------
	.byte	W04
	.byte		        Ds2
	.byte	W08
	.byte		        Dn1
	.byte	W08
	.byte		        Gs1
	.byte	W08
	.byte		        Dn2
	.byte	W08
	.byte		        Cs1
	.byte	W08
	.byte		        Gn1
	.byte	W08
	.byte		        Cs2
	.byte	W08
	.byte		        Cn1
	.byte	W08
	.byte		        Fs1
	.byte	W08
	.byte		        Cn2
	.byte	W08
	.byte		PAN   , c_v-1
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N06   , Bn1 , v068
	.byte	W06
	.byte		        Cn2
	.byte	W06
@ 003   ----------------------------------------
	.byte		        Bn1
	.byte	W06
	.byte		        As1
	.byte	W06
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 90*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N06   , An1 , v076
	.byte	W12
	.byte		        An1 , v068
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		        An1 , v068
	.byte	W12
	.byte		N06   
	.byte	W12
@ 004   ----------------------------------------
mus_vs_champion_3_B1:
	.byte		N06   
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		        An1 , v068
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		N12   , Bn1 , v068
	.byte	W12
	.byte		N06   , Ds2
	.byte	W06
	.byte		        Dn2
	.byte	W06
@ 005   ----------------------------------------
	.byte		N12   , Cn2
	.byte	W12
	.byte		N06   , An1 , v076
	.byte	W12
	.byte		        An1 , v068
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		        An1 , v068
	.byte	W12
	.byte		N06   
	.byte	W12
@ 006   ----------------------------------------
mus_vs_champion_3_006:
	.byte		N06   , An1 , v068
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		N12   , Dn2
	.byte	W12
	.byte		N06   , Ds2
	.byte	W06
	.byte		        Dn2
	.byte	W06
	.byte	PEND
@ 007   ----------------------------------------
	.byte		N12   , As1
	.byte	W24
	.byte		N06   , An1
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
@ 008   ----------------------------------------
	.byte		N06   
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		        An1 , v068
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Bn1
	.byte	W12
	.byte		N06   , Ds2
	.byte	W06
	.byte		        Dn2
	.byte	W06
@ 009   ----------------------------------------
	.byte		N12   , Cn2
	.byte	W12
	.byte		N06   , An1 , v076
	.byte	W12
	.byte		        An1 , v068
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_3_006
	.byte		N12   , As1 , v068
	.byte	W12
	.byte		N08   , En1 , v076
	.byte	W12
	.byte		        En1 , v068
	.byte	W12
	.byte		N24   , En2
	.byte	W24
	.byte		N08   , En1 , v076
	.byte	W12
	.byte		        En1 , v068
	.byte	W12
	.byte		N24   , Fn2
	.byte	W12
@ 011   ----------------------------------------
	.byte	W12
	.byte		N08   , En1 , v076
	.byte	W12
	.byte		        En1 , v068
	.byte	W12
	.byte		N24   , Fs2
	.byte	W24
	.byte		N08   , En1 , v076
	.byte	W12
	.byte		        En1 , v068
	.byte	W12
	.byte		N24   , Gn2 , v076
	.byte	W12
@ 012   ----------------------------------------
	.byte	W12
	.byte		N06   , En1
	.byte	W12
	.byte		N12   , En2 , v068
	.byte	W12
	.byte		N06   , En1
	.byte	W12
	.byte		N12   , Fn2
	.byte	W12
	.byte		N06   , En1 , v076
	.byte	W12
	.byte		N12   , Fs2 , v068
	.byte	W12
	.byte		N06   , En1
	.byte	W12
@ 013   ----------------------------------------
	.byte		N12   , Gn2
	.byte	W12
	.byte		N06   , En1
	.byte	W12
	.byte		N12   , Gs2
	.byte	W12
	.byte		N06   , En1
	.byte	W12
	.byte		N12   , An2
	.byte	W12
	.byte		N06   , En1
	.byte	W12
	.byte		N12   , As2
	.byte	W12
	.byte		N06   , En1
	.byte	W12
@ 014   ----------------------------------------
	.byte		N12   , Bn2
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En1
	.byte	W12
	.byte		        En2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En1
	.byte	W12
	.byte		        En2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En1
	.byte	W12
	.byte		        En2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En1
	.byte	W12
@ 015   ----------------------------------------
mus_vs_champion_3_015:
	.byte		N06   , En2 , v068
	.byte	W06
	.byte		        Ds2
	.byte	W06
	.byte		N12   , En2
	.byte	W12
	.byte		N06   , En1
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   
	.byte	W12
	.byte		        En2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Bn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		N06   , En2
	.byte	W06
	.byte		        Bn1
	.byte	W06
	.byte	PEND
@ 016   ----------------------------------------
mus_vs_champion_3_016:
	.byte		N06   , Gs1 , v068
	.byte	W06
	.byte		        Fs1
	.byte	W06
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En1
	.byte	W12
	.byte		        En2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En1
	.byte	W12
	.byte		        En2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En1
	.byte	W12
	.byte		        En2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En1
	.byte	W12
	.byte	PEND
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_3_015
	.byte	PATT
	 .word	mus_vs_champion_3_016
	.byte	PATT
	 .word	mus_vs_champion_3_015
	.byte		N06   , Gs1 , v068
	.byte	W06
	.byte		        Fs1
	.byte	W06
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Dn1
	.byte	W12
	.byte		        Dn2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Dn1
	.byte	W12
	.byte		        Dn2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Dn1
	.byte	W12
	.byte		        Dn2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Dn1
	.byte	W12
@ 018   ----------------------------------------
	.byte		N06   , Dn2
	.byte	W06
	.byte		        Cs2
	.byte	W06
	.byte		N12   , Dn2
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   
	.byte	W12
	.byte		        Dn2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , An1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		N06   , Dn2
	.byte	W06
	.byte		        An1
	.byte	W06
@ 019   ----------------------------------------
	.byte		        Fs1
	.byte	W06
	.byte		        En1
	.byte	W06
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Cs2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Cs2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Cs2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
@ 020   ----------------------------------------
	.byte		N06   , Cs2
	.byte	W06
	.byte		        Cn2
	.byte	W06
	.byte		N12   , Cs2
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   
	.byte	W12
	.byte		        Cs2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Gs1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		N06   , Cs2
	.byte	W06
	.byte		        Gs1
	.byte	W06
@ 021   ----------------------------------------
	.byte		        Fn1
	.byte	W06
	.byte		        Ds1
	.byte	W06
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn1
	.byte	W12
@ 022   ----------------------------------------
	.byte		N06   , Cn2
	.byte	W06
	.byte		        Bn1
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Bn0
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   
	.byte	W12
	.byte		        Bn1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Fs1
	.byte	W12
	.byte		        Bn0
	.byte	W12
	.byte		N06   , Bn1
	.byte	W06
	.byte		        Fs1
	.byte	W06
@ 023   ----------------------------------------
	.byte		        Ds1
	.byte	W06
	.byte		        Cs1
	.byte	W06
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   
	.byte	W12
	.byte		        Gs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Gn1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs2
	.byte	W12
@ 024   ----------------------------------------
mus_vs_champion_3_024:
	.byte		N12   , Gn1 , v068
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Gn1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs2
	.byte	W12
	.byte		        Gn1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En1
	.byte	W12
	.byte		        Fs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N06   , En1
	.byte	W06
	.byte		        Dn1
	.byte	W06
	.byte	PEND
@ 025   ----------------------------------------
mus_vs_champion_3_025:
	.byte		N12   , Bn0 , v068
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Gn1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs2
	.byte	W12
	.byte	PEND
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_3_024
	.byte	PATT
	 .word	mus_vs_champion_3_025
	.byte	PATT
	 .word	mus_vs_champion_3_024
	.byte		N12   , Bn0 , v068
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Gn1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs2
	.byte	W12
	.byte		        Gn1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En1
	.byte	W12
	.byte		        Fs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Dn1
	.byte	W12
@ 027   ----------------------------------------
	.byte		        Bn0
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Gn1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Dn2
	.byte	W12
@ 028   ----------------------------------------
	.byte		        Gn1
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Bn0
	.byte	W12
	.byte		        Fs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Bn1
	.byte	W12
	.byte		        Fn1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Ds1
	.byte	W12
	.byte		        En1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N06   , Ds1
	.byte	W06
	.byte		        Cs1
	.byte	W06
@ 029   ----------------------------------------
mus_vs_champion_3_029:
	.byte		N12   , As0 , v068
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Bn0
	.byte	W12
	.byte		        Fs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Bn0
	.byte	W12
	.byte		        Fs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Bn0
	.byte	W12
	.byte		        Fn1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Bn1
	.byte	W12
	.byte	PEND
@ 030   ----------------------------------------
	.byte		        Fn1
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Bn0
	.byte	W12
	.byte		        Fs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Bn1
	.byte	W12
	.byte		        Fs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Dn1
	.byte	W12
	.byte		        En1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N06   , Ds1
	.byte	W06
	.byte		        Cs1
	.byte	W06
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_3_029
	.byte		N12   , Fn1 , v068
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs2
	.byte	W12
	.byte		        Gs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Dn1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Bn0
	.byte	W12
@ 032   ----------------------------------------
	.byte		        Dn1
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Dn1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Bn0
	.byte	W12
@ 033   ----------------------------------------
	.byte		        Dn1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
@ 034   ----------------------------------------
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
@ 035   ----------------------------------------
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        Fn1
	.byte	W12
@ 036   ----------------------------------------
mus_vs_champion_3_036:
	.byte		N12   , As1 , v068
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte	PEND
@ 037   ----------------------------------------
	.byte		        Fs1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        Fn1
	.byte	W12
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_3_036
	.byte		N12   , Fs1 , v068
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn1
	.byte	W12
@ 039   ----------------------------------------
mus_vs_champion_3_039:
	.byte		N06   , Cn2 , v068
	.byte	W06
	.byte		        Bn1
	.byte	W06
	.byte		N12   , Cn2
	.byte	W12
	.byte		N06   , Cn1
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   
	.byte	W12
	.byte		        Cn2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Gn1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		N06   , Cn2
	.byte	W06
	.byte		        Gn1
	.byte	W06
	.byte	PEND
@ 040   ----------------------------------------
mus_vs_champion_3_040:
	.byte		N06   , En1 , v068
	.byte	W06
	.byte		        Dn1
	.byte	W06
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn1
	.byte	W12
	.byte	PEND
@ 041   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_3_039
	.byte	PATT
	 .word	mus_vs_champion_3_040
	.byte	PATT
	 .word	mus_vs_champion_3_039
	.byte		N06   , En1 , v068
	.byte	W06
	.byte		        Dn1
	.byte	W06
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , As0
	.byte	W12
	.byte		        As1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , As0
	.byte	W12
	.byte		        As1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , As0
	.byte	W12
	.byte		        As1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , As0
	.byte	W12
@ 042   ----------------------------------------
	.byte		N06   , As1
	.byte	W06
	.byte		        An1
	.byte	W06
	.byte		N12   , As1
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   
	.byte	W12
	.byte		        As1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Fn1
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		N06   , As1
	.byte	W06
	.byte		        Fn1
	.byte	W06
@ 043   ----------------------------------------
	.byte		        Dn1
	.byte	W06
	.byte		        Cn1
	.byte	W06
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , An0
	.byte	W12
	.byte		        An1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , An0
	.byte	W12
	.byte		        An1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , An0
	.byte	W12
	.byte		        An1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , An0
	.byte	W12
@ 044   ----------------------------------------
	.byte		N06   , An1
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N12   , An1
	.byte	W12
	.byte		        An0
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   
	.byte	W12
	.byte		        An1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En1
	.byte	W12
	.byte		        An0
	.byte	W12
	.byte		N06   , An1
	.byte	W06
	.byte		        En1
	.byte	W06
@ 045   ----------------------------------------
	.byte		        Cs1
	.byte	W06
	.byte		        Bn0
	.byte	W06
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Gs0
	.byte	W12
	.byte		        Gs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Gs0
	.byte	W12
	.byte		        Gs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Gs0
	.byte	W12
	.byte		        Gs1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Gs0
	.byte	W12
@ 046   ----------------------------------------
	.byte		N06   , Gs1
	.byte	W06
	.byte		        Gn1
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		VOL   , 85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   
	.byte	W12
	.byte		        Gn1
	.byte	W06
	.byte		VOL   , 70*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        85*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Dn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		N06   , Gn1
	.byte	W06
	.byte		        Dn1
	.byte	W06
@ 047   ----------------------------------------
	.byte		        Bn0
	.byte	W06
	.byte		        An0
	.byte	W90
@ 048   ----------------------------------------
	.byte	W12
	.byte		N12   , Fn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Fn2
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		N06   , Fn2
	.byte	W06
	.byte		        Gn2
	.byte	W06
@ 049   ----------------------------------------
mus_vs_champion_3_049:
	.byte		N06   , Fn2 , v068
	.byte	W06
	.byte		        Cn2
	.byte	W06
	.byte		N12   , Fn2
	.byte	W12
	.byte		        Fn1
	.byte	W24
	.byte		        Cn2
	.byte	W24
	.byte		        Fn2
	.byte	W24
	.byte	PEND
@ 050   ----------------------------------------
	.byte		        An2
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        Gn2
	.byte	W12
	.byte		        Dn2
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		N06   , Bn1
	.byte	W06
	.byte		        Dn2
	.byte	W06
@ 051   ----------------------------------------
	.byte		        Bn1
	.byte	W06
	.byte		        An1
	.byte	W06
	.byte		N12   , Gn1
	.byte	W12
	.byte		        Dn1
	.byte	W24
	.byte		        Gn1
	.byte	W24
	.byte		        Bn1
	.byte	W24
@ 052   ----------------------------------------
	.byte		        Dn2
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		N06   , En2
	.byte	W06
	.byte		        Fn2
	.byte	W06
@ 053   ----------------------------------------
	.byte		        En2
	.byte	W06
	.byte		        Bn1
	.byte	W06
	.byte		N12   , En1
	.byte	W12
	.byte		        Bn0
	.byte	W24
	.byte		        En1
	.byte	W24
	.byte		        Gs1
	.byte	W24
@ 054   ----------------------------------------
	.byte		        Bn1
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        An2
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		N06   , Cs3 , v048
	.byte	W06
	.byte		        Dn3
	.byte	W06
@ 055   ----------------------------------------
	.byte		        Cs3
	.byte	W06
	.byte		        An2
	.byte	W06
	.byte		N12   , An1 , v068
	.byte	W12
	.byte		        En1
	.byte	W24
	.byte		        An1
	.byte	W24
	.byte		        Cs2
	.byte	W24
@ 056   ----------------------------------------
	.byte		        En2
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Fn2
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		N06   , Fn2
	.byte	W06
	.byte		        Gn2
	.byte	W06
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_3_049
	.byte		N12   , An2 , v068
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        Fs2
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		N06   , Fs2
	.byte	W06
	.byte		        Gn2
	.byte	W06
@ 058   ----------------------------------------
	.byte		        Fs2
	.byte	W06
	.byte		        Cn2
	.byte	W06
	.byte		N12   , Fs2
	.byte	W12
	.byte		        An1
	.byte	W24
	.byte		        Cn2
	.byte	W24
	.byte		        En2
	.byte	W24
@ 059   ----------------------------------------
	.byte		        An2
	.byte	W12
	.byte		N08   , Fs1
	.byte	W08
	.byte		        Cn2
	.byte	W08
	.byte		        Fs2
	.byte	W08
	.byte		        Fn1
	.byte	W08
	.byte		        Bn1
	.byte	W08
	.byte		        Fn2
	.byte	W08
	.byte		        En1
	.byte	W08
	.byte		        As1
	.byte	W08
	.byte		        En2
	.byte	W08
	.byte		        Ds1
	.byte	W08
	.byte		        An1
	.byte	W04
@ 060   ----------------------------------------
	.byte	W04
	.byte		        Ds2
	.byte	W08
	.byte		        Dn1
	.byte	W08
	.byte		        Gs1
	.byte	W08
	.byte		        Dn2
	.byte	W08
	.byte		        Cs1
	.byte	W08
	.byte		        Gn1
	.byte	W08
	.byte		        Cs2
	.byte	W08
	.byte		        Cn1
	.byte	W08
	.byte		        Fs1
	.byte	W08
	.byte		        Cn2
	.byte	W08
	.byte		        Bn1
	.byte	W08
	.byte		        Cn2
	.byte	W04
@ 061   ----------------------------------------
	.byte	W04
	.byte		        As1
	.byte	W08
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 90*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N06   , An1 , v076
	.byte	W12
	.byte		        An1 , v068
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		        An1 , v068
	.byte	W12
	.byte		N06   
	.byte	W12
@ 062   ----------------------------------------
	.byte	GOTO
	 .word	mus_vs_champion_3_B1
	.byte	W06
	.byte	FINE

@**************** Track 4 ****************@

mus_vs_champion_4:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_vs_champion_key+0
	.byte		VOICE , 47
	.byte		PAN   , c_v-20
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 69*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		BEND  , c_v+2
	.byte	W12
	.byte		N08   , En2 , v104
	.byte	W08
	.byte		        En2 , v080
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N23   , Bn1 , v112
	.byte	W24
	.byte		N08   , En2 , v104
	.byte	W08
	.byte		        En2 , v064
	.byte	W08
	.byte		        En2 , v068
	.byte	W08
	.byte		        En2 , v056
	.byte	W08
	.byte		        En2 , v032
	.byte	W04
@ 001   ----------------------------------------
	.byte	W04
	.byte		N08   
	.byte	W08
	.byte		VOICE , 1
	.byte		PAN   , c_v-33
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		BEND  , c_v+0
	.byte		N08   , Bn3 , v072
	.byte	W08
	.byte		        Fn4
	.byte	W08
	.byte		        Bn4
	.byte	W08
	.byte		        As3
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        As4
	.byte	W08
	.byte		        An3
	.byte	W08
	.byte		        Ds4
	.byte	W08
	.byte		        An4
	.byte	W08
	.byte		        Gs3
	.byte	W08
	.byte		        Dn4
	.byte	W04
@ 002   ----------------------------------------
	.byte	W04
	.byte		        Gs4
	.byte	W08
	.byte		        Gn3
	.byte	W08
	.byte		        Cs4
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		        Fs3
	.byte	W08
	.byte		        Cn4
	.byte	W08
	.byte		        Fs4
	.byte	W08
	.byte		        Fn3
	.byte	W08
	.byte		        Bn3
	.byte	W08
	.byte		        Fn4
	.byte	W08
	.byte		N03   , En4 , v080
	.byte	W06
	.byte		        Fn4
	.byte	W06
@ 003   ----------------------------------------
	.byte		        En4
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		VOL   , 89*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W24
	.byte		VOICE , 33
	.byte		N12   , An1 , v127
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Gs1 , v016
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Bn1 , v127
	.byte	W12
	.byte		        Cn2
	.byte	W12
@ 004   ----------------------------------------
mus_vs_champion_4_B1:
	.byte		PAN   , c_v+63
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Cn2 , v016
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		        Ds2
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Ds2 , v016
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Bn1 , v127
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		N06   , An1
	.byte	W06
	.byte		        Cn2
	.byte	W06
@ 005   ----------------------------------------
	.byte		N12   , As1
	.byte	W12
	.byte		N32   , Ds2
	.byte	W36
	.byte		N24   , Dn2
	.byte	W24
	.byte		        Cn2
	.byte	W24
@ 006   ----------------------------------------
	.byte		N12   , Bn1
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		N06   , Ds1
	.byte	W06
	.byte		        Fn1
	.byte	W06
@ 007   ----------------------------------------
	.byte		N12   , En1
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Gs1 , v016
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Bn1 , v127
	.byte	W12
	.byte		        Cn2
	.byte	W12
@ 008   ----------------------------------------
	.byte		PAN   , c_v+63
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Cn2 , v016
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Cn2 , v052
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Ds2 , v127
	.byte	W12
	.byte		        Fn2
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Fn2 , v016
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		        Ds2
	.byte	W12
	.byte		N06   , Cn2
	.byte	W06
	.byte		        Dn2
	.byte	W06
@ 009   ----------------------------------------
	.byte		N12   , Cs2
	.byte	W12
	.byte		N32   , Gn2
	.byte	W36
	.byte		N24   , Fn2
	.byte	W24
	.byte		        Ds2
	.byte	W24
@ 010   ----------------------------------------
	.byte		N12   , Bn1
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Ds1
	.byte	W12
@ 011   ----------------------------------------
	.byte		        En1
	.byte	W12
	.byte		VOL   , 79*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W24
	.byte		VOICE , 60
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N24   , En3 , v064
	.byte	W48
	.byte		        Fn3
	.byte	W12
@ 012   ----------------------------------------
	.byte	W36
	.byte		        Fs3
	.byte	W48
	.byte		        Gn3
	.byte	W12
@ 013   ----------------------------------------
	.byte	W24
	.byte		N12   , En3
	.byte	W24
	.byte		        Fn3
	.byte	W24
	.byte		        Fs3
	.byte	W24
@ 014   ----------------------------------------
	.byte		        Gn3
	.byte	W24
	.byte		        Gs3
	.byte	W24
	.byte		        An3
	.byte	W24
	.byte		        As3
	.byte	W24
@ 015   ----------------------------------------
	.byte		        Bn3
	.byte	W12
	.byte		PAN   , c_v-24
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		VOICE , 1
	.byte		N12   , En4 , v108
	.byte	W36
	.byte		N12   
	.byte	W36
@ 016   ----------------------------------------
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Bn3
	.byte	W06
	.byte		        Cs4
	.byte	W06
@ 017   ----------------------------------------
	.byte		        Bn3
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		N12   , En4
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 018   ----------------------------------------
	.byte	W12
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Bn3
	.byte	W06
	.byte		        Cs4
	.byte	W06
@ 019   ----------------------------------------
	.byte		        Bn3
	.byte	W06
	.byte		        Gs3
	.byte	W18
	.byte		N12   , En4
	.byte	W24
	.byte		        Bn3
	.byte	W12
	.byte		        En4
	.byte	W12
	.byte		        Bn3
	.byte	W12
	.byte		        Gs3
	.byte	W12
@ 020   ----------------------------------------
	.byte		        En4
	.byte	W24
	.byte		        Gs4
	.byte	W12
	.byte		        En4
	.byte	W12
	.byte		        Bn4 , v100
	.byte	W12
	.byte		        Gs4 , v108
	.byte	W12
	.byte		        En5 , v096
	.byte	W12
	.byte		        Bn4 , v108
	.byte	W12
@ 021   ----------------------------------------
	.byte		        Gs5 , v100
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 38*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		PAN   , c_v-16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Fs5
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		PAN   , c_v+32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Bn4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		        Fs5
	.byte	W06
	.byte		        En5
	.byte	W06
@ 022   ----------------------------------------
	.byte		        Bn4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		        Fs5
	.byte	W06
	.byte		        Gn5
	.byte	W06
	.byte		        Fs5
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		PAN   , c_v+15
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Bn4
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , En4
	.byte	W06
	.byte		        Bn3
	.byte	W06
@ 023   ----------------------------------------
	.byte		        En4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		PAN   , c_v-17
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Fs5
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		PAN   , c_v+32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , En4
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		        Fs5
	.byte	W06
	.byte		        En5
	.byte	W06
@ 024   ----------------------------------------
	.byte		        Bn4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		PAN   , c_v+16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Gs5
	.byte	W06
	.byte		        Bn5
	.byte	W06
	.byte		        Gs5
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Bn4
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        En5
	.byte	W06
@ 025   ----------------------------------------
	.byte		        Fs5
	.byte	W06
	.byte		        Gs5
	.byte	W06
	.byte		        Cn6
	.byte	W06
	.byte		        An5
	.byte	W06
	.byte		        Gn5
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		PAN   , c_v-16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Cn5
	.byte	W06
	.byte		        An4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		PAN   , c_v+31
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Cn4
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Cn5
	.byte	W06
@ 026   ----------------------------------------
	.byte		        Gn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        An4
	.byte	W06
	.byte		PAN   , c_v+15
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Bn4
	.byte	W06
	.byte		        Ds5
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Ds4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        Ds5
	.byte	W06
	.byte		        Fs5
	.byte	W06
	.byte		        Ds5
	.byte	W06
@ 027   ----------------------------------------
	.byte		        Bn4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        Cs4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		PAN   , c_v-16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Cs5
	.byte	W06
	.byte		        Ds5
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		        Ds5
	.byte	W06
	.byte		PAN   , c_v+32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Cs5
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		PAN   , c_v-33
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Cs4
	.byte	W06
	.byte		        Gs3
	.byte	W06
@ 028   ----------------------------------------
	.byte		        Fs3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		VOL   , 66*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v+32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W72
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
@ 029   ----------------------------------------
	.byte		VOICE , 60
	.byte		N06   , Cs2
	.byte	W06
	.byte		        Gn2
	.byte	W06
	.byte		N12   , Gs2
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 030   ----------------------------------------
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		        Fs2
	.byte	W24
	.byte		N24   , An2
	.byte	W12
@ 031   ----------------------------------------
	.byte	W12
	.byte		N12   , Gs2
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 032   ----------------------------------------
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		        An2
	.byte	W24
	.byte		N24   , Fs2
	.byte	W12
@ 033   ----------------------------------------
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 66*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W84
@ 034   ----------------------------------------
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	W96
@ 037   ----------------------------------------
	.byte	W96
@ 038   ----------------------------------------
	.byte	W96
@ 039   ----------------------------------------
	.byte	W96
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W12
	.byte		VOICE , 1
	.byte		VOL   , 37*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Gn4
	.byte	W12
	.byte		        Cs4
	.byte	W12
	.byte		        Gn3
	.byte	W12
	.byte		        Dn4
	.byte	W12
	.byte		        Cs4
	.byte	W12
	.byte		        Gn3
	.byte	W12
	.byte		        En3
	.byte	W12
@ 044   ----------------------------------------
	.byte		PAN   , c_v+23
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Gn4
	.byte	W12
	.byte		        Fs4
	.byte	W12
	.byte		        Cs4
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        Cs4
	.byte	W12
	.byte		        Bn3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Bn2
	.byte	W12
@ 045   ----------------------------------------
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Fs3
	.byte	W12
	.byte		N08   , Gn4
	.byte	W08
	.byte		        Bn3
	.byte	W08
	.byte		        Gn3
	.byte	W08
	.byte		PAN   , c_v+24
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , Fs4
	.byte	W08
	.byte		        As3
	.byte	W08
	.byte		        Fs3
	.byte	W08
	.byte		PAN   , c_v-33
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , Fn4
	.byte	W08
	.byte		        An3
	.byte	W08
	.byte		        Fn3
	.byte	W08
	.byte		PAN   , c_v+23
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , En4
	.byte	W08
	.byte		        Gs3
	.byte	W04
@ 046   ----------------------------------------
	.byte	W04
	.byte		        En3
	.byte	W08
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N06   , Gn4 , v068
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		        Cs4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Fs3
	.byte	W06
@ 047   ----------------------------------------
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Dn3
	.byte	W06
	.byte		PAN   , c_v-22
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		N12   , Cn4 , v108
	.byte	W36
	.byte		N12   
	.byte	W36
@ 048   ----------------------------------------
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Gn3
	.byte	W06
	.byte		        An3
	.byte	W06
@ 049   ----------------------------------------
	.byte		        Gn3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		N12   , Cn4
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 050   ----------------------------------------
	.byte	W12
	.byte		VOL   , 46*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Gn3
	.byte	W06
	.byte		        An3
	.byte	W06
@ 051   ----------------------------------------
	.byte		        Gn3
	.byte	W06
	.byte		        En3
	.byte	W18
	.byte		N12   , Cn4
	.byte	W24
	.byte		        Gn3
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		        Gn3
	.byte	W12
	.byte		        En3
	.byte	W12
@ 052   ----------------------------------------
	.byte		        Cn4
	.byte	W24
	.byte		        En4
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		        Gn4
	.byte	W12
	.byte		        En4
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W12
	.byte		        Gn4 , v108
	.byte	W12
@ 053   ----------------------------------------
	.byte		        En5 , v096
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 42*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N03   , Cn4 , v112
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		PAN   , c_v-16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Dn5
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		PAN   , c_v+32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Gn4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		        Dn5
	.byte	W06
	.byte		        Cn5
	.byte	W06
@ 054   ----------------------------------------
	.byte		        Gn4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		        Dn5
	.byte	W06
	.byte		        Ds5
	.byte	W06
	.byte		        Dn5
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		PAN   , c_v+15
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Gn4
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Cn4
	.byte	W06
	.byte		        Gn3
	.byte	W06
@ 055   ----------------------------------------
	.byte		        Cn4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		PAN   , c_v-17
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Dn5
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		PAN   , c_v+32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Cn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		        Dn5
	.byte	W06
	.byte		        Cn5
	.byte	W06
@ 056   ----------------------------------------
	.byte		        Gn4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		PAN   , c_v+16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , En5
	.byte	W06
	.byte		        Gn5
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Gn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Cn5
	.byte	W06
@ 057   ----------------------------------------
	.byte		        Dn5
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		        Gs5
	.byte	W06
	.byte		        Fn5
	.byte	W06
	.byte		        Ds5
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte		PAN   , c_v-16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Gs4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		PAN   , c_v+31
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Gs3
	.byte	W06
	.byte		        Ds3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Gs4
	.byte	W06
@ 058   ----------------------------------------
	.byte		        Ds4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		PAN   , c_v+15
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Gn4
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N03   , Bn3
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        Dn5
	.byte	W06
	.byte		        Bn4
	.byte	W06
@ 059   ----------------------------------------
	.byte		        Gn4
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		VOICE , 47
	.byte		VOL   , 78*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N08   , Gn2
	.byte	W08
	.byte		        Gn2 , v080
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Dn2 , v060
	.byte	W08
	.byte		        Gn2 , v032
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Gn2 , v112
	.byte	W08
	.byte		        Gn2 , v080
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Dn2 , v060
	.byte	W08
	.byte		        Gn2 , v032
	.byte	W04
@ 060   ----------------------------------------
	.byte	W04
	.byte		N08   
	.byte	W08
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W48
	.byte		VOICE , 60
	.byte		N06   , An3 , v096
	.byte	W18
	.byte		N03   , Fn3
	.byte	W06
	.byte		N68   , Cn4
	.byte	W12
@ 061   ----------------------------------------
	.byte	W36
	.byte		VOL   , 48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        38*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        29*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        19*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , Dn4
	.byte	W24
	.byte		N06   , Fn4
	.byte	W06
	.byte		        Gn4
	.byte	W06
@ 062   ----------------------------------------
	.byte		        Fn4
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		N44   , Bn3
	.byte	W24
	.byte		VOL   , 48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        44*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        31*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        25*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        19*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W36
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W12
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W48
	.byte		N06   
	.byte	W18
	.byte		N03   , Gn3
	.byte	W06
	.byte		N68   , Dn4
	.byte	W12
@ 065   ----------------------------------------
	.byte	W36
	.byte		VOL   , 48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        39*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        35*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        32*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        28*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        20*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N44   , Ds4
	.byte	W24
	.byte		VOL   , 48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        39*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        35*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 066   ----------------------------------------
	.byte		        32*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        28*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        20*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N44   , En4
	.byte	W24
	.byte		VOL   , 48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        39*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        35*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        32*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        28*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        20*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W24
	.byte		N04   , Cs4 , v100
	.byte	W08
	.byte		N04   
	.byte	W04
@ 067   ----------------------------------------
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W32
	.byte		N04   , Bn3
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N44   
	.byte	W24
	.byte		VOL   , 48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        39*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        35*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 068   ----------------------------------------
	.byte		        32*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        28*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        20*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N06   , Fn3 , v096
	.byte	W18
	.byte		N03   , Cn3
	.byte	W06
	.byte		N24   , An3
	.byte	W24
	.byte		N06   , Cn4
	.byte	W18
	.byte		N03   , An3
	.byte	W06
	.byte		N44   , Fn4
	.byte	W12
@ 069   ----------------------------------------
	.byte	W12
	.byte		VOL   , 48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        39*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        35*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        32*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        28*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        20*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W60
@ 070   ----------------------------------------
	.byte		VOICE , 48
	.byte		N12   , Cn4
	.byte	W12
	.byte		N06   , Fs3
	.byte	W18
	.byte		N03   , Cn3
	.byte	W06
	.byte		N24   , An3
	.byte	W24
	.byte		N06   , Cn4
	.byte	W18
	.byte		N03   , An3
	.byte	W06
	.byte		N44   , Fs4
	.byte	W12
@ 071   ----------------------------------------
	.byte	W12
	.byte		VOL   , 48*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        39*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        35*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        32*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        28*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        20*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 56*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W24
	.byte		N44   , Cn5 , v112
	.byte	W36
@ 072   ----------------------------------------
	.byte	W12
	.byte		N92   , Dn5
	.byte	W48
	.byte		VOL   , 52*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        50*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        46*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        43*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        38*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        31*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        28*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        25*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        19*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 073   ----------------------------------------
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        15*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        13*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        12*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		PAN   , c_v-20
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 68*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W84
@ 074   ----------------------------------------
	.byte	W12
	.byte		        89*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W24
	.byte		VOICE , 33
	.byte		N12   , An1 , v127
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Gs1 , v016
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Bn1 , v127
	.byte	W12
	.byte		        Cn2
	.byte	W12
@ 075   ----------------------------------------
	.byte	GOTO
	 .word	mus_vs_champion_4_B1
	.byte	W06
	.byte	FINE

@**************** Track 5 ****************@

mus_vs_champion_5:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_vs_champion_key+0
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		BEND  , c_v+1
	.byte	W96
@ 001   ----------------------------------------
	.byte	W12
	.byte		N05   , Fs1 , v068
	.byte	W08
	.byte		        Cn2
	.byte	W08
	.byte		        Fs2
	.byte	W08
	.byte		        Fn1
	.byte	W08
	.byte		        Bn1
	.byte	W08
	.byte		        Fn2
	.byte	W08
	.byte		        En1
	.byte	W08
	.byte		        As1
	.byte	W08
	.byte		        En2
	.byte	W08
	.byte		        Ds1
	.byte	W08
	.byte		        An1
	.byte	W04
@ 002   ----------------------------------------
	.byte	W04
	.byte		        Ds2
	.byte	W08
	.byte		        Dn1
	.byte	W08
	.byte		        Gs1
	.byte	W08
	.byte		        Dn2
	.byte	W08
	.byte		        Cs1
	.byte	W08
	.byte		        Gn1
	.byte	W08
	.byte		        Cs2
	.byte	W08
	.byte		        Cn1
	.byte	W08
	.byte		        Fs1
	.byte	W08
	.byte		        Cn2
	.byte	W08
	.byte		N03   , Bn1
	.byte	W06
	.byte		        Cn2
	.byte	W06
@ 003   ----------------------------------------
	.byte		        Bn1
	.byte	W06
	.byte		        As1
	.byte	W06
	.byte		        An1
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
@ 004   ----------------------------------------
mus_vs_champion_5_B1:
	.byte		N03   , An1 , v068
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , Bn1
	.byte	W12
	.byte		N03   , Ds2
	.byte	W06
	.byte		        Dn2
	.byte	W06
	.byte	PEND
@ 005   ----------------------------------------
mus_vs_champion_5_005:
	.byte		N09   , Cn2 , v068
	.byte	W12
	.byte		N03   , An1
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		N09   , Dn2
	.byte	W12
	.byte		N03   , Ds2
	.byte	W06
	.byte		        Dn2
	.byte	W06
@ 007   ----------------------------------------
	.byte		N09   , As1
	.byte	W12
	.byte		VOL   , 90*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		BEND  , c_v+0
	.byte		N03   , An1 , v076
	.byte	W12
	.byte		BEND  , c_v+1
	.byte		N03   , An1 , v068
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_5_B1
	.byte	PATT
	 .word	mus_vs_champion_5_005
	.byte		N03   , An1 , v068
	.byte	W12
	.byte		VOL   , 90*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		BEND  , c_v+0
	.byte		N03   , An1 , v076
	.byte	W12
	.byte		BEND  , c_v+1
	.byte		N03   , An1 , v068
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		N09   , Dn2
	.byte	W12
	.byte		N03   , Ds2
	.byte	W06
	.byte		        Dn2
	.byte	W06
@ 009   ----------------------------------------
	.byte		N09   , As1
	.byte	W12
	.byte		N05   , En1
	.byte	W12
	.byte		N05   
	.byte	W12
	.byte		N21   , En2
	.byte	W24
	.byte		N05   , En1
	.byte	W12
	.byte		N05   
	.byte	W12
	.byte		N21   , Fn2
	.byte	W12
@ 010   ----------------------------------------
	.byte	W12
	.byte		N05   , En1
	.byte	W12
	.byte		N05   
	.byte	W12
	.byte		N21   , Fs2
	.byte	W24
	.byte		N05   , En1
	.byte	W12
	.byte		N05   
	.byte	W12
	.byte		N21   , Gn2
	.byte	W12
@ 011   ----------------------------------------
	.byte	W12
	.byte		N03   , En1
	.byte	W12
	.byte		N09   , En2
	.byte	W12
	.byte		N03   , En1
	.byte	W12
	.byte		N09   , Fn2
	.byte	W12
	.byte		N03   , En1
	.byte	W12
	.byte		N09   , Fs2
	.byte	W12
	.byte		N03   , En1
	.byte	W12
@ 012   ----------------------------------------
	.byte		N09   , Gn2
	.byte	W12
	.byte		N03   , En1
	.byte	W12
	.byte		N09   , Gs2
	.byte	W12
	.byte		N03   , En1
	.byte	W12
	.byte		N09   , An2
	.byte	W12
	.byte		N03   , En1
	.byte	W12
	.byte		N09   , As2
	.byte	W12
	.byte		N03   , En1
	.byte	W12
@ 013   ----------------------------------------
	.byte		N09   , Bn2
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        En1
	.byte	W12
@ 014   ----------------------------------------
mus_vs_champion_5_014:
	.byte		N03   , En2 , v068
	.byte	W06
	.byte		        Ds2
	.byte	W06
	.byte		N09   , En2
	.byte	W12
	.byte		N03   , En1
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		N03   , En2
	.byte	W06
	.byte		        Bn1
	.byte	W06
	.byte	PEND
@ 015   ----------------------------------------
mus_vs_champion_5_015:
	.byte		N03   , Gs1 , v068
	.byte	W06
	.byte		        Fs1
	.byte	W06
	.byte		N09   , En1
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte	PEND
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_5_014
	.byte	PATT
	 .word	mus_vs_champion_5_015
	.byte	PATT
	 .word	mus_vs_champion_5_014
	.byte		N03   , Gs1 , v068
	.byte	W06
	.byte		        Fs1
	.byte	W06
	.byte		N09   , Dn1
	.byte	W12
	.byte		        Dn2
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Dn2
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Dn2
	.byte	W12
	.byte		        Dn1
	.byte	W12
@ 017   ----------------------------------------
	.byte		N03   , Dn2
	.byte	W06
	.byte		        Cs2
	.byte	W06
	.byte		N09   , Dn2
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Dn2
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		N03   , Dn2
	.byte	W06
	.byte		        An1
	.byte	W06
@ 018   ----------------------------------------
	.byte		        Fs1
	.byte	W06
	.byte		        En1
	.byte	W06
	.byte		N09   , Cs1
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        Cs1
	.byte	W12
@ 019   ----------------------------------------
	.byte		N03   , Cs2
	.byte	W06
	.byte		        Cn2
	.byte	W06
	.byte		N09   , Cs2
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		N03   , Cs2
	.byte	W06
	.byte		        Gs1
	.byte	W06
@ 020   ----------------------------------------
	.byte		        Fn1
	.byte	W06
	.byte		        Ds1
	.byte	W06
	.byte		N09   , Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Cn1
	.byte	W12
@ 021   ----------------------------------------
	.byte		N03   , Cn2
	.byte	W06
	.byte		        Bn1
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		        Bn0
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Bn0
	.byte	W12
	.byte		        Bn1
	.byte	W06
	.byte		N03   , Fs1
	.byte	W06
@ 022   ----------------------------------------
	.byte		        Ds1
	.byte	W06
	.byte		        Cs1
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        Cs2
	.byte	W12
@ 023   ----------------------------------------
mus_vs_champion_5_023:
	.byte		N09   , Gn1 , v068
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		N03   , En1
	.byte	W06
	.byte		        Dn1
	.byte	W06
	.byte	PEND
@ 024   ----------------------------------------
mus_vs_champion_5_024:
	.byte		N09   , Bn0 , v068
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte	PEND
@ 025   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_5_023
	.byte	PATT
	 .word	mus_vs_champion_5_024
	.byte	PATT
	 .word	mus_vs_champion_5_023
	.byte		N09   , Bn0 , v068
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Dn1
	.byte	W12
@ 026   ----------------------------------------
	.byte		        Bn0
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        Dn2
	.byte	W12
@ 027   ----------------------------------------
	.byte		        Gn1
	.byte	W12
	.byte		        Bn0
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		N03   , Ds1
	.byte	W06
	.byte		        Cs1
	.byte	W06
@ 028   ----------------------------------------
mus_vs_champion_5_028:
	.byte		N09   , As0 , v068
	.byte	W12
	.byte		        Bn0
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Bn0
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Bn0
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte	PEND
@ 029   ----------------------------------------
	.byte		        Fn1
	.byte	W12
	.byte		        Bn0
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		N03   , Ds1
	.byte	W06
	.byte		        Cs1
	.byte	W06
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_5_028
	.byte		N09   , Fn1 , v068
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Bn0
	.byte	W12
@ 031   ----------------------------------------
	.byte		        Dn1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Bn0
	.byte	W12
@ 032   ----------------------------------------
	.byte		        Dn1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W24
@ 033   ----------------------------------------
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W12
@ 034   ----------------------------------------
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        Fn1
	.byte	W12
@ 035   ----------------------------------------
mus_vs_champion_5_035:
	.byte		N09   , As1 , v068
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte	PEND
@ 036   ----------------------------------------
	.byte		        Fs1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        Fn1
	.byte	W12
@ 037   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_5_035
	.byte		N09   , Fs1 , v068
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Cn1
	.byte	W12
@ 038   ----------------------------------------
mus_vs_champion_5_038:
	.byte		N03   , Cn2 , v068
	.byte	W06
	.byte		        Bn1
	.byte	W06
	.byte		N09   , Cn2
	.byte	W12
	.byte		N03   , Cn1
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		N03   , Cn2
	.byte	W06
	.byte		        Gn1
	.byte	W06
	.byte	PEND
@ 039   ----------------------------------------
mus_vs_champion_5_039:
	.byte		N03   , En1 , v068
	.byte	W06
	.byte		        Dn1
	.byte	W06
	.byte		N09   , Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte	PEND
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_5_038
	.byte	PATT
	 .word	mus_vs_champion_5_039
	.byte	PATT
	 .word	mus_vs_champion_5_038
	.byte		N03   , En1 , v068
	.byte	W06
	.byte		        Dn1
	.byte	W06
	.byte		N09   , As0
	.byte	W12
	.byte		        As1
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        As1
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        As1
	.byte	W12
	.byte		        As0
	.byte	W12
@ 041   ----------------------------------------
	.byte		N03   , As1
	.byte	W06
	.byte		        An1
	.byte	W06
	.byte		N09   , As1
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        As1
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		N03   , As1
	.byte	W06
	.byte		        Fn1
	.byte	W06
@ 042   ----------------------------------------
	.byte		        Dn1
	.byte	W06
	.byte		        Cn1
	.byte	W06
	.byte		N09   , An0
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		        An0
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		        An0
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		        An0
	.byte	W12
@ 043   ----------------------------------------
	.byte		N03   , An1
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N09   , An1
	.byte	W12
	.byte		        An0
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        An0
	.byte	W12
	.byte		N03   , An1
	.byte	W06
	.byte		        En1
	.byte	W06
@ 044   ----------------------------------------
	.byte		        Cs1
	.byte	W06
	.byte		        Bn0
	.byte	W06
	.byte		N09   , Gs0
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Gs0
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Gs0
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        Gs0
	.byte	W12
@ 045   ----------------------------------------
	.byte		N03   , Gs1
	.byte	W06
	.byte		        Gn1
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		N03   , Gn1
	.byte	W06
	.byte		        Dn1
	.byte	W06
@ 046   ----------------------------------------
	.byte		        Bn0
	.byte	W06
	.byte		        An0
	.byte	W90
@ 047   ----------------------------------------
	.byte	W12
	.byte		N09   , Fn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Fn2
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		N03   , Fn2
	.byte	W06
	.byte		        Gn2
	.byte	W06
@ 048   ----------------------------------------
mus_vs_champion_5_048:
	.byte		N03   , Fn2 , v068
	.byte	W06
	.byte		        Cn2
	.byte	W06
	.byte		N09   , Fn2
	.byte	W12
	.byte		        Fn1
	.byte	W24
	.byte		        Cn2
	.byte	W24
	.byte		        Fn2
	.byte	W24
	.byte	PEND
@ 049   ----------------------------------------
	.byte		        An2
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        Gn2
	.byte	W12
	.byte		        Dn2
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		N03   , Bn1
	.byte	W06
	.byte		        Dn2
	.byte	W06
@ 050   ----------------------------------------
	.byte		        Bn1
	.byte	W06
	.byte		        An1
	.byte	W06
	.byte		N09   , Gn1
	.byte	W12
	.byte		        Dn1
	.byte	W24
	.byte		        Gn1
	.byte	W24
	.byte		        Bn1
	.byte	W24
@ 051   ----------------------------------------
	.byte		        Dn2
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		N03   , En2
	.byte	W06
	.byte		        Fn2
	.byte	W06
@ 052   ----------------------------------------
	.byte		        En2
	.byte	W06
	.byte		        Bn1
	.byte	W06
	.byte		N09   , En1
	.byte	W12
	.byte		        Bn0
	.byte	W24
	.byte		        En1
	.byte	W24
	.byte		        Gs1
	.byte	W24
@ 053   ----------------------------------------
	.byte		        Bn1
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        An2
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		N03   , Cs3 , v016
	.byte	W06
	.byte		        Dn3
	.byte	W06
@ 054   ----------------------------------------
	.byte		        Cs3
	.byte	W06
	.byte		        An2
	.byte	W06
	.byte		N09   , An1 , v068
	.byte	W12
	.byte		        En1
	.byte	W24
	.byte		        An1
	.byte	W24
	.byte		        Cs2
	.byte	W24
@ 055   ----------------------------------------
	.byte		        En2
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Fn2
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		N03   , Fn2
	.byte	W06
	.byte		        Gn2
	.byte	W06
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_5_048
	.byte		N09   , An2 , v068
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        Fs2
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		N03   , Fs2
	.byte	W06
	.byte		        Gn2
	.byte	W06
@ 057   ----------------------------------------
	.byte		        Fs2
	.byte	W06
	.byte		        Cn2
	.byte	W06
	.byte		N09   , Fs2
	.byte	W12
	.byte		        An1
	.byte	W24
	.byte		        Cn2
	.byte	W24
	.byte		        En2
	.byte	W24
@ 058   ----------------------------------------
	.byte		        An2
	.byte	W12
	.byte		N05   , Fs1
	.byte	W08
	.byte		        Cn2
	.byte	W08
	.byte		        Fs2
	.byte	W08
	.byte		        Fn1
	.byte	W08
	.byte		        Bn1
	.byte	W08
	.byte		        Fn2
	.byte	W08
	.byte		        En1
	.byte	W08
	.byte		        As1
	.byte	W08
	.byte		        En2
	.byte	W08
	.byte		        Ds1
	.byte	W08
	.byte		        An1
	.byte	W04
@ 059   ----------------------------------------
	.byte	W04
	.byte		        Ds2
	.byte	W08
	.byte		        Dn1
	.byte	W08
	.byte		        Gs1
	.byte	W08
	.byte		        Dn2
	.byte	W08
	.byte		        Cs1
	.byte	W08
	.byte		        Gn1
	.byte	W08
	.byte		        Cs2
	.byte	W08
	.byte		        Cn1
	.byte	W08
	.byte		        Fs1
	.byte	W08
	.byte		        Cn2
	.byte	W08
	.byte		        Bn1
	.byte	W08
	.byte		        Cn2
	.byte	W04
@ 060   ----------------------------------------
	.byte	W04
	.byte		        As1
	.byte	W08
	.byte		N03   , An1
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
@ 061   ----------------------------------------
	.byte	GOTO
	 .word	mus_vs_champion_5_B1
	.byte	W06
	.byte	FINE

@**************** Track 6 ****************@

mus_vs_champion_6:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_vs_champion_key+0
	.byte		VOICE , 47
	.byte		PAN   , c_v+20
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 80*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N04   , Bn2 , v112
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N08   , En2
	.byte	W08
	.byte		        En2 , v080
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        En2 , v084
	.byte	W08
	.byte		        En2 , v080
	.byte	W08
	.byte		        En2 , v112
	.byte	W08
	.byte		        En2 , v084
	.byte	W08
	.byte		        En2 , v080
	.byte	W08
	.byte		        En2 , v124
	.byte	W08
	.byte		        En2 , v092
	.byte	W04
@ 001   ----------------------------------------
	.byte	W04
	.byte		N08   
	.byte	W92
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W12
	.byte		VOL   , 90*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v+19
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , An2 , v112
	.byte	W12
	.byte		        An1
	.byte	W72
@ 004   ----------------------------------------
mus_vs_champion_6_B1:
	.byte	W12
	.byte		N12   
	.byte	W84
@ 005   ----------------------------------------
mus_vs_champion_6_005:
	.byte	W12
	.byte		N12   , An1 , v112
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	PEND
@ 006   ----------------------------------------
	.byte	W12
	.byte		N12   
	.byte	W84
@ 007   ----------------------------------------
	.byte	W12
	.byte		N12   
	.byte	W84
@ 008   ----------------------------------------
	.byte	W12
	.byte		N12   
	.byte	W84
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_6_005
	.byte	W12
	.byte		N12   , An1 , v112
	.byte	W84
@ 010   ----------------------------------------
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , En1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		PAN   , c_v+25
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N24   , En2
	.byte	W24
	.byte		PAN   , c_v-31
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , En1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		PAN   , c_v+25
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N24   , Fn2
	.byte	W12
@ 011   ----------------------------------------
	.byte	W12
	.byte		PAN   , c_v-31
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , En1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		PAN   , c_v+28
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N24   , Fs2
	.byte	W24
	.byte		PAN   , c_v-32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , En1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		PAN   , c_v+25
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N24   , Gn2 , v127
	.byte	W12
@ 012   ----------------------------------------
	.byte	W12
	.byte		N06   , En2 , v112
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
@ 013   ----------------------------------------
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N08   , Ds2
	.byte	W08
	.byte		        Bn1 , v080
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		PAN   , c_v-16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , Fs1 , v112
	.byte	W08
	.byte		        Bn1 , v084
	.byte	W08
	.byte		        Bn1 , v080
	.byte	W08
	.byte		PAN   , c_v+27
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , Bn1 , v112
	.byte	W08
	.byte		        Bn1 , v084
	.byte	W08
	.byte		        Bn1 , v080
	.byte	W08
	.byte		PAN   , c_v-16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , Bn1 , v124
	.byte	W08
	.byte		        Bn1 , v092
	.byte	W04
@ 014   ----------------------------------------
	.byte	W04
	.byte		N08   
	.byte	W08
	.byte		VOL   , 82*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v+20
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , En2 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 015   ----------------------------------------
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		PAN   , c_v-14
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N06   , Bn1
	.byte	W06
	.byte		N06   
	.byte	W06
@ 016   ----------------------------------------
mus_vs_champion_6_016:
	.byte		N06   , Bn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+20
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , En2
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 017   ----------------------------------------
mus_vs_champion_6_017:
	.byte	W24
	.byte		N12   , En2 , v112
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		PAN   , c_v-13
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N06   , Bn1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_6_016
	.byte	PATT
	 .word	mus_vs_champion_6_017
	.byte		N06   , Bn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+19
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Dn2
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 019   ----------------------------------------
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		        An1
	.byte	W12
@ 020   ----------------------------------------
	.byte	W12
	.byte		        Cs2
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 021   ----------------------------------------
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		PAN   , c_v-16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Gs1
	.byte	W12
@ 022   ----------------------------------------
	.byte	W12
	.byte		PAN   , c_v+23
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Cn2
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 023   ----------------------------------------
	.byte	W24
	.byte		        Bn1
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		PAN   , c_v-12
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Fs1
	.byte	W12
@ 024   ----------------------------------------
	.byte	W12
	.byte		PAN   , c_v+23
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 82*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Gs2
	.byte	W36
	.byte		        Cs2
	.byte	W48
@ 025   ----------------------------------------
	.byte		N06   , Gs2 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N24   , Cs2
	.byte	W24
	.byte		N32   
	.byte	W24
@ 026   ----------------------------------------
	.byte	W12
	.byte		        Gs2
	.byte	W36
	.byte		        Cs2
	.byte	W48
@ 027   ----------------------------------------
mus_vs_champion_6_027:
	.byte		N06   , Gs2 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N32   , Cs2
	.byte	W36
	.byte		N24   
	.byte	W12
	.byte	PEND
@ 028   ----------------------------------------
	.byte	W12
	.byte		N32   , Gs2
	.byte	W36
	.byte		N44   , Cs2
	.byte	W48
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_6_027
	.byte	W12
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		N24   , Cs2
	.byte	W24
	.byte		N44   , Gs2
	.byte	W48
@ 030   ----------------------------------------
	.byte		N06   , Gs2 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs2 , v112
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte		        Dn2
	.byte	W12
@ 031   ----------------------------------------
	.byte	W12
	.byte		N32   , Fs2
	.byte	W36
	.byte		N44   , Bn1
	.byte	W48
@ 032   ----------------------------------------
	.byte		N06   , Bn1 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Fs2 , v112
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		        Bn1
	.byte	W24
	.byte		N24   
	.byte	W24
@ 033   ----------------------------------------
	.byte		N06   , Bn1 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Fs2 , v112
	.byte	W12
	.byte		        Bn1
	.byte	W24
	.byte		        Fs2
	.byte	W48
@ 034   ----------------------------------------
	.byte		N06   , Fs2 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn1 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 035   ----------------------------------------
	.byte		        Fn1
	.byte	W12
	.byte		        Cs2
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 036   ----------------------------------------
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N24   , Dn2
	.byte	W24
	.byte		        Bn1
	.byte	W12
@ 037   ----------------------------------------
	.byte	W12
	.byte		N12   , Gs2
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
@ 038   ----------------------------------------
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
@ 039   ----------------------------------------
	.byte	W12
	.byte		PAN   , c_v+23
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W84
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W12
	.byte		        c_v+16
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 79*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cn2 , v108
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 044   ----------------------------------------
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Gn1
	.byte	W06
	.byte		        Gn1 , v096
	.byte	W06
@ 045   ----------------------------------------
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn2 , v108
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 046   ----------------------------------------
mus_vs_champion_6_046:
	.byte	W24
	.byte		N12   , Cn2 , v108
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Gn1
	.byte	W06
	.byte		        Gn1 , v080
	.byte	W06
	.byte	PEND
@ 047   ----------------------------------------
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn2 , v108
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 048   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_6_046
	.byte		N06   , Gn1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , As1 , v100
	.byte	W36
	.byte		        As1 , v112
	.byte	W36
	.byte		N12   
	.byte	W12
@ 049   ----------------------------------------
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		        Fn1
	.byte	W12
@ 050   ----------------------------------------
	.byte	W12
	.byte		        An1
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 051   ----------------------------------------
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		        En1
	.byte	W12
@ 052   ----------------------------------------
	.byte	W12
	.byte		        Gs1
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 053   ----------------------------------------
	.byte	W24
	.byte		        Gn1
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		        Dn1
	.byte	W12
@ 054   ----------------------------------------
	.byte	W04
	.byte		N04   , Bn2
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		PAN   , c_v+32
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N08   , Gn2 , v064
	.byte	W08
	.byte		        Gn2 , v032
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Dn2 , v116
	.byte	W08
	.byte		        Gn2 , v080
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Gn2 , v064
	.byte	W08
	.byte		        Gn2 , v032
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Dn2 , v116
	.byte	W08
	.byte		        Gn2 , v084
	.byte	W04
@ 055   ----------------------------------------
	.byte	W04
	.byte		N08   
	.byte	W92
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W96
@ 060   ----------------------------------------
	.byte	W96
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	W96
@ 069   ----------------------------------------
	.byte	W12
	.byte		VOL   , 90*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		PAN   , c_v+19
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , An2 , v112
	.byte	W12
	.byte		        An1
	.byte	W72
@ 070   ----------------------------------------
	.byte	GOTO
	 .word	mus_vs_champion_6_B1
	.byte	W06
	.byte	FINE

@**************** Track 7 ****************@

mus_vs_champion_7:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_vs_champion_key+0
	.byte		VOICE , 17
	.byte		PAN   , c_v-64
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W12
	.byte		N24   , Bn4 , v127
	.byte		N24   , Bn5
	.byte	W24
	.byte		        As4
	.byte		N24   , As5
	.byte	W24
	.byte		        An4
	.byte		N24   , An5
	.byte	W24
	.byte		        Gs4
	.byte		N24   , Gs5
	.byte	W12
@ 002   ----------------------------------------
mus_vs_champion_7_002:
	.byte	W12
	.byte		N24   , Gn4 , v127
	.byte		N24   , Gn5
	.byte	W24
	.byte		        Fs4
	.byte		N24   , Fs5
	.byte	W24
	.byte		        Fn4
	.byte		N24   , Fn5
	.byte	W24
	.byte		        En4
	.byte		N24   , En5
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
	.byte	W12
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W24
	.byte		N12   , Fn2
	.byte		N12   , Fn3
	.byte	W12
	.byte		        En2
	.byte		N12   , En3
	.byte	W24
	.byte		        Gn2
	.byte		N12   , Gn3
	.byte	W12
	.byte		        Gs2
	.byte		N12   , Gs3
	.byte	W12
@ 004   ----------------------------------------
mus_vs_champion_7_B1:
	.byte	W24
	.byte		        As2
	.byte		N12   , As3
	.byte	W12
	.byte		        Bn2
	.byte		N12   , Bn3
	.byte	W24
	.byte		        Gn2
	.byte		N12   , Gn3
	.byte	W12
	.byte		        Gs2
	.byte		N12   , Gs3
	.byte	W12
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte	W06
	.byte		        Gn2
	.byte		N06   , Gn3
	.byte	W06
@ 005   ----------------------------------------
	.byte		N12   , Fs2
	.byte		N12   , Fs3
	.byte	W12
	.byte		N32   , Cn3
	.byte		N32   , Cn4
	.byte	W36
	.byte		N24   , Bn2
	.byte		N24   , Bn3
	.byte	W24
	.byte		        An2
	.byte		N24   , An3
	.byte	W24
@ 006   ----------------------------------------
	.byte		N12   , Gs2
	.byte		N12   , Gs3
	.byte	W12
	.byte		        Fs2
	.byte		N12   , Fs3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Fn3
	.byte	W12
	.byte		        Gs2
	.byte		N12   , Gs3
	.byte	W12
	.byte		        Cs2
	.byte		N12   , Cs3
	.byte	W12
	.byte		        Dn2
	.byte		N12   , Dn3
	.byte	W12
	.byte		        Cs2
	.byte		N12   , Cs3
	.byte	W12
	.byte		N06   , Cn2
	.byte		N06   , Cn3
	.byte	W06
	.byte		        Dn2
	.byte		N06   , Dn3
	.byte	W06
@ 007   ----------------------------------------
	.byte		N12   , Cs2
	.byte		N12   , Cs3
	.byte	W12
	.byte		        Cs2
	.byte		N12   , Cs3
	.byte	W12
	.byte		        Dn2
	.byte		N12   , Dn3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Fn3
	.byte	W12
	.byte		        En2
	.byte		N12   , En3
	.byte	W24
	.byte		        Gn2
	.byte		N12   , Gn3
	.byte	W12
	.byte		        Gs2
	.byte		N12   , Gs3
	.byte	W12
@ 008   ----------------------------------------
	.byte	W24
	.byte		        Cn3
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Dn3
	.byte		N12   , Dn4
	.byte	W24
	.byte		        As2
	.byte		N12   , As3
	.byte	W12
	.byte		        Bn2
	.byte		N12   , Bn3
	.byte	W12
	.byte		N06   , Gs2
	.byte		N06   , Gs3
	.byte	W06
	.byte		        As2
	.byte		N06   , As3
	.byte	W06
@ 009   ----------------------------------------
	.byte		N12   , An2
	.byte		N12   , An3
	.byte	W12
	.byte		N32   , En3
	.byte		N32   , En4
	.byte	W36
	.byte		N24   , Dn3
	.byte		N24   , Dn4
	.byte	W24
	.byte		        Cn3
	.byte		N24   , Cn4
	.byte	W24
@ 010   ----------------------------------------
	.byte		N12   , Gs2
	.byte		N12   , Gs3
	.byte	W12
	.byte		        Fs2
	.byte		N12   , Fs3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Fn3
	.byte	W12
	.byte		        Gs2
	.byte		N12   , Gs3
	.byte	W12
	.byte		        Cs2
	.byte		N12   , Cs3
	.byte	W12
	.byte		        Dn2
	.byte		N12   , Dn3
	.byte	W12
	.byte		        Cs2
	.byte		N12   , Cs3
	.byte	W12
	.byte		        Cn2
	.byte		N12   , Cn3
	.byte	W12
@ 011   ----------------------------------------
	.byte		        Cs2
	.byte		N12   , Cs3
	.byte	W12
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W24
	.byte		N24   , Bn2
	.byte		N24   , Bn3
	.byte	W48
	.byte		        Cn3
	.byte		N24   , Cn4
	.byte	W12
@ 012   ----------------------------------------
	.byte	W36
	.byte		        Cs3
	.byte		N24   , Cs4
	.byte	W48
	.byte		        Dn3
	.byte		N24   , Dn4
	.byte	W12
@ 013   ----------------------------------------
	.byte	W24
	.byte		N12   , Bn2
	.byte		N12   , Bn3
	.byte	W24
	.byte		        Cn3
	.byte		N12   , Cn4
	.byte	W24
	.byte		        Cs3
	.byte		N12   , Cs4
	.byte	W24
@ 014   ----------------------------------------
	.byte		        Dn3
	.byte		N12   , Dn4
	.byte	W24
	.byte		        Ds3
	.byte		N12   , Ds4
	.byte	W24
	.byte		        En3
	.byte		N12   , En4
	.byte	W24
	.byte		        Fn3
	.byte		N12   , Fn4
	.byte	W24
@ 015   ----------------------------------------
	.byte		        Fs3
	.byte		N12   , Fs4
	.byte	W24
	.byte		N32   , Gs3
	.byte		N32   , Gs4
	.byte	W36
	.byte		N12   , An3
	.byte		N12   , An4
	.byte	W24
	.byte		        Bn3
	.byte		N12   , Bn4
	.byte	W12
@ 016   ----------------------------------------
	.byte	W12
	.byte		        Cs4
	.byte		N12   , Cs5
	.byte	W12
	.byte		N32   , Bn3
	.byte		N32   , Bn4
	.byte	W36
	.byte		N12   , Cs4
	.byte		N12   , Cs5
	.byte	W24
	.byte		N24   , En4
	.byte		N24   , En5
	.byte	W12
@ 017   ----------------------------------------
	.byte	W12
	.byte		N92   , Bn3
	.byte		N92   , Bn4
	.byte	W84
@ 018   ----------------------------------------
	.byte	W12
	.byte		        Gs3
	.byte		N92   , Gs4
	.byte	W84
@ 019   ----------------------------------------
	.byte	W24
	.byte		N32   , Gs3
	.byte		N32   , Gs4
	.byte	W36
	.byte		N12   , An3
	.byte		N12   , An4
	.byte	W24
	.byte		N24   , Bn3
	.byte		N24   , Bn4
	.byte	W12
@ 020   ----------------------------------------
	.byte	W12
	.byte		N12   , Cs4
	.byte		N12   , Cs5
	.byte	W12
	.byte		N24   , Bn3
	.byte		N24   , Bn4
	.byte	W24
	.byte		N12   , Cs4
	.byte		N12   , Cs5
	.byte	W24
	.byte		N32   , En4
	.byte		N32   , En5
	.byte	W24
@ 021   ----------------------------------------
	.byte	W12
	.byte		N12   , Gn3
	.byte		N12   , Gn4
	.byte	W36
	.byte		        Gn3
	.byte		N12   , Gn4
	.byte	W36
	.byte		        Gn3
	.byte		N12   , Gn4
	.byte	W12
@ 022   ----------------------------------------
	.byte	W24
	.byte		N32   , En3
	.byte		N32   , En4
	.byte	W36
	.byte		N12   , Gn3
	.byte		N12   , Gn4
	.byte	W24
	.byte		        En3
	.byte		N12   , En4
	.byte	W12
@ 023   ----------------------------------------
	.byte	W12
	.byte		        Gs3
	.byte		N12   , Gs4
	.byte	W36
	.byte		        Gs3
	.byte		N12   , Gs4
	.byte	W36
	.byte		        Gs3
	.byte		N12   , Gs4
	.byte	W12
@ 024   ----------------------------------------
	.byte	W24
	.byte		N32   , En3
	.byte		N32   , En4
	.byte	W36
	.byte		N12   , Gs3
	.byte		N12   , Gs4
	.byte	W24
	.byte		        Gs3
	.byte		N12   , Gs4
	.byte	W12
@ 025   ----------------------------------------
	.byte	W12
	.byte		        An3
	.byte		N12   , An4
	.byte	W36
	.byte		        An3
	.byte		N12   , An4
	.byte	W36
	.byte		        An3
	.byte		N12   , An4
	.byte	W12
@ 026   ----------------------------------------
	.byte	W24
	.byte		N32   , Fs3
	.byte		N32   , Fs4
	.byte	W36
	.byte		N12   , Gs3
	.byte		N12   , Gs4
	.byte	W24
	.byte		N24   , Bn3
	.byte		N24   , Bn4
	.byte	W12
@ 027   ----------------------------------------
	.byte	W12
	.byte		N92   , Cs4
	.byte		N92   , Cs5
	.byte	W48
	.byte		VOL   , 28*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        25*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        21*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        19*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        15*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        14*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        11*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        8*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 028   ----------------------------------------
	.byte		        6*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        4*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        2*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        2*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W84
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W84
@ 033   ----------------------------------------
	.byte		N06   , Gs3
	.byte		N06   , Gs4 , v120
	.byte	W06
	.byte		        Bn3 , v127
	.byte		N06   , Bn4 , v120
	.byte	W06
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs4 , v127
	.byte		N12   , Cs5 , v120
	.byte	W12
	.byte		        Gs3 , v127
	.byte		N12   , Gs4 , v120
	.byte	W24
	.byte		N32   , Gs4 , v127
	.byte		N32   , Gs5 , v120
	.byte	W12
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , Cs5 , v127
	.byte		N24   , Cs6 , v120
	.byte	W12
@ 034   ----------------------------------------
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		N06   , Gs3 , v127
	.byte		N06   , Gs4 , v120
	.byte	W06
	.byte		        Bn3 , v127
	.byte		N06   , Bn4 , v120
	.byte	W06
	.byte		N24   , Cs4 , v127
	.byte		N24   , Cs5 , v120
	.byte	W12
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , Bn3 , v127
	.byte		N24   , Bn4 , v120
	.byte	W12
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , An3 , v127
	.byte		N24   , An4 , v120
	.byte	W12
@ 035   ----------------------------------------
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Fs3 , v127
	.byte		N12   , Fs4 , v120
	.byte	W12
	.byte		        Gs3 , v127
	.byte		N12   , Gs4 , v120
	.byte	W12
	.byte		        Fs3 , v127
	.byte		N12   , Fs4 , v120
	.byte	W12
	.byte		        En3 , v127
	.byte		N12   , En4 , v120
	.byte	W12
	.byte		N44   , Fs3 , v127
	.byte		N44   , Fs4 , v120
	.byte	W12
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W24
@ 036   ----------------------------------------
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W84
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
@ 037   ----------------------------------------
	.byte		N06   , Fs3 , v127
	.byte		N06   , Fs4 , v120
	.byte	W06
	.byte		        An3 , v127
	.byte		N06   , An4 , v120
	.byte	W06
	.byte		VOL   , 45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Bn3 , v127
	.byte		N12   , Bn4 , v120
	.byte	W12
	.byte		        Fs3 , v127
	.byte		N12   , Fs4 , v120
	.byte	W24
	.byte		N32   , Fs4 , v127
	.byte		N32   , Fs5 , v120
	.byte	W12
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , Bn4 , v127
	.byte		N24   , Bn5 , v120
	.byte	W12
@ 038   ----------------------------------------
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		N06   , Fs3 , v127
	.byte		N06   , Fs4 , v120
	.byte	W06
	.byte		        An3 , v127
	.byte		N06   , An4 , v120
	.byte	W06
	.byte		N24   , Bn3 , v127
	.byte		N24   , Bn4 , v120
	.byte	W12
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , Fs4 , v127
	.byte		N24   , Fs5 , v120
	.byte	W12
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , En4 , v127
	.byte		N24   , En5 , v120
	.byte	W12
@ 039   ----------------------------------------
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Cs4 , v127
	.byte		N12   , Cs5 , v120
	.byte	W12
	.byte		        Dn4 , v127
	.byte		N12   , Dn5 , v120
	.byte	W12
	.byte		        Cs4 , v127
	.byte		N12   , Cs5 , v120
	.byte	W12
	.byte		        Cn4 , v127
	.byte		N12   , Cn5 , v120
	.byte	W12
	.byte		N44   , Cs4 , v127
	.byte		N44   , Cs5 , v120
	.byte	W12
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W24
@ 040   ----------------------------------------
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W60
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W36
@ 041   ----------------------------------------
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Cs4 , v127
	.byte		N12   , Cs5
	.byte	W12
	.byte		        Cs4
	.byte		N12   , Cs5
	.byte	W24
	.byte		        Cs4
	.byte		N12   , Cs5
	.byte	W24
	.byte		        Cs4
	.byte		N12   , Cs5
	.byte	W24
@ 042   ----------------------------------------
	.byte		        Cs4
	.byte		N12   , Cs5
	.byte	W24
	.byte		        Cs4
	.byte		N12   , Cs5
	.byte	W24
	.byte		        Cs4
	.byte		N12   , Cs5
	.byte	W12
	.byte		        Cs4
	.byte		N12   , Cs5
	.byte	W24
	.byte		        Cs4
	.byte		N12   , Cs5
	.byte	W12
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	W96
@ 045   ----------------------------------------
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte	W24
	.byte		N32   , En3
	.byte		N32   , En4
	.byte	W36
	.byte		N12   , Fn3
	.byte		N12   , Fn4
	.byte	W24
	.byte		        Gn3
	.byte		N12   , Gn4
	.byte	W12
@ 048   ----------------------------------------
	.byte	W12
	.byte		        An3
	.byte		N12   , An4
	.byte	W12
	.byte		N32   , Gn3
	.byte		N32   , Gn4
	.byte	W36
	.byte		N12   , An3
	.byte		N12   , An4
	.byte	W24
	.byte		N24   , Cn4
	.byte		N24   , Cn5
	.byte	W12
@ 049   ----------------------------------------
	.byte	W12
	.byte		N92   , Gn3
	.byte		N92   , Gn4
	.byte	W84
@ 050   ----------------------------------------
	.byte	W12
	.byte		        En3
	.byte		N92   , En4
	.byte	W84
@ 051   ----------------------------------------
	.byte	W24
	.byte		N32   , En3
	.byte		N32   , En4
	.byte	W36
	.byte		N12   , Fn3
	.byte		N12   , Fn4
	.byte	W24
	.byte		N24   , Gn3
	.byte		N24   , Gn4
	.byte	W12
@ 052   ----------------------------------------
	.byte	W12
	.byte		N12   , An3
	.byte		N12   , An4
	.byte	W12
	.byte		N24   , Gn3
	.byte		N24   , Gn4
	.byte	W24
	.byte		N12   , An3
	.byte		N12   , An4
	.byte	W24
	.byte		N32   , Cn4
	.byte		N32   , Cn5
	.byte	W24
@ 053   ----------------------------------------
	.byte	W12
	.byte		N12   , Ds4
	.byte		N12   , Ds5
	.byte	W36
	.byte		        Ds4
	.byte		N12   , Ds5
	.byte	W36
	.byte		        Ds4
	.byte		N12   , Ds5
	.byte	W12
@ 054   ----------------------------------------
	.byte	W24
	.byte		N32   , Cn4
	.byte		N32   , Cn5
	.byte	W36
	.byte		N12   , Ds4
	.byte		N12   , Ds5
	.byte	W24
	.byte		        Cn4
	.byte		N12   , Cn5
	.byte	W12
@ 055   ----------------------------------------
	.byte	W12
	.byte		        En4
	.byte		N12   , En5
	.byte	W36
	.byte		        En4
	.byte		N12   , En5
	.byte	W36
	.byte		        En4
	.byte		N12   , En5
	.byte	W12
@ 056   ----------------------------------------
	.byte	W24
	.byte		N32   , Cn4
	.byte		N32   , Cn5
	.byte	W24
	.byte		VOL   , 27*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W01
	.byte		        21*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W01
	.byte		        11*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En4
	.byte		N12   , En5
	.byte	W24
	.byte		        En4
	.byte		N12   , En5
	.byte	W12
@ 057   ----------------------------------------
	.byte	W12
	.byte		        Fn4
	.byte		N12   , Fn5
	.byte	W36
	.byte		        Fn4
	.byte		N12   , Fn5
	.byte	W36
	.byte		        Fn4
	.byte		N12   , Fn5
	.byte	W12
@ 058   ----------------------------------------
	.byte	W24
	.byte		N32   , Dn4
	.byte		N32   , Dn5
	.byte	W24
	.byte		VOL   , 27*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W01
	.byte		        21*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W01
	.byte		        11*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , En4
	.byte		N12   , En5
	.byte	W24
	.byte		N92   , Gn4
	.byte		N92   , Gn5
	.byte	W12
@ 059   ----------------------------------------
	.byte	W36
	.byte		VOL   , 31*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        28*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        25*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        21*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        19*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        18*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        15*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        14*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        13*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        11*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		N06   , Fn4
	.byte		N06   , Fn5
	.byte	W06
@ 060   ----------------------------------------
	.byte		        Gn4
	.byte		N06   , Gn5
	.byte	W06
	.byte		        An4
	.byte		N06   , An5
	.byte	W06
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N06   , Cn5
	.byte		N06   , Cn6
	.byte	W18
	.byte		N03   , Fn4
	.byte		N03   , Fn5
	.byte	W06
	.byte		N68   , Fn4
	.byte		N68   , Fn5
	.byte	W24
	.byte		VOL   , 30*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        29*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        27*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        23*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        21*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        19*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 061   ----------------------------------------
	.byte		        15*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        13*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        12*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        11*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , Cn5
	.byte		N24   , Cn6
	.byte	W24
	.byte		        Bn4
	.byte		N24   , Bn5
	.byte	W24
	.byte		        An4
	.byte		N24   , An5
	.byte	W24
	.byte		        Bn4
	.byte		N24   , Bn5
	.byte	W12
@ 062   ----------------------------------------
	.byte	W12
	.byte		N06   , Gn4
	.byte		N06   , Gn5
	.byte	W06
	.byte		        An4
	.byte		N06   , An5
	.byte	W06
	.byte		        Gn4
	.byte		N06   , Gn5
	.byte	W06
	.byte		        Fs4
	.byte		N06   , Fs5
	.byte	W06
	.byte		N32   , Gn4
	.byte		N32   , Gn5
	.byte	W12
	.byte		VOL   , 30*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        27*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        25*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        19*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        15*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        14*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N12   , Dn4
	.byte		N12   , Dn5
	.byte	W12
	.byte		N24   , Gn3
	.byte		N24   , Gn4
	.byte	W12
@ 063   ----------------------------------------
	.byte	W12
	.byte		        Gn2
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W30
	.byte		N06   , En4
	.byte		N06   , En5
	.byte	W06
@ 064   ----------------------------------------
	.byte		        Fn4
	.byte		N06   , Fn5
	.byte	W06
	.byte		        Gn4
	.byte		N06   , Gn5
	.byte	W06
	.byte		        Bn4
	.byte		N06   , Bn5
	.byte	W18
	.byte		N03   , Dn4
	.byte		N03   , Dn5
	.byte	W06
	.byte		N68   , Dn4
	.byte		N68   , Dn5
	.byte	W24
	.byte		VOL   , 29*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        23*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        21*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        19*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        19*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        17*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        16*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
@ 065   ----------------------------------------
	.byte		        15*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        12*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        11*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , Gn4
	.byte		N24   , Gn5
	.byte	W24
	.byte		        Dn4
	.byte		N24   , Dn5
	.byte	W24
	.byte		        Bn4
	.byte		N24   , Bn5
	.byte	W24
	.byte		        An4
	.byte		N24   , An5
	.byte	W12
@ 066   ----------------------------------------
	.byte	W12
	.byte		N06   , Cs5
	.byte		N06   , Cs6
	.byte	W06
	.byte		        Dn5
	.byte		N06   , Dn6
	.byte	W06
	.byte		        Cs5
	.byte		N06   , Cs6
	.byte	W06
	.byte		        Bn4
	.byte		N06   , Bn5
	.byte	W06
	.byte		N44   , Cs5
	.byte		N44   , Cs6
	.byte	W24
	.byte		VOL   , 30*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        29*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        26*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        24*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        21*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        18*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        15*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		        14*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N02   , En3
	.byte	W08
	.byte		N02   
	.byte	W04
@ 067   ----------------------------------------
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W08
	.byte		N02   , Dn3
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 22*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N08   , Fn4
	.byte		N08   , Fn5
	.byte	W08
	.byte		        Gn4
	.byte		N08   , Gn5
	.byte	W04
@ 068   ----------------------------------------
	.byte	W04
	.byte		        An4
	.byte		N08   , An5
	.byte	W08
	.byte		N06   , Cn5
	.byte		N06   , Cn6
	.byte	W18
	.byte		N03   , Fn4
	.byte		N03   , Fn5
	.byte	W06
	.byte		N32   , Fn4
	.byte		N32   , Fn5
	.byte	W36
	.byte		N12   , Cn4
	.byte		N12   , Cn5
	.byte	W12
	.byte		        An3
	.byte		N12   , An4
	.byte	W12
@ 069   ----------------------------------------
	.byte		        Fn3
	.byte		N12   , Fn4
	.byte	W12
	.byte		        Cn3
	.byte		N12   , Cn4
	.byte	W12
	.byte		        An2
	.byte		N12   , An3
	.byte	W24
	.byte		        Cn3
	.byte		N12   , Cn4
	.byte	W24
	.byte		        Fn3
	.byte		N12   , Fn4
	.byte	W24
@ 070   ----------------------------------------
	.byte		        An3
	.byte		N12   , An4
	.byte	W12
	.byte		N06   , Cn5
	.byte		N06   , Cn6
	.byte	W18
	.byte		N03   , Fs4
	.byte		N03   , Fs5
	.byte	W06
	.byte		N32   , Fs4
	.byte		N32   , Fs5
	.byte	W36
	.byte		N12   , Cn4
	.byte		N12   , Cn5
	.byte	W12
	.byte		        An3
	.byte		N12   , An4
	.byte	W12
@ 071   ----------------------------------------
	.byte		        Fs3
	.byte		N12   , Fs4
	.byte	W12
	.byte		        Cn3
	.byte		N12   , Cn4
	.byte	W12
	.byte		        An2
	.byte		N12   , An3
	.byte	W24
	.byte		        Cn3
	.byte		N12   , Cn4
	.byte	W24
	.byte		        Fs3
	.byte		N12   , Fs4
	.byte	W24
@ 072   ----------------------------------------
	.byte		        An3
	.byte		N12   , An4
	.byte	W12
	.byte		N24   , Bn4
	.byte		N24   , Bn5
	.byte	W24
	.byte		        As4
	.byte		N24   , As5
	.byte	W24
	.byte		        An4
	.byte		N24   , An5
	.byte	W24
	.byte		        Gs4
	.byte		N24   , Gs5
	.byte	W12
@ 073   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_7_002
	.byte	W12
	.byte		VOL   , 34*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	W24
	.byte		N12   , Fn2 , v127
	.byte		N12   , Fn3
	.byte	W12
	.byte		        En2
	.byte		N12   , En3
	.byte	W24
	.byte		        Gn2
	.byte		N12   , Gn3
	.byte	W12
	.byte		        Gs2
	.byte		N12   , Gs3
	.byte	W12
@ 074   ----------------------------------------
	.byte	GOTO
	 .word	mus_vs_champion_7_B1
	.byte	W06
	.byte	FINE

@**************** Track 8 ****************@

mus_vs_champion_8:
@ 000   ----------------------------------------
	.byte		VOL   , 127*mus_vs_champion_mvl/mxv
	.byte	KEYSH , mus_vs_champion_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N06   , Cn1 , v127
	.byte		N24   , An2
	.byte	W48
	.byte		N06   , Cn1
	.byte		N24   , Gn2
	.byte	W36
@ 001   ----------------------------------------
	.byte	W28
	.byte		N08   , Cn1 , v124
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W20
@ 002   ----------------------------------------
	.byte	W04
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N24   , Cn3 , v127
	.byte	W12
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
mus_vs_champion_8_B1:
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W96
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
	.byte	W96
@ 019   ----------------------------------------
	.byte	W96
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W96
@ 022   ----------------------------------------
	.byte	W96
@ 023   ----------------------------------------
	.byte	W96
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	W96
@ 037   ----------------------------------------
	.byte	W96
@ 038   ----------------------------------------
	.byte	W96
@ 039   ----------------------------------------
	.byte	W96
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	W96
@ 045   ----------------------------------------
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte	W96
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W12
	.byte		        An2
	.byte	W48
	.byte		        Gn2
	.byte	W36
@ 060   ----------------------------------------
mus_vs_champion_8_060:
	.byte	W12
	.byte		N06   , Cn1 , v127
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PEND
@ 061   ----------------------------------------
mus_vs_champion_8_061:
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte	PEND
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_8_060
mus_vs_champion_8_062:
	.byte	W12
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte	PEND
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_8_060
	.byte	PATT
	 .word	mus_vs_champion_8_061
	.byte	W12
	.byte		N06   , Cn1 , v127
	.byte	W24
	.byte		        Dn1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Dn1
	.byte	W12
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_8_061
	.byte	PATT
	 .word	mus_vs_champion_8_062
	.byte	W12
	.byte		N06   , Cn1 , v127
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Dn1
	.byte	W12
@ 065   ----------------------------------------
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Cn1
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Dn1
	.byte	W12
@ 066   ----------------------------------------
	.byte	W12
	.byte		        Cn1
	.byte	W24
	.byte		        Dn1
	.byte	W12
	.byte		        Cn1
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Dn1
	.byte	W12
@ 067   ----------------------------------------
	.byte		        Cn1
	.byte	W28
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W20
@ 068   ----------------------------------------
	.byte	W04
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N24   , Cn3
	.byte	W12
@ 069   ----------------------------------------
	.byte	W96
@ 070   ----------------------------------------
	.byte	GOTO
	 .word	mus_vs_champion_8_B1
	.byte	W06
	.byte	FINE

@**************** Track 9 ****************@

mus_vs_champion_9:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_vs_champion_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 45*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W12
	.byte		N02   , Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
@ 002   ----------------------------------------
mus_vs_champion_9_002:
	.byte		N02   , Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_9_002
mus_vs_champion_9_B1:
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
mus_vs_champion_9_003:
	.byte		N02   , Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte	PEND
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte	PATT
	 .word	mus_vs_champion_9_003
	.byte		N02   , Cn5 , v016
	.byte	W12
	.byte		VOL   , 55*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N02   , Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte		N02   , Cn5 , v016
	.byte	W12
	.byte		VOL   , 44*mus_vs_champion_mvl/mxv
	.byte	PRIO  , 0
	.byte		N02   , Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_champion_9_002
	.byte		N02   , Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
@ 007   ----------------------------------------
	.byte	GOTO
	 .word	mus_vs_champion_9_B1
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

mus_vs_champion:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_vs_champion_pri	@ Priority
	.byte	mus_vs_champion_rev	@ Reverb.

	.word	mus_vs_champion_grp

	.word	mus_vs_champion_1
	.word	mus_vs_champion_2
	.word	mus_vs_champion_3
	.word	mus_vs_champion_4
	.word	mus_vs_champion_5
	.word	mus_vs_champion_6
	.word	mus_vs_champion_7
	.word	mus_vs_champion_8
	.word	mus_vs_champion_9

	.end
