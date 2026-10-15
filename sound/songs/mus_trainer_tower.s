	.include "MPlayDef.s"

@ ShinyGold: Now a battle theme (not identified: no melodic match in GSC or FRLG music).
@ Used through the hack's music-swap scripts in place of MUS_VS_TRAINER for a set of
@ 'PKMN TRAINER' battles; also the map music of a Lighthouse interior.
@
@ The hack edited this song header in place (keeping the song ID) to point at new track data
@ it inserted at 0x08A063B0; voicegroup changed from voicegroup134 to voicegroup011, 7 -> 10 tracks.
@ Disassembled from the hack ROM (no MIDI source exists).  Labels replace the hack's
@ absolute pointers; the byte stream of every track is identical to the hack's.
@ `_mvl` is 127, so `VOL , N*_mvl/mxv` emits N unchanged (edit _mvl to rescale volumes).

	.equ	mus_trainer_tower_grp, voicegroup011
	.equ	mus_trainer_tower_pri, 0
	.equ	mus_trainer_tower_rev, reverb_set+50
	.equ	mus_trainer_tower_mvl, 127
	.equ	mus_trainer_tower_key, 0
	.equ	mus_trainer_tower_tbs, 1
	.equ	mus_trainer_tower_exg, 0
	.equ	mus_trainer_tower_cmp, 1

	.section .rodata
	.global	mus_trainer_tower
	.align	2

@**************** Track 1 ****************@

mus_trainer_tower_1:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_trainer_tower_key+0
	.byte	TEMPO , 180*mus_trainer_tower_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 114*mus_trainer_tower_mvl/mxv
	.byte		TIE   , Dn2 , v127
	.byte		TIE   , Gn2
	.byte		TIE   , Dn3
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte		EOT   , Dn2
	.byte		        Gn2
	.byte		        Dn3
	.byte		TIE   , Ds2
	.byte		TIE   , Gs2
	.byte		TIE   , Ds3
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte		EOT   , Ds2
	.byte		        Gs2
	.byte		        Ds3
	.byte		TIE   , Cn2
	.byte		TIE   , Fn2
	.byte		TIE   , Cn3
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte		EOT   , Cn2
	.byte		        Fn2
	.byte		        Cn3
	.byte		TIE   , En2
	.byte		TIE   , Cn3
	.byte	W96
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte		EOT   , En2
	.byte		        Cn3
	.byte	W96
@ 009   ----------------------------------------
	.byte	W92
	.byte	W01
	.byte	W03
@ 010   ----------------------------------------
mus_trainer_tower_1_B1:
	.byte		N96   , Gn3
	.byte	W96
@ 011   ----------------------------------------
mus_trainer_tower_1_011:
	.byte		N84   , Cn4 , v127
	.byte	W84
	.byte		N12   , Gn4
	.byte	W12
	.byte	PEND
@ 012   ----------------------------------------
mus_trainer_tower_1_012:
	.byte		N16   , Fn4 , v127
	.byte	W16
	.byte		TIE   , En4
	.byte	W80
	.byte	PEND
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte		EOT   
	.byte		N96   , As3
	.byte	W96
@ 015   ----------------------------------------
mus_trainer_tower_1_015:
	.byte		N84   , As4 , v127
	.byte	W84
	.byte		N12   , Gs4
	.byte	W12
	.byte	PEND
@ 016   ----------------------------------------
	.byte		N16   , Gn4
	.byte	W16
	.byte		TIE   , En4
	.byte	W80
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
	.byte		EOT   
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
	.byte	W16
	.byte		N16   , As3
	.byte	W16
	.byte		        Gs3
	.byte	W16
	.byte		        Gn3
	.byte	W16
	.byte		        Fs3
	.byte	W16
	.byte		        Fn3
	.byte	W16
@ 024   ----------------------------------------
	.byte		        En3
	.byte	W16
	.byte		        Fn3
	.byte	W16
	.byte		        Gn3
	.byte	W16
	.byte		        Fn3
	.byte	W16
	.byte		        Gn3
	.byte	W16
	.byte		        Bn3
	.byte	W16
@ 025   ----------------------------------------
	.byte		N96   , Cn4
	.byte	W96
@ 026   ----------------------------------------
	.byte		        Gn3
	.byte	W96
@ 027   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_1_011
	.byte	PATT
	 .word	mus_trainer_tower_1_012
	.byte	W96
@ 028   ----------------------------------------
	.byte		EOT   , En4
	.byte		N96   , As3 , v127
	.byte	W96
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_1_015
	.byte		N16   , Gn4 , v127
	.byte	W16
	.byte		N64   , En4
	.byte	W64
	.byte		N08   , As4
	.byte	W08
	.byte		        Bn4
	.byte	W08
@ 030   ----------------------------------------
	.byte		N96   , Cn5
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
	.byte	W48
	.byte		N16   , Cn3
	.byte	W16
	.byte		        Cs3
	.byte	W16
	.byte		        Fn3
	.byte	W16
@ 036   ----------------------------------------
	.byte		        En3
	.byte	W16
	.byte		        Fn3
	.byte	W16
	.byte		        En3
	.byte	W16
	.byte		        Gn3
	.byte	W16
	.byte		        Fn3
	.byte	W16
	.byte		        Gn3
	.byte	W16
@ 037   ----------------------------------------
	.byte		        Gs3
	.byte	W16
	.byte		        As3
	.byte	W16
	.byte		        Cn4
	.byte	W16
	.byte		        Cs4
	.byte	W16
	.byte		        Ds4
	.byte	W16
	.byte		        Fn4
	.byte	W16
@ 038   ----------------------------------------
	.byte		N96   , Gn4
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
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte		TIE   , Cn3
	.byte		TIE   , Fn3
	.byte	W96
@ 056   ----------------------------------------
	.byte	W72
	.byte		EOT   , Cn3
	.byte		        Fn3
	.byte		N24   , Gn3
	.byte		N24   , Cn4
	.byte	W24
@ 057   ----------------------------------------
	.byte		N16   , Fs3
	.byte		N16   , Bn3
	.byte	W16
	.byte		N80   , Dn3
	.byte		N80   , Gn3
	.byte	W80
@ 058   ----------------------------------------
	.byte		N16   , Ds3
	.byte		N16   , Gs3
	.byte	W16
	.byte		N80   , Cn3
	.byte		N80   , Fn3
	.byte	W80
@ 059   ----------------------------------------
	.byte		N96   , Gs3
	.byte	W96
@ 060   ----------------------------------------
	.byte		        Bn3
	.byte	W96
@ 061   ----------------------------------------
	.byte		TIE   , Cn4
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte		EOT   
	.byte		TIE   , Cn3
	.byte	W96
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte		EOT   
	.byte	W96
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	W96
@ 069   ----------------------------------------
	.byte	W96
@ 070   ----------------------------------------
	.byte	W96
@ 071   ----------------------------------------
	.byte	W96
@ 072   ----------------------------------------
	.byte	W96
@ 073   ----------------------------------------
	.byte	W96
@ 074   ----------------------------------------
	.byte	W96
@ 075   ----------------------------------------
	.byte		N96   , As2
	.byte	W96
@ 076   ----------------------------------------
	.byte		N84   , Cs3
	.byte	W84
	.byte		N12   , Fs3
	.byte	W12
@ 077   ----------------------------------------
	.byte		N16   , En3
	.byte	W16
	.byte		TIE   , Fs3
	.byte	W80
@ 078   ----------------------------------------
	.byte	W96
@ 079   ----------------------------------------
	.byte		EOT   
	.byte		N96   , Bn2
	.byte	W96
@ 080   ----------------------------------------
	.byte		N84   , Cs4
	.byte	W84
	.byte		N12   , Bn3
	.byte	W12
@ 081   ----------------------------------------
	.byte		N16   , As3
	.byte	W16
	.byte		TIE   , Fs3
	.byte	W80
@ 082   ----------------------------------------
	.byte	W96
@ 083   ----------------------------------------
	.byte		EOT   
	.byte		N16   , Gs3
	.byte	W16
	.byte		        En3
	.byte	W16
	.byte		        Bn2
	.byte	W16
	.byte		N64   , Bn3
	.byte	W48
