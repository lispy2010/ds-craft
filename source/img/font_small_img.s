
@{{BLOCK(font_small)

@=======================================================================
@
@	font_small, 64x128@4, 
@	+ palette 256 entries, not compressed
@	+ bitmap not compressed
@	Total size: 512 + 4096 = 4608
@
@	Time-stamp: 2022-07-02, 18:06:36
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.17
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global font_smallBitmap		@ 4096 unsigned chars
	.hidden font_smallBitmap
font_smallBitmap:
	.word 0x00000000,0x00000000,0x00010100,0x00000000,0x00000000,0x00000000,0x00000000,0x00001000
	.word 0x00000000,0x00000010,0x00010100,0x00010100,0x00001000,0x00100110,0x00001000,0x00001000
	.word 0x00000000,0x00000010,0x00000000,0x00010100,0x00111100,0x00010110,0x00010100,0x00000000
	.word 0x00000000,0x00000010,0x00000000,0x00111110,0x00000010,0x00010000,0x00001000,0x00000000
	.word 0x00000000,0x00000010,0x00000000,0x00010100,0x00011100,0x00001000,0x00101100,0x00000000
	.word 0x00000000,0x00000010,0x00000000,0x00111110,0x00100000,0x00000100,0x00011010,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00010100,0x00011110,0x00110100,0x00010010,0x00000000
	.word 0x00000000,0x00000010,0x00000000,0x00010100,0x00001000,0x00110010,0x00101100,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x11000000,0x00000110,0x00010010,0x00000000,0x00000000,0x00000000,0x00100000,0x00011100
	.word 0x00100000,0x00001000,0x00001100,0x00001000,0x00000000,0x00000000,0x00010000,0x00100010
	.word 0x00010000,0x00010000,0x00010010,0x00001000,0x00000000,0x00000000,0x00010000,0x00110010
	.word 0x00010000,0x00010000,0x00000000,0x00111110,0x00111110,0x00000000,0x00001000,0x00101010
	.word 0x00010000,0x00010000,0x00000000,0x00001000,0x00000000,0x00000000,0x00000100,0x00100110
	.word 0x00100000,0x00001000,0x00000000,0x00001000,0x00000000,0x00000010,0x00000100,0x00100010

	.word 0x11000000,0x00000110,0x00000000,0x00000000,0x00000000,0x00000000,0x00000010,0x00011100
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00001000,0x00011100,0x00011100,0x00110000,0x00111110,0x00110000,0x00111110,0x00111000
	.word 0x00001100,0x00100010,0x00100010,0x00101000,0x00000010,0x00001000,0x00100010,0x01000100
	.word 0x00001000,0x00100000,0x00100000,0x00100100,0x00011110,0x00000100,0x00100000,0x01000100
	.word 0x00001000,0x00011000,0x00011000,0x00100010,0x00100000,0x00111100,0x00010000,0x00111000
	.word 0x00001000,0x00000100,0x00100000,0x00111110,0x00100000,0x01000100,0x00001000,0x01000100

	.word 0x00001000,0x00000010,0x00100010,0x00100000,0x00100010,0x01000100,0x00001000,0x01000100
	.word 0x00111110,0x00111110,0x00011100,0x00100000,0x00011100,0x00111000,0x00001000,0x00111000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00010000,0x00000000,0x00000100,0x00011100,0x00111100
	.word 0x00011100,0x00000000,0x00000000,0x00001000,0x00000000,0x00001000,0x00100010,0x01000010
	.word 0x00100010,0x00000000,0x00000000,0x00000100,0x00111110,0x00010000,0x00100000,0x01011010
	.word 0x00100010,0x00000001,0x00000010,0x00000010,0x00000000,0x00100000,0x00010000,0x01011010
	.word 0x00111100,0x00000000,0x00000000,0x00000100,0x00000000,0x00010000,0x00001000,0x01111010

	.word 0x00100000,0x00000000,0x00000000,0x00001000,0x00111110,0x00001000,0x00000000,0x00000010
	.word 0x00010000,0x00000001,0x00000010,0x00010000,0x00000000,0x00000100,0x00001000,0x01111100
	.word 0x00001100,0x00000000,0x00000010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00011100,0x00011110,0x00111000,0x00011110,0x01111100,0x01111100,0x00111100,0x00100010
	.word 0x00100010,0x00100010,0x01000100,0x00100010,0x00000100,0x00000100,0x00000010,0x00100010
	.word 0x00111110,0x00011110,0x00000100,0x00100010,0x00011100,0x00011100,0x00110010,0x00111110
	.word 0x00100010,0x00100010,0x00000100,0x00100010,0x00000100,0x00000100,0x00100010,0x00100010

	.word 0x00100010,0x00100010,0x00000100,0x00100010,0x00000100,0x00000100,0x00100010,0x00100010
	.word 0x00100010,0x00100010,0x01000100,0x00100010,0x00000100,0x00000100,0x00100010,0x00100010
	.word 0x00100010,0x00011110,0x00111000,0x00011110,0x01111100,0x00000100,0x00011100,0x00100010
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00011100,0x00100000,0x00100010,0x00000010,0x01000100,0x00100010,0x00011100,0x00011110
	.word 0x00001000,0x00100000,0x00010010,0x00000010,0x01101100,0x00100110,0x00100010,0x00100010
	.word 0x00001000,0x00100000,0x00001110,0x00000010,0x01010100,0x00101010,0x00100010,0x00011110

	.word 0x00001000,0x00100000,0x00010010,0x00000010,0x01000100,0x00110010,0x00100010,0x00000010
	.word 0x00001000,0x00100000,0x00100010,0x00000010,0x01000100,0x00100010,0x00100010,0x00000010
	.word 0x00001000,0x00100010,0x00100010,0x00000010,0x01000100,0x00100010,0x00100010,0x00000010
	.word 0x00011100,0x00011100,0x00100010,0x00111110,0x01000100,0x00100010,0x00011100,0x00000010
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00011100,0x00011110,0x00111100,0x00111110,0x00100010,0x00100010,0x00100010,0x00100010
	.word 0x00100010,0x00100010,0x00000010,0x00001000,0x00100010,0x00100010,0x00100010,0x00010100

	.word 0x00100010,0x00011110,0x00011100,0x00001000,0x00100010,0x00100010,0x00100010,0x00001000
	.word 0x00100010,0x00100010,0x00100000,0x00001000,0x00100010,0x00100010,0x00100010,0x00010100
	.word 0x00100010,0x00100010,0x00100000,0x00001000,0x00100010,0x00010100,0x00101010,0x00100010
	.word 0x00010010,0x00100010,0x00100010,0x00001000,0x00100010,0x00010100,0x00110110,0x00100010
	.word 0x00101100,0x00100010,0x00011100,0x00001000,0x00011100,0x00001000,0x00100010,0x00100010
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00100010,0x00111110,0x00111000,0x00000001,0x00000111,0x00111100,0x00000000,0x00000000

	.word 0x00010100,0x00100000,0x00001000,0x00000010,0x00000100,0x01000010,0x00000000,0x00000000
	.word 0x00001000,0x00010000,0x00001000,0x00000010,0x00000100,0x10011001,0x00000000,0x00000000
	.word 0x00001000,0x00001000,0x00001000,0x00000100,0x00000100,0x10000101,0x00000000,0x00000000
	.word 0x00001000,0x00000100,0x00001000,0x00001000,0x00000100,0x10000101,0x00000000,0x00000000
	.word 0x00001000,0x00000010,0x00001000,0x00001000,0x00000100,0x10011001,0x00000000,0x00000000
	.word 0x00001000,0x00111110,0x00111000,0x00010000,0x00000111,0x01000010,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00111100,0x11111111,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00011100,0x00111100,0x00010110,0x00011110,0x00011100,0x00011010,0x00101100,0x00011010
	.word 0x00100000,0x00100010,0x00101010,0x00100010,0x00100010,0x00100110,0x00110010,0x00100110
	.word 0x00111100,0x00100010,0x00101010,0x00100010,0x00100010,0x00100010,0x00100010,0x00000010
	.word 0x00100010,0x00111100,0x00100010,0x00100010,0x00100010,0x00011110,0x00111100,0x00000010
	.word 0x00111100,0x00100000,0x00100010,0x00100010,0x00011100,0x00000010,0x00100000,0x00000010
	.word 0x00000000,0x00011110,0x00000000,0x00000000,0x00000000,0x00000010,0x00100000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000010,0x00000010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000010,0x00000010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00011010,0x00011010,0x00111100,0x00100010,0x00100010,0x01111100,0x00000000,0x00000000
	.word 0x00100110,0x00100110,0x00000010,0x00010100,0x00100010,0x00100000,0x00000000,0x00000000
	.word 0x00100010,0x00100010,0x00011100,0x00001000,0x00100010,0x00010000,0x00000000,0x00000000
	.word 0x00100010,0x00100010,0x00100000,0x00010100,0x00111100,0x00001000,0x00000000,0x00000000
	.word 0x00011110,0x00100010,0x00011110,0x00100010,0x00100000,0x01111100,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00011110,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00001000,0x00000100,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00001110,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00011100,0x00001000,0x00000100,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00100010,0x00001000,0x00000100,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000010,0x00001000,0x00000100,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00100010,0x00001000,0x00000100,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00011100,0x00001000,0x00001000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00100000,0x00100000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00100000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00101100,0x00100000,0x00100010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00110010,0x00100000,0x00100010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00100010,0x00100000,0x00100010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00100010,0x00100010,0x00100010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00111100,0x00100010,0x00111100,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00011100,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000100,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000100,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00011100,0x00100100,0x00100010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00100010,0x00010100,0x00100010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00111110,0x00001100,0x00100010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000010,0x00010100,0x00010100,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00111100,0x00100100,0x00001000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00011000,0x00000100,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000100,0x00000100,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00011110,0x00000100,0x00100010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000100,0x00000100,0x00100010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000100,0x00000100,0x00101010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000100,0x00000100,0x00101010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000100,0x00001000,0x00111100,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global font_smallPal		@ 512 unsigned chars
	.hidden font_smallPal
font_smallPal:
	.hword 0x0000,0x7FFF,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0421,0x0421,0x0421,0x0421,0x0421,0x0421,0x0421,0x0421
	.hword 0x0842,0x0842,0x0842,0x0842,0x0842,0x0842,0x0842,0x0842
	.hword 0x0C63,0x0C63,0x0C63,0x0C63,0x0C63,0x0C63,0x0C63,0x0C63
	.hword 0x1084,0x1084,0x1084,0x1084,0x1084,0x1084,0x1084,0x1084
	.hword 0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5
	.hword 0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6
	.hword 0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7

	.hword 0x2108,0x2108,0x2108,0x2108,0x2108,0x2108,0x2108,0x2108
	.hword 0x2529,0x2529,0x2529,0x2529,0x2529,0x2529,0x2529,0x2529
	.hword 0x294A,0x294A,0x294A,0x294A,0x294A,0x294A,0x294A,0x294A
	.hword 0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B
	.hword 0x318C,0x318C,0x318C,0x318C,0x318C,0x318C,0x318C,0x318C
	.hword 0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD
	.hword 0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE
	.hword 0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF

	.hword 0x4210,0x4210,0x4210,0x4210,0x4210,0x4210,0x4210,0x4210
	.hword 0x4631,0x4631,0x4631,0x4631,0x4631,0x4631,0x4631,0x4631
	.hword 0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52
	.hword 0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73
	.hword 0x5294,0x5294,0x5294,0x5294,0x5294,0x5294,0x5294,0x5294
	.hword 0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5
	.hword 0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6
	.hword 0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7

	.hword 0x6318,0x6318,0x6318,0x6318,0x6318,0x6318,0x6318,0x6318
	.hword 0x6739,0x6739,0x6739,0x6739,0x6739,0x6739,0x6739,0x6739
	.hword 0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A
	.hword 0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B
	.hword 0x739C,0x739C,0x739C,0x739C,0x739C,0x739C,0x739C,0x739C
	.hword 0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD
	.hword 0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE
	.hword 0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF

@}}BLOCK(font_small)
