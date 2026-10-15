	.include "MPlayDef.s"

@ ShinyGold: Now Gold/Silver/Crystal "Route 2" (Kanto route theme; map music of the Union Room
@ and Route 2).
@
@ The hack edited this song header in place (keeping the song ID) to point at new track data
@ it inserted at 0x08A03CA0; voicegroup changed from voicegroup132 to voicegroup008, 8 -> 9 tracks.
@ Disassembled from the hack ROM (no MIDI source exists).  Labels replace the hack's
@ absolute pointers; the byte stream of every track is identical to the hack's.
@ `_mvl` is 127, so `VOL , N*_mvl/mxv` emits N unchanged (edit _mvl to rescale volumes).

	.equ	mus_union_room_grp, voicegroup008
	.equ	mus_union_room_pri, 0
	.equ	mus_union_room_rev, reverb_set+50
	.equ	mus_union_room_mvl, 127
	.equ	mus_union_room_key, 0
	.equ	mus_union_room_tbs, 1
	.equ	mus_union_room_exg, 0
	.equ	mus_union_room_cmp, 1

	.section .rodata
	.global	mus_union_room
	.align	2

@**************** Track 1 ****************@

mus_union_room_1:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_union_room_key+0
	.byte	TEMPO , 130*mus_union_room_tbs/2
	.byte		VOICE , 46
	.byte		PAN   , c_v+35
	.byte		VOL   , 109*mus_union_room_mvl/mxv
	.byte		N06   , Bn3 , v127
	.byte		N06   , En4
	.byte	W24
	.byte		        Bn3
	.byte		N06   , En4
	.byte	W24
	.byte		        Bn3
	.byte		N06   , En4
	.byte	W24
	.byte		        Bn3
	.byte		N06   , En4
	.byte	W24
@ 001   ----------------------------------------
mus_union_room_1_001:
	.byte		N06   , En4 , v127
	.byte		N06   , As4
	.byte	W24
	.byte		        En4
	.byte		N06   , As4
	.byte	W24
	.byte		        En4
	.byte		N06   , As4
	.byte	W24
	.byte		        En4
	.byte		N06   , As4
	.byte	W24
	.byte	PEND
@ 002   ----------------------------------------
mus_union_room_1_002:
	.byte		N12   , Cn4 , v127
	.byte		N12   , An4
	.byte	W24
	.byte		        Cn4
	.byte		N12   , An4
	.byte	W24
	.byte		        Cn4
	.byte		N12   , An4
	.byte	W24
	.byte		        Cn4
	.byte		N12   , An4
	.byte	W24
	.byte	PEND
@ 003   ----------------------------------------
	.byte		        Cn4
	.byte		N12   , Gs4
	.byte	W24
	.byte		        Cn4
	.byte		N12   , Gs4
	.byte	W24
	.byte		N24   , Cn4
	.byte		N24   , Gs4
	.byte	W24
	.byte		        Dn4
	.byte		N24   , Gn4
	.byte	W23
	.byte	W01
@ 004   ----------------------------------------
mus_union_room_1_004:
	.byte		N06   , Bn3 , v127
	.byte		N06   , En4
	.byte	W24
	.byte		        Bn3
	.byte		N06   , En4
	.byte	W24
	.byte		        Bn3
	.byte		N06   , En4
	.byte	W24
	.byte		        Bn3
	.byte		N06   , En4
	.byte	W24
	.byte	PEND
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_union_room_1_001
	.byte	PATT
	 .word	mus_union_room_1_002
mus_union_room_1_005:
	.byte		N12   , Cn4 , v127
	.byte		N12   , Gs4
	.byte	W24
	.byte		        Cn4
	.byte		N12   , Gs4
	.byte	W24
	.byte		N24   , Cn4
	.byte		N24   , Gs4
	.byte	W24
	.byte		        Dn4
	.byte		N24   , Gn4
	.byte	W24
	.byte	PEND
