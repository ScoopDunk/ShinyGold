	.include "MPlayDef.s"

@ ShinyGold: Now Gold/Silver/Crystal "Dark Cave" (map music of Dark Cave, Ice Path, Slowpoke Well...).
@
@ The hack edited this song header in place (keeping the song ID) to point at new track data
@ it inserted at 0x08A01C80; voicegroup changed from voicegroup147 to voicegroup153, 7 -> 6 tracks.
@ Disassembled from the hack ROM (no MIDI source exists).  Labels replace the hack's
@ absolute pointers; the byte stream of every track is identical to the hack's.
@ `_mvl` is 127, so `VOL , N*_mvl/mxv` emits N unchanged (edit _mvl to rescale volumes).

	.equ	mus_sevii_cave_grp, voicegroup153
	.equ	mus_sevii_cave_pri, 0
	.equ	mus_sevii_cave_rev, reverb_set+50
	.equ	mus_sevii_cave_mvl, 127
	.equ	mus_sevii_cave_key, 0
	.equ	mus_sevii_cave_tbs, 1
	.equ	mus_sevii_cave_exg, 0
	.equ	mus_sevii_cave_cmp, 1

	.section .rodata
	.global	mus_sevii_cave
	.align	2

@**************** Track 1 ****************@

mus_sevii_cave_1:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_cave_key+0
	.byte	TEMPO , 160*mus_sevii_cave_tbs/2
	.byte		VOICE , 80
	.byte		VOL   , 127*mus_sevii_cave_mvl/mxv
	.byte		N24   , Cn1 , v092
	.byte	W24
	.byte		N12   , Gn1
	.byte	W12
	.byte		N24   , Ds1
	.byte	W24
	.byte		N12   , Gn1
	.byte	W12
	.byte		N24   , Fn1
	.byte	W24
@ 001   ----------------------------------------
mus_sevii_cave_1_001:
	.byte		N12   , Ds1 , v092
	.byte	W24
	.byte		N36   , As0
	.byte	W36
	.byte		N12   , Cn1
	.byte	W12
	.byte		        Cs1
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
mus_sevii_cave_1_002:
	.byte		N24   , Cn1 , v092
	.byte	W24
	.byte		N12   , Gn1
	.byte	W12
	.byte		N24   , Ds1
	.byte	W24
	.byte		N12   , Gn1
	.byte	W12
	.byte		N24   , Ds1
	.byte	W24
	.byte	PEND
@ 003   ----------------------------------------
mus_sevii_cave_1_003:
	.byte		N12   , Fn1 , v092
	.byte	W24
	.byte		N24   , As0
	.byte	W24
	.byte		N12   , Cs1
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		N24   , Cs1
	.byte	W24
	.byte	PEND
@ 004   ----------------------------------------
mus_sevii_cave_1_004:
	.byte		N24   , Cn1 , v092
	.byte	W24
	.byte		N12   , Gn1
	.byte	W12
	.byte		N24   , Ds1
	.byte	W24
	.byte		N12   , Gn1
	.byte	W12
	.byte		N24   , Fn1
	.byte	W24
	.byte	PEND
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_cave_1_001
	.byte	PATT
	 .word	mus_sevii_cave_1_002
	.byte	PATT
	 .word	mus_sevii_cave_1_003
