	.include "MPlayDef.s"

@ ShinyGold: Now an unidentified theme (no melodic match in GSC or FRLG music); map music of an
@ Ecruteak City interior.
@
@ The hack edited this song header in place (keeping the song ID) to point at new track data
@ it inserted at 0x08A03700; voicegroup changed from voicegroup131 to voicegroup008, 8 -> 6 tracks.
@ Disassembled from the hack ROM (no MIDI source exists).  Labels replace the hack's
@ absolute pointers; the byte stream of every track is identical to the hack's.
@ `_mvl` is 127, so `VOL , N*_mvl/mxv` emits N unchanged (edit _mvl to rescale volumes).

	.equ	mus_teachy_tv_show_grp, voicegroup008
	.equ	mus_teachy_tv_show_pri, 0
	.equ	mus_teachy_tv_show_rev, reverb_set+50
	.equ	mus_teachy_tv_show_mvl, 127
	.equ	mus_teachy_tv_show_key, 0
	.equ	mus_teachy_tv_show_tbs, 1
	.equ	mus_teachy_tv_show_exg, 0
	.equ	mus_teachy_tv_show_cmp, 1

	.section .rodata
	.global	mus_teachy_tv_show
	.align	2

@**************** Track 1 ****************@

mus_teachy_tv_show_1:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_teachy_tv_show_key+0
mus_teachy_tv_show_1_B1:
	.byte	TEMPO , 100*mus_teachy_tv_show_tbs/2
	.byte		VOICE , 88
	.byte		VOL   , 127*mus_teachy_tv_show_mvl/mxv
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W48
	.byte		N12   , Fn1 , v127
	.byte	W12
	.byte		        Gn1
	.byte	W12
	.byte		        Gs1
	.byte	W12
	.byte		        As1
	.byte	W12
@ 004   ----------------------------------------
mus_teachy_tv_show_1_004:
	.byte		N24   , Cn2 , v127
	.byte	W24
	.byte		        Gn2
	.byte	W24
	.byte		        Cs2
	.byte	W24
	.byte		        Gs2
	.byte	W24
	.byte	PEND
@ 005   ----------------------------------------
	.byte		        Cn2
	.byte	W24
	.byte		        Gn2
	.byte	W24
	.byte		        As1
	.byte	W24
	.byte		        Fn2
	.byte	W24
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_teachy_tv_show_1_004
mus_teachy_tv_show_1_006:
	.byte		N24   , Cn2 , v127
	.byte	W24
	.byte		        Gn2
	.byte	W24
	.byte		        Cn2
	.byte	W24
	.byte		        Gn1
	.byte	W24
	.byte	PEND
@ 007   ----------------------------------------
	.byte		N06   , Cn1
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N12   , Gn0
	.byte	W12
	.byte		        Gs0
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Cs1
	.byte	W12
@ 008   ----------------------------------------
	.byte		N06   , Cn1
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        Gn1
	.byte	W06
	.byte		        Gs1
	.byte	W06
	.byte		        Gn1
	.byte	W06
	.byte		        Fn1
	.byte	W06
	.byte		N12   , En1
	.byte	W12
	.byte		        Cn1
	.byte	W12
@ 009   ----------------------------------------
	.byte		N24   , Cs1
	.byte	W24
	.byte		        Gs1
	.byte	W24
	.byte		        Gn1
	.byte	W24
	.byte		        Fn1
	.byte	W24
@ 010   ----------------------------------------
	.byte		N48   , Cs2
	.byte	W48
	.byte		N24   , Cs1
	.byte	W24
	.byte		        Cs2
	.byte	W24
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_teachy_tv_show_1_004
	.byte	PATT
	 .word	mus_teachy_tv_show_1_006
	.byte	PATT
	 .word	mus_teachy_tv_show_1_004
mus_teachy_tv_show_1_011:
	.byte		N24   , Cn2 , v127
	.byte	W24
	.byte		        Gn2
	.byte	W24
	.byte		N48   , Cn2
	.byte	W48
	.byte	PEND
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_teachy_tv_show_1_004
	.byte	PATT
	 .word	mus_teachy_tv_show_1_006
	.byte	PATT
	 .word	mus_teachy_tv_show_1_004
	.byte	PATT
	 .word	mus_teachy_tv_show_1_011
	.byte	GOTO
	 .word	mus_teachy_tv_show_1_B1
	.byte	W06
	.byte	FINE

@**************** Track 2 ****************@

