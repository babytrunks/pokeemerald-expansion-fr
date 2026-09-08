	.include "MPlayDef.s"

	.equ	mus_vs_arven_grp, voicegroup_vs_arven
	.equ	mus_vs_arven_pri, 0
	.equ	mus_vs_arven_rev, reverb_set+50
	.equ	mus_vs_arven_mvl, 90
	.equ	mus_vs_arven_key, 0
	.equ	mus_vs_arven_tbs, 1
	.equ	mus_vs_arven_exg, 0
	.equ	mus_vs_arven_cmp, 1

	.section .rodata
	.global	mus_vs_arven
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

mus_vs_arven_1:
	.byte	KEYSH , mus_vs_arven_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 300*mus_vs_arven_tbs/2
	.byte		VOICE , 56
	.byte		VOL   , 90*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BENDR , 12
	.byte		N04   , Fn4 , v096
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        An3 , v088
	.byte	W04
	.byte		        Fn3 , v076
	.byte	W04
	.byte		        Ds3 , v068
	.byte	W04
	.byte		        An2 , v060
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        An2 , v064
	.byte	W04
	.byte		        As2 , v068
	.byte	W04
	.byte		        Cn3 , v072
	.byte	W04
	.byte		        Dn3 , v076
	.byte	W04
	.byte		        Ds3 , v080
	.byte	W04
	.byte		        Fn3 , v084
	.byte	W04
	.byte		        Gn3 , v088
	.byte	W04
	.byte		        An3 , v092
	.byte	W04
	.byte		        As3 , v096
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Dn4 , v100
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
@ 001   ----------------------------------------
	.byte	TEMPO , 150*mus_vs_arven_tbs/2
	.byte		N60   , As4 
	.byte	W60
	.byte		N12   , As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
@ 002   ----------------------------------------
mus_vs_arven_1_002:
	.byte		N12   , Fn4 , v100
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N04   , Ds5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N18   , An4 
	.byte	W18
	.byte	PEND
@ 003   ----------------------------------------
mus_vs_arven_1_003:
	.byte		N60   , As4 , v100
	.byte	W60
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte	PEND
@ 004   ----------------------------------------
mus_vs_arven_1_004:
	.byte		N12   , Ds4 , v100
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N04   , Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W04
	.byte		N02   , Bn3 , v092
	.byte	W02
	.byte		        As3 , v084
	.byte	W02
	.byte		        An3 , v076
	.byte	W02
	.byte		        Gn3 , v068
	.byte	W02
	.byte		        Fn3 , v060
	.byte	W02
	.byte		        Ds3 , v052
	.byte	W02
	.byte		        Dn3 , v044
	.byte	W08
	.byte	PEND
@ 005   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 60*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , An3 , v100
	.byte	W06
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W06
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		N06   , Ds4 
	.byte	W06
	.byte		VOL   , 90*mus_vs_arven_mvl/mxv
	.byte		TIE   , Gs4 
	.byte	W06
	.byte		VOL   , 90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        88*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        85*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        82*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        77*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        71*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        64*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        57*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        47*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        44*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        42*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        43*mus_vs_arven_mvl/mxv
	.byte	W14
	.byte		        44*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        45*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        46*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        47*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        48*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        50*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        56*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        58*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        60*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        62*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        65*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        67*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        69*mus_vs_arven_mvl/mxv
	.byte	W02
@ 006   ----------------------------------------
	.byte		        71*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        74*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        76*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        78*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        80*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        82*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        84*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        88*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        91*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        94*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        95*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        96*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        98*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        99*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte	W10
	.byte		EOT   
	.byte		N18   , An4 
	.byte	W06
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W06
	.byte		        99*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        98*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        96*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte		N02   , Gs4 
	.byte	W02
	.byte		VOL   , 79*mus_vs_arven_mvl/mxv
	.byte		N02   , Gn4 
	.byte	W02
	.byte		VOL   , 59*mus_vs_arven_mvl/mxv
	.byte		N02   , Fn4 
	.byte	W02
	.byte		VOL   , 26*mus_vs_arven_mvl/mxv
	.byte	W24
@ 007   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , An3 
	.byte	W06
	.byte		VOL   , 60*mus_vs_arven_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W06
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		N06   , Ds4 
	.byte	W06
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		N06   , Fn4 
	.byte	W06
	.byte		VOL   , 90*mus_vs_arven_mvl/mxv
	.byte		TIE   , An4 
	.byte	W04
	.byte		VOL   , 85*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        82*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        77*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        71*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        64*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        57*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        47*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        44*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        42*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        43*mus_vs_arven_mvl/mxv
	.byte	W10
	.byte		        44*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        45*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        46*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        47*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        49*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        50*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        52*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        57*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        59*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        61*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        63*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        66*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        68*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        70*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        73*mus_vs_arven_mvl/mxv
	.byte	W02
@ 008   ----------------------------------------
mus_vs_arven_1_008:
	.byte		VOL   , 75*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        78*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        80*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        82*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        84*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        88*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        92*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        95*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        96*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        98*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        99*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte	W14
	.byte	PEND
	.byte		EOT   , An4 
	.byte		VOICE , 56
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Gs4 , v100
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Cn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 21
	.byte		VOL   , 110*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
mus_vs_arven_1_B1:
@ 009   ----------------------------------------
	.byte		N24   , Cs4 , v100
	.byte	W36
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
@ 010   ----------------------------------------
	.byte		N18   , Ds4 
	.byte	W18
	.byte		N02   , En4 
	.byte	W02
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N24   , As3 
	.byte	W36
	.byte		        Cn4 
	.byte	W24
@ 011   ----------------------------------------
	.byte		N02   
	.byte	W02
	.byte		N16   , Cs4 
	.byte	W22
	.byte		N06   , Gs3 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W18
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W12
@ 012   ----------------------------------------
	.byte		N18   , Fn4 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N30   , Ds4 
	.byte	W36
	.byte		N24   
	.byte	W24
@ 013   ----------------------------------------
	.byte		        Cs4 
	.byte	W36
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
@ 014   ----------------------------------------
	.byte		        Ds4 
	.byte	W18
	.byte		        Fn4 
	.byte	W18
	.byte		N18   , As4 
	.byte	W24
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
@ 015   ----------------------------------------
	.byte		N02   , Cn4 
	.byte	W02
	.byte		N22   , Cs4 
	.byte	W22
	.byte		N06   , An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		N18   , Cs4 
	.byte	W18
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W12
@ 016   ----------------------------------------
	.byte		N12   , Ds4 
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N36   , Cs4 
	.byte	W36
	.byte		N12   , Cn4 
	.byte	W12
	.byte		VOICE , 73
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
@ 017   ----------------------------------------
	.byte		N44   , Cs5 
	.byte	W18
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        83*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        79*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        76*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        72*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        69*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        65*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        62*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        58*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N12   , Cn5 
	.byte	W12
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		N24   , Cs5 
	.byte	W18
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N56   , Ds5 
	.byte	W12
@ 018   ----------------------------------------
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W18
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        83*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        79*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        76*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        72*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        69*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        65*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        62*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        58*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N24   , Cs5 
	.byte	W18
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N24   , Ds5 
	.byte	W18
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
@ 019   ----------------------------------------
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N44   , Fn5 
	.byte	W18
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        83*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        79*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        76*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        72*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        69*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        65*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        62*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        58*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N44   , Ds5 
	.byte	W18
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        83*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        79*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        76*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        72*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        69*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        65*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        62*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        58*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
@ 020   ----------------------------------------
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N44   , Dn5 
	.byte	W18
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        83*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        79*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        76*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        72*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        69*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        65*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        62*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        58*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N44   , As4 
	.byte	W18
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        83*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        79*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        76*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        72*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        69*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        65*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        62*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        58*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
@ 021   ----------------------------------------
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N44   , Fs5 
	.byte	W18
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        83*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        79*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        76*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        72*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        69*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        65*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        62*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        58*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N12   , Fn5 
	.byte	W12
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		N24   , Fs5 
	.byte	W18
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N06   , Fn5 
	.byte	W06
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		N06   , En5 
	.byte	W06
@ 022   ----------------------------------------
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		N44   , Ds5 
	.byte	W18
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        83*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        79*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        76*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        72*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        69*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        65*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        62*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        58*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N32   , Cn5 
	.byte	W18
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        83*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        79*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        76*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        72*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N06   , Ds5 
	.byte	W06
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		N06   , En5 
	.byte	W06
@ 023   ----------------------------------------
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		N44   , Fn5 
	.byte	W18
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        83*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        79*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        76*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        72*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        69*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        65*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        62*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        58*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N12   , Ds5 
	.byte	W12
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		N24   , Fn5 
	.byte	W18
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N12   , Ds5 
	.byte	W12
@ 024   ----------------------------------------
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		N02   , En5 , v080
	.byte	W02
	.byte		N60   , Fn5 , v100
	.byte	W32
	.byte	W02
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        95*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        85*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        80*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        75*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        70*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        65*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        60*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        50*mus_vs_arven_mvl/mxv
	.byte	W01
	.byte		        48*mus_vs_arven_mvl/mxv
	.byte	W09
	.byte		VOICE , 60
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , As3 , v092
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		N06   , Cs4 , v100
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
@ 025   ----------------------------------------
	.byte		N44   , Cs4 
	.byte	W44
	.byte		N02   , Ds4 , v092
	.byte	W02
	.byte		        Cs4 
	.byte	W02
	.byte		N24   , Cn4 , v100
	.byte	W24
	.byte		        Cs4 
	.byte	W24
@ 026   ----------------------------------------
	.byte		N44   , Ds4 
	.byte	W44
	.byte		N02   , Fn4 , v092
	.byte	W02
	.byte		        Ds4 
	.byte	W02
	.byte		N24   , Cs4 , v100
	.byte	W24
	.byte		        Ds4 
	.byte	W24
@ 027   ----------------------------------------
	.byte		N48   , Fn4 
	.byte	W48
	.byte		N18   , Ds4 
	.byte	W18
	.byte		        Fn4 
	.byte	W18
	.byte		N12   , Gs4 
	.byte	W12
@ 028   ----------------------------------------
	.byte		N18   , As4 
	.byte	W18
	.byte		        Fn4 
	.byte	W18
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N32   , Dn4 
	.byte	W32
	.byte		N02   , Ds4 , v092
	.byte	W02
	.byte		        Fn4 
	.byte	W02
@ 029   ----------------------------------------
	.byte		N44   , Fs4 , v100
	.byte	W44
	.byte	W02
	.byte		N02   , Gn4 , v092
	.byte	W02
	.byte		N12   , Gs4 , v100
	.byte	W12
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N54   , En4 
	.byte	W06
@ 030   ----------------------------------------
	.byte	W48
	.byte		N32   , Cn4 
	.byte	W36
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
@ 031   ----------------------------------------
	.byte		N48   , Fn4 
	.byte	W48
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N42   , Fn4 
	.byte	W42
@ 032   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W18
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W18
	.byte		N06   , Gs3 
	.byte	W06
	.byte		VOICE , 48
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
@ 033   ----------------------------------------
	.byte		N36   , Gn4 
	.byte	W36
	.byte		        Fn4 
	.byte	W36
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N48   , En4 
	.byte	W12
@ 034   ----------------------------------------
mus_vs_arven_1_034:
	.byte	W36
	.byte		N36   , Cn4 , v100
	.byte	W42
	.byte		N06   
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte	PEND
@ 035   ----------------------------------------
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W24
	.byte		        As4 
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N48   , Gn4 
	.byte	W12
@ 036   ----------------------------------------
	.byte	W36
	.byte		N36   , Cn5 
	.byte	W42
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
@ 037   ----------------------------------------
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W18
	.byte		N36   , Fn4 
	.byte	W36
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N48   , En4 
	.byte	W12
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_1_034
@ 039   ----------------------------------------
	.byte		N12   , Gn4 , v100
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W24
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N60   , En4 
	.byte	W12
@ 040   ----------------------------------------
	.byte	W48
	.byte		VOICE , 56
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N08   , As3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
@ 041   ----------------------------------------
	.byte		N90   , Gn4 
	.byte	W96
@ 042   ----------------------------------------
	.byte		N32   , Fn4 
	.byte	W36
	.byte		N09   , Gn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As3 , v092
	.byte	W12
	.byte		        Fn3 , v076
	.byte	W12
	.byte		        Dn3 , v060
	.byte	W12
@ 043   ----------------------------------------
	.byte		N03   , Dn4 , v072
	.byte	W03
	.byte		N09   , Fn4 , v100
	.byte	W32
	.byte	W01
	.byte		N09   
	.byte	W36
	.byte		N09   
	.byte	W24
@ 044   ----------------------------------------
	.byte		N04   , En4 
	.byte	W06
	.byte		        En4 , v080
	.byte	W18
	.byte		N66   , As4 , v100
	.byte	W72
@ 045   ----------------------------------------
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N02   , Bn4 , v072
	.byte	W02
	.byte		N76   , Cn5 , v100
	.byte	W80
	.byte	W02
@ 046   ----------------------------------------
	.byte		N08   , Fn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
