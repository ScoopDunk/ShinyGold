	.include "MPlayDef.s"

@ ShinyGold: Now an unidentified theme (no melodic match in GSC or FRLG music); map music of
@ a Trick House interior and some unused maps.
@
@ The hack edited this song header in place (keeping the song ID) to point at new track data
@ it inserted at 0x089E0000; voicegroup changed from voicegroup132 to voicegroup008, 8 -> 7 tracks.
@ Disassembled from the hack ROM (no MIDI source exists).  Labels replace the hack's
@ absolute pointers; the byte stream of every track is identical to the hack's.
@ `_mvl` is 127, so `VOL , N*_mvl/mxv` emits N unchanged (edit _mvl to rescale volumes).

	.equ	mus_berry_pick_grp, voicegroup008
	.equ	mus_berry_pick_pri, 0
	.equ	mus_berry_pick_rev, reverb_set+50
	.equ	mus_berry_pick_mvl, 127
	.equ	mus_berry_pick_key, 0
	.equ	mus_berry_pick_tbs, 1
	.equ	mus_berry_pick_exg, 0
	.equ	mus_berry_pick_cmp, 1

	.section .rodata
	.global	mus_berry_pick
	.align	2

@**************** Track 1 ****************@

mus_berry_pick_1:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_berry_pick_key+0
	.byte	TEMPO , 120*mus_berry_pick_tbs/2
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte	W24
mus_berry_pick_1_B1:
	.byte	TEMPO , 120*mus_berry_pick_tbs/2
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 110*mus_berry_pick_mvl/mxv
	.byte	PRIO  , 0
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W12
	.byte		N07   , Cs5 , v127
	.byte	W08
	.byte		N03   , Cs5 , v016
	.byte	W04
	.byte		N07   , As4 , v127
	.byte	W08
	.byte		N03   , As4 , v016
	.byte	W04
	.byte		N07   , Bn4 , v127
	.byte	W08
	.byte		N03   , Bn4 , v016
	.byte	W04
	.byte		N07   , Cs5 , v127
	.byte	W08
	.byte		N03   , Cs5 , v016
	.byte	W04
	.byte		N07   , Ds5 , v127
	.byte	W08
	.byte		N03   , Ds5 , v016
	.byte	W04
@ 002   ----------------------------------------
	.byte		N07   , As4 , v127
	.byte	W08
	.byte		N03   , Fs4
	.byte	W04
	.byte		N07   , Gs4
	.byte	W08
	.byte		N03   , Fs4
	.byte	W04
	.byte		        Fs4 , v016
	.byte	W96
@ 003   ----------------------------------------
	.byte	W12
	.byte		N07   , Cs5 , v127
	.byte	W08
	.byte		N03   , Cs5 , v016
	.byte	W04
	.byte		N07   , As4 , v127
	.byte	W08
	.byte		N03   , As4 , v016
	.byte	W04
	.byte		N07   , Bn4 , v127
	.byte	W08
	.byte		N03   , Bn4 , v016
	.byte	W04
	.byte		N07   , Cs5 , v127
	.byte	W08
	.byte		N03   , Cs5 , v016
	.byte	W04
	.byte		N07   , Ds5 , v127
	.byte	W08
	.byte		N03   , Ds5 , v016
	.byte	W04
@ 004   ----------------------------------------
	.byte		N07   , An4 , v127
	.byte	W08
	.byte		N03   , Fs4
	.byte	W04
	.byte		N07   , Gs4
	.byte	W08
	.byte		N03   , Fs4
	.byte	W04
	.byte		        Fs4 , v016
	.byte	W96
@ 005   ----------------------------------------
	.byte	W12
	.byte		N07   , Fs4 , v127
	.byte	W08
	.byte		N03   , Fs4 , v016
	.byte	W04
	.byte		N07   , Ds4 , v127
	.byte	W08
	.byte		N03   , Ds4 , v016
	.byte	W04
	.byte		N07   , En4 , v127
	.byte	W08
	.byte		N03   , En4 , v016
	.byte	W04
	.byte		N07   , Fs4 , v127
	.byte	W08
	.byte		N03   , Fs4 , v016
	.byte	W04
	.byte		N07   , Bn4 , v127
	.byte	W08
	.byte		N03   , Bn4 , v016
	.byte	W04
@ 006   ----------------------------------------
	.byte		N07   , An4 , v127
	.byte	W08
	.byte		N03   , Fs4
	.byte	W04
	.byte		N07   , Gs4
	.byte	W08
	.byte		N03   , Fs4
	.byte	W04
	.byte		        Fs4 , v016
	.byte	W96
@ 007   ----------------------------------------
	.byte	W12
	.byte		N07   , Gs4 , v127
	.byte	W08
	.byte		N03   , Gs4 , v016
	.byte	W04
	.byte		N07   , Fn4 , v127
	.byte	W08
	.byte		N03   , Fn4 , v016
	.byte	W04
	.byte		N07   , Fs4 , v127
	.byte	W08
	.byte		N03   , Fs4 , v016
	.byte	W04
	.byte		N07   , Gs4 , v127
	.byte	W08
	.byte		N03   , Gs4 , v016
	.byte	W04
	.byte		N07   , As4 , v127
	.byte	W08
	.byte		N03   , As4 , v016
	.byte	W04
@ 008   ----------------------------------------
	.byte		N07   , Bn4 , v127
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte		N03   , Cn5 , v016
	.byte	W04
	.byte		N07   , Cs5 , v127
	.byte	W04
	.byte	W04
	.byte		N03   , Cs5 , v016
	.byte	W20
	.byte		N07   , Cs5 , v127
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N03   , Cs5 , v016
	.byte	W04
	.byte		        Ds5 , v127
	.byte	W04
	.byte		N07   , En5
	.byte	W08
	.byte		N03   , Cs5
	.byte	W04
	.byte		N07   , Ds5
	.byte	W08
	.byte		N03   , Cs5
	.byte	W04
@ 009   ----------------------------------------
	.byte		        Cs5 , v016
	.byte	W24
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte		N07   , Gn5 , v127
	.byte	W08
	.byte		N03   , Gn5 , v016
	.byte	W04
	.byte		N07   , Dn5 , v127
	.byte	W08
	.byte		N03   , Dn5 , v016
	.byte	W04
	.byte		N07   , En5 , v127
	.byte	W08
	.byte		N03   , Dn5
	.byte	W04
	.byte		        Dn5 , v016
	.byte	W08
	.byte		        Fn5 , v127
	.byte	W04
	.byte		        Fn5 , v016
	.byte	W08
	.byte		        Fn5 , v127
	.byte	W04
	.byte		N07   , Dn5
	.byte	W08
	.byte		N03   , Dn5 , v016
	.byte	W04
@ 012   ----------------------------------------
	.byte		N07   , En5 , v127
	.byte	W08
	.byte		N03   , Dn5
	.byte	W04
	.byte		        Dn5 , v016
	.byte	W08
	.byte		        Fn5 , v127
	.byte	W04
	.byte		        Fn5 , v016
	.byte	W08
	.byte		        Fn5 , v127
	.byte	W04
	.byte		N07   , En5
	.byte	W08
	.byte		N03   , En5 , v016
	.byte	W04
	.byte		N07   , Dn5 , v127
	.byte	W08
	.byte		        En5
	.byte	W08
	.byte		N03   , En5 , v016
	.byte	W04
	.byte		N07   , Gn4 , v127
	.byte	W08
	.byte		N03   , Gn4 , v016
	.byte	W44
@ 013   ----------------------------------------
	.byte		N07   , Gn5 , v127
	.byte	W08
	.byte		N03   , Gn5 , v016
	.byte	W04
	.byte		N07   , Dn5 , v127
	.byte	W08
	.byte		N03   , Dn5 , v016
	.byte	W04
	.byte		N07   , En5 , v127
	.byte	W08
	.byte		N03   , Dn5
	.byte	W04
	.byte		        Dn5 , v016
	.byte	W08
	.byte		        Fn5 , v127
	.byte	W04
	.byte		        Fn5 , v016
	.byte	W08
	.byte		        Fn5 , v127
	.byte	W04
	.byte		N07   , En5
	.byte	W08
	.byte		N03   , En5 , v016
	.byte	W04
@ 014   ----------------------------------------
	.byte		N07   , Dn5 , v127
	.byte	W08
	.byte		N03   , Ds5
	.byte	W04
	.byte		N07   , En5
	.byte	W08
	.byte		        Fn5
	.byte	W04
	.byte	W04
	.byte		N03   , Fn5 , v016
	.byte	W04
	.byte		        Fn5 , v127
	.byte	W04
	.byte		N07   , En5
	.byte	W08
	.byte		N03   , En5 , v016
	.byte	W04
	.byte		N07   , Dn5 , v127
	.byte	W08
	.byte		N03   , En5
	.byte	W04
	.byte		N07   , Fn5
	.byte	W08
	.byte		        Gn5
	.byte	W08
	.byte		N03   , Gn5 , v016
	.byte	W44
@ 015   ----------------------------------------
	.byte		N07   , As4 , v127
	.byte	W08
	.byte		N03   , As4 , v016
	.byte	W04
	.byte		N07   , Gn4 , v127
	.byte	W08
	.byte		N03   , Gn4 , v016
	.byte	W04
	.byte		N07   , An4 , v127
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		N03   , Gn4 , v016
	.byte	W04
	.byte		N07   , As4 , v127
	.byte	W08
	.byte		N03   , As4 , v016
	.byte	W04
	.byte		        As4 , v127
	.byte	W04
	.byte		N07   , Cn5
	.byte	W08
	.byte		N03   , Cn5 , v016
	.byte	W04
@ 016   ----------------------------------------
	.byte		N07   , Dn5 , v127
	.byte	W08
	.byte		        Fn5
	.byte	W08
	.byte		N03   , Fn5 , v016
	.byte	W04
	.byte		        Dn5 , v127
	.byte	W04
	.byte		N07   , Gn5
	.byte	W08
	.byte		N03   , Gn5 , v016
	.byte	W04
	.byte		N07   , Dn5 , v127
	.byte	W08
	.byte		N03   , Dn5 , v016
	.byte	W04
	.byte		N07   , Gn5 , v127
	.byte	W08
	.byte		        Fs5
	.byte	W08
	.byte		N03   , Fs5 , v016
	.byte	W04
	.byte		        Fn5 , v127
	.byte	W04
	.byte		N07   , En5
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N03   , En5 , v016
	.byte	W04
	.byte		N07   , Bn4 , v127
	.byte	W08
@ 017   ----------------------------------------
	.byte		N03   , Bn4 , v016
	.byte	W20
	.byte		N07   , As4 , v127
	.byte	W08
	.byte		N03   , As4 , v016
	.byte	W04
	.byte		N07   , Gn4 , v127
	.byte	W08
	.byte		N03   , Gn4 , v016
	.byte	W04
	.byte		N07   , An4 , v127
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		N03   , Gn4 , v016
	.byte	W04
	.byte		N07   , As4 , v127
	.byte	W08
	.byte		N03   , As4 , v016
	.byte	W04
	.byte		        As4 , v127
	.byte	W04
	.byte		N07   , Cn5
	.byte	W08
	.byte		N03   , Dn5
	.byte	W04
@ 018   ----------------------------------------
	.byte		N07   , As4
	.byte	W08
	.byte		N03   , Gn4
	.byte	W04
	.byte		N07   , Fn4
	.byte	W08
	.byte		        Gn4
	.byte	W04
	.byte	W04
	.byte		N03   , Gn4 , v016
	.byte	W08
	.byte		N07   , Gn4 , v127
	.byte	W08
	.byte		N03   , Gn4 , v016
	.byte	W04
	.byte		N07   , Dn5 , v127
	.byte	W08
	.byte		N03   , As4
	.byte	W04
	.byte		N07   , Cn5
	.byte	W08
	.byte		N03   , Dn5
	.byte	W04
	.byte		        Dn5 , v016
	.byte	W08
	.byte		N07   , Dn5 , v127
	.byte	W08
	.byte		N03   , Dn5 , v016
	.byte	W04
	.byte		        Dn4 , v127
	.byte	W04
