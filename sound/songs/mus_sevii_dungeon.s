	.include "MPlayDef.s"

@ ShinyGold: Now Gold/Silver/Crystal "Victory Road" (map music of Victory Road and some caves).
@
@ The hack edited this song header in place (keeping the song ID) to point at new track data
@ it inserted at 0x08A04650; voicegroup changed from voicegroup146 to voicegroup144, 10 -> 6 tracks.
@ Disassembled from the hack ROM (no MIDI source exists).  Labels replace the hack's
@ absolute pointers; the byte stream of every track is identical to the hack's.
@ `_mvl` is 127, so `VOL , N*_mvl/mxv` emits N unchanged (edit _mvl to rescale volumes).

	.equ	mus_sevii_dungeon_grp, voicegroup144
	.equ	mus_sevii_dungeon_pri, 0
	.equ	mus_sevii_dungeon_rev, reverb_set+50
	.equ	mus_sevii_dungeon_mvl, 127
	.equ	mus_sevii_dungeon_key, 0
	.equ	mus_sevii_dungeon_tbs, 1
	.equ	mus_sevii_dungeon_exg, 0
	.equ	mus_sevii_dungeon_cmp, 1

	.section .rodata
	.global	mus_sevii_dungeon
	.align	2

@**************** Track 1 ****************@

mus_sevii_dungeon_1:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_dungeon_key+0
mus_sevii_dungeon_1_B1:
	.byte	TEMPO , 148*mus_sevii_dungeon_tbs/2
	.byte		VOICE , 38
	.byte		VOL   , 103*mus_sevii_dungeon_mvl/mxv
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Bn1
	.byte	W06
	.byte		        Cn2
	.byte	W12
	.byte		        Gn1
	.byte	W06
	.byte		        Bn1
	.byte	W18
	.byte		        Gn1
	.byte	W06
	.byte		        Cn2
	.byte	W18
	.byte		        Gn1
	.byte	W06
	.byte		        Fs2
	.byte	W18
@ 001   ----------------------------------------
mus_sevii_dungeon_1_001:
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Bn1
	.byte	W06
	.byte		        Cn2
	.byte	W12
	.byte		        Gn1
	.byte	W06
	.byte		        Bn1
	.byte	W18
	.byte		        Gn1
	.byte	W06
	.byte		        Cn2
	.byte	W18
	.byte		        Gn1
	.byte	W06
	.byte		        Fs2
	.byte	W18
	.byte	PEND
@ 002   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_dungeon_1_001
	.byte	PATT
	 .word	mus_sevii_dungeon_1_001
	.byte	PATT
	 .word	mus_sevii_dungeon_1_001
	.byte	PATT
	 .word	mus_sevii_dungeon_1_001
mus_sevii_dungeon_1_002:
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        Cs2
	.byte	W06
	.byte		        Dn2
	.byte	W12
	.byte		        An1
	.byte	W06
	.byte		        Cs2
	.byte	W18
	.byte		        An1
	.byte	W06
	.byte		        Dn2
	.byte	W18
	.byte		        An1
	.byte	W06
	.byte		        Gs2
	.byte	W18
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_dungeon_1_002
	.byte	PATT
	 .word	mus_sevii_dungeon_1_001
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Bn1
	.byte	W06
	.byte		        Cn2
	.byte	W12
	.byte		        Gn1
	.byte	W06
	.byte		        Bn1
	.byte	W18
	.byte		        Gn1
	.byte	W06
	.byte		        Cn2
	.byte	W18
	.byte		        Gn1
	.byte	W06
	.byte		        Fs2
	.byte	W18
@ 004   ----------------------------------------
	.byte	GOTO
	 .word	mus_sevii_dungeon_1_B1
	.byte	W06
	.byte	FINE

@**************** Track 2 ****************@

mus_sevii_dungeon_2:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_dungeon_key+0
mus_sevii_dungeon_2_B1:
	.byte		VOICE , 1
	.byte		VOL   , 97*mus_sevii_dungeon_mvl/mxv
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        An4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        Fs3
	.byte	W06
	.byte		        Cn4
	.byte	W06
@ 001   ----------------------------------------
mus_sevii_dungeon_2_001:
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        An4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        Fs3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte	PEND
@ 002   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_dungeon_2_001
	.byte	PATT
	 .word	mus_sevii_dungeon_2_001
	.byte	PATT
	 .word	mus_sevii_dungeon_2_001
	.byte	PATT
	 .word	mus_sevii_dungeon_2_001