@ 084   ----------------------------------------
	.byte	W16
	.byte		N16   , Gs3
	.byte	W16
	.byte		        Bn3
	.byte	W16
	.byte		        Gs3
	.byte	W16
	.byte		        Ds3
	.byte	W16
	.byte		        En3
	.byte	W16
@ 085   ----------------------------------------
	.byte		        Fn3
	.byte	W16
	.byte		N80   , Fs3
	.byte	W80
@ 086   ----------------------------------------
	.byte		N16   , En3
	.byte	W16
	.byte		N80   , Cs3
	.byte	W80
@ 087   ----------------------------------------
	.byte		N16   , Gs3
	.byte	W16
	.byte		        En3
	.byte	W16
	.byte		        Bn2
	.byte	W16
	.byte		N48   , Bn3
	.byte	W48
@ 088   ----------------------------------------
	.byte		N16   , An3
	.byte	W16
	.byte		        Gs3
	.byte	W16
	.byte		        Gn3
	.byte	W16
	.byte		        Fs3
	.byte	W16
	.byte		        Fn3
	.byte	W16
	.byte		        Gs3
	.byte	W16
@ 089   ----------------------------------------
	.byte		        As3
	.byte	W16
	.byte		        Bn3
	.byte	W16
	.byte		        As3
	.byte	W16
	.byte		        Bn3
	.byte	W16
	.byte		        As3
	.byte	W16
	.byte		        Bn3
	.byte	W16
@ 090   ----------------------------------------
	.byte		N96   , Cs4
	.byte	W96
@ 091   ----------------------------------------
	.byte	GOTO
	 .word	mus_trainer_tower_1_B1
	.byte	W06
	.byte	FINE

@**************** Track 2 ****************@

mus_trainer_tower_2:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_trainer_tower_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v-64
	.byte		VOL   , 127*mus_trainer_tower_mvl/mxv
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
mus_trainer_tower_2_004:
	.byte		N08   , Cn3 , v127
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cs3
	.byte	W16
	.byte		        Cn3
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cs3
	.byte	W16
	.byte		        Cn3
	.byte	W08
	.byte	PEND
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_2_004
	.byte	W96
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_2_004
	.byte	W96
@ 008   ----------------------------------------
mus_trainer_tower_2_B1:
	.byte	PATT
	 .word	mus_trainer_tower_2_004
	.byte	W96
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_2_004
	.byte	W96
@ 010   ----------------------------------------
mus_trainer_tower_2_010:
	.byte		N08   , As2 , v127
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Bn2
	.byte	W16
	.byte		        As2
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Bn2
	.byte	W16
	.byte		        As2
	.byte	W08
	.byte	PEND
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_2_004
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
	.byte	PATT
	 .word	mus_trainer_tower_2_004
	.byte	W96
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_2_004
	.byte	W96
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_2_010
	.byte	W96
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_2_004
	.byte	W96
@ 025   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_2_004
	.byte	W96
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_2_004
	.byte	W96
@ 027   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_2_004
	.byte	W96
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_2_004
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
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte	W96
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W96
@ 060   ----------------------------------------
	.byte	W96
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
mus_trainer_tower_2_065:
	.byte		N08   , Fs4 , v127
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Gn4
	.byte	W16
	.byte		        Fs4
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Gn4
	.byte	W16
	.byte		        Fs4
	.byte	W08
	.byte	PEND
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_2_065
	.byte	W96
@ 068   ----------------------------------------
	.byte		N08   , En4 , v127
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Fn4
	.byte	W16
	.byte		        En4
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Fn4
	.byte	W16
	.byte		        En4
	.byte	W08
@ 069   ----------------------------------------
	.byte	W96
@ 070   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_2_065
	.byte	W96
@ 071   ----------------------------------------
	.byte	W96
@ 072   ----------------------------------------
	.byte	W96
@ 073   ----------------------------------------
	.byte	W96
@ 074   ----------------------------------------
	.byte	W96
@ 075   ----------------------------------------
	.byte	W96
@ 076   ----------------------------------------
	.byte	W96
@ 077   ----------------------------------------
	.byte	W96
@ 078   ----------------------------------------
	.byte	W96
@ 079   ----------------------------------------
	.byte	GOTO
	 .word	mus_trainer_tower_2_B1
	.byte	W06
	.byte	FINE

@**************** Track 3 ****************@

mus_trainer_tower_3:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_trainer_tower_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v+63
	.byte		VOL   , 127*mus_trainer_tower_mvl/mxv
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
mus_trainer_tower_3_005:
	.byte		N08   , Cn3 , v127
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cs3
	.byte	W16
	.byte		        Cn3
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cs3
	.byte	W16
	.byte		        Cn3
	.byte	W08
	.byte	PEND
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_3_005
	.byte	W96
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_3_005
mus_trainer_tower_3_B1:
	.byte	W96
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_3_005
	.byte	W96
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_3_005
	.byte	W96
@ 011   ----------------------------------------
mus_trainer_tower_3_011:
	.byte		N08   , As2 , v127
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Bn2
	.byte	W16
	.byte		        As2
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Bn2
	.byte	W16
	.byte		        As2
	.byte	W08
	.byte	PEND
@ 012   ----------------------------------------
	.byte	W96
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_3_005
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
	 .word	mus_trainer_tower_3_005
	.byte	W96
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_3_005
	.byte	W96
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_3_011
	.byte	W96
@ 025   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_3_005
	.byte	W96
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_3_005
	.byte	W96
@ 027   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_3_005
	.byte	W96
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_3_005
	.byte	W96
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_3_005
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
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte	W96
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W96
@ 060   ----------------------------------------
	.byte	W96
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
mus_trainer_tower_3_066:
	.byte		N08   , Fs4 , v127
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Gn4
	.byte	W16
	.byte		        Fs4
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Gn4
	.byte	W16
	.byte		        Fs4
	.byte	W08
	.byte	PEND
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_3_066
	.byte	W96
@ 069   ----------------------------------------
	.byte		N08   , En4 , v127
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Fn4
	.byte	W16
	.byte		        En4
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Fn4
	.byte	W16
	.byte		        En4
	.byte	W08
@ 070   ----------------------------------------
	.byte	W96
@ 071   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_3_066
	.byte	W96
@ 072   ----------------------------------------
	.byte	W96
@ 073   ----------------------------------------
	.byte	W96
@ 074   ----------------------------------------
	.byte	W96
@ 075   ----------------------------------------
	.byte	W96
@ 076   ----------------------------------------
	.byte	W96
@ 077   ----------------------------------------
	.byte	W96
@ 078   ----------------------------------------
	.byte	W96
@ 079   ----------------------------------------
	.byte	GOTO
	 .word	mus_trainer_tower_3_B1
	.byte	W06
	.byte	FINE

@**************** Track 4 ****************@

mus_trainer_tower_4:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_trainer_tower_key+0
	.byte		VOICE , 33
	.byte		VOL   , 101*mus_trainer_tower_mvl/mxv
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
mus_trainer_tower_4_006:
	.byte		N24   , Cn1 , v127
	.byte	W24
	.byte		N16   
	.byte	W16
	.byte		N08   , Cs1
	.byte	W08
	.byte		N24   , As0
	.byte	W24
	.byte		N16   
	.byte	W16
	.byte		N08   , Cs1
	.byte	W08
	.byte	PEND
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
mus_trainer_tower_4_B1:
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
mus_trainer_tower_4_007:
	.byte		N24   , As0 , v127
	.byte	W24
	.byte		N16   
	.byte	W16
	.byte		N08   , Cn1
	.byte	W08
	.byte		N24   , Gn0
	.byte	W24
	.byte		N16   
	.byte	W16
	.byte		N08   , Cn1
	.byte	W08
	.byte	PEND
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_4_007
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_007
	.byte	PATT
	 .word	mus_trainer_tower_4_007
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_007
	.byte	PATT
	 .word	mus_trainer_tower_4_007
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_007
	.byte	PATT
	 .word	mus_trainer_tower_4_007
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
	.byte	PATT
	 .word	mus_trainer_tower_4_006