mus_sevii_cave_1_B1:
	.byte	PATT
	 .word	mus_sevii_cave_1_004
	.byte	PATT
	 .word	mus_sevii_cave_1_001
	.byte	PATT
	 .word	mus_sevii_cave_1_002
	.byte	PATT
	 .word	mus_sevii_cave_1_003
	.byte	PATT
	 .word	mus_sevii_cave_1_004
	.byte	PATT
	 .word	mus_sevii_cave_1_001
	.byte	PATT
	 .word	mus_sevii_cave_1_002
	.byte	PATT
	 .word	mus_sevii_cave_1_003
	.byte	PATT
	 .word	mus_sevii_cave_1_004
	.byte	PATT
	 .word	mus_sevii_cave_1_001
	.byte	PATT
	 .word	mus_sevii_cave_1_002
	.byte	PATT
	 .word	mus_sevii_cave_1_003
	.byte	PATT
	 .word	mus_sevii_cave_1_004
	.byte	PATT
	 .word	mus_sevii_cave_1_001
	.byte	PATT
	 .word	mus_sevii_cave_1_002
	.byte	PATT
	 .word	mus_sevii_cave_1_003
	.byte	PATT
	 .word	mus_sevii_cave_1_004
	.byte	PATT
	 .word	mus_sevii_cave_1_001
	.byte	PATT
	 .word	mus_sevii_cave_1_002
	.byte	PATT
	 .word	mus_sevii_cave_1_003
	.byte	PATT
	 .word	mus_sevii_cave_1_004
	.byte	PATT
	 .word	mus_sevii_cave_1_001
	.byte	PATT
	 .word	mus_sevii_cave_1_002
	.byte	PATT
	 .word	mus_sevii_cave_1_003
	.byte	PATT
	 .word	mus_sevii_cave_1_004
	.byte	PATT
	 .word	mus_sevii_cave_1_001
	.byte	PATT
	 .word	mus_sevii_cave_1_002
	.byte	PATT
	 .word	mus_sevii_cave_1_003
mus_sevii_cave_1_005:
	.byte		N24   , Cn2 , v092
	.byte	W24
	.byte		N12   , Gn2
	.byte	W12
	.byte		N24   , Ds2
	.byte	W24
	.byte		N12   , Gn2
	.byte	W12
	.byte		N24   , Fn2
	.byte	W24
	.byte	PEND
@ 006   ----------------------------------------
mus_sevii_cave_1_006:
	.byte		N12   , Ds2 , v092
	.byte	W24
	.byte		N36   , As1
	.byte	W36
	.byte		N12   , Cn2
	.byte	W12
	.byte		        Cs2
	.byte	W12
	.byte		        Ds2
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
mus_sevii_cave_1_007:
	.byte		N24   , Cn2 , v092
	.byte	W24
	.byte		N12   , Gn2
	.byte	W12
	.byte		N24   , Ds2
	.byte	W24
	.byte		N12   , Gn2
	.byte	W12
	.byte		N24   , Ds2
	.byte	W24
	.byte	PEND
@ 008   ----------------------------------------
mus_sevii_cave_1_008:
	.byte		N12   , Fn2 , v092
	.byte	W24
	.byte		N24   , As1
	.byte	W24
	.byte		N12   , Cs2
	.byte	W12
	.byte		        Ds2
	.byte	W12
	.byte		N24   , Cs2
	.byte	W24
	.byte	PEND
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_cave_1_005
	.byte	PATT
	 .word	mus_sevii_cave_1_006
	.byte	PATT
	 .word	mus_sevii_cave_1_007
	.byte	PATT
	 .word	mus_sevii_cave_1_008
	.byte	PATT
	 .word	mus_sevii_cave_1_005
	.byte	PATT
	 .word	mus_sevii_cave_1_006
	.byte	PATT
	 .word	mus_sevii_cave_1_007
	.byte	PATT
	 .word	mus_sevii_cave_1_008
	.byte	PATT
	 .word	mus_sevii_cave_1_005
	.byte	PATT
	 .word	mus_sevii_cave_1_006
	.byte	PATT
	 .word	mus_sevii_cave_1_007
	.byte	PATT
	 .word	mus_sevii_cave_1_008
	.byte	GOTO
	 .word	mus_sevii_cave_1_B1
	.byte	W06
	.byte	FINE

@**************** Track 2 ****************@

mus_sevii_cave_2:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_cave_key+0
	.byte		VOICE , 46
	.byte		VOL   , 99*mus_sevii_cave_mvl/mxv
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte		N96   , Ds4 , v127
	.byte		N96   , Gn4
	.byte	W96
