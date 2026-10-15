	.include "MPlayDef.s"

@ ShinyGold: Now Gold/Silver/Crystal "Goldenrod City" (map music of Goldenrod City).
@
@ The hack edited this song header in place (keeping the song ID) to point at new track data
@ it inserted at 0x08A02840; voicegroup changed from voicegroup132 to voicegroup152, 8 -> 7 tracks.
@ Disassembled from the hack ROM (no MIDI source exists).  Labels replace the hack's
@ absolute pointers; the byte stream of every track is identical to the hack's.
@ `_mvl` is 127, so `VOL , N*_mvl/mxv` emits N unchanged (edit _mvl to rescale volumes).

	.equ	mus_poke_jump_grp, voicegroup152
	.equ	mus_poke_jump_pri, 0
	.equ	mus_poke_jump_rev, reverb_set+50
	.equ	mus_poke_jump_mvl, 127
	.equ	mus_poke_jump_key, 0
	.equ	mus_poke_jump_tbs, 1
	.equ	mus_poke_jump_exg, 0
	.equ	mus_poke_jump_cmp, 1

	.section .rodata
	.global	mus_poke_jump
	.align	2

@**************** Track 1 ****************@

mus_poke_jump_1:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_poke_jump_key+0
	.byte	TEMPO , 120*mus_poke_jump_tbs/2
	.byte		VOICE , 81
	.byte		VOL   , 113*mus_poke_jump_mvl/mxv
	.byte		N36   , Cs2 , v096
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N36   , Cn2
	.byte	W36
	.byte		N12   
	.byte	W12
@ 001   ----------------------------------------
mus_poke_jump_1_001:
	.byte		N36   , As1 , v096
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N36   , Gs1
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
mus_poke_jump_1_002:
	.byte		N36   , Fs1 , v096
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N36   , Ds2
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
mus_poke_jump_1_003:
	.byte		N36   , Gs2 , v096
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   , Gs2
	.byte	W12
	.byte	PEND
@ 004   ----------------------------------------
mus_poke_jump_1_004:
	.byte		N36   , Cs2 , v096
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N36   , Cn2
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_jump_1_001
	.byte	PATT
	 .word	mus_poke_jump_1_002
	.byte	PATT
	 .word	mus_poke_jump_1_003
mus_poke_jump_1_005:
	.byte		N06   , Cs2 , v104
	.byte	W12
	.byte		        Cs3
	.byte	W06
	.byte		        Cs2
	.byte	W18
	.byte		N06   
	.byte	W36
	.byte		        Cn3
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		N12   , Gs2
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
mus_poke_jump_1_006:
	.byte		N06   , Cn2 , v104
	.byte	W12
	.byte		        Cn3
	.byte	W06
	.byte		        Cn2
	.byte	W18
	.byte		N06   
	.byte	W36
	.byte		        Bn2
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		N12   , Gs2
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
mus_poke_jump_1_007:
	.byte		N06   , As1 , v104
	.byte	W12
	.byte		        As2
	.byte	W06
	.byte		        As1
	.byte	W18
	.byte		N06   
	.byte	W36
	.byte		        An2
	.byte	W06
	.byte		        As2
	.byte	W06
	.byte		N12   , Fs2
	.byte	W12
	.byte	PEND
@ 008   ----------------------------------------
mus_poke_jump_1_008:
	.byte		N06   , Gs1 , v104
	.byte	W12
	.byte		        Gs2
	.byte	W06
	.byte		        Gs1
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		        Cn2
	.byte	W06
	.byte		        Ds2
	.byte	W06
	.byte		N12   , Gs2
	.byte	W12
	.byte		        Ds2
	.byte	W12
	.byte	PEND
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_jump_1_005
	.byte	PATT
	 .word	mus_poke_jump_1_006
	.byte	PATT
	 .word	mus_poke_jump_1_007