mus_trainer_tower_4_008:
	.byte		N24   , Cn1 , v127
	.byte		N08   , Cn2
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N16   , Cn1
	.byte		N08   , Cs2
	.byte	W16
	.byte		        Cs1
	.byte		N08   , Cn2
	.byte	W08
	.byte		N24   , As0
	.byte	W08
	.byte		N08   , Cn2
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N16   , As0
	.byte		N08   , Cs2
	.byte	W16
	.byte		        Cs1
	.byte		N08   , Cn2
	.byte	W08
	.byte	PEND
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_4_008
	.byte	PATT
	 .word	mus_trainer_tower_4_008
	.byte	PATT
	 .word	mus_trainer_tower_4_008
mus_trainer_tower_4_009:
	.byte		N24   , Bn0 , v127
	.byte		N08   , Bn1
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N16   , Bn0
	.byte		N08   , Cn2
	.byte	W16
	.byte		        Cn1
	.byte		N08   , Bn1
	.byte	W08
	.byte		N24   , An0
	.byte	W08
	.byte		N08   , Bn1
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N16   , An0
	.byte		N08   , Cn2
	.byte	W16
	.byte		        Cn1
	.byte		N08   , Bn1
	.byte	W08
	.byte	PEND
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_4_009
	.byte	PATT
	 .word	mus_trainer_tower_4_008
	.byte	PATT
	 .word	mus_trainer_tower_4_008
	.byte	PATT
	 .word	mus_trainer_tower_4_008
	.byte	PATT
	 .word	mus_trainer_tower_4_008
	.byte	PATT
	 .word	mus_trainer_tower_4_008
	.byte	PATT
	 .word	mus_trainer_tower_4_008
	.byte	PATT
	 .word	mus_trainer_tower_4_009
	.byte	PATT
	 .word	mus_trainer_tower_4_009
	.byte	PATT
	 .word	mus_trainer_tower_4_008
	.byte	PATT
	 .word	mus_trainer_tower_4_008
	.byte	PATT
	 .word	mus_trainer_tower_4_008
	.byte	PATT
	 .word	mus_trainer_tower_4_008
mus_trainer_tower_4_010:
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte	PEND
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_4_010
	.byte	PATT
	 .word	mus_trainer_tower_4_010
	.byte	PATT
	 .word	mus_trainer_tower_4_010
	.byte	PATT
	 .word	mus_trainer_tower_4_010
	.byte		N16   , Cs1 , v127
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
@ 012   ----------------------------------------
	.byte		        Dn1
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
@ 013   ----------------------------------------
	.byte		        Gs1
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
@ 014   ----------------------------------------
	.byte		TIE   , Cs0
	.byte	W96
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte		EOT   
mus_trainer_tower_4_016:
	.byte		N24   , Fs1 , v127
	.byte	W24
	.byte		N16   
	.byte	W16
	.byte		N08   , Gn1
	.byte	W08
	.byte		N24   , En1
	.byte	W24
	.byte		N16   
	.byte	W16
	.byte		N08   , Gn1
	.byte	W08
	.byte	PEND
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_4_016
	.byte	PATT
	 .word	mus_trainer_tower_4_016
	.byte	PATT
	 .word	mus_trainer_tower_4_016
mus_trainer_tower_4_017:
	.byte		N24   , En1 , v127
	.byte	W24
	.byte		N16   
	.byte	W16
	.byte		N08   , Fs1
	.byte	W08
	.byte		N24   , Cs1
	.byte	W24
	.byte		N16   
	.byte	W16
	.byte		N08   , Fs1
	.byte	W08
	.byte	PEND
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_4_017
	.byte	PATT
	 .word	mus_trainer_tower_4_016
	.byte	PATT
	 .word	mus_trainer_tower_4_016
	.byte	PATT
	 .word	mus_trainer_tower_4_017
	.byte	PATT
	 .word	mus_trainer_tower_4_017
	.byte	PATT
	 .word	mus_trainer_tower_4_016
	.byte	PATT
	 .word	mus_trainer_tower_4_016
	.byte	PATT
	 .word	mus_trainer_tower_4_017
	.byte	PATT
	 .word	mus_trainer_tower_4_017
	.byte	PATT
	 .word	mus_trainer_tower_4_016
	.byte	PATT
	 .word	mus_trainer_tower_4_016
	.byte	GOTO
	 .word	mus_trainer_tower_4_B1
	.byte	W06
	.byte	FINE

@**************** Track 5 ****************@

mus_trainer_tower_5:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_trainer_tower_key+0
	.byte		VOICE , 17
	.byte		PAN   , c_v-38
	.byte		VOL   , 83*mus_trainer_tower_mvl/mxv
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
	.byte		N08   , Cn5 , v127
	.byte	W08
	.byte		        Gs4
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		        Gs4
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Fn4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Cn4
	.byte	W08
	.byte		        Cs4
	.byte	W08
	.byte		        Cn4
	.byte	W08
	.byte		        As3
	.byte	W08
@ 010   ----------------------------------------
mus_trainer_tower_5_B1:
	.byte		N07   , Cn4 , v127
	.byte	W08
	.byte		        Gn3
	.byte	W08
	.byte		        Cn4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Cn4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Cn4
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte	PEND
@ 011   ----------------------------------------
mus_trainer_tower_5_011:
	.byte		N07   , En4 , v127
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte		        Cn4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Cn4
	.byte	W08
	.byte		        Gn3
	.byte	W08
	.byte		        Cn4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte	PEND
@ 012   ----------------------------------------
mus_trainer_tower_5_012:
	.byte		N07   , Cn4 , v127
	.byte	W08
	.byte		        Gn3
	.byte	W08
	.byte		        Cn4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Cn4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte		        En5
	.byte	W08
	.byte		        Gn5
	.byte	W08
	.byte		        En5
	.byte	W08
	.byte		        Gn5
	.byte	W08
	.byte	PEND
@ 013   ----------------------------------------
mus_trainer_tower_5_013:
	.byte		N07   , En3 , v127
	.byte	W08
	.byte		        Gn3
	.byte	W08
	.byte		        Cn4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Gn3
	.byte	W08
	.byte		        Cn4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte		        En5
	.byte	W08
	.byte		        Gn5
	.byte	W08
	.byte		        Cn6
	.byte	W08
	.byte	PEND
@ 014   ----------------------------------------
mus_trainer_tower_5_014:
	.byte		N07   , As3 , v127
	.byte	W08
	.byte		        Fn3
	.byte	W08
	.byte		        As3
	.byte	W08
	.byte		        Dn4
	.byte	W08
	.byte		        As3
	.byte	W08
	.byte		        Dn4
	.byte	W08
	.byte		        Fn4
	.byte	W08
	.byte		        As4
	.byte	W08
	.byte		        Fn4
	.byte	W08
	.byte		        Dn4
	.byte	W08
	.byte		        As3
	.byte	W08
	.byte		        Fn4
	.byte	W08
	.byte	PEND
@ 015   ----------------------------------------
mus_trainer_tower_5_015:
	.byte		N07   , Dn4 , v127
	.byte	W08
	.byte		        As4
	.byte	W08
	.byte		        As3
	.byte	W08
	.byte		        Dn4
	.byte	W08
	.byte		        As3
	.byte	W08
	.byte		        Fn3
	.byte	W08
	.byte		        As3
	.byte	W08
	.byte		        Dn4
	.byte	W08
	.byte		        Fn4
	.byte	W08
	.byte		        Dn4
	.byte	W08
	.byte		        Fn4
	.byte	W08
	.byte		        As4
	.byte	W08
	.byte	PEND
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_5_012
mus_trainer_tower_5_016:
	.byte		N07   , En2 , v127
	.byte	W08
	.byte		        Gn2
	.byte	W08
	.byte		        Cn3
	.byte	W08
	.byte		        En3
	.byte	W08
	.byte		        Gn3
	.byte	W08
	.byte		        Cn4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte		        En5
	.byte	W08
	.byte		        Gn5
	.byte	W08
	.byte		        Cn6
	.byte	W08
	.byte	PEND
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
	.byte	PATT
	 .word	mus_trainer_tower_5_B1
	.byte	PATT
	 .word	mus_trainer_tower_5_011
	.byte	PATT
	 .word	mus_trainer_tower_5_012
	.byte	PATT
	 .word	mus_trainer_tower_5_013
	.byte	PATT
	 .word	mus_trainer_tower_5_014
	.byte	PATT
	 .word	mus_trainer_tower_5_015
	.byte	PATT
	 .word	mus_trainer_tower_5_012
	.byte	PATT
	 .word	mus_trainer_tower_5_016
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
	.byte		N08   , Bn3 , v127
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		        An4
	.byte	W08
	.byte		N23   , Bn4
	.byte	W16
	.byte		N08   , Bn3
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		        An4
	.byte	W08
	.byte		N23   , Bn4
	.byte	W88
