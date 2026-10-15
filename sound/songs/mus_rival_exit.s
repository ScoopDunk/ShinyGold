	.include "MPlayDef.s"

@ ShinyGold: Now a battle theme (not identified: no melodic match in GSC or FRLG music).
@ Used through the hack's music-swap scripts in place of MUS_VS_TRAINER /
@ MUS_VS_GYM_LEADER, mostly for Team Rocket battles.
@
@ The hack edited this song header in place (keeping the song ID) to point at new track data
@ it inserted at 0x08A0A500; voicegroup changed from voicegroup174 to voicegroup011, 9 -> 7 tracks.
@ Disassembled from the hack ROM (no MIDI source exists).  Labels replace the hack's
@ absolute pointers; the byte stream of every track is identical to the hack's.
@ `_mvl` is 127, so `VOL , N*_mvl/mxv` emits N unchanged (edit _mvl to rescale volumes).

	.equ	mus_rival_exit_grp, voicegroup011
	.equ	mus_rival_exit_pri, 0
	.equ	mus_rival_exit_rev, reverb_set+50
	.equ	mus_rival_exit_mvl, 127
	.equ	mus_rival_exit_key, 0
	.equ	mus_rival_exit_tbs, 1
	.equ	mus_rival_exit_exg, 0
	.equ	mus_rival_exit_cmp, 1

	.section .rodata
	.global	mus_rival_exit
	.align	2

@**************** Track 1 ****************@

mus_rival_exit_1:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_rival_exit_key+0
	.byte	TEMPO , 202*mus_rival_exit_tbs/2
	.byte		VOICE , 56
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 80*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W42
	.byte		N06   , Dn3 , v127
	.byte	W06
	.byte		N92   , Ds3
	.byte	W48
@ 004   ----------------------------------------
	.byte	W54
	.byte		N06   , Dn3
	.byte	W06
	.byte		N12   , Ds3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
@ 005   ----------------------------------------
	.byte		        Fs3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		N92   , Ds3
	.byte	W48
@ 006   ----------------------------------------
mus_rival_exit_1_006:
	.byte	W60
	.byte		N12   , Ds3 , v127
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
	.byte		        Fs3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		N92   , Ds3
	.byte	W48
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_1_006
	.byte		N12   , Fs3 , v127
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		TIE   , Ds3
	.byte	W48
@ 009   ----------------------------------------
	.byte	W32
	.byte	W01
	.byte		VOL   , 76*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W09
	.byte		        73*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W09
	.byte		        68*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W09
	.byte		        59*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W09
	.byte		        50*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W09
	.byte		        38*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        25*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        13*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
@ 010   ----------------------------------------
	.byte		EOT   
	.byte	W42
	.byte		VOL   , 80*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte		N06   , En3
	.byte	W06
	.byte		N92   , Fn3
	.byte	W48
@ 011   ----------------------------------------
mus_rival_exit_1_011:
	.byte	W54
	.byte		N06   , En3 , v127
	.byte	W06
	.byte		N12   , Fn3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte	PEND
@ 012   ----------------------------------------
mus_rival_exit_1_012:
	.byte		N12   , Gs3 , v127
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		N92   , Fn3
	.byte	W48
	.byte	PEND
@ 013   ----------------------------------------
mus_rival_exit_1_013:
	.byte	W60
	.byte		N12   , Fn3 , v127
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte	PEND
@ 014   ----------------------------------------
mus_rival_exit_1_014:
	.byte		N12   , Gs3 , v127
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        As3
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		N92   , Fn3
	.byte	W48
	.byte	PEND
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_1_013
	.byte		N12   , Gs3 , v127
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		TIE   , Fn3
	.byte	W48
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte		EOT   
mus_rival_exit_1_B1:
	.byte		N44   , Fs3
	.byte	W48
	.byte		N92   , Gn3
	.byte	W48
@ 018   ----------------------------------------
mus_rival_exit_1_018:
	.byte	W60
	.byte		N12   , Gn3 , v127
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Gn3
	.byte	W12
	.byte	PEND
@ 019   ----------------------------------------
	.byte		        As3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Gn3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		N92   , Gn3
	.byte	W48
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_1_018
	.byte		N12   , As3 , v127
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		N92   , Gn3
	.byte	W48
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_1_018
	.byte		N12   , As3 , v127
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Gn3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		N68   , Gn3
	.byte	W48
@ 022   ----------------------------------------
	.byte	W24
	.byte		        Dn4
	.byte	W72
@ 023   ----------------------------------------
	.byte		N44   , Cn4
	.byte	W48
	.byte		VOICE , 48
	.byte		PAN   , c_v-10
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N32   , Bn3
	.byte	W36
	.byte		        As3
	.byte	W12