@ 019   ----------------------------------------
	.byte		N07   
	.byte	W08
	.byte		N03   , Dn4 , v016
	.byte	W04
	.byte		N07   , Dn4 , v127
	.byte	W08
	.byte		N03   , Dn4 , v016
	.byte	W04
mus_berry_pick_1_019:
	.byte		N07   , Gn4 , v127
	.byte	W08
	.byte		N03   , Gn4 , v016
	.byte	W04
	.byte		N07   , Gn4 , v127
	.byte	W08
	.byte		N03   , Gn4 , v016
	.byte	W04
	.byte		N07   , Gn4 , v127
	.byte	W08
	.byte		N03   , Gn4 , v016
	.byte	W04
	.byte		N07   , Dn4 , v127
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		N03   , Gn4 , v016
	.byte	W04
	.byte		        Gn4 , v127
	.byte	W04
	.byte		        Gn4 , v016
	.byte	W08
	.byte		        Gn4 , v127
	.byte	W04
@ 020   ----------------------------------------
	.byte		N07   
	.byte	W08
	.byte		N03   , Gn4 , v016
	.byte	W04
	.byte		N07   , Dn4 , v127
	.byte	W08
	.byte		N03   , Dn4 , v016
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_berry_pick_1_019
	.byte	PATT
	 .word	mus_berry_pick_1_019
mus_berry_pick_1_020:
	.byte	W08
	.byte		N03   , Gn4 , v127
	.byte	W04
	.byte		N01   , An4
	.byte	W02
	.byte		N05   , As4
	.byte	W06
	.byte		N03   , Gn4
	.byte	W04
	.byte		N07   , An4
	.byte	W08
	.byte		N03   , Gn4
	.byte	W04
	.byte		        Gn4 , v016
	.byte	W08
	.byte		        Gn4 , v127
	.byte	W04
	.byte		N01   , An4
	.byte	W02
	.byte		N05   , As4
	.byte	W06
	.byte		N03   , Gn4
	.byte	W04
	.byte		N07   , An4
	.byte	W08
	.byte		N03   , Gn4
	.byte	W04
@ 021   ----------------------------------------
	.byte		        Gn4 , v016
	.byte	W24
	.byte	PEND
	.byte		N07   , Dn5 , v127
	.byte	W08
	.byte		N03   , Dn5 , v016
	.byte	W04
	.byte		N07   , Dn5 , v127
	.byte	W08
	.byte		N03   , Dn5 , v016
	.byte	W04
	.byte		N07   , Dn5 , v127
	.byte	W08
	.byte		N03   , Dn5 , v016
	.byte	W04
	.byte		N07   , Gn4 , v127
	.byte	W08
	.byte		N01   , Cs5
	.byte	W02
	.byte		N09   , Dn5
	.byte	W10
	.byte		N03   
	.byte	W04
	.byte		        Dn5 , v016
	.byte	W08
	.byte		        Dn5 , v127
	.byte	W04
@ 022   ----------------------------------------
	.byte		N07   
	.byte	W08
	.byte		N03   , Dn5 , v016
	.byte	W04
	.byte		N07   , Gn4 , v127
	.byte	W08
	.byte		N03   , Gn4 , v016
	.byte	W04
	.byte	PATT
	 .word	mus_berry_pick_1_020
	.byte		N03   , Cn5 , v127
	.byte	W04
	.byte		        Cs5
	.byte	W04
	.byte		        Dn5
	.byte	W04
	.byte		        Cn5
	.byte	W04
	.byte		        Cs5
	.byte	W04
	.byte		        Dn5
	.byte	W04
	.byte		        Cn5
	.byte	W04
	.byte		        Cs5
	.byte	W04
	.byte		        Dn5
	.byte	W04
	.byte		        Cn5
	.byte	W04
	.byte		        Cs5
	.byte	W04
	.byte		        Dn5
	.byte	W04
	.byte		N07   , Fn5
	.byte	W08
	.byte		N03   , Dn5
	.byte	W04
	.byte		        Dn5 , v016
	.byte	W08
	.byte		        An4 , v127
	.byte	W04
@ 023   ----------------------------------------
	.byte		N07   , Cn5
	.byte	W08
	.byte		        Dn5
	.byte	W08
	.byte		N03   , Dn5 , v016
	.byte	W04
	.byte		        Dn5 , v127
	.byte	W04
	.byte		        Dn5 , v016
	.byte	W12
	.byte		N07   , Fn5 , v127
	.byte	W08
	.byte		N03   , Fn5 , v016
	.byte	W04
	.byte		N07   , Fn5 , v127
	.byte	W08
	.byte		N03   , Dn5
	.byte	W04
	.byte		        Dn5 , v016
	.byte	W08
	.byte		        Dn5 , v127
	.byte	W04
	.byte		N07   , Fn5
	.byte	W08
	.byte		N03   , Fn5 , v016
	.byte	W04
	.byte		N07   , Fn5 , v127
	.byte	W08
	.byte		        Dn5
	.byte	W08
@ 024   ----------------------------------------
	.byte		N01   , Cn5
	.byte	W02
	.byte		        As4
	.byte	W02
	.byte		        An4
	.byte	W02
	.byte		        Gn4
	.byte	W02
	.byte		        Fn4
	.byte	W02
	.byte		        Ds4
	.byte	W02
	.byte		        Dn4
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		        Fn4
	.byte	W04
	.byte		        Fs4
	.byte	W04
	.byte		        An4
	.byte	W04
	.byte		        Fn4
	.byte	W04
	.byte		        Fs4
	.byte	W04
	.byte		        An4
	.byte	W04
	.byte		        Fn4
	.byte	W04
	.byte		        Fs4
	.byte	W04
	.byte		        An4
	.byte	W04
	.byte		        Fn4
	.byte	W04
	.byte		        Fs4
	.byte	W04
	.byte		        An4
	.byte	W04
	.byte		N07   , Cn5
	.byte	W08
	.byte		N03   , As4
	.byte	W04
	.byte		        As4 , v016
	.byte	W08
	.byte		        Dn4 , v127
	.byte	W04
@ 025   ----------------------------------------
	.byte		N07   , Fn4
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		N03   , Gn4 , v016
	.byte	W04
	.byte		        Gn4 , v127
	.byte	W04
	.byte	W12
	.byte		N07   , Fn4
	.byte	W08
	.byte		N03   , Fn4 , v016
	.byte	W04
	.byte		N07   , Fn4 , v127
	.byte	W08
	.byte		N03   , As4
	.byte	W04
	.byte		        As4 , v016
	.byte	W08
	.byte		        As4 , v127
	.byte	W04
	.byte		N07   , Fn4
	.byte	W08
	.byte		N03   , Fn4 , v016
	.byte	W04
	.byte		N07   , Fn4 , v127
	.byte	W08
	.byte		        As4
	.byte	W08
@ 026   ----------------------------------------
	.byte		N01   , An4
	.byte	W02
	.byte		        Gn4
	.byte	W02
	.byte		        Fn4
	.byte	W02
	.byte		        Ds4
	.byte	W02
	.byte		N03   , Dn4
	.byte	W06
	.byte		N03   
	.byte	W06
mus_berry_pick_1_026:
	.byte		N09   , Fn4 , v127
	.byte	W10
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N03   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N03   , Dn4
	.byte	W04
	.byte		N01   
	.byte	W48
	.byte	PEND
@ 027   ----------------------------------------
	.byte	PATT
	 .word	mus_berry_pick_1_026
mus_berry_pick_1_027:
	.byte		N05   , En5 , v127
	.byte	W06
	.byte		        Fn5
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        En5
	.byte	W06
	.byte		        Fn5
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        As5
	.byte	W06
	.byte		        Fn5
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
@ 028   ----------------------------------------
	.byte		        En5
	.byte	W06
	.byte		        Fn5
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte	PEND
	.byte		N03   , Fn5 , v016
	.byte	W12
	.byte		        Cn5 , v127
	.byte	W04
	.byte		        Cs5
	.byte	W04
	.byte		        Dn5
	.byte	W04
	.byte		N07   , Fn5
	.byte	W08
	.byte		N03   , Fn5 , v016
	.byte	W04
	.byte		        Cn5 , v127
	.byte	W04
	.byte		        Cs5
	.byte	W04
	.byte		        Dn5
	.byte	W04
	.byte		N07   , Fn4
	.byte	W08
	.byte		N03   , Fn4 , v016
	.byte	W04
	.byte		N05   , Cs5 , v127
	.byte	W06
	.byte		        Dn5
	.byte	W06
@ 029   ----------------------------------------
	.byte		N03   , Dn5 , v016
	.byte	W06
	.byte		N05   , Cs5 , v127
	.byte	W06
	.byte		        Dn5
	.byte	W08
	.byte		N03   , Dn5 , v016
	.byte	W04
	.byte	PATT
	 .word	mus_berry_pick_1_027
	.byte		N03   , Fn5 , v016
	.byte	W12
	.byte		        Gn4 , v127
	.byte	W04
	.byte		        Gs4
	.byte	W04
	.byte		        An4
	.byte	W04
	.byte		N07   , As4
	.byte	W08
	.byte		N03   , As4 , v016
	.byte	W04
	.byte		        Gn4 , v127
	.byte	W04
	.byte		        Gs4
	.byte	W04
	.byte		        An4
	.byte	W04
	.byte		N07   , As3
	.byte	W08
	.byte		N03   , As3 , v016
	.byte	W04
	.byte		N05   , Fs4 , v127
	.byte	W06
	.byte		        Gn4
	.byte	W12
@ 030   ----------------------------------------
	.byte		        Fs4
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte		        Dn5
	.byte	W06
	.byte		N03   , As5
	.byte	W04
	.byte		        An5
	.byte	W04
	.byte		        Gn5
	.byte	W04
	.byte		        Fn5
	.byte	W04
	.byte		        Ds5
	.byte	W04
	.byte		        Dn5
	.byte	W04
	.byte		        As5
	.byte	W04
	.byte		        An5
	.byte	W04
	.byte		        Gn5
	.byte	W04
	.byte		        Fn5
	.byte	W04
	.byte		        Ds5
	.byte	W04
	.byte		        Dn5
	.byte	W04
	.byte		        As5
	.byte	W04
	.byte		        An5
	.byte	W04
	.byte		        Gn5
	.byte	W04
	.byte		        Fn5
	.byte	W04
	.byte		        Ds5
	.byte	W04
	.byte		        Dn5
	.byte	W04
@ 031   ----------------------------------------
	.byte		        As5
	.byte	W04
	.byte		        An5
	.byte	W04
	.byte		        Gn5
	.byte	W04
	.byte		        Fn5
	.byte	W04
	.byte		        Ds5
	.byte	W04
	.byte		        Dn5
	.byte	W04
	.byte		N01   , An4
	.byte	W02
	.byte		N05   , As4
	.byte	W06
	.byte		N03   , Gn4
	.byte	W04
	.byte		        Gn4 , v016
	.byte	W08
	.byte		        Dn4 , v127
	.byte	W04
	.byte		N07   , Gn4
	.byte	W08
	.byte		        As4
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte		        Cs5
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Cs5 , v016
	.byte	W08
	.byte		N07   , Cn5 , v127
	.byte	W12
@ 032   ----------------------------------------
	.byte		N03   , Bn4
	.byte	W04
	.byte		N07   , Cn5
	.byte	W08
	.byte		N03   , Cn5 , v016
	.byte	W04
	.byte		N01   , Gs4 , v127
	.byte	W02
	.byte		N05   , An4
	.byte	W06
	.byte		N03   , En4
	.byte	W04
	.byte		        En4 , v016
	.byte	W08
	.byte		        Cn4 , v127
	.byte	W04
	.byte		N07   , An4
	.byte	W08
	.byte		N03   , Cn5
	.byte	W04
	.byte		N07   , Dn5
	.byte	W08
	.byte		N03   , Ds5
	.byte	W04
	.byte		N07   , Dn5
	.byte	W08
	.byte		N03   , Cs5
	.byte	W04
	.byte		N07   , Cn5
	.byte	W08
	.byte		N03   , Dn5
	.byte	W04
