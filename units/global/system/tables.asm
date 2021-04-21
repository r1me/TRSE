 processor 6502
	org $1100
	; Starting new memory block at $1100
StartBlock1100
	; LineNumber: 10
	jmp block1
	; LineNumber: 4
Tables_sine256	dc.w $00, $06, $0c, $12, $18, $1f, $25, $2b
	dc.w $31, $37, $3d, $44, $4a, $4f, $55, $5b
	dc.w $61, $67, $6d, $72, $78, $7d, $83, $88
	dc.w $8d, $92, $97, $9c, $a1, $a6, $ab, $af
	dc.w $b4, $b8, $bc, $c1, $c5, $c9, $cc, $d0
	dc.w $d4, $d7, $da, $dd, $e0, $e3, $e6, $e9
	dc.w $eb, $ed, $f0, $f2, $f4, $f5, $f7, $f8
	dc.w $fa, $fb, $fc, $fd, $fd, $fe, $fe, $fe
	dc.w $ff, $fe, $fe, $fe, $fd, $fd, $fc, $fb
	dc.w $fa, $f8, $f7, $f5, $f4, $f2, $f0, $ed
	dc.w $eb, $e9, $e6, $e3, $e0, $dd, $da, $d7
	dc.w $d4, $d0, $cc, $c9, $c5, $c1, $bc, $b8
	dc.w $b4, $af, $ab, $a6, $a1, $9c, $97, $92
	dc.w $8d, $88, $83, $7d, $78, $72, $6d, $67
	dc.w $61, $5b, $55, $4f, $4a, $44, $3d, $37
	dc.w $31, $2b, $25, $1f, $18, $12, $0c, $06
	dc.w $00, $fffa, $fff4, $ffee, $ffe8, $ffe1, $ffdb, $ffd5
	dc.w $ffcf, $ffc9, $ffc3, $ffbc, $ffb6, $ffb1, $ffab, $ffa5
	dc.w $ff9f, $ff99, $ff93, $ff8e, $ff88, $ff83, $ff7d, $ff78
	dc.w $ff73, $ff6e, $ff69, $ff64, $ff5f, $ff5a, $ff55, $ff51
	dc.w $ff4c, $ff48, $ff44, $ff3f, $ff3b, $ff37, $ff34, $ff30
	dc.w $ff2c, $ff29, $ff26, $ff23, $ff20, $ff1d, $ff1a, $ff17
	dc.w $ff15, $ff13, $ff10, $ff0e, $ff0c, $ff0b, $ff09, $ff08
	dc.w $ff06, $ff05, $ff04, $ff03, $ff03, $ff02, $ff02, $ff02
	dc.w $ff01, $ff02, $ff02, $ff02, $ff03, $ff03, $ff04, $ff05
	dc.w $ff06, $ff08, $ff09, $ff0b, $ff0c, $ff0e, $ff10, $ff13
	dc.w $ff15, $ff17, $ff1a, $ff1d, $ff20, $ff23, $ff26, $ff29
	dc.w $ff2c, $ff30, $ff34, $ff37, $ff3b, $ff3f, $ff44, $ff48
	dc.w $ff4c, $ff51, $ff55, $ff5a, $ff5f, $ff64, $ff69, $ff6e
	dc.w $ff73, $ff78, $ff7d, $ff83, $ff88, $ff8e, $ff93, $ff99
	dc.w $ff9f, $ffa5, $ffab, $ffb1, $ffb6, $ffbc, $ffc3, $ffc9
	dc.w $ffcf, $ffd5, $ffdb, $ffe1, $ffe8, $ffee, $fff4, $fffa
	; LineNumber: 5