@ 005   ----------------------------------------
	.byte		        Dn4
	.byte		N96   , As4
	.byte	W96
@ 006   ----------------------------------------
	.byte		        Cs4
	.byte		N96   , Fn4
	.byte	W96
@ 007   ----------------------------------------
	.byte		        Cn4
	.byte		N96   , Gn4
	.byte	W96
@ 008   ----------------------------------------
mus_sevii_cave_2_B1:
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
mus_sevii_cave_2_020:
	.byte		N24   , Fn4 , v127
	.byte	W24
	.byte		N12   , Ds4
	.byte	W12
	.byte		        Dn4
	.byte	W12
	.byte		N24   , Ds4
	.byte	W24
	.byte		N12   , Dn4
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte	PEND
@ 021   ----------------------------------------
	.byte		        Dn4
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		        As3
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		N24   , Dn4
	.byte	W24
	.byte		        As3
	.byte	W24
@ 022   ----------------------------------------
	.byte		N48   , Cs4
	.byte	W48
	.byte		        As3
	.byte	W48
@ 023   ----------------------------------------
	.byte		N12   , Ds4
	.byte	W12
	.byte		        Dn4
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		        As3
	.byte	W12
	.byte		N48   , Cn4
	.byte	W48
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_cave_2_020
	.byte		N12   , Dn4 , v127
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		        As3
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		N24   , Dn4
	.byte	W24
	.byte		N12   , As3
	.byte	W12
	.byte		        Cn4
	.byte	W12
@ 025   ----------------------------------------
	.byte		N24   , Cs4
	.byte	W24
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Cs4
	.byte	W12
	.byte		        Ds4
	.byte	W12
	.byte		        Cs4
	.byte	W12
	.byte		        As3
	.byte	W12
	.byte		        Cs4
	.byte	W12
@ 026   ----------------------------------------
	.byte		N96   , Cn4
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
	.byte	W48
	.byte		N12   , Fn3
	.byte		N12   , As3
	.byte	W12
	.byte		        Gn3
	.byte		N12   , Cn4
	.byte	W12
	.byte		N24   , Gs3
	.byte		N24   , Cs4
	.byte	W24
@ 037   ----------------------------------------
	.byte		N96   , Gn3
	.byte		N96   , Cn4
	.byte	W96
@ 038   ----------------------------------------
	.byte	W48
	.byte		N12   , Gs3
	.byte		N12   , Cs4
	.byte	W12
	.byte		        Gn3
	.byte		N12   , Cn4
	.byte	W12
	.byte		N24   , Gs3
	.byte		N24   , Cs4
	.byte	W24
@ 039   ----------------------------------------
	.byte		N96   , Gn3
	.byte		N96   , Cn4
	.byte	W96
@ 040   ----------------------------------------
	.byte		N12   , As3
	.byte		N12   , Ds4
	.byte	W48
	.byte		        Fn3
	.byte		N12   , As3
	.byte	W12
	.byte		        Gn3
	.byte		N12   , Cn4
	.byte	W12
	.byte		N24   , Gs3
	.byte		N24   , Cs4
	.byte	W24
@ 041   ----------------------------------------
	.byte		N96   , Gn3
	.byte		N96   , Cn4
	.byte	W96
@ 042   ----------------------------------------
	.byte		N12   , Fn3
	.byte		N12   , As3
	.byte	W48
	.byte		        Gs3
	.byte		N12   , Cs4
	.byte	W12
	.byte		        Gn3
	.byte		N12   , Cn4
	.byte	W12
	.byte		N24   , Gs3
	.byte		N24   , Cs4
	.byte	W24
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	W96
@ 045   ----------------------------------------
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte		N96   , Ds4
	.byte		N96   , Gn4
	.byte	W96
@ 048   ----------------------------------------
	.byte		        Dn4
	.byte		N96   , As4
	.byte	W96
@ 049   ----------------------------------------
	.byte		        Cs4
	.byte		N96   , Fn4
	.byte	W96