@ 006   ----------------------------------------
mus_union_room_1_B1:
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
	.byte	PATT
	 .word	mus_union_room_1_004
	.byte	PATT
	 .word	mus_union_room_1_001
	.byte	PATT
	 .word	mus_union_room_1_002
	.byte	PATT
	 .word	mus_union_room_1_005
	.byte	GOTO
	 .word	mus_union_room_1_B1
	.byte	W06
	.byte	FINE

@**************** Track 2 ****************@

mus_union_room_2:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_union_room_key+0
	.byte		VOICE , 81
	.byte		VOL   , 127*mus_union_room_mvl/mxv
	.byte		N06   , Cn1 , v127
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
@ 001   ----------------------------------------
	.byte		        Gn1
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
@ 002   ----------------------------------------
mus_union_room_2_002:
	.byte		N24   , Fn1 , v127
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
mus_union_room_2_003:
	.byte		N24   , Fn1 , v127
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		        Dn1
	.byte	W24
	.byte	PEND
@ 004   ----------------------------------------
mus_union_room_2_004:
	.byte		N24   , Cn1 , v127
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
mus_union_room_2_005:
	.byte		N24   , Gn1 , v127
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_union_room_2_002
	.byte	PATT
	 .word	mus_union_room_2_003
mus_union_room_2_B1:
	.byte	PATT
	 .word	mus_union_room_2_004
	.byte	PATT
	 .word	mus_union_room_2_005
	.byte	PATT
	 .word	mus_union_room_2_002
	.byte	PATT
	 .word	mus_union_room_2_003
	.byte	PATT
	 .word	mus_union_room_2_004
	.byte	PATT
	 .word	mus_union_room_2_005
	.byte	PATT
	 .word	mus_union_room_2_002
	.byte	PATT
	 .word	mus_union_room_2_003
mus_union_room_2_006:
	.byte		N06   , En1 , v127
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
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
mus_union_room_2_007:
	.byte		N06   , An1 , v127
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
@ 008   ----------------------------------------
mus_union_room_2_008:
	.byte		N06   , Fn1 , v127
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
@ 009   ----------------------------------------
	.byte		        Gn1
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fs1
	.byte	W12
	.byte		        Fn1
	.byte	W12
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_union_room_2_006
	.byte	PATT
	 .word	mus_union_room_2_007
	.byte	PATT
	 .word	mus_union_room_2_008
	.byte		N06   , Gn1 , v127
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Gn2
	.byte	W12
	.byte		        Fn2
	.byte	W12
	.byte		        Dn2
	.byte	W12
	.byte		        Gn1
	.byte	W12
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_union_room_2_004
	.byte	PATT
	 .word	mus_union_room_2_005
	.byte	PATT
	 .word	mus_union_room_2_002
	.byte	PATT
	 .word	mus_union_room_2_003
	.byte	GOTO
	 .word	mus_union_room_2_B1
	.byte	W06
	.byte	FINE

@**************** Track 3 ****************@

mus_union_room_3:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_union_room_key+0
	.byte		VOICE , 46
	.byte		PAN   , c_v+17
	.byte		VOL   , 109*mus_union_room_mvl/mxv
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
mus_union_room_3_B1:
	.byte		N06   , Cn2 , v127
	.byte	W06
	.byte		        Gn2
	.byte	W06
	.byte		        Bn2
	.byte	W06
	.byte		        En2
	.byte	W06
	.byte		        Gn2
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Bn2
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte	PEND
@ 009   ----------------------------------------
mus_union_room_3_009:
	.byte		N06   , Dn3 , v127
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Dn3
	.byte	W06
	.byte	PEND
@ 010   ----------------------------------------
mus_union_room_3_010:
	.byte		N06   , Cn3 , v127
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte	PEND
@ 011   ----------------------------------------
mus_union_room_3_011:
	.byte		N06   , Cn3 , v127
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Dn3
	.byte	W06
	.byte		        Bn2
	.byte	W06
	.byte	PEND
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_union_room_3_B1
	.byte	PATT
	 .word	mus_union_room_3_009
	.byte	PATT
	 .word	mus_union_room_3_010
	.byte	PATT
	 .word	mus_union_room_3_011
	.byte		N06   , Gn3 , v127
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        En3
	.byte	W06