@ 033   ----------------------------------------
	.byte		N01   , An4
	.byte	W02
	.byte		N05   , As4
	.byte	W06
	.byte		N07   , Gn4
	.byte	W08
	.byte		N03   , Gn4 , v016
	.byte	W04
	.byte		        Dn5 , v127
	.byte	W04
	.byte		N07   , Gn5
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Gn5 , v016
	.byte	W12
	.byte		N07   , Gn5 , v127
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Gn5 , v016
	.byte	W12
	.byte		N07   , Gn5 , v127
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Gn5 , v016
	.byte	W08
	.byte		        Gn5 , v127
	.byte	W04
@ 034   ----------------------------------------
	.byte		N03   
	.byte	W04
	.byte		        Gn5 , v016
	.byte	W08
	.byte		N23   , As5 , v127
	.byte	W12
	.byte	W12
	.byte		N09   
	.byte	W10
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N03   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N03   , As5 , v016
	.byte	W16
@ 035   ----------------------------------------
	.byte	W24
	.byte	GOTO
	 .word	mus_berry_pick_1_B1
	.byte	W06
	.byte	FINE

@**************** Track 2 ****************@

mus_berry_pick_2:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_berry_pick_key+0
	.byte		VOICE , 46
	.byte		PAN   , c_v-48
	.byte	W24
mus_berry_pick_2_B1:
	.byte		VOICE , 46
	.byte		VOL   , 82*mus_berry_pick_mvl/mxv
	.byte	W80
@ 001   ----------------------------------------
	.byte		N15   , Cn4 , v112
	.byte	W16
mus_berry_pick_2_001:
	.byte		N78   , Cs4 , v112
	.byte	W80
@ 002   ----------------------------------------
	.byte		N15   , Cn4
	.byte	W16
	.byte	PEND
	.byte		N11   , Cs4
	.byte	W12
	.byte		N03   , Cs4 , v016
	.byte	W12
	.byte		N11   , Ds4 , v112
	.byte	W12
	.byte		N03   , Ds4 , v016
	.byte	W12
	.byte		N07   , En4 , v112
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N03   , En4 , v016
	.byte	W04
	.byte		        Ds4 , v112
	.byte	W04
@ 003   ----------------------------------------
	.byte		        Ds4 , v016
	.byte	W08
	.byte		N11   , Cn4 , v112
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte	PATT
	 .word	mus_berry_pick_2_001
	.byte		N11   , Cs4 , v112
	.byte	W12
	.byte		N03   , Cs4 , v016
	.byte	W12
	.byte		N11   , Ds4 , v112
	.byte	W12
	.byte		N03   , Ds4 , v016
	.byte	W12
	.byte		N07   , En4 , v112
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N03   , En4 , v016
	.byte	W04
	.byte		        Fs4 , v112
	.byte	W04
@ 004   ----------------------------------------
	.byte		        Fs4 , v016
	.byte	W08
	.byte		N11   , Gs4 , v112
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N30   , An4
	.byte	W32
	.byte		N11   , Gs4
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N30   , An4
	.byte	W32
@ 005   ----------------------------------------
	.byte		N11   , Fn4
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N11   , Fs4
	.byte	W12
	.byte		N07   , Dn4
	.byte	W08
	.byte		N11   , Ds4
	.byte	W12
	.byte		N03   , As3
	.byte	W04
	.byte		N07   , Bn3
	.byte	W08
	.byte		N03   , Fs3
	.byte	W04
	.byte		        Ds3
	.byte	W04
	.byte		        Fs3
	.byte	W04
	.byte		        Bn3
	.byte	W04
	.byte		N07   , Ds4
	.byte	W08
	.byte		N03   , As3
	.byte	W04
@ 006   ----------------------------------------
	.byte		N07   , Bn3
	.byte	W08
	.byte		N11   
	.byte	W12
	.byte		N03   , Cn4
	.byte	W04
	.byte		N07   , Cs4
	.byte	W08
	.byte		N11   , Gs3
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N07   , Ds4
	.byte	W08
	.byte		N11   , Gs3
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N07   , En4
	.byte	W08
	.byte		N11   , Gs3
	.byte	W12
	.byte		N03   , En4
	.byte	W04
@ 007   ----------------------------------------
	.byte		N07   , Ds4
	.byte	W08
	.byte		N03   , Gs3
	.byte	W04
	.byte		        As3
	.byte	W04
	.byte		        Bn3
	.byte	W04
	.byte		        Cn4
	.byte	W04
	.byte		        Cs4
	.byte	W04
	.byte		        Cs4 , v016
	.byte	W04
	.byte		        Gs3 , v112
	.byte	W04
	.byte		N07   , Cs4
	.byte	W08
	.byte		        Fn3
	.byte	W08
	.byte		N11   , Cs4
	.byte	W12
	.byte		N03   , Gs3
	.byte	W04
	.byte		        Bn3
	.byte	W04
	.byte		N07   , En4
	.byte	W08
	.byte		N03   , Cs4
	.byte	W04
	.byte		N07   , Ds4
	.byte	W08
	.byte		N11   , Cs4
	.byte	W12
@ 008   ----------------------------------------
	.byte		        Cn4
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N07   , Cs4
	.byte	W08
	.byte		N11   
	.byte	W12
	.byte		N03   , Cs4 , v016
	.byte	W04
	.byte		N07   , Cs4 , v112
	.byte	W08
	.byte		N11   
	.byte	W12
	.byte		N03   , Bn3
	.byte	W04
	.byte		N07   , As3
	.byte	W08
	.byte		N03   , Cs4
	.byte	W04
	.byte		N07   , Ds4
	.byte	W08
	.byte		N15   , En4
	.byte	W16
@ 009   ----------------------------------------
	.byte		N07   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N68   , Fn4
	.byte	W72
@ 010   ----------------------------------------
	.byte		N03   , Fn4 , v016
	.byte	W24
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
	.byte	W48
	.byte		VOICE , 2
	.byte		N05   , Gn5 , v112
	.byte	W06
	.byte		N01   , Fn5
	.byte	W02
	.byte		        En5
	.byte	W02
	.byte		        Dn5
	.byte	W02
	.byte		        Cn5
	.byte	W02
	.byte		        Bn4
	.byte	W02
	.byte		        An4
	.byte	W02
	.byte		        Gn4
	.byte	W02
	.byte		        Fn4
	.byte	W02
	.byte		        En4
	.byte	W02
@ 020   ----------------------------------------
	.byte		        Dn4
	.byte	W02
	.byte		        Cn4
	.byte	W02
	.byte		        Bn3
	.byte	W02
	.byte		        An3
	.byte	W02
	.byte		        Gn3
	.byte	W02
	.byte		        Fn3
	.byte	W02
	.byte		        En3
	.byte	W02
	.byte		        Dn3
	.byte	W02
	.byte		N03   
	.byte	W04
	.byte		        As3
	.byte	W04
	.byte	W08
	.byte		        Gn3
	.byte	W04
	.byte		        Gn3 , v016
	.byte	W08
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v016
	.byte	W08
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v016
	.byte	W08
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v016
	.byte	W08
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v016
	.byte	W08
	.byte		        Gn3 , v112
	.byte	W04
@ 021   ----------------------------------------
	.byte		        Gn3 , v016
	.byte	W08
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v016
	.byte	W08
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v016
	.byte	W08
	.byte		        As3 , v112
	.byte	W04
	.byte		        As3 , v016
	.byte	W08
	.byte		        As3 , v112
	.byte	W04
	.byte		        As3 , v016
	.byte	W08
	.byte		        As3 , v112
	.byte	W04
	.byte		        As3 , v016
	.byte	W08
	.byte		        As3 , v112
	.byte	W04
	.byte		        As3 , v016
	.byte	W08
	.byte		        As3 , v112
	.byte	W04
	.byte		        As3 , v016
	.byte	W08
	.byte		        As3 , v112
	.byte	W04
@ 022   ----------------------------------------
	.byte		        As3 , v016
	.byte	W08
	.byte		        As3 , v112
	.byte	W04
	.byte		        As3 , v016
	.byte	W08
	.byte		        As3 , v112
	.byte	W04
	.byte		N09   , Gn3
	.byte	W10
	.byte		N01   , Ds3 , v127
	.byte	W02
	.byte		N11   , En3
	.byte	W12
	.byte		N07   , Gn3 , v112
	.byte	W08
	.byte		N11   , An3
	.byte	W12
	.byte		N01   , An3 , v127
	.byte	W02
	.byte		N09   , As3 , v112
	.byte	W10
	.byte		N11   
	.byte	W12
	.byte		        An3
	.byte	W12
@ 023   ----------------------------------------
	.byte		N01   , An3 , v127
	.byte	W02
	.byte		N13   , As3 , v112
	.byte	W14
	.byte		N03   , As3 , v016
	.byte	W12
	.byte		N11   , An3 , v112
	.byte	W12
	.byte		N07   
	.byte	W08
	.byte		N15   , As3
	.byte	W16
	.byte		N01   , Fn3
	.byte	W02
	.byte		N09   , Fs3
	.byte	W10
	.byte		N09   
	.byte	W10
	.byte		        Gn3
	.byte	W10
@ 024   ----------------------------------------
	.byte		N01   , An3
	.byte	W02
	.byte		N13   , As3
	.byte	W14
	.byte		N07   , Fn3
	.byte	W08
	.byte		N11   , Fs3
	.byte	W12
	.byte		N03   , An3
	.byte	W04
	.byte		        An3 , v016
	.byte	W08
	.byte		        An3 , v112
	.byte	W04
	.byte		        An3 , v016
	.byte	W12
	.byte		N07   , Ds3 , v112
	.byte	W08
	.byte		N11   , En3
	.byte	W12
	.byte		N03   , Gn3
	.byte	W04
@ 025   ----------------------------------------
	.byte		        Gn3 , v016
	.byte	W08
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        As3
	.byte	W04
	.byte		        As3 , v016
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W04
	.byte		        Cs4 , v016
	.byte	W08
	.byte		        As3 , v112
	.byte	W04
	.byte		        As3 , v016
	.byte	W08
	.byte		N01   , Bn3 , v112
	.byte	W02
	.byte		N05   , Cn4
	.byte	W06
	.byte		N03   , As3
	.byte	W04
	.byte		        As3 , v016
	.byte	W08
	.byte		        As3 , v112
	.byte	W04
	.byte		N07   , Cs4
	.byte	W08
	.byte		N03   , As3
	.byte	W04
	.byte		N07   , Cn4
	.byte	W08
	.byte		N24   , As3
	.byte	W24
@ 026   ----------------------------------------
	.byte	W02
	.byte		N01   , Cs4
	.byte	W02
	.byte		N15   , Dn4
	.byte	W16
	.byte		N03   , Dn4 , v016
	.byte	W04
	.byte		        Dn4 , v112
	.byte	W04
	.byte		        Dn4 , v016
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W04
	.byte		        Dn4 , v016
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W04
	.byte		N07   , En4
	.byte	W08
	.byte		N03   , En4 , v016
	.byte	W04
	.byte		        Dn3 , v112
	.byte	W04
	.byte		        Dn3 , v016
	.byte	W08
@ 027   ----------------------------------------
	.byte		        Dn3 , v112
	.byte	W04
	.byte		        Dn3 , v016
	.byte	W04
	.byte		N01   , Ds3 , v112
	.byte	W02
	.byte		N09   , En3
	.byte	W10
	.byte		N01   , En3 , v016
	.byte	W02
	.byte		N11   , As3 , v112
	.byte	W02
	.byte	W10
	.byte		N03   , As3 , v016
	.byte	W10
	.byte		N15   , Fn3 , v112
	.byte	W16
	.byte		N11   , As3
	.byte	W12
	.byte		N07   , Fn3
	.byte	W08
	.byte		        Gn3
	.byte	W08
	.byte		        Cs3
	.byte	W08
