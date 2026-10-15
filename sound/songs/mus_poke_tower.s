	.include "MPlayDef.s"

@ ShinyGold: Now Gold/Silver/Crystal "Sprout Tower" (map music of the Sprout Tower maps).
@
@ The hack edited this song header in place (keeping the song ID) to point at new track data
@ it inserted at 0x08A033B0; voicegroup changed from voicegroup165 to voicegroup162, 6 -> 6 tracks.
@ Disassembled from the hack ROM (no MIDI source exists).  Labels replace the hack's
@ absolute pointers; the byte stream of every track is identical to the hack's.
@ `_mvl` is 127, so `VOL , N*_mvl/mxv` emits N unchanged (edit _mvl to rescale volumes).

	.equ	mus_poke_tower_grp, voicegroup162
	.equ	mus_poke_tower_pri, 0
	.equ	mus_poke_tower_rev, reverb_set+50
	.equ	mus_poke_tower_mvl, 127
	.equ	mus_poke_tower_key, 0
	.equ	mus_poke_tower_tbs, 1
	.equ	mus_poke_tower_exg, 0
	.equ	mus_poke_tower_cmp, 1

	.section .rodata
	.global	mus_poke_tower
	.align	2

@**************** Track 1 ****************@

mus_poke_tower_1:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_poke_tower_key+0
	.byte	TEMPO , 108*mus_poke_tower_tbs/2
	.byte		VOICE , 81
	.byte		VOL   , 127*mus_poke_tower_mvl/mxv
	.byte		N12   , Fn1 , v127
	.byte	W24
	.byte		        Cn1
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Ds1
	.byte	W24
	.byte		        Fs1
	.byte	W12
@ 001   ----------------------------------------
mus_poke_tower_1_001:
	.byte		N12   , Fn1 , v127
	.byte	W24
	.byte		        Cn1
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Ds1
	.byte	W24
	.byte		        Fs1
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
mus_poke_tower_1_B1:
	.byte	PATT
	 .word	mus_poke_tower_1_001
	.byte	PATT
	 .word	mus_poke_tower_1_001
	.byte		N12   , Ds1 , v127
	.byte	W24
	.byte		        As0
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Ds1
	.byte	W24
	.byte		        Fs1
	.byte	W12
@ 003   ----------------------------------------
	.byte		        Fn1
	.byte	W24
	.byte		        Cn1
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        Cn1
	.byte	W24
	.byte		        Fn1
	.byte	W12
@ 004   ----------------------------------------
	.byte		        Ds1
	.byte	W24
	.byte		        As0
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		        As0
	.byte	W24
	.byte		        Ds1
	.byte	W12
@ 005   ----------------------------------------
	.byte		        Fs1
	.byte	W24
	.byte		        Cs1
	.byte	W12
	.byte		        Fn1
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Ds1
	.byte	W24
	.byte		        Fs1
	.byte	W12
@ 006   ----------------------------------------
	.byte		N96   , Fn1
	.byte	W96
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_tower_1_001
	.byte	PATT
	 .word	mus_poke_tower_1_001
	.byte	GOTO
	 .word	mus_poke_tower_1_B1
	.byte	W96
@ 008   ----------------------------------------
	.byte	FINE

@**************** Track 2 ****************@

mus_poke_tower_2:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_poke_tower_key+0
	.byte		VOICE , 48
	.byte		VOL   , 93*mus_poke_tower_mvl/mxv
	.byte		N12   , Fn2 , v092
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Fs2
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        Cs3
	.byte	W12
@ 001   ----------------------------------------
mus_poke_tower_2_001:
	.byte		N12   , Fn2 , v092
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Fs2
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
mus_poke_tower_2_B1:
	.byte	PATT
	 .word	mus_poke_tower_2_001
	.byte		N12   , Fn2 , v092
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        Cs3
	.byte	W12
@ 003   ----------------------------------------
	.byte		        Ds2
	.byte	W12
	.byte		        Fs2
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        Fs2
	.byte	W12
