
#include <Arduino.h>
#define TOTAL_BITS 32
#define FIXED_FBITS 10
#define SIGNED
#include "FixedNum.h"


#define INPUT_SIZE 64
#define OUTPUT_SIZE 5
#define NUMBER_OF_NEURONS 108

/* Instance array must be global
 * Attributes MUST be sorted in instance array in the following order:
 * mean_vel
 * std_vel
 * temp_ste
 * temp_mag
 * temp_roms
 * temp_mean
 * temp_tc
 * temp_zcr
 * temp_itv
 * temp_var
 * temp_std
 * temp_skewness
 * temp_kurtosis
 * temp_ce
 * temp_ce_norm
 * temp_crest
 * temp_max2min
 * temp_mag2rms
 * temp_rms2
 * temp_rssl
 * temp_mnp
 * temp_adp
 * temp_ety
 * temp_md
 * temp_iqr2
 * spec_f0
 * spec_ste
 * spec_mag
 * spec_sc
 * spec_si
 * spec_sim
 * spec_sfm
 * spec_flux
 * spec_sro
 * spec_var
 * spec_std
 * spec_skw
 * spec_kts
 * spec_max2min
 * spec_mag2rms
 * spec_mnp
 * spec_adp
 * spec_ety
 * spec_cov1
 * spec_cov2
 * spec_cov3
 * spec_peaks1
 * spec_peaks2
 * spec_peaks3
 * spec_peaks4
 * spec_peaks5
 * spec_peaks6
 * spec_peaks7
 * spec_peaks8
 * spec_peaks9
 * spec_peaks10
 * spec_peaks11
 * spec_peaks12
 * spec_power1
 * spec_power2
 * spec_power3
 * spec_power4
 * spec_power5
 * spec_iqr2
 */
FixedNum instance[INPUT_SIZE+1];

const int m_outputs[OUTPUT_SIZE] = {103, 104, 105, 107, 106};

const FixedNum m_attributeBases[INPUT_SIZE] = {(FixedNum)0x0000020e, (FixedNum)0x000001e2, (FixedNum)0x00000200, (FixedNum)0x00000202, (FixedNum)0x00000201, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000201, (FixedNum)0x0000020b, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000201, (FixedNum)0x00000201, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001e9, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000201, (FixedNum)0x000001fc, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000214, (FixedNum)0x000001de, (FixedNum)0x000001f6, (FixedNum)0x00000200, (FixedNum)0x000001e6, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000203, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001d8, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000191, (FixedNum)0x00000200, (FixedNum)0x00000202};
const FixedNum m_attributeRanges[INPUT_SIZE] = {(FixedNum)0x000001f2, (FixedNum)0x000001e2, (FixedNum)0x00000200, (FixedNum)0x000001fe, (FixedNum)0x000001ff, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001ff, (FixedNum)0x000001f5, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001ff, (FixedNum)0x000001ff, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001e9, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001ff, (FixedNum)0x000001fc, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001ec, (FixedNum)0x000001de, (FixedNum)0x000001f6, (FixedNum)0x00000200, (FixedNum)0x000001e6, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001fd, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001d8, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000191, (FixedNum)0x00000200, (FixedNum)0x000001fe};

const FixedNum *m_weights[NUMBER_OF_NEURONS];
const int *m_connections[NUMBER_OF_NEURONS];

const int tmp_connections0[1] = {0};

const int tmp_connections1[1] = {0};

const int tmp_connections2[1] = {0};

const int tmp_connections3[1] = {0};

const int tmp_connections4[1] = {0};

const int tmp_connections5[1] = {0};

const int tmp_connections6[1] = {0};

const int tmp_connections7[1] = {0};

const int tmp_connections8[1] = {0};

const int tmp_connections9[1] = {0};

const int tmp_connections10[1] = {0};

const int tmp_connections11[1] = {0};

const int tmp_connections12[1] = {0};

const int tmp_connections13[1] = {0};

const int tmp_connections14[1] = {0};

const int tmp_connections15[1] = {0};

const int tmp_connections16[1] = {0};

const int tmp_connections17[1] = {0};

const int tmp_connections18[1] = {0};

const int tmp_connections19[1] = {0};

const int tmp_connections20[1] = {0};

const int tmp_connections21[1] = {0};

const int tmp_connections22[1] = {0};

const int tmp_connections23[1] = {0};

const int tmp_connections24[1] = {0};

const int tmp_connections25[1] = {0};

const int tmp_connections26[1] = {0};

const int tmp_connections27[1] = {0};

const int tmp_connections28[1] = {0};

const int tmp_connections29[1] = {0};

const int tmp_connections30[1] = {0};

const int tmp_connections31[1] = {0};

const int tmp_connections32[1] = {0};

const int tmp_connections33[1] = {0};

const int tmp_connections34[1] = {0};

const int tmp_connections35[1] = {0};

const int tmp_connections36[1] = {0};

const int tmp_connections37[1] = {0};

const int tmp_connections38[1] = {0};

const int tmp_connections39[1] = {0};

const int tmp_connections40[1] = {0};

const int tmp_connections41[1] = {0};

const int tmp_connections42[1] = {0};

const int tmp_connections43[1] = {0};

const int tmp_connections44[1] = {0};

const int tmp_connections45[1] = {0};

const int tmp_connections46[1] = {0};

const int tmp_connections47[1] = {0};

const int tmp_connections48[1] = {0};

const int tmp_connections49[1] = {0};

const int tmp_connections50[1] = {0};

const int tmp_connections51[1] = {0};

const int tmp_connections52[1] = {0};

const int tmp_connections53[1] = {0};

const int tmp_connections54[1] = {0};

const int tmp_connections55[1] = {0};

const int tmp_connections56[1] = {0};

const int tmp_connections57[1] = {0};

const int tmp_connections58[1] = {0};

const int tmp_connections59[1] = {0};

const int tmp_connections60[1] = {0};

const int tmp_connections61[1] = {0};

const int tmp_connections62[1] = {0};

const int tmp_connections63[1] = {0};