Tables_sine128	dc.b $00, $03, $06, $09, $0c, $0f, $12, $15
	dc.b $18, $1b, $1e, $21, $24, $27, $2a, $2d
	dc.b $30, $33, $36, $39, $3b, $3e, $41, $43
	dc.b $46, $49, $4b, $4e, $50, $52, $55, $57
	dc.b $59, $5b, $5e, $60, $62, $64, $66, $67
	dc.b $69, $6b, $6c, $6e, $70, $71, $72, $74
	dc.b $75, $76, $77, $78, $79, $7a, $7b, $7b
	dc.b $7c, $7d, $7d, $7e, $7e, $7e, $7e, $7e
	dc.b $7f, $7e, $7e, $7e, $7e, $7e, $7d, $7d
	dc.b $7c, $7b, $7b, $7a, $79, $78, $77, $76
	dc.b $75, $74, $72, $71, $70, $6e, $6c, $6b
	dc.b $69, $67, $66, $64, $62, $60, $5e, $5b
	dc.b $59, $57, $55, $52, $50, $4e, $4b, $49
	dc.b $46, $43, $41, $3e, $3b, $39, $36, $33
	dc.b $30, $2d, $2a, $27, $24, $21, $1e, $1b
	dc.b $18, $15, $12, $0f, $0c, $09, $06, $03
	dc.b $00, $fd, $fa, $f7, $f4, $f1, $ee, $eb
	dc.b $e8, $e5, $e2, $df, $dc, $d9, $d6, $d3
	dc.b $d0, $cd, $ca, $c7, $c5, $c2, $bf, $bd
	dc.b $ba, $b7, $b5, $b2, $b0, $ae, $ab, $a9
	dc.b $a7, $a5, $a2, $a0, $9e, $9c, $9a, $99
	dc.b $97, $95, $94, $92, $90, $8f, $8e, $8c
	dc.b $8b, $8a, $89, $88, $87, $86, $85, $85
	dc.b $84, $83, $83, $82, $82, $82, $82, $82
	dc.b $81, $82, $82, $82, $82, $82, $83, $83
	dc.b $84, $85, $85, $86, $87, $88, $89, $8a
	dc.b $8b, $8c, $8e, $8f, $90, $92, $94, $95
	dc.b $97, $99, $9a, $9c, $9e, $a0, $a2, $a5
	dc.b $a7, $a9, $ab, $ae, $b0, $b2, $b5, $b7
	dc.b $ba, $bd, $bf, $c2, $c5, $c7, $ca, $cd
	dc.b $d0, $d3, $d6, $d9, $dc, $df, $e2, $e5
	dc.b $e8, $eb, $ee, $f1, $f4, $f7, $fa, $fd
	; LineNumber: 6
Tables_sine320	dc.b $80, $82, $84, $87, $89, $8c, $8e, $91
	dc.b $93, $96, $98, $9b, $9d, $a0, $a2, $a4
	dc.b $a7, $a9, $ab, $ae, $b0, $b2, $b5, $b7
	dc.b $b9, $bb, $be, $c0, $c2, $c4, $c6, $c8
	dc.b $ca, $cc, $ce, $d0, $d2, $d4, $d6, $d8
	dc.b $d9, $db, $dd, $de, $e0, $e2, $e3, $e5
	dc.b $e6, $e8, $e9, $ea, $ec, $ed, $ee, $f0
	dc.b $f1, $f2, $f3, $f4, $f5, $f6, $f7, $f7
	dc.b $f8, $f9, $fa, $fa, $fb, $fc, $fc, $fd
	dc.b $fd, $fd, $fe, $fe, $fe, $fe, $fe, $fe
	dc.b $ff, $fe, $fe, $fe, $fe, $fe, $fe, $fd
	dc.b $fd, $fd, $fc, $fc, $fb, $fa, $fa, $f9
	dc.b $f8, $f7, $f7, $f6, $f5, $f4, $f3, $f2
	dc.b $f1, $f0, $ee, $ed, $ec, $ea, $e9, $e8
	dc.b $e6, $e5, $e3, $e2, $e0, $de, $dd, $db
	dc.b $d9, $d8, $d6, $d4, $d2, $d0, $ce, $cc
	dc.b $ca, $c8, $c6, $c4, $c2, $c0, $be, $bb
	dc.b $b9, $b7, $b5, $b2, $b0, $ae, $ab, $a9
	dc.b $a7, $a4, $a2, $a0, $9d, $9b, $98, $96
	dc.b $93, $91, $8e, $8c, $89, $87, $84, $82
	dc.b $80, $7d, $7b, $78, $76, $73, $71, $6e
	dc.b $6c, $69, $67, $64, $62, $5f, $5d, $5b
	dc.b $58, $56, $54, $51, $4f, $4d, $4a, $48
	dc.b $46, $44, $41, $3f, $3d, $3b, $39, $37
	dc.b $35, $33, $31, $2f, $2d, $2b, $29, $27
	dc.b $26, $24, $22, $21, $1f, $1d, $1c, $1a
	dc.b $19, $17, $16, $15, $13, $12, $11, $0f
	dc.b $0e, $0d, $0c, $0b, $0a, $09, $08, $08
	dc.b $07, $06, $05, $05, $04, $03, $03, $02
	dc.b $02, $02, $01, $01, $01, $01, $01, $01
	dc.b $01, $01, $01, $01, $01, $01, $01, $02
	dc.b $02, $02, $03, $03, $04, $05, $05, $06
	dc.b $07, $08, $08, $09, $0a, $0b, $0c, $0d
	dc.b $0e, $0f, $11, $12, $13, $15, $16, $17
	dc.b $19, $1a, $1c, $1d, $1f, $21, $22, $24
	dc.b $26, $27, $29, $2b, $2d, $2f, $31, $33
	dc.b $35, $37, $39, $3b, $3d, $3f, $41, $44
	dc.b $46, $48, $4a, $4d, $4f, $51, $54, $56
	dc.b $58, $5b, $5d, $5f, $62, $64, $67, $69
	dc.b $6c, $6e, $71, $73, $76, $78, $7b, $7d
	; LineNumber: 7