@ 013   ----------------------------------------
	.byte		        Cn4
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gs3
	.byte	W06
@ 014   ----------------------------------------
	.byte		        Cn4
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Fs3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Fs3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        An3
	.byte	W06
@ 015   ----------------------------------------
	.byte		        Dn4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		        Bn3
	.byte	W06
@ 016   ----------------------------------------
	.byte		        En4
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        En4
	.byte	W06
@ 017   ----------------------------------------
	.byte		        An3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Cn4
	.byte	W06
@ 018   ----------------------------------------
	.byte		        An3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        An3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte		        Cn4
	.byte	W06
@ 019   ----------------------------------------
	.byte		        Gn3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte		        Bn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W96
@ 022   ----------------------------------------
	.byte	W96
@ 023   ----------------------------------------
	.byte	W96
@ 024   ----------------------------------------
	.byte	GOTO
	 .word	mus_union_room_3_B1
	.byte	W06
	.byte	FINE

@**************** Track 4 ****************@

mus_union_room_4:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_union_room_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v-31
	.byte		VOL   , 111*mus_union_room_mvl/mxv
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
mus_union_room_4_004:
	.byte		N12   , Bn2 , v127
	.byte		N12   , En3
	.byte	W12
	.byte		        Cn2
	.byte		N12   , Gn2
	.byte	W12
	.byte		        Bn2
	.byte		N12   , En3
	.byte	W12
	.byte		        Cn2
	.byte		N12   , Gn2
	.byte	W12
	.byte		        Bn2
	.byte		N12   , En3
	.byte	W12
	.byte		        Cn2
	.byte		N12   , Gn2
	.byte	W12
	.byte		        Bn2
	.byte		N12   , En3
	.byte	W12
	.byte		        Cn2
	.byte		N12   , Gn2
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
mus_union_room_4_005:
	.byte		N12   , En3 , v127
	.byte		N12   , As3
	.byte	W12
	.byte		        Gn2
	.byte		N12   , Dn3
	.byte	W12
	.byte		        En3
	.byte		N12   , As3
	.byte	W12
	.byte		        Gn2
	.byte		N12   , Dn3
	.byte	W12
	.byte		        En3
	.byte		N12   , As3
	.byte	W12
	.byte		        Gn2
	.byte		N12   , Dn3
	.byte	W12
	.byte		        En3
	.byte		N12   , As3
	.byte	W12
	.byte		        Gn2
	.byte		N12   , Dn3
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
mus_union_room_4_006:
	.byte		N12   , En3 , v127
	.byte		N12   , An3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Cn3
	.byte	W12
	.byte		        En3
	.byte		N12   , An3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Cn3
	.byte	W12
	.byte		        En3
	.byte		N12   , An3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Cn3
	.byte	W12
	.byte		        En3
	.byte		N12   , An3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Cn3
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
mus_union_room_4_007:
	.byte		N12   , Fn3 , v127
	.byte		N12   , Gs3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Cn3
	.byte	W12
	.byte		        Fn3
	.byte		N12   , Gs3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Cn3
	.byte	W12
	.byte		        Fn3
	.byte		N12   , Gs3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Cn3
	.byte	W12
	.byte		        Dn3
	.byte		N12   , Gn3
	.byte	W12
	.byte		        Gn2
	.byte		N12   , Bn2
	.byte	W12
	.byte	PEND
@ 008   ----------------------------------------
mus_union_room_4_B1:
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
	.byte	PATT
	 .word	mus_union_room_4_004
	.byte	PATT
	 .word	mus_union_room_4_005
	.byte	PATT
	 .word	mus_union_room_4_006
	.byte	PATT
	 .word	mus_union_room_4_007
	.byte	GOTO
	 .word	mus_union_room_4_B1
	.byte	W06
	.byte	FINE