mus_poke_jump_1_009:
	.byte		N06   , Gs1 , v104
	.byte	W12
	.byte		        Gs2
	.byte	W06
	.byte		        Gs1
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N24   , Gs2
	.byte	W24
	.byte		N12   , Ds2
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte	PEND
@ 010   ----------------------------------------
mus_poke_jump_1_B1:
	.byte		N36   , Cs2 , v096
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N36   , Cn2
	.byte	W36
	.byte		N12   
	.byte	W12
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_jump_1_001
	.byte	PATT
	 .word	mus_poke_jump_1_002
	.byte	PATT
	 .word	mus_poke_jump_1_003
	.byte	PATT
	 .word	mus_poke_jump_1_004
	.byte	PATT
	 .word	mus_poke_jump_1_001
	.byte	PATT
	 .word	mus_poke_jump_1_002
	.byte	PATT
	 .word	mus_poke_jump_1_003
	.byte	PATT
	 .word	mus_poke_jump_1_005
	.byte	PATT
	 .word	mus_poke_jump_1_006
	.byte	PATT
	 .word	mus_poke_jump_1_007
	.byte	PATT
	 .word	mus_poke_jump_1_008
	.byte	PATT
	 .word	mus_poke_jump_1_005
	.byte	PATT
	 .word	mus_poke_jump_1_006
	.byte	PATT
	 .word	mus_poke_jump_1_007
	.byte	PATT
	 .word	mus_poke_jump_1_009
	.byte	GOTO
	 .word	mus_poke_jump_1_B1
	.byte	W06
	.byte	FINE

@**************** Track 2 ****************@

mus_poke_jump_2:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_poke_jump_key+0
	.byte		VOICE , 56
	.byte		VOL   , 127*mus_poke_jump_mvl/mxv
	.byte		N24   , Fn4 , v127
	.byte	W24
	.byte		        Cs4
	.byte	W24
	.byte		        Ds4
	.byte	W24
	.byte		        Cn4
	.byte	W24
@ 001   ----------------------------------------
mus_poke_jump_2_001:
	.byte		N12   , Cs4 , v127
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		        As3
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		N36   , Gs3
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte	PEND
@ 002   ----------------------------------------
mus_poke_jump_2_002:
	.byte		N24   , As3 , v127
	.byte	W24
	.byte		        Cs4
	.byte	W24
	.byte		N12   , As3
	.byte	W12
	.byte		        As4
	.byte	W12
	.byte		        Gs4
	.byte	W12
	.byte		        Fs4
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
mus_poke_jump_2_003:
	.byte		N12   , Fn4 , v127
	.byte	W12
	.byte		        Fs4
	.byte	W12
	.byte		        Gs4
	.byte	W12
	.byte		        Fn4
	.byte	W12
	.byte		N48   , Ds4
	.byte	W48
	.byte	PEND
@ 004   ----------------------------------------
mus_poke_jump_2_004:
	.byte		N12   , Cs4 , v127
	.byte	W12
	.byte		        Gs3
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		        Gs3
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
mus_poke_jump_2_005:
	.byte		N12   , As3 , v127
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
mus_poke_jump_2_006:
	.byte		N12   , Fs3 , v127
	.byte	W12
	.byte		        Cs3
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        As3
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
mus_poke_jump_2_007:
	.byte		N12   , Cs3 , v127
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Cs4
	.byte	W12
	.byte		N06   , Gs3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		        Cn5
	.byte	W06
	.byte	PEND
@ 008   ----------------------------------------
mus_poke_jump_2_008:
	.byte		N36   , Cs5 , v127
	.byte	W36
	.byte		        Fn5
	.byte	W36
	.byte		N24   , Cs5
	.byte	W24
	.byte	PEND
@ 009   ----------------------------------------
mus_poke_jump_2_009:
	.byte		N36   , Cn5 , v127
	.byte	W36
	.byte		        Ds5
	.byte	W36
	.byte		N12   , Cn5
	.byte	W12
	.byte		N06   , Gs4
	.byte	W06
	.byte		        An4
	.byte	W06
	.byte	PEND