@ 024   ----------------------------------------
	.byte	W24
	.byte		N24   , Fs3
	.byte	W24
	.byte		N32   , An3
	.byte	W36
	.byte		        Gn3
	.byte	W12
@ 025   ----------------------------------------
	.byte	W24
	.byte		N24   , En3
	.byte	W24
	.byte		N32   , Fs3
	.byte	W36
	.byte		        Gn3
	.byte	W12
@ 026   ----------------------------------------
	.byte	W24
	.byte		N24   , Fs3
	.byte	W24
	.byte		TIE   , Ds3
	.byte	W48
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W48
	.byte		EOT   
	.byte		TIE   , Ds2
	.byte	W48
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W48
	.byte		EOT   
	.byte		VOICE , 60
	.byte		N32   , Cn2
	.byte	W36
	.byte		        Cs2
	.byte	W12
@ 031   ----------------------------------------
	.byte	W24
	.byte		N24   , Fs2
	.byte	W24
	.byte		N32   , Fn2
	.byte	W36
	.byte		        Cs2
	.byte	W12
@ 032   ----------------------------------------
	.byte	W24
	.byte		N24   , Bn1
	.byte	W24
	.byte		N32   , Cn2
	.byte	W36
	.byte		        Cs2
	.byte	W12
@ 033   ----------------------------------------
	.byte	W24
	.byte		N24   , Fs2
	.byte	W24
	.byte		N32   , Fn2
	.byte	W36
	.byte		        Fs2
	.byte	W12
@ 034   ----------------------------------------
	.byte	W24
	.byte		N24   , Ds2
	.byte	W24
	.byte		N32   , Fn2
	.byte	W36
	.byte		        Fs2
	.byte	W12
@ 035   ----------------------------------------
	.byte	W24
	.byte		N24   , Bn2
	.byte	W24
	.byte		N32   , As2
	.byte	W36
	.byte		        Fs2
	.byte	W12
@ 036   ----------------------------------------
	.byte	W24
	.byte		N24   , En2
	.byte	W24
	.byte		N32   , Fn2
	.byte	W36
	.byte		        Fs2
	.byte	W12
@ 037   ----------------------------------------
	.byte	W24
	.byte		N24   , Bn2
	.byte	W24
	.byte		N32   , As2
	.byte	W36
	.byte		        Bn2
	.byte	W12
@ 038   ----------------------------------------
	.byte	W24
	.byte		N24   , Cs3
	.byte	W24
	.byte		VOICE , 56
	.byte		N12   , Cn3
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs3
	.byte	W24
@ 039   ----------------------------------------
mus_rival_exit_1_039:
	.byte		N12   , Cn3 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Ds3
	.byte	W24
	.byte		N12   , Cn3
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En3
	.byte	W24
	.byte	PEND
@ 040   ----------------------------------------
	.byte		N12   , Fn3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs3
	.byte	W24
@ 041   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_1_039
	.byte		N24   , Fn3 , v127
	.byte	W24
	.byte		        En3
	.byte	W24
	.byte		VOICE , 48
	.byte		N12   , Cn4
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs4
	.byte	W24
@ 042   ----------------------------------------
mus_rival_exit_1_042:
	.byte		N12   , Cn4 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Ds4
	.byte	W24
	.byte		N12   , Cn4
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En4
	.byte	W24
	.byte	PEND
@ 043   ----------------------------------------
	.byte		N12   , Fn4
	.byte	W12
	.byte		        En4
	.byte	W12
	.byte		        Cs4
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs4
	.byte	W24
@ 044   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_1_042
	.byte		N24   , Fn4 , v127
	.byte	W24
	.byte		        En4
	.byte	W24
	.byte		TIE   , Fn4
	.byte	W48
@ 045   ----------------------------------------
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte	W96
@ 048   ----------------------------------------
	.byte	W48
	.byte		EOT   
	.byte		TIE   , Fn5
	.byte	W24
	.byte		VOL   , 78*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W15
	.byte		        74*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W09
@ 049   ----------------------------------------
	.byte	W06
	.byte		        70*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        68*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        65*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        62*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W15
	.byte		        59*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        55*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W18
	.byte		        58*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W09
@ 050   ----------------------------------------
	.byte	W06
	.byte		        61*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        63*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        66*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        69*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        70*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        74*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W12
	.byte		        77*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W09
	.byte		        80*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W09
@ 051   ----------------------------------------
	.byte	W66
	.byte		        76*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W09
	.byte		        72*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W09
	.byte		        68*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W09
	.byte		        62*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