@**************** Track 5 ****************@

mus_union_room_5:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_union_room_key+0
	.byte		VOICE , 88
	.byte		PAN   , c_v-34
	.byte		VOL   , 127*mus_union_room_mvl/mxv
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
mus_union_room_5_B1:
	.byte		N12   , En2 , v056
	.byte		N12   , Bn2
	.byte	W12
	.byte		        Gn2
	.byte		N12   , En3
	.byte	W12
	.byte		        En2
	.byte		N12   , Bn2
	.byte	W12
	.byte		        Gn2
	.byte		N12   , En3
	.byte	W12
	.byte		        En2
	.byte		N12   , Bn2
	.byte	W12
	.byte		        Gn2
	.byte		N12   , En3
	.byte	W12
	.byte		        En2
	.byte		N12   , Bn2
	.byte	W12
	.byte		        Gn2
	.byte		N12   , En3
	.byte	W12
	.byte	PEND
@ 009   ----------------------------------------
mus_union_room_5_009:
	.byte		N12   , Gn2 , v056
	.byte		N12   , Dn3
	.byte	W12
	.byte		        Fn3
	.byte		N12   , As3
	.byte	W12
	.byte		        Gn2
	.byte		N12   , Dn3
	.byte	W12
	.byte		        Fn3
	.byte		N12   , As3
	.byte	W12
	.byte		        Gn2
	.byte		N12   , Dn3
	.byte	W12
	.byte		        Fn3
	.byte		N12   , As3
	.byte	W12
	.byte		        Gn2
	.byte		N12   , Dn3
	.byte	W12
	.byte		        Fn3
	.byte		N12   , As3
	.byte	W12
	.byte	PEND
@ 010   ----------------------------------------
mus_union_room_5_010:
	.byte		N12   , Fn2 , v056
	.byte		N12   , Cn3
	.byte	W12
	.byte		        En3
	.byte		N12   , An3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Cn3
	.byte	W12
	.byte		        En3
	.byte		N12   , An3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Cn3
	.byte	W12
	.byte		        En3
	.byte		N12   , An3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Cn3
	.byte	W12
	.byte		        En3
	.byte		N12   , An3
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
mus_union_room_5_011:
	.byte		N12   , Fn2 , v056
	.byte		N12   , Cn3
	.byte	W12
	.byte		N12   
	.byte		N12   , Gs3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Cn3
	.byte	W12
	.byte		N12   
	.byte		N12   , Gs3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Bn2
	.byte	W12
	.byte		        Dn3
	.byte		N12   , Gs3
	.byte	W12
	.byte		        Fn2
	.byte		N12   , Bn2
	.byte	W12
	.byte		        Dn3
	.byte		N12   , Gn3
	.byte	W12
	.byte	PEND
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_union_room_5_B1
	.byte	PATT
	 .word	mus_union_room_5_009
	.byte	PATT
	 .word	mus_union_room_5_010
	.byte	PATT
	 .word	mus_union_room_5_011
mus_union_room_5_012:
	.byte		N12   , En3 , v056
	.byte		N12   , Bn3
	.byte	W12
	.byte		        Bn2
	.byte		N12   , Gn3
	.byte	W12
	.byte		        En3
	.byte		N12   , Bn3
	.byte	W12
	.byte		        Bn2
	.byte		N12   , Gn3
	.byte	W12
	.byte		        En3
	.byte		N12   , Bn3
	.byte	W12
	.byte		        Bn2
	.byte		N12   , Gs3
	.byte	W12
	.byte		        En3
	.byte		N12   , Bn3
	.byte	W12
	.byte		        Bn2
	.byte		N12   , Gs3
	.byte	W12
	.byte	PEND
