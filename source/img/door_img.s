
@{{BLOCK(door)

@=======================================================================
@
@	door, 32x32@4, 
@	+ palette 16 entries, not compressed
@	+ bitmap not compressed
@	Total size: 32 + 512 = 544
@
@	Time-stamp: 2022-07-02, 18:00:38
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.17
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global doorBitmap		@ 512 unsigned chars
	.hidden doorBitmap
doorBitmap:
	.word 0x11112210,0x11211112,0x00000003,0x00000000,0x33333320,0x33333333,0x00000004,0x00000000
	.word 0x44445310,0x33444453,0x00000004,0x00000000,0x00004310,0x32000042,0x00000005,0x00000000
	.word 0x00004360,0x37000047,0x00000008,0x00000000,0x00004390,0x32000042,0x00000004,0x00000000
	.word 0x27728320,0x32277282,0x00000004,0x00000000,0x44445310,0x33444453,0x00000005,0x00000000
	.word 0x00004310,0x32000042,0x00000008,0x00000000,0x00004320,0x37000047,0x00000004,0x00000000
	.word 0x00004310,0x32000042,0x00000004,0x00000000,0x27728310,0x32277282,0x00000005,0x00000000
	.word 0x83222310,0x38832228,0x00000008,0x00000000,0x44445310,0x33444453,0x00000004,0x00000000
	.word 0x33334320,0x3A663342,0x00000004,0x00000000,0x88884860,0x885A8842,0x00000005,0x00000000

	.word 0x883343A0,0x37553347,0x00000008,0x00000000,0x77728320,0x32777282,0x00000004,0x00000000
	.word 0x83322320,0x33883338,0x00000004,0x00000000,0x44445310,0x32444453,0x00000005,0x00000000
	.word 0x33334310,0x32333342,0x00000008,0x00000000,0x83334310,0x37833347,0x00000004,0x00000000
	.word 0x88334310,0x37883347,0x00000004,0x00000000,0x77728310,0x82777282,0x00000005,0x00000000
	.word 0x83222320,0x88832238,0x00000008,0x00000000,0x44445310,0x32444483,0x00000004,0x00000000
	.word 0x33334360,0x32333342,0x00000004,0x00000000,0x833343A0,0x37833347,0x00000005,0x00000000
	.word 0x88334320,0x37883347,0x00000008,0x00000000,0x77728320,0x82777282,0x00000004,0x00000000
	.word 0x32238810,0x88322388,0x00000004,0x00000000,0x55555540,0x55555555,0x00000005,0x00000000

	.section .rodata
	.align	2
	.global doorPal		@ 32 unsigned chars
	.hidden doorPal
doorPal:
	.hword 0x0000,0x2E57,0x2614,0x21D2,0x154C,0x10EA,0x4A30,0x2A36
	.hword 0x198F,0x35AD,0x3DAD,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(door)