@ 052   ----------------------------------------
	.byte	W06
	.byte		        56*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W09
	.byte		        46*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        34*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		        22*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
	.byte		        10*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W03
	.byte		        5*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		EOT   
	.byte	W03
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte		N06   , En3
	.byte	W06
	.byte		N92   , Fn3
	.byte	W48
@ 053   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_1_011
	.byte	PATT
	 .word	mus_rival_exit_1_012
	.byte	PATT
	 .word	mus_rival_exit_1_013
	.byte	PATT
	 .word	mus_rival_exit_1_014
	.byte	PATT
	 .word	mus_rival_exit_1_013
	.byte		N12   , Gs3 , v127
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		N68   , Fn3
	.byte	W48
@ 054   ----------------------------------------
	.byte	W24
	.byte		N44   , Cn4
	.byte	W48
	.byte		N24   , Fn3
	.byte	W24
@ 055   ----------------------------------------
	.byte	GOTO
	 .word	mus_rival_exit_1_B1
	.byte	W06
	.byte	FINE

@**************** Track 2 ****************@

mus_rival_exit_2:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_rival_exit_key+0
	.byte		VOICE , 33
	.byte		VOL   , 80*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte		N24   , Ds0 , v116
	.byte	W24
	.byte		        Fs0
	.byte	W24
	.byte		        En0
	.byte	W24
	.byte		        Ds0
	.byte	W24
@ 001   ----------------------------------------
	.byte		        Cs0
	.byte	W24
	.byte		        En0
	.byte	W24
	.byte		        Ds0
	.byte	W24
	.byte		        Cs0
	.byte	W24
@ 002   ----------------------------------------
	.byte		        Ds0
	.byte	W24
	.byte		        Fs0
	.byte	W24
	.byte		        En0
	.byte	W24
	.byte		        Ds0
	.byte	W24
@ 003   ----------------------------------------
	.byte		        Cs0
	.byte	W24
	.byte		        BnM1
	.byte	W24
	.byte		N12   , Ds0
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Ds0
	.byte	W12
	.byte		        As0
	.byte	W12
@ 004   ----------------------------------------
	.byte		        Ds0
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Ds0
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Ds0
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Ds0
	.byte	W12
	.byte		        As0
	.byte	W12
@ 005   ----------------------------------------
mus_rival_exit_2_005:
	.byte		N12   , Fs0 , v116
	.byte	W12
	.byte		        Gs0
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Bn0
	.byte	W12
	.byte		        Ds0
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Ds0
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
mus_rival_exit_2_006:
	.byte		N12   , Ds0 , v116
	.byte	W12
	.byte		        Fs0
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Bn0
	.byte	W12
	.byte		        Ds0
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Ds0
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
	.byte		        Ds0
	.byte	W12
	.byte		        Bn0
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Gs0
	.byte	W12
	.byte		        Ds0
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Ds0
	.byte	W12
	.byte		        As0
	.byte	W12
@ 008   ----------------------------------------
	.byte		        Ds0
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Ds0
	.byte	W12
	.byte		        Bn0
	.byte	W12
	.byte		        Ds0
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Ds0
	.byte	W12
	.byte		        As0
	.byte	W12
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_2_005
	.byte	PATT
	 .word	mus_rival_exit_2_006
	.byte		N12   , Ds0 , v116
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        An0
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
@ 010   ----------------------------------------
mus_rival_exit_2_010:
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
mus_rival_exit_2_011:
	.byte		N12   , Gs0 , v116
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte	PEND
@ 012   ----------------------------------------
mus_rival_exit_2_012:
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Gs0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte	PEND
@ 013   ----------------------------------------
mus_rival_exit_2_013:
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte	PEND
@ 014   ----------------------------------------
mus_rival_exit_2_014:
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte	PEND
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_2_011
	.byte	PATT
	 .word	mus_rival_exit_2_012
mus_rival_exit_2_B1:
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Fs0
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        An0
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
@ 016   ----------------------------------------
mus_rival_exit_2_016:
	.byte		N12   , Gn0 , v116
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte	PEND
@ 017   ----------------------------------------
mus_rival_exit_2_017:
	.byte		N12   , As0 , v116
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte	PEND
@ 018   ----------------------------------------
mus_rival_exit_2_018:
	.byte		N12   , Gn0 , v116
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte	PEND
@ 019   ----------------------------------------
	.byte		        Gn0
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
@ 020   ----------------------------------------
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_2_017
	.byte	PATT
	 .word	mus_rival_exit_2_018
	.byte		N12   , Gn0 , v116
	.byte	W12
	.byte		        Gs0
	.byte	W12
	.byte		        An0
	.byte	W12
	.byte		        Bn0
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Dn1
	.byte	W12
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_2_016
	.byte	PATT
	 .word	mus_rival_exit_2_016
	.byte		N12   , Gn0 , v116
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Gs0
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Gs0
	.byte	W12
	.byte		        Ds1
	.byte	W12
