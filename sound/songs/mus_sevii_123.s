	.include "MPlayDef.s"

@ ShinyGold: Now Gold/Silver/Crystal "Cherrygrove City" (also used for Mahogany Town, as in GSC).
@
@ The hack edited this song header in place (keeping the song ID) to point at new track data
@ it inserted at 0x08A02310; voicegroup changed from voicegroup173 to voicegroup153, 9 -> 6 tracks.
@ Disassembled from the hack ROM (no MIDI source exists).  Labels replace the hack's
@ absolute pointers; the byte stream of every track is identical to the hack's.
@ `_mvl` is 127, so `VOL , N*_mvl/mxv` emits N unchanged (edit _mvl to rescale volumes).

	.equ	mus_sevii_123_grp, voicegroup153
	.equ	mus_sevii_123_pri, 0
	.equ	mus_sevii_123_rev, reverb_set+50
	.equ	mus_sevii_123_mvl, 127
	.equ	mus_sevii_123_key, 0
	.equ	mus_sevii_123_tbs, 1
	.equ	mus_sevii_123_exg, 0
	.equ	mus_sevii_123_cmp, 1

	.section .rodata
	.global	mus_sevii_123
	.align	2

@**************** Track 1 ****************@

mus_sevii_123_1:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_123_key+0
	.byte	TEMPO , 120*mus_sevii_123_tbs/2
	.byte		VOICE , 35
	.byte		VOL   , 127*mus_sevii_123_mvl/mxv
	.byte	W48
	.byte		N48   , Dn1 , v084
	.byte	W48
@ 001   ----------------------------------------
mus_sevii_123_1_B1:
	.byte		N24   , Gn1
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   , Dn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Fs1
	.byte	W12
@ 002   ----------------------------------------
	.byte		N24   , Gn1
	.byte	W24
	.byte		N12   , Dn2
	.byte	W12
	.byte		N24   , Gn1
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        En1
	.byte	W12
@ 003   ----------------------------------------
	.byte		N24   , Fs1
	.byte	W24
	.byte		N12   , En2
	.byte	W12
	.byte		N24   , Cn2
	.byte	W24
	.byte		N12   , An1
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        An1
	.byte	W12
@ 004   ----------------------------------------
	.byte		        Fs1
	.byte	W12
	.byte		N24   , En1
	.byte	W24
	.byte		        Dn1
	.byte	W24
	.byte		        An1
	.byte	W24
	.byte		N12   , Dn1
	.byte	W12
@ 005   ----------------------------------------
mus_sevii_123_1_005:
	.byte		N24   , Cn1 , v084
	.byte	W24
	.byte		N12   , Gn1
	.byte	W12
	.byte		        En2
	.byte	W12
	.byte		        Dn2
	.byte	W12
	.byte		        Cn2
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        An1
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
mus_sevii_123_1_006:
	.byte		N24   , Gn1 , v084
	.byte	W24
	.byte		        Dn1
	.byte	W24
	.byte		N12   , Gn1
	.byte	W12
	.byte		        Dn2
	.byte	W12
	.byte		        Bn1
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_123_1_005
	.byte		N24   , Dn1 , v084
	.byte	W24
	.byte		N12   , En2
	.byte	W12
	.byte		N24   , Dn2
	.byte	W24
	.byte		N12   , An1
	.byte	W12
	.byte		N24   , Dn1
	.byte	W24
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_123_1_005
	.byte	PATT
	 .word	mus_sevii_123_1_006
	.byte		N24   , Gs1 , v084
	.byte	W24
	.byte		N12   , Cn2
	.byte	W12
	.byte		N24   , Dn1
	.byte	W24
	.byte		        Fs1
	.byte	W24
	.byte		N12   , Dn1
	.byte	W12
@ 009   ----------------------------------------
	.byte		N24   , Gn1
	.byte	W24
	.byte		N12   , Dn1
	.byte	W12
	.byte		N24   , Gn1
	.byte	W24
	.byte		N12   , Bn1
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        Dn1
	.byte	W12