mus_sevii_dungeon_2_002:
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		        Fs3
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        Fs3
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		        Fs3
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        As4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		        Bn4
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_dungeon_2_002
	.byte	PATT
	 .word	mus_sevii_dungeon_2_001
	.byte	PATT
	 .word	mus_sevii_dungeon_2_001
	.byte	GOTO
	 .word	mus_sevii_dungeon_2_B1
	.byte	W06
	.byte	FINE

@**************** Track 3 ****************@

mus_sevii_dungeon_3:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_dungeon_key+0
mus_sevii_dungeon_3_B1:
	.byte		VOICE , 35
	.byte		VOL   , 127*mus_sevii_dungeon_mvl/mxv
	.byte	W96
@ 001   ----------------------------------------
	.byte	W90
	.byte		N06   , Cn3 , v127
	.byte	W06
@ 002   ----------------------------------------
mus_sevii_dungeon_3_002:
	.byte		N48   , En3 , v127
	.byte	W48
	.byte		N24   , Cn4
	.byte	W24
	.byte		        Bn3
	.byte	W24
	.byte	PEND
@ 003   ----------------------------------------
	.byte		N72   , En3
	.byte	W90
	.byte		N06   , Ds3
	.byte	W06
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_dungeon_3_002
	.byte		N72   , En4 , v127
	.byte	W96
@ 005   ----------------------------------------
	.byte		N48   , Dn4
	.byte	W48
	.byte		N24   , Cs4
	.byte	W24
	.byte		        An3
	.byte	W24
@ 006   ----------------------------------------
	.byte		N48   , Cn4
	.byte	W48
	.byte		N24   , As3
	.byte	W24
	.byte		        Fn3
	.byte	W24
@ 007   ----------------------------------------
	.byte		N48   , An3
	.byte	W72
	.byte		N06   , Dn3
	.byte	W06
	.byte		        Fs3
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Cs4
	.byte	W06
@ 008   ----------------------------------------
	.byte		N72   , Dn4
	.byte	W96
@ 009   ----------------------------------------
	.byte	GOTO
	 .word	mus_sevii_dungeon_3_B1
	.byte	W06
	.byte	FINE

@**************** Track 4 ****************@

mus_sevii_dungeon_4:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_dungeon_key+0
mus_sevii_dungeon_4_B1:
	.byte		VOICE , 48
	.byte		VOL   , 85*mus_sevii_dungeon_mvl/mxv
	.byte		N06   , Cn3 , v092
	.byte		N06   , En3
	.byte		N06   , Gs3
	.byte	W12
	.byte		        Cn3
	.byte		N06   , En3
	.byte		N06   , Gs3
	.byte	W12
	.byte		        Bn2
	.byte		N06   , Ds3
	.byte		N06   , Gn3
	.byte	W12
	.byte		N12   , Cn3
	.byte		N12   , En3
	.byte		N12   , Gs3
	.byte	W24
	.byte		N06   , Cn3
	.byte		N06   , En3
	.byte		N06   , Gs3
	.byte	W12
	.byte		N12   , Cs3
	.byte		N12   , En3
	.byte		N12   , Fn3
	.byte		N12   , An3
	.byte	W24
@ 001   ----------------------------------------
mus_sevii_dungeon_4_001:
	.byte		N06   , Cn3 , v092
	.byte		N06   , En3
	.byte		N06   , Gs3
	.byte	W12
	.byte		        Cn3
	.byte		N06   , En3
	.byte		N06   , Gs3
	.byte	W12
	.byte		        Bn2
	.byte		N06   , Ds3
	.byte		N06   , Gn3
	.byte	W12
	.byte		N12   , Cn3
	.byte		N12   , En3
	.byte		N12   , Gs3
	.byte	W24
	.byte		N06   , Cn3
	.byte		N06   , En3
	.byte		N06   , Gs3
	.byte	W12
	.byte		N12   , Cs3
	.byte		N12   , En3
	.byte		N12   , Fn3
	.byte		N12   , An3
	.byte	W24
	.byte	PEND
@ 002   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_dungeon_4_001
	.byte	PATT
	 .word	mus_sevii_dungeon_4_001
	.byte	PATT
	 .word	mus_sevii_dungeon_4_001
	.byte	PATT
	 .word	mus_sevii_dungeon_4_001