@ 023   ----------------------------------------
mus_rival_exit_2_023:
	.byte		N12   , Gs0 , v116
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Gs0
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Gs0
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Gs0
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte	PEND
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_2_023
	.byte	PATT
	 .word	mus_rival_exit_2_023
	.byte		N12   , Gs0 , v116
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Gs0
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
@ 025   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_2_010
mus_rival_exit_2_025:
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Bn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte	PEND
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_2_010
	.byte	PATT
	 .word	mus_rival_exit_2_025
	.byte	PATT
	 .word	mus_rival_exit_2_010
	.byte	PATT
	 .word	mus_rival_exit_2_025
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        Fs1
	.byte	W12
@ 027   ----------------------------------------
	.byte		        Fn1
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
@ 028   ----------------------------------------
mus_rival_exit_2_028:
	.byte		N12   , Gn0 , v116
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte	PEND
@ 029   ----------------------------------------
	.byte		        Gn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_2_028
	.byte		N12   , Gn0 , v116
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
@ 031   ----------------------------------------
	.byte		        Gn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
@ 032   ----------------------------------------
	.byte		        Cs1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
@ 033   ----------------------------------------
	.byte		        Gn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        As0
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
@ 034   ----------------------------------------
	.byte		        Gn0
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_2_010
	.byte	PATT
	 .word	mus_rival_exit_2_010
	.byte	PATT
	 .word	mus_rival_exit_2_010
	.byte	PATT
	 .word	mus_rival_exit_2_010
	.byte	PATT
	 .word	mus_rival_exit_2_010
	.byte	PATT
	 .word	mus_rival_exit_2_010
	.byte	PATT
	 .word	mus_rival_exit_2_010
	.byte		N12   , Cs1 , v116
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Fn0
	.byte	W12
	.byte		        Cn1
	.byte	W12
@ 036   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_2_010
	.byte	PATT
	 .word	mus_rival_exit_2_011
	.byte	PATT
	 .word	mus_rival_exit_2_012
	.byte	PATT
	 .word	mus_rival_exit_2_013
	.byte	PATT
	 .word	mus_rival_exit_2_014
	.byte	PATT
	 .word	mus_rival_exit_2_011
	.byte	PATT
	 .word	mus_rival_exit_2_012
	.byte	GOTO
	 .word	mus_rival_exit_2_B1
	.byte	W06
	.byte	FINE

@**************** Track 3 ****************@

mus_rival_exit_3:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_rival_exit_key+0
	.byte		VOICE , 17
	.byte		PAN   , c_v-48
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 80*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W48
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N06   , Ds4 , v064
	.byte		N06   , Ds5 , v052
	.byte	W36
	.byte		        Ds4 , v064
	.byte		N06   , Ds5 , v052
	.byte	W12
@ 004   ----------------------------------------
	.byte	W24
	.byte		        Ds4 , v064
	.byte		N06   , Ds5 , v052
	.byte	W24
	.byte		        Ds4 , v064
	.byte		N06   , Ds5 , v052
	.byte	W36
	.byte		        Ds4 , v064
	.byte		N06   , Ds5 , v052
	.byte	W12
@ 005   ----------------------------------------
mus_rival_exit_3_005:
	.byte	W24
	.byte		N24   , En4 , v064
	.byte		N24   , En5 , v052
	.byte	W24
	.byte		N06   , Ds4 , v064
	.byte		N06   , Ds5 , v052
	.byte	W48
	.byte	PEND
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W48
	.byte		        Ds4 , v064
	.byte		N06   , Ds5 , v052
	.byte	W36
	.byte		        Ds4 , v064
	.byte		N06   , Ds5 , v052
	.byte	W12
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_3_005
	.byte	W96
@ 010   ----------------------------------------
mus_rival_exit_3_010:
	.byte	W48
	.byte		N06   , Fn4 , v064
	.byte		N06   , Fn5 , v052
	.byte	W36
	.byte		        Fn4 , v064
	.byte		N06   , Fn5 , v052
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
	.byte	W24
	.byte		        Fn4 , v064
	.byte		N06   , Fn5 , v052
	.byte	W24
	.byte		        Fn4 , v064
	.byte		N06   , Fn5 , v052
	.byte	W36
	.byte		        Fn4 , v064
	.byte		N06   , Fn5 , v052
	.byte	W12