@ 028   ----------------------------------------
	.byte		        Dn3
	.byte	W08
	.byte		        Cs3
	.byte	W08
	.byte		        Cn3
	.byte	W08
	.byte	W04
	.byte		        Dn3
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W02
	.byte		VOL   , 82*mus_berry_pick_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		N07   
	.byte	W02
	.byte		VOL   , 57*mus_berry_pick_mvl/mxv
	.byte	PRIO  , 0
	.byte	W06
	.byte		N07   
	.byte	W04
	.byte		VOL   , 43*mus_berry_pick_mvl/mxv
	.byte	PRIO  , 0
	.byte	W04
	.byte		N07   
	.byte	W08
	.byte		VOL   , 26*mus_berry_pick_mvl/mxv
	.byte	PRIO  , 0
	.byte		N07   
	.byte	W28
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
	.byte	GOTO
	 .word	mus_berry_pick_2_B1
	.byte	W06
	.byte	FINE

@**************** Track 3 ****************@

mus_berry_pick_3:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_berry_pick_key+0
	.byte		VOICE , 46
	.byte		PAN   , c_v-48
	.byte	W24
mus_berry_pick_3_B1:
	.byte		VOICE , 46
	.byte		VOL   , 89*mus_berry_pick_mvl/mxv
	.byte	W80
@ 001   ----------------------------------------
	.byte		N15   , An3 , v112
	.byte	W16
	.byte		VOL   , 87*mus_berry_pick_mvl/mxv
	.byte	PRIO  , 0
	.byte		N78   , As3
	.byte	W80
@ 002   ----------------------------------------
	.byte		N15   , An3
	.byte	W16
	.byte		N11   , As3
	.byte	W12
	.byte		N03   , As3 , v016
	.byte	W12
	.byte		N11   , Bn3 , v112
	.byte	W12
	.byte		N03   , Bn3 , v016
	.byte	W12
	.byte		N07   , Cs4 , v112
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N03   , Cs4 , v016
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W04
@ 003   ----------------------------------------
	.byte		        Bn3 , v016
	.byte	W08
	.byte		N11   , An3 , v112
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N78   , As3
	.byte	W80
@ 004   ----------------------------------------
	.byte		N15   , An3
	.byte	W16
	.byte		N11   , As3
	.byte	W12
	.byte		N03   , As3 , v016
	.byte	W12
	.byte		N11   , Bn3 , v112
	.byte	W12
	.byte		N03   , Bn3 , v016
	.byte	W12
	.byte		N07   , Cs4 , v112
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N03   , Cs4 , v016
	.byte	W04
	.byte		        Ds4 , v112
	.byte	W04
@ 005   ----------------------------------------
	.byte		        Ds4 , v016
	.byte	W08
	.byte		N11   , Dn4 , v112
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N30   , Ds4
	.byte	W32
	.byte		N11   , Fn4
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N30   , Fs4
	.byte	W32
@ 006   ----------------------------------------
	.byte		N11   , Dn4
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N11   , Ds4
	.byte	W12
	.byte		N07   , As3
	.byte	W08
	.byte		N11   , Bn3
	.byte	W16
	.byte		N07   , Ds3
	.byte	W24
	.byte		        Fs3
	.byte	W08
	.byte		N03   , Fs3 , v016
	.byte	W04
@ 007   ----------------------------------------
	.byte		N07   , Fs3 , v112
	.byte	W08
	.byte		N11   
	.byte	W12
	.byte		N03   , Gn3
	.byte	W04
	.byte		N07   , Gs3
	.byte	W08
	.byte		N11   , Fn3
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N11   
	.byte	W16
@ 008   ----------------------------------------
	.byte	W12
	.byte		N07   , Bn3
	.byte	W08
	.byte		        Cs3
	.byte	W08
	.byte		N11   , Gs3
	.byte	W20
	.byte		N07   , Cs4
	.byte	W08
	.byte		N03   , As3
	.byte	W04
	.byte		N07   , Bn3
	.byte	W08
	.byte		N11   , As3
	.byte	W12
	.byte		        An3
	.byte	W12
	.byte		N03   
	.byte	W04
@ 009   ----------------------------------------
	.byte		N07   , As3
	.byte	W08
	.byte		N11   
	.byte	W12
	.byte		N03   , As3 , v016
	.byte	W04
	.byte		N07   , As3 , v112
	.byte	W08
	.byte		N11   
	.byte	W12
	.byte		N03   , Gs3
	.byte	W04
	.byte		N07   , Fs3
	.byte	W08
	.byte		N03   , As3
	.byte	W04
	.byte		N07   , Bn3
	.byte	W08
	.byte		N15   , Cs4
	.byte	W16
	.byte		N07   
	.byte	W08
	.byte		N03   
	.byte	W04
@ 010   ----------------------------------------
	.byte		N68   , Dn4
	.byte	W72
	.byte		N03   , Dn4 , v016
	.byte	W24
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
	.byte	W56
	.byte		VOICE , 2
	.byte		N01   , Fn5 , v112
	.byte	W02
	.byte		        En5
	.byte	W02
	.byte		        Dn5
	.byte	W02
	.byte		        Cn5
	.byte	W02
	.byte		        Bn4
	.byte	W02
	.byte		        An4
	.byte	W02
	.byte		        Gn4
	.byte	W02
	.byte		        Fn4
	.byte	W02
	.byte		        En4
	.byte	W02
	.byte		        Dn4
	.byte	W02
	.byte		        Cn4
	.byte	W02
	.byte		        Bn3
	.byte	W02
	.byte		        An3
	.byte	W02
	.byte		        Gn3
	.byte	W02
	.byte		        Fn3
	.byte	W02
	.byte		        En3
	.byte	W02
	.byte		        Dn3
	.byte	W08
@ 021   ----------------------------------------
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   , Dn3
	.byte	W04
	.byte		N07   , Bn1
	.byte	W08
	.byte		N03   , Dn3
	.byte	W04
	.byte		N07   , Dn2
	.byte	W08
	.byte		N03   , Dn3
	.byte	W04
	.byte		N07   , En2
	.byte	W08
	.byte		N03   , Dn3
	.byte	W04
	.byte		N07   , Fn2
	.byte	W08
	.byte		N03   , Dn3
	.byte	W04
	.byte		N07   , En2
	.byte	W08
	.byte		N03   , Dn3
	.byte	W04
	.byte		N07   , Dn2
	.byte	W08
	.byte		N03   , Dn3
	.byte	W04
	.byte		N07   , Bn1
	.byte	W08
	.byte		N03   , Dn3
	.byte	W04
@ 022   ----------------------------------------
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   , Fn3
	.byte	W04
	.byte		N07   , Bn1
	.byte	W08
	.byte		N03   , Fn3
	.byte	W04
	.byte		N07   , Dn2
	.byte	W08
	.byte		N03   , Fn3
	.byte	W04
	.byte		N07   , En2
	.byte	W08
	.byte		N03   , Fn3
	.byte	W04
	.byte		N07   , Fn2
	.byte	W08
	.byte		N03   , Fn3
	.byte	W04
	.byte		N07   , En2
	.byte	W08
	.byte		N03   , Fn3
	.byte	W04
	.byte		N07   , Dn2
	.byte	W08
	.byte		N03   , Fn3
	.byte	W04
	.byte		N07   , Bn1
	.byte	W08
	.byte		N03   , Fn3
	.byte	W04
@ 023   ----------------------------------------
	.byte		N09   , En3
	.byte	W12
	.byte		N11   , Cn3 , v127
	.byte	W12
	.byte		N07   , En3 , v112
	.byte	W08
	.byte		N11   , Fn3
	.byte	W14
	.byte		N09   , En3
	.byte	W10
	.byte		N11   
	.byte	W12
	.byte		        Ds3
	.byte	W14
	.byte		N13   , En3
	.byte	W14
@ 024   ----------------------------------------
	.byte		N03   , En3 , v016
	.byte	W12
	.byte		N11   , Ds3 , v112
	.byte	W12
	.byte		N07   
	.byte	W08
	.byte		N15   , En3
	.byte	W16
	.byte		N01   , Dn3
	.byte	W02
	.byte		N09   , Ds3
	.byte	W10
	.byte		N09   
	.byte	W10
	.byte		        En3
	.byte	W10
	.byte		N01   , Ds3
	.byte	W02
	.byte		N13   , En3
	.byte	W14
@ 025   ----------------------------------------
	.byte		N07   , Cs3
	.byte	W08
	.byte		N11   , Dn3
	.byte	W12
	.byte		N03   , Fs3
	.byte	W04
	.byte		        Fs3 , v016
	.byte	W08
	.byte		        Dn3 , v112
	.byte	W04
	.byte		        Dn3 , v016
	.byte	W12
	.byte		N07   , Bn2 , v112
	.byte	W08
	.byte		N11   , Cn3
	.byte	W12
	.byte		N03   , En3
	.byte	W04
	.byte		        En3 , v016
	.byte	W08
	.byte		        Cn3 , v112
	.byte	W04
	.byte		        En3
	.byte	W04
	.byte		        En3 , v016
	.byte	W08
@ 026   ----------------------------------------
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v016
	.byte	W08
	.byte		        Dn3 , v112
	.byte	W04
	.byte		        Dn3 , v016
	.byte	W08
	.byte		N01   , Fn3 , v112
	.byte	W02
	.byte		N05   , Fs3
	.byte	W06
	.byte		N03   , Dn3
	.byte	W04
	.byte		        Dn3 , v016
	.byte	W08
	.byte		        Dn3 , v112
	.byte	W04
	.byte		N07   , Gn3
	.byte	W08
	.byte		N03   , Dn3
	.byte	W04
	.byte		N07   , Fs3
	.byte	W08
	.byte		N24   , Dn3
	.byte	W24
	.byte	W02
	.byte		N01   , Fn3
	.byte	W02
@ 027   ----------------------------------------
	.byte		N15   , Fs3
	.byte	W16
	.byte		N03   , Fs3 , v016
	.byte	W04
	.byte		        Fs3 , v112
	.byte	W04
	.byte		        Fs3 , v016
	.byte	W08
	.byte		        Fs3 , v112
	.byte	W04
	.byte		        Fs3 , v016
	.byte	W08
	.byte		        Fs3 , v112
	.byte	W04
	.byte		N07   , Gn3
	.byte	W08
	.byte		N03   , Gn3 , v016
	.byte	W04
	.byte		        Fs2 , v112
	.byte	W04
	.byte		        Fs2 , v016
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W04
	.byte		        Fs2 , v016
	.byte	W06
	.byte		N09   , As2 , v112
	.byte	W10
	.byte		N01   , As2 , v016
	.byte	W02
	.byte		N11   , Dn3 , v112
	.byte	W02
@ 028   ----------------------------------------
	.byte	W10
	.byte		N03   , Dn3 , v016
	.byte	W10
	.byte		N15   , Gn2 , v112
	.byte	W16
	.byte		N11   , Dn3
	.byte	W20
	.byte		N07   
	.byte	W16
	.byte		        Bn2
	.byte	W16
	.byte		        An2
	.byte	W08
@ 029   ----------------------------------------
	.byte		        Bn2
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W06
	.byte		VOL   , 82*mus_berry_pick_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		N07   
	.byte	W06
	.byte		VOL   , 57*mus_berry_pick_mvl/mxv
	.byte	PRIO  , 0
	.byte	W02
	.byte		N07   
	.byte	W08
	.byte		VOL   , 43*mus_berry_pick_mvl/mxv
	.byte	PRIO  , 0
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W04
	.byte		VOL   , 26*mus_berry_pick_mvl/mxv
	.byte	PRIO  , 0
	.byte	W28
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
	.byte	W24
	.byte	GOTO
	 .word	mus_berry_pick_3_B1
	.byte	W06
	.byte	FINE

@**************** Track 4 ****************@

mus_berry_pick_4:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_berry_pick_key+0
	.byte		VOICE , 13
	.byte		PAN   , c_v+48
	.byte	W24
mus_berry_pick_4_B1:
	.byte		VOICE , 13
	.byte		VOL   , 82*mus_berry_pick_mvl/mxv
	.byte	PRIO  , 0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		BEND  , c_v+0
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
	.byte	W84
@ 010   ----------------------------------------
	.byte		N03   , Cs4 , v112
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		        Dn4
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   , En4
	.byte	W04
	.byte		        Fn4
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        En4
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
@ 011   ----------------------------------------
	.byte		        Dn4
	.byte	W04
	.byte		        Cs4
	.byte	W04
	.byte		        Dn4
	.byte	W04
	.byte		        Bn3
	.byte	W04
	.byte		        As3
	.byte	W04
	.byte		        Bn3
	.byte	W04
	.byte		        Gn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , Bn3
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   , Gn3
	.byte	W04
	.byte		        Fs3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , Gn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , En3
	.byte	W04
