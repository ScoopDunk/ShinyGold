	.include "MPlayDef.s"

@ ShinyGold: Now Gold/Silver/Crystal "Lighthouse" (map music of the Lighthouse and Mt. Silver).
@
@ The hack edited this song header in place (keeping the song ID) to point at new track data
@ it inserted at 0x08A00AF0; voicegroup changed from voicegroup162 to voicegroup153, 10 -> 7 tracks.
@ Disassembled from the hack ROM (no MIDI source exists).  Labels replace the hack's
@ absolute pointers; the byte stream of every track is identical to the hack's.
@ `_mvl` is 127, so `VOL , N*_mvl/mxv` emits N unchanged (edit _mvl to rescale volumes).

	.equ	mus_net_center_grp, voicegroup153
	.equ	mus_net_center_pri, 0
	.equ	mus_net_center_rev, reverb_set+50
	.equ	mus_net_center_mvl, 127
	.equ	mus_net_center_key, 0
	.equ	mus_net_center_tbs, 1
	.equ	mus_net_center_exg, 0
	.equ	mus_net_center_cmp, 1

	.section .rodata
	.global	mus_net_center
	.align	2

@**************** Track 1 ****************@

mus_net_center_1:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_net_center_key+0
mus_net_center_1_B1:
	.byte	TEMPO , 130*mus_net_center_tbs/2
	.byte		VOICE , 73
	.byte		VOL   , 108*mus_net_center_mvl/mxv
	.byte		N24   , Gs1 , v127
	.byte	W24
	.byte		        Ds1
	.byte	W24
	.byte		        Fs1
	.byte	W24
	.byte		        An1
	.byte	W24
@ 001   ----------------------------------------
mus_net_center_1_001:
	.byte		N24   , Gs1 , v127
	.byte	W24
	.byte		        Ds1
	.byte	W24
	.byte		        Fs1
	.byte	W24
	.byte		        An1
	.byte	W24
	.byte	PEND
@ 002   ----------------------------------------
	.byte	PATT
	 .word	mus_net_center_1_001
	.byte		N24   , Gs1 , v127
	.byte	W24
	.byte		        Ds1
	.byte	W24
	.byte		        Fs1
	.byte	W24
	.byte		N12   , An1
	.byte	W12
	.byte		        Cn2
	.byte	W12
@ 003   ----------------------------------------
mus_net_center_1_003:
	.byte		N24   , Cs2 , v127
	.byte	W24
	.byte		        Gs1
	.byte	W24
	.byte		        An1
	.byte	W24
	.byte		        Dn2
	.byte	W24
	.byte	PEND
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_net_center_1_003
	.byte	PATT
	 .word	mus_net_center_1_003
	.byte		N24   , Cs2 , v127
	.byte	W24
	.byte		        Gs1
	.byte	W24
	.byte		        An1
	.byte	W24
	.byte		N12   , Ds2
	.byte	W12
	.byte		        Fs2
	.byte	W12
@ 005   ----------------------------------------
mus_net_center_1_005:
	.byte		N24   , En2 , v127
	.byte	W24
	.byte		        Bn1
	.byte	W24
	.byte		        Cn2
	.byte	W24
	.byte		        Fn2
	.byte	W24
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_net_center_1_005
	.byte	PATT
	 .word	mus_net_center_1_005
	.byte	PATT
	 .word	mus_net_center_1_005
	.byte	PATT
	 .word	mus_net_center_1_005
	.byte	PATT
	 .word	mus_net_center_1_005
	.byte	PATT
	 .word	mus_net_center_1_005
	.byte	PATT
	 .word	mus_net_center_1_005
	.byte	GOTO
	 .word	mus_net_center_1_B1
	.byte	W06
	.byte	FINE

@**************** Track 2 ****************@

mus_net_center_2:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_net_center_key+0
mus_net_center_2_B1:
	.byte		VOICE , 48
	.byte		VOL   , 85*mus_net_center_mvl/mxv
	.byte		N96   , Ds3 , v127
	.byte		N96   , Gs3
	.byte	W96
@ 001   ----------------------------------------
	.byte		        En3
	.byte		N96   , An3
	.byte	W96
@ 002   ----------------------------------------
	.byte		N72   , Ds3
	.byte		N72   , Gs3
	.byte	W72
	.byte		N24   , En3
	.byte		N24   , An3
	.byte	W24
@ 003   ----------------------------------------
	.byte		N96   , Gs3
	.byte		N48   , Cn4
	.byte	W48
	.byte		TIE   , Cs4
	.byte	W48
@ 004   ----------------------------------------
	.byte		N96   , Gs3
	.byte	W96
@ 005   ----------------------------------------
	.byte		N48   , An3
	.byte	W48
	.byte		        En4
	.byte	W48