@ 047   ----------------------------------------
	.byte		N09   , Fn4 
	.byte	W36
	.byte		N09   
	.byte	W36
	.byte		N09   
	.byte	W24
@ 048   ----------------------------------------
	.byte		N12   , Fn4 , v092
	.byte	W18
	.byte		        En4 , v072
	.byte	W18
	.byte		N54   , Cn5 , v060
	.byte	W60
@ 049   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N84   , Cn4 , v100
	.byte	W96
@ 050   ----------------------------------------
	.byte		N48   , Dn4 
	.byte	W96
@ 051   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N48   , Fn4 
	.byte	W06
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        99*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        98*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        96*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        95*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        94*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        92*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        91*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        89*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        88*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        87*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        85*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        84*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        83*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        82*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        81*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        80*mus_vs_arven_mvl/mxv
	.byte	W48
@ 052   ----------------------------------------
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N32   , Fn4 , v092
	.byte	W06
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        99*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        98*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        96*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        95*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        94*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        92*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        91*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        89*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        88*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        87*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N36   , En4 , v080
	.byte	W06
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        99*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        98*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        96*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        95*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        94*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        92*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        91*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        89*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        88*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        87*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        85*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        84*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        83*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        82*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        81*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        80*mus_vs_arven_mvl/mxv
	.byte	W12
@ 053   ----------------------------------------
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte	W12
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte		VOL   , 43*mus_vs_arven_mvl/mxv
	.byte		N03   , Gs3 , v100
	.byte	W12
	.byte		VOL   , 54*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 66*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 77*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 88*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
@ 054   ----------------------------------------
	.byte	W12
	.byte		VOL   , 66*mus_vs_arven_mvl/mxv
	.byte		N03   , As3 
	.byte	W12
	.byte		VOL   , 77*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 88*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
@ 055   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Fn3 
	.byte	W96
@ 056   ----------------------------------------
	.byte	W48
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
@ 057   ----------------------------------------
	.byte		N48   , Gn4 
	.byte	W48
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
@ 058   ----------------------------------------
	.byte		N48   , Gn4 
	.byte	W96
@ 059   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 90*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N60   , As4 
	.byte	W60
	.byte		N12   , As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_1_002
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_1_003
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_1_004
@ 063   ----------------------------------------
	.byte		VOICE , 56
	.byte		PAN   , c_v+0
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		N06   , An3 , v100
	.byte	W06
	.byte		VOL   , 60*mus_vs_arven_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W06
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		N06   , Ds4 
	.byte	W06
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		N06   , Fn4 
	.byte	W06
	.byte		VOL   , 90*mus_vs_arven_mvl/mxv
	.byte		TIE   , An4 
	.byte	W04
	.byte		VOL   , 85*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        82*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        77*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        71*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        64*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        57*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        47*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        44*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        42*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        43*mus_vs_arven_mvl/mxv
	.byte	W10
	.byte		        44*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        45*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        46*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        47*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        49*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        50*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        52*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        57*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        59*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        61*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        63*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        66*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        68*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        70*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        73*mus_vs_arven_mvl/mxv
	.byte	W02
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_1_008
	.byte		EOT   , An4 
	.byte		VOICE , 56
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Gs4 , v100
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Cn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 21
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte	GOTO
	 .word	mus_vs_arven_1_B1
mus_vs_arven_1_B2:
@ 065   ----------------------------------------
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

mus_vs_arven_2:
	.byte	KEYSH , mus_vs_arven_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BENDR , 12
	.byte		N04   , Ds4 , v096
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Fn3 , v088
	.byte	W04
	.byte		        Ds3 , v076
	.byte	W04
	.byte		        Cn3 , v068
	.byte	W04
	.byte		        Fn2 , v060
	.byte	W04
	.byte		        Gn1 
	.byte	W04
	.byte		        An1 
	.byte	W04
	.byte		        As1 
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Ds2 , v064
	.byte	W04
	.byte		        Fn2 , v068
	.byte	W04
	.byte		        Gn2 , v072
	.byte	W04
	.byte		        An2 , v076
	.byte	W04
	.byte		        As2 , v080
	.byte	W04
	.byte		        Cn3 , v084
	.byte	W04
	.byte		        Dn3 , v088
	.byte	W04
	.byte		        Ds3 , v092
	.byte	W04
	.byte		        Fn3 , v096
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        An3 , v100
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
@ 001   ----------------------------------------
	.byte		N60   , Fn4 
	.byte	W60
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
@ 002   ----------------------------------------
mus_vs_arven_2_002:
	.byte		N12   , Cn4 , v100
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N04   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N18   , Fn4 
	.byte	W18
	.byte	PEND
@ 003   ----------------------------------------
mus_vs_arven_2_003:
	.byte		N60   , Fn4 , v100
	.byte	W60
	.byte		N12   , As4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte	PEND
@ 004   ----------------------------------------
mus_vs_arven_2_004:
	.byte		N12   , Cs4 , v100
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N04   , Gs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W04
	.byte		N02   , Gs3 , v092
	.byte	W02
	.byte		        Gn3 , v084
	.byte	W02
	.byte		        Fn3 , v076
	.byte	W02
	.byte		        Ds3 , v068
	.byte	W02
	.byte		        Dn3 , v060
	.byte	W02
	.byte		        Cn3 , v052
	.byte	W02
	.byte		        As2 , v044
	.byte	W08
	.byte	PEND
@ 005   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 60*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Fn3 , v100
	.byte	W06
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		N06   , An3 
	.byte	W06
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W06
	.byte		VOL   , 90*mus_vs_arven_mvl/mxv
	.byte		TIE   , Ds4 
	.byte	W06
	.byte		VOL   , 90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        88*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        85*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        82*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        77*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        71*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        64*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        57*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        47*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        44*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        42*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        43*mus_vs_arven_mvl/mxv
	.byte	W14
	.byte		        44*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        45*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        46*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        47*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        48*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        50*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        56*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        58*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        60*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        62*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        65*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        67*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        69*mus_vs_arven_mvl/mxv
	.byte	W02
@ 006   ----------------------------------------
	.byte		        71*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        74*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        76*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        78*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        80*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        82*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        84*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        88*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        91*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        94*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        95*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        96*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        98*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        99*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte	W10
	.byte		EOT   
	.byte		N18   , Fn4 
	.byte	W06
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W06
	.byte		        99*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        98*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        96*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte		N02   , En4 
	.byte	W02
	.byte		VOL   , 79*mus_vs_arven_mvl/mxv
	.byte		N02   , Ds4 
	.byte	W02
	.byte		VOL   , 59*mus_vs_arven_mvl/mxv
	.byte		N02   , Cs4 
	.byte	W02
	.byte		VOL   , 26*mus_vs_arven_mvl/mxv
	.byte	W24
@ 007   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Fn3 
	.byte	W06
	.byte		VOL   , 60*mus_vs_arven_mvl/mxv
	.byte		N06   , An3 
	.byte	W06
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W06
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		N06   , Ds4 
	.byte	W06
	.byte		VOL   , 90*mus_vs_arven_mvl/mxv
	.byte		TIE   , Fn4 
	.byte	W04
	.byte		VOL   , 85*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        82*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        77*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        71*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        64*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        57*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        47*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        44*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        42*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        43*mus_vs_arven_mvl/mxv
	.byte	W10
	.byte		        44*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        45*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        46*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        47*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        49*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        50*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        52*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        57*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        59*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        61*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        63*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        66*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        68*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        70*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        73*mus_vs_arven_mvl/mxv
	.byte	W02
@ 008   ----------------------------------------
mus_vs_arven_2_008:
	.byte		VOL   , 75*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        78*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        80*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        82*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        84*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        88*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        92*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        95*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        96*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        98*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        99*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte	W14
	.byte	PEND
	.byte		EOT   , Fn4 
	.byte		VOICE , 56
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Fn4 , v100
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        An4 
	.byte	W06
	.byte		N03   
	.byte	W18
mus_vs_arven_2_B1:
@ 009   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		N12   , Cs4 , v100
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N36   , Fn3 
	.byte	W36
	.byte		N24   , Gs3 
	.byte	W24
@ 010   ----------------------------------------
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N36   , As3 
	.byte	W60
@ 011   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N18   , Cs3 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N36   , Ds3 
	.byte	W60
@ 012   ----------------------------------------
	.byte		N18   , Cs3 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N36   , Cn3 
	.byte	W36
	.byte		N24   , Fn3 
	.byte	W24
@ 013   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
@ 014   ----------------------------------------
	.byte		        Cs4 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W60
@ 015   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N18   , En3 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Ds3 
	.byte	W12
@ 016   ----------------------------------------
	.byte		        Fs3 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N60   , Fn3 
	.byte	W60
@ 017   ----------------------------------------
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
@ 018   ----------------------------------------
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
@ 019   ----------------------------------------
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
@ 020   ----------------------------------------
mus_vs_arven_2_020:
	.byte		N12   , As1 , v100
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N06   , As1 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte	PEND
@ 021   ----------------------------------------
mus_vs_arven_2_021:
	.byte		N12   , Fs1 , v100
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte	PEND
@ 022   ----------------------------------------
mus_vs_arven_2_022:
	.byte		N12   , Cn1 , v100
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	PEND
@ 023   ----------------------------------------
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W30
	.byte		N06   , Fs3 
	.byte	W06
@ 024   ----------------------------------------
	.byte		N12   , As1 
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn4 
	.byte	W09
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte	W03
	.byte		N16   , As4 
	.byte	W07
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        76*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        71*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        58*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        37*mus_vs_arven_mvl/mxv
	.byte	W15
@ 025   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
@ 026   ----------------------------------------
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
@ 027   ----------------------------------------
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_2_020
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_2_021
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_2_022
@ 031   ----------------------------------------
	.byte		N12   , Fn1 , v100
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
@ 032   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , Ds3 
	.byte	W18
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , Ds3 
	.byte	W18
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
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
	.byte		VOICE , 56
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N48   , Dn4 , v092
	.byte	W06
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        99*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        98*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        96*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        95*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        94*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        92*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        91*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        89*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        88*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        87*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        85*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        84*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        83*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        82*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        81*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        80*mus_vs_arven_mvl/mxv
	.byte	W48
@ 052   ----------------------------------------
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N32   , Dn4 , v084
	.byte	W06
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        99*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        98*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        96*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        95*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        94*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        92*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        91*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        89*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        88*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        87*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte		N36   , Bn3 , v072
	.byte	W06
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        99*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        98*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        97*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        96*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        95*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        94*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        93*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        92*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        91*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        90*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        89*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        88*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        87*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        86*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        85*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        84*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        83*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        82*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        81*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        80*mus_vs_arven_mvl/mxv
	.byte	W12
@ 053   ----------------------------------------
	.byte		        100*mus_vs_arven_mvl/mxv
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W48
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , As3 , v100
	.byte	W24
	.byte		        Cs4 
	.byte	W24
@ 057   ----------------------------------------
	.byte		N48   , Cn4 
	.byte	W48
	.byte		N24   , As3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
@ 058   ----------------------------------------
	.byte		N48   , Cn4 
	.byte	W96
@ 059   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N60   , Fn4 
	.byte	W60
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_2_002
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_2_003
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_2_004
@ 063   ----------------------------------------
	.byte		VOICE , 56
	.byte		PAN   , c_v+0
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		N06   , Fn3 , v100
	.byte	W06
	.byte		VOL   , 60*mus_vs_arven_mvl/mxv
	.byte		N06   , An3 
	.byte	W06
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W06
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		N06   , Ds4 
	.byte	W06
	.byte		VOL   , 90*mus_vs_arven_mvl/mxv
	.byte		TIE   , Fn4 
	.byte	W04
	.byte		VOL   , 85*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        82*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        77*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        71*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        64*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        57*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        47*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        44*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        42*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        43*mus_vs_arven_mvl/mxv
	.byte	W10
	.byte		        44*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        45*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        46*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        47*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        49*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        50*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        52*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        55*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        57*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        59*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        61*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        63*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        66*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        68*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        70*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        73*mus_vs_arven_mvl/mxv
	.byte	W02
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_2_008
	.byte		EOT   , Fn4 
	.byte		VOICE , 56
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Fn4 , v100
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        An4 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte	GOTO
	 .word	mus_vs_arven_2_B1
mus_vs_arven_2_B2:
@ 065   ----------------------------------------
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

mus_vs_arven_3:
	.byte	KEYSH , mus_vs_arven_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 60*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BENDR , 12
	.byte		N06   , Fn3 , v100
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        Gs3 
	.byte	W12
	.byte		N06   
	.byte	W36
@ 001   ----------------------------------------
mus_vs_arven_3_001:
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , Gs3 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte	PEND
@ 002   ----------------------------------------
mus_vs_arven_3_002:
	.byte		VOICE , 24
	.byte		VOL   , 30*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Ds3 , v100
	.byte	W24
	.byte		N12   
	.byte	W18
	.byte		N24   , Fn3 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
