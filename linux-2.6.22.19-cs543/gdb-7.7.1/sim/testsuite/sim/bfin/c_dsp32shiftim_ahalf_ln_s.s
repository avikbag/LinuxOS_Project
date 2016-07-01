//Original:/testcases/core/c_dsp32shiftim_ahalf_ln_s/c_dsp32shiftim_ahalf_ln_s.dsp
// Spec Reference: dspshiftimm dreg_lo(hi) = ashift (dreg_lo(hi) by imm5) saturated
# mach: bfin

.include "testutils.inc"
	start



// Ashift : neg data, count (+)=left (half reg)
// d_lo = ashft (d_lo BY d_lo)
// RLx by RLx
imm32 r0, 0x1000c000;
imm32 r1, 0x1000c001;
imm32 r2, 0x1000c002;
imm32 r3, 0x1000c003;
imm32 r4, 0x1000c004;
imm32 r5, 0x1000c005;
imm32 r6, 0x1000c006;
imm32 r7, 0x1000c007;
R0.L = R0.L << 1 (S);
R1.L = R1.L << 1 (S);
R2.L = R2.L << 1 (S);
R3.L = R3.L << 1 (S);
R4.L = R4.L << 1 (S);
R5.L = R5.L << 1 (S);
R6.L = R6.L << 1 (S);
R7.L = R7.L << 1 (S);
CHECKREG r0, 0x10008000;
CHECKREG r1, 0x10008002;
CHECKREG r2, 0x10008004;
CHECKREG r3, 0x10008006;
CHECKREG r4, 0x10008008;
CHECKREG r5, 0x1000800A;
CHECKREG r6, 0x1000800C;
CHECKREG r7, 0x1000800E;

imm32 r0, 0x20008001;
imm32 r1, 0x20000001;
imm32 r2, 0x2000d002;
imm32 r3, 0x2000e003;
imm32 r4, 0x2000f004;
imm32 r5, 0x2000c005;
imm32 r6, 0x2000d006;
imm32 r7, 0x2000e007;
R7.L = R0.L << 1 (S);
R6.L = R1.L << 1 (S);
R5.L = R2.L << 1 (S);
R4.L = R3.L << 1 (S);
R3.L = R4.L << 1 (S);
R2.L = R5.L << 1 (S);
R1.L = R6.L << 1 (S);
R0.L = R7.L << 1 (S);

imm32 r0, 0x3000c001;
imm32 r1, 0x3000d001;
imm32 r2, 0x3000000f;
imm32 r3, 0x3000e003;
imm32 r4, 0x3000f004;
imm32 r5, 0x3000f005;
imm32 r6, 0x3000f006;
imm32 r7, 0x3000f007;
R6.L = R0.L << 12 (S);
R7.L = R1.L << 12 (S);
R5.L = R2.L << 12 (S);
R4.L = R3.L << 12 (S);
R3.L = R4.L << 12 (S);
R2.L = R5.L << 12 (S);
R1.L = R6.L << 12 (S);
R0.L = R7.L << 12 (S);
CHECKREG r1, 0x30008000;
CHECKREG r0, 0x30008000;
CHECKREG r2, 0x30007FFF;
CHECKREG r3, 0x30008000;
CHECKREG r4, 0x30008000;
CHECKREG r5, 0x30007FFF;
CHECKREG r6, 0x30008000;
CHECKREG r7, 0x30008000;

imm32 r0, 0x40009001;
imm32 r1, 0x4000a001;
imm32 r2, 0x4000b002;
imm32 r3, 0x40000010;
imm32 r4, 0x4000c004;
imm32 r5, 0x4000d005;
imm32 r6, 0x4000e006;
imm32 r7, 0x4000f007;
R5.L = R0.L << 13 (S);
R6.L = R1.L << 13 (S);
R7.L = R2.L << 13 (S);
R0.L = R3.L << 13 (S);
R1.L = R4.L << 13 (S);
R2.L = R5.L << 13 (S);
R3.L = R6.L << 13 (S);
R4.L = R7.L << 13 (S);
CHECKREG r0, 0x40007FFF;
CHECKREG r1, 0x40008000;
CHECKREG r2, 0x40008000;
CHECKREG r3, 0x40008000;
CHECKREG r4, 0x40008000;
CHECKREG r5, 0x40008000;
CHECKREG r6, 0x40008000;
CHECKREG r7, 0x40008000;