@ 006   ----------------------------------------
	.byte		TIE   , Ds4
	.byte	W96
@ 007   ----------------------------------------
	.byte	W48
	.byte		EOT   , Cs4
	.byte		N48   , Cn4
	.byte	W48
@ 008   ----------------------------------------
	.byte		EOT   , Ds4
mus_net_center_2_008:
	.byte		TIE   , Cs4 , v127
	.byte		TIE   , En4
	.byte	W96
	.byte	PEND
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte		EOT   , Cs4
	.byte		        En4
	.byte		TIE   , Cs4
	.byte		TIE   , Ds4
	.byte	W96
@ 011   ----------------------------------------
	.byte	W48
	.byte		EOT   , Cs4
	.byte		N48   , Cn4
	.byte	W48
@ 012   ----------------------------------------
	.byte		EOT   , Ds4
	.byte	PATT
	 .word	mus_net_center_2_008
	.byte	W96
@ 013   ----------------------------------------
	.byte		EOT   , Cs4
	.byte		        En4
	.byte		TIE   , Cs4 , v127
	.byte		TIE   , Fs4
	.byte	W96
@ 014   ----------------------------------------
	.byte	W48
	.byte		EOT   , Cs4
	.byte		        Fs4
	.byte		N48   , Cn4
	.byte		N48   , Gs4
	.byte	W48
@ 015   ----------------------------------------
	.byte	GOTO
	 .word	mus_net_center_2_B1
	.byte	W06
	.byte	FINE

@**************** Track 3 ****************@

mus_net_center_3:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_net_center_key+0
mus_net_center_3_B1:
	.byte		VOICE , 14
	.byte		VOL   , 127*mus_net_center_mvl/mxv
	.byte		N24   , Gs3 , v127
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W48
	.byte		N24   
	.byte	W48
@ 003   ----------------------------------------
	.byte		N96   , Gs2
	.byte	W96
@ 004   ----------------------------------------
	.byte		N24   , Gs3
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W48
	.byte		        Ds4
	.byte	W48
@ 007   ----------------------------------------
	.byte		N96   , Gs2
	.byte	W96
@ 008   ----------------------------------------
	.byte		        En4
	.byte	W96
@ 009   ----------------------------------------
	.byte		        Gs3
	.byte	W96
@ 010   ----------------------------------------
	.byte		        Bn3
	.byte	W96
@ 011   ----------------------------------------
mus_net_center_3_011:
	.byte		N48   , Ds3 , v127
	.byte	W48
	.byte		        Gs3
	.byte	W48
	.byte	PEND
@ 012   ----------------------------------------
	.byte		N96   , En4
	.byte	W96
@ 013   ----------------------------------------
	.byte		        Gs3
	.byte	W96
@ 014   ----------------------------------------
	.byte		        Bn3
	.byte	W96
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_net_center_3_011
	.byte	GOTO
	 .word	mus_net_center_3_B1
	.byte	W06
	.byte	FINE

@**************** Track 4 ****************@

mus_net_center_4:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_net_center_key+0
mus_net_center_4_B1:
	.byte		VOICE , 80
	.byte		VOL   , 127*mus_net_center_mvl/mxv
	.byte		N72   , Gs3 , v127
	.byte	W72
	.byte		N12   , Fs3
	.byte	W12
	.byte		        Gs3
	.byte	W12
@ 001   ----------------------------------------
mus_net_center_4_001:
	.byte		N48   , An3 , v127
	.byte	W48
	.byte		        Cs4
	.byte	W48
	.byte	PEND
@ 002   ----------------------------------------
	.byte		N06   , Cn4
	.byte	W48
	.byte		N48   , Gs3
	.byte	W48
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte		N72   
	.byte	W72
	.byte		N12   , Fs3
	.byte	W12
	.byte		        Gs3
	.byte	W12
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_net_center_4_001
	.byte		N06   , Cn4 , v127
	.byte	W48
	.byte		N48   , Ds4
	.byte	W48
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
mus_net_center_4_007:
	.byte		N72   , En4 , v127
	.byte	W72
	.byte		N12   , Ds4
	.byte	W12
	.byte		        Cs4
	.byte	W12
	.byte	PEND
@ 008   ----------------------------------------
	.byte		N72   , Gs3
	.byte	W72
	.byte		N24   , As3
	.byte	W24
@ 009   ----------------------------------------
	.byte		N12   , Bn3
	.byte	W12
	.byte		        Cs4
	.byte	W12
	.byte		N72   , Ds4
	.byte	W72
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_net_center_4_007
	.byte		N72   , Gs3 , v127
	.byte	W72
	.byte		N24   , Cn4
	.byte	W24