@ 050   ----------------------------------------
	.byte		        Cn4
	.byte		N96   , Gn4
	.byte	W96
@ 051   ----------------------------------------
	.byte	GOTO
	 .word	mus_sevii_cave_2_B1
	.byte	W06
	.byte	FINE

@**************** Track 3 ****************@

mus_sevii_cave_3:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_cave_key+0
	.byte		VOICE , 46
	.byte		VOL   , 127*mus_sevii_cave_mvl/mxv
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
mus_sevii_cave_3_B1:
	.byte		N12   , Gn3 , v127
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Gn3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Gn3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte	PEND
@ 009   ----------------------------------------
mus_sevii_cave_3_009:
	.byte		N12   , Fn3 , v127
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        Dn3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        Dn3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Dn3
	.byte	W12
	.byte	PEND
@ 010   ----------------------------------------
mus_sevii_cave_3_010:
	.byte		N12   , Fn3 , v127
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        As2
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
mus_sevii_cave_3_011:
	.byte		N12   , Fn3 , v127
	.byte	W12
	.byte		        Gs2
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Gs2
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte	PEND
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_cave_3_B1
	.byte	PATT
	 .word	mus_sevii_cave_3_009
	.byte	PATT
	 .word	mus_sevii_cave_3_010
	.byte	PATT
	 .word	mus_sevii_cave_3_011
	.byte	PATT
	 .word	mus_sevii_cave_3_B1
	.byte	PATT
	 .word	mus_sevii_cave_3_009
	.byte	PATT
	 .word	mus_sevii_cave_3_010
	.byte	PATT
	 .word	mus_sevii_cave_3_011
	.byte	PATT
	 .word	mus_sevii_cave_3_B1
	.byte	PATT
	 .word	mus_sevii_cave_3_009
	.byte	PATT
	 .word	mus_sevii_cave_3_010
	.byte	PATT
	 .word	mus_sevii_cave_3_011
	.byte	PATT
	 .word	mus_sevii_cave_3_B1
	.byte	PATT
	 .word	mus_sevii_cave_3_009
	.byte	PATT
	 .word	mus_sevii_cave_3_010
	.byte	PATT
	 .word	mus_sevii_cave_3_011
	.byte	PATT
	 .word	mus_sevii_cave_3_B1
	.byte	PATT
	 .word	mus_sevii_cave_3_009
	.byte	PATT
	 .word	mus_sevii_cave_3_010
	.byte	PATT
	 .word	mus_sevii_cave_3_011
	.byte	PATT
	 .word	mus_sevii_cave_3_B1
	.byte	PATT
	 .word	mus_sevii_cave_3_009
	.byte	PATT
	 .word	mus_sevii_cave_3_010
mus_sevii_cave_3_012:
	.byte		N12   , Fn3 , v127
	.byte	W12
	.byte		        Gs2
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Gs2
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Bn2
	.byte	W12
	.byte	PEND
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
	.byte	PATT
	 .word	mus_sevii_cave_3_B1
	.byte	PATT
	 .word	mus_sevii_cave_3_009
	.byte	PATT
	 .word	mus_sevii_cave_3_010
	.byte	PATT
	 .word	mus_sevii_cave_3_012
	.byte	PATT
	 .word	mus_sevii_cave_3_B1
	.byte	PATT
	 .word	mus_sevii_cave_3_009
	.byte	PATT
	 .word	mus_sevii_cave_3_010
	.byte	PATT
	 .word	mus_sevii_cave_3_012
	.byte	GOTO
	 .word	mus_sevii_cave_3_B1
	.byte	W06
	.byte	FINE

@**************** Track 4 ****************@

mus_sevii_cave_4:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_cave_key+0
	.byte		VOICE , 48
	.byte		VOL   , 99*mus_sevii_cave_mvl/mxv
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
mus_sevii_cave_4_B1:
	.byte	W96
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W48
	.byte		N48   , Cn4 , v127
	.byte	W48