@ 010   ----------------------------------------
	.byte	GOTO
	 .word	mus_sevii_123_1_B1
	.byte	W06
	.byte	FINE

@**************** Track 2 ****************@

mus_sevii_123_2:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_123_key+0
	.byte		VOICE , 81
	.byte		VOL   , 127*mus_sevii_123_mvl/mxv
	.byte		N12   , Dn3 , v096
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        Bn3
	.byte	W12
	.byte		        Cn4
	.byte	W12
@ 001   ----------------------------------------
mus_sevii_123_2_B1:
	.byte		N36   , Gn3
	.byte		N36   , Dn4
	.byte	W36
	.byte		        Cn4
	.byte		N36   , En4
	.byte	W36
	.byte		N12   , Bn3
	.byte		N12   , Dn4
	.byte	W12
	.byte		        An3
	.byte		N12   , Cn4
	.byte	W12
@ 002   ----------------------------------------
	.byte		N36   , Gn3
	.byte		N36   , Dn4
	.byte	W36
	.byte		N12   , Dn3
	.byte		N12   , Bn3
	.byte	W12
	.byte		N48   , Bn2
	.byte		N48   , Gn3
	.byte	W48
@ 003   ----------------------------------------
	.byte		N36   , Fs3
	.byte		N36   , Cn4
	.byte	W36
	.byte		        An3
	.byte		N36   , Dn4
	.byte	W36
	.byte		N12   , An3
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Gn3
	.byte		N12   , Bn3
	.byte	W12
@ 004   ----------------------------------------
	.byte		N36   , An3
	.byte		N36   , Cn4
	.byte	W36
	.byte		N12   , Fs3
	.byte		N12   , An3
	.byte	W12
	.byte		N48   , Dn3
	.byte		N48   , Fs3
	.byte	W48
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
	.byte	GOTO
	 .word	mus_sevii_123_2_B1
	.byte	W06
	.byte	FINE

@**************** Track 3 ****************@

mus_sevii_123_3:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_123_key+0
	.byte		VOICE , 1
	.byte		VOL   , 127*mus_sevii_123_mvl/mxv
	.byte	W24
	.byte		N12   , Dn3 , v127
	.byte		N12   , Fs3
	.byte	W12
	.byte		        Cn3
	.byte		N12   , En3
	.byte	W12
	.byte		        Bn2
	.byte		N12   , Dn3
	.byte	W12
	.byte		        An2
	.byte		N12   , Cn3
	.byte	W12
	.byte		        Gn2
	.byte		N12   , Bn2
	.byte	W12
	.byte		        Fs2
	.byte		N12   , An2
	.byte	W12
@ 001   ----------------------------------------
mus_sevii_123_3_B1:
	.byte		        Gn2
	.byte		N12   , Bn2
	.byte	W12
	.byte		        Dn2
	.byte		N12   , Gn2
	.byte	W12
	.byte		N12   
	.byte		N12   , Bn2
	.byte	W12
	.byte		N24   , Cn3
	.byte		N24   , En3
	.byte	W24
	.byte		N12   , An2
	.byte		N12   , Cn3
	.byte	W12
	.byte		        Fs2
	.byte		N12   , An2
	.byte	W12
	.byte		        Cn3
	.byte		N12   , En3
	.byte	W12
@ 002   ----------------------------------------
	.byte		        Bn2
	.byte		N12   , Dn3
	.byte	W12
	.byte		        Dn2
	.byte		N12   , Gn2
	.byte	W12
	.byte		N12   
	.byte		N12   , Bn2
	.byte	W12
	.byte		N24   
	.byte		N24   , Dn3
	.byte	W24
	.byte		N12   , Dn2
	.byte		N12   , Gn2
	.byte	W12
	.byte		        Fs2
	.byte		N12   , An2
	.byte	W12
	.byte		        Gn2
	.byte		N12   , Bn2
	.byte	W12