@ 012   ----------------------------------------
	.byte		N07   , Dn3
	.byte	W08
	.byte		N03   , Cs3
	.byte	W04
	.byte		N07   , Cn3
	.byte	W08
	.byte		N03   , An2
	.byte	W04
	.byte		        As2
	.byte	W04
	.byte		        Bn2
	.byte	W04
	.byte		        Gn3
	.byte	W04
	.byte		N01   
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , Dn3
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   , As2
	.byte	W04
	.byte		        Bn2
	.byte	W04
	.byte		        Dn3
	.byte	W04
	.byte		        Gn3
	.byte	W04
@ 013   ----------------------------------------
	.byte		N07   , As3
	.byte	W08
	.byte		N11   , Gn3
	.byte	W12
	.byte		N03   , Dn3
	.byte	W04
	.byte		N07   , Fn3
	.byte	W08
	.byte		N11   , Gn3
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W12
	.byte		N03   , Fn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , Gn3
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W08
@ 014   ----------------------------------------
	.byte		N07   , As3
	.byte	W08
	.byte		N03   , Gn3
	.byte	W04
	.byte		N07   , An3
	.byte	W08
	.byte		N03   , Bn3
	.byte	W04
	.byte		        As3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W04
	.byte		N03   , An3
	.byte	W04
	.byte		        Gs3
	.byte	W04
	.byte		        Gn3
	.byte	W04
	.byte		N07   , As3
	.byte	W08
	.byte		N03   , Gn3
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   , As2
	.byte	W04
	.byte		        Bn2
	.byte	W04
	.byte		        Dn3
	.byte	W04
	.byte		        Gn3
	.byte	W04
@ 015   ----------------------------------------
	.byte		N07   , As3
	.byte	W08
	.byte		N15   , Cs4
	.byte	W16
	.byte		N03   , Dn4
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , Cs4
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , Dn4
	.byte	W04
	.byte		N11   , Cs4
	.byte	W12
	.byte		N03   , Cn4
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , As3
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   , Cn4
	.byte	W04
	.byte		N11   , As3
	.byte	W12
@ 016   ----------------------------------------
	.byte		N03   , Gn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , Dn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , Fn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N07   , Gn3
	.byte	W08
	.byte		N11   
	.byte		N11   , Dn4
	.byte	W12
	.byte		N03   , Cn4
	.byte	W04
	.byte		N07   , Bn3
	.byte	W08
	.byte		        As3
	.byte	W08
	.byte		N01   
	.byte	W04
	.byte		N03   , An3
	.byte	W04
	.byte		N07   , Gs3
	.byte	W08
	.byte		N03   , Gn3
	.byte	W04
	.byte		N07   , Gs3
	.byte	W08
	.byte		N11   , Fn4
	.byte	W12
@ 017   ----------------------------------------
	.byte		N15   , En4
	.byte	W16
	.byte		N03   , Cn4
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N03   , An3
	.byte	W04
	.byte		        Gs3
	.byte	W04
	.byte		        Gn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   , As3
	.byte	W04
@ 018   ----------------------------------------
	.byte		N01   
	.byte	W08
	.byte		N07   
	.byte	W16
	.byte		N15   , Gn3
	.byte	W16
	.byte		N03   , Fn3
	.byte	W04
	.byte		        Fs3
	.byte	W04
	.byte		N15   , Gn3
	.byte	W16
	.byte		N03   , Fn3
	.byte	W04
	.byte		        Fs3
	.byte	W04
	.byte		        Gn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N24   , Dn3
	.byte	W28
@ 019   ----------------------------------------
	.byte		N03   , Gn3
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W16
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
@ 020   ----------------------------------------
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte	W08
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N30   , Dn4
	.byte	W32
@ 021   ----------------------------------------
	.byte		N01   
	.byte	W08
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
	.byte	W44
	.byte		VOICE , 60
	.byte		N03   , As3
	.byte	W04
	.byte		N42   , Bn3
	.byte	W44
@ 030   ----------------------------------------
	.byte		N03   , As3
	.byte	W04
	.byte		N56   , Bn3
	.byte	W56
	.byte	W01
	.byte		N02   , As3
	.byte	W03
	.byte		        Bn3
	.byte	W03
	.byte		        As3
	.byte	W03
	.byte		        Bn3
	.byte	W03
	.byte		        As3
	.byte	W03
@ 031   ----------------------------------------
	.byte		        Bn3
	.byte	W03
	.byte		        Bn3 , v016
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v016
	.byte	W15
	.byte	W12
	.byte		N05   , Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v016
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v016
	.byte	W12
	.byte		        En3 , v112
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        En3 , v016
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
@ 032   ----------------------------------------
	.byte		        Fn3 , v016
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v016
	.byte	W12
	.byte		N11   , As3 , v112
	.byte	W12
	.byte		N05   , As3 , v016
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v016
	.byte	W12
	.byte		        En3 , v112
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        En3 , v016
	.byte	W12
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        En3
	.byte	W06
@ 033   ----------------------------------------
	.byte		        Fn3
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Fn3 , v016
	.byte	W12
	.byte	W12
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Dn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fn3
	.byte	W06
	.byte		        Fn3 , v016
	.byte	W12
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Dn3
	.byte	W06
	.byte		        En3
	.byte	W06
	.byte		        Fn3
	.byte	W06
@ 034   ----------------------------------------
	.byte		        Fn3 , v016
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v016
	.byte	W12
	.byte		        As3 , v112
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        As3 , v016
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v016
	.byte	W12
	.byte		N11   , As3 , v112
	.byte	W12
	.byte		N05   , As3 , v016
	.byte	W12
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        As3
	.byte	W06
@ 035   ----------------------------------------
	.byte		        Cs4
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Cs4 , v016
	.byte	W12
	.byte	W24
	.byte		N44   , Cn4 , v112
	.byte	W48
@ 036   ----------------------------------------
	.byte		N23   , As3
	.byte	W24
	.byte		N05   , Bn3
	.byte	W06
	.byte		N11   , Dn4
	.byte	W12
	.byte		N05   , Dn4 , v016
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W06
	.byte		N11   , Dn4
	.byte	W12
	.byte		N05   , En4
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Fn4 , v016
	.byte	W06
	.byte		N11   , En4 , v112
	.byte	W12
@ 037   ----------------------------------------
	.byte		N02   , Fn4
	.byte	W03
	.byte		        En4
	.byte	W03
	.byte		        Fn4
	.byte	W03
	.byte		        En4
	.byte	W03
	.byte		        Fn4
	.byte	W03
	.byte		        En4
	.byte	W03
	.byte	W24
	.byte		N44   , Cn4
	.byte	W48
@ 038   ----------------------------------------
	.byte		N23   , Ds4
	.byte	W24
	.byte		N03   , Dn4
	.byte	W04
	.byte		        Dn4 , v016
	.byte	W04
	.byte		        Dn4 , v112
	.byte	W04
	.byte		        Dn4 , v016
	.byte	W12
	.byte		        Dn4 , v112
	.byte	W04
	.byte		        Dn4 , v016
	.byte	W04
	.byte		        Dn4 , v112
	.byte	W04
	.byte		        Dn4 , v016
	.byte	W12
	.byte		        Dn4 , v112
	.byte	W04
	.byte		        Dn4 , v016
	.byte	W04
	.byte		        Dn4 , v112
	.byte	W04
	.byte		        Dn4 , v016
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W04
@ 039   ----------------------------------------
	.byte		N03   
	.byte	W04
	.byte		        Dn4 , v016
	.byte	W08
	.byte		N52   , Fn4 , v112
	.byte	W12
	.byte	W42
	.byte		N01   , En4
	.byte	W02
	.byte		        Dn4
	.byte	W02
	.byte		        Bn3
	.byte	W02
	.byte		N03   , Bn3 , v016
	.byte	W48
@ 040   ----------------------------------------
	.byte	GOTO
	 .word	mus_berry_pick_4_B1
	.byte	W06
	.byte	FINE

@**************** Track 5 ****************@

mus_berry_pick_5:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_berry_pick_key+0
	.byte		VOICE , 13
	.byte		PAN   , c_v+48
	.byte	W24
mus_berry_pick_5_B1:
	.byte		VOICE , 13
	.byte		VOL   , 82*mus_berry_pick_mvl/mxv
	.byte	PRIO  , 0
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		BEND  , c_v+0
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
	.byte	W84
@ 010   ----------------------------------------
	.byte		N03   , As3 , v112
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		        Bn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W12
	.byte		N03   , Dn4
	.byte	W04
	.byte		        Cs4
	.byte	W04
	.byte		        Dn4
	.byte	W04
	.byte		        Cn4
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
@ 011   ----------------------------------------
	.byte		        Bn3
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Gn3
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Bn2
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , Gn3
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W12
	.byte		N03   , Cs3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , Dn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W32
@ 012   ----------------------------------------
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W32
@ 013   ----------------------------------------
	.byte		N07   , Fn3
	.byte	W08
	.byte		N11   , Dn3
	.byte	W12
	.byte		N03   , Bn2
	.byte	W04
	.byte		N07   , Cn3
	.byte	W08
	.byte		N11   , Dn3
	.byte	W12
	.byte		N03   , Cn3
	.byte	W04
	.byte		N01   
	.byte	W12
	.byte		N03   , Dn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , En3
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   , Cn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W08
@ 014   ----------------------------------------
	.byte		N07   , Fn3
	.byte	W24
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , Gn3
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W16
	.byte		N07   , Fn3
	.byte	W08
	.byte		N03   , Dn3
	.byte	W04
	.byte		N01   
	.byte	W24
@ 015   ----------------------------------------
	.byte		N07   , Gn3
	.byte	W08
	.byte		N15   , As3
	.byte	W16
	.byte		N03   , An3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , Gs3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , An3
	.byte	W04
	.byte		N11   , Gs3
	.byte	W12
	.byte		N03   , Gn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , Fn3
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   , Gn3
	.byte	W04
	.byte		N11   , Fn3
	.byte	W12
@ 016   ----------------------------------------
	.byte		N03   , Dn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , As2
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , Dn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N07   
	.byte	W20
	.byte		N03   , Gs3
	.byte	W04
	.byte		N07   , Gn3
	.byte	W08
	.byte		        Fs3
	.byte	W08
	.byte		N01   
	.byte	W04
	.byte		N03   , Fn3
	.byte	W04
	.byte		N07   , En3
	.byte	W08
	.byte		N03   , Ds3
	.byte	W04
	.byte		N07   , En3
	.byte	W08
	.byte		N11   , Cn4
	.byte	W12
@ 017   ----------------------------------------
	.byte		N15   , Bn3
	.byte	W16
	.byte		N03   , Dn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   , Gn3
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N07   
	.byte	W16
	.byte		N03   , Cn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   , Fn3
	.byte	W04
@ 018   ----------------------------------------
	.byte		N01   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Fs3
	.byte	W04
	.byte		N15   , Dn3
	.byte	W16
	.byte		N03   , Cn3
	.byte	W04
	.byte		        Cs3
	.byte	W04
	.byte		N15   , Dn3
	.byte	W16
	.byte		N03   , Cn3
	.byte	W04
	.byte		        Cs3
	.byte	W04
	.byte		        Dn3
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N24   , An2
	.byte	W28
@ 019   ----------------------------------------
	.byte		N03   , Dn3
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		        Cs3
	.byte	W04
	.byte		        Dn3
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
@ 020   ----------------------------------------
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N03   , Cs3
	.byte	W04
	.byte		        Dn3
	.byte	W08
	.byte		        Cs3
	.byte	W04
	.byte		        Dn3
	.byte	W08
	.byte		        Cs3
	.byte	W04
	.byte		        Dn3
	.byte	W08
	.byte		        Cs3
	.byte	W04
	.byte		        Dn3
	.byte	W16
	.byte		N30   , Gn3
	.byte	W32
@ 021   ----------------------------------------
	.byte		N01   
	.byte	W08
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
	.byte	W44
	.byte		VOICE , 60
	.byte		N03   , Fs3
	.byte	W04
	.byte		N42   , Gn3
	.byte	W44