@ 013   ----------------------------------------
mus_union_room_5_013:
	.byte		N12   , En3 , v056
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Cn3
	.byte		N12   , An3
	.byte	W12
	.byte		        En3
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Cn3
	.byte		N12   , An3
	.byte	W12
	.byte		        En3
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Cn3
	.byte		N12   , Gs3
	.byte	W12
	.byte		        En3
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Cn3
	.byte		N12   , Gs3
	.byte	W12
	.byte	PEND
@ 014   ----------------------------------------
mus_union_room_5_014:
	.byte		N12   , Fn3 , v056
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Cn3
	.byte		N12   , An3
	.byte	W12
	.byte		        Fn3
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Cn3
	.byte		N12   , An3
	.byte	W12
	.byte		        Fs3
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Cn3
	.byte		N12   , An3
	.byte	W12
	.byte		        Fs3
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Cn3
	.byte		N12   , An3
	.byte	W12
	.byte	PEND
@ 015   ----------------------------------------
	.byte		        Gn3
	.byte		N12   , Bn3
	.byte	W12
	.byte		        Dn3
	.byte		N12   , Gn3
	.byte	W12
	.byte		N12   
	.byte		N12   , Bn3
	.byte	W12
	.byte		        Dn3
	.byte		N12   , Gn3
	.byte	W12
	.byte		        Fn3
	.byte		N12   , Bn3
	.byte	W12
	.byte		        Dn3
	.byte		N12   , Gn3
	.byte	W12
	.byte		        Fn3
	.byte		N12   , Bn3
	.byte	W12
	.byte		        Dn3
	.byte		N12   , Gn3
	.byte	W12
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_union_room_5_012
	.byte	PATT
	 .word	mus_union_room_5_013
	.byte	PATT
	 .word	mus_union_room_5_014
	.byte		N12   , Cn3 , v056
	.byte		N12   , Gn3
	.byte	W12
	.byte		        Fn3
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Gn3
	.byte		N12   , Dn4
	.byte	W12
	.byte		        Cn4
	.byte		N12   , Gn4
	.byte	W12
	.byte		        Bn3
	.byte		N12   , Fn4
	.byte	W12
	.byte		        Gn3
	.byte		N12   , Dn4
	.byte	W12
	.byte		        Fn3
	.byte		N12   , Bn3
	.byte	W12
	.byte		        Bn2
	.byte		N12   , Gn3
	.byte	W12
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
	.byte	W96
@ 019   ----------------------------------------
	.byte	W96
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	GOTO
	 .word	mus_union_room_5_B1
	.byte	W06
	.byte	FINE

@**************** Track 6 ****************@

mus_union_room_6:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_union_room_key+0
	.byte		VOICE , 56
	.byte		PAN   , c_v-22
	.byte		VOL   , 127*mus_union_room_mvl/mxv
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
mus_union_room_6_007:
	.byte	W84
	.byte		N06   , Cn4 , v127
	.byte	W06
	.byte		        Dn4
	.byte	W06
	.byte	PEND
@ 008   ----------------------------------------
mus_union_room_6_B1:
	.byte		N48   , En4
	.byte	W60
	.byte		N03   , Dn4
	.byte	W03
	.byte		        En4
	.byte	W03
	.byte		N18   , Dn4
	.byte	W18
	.byte		N12   , Cn4
	.byte	W12
@ 009   ----------------------------------------
	.byte		N48   , Gn3
	.byte	W48
	.byte		N12   , An3
	.byte	W12
	.byte		        As3
	.byte	W24
	.byte		N06   , Cn4
	.byte	W06
	.byte		        Dn4
	.byte	W06
@ 010   ----------------------------------------
	.byte		N48   , En4
	.byte	W60
	.byte		N24   , Fn4
	.byte	W24
	.byte		N12   , En4
	.byte	W12
@ 011   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N04   , Dn4
	.byte	W04
	.byte		        En4
	.byte	W04
	.byte		        Dn4
	.byte	W04
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Dn4
	.byte	W60
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
	.byte	PATT
	 .word	mus_union_room_6_007
	.byte	GOTO
	 .word	mus_union_room_6_B1
	.byte	W06
	.byte	FINE