@ 012   ----------------------------------------
	.byte		N12   , Bn3
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		N72   , Ds4
	.byte	W72
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	GOTO
	 .word	mus_net_center_4_B1
	.byte	W06
	.byte	FINE

@**************** Track 5 ****************@

mus_net_center_5:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_net_center_key+0
mus_net_center_5_B1:
	.byte		VOICE , 81
	.byte		VOL   , 115*mus_net_center_mvl/mxv
	.byte		N48   , Cs3 , v127
	.byte	W48
	.byte		N12   , Fs2
	.byte	W12
	.byte		        Gs2
	.byte	W12
	.byte		        An2
	.byte	W12
	.byte		        Bn2
	.byte	W12
@ 001   ----------------------------------------
	.byte		N24   , Cs3
	.byte	W24
	.byte		        Bn2
	.byte	W24
	.byte		        An2
	.byte	W24
	.byte		        Bn2
	.byte	W24
@ 002   ----------------------------------------
	.byte		N06   , Gs2
	.byte	W48
	.byte		N24   , Cn3
	.byte	W24
	.byte		N06   , Gs2
	.byte	W12
	.byte		N06   
	.byte	W12
@ 003   ----------------------------------------
	.byte		N06   
	.byte	W12
	.byte		N12   , Cn2
	.byte	W12
	.byte		        Ds2
	.byte	W12
	.byte		N06   , Fs2
	.byte	W12
	.byte		        Gs2
	.byte		N06   , Cn3
	.byte	W12
	.byte		        Gs2
	.byte		N06   , Cs3
	.byte	W12
	.byte		        Gs2
	.byte		N06   , An2
	.byte		N06   , Cs3
	.byte	W12
	.byte		        Gs2
	.byte		N06   , An2
	.byte		N06   , Cs3
	.byte	W12
@ 004   ----------------------------------------
	.byte		N48   
	.byte	W48
	.byte		N12   , Cs2
	.byte	W12
	.byte		        Fs2
	.byte	W12
	.byte		        Gs2
	.byte	W12
	.byte		        Cs3
	.byte	W12
@ 005   ----------------------------------------
	.byte		        Dn3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        An2
	.byte	W12
	.byte		        Gs2
	.byte	W12
	.byte		        An2
	.byte	W12
	.byte		        Gs2
	.byte	W12
	.byte		        Fs2
	.byte	W12
	.byte		        An2
	.byte	W12
@ 006   ----------------------------------------
	.byte		N06   , Gs2
	.byte	W48
	.byte		N48   , Cn3
	.byte	W48
@ 007   ----------------------------------------
	.byte	W24
	.byte		N06   , Gs2
	.byte		N06   , Ds3
	.byte	W12
	.byte		        Gs2
	.byte		N06   , Ds3
	.byte	W12
	.byte		N12   , Gs2
	.byte		N12   , Ds3
	.byte	W24
	.byte		        Gs2
	.byte		N12   , Ds3
	.byte	W24
@ 008   ----------------------------------------
	.byte	W24
	.byte		N24   , An3
	.byte	W24
	.byte		        Gs3
	.byte	W24
	.byte		        Fs3
	.byte	W24
@ 009   ----------------------------------------
	.byte		        En3
	.byte	W24
	.byte		        Ds3
	.byte	W24
	.byte		        Cs3
	.byte	W24
	.byte		        En3
	.byte	W24
@ 010   ----------------------------------------
	.byte		N12   , Fs3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		N72   , Ds3
	.byte	W72
@ 011   ----------------------------------------
mus_net_center_5_011:
	.byte		N12   , Bn2 , v127
	.byte		N12   , Ds3
	.byte	W12
	.byte		        An2
	.byte		N12   , Cs3
	.byte	W12
	.byte		        Bn2
	.byte		N12   , Ds3
	.byte	W12
	.byte		        An2
	.byte		N12   , Cs3
	.byte	W12
	.byte		N48   , Gs2
	.byte		N48   , Cn3
	.byte	W48
	.byte	PEND
@ 012   ----------------------------------------
	.byte	W24
	.byte		N24   , An3
	.byte	W24
	.byte		N12   , Gs3
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Fs3
	.byte	W12
@ 013   ----------------------------------------
	.byte		        En3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Bn2
	.byte	W12
	.byte		        An2
	.byte	W12
	.byte		        Bn2
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
@ 014   ----------------------------------------
	.byte		        En3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		N72   , Gs3
	.byte	W72
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_net_center_5_011
	.byte	GOTO
	 .word	mus_net_center_5_B1
	.byte	W06
	.byte	FINE

@**************** Track 6 ****************@