mus_teachy_tv_show_2:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_teachy_tv_show_key+0
mus_teachy_tv_show_2_B1:
	.byte		VOICE , 48
	.byte		VOL   , 119*mus_teachy_tv_show_mvl/mxv
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte		N06   , Cn3 , v080
	.byte	W06
	.byte		        Gn2
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        As2
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        Gs2
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        Bn2
	.byte	W06
	.byte		        Cs3
	.byte	W06
@ 005   ----------------------------------------
	.byte		        Cn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        As2
	.byte	W06
	.byte		        Ds3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        As2
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Gs3
	.byte	W06
@ 006   ----------------------------------------
	.byte		        Gn3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Gs3
	.byte	W06
@ 007   ----------------------------------------
	.byte		        Gn3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Gn2
	.byte	W06
	.byte		        As2
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Gn2
	.byte	W06
	.byte		        As2
	.byte	W06
	.byte		        Cs3
	.byte	W06
@ 008   ----------------------------------------
	.byte		        Cn2
	.byte		N06   , Gn2
	.byte		N06   , Cn3
	.byte	W96
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte		        En2
	.byte	W06
	.byte		        Gn2
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Gn2
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        As2
	.byte	W06
	.byte		        Gs2
	.byte	W06
	.byte		        As2
	.byte	W06
	.byte		        Gs2
	.byte	W06
	.byte		        Gn2
	.byte	W06
	.byte		        Fn2
	.byte	W06
@ 013   ----------------------------------------
	.byte		        En2
	.byte	W06
	.byte		        Fn2
	.byte	W06
	.byte		        Gn2
	.byte	W06
	.byte		        Gs2
	.byte	W06
	.byte		        Gn2
	.byte	W06
	.byte		        Fn2
	.byte	W06
	.byte		        En2
	.byte	W06
	.byte		        Fn2
	.byte	W06
	.byte		        Gn2
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        As2
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fn3
	.byte	W06
@ 014   ----------------------------------------
	.byte		        Gn3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cs3
	.byte	W06
@ 015   ----------------------------------------
	.byte		        Cn3
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cs3
	.byte	W05
	.byte		N03   , Cn3
	.byte	W03
	.byte		        Cs3
	.byte	W03
	.byte		        En3
	.byte	W03
	.byte		        Fn3
	.byte	W03
	.byte		        Gn3
	.byte	W03
	.byte		        Gs3
	.byte	W03
	.byte		        Bn3
	.byte	W03
	.byte		        Cn4
	.byte	W03
	.byte		        Fn3
	.byte	W03
	.byte		        Gn3
	.byte	W03
	.byte		        Gs3
	.byte	W03
	.byte		        Bn3
	.byte	W03
	.byte		        Cn4
	.byte	W03
	.byte		        Cs4
	.byte	W03
	.byte		        En4
	.byte	W03
	.byte		        Fn4
	.byte	W03
	.byte		N06   , En2
	.byte		N24   , Gn4
	.byte	W01
@ 016   ----------------------------------------
	.byte	W05
	.byte		N06   , Gn2
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        Cn3
	.byte		N24   , Cn5
	.byte	W06
	.byte		N06   , Gn2
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Cs3
	.byte		N12   , As4
	.byte	W06
	.byte		N06   , Cn3
	.byte	W06
	.byte		        As2
	.byte		N12   , Gs4
	.byte	W06
	.byte		N06   , Gs2
	.byte	W06
	.byte		        As2
	.byte		N12   , Gn4
	.byte	W06
	.byte		N06   , Gs2
	.byte	W06
	.byte		        Gn2
	.byte		N12   , Gs4
	.byte	W06
	.byte		N06   , Fn2
	.byte	W06
	.byte		        En2
	.byte		N24   , Gn4
	.byte	W01
@ 017   ----------------------------------------
	.byte	W05
	.byte		N06   , Fn2
	.byte	W06
	.byte		        Gn2
	.byte	W06
	.byte		        Gs2
	.byte	W06
	.byte		        Gn2
	.byte		N24   , Fn4
	.byte	W06
	.byte		N06   , Fn2
	.byte	W06
	.byte		        En2
	.byte	W06
	.byte		        Fn2
	.byte	W06
	.byte		        Gn2
	.byte		N12   , En4
	.byte	W06
	.byte		N06   , Cn3
	.byte	W06
	.byte		        Cs3
	.byte		N36   , Gn4
	.byte	W06
	.byte		N06   , As2
	.byte	W06
	.byte		        Cn3
	.byte	W06
	.byte		        Cs3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Gn3
	.byte		N24   , Gn4
	.byte	W01