@ 012   ----------------------------------------
mus_rival_exit_3_012:
	.byte	W24
	.byte		N24   , Fs4 , v064
	.byte		N24   , Fs5 , v052
	.byte	W24
	.byte		N06   , Fn4 , v064
	.byte		N06   , Fn5 , v052
	.byte	W48
	.byte	PEND
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_3_010
	.byte	PATT
	 .word	mus_rival_exit_3_012
	.byte	W96
@ 016   ----------------------------------------
mus_rival_exit_3_B1:
	.byte	W48
	.byte		PAN   , c_v-48
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N06   , Gn4 , v064
	.byte		N06   , Gn5 , v052
	.byte	W36
	.byte		        Gn4 , v064
	.byte		N06   , Gn5 , v052
	.byte	W12
@ 017   ----------------------------------------
	.byte	W24
	.byte		        Gn4 , v064
	.byte		N06   , Gn5 , v052
	.byte	W24
	.byte		        Gn4 , v064
	.byte		N06   , Gn5 , v052
	.byte	W36
	.byte		        Gn4 , v064
	.byte		N06   , Gn5 , v052
	.byte	W12
@ 018   ----------------------------------------
mus_rival_exit_3_018:
	.byte	W24
	.byte		N24   , Gs4 , v064
	.byte		N24   , Gs5 , v052
	.byte	W24
	.byte		N06   , Gn4 , v064
	.byte		N06   , Gn5 , v052
	.byte	W48
	.byte	PEND
@ 019   ----------------------------------------
	.byte	W96
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W48
	.byte		        Gn4 , v064
	.byte		N06   , Gn5 , v052
	.byte	W36
	.byte		        Gn4 , v064
	.byte		N06   , Gn5 , v052
	.byte	W12
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_3_018
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
	.byte	W48
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W12
	.byte		N12   , Cn3 , v072
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        Cn3
	.byte	W12
@ 033   ----------------------------------------
	.byte		        Ds3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		N92   , Cn3
	.byte	W48
@ 034   ----------------------------------------
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	W96
@ 037   ----------------------------------------
	.byte	W96
@ 038   ----------------------------------------
	.byte	W48
	.byte		PAN   , c_v+48
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N12   , Cn2
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs2
	.byte	W24
@ 039   ----------------------------------------
mus_rival_exit_3_039:
	.byte		N12   , Cn2 , v072
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Ds2
	.byte	W24
	.byte		N12   , Cn2
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En2
	.byte	W24
	.byte	PEND
@ 040   ----------------------------------------
	.byte		N12   , Fn2
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs2
	.byte	W24
@ 041   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_3_039
	.byte		N24   , Fn2 , v072
	.byte	W24
	.byte		        En2
	.byte	W24
	.byte		N12   , Cn3
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs3
	.byte	W24
@ 042   ----------------------------------------
mus_rival_exit_3_042:
	.byte		N12   , Cn3 , v072
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Ds3
	.byte	W24
	.byte		N12   , Cn3
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En3
	.byte	W24
	.byte	PEND
@ 043   ----------------------------------------
	.byte		N12   , Fn3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs3
	.byte	W24
@ 044   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_3_042
	.byte		N12   , Cn3 , v072
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Fn3 , v088
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 045   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Bn2
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 046   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 047   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fs2
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 048   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn2
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 049   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 050   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        As1
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 051   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 052   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W60
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W48
	.byte		PAN   , c_v-48
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N06   , Fn4 , v064
	.byte		N06   , Fn5 , v052
	.byte	W36
	.byte		        Fn4 , v064
	.byte		N06   , Fn5 , v052
	.byte	W12
@ 058   ----------------------------------------
	.byte	W24
	.byte		N24   , Fs4 , v064
	.byte		N24   , Fs5 , v052
	.byte	W24
	.byte		N06   , Fn4 , v064
	.byte		N06   , Fn5 , v052
	.byte	W48
@ 059   ----------------------------------------
	.byte	W96
@ 060   ----------------------------------------
	.byte	GOTO
	 .word	mus_rival_exit_3_B1
	.byte	W06
	.byte	FINE

@**************** Track 4 ****************@

mus_rival_exit_4:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_rival_exit_key+0
	.byte		VOICE , 81
	.byte		PAN   , c_v+48
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 80*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W48
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N06   , As3 , v068
	.byte		N06   , As4 , v056
	.byte	W36
	.byte		        As3 , v068
	.byte		N06   , As4 , v056
	.byte	W12