mus_net_center_6:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_net_center_key+0
mus_net_center_6_B1:
	.byte		VOICE , 46
	.byte		VOL   , 97*mus_net_center_mvl/mxv
	.byte		N12   , Cs3 , v127
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Gs3
	.byte	W12
@ 001   ----------------------------------------
mus_net_center_6_001:
	.byte		N12   , Cs3 , v127
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
	.byte		        Cn3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Gs3
	.byte	W12
@ 003   ----------------------------------------
	.byte		        Cn3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        An3
	.byte	W12
@ 004   ----------------------------------------
mus_net_center_6_004:
	.byte		N12   , Cs3 , v127
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_net_center_6_001
mus_net_center_6_005:
	.byte		N12   , Cs3 , v127
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
mus_net_center_6_006:
	.byte		N12   , Cs3 , v127
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cs3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Ds3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_net_center_6_001
	.byte	PATT
	 .word	mus_net_center_6_004
	.byte	PATT
	 .word	mus_net_center_6_005
	.byte	PATT
	 .word	mus_net_center_6_006
	.byte	PATT
	 .word	mus_net_center_6_001
	.byte	PATT
	 .word	mus_net_center_6_004
	.byte	PATT
	 .word	mus_net_center_6_005
	.byte	PATT
	 .word	mus_net_center_6_006
	.byte	GOTO
	 .word	mus_net_center_6_B1
	.byte	W06
	.byte	FINE

@**************** Track 7 ****************@

mus_net_center_7:
@ 000   ----------------------------------------
	.byte		VOL   , 127*mus_net_center_mvl/mxv
	.byte	KEYSH , mus_net_center_key+0
mus_net_center_7_B1:
	.byte		VOICE , 0
	.byte		N12   , Cn1 , v127
	.byte		N12   , Fs1
	.byte		N96   , En2
	.byte	W24
	.byte		N12   , Gs1
	.byte	W12
	.byte		        Cn1
	.byte		N12   , Fs1
	.byte	W24
	.byte		        Gs1
	.byte	W12
	.byte		        Dn1
	.byte		N12   , En1
	.byte		N12   , Fn2
	.byte		N12   , Bn4
	.byte	W12
	.byte		        Fs1
	.byte	W12
@ 001   ----------------------------------------
mus_net_center_7_001:
	.byte		N12   , Cn1 , v127
	.byte		N12   , Gs1
	.byte	W24
	.byte		        Fs1
	.byte	W12
	.byte		        Cn1
	.byte		N12   , Gs1
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Cn1
	.byte		N12   , Gs1
	.byte	W12
	.byte		        Dn1
	.byte		N12   , En1
	.byte		N12   , Fn2
	.byte		N12   , Bn4
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
mus_net_center_7_002:
	.byte		N12   , Cn1 , v127
	.byte		N12   , Fs1
	.byte	W24
	.byte		        Gs1
	.byte	W12
	.byte		        Cn1
	.byte		N12   , Fs1
	.byte	W24
	.byte		        Gs1
	.byte	W12
	.byte		        Dn1
	.byte		N12   , En1
	.byte		N12   , Fn2
	.byte		N12   , Bn4
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	mus_net_center_7_001
mus_net_center_7_003:
	.byte		N12   , Cn1 , v127
	.byte		N12   , Fs1
	.byte		N96   , En2
	.byte	W24
	.byte		N12   , Gs1
	.byte	W12
	.byte		        Cn1
	.byte		N12   , Fs1
	.byte	W24
	.byte		        Gs1
	.byte	W12
	.byte		        Dn1
	.byte		N12   , En1
	.byte		N12   , Fn2
	.byte		N12   , Bn4
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte	PEND
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_net_center_7_001
	.byte	PATT
	 .word	mus_net_center_7_002
	.byte	PATT
	 .word	mus_net_center_7_001
	.byte	PATT
	 .word	mus_net_center_7_003
	.byte	PATT
	 .word	mus_net_center_7_001
	.byte	PATT
	 .word	mus_net_center_7_002
	.byte	PATT
	 .word	mus_net_center_7_001
	.byte	PATT
	 .word	mus_net_center_7_003
	.byte	PATT
	 .word	mus_net_center_7_001
	.byte	PATT
	 .word	mus_net_center_7_002
	.byte	PATT
	 .word	mus_net_center_7_001
	.byte	GOTO
	 .word	mus_net_center_7_B1
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

mus_net_center:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_net_center_pri	@ Priority
	.byte	mus_net_center_rev	@ Reverb.

	.word	mus_net_center_grp

	.word	mus_net_center_1
	.word	mus_net_center_2
	.word	mus_net_center_3
	.word	mus_net_center_4
	.word	mus_net_center_5
	.word	mus_net_center_6
	.word	mus_net_center_7

	.end