@ 010   ----------------------------------------
mus_poke_jump_2_010:
	.byte		N36   , As4 , v127
	.byte	W36
	.byte		        Cs5
	.byte	W36
	.byte		N24   , As4
	.byte	W24
	.byte	PEND
@ 011   ----------------------------------------
mus_poke_jump_2_011:
	.byte		N24   , Cn5 , v127
	.byte	W24
	.byte		N12   , Ds5
	.byte	W12
	.byte		        Gs4
	.byte	W12
	.byte		        As4
	.byte	W12
	.byte		        Bn4
	.byte	W12
	.byte		N24   , Cn5
	.byte	W24
	.byte	PEND
@ 012   ----------------------------------------
	.byte	W96
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
mus_poke_jump_2_B1:
	.byte		        Fn4
	.byte	W24
	.byte		        Cs4
	.byte	W24
	.byte		        Ds4
	.byte	W24
	.byte		        Cn4
	.byte	W24
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_jump_2_001
	.byte	PATT
	 .word	mus_poke_jump_2_002
	.byte	PATT
	 .word	mus_poke_jump_2_003
	.byte	PATT
	 .word	mus_poke_jump_2_004
	.byte	PATT
	 .word	mus_poke_jump_2_005
	.byte	PATT
	 .word	mus_poke_jump_2_006
	.byte	PATT
	 .word	mus_poke_jump_2_007
	.byte	PATT
	 .word	mus_poke_jump_2_008
	.byte	PATT
	 .word	mus_poke_jump_2_009
	.byte	PATT
	 .word	mus_poke_jump_2_010
	.byte	PATT
	 .word	mus_poke_jump_2_011
	.byte	W96
@ 018   ----------------------------------------
	.byte	W96
@ 019   ----------------------------------------
	.byte	W96
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	GOTO
	 .word	mus_poke_jump_2_B1
	.byte	W06
	.byte	FINE

@**************** Track 3 ****************@

mus_poke_jump_3:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_poke_jump_key+0
	.byte		VOICE , 14
	.byte		VOL   , 101*mus_poke_jump_mvl/mxv
	.byte		N48   , Cs4 , v127
	.byte	W48
	.byte		        Cn4
	.byte	W48
@ 001   ----------------------------------------
	.byte		        As3
	.byte	W48
	.byte		        Gs3
	.byte	W48
@ 002   ----------------------------------------
	.byte		N24   , Fs3
	.byte	W24
	.byte		        As3
	.byte	W24
	.byte		        Cs4
	.byte	W24
	.byte		        Ds4
	.byte	W24
@ 003   ----------------------------------------
	.byte		        Gs3
	.byte	W24
	.byte		        Cs4
	.byte	W24
	.byte		        Cn4
	.byte	W24
	.byte		        Fs4
	.byte	W24
@ 004   ----------------------------------------
	.byte		N48   , Fn4
	.byte	W48
	.byte		        Ds4
	.byte	W48
@ 005   ----------------------------------------
	.byte		N12   , Cs4
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		N24   , As3
	.byte	W24
	.byte		N48   , Gs3
	.byte	W48
@ 006   ----------------------------------------
	.byte		N24   , Fs3
	.byte	W24
	.byte		        As3
	.byte	W24
	.byte		        Ds4
	.byte	W24
	.byte		        Fs4
	.byte	W24
@ 007   ----------------------------------------
	.byte		        Gs4
	.byte	W24
	.byte		        Fn4
	.byte	W24
	.byte		        Fs4
	.byte	W24
	.byte		        Ds4
	.byte	W24
@ 008   ----------------------------------------
	.byte		N96   , Cs4
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
mus_poke_jump_3_B1:
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
	.byte	GOTO
	 .word	mus_poke_jump_3_B1
	.byte	W06
	.byte	FINE

@**************** Track 4 ****************@