@ 004   ----------------------------------------
	.byte	W24
	.byte		        As3 , v068
	.byte		N06   , As4 , v056
	.byte	W24
	.byte		        As3 , v068
	.byte		N06   , As4 , v056
	.byte	W36
	.byte		        As3 , v068
	.byte		N06   , As4 , v056
	.byte	W12
@ 005   ----------------------------------------
mus_rival_exit_4_005:
	.byte	W24
	.byte		N24   , Bn3 , v068
	.byte		N24   , Bn4 , v056
	.byte	W24
	.byte		N06   , As3 , v068
	.byte		N06   , As4 , v056
	.byte	W48
	.byte	PEND
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W48
	.byte		        As3 , v068
	.byte		N06   , As4 , v056
	.byte	W36
	.byte		        As3 , v068
	.byte		N06   , As4 , v056
	.byte	W12
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_4_005
	.byte	W96
@ 010   ----------------------------------------
mus_rival_exit_4_010:
	.byte	W48
	.byte		N06   , Cn4 , v068
	.byte		N06   , Cn5 , v056
	.byte	W36
	.byte		        Cn4 , v068
	.byte		N06   , Cn5 , v056
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
	.byte	W24
	.byte		        Cn4 , v068
	.byte		N06   , Cn5 , v056
	.byte	W24
	.byte		        Cn4 , v068
	.byte		N06   , Cn5 , v056
	.byte	W36
	.byte		        Cn4 , v068
	.byte		N06   , Cn5 , v056
	.byte	W12
@ 012   ----------------------------------------
mus_rival_exit_4_012:
	.byte	W24
	.byte		N24   , Cs4 , v068
	.byte		N24   , Cs5 , v056
	.byte	W24
	.byte		N06   , Cn4 , v068
	.byte		N06   , Cn5 , v056
	.byte	W48
	.byte	PEND
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_4_010
	.byte	PATT
	 .word	mus_rival_exit_4_012
	.byte	W96
@ 016   ----------------------------------------
mus_rival_exit_4_B1:
	.byte	W48
	.byte		PAN   , c_v+48
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		N06   , Dn4 , v068
	.byte		N06   , Dn5 , v056
	.byte	W36
	.byte		        Dn4 , v068
	.byte		N06   , Dn5 , v056
	.byte	W12
@ 017   ----------------------------------------
	.byte	W24
	.byte		        Dn4 , v068
	.byte		N06   , Dn5 , v056
	.byte	W24
	.byte		        Dn4 , v068
	.byte		N06   , Dn5 , v056
	.byte	W36
	.byte		        Dn4 , v068
	.byte		N06   , Dn5 , v056
	.byte	W12
@ 018   ----------------------------------------
mus_rival_exit_4_018:
	.byte	W24
	.byte		N24   , Ds4 , v068
	.byte		N24   , Ds5 , v056
	.byte	W24
	.byte		N06   , Dn4 , v068
	.byte		N06   , Dn5 , v056
	.byte	W48
	.byte	PEND
@ 019   ----------------------------------------
	.byte	W96
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W48
	.byte		        Dn4 , v068
	.byte		N06   , Dn5 , v056
	.byte	W36
	.byte		        Dn4 , v068
	.byte		N06   , Dn5 , v056
	.byte	W12
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_4_018
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
	.byte	W48
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		BEND  , c_v-3
	.byte	W18
	.byte		N12   , Cn3 , v016
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        Cn3
	.byte	W06
@ 033   ----------------------------------------
	.byte	W06
	.byte		        Ds3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W06
@ 034   ----------------------------------------
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W54
@ 035   ----------------------------------------
	.byte	W48
	.byte		BEND  , c_v+0
	.byte	W48
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
	.byte	W48
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		BEND  , c_v-2
	.byte		N12   , Bn1 , v092
	.byte	W12
	.byte		        Ds2
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        Fs2
	.byte	W12
@ 047   ----------------------------------------
	.byte		        Gn2
	.byte	W12
	.byte		        An2
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        Bn2
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Bn2
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        An2
	.byte	W12
@ 048   ----------------------------------------
	.byte		        Gn2
	.byte	W12
	.byte		        Fs2
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        Ds2
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        Fn2
	.byte	W12
	.byte		        Fs2
	.byte	W12
	.byte		        Gs2
	.byte	W12
@ 049   ----------------------------------------
	.byte		        An2
	.byte	W12
	.byte		        Bn2
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Dn3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Bn2
	.byte	W12
@ 050   ----------------------------------------
	.byte		        An2
	.byte	W12
	.byte		        Gs2
	.byte	W12
	.byte		        Fs2
	.byte	W12
	.byte		        Fn2
	.byte	W12
	.byte		        Ds2
	.byte	W12
	.byte		        Gn2
	.byte	W12
	.byte		        Gs2
	.byte	W12
	.byte		        As2
	.byte	W12
