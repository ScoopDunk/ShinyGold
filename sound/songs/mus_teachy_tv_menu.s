	.include "MPlayDef.s"

	.equ	mus_teachy_tv_menu_grp, voicegroup186
	.equ	mus_teachy_tv_menu_pri, 0
	.equ	mus_teachy_tv_menu_rev, reverb_set+50
	.equ	mus_teachy_tv_menu_mvl, 59
	.equ	mus_teachy_tv_menu_key, 0
	.equ	mus_teachy_tv_menu_tbs, 1
	.equ	mus_teachy_tv_menu_exg, 1
	.equ	mus_teachy_tv_menu_cmp, 1

	.section .rodata
	.global	mus_teachy_tv_menu
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

mus_teachy_tv_menu_1:
@ ShinyGold: the hack enlarged the mus_slow_pallet header (which sits directly before this
@ song's track data in vanilla FireRed) from 6 to 10 tracks in place, so its 4 extra track
@ pointers (0x08A0577C, 0x08A05B16, 0x08A05E41, 0x08A061AE) overwrote the first 16 bytes of this
@ track.  Ported byte-for-byte so the game behaves exactly like the hack: the first byte (0x7C)
@ is a running-status byte with no running status, which the m4a engine executes as an endless
@ wait, so track 1 (the bass line, and the TEMPO command -> the song runs at the default 150 BPM
@ instead of 144) never plays.  This is a hack bug; to restore the intended track replace the
@ bytes up to the `.byte W12` below with the original commands:
@	.byte	KEYSH , mus_teachy_tv_menu_key+0
@	.byte	TEMPO , 144*mus_teachy_tv_menu_tbs/2
@	.byte		VOICE , 1
@	.byte		LFOS  , 44
@	.byte		BENDR , 12
@	.byte		VOL   , 127*mus_teachy_tv_menu_mvl/mxv
@	.byte	W24
@ mus_teachy_tv_menu_1_B1:
@ mus_teachy_tv_menu_1_001:
@	.byte		N06   , Cn2 , v088
	.byte	0x7C, 0x57, 0xA0, 0x08, 0x16, 0x5B, 0xA0, 0x08, 0x41, 0x5E, 0xA0, 0x08, 0xAE
mus_teachy_tv_menu_1_B1:
@ 001   ----------------------------------------
mus_teachy_tv_menu_1_001:
	.byte	0x61, 0xA0, 0x08
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
	.byte	PATT
	 .word	mus_teachy_tv_menu_1_001
	.byte	GOTO
	 .word	mus_teachy_tv_menu_1_B1
mus_teachy_tv_menu_1_B2:
@ 003   ----------------------------------------
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

mus_teachy_tv_menu_2:
	.byte	KEYSH , mus_teachy_tv_menu_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 97*mus_teachy_tv_menu_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W24
mus_teachy_tv_menu_2_B1:
@ 001   ----------------------------------------
mus_teachy_tv_menu_2_001:
	.byte	W12
	.byte		N06   , En3 , v088
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
	.byte	PATT
	 .word	mus_teachy_tv_menu_2_001
	.byte	GOTO
	 .word	mus_teachy_tv_menu_2_B1
mus_teachy_tv_menu_2_B2:
@ 003   ----------------------------------------
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

mus_teachy_tv_menu_3:
	.byte	KEYSH , mus_teachy_tv_menu_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 97*mus_teachy_tv_menu_mvl/mxv
	.byte		BEND  , c_v+2
	.byte	W24
mus_teachy_tv_menu_3_B1:
@ 001   ----------------------------------------
mus_teachy_tv_menu_3_001:
	.byte		N06   , Cn2 , v048
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
	.byte	PATT
	 .word	mus_teachy_tv_menu_3_001
	.byte	GOTO
	 .word	mus_teachy_tv_menu_3_B1
mus_teachy_tv_menu_3_B2:
@ 003   ----------------------------------------
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

mus_teachy_tv_menu_4:
	.byte	KEYSH , mus_teachy_tv_menu_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 74*mus_teachy_tv_menu_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Cn4 , v120
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   , Cn5 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , Gn4 
	.byte	W12
mus_teachy_tv_menu_4_B1:
@ 001   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		TIE   , Cn4 , v064
	.byte	W24
	.byte		BEND  , c_v+9
	.byte	W09
	.byte		        c_v-10
	.byte	W09
	.byte		        c_v+0
	.byte	W54
@ 002   ----------------------------------------
	.byte		        c_v+9
	.byte	W24
	.byte		        c_v-8
	.byte	W24
	.byte		        c_v+0
	.byte	W48
	.byte		EOT   
	.byte	GOTO
	 .word	mus_teachy_tv_menu_4_B1
mus_teachy_tv_menu_4_B2:
@ 003   ----------------------------------------
	.byte	FINE

@******************************************************@
	.align	2

mus_teachy_tv_menu:
	.byte	4	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_teachy_tv_menu_pri	@ Priority
	.byte	mus_teachy_tv_menu_rev	@ Reverb.

	.word	mus_teachy_tv_menu_grp

	.word	mus_teachy_tv_menu_1
	.word	mus_teachy_tv_menu_2
	.word	mus_teachy_tv_menu_3
	.word	mus_teachy_tv_menu_4

	.end