@**************** Track 7 ****************@

mus_union_room_7:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_union_room_key+0
	.byte		VOICE , 73
	.byte		PAN   , c_v+35
	.byte		VOL   , 127*mus_union_room_mvl/mxv
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
mus_union_room_7_B1:
	.byte	W96
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	W60
	.byte		N30   , Gn4 , v127
	.byte	W30
	.byte		N03   , Fn4
	.byte	W03
	.byte		        Gn4
	.byte	W03
@ 012   ----------------------------------------
	.byte		N48   , En4
	.byte	W60
	.byte		N03   , Dn4
	.byte	W03
	.byte		        En4
	.byte	W03
	.byte		N18   , Dn4
	.byte	W18
	.byte		N12   , Cn4
	.byte	W12
@ 013   ----------------------------------------
	.byte		N48   , Gn3
	.byte	W48
	.byte		N12   , An3
	.byte	W12
	.byte		        As3
	.byte	W24
	.byte		N06   , Cn4
	.byte	W06
	.byte		        Dn4
	.byte	W06
@ 014   ----------------------------------------
	.byte		N48   , En4
	.byte	W60
	.byte		N24   , Fn4
	.byte	W24
	.byte		N12   , En4
	.byte	W12
@ 015   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N04   , Dn4
	.byte	W04
	.byte		        En4
	.byte	W04
	.byte		        Dn4
	.byte	W04
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Dn4
	.byte	W24
	.byte		N24   , Gs4
	.byte	W24
	.byte		N01   , Fn4
	.byte	W01
	.byte		        Dn4
	.byte	W02
	.byte		        Cn4
	.byte	W01
	.byte		        Gs3
	.byte	W02
	.byte		        Fn3
	.byte	W01
	.byte		        Dn3
	.byte	W02
	.byte		        Cn3
	.byte	W01
	.byte		        Gs2
	.byte	W02
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
	.byte	GOTO
	 .word	mus_union_room_7_B1
	.byte	W06
	.byte	FINE

@**************** Track 8 ****************@

mus_union_room_8:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_union_room_key+0
	.byte		VOICE , 48
	.byte		VOL   , 114*mus_union_room_mvl/mxv
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
mus_union_room_8_B1:
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
	.byte	W84
	.byte		N03   , Gn3 , v127
	.byte	W03
	.byte		        Gs3
	.byte	W03
	.byte		        An3
	.byte	W03
	.byte		        As3
	.byte	W03
@ 016   ----------------------------------------
	.byte		N48   , Bn3
	.byte	W60
	.byte		N24   , Dn4
	.byte	W24
	.byte		N12   , En4
	.byte	W12
@ 017   ----------------------------------------
	.byte		N48   , Cn4
	.byte	W60
	.byte		N24   , Dn4
	.byte	W24
	.byte		N12   , En4
	.byte	W12
@ 018   ----------------------------------------
	.byte		N48   , Fn4
	.byte	W60
	.byte		N24   , En4
	.byte	W24
	.byte		N12   , Dn4
	.byte	W12
@ 019   ----------------------------------------
	.byte		        Cn4
	.byte	W12
	.byte		        Bn3
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		N24   , Bn3
	.byte	W24
	.byte		        An4
	.byte	W24
	.byte		N12   , Gn4
	.byte	W12
@ 020   ----------------------------------------
	.byte		N48   , En4
	.byte		N48   , Bn4
	.byte	W60
	.byte		N24   , Gs4
	.byte		N24   , Dn5
	.byte	W24
	.byte		N12   , Bn4
	.byte		N12   , En5
	.byte	W12
@ 021   ----------------------------------------
	.byte		N48   , An4
	.byte		N48   , Cn5
	.byte	W60
	.byte		N24   , An4
	.byte		N24   , Dn5
	.byte	W24
	.byte		N12   , Bn4
	.byte		N12   , En5
	.byte	W12