imm32 r0, 0x00005000;
imm32 r1, 0x00015000;
imm32 r2, 0x00025000;
imm32 r3, 0x00035000;
imm32 r4, 0x00045000;
imm32 r5, 0x00055000;
imm32 r6, 0x00065000;
imm32 r7, 0x00075500;
R0.L = R0.H << 10 (S);
R1.L = R1.H << 10 (S);
R2.L = R2.H << 10 (S);
R3.L = R3.H << 10 (S);
R4.L = R4.H << 10 (S);
R5.L = R5.H << 10 (S);
R6.L = R6.H << 10 (S);
R7.L = R7.H << 10 (S);
CHECKREG r0, 0x00000000;
CHECKREG r1, 0x00010400;
CHECKREG r2, 0x00020800;
CHECKREG r3, 0x00030C00;
CHECKREG r4, 0x00041000;
CHECKREG r5, 0x00051400;
CHECKREG r6, 0x00061800;
CHECKREG r7, 0x00071C00;

imm32 r0, 0x90010000;
imm32 r1, 0x90010001;
imm32 r2, 0x90020000;
imm32 r3, 0x90030000;
imm32 r4, 0x90040000;
imm32 r5, 0x90050000;
imm32 r6, 0x90060000;
imm32 r7, 0x90070000;
R2.L = R0.H << 11 (S);
R3.L = R1.H << 11 (S);
R4.L = R2.H << 11 (S);
R5.L = R3.H << 11 (S);
R6.L = R4.H << 11 (S);
R7.L = R5.H << 11 (S);
R0.L = R6.H << 11 (S);
R1.L = R7.H << 11 (S);
CHECKREG r0, 0x90018000;
CHECKREG r1, 0x90018000;
CHECKREG r2, 0x90028000;
CHECKREG r3, 0x90038000;
CHECKREG r4, 0x90048000;
CHECKREG r5, 0x90058000;
CHECKREG r6, 0x90068000;
CHECKREG r7, 0x90078000;


imm32 r0, 0xa0010600;
imm32 r1, 0xa0010600;
imm32 r2, 0xa002060f;
imm32 r3, 0xa0030600;
imm32 r4, 0xa0040600;
imm32 r5, 0xa0050600;
imm32 r6, 0xa0060600;
imm32 r7, 0xa0070600;
R0.L = R0.H << 12 (S);
R1.L = R1.H << 12 (S);
R2.L = R2.H << 12 (S);
R3.L = R3.H << 12 (S);
R4.L = R4.H << 12 (S);
R5.L = R5.H << 12 (S);
R6.L = R6.H << 12 (S);
R7.L = R7.H << 12 (S);
CHECKREG r0, 0xA0018000;
CHECKREG r1, 0xA0018000;
CHECKREG r2, 0xA0028000;
CHECKREG r3, 0xA0038000;
CHECKREG r4, 0xA0048000;
CHECKREG r5, 0xA0058000;
CHECKREG r6, 0xA0068000;
CHECKREG r7, 0xA0078000;

imm32 r0, 0xc0010701;
imm32 r1, 0xc0010701;
imm32 r2, 0xc0020702;
imm32 r3, 0xc0030710;
imm32 r4, 0xc0040704;
imm32 r5, 0xc0050705;
imm32 r6, 0xc0060706;
imm32 r7, 0xc0070707;
R0.L = R0.H << 13 (S);
R1.L = R1.H << 13 (S);
R2.L = R2.H << 13 (S);
R3.L = R3.H << 13 (S);
R4.L = R4.H << 13 (S);
R5.L = R5.H << 13 (S);
R6.L = R6.H << 13 (S);
R7.L = R7.H << 13 (S);
CHECKREG r0, 0xC0018000;
CHECKREG r1, 0xC0018000;
CHECKREG r2, 0xC0028000;
CHECKREG r3, 0xC0038000;
CHECKREG r4, 0xC0048000;
CHECKREG r5, 0xC0058000;
CHECKREG r6, 0xC0068000;
CHECKREG r7, 0xC0078000;