@ 004   ----------------------------------------
	.byte		        Fn2
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        As3
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		        Fn3
	.byte	W12
@ 005   ----------------------------------------
	.byte		N06   , Ds2
	.byte		N12   , Cs5
	.byte	W06
	.byte		N06   , Fs2
	.byte	W06
	.byte		        As2
	.byte		N12   , Cn5
	.byte	W06
	.byte		N06   , Cs3
	.byte	W06
	.byte		        Fs2
	.byte		N12   , As4
	.byte	W06
	.byte		N06   , As2
	.byte	W06
	.byte		        Cs3
	.byte		N12   , Fs4
	.byte	W06
	.byte		N06   , Ds3
	.byte	W06
	.byte		        Fs3
	.byte		N48   , As4
	.byte	W06
	.byte		N06   , Ds3
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Fs3
	.byte	W06
	.byte		        Ds3
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        As2
	.byte	W06
	.byte		        Fs2
	.byte	W06
@ 006   ----------------------------------------
	.byte		        As2
	.byte		N12   , Cn5
	.byte	W06
	.byte		N06   , Cs3
	.byte	W06
	.byte		        Fn3
	.byte		N12   , As4
	.byte	W06
	.byte		N06   , Fs3
	.byte	W06
	.byte		        As3
	.byte		N12   , Fs4
	.byte	W06
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Fn3
	.byte		N12   , Ds4
	.byte	W06
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Fn3
	.byte		N48   , Fn4
	.byte	W06
	.byte		N06   , Cs3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        As2
	.byte	W06
	.byte		        Fs2
	.byte	W06
	.byte		        As2
	.byte	W06
@ 007   ----------------------------------------
	.byte		N96   , Fn2
	.byte	W96
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_tower_2_001
	.byte	PATT
	 .word	mus_poke_tower_2_001
	.byte	GOTO
	 .word	mus_poke_tower_2_B1
	.byte	W96
@ 009   ----------------------------------------
	.byte	FINE

@**************** Track 3 ****************@

mus_poke_tower_3:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_poke_tower_key+0
	.byte		VOICE , 4
	.byte		VOL   , 100*mus_poke_tower_mvl/mxv
	.byte		N12   , Cn3 , v127
	.byte		N12   , Fn3
	.byte	W24
	.byte		N24   , Cn3
	.byte		N24   , Fn3
	.byte	W24
	.byte		N12   , Cs3
	.byte		N12   , Fs3
	.byte	W24
	.byte		N24   , Cs3
	.byte		N24   , Fs3
	.byte	W24
@ 001   ----------------------------------------
mus_poke_tower_3_001:
	.byte		N12   , Cn3 , v127
	.byte		N12   , Fn3
	.byte	W24
	.byte		N24   , Cn3
	.byte		N24   , Fn3
	.byte	W24
	.byte		N12   , As2
	.byte		N12   , Ds3
	.byte	W24
	.byte		N24   , As2
	.byte		N24   , Ds3
	.byte	W24
	.byte	PEND
@ 002   ----------------------------------------
mus_poke_tower_3_B1:
	.byte		N12   , Cn3 , v127
	.byte		N12   , Fn3
	.byte	W24
	.byte		N24   , Cn3
	.byte		N24   , Fn3
	.byte	W24
	.byte		N12   , Cs3
	.byte		N12   , Fs3
	.byte	W24
	.byte		N24   , Cs3
	.byte		N24   , Fs3
	.byte	W24
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_tower_3_B1
	.byte		N12   , As2 , v127
	.byte		N12   , Ds3
	.byte	W24
	.byte		N24   , As2
	.byte		N24   , Ds3
	.byte	W24
	.byte		N12   , Cs3
	.byte		N12   , Fs3
	.byte	W24
	.byte		N24   , Cs3
	.byte		N24   , Fs3
	.byte	W24