@ 051   ----------------------------------------
	.byte		        Bn2
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Dn3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Dn3
	.byte	W12
	.byte		        Cs3
	.byte	W12
@ 052   ----------------------------------------
	.byte		        Bn2
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        Gs2
	.byte	W12
	.byte		        Gn2
	.byte	W12
	.byte		        Fn2
	.byte	W12
	.byte		        An2
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        Cn3
	.byte	W12
@ 053   ----------------------------------------
	.byte		        Cs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Ds3
	.byte	W12
@ 054   ----------------------------------------
	.byte		        Cs3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        An2
	.byte	W60
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W48
	.byte		PAN   , c_v+48
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		BEND  , c_v+0
	.byte		N06   , Cn4 , v068
	.byte		N06   , Cn5 , v056
	.byte	W36
	.byte		        Cn4 , v068
	.byte		N06   , Cn5 , v056
	.byte	W12
@ 060   ----------------------------------------
	.byte	W24
	.byte		N24   , Cs4 , v068
	.byte		N24   , Cs5 , v056
	.byte	W24
	.byte		N06   , Cn4 , v068
	.byte		N06   , Cn5 , v056
	.byte	W48
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	GOTO
	 .word	mus_rival_exit_4_B1
	.byte	W06
	.byte	FINE

@**************** Track 5 ****************@

mus_rival_exit_5:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_rival_exit_key+0
	.byte		VOICE , 81
	.byte		VOL   , 80*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
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
	.byte		N12   , Cn3 , v060
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
@ 012   ----------------------------------------
mus_rival_exit_5_012:
	.byte	W24
	.byte		N12   , Cn3 , v060
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 013   ----------------------------------------
mus_rival_exit_5_013:
	.byte	W24
	.byte		N12   , Cn3 , v060
	.byte	W12
	.byte		N06   , Fn2
	.byte	W06
	.byte		        As2
	.byte	W06
	.byte		N12   , Cn3
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_5_012
mus_rival_exit_5_014:
	.byte	W24
	.byte		N12   , Cn3 , v060
	.byte	W12
	.byte		N06   , Cs3
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn3
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_5_012
	.byte	PATT
	 .word	mus_rival_exit_5_013
	.byte	PATT
	 .word	mus_rival_exit_5_012
mus_rival_exit_5_B1:
	.byte		N12   , Cs3 , v060
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Dn3
	.byte	W24
	.byte		        Gn2
	.byte	W12
	.byte		        Dn3
	.byte	W12
@ 016   ----------------------------------------
mus_rival_exit_5_016:
	.byte		N12   , Gn2 , v060
	.byte	W24
	.byte		        Dn3
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Fn2
	.byte	W12
	.byte		        Dn3
	.byte	W12
	.byte	PEND
@ 017   ----------------------------------------
	.byte		        Gn2
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Dn3
	.byte	W12
	.byte		N06   , Gn2
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		N12   , Dn3
	.byte	W24
	.byte		        Gn2
	.byte	W12
	.byte		        Dn3
	.byte	W12
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_5_016
	.byte		N12   , Gn2 , v060
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn3
	.byte	W24
	.byte		        Gn2
	.byte	W12
	.byte		        Dn3
	.byte	W12
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_5_016
	.byte		N12   , Gn2 , v060
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Dn3
	.byte	W12
	.byte		N06   , Gn2
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		N12   , Dn3
	.byte	W24
	.byte		        Gn2
	.byte	W12
	.byte		        Ds3
	.byte	W12
@ 020   ----------------------------------------
	.byte		        Gn2
	.byte	W24
	.byte		        Dn3
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gn2
	.byte	W12
	.byte		        Dn3
	.byte	W12
	.byte		        Fs3
	.byte	W12
@ 021   ----------------------------------------
	.byte		N44   , Gn3
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
	.byte	W48
	.byte		N12   , Cn3
	.byte	W36
	.byte		N12   
	.byte	W12
@ 053   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_5_012
	.byte	PATT
	 .word	mus_rival_exit_5_013
	.byte	PATT
	 .word	mus_rival_exit_5_012
	.byte	PATT
	 .word	mus_rival_exit_5_014
	.byte	PATT
	 .word	mus_rival_exit_5_012
	.byte	PATT
	 .word	mus_rival_exit_5_013
	.byte	PATT
	 .word	mus_rival_exit_5_012
	.byte	GOTO
	 .word	mus_rival_exit_5_B1
	.byte	W06
	.byte	FINE

@**************** Track 6 ****************@