Tables_sineDistort	dc.w $500, $519, $532, $54b, $565, $57e, $597, $5b0
	dc.w $5c9, $5e2, $5fb, $614, $62c, $645, $65d, $675
	dc.w $68d, $6a5, $6bd, $6d5, $6ec, $703, $71a, $731
	dc.w $748, $75e, $774, $78a, $7a0, $7b5, $7ca, $7df
	dc.w $7f3, $808, $81b, $82f, $842, $855, $868, $87a
	dc.w $88c, $89d, $8ae, $8bf, $8cf, $8df, $8ef, $8fe
	dc.w $90d, $91b, $929, $937, $944, $951, $95d, $969
	dc.w $974, $97f, $989, $993, $99d, $9a6, $9af, $9b7
	dc.w $9be, $9c5, $9cc, $9d2, $9d8, $9dd, $9e2, $9e6
	dc.w $9ea, $9ed, $9f0, $9f2, $9f3, $9f5, $9f5, $9f5
	dc.w $9f5, $9f4, $9f3, $9f1, $9ef, $9ec, $9e9, $9e5
	dc.w $9e0, $9dc, $9d6, $9d1, $9ca, $9c3, $9bc, $9b4
	dc.w $9ac, $9a3, $99a, $991, $986, $97c, $971, $965
	dc.w $959, $94d, $940, $933, $925, $917, $909, $8fa
	dc.w $8eb, $8db, $8cb, $8ba, $8a9, $898, $887, $875
	dc.w $862, $850, $83d, $829, $816, $802, $7ed, $7d9
	dc.w $7c4, $7af, $799, $784, $76e, $758, $741, $72b
	dc.w $714, $6fd, $6e5, $6ce, $6b6, $69e, $686, $66e
	dc.w $656, $63e, $625, $60c, $5f4, $5db, $5c2, $5a9
	dc.w $590, $576, $55d, $544, $52b, $511, $4f8, $4df
	dc.w $4c6, $4ac, $493, $47a, $461, $448, $42f, $416
	dc.w $3fd, $3e4, $3cc, $3b3, $39b, $383, $36b, $353
	dc.w $33b, $323, $30c, $2f5, $2de, $2c7, $2b1, $29a
	dc.w $284, $26f, $259, $244, $22f, $21a, $206, $1f2
	dc.w $1de, $1ca, $1b7, $1a4, $192, $180, $16e, $15d
	dc.w $14c, $13b, $12b, $11b, $10b, $fc, $ee, $df
	dc.w $d2, $c4, $b7, $ab, $9f, $93, $88, $7d
	dc.w $73, $69, $5f, $56, $4e, $46, $3f, $38
	dc.w $31, $2b, $26, $20, $1c, $18, $14, $11
	dc.w $0f, $0d, $0b, $0a, $0a, $0a, $0a, $0b
	dc.w $0c, $0e, $11, $14, $17, $1b, $20, $25
	dc.w $2a, $30, $37, $3e, $45, $4d, $55, $5e
	dc.w $68, $71, $7c, $86, $91, $9d, $a9, $b6
	dc.w $c3, $d0, $de, $ec, $fb, $10a, $119, $129
	dc.w $139, $14a, $15b, $16c, $17e, $190, $1a2, $1b5
	dc.w $1c8, $1db, $1ef, $203, $218, $22c, $241, $256
	dc.w $26c, $282, $298, $2ae, $2c4, $2db, $2f2, $309
	dc.w $320, $338, $350, $368, $380, $398, $3b0, $3c9
	dc.w $3e1, $3fa, $413, $42c, $445, $45e, $477, $490
	dc.w $4a9, $4c2, $4dc, $4f5, $50e, $528, $541, $55a
	dc.w $573, $58c, $5a6, $5bf, $5d8, $5f0, $609, $622
	dc.w $63b, $653, $66b, $683, $69b, $6b3, $6cb, $6e2
	dc.w $6fa, $711, $728, $73e, $755, $76b, $781, $797
	dc.w $7ac, $7c1, $7d6, $7eb, $7ff, $813, $827, $83a
	dc.w $84d, $860, $872, $884, $896, $8a7, $8b8, $8c9
	dc.w $8d9, $8e9, $8f8, $907, $916, $924, $931, $93f
	dc.w $94c, $958, $964, $96f, $97b, $985, $98f, $999
	dc.w $9a2, $9ab, $9b3, $9bb, $9c3, $9c9, $9d0, $9d6
	dc.w $9db, $9e0, $9e4, $9e8, $9ec, $9ef, $9f1, $9f3
	dc.w $9f4, $9f5, $9f5, $9f5, $9f5, $9f4, $9f2, $9f0
	dc.w $9ed, $9ea, $9e6, $9e2, $9de, $9d9, $9d3, $9cd
	dc.w $9c6, $9bf, $9b8, $9b0, $9a7, $99e, $995, $98b
	dc.w $980, $976, $96a, $95e, $952, $946, $939, $92b
	dc.w $91d, $90f, $900, $8f1, $8e1, $8d1, $8c1, $8b0
	dc.w $89f, $88e, $87c, $86a, $857, $845, $831, $81e
	dc.w $80a, $7f6, $7e1, $7cd, $7b8, $7a2, $78d, $777
	dc.w $761, $74b, $734, $71d, $706, $6ef, $6d8, $6c0
	dc.w $6a8, $690, $678, $660, $648, $62f, $617, $5fe
	dc.w $5e5, $5cc, $5b3, $59a, $581, $568, $54e, $535
	dc.w $51c, $503, $4e9, $4d0, $4b7, $49e, $484, $46b
	dc.w $452, $439, $420, $407, $3ee, $3d6, $3bd, $3a5
	dc.w $38d, $375, $35d, $345, $32d, $316, $2fe, $2e7
	dc.w $2d1, $2ba, $2a4, $28d, $278, $262, $24d, $238
	dc.w $223, $20e, $1fa, $1e6, $1d2, $1bf, $1ac, $19a
	dc.w $187, $175, $164, $153, $142, $132, $121, $112
	dc.w $103, $f4, $e5, $d7, $ca, $bd, $b0, $a3
	dc.w $98, $8c, $81, $77, $6d, $63, $5a, $51
	dc.w $49, $42, $3a, $34, $2d, $28, $23, $1e
	dc.w $1a, $16, $12, $10, $0d, $0c, $0a, $0a
	dc.w $0a, $0a, $0b, $0c, $0e, $10, $13, $16
	dc.w $1a, $1e, $23, $28, $2e, $34, $3b, $42
	dc.w $4a, $52, $5a, $64, $6d, $77, $82, $8d
	dc.w $98, $a4, $b0, $bd, $ca, $d8, $e6, $f4
	dc.w $103, $113, $122, $132, $143, $154, $165, $176
	dc.w $188, $19a, $1ad, $1c0, $1d3, $1e7, $1fb, $20f
	dc.w $224, $238, $24e, $263, $279, $28e, $2a5, $2bb
	dc.w $2d2, $2e8, $2ff, $317, $32e, $346, $35e, $376
	dc.w $38e, $3a6, $3be, $3d7, $3f0, $408, $421, $43a
	dc.w $453, $46c, $485, $49f, $4b8, $4d1, $4ea, $504
	dc.w $51d, $536, $550, $569, $582, $59b, $5b4, $5cd
	dc.w $5e6, $5ff, $618, $630, $649, $661, $679, $692
	dc.w $6a9, $6c1, $6d9, $6f0, $707, $71e, $735, $74c
	dc.w $762, $778, $78e, $7a3, $7b9, $7ce, $7e2, $7f7
	dc.w $80b, $81f, $832, $845, $858, $86b, $87d, $88f
	dc.w $8a0, $8b1, $8c2, $8d2, $8e2, $8f2, $901, $910
	dc.w $91e, $92c, $939, $946, $953, $95f, $96b, $976
	dc.w $981, $98b, $995, $99f, $9a7, $9b0, $9b8, $9c0
	dc.w $9c7, $9cd, $9d3, $9d9, $9de, $9e3, $9e7, $9ea
	dc.w $9ed, $9f0, $9f2, $9f4, $9f5, $9f5, $9f5, $9f5
	dc.w $9f4, $9f3, $9f1, $9ee, $9eb, $9e8, $9e4, $9e0
	dc.w $9db, $9d5, $9cf, $9c9, $9c2, $9bb, $9b3, $9ab
	dc.w $9a2, $999, $98f, $985, $97a, $96f, $963, $957
	dc.w $94b, $93e, $931, $923, $915, $906, $8f7, $8e8
	dc.w $8d8, $8c8, $8b7, $8a7, $895, $884, $872, $85f
	dc.w $84c, $839, $826, $812, $7fe, $7ea, $7d5, $7c0
	dc.w $7ab, $796, $780, $76a, $754, $73d, $727, $710
	dc.w $6f9, $6e1, $6ca, $6b2, $69a, $682, $66a, $652
	dc.w $639, $621, $608, $5ef, $5d7, $5be, $5a4, $58b
	dc.w $572, $559, $540, $526, $50d, $4f4, $4db, $4c1
	dc.w $4a8, $48f, $476, $45d, $443, $42a, $412, $3f9
	dc.w $3e0, $3c7, $3af, $397, $37f, $366, $34f, $337
	dc.w $31f, $308, $2f1, $2da, $2c3, $2ad, $297, $281
	dc.w $26b, $255, $240, $22b, $217, $202, $1ee, $1db
	dc.w $1c7, $1b4, $1a1, $18f, $17d, $16b, $15a, $149
	dc.w $138, $128, $118, $109, $fa, $eb, $dd, $cf
	dc.w $c2, $b5, $a9, $9d, $91, $86, $7b, $71
	dc.w $67, $5e, $55, $4d, $45, $3d, $36, $30
	dc.w $2a, $25, $20, $1b, $17, $14, $11, $0e
	dc.w $0c, $0b, $0a, $0a, $0a, $0a, $0b, $0d
	dc.w $0f, $11, $14, $18, $1c, $21, $26, $2b
	dc.w $31, $38, $3f, $46, $4e, $57, $60, $69
	dc.w $73, $7d, $88, $93, $9f, $ab, $b8, $c5
	dc.w $d2, $e0, $ee, $fd, $10c, $11c, $12c, $13c
	dc.w $14c, $15e, $16f, $181, $193, $1a5, $1b8, $1cb
	dc.w $1df, $1f3, $207, $21b, $230, $245, $25a, $270
	dc.w $285, $29b, $2b2, $2c8, $2df, $2f6, $30d, $324
	dc.w $33c, $354, $36c, $384, $39c, $3b4, $3cd, $3e5
	dc.w $3fe, $417, $430, $449, $462, $47b, $494, $4ad
	dc.w $4c7, $4e0, $4f9, $513, $52c, $545, $55e, $578
	dc.w $591, $5aa, $5c3, $5dc, $5f5, $60d, $626, $63f
	dc.w $657, $66f, $688, $69f, $6b7, $6cf, $6e6, $6fe
	dc.w $715, $72c, $742, $759, $76f, $785, $79a, $7b0
	dc.w $7c5, $7da, $7ee, $803, $816, $82a, $83d, $850
	dc.w $863, $875, $887, $899, $8aa, $8bb, $8cb, $8dc
	dc.w $8eb, $8fb, $909, $918, $926, $934, $941, $94e
	dc.w $95a, $966, $971, $97c, $987, $991, $99b, $9a4
	dc.w $9ad, $9b5, $9bc, $9c4, $9ca, $9d1, $9d7, $9dc
	dc.w $9e1, $9e5, $9e9, $9ec, $9ef, $9f1, $9f3, $9f4
	; LineNumber: 8
Tables_bits	dc.b $01, $02, $04, $08, $010, $020, $040, $080
block1
	; End of program
	; Ending memory block
EndBlock1100