@ 046   ----------------------------------------
	.byte	W44
@ 047   ----------------------------------------
	.byte		N01   
	.byte	W52
	.byte		N08   , Fn5
	.byte	W08
	.byte		        Cs5
	.byte	W08
	.byte		        Cn5
	.byte	W08
@ 048   ----------------------------------------
	.byte		        Cs5
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte		        An4
	.byte	W08
	.byte		        As4
	.byte	W08
	.byte		        An4
	.byte	W08
	.byte		        Fn4
	.byte	W08
	.byte		        Fs4
	.byte	W08
	.byte		        Fn4
	.byte	W08
	.byte		N23   , Ds4
	.byte	W08
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W44
@ 052   ----------------------------------------
	.byte		N01   , Gn4
	.byte	W52
	.byte		N07   , Bn3
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Gn4
	.byte	W08
@ 053   ----------------------------------------
	.byte		        An4
	.byte	W08
	.byte		        Bn4
	.byte	W08
	.byte		N23   , En5
	.byte	W32
	.byte		N07   , Bn3
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Gn4
	.byte	W08
	.byte		        An4
	.byte	W08
	.byte		        Bn4
	.byte	W08
	.byte		        En5
	.byte	W08
@ 054   ----------------------------------------
	.byte		N07   
	.byte	W08
	.byte		        Bn4
	.byte	W08
	.byte		        En5
	.byte	W08
	.byte		        Bn4
	.byte	W08
	.byte		        En5
	.byte	W08
	.byte		        Bn4
	.byte	W08
	.byte		        En5
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		        Bn4
	.byte	W08
mus_trainer_tower_5_054:
	.byte		N07   , Fn5 , v127
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte		        Fn5
	.byte	W08
@ 055   ----------------------------------------
	.byte		        Cn5
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		        Fn5
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte		        Fn5
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte		        Fn5
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte	PEND
mus_trainer_tower_5_055:
	.byte		N07   , Fn5 , v127
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte		        Fn5
	.byte	W08
@ 056   ----------------------------------------
	.byte		        Cn5
	.byte	W08
	.byte		        Fn5
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte		        Fn5
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte		        Fn5
	.byte	W08
	.byte		        Cn5
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_trainer_tower_5_054
	.byte	PATT
	 .word	mus_trainer_tower_5_055
	.byte	PATT
	 .word	mus_trainer_tower_5_054
	.byte	PATT
	 .word	mus_trainer_tower_5_055
	.byte	PATT
	 .word	mus_trainer_tower_5_054
	.byte	PATT
	 .word	mus_trainer_tower_5_055
	.byte	PATT
	 .word	mus_trainer_tower_5_054
	.byte	PATT
	 .word	mus_trainer_tower_5_055
	.byte	PATT
	 .word	mus_trainer_tower_5_054
	.byte	PATT
	 .word	mus_trainer_tower_5_055
	.byte	W96
@ 057   ----------------------------------------
	.byte	W48
@ 058   ----------------------------------------
	.byte	W02
	.byte		N01   , An4 , v127
	.byte	W44
	.byte	W02
	.byte		N07   , Fs4
	.byte	W08
	.byte		        Cs4
	.byte	W08
	.byte		        Fs4
	.byte	W08
@ 059   ----------------------------------------
	.byte		        As4
	.byte	W08
	.byte		        Fs4
	.byte	W08
	.byte		        As4
	.byte	W08
	.byte		        Cs5
	.byte	W08
	.byte		        Fs5
	.byte	W08
	.byte		        Cs5
	.byte	W08
	.byte		        As4
	.byte	W08
	.byte		        Fs4
	.byte	W08
	.byte		        Cs5
	.byte	W08
	.byte		        As4
	.byte	W08
	.byte		        Fs5
	.byte	W08
	.byte		        Fs4
	.byte	W08
@ 060   ----------------------------------------
	.byte		        As4
	.byte	W08
	.byte		        Fs4
	.byte	W08
	.byte		        Cs4
	.byte	W08
	.byte		        Fs4
	.byte	W08
	.byte		        As4
	.byte	W08
	.byte		        Cs5
	.byte	W08
	.byte		        As4
	.byte	W08
	.byte		        Cs5
	.byte	W08
	.byte		        Fs5
	.byte	W08
mus_trainer_tower_5_060:
	.byte		N07   , Fs4 , v127
	.byte	W08
	.byte		        Cs4
	.byte	W08
	.byte		        Fs4
	.byte	W08
@ 061   ----------------------------------------
	.byte		        As4
	.byte	W08
	.byte		        Fs4
	.byte	W08
	.byte		        As4
	.byte	W08
	.byte		        Cs5
	.byte	W08
	.byte		        Fs5
	.byte	W08
	.byte		        As5
	.byte	W08
	.byte		        Cs6
	.byte	W08
	.byte		        As5
	.byte	W08
	.byte		        Cs6
	.byte	W08
	.byte	PEND
	.byte		        As3
	.byte	W08
	.byte		        Cs4
	.byte	W08
	.byte		        Fs4
	.byte	W08
@ 062   ----------------------------------------
	.byte		        As4
	.byte	W08
	.byte		        Cs4
	.byte	W08
	.byte		        Fs4
	.byte	W08
	.byte		        As4
	.byte	W08
	.byte		        Cs5
	.byte	W08
	.byte		        Fs5
	.byte	W08
	.byte		        As5
	.byte	W08
	.byte		        Cs6
	.byte	W08
	.byte		        Fs6
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Bn3
	.byte	W08
	.byte		        En4
	.byte	W08
@ 063   ----------------------------------------
	.byte		        Gs4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Gs4
	.byte	W08
	.byte		        Bn4
	.byte	W08
	.byte		        En5
	.byte	W08
	.byte		        Bn4
	.byte	W08
	.byte		        Gs4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Bn4
	.byte	W08
	.byte		        Gs4
	.byte	W08
	.byte		        En5
	.byte	W08
	.byte		        En4
	.byte	W08
@ 064   ----------------------------------------
	.byte		        Gs4
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Bn3
	.byte	W08
	.byte		        En4
	.byte	W08
	.byte		        Gs4
	.byte	W08
	.byte		        Bn4
	.byte	W08
	.byte		        Gs4
	.byte	W08
	.byte		        Bn4
	.byte	W08
	.byte		        En5
	.byte	W08
	.byte	PATT
	 .word	mus_trainer_tower_5_060
	.byte		N07   , As2 , v127
	.byte	W08
	.byte		        Cs3
	.byte	W08
	.byte		        Fs3
	.byte	W08
@ 065   ----------------------------------------
	.byte		        As3
	.byte	W08
	.byte		        Cs4
	.byte	W08
	.byte		        Fs4
	.byte	W08
	.byte		        As4
	.byte	W08
	.byte		        Cs5
	.byte	W08
	.byte		        Fs5
	.byte	W08
	.byte		        As5
	.byte	W08
	.byte		        Cs6
	.byte	W08
	.byte		        Fs6
	.byte	W08
	.byte	W96
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	W96
@ 069   ----------------------------------------
	.byte	W96
@ 070   ----------------------------------------
	.byte	W96
@ 071   ----------------------------------------
	.byte	W96
@ 072   ----------------------------------------
	.byte	W96