mus_vs_arven_3_003:
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , Gs3 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte	PEND
@ 004   ----------------------------------------
mus_vs_arven_3_004:
	.byte		VOICE , 24
	.byte		VOL   , 30*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Ds3 , v100
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N18   , Cn3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 60*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-12
	.byte		N06   , Ds4 
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
	.byte		        Cn4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		N06   
	.byte	W18
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
mus_vs_arven_3_008:
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Fn4 , v080
	.byte	W12
	.byte		        Fn4 , v088
	.byte	W12
	.byte		        Fn4 , v092
	.byte	W12
	.byte		        Ds4 , v100
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Fn4 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte	PEND
mus_vs_arven_3_B1:
@ 009   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , As4 , v100
	.byte	W02
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte	W08
	.byte		        54*mus_vs_arven_mvl/mxv
	.byte	W08
	.byte		        53*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        52*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        50*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        46*mus_vs_arven_mvl/mxv
	.byte		N02   , An4 
	.byte	W02
	.byte		VOL   , 42*mus_vs_arven_mvl/mxv
	.byte		N02   , Gs4 
	.byte	W02
	.byte		VOL   , 35*mus_vs_arven_mvl/mxv
	.byte		N02   , Gn4 
	.byte	W02
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		N02   , Fs4 
	.byte	W02
	.byte		VOL   , 12*mus_vs_arven_mvl/mxv
	.byte		N02   , Fn4 
	.byte	W02
	.byte		VOL   , 0*mus_vs_arven_mvl/mxv
	.byte	W60
	.byte	W02
@ 010   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 63*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N18   , Ds4 
	.byte	W18
	.byte		        Fn4 
	.byte	W18
	.byte		N06   , As4 
	.byte	W24
	.byte		        Fn4 
	.byte	W36
@ 011   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N18   , Cs2 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N36   , Ds2 
	.byte	W48
	.byte		VOICE , 56
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N06   , As4 
	.byte	W12
@ 012   ----------------------------------------
	.byte		        Cs5 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		N30   , Cn5 
	.byte	W02
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte	W08
	.byte		        54*mus_vs_arven_mvl/mxv
	.byte	W08
	.byte		        53*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        52*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        50*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        46*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        42*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        35*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        25*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        12*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        0*mus_vs_arven_mvl/mxv
	.byte	W14
	.byte		        56*mus_vs_arven_mvl/mxv
	.byte		N06   , Cs5 
	.byte	W12
@ 013   ----------------------------------------
	.byte		        As4 
	.byte	W36
	.byte		        Cs4 
	.byte	W12
	.byte		        As3 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		        Cs4 
	.byte	W12
@ 014   ----------------------------------------
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		N20   
	.byte	W02
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        54*mus_vs_arven_mvl/mxv
	.byte	W08
	.byte		        53*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        52*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        50*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        46*mus_vs_arven_mvl/mxv
	.byte		N02   , En4 
	.byte	W02
	.byte		VOL   , 42*mus_vs_arven_mvl/mxv
	.byte		N02   , Ds4 
	.byte	W02
	.byte		VOL   , 35*mus_vs_arven_mvl/mxv
	.byte		N02   , Dn4 
	.byte	W02
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		N02   , Cs4 
	.byte	W02
	.byte		VOL   , 12*mus_vs_arven_mvl/mxv
	.byte		N02   , Cn4 
	.byte	W02
	.byte		VOL   , 0*mus_vs_arven_mvl/mxv
	.byte	W14
	.byte		        56*mus_vs_arven_mvl/mxv
	.byte	W16
@ 015   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N18   , En2 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N24   , Fs2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cs2 
	.byte	W12
@ 016   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-12
	.byte		N04   , Cs4 
	.byte	W18
	.byte		N04   
	.byte	W18
	.byte		N24   
	.byte	W18
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        49*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        39*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        26*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        14*mus_vs_arven_mvl/mxv
	.byte	W10
	.byte		VOICE , 60
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-12
	.byte		N24   , Cn4 
	.byte	W24
@ 017   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N24   , Fs2 
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
@ 018   ----------------------------------------
mus_vs_arven_3_018:
	.byte	W12
	.byte		N24   , Fs2 , v100
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 019   ----------------------------------------
mus_vs_arven_3_019:
	.byte	W12
	.byte		N24   , Fn2 , v100
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 020   ----------------------------------------
	.byte	W12
	.byte		N24   , Gs2 
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_3_018
@ 022   ----------------------------------------
	.byte	W12
	.byte		N24   , En3 , v100
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_3_019
@ 024   ----------------------------------------
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N06   , As3 , v100
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        As3 
	.byte	W09
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte	W03
	.byte		N16   , Fn4 
	.byte	W07
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        76*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        71*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        58*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        37*mus_vs_arven_mvl/mxv
	.byte	W15
@ 025   ----------------------------------------
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 45*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 026   ----------------------------------------
	.byte	W12
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Fs2 
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
@ 027   ----------------------------------------
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 45*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 028   ----------------------------------------
	.byte	W12
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Gs2 
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
@ 029   ----------------------------------------
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 45*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , As4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
@ 030   ----------------------------------------
	.byte	W12
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , En3 
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
@ 031   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 40*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		VOICE , 56
	.byte		PAN   , c_v+8
	.byte		VOL   , 60*mus_vs_arven_mvl/mxv
	.byte		N02   , Gs1 
	.byte	W02
	.byte		        Cn2 
	.byte	W02
	.byte		        Ds2 
	.byte	W02
	.byte		        Fn2 
	.byte	W02
	.byte		        Gs2 
	.byte	W02
	.byte		        Cn3 
	.byte	W02
	.byte		        Ds3 
	.byte	W02
	.byte		        Fn3 
	.byte	W02
	.byte		        Gs3 
	.byte	W02
	.byte		        Cn4 
	.byte	W02
	.byte		        Ds4 
	.byte	W02
	.byte		        Fn4 
	.byte	W02
	.byte		        Gs4 
	.byte	W24
@ 032   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , An2 
	.byte	W18
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , An2 
	.byte	W18
	.byte		N06   , Cn3 
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
@ 033   ----------------------------------------
	.byte	W12
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N36   , Gn3 
	.byte	W48
	.byte		        Fn3 
	.byte	W36
@ 034   ----------------------------------------
mus_vs_arven_3_034:
	.byte	W12
	.byte		N36   , En3 , v100
	.byte	W36
	.byte		N24   , Cn3 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte	PEND
@ 035   ----------------------------------------
mus_vs_arven_3_035:
	.byte	W12
	.byte		N36   , Gn3 , v100
	.byte	W48
	.byte		        Fn3 
	.byte	W36
	.byte	PEND
@ 036   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_3_034
@ 037   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_3_035
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_3_034
@ 039   ----------------------------------------
	.byte		N48   , Gn3 , v100
	.byte	W48
	.byte		        Fn3 
	.byte	W48
@ 040   ----------------------------------------
	.byte		        En3 
	.byte	W48
	.byte		N24   , Cn3 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
@ 041   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 60*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N96   , Gn4 
	.byte	W96
@ 042   ----------------------------------------
mus_vs_arven_3_042:
	.byte		N24   , Fn4 , v100
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	PEND
@ 043   ----------------------------------------
mus_vs_arven_3_043:
	.byte		N12   , Fn4 , v100
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
@ 044   ----------------------------------------
	.byte		N06   , En4 
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N60   , As4 
	.byte	W72
@ 045   ----------------------------------------
	.byte		N96   , Gn4 
	.byte	W96
@ 046   ----------------------------------------
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
@ 047   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_3_043
@ 048   ----------------------------------------
	.byte		N96   , En4 , v100
	.byte	W96
@ 049   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N84   , Ds4 
	.byte	W96
@ 050   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_3_042
@ 051   ----------------------------------------
	.byte	W12
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N48   , Fn3 
	.byte	W48
@ 052   ----------------------------------------
	.byte		N30   
	.byte	W36
	.byte		N48   , En3 
	.byte	W60
@ 053   ----------------------------------------
	.byte	W12
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte		VOL   , 34*mus_vs_arven_mvl/mxv
	.byte		N03   , An2 
	.byte	W12
	.byte		VOL   , 43*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 52*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 61*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
@ 054   ----------------------------------------
	.byte	W12
	.byte		VOL   , 52*mus_vs_arven_mvl/mxv
	.byte		N03   , Gn2 
	.byte	W12
	.byte		VOL   , 61*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
@ 055   ----------------------------------------
	.byte		VOICE , 1
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Fn2 
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_3_002
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_3_003
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_3_004
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_3_001
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_3_002
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_3_003
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_3_004
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_3_008
	.byte	GOTO
	 .word	mus_vs_arven_3_B1
mus_vs_arven_3_B2:
@ 065   ----------------------------------------
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

mus_vs_arven_4:
	.byte	KEYSH , mus_vs_arven_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 33
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		N08   , Gs1 , v100
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		BEND  , c_v+0
	.byte		N08   , Ds1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W36
@ 001   ----------------------------------------
mus_vs_arven_4_001:
	.byte		BEND  , c_v-6
	.byte		N10   , As0 , v100
	.byte	W02
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-2
	.byte	W02
	.byte		        c_v+0
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte	PEND
@ 002   ----------------------------------------
mus_vs_arven_4_002:
	.byte		BEND  , c_v-6
	.byte		N10   , Ds1 , v100
	.byte	W02
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-2
	.byte	W02
	.byte		        c_v+0
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		BEND  , c_v-6
	.byte		N10   
	.byte	W02
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-2
	.byte	W02
	.byte		        c_v+0
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
mus_vs_arven_4_003:
	.byte		BEND  , c_v-6
	.byte		N10   , As0 , v100
	.byte	W02
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-2
	.byte	W02
	.byte		        c_v+0
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte	PEND
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_4_002
@ 005   ----------------------------------------
mus_vs_arven_4_005:
	.byte		N06   , Fn1 , v100
	.byte	W48
	.byte		N06   
	.byte	W48
	.byte	PEND
@ 006   ----------------------------------------
	.byte		N06   
	.byte	W48
	.byte		        Gs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W18
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_4_005
@ 008   ----------------------------------------
mus_vs_arven_4_008:
	.byte		N24   , Fn0 , v100
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N04   , Ds1 
	.byte	W06
	.byte		        Fn1 
	.byte	W18
	.byte		        As0 
	.byte	W06
	.byte		        Cn1 
	.byte	W18
	.byte	PEND
mus_vs_arven_4_B1:
@ 009   ----------------------------------------
	.byte		N12   , As0 , v100
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N36   , Gs0 
	.byte	W36
	.byte		N24   
	.byte	W24
@ 010   ----------------------------------------
	.byte		N12   , Gn0 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N36   , Fs0 
	.byte	W36
	.byte		N24   , Fn0 
	.byte	W24
@ 011   ----------------------------------------
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N36   , Gn0 
	.byte	W36
	.byte		N24   
	.byte	W24
@ 012   ----------------------------------------
	.byte		N12   , Gs0 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N36   , An0 
	.byte	W36
	.byte		N24   , Fn0 
	.byte	W24
@ 013   ----------------------------------------
	.byte		N12   , As1 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N22   , Gs1 
	.byte	W24
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N10   
	.byte	W12
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
@ 014   ----------------------------------------
	.byte		N10   , Gn1 
	.byte	W12
	.byte		N04   
	.byte	W06
	.byte		N10   
	.byte	W12
	.byte		N04   
	.byte	W06
	.byte		N36   , Fs1 
	.byte	W36
	.byte		N24   , Gs1 
	.byte	W24
@ 015   ----------------------------------------
	.byte		N12   , An1 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N36   , Bn0 
	.byte	W36
	.byte		N24   , Bn1 
	.byte	W24
@ 016   ----------------------------------------
	.byte		N12   , Cs1 
	.byte	W18
	.byte		        Cn1 
	.byte	W18
	.byte		N36   , Cs1 
	.byte	W36
	.byte		N24   , Fn1 
	.byte	W24
@ 017   ----------------------------------------
	.byte		N48   , Fs0 
	.byte	W72
	.byte		N24   
	.byte	W24
@ 018   ----------------------------------------
	.byte		N48   
	.byte	W60
	.byte		N06   , Cs1 
	.byte	W12
	.byte		N24   , Fs0 
	.byte	W24
@ 019   ----------------------------------------
	.byte		BEND  , c_v+0
	.byte		N48   , Fn0 
	.byte	W48
	.byte		N12   , Cn1 
	.byte	W12
	.byte		BEND  , c_v-16
	.byte		N24   , Cn2 
	.byte	W02
	.byte		BEND  , c_v-5
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v+0
	.byte	W16
	.byte		        c_v+0
	.byte		N12   , An1 
	.byte	W12
@ 020   ----------------------------------------
	.byte		N48   , As1 
	.byte	W48
	.byte		N36   , Fn1 
	.byte	W36
	.byte		N12   , As0 
	.byte	W12
@ 021   ----------------------------------------
	.byte		N30   , Fs1 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		N18   , Fs1 
	.byte	W24
	.byte		N12   , Cs1 
	.byte	W12
@ 022   ----------------------------------------
	.byte		N30   , Cn1 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W12
	.byte		N36   , Cn1 
	.byte	W36