@ 013   ----------------------------------------
mus_sevii_cave_4_013:
	.byte		N12   , Dn4 , v127
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		        As3
	.byte	W12
	.byte		N24   , Gn3
	.byte	W24
	.byte		N12   , As3
	.byte	W12
	.byte		N24   , Dn4
	.byte	W24
	.byte	PEND
@ 014   ----------------------------------------
	.byte		N96   , Cs4
	.byte	W96
@ 015   ----------------------------------------
	.byte		        Cn4
	.byte	W96
@ 016   ----------------------------------------
	.byte	W48
	.byte		N48   
	.byte	W48
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_cave_4_013
	.byte		N72   , Cs4 , v127
	.byte		N72   , Gs4
	.byte	W72
	.byte		N12   , Cn4
	.byte		N12   , Gn4
	.byte	W12
	.byte		        Cs4
	.byte		N12   , Gs4
	.byte	W12
@ 018   ----------------------------------------
	.byte		N96   , Ds4
	.byte		N96   , As4
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
	.byte	W48
	.byte		N48   , Cn4
	.byte	W48
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_cave_4_013
	.byte		N96   , Cs4 , v127
	.byte	W96
@ 029   ----------------------------------------
	.byte		        Cn4
	.byte	W96
@ 030   ----------------------------------------
	.byte	W48
	.byte		N48   
	.byte	W48
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_cave_4_013
	.byte		N96   , Fn3 , v127
	.byte		N96   , Cs4
	.byte	W96
@ 032   ----------------------------------------
	.byte		        Gn3
	.byte		N96   , Cn4
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
	.byte	GOTO
	 .word	mus_sevii_cave_4_B1
	.byte	W06
	.byte	FINE

@**************** Track 5 ****************@

mus_sevii_cave_5:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_cave_key+0
	.byte		VOICE , 14
	.byte		VOL   , 127*mus_sevii_cave_mvl/mxv
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
mus_sevii_cave_5_B1:
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
mus_sevii_cave_5_020:
	.byte		N48   , Gs3 , v127
	.byte	W48
	.byte		        Ds3
	.byte	W48
	.byte	PEND
@ 021   ----------------------------------------
mus_sevii_cave_5_021:
	.byte		N48   , Gn3 , v127
	.byte	W48
	.byte		        Dn3
	.byte	W48
	.byte	PEND
@ 022   ----------------------------------------
mus_sevii_cave_5_022:
	.byte		N48   , Fn3 , v127
	.byte	W48
	.byte		        Cs3
	.byte	W48
	.byte	PEND
@ 023   ----------------------------------------
	.byte		        Ds3
	.byte	W48
	.byte		        Gn3
	.byte	W48
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_cave_5_020
	.byte	PATT
	 .word	mus_sevii_cave_5_021
	.byte	PATT
	 .word	mus_sevii_cave_5_022
	.byte		N48   , Ds3 , v127
	.byte	W48
	.byte		        Cn3
	.byte	W48
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
	.byte		N96   , Ds4
	.byte	W96
@ 046   ----------------------------------------
	.byte		        Dn4
	.byte	W96
@ 047   ----------------------------------------
	.byte		        Fn4
	.byte	W96
@ 048   ----------------------------------------
	.byte		        Ds4
	.byte	W96
@ 049   ----------------------------------------
	.byte	GOTO
	 .word	mus_sevii_cave_5_B1
	.byte	W06
	.byte	FINE

@**************** Track 6 ****************@

mus_sevii_cave_6:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_cave_key+0
	.byte		VOICE , 0
	.byte		VOL   , 94*mus_sevii_cave_mvl/mxv
	.byte		N24   , Cn1 , v100
	.byte		N24   , Cs2
	.byte		N24   , En2
	.byte		N24   , An2
	.byte	W36
	.byte		N04   , En1
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N12   , En0
	.byte		N12   , Dn1
	.byte		N12   , Fn3
	.byte		N12   , Fs3
	.byte		N12   , Bn4
	.byte	W12
	.byte		        Ds0
	.byte		N12   , En1
	.byte		N12   , Dn2
	.byte	W12
	.byte		        Ds0
	.byte		N12   , En1
	.byte	W12
	.byte		        Ds0
	.byte		N12   , En1
	.byte		N12   , An1
	.byte	W12