mus_poke_jump_4:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_poke_jump_key+0
	.byte		VOICE , 88
	.byte		VOL   , 118*mus_poke_jump_mvl/mxv
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte		N12   , Fn4 , v044
	.byte	W12
	.byte		        Fs4
	.byte	W12
	.byte		        Gs4
	.byte	W12
	.byte		        Fn4
	.byte	W12
	.byte		N48   , Ds4
	.byte	W48
@ 004   ----------------------------------------
mus_poke_jump_4_004:
	.byte		N24   , Fn4 , v060
	.byte	W24
	.byte		        Cs4
	.byte	W24
	.byte		        Ds4
	.byte	W24
	.byte		        Cn4
	.byte	W24
	.byte	PEND
@ 005   ----------------------------------------
mus_poke_jump_4_005:
	.byte		N12   , Cs4 , v060
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		        As3
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		N36   , Gs3
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte	PEND
@ 006   ----------------------------------------
mus_poke_jump_4_006:
	.byte		N24   , As3 , v060
	.byte	W24
	.byte		        Cs4
	.byte	W24
	.byte		N12   , As3
	.byte	W12
	.byte		        As4
	.byte	W12
	.byte		        Gs4
	.byte	W12
	.byte		        Fs4
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
mus_poke_jump_4_007:
	.byte		N12   , Gs4 , v060
	.byte	W12
	.byte		        As4
	.byte	W12
	.byte		        Cn5
	.byte	W12
	.byte		        Cs5
	.byte	W12
	.byte		N48   , Ds5
	.byte	W48
	.byte	PEND
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
mus_poke_jump_4_012:
	.byte		N36   , Cs5 , v060
	.byte	W36
	.byte		        Fn5
	.byte	W36
	.byte		N24   , Cs5
	.byte	W24
	.byte	PEND
@ 013   ----------------------------------------
mus_poke_jump_4_013:
	.byte		N36   , Cn5 , v060
	.byte	W36
	.byte		        Ds5
	.byte	W36
	.byte		N12   , Cn5
	.byte	W12
	.byte		N06   , Gs4
	.byte	W06
	.byte		        An4
	.byte	W06
	.byte	PEND
@ 014   ----------------------------------------
mus_poke_jump_4_014:
	.byte		N36   , As4 , v060
	.byte	W36
	.byte		        Cs5
	.byte	W36
	.byte		N24   , As4
	.byte	W24
	.byte	PEND
@ 015   ----------------------------------------
mus_poke_jump_4_015:
	.byte		N24   , Cn5 , v060
	.byte	W24
	.byte		N12   , Ds5
	.byte	W12
	.byte		        Fn5
	.byte	W12
	.byte		        Ds5
	.byte	W12
	.byte		        Cs5
	.byte	W12
	.byte		        Cn5
	.byte	W12
	.byte		        Gs4
	.byte	W12
	.byte	PEND
@ 016   ----------------------------------------
mus_poke_jump_4_B1:
	.byte		        Cs4
	.byte	W12
	.byte		        Gs3
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		        Gs3
	.byte	W24
	.byte		N12   
	.byte	W12
@ 017   ----------------------------------------
	.byte		        As3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
@ 018   ----------------------------------------
	.byte		        Fs3
	.byte	W12
	.byte		        Cs3
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        As3
	.byte	W12
@ 019   ----------------------------------------
	.byte		        Cs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Cs4
	.byte	W12
	.byte		N24   , Cn4
	.byte	W24
	.byte		N12   , Gs3
	.byte	W12
	.byte		        Cn4
	.byte	W12
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_jump_4_004
	.byte	PATT
	 .word	mus_poke_jump_4_005
	.byte	PATT
	 .word	mus_poke_jump_4_006
	.byte	PATT
	 .word	mus_poke_jump_4_007
	.byte	W96
@ 021   ----------------------------------------
	.byte	W96
@ 022   ----------------------------------------
	.byte	W96