mus_sevii_dungeon_4_002:
	.byte		N06   , Dn3 , v092
	.byte		N06   , Fs3
	.byte		N06   , As3
	.byte	W12
	.byte		        Dn3
	.byte		N06   , Fs3
	.byte		N06   , As3
	.byte	W12
	.byte		        Cs3
	.byte		N06   , Fn3
	.byte		N06   , An3
	.byte	W12
	.byte		N12   , Dn3
	.byte		N12   , Fs3
	.byte		N12   , As3
	.byte	W24
	.byte		N06   , Dn3
	.byte		N06   , Fs3
	.byte		N06   , As3
	.byte	W12
	.byte		N12   , Ds3
	.byte		N12   , Fs3
	.byte		N12   , Gn3
	.byte		N12   , Bn3
	.byte	W24
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_dungeon_4_002
	.byte	PATT
	 .word	mus_sevii_dungeon_4_001
	.byte		N06   , Cn3 , v092
	.byte		N06   , En3
	.byte		N06   , Gs3
	.byte	W12
	.byte		        Cn3
	.byte		N06   , En3
	.byte		N06   , Gs3
	.byte	W12
	.byte		        Bn2
	.byte		N06   , Ds3
	.byte		N06   , Gn3
	.byte	W12
	.byte		N12   , Cn3
	.byte		N12   , En3
	.byte		N12   , Gs3
	.byte	W24
	.byte		N06   , Cn3
	.byte		N06   , En3
	.byte		N06   , Gs3
	.byte	W12
	.byte		N12   , Cs3
	.byte		N12   , En3
	.byte		N12   , Fn3
	.byte		N12   , An3
	.byte	W24
@ 004   ----------------------------------------
	.byte	GOTO
	 .word	mus_sevii_dungeon_4_B1
	.byte	W06
	.byte	FINE

@**************** Track 5 ****************@

mus_sevii_dungeon_5:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_dungeon_key+0
mus_sevii_dungeon_5_B1:
	.byte		VOICE , 35
	.byte		VOL   , 96*mus_sevii_dungeon_mvl/mxv
	.byte		N06   , Gn1 , v104
	.byte	W06
	.byte		        Bn1
	.byte	W06
	.byte		        Cn2
	.byte	W12
	.byte		        Gn1
	.byte	W06
	.byte		        Bn1
	.byte	W18
	.byte		        Gn1
	.byte	W06
	.byte		        Cn2
	.byte	W18
	.byte		        Gn1
	.byte	W06
	.byte		        Fs2
	.byte	W18
@ 001   ----------------------------------------
mus_sevii_dungeon_5_001:
	.byte		N06   , Gn1 , v104
	.byte	W06
	.byte		        Bn1
	.byte	W06
	.byte		        Cn2
	.byte	W12
	.byte		        Gn1
	.byte	W06
	.byte		        Bn1
	.byte	W18
	.byte		        Gn1
	.byte	W06
	.byte		        Cn2
	.byte	W18
	.byte		        Gn1
	.byte	W06
	.byte		        Fs2
	.byte	W18
	.byte	PEND
@ 002   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_dungeon_5_001
	.byte	PATT
	 .word	mus_sevii_dungeon_5_001
	.byte	PATT
	 .word	mus_sevii_dungeon_5_001
	.byte	PATT
	 .word	mus_sevii_dungeon_5_001
mus_sevii_dungeon_5_002:
	.byte		N06   , An1 , v104
	.byte	W06
	.byte		        Cs2
	.byte	W06
	.byte		        Dn2
	.byte	W12
	.byte		        An1
	.byte	W06
	.byte		        Cs2
	.byte	W18
	.byte		        An1
	.byte	W06
	.byte		        Dn2
	.byte	W18
	.byte		        An1
	.byte	W06
	.byte		        Gs2
	.byte	W18
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_dungeon_5_002
	.byte	PATT
	 .word	mus_sevii_dungeon_5_001
	.byte		N06   , Gn1 , v104
	.byte	W06
	.byte		        Bn1
	.byte	W06
	.byte		        Cn2
	.byte	W12
	.byte		        Gn1
	.byte	W06
	.byte		        Bn1
	.byte	W18
	.byte		        Gn1
	.byte	W06
	.byte		        Cn2
	.byte	W18
	.byte		        Gn1
	.byte	W06
	.byte		        Fs2
	.byte	W18
@ 004   ----------------------------------------
	.byte	GOTO
	 .word	mus_sevii_dungeon_5_B1
	.byte	W06
	.byte	FINE

@**************** Track 6 ****************@