@ 023   ----------------------------------------
	.byte		BEND  , c_v+0
	.byte		N30   , Fn1 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W12
	.byte		N36   , Fn1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+2
	.byte	W02
	.byte		        c_v+4
	.byte	W02
	.byte		        c_v+9
	.byte	W02
	.byte		        c_v+17
	.byte	W02
	.byte		        c_v+29
	.byte	W01
	.byte		        c_v+37
	.byte	W09
@ 024   ----------------------------------------
	.byte		        c_v+0
	.byte		N32   , As1 
	.byte	W36
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N24   , Gs1 
	.byte	W24
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
@ 025   ----------------------------------------
	.byte		BEND  , c_v+0
	.byte		N48   , Fs1 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+1
	.byte	W02
	.byte		        c_v+2
	.byte	W02
	.byte		        c_v+3
	.byte	W02
	.byte		        c_v+5
	.byte	W02
	.byte		        c_v+8
	.byte	W02
	.byte		        c_v+12
	.byte	W02
	.byte		        c_v+18
	.byte	W02
	.byte		        c_v+25
	.byte	W02
	.byte		        c_v+35
	.byte	W02
	.byte		        c_v+48
	.byte	W02
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N48   , Fs2 
	.byte	W24
	.byte		MOD   , 14
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-2
	.byte	W02
	.byte		        c_v-4
	.byte	W02
	.byte		        c_v-7
	.byte	W02
	.byte		        c_v-13
	.byte	W02
	.byte		        c_v-21
	.byte	W01
	.byte		        c_v-27
	.byte	W03
@ 026   ----------------------------------------
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N30   , Cs2 
	.byte	W36
	.byte		N09   
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N24   , Fs1 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-4
	.byte	W02
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v+0
	.byte		N12   , En1 
	.byte	W12
@ 027   ----------------------------------------
	.byte		N30   , Fn1 
	.byte	W36
	.byte		N06   , Cn2 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-2
	.byte	W02
	.byte		        c_v-4
	.byte	W02
	.byte		        c_v-6
	.byte	W02
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v+0
	.byte		N12   , Ds2 
	.byte	W12
@ 028   ----------------------------------------
	.byte		N36   , Dn2 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn2 
	.byte	W12
	.byte		N24   , As1 
	.byte	W24
	.byte		N03   
	.byte	W12
@ 029   ----------------------------------------
	.byte		N36   , Fs1 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N24   , Cs2 
	.byte	W24
	.byte		N12   , Fs1 
	.byte	W12
@ 030   ----------------------------------------
	.byte		N36   , Cn1 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N12   
	.byte	W12
	.byte		BEND  , c_v-11
	.byte		N24   , Cn2 
	.byte	W02
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v+0
	.byte	W18
	.byte		N12   , Gs1 
	.byte	W12
@ 031   ----------------------------------------
	.byte		N30   , Fn1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W36
@ 032   ----------------------------------------
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W18
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W18
	.byte		N03   , Fn1 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
@ 033   ----------------------------------------
	.byte		N36   , As0 
	.byte	W36
	.byte		N06   , Dn1 
	.byte	W12
	.byte		MOD   , 0
	.byte		N48   , Fn1 
	.byte	W06
	.byte		MOD   , 7
	.byte	W18
	.byte		        14
	.byte	W24
@ 034   ----------------------------------------
	.byte		        0
	.byte		N12   , Cn1 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N06   , En1 
	.byte	W12
	.byte		N48   , Gn1 
	.byte	W36
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-4
	.byte	W02
	.byte		        c_v-11
	.byte	W02
@ 035   ----------------------------------------
	.byte		        c_v+0
	.byte		N16   , As0 
	.byte	W16
	.byte		        Dn1 
	.byte	W16
	.byte		        Fn1 
	.byte	W16
	.byte		N48   , As1 
	.byte	W36
	.byte		BEND  , c_v-11
	.byte	W06
	.byte		        c_v-16
	.byte	W06
@ 036   ----------------------------------------
	.byte		        c_v+0
	.byte		N18   , Cn1 
	.byte	W18
	.byte		        En1 
	.byte	W18
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
@ 037   ----------------------------------------
	.byte		N18   , As0 
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N12   , Dn1 
	.byte	W12
	.byte		MOD   , 0
	.byte		N04   , Fn1 
	.byte	W06
	.byte		MOD   , 7
	.byte		N18   , As0 
	.byte	W18
	.byte		MOD   , 14
	.byte		N12   
	.byte	W12
	.byte		        Bn0 
	.byte	W12
@ 038   ----------------------------------------
	.byte		MOD   , 0
	.byte		N18   , Cn1 
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N12   , En1 
	.byte	W12
	.byte		N48   , Gn1 
	.byte	W36
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-4
	.byte	W02
	.byte		        c_v-11
	.byte	W02
@ 039   ----------------------------------------
	.byte		        c_v+0
	.byte		N18   , Gs0 
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N24   , As1 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
@ 040   ----------------------------------------
	.byte		N18   , En1 
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N24   
	.byte	W24
	.byte		        Dn1 
	.byte	W24
@ 041   ----------------------------------------
	.byte		N18   , As0 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		        Fn1 
	.byte	W12
	.byte		N48   , As1 
	.byte	W48
@ 042   ----------------------------------------
	.byte		N36   
	.byte	W36
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
@ 043   ----------------------------------------
	.byte		        Ds1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		MOD   , 0
	.byte		N36   , As1 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        12
	.byte	W12
	.byte		        0
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        As0 
	.byte	W12
@ 044   ----------------------------------------
	.byte		N36   , Cn1 
	.byte	W36
	.byte		N12   , En1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        As1 
	.byte	W12
@ 045   ----------------------------------------
	.byte		N18   , As0 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		        Fn1 
	.byte	W12
	.byte		N30   , As1 
	.byte	W36
	.byte		N12   , Dn2 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-3
	.byte	W02
	.byte		        c_v-22
	.byte	W02
@ 046   ----------------------------------------
	.byte		        c_v+0
	.byte		N12   , As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte		        As0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
@ 047   ----------------------------------------
	.byte		BEND  , c_v+0
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		MOD   , 0
	.byte		N36   , As1 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v-3
	.byte	W02
	.byte		MOD   , 14
	.byte		BEND  , c_v-16
	.byte	W12
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        As0 
	.byte	W12
@ 048   ----------------------------------------
	.byte		N24   , Cn1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        Gn0 
	.byte	W24
	.byte		        As0 
	.byte	W24
@ 049   ----------------------------------------
	.byte		N96   , Fn1 , v092
	.byte	W96
@ 050   ----------------------------------------
	.byte		        As1 
	.byte	W96
@ 051   ----------------------------------------
	.byte		        Ds1 , v080
	.byte	W96
@ 052   ----------------------------------------
	.byte		        En1 , v060
	.byte	W96
@ 053   ----------------------------------------
	.byte		N24   , Fn1 , v072
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N12   
	.byte	W12
@ 054   ----------------------------------------
	.byte		N24   , Gn1 
	.byte	W36
	.byte		N09   
	.byte	W12
	.byte		N04   , Gn1 , v100
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte	W06
@ 055   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_4_001
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_4_002
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_4_003
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_4_002
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_4_001
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_4_002
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_4_003
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_4_002
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_4_005
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_4_008
	.byte	GOTO
	 .word	mus_vs_arven_4_B1
mus_vs_arven_4_B2:
@ 065   ----------------------------------------
	.byte	FINE

@**************** Track 5 (Midi-Chn.5) ****************@

mus_vs_arven_5:
	.byte	KEYSH , mus_vs_arven_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BENDR , 12
	.byte		N12   , Fs3 , v112
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W24
@ 001   ----------------------------------------
	.byte		N48   , An2 , v100
	.byte	W24
	.byte		N06   , Fs3 
	.byte	W18
	.byte		        Fs3 , v080
	.byte	W06
	.byte		        Fn3 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Fs3 
	.byte	W06
@ 002   ----------------------------------------
mus_vs_arven_5_002:
	.byte		N06   , Fn3 , v080
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W18
	.byte		        Fn3 , v080
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
	.byte		N48   , An2 
	.byte	W24
	.byte		N06   , Fs3 
	.byte	W18
	.byte		        Fn3 , v080
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W12
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_5_002
@ 005   ----------------------------------------
	.byte		N48   , An2 , v100
	.byte		N06   , Fn3 , v080
	.byte	W12
	.byte		        Dn3 , v060
	.byte		N06   , Cs5 , v052
	.byte	W06
	.byte		        Dn3 , v060
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W12
	.byte		        Dn3 , v060
	.byte		N06   , Dn4 , v052
	.byte	W06
	.byte		        Dn3 , v060
	.byte		N06   , Dn4 , v052
	.byte	W06
	.byte		        Fn3 , v080
	.byte		N06   , Cs5 , v052
	.byte	W12
	.byte		        Dn3 , v060
	.byte	W06
	.byte		N06   
	.byte		N06   , En3 , v052
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Dn3 , v060
	.byte		N06   , En3 , v052
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		        Dn3 , v060
	.byte	W06
	.byte		N06   
	.byte		N06   , Dn4 , v052
	.byte	W06
	.byte		        Dn3 , v060
	.byte		N06   , Dn4 , v052
	.byte		N06   , Cs5 
	.byte	W06
@ 006   ----------------------------------------
	.byte		        Fn3 , v080
	.byte	W12
	.byte		        Dn3 , v060
	.byte		N06   , Cs5 , v052
	.byte	W06
	.byte		        Dn3 , v060
	.byte	W06
	.byte		        Fn3 , v080
	.byte		N06   , Cs5 , v052
	.byte	W06
	.byte		        Dn3 , v060
	.byte	W06
	.byte		N06   
	.byte		N06   , Dn4 , v052
	.byte	W06
	.byte		N10   , Dn3 , v060
	.byte		N06   , Dn4 , v052
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		N10   , Dn3 , v060
	.byte	W06
	.byte		N06   , En3 , v052
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        En3 
	.byte		N06   , Fn3 , v080
	.byte	W12
	.byte		        Dn3 , v060
	.byte		N06   , Dn4 , v052
	.byte	W06
	.byte		        Dn3 , v060
	.byte		N06   , Dn4 , v052
	.byte		N06   , Cs5 
	.byte	W06
@ 007   ----------------------------------------
mus_vs_arven_5_007:
	.byte		N48   , An2 , v060
	.byte		N06   , Fn3 , v080
	.byte	W12
	.byte		        Dn3 , v060
	.byte		N06   , Cs5 , v052
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W06
	.byte		N06   
	.byte		N06   , Cs5 , v052
	.byte	W06
	.byte		        Dn3 , v060
	.byte	W18
	.byte		        Fn3 , v080
	.byte		N06   , Cs5 , v052
	.byte	W06
	.byte		        En3 
	.byte	W12
	.byte		N06   
	.byte		N06   , Fn3 , v080
	.byte		N06   , Cs5 , v052
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W12
	.byte		        Cs5 , v052
	.byte	W12
	.byte	PEND
@ 008   ----------------------------------------
mus_vs_arven_5_008:
	.byte		N06   , Fn3 , v080
	.byte	W12
	.byte		        Cs5 , v052
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Cs5 , v052
	.byte	W06
	.byte		        Dn3 , v060
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Cs5 , v052
	.byte	W06
	.byte		        En3 
	.byte	W12
	.byte		N06   
	.byte		N06   , Fn3 , v080
	.byte		N06   , Cs5 , v052
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W12
	.byte		        Cs5 , v052
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W06
	.byte	PEND
mus_vs_arven_5_B1:
@ 009   ----------------------------------------
	.byte		N48   , An2 , v080
	.byte	W36
	.byte		N06   , Fn3 
	.byte	W36
	.byte		        Fs3 , v100
	.byte	W24
@ 010   ----------------------------------------
	.byte	W60
	.byte		N06   
	.byte	W24
	.byte		        Fn3 , v080
	.byte	W12
@ 011   ----------------------------------------
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W48
	.byte		N06   
	.byte		N06   , Fs3 , v100
	.byte	W12
@ 012   ----------------------------------------
	.byte		N18   , An2 , v052
	.byte	W18
	.byte		        An2 , v068
	.byte	W18
	.byte		N36   , An2 , v080
	.byte	W24
	.byte		N06   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v080
	.byte	W18
	.byte		        Fn3 
	.byte		N06   , Fs3 , v100
	.byte	W12
@ 013   ----------------------------------------
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N04   , Ds1 , v060
	.byte		N06   , Fs3 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
@ 014   ----------------------------------------
	.byte		N18   , An2 , v068
	.byte	W12
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		N18   , An2 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N36   , An2 , v100
	.byte	W12
	.byte		N04   , Ds1 , v060
	.byte	W24
	.byte		N06   , Fs3 , v100
	.byte	W24
@ 015   ----------------------------------------
	.byte		        Fn3 , v080
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		        Fs3 , v100
	.byte	W24
@ 016   ----------------------------------------
	.byte		N18   , An2 , v052
	.byte	W18
	.byte		        An2 , v068
	.byte	W18
	.byte		N24   , An2 , v080
	.byte	W36
	.byte		N06   , Fs3 , v100
	.byte	W24