@ 022   ----------------------------------------
	.byte		N48   , Cn5
	.byte		N48   , Fn5
	.byte	W60
	.byte		N24   , Cn5
	.byte		N24   , An5
	.byte	W24
	.byte		N12   , Dn5
	.byte		N12   , Bn5
	.byte	W12
@ 023   ----------------------------------------
	.byte		N48   , Cn5
	.byte		N96   , Gn5
	.byte	W48
	.byte		N48   , Bn4
	.byte	W48
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	GOTO
	 .word	mus_union_room_8_B1
	.byte	W06
	.byte	FINE

@**************** Track 9 ****************@

mus_union_room_9:
@ 000   ----------------------------------------
	.byte		VOL   , 127*mus_union_room_mvl/mxv
	.byte	KEYSH , mus_union_room_key+0
	.byte		VOICE , 0
	.byte		N12   , En3 , v088
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		        En3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		N12   
	.byte	W12
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte		        En3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		        En3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		N12   
	.byte	W12
@ 003   ----------------------------------------
	.byte		N06   , An4
	.byte	W24
	.byte		N24   , En3
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   , Fn3
	.byte		N24   , Fs3
	.byte		N24   , An4
	.byte		N24   , Bn4
	.byte		N24   , Cn5
	.byte	W24
@ 004   ----------------------------------------
mus_union_room_9_004:
	.byte		N12   , En3 , v088
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Dn3
	.byte	W12
	.byte		        Fn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		N12   , En3
	.byte	W12
	.byte		        Fn3
	.byte		N12   , An4
	.byte		N12   , Bn4
	.byte		N12   , Cn5
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
mus_union_room_9_005:
	.byte		N12   , En3 , v088
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Fn3
	.byte		N12   , An4
	.byte		N12   , Bn4
	.byte		N12   , Cn5
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_union_room_9_005
mus_union_room_9_006:
	.byte		VOL   , 127*mus_union_room_mvl/mxv
	.byte		N12   , En3 , v088
	.byte	W12
	.byte		        Fs3
	.byte		N12   , Gn3
	.byte		N12   , Bn4
	.byte	W12
	.byte		N06   , En3
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		        Fn3
	.byte		N12   , Fs3
	.byte		N12   , Bn4
	.byte	W12
	.byte		        Fn3
	.byte		N12   , Fs3
	.byte		N12   , Bn4
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte		        An4
	.byte		N12   , Bn4
	.byte		N12   , Cn5
	.byte	W12
	.byte		        En3
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
mus_union_room_9_B1:
	.byte		N12   , Fs3 , v088
	.byte		N12   , Gn3
	.byte	W12
	.byte		        Cn3
	.byte	W06
	.byte		        Fs3
	.byte		N12   , Gn3
	.byte	W06
	.byte		        Cn3
	.byte	W12
	.byte		        Fn3
	.byte		N12   , Gn3
	.byte	W12
	.byte		N06   , Fn3
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , En3
	.byte	W12
	.byte		        An4
	.byte		N12   , Bn4
	.byte		N12   , Cn5
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte	PEND
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_union_room_9_B1
	.byte	PATT
	 .word	mus_union_room_9_B1
	.byte	PATT
	 .word	mus_union_room_9_B1
	.byte	PATT
	 .word	mus_union_room_9_B1
	.byte	PATT
	 .word	mus_union_room_9_B1
	.byte	PATT
	 .word	mus_union_room_9_B1
	.byte		N12   , Fs3 , v088
	.byte		N12   , Gn3
	.byte	W12
	.byte		        Cn3
	.byte	W06
	.byte		        Fs3
	.byte		N12   , Gn3
	.byte	W06
	.byte		        Cn3
	.byte	W12
	.byte		        Fn3
	.byte		N12   , Gn3
	.byte	W12
	.byte		N06   , Fn3
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , En3
	.byte	W12
	.byte		        An4
	.byte		N12   , Bn4
	.byte		N12   , Cn5
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        Fn3
	.byte		N06   , Fs3
	.byte	W06