@ 073   ----------------------------------------
	.byte	W17
	.byte	GOTO
	 .word	mus_trainer_tower_5_B1
	.byte	W06
	.byte	FINE

@**************** Track 6 ****************@

mus_trainer_tower_6:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_trainer_tower_key+0
	.byte		VOICE , 48
	.byte		VOL   , 117*mus_trainer_tower_mvl/mxv
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
	.byte	W96
@ 010   ----------------------------------------
mus_trainer_tower_6_B1:
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
	.byte		N16   , Fn4 , v080
	.byte	W16
	.byte		        Dn4
	.byte	W16
	.byte		        As3
	.byte	W16
	.byte		TIE   , As4
	.byte	W48
@ 019   ----------------------------------------
	.byte	W80
	.byte		EOT   
	.byte		N16   , Gs4
	.byte	W16
@ 020   ----------------------------------------
	.byte		        Gn4
	.byte	W16
	.byte		N80   , En4
	.byte	W80
@ 021   ----------------------------------------
	.byte		N16   , Dn4
	.byte	W16
	.byte		N80   , En4
	.byte	W80
@ 022   ----------------------------------------
	.byte		N16   , Fn4
	.byte	W16
	.byte		        Dn4
	.byte	W16
	.byte		        As3
	.byte	W16
	.byte		N80   , As4
	.byte	W48
@ 023   ----------------------------------------
	.byte	W32
	.byte		N16   , Gs4
	.byte	W16
	.byte		        As4
	.byte	W16
	.byte		        Gs4
	.byte	W16
	.byte		        Bn4
	.byte	W16
@ 024   ----------------------------------------
	.byte		        Cn5
	.byte	W16
	.byte		        Dn5
	.byte	W16
	.byte		        Cn5
	.byte	W16
	.byte		        Dn5
	.byte	W16
	.byte		        Cn5
	.byte	W16
	.byte		        Dn5
	.byte	W16
@ 025   ----------------------------------------
	.byte		N96   , En5
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
	.byte		N16   , Cn3
	.byte	W16
	.byte		        Cs3
	.byte	W16
	.byte		        Fn3
	.byte	W16
	.byte		        En3
	.byte	W16
	.byte		        Fn3
	.byte	W16
	.byte		        En3
	.byte	W16
@ 035   ----------------------------------------
	.byte		        Gn3
	.byte	W16
	.byte		        Fn3
	.byte	W16
	.byte		        Gn3
	.byte	W16
	.byte		        Gs3
	.byte	W16
	.byte		        As3
	.byte	W16
	.byte		        Gs3
	.byte	W16
@ 036   ----------------------------------------
	.byte		        As3
	.byte	W16
	.byte		        Cn4
	.byte	W16
	.byte		        As3
	.byte	W16
	.byte		        Gs3
	.byte	W16
	.byte		        As3
	.byte	W16
	.byte		        Gs3
	.byte	W16
@ 037   ----------------------------------------
	.byte		N96   , Gn3
	.byte	W96
@ 038   ----------------------------------------
	.byte		N16   , Cn4
	.byte	W16
	.byte		        Cs4
	.byte	W16
	.byte		        Fn4
	.byte	W16
	.byte		        En4
	.byte	W16
	.byte		        Fn4
	.byte	W16
	.byte		        En4
	.byte	W16
@ 039   ----------------------------------------
	.byte		        Gn4
	.byte	W16
	.byte		        Fn4
	.byte	W16
	.byte		        Gn4
	.byte	W16
	.byte		        Gs4
	.byte	W16
	.byte		        As4
	.byte	W16
	.byte		        Gs4
	.byte	W16
@ 040   ----------------------------------------
	.byte		        As4
	.byte	W16
	.byte		        Cn5
	.byte	W16
	.byte		        As4
	.byte	W16
	.byte		        Cs5
	.byte	W16
	.byte		        Ds5
	.byte	W16
	.byte		        Cs5
	.byte	W16
@ 041   ----------------------------------------
	.byte		N96   , Cn5
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
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W96
@ 060   ----------------------------------------
	.byte	W96
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	W96
@ 069   ----------------------------------------
	.byte	W96
@ 070   ----------------------------------------
	.byte	W96
@ 071   ----------------------------------------
	.byte	W96
@ 072   ----------------------------------------
	.byte	W96
@ 073   ----------------------------------------
	.byte	W96
@ 074   ----------------------------------------
	.byte	W96
@ 075   ----------------------------------------
	.byte	W96
@ 076   ----------------------------------------
	.byte	W96
@ 077   ----------------------------------------
	.byte	W96
@ 078   ----------------------------------------
	.byte		        Cs4
	.byte	W96
@ 079   ----------------------------------------
	.byte		N84   , Fs4
	.byte	W84
	.byte		N12   , Cs5
	.byte	W12
@ 080   ----------------------------------------
	.byte		N16   , Bn4
	.byte	W16
	.byte		TIE   , As4
	.byte	W80
@ 081   ----------------------------------------
	.byte	W96
@ 082   ----------------------------------------
	.byte		EOT   
	.byte		N96   , En4
	.byte	W96
@ 083   ----------------------------------------
	.byte		N84   , En5
	.byte	W84
	.byte		N12   , Dn5
	.byte	W12
@ 084   ----------------------------------------
	.byte		N16   , Cs5
	.byte	W16
	.byte		TIE   , As4
	.byte	W80
@ 085   ----------------------------------------
	.byte	W96
@ 086   ----------------------------------------
	.byte		EOT   
	.byte	W96
@ 087   ----------------------------------------
	.byte	W96
@ 088   ----------------------------------------
	.byte	W96
@ 089   ----------------------------------------
	.byte	W96
@ 090   ----------------------------------------
	.byte	W96
@ 091   ----------------------------------------
	.byte	W16
	.byte		N16   , En3
	.byte	W16
	.byte		        Dn3
	.byte	W16
	.byte		        Cs3
	.byte	W16
	.byte		        Cn3
	.byte	W16
	.byte		        Bn2
	.byte	W16
@ 092   ----------------------------------------
	.byte		        As2
	.byte	W16
	.byte		        Bn2
	.byte	W16
	.byte		        Cs3
	.byte	W16
	.byte		        Bn2
	.byte	W16
	.byte		        Cs3
	.byte	W16
	.byte		        Fn3
	.byte	W16
@ 093   ----------------------------------------
	.byte		N96   , Fs3
	.byte	W96
@ 094   ----------------------------------------
	.byte	GOTO
	 .word	mus_trainer_tower_6_B1
	.byte	W06
	.byte	FINE

@**************** Track 7 ****************@

mus_trainer_tower_7:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_trainer_tower_key+0
	.byte		VOICE , 56
	.byte		PAN   , c_v+38
	.byte		VOL   , 107*mus_trainer_tower_mvl/mxv
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
	.byte	W96
@ 010   ----------------------------------------
mus_trainer_tower_7_B1:
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
	.byte		N16   , Dn4 , v127
	.byte	W16
	.byte		        As3
	.byte	W16
	.byte		        Fn3
	.byte	W16
	.byte		N64   , Fn4
	.byte	W48
@ 019   ----------------------------------------
	.byte	W16
	.byte		N16   , Dn4
	.byte	W16
	.byte		        Fn4
	.byte	W16
	.byte		        Dn4
	.byte	W16
	.byte		        An3
	.byte	W16
	.byte		        As3
	.byte	W16
@ 020   ----------------------------------------
	.byte		        Bn3
	.byte	W16
	.byte		N80   , Cn4
	.byte	W80
@ 021   ----------------------------------------
	.byte		N16   , As3
	.byte	W16
	.byte		N80   , Gn3
	.byte	W80
@ 022   ----------------------------------------
	.byte		N16   , Dn4
	.byte	W16
	.byte		        As3
	.byte	W16
	.byte		        Fn3
	.byte	W16
	.byte		N48   , Fn4
	.byte	W48
@ 023   ----------------------------------------
	.byte		N16   , Ds4
	.byte	W16
	.byte		        Dn4
	.byte	W16
	.byte		        Cs4
	.byte	W16
	.byte		        Cn4
	.byte	W16
	.byte		        Bn3
	.byte	W16
	.byte		        Dn4
	.byte	W16