@ 003   ----------------------------------------
	.byte		        An2
	.byte		N12   , Cn3
	.byte	W12
	.byte		        Fs2
	.byte		N12   , An2
	.byte	W12
	.byte		        Gn2
	.byte		N12   , Cn3
	.byte	W12
	.byte		N24   , An2
	.byte		N24   , Dn3
	.byte	W24
	.byte		N12   , Dn2
	.byte		N12   , Gn2
	.byte	W12
	.byte		        En2
	.byte		N12   , An2
	.byte	W12
	.byte		        Gn2
	.byte		N12   , Bn2
	.byte	W12
@ 004   ----------------------------------------
	.byte		N24   , An2
	.byte		N24   , Cn3
	.byte	W24
	.byte		N12   , Bn2
	.byte		N12   , Dn3
	.byte	W12
	.byte		        An2
	.byte		N12   , Cn3
	.byte	W12
	.byte		        Gn2
	.byte		N12   , Bn2
	.byte	W12
	.byte		        Fs2
	.byte		N12   , An2
	.byte	W12
	.byte		        En2
	.byte		N12   , Gn2
	.byte	W12
	.byte		        Dn2
	.byte		N12   , Fs2
	.byte	W12
@ 005   ----------------------------------------
mus_sevii_123_3_005:
	.byte		N12   , Cn2 , v127
	.byte		N12   , En2 , v100
	.byte	W12
	.byte		N24   , En2 , v127
	.byte		N24   , Gn2 , v100
	.byte	W24
	.byte		N12   , Gn2 , v127
	.byte		N12   , Cn3 , v100
	.byte	W12
	.byte		        En2 , v127
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		        Gn2 , v127
	.byte		N12   , Cn3 , v100
	.byte	W12
	.byte		        Fs2 , v127
	.byte		N12   , Bn2 , v100
	.byte	W12
	.byte		        En2 , v127
	.byte		N12   , An2 , v100
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
mus_sevii_123_3_006:
	.byte		N12   , Dn2 , v127
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		N24   , Gn2 , v127
	.byte		N24   , Bn2 , v100
	.byte	W24
	.byte		N12   , Dn2 , v127
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		        Gn2 , v127
	.byte		N12   , Bn2 , v100
	.byte	W12
	.byte		        Dn2 , v127
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		        Dn2 , v127
	.byte		N12   , Fs2 , v100
	.byte	W12
	.byte		        Dn2 , v127
	.byte		N12   , Fn2 , v100
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_123_3_005
	.byte		N12   , Dn2 , v127
	.byte		N12   , Fs2 , v100
	.byte	W12
	.byte		        Fs2 , v127
	.byte		N12   , An2 , v100
	.byte	W12
	.byte		        Gn2 , v127
	.byte		N12   , Cn3 , v100
	.byte	W12
	.byte		        An2 , v127
	.byte		N12   , Dn3 , v100
	.byte	W12
	.byte		        Gn2 , v127
	.byte		N12   , Cn3 , v100
	.byte	W12
	.byte		        Fs2 , v127
	.byte		N12   , Bn2 , v100
	.byte	W12
	.byte		        En2 , v127
	.byte		N12   , An2 , v100
	.byte	W12
	.byte		        Dn2 , v127
	.byte		N12   , Gn2 , v100
	.byte	W12
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_123_3_005
	.byte	PATT
	 .word	mus_sevii_123_3_006
	.byte		N12   , Cn2 , v127
	.byte		N12   , Ds2 , v100
	.byte	W12
	.byte		N24   , Ds2 , v127
	.byte		N24   , Gn2 , v100
	.byte	W24
	.byte		N12   , Gn2 , v127
	.byte		N12   , Cn3 , v100
	.byte	W12
	.byte		        Ds2 , v127
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		        Gn2 , v127
	.byte		N12   , Cn3 , v100
	.byte	W12
	.byte		        Gn2 , v127
	.byte		N12   , Bn2 , v100
	.byte	W12
	.byte		        Fs2 , v127
	.byte		N12   , An2 , v100
	.byte	W12