@ 023   ----------------------------------------
	.byte	W96
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_jump_4_012
	.byte	PATT
	 .word	mus_poke_jump_4_013
	.byte	PATT
	 .word	mus_poke_jump_4_014
	.byte	PATT
	 .word	mus_poke_jump_4_015
	.byte	GOTO
	 .word	mus_poke_jump_4_B1
	.byte	W06
	.byte	FINE

@**************** Track 5 ****************@

mus_poke_jump_5:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_poke_jump_key+0
	.byte		VOICE , 48
	.byte		VOL   , 100*mus_poke_jump_mvl/mxv
	.byte		N48   , Cs3 , v108
	.byte		N48   , Fn3
	.byte	W48
	.byte		        Cn3
	.byte		N48   , Ds3
	.byte	W48
@ 001   ----------------------------------------
mus_poke_jump_5_001:
	.byte		N48   , As2 , v108
	.byte		N48   , Cs3
	.byte	W48
	.byte		        Gs2
	.byte		N48   , Cn3
	.byte	W48
	.byte	PEND
@ 002   ----------------------------------------
mus_poke_jump_5_002:
	.byte		N48   , As2 , v108
	.byte		N48   , Cs3
	.byte	W48
	.byte		        As2
	.byte		N48   , Ds3
	.byte	W48
	.byte	PEND
@ 003   ----------------------------------------
mus_poke_jump_5_003:
	.byte		N48   , Cs3 , v108
	.byte		N48   , Ds3
	.byte	W48
	.byte		        Cn3
	.byte		N48   , Ds3
	.byte	W48
	.byte	PEND
@ 004   ----------------------------------------
mus_poke_jump_5_004:
	.byte		N48   , Cs3 , v108
	.byte		N48   , Fn3
	.byte	W48
	.byte		        Cn3
	.byte		N48   , Ds3
	.byte	W48
	.byte	PEND
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_jump_5_001
	.byte	PATT
	 .word	mus_poke_jump_5_002
mus_poke_jump_5_005:
	.byte		N48   , Ds3 , v108
	.byte		N48   , Gs3
	.byte	W48
	.byte		N48   
	.byte		N48   , Cn4
	.byte	W48
	.byte	PEND
@ 006   ----------------------------------------
	.byte		N96   , Gs3
	.byte		N96   , Cs4
	.byte	W96
@ 007   ----------------------------------------
	.byte		        Gs3
	.byte		N96   , Cn4
	.byte	W96
@ 008   ----------------------------------------
	.byte		        Fs3
	.byte		N96   , As3
	.byte	W96
@ 009   ----------------------------------------
	.byte		        Gs3
	.byte		N96   , Cn4
	.byte	W96
@ 010   ----------------------------------------
	.byte		        Gs3
	.byte		N96   , Cs4
	.byte	W96
@ 011   ----------------------------------------
	.byte		        Cn4
	.byte		N96   , Ds4
	.byte	W96
@ 012   ----------------------------------------
mus_poke_jump_5_012:
	.byte		TIE   , Fs4 , v108
	.byte		TIE   , Gs4
	.byte	W96
	.byte	PEND
@ 013   ----------------------------------------
mus_poke_jump_5_013:
	.byte	W48
	.byte		N48   , Cn4 , v108
	.byte		N48   , Ds4
	.byte	W48
	.byte	PEND
@ 014   ----------------------------------------
	.byte		EOT   , Fs4
	.byte		        Gs4
mus_poke_jump_5_B1:
	.byte	PATT
	 .word	mus_poke_jump_5_004
	.byte	PATT
	 .word	mus_poke_jump_5_001
	.byte	PATT
	 .word	mus_poke_jump_5_002
	.byte	PATT
	 .word	mus_poke_jump_5_003
	.byte	PATT
	 .word	mus_poke_jump_5_004
	.byte	PATT
	 .word	mus_poke_jump_5_001
	.byte	PATT
	 .word	mus_poke_jump_5_002
	.byte	PATT
	 .word	mus_poke_jump_5_005
	.byte		N96   , Gs3 , v108
	.byte		N96   , Cs4
	.byte	W96