imm32 r0, 0x00008000;
imm32 r1, 0x00008001;
imm32 r2, 0x00008002;
imm32 r3, 0x00008003;
imm32 r4, 0x00008004;
imm32 r5, 0x00008005;
imm32 r6, 0x00008006;
imm32 r7, 0x00008007;
R0.H = R0.L << 0 (S);
R1.H = R1.L << 1 (S);
R2.H = R2.L << 2 (S);
R3.H = R3.L << 3 (S);
R4.H = R4.L << 4 (S);
R5.H = R5.L << 5 (S);
R6.H = R6.L << 6 (S);
R7.H = R7.L << 7 (S);
CHECKREG r0, 0x80008000;
CHECKREG r1, 0x80008001;
CHECKREG r2, 0x80008002;
CHECKREG r3, 0x80008003;
CHECKREG r4, 0x80008004;
CHECKREG r5, 0x80008005;
CHECKREG r6, 0x80008006;
CHECKREG r7, 0x80008007;

imm32 r0, 0x0000d001;
imm32 r1, 0x00000001;
imm32 r2, 0x0000d002;
imm32 r3, 0x0000d003;
imm32 r4, 0x0000d004;
imm32 r5, 0x0000d005;
imm32 r6, 0x0000d006;
imm32 r7, 0x0000d007;
R2.H = R0.L << 8 (S);
R3.H = R1.L << 9 (S);
R4.H = R2.L << 10 (S);
R5.H = R3.L << 11 (S);
R6.H = R4.L << 12 (S);
R7.H = R5.L << 13 (S);
R0.H = R6.L << 14 (S);
R1.H = R7.L << 15 (S);
CHECKREG r0, 0x8000D001;
CHECKREG r1, 0x80000001;
CHECKREG r2, 0x8000D002;
CHECKREG r3, 0x0200D003;
CHECKREG r4, 0x8000D004;
CHECKREG r5, 0x8000D005;
CHECKREG r6, 0x8000D006;
CHECKREG r7, 0x8000D007;

imm32 r0, 0x0000e001;
imm32 r1, 0x0000e001;
imm32 r2, 0x0000000f;
imm32 r3, 0x0000e003;
imm32 r4, 0x0000e004;
imm32 r5, 0x0000e005;
imm32 r6, 0x0000e006;
imm32 r7, 0x0000e007;
R0.H = R0.L << 12 (S);
R1.H = R1.L << 12 (S);
R2.H = R2.L << 12 (S);
R3.H = R3.L << 12 (S);
R4.H = R4.L << 12 (S);
R5.H = R5.L << 12 (S);
R6.H = R6.L << 12 (S);
R7.H = R7.L << 12 (S);
CHECKREG r0, 0x8000E001;
CHECKREG r1, 0x8000E001;
CHECKREG r2, 0x7FFF000F;
CHECKREG r3, 0x8000E003;
CHECKREG r4, 0x8000E004;
CHECKREG r5, 0x8000E005;
CHECKREG r6, 0x8000E006;
CHECKREG r7, 0x8000E007;

imm32 r0, 0x0000f001;
imm32 r1, 0x0000f001;
imm32 r2, 0x0000f002;
imm32 r3, 0x00000010;
imm32 r4, 0x0000f004;
imm32 r5, 0x0000f005;
imm32 r6, 0x0000f006;
imm32 r7, 0x0000f007;
R5.H = R0.L << 13 (S);
R6.H = R1.L << 13 (S);
R7.H = R2.L << 13 (S);
R0.H = R3.L << 13 (S);
R1.H = R4.L << 13 (S);
R2.H = R5.L << 13 (S);
R3.H = R6.L << 13 (S);
R4.H = R7.L << 13 (S);
CHECKREG r0, 0x7FFFF001;
CHECKREG r1, 0x8000F001;
CHECKREG r2, 0x8000F002;
CHECKREG r3, 0x80000010;
CHECKREG r4, 0x8000F004;
CHECKREG r5, 0x8000F005;
CHECKREG r6, 0x8000F006;
CHECKREG r7, 0x8000F007;