@ 018   ----------------------------------------
	.byte	W05
	.byte		N06   , Fn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Gn3
	.byte		N24   , Cn5
	.byte	W06
	.byte		N06   , Cn4
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Gn3
	.byte		N12   , As4
	.byte	W06
	.byte		N06   , Gs3
	.byte	W06
	.byte		        Gn3
	.byte		N12   , Cn5
	.byte	W06
	.byte		N06   , Fn3
	.byte	W06
	.byte		        En3
	.byte		N12   , Cs5
	.byte	W06
	.byte		N06   , Fn3
	.byte	W06
	.byte		        En3
	.byte		N06   , As4
	.byte	W06
	.byte		        Cs3
	.byte		N06   , Ds5
	.byte	W06
	.byte		        Cn3
	.byte		N96   , Cn5
	.byte	W01
@ 019   ----------------------------------------
	.byte	W05
	.byte		N06   , Cs3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        En3
	.byte	W07
	.byte		        Cs3
	.byte		N06   , Fn3
	.byte	W06
	.byte		N48   , Cn3
	.byte		N48   , En3
	.byte	W48
@ 020   ----------------------------------------
	.byte	GOTO
	 .word	mus_teachy_tv_show_2_B1
	.byte	W06
	.byte	FINE

@**************** Track 3 ****************@

mus_teachy_tv_show_3:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_teachy_tv_show_key+0
mus_teachy_tv_show_3_B1:
	.byte		VOICE , 46
	.byte		VOL   , 108*mus_teachy_tv_show_mvl/mxv
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W48
	.byte		N03   , Cn4 , v127
	.byte	W03
	.byte		        Cs4
	.byte	W03
	.byte		        En4
	.byte	W03
	.byte		        Fn4
	.byte	W03
	.byte		        Gn4
	.byte	W03
	.byte		        Gs4
	.byte	W03
	.byte		        Bn4
	.byte	W03
	.byte		        Cn5
	.byte	W03
	.byte		        En5
	.byte	W03
	.byte		        Cn5
	.byte	W03
	.byte		        Bn4
	.byte	W03
	.byte		        Gs4
	.byte	W03
	.byte		        Gn4
	.byte	W03
	.byte		        Fn4
	.byte	W03
	.byte		        En4
	.byte	W03
	.byte		        Cs4
	.byte	W03
@ 004   ----------------------------------------
mus_teachy_tv_show_3_004:
	.byte		N12   , Cn4 , v127
	.byte	W12
	.byte		        Gn3
	.byte	W12
	.byte		        Gn4
	.byte	W24
	.byte		        Cs4
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		        Gs4
	.byte	W24
	.byte	PEND
@ 005   ----------------------------------------
	.byte		        Cn4
	.byte	W12
	.byte		        Gn3
	.byte	W12
	.byte		        Gn4
	.byte	W24
	.byte		        As3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        Fn4
	.byte	W24
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_teachy_tv_show_3_004
	.byte		N12   , Cn4 , v127
	.byte	W12
	.byte		        Gn3
	.byte	W12
	.byte		        Gn4
	.byte	W18
	.byte		N01   , Cn3
	.byte	W01
	.byte		        Gn3
	.byte	W02
	.byte		        Cn4
	.byte	W01
	.byte		        Gn4
	.byte	W02
	.byte		N24   , Cn5
	.byte	W48
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
	.byte	W92
	.byte	W03
	.byte		N06   , Cn3
	.byte	W01
@ 015   ----------------------------------------
	.byte	W05
	.byte		        En3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Cs3
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
	.byte		        Gs3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Cn3
	.byte	W01
@ 016   ----------------------------------------
	.byte	W05
	.byte		        En3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Cs4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Cs4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		N06   
	.byte	W01
@ 017   ----------------------------------------
	.byte	W05
	.byte		        Cn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Gn3
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        As3
	.byte	W06
	.byte		        Gs3
	.byte	W06
	.byte		        Cs4
	.byte	W06
	.byte		        Ds4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        En4
	.byte	W01
@ 018   ----------------------------------------
	.byte	W05
	.byte		        Fn4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		        Cn4
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte		N01   , Gn3
	.byte	W02
	.byte		        Cn4
	.byte	W01
	.byte		        En4
	.byte	W02
	.byte		        Gn4
	.byte	W01
	.byte		N48   , Cn5
	.byte	W48
	.byte	GOTO
	 .word	mus_teachy_tv_show_3_B1
	.byte	W06