@ 017   ----------------------------------------
	.byte		        Fn3 , v080
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Fs3 , v100
	.byte	W24
@ 018   ----------------------------------------
	.byte		        Fn3 , v080
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Fs3 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs3 , v080
	.byte	W06
@ 019   ----------------------------------------
	.byte		        Fn3 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 020   ----------------------------------------
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Fs3 , v100
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W12
@ 021   ----------------------------------------
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W24
@ 022   ----------------------------------------
	.byte		        Fn3 , v080
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Fs3 , v100
	.byte	W24
@ 023   ----------------------------------------
	.byte		        Fn3 , v080
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Fs3 , v100
	.byte	W18
	.byte		        Fs3 , v080
	.byte	W06
@ 024   ----------------------------------------
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W12
	.byte		        Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v080
	.byte	W06
	.byte		N12   , An2 , v072
	.byte	W12
	.byte		        An2 , v084
	.byte	W12
	.byte		        An2 , v092
	.byte	W12
@ 025   ----------------------------------------
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N06   , Fs3 , v100
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Fs3 , v100
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W12
@ 026   ----------------------------------------
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fs3 , v100
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W12
@ 027   ----------------------------------------
mus_vs_arven_5_027:
	.byte		N06   , Fn3 , v080
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fs3 , v100
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Fs3 , v100
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W12
	.byte	PEND
@ 028   ----------------------------------------
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fs3 , v100
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_5_027
@ 030   ----------------------------------------
	.byte		N06   , Fn3 , v080
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fs3 , v100
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W12
@ 031   ----------------------------------------
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fs3 , v100
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte		        Fs3 , v092
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W12
@ 032   ----------------------------------------
	.byte		        Fs3 , v100
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Dn1 , v080
	.byte	W18
	.byte		        Fs3 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Dn1 , v100
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 , v080
	.byte	W12
	.byte		        Fs3 , v100
	.byte	W12
@ 033   ----------------------------------------
	.byte		N04   , Ds1 , v060
	.byte		N48   , An2 , v100
	.byte	W32
	.byte		N06   , Fn3 , v080
	.byte	W16
	.byte		N04   , Ds1 , v060
	.byte		N06   , Fs3 , v100
	.byte	W48
@ 034   ----------------------------------------
	.byte		N04   , Ds1 , v060
	.byte		N06   , Fn3 , v080
	.byte	W08
	.byte		N04   , Ds1 , v036
	.byte	W08
	.byte		        Ds1 , v028
	.byte	W02
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		N04   , Ds1 , v020
	.byte	W12
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N04   , Ds1 , v060
	.byte		N06   , Fs3 , v100
	.byte	W12
	.byte		        Fs3 , v072
	.byte	W12
	.byte		        Fs3 , v052
	.byte	W24
@ 035   ----------------------------------------
	.byte		N04   , Ds1 , v060
	.byte		N24   , Bn2 
	.byte	W32
	.byte		N06   , Fn3 , v080
	.byte	W08
	.byte		N06   
	.byte	W08
	.byte		N04   , Ds1 , v060
	.byte		N06   , Fs3 , v100
	.byte	W48
@ 036   ----------------------------------------
	.byte		        Fn3 , v080
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W12
	.byte		        Fs3 , v080
	.byte	W36
@ 037   ----------------------------------------
mus_vs_arven_5_037:
	.byte		N04   , Ds1 , v060
	.byte		N06   , Fn3 , v080
	.byte	W18
	.byte		N04   , Ds1 , v048
	.byte		N06   , Fn3 , v080
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N48   , An2 , v072
	.byte		N06   , Fs3 , v100
	.byte	W48
	.byte	PEND
@ 038   ----------------------------------------
mus_vs_arven_5_038:
	.byte		N04   , Ds1 , v060
	.byte		N06   , Fn3 , v080
	.byte	W08
	.byte		N04   , Ds1 , v036
	.byte	W08
	.byte		        Ds1 , v028
	.byte	W02
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		N04   , Ds1 , v020
	.byte	W12
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N48   , Bn2 , v072
	.byte		N06   , Fs3 , v100
	.byte	W48
	.byte	PEND
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_5_037
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_5_038
@ 041   ----------------------------------------
	.byte		N06   , Cn1 , v092
	.byte		N48   , An2 , v100
	.byte	W18
	.byte		N06   , Cn1 , v092
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Dn1 , v072
	.byte		N04   , Ds1 , v060
	.byte	W18
	.byte		N06   , Cn1 , v092
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
@ 042   ----------------------------------------
mus_vs_arven_5_042:
	.byte		N06   , Cn1 , v092
	.byte		N04   , Ds1 , v060
	.byte	W18
	.byte		N06   , Cn1 , v092
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Dn1 , v072
	.byte		N04   , Ds1 , v060
	.byte	W18
	.byte		N06   , Cn1 , v092
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte	PEND
@ 043   ----------------------------------------
	.byte		N06   
	.byte		N04   , Ds1 , v060
	.byte	W12
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Dn1 , v072
	.byte		N04   , Ds1 , v060
	.byte	W12
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 , v072
	.byte	W06
	.byte		        Cn1 , v092
	.byte		N06   , Dn1 , v072
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W12
@ 044   ----------------------------------------
	.byte		        Dn1 , v072
	.byte		N04   , Ds1 , v060
	.byte	W06
	.byte		N06   , Cn1 , v092
	.byte		N06   , Dn1 , v072
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 , v072
	.byte		N18   , An2 , v100
	.byte	W12
	.byte		N12   , As4 , v052
	.byte	W06
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte		N12   , As4 , v052
	.byte	W06
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte		N12   , As4 , v052
	.byte	W12
@ 045   ----------------------------------------
	.byte		N06   , Cn1 , v092
	.byte		N04   , Ds1 , v060
	.byte	W12
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Dn1 , v072
	.byte		N04   , Ds1 , v060
	.byte	W18
	.byte		N06   , Cn1 , v092
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
@ 046   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_5_042
@ 047   ----------------------------------------
	.byte		N06   , Cn1 , v092
	.byte		N04   , Ds1 , v060
	.byte	W12
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Dn1 , v072
	.byte		N04   , Ds1 , v060
	.byte	W18
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N06   
	.byte		N06   , Dn1 , v072
	.byte	W06
	.byte		        Cn1 , v092
	.byte		N06   , Dn1 , v072
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W12
@ 048   ----------------------------------------
	.byte		N06   
	.byte		N04   , Ds1 , v060
	.byte	W24
	.byte		N06   , Dn1 , v072
	.byte	W18
	.byte		        Cn1 , v092
	.byte	W06
	.byte		N04   , Ds1 , v060
	.byte	W06
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		        Dn1 , v072
	.byte	W06
	.byte		        Cn1 , v092
	.byte		N06   , Dn1 , v072
	.byte	W12
	.byte		        Cn1 , v092
	.byte	W06
	.byte		N06   
	.byte		N06   , Dn1 , v072
	.byte	W12
@ 049   ----------------------------------------
	.byte		N48   , Bn2 , v100
	.byte		N06   , Fn3 , v092
	.byte	W24
	.byte		        Dn1 , v052
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 , v092
	.byte	W24
	.byte		        Dn1 , v052
	.byte		N06   , En3 
	.byte	W24
@ 050   ----------------------------------------
	.byte		N06   
	.byte		N06   , Fn3 , v092
	.byte	W12
	.byte		        En3 , v052
	.byte	W12
	.byte		        Dn1 
	.byte		N06   , En3 
	.byte	W12
	.byte		        Dn1 
	.byte		N06   , En3 
	.byte	W12
	.byte		        Fn3 , v092
	.byte	W24
	.byte		        Dn1 , v052
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
@ 051   ----------------------------------------
mus_vs_arven_5_051:
	.byte		N06   , Fn3 , v092
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PEND
@ 052   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_5_051
@ 053   ----------------------------------------
	.byte		N04   , Fs1 , v028
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Dn3 , v060
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , En4 , v060
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Dn3 , v060
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Dn3 , v060
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Dn3 , v060
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , En4 , v060
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte		N06   , En4 , v060
	.byte	W06
@ 054   ----------------------------------------
	.byte		        Fn3 , v096
	.byte	W12
	.byte		N04   , Fs1 , v028
	.byte		N06   , Dn3 , v060
	.byte	W12
	.byte		        Fn3 , v096
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , En4 , v060
	.byte	W12
	.byte		        Fn3 , v096
	.byte		N06   , Fs3 , v112
	.byte	W12
	.byte		        Dn3 , v060
	.byte		N06   , Fs3 , v112
	.byte	W12
	.byte		        Fn3 , v080
	.byte		N06   , Fs3 , v112
	.byte	W06
	.byte		        Dn3 , v060
	.byte		N06   , Fs3 , v112
	.byte	W06
	.byte		        Fn3 , v080
	.byte		N06   , En4 , v060
	.byte	W12
@ 055   ----------------------------------------
	.byte		N48   , An2 , v100
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Dn3 , v060
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , En4 , v060
	.byte	W06
	.byte		        Fn3 , v080
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Dn3 , v060
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		N06   
	.byte		N06   , Fs3 , v100
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Fn3 , v080
	.byte		N06   , En4 , v060
	.byte	W06
	.byte		        Fs3 , v080
	.byte		N06   , En4 , v060
	.byte	W06
@ 056   ----------------------------------------
	.byte		N04   , Fs1 , v028
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Dn3 , v060
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , En4 , v060
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Dn3 , v060
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W12
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Dn1 , v100
	.byte	W12
@ 057   ----------------------------------------
mus_vs_arven_5_057:
	.byte		N48   , An2 , v100
	.byte	W24
	.byte		N06   , Fs3 
	.byte	W12
	.byte		        En4 , v060
	.byte	W06
	.byte		        Fs3 , v080
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Dn3 , v060
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W12
	.byte		        En4 , v060
	.byte	W06
	.byte		        Fs3 , v080
	.byte	W06
	.byte	PEND
@ 058   ----------------------------------------
	.byte		        Fn3 
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Dn3 , v060
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , En4 , v060
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Dn3 , v060
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W12
	.byte		N04   
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		        Dn3 , v060
	.byte		N06   , Fs3 , v100
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Dn1 , v100
	.byte		N06   , En4 , v060
	.byte	W12
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_5_057
@ 060   ----------------------------------------
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Dn3 , v060
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , En4 , v060
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Dn3 , v060
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W12
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Dn1 , v100
	.byte	W12
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_5_057
@ 062   ----------------------------------------
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Dn3 , v060
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , En4 , v060
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Dn3 , v060
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Gn4 , v060
	.byte	W06
	.byte		        Fn3 , v080
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		N04   , Fs1 , v028
	.byte	W06
	.byte		N06   , Dn1 , v100
	.byte	W12
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_5_007
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_5_008
	.byte	GOTO
	 .word	mus_vs_arven_5_B1
mus_vs_arven_5_B2:
@ 065   ----------------------------------------
	.byte	FINE

@**************** Track 6 (Midi-Chn.6) ****************@

mus_vs_arven_6:
	.byte	KEYSH , mus_vs_arven_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		VOL   , 60*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		BENDR , 12
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
mus_vs_arven_6_B1:
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		N12   , Cs4 , v100
	.byte	W18
	.byte		        Cn4 
	.byte	W18
	.byte		N06   , Cs4 
	.byte	W60
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
	.byte		VOICE , 0
	.byte		VOL   , 100*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+28
	.byte	W24
	.byte		N12   , Dn7 , v052
	.byte	W16
	.byte		        Dn7 , v048
	.byte	W32
	.byte		        Dn7 , v052
	.byte	W16
	.byte		        Dn7 , v048
	.byte	W08
@ 036   ----------------------------------------
	.byte		PAN   , c_v-28
	.byte		N12   , As4 , v052
	.byte	W12
	.byte		        As4 , v040
	.byte	W12
	.byte		N06   , As4 , v020
	.byte	W06
	.byte		N12   , As4 , v052
	.byte	W18
	.byte		        As4 , v048
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N06   , As4 , v020
	.byte	W06
	.byte		N12   , As4 , v052
	.byte	W12
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
	.byte	GOTO
	 .word	mus_vs_arven_6_B1
mus_vs_arven_6_B2:
@ 065   ----------------------------------------
	.byte	FINE

@**************** Track 7 (Midi-Chn.7) ****************@

mus_vs_arven_7:
	.byte	KEYSH , mus_vs_arven_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 80
	.byte		VOL   , 30*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BENDR , 12
	.byte		N06   , Cn3 , v100
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        Ds3 
	.byte	W12
	.byte		N06   
	.byte	W36
@ 001   ----------------------------------------
mus_vs_arven_7_001:
	.byte	W12
	.byte		VOICE , 80
	.byte		VOL   , 20*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , Cs3 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte	PEND
@ 002   ----------------------------------------
mus_vs_arven_7_002:
	.byte		VOICE , 81
	.byte		VOL   , 20*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Cs3 , v100
	.byte	W24
	.byte		N12   
	.byte	W18
	.byte		N24   , Cn3 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