mus_sevii_dungeon_6:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_sevii_dungeon_key+0
mus_sevii_dungeon_6_B1:
	.byte		VOICE , 0
	.byte		VOL   , 102*mus_sevii_dungeon_mvl/mxv
	.byte		N12   , En1 , v127
	.byte		N96   , En2
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		N12   , Dn1
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		        Cn1
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Bn0
	.byte	W12
	.byte		        Cn1
	.byte		N06   , Gs1
	.byte	W06
	.byte		N12   , En1
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		N12   , Dn1
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		        Cn1
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Bn0
	.byte	W12
	.byte		        Cn1
	.byte		N06   , Gs1
	.byte	W06
@ 001   ----------------------------------------
mus_sevii_dungeon_6_001:
	.byte		N12   , En1 , v127
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		N12   , Dn1
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		        Cn1
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Bn0
	.byte	W12
	.byte		        Cn1
	.byte		N06   , Gs1
	.byte	W06
	.byte		N12   , En1
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		N12   , Dn1
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		        Cn1
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Bn0
	.byte	W12
	.byte		        Cn1
	.byte		N06   , Gs1
	.byte	W06
	.byte	PEND
@ 002   ----------------------------------------
mus_sevii_dungeon_6_002:
	.byte		N12   , En1 , v127
	.byte		N96   , Cs2
	.byte		N96   , En2
	.byte		N96   , An2
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		N12   , Dn1
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		        Cn1
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Bn0
	.byte	W12
	.byte		        Cn1
	.byte		N06   , Gs1
	.byte	W06
	.byte		N12   , En1
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		N12   , Dn1
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		        Cn1
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Bn0
	.byte	W12
	.byte		        Cn1
	.byte		N06   , Gs1
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_dungeon_6_001
	.byte	PATT
	 .word	mus_sevii_dungeon_6_001
	.byte		N12   , En1 , v127
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		N12   , Dn1
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		        Cn1
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Bn0
	.byte	W12
	.byte		        Cn1
	.byte		N06   , Gs1
	.byte	W06
	.byte		        An1
	.byte		N06   , Cn2
	.byte	W06
	.byte		        An1
	.byte		N06   , Cn2
	.byte	W06
	.byte		N12   , Dn1
	.byte	W06
	.byte		N06   , An1
	.byte		N06   , Cn2
	.byte	W06
	.byte		        An1
	.byte		N06   , Cn2
	.byte	W06
	.byte		N12   , Dn1
	.byte	W06
	.byte		N06   , An1
	.byte		N06   , Cn2
	.byte	W06
	.byte		        An1
	.byte		N06   , Cn2
	.byte	W06
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_sevii_dungeon_6_002
	.byte	PATT
	 .word	mus_sevii_dungeon_6_001
	.byte		N12   , En1 , v127
	.byte		N96   , En2
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		N12   , Dn1
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		        Cn1
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Bn0
	.byte	W12
	.byte		        Cn1
	.byte		N06   , Gs1
	.byte	W06
	.byte		N12   , En1
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		N12   , Dn1
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		        Cn1
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Bn0
	.byte	W12
	.byte		        Cn1
	.byte		N06   , Gs1
	.byte	W06
@ 005   ----------------------------------------
	.byte		N12   , En1
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		N12   , Dn1
	.byte	W06
	.byte		N06   , Gs1
	.byte	W06
	.byte		        Cn1
	.byte		N06   , Fs1
	.byte	W06
	.byte		        Bn0
	.byte	W12
	.byte		        Cn1
	.byte		N06   , Gs1
	.byte	W06
	.byte		        An1
	.byte		N06   , Cn2
	.byte	W06
	.byte		        An1
	.byte		N06   , Cn2
	.byte	W06
	.byte		N12   , Dn1
	.byte	W06
	.byte		N06   , An1
	.byte		N06   , Cn2
	.byte	W06
	.byte		N12   , An1
	.byte		N06   , Cn2
	.byte	W06
	.byte		N12   , Dn1
	.byte	W06
	.byte		N06   , An1
	.byte		N06   , Cn2
	.byte	W06
	.byte		        An1
	.byte		N06   , Cn2
	.byte	W06
@ 006   ----------------------------------------
	.byte	GOTO
	 .word	mus_sevii_dungeon_6_B1
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

mus_sevii_dungeon:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_sevii_dungeon_pri	@ Priority
	.byte	mus_sevii_dungeon_rev	@ Reverb.

	.word	mus_sevii_dungeon_grp

	.word	mus_sevii_dungeon_1
	.word	mus_sevii_dungeon_2
	.word	mus_sevii_dungeon_3
	.word	mus_sevii_dungeon_4
	.word	mus_sevii_dungeon_5
	.word	mus_sevii_dungeon_6

	.end