@ 030   ----------------------------------------
	.byte		N03   , Fs3
	.byte	W04
	.byte		N56   , Gn3
	.byte	W56
	.byte	W01
	.byte		N02   , Fs3
	.byte	W03
	.byte		        Gn3
	.byte	W03
	.byte		        Fs3
	.byte	W03
	.byte		        Gn3
	.byte	W03
	.byte		        Fs3
	.byte	W03
@ 031   ----------------------------------------
	.byte		        Gn3
	.byte	W03
	.byte		        Gn3 , v016
	.byte	W03
	.byte		        Gn3 , v112
	.byte	W03
	.byte		        Gn3 , v016
	.byte	W15
	.byte	W12
	.byte		N05   , Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v016
	.byte	W12
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v016
	.byte	W12
	.byte		        As2 , v112
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        As2 , v016
	.byte	W06
	.byte		        Bn2 , v112
	.byte	W06
@ 032   ----------------------------------------
	.byte		        Bn2 , v016
	.byte	W06
	.byte		        Bn2 , v112
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W12
	.byte		N11   , Fn3 , v112
	.byte	W12
	.byte		N05   , Fn3 , v016
	.byte	W06
	.byte		        Bn2 , v112
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W12
	.byte		        Cn3 , v112
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Cn3 , v016
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Cs3
	.byte	W06
@ 033   ----------------------------------------
	.byte		        Dn3
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Dn3 , v016
	.byte	W12
	.byte	W12
	.byte		        As2 , v112
	.byte	W06
	.byte		        Gn2
	.byte	W06
	.byte		        An2
	.byte	W06
	.byte		        As2
	.byte	W06
	.byte		        As2 , v016
	.byte	W12
	.byte		        As2 , v112
	.byte	W06
	.byte		        Gn2
	.byte	W06
	.byte		        An2
	.byte	W06
	.byte		        As2
	.byte	W06
@ 034   ----------------------------------------
	.byte		        As2 , v016
	.byte	W06
	.byte		        As2 , v112
	.byte	W06
	.byte		        As2 , v016
	.byte	W12
	.byte		        Fn3 , v112
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Fn3 , v016
	.byte	W06
	.byte		        As2 , v112
	.byte	W06
	.byte		        As2 , v016
	.byte	W12
	.byte		N11   , Fn3 , v112
	.byte	W12
	.byte		N05   , Fn3 , v016
	.byte	W12
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Cs3
	.byte	W06
@ 035   ----------------------------------------
	.byte		        Fn3
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Fn3 , v016
	.byte	W12
	.byte		N44   , An3 , v112
	.byte	W48
	.byte		        Gn3
	.byte	W48
@ 036   ----------------------------------------
	.byte		N05   
	.byte	W06
	.byte		N11   , Bn3
	.byte	W12
	.byte		N05   , Bn3 , v016
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		N11   , Bn3
	.byte	W18
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W06
	.byte		N11   , Gs3 , v112
	.byte	W12
@ 037   ----------------------------------------
	.byte		N02   , An3
	.byte	W03
	.byte		        Gs3
	.byte	W03
	.byte		        An3
	.byte	W03
	.byte		        Gs3
	.byte	W03
	.byte		        An3
	.byte	W03
	.byte		        Gs3
	.byte	W03
	.byte		N44   , En3
	.byte	W48
	.byte		        Gs3
	.byte	W48
@ 038   ----------------------------------------
	.byte		N03   , Bn3
	.byte	W04
	.byte		        Bn3 , v016
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Bn3 , v016
	.byte	W12
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Bn3 , v016
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Bn3 , v016
	.byte	W12
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Bn3 , v016
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Bn3 , v016
	.byte	W08
	.byte		        Bn3 , v112
	.byte	W04
@ 039   ----------------------------------------
	.byte		N03   
	.byte	W04
	.byte		        Bn3 , v016
	.byte	W08
	.byte		N52   , Bn3 , v112
	.byte	W12
	.byte	W42
	.byte		N01   , As3
	.byte	W02
	.byte		        Gn3
	.byte	W02
	.byte		        Dn3
	.byte	W02
	.byte		N03   , Dn3 , v016
	.byte	W48
@ 040   ----------------------------------------
	.byte	GOTO
	 .word	mus_berry_pick_5_B1
	.byte	W06
	.byte	FINE

@**************** Track 6 ****************@

mus_berry_pick_6:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_berry_pick_key+0
	.byte		VOICE , 88
	.byte		PAN   , c_v+0
	.byte	W24
mus_berry_pick_6_B1:
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 110*mus_berry_pick_mvl/mxv
	.byte	PRIO  , 0
	.byte		BEND  , c_v+0
	.byte		N07   , Cs1 , v112
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Cs1 , v016
	.byte	W12
	.byte		N07   , Cs1 , v112
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Cs1 , v016
	.byte	W12
	.byte		N07   , Cs2 , v112
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Cs2 , v016
	.byte	W08
	.byte		N07   , Cs2 , v112
	.byte	W08
@ 001   ----------------------------------------
	.byte		N03   , Cs2 , v016
	.byte	W20
mus_berry_pick_6_001:
	.byte		N07   , Fs1 , v112
	.byte	W08
	.byte		N03   , Fs1 , v016
	.byte	W04
	.byte		N07   , As1 , v112
	.byte	W08
	.byte		N03   , As1 , v016
	.byte	W04
	.byte		N07   , Cs2 , v112
	.byte	W08
	.byte		N03   , Cs2 , v016
	.byte	W04
	.byte		N07   , Ds2 , v112
	.byte	W08
	.byte		N03   , Ds2 , v016
	.byte	W04
	.byte		N07   , En2 , v112
	.byte	W08
	.byte		N03   , En2 , v016
	.byte	W04
	.byte		N07   , Ds2 , v112
	.byte	W08
	.byte		N03   , Ds2 , v016
	.byte	W04
@ 002   ----------------------------------------
	.byte		N07   , Cs2 , v112
	.byte	W08
	.byte		N03   , Cs2 , v016
	.byte	W04
	.byte		N07   , As1 , v112
	.byte	W08
	.byte		N03   , As1 , v016
	.byte	W04
	.byte	PEND
mus_berry_pick_6_002:
	.byte		N07   , Fs1 , v112
	.byte	W08
	.byte		N03   , Fs1 , v016
	.byte	W16
	.byte		N07   , Fs1 , v112
	.byte	W08
	.byte		N03   , Fs1 , v016
	.byte	W16
	.byte		N07   , Fs1 , v112
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Fs1 , v016
	.byte	W08
	.byte		N07   , Fs1 , v112
	.byte	W08
@ 003   ----------------------------------------
	.byte		N03   , Fs1 , v016
	.byte	W20
	.byte	PEND
	.byte	PATT
	 .word	mus_berry_pick_6_001
	.byte	PATT
	 .word	mus_berry_pick_6_002
	.byte		N07   , Bn1 , v112
	.byte	W08
	.byte		N03   , Bn1 , v016
	.byte	W04
	.byte		N07   , Fs1 , v112
	.byte	W08
	.byte		N03   , Fs1 , v016
	.byte	W04
	.byte		N07   , Ds2 , v112
	.byte	W08
	.byte		N03   , Ds2 , v016
	.byte	W04
	.byte		N07   , Fs2 , v112
	.byte	W08
	.byte		N03   , Fs2 , v016
	.byte	W04
	.byte		N07   , An2 , v112
	.byte	W08
	.byte		N03   , An2 , v016
	.byte	W04
	.byte		N07   , Fs2 , v112
	.byte	W08
	.byte		N03   , Fs2 , v016
	.byte	W04
@ 004   ----------------------------------------
	.byte		N07   , Gs2 , v112
	.byte	W08
	.byte		N03   , Gs2 , v016
	.byte	W04
	.byte		N07   , Fs2 , v112
	.byte	W08
	.byte		N03   , Fs2 , v016
	.byte	W04
	.byte		N07   , Bn1 , v112
	.byte	W08
	.byte		N03   , Bn1 , v016
	.byte	W16
	.byte		N07   , Bn1 , v112
	.byte	W08
	.byte		N03   , Bn1 , v016
	.byte	W16
	.byte		N11   , Ds2 , v112
	.byte	W12
	.byte		N07   , Bn1
	.byte	W08
	.byte		N11   , Cs2
	.byte	W12
@ 005   ----------------------------------------
	.byte		N03   , Bn1
	.byte	W04
	.byte		N11   , Ds2
	.byte	W12
	.byte		N07   , Cs2
	.byte	W08
	.byte		N03   , Cs2 , v016
	.byte	W04
	.byte		N07   , Gs1 , v112
	.byte	W08
	.byte		N03   , Gs1 , v016
	.byte	W04
	.byte		N07   , Fn2 , v112
	.byte	W08
	.byte		N03   , Fn2 , v016
	.byte	W04
	.byte		N07   , Gs2 , v112
	.byte	W08
	.byte		N03   , Gs2 , v016
	.byte	W04
	.byte		N07   , Bn2 , v112
	.byte	W08
	.byte		N03   , Bn2 , v016
	.byte	W04
	.byte		N07   , Gs2 , v112
	.byte	W08
	.byte		N03   , Gs2 , v016
	.byte	W04
@ 006   ----------------------------------------
	.byte		N07   , As2 , v112
	.byte	W08
	.byte		N03   , As2 , v016
	.byte	W04
	.byte		N07   , Gs2 , v112
	.byte	W08
	.byte		N03   , Gs2 , v016
	.byte	W04
	.byte		N07   , Cs2 , v112
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Cs2 , v016
	.byte	W12
	.byte		N07   , Cs2 , v112
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Cs2 , v016
	.byte	W08
	.byte		        Ds2 , v112
	.byte	W04
	.byte		N07   , En2
	.byte	W08
	.byte		N03   , Cs2
	.byte	W04
	.byte		N07   , Ds2
	.byte	W08
	.byte		        Cs2
	.byte	W08
@ 007   ----------------------------------------
	.byte		N03   , Cs2 , v016
	.byte	W20
	.byte		N07   , Fs1 , v112
	.byte	W08
	.byte		N03   , Fs1 , v016
	.byte	W04
	.byte		N07   , As1 , v112
	.byte	W08
	.byte		N03   , As1 , v016
	.byte	W04
	.byte		N07   , Bn1 , v112
	.byte	W08
	.byte		N03   , Cn2
	.byte	W04
	.byte		        Cn2 , v016
	.byte	W08
	.byte		N07   , Cs2 , v112
	.byte	W08
	.byte		N03   , Cs2 , v016
	.byte	W04
	.byte		        Cs2 , v112
	.byte	W04
	.byte		N07   , Bn1
	.byte	W08
	.byte		N03   , Bn1 , v016
	.byte	W04
@ 008   ----------------------------------------
	.byte		N07   , As1 , v112
	.byte	W08
	.byte		N03   , As1 , v016
	.byte	W04
	.byte		N07   , Gs1 , v112
	.byte	W08
	.byte		N03   , Gs1 , v016
	.byte	W04
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		N07   , Bn1 , v112
	.byte	W08
	.byte		N03   , Bn1 , v016
	.byte	W04
	.byte		N07   , Cn2 , v112
	.byte	W08
	.byte		N03   , Cs2
	.byte	W04
	.byte		        Cs2 , v016
	.byte	W08
	.byte		N07   , Dn2 , v112
	.byte	W08
	.byte		N03   , Dn2 , v016
	.byte	W04
	.byte		        Dn2 , v112
	.byte	W04
	.byte		N07   , Cn2
	.byte	W08
	.byte		N03   , Cn2 , v016
	.byte	W04
@ 009   ----------------------------------------
	.byte		N07   , Bn1 , v112
	.byte	W08
	.byte		N03   , Bn1 , v016
	.byte	W04
	.byte		N07   , An1 , v112
	.byte	W08
	.byte		N03   , An1 , v016
	.byte	W04