@ 024   ----------------------------------------
	.byte		        En4
	.byte	W16
	.byte		        Fn4
	.byte	W16
	.byte		        En4
	.byte	W16
	.byte		        Fn4
	.byte	W16
	.byte		        En4
	.byte	W16
	.byte		        Fn4
	.byte	W16
@ 025   ----------------------------------------
	.byte		N96   , Gn4
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
	.byte	W16
	.byte		N16   , Cn4
	.byte	W16
	.byte		        Cs4
	.byte	W16
	.byte		        Ds4
	.byte	W16
	.byte		        Fn4
	.byte	W16
	.byte		        Gn4
	.byte	W16
@ 038   ----------------------------------------
	.byte	W96
@ 039   ----------------------------------------
	.byte	W96
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
mus_trainer_tower_7_042:
	.byte		N12   , Gs3 , v127
	.byte		N12   , Ds4
	.byte	W24
	.byte		        Gn3
	.byte		N12   , Cs4
	.byte	W72
	.byte	PEND
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_7_042
	.byte	W96
@ 045   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_7_042
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte	W96
@ 048   ----------------------------------------
	.byte		TIE   , Cn3 , v127
	.byte		TIE   , Fn3
	.byte	W96
@ 049   ----------------------------------------
	.byte	W72
	.byte		EOT   , Cn3
	.byte		        Fn3
	.byte		N24   , Gn3
	.byte		N24   , Cn4
	.byte	W24
@ 050   ----------------------------------------
	.byte		N16   , Fs3
	.byte		N16   , Bn3
	.byte	W16
	.byte		N80   , Dn3
	.byte		N80   , Gn3
	.byte	W80
@ 051   ----------------------------------------
	.byte		N16   , Ds3
	.byte		N16   , Gs3
	.byte	W16
	.byte		N80   , Cn3
	.byte		N80   , Fn3
	.byte	W80
@ 052   ----------------------------------------
	.byte		N96   , Bn2
	.byte		N96   , En3
	.byte	W96
@ 053   ----------------------------------------
	.byte		        Gs2
	.byte		N88   , Bn2
	.byte	W88
	.byte		N08   , En3
	.byte	W08
@ 054   ----------------------------------------
	.byte		N12   , Cn3
	.byte		N12   , Fn3
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W96
@ 060   ----------------------------------------
	.byte	W96
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W72
	.byte		N08   , Dn3
	.byte		N08   , An3
	.byte	W08
	.byte		        Ds3
	.byte		N08   , As3
	.byte	W08
	.byte		        En3
	.byte		N08   , Bn3
	.byte	W08
@ 066   ----------------------------------------
mus_trainer_tower_7_066:
	.byte		N08   , Fn3 , v127
	.byte		N08   , Cn4
	.byte	W16
	.byte		        Fn3
	.byte		N08   , Cn4
	.byte	W16
	.byte		        Fn3
	.byte		N08   , Cn4
	.byte	W08
	.byte		        Fn3
	.byte		N08   , Cn4
	.byte	W08
	.byte		        Fn3
	.byte		N08   , Cn4
	.byte	W16
	.byte		        Fn3
	.byte		N08   , Cn4
	.byte	W16
	.byte		        Fn3
	.byte		N08   , Cn4
	.byte	W08
	.byte		        Fn3
	.byte		N08   , Cn4
	.byte	W08
	.byte	PEND
@ 067   ----------------------------------------
mus_trainer_tower_7_067:
	.byte		N08   , Fs3 , v127
	.byte		N08   , Cs4
	.byte	W16
	.byte		        Fs3
	.byte		N08   , Cs4
	.byte	W16
	.byte		        Fs3
	.byte		N08   , Cs4
	.byte	W08
	.byte		        Fs3
	.byte		N08   , Cs4
	.byte	W08
	.byte		        Fs3
	.byte		N08   , Cs4
	.byte	W16
	.byte		        Fs3
	.byte		N08   , Cs4
	.byte	W16
	.byte		        Fs3
	.byte		N08   , Cs4
	.byte	W08
	.byte		        Fs3
	.byte		N08   , Cs4
	.byte	W08
	.byte	PEND
@ 068   ----------------------------------------
mus_trainer_tower_7_068:
	.byte		N08   , Gn3 , v127
	.byte		N08   , Dn4
	.byte	W16
	.byte		        Gn3
	.byte		N08   , Dn4
	.byte	W16
	.byte		        Gn3
	.byte		N08   , Dn4
	.byte	W08
	.byte		        Gn3
	.byte		N08   , Dn4
	.byte	W08
	.byte		        Gn3
	.byte		N08   , Dn4
	.byte	W16
	.byte		        Gn3
	.byte		N08   , Dn4
	.byte	W16
	.byte		        Gn3
	.byte		N08   , Dn4
	.byte	W08
	.byte		        Gn3
	.byte		N08   , Dn4
	.byte	W08
	.byte	PEND
@ 069   ----------------------------------------
	.byte		        Gs3
	.byte		N08   , Ds4
	.byte	W16
	.byte		        Gs3
	.byte		N08   , Ds4
	.byte	W16
	.byte		        Gs3
	.byte		N08   , Ds4
	.byte	W08
	.byte		        Gs3
	.byte		N08   , Ds4
	.byte	W08
	.byte		        Gs3
	.byte		N08   , Ds4
	.byte	W16
	.byte		        Gs3
	.byte		N08   , Ds4
	.byte	W16
	.byte		        Gs3
	.byte		N08   , Ds4
	.byte	W08
	.byte		        Gs3
	.byte		N08   , Ds4
	.byte	W08
@ 070   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_7_066
	.byte	PATT
	 .word	mus_trainer_tower_7_067
	.byte	PATT
	 .word	mus_trainer_tower_7_068
	.byte		N08   , Cs4 , v127
	.byte		N08   , Gs4
	.byte	W16
	.byte		        Cs4
	.byte		N08   , Gs4
	.byte	W16
	.byte		        Cs4
	.byte		N08   , Gs4
	.byte	W08
	.byte		        Cs4
	.byte		N08   , Gs4
	.byte	W08
	.byte		        Cs4
	.byte		N08   , Gs4
	.byte	W16
	.byte		        Cs4
	.byte		N08   , Gs4
	.byte	W16
	.byte		        Cs4
	.byte		N08   , Gs4
	.byte	W08
	.byte		        Cs4
	.byte		N08   , Gs4
	.byte	W08
@ 071   ----------------------------------------
	.byte	W96
@ 072   ----------------------------------------
	.byte	W96
@ 073   ----------------------------------------
	.byte	W96
@ 074   ----------------------------------------
	.byte	W96
@ 075   ----------------------------------------
	.byte	W96
@ 076   ----------------------------------------
	.byte	W96
@ 077   ----------------------------------------
	.byte	W96
@ 078   ----------------------------------------
	.byte	W96
@ 079   ----------------------------------------
	.byte	W96
@ 080   ----------------------------------------
	.byte	W96
@ 081   ----------------------------------------
	.byte		N16   , Bn3
	.byte	W16
	.byte		        Gs3
	.byte	W16
	.byte		        En3
	.byte	W16
	.byte		TIE   , En4
	.byte	W48
@ 082   ----------------------------------------
	.byte	W80
	.byte		EOT   
	.byte		N16   , Dn4
	.byte	W16
@ 083   ----------------------------------------
	.byte		        Cs4
	.byte	W16
	.byte		N80   , As3
	.byte	W80
@ 084   ----------------------------------------
	.byte		N16   , Gs3
	.byte	W16
	.byte		N80   , As3
	.byte	W80
@ 085   ----------------------------------------
	.byte		N16   , Bn3
	.byte	W16
	.byte		        Gs3
	.byte	W16
	.byte		        En3
	.byte	W16
	.byte		N80   , En4
	.byte	W48
@ 086   ----------------------------------------
	.byte	W32
	.byte		N16   , Dn4
	.byte	W16
	.byte		        En4
	.byte	W16
	.byte		        Dn4
	.byte	W16
	.byte		        Fn4
	.byte	W16