mus_vs_arven_7_003:
	.byte	W12
	.byte		VOICE , 80
	.byte		VOL   , 20*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , Cs3 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte	PEND
@ 004   ----------------------------------------
mus_vs_arven_7_004:
	.byte		VOICE , 81
	.byte		VOL   , 20*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Cs3 , v100
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Ds3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N18   , As2 
	.byte	W24
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 005   ----------------------------------------
	.byte		VOICE , 80
	.byte		VOL   , 20*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N84   , Cn4 
	.byte	W84
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
@ 006   ----------------------------------------
	.byte		N48   , An3 
	.byte	W48
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
@ 007   ----------------------------------------
	.byte		N84   
	.byte	W84
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
@ 008   ----------------------------------------
mus_vs_arven_7_008:
	.byte		N48   , Fn3 , v100
	.byte	W48
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte	PEND
mus_vs_arven_7_B1:
@ 009   ----------------------------------------
	.byte		VOICE , 80
	.byte		VOL   , 24*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Fn4 , v100
	.byte	W02
	.byte		VOL   , 24*mus_vs_arven_mvl/mxv
	.byte	W08
	.byte		        23*mus_vs_arven_mvl/mxv
	.byte	W08
	.byte		        22*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        22*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        21*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte		N02   , En4 
	.byte	W02
	.byte		VOL   , 18*mus_vs_arven_mvl/mxv
	.byte		N02   , Ds4 
	.byte	W02
	.byte		VOL   , 15*mus_vs_arven_mvl/mxv
	.byte		N02   , Dn4 
	.byte	W02
	.byte		VOL   , 10*mus_vs_arven_mvl/mxv
	.byte		N02   , Cs4 
	.byte	W02
	.byte		VOL   , 5*mus_vs_arven_mvl/mxv
	.byte		N02   , Cn4 
	.byte	W02
	.byte		VOL   , 0*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		VOICE , 81
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N36   , Cs3 
	.byte	W36
	.byte		N24   
	.byte	W24
@ 010   ----------------------------------------
	.byte		N18   , Gn3 
	.byte	W18
	.byte		        An3 
	.byte	W18
	.byte		N06   , Fn3 
	.byte	W24
	.byte		VOICE , 80
	.byte		VOL   , 24*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N06   , Cs4 
	.byte	W36
@ 011   ----------------------------------------
	.byte		VOICE , 81
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N18   , Gs2 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N36   , As2 
	.byte	W48
	.byte		VOICE , 80
	.byte		VOL   , 24*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N06   , Fn4 
	.byte	W12
@ 012   ----------------------------------------
	.byte		        Gs4 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		VOL   , 24*mus_vs_arven_mvl/mxv
	.byte		N30   , An4 
	.byte	W02
	.byte		VOL   , 24*mus_vs_arven_mvl/mxv
	.byte	W08
	.byte		        23*mus_vs_arven_mvl/mxv
	.byte	W08
	.byte		        22*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        22*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        21*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        15*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        10*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        5*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        0*mus_vs_arven_mvl/mxv
	.byte	W14
	.byte		        24*mus_vs_arven_mvl/mxv
	.byte		N06   , As4 
	.byte	W12
@ 013   ----------------------------------------
	.byte		        Fn4 
	.byte	W36
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		        As3 
	.byte	W12
@ 014   ----------------------------------------
	.byte		VOL   , 24*mus_vs_arven_mvl/mxv
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		VOL   , 24*mus_vs_arven_mvl/mxv
	.byte		N20   
	.byte	W02
	.byte		VOL   , 24*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        23*mus_vs_arven_mvl/mxv
	.byte	W08
	.byte		        22*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        22*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        21*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte		N02   , Cn4 
	.byte	W02
	.byte		VOL   , 18*mus_vs_arven_mvl/mxv
	.byte		N02   , Bn3 
	.byte	W02
	.byte		VOL   , 15*mus_vs_arven_mvl/mxv
	.byte		N02   , As3 
	.byte	W02
	.byte		VOL   , 10*mus_vs_arven_mvl/mxv
	.byte		N02   , An3 
	.byte	W02
	.byte		VOL   , 5*mus_vs_arven_mvl/mxv
	.byte		N02   , Gs3 
	.byte	W02
	.byte		VOL   , 0*mus_vs_arven_mvl/mxv
	.byte	W14
	.byte		        24*mus_vs_arven_mvl/mxv
	.byte	W16
@ 015   ----------------------------------------
	.byte		VOICE , 81
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N18   , Cs3 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Bn2 
	.byte	W12
@ 016   ----------------------------------------
	.byte		VOICE , 80
	.byte		VOL   , 24*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-12
	.byte		N04   , Gs3 , v080
	.byte	W18
	.byte		N04   
	.byte	W18
	.byte		N24   
	.byte	W18
	.byte		VOL   , 24*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        21*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        11*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        6*mus_vs_arven_mvl/mxv
	.byte	W10
	.byte		VOICE , 80
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-12
	.byte		N24   , Cn5 , v100
	.byte	W24
@ 017   ----------------------------------------
	.byte	W12
	.byte		VOICE , 84
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , As2 
	.byte	W30
	.byte		N06   
	.byte	W06
@ 018   ----------------------------------------
	.byte	W12
	.byte		VOICE , 84
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , As2 
	.byte	W36
@ 019   ----------------------------------------
	.byte	W12
	.byte		VOICE , 84
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Gs2 
	.byte	W30
	.byte		N06   
	.byte	W06
@ 020   ----------------------------------------
	.byte	W12
	.byte		VOICE , 84
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
@ 021   ----------------------------------------
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , As2 
	.byte	W30
	.byte		N06   
	.byte	W06
@ 022   ----------------------------------------
	.byte	W12
	.byte		VOICE , 84
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
@ 023   ----------------------------------------
	.byte	W12
	.byte		VOICE , 84
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 024   ----------------------------------------
	.byte		        Fn4 
	.byte	W12
	.byte		VOICE , 80
	.byte		VOL   , 30*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N06   , Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W09
	.byte		VOL   , 30*mus_vs_arven_mvl/mxv
	.byte	W03
	.byte		N16   , Dn4 
	.byte	W07
	.byte		VOL   , 30*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        29*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        26*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        22*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        14*mus_vs_arven_mvl/mxv
	.byte	W09
	.byte		VOICE , 81
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , As2 
	.byte	W06
@ 025   ----------------------------------------
	.byte	W12
	.byte		VOICE , 80
	.byte		VOL   , 22*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 026   ----------------------------------------
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Cn3 
	.byte	W30
	.byte		N06   , As2 
	.byte	W18
	.byte		N24   , Cn3 
	.byte	W30
	.byte		N06   , As2 
	.byte	W06
@ 027   ----------------------------------------
	.byte	W12
	.byte		VOICE , 80
	.byte		VOL   , 22*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds4 
	.byte	W06
@ 028   ----------------------------------------
	.byte		        Dn4 
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , As2 
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
@ 029   ----------------------------------------
	.byte	W12
	.byte		VOICE , 80
	.byte		VOL   , 22*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
@ 030   ----------------------------------------
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Gs3 
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
@ 031   ----------------------------------------
	.byte		VOICE , 81
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		N06   , An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		VOICE , 80
	.byte		PAN   , c_v+8
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		N02   , Fn1 
	.byte	W02
	.byte		        Gs1 
	.byte	W02
	.byte		        Cn2 
	.byte	W02
	.byte		        Ds2 
	.byte	W02
	.byte		        Fn2 
	.byte	W02
	.byte		        Gs2 
	.byte	W02
	.byte		        Cn3 
	.byte	W02
	.byte		        Ds3 
	.byte	W02
	.byte		        Fn3 
	.byte	W02
	.byte		        Gs3 
	.byte	W02
	.byte		        Cn4 
	.byte	W02
	.byte		        Ds4 
	.byte	W02
	.byte		        Fn4 
	.byte	W24
@ 032   ----------------------------------------
	.byte		VOICE , 81
	.byte		VOL   , 35*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , Cn3 
	.byte	W18
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , Cn3 
	.byte	W18
	.byte		N06   , Ds3 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 033   ----------------------------------------
mus_vs_arven_7_033:
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N36   , Ds3 , v100
	.byte	W48
	.byte		        Dn3 
	.byte	W36
	.byte	PEND
@ 034   ----------------------------------------
	.byte	W12
	.byte		VOICE , 88
	.byte		VOL   , 30*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_7_033
@ 036   ----------------------------------------
	.byte	W12
	.byte		N36   , Cn3 , v100
	.byte	W36
	.byte		N24   , Gn2 
	.byte	W24
	.byte		        En2 
	.byte	W24
@ 037   ----------------------------------------
	.byte	W12
	.byte		N36   , Ds3 
	.byte	W48
	.byte		        Dn3 
	.byte	W36
@ 038   ----------------------------------------
	.byte	W12
	.byte		VOICE , 88
	.byte		VOL   , 30*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
@ 039   ----------------------------------------
	.byte		VOICE , 81
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N48   , Ds3 
	.byte	W48
	.byte		        Dn3 
	.byte	W48
@ 040   ----------------------------------------
	.byte		        Cn3 
	.byte	W48
	.byte		N24   , Gn2 
	.byte	W24
	.byte		        En2 
	.byte	W24
@ 041   ----------------------------------------
	.byte		VOICE , 81
	.byte		VOL   , 35*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N96   , Ds4 
	.byte	W96
@ 042   ----------------------------------------
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N12   , As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
@ 043   ----------------------------------------
	.byte		        Dn4 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
@ 044   ----------------------------------------
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		VOICE , 80
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N02   , Cs3 
	.byte	W02
	.byte		        En3 
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        As3 
	.byte	W02
	.byte		        Cs4 
	.byte	W02
	.byte		        En4 
	.byte	W02
	.byte		N72   , Gn4 
	.byte	W72
@ 045   ----------------------------------------
	.byte		N02   , Cn4 
	.byte	W02
	.byte		        Cs4 
	.byte	W02
	.byte		        Ds4 
	.byte	W02
	.byte		        En4 
	.byte	W02
	.byte		        Fn4 
	.byte	W02
	.byte		        Fs4 
	.byte	W02
	.byte		N84   , Gn4 
	.byte	W84
@ 046   ----------------------------------------
	.byte		N06   , Dn4 
	.byte	W60
	.byte		N36   , Fn4 
	.byte	W36
@ 047   ----------------------------------------
	.byte		VOICE , 81
	.byte		VOL   , 35*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Dn4 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
@ 048   ----------------------------------------
	.byte		VOICE , 80
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N96   , Cs4 
	.byte	W96
@ 049   ----------------------------------------
	.byte		VOICE , 80
	.byte		VOL   , 20*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N96   , Gs3 
	.byte	W96
@ 050   ----------------------------------------
	.byte		N48   , As3 
	.byte	W48
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
@ 051   ----------------------------------------
	.byte	W12
	.byte		        Gn3 
	.byte	W24
	.byte		N48   , Dn4 
	.byte	W60
@ 052   ----------------------------------------
	.byte		VOL   , 20*mus_vs_arven_mvl/mxv
	.byte		N32   , Bn3 , v092
	.byte	W06
	.byte		VOL   , 20*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        20*mus_vs_arven_mvl/mxv
	.byte		N36   , Gs3 , v080
	.byte	W06
	.byte		VOL   , 20*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_arven_mvl/mxv
	.byte	W12
@ 053   ----------------------------------------
	.byte	W12
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		VOL   , 21*mus_vs_arven_mvl/mxv
	.byte		N03   , Ds3 , v100
	.byte	W12
	.byte		VOL   , 27*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 33*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 38*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 44*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
@ 054   ----------------------------------------
	.byte	W12
	.byte		VOL   , 33*mus_vs_arven_mvl/mxv
	.byte		N03   , Fn3 
	.byte	W12
	.byte		VOL   , 38*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 44*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
@ 055   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_7_001
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_7_002
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_7_003
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_7_004
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_7_001
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_7_002
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_7_003
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_7_004
@ 063   ----------------------------------------
	.byte		VOICE , 80
	.byte		VOL   , 20*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N84   , An3 , v100
	.byte	W84
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_7_008
	.byte	GOTO
	 .word	mus_vs_arven_7_B1
mus_vs_arven_7_B2:
@ 065   ----------------------------------------
	.byte	FINE

@**************** Track 8 (Midi-Chn.8) ****************@

mus_vs_arven_8:
	.byte	KEYSH , mus_vs_arven_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 90
	.byte		VOL   , 30*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BENDR , 12
	.byte	W96
@ 001   ----------------------------------------
	.byte		N60   , Cs4 , v100
	.byte	W60
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
@ 002   ----------------------------------------
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N04   , As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N18   , Cn4 
	.byte	W18