@ 019   ----------------------------------------
	.byte	FINE

@**************** Track 4 ****************@

mus_teachy_tv_show_4:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_teachy_tv_show_key+0
mus_teachy_tv_show_4_B1:
	.byte		VOICE , 1
	.byte		VOL   , 127*mus_teachy_tv_show_mvl/mxv
	.byte		N24   , Gn3 , v127
	.byte		N24   , Cn4
	.byte	W24
	.byte		        Cn3
	.byte		N24   , Cn4
	.byte	W24
	.byte		N12   , Gs3
	.byte		N12   , Cs4
	.byte	W12
	.byte		        Gn3
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Fn3
	.byte		N12   , As3
	.byte	W12
	.byte		        Gs3
	.byte		N12   , Cs4
	.byte	W12
@ 001   ----------------------------------------
mus_teachy_tv_show_4_001:
	.byte		N24   , Gn3 , v127
	.byte		N24   , Cn4
	.byte	W24
	.byte		        Cn3
	.byte		N24   , Fn4
	.byte	W24
	.byte		N12   , As2
	.byte		N24   , Cs4
	.byte	W12
	.byte		N12   , Cn3
	.byte	W12
	.byte		        Cs3
	.byte		N24   , As3
	.byte	W12
	.byte		N12   , As2
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
mus_teachy_tv_show_4_002:
	.byte		N24   , Gn3 , v127
	.byte		N24   , Cn4
	.byte	W24
	.byte		        Cn3
	.byte		N24   , Cn4
	.byte	W24
	.byte		N12   , Gs3
	.byte		N12   , Cs4
	.byte	W12
	.byte		        Gn3
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Fn3
	.byte		N12   , As3
	.byte	W12
	.byte		        Gs3
	.byte		N12   , Cs4
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
	.byte		N24   , Gn3
	.byte		N24   , Cn4
	.byte	W24
	.byte		        Gn2
	.byte		N24   , Cn3
	.byte	W24
	.byte		        Gn3
	.byte		N24   , Cn4
	.byte	W36
	.byte		N12   , Fn3
	.byte		N12   , As3
	.byte	W12
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_teachy_tv_show_4_002
	.byte	PATT
	 .word	mus_teachy_tv_show_4_001
	.byte	PATT
	 .word	mus_teachy_tv_show_4_002
	.byte		N24   , Gn3 , v127
	.byte		N24   , Cn4
	.byte	W24
	.byte		        Gn2
	.byte		N24   , Cn3
	.byte	W24
	.byte		        Gn3
	.byte		N24   , Cn4
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
	.byte		N12   , Gn3
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		N24   , Cn4
	.byte	W24
	.byte		N12   , As3
	.byte	W12
	.byte		        Gs3
	.byte	W12
	.byte		N04   , Gn3
	.byte	W04
	.byte		        Gs3
	.byte	W04
	.byte		        Gn3
	.byte	W04
	.byte		N06   , Fn3
	.byte	W06
	.byte		        Gs3
	.byte	W06
@ 010   ----------------------------------------
	.byte		N24   , Gn3
	.byte	W24
	.byte		N12   , Cn3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		N48   , Gn3
	.byte	W48
@ 011   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		N24   , Cn4
	.byte	W24
	.byte		N12   , As3
	.byte	W12
	.byte		        Cn4
	.byte	W12
	.byte		N04   , Cs4
	.byte	W04
	.byte		        Ds4
	.byte	W04
	.byte		        Cn4
	.byte	W04
	.byte		N06   , As3
	.byte	W06
	.byte		        Cs4
	.byte	W06
@ 012   ----------------------------------------
	.byte		N12   , Cn4
	.byte	W12
	.byte		        Cn3
	.byte	W12
	.byte		        Gn3
	.byte	W12
	.byte		        Cs4
	.byte	W12
	.byte		N48   , Cn4
	.byte	W48
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	GOTO
	 .word	mus_teachy_tv_show_4_B1
	.byte	W06
	.byte	FINE

@**************** Track 5 ****************@

mus_teachy_tv_show_5:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_teachy_tv_show_key+0
mus_teachy_tv_show_5_B1:
	.byte		VOICE , 56
	.byte		VOL   , 127*mus_teachy_tv_show_mvl/mxv
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
	.byte		N06   , Cn2 , v127
	.byte		N06   , Gn2
	.byte		N06   , Cn3
	.byte	W24
	.byte		        Cn2
	.byte		N06   , Gn2
	.byte		N06   , Cn3
	.byte	W72