@ 015   ----------------------------------------
	.byte		        Gs3
	.byte		N96   , Cn4
	.byte	W96
@ 016   ----------------------------------------
	.byte		        Fs3
	.byte		N96   , As3
	.byte	W96
@ 017   ----------------------------------------
	.byte		        Gs3
	.byte		N96   , Cn4
	.byte	W96
@ 018   ----------------------------------------
	.byte		        Gs3
	.byte		N96   , Cs4
	.byte	W96
@ 019   ----------------------------------------
	.byte		        Cn4
	.byte		N96   , Ds4
	.byte	W96
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_jump_5_012
	.byte	PATT
	 .word	mus_poke_jump_5_013
	.byte		EOT   , Fs4
	.byte		        Gs4
	.byte	GOTO
	 .word	mus_poke_jump_5_B1
	.byte	W06
	.byte	FINE

@**************** Track 6 ****************@

mus_poke_jump_6:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_poke_jump_key+0
	.byte		VOICE , 46
	.byte		VOL   , 80*mus_poke_jump_mvl/mxv
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
mus_poke_jump_6_008:
	.byte		N06   , Fn4 , v127
	.byte	W06
	.byte		        Cs4
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Cs4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		        Cs4
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Cs4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        Cs4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte	PEND
@ 009   ----------------------------------------
mus_poke_jump_6_009:
	.byte		N06   , Ds4 , v127
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Fs3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte	PEND
@ 010   ----------------------------------------
mus_poke_jump_6_010:
	.byte		N06   , Cs4 , v127
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Fs3
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Cs4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        Cs4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Fs3
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        Fs3
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Cs4
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Cs4
	.byte	W06
	.byte	PEND
@ 011   ----------------------------------------
mus_poke_jump_6_011:
	.byte		N06   , Ds4 , v127
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		N12   , Ds4
	.byte	W12
	.byte		        Fn4
	.byte	W12
	.byte		        Fs4
	.byte	W12
	.byte		N24   , Gs4
	.byte	W24
	.byte	PEND
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_jump_6_008
	.byte	PATT
	 .word	mus_poke_jump_6_009
	.byte	PATT
	 .word	mus_poke_jump_6_010
mus_poke_jump_6_012:
	.byte		N06   , Ds4 , v127
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		N12   , Cn5
	.byte	W12
	.byte		        Gs4
	.byte	W12
	.byte		        Fs4
	.byte	W12
	.byte		        Ds4
	.byte	W12
	.byte	PEND
@ 013   ----------------------------------------
mus_poke_jump_6_B1:
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
	.byte	PATT
	 .word	mus_poke_jump_6_008
	.byte	PATT
	 .word	mus_poke_jump_6_009
	.byte	PATT
	 .word	mus_poke_jump_6_010
	.byte	PATT
	 .word	mus_poke_jump_6_011
	.byte	PATT
	 .word	mus_poke_jump_6_008
	.byte	PATT
	 .word	mus_poke_jump_6_009
	.byte	PATT
	 .word	mus_poke_jump_6_010
	.byte	PATT
	 .word	mus_poke_jump_6_012
	.byte	GOTO
	 .word	mus_poke_jump_6_B1
	.byte	W06
	.byte	FINE

@**************** Track 7 ****************@