mus_rival_exit_6:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_rival_exit_key+0
	.byte		VOICE , 127
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 80*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W48
	.byte		VOICE , 126
	.byte	W48
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
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
	.byte		PAN   , c_v+0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte	W24
	.byte		VOICE , 0
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
@ 012   ----------------------------------------
mus_rival_exit_6_012:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
mus_rival_exit_6_B1:
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
mus_rival_exit_6_013:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		        Ds1 , v092
	.byte	W24
@ 015   ----------------------------------------
mus_rival_exit_6_015:
	.byte	W24
	.byte		N12   , Ds1 , v092
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_6_015
	.byte	W24
	.byte		N12   , Ds1 , v092
	.byte	W48
	.byte		        Dn1 , v112
	.byte	W24
@ 017   ----------------------------------------
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_013
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
@ 019   ----------------------------------------
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
mus_rival_exit_6_020:
	.byte	W12
	.byte		N12   , Dn1 , v112
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_020
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	PATT
	 .word	mus_rival_exit_6_012
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
@ 022   ----------------------------------------
	.byte	GOTO
	 .word	mus_rival_exit_6_B1
	.byte	W06
	.byte	FINE

@**************** Track 7 ****************@

mus_rival_exit_7:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_rival_exit_key+0
	.byte		VOICE , 47
	.byte		PAN   , c_v+8
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 80*mus_rival_exit_mvl/mxv
	.byte	PRIO  , 0
	.byte		N92   , Ds2 , v112
	.byte	W96
@ 001   ----------------------------------------
	.byte		N44   
	.byte	W48
	.byte		N92   
	.byte	W48
@ 002   ----------------------------------------
	.byte	W72
	.byte		N24   , Gn2
	.byte	W24
@ 003   ----------------------------------------
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N32   
	.byte	W36
	.byte		N32   
	.byte	W12
@ 004   ----------------------------------------
mus_rival_exit_7_004:
	.byte	W24
	.byte		N24   , Cn2 , v112
	.byte	W24
	.byte		N32   , Gn2
	.byte	W36
	.byte		N32   
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
mus_rival_exit_7_005:
	.byte	W24
	.byte		N12   , Cn2 , v112
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn2
	.byte	W06
	.byte		N32   , Gn2
	.byte	W36
	.byte		N32   
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_7_004
	.byte	PATT
	 .word	mus_rival_exit_7_005
	.byte	PATT
	 .word	mus_rival_exit_7_004
	.byte	PATT
	 .word	mus_rival_exit_7_004
	.byte	PATT
	 .word	mus_rival_exit_7_004
mus_rival_exit_7_006:
	.byte	W36
	.byte		N06   , Cn2 , v112
	.byte	W06
	.byte		        Fn2
	.byte	W06
	.byte		N12   , Gn2
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
mus_rival_exit_7_007:
	.byte	W48
	.byte		N12   , Gn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_006
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
mus_rival_exit_7_B1:
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_006
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_006
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	W96
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	W12
	.byte		N12   , Gn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Dn2
	.byte	W24
	.byte		        Gn2
	.byte	W12
@ 013   ----------------------------------------
mus_rival_exit_7_013:
	.byte		N12   , Dn2 , v112
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		        Fn2
	.byte	W12
	.byte		        Gn2
	.byte	W12
	.byte		        Dn2
	.byte	W24
	.byte		        Gn2
	.byte	W12
	.byte	PEND
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_7_013
	.byte	PATT
	 .word	mus_rival_exit_7_013
	.byte		N12   , Dn2 , v112
	.byte	W12
	.byte		        Gn2
	.byte	W24
	.byte		        Dn2
	.byte	W12
	.byte		        Gn2
	.byte	W12
	.byte		        Dn2
	.byte	W24
	.byte		        Gn2
	.byte	W12
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_7_013
	.byte	PATT
	 .word	mus_rival_exit_7_013
	.byte	PATT
	 .word	mus_rival_exit_7_013
	.byte		N12   , Dn2 , v112
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Gn2
	.byte	W36
	.byte		N12   
	.byte	W12
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_006
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	PATT
	 .word	mus_rival_exit_7_007
	.byte	GOTO
	 .word	mus_rival_exit_7_B1
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

mus_rival_exit:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rival_exit_pri	@ Priority
	.byte	mus_rival_exit_rev	@ Reverb.

	.word	mus_rival_exit_grp

	.word	mus_rival_exit_1
	.word	mus_rival_exit_2
	.word	mus_rival_exit_3
	.word	mus_rival_exit_4
	.word	mus_rival_exit_5
	.word	mus_rival_exit_6
	.word	mus_rival_exit_7

	.end