@ 009   ----------------------------------------
	.byte		        Cn2
	.byte		N06   , Gn2
	.byte		N06   , Cn3
	.byte	W24
	.byte		        Cn2
	.byte		N06   , Gn2
	.byte		N06   , Cn3
	.byte	W48
	.byte		N24   , Cn2
	.byte		N24   , Gn2
	.byte		N24   , Cn3
	.byte	W24
@ 010   ----------------------------------------
	.byte		N06   , Cs2
	.byte		N06   , Gs2
	.byte		N06   , Cs3
	.byte	W24
	.byte		        Cs2
	.byte		N06   , Gs2
	.byte		N06   , Cs3
	.byte	W48
	.byte		N24   , Cn2
	.byte		N24   , Gn2
	.byte		N24   , Cn3
	.byte	W24
@ 011   ----------------------------------------
	.byte		N06   , Cs2
	.byte		N06   , Gs2
	.byte		N06   , Cs3
	.byte	W24
	.byte		        Cs2
	.byte		N06   , Gs2
	.byte		N06   , Cs3
	.byte	W48
	.byte		N24   , Ds2
	.byte		N24   , As2
	.byte		N24   , Ds3
	.byte	W24
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
	.byte	GOTO
	 .word	mus_teachy_tv_show_5_B1
	.byte	W06
	.byte	FINE

@**************** Track 6 ****************@

mus_teachy_tv_show_6:
@ 000   ----------------------------------------
	.byte		VOL   , 127*mus_teachy_tv_show_mvl/mxv
	.byte	KEYSH , mus_teachy_tv_show_key+0
mus_teachy_tv_show_6_B1:
	.byte		VOICE , 0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W48
	.byte		N48   , An4 , v127
	.byte		N48   , Bn4
	.byte		N48   , Cn5
	.byte	W48
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W48
	.byte		        An4
	.byte		N48   , Bn4
	.byte		N48   , Cn5
	.byte	W12
	.byte		N12   , An3
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 004   ----------------------------------------
mus_teachy_tv_show_6_004:
	.byte		N12   , An3 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
mus_teachy_tv_show_6_005:
	.byte		N12   , An3 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N48   , An4
	.byte		N48   , Bn4
	.byte		N48   , Cn5
	.byte	W12
	.byte		N12   , An3
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_teachy_tv_show_6_004
	.byte	PATT
	 .word	mus_teachy_tv_show_6_005
	.byte		N12   , An3 , v127
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fs3
	.byte	W12
@ 007   ----------------------------------------
	.byte		        An3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		N48   , An4
	.byte		N48   , Bn4
	.byte		N48   , Cn5
	.byte	W12
	.byte		N12   , An3
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        Fn3
	.byte	W12
@ 008   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        Fs3
	.byte	W12
@ 009   ----------------------------------------
	.byte		        Fn3
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		        Fs3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		N48   , An4
	.byte		N48   , Bn4
	.byte		N48   , Cn5
	.byte	W12
	.byte		N12   , Fs3
	.byte	W12
	.byte		        Fn3
	.byte	W12
	.byte		        An3
	.byte	W12
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_teachy_tv_show_6_004
	.byte	PATT
	 .word	mus_teachy_tv_show_6_005
	.byte	PATT
	 .word	mus_teachy_tv_show_6_004
	.byte	PATT
	 .word	mus_teachy_tv_show_6_005
	.byte	PATT
	 .word	mus_teachy_tv_show_6_004
	.byte	PATT
	 .word	mus_teachy_tv_show_6_005
	.byte	PATT
	 .word	mus_teachy_tv_show_6_004
	.byte		N12   , An3 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N48   , An4
	.byte		N48   , Bn4
	.byte		N48   , Cn5
	.byte	W48
@ 011   ----------------------------------------
	.byte	GOTO
	 .word	mus_teachy_tv_show_6_B1
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

mus_teachy_tv_show:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_teachy_tv_show_pri	@ Priority
	.byte	mus_teachy_tv_show_rev	@ Reverb.

	.word	mus_teachy_tv_show_grp

	.word	mus_teachy_tv_show_1
	.word	mus_teachy_tv_show_2
	.word	mus_teachy_tv_show_3
	.word	mus_teachy_tv_show_4
	.word	mus_teachy_tv_show_5
	.word	mus_teachy_tv_show_6

	.end