mus_poke_jump_7:
@ 000   ----------------------------------------
	.byte		VOL   , 127*mus_poke_jump_mvl/mxv
	.byte	KEYSH , mus_poke_jump_key+0
	.byte		VOICE , 0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W48
	.byte		N06   , Fs1 , v100
	.byte	W24
	.byte		        Ds0 , v127
	.byte		N06   , Cn1
	.byte		N06   , Fs1 , v100
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Fs1 , v100
	.byte	W06
	.byte		        En0 , v127
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
@ 004   ----------------------------------------
	.byte		        Ds0
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte		N06   , Cs2 , v127
	.byte		N06   , En2
	.byte		N06   , An2
	.byte	W06
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fs1 , v127
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fs1 , v127
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W06
@ 005   ----------------------------------------
mus_poke_jump_7_005:
	.byte		N06   , Ds0 , v127
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fs1 , v127
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fs1 , v127
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_jump_7_005
	.byte		N06   , Ds0 , v127
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fs1 , v127
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W06
	.byte		        Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		        En0
	.byte		N06   , Cn1 , v100
	.byte		N06   , Dn1 , v127
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fs1 , v127
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Cn1 , v100
	.byte		N06   , Gs1 , v127
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fn2 , v127
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N06   , Bn4
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N06   , Gs1
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N06   , Bn4
	.byte	W06
@ 007   ----------------------------------------
	.byte		        Ds0
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte		N06   , Cs2 , v127
	.byte		N06   , En2
	.byte		N06   , An2
	.byte		N06   , Bn4
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs1 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En0 , v127
	.byte		N06   , Dn1 , v100
	.byte		N06   , Ds1 , v127
	.byte		N06   , En1
	.byte		N06   , En2
	.byte		N06   , Gs4
	.byte		N06   , An4
	.byte		N06   , Bn4
	.byte		N06   , Cn5
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		        Fs1 , v100
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W06
@ 008   ----------------------------------------
mus_poke_jump_7_008:
	.byte		N06   , Ds0 , v127
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs1 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En0 , v127
	.byte		N06   , Dn1 , v100
	.byte		N06   , Ds1 , v127
	.byte		N06   , En1
	.byte		N06   , En2
	.byte		N06   , Gs4
	.byte		N06   , An4
	.byte		N06   , Bn4
	.byte		N06   , Cn5
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		        Fs1 , v100
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W06
	.byte	PEND
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_jump_7_008
	.byte	PATT
	 .word	mus_poke_jump_7_008
	.byte	PATT
	 .word	mus_poke_jump_7_008
	.byte	PATT
	 .word	mus_poke_jump_7_008
	.byte	PATT
	 .word	mus_poke_jump_7_008
	.byte		N06   , Ds0 , v127
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Cn1
	.byte		N06   , Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs1 , v100
	.byte		N06   , Fn2 , v127
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Fs1 , v100
	.byte	W06
	.byte		        Ds0 , v127
	.byte		N06   , En0
	.byte		N06   , Cn1
	.byte		N06   , Dn1 , v100
	.byte		N06   , Ds1 , v127
	.byte		N06   , En1
	.byte		N06   , Fs1 , v100
	.byte		N06   , En2 , v127
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N06   , Gs4
	.byte		N06   , An4
	.byte		N06   , Bn4
	.byte		N06   , Cn5
	.byte	W06
	.byte		        Fs1 , v100
	.byte		N06   , Gs1 , v127
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N06   , Fs1 , v100
	.byte		N06   , As1
	.byte		N06   , Fn3 , v127
	.byte		N06   , Fs3
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N06   , Gs1
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
@ 010   ----------------------------------------
mus_poke_jump_7_B1:
	.byte		        Ds0
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1
	.byte		N06   , Cs2 , v127
	.byte		N06   , En2
	.byte		N06   , An2
	.byte	W06
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fs1 , v127
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		TIE   , Cn1 , v100
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W06
	.byte		        As1 , v100
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fs1 , v127
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W06
@ 011   ----------------------------------------
mus_poke_jump_7_011:
	.byte		N06   , Ds0 , v127
	.byte		N06   , Fs1 , v100
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fs1 , v127
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Fs1 , v100
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fs1 , v127
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_jump_7_011
mus_poke_jump_7_012:
	.byte		N06   , Ds0 , v127
	.byte		N06   , Fs1 , v100
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fs1 , v127
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Fs1 , v100
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W06
	.byte		        Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fs1 , v127
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fn2 , v127
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N06   , Bn4
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N06   , Gs1
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N06   , Bn4
	.byte	W06
	.byte	PEND