const FixedNum tmp_weights64[65] = {(FixedNum)0xfffffc01, (FixedNum)0x00000999, (FixedNum)0x00000d91, (FixedNum)0x0000024f, (FixedNum)0xfffffcfb, (FixedNum)0x000001c3, (FixedNum)0xfffffa83, (FixedNum)0x00000408, (FixedNum)0x00000041, (FixedNum)0x0000025b, (FixedNum)0x0000021a, (FixedNum)0x000001b6, (FixedNum)0x00000215, (FixedNum)0x000004a9, (FixedNum)0xfffff98c, (FixedNum)0xfffff9c9, (FixedNum)0xfffffe68, (FixedNum)0x00000237, (FixedNum)0x000002aa, (FixedNum)0x000001c3, (FixedNum)0x000001bf, (FixedNum)0xffffff07, (FixedNum)0xfffffafa, (FixedNum)0xfffffcef, (FixedNum)0x0000048f, (FixedNum)0xfffff8c4, (FixedNum)0xffffea4a, (FixedNum)0x0000024c, (FixedNum)0xfffffe98, (FixedNum)0xffffe5dc, (FixedNum)0xfffffa81, (FixedNum)0xfffff081, (FixedNum)0xffffe3c4, (FixedNum)0xfffff336, (FixedNum)0xfffff9b1, (FixedNum)0x00000581, (FixedNum)0x000007b3, (FixedNum)0x00000781, (FixedNum)0x00000016, (FixedNum)0xfffffd04, (FixedNum)0xfffffecf, (FixedNum)0x0000061b, (FixedNum)0xffffff86, (FixedNum)0xfffffb4a, (FixedNum)0x00000263, (FixedNum)0xfffffc32, (FixedNum)0xfffff613, (FixedNum)0xffffff21, (FixedNum)0xfffff521, (FixedNum)0xfffff4d7, (FixedNum)0xfffff967, (FixedNum)0x00000dc4, (FixedNum)0x00000313, (FixedNum)0xfffffa26, (FixedNum)0xfffffcb3, (FixedNum)0x000008e3, (FixedNum)0x000001a4, (FixedNum)0xfffff992, (FixedNum)0x00000c9d, (FixedNum)0x00001a69, (FixedNum)0x0000078e, (FixedNum)0x000002c2, (FixedNum)0xfffffd18, (FixedNum)0xffffff4a, (FixedNum)0xfffff537};
const int tmp_connections64[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights65[65] = {(FixedNum)0x000000f5, (FixedNum)0xffffee1a, (FixedNum)0xfffff691, (FixedNum)0x000002c7, (FixedNum)0x000010d5, (FixedNum)0x00000943, (FixedNum)0x00000459, (FixedNum)0x00000904, (FixedNum)0xfffff35d, (FixedNum)0xfffffd45, (FixedNum)0x000002d2, (FixedNum)0x0000096d, (FixedNum)0xfffff58e, (FixedNum)0xfffff916, (FixedNum)0x0000090d, (FixedNum)0x000008c4, (FixedNum)0xfffff1d4, (FixedNum)0xfffffd8f, (FixedNum)0xfffff110, (FixedNum)0x0000098b, (FixedNum)0x00000962, (FixedNum)0x0000024b, (FixedNum)0xfffffc86, (FixedNum)0x000011ff, (FixedNum)0x00000409, (FixedNum)0x00000e9d, (FixedNum)0x00001419, (FixedNum)0x000002fe, (FixedNum)0x00000d78, (FixedNum)0xfffff8d3, (FixedNum)0x000012df, (FixedNum)0xfffffcc3, (FixedNum)0x00000a46, (FixedNum)0x000016cf, (FixedNum)0x0000004d, (FixedNum)0xfffffbe9, (FixedNum)0xffffff54, (FixedNum)0xfffff3c2, (FixedNum)0xfffffe32, (FixedNum)0x00000199, (FixedNum)0xfffffb25, (FixedNum)0xfffff764, (FixedNum)0x00000347, (FixedNum)0x00000d20, (FixedNum)0x00000305, (FixedNum)0x0000009f, (FixedNum)0x00000393, (FixedNum)0xfffffca2, (FixedNum)0xfffffa10, (FixedNum)0x000003f5, (FixedNum)0x0000005d, (FixedNum)0x000001f5, (FixedNum)0xffffff9d, (FixedNum)0xfffff9e4, (FixedNum)0x00000976, (FixedNum)0xfffffbea, (FixedNum)0xfffff8c2, (FixedNum)0x00000039, (FixedNum)0xfffffbff, (FixedNum)0xfffff604, (FixedNum)0xfffffa5e, (FixedNum)0x00000a34, (FixedNum)0x00001166, (FixedNum)0x000018e6, (FixedNum)0x00000ef2};
const int tmp_connections65[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights66[65] = {(FixedNum)0x0000005c, (FixedNum)0x00000585, (FixedNum)0x000005dc, (FixedNum)0xffffff13, (FixedNum)0xfffffdfe, (FixedNum)0x00000090, (FixedNum)0x0000006b, (FixedNum)0xfffff492, (FixedNum)0x000009b1, (FixedNum)0x000001b4, (FixedNum)0xffffff2e, (FixedNum)0x000000a3, (FixedNum)0xfffff6eb, (FixedNum)0x000001ce, (FixedNum)0xfffff7d5, (FixedNum)0xfffff7da, (FixedNum)0x00000207, (FixedNum)0x000001f9, (FixedNum)0x000004a3, (FixedNum)0x00000083, (FixedNum)0x000000cf, (FixedNum)0x00000c9d, (FixedNum)0xfffff235, (FixedNum)0x000004da, (FixedNum)0xfffffe0f, (FixedNum)0x0000004e, (FixedNum)0xfffff5e8, (FixedNum)0xffffff47, (FixedNum)0xfffffbc4, (FixedNum)0xfffff43c, (FixedNum)0xfffffb0e, (FixedNum)0xfffff1ee, (FixedNum)0xffffecad, (FixedNum)0xffffeed7, (FixedNum)0x00000928, (FixedNum)0x0000052b, (FixedNum)0x0000092c, (FixedNum)0x00000971, (FixedNum)0xfffffe1e, (FixedNum)0x0000026c, (FixedNum)0x00000105, (FixedNum)0x000003f6, (FixedNum)0xfffffe1f, (FixedNum)0xfffffabb, (FixedNum)0xffffff4f, (FixedNum)0x00001648, (FixedNum)0xfffff3d3, (FixedNum)0x0000171e, (FixedNum)0xfffffc07, (FixedNum)0xfffffa70, (FixedNum)0x000007bf, (FixedNum)0x00000c6e, (FixedNum)0xffffef09, (FixedNum)0xffffed97, (FixedNum)0xfffff1e8, (FixedNum)0x000008e9, (FixedNum)0x0000130c, (FixedNum)0xfffff8fa, (FixedNum)0x0000076c, (FixedNum)0x000015cd, (FixedNum)0x000009dd, (FixedNum)0xfffffa04, (FixedNum)0x000003dd, (FixedNum)0xfffffd7c, (FixedNum)0xfffff2e9};
const int tmp_connections66[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights67[65] = {(FixedNum)0xffffed30, (FixedNum)0x00000988, (FixedNum)0x00000808, (FixedNum)0x000006bd, (FixedNum)0xfffff138, (FixedNum)0xfffff040, (FixedNum)0xffffeefa, (FixedNum)0x000006a9, (FixedNum)0x000010a0, (FixedNum)0xfffffcfe, (FixedNum)0x000006a3, (FixedNum)0xffffeffa, (FixedNum)0xfffffd60, (FixedNum)0x0000092f, (FixedNum)0xfffff3ba, (FixedNum)0xfffff3a5, (FixedNum)0xfffff144, (FixedNum)0xfffffcfa, (FixedNum)0xffffff8c, (FixedNum)0xffffeff5, (FixedNum)0xffffeff8, (FixedNum)0x00000fab, (FixedNum)0x0000014d, (FixedNum)0x000017ea, (FixedNum)0xfffff99b, (FixedNum)0xfffff719, (FixedNum)0x00001599, (FixedNum)0x0000069e, (FixedNum)0xfffff3cd, (FixedNum)0x0000061b, (FixedNum)0xffffdd94, (FixedNum)0x00001bee, (FixedNum)0xffffec64, (FixedNum)0xffffea92, (FixedNum)0xffffe45c, (FixedNum)0x000009b7, (FixedNum)0xfffff3c0, (FixedNum)0xfffff3a2, (FixedNum)0x000007cd, (FixedNum)0xfffff5bd, (FixedNum)0xfffffd69, (FixedNum)0x00000327, (FixedNum)0x00000875, (FixedNum)0x0000109b, (FixedNum)0x000006ce, (FixedNum)0x00000d0f, (FixedNum)0x00000367, (FixedNum)0xfffffe73, (FixedNum)0xfffffe49, (FixedNum)0xffffdc8f, (FixedNum)0x00000448, (FixedNum)0xfffff3ad, (FixedNum)0x000013fb, (FixedNum)0x00000e68, (FixedNum)0x00000e74, (FixedNum)0x00000f12, (FixedNum)0x00000580, (FixedNum)0x00000836, (FixedNum)0x0000110d, (FixedNum)0x000008fc, (FixedNum)0x00000f9c, (FixedNum)0x00000ef0, (FixedNum)0x00000933, (FixedNum)0x00000861, (FixedNum)0xfffffb98};
const int tmp_connections67[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights68[65] = {(FixedNum)0x00000659, (FixedNum)0xfffffc94, (FixedNum)0x00001076, (FixedNum)0x00000240, (FixedNum)0x0000085d, (FixedNum)0x000009b1, (FixedNum)0xfffff384, (FixedNum)0x000006fc, (FixedNum)0x000004a8, (FixedNum)0x000002a2, (FixedNum)0x00000210, (FixedNum)0x000009c8, (FixedNum)0xfffff11e, (FixedNum)0xfffffacc, (FixedNum)0xfffffefc, (FixedNum)0xffffff04, (FixedNum)0xfffffc1a, (FixedNum)0x0000026c, (FixedNum)0x00000149, (FixedNum)0x000009a6, (FixedNum)0x000009d1, (FixedNum)0x00000461, (FixedNum)0xfffffa27, (FixedNum)0x00000262, (FixedNum)0x00000625, (FixedNum)0x0000044d, (FixedNum)0xffffecbd, (FixedNum)0x00000224, (FixedNum)0x000005e9, (FixedNum)0xfffff1ac, (FixedNum)0x00000bd1, (FixedNum)0xffffde0d, (FixedNum)0xfffffe1b, (FixedNum)0xffffeecf, (FixedNum)0x000001e4, (FixedNum)0x00000205, (FixedNum)0x00000bb6, (FixedNum)0x00000e37, (FixedNum)0x0000018e, (FixedNum)0x00000ba7, (FixedNum)0x000006f0, (FixedNum)0x00000955, (FixedNum)0xfffff276, (FixedNum)0xffffeffe, (FixedNum)0x0000021e, (FixedNum)0x0000136e, (FixedNum)0xfffff64b, (FixedNum)0x0000125c, (FixedNum)0xfffffb26, (FixedNum)0xfffff12c, (FixedNum)0xfffff488, (FixedNum)0xfffffbd4, (FixedNum)0x000005f3, (FixedNum)0xffffed7c, (FixedNum)0xffffff52, (FixedNum)0x0000060b, (FixedNum)0xfffffda2, (FixedNum)0xfffff4cd, (FixedNum)0x00000501, (FixedNum)0x000020b4, (FixedNum)0x000002be, (FixedNum)0xfffff981, (FixedNum)0xfffffa2c, (FixedNum)0xffffff4f, (FixedNum)0xfffff979};
const int tmp_connections68[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights69[65] = {(FixedNum)0x0000058d, (FixedNum)0xffffcafb, (FixedNum)0xfffff7f5, (FixedNum)0x000002c9, (FixedNum)0x0000137e, (FixedNum)0x00000c78, (FixedNum)0xffffeb1c, (FixedNum)0x00000986, (FixedNum)0xffffd07f, (FixedNum)0x000000b9, (FixedNum)0x0000030a, (FixedNum)0x00000c97, (FixedNum)0xfffff8d5, (FixedNum)0xfffff6c1, (FixedNum)0x00000700, (FixedNum)0x00000761, (FixedNum)0xfffff68e, (FixedNum)0x0000009c, (FixedNum)0xfffff9b9, (FixedNum)0x00000c9a, (FixedNum)0x00000c98, (FixedNum)0x000003f3, (FixedNum)0xfffff7bd, (FixedNum)0x00000e01, (FixedNum)0xfffff17a, (FixedNum)0x00000fba, (FixedNum)0xfffffe86, (FixedNum)0x000002df, (FixedNum)0x00000ee0, (FixedNum)0xfffff247, (FixedNum)0x0000133e, (FixedNum)0x0000095d, (FixedNum)0xfffff731, (FixedNum)0x00002b0b, (FixedNum)0x00000fbc, (FixedNum)0xfffffc23, (FixedNum)0x0000038f, (FixedNum)0xffffefbe, (FixedNum)0xfffff8a7, (FixedNum)0x000003d8, (FixedNum)0xfffffa8f, (FixedNum)0xfffffce2, (FixedNum)0xfffff8c7, (FixedNum)0x00000a15, (FixedNum)0x000002ef, (FixedNum)0xfffff59a, (FixedNum)0x000008b3, (FixedNum)0xfffff235, (FixedNum)0xffffebb2, (FixedNum)0xffffe262, (FixedNum)0xffffda81, (FixedNum)0x000020ac, (FixedNum)0xfffff8a4, (FixedNum)0xfffffd95, (FixedNum)0x000005d8, (FixedNum)0xfffffd62, (FixedNum)0x00001710, (FixedNum)0x00000251, (FixedNum)0x000008a6, (FixedNum)0xffffed19, (FixedNum)0xfffffb90, (FixedNum)0x000011ef, (FixedNum)0x00000af4, (FixedNum)0x0000250f, (FixedNum)0x00000a50};
const int tmp_connections69[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights70[65] = {(FixedNum)0xfffff3ea, (FixedNum)0xffffceba, (FixedNum)0xfffffcef, (FixedNum)0x00000479, (FixedNum)0x000008ea, (FixedNum)0x000002ce, (FixedNum)0x0000056b, (FixedNum)0x00000b2e, (FixedNum)0x0000057d, (FixedNum)0xffffffed, (FixedNum)0x0000043b, (FixedNum)0x000002e9, (FixedNum)0xffffff03, (FixedNum)0x00000664, (FixedNum)0x00000acf, (FixedNum)0x00000ab7, (FixedNum)0xfffff99b, (FixedNum)0xffffffdf, (FixedNum)0xfffffdeb, (FixedNum)0x000002cd, (FixedNum)0x0000030b, (FixedNum)0xffffeeb2, (FixedNum)0x00000be3, (FixedNum)0x00000bb0, (FixedNum)0x00000462, (FixedNum)0x00001215, (FixedNum)0xfffffb9f, (FixedNum)0x00000481, (FixedNum)0x00000775, (FixedNum)0x00000a70, (FixedNum)0x0000063f, (FixedNum)0x000003c0, (FixedNum)0x00000565, (FixedNum)0x00000f07, (FixedNum)0xfffff86a, (FixedNum)0x00000097, (FixedNum)0xfffffde9, (FixedNum)0x000003e7, (FixedNum)0x00000a3c, (FixedNum)0xfffffb14, (FixedNum)0xfffffdde, (FixedNum)0x00000516, (FixedNum)0xffffff69, (FixedNum)0x000007d6, (FixedNum)0x0000047c, (FixedNum)0x000009de, (FixedNum)0xffffffa4, (FixedNum)0x00001364, (FixedNum)0x00000659, (FixedNum)0xfffffc67, (FixedNum)0xfffff604, (FixedNum)0x000005b1, (FixedNum)0xfffffc24, (FixedNum)0xfffffaf7, (FixedNum)0x000005ea, (FixedNum)0x00000364, (FixedNum)0xfffff20c, (FixedNum)0xfffff359, (FixedNum)0xfffff285, (FixedNum)0x000000a8, (FixedNum)0xfffffedd, (FixedNum)0x00000bd4, (FixedNum)0xfffff641, (FixedNum)0x00000e51, (FixedNum)0xfffffe5a};
const int tmp_connections70[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights71[65] = {(FixedNum)0x000008f0, (FixedNum)0x00002265, (FixedNum)0x00001479, (FixedNum)0xffffff65, (FixedNum)0x0000028d, (FixedNum)0x00000790, (FixedNum)0xfffff06b, (FixedNum)0xfffff2ce, (FixedNum)0x00000e3a, (FixedNum)0x00000845, (FixedNum)0xffffff31, (FixedNum)0x000007b8, (FixedNum)0x0000071c, (FixedNum)0xffffff26, (FixedNum)0x0000029a, (FixedNum)0x00000292, (FixedNum)0x000007ae, (FixedNum)0x0000087c, (FixedNum)0xfffff5c6, (FixedNum)0x000007af, (FixedNum)0x00000796, (FixedNum)0x00001419, (FixedNum)0xffffea07, (FixedNum)0xfffff97c, (FixedNum)0x00001488, (FixedNum)0xffffff84, (FixedNum)0x00002321, (FixedNum)0xffffff38, (FixedNum)0x00000502, (FixedNum)0x00000268, (FixedNum)0x00000ded, (FixedNum)0xfffff1da, (FixedNum)0xfffff64d, (FixedNum)0x00000162, (FixedNum)0x00000bb9, (FixedNum)0xffffffe7, (FixedNum)0x0000077b, (FixedNum)0x00000292, (FixedNum)0xfffffcc5, (FixedNum)0x00000893, (FixedNum)0x0000003b, (FixedNum)0x0000041a, (FixedNum)0xfffff41b, (FixedNum)0x000001dd, (FixedNum)0xffffff23, (FixedNum)0xffffe6e2, (FixedNum)0x00000065, (FixedNum)0xffffefcd, (FixedNum)0x00000d9f, (FixedNum)0x00000813, (FixedNum)0x00000b7b, (FixedNum)0x00000b21, (FixedNum)0x00000bf1, (FixedNum)0xfffffe74, (FixedNum)0xfffffc83, (FixedNum)0xfffffd98, (FixedNum)0xfffff6a2, (FixedNum)0xfffff43b, (FixedNum)0xfffff29e, (FixedNum)0x00000c31, (FixedNum)0xfffffe62, (FixedNum)0xfffffb9f, (FixedNum)0xfffffa23, (FixedNum)0xfffffe07, (FixedNum)0x00000cb9};
const int tmp_connections71[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights72[65] = {(FixedNum)0x00000c2c, (FixedNum)0xffffe4a9, (FixedNum)0xffffe299, (FixedNum)0x00000349, (FixedNum)0x00001822, (FixedNum)0x00001157, (FixedNum)0xfffffe5c, (FixedNum)0x00000a6c, (FixedNum)0xffffedea, (FixedNum)0xffffffdf, (FixedNum)0x0000034f, (FixedNum)0x00001183, (FixedNum)0xfffff8a8, (FixedNum)0xffffeec4, (FixedNum)0x0000068c, (FixedNum)0x0000066b, (FixedNum)0xfffff44a, (FixedNum)0x00000000, (FixedNum)0xfffffece, (FixedNum)0x00001172, (FixedNum)0x0000116f, (FixedNum)0xfffff8b1, (FixedNum)0x000002cf, (FixedNum)0x0000067e, (FixedNum)0xffffecaa, (FixedNum)0x00000fc5, (FixedNum)0x00000d62, (FixedNum)0x00000381, (FixedNum)0x0000121d, (FixedNum)0xffffea38, (FixedNum)0x000019f9, (FixedNum)0xfffff2e2, (FixedNum)0x000001d6, (FixedNum)0x000019af, (FixedNum)0x0000076b, (FixedNum)0xfffffb83, (FixedNum)0x00000837, (FixedNum)0xfffff0ac, (FixedNum)0xfffff588, (FixedNum)0x000005ad, (FixedNum)0xfffff2d5, (FixedNum)0xffffdd37, (FixedNum)0x00000ff5, (FixedNum)0x00000fa0, (FixedNum)0x00000356, (FixedNum)0xfffff8b5, (FixedNum)0x0000037e, (FixedNum)0xffffe821, (FixedNum)0xfffffbb8, (FixedNum)0xfffff789, (FixedNum)0xfffff566, (FixedNum)0x00000aa7, (FixedNum)0xffffeca1, (FixedNum)0xfffff099, (FixedNum)0x0000027e, (FixedNum)0xfffffe35, (FixedNum)0x00001174, (FixedNum)0x0000117d, (FixedNum)0xffffffee, (FixedNum)0xfffff2cf, (FixedNum)0xfffffa7f, (FixedNum)0x0000077b, (FixedNum)0x00001284, (FixedNum)0x00001820, (FixedNum)0x00000c4d};
const int tmp_connections72[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights73[65] = {(FixedNum)0xffffff6c, (FixedNum)0x0000134a, (FixedNum)0xfffff69b, (FixedNum)0xfffffef4, (FixedNum)0xfffffd9f, (FixedNum)0x00000263, (FixedNum)0xfffff0ed, (FixedNum)0x0000008b, (FixedNum)0xfffff2eb, (FixedNum)0x000006a0, (FixedNum)0xfffffee7, (FixedNum)0x0000024e, (FixedNum)0x00000694, (FixedNum)0x00000436, (FixedNum)0x0000034e, (FixedNum)0x0000031f, (FixedNum)0x00000fa0, (FixedNum)0x00000669, (FixedNum)0x000006ab, (FixedNum)0x00000253, (FixedNum)0x00000231, (FixedNum)0xfffff60d, (FixedNum)0x0000087e, (FixedNum)0xffffee2b, (FixedNum)0xfffffcb2, (FixedNum)0xfffff777, (FixedNum)0x00000dca, (FixedNum)0xffffff11, (FixedNum)0x000001e6, (FixedNum)0x000000b2, (FixedNum)0x00000654, (FixedNum)0xfffff8ae, (FixedNum)0x00000908, (FixedNum)0x00000062, (FixedNum)0xfffffff0, (FixedNum)0x000000aa, (FixedNum)0x000002ea, (FixedNum)0x000005b4, (FixedNum)0x00000212, (FixedNum)0x00000032, (FixedNum)0xffffffcc, (FixedNum)0xfffffcbf, (FixedNum)0x000004d1, (FixedNum)0xffffffc1, (FixedNum)0xffffff25, (FixedNum)0x00001906, (FixedNum)0x00000154, (FixedNum)0xfffff660, (FixedNum)0xfffff8e9, (FixedNum)0x00000ba5, (FixedNum)0xfffff9e1, (FixedNum)0xfffff992, (FixedNum)0x000006c9, (FixedNum)0x000002f9, (FixedNum)0x000001bc, (FixedNum)0x00000053, (FixedNum)0xfffffb28, (FixedNum)0xfffffb6c, (FixedNum)0xfffffb39, (FixedNum)0x00000243, (FixedNum)0xffffffc8, (FixedNum)0xffffff33, (FixedNum)0xfffffad7, (FixedNum)0xfffffcb1, (FixedNum)0x00000175};
const int tmp_connections73[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights74[65] = {(FixedNum)0xfffffcf5, (FixedNum)0x00000497, (FixedNum)0x00000006, (FixedNum)0x000001ba, (FixedNum)0xfffffd26, (FixedNum)0x000000d1, (FixedNum)0xfffff33f, (FixedNum)0x00000aec, (FixedNum)0xfffffc8e, (FixedNum)0x00000036, (FixedNum)0x000001cd, (FixedNum)0x00000122, (FixedNum)0x000005b3, (FixedNum)0x000003c9, (FixedNum)0xfffffa24, (FixedNum)0xfffffa50, (FixedNum)0xfffffab3, (FixedNum)0x00000023, (FixedNum)0x0000027d, (FixedNum)0x000000ed, (FixedNum)0x0000010d, (FixedNum)0xfffff587, (FixedNum)0x00000484, (FixedNum)0x00000353, (FixedNum)0xfffffe64, (FixedNum)0xfffff827, (FixedNum)0xfffff355, (FixedNum)0x000001b6, (FixedNum)0xffffff0f, (FixedNum)0xffffe8ec, (FixedNum)0xfffffb9a, (FixedNum)0xfffff672, (FixedNum)0xffffec83, (FixedNum)0xfffff6b9, (FixedNum)0xfffffc61, (FixedNum)0x0000041e, (FixedNum)0x00000483, (FixedNum)0x0000063e, (FixedNum)0x000000ee, (FixedNum)0xfffffc74, (FixedNum)0xffffffb4, (FixedNum)0xfffffe65, (FixedNum)0x0000049f, (FixedNum)0xfffffa0f, (FixedNum)0x000001ce, (FixedNum)0x000001bc, (FixedNum)0xfffff7df, (FixedNum)0x00000027, (FixedNum)0xfffff97e, (FixedNum)0xfffffbf4, (FixedNum)0xfffffde7, (FixedNum)0x000011ec, (FixedNum)0x00000568, (FixedNum)0xfffffbff, (FixedNum)0x0000018b, (FixedNum)0x000004db, (FixedNum)0xfffffd7c, (FixedNum)0xfffffe4d, (FixedNum)0x00000d2f, (FixedNum)0x0000128a, (FixedNum)0x00000611, (FixedNum)0x00000415, (FixedNum)0xfffffecb, (FixedNum)0xfffffd1a, (FixedNum)0xfffff3da};
const int tmp_connections74[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights75[65] = {(FixedNum)0xfffffe5c, (FixedNum)0xfffffdb8, (FixedNum)0xfffff27f, (FixedNum)0x00000148, (FixedNum)0xfffffc57, (FixedNum)0x000003ca, (FixedNum)0x00000318, (FixedNum)0xfffff405, (FixedNum)0x000004dc, (FixedNum)0x000003ee, (FixedNum)0x00000192, (FixedNum)0x000003c5, (FixedNum)0x00000a7c, (FixedNum)0x00000583, (FixedNum)0xfffffacb, (FixedNum)0xfffffac0, (FixedNum)0x0000023a, (FixedNum)0x000003c8, (FixedNum)0x0000073c, (FixedNum)0x00000384, (FixedNum)0x000003c8, (FixedNum)0xfffff87e, (FixedNum)0x00000425, (FixedNum)0xfffff23f, (FixedNum)0x00000191, (FixedNum)0xfffff836, (FixedNum)0xfffffa3d, (FixedNum)0x00000142, (FixedNum)0xffffff1c, (FixedNum)0xffffe920, (FixedNum)0xfffffcaa, (FixedNum)0xffffecf4, (FixedNum)0xffffe045, (FixedNum)0xfffff33b, (FixedNum)0xfffffb3f, (FixedNum)0x000004e1, (FixedNum)0x000009c1, (FixedNum)0x000007c6, (FixedNum)0xffffffaf, (FixedNum)0xfffffcf0, (FixedNum)0xfffffcce, (FixedNum)0xfffffee7, (FixedNum)0x000002b8, (FixedNum)0xfffffa0e, (FixedNum)0x0000014a, (FixedNum)0x00000619, (FixedNum)0xfffffd93, (FixedNum)0xfffff7d9, (FixedNum)0xfffff79b, (FixedNum)0xfffffa22, (FixedNum)0xfffff94b, (FixedNum)0x0000117d, (FixedNum)0x000000d8, (FixedNum)0xfffff653, (FixedNum)0xfffff9d4, (FixedNum)0x000004cd, (FixedNum)0x00000baf, (FixedNum)0xfffff9bb, (FixedNum)0x00000fb9, (FixedNum)0x00000d31, (FixedNum)0x00000685, (FixedNum)0xfffffef2, (FixedNum)0x00000258, (FixedNum)0x0000016c, (FixedNum)0xfffff387};
const int tmp_connections75[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights76[65] = {(FixedNum)0x0000031e, (FixedNum)0x00003e37, (FixedNum)0x00000c53, (FixedNum)0xfffff7f3, (FixedNum)0xfffff766, (FixedNum)0xfffff692, (FixedNum)0x00000e24, (FixedNum)0x0000035b, (FixedNum)0xfffff9b7, (FixedNum)0xfffffb02, (FixedNum)0xfffff7cf, (FixedNum)0xfffff6c7, (FixedNum)0xfffffc01, (FixedNum)0xfffffb15, (FixedNum)0xfffff507, (FixedNum)0xfffff4df, (FixedNum)0x0000062b, (FixedNum)0xfffffad2, (FixedNum)0xfffffd96, (FixedNum)0xfffff6b2, (FixedNum)0xfffff685, (FixedNum)0xfffffd50, (FixedNum)0x00000cb8, (FixedNum)0xfffff690, (FixedNum)0x00000915, (FixedNum)0xfffff72e, (FixedNum)0xffffeef2, (FixedNum)0xfffff810, (FixedNum)0xfffff28d, (FixedNum)0xfffffd29, (FixedNum)0xfffff1c8, (FixedNum)0x00000494, (FixedNum)0xffffed02, (FixedNum)0xfffff4ef, (FixedNum)0x000003eb, (FixedNum)0x000000fe, (FixedNum)0xffffff64, (FixedNum)0xfffff9a2, (FixedNum)0xfffff9b8, (FixedNum)0x00000114, (FixedNum)0x00000452, (FixedNum)0xfffffa1e, (FixedNum)0x00000353, (FixedNum)0xfffff746, (FixedNum)0xfffff7cf, (FixedNum)0xffffe7c3, (FixedNum)0xfffffc9d, (FixedNum)0x00000d14, (FixedNum)0x0000067f, (FixedNum)0xfffffda2, (FixedNum)0xfffffcb6, (FixedNum)0x0000145f, (FixedNum)0xfffff875, (FixedNum)0x00000c01, (FixedNum)0x00000159, (FixedNum)0xfffffaaa, (FixedNum)0xfffffac9, (FixedNum)0x000009b0, (FixedNum)0x000001aa, (FixedNum)0xfffff72c, (FixedNum)0x000000b4, (FixedNum)0xfffff1a1, (FixedNum)0xfffffb5b, (FixedNum)0x000007a4, (FixedNum)0x0000024d};
const int tmp_connections76[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights77[65] = {(FixedNum)0xfffff71a, (FixedNum)0xffffc087, (FixedNum)0xfffff937, (FixedNum)0x00000418, (FixedNum)0x00000897, (FixedNum)0x00000359, (FixedNum)0x00000912, (FixedNum)0x0000051b, (FixedNum)0x00000628, (FixedNum)0x00000333, (FixedNum)0x0000040a, (FixedNum)0x00000394, (FixedNum)0x000002a7, (FixedNum)0x000005d7, (FixedNum)0x000008db, (FixedNum)0x000008d8, (FixedNum)0xfffffd4c, (FixedNum)0x00000349, (FixedNum)0x00000451, (FixedNum)0x00000377, (FixedNum)0x00000345, (FixedNum)0xfffffabd, (FixedNum)0xfffffb15, (FixedNum)0x000006a1, (FixedNum)0x00000986, (FixedNum)0x000015a6, (FixedNum)0x00000277, (FixedNum)0x00000435, (FixedNum)0x00000955, (FixedNum)0x00000c29, (FixedNum)0x00000bae, (FixedNum)0x000000db, (FixedNum)0x0000169f, (FixedNum)0x00000a13, (FixedNum)0xfffff9ae, (FixedNum)0xfffffd6e, (FixedNum)0xfffffa09, (FixedNum)0x00000083, (FixedNum)0x000007ca, (FixedNum)0xfffffaaa, (FixedNum)0xfffffb7c, (FixedNum)0x00000a2f, (FixedNum)0xfffff9a3, (FixedNum)0x00000979, (FixedNum)0x00000431, (FixedNum)0x0000049e, (FixedNum)0xffffff5d, (FixedNum)0x000009a9, (FixedNum)0x000009b1, (FixedNum)0x00000212, (FixedNum)0x0000001f, (FixedNum)0x00000122, (FixedNum)0xfffffef9, (FixedNum)0xfffffa29, (FixedNum)0x00000b0e, (FixedNum)0x00000087, (FixedNum)0xfffffc2c, (FixedNum)0xfffff72d, (FixedNum)0xfffffd65, (FixedNum)0xfffffc69, (FixedNum)0x000002c2, (FixedNum)0x00000d58, (FixedNum)0xfffffe40, (FixedNum)0x000009c4, (FixedNum)0xfffffb70};
const int tmp_connections77[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights78[65] = {(FixedNum)0x0000005b, (FixedNum)0xffffeb66, (FixedNum)0xfffff866, (FixedNum)0x000002f7, (FixedNum)0x00000703, (FixedNum)0x000007e9, (FixedNum)0x0000003d, (FixedNum)0xfffffea3, (FixedNum)0x00000a3c, (FixedNum)0xffffff56, (FixedNum)0x000002ff, (FixedNum)0x000007c7, (FixedNum)0xfffff851, (FixedNum)0x00000185, (FixedNum)0xfffffeb7, (FixedNum)0xfffffedc, (FixedNum)0xfffff510, (FixedNum)0xffffff31, (FixedNum)0xfffff643, (FixedNum)0x000007eb, (FixedNum)0x000007cc, (FixedNum)0x00000147, (FixedNum)0xfffffc69, (FixedNum)0x00000e00, (FixedNum)0x00000082, (FixedNum)0x000006b4, (FixedNum)0xfffff19e, (FixedNum)0x00000325, (FixedNum)0x0000042e, (FixedNum)0xfffff438, (FixedNum)0x00000649, (FixedNum)0xffffee8f, (FixedNum)0xfffff3e5, (FixedNum)0xfffffbbb, (FixedNum)0xfffffabc, (FixedNum)0x00000612, (FixedNum)0x00000d45, (FixedNum)0x00000ad8, (FixedNum)0xfffffec2, (FixedNum)0x00000959, (FixedNum)0x00000194, (FixedNum)0x00000da3, (FixedNum)0xfffff420, (FixedNum)0xfffffb2e, (FixedNum)0x0000030c, (FixedNum)0xffffec5e, (FixedNum)0xfffff71a, (FixedNum)0x000005b1, (FixedNum)0xfffff765, (FixedNum)0xfffff1b1, (FixedNum)0xfffffc63, (FixedNum)0xffffffce, (FixedNum)0x00000903, (FixedNum)0xffffedea, (FixedNum)0xfffffe46, (FixedNum)0x00000e20, (FixedNum)0x0000053e, (FixedNum)0xfffffbab, (FixedNum)0x0000068d, (FixedNum)0x00001baa, (FixedNum)0x00000621, (FixedNum)0x00000619, (FixedNum)0xffffffe7, (FixedNum)0x000007a2, (FixedNum)0xfffff9b5};
const int tmp_connections78[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights79[65] = {(FixedNum)0xfffffad1, (FixedNum)0xffffd666, (FixedNum)0xfffff0a3, (FixedNum)0x00000441, (FixedNum)0x000002dc, (FixedNum)0x00000299, (FixedNum)0x000007e9, (FixedNum)0x00000fbd, (FixedNum)0x00000ccf, (FixedNum)0x0000010d, (FixedNum)0x0000044c, (FixedNum)0x00000274, (FixedNum)0x000005a3, (FixedNum)0x000006dc, (FixedNum)0x00000573, (FixedNum)0x0000057b, (FixedNum)0xfffffadd, (FixedNum)0x00000100, (FixedNum)0xfffffe0d, (FixedNum)0x00000297, (FixedNum)0x00000266, (FixedNum)0xfffffcac, (FixedNum)0xfffffe6f, (FixedNum)0x00000931, (FixedNum)0xfffffb14, (FixedNum)0x0000090d, (FixedNum)0x000003c5, (FixedNum)0x00000441, (FixedNum)0x0000056e, (FixedNum)0x000004b8, (FixedNum)0x00000566, (FixedNum)0xfffffd72, (FixedNum)0x00000b26, (FixedNum)0x0000001b, (FixedNum)0xfffffb61, (FixedNum)0x000000e8, (FixedNum)0xfffffe75, (FixedNum)0x000003a6, (FixedNum)0x00000478, (FixedNum)0xffffff33, (FixedNum)0xfffffd97, (FixedNum)0xfffffc72, (FixedNum)0x0000059a, (FixedNum)0x00000379, (FixedNum)0x0000048c, (FixedNum)0xffffff70, (FixedNum)0x00000959, (FixedNum)0xfffff79a, (FixedNum)0x000000ee, (FixedNum)0xfffff874, (FixedNum)0xfffffeeb, (FixedNum)0x00000adb, (FixedNum)0x00000101, (FixedNum)0xfffff04b, (FixedNum)0x00000430, (FixedNum)0x000000d9, (FixedNum)0x00000bcc, (FixedNum)0x00000403, (FixedNum)0x00000237, (FixedNum)0xfffffb80, (FixedNum)0x00000204, (FixedNum)0x00000d0e, (FixedNum)0xfffffb05, (FixedNum)0x00000ebf, (FixedNum)0xfffff986};
const int tmp_connections79[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights80[65] = {(FixedNum)0xfffffc3b, (FixedNum)0xfffffd39, (FixedNum)0x000004c0, (FixedNum)0x000001ac, (FixedNum)0x000000ad, (FixedNum)0x00000074, (FixedNum)0xfffffdc1, (FixedNum)0xfffffdf8, (FixedNum)0xfffffcb9, (FixedNum)0x000001d1, (FixedNum)0x000001a6, (FixedNum)0x00000080, (FixedNum)0xfffffd10, (FixedNum)0x000001dc, (FixedNum)0xfffffeb1, (FixedNum)0xfffffe77, (FixedNum)0x000002bf, (FixedNum)0x000001d6, (FixedNum)0x0000022d, (FixedNum)0x0000007a, (FixedNum)0x00000073, (FixedNum)0x00000f9a, (FixedNum)0xfffff40c, (FixedNum)0xfffffe02, (FixedNum)0xfffffd27, (FixedNum)0x000000a3, (FixedNum)0x00000ff0, (FixedNum)0x00000203, (FixedNum)0x0000011f, (FixedNum)0xfffff89f, (FixedNum)0xffffffb3, (FixedNum)0xfffffcda, (FixedNum)0xffffffb8, (FixedNum)0xfffffcf4, (FixedNum)0x00000619, (FixedNum)0x0000027a, (FixedNum)0x00000000, (FixedNum)0xfffffcab, (FixedNum)0xffffffe4, (FixedNum)0xfffffdf5, (FixedNum)0xfffffe3e, (FixedNum)0xfffffebc, (FixedNum)0x000002d5, (FixedNum)0x000003ba, (FixedNum)0x000001cd, (FixedNum)0x0000011b, (FixedNum)0xfffffe61, (FixedNum)0xfffffe93, (FixedNum)0xfffff8cd, (FixedNum)0xfffff23d, (FixedNum)0xfffffac5, (FixedNum)0xfffff8e8, (FixedNum)0x0000012e, (FixedNum)0x0000011c, (FixedNum)0x000001ec, (FixedNum)0x0000044f, (FixedNum)0x00000563, (FixedNum)0x00000327, (FixedNum)0x000007a4, (FixedNum)0x00000915, (FixedNum)0x0000046a, (FixedNum)0x0000047c, (FixedNum)0x00000179, (FixedNum)0x000002f8, (FixedNum)0xfffffe79};
const int tmp_connections80[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights81[65] = {(FixedNum)0xfffffe0d, (FixedNum)0xfffff640, (FixedNum)0x000002b8, (FixedNum)0xffffff4a, (FixedNum)0x00000101, (FixedNum)0x00000542, (FixedNum)0xffffee1b, (FixedNum)0x000013b6, (FixedNum)0x000018a2, (FixedNum)0x0000016f, (FixedNum)0xffffff3d, (FixedNum)0x00000578, (FixedNum)0x0000127f, (FixedNum)0x00000540, (FixedNum)0x00000196, (FixedNum)0x00000199, (FixedNum)0xfffffbac, (FixedNum)0x00000149, (FixedNum)0xfffffc10, (FixedNum)0x00000584, (FixedNum)0x00000545, (FixedNum)0x00000bc6, (FixedNum)0xfffff377, (FixedNum)0x0000013f, (FixedNum)0xfffff0ba, (FixedNum)0xfffffa93, (FixedNum)0xffffecd4, (FixedNum)0xffffff2f, (FixedNum)0x0000049f, (FixedNum)0xfffff9c1, (FixedNum)0x00000c6e, (FixedNum)0xffffe349, (FixedNum)0x00000712, (FixedNum)0xfffff61d, (FixedNum)0x000007b0, (FixedNum)0x000000a9, (FixedNum)0x000005a9, (FixedNum)0x00000441, (FixedNum)0xfffffcee, (FixedNum)0xfffffc79, (FixedNum)0xfffff776, (FixedNum)0xffffedc9, (FixedNum)0x000012d3, (FixedNum)0x0000040b, (FixedNum)0xfffffef6, (FixedNum)0xfffff0ee, (FixedNum)0xfffffa6c, (FixedNum)0xfffff5bd, (FixedNum)0xfffffd4c, (FixedNum)0x000002e0, (FixedNum)0xfffffdd5, (FixedNum)0xfffff523, (FixedNum)0xfffff8fa, (FixedNum)0xfffffef4, (FixedNum)0xfffffe75, (FixedNum)0xfffffdfa, (FixedNum)0x00000563, (FixedNum)0xfffffb3e, (FixedNum)0xfffffd82, (FixedNum)0x00001536, (FixedNum)0x000000c3, (FixedNum)0xfffffcc0, (FixedNum)0xfffffc26, (FixedNum)0xfffffabb, (FixedNum)0x00000673};
const int tmp_connections81[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights82[65] = {(FixedNum)0x00000139, (FixedNum)0x000004eb, (FixedNum)0x000001f1, (FixedNum)0xfffffee7, (FixedNum)0xfffffe66, (FixedNum)0x000000e1, (FixedNum)0xffffff09, (FixedNum)0x00000190, (FixedNum)0xfffff9bf, (FixedNum)0x000001d7, (FixedNum)0xfffffec7, (FixedNum)0x000000c5, (FixedNum)0x000006a5, (FixedNum)0x000001a0, (FixedNum)0xfffffcfe, (FixedNum)0xfffffd1f, (FixedNum)0x0000087a, (FixedNum)0x000001cb, (FixedNum)0x00000607, (FixedNum)0x000000b8, (FixedNum)0x0000009a, (FixedNum)0xfffffdb5, (FixedNum)0xffffffa6, (FixedNum)0xfffff3c2, (FixedNum)0xfffffa58, (FixedNum)0xfffffad7, (FixedNum)0x0000008b, (FixedNum)0xfffffebb, (FixedNum)0xffffff8b, (FixedNum)0xfffff20a, (FixedNum)0x0000005d, (FixedNum)0xfffff8a1, (FixedNum)0xfffff88d, (FixedNum)0xfffffcef, (FixedNum)0x00000492, (FixedNum)0xffffff8a, (FixedNum)0x00000230, (FixedNum)0x000004a3, (FixedNum)0xffffff32, (FixedNum)0xfffffddf, (FixedNum)0xfffffdea, (FixedNum)0xfffffb26, (FixedNum)0x0000040d, (FixedNum)0xfffffe5f, (FixedNum)0xfffffec8, (FixedNum)0x00000355, (FixedNum)0xfffffd7c, (FixedNum)0xfffffd54, (FixedNum)0xfffffae1, (FixedNum)0xfffffd05, (FixedNum)0xfffffc17, (FixedNum)0xfffffd48, (FixedNum)0x00000622, (FixedNum)0xfffffd04, (FixedNum)0xffffff96, (FixedNum)0xfffffebd, (FixedNum)0x00000141, (FixedNum)0x000001f7, (FixedNum)0x0000002d, (FixedNum)0x00000555, (FixedNum)0x00000022, (FixedNum)0xffffff72, (FixedNum)0xfffffe56, (FixedNum)0xfffffdff, (FixedNum)0xfffffe42};
const int tmp_connections82[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights83[65] = {(FixedNum)0xfffff2d8, (FixedNum)0x000043f8, (FixedNum)0x000024ae, (FixedNum)0xfffffdac, (FixedNum)0xffffe983, (FixedNum)0xffffebdb, (FixedNum)0xfffff318, (FixedNum)0xfffffb8f, (FixedNum)0x00000356, (FixedNum)0x000000c6, (FixedNum)0xfffffda3, (FixedNum)0xffffebc8, (FixedNum)0x0000033b, (FixedNum)0x0000077f, (FixedNum)0xfffffaa5, (FixedNum)0xfffffa90, (FixedNum)0x0000169d, (FixedNum)0x0000007d, (FixedNum)0x00001757, (FixedNum)0xffffebe4, (FixedNum)0xffffebde, (FixedNum)0x00000301, (FixedNum)0x00000aaf, (FixedNum)0xffffed4e, (FixedNum)0x0000038e, (FixedNum)0xffffe787, (FixedNum)0x0000146a, (FixedNum)0xfffffd9e, (FixedNum)0xffffe759, (FixedNum)0x00001981, (FixedNum)0xffffd8dc, (FixedNum)0x0000214d, (FixedNum)0xffffe71a, (FixedNum)0xfffff943, (FixedNum)0x00000208, (FixedNum)0x00000a15, (FixedNum)0xfffffdd6, (FixedNum)0x000013a9, (FixedNum)0x00000948, (FixedNum)0xfffff0f1, (FixedNum)0xfffffb96, (FixedNum)0x00000be6, (FixedNum)0x000000ee, (FixedNum)0x00000895, (FixedNum)0xfffffd8f, (FixedNum)0xfffff24b, (FixedNum)0xfffffff1, (FixedNum)0x0000136a, (FixedNum)0x0000075d, (FixedNum)0xfffffcbc, (FixedNum)0xffffffd2, (FixedNum)0xfffffc87, (FixedNum)0x000009a8, (FixedNum)0x000009cd, (FixedNum)0xfffffb25, (FixedNum)0x0000018e, (FixedNum)0xfffffce4, (FixedNum)0xfffffe9e, (FixedNum)0xfffffa5c, (FixedNum)0xfffff946, (FixedNum)0x0000081f, (FixedNum)0xfffff619, (FixedNum)0xfffff982, (FixedNum)0xffffd4f9, (FixedNum)0xfffff82d};
const int tmp_connections83[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights84[65] = {(FixedNum)0xfffffee1, (FixedNum)0xffffef92, (FixedNum)0xfffffe27, (FixedNum)0x00000245, (FixedNum)0x0000026c, (FixedNum)0x00000297, (FixedNum)0xfffffce2, (FixedNum)0x00000796, (FixedNum)0x000003d2, (FixedNum)0x0000013a, (FixedNum)0x00000272, (FixedNum)0x000002af, (FixedNum)0x000001b8, (FixedNum)0x000002ac, (FixedNum)0x00000318, (FixedNum)0x000002c7, (FixedNum)0xfffffe7f, (FixedNum)0x00000130, (FixedNum)0x0000003d, (FixedNum)0x000002cd, (FixedNum)0x000002c8, (FixedNum)0x0000026b, (FixedNum)0xfffffb38, (FixedNum)0x00000278, (FixedNum)0x00000240, (FixedNum)0x00000289, (FixedNum)0xffffff3f, (FixedNum)0x00000233, (FixedNum)0x000002e7, (FixedNum)0x0000010f, (FixedNum)0x000002f0, (FixedNum)0xfffffdb9, (FixedNum)0x00000073, (FixedNum)0x000002b6, (FixedNum)0xffffffe7, (FixedNum)0x00000133, (FixedNum)0x000001ec, (FixedNum)0x000001ff, (FixedNum)0x000000d6, (FixedNum)0x0000000c, (FixedNum)0xfffffde3, (FixedNum)0xffffff87, (FixedNum)0x00000103, (FixedNum)0x000002b6, (FixedNum)0x0000023a, (FixedNum)0xfffff712, (FixedNum)0xfffffea7, (FixedNum)0x00000255, (FixedNum)0xfffffe26, (FixedNum)0xfffffdba, (FixedNum)0xffffff62, (FixedNum)0xfffffd51, (FixedNum)0xfffffe31, (FixedNum)0xfffffbe6, (FixedNum)0x00000131, (FixedNum)0x0000026b, (FixedNum)0x0000015a, (FixedNum)0x0000010b, (FixedNum)0xffffffad, (FixedNum)0x000001af, (FixedNum)0x000001b0, (FixedNum)0x00000389, (FixedNum)0xfffffc93, (FixedNum)0x0000031e, (FixedNum)0xfffffe5c};
const int tmp_connections84[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights85[65] = {(FixedNum)0xffffea5a, (FixedNum)0xffffedbf, (FixedNum)0x00000284, (FixedNum)0x0000059b, (FixedNum)0xffffeaf9, (FixedNum)0xffffe82c, (FixedNum)0xfffff684, (FixedNum)0x00002833, (FixedNum)0x00000bea, (FixedNum)0xfffffc77, (FixedNum)0x000005cf, (FixedNum)0xffffe82f, (FixedNum)0xfffff09f, (FixedNum)0x0000083d, (FixedNum)0xffffe9fc, (FixedNum)0xffffe9dc, (FixedNum)0xfffff939, (FixedNum)0xfffffc66, (FixedNum)0x0000185a, (FixedNum)0xffffe82f, (FixedNum)0xffffe83f, (FixedNum)0x000027df, (FixedNum)0xffffe44c, (FixedNum)0x00001307, (FixedNum)0x00001c3f, (FixedNum)0xfffff8b0, (FixedNum)0x0000039a, (FixedNum)0x000005ea, (FixedNum)0xffffed69, (FixedNum)0x00000041, (FixedNum)0xffffd340, (FixedNum)0x0000276a, (FixedNum)0x000001ea, (FixedNum)0xffffe2c3, (FixedNum)0xffffe1c4, (FixedNum)0x00000946, (FixedNum)0xffffebd3, (FixedNum)0x000009de, (FixedNum)0x00001cd7, (FixedNum)0x000000e6, (FixedNum)0x00002717, (FixedNum)0x00000795, (FixedNum)0xffffffbe, (FixedNum)0xffffe883, (FixedNum)0x000005a6, (FixedNum)0x0000152e, (FixedNum)0x000001fc, (FixedNum)0x000017aa, (FixedNum)0xffffdca0, (FixedNum)0xffffe9a6, (FixedNum)0xfffff6ad, (FixedNum)0x0000112f, (FixedNum)0x0000021c, (FixedNum)0x00000e37, (FixedNum)0x00000e90, (FixedNum)0x0000143b, (FixedNum)0x00000108, (FixedNum)0xfffff5c0, (FixedNum)0x00001d52, (FixedNum)0x000008d6, (FixedNum)0x000014a2, (FixedNum)0x0000105b, (FixedNum)0xffffff77, (FixedNum)0x00000bb6, (FixedNum)0xffffee6a};
const int tmp_connections85[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights86[65] = {(FixedNum)0x000016e2, (FixedNum)0xfffff93b, (FixedNum)0xfffff00b, (FixedNum)0xfffff86c, (FixedNum)0x0000123a, (FixedNum)0x00001415, (FixedNum)0x000027c2, (FixedNum)0xfffffed5, (FixedNum)0x000001b9, (FixedNum)0x000002ab, (FixedNum)0xfffff833, (FixedNum)0x000013d3, (FixedNum)0x00001c15, (FixedNum)0xfffff8bc, (FixedNum)0x00000e19, (FixedNum)0x00000e1b, (FixedNum)0x00001339, (FixedNum)0x000002c2, (FixedNum)0xffffff6f, (FixedNum)0x000013e5, (FixedNum)0x00001420, (FixedNum)0x0000002c, (FixedNum)0xfffff3da, (FixedNum)0xffffe399, (FixedNum)0xffffe937, (FixedNum)0x00000747, (FixedNum)0x00000099, (FixedNum)0xfffff86a, (FixedNum)0x00000e73, (FixedNum)0xfffff5ad, (FixedNum)0x000025fd, (FixedNum)0xffffdced, (FixedNum)0xfffff9c0, (FixedNum)0x00001907, (FixedNum)0x00001ff2, (FixedNum)0xfffff524, (FixedNum)0x0000120a, (FixedNum)0x0000049b, (FixedNum)0xffffed91, (FixedNum)0x0000080c, (FixedNum)0xfffff1e7, (FixedNum)0xfffff9f7, (FixedNum)0xfffffc73, (FixedNum)0xfffffb86, (FixedNum)0xfffff84b, (FixedNum)0x00000041, (FixedNum)0xfffffb92, (FixedNum)0x00000aba, (FixedNum)0xfffff805, (FixedNum)0xfffff584, (FixedNum)0x000004b7, (FixedNum)0x00000ef0, (FixedNum)0xfffffd42, (FixedNum)0xfffff1a6, (FixedNum)0xffffeea0, (FixedNum)0xffffec0b, (FixedNum)0x00000278, (FixedNum)0x0000021e, (FixedNum)0xffffe96c, (FixedNum)0xfffff8e1, (FixedNum)0xffffec3e, (FixedNum)0xffffec96, (FixedNum)0xfffff9d7, (FixedNum)0xfffff205, (FixedNum)0x00000d30};
const int tmp_connections86[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights87[65] = {(FixedNum)0x00000700, (FixedNum)0x00000b1e, (FixedNum)0xffffedab, (FixedNum)0xfffffd67, (FixedNum)0x000009c4, (FixedNum)0x0000078f, (FixedNum)0xffffd832, (FixedNum)0x0000162e, (FixedNum)0xffffe270, (FixedNum)0x0000028f, (FixedNum)0xfffffd18, (FixedNum)0x0000076f, (FixedNum)0x00000b6b, (FixedNum)0xfffffe67, (FixedNum)0x00000c4a, (FixedNum)0x00000c51, (FixedNum)0x00000f3d, (FixedNum)0x000002a7, (FixedNum)0x00001137, (FixedNum)0x00000795, (FixedNum)0x0000077c, (FixedNum)0xffffee6a, (FixedNum)0x00000e2a, (FixedNum)0xffffeda0, (FixedNum)0xfffff5b6, (FixedNum)0x00000a32, (FixedNum)0x00001a45, (FixedNum)0xfffffd42, (FixedNum)0x0000087f, (FixedNum)0x0000046b, (FixedNum)0x000014dc, (FixedNum)0xfffffefa, (FixedNum)0x00001cee, (FixedNum)0x000019b0, (FixedNum)0x00000782, (FixedNum)0xfffff9ff, (FixedNum)0x00000210, (FixedNum)0x00000135, (FixedNum)0xfffffba2, (FixedNum)0x000004f8, (FixedNum)0xfffffe9e, (FixedNum)0xfffff70b, (FixedNum)0xfffffd74, (FixedNum)0xfffffdc4, (FixedNum)0xfffffd27, (FixedNum)0xfffffb5d, (FixedNum)0x00000419, (FixedNum)0x00000c11, (FixedNum)0x00000109, (FixedNum)0x00000992, (FixedNum)0xfffffdd0, (FixedNum)0x000005b9, (FixedNum)0xfffff88b, (FixedNum)0xfffffdf0, (FixedNum)0x00000308, (FixedNum)0xfffff5ac, (FixedNum)0xffffeb2a, (FixedNum)0xfffff673, (FixedNum)0xffffef09, (FixedNum)0xffffe5a7, (FixedNum)0xfffff559, (FixedNum)0xfffffcc7, (FixedNum)0x0000013b, (FixedNum)0x00000586, (FixedNum)0x00000a24};
const int tmp_connections87[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights88[65] = {(FixedNum)0xfffff514, (FixedNum)0x00002775, (FixedNum)0xfffff89b, (FixedNum)0x00000334, (FixedNum)0xfffff389, (FixedNum)0xfffff54f, (FixedNum)0xfffffa0a, (FixedNum)0xffffed7f, (FixedNum)0xfffffb22, (FixedNum)0x000000ce, (FixedNum)0x00000365, (FixedNum)0xfffff585, (FixedNum)0xfffff658, (FixedNum)0x00000643, (FixedNum)0x000001a1, (FixedNum)0x0000019f, (FixedNum)0x00000e03, (FixedNum)0x000000db, (FixedNum)0x00000848, (FixedNum)0xfffff578, (FixedNum)0xfffff595, (FixedNum)0x00000231, (FixedNum)0x00000bd3, (FixedNum)0xfffff0a4, (FixedNum)0x00000abf, (FixedNum)0xfffff1b8, (FixedNum)0xfffffa10, (FixedNum)0x0000035b, (FixedNum)0xfffff897, (FixedNum)0x00001f7a, (FixedNum)0xffffecea, (FixedNum)0x00001c10, (FixedNum)0xfffffc2e, (FixedNum)0xffffff21, (FixedNum)0xfffff5b8, (FixedNum)0x000004c9, (FixedNum)0xfffff63a, (FixedNum)0xfffff8da, (FixedNum)0x0000088c, (FixedNum)0xfffff912, (FixedNum)0x00000253, (FixedNum)0xfffffe77, (FixedNum)0x0000094a, (FixedNum)0x00000c16, (FixedNum)0x0000034c, (FixedNum)0x0000182f, (FixedNum)0x0000020f, (FixedNum)0x00000447, (FixedNum)0x00000614, (FixedNum)0x00000641, (FixedNum)0xfffffbcd, (FixedNum)0xffffec97, (FixedNum)0x000016b5, (FixedNum)0x00000c75, (FixedNum)0x0000063d, (FixedNum)0x000003af, (FixedNum)0xfffff465, (FixedNum)0xfffffbec, (FixedNum)0x000005e3, (FixedNum)0xfffff901, (FixedNum)0x0000045d, (FixedNum)0x000004f9, (FixedNum)0x00000b62, (FixedNum)0xfffffdd9, (FixedNum)0xfffffeda};
const int tmp_connections88[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights89[65] = {(FixedNum)0x00000ac1, (FixedNum)0xffffe8df, (FixedNum)0x00000813, (FixedNum)0x000003b5, (FixedNum)0x00001580, (FixedNum)0x00001092, (FixedNum)0xfffff247, (FixedNum)0x00000c55, (FixedNum)0xffffdc7c, (FixedNum)0x00000058, (FixedNum)0x000003bd, (FixedNum)0x00001099, (FixedNum)0xfffff5e1, (FixedNum)0xfffff2a9, (FixedNum)0x00000a0e, (FixedNum)0x00000a18, (FixedNum)0xfffff296, (FixedNum)0x00000061, (FixedNum)0xfffffcba, (FixedNum)0x000010c9, (FixedNum)0x000010e5, (FixedNum)0xfffff310, (FixedNum)0x000000a0, (FixedNum)0x00000d8a, (FixedNum)0xfffff3e0, (FixedNum)0x000014d4, (FixedNum)0xffffe8f0, (FixedNum)0x000003c7, (FixedNum)0x0000124e, (FixedNum)0xfffff516, (FixedNum)0x000019b1, (FixedNum)0xfffff1f1, (FixedNum)0x00000152, (FixedNum)0x0000166d, (FixedNum)0x000009f0, (FixedNum)0xfffffac9, (FixedNum)0x000005bc, (FixedNum)0xfffff0df, (FixedNum)0xfffff7c8, (FixedNum)0x0000067a, (FixedNum)0xfffff942, (FixedNum)0x0000077f, (FixedNum)0xfffff0ea, (FixedNum)0x0000057e, (FixedNum)0x000003cc, (FixedNum)0x00000335, (FixedNum)0x00000265, (FixedNum)0xfffff86c, (FixedNum)0xffffffe2, (FixedNum)0xfffffa7e, (FixedNum)0x0000074e, (FixedNum)0x00000352, (FixedNum)0x00000802, (FixedNum)0xfffff249, (FixedNum)0xffffff57, (FixedNum)0x000000bd, (FixedNum)0xfffffd07, (FixedNum)0xfffffabf, (FixedNum)0xffffff92, (FixedNum)0xfffff65c, (FixedNum)0xfffff85d, (FixedNum)0x0000081d, (FixedNum)0x00000d85, (FixedNum)0x00001aa7, (FixedNum)0x00001044};
const int tmp_connections89[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights90[65] = {(FixedNum)0x000003b2, (FixedNum)0xfffff042, (FixedNum)0x00000946, (FixedNum)0xfffffebf, (FixedNum)0x00000135, (FixedNum)0x00000317, (FixedNum)0xfffffd18, (FixedNum)0x0000046f, (FixedNum)0xffffff76, (FixedNum)0x000000c1, (FixedNum)0xfffffed4, (FixedNum)0x000002f0, (FixedNum)0x00000421, (FixedNum)0xffffff6d, (FixedNum)0xffffffed, (FixedNum)0x0000002a, (FixedNum)0x000003e5, (FixedNum)0x000000ba, (FixedNum)0x00000314, (FixedNum)0x000002ee, (FixedNum)0x000002b6, (FixedNum)0x000002ad, (FixedNum)0xfffffb3b, (FixedNum)0xfffffa05, (FixedNum)0xffffff61, (FixedNum)0xfffffe86, (FixedNum)0xfffffa7a, (FixedNum)0xffffff0a, (FixedNum)0x00000196, (FixedNum)0xfffff619, (FixedNum)0x00000483, (FixedNum)0xfffff5b5, (FixedNum)0xfffffbb3, (FixedNum)0xfffffed9, (FixedNum)0xfffffbef, (FixedNum)0xfffffe82, (FixedNum)0x00000361, (FixedNum)0x000005a1, (FixedNum)0xfffffed6, (FixedNum)0x0000013e, (FixedNum)0xffffffaf, (FixedNum)0xfffffbda, (FixedNum)0x00000257, (FixedNum)0xfffffad2, (FixedNum)0xfffffef0, (FixedNum)0x0000027e, (FixedNum)0xfffffb32, (FixedNum)0x000003af, (FixedNum)0x00000178, (FixedNum)0xfffffacc, (FixedNum)0x000000e5, (FixedNum)0x0000081f, (FixedNum)0x00000a04, (FixedNum)0xfffff96c, (FixedNum)0xfffffec1, (FixedNum)0xfffffdf8, (FixedNum)0xfffffd9c, (FixedNum)0xfffffdd0, (FixedNum)0xfffffc68, (FixedNum)0x00000687, (FixedNum)0xfffffd49, (FixedNum)0xfffffe35, (FixedNum)0xfffff8c2, (FixedNum)0xfffffc82, (FixedNum)0xfffffd4c};
const int tmp_connections90[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights91[65] = {(FixedNum)0xfffffd4e, (FixedNum)0xfffff229, (FixedNum)0xffffffc6, (FixedNum)0x000001fc, (FixedNum)0x0000066b, (FixedNum)0x00000517, (FixedNum)0xfffffdf8, (FixedNum)0x000007ce, (FixedNum)0xfffffdf0, (FixedNum)0x000003b1, (FixedNum)0x00000221, (FixedNum)0x0000056c, (FixedNum)0xfffffdbd, (FixedNum)0xffffff02, (FixedNum)0x00000955, (FixedNum)0x0000096f, (FixedNum)0x000000dc, (FixedNum)0x000003a4, (FixedNum)0xfffffd2a, (FixedNum)0x0000057b, (FixedNum)0x00000558, (FixedNum)0x00000694, (FixedNum)0xfffff6ac, (FixedNum)0xfffffc81, (FixedNum)0x0000041f, (FixedNum)0x00000419, (FixedNum)0x00000adc, (FixedNum)0x0000025a, (FixedNum)0x00000748, (FixedNum)0x00000206, (FixedNum)0x00000bfe, (FixedNum)0xfffffd9d, (FixedNum)0x00000fb2, (FixedNum)0x00000bb8, (FixedNum)0x0000057a, (FixedNum)0xffffffcd, (FixedNum)0x000000fe, (FixedNum)0xfffffe92, (FixedNum)0x000000f3, (FixedNum)0xffffff88, (FixedNum)0xfffffb65, (FixedNum)0x00000085, (FixedNum)0x0000002a, (FixedNum)0x000005a4, (FixedNum)0x000001fb, (FixedNum)0xfffffcfb, (FixedNum)0x000001c2, (FixedNum)0xfffff4be, (FixedNum)0x0000010b, (FixedNum)0xfffffde6, (FixedNum)0x0000060c, (FixedNum)0x000008da, (FixedNum)0xfffff815, (FixedNum)0x000000f3, (FixedNum)0x0000031f, (FixedNum)0xfffffe64, (FixedNum)0xffffffdd, (FixedNum)0xfffffb14, (FixedNum)0xfffffb83, (FixedNum)0xfffffb73, (FixedNum)0x00000013, (FixedNum)0x00000094, (FixedNum)0xfffffefc, (FixedNum)0x0000002a, (FixedNum)0x000002d3};
const int tmp_connections91[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights92[65] = {(FixedNum)0x000000bc, (FixedNum)0xffffe0aa, (FixedNum)0x0000104c, (FixedNum)0xffffff88, (FixedNum)0x000002c5, (FixedNum)0x000001e4, (FixedNum)0x000007cb, (FixedNum)0x00000e5c, (FixedNum)0x00000e33, (FixedNum)0x000001d0, (FixedNum)0xffffff60, (FixedNum)0x0000022c, (FixedNum)0x0000003a, (FixedNum)0xffffff27, (FixedNum)0x000004a7, (FixedNum)0x00000487, (FixedNum)0x000003a8, (FixedNum)0x0000019a, (FixedNum)0xfffff98d, (FixedNum)0x00000227, (FixedNum)0x00000222, (FixedNum)0x000003ac, (FixedNum)0xfffffbc0, (FixedNum)0xfffffa09, (FixedNum)0x00000e2f, (FixedNum)0x0000046e, (FixedNum)0xfffffcf1, (FixedNum)0xffffff4e, (FixedNum)0x000001ee, (FixedNum)0x0000088a, (FixedNum)0x000004eb, (FixedNum)0x0000014c, (FixedNum)0x00000105, (FixedNum)0x000007d4, (FixedNum)0x000005c2, (FixedNum)0xfffffedb, (FixedNum)0x00000183, (FixedNum)0x00000785, (FixedNum)0x0000042b, (FixedNum)0x00000714, (FixedNum)0x00000773, (FixedNum)0xfffffca7, (FixedNum)0xffffff54, (FixedNum)0xfffff34f, (FixedNum)0xffffffa3, (FixedNum)0x0000055f, (FixedNum)0x00000729, (FixedNum)0xfffff901, (FixedNum)0x000006db, (FixedNum)0x0000079c, (FixedNum)0xfffffdab, (FixedNum)0x00000c2e, (FixedNum)0xfffff97d, (FixedNum)0xffffff63, (FixedNum)0x00000101, (FixedNum)0xfffffe55, (FixedNum)0xfffffc7d, (FixedNum)0xfffff9ec, (FixedNum)0xfffff252, (FixedNum)0xfffff44b, (FixedNum)0xfffffdbc, (FixedNum)0xffffff7a, (FixedNum)0xfffffe8f, (FixedNum)0x0000051f, (FixedNum)0xffffffe9};
const int tmp_connections92[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights93[65] = {(FixedNum)0xffffe4c0, (FixedNum)0x0000213e, (FixedNum)0x0000161f, (FixedNum)0x00000958, (FixedNum)0xffffe8d3, (FixedNum)0xffffe797, (FixedNum)0x00000d89, (FixedNum)0xfffffdd6, (FixedNum)0x000009dc, (FixedNum)0xfffffd4d, (FixedNum)0x0000095f, (FixedNum)0xffffe79f, (FixedNum)0xffffe928, (FixedNum)0x00000c60, (FixedNum)0xffffecc8, (FixedNum)0xffffeca9, (FixedNum)0xfffff93e, (FixedNum)0xfffffd6e, (FixedNum)0xfffffdd1, (FixedNum)0xffffe7a5, (FixedNum)0xffffe799, (FixedNum)0x000004c9, (FixedNum)0x00000e5e, (FixedNum)0x000012f9, (FixedNum)0x00001f2b, (FixedNum)0xfffff841, (FixedNum)0xfffff698, (FixedNum)0x000009a9, (FixedNum)0xffffef02, (FixedNum)0x00000c26, (FixedNum)0xffffd305, (FixedNum)0x00002e35, (FixedNum)0x00000a99, (FixedNum)0xffffe206, (FixedNum)0xffffe1d6, (FixedNum)0x00000cfa, (FixedNum)0xffffea42, (FixedNum)0xfffff2fd, (FixedNum)0x00000ef2, (FixedNum)0xfffff3a7, (FixedNum)0x000003f3, (FixedNum)0x0000032e, (FixedNum)0x00000713, (FixedNum)0x00000e07, (FixedNum)0x0000099c, (FixedNum)0x000009b7, (FixedNum)0x00000861, (FixedNum)0xffffe3c9, (FixedNum)0x00000940, (FixedNum)0x000016a7, (FixedNum)0x000007a4, (FixedNum)0xfffffb7a, (FixedNum)0x00000297, (FixedNum)0x00001ae1, (FixedNum)0x00001007, (FixedNum)0x00001272, (FixedNum)0x000004d9, (FixedNum)0xfffffc57, (FixedNum)0x000016e3, (FixedNum)0x0000016f, (FixedNum)0x00001596, (FixedNum)0x0000123a, (FixedNum)0x0000110d, (FixedNum)0x00001538, (FixedNum)0xfffffa0e};
const int tmp_connections93[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights94[65] = {(FixedNum)0x00000394, (FixedNum)0x00000ca2, (FixedNum)0x00000fc5, (FixedNum)0xfffffe05, (FixedNum)0xfffffcda, (FixedNum)0x00000232, (FixedNum)0x0000249c, (FixedNum)0x000002fb, (FixedNum)0x00000901, (FixedNum)0x00000053, (FixedNum)0xfffffe5a, (FixedNum)0x00000254, (FixedNum)0x0000168d, (FixedNum)0x0000053d, (FixedNum)0x00000167, (FixedNum)0x0000014d, (FixedNum)0x000006be, (FixedNum)0x00000046, (FixedNum)0x000000e8, (FixedNum)0x00000222, (FixedNum)0x00000218, (FixedNum)0x00000153, (FixedNum)0xfffffcf9, (FixedNum)0xfffff2a0, (FixedNum)0xfffffec0, (FixedNum)0xfffff4b4, (FixedNum)0xfffff02b, (FixedNum)0xfffffe06, (FixedNum)0xffffffb7, (FixedNum)0xfffff868, (FixedNum)0x00000173, (FixedNum)0xfffff51e, (FixedNum)0xffffec9f, (FixedNum)0x0000010d, (FixedNum)0x00000012, (FixedNum)0xfffffef1, (FixedNum)0x00000495, (FixedNum)0xffffff14, (FixedNum)0xfffffcac, (FixedNum)0x00000208, (FixedNum)0x000001f6, (FixedNum)0x000008ef, (FixedNum)0xfffff4f2, (FixedNum)0xfffffe32, (FixedNum)0xfffffe33, (FixedNum)0x00001039, (FixedNum)0xffffff0c, (FixedNum)0x00000477, (FixedNum)0xfffffd15, (FixedNum)0xffffff85, (FixedNum)0xfffff057, (FixedNum)0xfffff5e2, (FixedNum)0x00000c7d, (FixedNum)0x00000455, (FixedNum)0x000004a3, (FixedNum)0xfffffeb7, (FixedNum)0xfffff216, (FixedNum)0x00000eb1, (FixedNum)0xffffff77, (FixedNum)0x0000038b, (FixedNum)0xfffffb48, (FixedNum)0xfffffdb3, (FixedNum)0xfffff85a, (FixedNum)0xfffff495, (FixedNum)0x00000818};
const int tmp_connections94[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights95[65] = {(FixedNum)0xfffff170, (FixedNum)0x0000137e, (FixedNum)0xfffff92d, (FixedNum)0x0000059b, (FixedNum)0xfffff6ca, (FixedNum)0xfffff666, (FixedNum)0xfffffb15, (FixedNum)0xfffff159, (FixedNum)0x00000037, (FixedNum)0x000000f7, (FixedNum)0x000005e2, (FixedNum)0xfffff626, (FixedNum)0xfffff746, (FixedNum)0x000006c1, (FixedNum)0xfffffb49, (FixedNum)0xfffffb33, (FixedNum)0xfffffcf2, (FixedNum)0x000000e9, (FixedNum)0xffffff89, (FixedNum)0xfffff67f, (FixedNum)0xfffff664, (FixedNum)0x0000036e, (FixedNum)0x000004c9, (FixedNum)0x000009e8, (FixedNum)0x000001ee, (FixedNum)0xfffffcc8, (FixedNum)0x000001e9, (FixedNum)0x000005dd, (FixedNum)0xfffff945, (FixedNum)0x0000145a, (FixedNum)0xffffed43, (FixedNum)0x000018a1, (FixedNum)0x00000898, (FixedNum)0xfffff71e, (FixedNum)0xfffff8ec, (FixedNum)0x000007dc, (FixedNum)0xfffff7ae, (FixedNum)0xfffffd2c, (FixedNum)0x00000b14, (FixedNum)0xfffffc9e, (FixedNum)0x00000308, (FixedNum)0x00000649, (FixedNum)0x00000164, (FixedNum)0x00000936, (FixedNum)0x00000592, (FixedNum)0xfffff8a1, (FixedNum)0x000004bb, (FixedNum)0x0000024e, (FixedNum)0x0000000d, (FixedNum)0x00000996, (FixedNum)0x000004c8, (FixedNum)0xfffff5e4, (FixedNum)0xfffff7d0, (FixedNum)0x00000e28, (FixedNum)0x000007c5, (FixedNum)0x00000b9b, (FixedNum)0x00000131, (FixedNum)0x000001cb, (FixedNum)0x00000e2a, (FixedNum)0x000000dd, (FixedNum)0x00000b5d, (FixedNum)0x000009ec, (FixedNum)0x000007a7, (FixedNum)0x00000812, (FixedNum)0xfffffbad};
const int tmp_connections95[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights96[65] = {(FixedNum)0x0000074c, (FixedNum)0x00000012, (FixedNum)0x00000958, (FixedNum)0x000000b0, (FixedNum)0x000006f4, (FixedNum)0x00000994, (FixedNum)0x000014c4, (FixedNum)0x00000737, (FixedNum)0x000003df, (FixedNum)0x000004a4, (FixedNum)0x0000009a, (FixedNum)0x000009b0, (FixedNum)0xfffff8c2, (FixedNum)0xfffff869, (FixedNum)0xfffffecb, (FixedNum)0xfffffef6, (FixedNum)0x000005b8, (FixedNum)0x000004d6, (FixedNum)0x00000942, (FixedNum)0x0000096b, (FixedNum)0x00000977, (FixedNum)0xfffffffc, (FixedNum)0xfffffaf1, (FixedNum)0xfffff552, (FixedNum)0xfffffe3e, (FixedNum)0x00000349, (FixedNum)0xffffe949, (FixedNum)0x000000a4, (FixedNum)0x0000068e, (FixedNum)0xffffef39, (FixedNum)0x00000bed, (FixedNum)0xffffe6ff, (FixedNum)0xfffff825, (FixedNum)0xfffffc60, (FixedNum)0x0000003f, (FixedNum)0xffffffe9, (FixedNum)0x0000099e, (FixedNum)0x00000276, (FixedNum)0xfffffcad, (FixedNum)0x0000083b, (FixedNum)0x0000008e, (FixedNum)0x00000559, (FixedNum)0xfffff7b1, (FixedNum)0xfffff640, (FixedNum)0x0000007c, (FixedNum)0xfffffc69, (FixedNum)0xfffffdae, (FixedNum)0xffffff31, (FixedNum)0xfffffb4e, (FixedNum)0xfffff866, (FixedNum)0xfffffecf, (FixedNum)0xffffff83, (FixedNum)0x00000420, (FixedNum)0xfffff6a4, (FixedNum)0xfffff828, (FixedNum)0x00000457, (FixedNum)0xfffffd90, (FixedNum)0xfffff8f9, (FixedNum)0x00000592, (FixedNum)0x00000a9b, (FixedNum)0xfffffff2, (FixedNum)0xfffffd1d, (FixedNum)0x0000021a, (FixedNum)0x00000132, (FixedNum)0xfffffd27};
const int tmp_connections96[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights97[65] = {(FixedNum)0xffffe52a, (FixedNum)0xfffff1c5, (FixedNum)0x00002aca, (FixedNum)0x000006f2, (FixedNum)0xffffe5c1, (FixedNum)0xffffe3cc, (FixedNum)0xffffeaac, (FixedNum)0x0000085b, (FixedNum)0x00001089, (FixedNum)0xfffffc58, (FixedNum)0x000006e4, (FixedNum)0xffffe3d2, (FixedNum)0xffffdef5, (FixedNum)0x0000072e, (FixedNum)0xffffeaa6, (FixedNum)0xffffea9b, (FixedNum)0xfffff258, (FixedNum)0xfffffc0f, (FixedNum)0x0000057a, (FixedNum)0xffffe3b3, (FixedNum)0xffffe3bc, (FixedNum)0x00000009, (FixedNum)0x00000684, (FixedNum)0x000014d5, (FixedNum)0x000003b0, (FixedNum)0xfffff5a4, (FixedNum)0xfffff525, (FixedNum)0x000006f2, (FixedNum)0xffffeb1a, (FixedNum)0x00002e37, (FixedNum)0xffffcc88, (FixedNum)0x00003377, (FixedNum)0xfffff1e5, (FixedNum)0xffffe0d3, (FixedNum)0xffffeced, (FixedNum)0x00000b34, (FixedNum)0xffffe6f0, (FixedNum)0xfffff304, (FixedNum)0x00001599, (FixedNum)0xfffff5ce, (FixedNum)0x0000124a, (FixedNum)0x0000144d, (FixedNum)0xfffff689, (FixedNum)0x00000845, (FixedNum)0x000006c4, (FixedNum)0xffffd784, (FixedNum)0x00000256, (FixedNum)0x00002ca7, (FixedNum)0x0000022a, (FixedNum)0xfffff54b, (FixedNum)0x00000732, (FixedNum)0x00001337, (FixedNum)0xffffffba, (FixedNum)0x000014d4, (FixedNum)0x00001141, (FixedNum)0x000018dd, (FixedNum)0xfffffe8d, (FixedNum)0x000000a9, (FixedNum)0x00001efc, (FixedNum)0x000003eb, (FixedNum)0x00001825, (FixedNum)0x000013d3, (FixedNum)0x0000014d, (FixedNum)0x00000ee9, (FixedNum)0xfffff37b};
const int tmp_connections97[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights98[35] = {(FixedNum)0xffffe510, (FixedNum)0xffffe54a, (FixedNum)0x00001850, (FixedNum)0xffffe4ab, (FixedNum)0xfffff405, (FixedNum)0xfffff87b, (FixedNum)0x00001eb6, (FixedNum)0xffffe2dd, (FixedNum)0x00000e7f, (FixedNum)0x000019bd, (FixedNum)0xffffef5b, (FixedNum)0xffffe8ce, (FixedNum)0xfffff4af, (FixedNum)0x00001eff, (FixedNum)0xffffe30c, (FixedNum)0xffffdc34, (FixedNum)0xffffe4b5, (FixedNum)0x0000043a, (FixedNum)0xfffff4b0, (FixedNum)0xfffff6d0, (FixedNum)0xffffd319, (FixedNum)0x0000016c, (FixedNum)0x00000430, (FixedNum)0xffffe1f6, (FixedNum)0x00000b07, (FixedNum)0xffffdf6e, (FixedNum)0x00001781, (FixedNum)0x00000232, (FixedNum)0xfffff292, (FixedNum)0xfffffb94, (FixedNum)0xfffffa67, (FixedNum)0x00001367, (FixedNum)0xfffff81e, (FixedNum)0x00000b04, (FixedNum)0x00000c66};
const int tmp_connections98[35] = {34, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97};

const FixedNum tmp_weights99[35] = {(FixedNum)0xfffff60e, (FixedNum)0xffffe95b, (FixedNum)0xffffe1b1, (FixedNum)0xffffefc5, (FixedNum)0xffffebc5, (FixedNum)0xffffd097, (FixedNum)0xffffe5a8, (FixedNum)0x0000020e, (FixedNum)0x00001648, (FixedNum)0xffffe23a, (FixedNum)0x000017c1, (FixedNum)0xfffffbf5, (FixedNum)0xffffce40, (FixedNum)0x000007f7, (FixedNum)0xfffff86e, (FixedNum)0xfffff50c, (FixedNum)0xfffffbfd, (FixedNum)0xfffff485, (FixedNum)0x000011ef, (FixedNum)0x000005c5, (FixedNum)0x00001794, (FixedNum)0xfffff733, (FixedNum)0xffffe811, (FixedNum)0x000012c4, (FixedNum)0x00000e12, (FixedNum)0xffffec83, (FixedNum)0xffffdfe4, (FixedNum)0x0000089a, (FixedNum)0xfffff027, (FixedNum)0x00000ffa, (FixedNum)0xffffe600, (FixedNum)0x000016c3, (FixedNum)0xfffff4a9, (FixedNum)0xffffe115, (FixedNum)0xffffe800};
const int tmp_connections99[35] = {34, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97};

const FixedNum tmp_weights100[35] = {(FixedNum)0xfffff12e, (FixedNum)0xfffff90f, (FixedNum)0xfffff7f5, (FixedNum)0x00000a2e, (FixedNum)0xfffffb89, (FixedNum)0x000004a6, (FixedNum)0xfffffd68, (FixedNum)0x000018a6, (FixedNum)0xffffe805, (FixedNum)0xfffffd73, (FixedNum)0xfffff7fe, (FixedNum)0xfffff616, (FixedNum)0xfffffab2, (FixedNum)0xffffddd5, (FixedNum)0x0000171b, (FixedNum)0x00001b9e, (FixedNum)0x00001ac9, (FixedNum)0xfffff8cf, (FixedNum)0xfffffdf0, (FixedNum)0x00000114, (FixedNum)0xfffff839, (FixedNum)0x00000d98, (FixedNum)0xfffffcbb, (FixedNum)0xfffff71d, (FixedNum)0xfffff2ce, (FixedNum)0xfffff974, (FixedNum)0x00000174, (FixedNum)0x000006fd, (FixedNum)0x00000d63, (FixedNum)0x00000a6d, (FixedNum)0xfffffd25, (FixedNum)0xffffef82, (FixedNum)0xfffffa75, (FixedNum)0xfffff9ea, (FixedNum)0xfffffc97};
const int tmp_connections100[35] = {34, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97};

const FixedNum tmp_weights101[35] = {(FixedNum)0xfffff362, (FixedNum)0xffffe20e, (FixedNum)0xfffff7f1, (FixedNum)0x00001003, (FixedNum)0x00001480, (FixedNum)0xfffff50a, (FixedNum)0xfffff95f, (FixedNum)0xfffffa99, (FixedNum)0xffffe7d0, (FixedNum)0xfffffa81, (FixedNum)0xffffeaf3, (FixedNum)0xffffecb0, (FixedNum)0xfffff2d3, (FixedNum)0xfffff6db, (FixedNum)0xfffffbb6, (FixedNum)0xfffff815, (FixedNum)0xfffffb0e, (FixedNum)0x00000b5b, (FixedNum)0xffffeac0, (FixedNum)0xfffff475, (FixedNum)0x000001c2, (FixedNum)0xfffffa89, (FixedNum)0x000018af, (FixedNum)0xffffedec, (FixedNum)0xfffff0c8, (FixedNum)0x00001390, (FixedNum)0xfffff9b5, (FixedNum)0xfffff7fd, (FixedNum)0xfffff62a, (FixedNum)0xffffef35, (FixedNum)0x000018f3, (FixedNum)0xffffe9c8, (FixedNum)0x00000af4, (FixedNum)0xfffff792, (FixedNum)0x00001937};
const int tmp_connections101[35] = {34, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97};

const FixedNum tmp_weights102[35] = {(FixedNum)0xfffff826, (FixedNum)0x000010c1, (FixedNum)0xfffff031, (FixedNum)0x00001606, (FixedNum)0xfffff4b4, (FixedNum)0x00002608, (FixedNum)0xffffefcf, (FixedNum)0xfffff145, (FixedNum)0xfffff27e, (FixedNum)0xffffefb0, (FixedNum)0x00000229, (FixedNum)0x000019bf, (FixedNum)0x0000194c, (FixedNum)0xfffff921, (FixedNum)0xffffff7a, (FixedNum)0x00000aca, (FixedNum)0xfffffbe0, (FixedNum)0x0000045d, (FixedNum)0x00000300, (FixedNum)0xffffff85, (FixedNum)0xffffee1f, (FixedNum)0x000004a5, (FixedNum)0x00000363, (FixedNum)0xfffff4ba, (FixedNum)0xffffeede, (FixedNum)0xffffe89d, (FixedNum)0xfffff5d8, (FixedNum)0x000009cb, (FixedNum)0xfffffc68, (FixedNum)0xffffeb1c, (FixedNum)0xfffff0a2, (FixedNum)0xffffef7a, (FixedNum)0xffffefcd, (FixedNum)0x000009fc, (FixedNum)0x0000105e};
const int tmp_connections102[35] = {34, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97};

const FixedNum tmp_weights103[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
const int tmp_connections103[2] = {1, 98};

const FixedNum tmp_weights104[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
const int tmp_connections104[2] = {1, 99};

const FixedNum tmp_weights105[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
const int tmp_connections105[2] = {1, 100};

const FixedNum tmp_weights106[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
const int tmp_connections106[2] = {1, 101};

const FixedNum tmp_weights107[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
const int tmp_connections107[2] = {1, 102};

const bool sigmoids[NUMBER_OF_NEURONS] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, false, false, false, false, false};

FixedNum m_value[NUMBER_OF_NEURONS];

/* Before every classification, all elements in m_calculated array need to be set to false */
bool m_calculated[NUMBER_OF_NEURONS];

/* Function calculateOutput description:
 * Returns the output value from a neuron
 */
inline void calculateOutput(){
	for (int i = 0; i < INPUT_SIZE; i++){
		m_value[i] = instance[i];
	}

	for (int i = INPUT_SIZE; i < NUMBER_OF_NEURONS; i++){
		FixedNum value = m_weights[i][0];
		for (int j = 0; j < m_connections[i][0]; j++){
			value = fxp_sum(value, fxp_mul(m_weights[i][j+1], m_value[m_connections[i][j+1]]));
		}
		if (sigmoids[i]){
			if (value < (FixedNum)0xffff4c00)
				value = (FixedNum)0;
			else if (value > (FixedNum)0x0000b400)
				value = (FixedNum)0x00000400;
			else{
				value = fxp_div((FixedNum)0x00000400, fxp_sum((FixedNum)0x00000400, fxp_exp(-value)));
			}
		}
		m_value[i] = value;
	}
}

/* Function classify description:
 * Instance array must be initializated, with appropriated attributes, before calling this function
 * Output number 0 means that the instance was classified as 'ruim'
 * Output number 1 means that the instance was classified as 'regular'
 * Output number 2 means that the instance was classified as 'pessimo'
 * Output number 3 means that the instance was classified as 'obstaculos'
 * Output number 4 means that the instance was classified as 'bom'
 */
int classify(){
	FixedNum theArray[OUTPUT_SIZE];
	for (int i = 0; i < INPUT_SIZE; i++){
		if (m_attributeRanges[i] != (FixedNum)0){
			instance[i] = fxp_div(fxp_diff(instance[i], m_attributeBases[i]), m_attributeRanges[i]);
		}
		else{
			instance[i] = fxp_diff(instance[i], m_attributeBases[i]);
		}
	}
	calculateOutput();
	for (int i = 0; i < OUTPUT_SIZE; i++){
		theArray[i] = m_value[m_outputs[i]];
	}
	FixedNum maxValue = -1;
	int indexMax = -1;
	for (int i = 0; i < OUTPUT_SIZE; i++){
		if (theArray[i] > maxValue){
			maxValue = theArray[i];
			indexMax = i;
		}
	}
	return indexMax;
}

void initConnections(){
	m_connections[0] = tmp_connections0;
	m_connections[1] = tmp_connections1;
	m_connections[2] = tmp_connections2;
	m_connections[3] = tmp_connections3;
	m_connections[4] = tmp_connections4;
	m_connections[5] = tmp_connections5;
	m_connections[6] = tmp_connections6;
	m_connections[7] = tmp_connections7;
	m_connections[8] = tmp_connections8;
	m_connections[9] = tmp_connections9;
	m_connections[10] = tmp_connections10;
	m_connections[11] = tmp_connections11;
	m_connections[12] = tmp_connections12;
	m_connections[13] = tmp_connections13;
	m_connections[14] = tmp_connections14;
	m_connections[15] = tmp_connections15;
	m_connections[16] = tmp_connections16;
	m_connections[17] = tmp_connections17;
	m_connections[18] = tmp_connections18;
	m_connections[19] = tmp_connections19;
	m_connections[20] = tmp_connections20;
	m_connections[21] = tmp_connections21;
	m_connections[22] = tmp_connections22;
	m_connections[23] = tmp_connections23;
	m_connections[24] = tmp_connections24;
	m_connections[25] = tmp_connections25;
	m_connections[26] = tmp_connections26;
	m_connections[27] = tmp_connections27;
	m_connections[28] = tmp_connections28;
	m_connections[29] = tmp_connections29;
	m_connections[30] = tmp_connections30;
	m_connections[31] = tmp_connections31;
	m_connections[32] = tmp_connections32;
	m_connections[33] = tmp_connections33;
	m_connections[34] = tmp_connections34;
	m_connections[35] = tmp_connections35;
	m_connections[36] = tmp_connections36;
	m_connections[37] = tmp_connections37;
	m_connections[38] = tmp_connections38;
	m_connections[39] = tmp_connections39;
	m_connections[40] = tmp_connections40;
	m_connections[41] = tmp_connections41;
	m_connections[42] = tmp_connections42;
	m_connections[43] = tmp_connections43;
	m_connections[44] = tmp_connections44;
	m_connections[45] = tmp_connections45;
	m_connections[46] = tmp_connections46;
	m_connections[47] = tmp_connections47;
	m_connections[48] = tmp_connections48;
	m_connections[49] = tmp_connections49;
	m_connections[50] = tmp_connections50;
	m_connections[51] = tmp_connections51;
	m_connections[52] = tmp_connections52;
	m_connections[53] = tmp_connections53;
	m_connections[54] = tmp_connections54;
	m_connections[55] = tmp_connections55;
	m_connections[56] = tmp_connections56;
	m_connections[57] = tmp_connections57;
	m_connections[58] = tmp_connections58;
	m_connections[59] = tmp_connections59;
	m_connections[60] = tmp_connections60;
	m_connections[61] = tmp_connections61;
	m_connections[62] = tmp_connections62;
	m_connections[63] = tmp_connections63;
	m_weights[64] = tmp_weights64;
	m_connections[64] = tmp_connections64;
	m_weights[65] = tmp_weights65;
	m_connections[65] = tmp_connections65;
	m_weights[66] = tmp_weights66;
	m_connections[66] = tmp_connections66;
	m_weights[67] = tmp_weights67;
	m_connections[67] = tmp_connections67;
	m_weights[68] = tmp_weights68;
	m_connections[68] = tmp_connections68;
	m_weights[69] = tmp_weights69;
	m_connections[69] = tmp_connections69;
	m_weights[70] = tmp_weights70;
	m_connections[70] = tmp_connections70;
	m_weights[71] = tmp_weights71;
	m_connections[71] = tmp_connections71;
	m_weights[72] = tmp_weights72;
	m_connections[72] = tmp_connections72;
	m_weights[73] = tmp_weights73;
	m_connections[73] = tmp_connections73;
	m_weights[74] = tmp_weights74;
	m_connections[74] = tmp_connections74;
	m_weights[75] = tmp_weights75;
	m_connections[75] = tmp_connections75;
	m_weights[76] = tmp_weights76;
	m_connections[76] = tmp_connections76;
	m_weights[77] = tmp_weights77;
	m_connections[77] = tmp_connections77;
	m_weights[78] = tmp_weights78;
	m_connections[78] = tmp_connections78;
	m_weights[79] = tmp_weights79;
	m_connections[79] = tmp_connections79;
	m_weights[80] = tmp_weights80;
	m_connections[80] = tmp_connections80;
	m_weights[81] = tmp_weights81;
	m_connections[81] = tmp_connections81;
	m_weights[82] = tmp_weights82;
	m_connections[82] = tmp_connections82;
	m_weights[83] = tmp_weights83;
	m_connections[83] = tmp_connections83;
	m_weights[84] = tmp_weights84;
	m_connections[84] = tmp_connections84;
	m_weights[85] = tmp_weights85;
	m_connections[85] = tmp_connections85;
	m_weights[86] = tmp_weights86;
	m_connections[86] = tmp_connections86;
	m_weights[87] = tmp_weights87;
	m_connections[87] = tmp_connections87;
	m_weights[88] = tmp_weights88;
	m_connections[88] = tmp_connections88;
	m_weights[89] = tmp_weights89;
	m_connections[89] = tmp_connections89;
	m_weights[90] = tmp_weights90;
	m_connections[90] = tmp_connections90;
	m_weights[91] = tmp_weights91;
	m_connections[91] = tmp_connections91;
	m_weights[92] = tmp_weights92;
	m_connections[92] = tmp_connections92;
	m_weights[93] = tmp_weights93;
	m_connections[93] = tmp_connections93;
	m_weights[94] = tmp_weights94;
	m_connections[94] = tmp_connections94;
	m_weights[95] = tmp_weights95;
	m_connections[95] = tmp_connections95;
	m_weights[96] = tmp_weights96;
	m_connections[96] = tmp_connections96;
	m_weights[97] = tmp_weights97;
	m_connections[97] = tmp_connections97;
	m_weights[98] = tmp_weights98;
	m_connections[98] = tmp_connections98;
	m_weights[99] = tmp_weights99;
	m_connections[99] = tmp_connections99;
	m_weights[100] = tmp_weights100;
	m_connections[100] = tmp_connections100;
	m_weights[101] = tmp_weights101;
	m_connections[101] = tmp_connections101;
	m_weights[102] = tmp_weights102;
	m_connections[102] = tmp_connections102;
	m_weights[103] = tmp_weights103;
	m_connections[103] = tmp_connections103;
	m_weights[104] = tmp_weights104;
	m_connections[104] = tmp_connections104;
	m_weights[105] = tmp_weights105;
	m_connections[105] = tmp_connections105;
	m_weights[106] = tmp_weights106;
	m_connections[106] = tmp_connections106;
	m_weights[107] = tmp_weights107;
	m_connections[107] = tmp_connections107;
}