mus_berry_pick_6_009:
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		N07   , Dn1 , v112
	.byte	W08
	.byte		N03   , Dn1 , v016
	.byte	W04
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W12
	.byte		        Gn1 , v112
	.byte	W04
	.byte		        Gn1 , v016
	.byte	W08
	.byte		        Gn1 , v112
	.byte	W04
	.byte		N07   , Dn1
	.byte	W08
	.byte		N03   , Dn1 , v016
	.byte	W04
@ 010   ----------------------------------------
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W16
	.byte	PEND
	.byte	PATT
	 .word	mus_berry_pick_6_009
	.byte		N07   , Cn2 , v112
	.byte	W08
	.byte		N03   , Cn2 , v016
	.byte	W04
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		N07   , Cn2 , v112
	.byte	W08
	.byte		N03   , Cn2 , v016
	.byte	W12
	.byte		        Cn2 , v112
	.byte	W04
	.byte		        Cn2 , v016
	.byte	W08
	.byte		        Cn2 , v112
	.byte	W04
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
@ 011   ----------------------------------------
	.byte		N07   , Cn2 , v112
	.byte	W08
	.byte		N03   , Cn2 , v016
	.byte	W16
	.byte	PATT
	 .word	mus_berry_pick_6_009
	.byte		N07   , Dn1 , v112
	.byte	W08
	.byte		N03   , An1
	.byte	W04
	.byte		        An1 , v016
	.byte	W08
	.byte		N07   , Dn2 , v112
	.byte	W08
	.byte		N03   , Dn2 , v016
	.byte	W04
	.byte		        Fs1 , v112
	.byte	W04
	.byte		N07   , An1
	.byte	W08
	.byte		N03   , An1 , v016
	.byte	W04
	.byte		N07   , Cn1 , v112
	.byte	W08
	.byte		N03   , Gn1
	.byte	W04
	.byte		        Gn1 , v016
	.byte	W08
	.byte		N07   , Cn2 , v112
	.byte	W08
@ 012   ----------------------------------------
	.byte		N03   , Cn2 , v016
	.byte	W04
	.byte		        En1 , v112
	.byte	W04
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		N07   , Dn1 , v112
	.byte	W08
	.byte		        Gn1
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		        Gn1 , v112
	.byte	W04
	.byte		N07   , Dn2
	.byte	W08
	.byte		N03   , Dn2 , v016
	.byte	W04
	.byte		N07   , Gs1 , v112
	.byte	W08
	.byte		N03   , Gs1 , v016
	.byte	W04
	.byte		N07   , En1 , v112
	.byte	W08
	.byte		        Gs1
	.byte	W08
@ 013   ----------------------------------------
	.byte		N03   , Gs1 , v016
	.byte	W04
	.byte		        Bn1 , v112
	.byte	W04
	.byte		N07   , En2
	.byte	W08
	.byte		N03   , En2 , v016
	.byte	W04
	.byte		N07   , Dn1 , v112
	.byte	W08
	.byte		N03   , An1
	.byte	W04
	.byte		        An1 , v016
	.byte	W08
	.byte		N07   , Dn2 , v112
	.byte	W08
	.byte		N03   , Dn2 , v016
	.byte	W04
	.byte		        Fs1 , v112
	.byte	W04
	.byte		N07   , An1
	.byte	W08
	.byte		N03   , An1 , v016
	.byte	W04
	.byte		N07   , Cn1 , v112
	.byte	W08
	.byte		N03   , Gn1
	.byte	W04
	.byte		        Gn1 , v016
	.byte	W08
	.byte		N07   , Cn2 , v112
	.byte	W08
@ 014   ----------------------------------------
	.byte		N03   , Cn2 , v016
	.byte	W04
	.byte		        En1 , v112
	.byte	W04
	.byte		N07   , As1
	.byte	W08
	.byte		N03   , As1 , v016
	.byte	W04
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		N07   , Dn1 , v112
	.byte	W08
	.byte		        Gn1
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		        Gn1 , v112
	.byte	W04
	.byte		N07   , Dn2
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Dn2 , v016
	.byte	W08
	.byte		N07   , Dn2 , v112
	.byte	W08
	.byte		N03   , Dn2 , v016
	.byte	W04
	.byte		        Dn2 , v112
	.byte	W04
@ 015   ----------------------------------------
	.byte		N07   
	.byte	W08
	.byte		N03   , Dn2 , v016
	.byte	W04
	.byte		N07   , Dn2 , v112
	.byte	W08
	.byte		N03   , Dn2 , v016
	.byte	W04
	.byte	W96
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
mus_berry_pick_6_017:
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N07   , Bn1
	.byte	W08
	.byte		N03   , Gn1
	.byte	W04
	.byte		N07   , Dn2
	.byte	W08
	.byte		N03   , Gn1
	.byte	W04
	.byte		N07   , En2
	.byte	W08
	.byte		N03   , Gn1
	.byte	W04
	.byte		N07   , Fn2
	.byte	W08
	.byte		N03   , Gn1
	.byte	W04
	.byte		N07   , En2
	.byte	W08
	.byte		N03   , Gn1
	.byte	W04
@ 018   ----------------------------------------
	.byte		N07   , Dn2
	.byte	W08
	.byte		N03   , Gn1
	.byte	W04
	.byte		        As1
	.byte	W04
	.byte		        Bn1
	.byte	W04
	.byte		        Dn1
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_berry_pick_6_017
mus_berry_pick_6_018:
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
	.byte		N07   , En1
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
	.byte		N07   , Cn2
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
	.byte		N07   , As1
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
	.byte		N07   , En1
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
@ 019   ----------------------------------------
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
	.byte		        As1
	.byte	W04
	.byte		        Cn2
	.byte	W04
	.byte		        Cn1
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_berry_pick_6_018
	.byte		N07   , An1 , v112
	.byte	W08
	.byte		N03   , Dn1
	.byte	W04
	.byte		        Dn1 , v016
	.byte	W08
	.byte		        Dn2 , v112
	.byte	W04
	.byte		        Dn2 , v016
	.byte	W08
	.byte		        Dn2 , v112
	.byte	W04
	.byte		N07   , Dn1
	.byte	W08
	.byte		N03   , Dn2
	.byte	W04
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
	.byte		        Cn1 , v016
	.byte	W08
	.byte		        Cn2 , v112
	.byte	W04
@ 020   ----------------------------------------
	.byte		        Cn2 , v016
	.byte	W08
	.byte		        Cn2 , v112
	.byte	W04
	.byte		N07   , Cn1
	.byte	W08
	.byte		N03   , Cn2
	.byte	W04
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		N07   , As1 , v112
	.byte	W08
	.byte		N03   , Dn2
	.byte	W04
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   , Dn2
	.byte	W04
	.byte		N07   , En2
	.byte	W08
	.byte		N03   , Fn2
	.byte	W04
	.byte		        Gn1
	.byte	W04
	.byte		        Gn1 , v016
	.byte	W04
	.byte		        Fn2 , v112
	.byte	W04
	.byte		N07   , En2
	.byte	W08
	.byte		N03   , Gn1
	.byte	W04
@ 021   ----------------------------------------
	.byte		N07   , Dn2
	.byte	W08
	.byte		N03   , Gn1
	.byte	W04
	.byte		        As1
	.byte	W04
	.byte		        Bn1
	.byte	W04
	.byte		        Gn1
	.byte	W04
	.byte		N07   , Dn1
	.byte	W08
	.byte		N03   , An1
	.byte	W04
	.byte		        An1 , v016
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W04
	.byte		        Dn1 , v016
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W04
	.byte		N07   , Dn2
	.byte	W08
	.byte		N03   , Dn1
	.byte	W04
	.byte		N07   , Cn1
	.byte	W08
	.byte		N03   , Gn1
	.byte	W04
	.byte		        Gn1 , v016
	.byte	W08
	.byte		        Cn1 , v112
	.byte	W04
@ 022   ----------------------------------------
	.byte		        Cn1 , v016
	.byte	W08
	.byte		        Cn1 , v112
	.byte	W04
	.byte		N07   , Cn2
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		N07   , As1 , v112
	.byte	W08
	.byte		N03   , Dn2
	.byte	W04
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   , Dn2
	.byte	W04
	.byte		N07   , En2
	.byte	W08
	.byte		N03   , Fn2
	.byte	W04
	.byte		        Gn1
	.byte	W04
	.byte		        Gn1 , v016
	.byte	W04
	.byte		        Fn2 , v112
	.byte	W04
	.byte		N07   , En2
	.byte	W08
	.byte		N03   , Gn1
	.byte	W04
@ 023   ----------------------------------------
	.byte		N07   , Dn2
	.byte	W08
	.byte		N03   , Gn1
	.byte	W04
	.byte		        As1
	.byte	W04
	.byte		        Bn1
	.byte	W04
	.byte		        Dn1
	.byte	W04
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Gn1 , v016
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W04
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Gn1 , v016
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W04
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Gn1 , v016
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W04
@ 024   ----------------------------------------
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Gn1 , v016
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W04
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Gn1 , v016
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W04
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Gn1 , v016
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W04
	.byte		N07   , Gn1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N07   , Bn1
	.byte	W08
	.byte		N03   , Gn1
	.byte	W04
@ 025   ----------------------------------------
	.byte		N07   , Dn2
	.byte	W08
	.byte		N03   , Gn1
	.byte	W04
	.byte		        Bn1 , v127
	.byte	W04
	.byte		        Dn1 , v112
	.byte	W04
	.byte		        Fn1
	.byte	W04
	.byte		N07   , Gn0
	.byte	W08
	.byte		N03   , Gn0 , v016
	.byte	W04
	.byte		N07   , Bn0 , v112
	.byte	W08
	.byte		N03   , Bn0 , v016
	.byte	W04
	.byte		N07   , Dn1 , v112
	.byte	W08
	.byte		N03   , Dn1 , v016
	.byte	W04
	.byte		N07   , En1 , v112
	.byte	W08
	.byte		N03   , En1 , v016
	.byte	W04
	.byte		N07   , Fn1 , v112
	.byte	W08
	.byte		N03   , Fn1 , v016
	.byte	W04
	.byte		N07   , En1 , v112
	.byte	W08
	.byte		N03   , En1 , v016
	.byte	W04
@ 026   ----------------------------------------
	.byte		N07   , Dn1 , v112
	.byte	W08
	.byte		N03   , Dn1 , v016
	.byte	W04
	.byte		N07   , Bn0 , v112
	.byte	W08
	.byte		N03   , Bn0 , v016
	.byte	W04
	.byte		N07   , Gn0 , v112
	.byte	W08
	.byte		N03   , Gn0 , v016
	.byte	W04
	.byte		N07   , Bn0 , v112
	.byte	W08
	.byte		N03   , Bn0 , v016
	.byte	W04
	.byte		N07   , Dn1 , v112
	.byte	W08
	.byte		N03   , Dn1 , v016
	.byte	W04
	.byte		N07   , En1 , v112
	.byte	W08
	.byte		N03   , En1 , v016
	.byte	W04
	.byte		N07   , Fn1 , v112
	.byte	W08
	.byte		N03   , Fn1 , v016
	.byte	W04
	.byte		N07   , Fs1 , v112
	.byte	W08
	.byte		N03   , Fs1 , v016
	.byte	W04
@ 027   ----------------------------------------
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		N07   , Bn0 , v112
	.byte	W08
	.byte		N03   , Bn0 , v016
	.byte	W04
	.byte		N07   , Cn1 , v112
	.byte	W08
	.byte		N03   , Cn1 , v016
	.byte	W04
	.byte		N07   , En1 , v112
	.byte	W08
	.byte		N03   , En1 , v016
	.byte	W04
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		N07   , An1 , v112
	.byte	W08
	.byte		N03   , An1 , v016
	.byte	W04
	.byte		N07   , As1 , v112
	.byte	W08
	.byte		N03   , As1 , v016
	.byte	W04
	.byte		N07   , An1 , v112
	.byte	W08
	.byte		N03   , An1 , v016
	.byte	W04