@ 087   ----------------------------------------
	.byte		        Fs4
	.byte	W16
	.byte		        Gs4
	.byte	W16
	.byte		        Fs4
	.byte	W16
	.byte		        Gs4
	.byte	W16
	.byte		        Fs4
	.byte	W16
	.byte		        Gs4
	.byte	W16
@ 088   ----------------------------------------
	.byte		N96   , As4
	.byte	W96
@ 089   ----------------------------------------
	.byte	GOTO
	 .word	mus_trainer_tower_7_B1
	.byte	W06
	.byte	FINE

@**************** Track 8 ****************@

mus_trainer_tower_8:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_trainer_tower_key+0
	.byte		VOICE , 47
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*mus_trainer_tower_mvl/mxv
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
	.byte	W96
@ 010   ----------------------------------------
mus_trainer_tower_8_B1:
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
	.byte	W48
	.byte		N24   , Gn1 , v127
	.byte	W48
@ 043   ----------------------------------------
	.byte		N08   
	.byte	W16
	.byte		        Gn2
	.byte	W08
	.byte		        Gn1
	.byte	W24
	.byte		N24   , Cn2
	.byte	W48
@ 044   ----------------------------------------
	.byte	W48
	.byte		N08   
	.byte	W08
	.byte		        Gn1
	.byte	W16
	.byte		        Cn2
	.byte	W24
@ 045   ----------------------------------------
	.byte		N08   
	.byte	W08
	.byte		        Gn1
	.byte	W16
	.byte		        Cn2
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N24   , Gn1
	.byte	W24
	.byte		N24   
	.byte	W24
@ 046   ----------------------------------------
	.byte	W48
	.byte		N08   , Cn2
	.byte	W16
	.byte		        Gn2
	.byte	W08
	.byte		        Gn1
	.byte	W24
@ 047   ----------------------------------------
	.byte		        Cn2
	.byte	W16
	.byte		        Gn2
	.byte	W08
	.byte		        Cn2
	.byte	W16
	.byte		        Gn2
	.byte	W08
	.byte		        Cn2
	.byte	W16
	.byte		        Gn2
	.byte	W08
	.byte		        Cn2
	.byte	W24
@ 048   ----------------------------------------
	.byte		        Gn2
	.byte	W08
	.byte		        Gn1
	.byte	W16
	.byte		        Cn2
	.byte	W16
	.byte		        Gn2
	.byte	W08
	.byte		        Gn1
	.byte	W24
	.byte		        Cn2
	.byte	W24
@ 049   ----------------------------------------
	.byte		N08   
	.byte	W16
	.byte		        Gn2
	.byte	W08
	.byte		        Gn1
	.byte	W16
	.byte		        Gn2
	.byte	W08
	.byte		        Cn2
	.byte	W16
	.byte		        Gn2
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn2
	.byte	W16
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W96
@ 060   ----------------------------------------
	.byte	W96
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	W96
@ 069   ----------------------------------------
	.byte	W96
@ 070   ----------------------------------------
	.byte	W96
@ 071   ----------------------------------------
	.byte	W80
	.byte		N16   , Ds1
	.byte	W16
@ 072   ----------------------------------------
	.byte		        Cn1
	.byte	W80
	.byte		N16   
	.byte	W16
@ 073   ----------------------------------------
	.byte		        Cs1
	.byte	W80
	.byte		N16   
	.byte	W16
@ 074   ----------------------------------------
	.byte		        Dn1
	.byte	W80
	.byte		N16   
	.byte	W16
@ 075   ----------------------------------------
	.byte		        Gs1
	.byte	W80
	.byte		N16   
	.byte	W16
@ 076   ----------------------------------------
	.byte		N96   , Cs1
	.byte	W96
@ 077   ----------------------------------------
	.byte		N24   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
@ 078   ----------------------------------------
	.byte	W96
@ 079   ----------------------------------------
	.byte	W96
@ 080   ----------------------------------------
	.byte	W96
@ 081   ----------------------------------------
	.byte	W96
@ 082   ----------------------------------------
	.byte	W96
@ 083   ----------------------------------------
	.byte	W96
@ 084   ----------------------------------------
	.byte	W96
@ 085   ----------------------------------------
	.byte	W96
@ 086   ----------------------------------------
	.byte	W96
@ 087   ----------------------------------------
	.byte	W96
@ 088   ----------------------------------------
	.byte	W96
@ 089   ----------------------------------------
	.byte	W96
@ 090   ----------------------------------------
	.byte	W96
@ 091   ----------------------------------------
	.byte	W96
@ 092   ----------------------------------------
	.byte	W96
@ 093   ----------------------------------------
	.byte	W96
@ 094   ----------------------------------------
	.byte	GOTO
	 .word	mus_trainer_tower_8_B1
	.byte	W06
	.byte	FINE

@**************** Track 9 ****************@

mus_trainer_tower_9:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_trainer_tower_key+0
	.byte		VOICE , 48
	.byte		PAN   , c_v-16
	.byte		VOL   , 76*mus_trainer_tower_mvl/mxv
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
	.byte	W96
@ 010   ----------------------------------------
mus_trainer_tower_9_B1:
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
mus_trainer_tower_9_042:
	.byte		N12   , Gs3 , v127
	.byte		N12   , Ds4
	.byte	W24
	.byte		        Gn3
	.byte		N12   , Cs4
	.byte	W72
	.byte	PEND
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_9_042
	.byte	W96
@ 045   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_9_042
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte	W96
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W96
@ 060   ----------------------------------------
	.byte	W96
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	W96
@ 069   ----------------------------------------
	.byte	W80
	.byte		N08   , Gs3 , v127
	.byte		N08   , Ds4
	.byte	W08
	.byte		        Gs3
	.byte		N08   , Ds4
	.byte	W08
@ 070   ----------------------------------------
	.byte		        Fn3
	.byte		N08   , Cn4
	.byte	W16
	.byte		        Fn3
	.byte		N08   , Cn4
	.byte	W16
	.byte		        Fn3
	.byte		N08   , Cn4
	.byte	W08
	.byte		        Fn3
	.byte		N08   , Cn4
	.byte	W08
	.byte		        Fn3
	.byte		N08   , Cn4
	.byte	W16
	.byte		        Fn3
	.byte		N08   , Cn4
	.byte	W16
	.byte		        Fn3
	.byte		N08   , Cn4
	.byte	W08
	.byte		        Fn3
	.byte		N08   , Cn4
	.byte	W08
@ 071   ----------------------------------------
	.byte		        Fs3
	.byte		N08   , Cs4
	.byte	W16
	.byte		        Fs3
	.byte		N08   , Cs4
	.byte	W16
	.byte		        Fs3
	.byte		N08   , Cs4
	.byte	W08
	.byte		        Fs3
	.byte		N08   , Cs4
	.byte	W08
	.byte		        Fs3
	.byte		N08   , Cs4
	.byte	W16
	.byte		        Fs3
	.byte		N08   , Cs4
	.byte	W16
	.byte		        Fs3
	.byte		N08   , Cs4
	.byte	W08
	.byte		        Fs3
	.byte		N08   , Cs4
	.byte	W08
@ 072   ----------------------------------------
	.byte		        Gn3
	.byte		N08   , Dn4
	.byte	W16
	.byte		        Gn3
	.byte		N08   , Dn4
	.byte	W16
	.byte		        Gn3
	.byte		N08   , Dn4
	.byte	W08
	.byte		        Gn3
	.byte		N08   , Dn4
	.byte	W08
	.byte		        Gn3
	.byte		N08   , Dn4
	.byte	W16
	.byte		        Gn3
	.byte		N08   , Dn4
	.byte	W16
	.byte		        Gn3
	.byte		N08   , Dn4
	.byte	W08
	.byte		        Gn3
	.byte		N08   , Dn4
	.byte	W08