@ 003   ----------------------------------------
	.byte		N60   , Cs4 
	.byte	W60
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
@ 004   ----------------------------------------
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N04   , Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W24
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W12
	.byte		VOICE , 90
	.byte		VOL   , 20*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-12
	.byte		N06   , Cn4 
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
	.byte		        An3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte		N06   
	.byte	W18
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
mus_vs_arven_8_008:
	.byte	W12
	.byte		VOICE , 90
	.byte		VOL   , 35*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Ds4 , v080
	.byte	W12
	.byte		        Ds4 , v088
	.byte	W12
	.byte		        Ds4 , v092
	.byte	W12
	.byte		        Cn4 , v100
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Ds4 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte	PEND
mus_vs_arven_8_B1:
@ 009   ----------------------------------------
	.byte		VOICE , 91
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N18   , Fn3 , v100
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N36   , As2 
	.byte	W36
	.byte		N24   
	.byte	W24
@ 010   ----------------------------------------
	.byte		N18   
	.byte	W18
	.byte		        Cn3 
	.byte	W18
	.byte		N06   , Cs3 
	.byte	W24
	.byte		VOICE , 90
	.byte		VOL   , 24*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N06   , Fn3 
	.byte	W36
@ 011   ----------------------------------------
	.byte		VOICE , 91
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N18   , Fn2 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N36   , Gn2 
	.byte	W60
@ 012   ----------------------------------------
	.byte		N18   , Gs2 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N36   , An2 
	.byte	W60
@ 013   ----------------------------------------
	.byte		N18   , Fn3 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N18   , Fn3 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N12   , Gs3 
	.byte	W12
@ 014   ----------------------------------------
	.byte		N18   , Gn3 
	.byte	W18
	.byte		        An3 
	.byte	W18
	.byte		N06   , As3 
	.byte	W60
@ 015   ----------------------------------------
	.byte		VOICE , 94
	.byte		VOL   , 30*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+12
	.byte		N24   , An3 
	.byte	W24
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N18   , En3 
	.byte	W18
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
@ 016   ----------------------------------------
	.byte		        Fs3 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N24   , Fn3 
	.byte	W60
@ 017   ----------------------------------------
	.byte	W12
	.byte		VOICE , 91
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Cs3 
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
@ 018   ----------------------------------------
	.byte	W12
	.byte		N24   , Cn3 
	.byte	W30
	.byte		N06   , As2 
	.byte	W18
	.byte		N24   , Cn3 
	.byte	W30
	.byte		N06   , As2 
	.byte	W06
@ 019   ----------------------------------------
	.byte	W12
	.byte		N24   , Cn3 
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
@ 020   ----------------------------------------
mus_vs_arven_8_020:
	.byte	W12
	.byte		N24   , Dn3 , v100
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 021   ----------------------------------------
	.byte	W12
	.byte		N24   , Cs3 
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
@ 022   ----------------------------------------
mus_vs_arven_8_022:
	.byte	W12
	.byte		N24   , As3 , v100
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 023   ----------------------------------------
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
@ 024   ----------------------------------------
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N06   , As1 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
@ 025   ----------------------------------------
mus_vs_arven_8_025:
	.byte	W12
	.byte		N24   , Fs2 , v100
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 026   ----------------------------------------
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W30
	.byte		N06   , Cs3 
	.byte	W18
	.byte		N24   , Ds3 
	.byte	W30
	.byte		N06   , Cs3 
	.byte	W06
@ 027   ----------------------------------------
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_8_020
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_8_025
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_8_022
@ 031   ----------------------------------------
	.byte	W12
	.byte		N24   , Fs3 , v100
	.byte	W30
	.byte		N06   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   
	.byte	W06
@ 032   ----------------------------------------
	.byte		VOICE , 91
	.byte		VOL   , 35*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W18
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W18
	.byte		N06   , Fn1 
	.byte	W06
	.byte		VOICE , 90
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
@ 033   ----------------------------------------
	.byte		N36   , Cn4 
	.byte	W36
	.byte		        As3 
	.byte	W36
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N48   , Gn3 
	.byte	W12
@ 034   ----------------------------------------
mus_vs_arven_8_034:
	.byte	W36
	.byte		N36   , En3 , v100
	.byte	W42
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte	PEND
@ 035   ----------------------------------------
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , As3 
	.byte	W24
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N48   , Cn4 
	.byte	W12
@ 036   ----------------------------------------
	.byte	W36
	.byte		N36   , Gn4 
	.byte	W42
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
@ 037   ----------------------------------------
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W18
	.byte		N36   , As3 
	.byte	W36
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N48   , Gn3 
	.byte	W12
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_8_034
@ 039   ----------------------------------------
	.byte		N12   , Cn4 , v100
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , As3 
	.byte	W24
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N60   , Cn4 
	.byte	W12
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte		VOICE , 90
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N96   
	.byte	W96
@ 042   ----------------------------------------
	.byte		N48   , As3 
	.byte	W48
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
@ 043   ----------------------------------------
	.byte		N03   , Gn3 
	.byte	W03
	.byte		N09   , As3 
	.byte	W32
	.byte	W01
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
@ 044   ----------------------------------------
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N02   , As2 
	.byte	W02
	.byte		        Cs3 
	.byte	W02
	.byte		        En3 
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        As3 
	.byte	W02
	.byte		        Cs4 
	.byte	W02
	.byte		N72   , En4 
	.byte	W72
@ 045   ----------------------------------------
	.byte		N02   , Gn3 
	.byte	W02
	.byte		        Gs3 
	.byte	W02
	.byte		        As3 
	.byte	W02
	.byte		        Bn3 
	.byte	W02
	.byte		        Cn4 
	.byte	W02
	.byte		        Cs4 
	.byte	W02
	.byte		N84   , Ds4 
	.byte	W84
@ 046   ----------------------------------------
	.byte		N06   , Cn4 
	.byte	W36
	.byte		N60   , Dn4 
	.byte	W60
@ 047   ----------------------------------------
	.byte		N12   , As3 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
@ 048   ----------------------------------------
	.byte		N96   
	.byte	W96
@ 049   ----------------------------------------
	.byte		VOICE , 90
	.byte		VOL   , 20*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N96   , Fn3 
	.byte	W96
@ 050   ----------------------------------------
	.byte		N48   , Gs3 
	.byte	W60
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
@ 051   ----------------------------------------
	.byte	W24
	.byte		N24   , As3 
	.byte	W24
	.byte		N48   , Fn4 
	.byte	W48
@ 052   ----------------------------------------
	.byte		VOL   , 20*mus_vs_arven_mvl/mxv
	.byte		N32   , Gs3 , v092
	.byte	W06
	.byte		VOL   , 20*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        20*mus_vs_arven_mvl/mxv
	.byte		N36   , En3 , v080
	.byte	W06
	.byte		VOL   , 20*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W04
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_arven_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_arven_mvl/mxv
	.byte	W12
@ 053   ----------------------------------------
	.byte	W12
	.byte		VOICE , 91
	.byte		PAN   , c_v+0
	.byte		VOL   , 21*mus_vs_arven_mvl/mxv
	.byte		N03   , Cn3 , v100
	.byte	W12
	.byte		VOL   , 27*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 33*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 38*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 44*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
@ 054   ----------------------------------------
	.byte	W12
	.byte		VOL   , 33*mus_vs_arven_mvl/mxv
	.byte		N03   , Dn3 
	.byte	W12
	.byte		VOL   , 38*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 44*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
@ 055   ----------------------------------------
	.byte		VOICE , 91
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Cs3 
	.byte	W12
	.byte		VOICE , 90
	.byte		VOL   , 60*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		N03   , As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N48   , Cs5 
	.byte	W48
@ 056   ----------------------------------------
mus_vs_arven_8_056:
	.byte	W12
	.byte		N03   , Cs5 , v100
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N48   , Fn5 
	.byte	W48
	.byte	PEND
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_8_056
@ 058   ----------------------------------------
	.byte	W12
	.byte		N03   , Cs5 , v100
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		        An5 
	.byte	W06
@ 059   ----------------------------------------
	.byte		N48   , Cs4 
	.byte	W60
	.byte		N09   , As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
@ 060   ----------------------------------------
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W84
@ 061   ----------------------------------------
	.byte		N60   , Fn5 
	.byte	W60
	.byte		N12   , Gs5 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
@ 062   ----------------------------------------
	.byte		        Gs4 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W84
@ 063   ----------------------------------------
	.byte		VOICE , 90
	.byte		VOL   , 30*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+20
	.byte		N06   , An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N84   , An3 
	.byte	W72
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_8_008
	.byte	GOTO
	 .word	mus_vs_arven_8_B1
mus_vs_arven_8_B2:
@ 065   ----------------------------------------
	.byte	FINE

@**************** Track 9 (Midi-Chn.9) ****************@

mus_vs_arven_9:
	.byte	KEYSH , mus_vs_arven_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 112
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BENDR , 12
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
	.byte		N02   , An4 , v100
	.byte	W06
	.byte		N02   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N02   
	.byte	W12
	.byte		        Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N02   
	.byte	W06
@ 006   ----------------------------------------
	.byte		        An4 
	.byte	W06
	.byte		N02   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N02   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
@ 007   ----------------------------------------
mus_vs_arven_9_007:
	.byte		N02   , An4 , v100
	.byte	W18
	.byte		N02   
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N02   
	.byte	W12
	.byte		N02   
	.byte	W12
	.byte		        Ds5 
	.byte	W18
	.byte		        An4 
	.byte	W06
	.byte	PEND
@ 008   ----------------------------------------
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		VOICE , 116
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Cn4 , v088
	.byte	W06
	.byte		VOICE , 112
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N02   , An4 , v100
	.byte	W06
	.byte		VOICE , 116
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Cn4 , v088
	.byte	W06
	.byte		VOICE , 112
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N02   , Ds5 , v100
	.byte	W06
	.byte		VOICE , 116
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Cn4 , v092
	.byte	W06
	.byte		VOICE , 112
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N02   , Ds5 , v100
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N02   
	.byte	W12
	.byte		N02   
	.byte	W12
	.byte		        Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W06
mus_vs_arven_9_B1:
@ 009   ----------------------------------------
	.byte		VOICE , 113
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N18   , Fn2 , v100
	.byte	W18
	.byte		N06   
	.byte	W78
@ 010   ----------------------------------------
	.byte		N18   , Ds2 
	.byte	W18
	.byte		        Fn2 
	.byte	W18
	.byte		N06   , As2 
	.byte	W24
	.byte		VOICE , 116
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N06   , Cs3 
	.byte	W36
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte		VOICE , 113
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N18   , Cs2 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N36   , Cn2 
	.byte	W60
@ 013   ----------------------------------------
	.byte		N18   , Fn2 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N12   
	.byte	W12
@ 014   ----------------------------------------
	.byte		N18   , Ds2 
	.byte	W18
	.byte		        Fn2 
	.byte	W18
	.byte		N06   
	.byte	W60
@ 015   ----------------------------------------
	.byte		N18   , An2 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fs2 
	.byte	W12
@ 016   ----------------------------------------
	.byte		        Gs2 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N24   
	.byte	W60
@ 017   ----------------------------------------
	.byte	W12
	.byte		        As2 
	.byte	W30
	.byte		N06   
	.byte	W54
@ 018   ----------------------------------------
	.byte	W12
	.byte		N24   
	.byte	W84
@ 019   ----------------------------------------
	.byte	W06
	.byte		VOICE , 110
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-22
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
@ 020   ----------------------------------------
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
@ 021   ----------------------------------------
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N36   , Fs4 
	.byte	W36
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
@ 022   ----------------------------------------
	.byte		N36   , Cn5 
	.byte	W36
	.byte		N06   , As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N36   , Gs4 
	.byte	W36
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
@ 023   ----------------------------------------
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N24   , As4 
	.byte	W24
	.byte		N12   , Cs4 
	.byte	W12
@ 024   ----------------------------------------
	.byte		N36   , Dn4 
	.byte	W36
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N48   , Fn4 
	.byte	W48
@ 025   ----------------------------------------
	.byte		VOICE , 113
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N42   , Gs4 
	.byte	W48
@ 026   ----------------------------------------
	.byte		N03   
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
@ 027   ----------------------------------------
	.byte		N03   , Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
@ 028   ----------------------------------------
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N18   , Cs5 
	.byte	W18
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
@ 029   ----------------------------------------
	.byte	W12
	.byte		N03   , Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 030   ----------------------------------------
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W18
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
@ 031   ----------------------------------------
	.byte	W12
	.byte		VOICE , 111
	.byte		VOL   , 30*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , An4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
@ 032   ----------------------------------------
	.byte	W84
	.byte		VOICE , 113
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Cn3 
	.byte	W12
@ 033   ----------------------------------------
	.byte		VOICE , 119
	.byte		VOL   , 50*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		BEND  , c_v+0
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
@ 034   ----------------------------------------
	.byte	W72
	.byte		        Cn3 
	.byte	W24
@ 035   ----------------------------------------
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N48   , Cn4 
	.byte	W12
@ 036   ----------------------------------------
	.byte	W36
	.byte		BEND  , c_v-6
	.byte		N36   , En4 
	.byte	W02
	.byte		BEND  , c_v-6
	.byte	W02
	.byte		        c_v-6
	.byte	W02
	.byte		        c_v-5
	.byte	W02
	.byte		        c_v+0
	.byte	W52