@ 009   ----------------------------------------
	.byte		        Bn1 , v127
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		        Dn2 , v127
	.byte		N12   , Bn2 , v100
	.byte	W12
	.byte		        Gn2
	.byte		N12   , Dn3 , v127
	.byte	W12
	.byte		        Dn2
	.byte		N12   , Bn2 , v100
	.byte	W12
	.byte		        Bn1 , v127
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		        Dn2 , v127
	.byte		N12   , Bn2 , v100
	.byte	W12
	.byte		        Gn2
	.byte		N12   , Dn3 , v127
	.byte	W12
	.byte		        Dn2
	.byte		N12   , Bn2 , v100
	.byte	W12
@ 010   ----------------------------------------
	.byte	GOTO
	 .word	mus_sevii_123_3_B1
	.byte	W06
	.byte	FINE

@**************** Track 4 ****************@

mus_sevii_123_4:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_123_key+0
	.byte		VOICE , 56
	.byte		VOL   , 114*mus_sevii_123_mvl/mxv
	.byte	W96
@ 001   ----------------------------------------
mus_sevii_123_4_B1:
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
mus_sevii_123_4_005:
	.byte		N24   , Cn4 , v127
	.byte		N24   , En4
	.byte	W36
	.byte		        Cn4
	.byte		N24   , Gn4
	.byte	W24
	.byte		N01   , En4
	.byte	W01
	.byte		        Cn4
	.byte	W02
	.byte		        Gn3
	.byte	W01
	.byte		        En3
	.byte	W02
	.byte		        Cn3
	.byte	W01
	.byte		        Gn2
	.byte	W02
	.byte		        En2
	.byte	W01
	.byte		        Cn2
	.byte	W02
	.byte		N24   , Cn5
	.byte		N24   , En5
	.byte	W24
	.byte	PEND
@ 006   ----------------------------------------
	.byte		N01   , An4
	.byte		N01   , Cn5
	.byte	W01
	.byte		        As4
	.byte		N01   , Cs5
	.byte	W02
	.byte		N21   , Bn4
	.byte		N21   , Dn5
	.byte	W32
	.byte	W01
	.byte		N12   , Dn4
	.byte		N12   , Bn4
	.byte	W12
	.byte		N24   , Bn3
	.byte		N36   , Gn4
	.byte	W36
	.byte		N01   , Dn4
	.byte	W01
	.byte		        Bn3
	.byte	W02
	.byte		        Gn3
	.byte	W01
	.byte		        Dn3
	.byte	W02
	.byte		        Bn2
	.byte	W01
	.byte		        Gn2
	.byte	W02
	.byte		        Dn2
	.byte	W01
	.byte		        Bn1
	.byte	W02
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_123_4_005
	.byte		N96   , An4 , v127
	.byte		N96   , Dn5
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
	.byte	GOTO
	 .word	mus_sevii_123_4_B1
	.byte	W06
	.byte	FINE

@**************** Track 5 ****************@

mus_sevii_123_5:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_123_key+0
	.byte		VOICE , 48
	.byte		VOL   , 103*mus_sevii_123_mvl/mxv
	.byte	W96
@ 001   ----------------------------------------
mus_sevii_123_5_B1:
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
	.byte		N72   , Cn4 , v127
	.byte		N36   , En4
	.byte	W36
	.byte		        Gn4
	.byte	W36
	.byte		N60   
	.byte		N24   , En5
	.byte	W24
@ 010   ----------------------------------------
	.byte		N36   , Dn5
	.byte	W36
	.byte		N12   , Dn4
	.byte		N12   , Bn4
	.byte	W12
	.byte		N48   , Bn3
	.byte		N48   , Gn4
	.byte	W48
@ 011   ----------------------------------------
	.byte		N36   , Gs3
	.byte		N36   , Ds4
	.byte	W36
	.byte		N60   , Cn4
	.byte		N36   , Gn4
	.byte	W36
	.byte		N24   , An4
	.byte	W24
@ 012   ----------------------------------------
	.byte		N96   , Bn3
	.byte		N96   , Gn4
	.byte	W96
@ 013   ----------------------------------------
	.byte	GOTO
	 .word	mus_sevii_123_5_B1
	.byte	W06
	.byte	FINE

@**************** Track 6 ****************@