@ 073   ----------------------------------------
	.byte		        Cs4
	.byte		N08   , Gs4
	.byte	W16
	.byte		        Cs4
	.byte		N08   , Gs4
	.byte	W16
	.byte		        Cs4
	.byte		N08   , Gs4
	.byte	W08
	.byte		        Cs4
	.byte		N08   , Gs4
	.byte	W08
	.byte		        Cs4
	.byte		N08   , Gs4
	.byte	W16
	.byte		        Cs4
	.byte		N08   , Gs4
	.byte	W16
	.byte		        Cs4
	.byte		N08   , Gs4
	.byte	W08
	.byte		        Cs4
	.byte		N08   , Gs4
	.byte	W08
@ 074   ----------------------------------------
	.byte	W96
@ 075   ----------------------------------------
	.byte	W96
@ 076   ----------------------------------------
	.byte	W96
@ 077   ----------------------------------------
	.byte	W96
@ 078   ----------------------------------------
	.byte	W96
@ 079   ----------------------------------------
	.byte	W96
@ 080   ----------------------------------------
	.byte	W96
@ 081   ----------------------------------------
	.byte	W96
@ 082   ----------------------------------------
	.byte	W96
@ 083   ----------------------------------------
	.byte	W96
@ 084   ----------------------------------------
	.byte	W96
@ 085   ----------------------------------------
	.byte	W96
@ 086   ----------------------------------------
	.byte	W96
@ 087   ----------------------------------------
	.byte	W96
@ 088   ----------------------------------------
	.byte	W96
@ 089   ----------------------------------------
	.byte	W96
@ 090   ----------------------------------------
	.byte	W96
@ 091   ----------------------------------------
	.byte	W96
@ 092   ----------------------------------------
	.byte	GOTO
	 .word	mus_trainer_tower_9_B1
	.byte	W06
	.byte	FINE

@**************** Track 10 ****************@

mus_trainer_tower_10:
@ 000   ----------------------------------------
	.byte	KEYSH , mus_trainer_tower_key+0
	.byte		VOICE , 0
	.byte		VOL   , 76*mus_trainer_tower_mvl/mxv
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
	.byte	W48
	.byte		N08   , En1 , v127
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte		N24   , An2
	.byte	W08
	.byte		N08   , En1
	.byte	W08
	.byte		N08   
	.byte	W08
@ 006   ----------------------------------------
mus_trainer_tower_10_006:
	.byte		N08   , Cn1 , v127
	.byte		N24   , An2
	.byte	W16
	.byte		N08   , Cn1
	.byte	W08
	.byte		        En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		        Cn1
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		        Cn1
	.byte	W08
	.byte	PEND
@ 007   ----------------------------------------
mus_trainer_tower_10_007:
	.byte		N08   , Cn1 , v127
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		        En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		        Cn1
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		        Cn1
	.byte	W08
	.byte	PEND
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_10_007
mus_trainer_tower_10_008:
	.byte		N08   , Cn1 , v127
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		        En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		        Cn1
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W08
	.byte		        En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W08
	.byte		        Cn1
	.byte		N08   , En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W08
	.byte	PEND
@ 009   ----------------------------------------
mus_trainer_tower_10_B1:
	.byte		N08   , Cn1 , v127
	.byte		N96   , An2
	.byte	W16
	.byte		N08   , Cn1
	.byte	W08
	.byte		        En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		        Cn1
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		        Cn1
	.byte	W08
	.byte	PEND
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_008
	.byte	PATT
	 .word	mus_trainer_tower_10_B1
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_008
mus_trainer_tower_10_010:
	.byte		N08   , Cn1 , v127
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		        En1
	.byte		N24   , An2
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		        Cn1
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		        Cn1
	.byte	W08
	.byte	PEND
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_010
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_010
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_006
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_006
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
	.byte	PATT
	 .word	mus_trainer_tower_10_007
mus_trainer_tower_10_011:
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N16   
	.byte		N16   , An2
	.byte	W16
	.byte		N08   , Cn1
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N16   
	.byte		N16   , An2
	.byte	W16
	.byte		        Cn1
	.byte	W16
	.byte		N08   
	.byte		N16   , An2
	.byte	W08
	.byte		N08   , Cn1
	.byte	W08
	.byte	PEND
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_10_011
	.byte	PATT
	 .word	mus_trainer_tower_10_011
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N16   
	.byte		N16   , An2
	.byte	W16
	.byte		N08   , Cn1
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N16   
	.byte		N16   , An2
	.byte	W16
	.byte		        Cn1
	.byte	W16
	.byte		N08   
	.byte		N16   , An2
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W08
	.byte		        Cn1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W08
@ 013   ----------------------------------------
mus_trainer_tower_10_013:
	.byte		N16   , Cn1 , v127
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		N16   , Cn1
	.byte		N16   , An2
	.byte	W16
	.byte		N08   , Cn1
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N16   
	.byte		N16   , An2
	.byte	W16
	.byte		        Cn1
	.byte	W16
	.byte		N08   
	.byte		N16   , An2
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W08
	.byte		        Cn1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W08
	.byte	PEND
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_10_013
	.byte	PATT
	 .word	mus_trainer_tower_10_013
	.byte		N16   , Cn1 , v127
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		N16   , Cn1
	.byte		N16   , An2
	.byte	W16
	.byte		N08   , Cn1
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N16   
	.byte		N16   , An2
	.byte	W16
	.byte		        Cn1
	.byte	W16
	.byte		N08   
	.byte		N16   , An2
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W08
	.byte		TIE   , Cn1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W08
@ 015   ----------------------------------------
	.byte		N96   , An2
	.byte	W96
@ 016   ----------------------------------------
	.byte		EOT   , Cn1
	.byte		N24   
	.byte	W24
	.byte		N72   
	.byte	W14
	.byte		N16   , An2
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W10
	.byte		        En1
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
@ 017   ----------------------------------------
	.byte		N16   , Cn1
	.byte		N96   , An2
	.byte	W16
	.byte		N24   , Cn1
	.byte	W08
	.byte		N08   , En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		N16   , Cn1
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N24   
	.byte	W08
	.byte		N08   , En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		        Cn1
	.byte	W08
@ 018   ----------------------------------------
mus_trainer_tower_10_018:
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N24   
	.byte	W08
	.byte		N08   , En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		N16   , Cn1
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N24   
	.byte	W08
	.byte		N08   , En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		        Cn1
	.byte	W08
	.byte	PEND
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_trainer_tower_10_018
	.byte	PATT
	 .word	mus_trainer_tower_10_018
	.byte	PATT
	 .word	mus_trainer_tower_10_018
	.byte	PATT
	 .word	mus_trainer_tower_10_018
	.byte	PATT
	 .word	mus_trainer_tower_10_018
	.byte	PATT
	 .word	mus_trainer_tower_10_018
	.byte	PATT
	 .word	mus_trainer_tower_10_018
	.byte	PATT
	 .word	mus_trainer_tower_10_018
	.byte	PATT
	 .word	mus_trainer_tower_10_018
	.byte	PATT
	 .word	mus_trainer_tower_10_018
	.byte	PATT
	 .word	mus_trainer_tower_10_018
	.byte	PATT
	 .word	mus_trainer_tower_10_018
	.byte	PATT
	 .word	mus_trainer_tower_10_018
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N24   
	.byte	W08
	.byte		N08   , En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W16
	.byte		N16   , Cn1
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N24   
	.byte	W08
	.byte		N08   , En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W08
	.byte		        En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W08
	.byte		        Cn1
	.byte		N08   , En1
	.byte		N08   , Fn3
	.byte		N08   , Fs3
	.byte	W08
@ 020   ----------------------------------------
	.byte	GOTO
	 .word	mus_trainer_tower_10_B1
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

mus_trainer_tower:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_trainer_tower_pri	@ Priority
	.byte	mus_trainer_tower_rev	@ Reverb.

	.word	mus_trainer_tower_grp

	.word	mus_trainer_tower_1
	.word	mus_trainer_tower_2
	.word	mus_trainer_tower_3
	.word	mus_trainer_tower_4
	.word	mus_trainer_tower_5
	.word	mus_trainer_tower_6
	.word	mus_trainer_tower_7
	.word	mus_trainer_tower_8
	.word	mus_trainer_tower_9
	.word	mus_trainer_tower_10

	.end