@ 028   ----------------------------------------
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		N07   , As0 , v112
	.byte	W08
	.byte		N03   , As0 , v016
	.byte	W04
	.byte		N07   , Gn0 , v112
	.byte	W08
	.byte		N03   , Gn0 , v016
	.byte	W04
	.byte		N07   , Bn0 , v112
	.byte	W08
	.byte		N03   , Bn0 , v016
	.byte	W04
	.byte		N07   , Dn1 , v112
	.byte	W08
	.byte		N03   , Dn1 , v016
	.byte	W04
	.byte		N07   , En1 , v112
	.byte	W08
	.byte		N03   , En1 , v016
	.byte	W04
	.byte		N07   , Fn1 , v112
	.byte	W08
	.byte		N03   , Fn1 , v016
	.byte	W04
	.byte		N07   , Fs1 , v112
	.byte	W08
	.byte		N03   , Fs1 , v016
	.byte	W04
@ 029   ----------------------------------------
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		N07   , As0 , v112
	.byte	W08
	.byte		N03   , As0 , v016
	.byte	W04
	.byte		N07   , Dn1 , v112
	.byte	W08
	.byte		N03   , Dn1 , v016
	.byte	W04
	.byte		N07   , An1 , v112
	.byte	W08
	.byte		N03   , An1 , v016
	.byte	W04
	.byte		N07   , Cn2 , v112
	.byte	W08
	.byte		N03   , Cn2 , v016
	.byte	W04
	.byte		N07   , An1 , v112
	.byte	W08
	.byte		N03   , An1 , v016
	.byte	W04
	.byte		N07   , Cn1 , v112
	.byte	W08
	.byte		N03   , Cn1 , v016
	.byte	W04
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
@ 030   ----------------------------------------
	.byte		N07   , Cn2 , v112
	.byte	W08
	.byte		N03   , Cn2 , v016
	.byte	W04
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		N07   , Gn0 , v112
	.byte	W08
	.byte		N03   , Gn0 , v016
	.byte	W04
	.byte		N07   , Dn1 , v112
	.byte	W08
	.byte		N03   , Dn1 , v016
	.byte	W04
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   , Gn1 , v016
	.byte	W04
	.byte		N07   , Bn1 , v112
	.byte	W08
	.byte		N03   , Bn1 , v016
	.byte	W04
	.byte		N07   , Gs0 , v112
	.byte	W08
	.byte		N03   , Gs0 , v016
	.byte	W04
	.byte		N07   , En1 , v112
	.byte	W08
	.byte		N03   , En1 , v016
	.byte	W04
@ 031   ----------------------------------------
	.byte		N07   , Bn1 , v112
	.byte	W08
	.byte		N03   , Bn1 , v016
	.byte	W04
	.byte		N07   , Fn2 , v112
	.byte	W08
	.byte		N03   , Fn2 , v016
	.byte	W04
	.byte		N07   , An0 , v112
	.byte	W08
	.byte		N03   , An0 , v016
	.byte	W04
	.byte		N07   , En1 , v112
	.byte	W08
	.byte		N03   , En1 , v016
	.byte	W04
	.byte		N07   , Cn2 , v112
	.byte	W08
	.byte		N03   , Cn2 , v016
	.byte	W04
	.byte		N07   , An1 , v112
	.byte	W08
	.byte		N03   , An1 , v016
	.byte	W04
	.byte		N07   , Gs0 , v112
	.byte	W08
	.byte		N03   , Gs0 , v016
	.byte	W04
	.byte		N07   , Ds1 , v112
	.byte	W08
	.byte		N03   , Ds1 , v016
	.byte	W04
@ 032   ----------------------------------------
	.byte		N07   , Gs1 , v112
	.byte	W08
	.byte		N03   , Gs1 , v016
	.byte	W04
	.byte		N07   , Cn2 , v112
	.byte	W08
	.byte		N03   , Cn2 , v016
	.byte	W04
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Gn1 , v016
	.byte	W12
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Gn1 , v016
	.byte	W12
	.byte		N07   , Gn1 , v112
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		        Gn1 , v016
	.byte	W08
	.byte		N07   , Gn1 , v112
	.byte	W08
@ 033   ----------------------------------------
	.byte		N03   , Gn1 , v016
	.byte	W08
	.byte		N72   , Gn0 , v112
	.byte	W12
	.byte	W60
	.byte	W36
@ 034   ----------------------------------------
	.byte	GOTO
	 .word	mus_berry_pick_6_B1
	.byte	W06
	.byte	FINE

@**************** Track 7 ****************@

mus_berry_pick_7:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_berry_pick_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte	W24
mus_berry_pick_7_B1:
	.byte	MEMACC, mem_set, 0x00, 0
	.byte		VOL   , 110*mus_berry_pick_mvl/mxv
	.byte	PRIO  , 0
	.byte		N23   , Ds1 , v112
	.byte	W12
	.byte		N11   , Cn1
	.byte	W12
	.byte		N23   , Ds1
	.byte	W12
	.byte		N11   , Cn1
	.byte	W12
	.byte		        Ds1
	.byte	W12
	.byte		N11   
	.byte	W12
@ 001   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		        Cn1
	.byte		N11   , Ds1
	.byte	W12
mus_berry_pick_7_001:
	.byte		N11   , Cn1 , v112
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Dn1
	.byte	W12
@ 002   ----------------------------------------
	.byte		        Cn1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte	PEND
mus_berry_pick_7_002:
	.byte		N11   , Cn1 , v112
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		N07   , Dn1
	.byte	W08
	.byte		N11   , Cn1
	.byte	W12
@ 003   ----------------------------------------
	.byte		N03   
	.byte	W04
	.byte		N11   , Dn1
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_berry_pick_7_001
	.byte	PATT
	 .word	mus_berry_pick_7_002
	.byte	PATT
	 .word	mus_berry_pick_7_001
mus_berry_pick_7_003:
	.byte		N11   , Cn1 , v112
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		N07   , Dn1
	.byte	W08
	.byte		N11   , Cn1
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N11   , Dn1
	.byte	W12
@ 004   ----------------------------------------
	.byte		        Cn1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte	PEND
	.byte		        Cn1
	.byte	W12
	.byte		N07   , Dn1
	.byte	W08
	.byte		N11   , Cn1
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N11   , Dn1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        Dn1
	.byte	W12
@ 005   ----------------------------------------
	.byte		        Cn1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte	PATT
	 .word	mus_berry_pick_7_003
	.byte		N11   , Cn1 , v112
	.byte	W12
	.byte		N07   , Dn1
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
	.byte		N11   
	.byte	W12
	.byte		N07   , Dn1
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
	.byte		N11   
	.byte	W12
	.byte		N07   , Dn1
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
@ 006   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		N07   , Dn1
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
	.byte		N11   
	.byte		N11   , Ds1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Cn1
	.byte		N11   , Ds1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Cn1
	.byte		N11   , Ds1
	.byte	W12
	.byte		N11   
	.byte		N11   , En1
	.byte	W12
@ 007   ----------------------------------------
	.byte		        Cn1
	.byte		N11   , Ds1
	.byte	W12
	.byte		N11   
	.byte		N11   , En1
	.byte	W12
mus_berry_pick_7_007:
	.byte		N11   , Cn1 , v112
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		N07   , En1
	.byte	W08
	.byte		N11   , Cn1
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N11   , En1
	.byte	W12
@ 008   ----------------------------------------
	.byte		        Cn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte	PEND
mus_berry_pick_7_008:
	.byte		N11   , Cn1 , v112
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		N07   , En1
	.byte	W08
	.byte		N11   , Cn1
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N11   , En1
	.byte	W12
@ 009   ----------------------------------------
	.byte		        Cn1
	.byte	W12
	.byte		N07   , En1
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_berry_pick_7_007
	.byte	PATT
	 .word	mus_berry_pick_7_008
	.byte	PATT
	 .word	mus_berry_pick_7_007
	.byte	PATT
	 .word	mus_berry_pick_7_008
	.byte	PATT
	 .word	mus_berry_pick_7_007
	.byte	PATT
	 .word	mus_berry_pick_7_008
	.byte		N11   , Cn1 , v112
	.byte		N11   , En1
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		N07   , En1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N11   , Cn1
	.byte	W08
	.byte		        En1
	.byte	W12
	.byte		N03   
	.byte	W04
@ 010   ----------------------------------------
	.byte		N11   , Cn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Cn1
	.byte		N11   , Ds1
	.byte	W12
	.byte		N07   , Dn1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N11   , Cn1
	.byte		N11   , Ds1
	.byte	W12
	.byte		        Dn1
	.byte	W12
	.byte		        Cn1
	.byte		N07   , Dn1
	.byte		N11   , Ds1
	.byte	W08
	.byte		N03   , Dn1
	.byte	W04
	.byte		N11   , Ds1
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
@ 011   ----------------------------------------
	.byte		N11   
	.byte		N07   , Dn1
	.byte		N11   , Ds1
	.byte	W08
	.byte		N03   , Dn1
	.byte	W04
	.byte		N11   , Ds1
	.byte	W08
	.byte		N03   , Cn1
	.byte	W04
mus_berry_pick_7_011:
	.byte		N07   , Cn1 , v112
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N07   , Dn1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N07   , Cn1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N11   , Dn1
	.byte	W12
	.byte		N07   , Cn1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N11   , Dn1
	.byte	W12
@ 012   ----------------------------------------
	.byte		N07   , Cn1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N07   , Dn1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_berry_pick_7_011
	.byte	PATT
	 .word	mus_berry_pick_7_011
	.byte	PATT
	 .word	mus_berry_pick_7_011
	.byte	PATT
	 .word	mus_berry_pick_7_011
	.byte	PATT
	 .word	mus_berry_pick_7_011
	.byte	PATT
	 .word	mus_berry_pick_7_011
	.byte	PATT
	 .word	mus_berry_pick_7_011
	.byte	PATT
	 .word	mus_berry_pick_7_011
	.byte		N11   , Cn1 , v112
	.byte		N11   , Ds1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Cn1
	.byte		N11   , Ds1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Cn1
	.byte		N11   , Ds1
	.byte	W12
	.byte		N11   
	.byte		N11   , En1
	.byte	W12
@ 013   ----------------------------------------
	.byte		        Cn1
	.byte		N11   , Ds1
	.byte	W12
	.byte		        Ds1 , v127
	.byte		N11   , En1
	.byte	W12
mus_berry_pick_7_013:
	.byte		N11   , Cn1 , v112
	.byte	W12
	.byte		N05   , En1
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   , Cn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        En1
	.byte	W12
@ 014   ----------------------------------------
	.byte		        Cn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte	PEND
mus_berry_pick_7_014:
	.byte		N11   , Cn1 , v112
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        En1
	.byte	W12
@ 015   ----------------------------------------
	.byte		        Cn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_berry_pick_7_013
	.byte		N11   , Cn1 , v112
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		N05   , En1
	.byte	W06
	.byte		N05   
	.byte	W06
@ 016   ----------------------------------------
	.byte		N11   , Cn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte	PATT
	 .word	mus_berry_pick_7_014
	.byte		N11   , Cn1 , v112
	.byte	W12
	.byte		N05   , En1
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   , Cn1
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte		        Cn1
	.byte	W12
	.byte		N05   , En1
	.byte	W06
	.byte		        Cn1
	.byte	W06
@ 017   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		        En1
	.byte	W12
	.byte	PATT
	 .word	mus_berry_pick_7_014
	.byte		N11   , Cn1 , v112
	.byte		N07   , En1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N11   , Cn1
	.byte	W12
	.byte		N11   
	.byte		N07   , En1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N11   , Cn1
	.byte	W12
	.byte		N11   
	.byte		N07   , En1
	.byte	W08
	.byte		N03   
	.byte	W04
	.byte		N11   , Cn1
	.byte	W12
@ 018   ----------------------------------------
	.byte		N11   
	.byte		N07   , En1
	.byte	W12
	.byte		N11   , Cn1
	.byte	W12
	.byte	W96
@ 019   ----------------------------------------
	.byte	GOTO
	 .word	mus_berry_pick_7_B1
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

mus_berry_pick:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_berry_pick_pri	@ Priority
	.byte	mus_berry_pick_rev	@ Reverb.

	.word	mus_berry_pick_grp

	.word	mus_berry_pick_1
	.word	mus_berry_pick_2
	.word	mus_berry_pick_3
	.word	mus_berry_pick_4
	.word	mus_berry_pick_5
	.word	mus_berry_pick_6
	.word	mus_berry_pick_7

	.end