mus_sevii_123_6:
@ 000   ----------------------------------------
	.byte		VOL   , 127*mus_sevii_123_mvl/mxv
	.byte	KEYSH , mus_sevii_123_key+0
	.byte		VOICE , 0
	.byte	W36
	.byte		N12   , Cn1 , v127
	.byte	W12
	.byte		        En1
	.byte		N24   , En2
	.byte		N24   , Fn3
	.byte		N24   , Fs3
	.byte		N24   , An4
	.byte		N24   , Bn4
	.byte		N24   , Cn5
	.byte	W12
	.byte		N06   , En1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
@ 001   ----------------------------------------
mus_sevii_123_6_B1:
	.byte		N12   , Ds0
	.byte		N06   , Cn1
	.byte		N06   , En1
	.byte		N96   , Cs2
	.byte		N96   , An2
	.byte	W12
	.byte		N06   , En1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N06   , An4
	.byte		N06   , Bn4
	.byte		N06   , Cn5
	.byte	W12
	.byte		        En1
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Ds0
	.byte		N06   , Cn1
	.byte		N06   , En1
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N06   , An4
	.byte		N06   , Bn4
	.byte		N06   , Cn5
	.byte	W06
	.byte		        En1
	.byte	W06
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
@ 002   ----------------------------------------
mus_sevii_123_6_002:
	.byte		N12   , Ds0 , v127
	.byte		N06   , Cn1
	.byte		N06   , En1
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N06   , An4
	.byte		N06   , Bn4
	.byte		N06   , Cn5
	.byte	W12
	.byte		        En1
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Ds0
	.byte		N06   , Cn1
	.byte		N06   , En1
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N06   , An4
	.byte		N06   , Bn4
	.byte		N06   , Cn5
	.byte	W06
	.byte		        En1
	.byte	W06
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_123_6_002
	.byte	PATT
	 .word	mus_sevii_123_6_002
	.byte		N12   , Ds0 , v127
	.byte		N06   , Cn1
	.byte		N06   , En1
	.byte		N12   , En2
	.byte	W12
	.byte		N06   , En1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N06   , An4
	.byte		N06   , Bn4
	.byte		N06   , Cn5
	.byte	W12
	.byte		        En1
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Ds0
	.byte		N06   , Cn1
	.byte		N06   , En1
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N06   , An4
	.byte		N06   , Bn4
	.byte		N06   , Cn5
	.byte	W06
	.byte		        En1
	.byte	W06
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_123_6_002
	.byte	PATT
	 .word	mus_sevii_123_6_002
	.byte	PATT
	 .word	mus_sevii_123_6_002
	.byte	PATT
	 .word	mus_sevii_123_6_002
	.byte	PATT
	 .word	mus_sevii_123_6_002
	.byte	PATT
	 .word	mus_sevii_123_6_002
	.byte		N12   , Ds0 , v127
	.byte		N06   , Cn1
	.byte		N06   , En1
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N06   , An4
	.byte		N06   , Bn4
	.byte		N06   , Cn5
	.byte	W12
	.byte		        En1
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Ds0
	.byte		N06   , Cn1
	.byte		N06   , En1
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , En0
	.byte		N06   , Dn1
	.byte		N06   , Ds1
	.byte		N06   , En1
	.byte		N12   , En2
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N06   , An4
	.byte		N06   , Bn4
	.byte		N06   , Cn5
	.byte	W06
	.byte		        En1
	.byte	W06
	.byte		N01   
	.byte		N12   , En2
	.byte		N12   , Gn2
	.byte		N12   , Bn2
	.byte	W01
	.byte		N01   , En1
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
@ 005   ----------------------------------------
	.byte	GOTO
	 .word	mus_sevii_123_6_B1
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

mus_sevii_123:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_sevii_123_pri	@ Priority
	.byte	mus_sevii_123_rev	@ Reverb.

	.word	mus_sevii_123_grp

	.word	mus_sevii_123_1
	.word	mus_sevii_123_2
	.word	mus_sevii_123_3
	.word	mus_sevii_123_4
	.word	mus_sevii_123_5
	.word	mus_sevii_123_6

	.end