@ 009   ----------------------------------------
	.byte		N12   , Fn3
	.byte		N24   , Fs3
	.byte		N24   , An4
	.byte		N24   , Bn4
	.byte		N24   , Cn5
	.byte	W06
	.byte		N12   , En3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		        Fn3
	.byte		N24   , Fs3
	.byte		N24   , An4
	.byte		N24   , Bn4
	.byte		N24   , Cn5
	.byte	W12
	.byte		N12   , Cn3
	.byte	W06
	.byte		N06   , En3
	.byte	W06
@ 010   ----------------------------------------
	.byte		N12   , Fn3
	.byte		N24   , Fs3
	.byte		N24   , An4
	.byte		N24   , Bn4
	.byte		N24   , Cn5
	.byte	W06
	.byte		N06   , En3
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		        Fn3
	.byte		N24   , Fs3
	.byte		N24   , An4
	.byte		N24   , Bn4
	.byte		N24   , Cn5
	.byte	W12
	.byte		N06   , En3
	.byte	W06
	.byte		N12   
	.byte	W06
@ 011   ----------------------------------------
	.byte		        Fn3
	.byte		N24   , Fs3
	.byte		N24   , An4
	.byte		N24   , Bn4
	.byte		N24   , Cn5
	.byte	W06
	.byte		N12   , En3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		        Cn3
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N12   , An4
	.byte		N12   , Bn4
	.byte		N12   , Cn5
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        En3
	.byte	W06
@ 012   ----------------------------------------
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		N12   , En3
	.byte	W06
	.byte		        Fn3
	.byte		N12   , Fs3
	.byte		N24   , An4
	.byte		N12   , Bn4
	.byte		N24   , Cn5
	.byte	W06
	.byte		N12   , En3
	.byte	W06
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N06   , Bn4
	.byte	W06
	.byte		        Fn3
	.byte		N06   , Fs3
	.byte		N06   , Bn4
	.byte	W06
@ 013   ----------------------------------------
	.byte		        En3
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N12   , Gs4
	.byte		N12   , An4
	.byte		N12   , Bn4
	.byte		N12   , Cn5
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        En3
	.byte	W06
@ 014   ----------------------------------------
mus_union_room_9_014:
	.byte	W06
	.byte		N06   , En3 , v088
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		N06   , Fn3
	.byte		N06   , Fs3
	.byte		N12   , An4
	.byte		N12   , Bn4
	.byte		N12   , Cn5
	.byte	W06
	.byte		N06   , En3
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte	PEND
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_union_room_9_014
	.byte		VOL   , 127*mus_union_room_mvl/mxv
	.byte		N06   , Fn3 , v088
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		N12   , Fn3
	.byte		N12   , Fs3
	.byte		N12   , Bn4
	.byte	W12
	.byte		N06   , Fn3
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte		N12   , Fs3
	.byte		N12   , Bn4
	.byte	W12
	.byte		N06   , Fn3
	.byte		N12   , Fs3
	.byte		N12   , Bn4
	.byte	W06
	.byte		N06   , Fn3
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		        An4
	.byte		N12   , Bn4
	.byte		N12   , Cn5
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		N06   , En3
	.byte	W06
	.byte		N06   
	.byte	W06
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_union_room_9_004
	.byte	PATT
	 .word	mus_union_room_9_005
	.byte	PATT
	 .word	mus_union_room_9_005
	.byte	PATT
	 .word	mus_union_room_9_006
	.byte	GOTO
	 .word	mus_union_room_9_B1
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

mus_union_room:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_union_room_pri	@ Priority
	.byte	mus_union_room_rev	@ Reverb.

	.word	mus_union_room_grp

	.word	mus_union_room_1
	.word	mus_union_room_2
	.word	mus_union_room_3
	.word	mus_union_room_4
	.word	mus_union_room_5
	.word	mus_union_room_6
	.word	mus_union_room_7
	.word	mus_union_room_8
	.word	mus_union_room_9

	.end