@ 004   ----------------------------------------
	.byte		N12   , Cn3
	.byte		N12   , Fn3
	.byte	W12
	.byte		        Cs3
	.byte		N12   , Fs3
	.byte	W12
	.byte		        Ds3
	.byte		N12   , Gs3
	.byte	W12
	.byte		        Cs3
	.byte		N12   , Fs3
	.byte	W12
	.byte		        Cn3
	.byte		N12   , Fn3
	.byte	W24
	.byte		N24   , Cn3
	.byte		N24   , Fn3
	.byte	W24
@ 005   ----------------------------------------
	.byte		N12   , Cs3
	.byte		N12   , Fs3
	.byte	W24
	.byte		N24   , Cs3
	.byte		N24   , Fs3
	.byte	W24
	.byte		N12   , As2
	.byte		N12   , Ds3
	.byte	W24
	.byte		N24   , As2
	.byte		N24   , Ds3
	.byte	W24
@ 006   ----------------------------------------
	.byte		N12   , Cs3
	.byte		N12   , Fs3
	.byte	W24
	.byte		N24   , Cs3
	.byte		N24   , Fs3
	.byte	W24
	.byte		N12   , Fn3
	.byte		N12   , As3
	.byte	W24
	.byte		N24   , Fn3
	.byte		N24   , As3
	.byte	W24
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_tower_3_B1
	.byte	PATT
	 .word	mus_poke_tower_3_B1
	.byte	PATT
	 .word	mus_poke_tower_3_001
	.byte	GOTO
	 .word	mus_poke_tower_3_B1
	.byte	W96
@ 008   ----------------------------------------
	.byte	FINE

@**************** Track 4 ****************@

mus_poke_tower_4:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_poke_tower_key+0
	.byte		VOICE , 17
	.byte		VOL   , 127*mus_poke_tower_mvl/mxv
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
mus_poke_tower_4_B1:
	.byte		N24   , Cn5 , v127
	.byte	W24
	.byte		N18   , As4
	.byte	W18
	.byte		N01   , Cn5
	.byte	W01
	.byte		        Cs5
	.byte	W02
	.byte		        Ds5
	.byte	W01
	.byte		N24   , Cs5
	.byte	W24
	.byte		N06   , Cn5
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N01   , Cs5
	.byte	W02
	.byte		        Cn5
	.byte	W01
	.byte		        Cs5
	.byte	W02
	.byte		N06   , As4
	.byte	W06
	.byte		        Cs5
	.byte	W06
@ 003   ----------------------------------------
	.byte		N12   , Cn5
	.byte	W12
	.byte		        As4
	.byte	W12
	.byte		N18   , Fs4
	.byte	W18
	.byte		N03   , As4
	.byte	W03
	.byte		        Fs4
	.byte	W03
	.byte		N48   , Fn4
	.byte	W48
@ 004   ----------------------------------------
	.byte		N24   , Fs4
	.byte	W24
	.byte		        As4
	.byte	W24
	.byte		N12   , Cn5
	.byte	W12
	.byte		N09   , Cs5
	.byte	W09
	.byte		N01   , Ds5
	.byte	W01
	.byte		        Cs5
	.byte	W02
	.byte		N06   , Cn5
	.byte	W06
	.byte		N03   , Cs5
	.byte	W03
	.byte		        Cn5
	.byte	W03
	.byte		N12   , As4
	.byte	W12
@ 005   ----------------------------------------
	.byte		        Cn5
	.byte	W12
	.byte		        Cs5
	.byte	W12
	.byte		        Ds5
	.byte	W12
	.byte		N09   , Cs5
	.byte	W09
	.byte		N01   , Ds5
	.byte	W01
	.byte		        Cs5
	.byte	W02
	.byte		N48   , Cn5
	.byte	W48
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte		        Fn4
	.byte	W48
	.byte		N24   , Fs4
	.byte	W24
	.byte		N18   , As4
	.byte	W18
	.byte		N03   , Fs4
	.byte	W03
	.byte		        As4
	.byte	W03