// d_lo = ashift (d_hi BY d_lo)
// RHx by RLx
imm32 r0, 0x90000000;
imm32 r1, 0x90010000;
imm32 r2, 0x90020000;
imm32 r3, 0x90030000;
imm32 r4, 0x90040000;
imm32 r5, 0x90050000;
imm32 r6, 0x90060000;
imm32 r7, 0x90070000;
R4.H = R0.H << 10 (S);
R5.H = R1.H << 10 (S);
R6.H = R2.H << 10 (S);
R7.H = R3.H << 10 (S);
R0.H = R4.H << 10 (S);
R1.H = R5.H << 10 (S);
R2.H = R6.H << 10 (S);
R3.H = R7.H << 10 (S);
CHECKREG r0, 0x80000000;
CHECKREG r1, 0x80000000;
CHECKREG r2, 0x80000000;
CHECKREG r3, 0x80000000;
CHECKREG r4, 0x80000000;
CHECKREG r5, 0x80000000;
CHECKREG r6, 0x80000000;
CHECKREG r7, 0x80000000;

imm32 r0, 0xa0010000;
imm32 r1, 0x00010001;
imm32 r2, 0xa0020000;
imm32 r3, 0xa0030000;
imm32 r4, 0xa0040000;
imm32 r5, 0xa0050000;
imm32 r6, 0xa0060000;
imm32 r7, 0xa0070000;
R7.H = R0.H << 11 (S);
R0.H = R1.H << 11 (S);
R1.H = R2.H << 11 (S);
R2.H = R3.H << 11 (S);
R3.H = R4.H << 11 (S);
R4.H = R5.H << 11 (S);
R5.H = R6.H << 11 (S);
R6.H = R7.H << 11 (S);
CHECKREG r0, 0x08000000;
CHECKREG r1, 0x80000001;
CHECKREG r2, 0x80000000;
CHECKREG r3, 0x80000000;
CHECKREG r4, 0x80000000;
CHECKREG r5, 0x80000000;
CHECKREG r6, 0x80000000;
CHECKREG r7, 0x80000000;


imm32 r0, 0xb0010000;
imm32 r1, 0xb0010000;
imm32 r2, 0xb002000f;
imm32 r3, 0xb0030000;
imm32 r4, 0xb0040000;
imm32 r5, 0xb0050000;
imm32 r6, 0xb0060000;
imm32 r7, 0xb0070000;
R6.H = R0.H << 12 (S);
R7.H = R1.H << 12 (S);
R0.H = R2.H << 12 (S);
R1.H = R3.H << 12 (S);
R2.H = R4.H << 12 (S);
R3.H = R5.H << 12 (S);
R4.H = R6.H << 12 (S);
R5.H = R7.H << 12 (S);
CHECKREG r0, 0x80000000;
CHECKREG r1, 0x80000000;
CHECKREG r2, 0x8000000F;
CHECKREG r3, 0x80000000;
CHECKREG r4, 0x80000000;
CHECKREG r5, 0x80000000;
CHECKREG r6, 0x80000000;
CHECKREG r7, 0x80000000;

imm32 r0, 0xd0010000;
imm32 r1, 0xd0010000;
imm32 r2, 0xd0020000;
imm32 r3, 0xd0030010;
imm32 r4, 0xd0040000;
imm32 r5, 0xd0050000;
imm32 r6, 0xd0060000;
imm32 r7, 0xd0070000;
R5.H = R0.H << 3 (S);
R6.H = R1.H << 3 (S);
R7.H = R2.H << 3 (S);
R0.H = R3.H << 3 (S);
R1.H = R4.H << 3 (S);
R2.H = R5.H << 3 (S);
R3.H = R6.H << 3 (S);
R4.H = R7.H << 3 (S);
CHECKREG r0, 0x80000000;
CHECKREG r1, 0x80000000;
CHECKREG r2, 0x80000000;
CHECKREG r3, 0x80000010;
CHECKREG r4, 0x80000000;
CHECKREG r5, 0x80000000;
CHECKREG r6, 0x80000000;
CHECKREG r7, 0x80000000;
pass