@ 001   ----------------------------------------
mus_sevii_cave_6_001:
	.byte		N12   , Ds0 , v100
	.byte		N12   , Cn1
	.byte		N12   , En1
	.byte		N12   , Fn1
	.byte		N24   , Cs2
	.byte		N24   , En2
	.byte	W36
	.byte		N12   , Cn1
	.byte	W12
	.byte		        En0
	.byte		N12   , Dn1
	.byte		N12   , Ds1
	.byte		N12   , En1
	.byte		N12   , En2
	.byte		N12   , Fn3
	.byte		N12   , Fs3
	.byte		N12   , Gs4
	.byte		N12   , An4
	.byte		N12   , Bn4
	.byte		N12   , Cn5
	.byte	W24
	.byte		N04   , Dn2
	.byte	W04
	.byte		        Cn2
	.byte	W08
	.byte		        An1
	.byte	W04
	.byte		        Gn1
	.byte	W04
	.byte		        Fn1
	.byte	W04
	.byte	PEND
@ 002   ----------------------------------------
mus_sevii_cave_6_002:
	.byte		N12   , Ds0 , v100
	.byte		N12   , Cn1
	.byte		N12   , En1
	.byte		N12   , Fn1
	.byte		N24   , En2
	.byte		N24   , An2
	.byte	W36
	.byte		N12   , Cn1
	.byte	W12
	.byte		        En0
	.byte		N12   , Dn1
	.byte		N12   , Ds1
	.byte		N12   , En1
	.byte		N12   , En2
	.byte		N12   , Fn3
	.byte		N12   , Fs3
	.byte		N12   , Gs4
	.byte		N12   , An4
	.byte		N12   , Bn4
	.byte		N12   , Cn5
	.byte	W24
	.byte		N04   , Dn2
	.byte	W04
	.byte		        Cn2
	.byte	W08
	.byte		        An1
	.byte	W04
	.byte		        Gn1
	.byte	W04
	.byte		        Fn1
	.byte	W04
	.byte	PEND
@ 003   ----------------------------------------
mus_sevii_cave_6_003:
	.byte		N24   , Cn1 , v100
	.byte		N24   , Cs2
	.byte		N24   , En2
	.byte		N24   , An2
	.byte	W36
	.byte		N04   , En1
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N12   , En0
	.byte		N12   , Dn1
	.byte		N12   , En2
	.byte		N12   , Fn3
	.byte		N12   , Fs3
	.byte		N12   , Bn4
	.byte	W12
	.byte		        Ds0
	.byte		N12   , En1
	.byte		N12   , Dn2
	.byte		N12   , En2
	.byte		N06   , Fn3
	.byte	W06
	.byte		        Fs3
	.byte	W06
	.byte		N12   , Ds0
	.byte		N12   , En1
	.byte		N12   , En2
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		N12   , Ds0
	.byte		N12   , En1
	.byte		N12   , An1
	.byte		N12   , En2
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte	PEND
@ 004   ----------------------------------------
mus_sevii_cave_6_004:
	.byte		N24   , Cn1 , v100
	.byte		N24   , Cs2
	.byte		N24   , En2
	.byte		N24   , An2
	.byte	W36
	.byte		N04   , En1
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N12   , En0
	.byte		N12   , Dn1
	.byte		N12   , Fn3
	.byte		N12   , Fs3
	.byte		N12   , Bn4
	.byte	W12
	.byte		        Ds0
	.byte		N12   , En1
	.byte		N12   , Dn2
	.byte	W12
	.byte		        Ds0
	.byte		N12   , En1
	.byte	W12
	.byte		        Ds0
	.byte		N12   , En1
	.byte		N12   , An1
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_cave_6_001
	.byte	PATT
	 .word	mus_sevii_cave_6_002
	.byte	PATT
	 .word	mus_sevii_cave_6_003