@ 009   ----------------------------------------
	.byte		TIE   , Cn5
	.byte	W96
@ 010   ----------------------------------------
	.byte	W48
	.byte		EOT   
	.byte	W48
@ 011   ----------------------------------------
	.byte	GOTO
	 .word	mus_poke_tower_4_B1
	.byte	W96
@ 012   ----------------------------------------
	.byte	FINE

@**************** Track 5 ****************@

mus_poke_tower_5:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_poke_tower_key+0
	.byte		VOICE , 14
	.byte		VOL   , 105*mus_poke_tower_mvl/mxv
	.byte		N96   , Fn3 , v127
	.byte	W96
@ 001   ----------------------------------------
	.byte	W72
	.byte		N24   , Fn4
	.byte	W24
@ 002   ----------------------------------------
mus_poke_tower_5_B1:
	.byte		        Cn5
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W48
	.byte		        Fn4
	.byte	W24
	.byte		        Cn4
	.byte	W24
@ 006   ----------------------------------------
	.byte		        Cs4
	.byte	W72
	.byte		        Ds4
	.byte	W24
@ 007   ----------------------------------------
	.byte		        As3
	.byte	W96
@ 008   ----------------------------------------
	.byte		        Cn4
	.byte	W96
@ 009   ----------------------------------------
	.byte		N96   , Fn3
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	GOTO
	 .word	mus_poke_tower_5_B1
	.byte	W96
@ 012   ----------------------------------------
	.byte	FINE

@**************** Track 6 ****************@

mus_poke_tower_6:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_poke_tower_key+0
	.byte		VOICE , 0
	.byte		VOL   , 111*mus_poke_tower_mvl/mxv
	.byte		N12   , Fs1 , v127
	.byte		N96   , En2
	.byte	W12
	.byte		N12   , Gs1
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , Fn1
	.byte		N12   , Fs1
	.byte	W12
	.byte		        Gs1
	.byte	W24
	.byte		N12   
	.byte	W12
@ 001   ----------------------------------------
mus_poke_tower_6_001:
	.byte		N12   , Fs1 , v127
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		N24   , Cn2
	.byte	W12
	.byte		N12   , Gs1
	.byte	W12
	.byte		        Fs1
	.byte		N24   , Bn4
	.byte	W12
	.byte		N12   , Gs1
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
mus_poke_tower_6_B1:
	.byte		N12   , Fs1 , v127
	.byte		N96   , En2
	.byte	W12
	.byte		N12   , Gs1
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , Fn1
	.byte		N12   , Fs1
	.byte	W12
	.byte		        Gs1
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_tower_6_001
	.byte		N12   , Fs1 , v127
	.byte	W12
	.byte		        Gs1
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , Fn1
	.byte		N12   , Fs1
	.byte	W12
	.byte		        Gs1
	.byte	W24
	.byte		N12   
	.byte	W12
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_tower_6_001
	.byte	PATT
	 .word	mus_poke_tower_6_B1
	.byte	PATT
	 .word	mus_poke_tower_6_001
	.byte		N24   , En2 , v127
	.byte	W48
	.byte		        Bn4
	.byte	W48
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_tower_6_B1
	.byte	PATT
	 .word	mus_poke_tower_6_001
	.byte	GOTO
	 .word	mus_poke_tower_6_B1
	.byte	W96
@ 006   ----------------------------------------
	.byte	FINE

@******************************************************@
	.align	2

mus_poke_tower:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_poke_tower_pri	@ Priority
	.byte	mus_poke_tower_rev	@ Reverb.

	.word	mus_poke_tower_grp

	.word	mus_poke_tower_1
	.word	mus_poke_tower_2
	.word	mus_poke_tower_3
	.word	mus_poke_tower_4
	.word	mus_poke_tower_5
	.word	mus_poke_tower_6

	.end