@ 037   ----------------------------------------
	.byte		        c_v+0
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , En3 
	.byte	W12
@ 038   ----------------------------------------
	.byte	W36
	.byte		N36   , Cn3 
	.byte	W36
	.byte		N24   
	.byte	W24
@ 039   ----------------------------------------
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N02   , Bn2 , v080
	.byte	W02
	.byte		N10   , Cn3 , v100
	.byte	W10
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Gs3 
	.byte	W24
	.byte		N02   , An3 , v080
	.byte	W02
	.byte		N10   , As3 , v100
	.byte	W10
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
@ 040   ----------------------------------------
	.byte	W36
	.byte		N36   , En4 
	.byte	W60
@ 041   ----------------------------------------
	.byte		VOICE , 113
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N96   , Gs3 
	.byte	W96
@ 042   ----------------------------------------
	.byte		N48   
	.byte	W48
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
@ 043   ----------------------------------------
	.byte		N03   , Fn3 
	.byte	W03
	.byte		N09   , Gn3 
	.byte	W32
	.byte	W01
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
@ 044   ----------------------------------------
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N72   , Cs4 
	.byte	W72
@ 045   ----------------------------------------
	.byte		N96   , Gs3 
	.byte	W96
@ 046   ----------------------------------------
	.byte		N06   
	.byte	W24
	.byte		N48   , As3 
	.byte	W48
	.byte		N24   , Cn4 
	.byte	W24
@ 047   ----------------------------------------
	.byte		N12   , Gn3 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
@ 048   ----------------------------------------
	.byte		N96   
	.byte	W96
@ 049   ----------------------------------------
	.byte		VOICE , 112
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N02   , Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W12
	.byte		N02   
	.byte	W12
	.byte		        Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N02   
	.byte	W06
@ 050   ----------------------------------------
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte		N02   , Ds5 
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		N02   
	.byte	W12
	.byte		N02   
	.byte		N02   , Ds5 
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W06
@ 051   ----------------------------------------
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N02   
	.byte		N02   , Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W06
@ 052   ----------------------------------------
	.byte		N02   
	.byte	W18
	.byte		N02   
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N02   
	.byte	W12
	.byte		N02   
	.byte		N02   , Ds5 
	.byte	W12
	.byte		        An4 
	.byte		N02   , Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N02   
	.byte		N02   , Ds5 
	.byte	W06
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
mus_vs_arven_9_055:
	.byte	W12
	.byte		N02   , Gs4 , v100
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		        Cs4 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte	PEND
@ 056   ----------------------------------------
mus_vs_arven_9_056:
	.byte	W12
	.byte		N02   , Gs4 , v100
	.byte	W24
	.byte		        Cs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W24
	.byte		N02   
	.byte	W24
	.byte	PEND
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_9_055
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_9_056
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_9_055
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_9_056
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_9_055
@ 062   ----------------------------------------
	.byte	W12
	.byte		N02   , Gs4 , v100
	.byte	W24
	.byte		        Cs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W24
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_9_007
@ 064   ----------------------------------------
	.byte	W06
	.byte		N02   , An4 , v100
	.byte	W06
	.byte		VOICE , 116
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Cn4 , v088
	.byte	W06
	.byte		VOICE , 112
	.byte		VOL   , 0*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N02   , An4 , v100
	.byte	W06
	.byte		VOICE , 116
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Cn4 , v088
	.byte	W06
	.byte		VOICE , 112
	.byte		VOL   , 0*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N02   , Ds5 , v100
	.byte	W06
	.byte		VOICE , 116
	.byte		VOL   , 25*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Cn4 , v092
	.byte	W06
	.byte		VOICE , 112
	.byte		VOL   , 0*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N02   , Ds5 , v100
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N02   
	.byte	W12
	.byte		N02   
	.byte	W12
	.byte		        Ds5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte	GOTO
	 .word	mus_vs_arven_9_B1
mus_vs_arven_9_B2:
@ 065   ----------------------------------------
	.byte	FINE

@**************** Track 10 (Midi-Chn.11) ****************@

mus_vs_arven_10:
	.byte	KEYSH , mus_vs_arven_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 122
	.byte		VOL   , 75*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BENDR , 12
	.byte		N08   , Cn5 , v080
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W36
@ 001   ----------------------------------------
mus_vs_arven_10_001:
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
mus_vs_arven_10_002:
	.byte		N02   , Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Fs4 , v052
	.byte	W06
	.byte		        Fs4 , v032
	.byte	W06
	.byte		        Fs4 , v048
	.byte	W06
	.byte		        Fs4 , v028
	.byte	W06
	.byte		        Fs4 , v024
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Fs4 , v020
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
mus_vs_arven_10_003:
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte	PEND
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_002
@ 005   ----------------------------------------
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		VOICE , 121
	.byte		VOL   , 75*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Ds4 , v080
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		VOICE , 121
	.byte		VOL   , 75*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Ds4 , v080
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
@ 006   ----------------------------------------
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		VOICE , 121
	.byte		VOL   , 75*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Ds4 , v080
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		VOICE , 121
	.byte		VOL   , 75*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Ds4 , v080
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N02   , Gs4 , v028
	.byte	W06
@ 007   ----------------------------------------
mus_vs_arven_10_007:
	.byte		VOICE , 121
	.byte		VOL   , 75*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , An3 , v068
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		VOICE , 121
	.byte		VOL   , 75*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Fn3 , v068
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte	PEND
@ 008   ----------------------------------------
mus_vs_arven_10_008:
	.byte		VOICE , 121
	.byte		VOL   , 75*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , An3 , v068
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		VOICE , 122
	.byte		VOL   , 80*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N04   , En4 , v100
	.byte	W06
	.byte		N04   
	.byte	W18
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N02   , Gs4 , v052
	.byte	W06
	.byte	PEND
mus_vs_arven_10_B1:
@ 009   ----------------------------------------
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v032
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v028
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Gs4 , v024
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
@ 010   ----------------------------------------
mus_vs_arven_10_010:
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v028
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Gs4 , v024
	.byte	W06
	.byte		N02   
	.byte	W12
	.byte		        Gs4 , v052
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W12
	.byte		        Gs4 , v028
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
mus_vs_arven_10_011:
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v032
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v028
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Gs4 , v024
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
	.byte	PEND
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_010
@ 013   ----------------------------------------
	.byte		VOICE , 122
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Bn3 , v072
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N02   , Gs4 , v032
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		VOICE , 122
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Bn3 , v072
	.byte	W06
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N02   , Gs4 , v032
	.byte	W06
	.byte		VOICE , 122
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Bn3 , v072
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N02   , Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v028
	.byte	W06
	.byte		VOICE , 122
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Bn3 , v072
	.byte	W06
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N02   , Gs4 , v024
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_010
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_011
@ 016   ----------------------------------------
	.byte		VOICE , 122
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Bn3 , v072
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N02   , Gs4 , v032
	.byte	W06
	.byte		VOICE , 122
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Bn3 , v072
	.byte	W06
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N02   , Gs4 , v028
	.byte	W06
	.byte		        Gs4 , v024
	.byte	W06
	.byte		VOICE , 122
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Bn3 , v072
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W12
	.byte		        Gs4 , v028
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_011
@ 018   ----------------------------------------
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v028
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Gs4 , v024
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Gs4 , v020
	.byte	W06
	.byte		        Gs4 , v016
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v016
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_011
@ 020   ----------------------------------------
mus_vs_arven_10_020:
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v028
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v028
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v028
	.byte	W06
	.byte		N02   
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte	PEND
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_011
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_020
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_011
@ 024   ----------------------------------------
	.byte		N02   , Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
@ 025   ----------------------------------------
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
@ 026   ----------------------------------------
mus_vs_arven_10_026:
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte	PEND
@ 027   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_026
@ 028   ----------------------------------------
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v028
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Gs4 , v024
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_026
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_026
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_026
@ 032   ----------------------------------------
	.byte		N02   , Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W24
	.byte		N02   
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		VOICE , 122
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Bn3 , v052
	.byte	W06
	.byte		        Bn3 , v060
	.byte	W06
@ 033   ----------------------------------------
	.byte		        Bn3 , v072
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W08
	.byte		        Gs4 , v032
	.byte	W08
	.byte		        Gs4 , v028
	.byte	W20
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W08
	.byte		        Gs4 , v032
	.byte	W08
	.byte		        Gs4 , v028
	.byte	W08
@ 034   ----------------------------------------
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W12
	.byte		        Gs4 , v052
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v028
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W12
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v052
	.byte	W12
@ 035   ----------------------------------------
	.byte		VOICE , 122
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Bn3 , v072
	.byte	W48
	.byte		N03   
	.byte	W48
@ 036   ----------------------------------------
	.byte		N03   
	.byte	W08
	.byte		        Bn3 , v040
	.byte	W08
	.byte		        Bn3 , v032
	.byte	W08
	.byte		        Bn3 , v020
	.byte	W24
	.byte		        Bn3 , v072
	.byte	W48
@ 037   ----------------------------------------
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v032
	.byte	W12
	.byte		        Gs4 , v052
	.byte	W24
	.byte		VOICE , 122
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Bn3 , v072
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N02   , Gs4 , v032
	.byte	W12
	.byte		        Gs4 , v052
	.byte	W24
@ 038   ----------------------------------------
mus_vs_arven_10_038:
	.byte		N12   , As4 , v060
	.byte	W12
	.byte		N02   , Gs4 , v032
	.byte	W12
	.byte		        Gs4 , v052
	.byte	W24
	.byte		VOICE , 122
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Bn3 , v072
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N02   , Gs4 , v032
	.byte	W12
	.byte		        Gs4 , v052
	.byte	W24
	.byte	PEND
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_038
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_038
@ 041   ----------------------------------------
	.byte		VOICE , 122
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Bn3 , v072
	.byte	W30
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , As4 , v060
	.byte	W06
	.byte		        Bn4 
	.byte	W60
@ 042   ----------------------------------------
mus_vs_arven_10_042:
	.byte		VOICE , 121
	.byte		VOL   , 65*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , An3 , v056
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	PEND
@ 043   ----------------------------------------
	.byte		N12   
	.byte	W30
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , As4 , v060
	.byte	W06
	.byte		        Bn4 
	.byte	W60
@ 044   ----------------------------------------
	.byte	W48
	.byte		VOICE , 122
	.byte		VOL   , 56*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Bn3 , v072
	.byte	W48
@ 045   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_042
@ 046   ----------------------------------------
mus_vs_arven_10_046:
	.byte		N12   , An3 , v056
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	PEND
@ 047   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_046
@ 048   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_046
@ 049   ----------------------------------------
	.byte		N08   , Gn3 , v056
	.byte	W12
	.byte		N08   
	.byte	W06
	.byte		N06   , Cn4 , v040
	.byte	W06
	.byte		N08   
	.byte	W24
	.byte		        Gn3 , v056
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		        Cn4 , v040
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W12
@ 050   ----------------------------------------
	.byte		        Ds4 
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N08   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N08   
	.byte	W12
@ 051   ----------------------------------------
	.byte		        Gn3 
	.byte	W12
	.byte		N08   
	.byte	W06
	.byte		N06   , Cn4 , v040
	.byte	W06
	.byte		N08   
	.byte	W24
	.byte		        Gn3 , v056
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		        Ds4 
	.byte	W12
@ 052   ----------------------------------------
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
@ 053   ----------------------------------------
	.byte		        Gn3 , v080
	.byte	W12
	.byte		N08   
	.byte	W06
	.byte		N06   , Cn4 , v064
	.byte	W06
	.byte		N08   
	.byte	W12
	.byte		VOICE , 120
	.byte		VOL   , 70*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N02   , Gs4 , v032
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v028
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Gs4 , v024
	.byte	W06
	.byte		N12   , As4 , v060
	.byte	W12
@ 054   ----------------------------------------
	.byte		N02   , Gs4 , v052
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v028
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v028
	.byte	W06
	.byte		VOICE , 122
	.byte		VOL   , 75*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N04   , Cn5 , v080
	.byte	W12
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		VOICE , 120
	.byte		VOL   , 75*mus_vs_arven_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N12   , As4 , v060
	.byte	W12
@ 055   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_001
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_002
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_003
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_002
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_003
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_002
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_003
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_002
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_007
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_vs_arven_10_008
	.byte	GOTO
	 .word	mus_vs_arven_10_B1
mus_vs_arven_10_B2:
@ 065   ----------------------------------------
	.byte	FINE

@******************************************************@
	.align	2

mus_vs_arven:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_vs_arven_pri	@ Priority
	.byte	mus_vs_arven_rev	@ Reverb.

	.word	mus_vs_arven_grp

	.word	mus_vs_arven_1
	.word	mus_vs_arven_2
	.word	mus_vs_arven_3
	.word	mus_vs_arven_4
	.word	mus_vs_arven_5
	.word	mus_vs_arven_6
	.word	mus_vs_arven_7
	.word	mus_vs_arven_8
	.word	mus_vs_arven_9
	.word	mus_vs_arven_10

	.end