mus_sevii_cave_6_B1:
	.byte	PATT
	 .word	mus_sevii_cave_6_004
	.byte	PATT
	 .word	mus_sevii_cave_6_001
	.byte	PATT
	 .word	mus_sevii_cave_6_002
	.byte	PATT
	 .word	mus_sevii_cave_6_003
	.byte	PATT
	 .word	mus_sevii_cave_6_004
	.byte	PATT
	 .word	mus_sevii_cave_6_001
	.byte	PATT
	 .word	mus_sevii_cave_6_002
	.byte	PATT
	 .word	mus_sevii_cave_6_003
	.byte	PATT
	 .word	mus_sevii_cave_6_004
	.byte	PATT
	 .word	mus_sevii_cave_6_001
	.byte	PATT
	 .word	mus_sevii_cave_6_002
	.byte	PATT
	 .word	mus_sevii_cave_6_003
	.byte	PATT
	 .word	mus_sevii_cave_6_004
	.byte	PATT
	 .word	mus_sevii_cave_6_001
	.byte	PATT
	 .word	mus_sevii_cave_6_002
	.byte	PATT
	 .word	mus_sevii_cave_6_003
	.byte	PATT
	 .word	mus_sevii_cave_6_004
	.byte	PATT
	 .word	mus_sevii_cave_6_001
	.byte	PATT
	 .word	mus_sevii_cave_6_002
	.byte	PATT
	 .word	mus_sevii_cave_6_003
	.byte	PATT
	 .word	mus_sevii_cave_6_004
	.byte	PATT
	 .word	mus_sevii_cave_6_001
	.byte	PATT
	 .word	mus_sevii_cave_6_002
	.byte	PATT
	 .word	mus_sevii_cave_6_003
	.byte	PATT
	 .word	mus_sevii_cave_6_004
	.byte	PATT
	 .word	mus_sevii_cave_6_001
	.byte	PATT
	 .word	mus_sevii_cave_6_002
	.byte	PATT
	 .word	mus_sevii_cave_6_003
	.byte	PATT
	 .word	mus_sevii_cave_6_004
	.byte	PATT
	 .word	mus_sevii_cave_6_001
	.byte	PATT
	 .word	mus_sevii_cave_6_002
	.byte	PATT
	 .word	mus_sevii_cave_6_003
	.byte	PATT
	 .word	mus_sevii_cave_6_004
	.byte	PATT
	 .word	mus_sevii_cave_6_001
	.byte	PATT
	 .word	mus_sevii_cave_6_002
	.byte	PATT
	 .word	mus_sevii_cave_6_003
	.byte	PATT
	 .word	mus_sevii_cave_6_004
	.byte	PATT
	 .word	mus_sevii_cave_6_001
	.byte	PATT
	 .word	mus_sevii_cave_6_002
	.byte	PATT
	 .word	mus_sevii_cave_6_003
	.byte	PATT
	 .word	mus_sevii_cave_6_004
	.byte	PATT
	 .word	mus_sevii_cave_6_001
	.byte	PATT
	 .word	mus_sevii_cave_6_002
	.byte	PATT
	 .word	mus_sevii_cave_6_003
	.byte	GOTO
	 .word	mus_sevii_cave_6_B1
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

mus_sevii_cave:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_sevii_cave_pri	@ Priority
	.byte	mus_sevii_cave_rev	@ Reverb.

	.word	mus_sevii_cave_grp

	.word	mus_sevii_cave_1
	.word	mus_sevii_cave_2
	.word	mus_sevii_cave_3
	.word	mus_sevii_cave_4
	.word	mus_sevii_cave_5
	.word	mus_sevii_cave_6

	.end