@ 013   ----------------------------------------
	.byte		EOT   , Cn1
	.byte		N06   , Ds0
	.byte		N48   , Cn1 , v100
	.byte		N06   , Fs1
	.byte		N06   , Cs2 , v127
	.byte		N06   , En2
	.byte		N06   , An2
	.byte	W06
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fs1 , v127
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N16   , Cn1 , v100
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1 , v100
	.byte		N06   , Fs1 , v127
	.byte		N06   , Fn2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W06
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_jump_7_011
	.byte	PATT
	 .word	mus_poke_jump_7_011
	.byte	PATT
	 .word	mus_poke_jump_7_012
	.byte		N06   , Ds0 , v127
	.byte		N06   , Fs1 , v100
	.byte		N06   , Cs2 , v127
	.byte		N06   , En2
	.byte		N06   , An2
	.byte		N06   , Bn4
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Fs1 , v100
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Fs1 , v100
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs1 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En0 , v127
	.byte		N06   , Dn1 , v100
	.byte		N06   , Ds1 , v127
	.byte		N06   , En1
	.byte		N06   , En2
	.byte		N06   , Gs4
	.byte		N06   , An4
	.byte		N06   , Bn4
	.byte		N06   , Cn5
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		        Fs1 , v100
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W06
@ 015   ----------------------------------------
mus_poke_jump_7_015:
	.byte		N06   , Ds0 , v127
	.byte		N06   , Fs1 , v100
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Fs1 , v100
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Fs1 , v100
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs1 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En0 , v127
	.byte		N06   , Dn1 , v100
	.byte		N06   , Ds1 , v127
	.byte		N06   , En1
	.byte		N06   , En2
	.byte		N06   , Gs4
	.byte		N06   , An4
	.byte		N06   , Bn4
	.byte		N06   , Cn5
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		        Fs1 , v100
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W06
	.byte	PEND
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_poke_jump_7_015
	.byte	PATT
	 .word	mus_poke_jump_7_015
	.byte	PATT
	 .word	mus_poke_jump_7_015
	.byte	PATT
	 .word	mus_poke_jump_7_015
	.byte	PATT
	 .word	mus_poke_jump_7_015
	.byte		N06   , Ds0 , v127
	.byte		N06   , Fs1 , v100
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Fs1 , v100
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Fs1 , v100
	.byte		N06   , Bn4 , v127
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		        Ds0
	.byte		N06   , Gs1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs1 , v100
	.byte		N06   , Fn2 , v127
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Fs1 , v100
	.byte	W06
	.byte		        Ds0 , v127
	.byte		N06   , En0
	.byte		N06   , Dn1 , v100
	.byte		N06   , Ds1 , v127
	.byte		N06   , En1
	.byte		N06   , Fs1 , v100
	.byte		N06   , En2 , v127
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N06   , Gs4
	.byte		N06   , An4
	.byte		N06   , Bn4
	.byte		N06   , Cn5
	.byte	W06
	.byte		        Fs1 , v100
	.byte		N06   , Gs1 , v127
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N06   , Fs1 , v100
	.byte		N06   , Fn3 , v127
	.byte		N06   , Fs3
	.byte	W06
	.byte		        En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N06   , Gs1
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
@ 017   ----------------------------------------
	.byte	GOTO
	 .word	mus_poke_jump_7_B1
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

mus_poke_jump:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_poke_jump_pri	@ Priority
	.byte	mus_poke_jump_rev	@ Reverb.

	.word	mus_poke_jump_grp

	.word	mus_poke_jump_1
	.word	mus_poke_jump_2
	.word	mus_poke_jump_3
	.word	mus_poke_jump_4
	.word	mus_poke_jump_5
	.word	mus_poke_jump_6
	.word	mus_poke_jump_7

	.end
