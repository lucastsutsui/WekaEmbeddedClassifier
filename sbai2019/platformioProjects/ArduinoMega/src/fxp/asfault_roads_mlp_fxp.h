//
// #include <Arduino.h>
// #define TOTAL_BITS 32
// #define FIXED_FBITS 10
// #define SIGNED
// #include "FixedNum.h"
//
//
// #define INPUT_SIZE 64
// #define CLASS_INDEX 64
// #define OUTPUT_SIZE 4
// #define NUMBER_OF_NEURONS 106
//
// /* Instance array must be global
//  * Attributes MUST be sorted in instance array in the following order:
//  * mean_vel
//  * std_vel
//  * temp_ste
//  * temp_mag
//  * temp_roms
//  * temp_mean
//  * temp_tc
//  * temp_zcr
//  * temp_itv
//  * temp_var
//  * temp_std
//  * temp_skewness
//  * temp_kurtosis
//  * temp_ce
//  * temp_ce_norm
//  * temp_crest
//  * temp_max2min
//  * temp_mag2rms
//  * temp_rms2
//  * temp_rssl
//  * temp_mnp
//  * temp_adp
//  * temp_ety
//  * temp_md
//  * temp_iqr2
//  * spec_f0
//  * spec_ste
//  * spec_mag
//  * spec_sc
//  * spec_si
//  * spec_sim
//  * spec_sfm
//  * spec_flux
//  * spec_sro
//  * spec_var
//  * spec_std
//  * spec_skw
//  * spec_kts
//  * spec_max2min
//  * spec_mag2rms
//  * spec_mnp
//  * spec_adp
//  * spec_ety
//  * spec_cov1
//  * spec_cov2
//  * spec_cov3
//  * spec_peaks1
//  * spec_peaks2
//  * spec_peaks3
//  * spec_peaks4
//  * spec_peaks5
//  * spec_peaks6
//  * spec_peaks7
//  * spec_peaks8
//  * spec_peaks9
//  * spec_peaks10
//  * spec_peaks11
//  * spec_peaks12
//  * spec_power1
//  * spec_power2
//  * spec_power3
//  * spec_power4
//  * spec_power5
//  * spec_iqr2
//  */
// FixedNum instance[INPUT_SIZE+1];
//
// const int m_outputs[OUTPUT_SIZE] = {102, 103, 104, 105};
//
// const FixedNum m_attributeBases[INPUT_SIZE] = {(FixedNum)0x000001fc, (FixedNum)0x00000118, (FixedNum)0x0000017c, (FixedNum)0x000001bd, (FixedNum)0x000001b2, (FixedNum)0x00000207, (FixedNum)0x000001e8, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x0000017c, (FixedNum)0x000001b2, (FixedNum)0x000001c0, (FixedNum)0x000001c1, (FixedNum)0x00000183, (FixedNum)0x00000183, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001b2, (FixedNum)0x000001b2, (FixedNum)0x00000200, (FixedNum)0x00000201, (FixedNum)0x000001fc, (FixedNum)0x000001f9, (FixedNum)0x000001ab, (FixedNum)0x00000200, (FixedNum)0x0000018d, (FixedNum)0x000001dc, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000146, (FixedNum)0x00000200, (FixedNum)0x00000128, (FixedNum)0x0000017a, (FixedNum)0x00000202, (FixedNum)0x00000201, (FixedNum)0x000001f5, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x0000017c, (FixedNum)0x00000200, (FixedNum)0x000001c3, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001f3, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000203, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000163, (FixedNum)0x00000157, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001dc, (FixedNum)0x00000202, (FixedNum)0x00000201, (FixedNum)0x000001fe, (FixedNum)0x00000164};
// const FixedNum m_attributeRanges[INPUT_SIZE] = {(FixedNum)0x000001fc, (FixedNum)0x00000118, (FixedNum)0x0000017c, (FixedNum)0x000001bd, (FixedNum)0x000001b2, (FixedNum)0x000001f9, (FixedNum)0x000001e8, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x0000017c, (FixedNum)0x000001b2, (FixedNum)0x000001c0, (FixedNum)0x000001c1, (FixedNum)0x00000183, (FixedNum)0x00000183, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001b2, (FixedNum)0x000001b2, (FixedNum)0x00000200, (FixedNum)0x000001ff, (FixedNum)0x000001fc, (FixedNum)0x000001f9, (FixedNum)0x000001ab, (FixedNum)0x00000200, (FixedNum)0x0000018d, (FixedNum)0x000001dc, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000146, (FixedNum)0x00000200, (FixedNum)0x00000128, (FixedNum)0x0000017a, (FixedNum)0x000001fe, (FixedNum)0x000001ff, (FixedNum)0x000001f5, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x0000017c, (FixedNum)0x00000200, (FixedNum)0x000001c3, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001f3, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001fd, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000163, (FixedNum)0x00000157, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x000001db, (FixedNum)0x000001fe, (FixedNum)0x000001ff, (FixedNum)0x000001fd, (FixedNum)0x00000161};
//
// const FixedNum *m_weights[NUMBER_OF_NEURONS];
// const int *m_connections[NUMBER_OF_NEURONS];
//
// const int tmp_connections0[1] = {0};
//
// const int tmp_connections1[1] = {0};
//
// const int tmp_connections2[1] = {0};
//
// const int tmp_connections3[1] = {0};
//
// const int tmp_connections4[1] = {0};
//
// const int tmp_connections5[1] = {0};
//
// const int tmp_connections6[1] = {0};
//
// const int tmp_connections7[1] = {0};
//
// const int tmp_connections8[1] = {0};
//
// const int tmp_connections9[1] = {0};
//
// const int tmp_connections10[1] = {0};
//
// const int tmp_connections11[1] = {0};
//
// const int tmp_connections12[1] = {0};
//
// const int tmp_connections13[1] = {0};
//
// const int tmp_connections14[1] = {0};
//
// const int tmp_connections15[1] = {0};
//
// const int tmp_connections16[1] = {0};
//
// const int tmp_connections17[1] = {0};
//
// const int tmp_connections18[1] = {0};
//
// const int tmp_connections19[1] = {0};
//
// const int tmp_connections20[1] = {0};
//
// const int tmp_connections21[1] = {0};
//
// const int tmp_connections22[1] = {0};
//
// const int tmp_connections23[1] = {0};
//
// const int tmp_connections24[1] = {0};
//
// const int tmp_connections25[1] = {0};
//
// const int tmp_connections26[1] = {0};
//
// const int tmp_connections27[1] = {0};
//
// const int tmp_connections28[1] = {0};
//
// const int tmp_connections29[1] = {0};
//
// const int tmp_connections30[1] = {0};
//
// const int tmp_connections31[1] = {0};
//
// const int tmp_connections32[1] = {0};
//
// const int tmp_connections33[1] = {0};
//
// const int tmp_connections34[1] = {0};
//
// const int tmp_connections35[1] = {0};
//
// const int tmp_connections36[1] = {0};
//
// const int tmp_connections37[1] = {0};
//
// const int tmp_connections38[1] = {0};
//
// const int tmp_connections39[1] = {0};
//
// const int tmp_connections40[1] = {0};
//
// const int tmp_connections41[1] = {0};
//
// const int tmp_connections42[1] = {0};
//
// const int tmp_connections43[1] = {0};
//
// const int tmp_connections44[1] = {0};
//
// const int tmp_connections45[1] = {0};
//
// const int tmp_connections46[1] = {0};
//
// const int tmp_connections47[1] = {0};
//
// const int tmp_connections48[1] = {0};
//
// const int tmp_connections49[1] = {0};
//
// const int tmp_connections50[1] = {0};
//
// const int tmp_connections51[1] = {0};
//
// const int tmp_connections52[1] = {0};
//
// const int tmp_connections53[1] = {0};
//
// const int tmp_connections54[1] = {0};
//
// const int tmp_connections55[1] = {0};
//
// const int tmp_connections56[1] = {0};
//
// const int tmp_connections57[1] = {0};
//
// const int tmp_connections58[1] = {0};
//
// const int tmp_connections59[1] = {0};
//
// const int tmp_connections60[1] = {0};
//
// const int tmp_connections61[1] = {0};
//
// const int tmp_connections62[1] = {0};
//
// const int tmp_connections63[1] = {0};
//
// const FixedNum tmp_weights64[65] = {(FixedNum)0xffffff73, (FixedNum)0x00000d78, (FixedNum)0x0000020b, (FixedNum)0x00000049, (FixedNum)0x0000054d, (FixedNum)0xffffff68, (FixedNum)0xfffff7c1, (FixedNum)0xfffffdbd, (FixedNum)0x0000006a, (FixedNum)0x0000012b, (FixedNum)0x00000035, (FixedNum)0xffffff65, (FixedNum)0xfffffadd, (FixedNum)0xfffffc72, (FixedNum)0xfffffb5f, (FixedNum)0xfffffb53, (FixedNum)0x00000293, (FixedNum)0x00000159, (FixedNum)0x00000132, (FixedNum)0xffffff57, (FixedNum)0xffffff93, (FixedNum)0x0000046b, (FixedNum)0xfffffc48, (FixedNum)0xfffffee1, (FixedNum)0x00000112, (FixedNum)0x00000b56, (FixedNum)0x00000637, (FixedNum)0xffffff08, (FixedNum)0xffffff0a, (FixedNum)0xfffff72e, (FixedNum)0xfffffee0, (FixedNum)0xfffffcd8, (FixedNum)0xfffff3e3, (FixedNum)0xfffffdbb, (FixedNum)0xfffffb01, (FixedNum)0x00000085, (FixedNum)0x000001f2, (FixedNum)0x00000257, (FixedNum)0x000001f6, (FixedNum)0x0000052f, (FixedNum)0x0000049b, (FixedNum)0xfffff360, (FixedNum)0x0000084a, (FixedNum)0xfffffbdf, (FixedNum)0x00000010, (FixedNum)0xfffff4b0, (FixedNum)0xfffffce6, (FixedNum)0xfffff5e6, (FixedNum)0xffffffe8, (FixedNum)0xfffffbdc, (FixedNum)0xfffffc8d, (FixedNum)0xfffff760, (FixedNum)0xfffffa61, (FixedNum)0x00000223, (FixedNum)0x0000013f, (FixedNum)0x00000365, (FixedNum)0x000001dd, (FixedNum)0x0000061f, (FixedNum)0xfffffa73, (FixedNum)0xfffffc54, (FixedNum)0x000002dd, (FixedNum)0x000002e2, (FixedNum)0x0000059f, (FixedNum)0x0000035e, (FixedNum)0x00000320};
// const int tmp_connections64[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights65[65] = {(FixedNum)0xfffffb77, (FixedNum)0xfffffa3b, (FixedNum)0x0000008d, (FixedNum)0xfffffecc, (FixedNum)0xfffffef1, (FixedNum)0xfffffc2d, (FixedNum)0x00000620, (FixedNum)0xfffffe43, (FixedNum)0x0000049c, (FixedNum)0xfffffc88, (FixedNum)0xfffffeaa, (FixedNum)0xfffffc20, (FixedNum)0xfffffbf7, (FixedNum)0x00000149, (FixedNum)0xfffff81a, (FixedNum)0xfffff80c, (FixedNum)0xfffff7c8, (FixedNum)0xfffffcac, (FixedNum)0xfffffb94, (FixedNum)0xfffffc2f, (FixedNum)0xfffffbe8, (FixedNum)0x000003ae, (FixedNum)0xfffffd7a, (FixedNum)0x00000a9b, (FixedNum)0x00000052, (FixedNum)0x000002d2, (FixedNum)0x000000f8, (FixedNum)0x000000ff, (FixedNum)0xfffffdd4, (FixedNum)0xfffffad5, (FixedNum)0xfffffbca, (FixedNum)0x00000119, (FixedNum)0xfffffc74, (FixedNum)0xfffff864, (FixedNum)0xfffff577, (FixedNum)0x0000004f, (FixedNum)0xfffffcc6, (FixedNum)0x00000196, (FixedNum)0x00000338, (FixedNum)0xffffff98, (FixedNum)0x00000352, (FixedNum)0xfffffdee, (FixedNum)0x000001ca, (FixedNum)0xfffffd05, (FixedNum)0xfffffe93, (FixedNum)0x000001f8, (FixedNum)0x00000217, (FixedNum)0xffffffe6, (FixedNum)0x00000417, (FixedNum)0x00000274, (FixedNum)0x000004df, (FixedNum)0xffffffc8, (FixedNum)0xffffffbe, (FixedNum)0x00000483, (FixedNum)0x00000202, (FixedNum)0x00000231, (FixedNum)0x0000049c, (FixedNum)0x0000044f, (FixedNum)0x000005a6, (FixedNum)0x0000026a, (FixedNum)0x00000a48, (FixedNum)0x0000022f, (FixedNum)0xffffff29, (FixedNum)0xfffffda4, (FixedNum)0xfffffdcf};
// const int tmp_connections65[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights66[65] = {(FixedNum)0xfffff918, (FixedNum)0x000006ab, (FixedNum)0xfffffc71, (FixedNum)0x00000113, (FixedNum)0x000009f8, (FixedNum)0xfffffa19, (FixedNum)0x00000147, (FixedNum)0xffffd5d7, (FixedNum)0x0000184d, (FixedNum)0xfffff4df, (FixedNum)0x00000108, (FixedNum)0xfffffa41, (FixedNum)0xfffff7e1, (FixedNum)0xfffffcb1, (FixedNum)0xfffffcb6, (FixedNum)0xfffffcdd, (FixedNum)0xffffebff, (FixedNum)0xfffff4a5, (FixedNum)0xfffff944, (FixedNum)0xfffffa71, (FixedNum)0xfffffa4c, (FixedNum)0xfffffa39, (FixedNum)0x00000cd8, (FixedNum)0x00001f2e, (FixedNum)0x00000c8a, (FixedNum)0x000019fc, (FixedNum)0x00001e2c, (FixedNum)0x000006e9, (FixedNum)0x00000283, (FixedNum)0xffffea69, (FixedNum)0xfffffe7d, (FixedNum)0xfffffda3, (FixedNum)0xfffff3f6, (FixedNum)0xfffff786, (FixedNum)0xfffff169, (FixedNum)0x00000994, (FixedNum)0x000004b0, (FixedNum)0xfffffbed, (FixedNum)0xfffffe21, (FixedNum)0x0000043f, (FixedNum)0x000000e9, (FixedNum)0xfffffd61, (FixedNum)0x000000d5, (FixedNum)0xfffff9ec, (FixedNum)0x000000e1, (FixedNum)0x0000074f, (FixedNum)0x000005cc, (FixedNum)0xfffff68d, (FixedNum)0xfffffb89, (FixedNum)0xfffffc9a, (FixedNum)0x00000235, (FixedNum)0x00001259, (FixedNum)0x0000129b, (FixedNum)0x00000002, (FixedNum)0x0000012a, (FixedNum)0x00000b5b, (FixedNum)0xfffffd4e, (FixedNum)0x00001914, (FixedNum)0x00000626, (FixedNum)0xfffff90f, (FixedNum)0x00000380, (FixedNum)0x0000079b, (FixedNum)0xfffffc14, (FixedNum)0xfffff38f, (FixedNum)0x0000015e};
// const int tmp_connections66[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights67[65] = {(FixedNum)0xfffffe7a, (FixedNum)0x0000047d, (FixedNum)0xffffffd7, (FixedNum)0xffffff09, (FixedNum)0xffffff24, (FixedNum)0xfffffecd, (FixedNum)0xfffffc46, (FixedNum)0xffffff20, (FixedNum)0x00000144, (FixedNum)0xfffffee7, (FixedNum)0xffffff00, (FixedNum)0xfffffee0, (FixedNum)0xffffff7a, (FixedNum)0x000000bb, (FixedNum)0xffffff62, (FixedNum)0xffffff6d, (FixedNum)0xfffffe3b, (FixedNum)0xfffffee1, (FixedNum)0xffffffe7, (FixedNum)0xfffffec6, (FixedNum)0xfffffeff, (FixedNum)0x00000087, (FixedNum)0x00000005, (FixedNum)0x00000233, (FixedNum)0xffffffcf, (FixedNum)0xffffff7c, (FixedNum)0xfffffce6, (FixedNum)0xfffffed4, (FixedNum)0xfffffe52, (FixedNum)0x0000049c, (FixedNum)0xfffffdf7, (FixedNum)0x000001fc, (FixedNum)0xfffffd46, (FixedNum)0xffffff7d, (FixedNum)0x00000107, (FixedNum)0xffffff56, (FixedNum)0xffffff12, (FixedNum)0x00000142, (FixedNum)0x00000082, (FixedNum)0xfffffddf, (FixedNum)0xfffffef4, (FixedNum)0xffffff08, (FixedNum)0x000000a1, (FixedNum)0x000001e1, (FixedNum)0xffffff47, (FixedNum)0x00000200, (FixedNum)0xfffffdf4, (FixedNum)0x000001a7, (FixedNum)0x000000d7, (FixedNum)0x0000015e, (FixedNum)0xffffffb1, (FixedNum)0x0000001d, (FixedNum)0x0000006c, (FixedNum)0x000000b6, (FixedNum)0x000002a7, (FixedNum)0x0000013b, (FixedNum)0x0000022d, (FixedNum)0x0000018b, (FixedNum)0xfffffe13, (FixedNum)0x000001d7, (FixedNum)0x0000004e, (FixedNum)0xfffffd80, (FixedNum)0xffffff8e, (FixedNum)0x0000006b, (FixedNum)0xffffff20};
// const int tmp_connections67[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights68[65] = {(FixedNum)0x000003df, (FixedNum)0xfffff761, (FixedNum)0xfffffc61, (FixedNum)0x000001e0, (FixedNum)0xfffff87a, (FixedNum)0x00000464, (FixedNum)0xffffebf4, (FixedNum)0x0000077c, (FixedNum)0xfffff617, (FixedNum)0x00000953, (FixedNum)0x000001c7, (FixedNum)0x000004a9, (FixedNum)0x00000e6b, (FixedNum)0x00000654, (FixedNum)0x00000416, (FixedNum)0x00000458, (FixedNum)0x000013c1, (FixedNum)0x00000909, (FixedNum)0xfffffbf6, (FixedNum)0x00000462, (FixedNum)0x000004aa, (FixedNum)0x00000ac1, (FixedNum)0xfffff192, (FixedNum)0xffffe503, (FixedNum)0xfffff526, (FixedNum)0xffffe99f, (FixedNum)0xffffeffb, (FixedNum)0x00000029, (FixedNum)0xfffffdc5, (FixedNum)0xfffff838, (FixedNum)0xfffff91c, (FixedNum)0x00000931, (FixedNum)0xffffde8e, (FixedNum)0x0000079a, (FixedNum)0xfffff687, (FixedNum)0x0000042f, (FixedNum)0x0000062c, (FixedNum)0x0000097f, (FixedNum)0x000003ae, (FixedNum)0x00000161, (FixedNum)0x00000470, (FixedNum)0x00000871, (FixedNum)0xfffffbb1, (FixedNum)0xffffffa9, (FixedNum)0x000001d7, (FixedNum)0xfffff562, (FixedNum)0xffffff34, (FixedNum)0x000002d6, (FixedNum)0xfffff243, (FixedNum)0xfffffeff, (FixedNum)0xfffff511, (FixedNum)0x00000dbd, (FixedNum)0x000017a0, (FixedNum)0xfffff248, (FixedNum)0xfffffe0d, (FixedNum)0xfffff076, (FixedNum)0x00000abd, (FixedNum)0xfffff17d, (FixedNum)0xfffffc03, (FixedNum)0x0000018e, (FixedNum)0xfffffe0c, (FixedNum)0xfffffbca, (FixedNum)0x0000085f, (FixedNum)0x00000bf0, (FixedNum)0xfffffb0a};
// const int tmp_connections68[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights69[65] = {(FixedNum)0xfffff882, (FixedNum)0x00000b49, (FixedNum)0x00000f20, (FixedNum)0x00000175, (FixedNum)0x0000025e, (FixedNum)0xfffffb0e, (FixedNum)0xffffeaa5, (FixedNum)0xffffefc5, (FixedNum)0x0000010e, (FixedNum)0xfffffd91, (FixedNum)0x00000166, (FixedNum)0xfffffb42, (FixedNum)0xfffff1fa, (FixedNum)0x00000216, (FixedNum)0xfffff901, (FixedNum)0xfffff8fa, (FixedNum)0x0000000b, (FixedNum)0xfffffd98, (FixedNum)0x00000485, (FixedNum)0xfffffb54, (FixedNum)0xfffffb39, (FixedNum)0x000025ec, (FixedNum)0xffffe550, (FixedNum)0x00000a3b, (FixedNum)0x000017a7, (FixedNum)0x000009ec, (FixedNum)0x000001f5, (FixedNum)0x00000321, (FixedNum)0xfffffc54, (FixedNum)0xffffeb3b, (FixedNum)0xfffff733, (FixedNum)0xfffffe29, (FixedNum)0xfffffb85, (FixedNum)0xfffff007, (FixedNum)0xfffff8b3, (FixedNum)0x000003af, (FixedNum)0xfffffffa, (FixedNum)0x00000f05, (FixedNum)0x00000c88, (FixedNum)0xfffff7e9, (FixedNum)0x00000607, (FixedNum)0xfffffa5e, (FixedNum)0x0000045c, (FixedNum)0xfffffe75, (FixedNum)0x00000187, (FixedNum)0x00002d98, (FixedNum)0x000012eb, (FixedNum)0xfffff16e, (FixedNum)0xfffff6b4, (FixedNum)0x000005af, (FixedNum)0x00001396, (FixedNum)0x0000118c, (FixedNum)0x0000043e, (FixedNum)0x000010d1, (FixedNum)0xfffffb08, (FixedNum)0x0000067f, (FixedNum)0xfffffab2, (FixedNum)0xfffff392, (FixedNum)0x00000123, (FixedNum)0xfffffbeb, (FixedNum)0xfffff187, (FixedNum)0x00001896, (FixedNum)0x000008a6, (FixedNum)0xfffffbe3, (FixedNum)0xfffff630};
// const int tmp_connections69[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights70[65] = {(FixedNum)0xfffffa3f, (FixedNum)0x000002f1, (FixedNum)0xfffffa8e, (FixedNum)0xfffffef6, (FixedNum)0x00000717, (FixedNum)0xfffff7cd, (FixedNum)0xffffcc9e, (FixedNum)0xfffffd30, (FixedNum)0xfffff4fb, (FixedNum)0xfffffbe0, (FixedNum)0xfffffee7, (FixedNum)0xfffff7fb, (FixedNum)0xffffeaef, (FixedNum)0xfffffb0f, (FixedNum)0xffffef1f, (FixedNum)0xffffef1e, (FixedNum)0xfffffda0, (FixedNum)0xfffffc1e, (FixedNum)0xfffffa02, (FixedNum)0xfffff7d5, (FixedNum)0xfffff7df, (FixedNum)0xfffff9c9, (FixedNum)0x00000d9a, (FixedNum)0x00001186, (FixedNum)0x00001446, (FixedNum)0x00001885, (FixedNum)0xffffe6b4, (FixedNum)0x00000435, (FixedNum)0xfffffe79, (FixedNum)0xfffff651, (FixedNum)0xfffff8aa, (FixedNum)0xffffff7d, (FixedNum)0xffffe67f, (FixedNum)0xfffff4f6, (FixedNum)0xffffff26, (FixedNum)0x000005b7, (FixedNum)0xffffff46, (FixedNum)0xfffffe8a, (FixedNum)0x0000008b, (FixedNum)0x00000147, (FixedNum)0xfffffcb3, (FixedNum)0xffffe354, (FixedNum)0x000011a5, (FixedNum)0x00000428, (FixedNum)0xfffffee5, (FixedNum)0xffffec73, (FixedNum)0x00000918, (FixedNum)0xffffdfd9, (FixedNum)0x00000a99, (FixedNum)0x000005dd, (FixedNum)0x00001453, (FixedNum)0x00001377, (FixedNum)0x00000290, (FixedNum)0x00001a93, (FixedNum)0xfffffc6b, (FixedNum)0xfffffb9f, (FixedNum)0x000001c3, (FixedNum)0x00000a97, (FixedNum)0x00001502, (FixedNum)0xfffff6ea, (FixedNum)0x00000c9f, (FixedNum)0x00001376, (FixedNum)0xfffff9a0, (FixedNum)0x00000459, (FixedNum)0x000000e3};
// const int tmp_connections70[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights71[65] = {(FixedNum)0x0000023b, (FixedNum)0xffffecae, (FixedNum)0xfffff44e, (FixedNum)0x0000052e, (FixedNum)0x0000008c, (FixedNum)0x0000068b, (FixedNum)0x00000d55, (FixedNum)0x00001752, (FixedNum)0xfffff28d, (FixedNum)0x000002ff, (FixedNum)0x0000054d, (FixedNum)0x0000064d, (FixedNum)0x000003b3, (FixedNum)0x0000010f, (FixedNum)0x00000325, (FixedNum)0x00000337, (FixedNum)0x00000068, (FixedNum)0x00000303, (FixedNum)0xfffff930, (FixedNum)0x00000637, (FixedNum)0x00000658, (FixedNum)0xfffffd72, (FixedNum)0x00000100, (FixedNum)0xffffff7a, (FixedNum)0xfffff061, (FixedNum)0xfffff717, (FixedNum)0x0000067b, (FixedNum)0xffffff5d, (FixedNum)0xfffffeeb, (FixedNum)0xfffff71b, (FixedNum)0xffffff02, (FixedNum)0xfffffebc, (FixedNum)0xfffffd6d, (FixedNum)0xfffff9b9, (FixedNum)0xfffffc36, (FixedNum)0xfffffeb5, (FixedNum)0xfffffe1f, (FixedNum)0xfffffbd9, (FixedNum)0xfffffb8c, (FixedNum)0xfffffc2d, (FixedNum)0xfffffda9, (FixedNum)0x000001d4, (FixedNum)0x00000283, (FixedNum)0x0000010a, (FixedNum)0x00000534, (FixedNum)0xffffff1a, (FixedNum)0xfffffcef, (FixedNum)0xffffff1b, (FixedNum)0xfffffdac, (FixedNum)0xffffffd4, (FixedNum)0xffffff3a, (FixedNum)0xfffff53b, (FixedNum)0xfffff893, (FixedNum)0xfffffca7, (FixedNum)0x00000160, (FixedNum)0xfffffd38, (FixedNum)0xfffffa83, (FixedNum)0xfffffcce, (FixedNum)0x0000093f, (FixedNum)0x00000831, (FixedNum)0xfffffe0a, (FixedNum)0x00000f65, (FixedNum)0x0000043d, (FixedNum)0x0000061e, (FixedNum)0xffffff21};
// const int tmp_connections71[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights72[65] = {(FixedNum)0x00000445, (FixedNum)0x0000181d, (FixedNum)0xfffff488, (FixedNum)0xfffffae1, (FixedNum)0xfffffd69, (FixedNum)0xfffffe07, (FixedNum)0x000003d0, (FixedNum)0xfffffaed, (FixedNum)0x000005d3, (FixedNum)0x0000000a, (FixedNum)0xfffffb0a, (FixedNum)0xfffffe0f, (FixedNum)0x0000010f, (FixedNum)0xfffffb96, (FixedNum)0xfffff7e7, (FixedNum)0xfffff7f8, (FixedNum)0x0000033f, (FixedNum)0xfffffff6, (FixedNum)0x000009ca, (FixedNum)0xfffffe34, (FixedNum)0xfffffdee, (FixedNum)0x00000977, (FixedNum)0xfffff775, (FixedNum)0xfffff3fd, (FixedNum)0x00001129, (FixedNum)0xfffffc8e, (FixedNum)0x0000018e, (FixedNum)0xfffff98d, (FixedNum)0xfffffe01, (FixedNum)0xffffef5c, (FixedNum)0x00000264, (FixedNum)0xfffffd8e, (FixedNum)0x0000029c, (FixedNum)0x00000388, (FixedNum)0xfffff0f8, (FixedNum)0xfffffb60, (FixedNum)0x000000b9, (FixedNum)0xffffff45, (FixedNum)0xfffffb35, (FixedNum)0x00000616, (FixedNum)0xfffffdbe, (FixedNum)0xfffffb8c, (FixedNum)0xfffffef3, (FixedNum)0xffffffd6, (FixedNum)0xfffffac5, (FixedNum)0x0000051a, (FixedNum)0xfffff08a, (FixedNum)0x000001ca, (FixedNum)0xffffff7d, (FixedNum)0xffffff13, (FixedNum)0xfffff723, (FixedNum)0x00000bd1, (FixedNum)0x00000183, (FixedNum)0xfffffec4, (FixedNum)0x00000712, (FixedNum)0x0000126d, (FixedNum)0xffffff70, (FixedNum)0xfffffa93, (FixedNum)0xfffffef9, (FixedNum)0x00000278, (FixedNum)0x0000066d, (FixedNum)0xfffffc9e, (FixedNum)0x000003e8, (FixedNum)0xfffffee5, (FixedNum)0x00000080};
// const int tmp_connections72[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights73[65] = {(FixedNum)0x00000ab7, (FixedNum)0xfffffcbd, (FixedNum)0xffffe71a, (FixedNum)0x0000081b, (FixedNum)0x00000789, (FixedNum)0x00000f78, (FixedNum)0x000006fa, (FixedNum)0x00002cdc, (FixedNum)0xfffff3f4, (FixedNum)0x00000721, (FixedNum)0x000007e6, (FixedNum)0x00000f75, (FixedNum)0xfffffd48, (FixedNum)0xfffffa36, (FixedNum)0x0000108c, (FixedNum)0x000010a4, (FixedNum)0x000001c1, (FixedNum)0x00000743, (FixedNum)0xffffe93a, (FixedNum)0x00000f1a, (FixedNum)0x00000f57, (FixedNum)0x000006d9, (FixedNum)0xfffff040, (FixedNum)0xfffff92b, (FixedNum)0xfffff9ae, (FixedNum)0xfffffcda, (FixedNum)0xfffffc1a, (FixedNum)0xfffff6ca, (FixedNum)0xfffff9a5, (FixedNum)0xfffff7f0, (FixedNum)0xfffffbbe, (FixedNum)0x0000145b, (FixedNum)0xfffff769, (FixedNum)0x00000f97, (FixedNum)0x000001fe, (FixedNum)0xfffff5eb, (FixedNum)0xfffffa60, (FixedNum)0x000007f8, (FixedNum)0x0000019e, (FixedNum)0x00000831, (FixedNum)0x000011c8, (FixedNum)0xffffec60, (FixedNum)0x00000f32, (FixedNum)0xffffec30, (FixedNum)0x000007fb, (FixedNum)0x000005c3, (FixedNum)0x0000027f, (FixedNum)0x00001414, (FixedNum)0xfffffb43, (FixedNum)0x00000451, (FixedNum)0xfffffb9b, (FixedNum)0xfffff594, (FixedNum)0x00000e1f, (FixedNum)0xfffffbcd, (FixedNum)0x0000028e, (FixedNum)0xfffff0a8, (FixedNum)0x00000461, (FixedNum)0x00000549, (FixedNum)0xfffffdd8, (FixedNum)0x000010c4, (FixedNum)0x0000005b, (FixedNum)0xfffffacc, (FixedNum)0x00000280, (FixedNum)0x000003ed, (FixedNum)0xfffff49d};
// const int tmp_connections73[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights74[65] = {(FixedNum)0xfffff420, (FixedNum)0xfffffa43, (FixedNum)0x0000097b, (FixedNum)0xfffffe53, (FixedNum)0xfffffda3, (FixedNum)0xfffff517, (FixedNum)0x00001d35, (FixedNum)0x0000091a, (FixedNum)0x000016ef, (FixedNum)0xffffff95, (FixedNum)0xfffffe6b, (FixedNum)0xfffff4cc, (FixedNum)0x000001b3, (FixedNum)0x00000626, (FixedNum)0xfffffa8f, (FixedNum)0xfffffabb, (FixedNum)0x000004c1, (FixedNum)0xffffffb3, (FixedNum)0x00000c55, (FixedNum)0xfffff50f, (FixedNum)0xfffff4ca, (FixedNum)0xfffffa06, (FixedNum)0x00000a51, (FixedNum)0x00000418, (FixedNum)0x00000a51, (FixedNum)0x000005d2, (FixedNum)0xfffffd53, (FixedNum)0x000003cf, (FixedNum)0xfffffc9f, (FixedNum)0x00000730, (FixedNum)0xfffff61d, (FixedNum)0x00000c42, (FixedNum)0x0000062b, (FixedNum)0xfffff681, (FixedNum)0x00000998, (FixedNum)0xfffffeac, (FixedNum)0xfffff371, (FixedNum)0xfffffdaa, (FixedNum)0x000006a0, (FixedNum)0xfffff37f, (FixedNum)0xffffff6f, (FixedNum)0x00000d27, (FixedNum)0xfffff475, (FixedNum)0x00000450, (FixedNum)0xfffffea0, (FixedNum)0x000010b7, (FixedNum)0x00000567, (FixedNum)0xfffff719, (FixedNum)0x00000585, (FixedNum)0x00000704, (FixedNum)0x000009b8, (FixedNum)0x000004f0, (FixedNum)0x000013d4, (FixedNum)0x00000a62, (FixedNum)0x000002da, (FixedNum)0xffffef46, (FixedNum)0x000001c9, (FixedNum)0x000009ad, (FixedNum)0xfffffe33, (FixedNum)0xfffffa0d, (FixedNum)0xfffff856, (FixedNum)0xffffffb9, (FixedNum)0x000004fa, (FixedNum)0x00000334, (FixedNum)0xffffffae};
// const int tmp_connections74[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights75[65] = {(FixedNum)0xfffffe5f, (FixedNum)0xfffffe64, (FixedNum)0x000001b4, (FixedNum)0xffffff5b, (FixedNum)0xffffffce, (FixedNum)0xfffffeee, (FixedNum)0x00000139, (FixedNum)0xfffffe24, (FixedNum)0x00000338, (FixedNum)0xffffff4c, (FixedNum)0xffffffa6, (FixedNum)0xfffffea4, (FixedNum)0xffffff4e, (FixedNum)0x000000cf, (FixedNum)0xfffffe02, (FixedNum)0xfffffe09, (FixedNum)0xfffffe6a, (FixedNum)0xffffff75, (FixedNum)0x00000011, (FixedNum)0xfffffecc, (FixedNum)0xfffffeb1, (FixedNum)0x00000119, (FixedNum)0x00000015, (FixedNum)0x00000281, (FixedNum)0x000001ab, (FixedNum)0x00000166, (FixedNum)0x000000e9, (FixedNum)0x00000076, (FixedNum)0xffffffcb, (FixedNum)0xfffffe6b, (FixedNum)0xffffff25, (FixedNum)0xffffff27, (FixedNum)0xfffffe2d, (FixedNum)0xfffffe2a, (FixedNum)0xffffff3f, (FixedNum)0x000000bc, (FixedNum)0x00000039, (FixedNum)0x0000016f, (FixedNum)0x00000126, (FixedNum)0x0000005c, (FixedNum)0x000000b8, (FixedNum)0xffffff02, (FixedNum)0x00000134, (FixedNum)0xfffffe6d, (FixedNum)0xffffff5c, (FixedNum)0xffffffae, (FixedNum)0xfffffffa, (FixedNum)0x00000174, (FixedNum)0x00000119, (FixedNum)0x00000105, (FixedNum)0x00000126, (FixedNum)0x00000032, (FixedNum)0x0000000e, (FixedNum)0x000000e1, (FixedNum)0x00000106, (FixedNum)0x00000159, (FixedNum)0x0000018e, (FixedNum)0x0000003f, (FixedNum)0x000000f3, (FixedNum)0x00000053, (FixedNum)0x0000027e, (FixedNum)0x000000e8, (FixedNum)0x00000072, (FixedNum)0xffffff82, (FixedNum)0xffffff74};
// const int tmp_connections75[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights76[65] = {(FixedNum)0xfffffcc6, (FixedNum)0xfffff94f, (FixedNum)0x00000192, (FixedNum)0xfffffe04, (FixedNum)0x000003eb, (FixedNum)0xfffffdcf, (FixedNum)0xffffff91, (FixedNum)0x00000a73, (FixedNum)0x00000998, (FixedNum)0xffffff51, (FixedNum)0xfffffe2b, (FixedNum)0xfffffdd8, (FixedNum)0xfffff822, (FixedNum)0xfffffd28, (FixedNum)0xffffff9a, (FixedNum)0xffffff5b, (FixedNum)0xfffff6cd, (FixedNum)0xffffff39, (FixedNum)0xfffffbb3, (FixedNum)0xfffffdc9, (FixedNum)0xfffffdad, (FixedNum)0x00000f7d, (FixedNum)0xfffff56f, (FixedNum)0x00000998, (FixedNum)0x000005e4, (FixedNum)0x00000a60, (FixedNum)0x00000950, (FixedNum)0x0000010a, (FixedNum)0x0000015d, (FixedNum)0xffffed0d, (FixedNum)0x0000035e, (FixedNum)0xfffff414, (FixedNum)0x00000478, (FixedNum)0xfffff7aa, (FixedNum)0x00000bff, (FixedNum)0x0000024a, (FixedNum)0x000002b9, (FixedNum)0x00000ce2, (FixedNum)0x000008d8, (FixedNum)0x00000e8d, (FixedNum)0x000011fd, (FixedNum)0xfffff5d0, (FixedNum)0x00000724, (FixedNum)0xffffe46e, (FixedNum)0xfffffe16, (FixedNum)0xffffd311, (FixedNum)0x000000c2, (FixedNum)0xfffff254, (FixedNum)0x0000023e, (FixedNum)0xfffff651, (FixedNum)0xfffffe12, (FixedNum)0x00000101, (FixedNum)0x00000d48, (FixedNum)0x00000703, (FixedNum)0x0000001f, (FixedNum)0x00001442, (FixedNum)0xffffe796, (FixedNum)0x00000b2b, (FixedNum)0x000008e6, (FixedNum)0xfffffbe7, (FixedNum)0xfffffa5b, (FixedNum)0x00000533, (FixedNum)0x00000412, (FixedNum)0xfffff508, (FixedNum)0xfffff97b};
// const int tmp_connections76[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights77[65] = {(FixedNum)0xfffff7d3, (FixedNum)0xfffff7ed, (FixedNum)0x00000561, (FixedNum)0xfffffd6f, (FixedNum)0x000001bf, (FixedNum)0xfffff827, (FixedNum)0x00000a39, (FixedNum)0x00000154, (FixedNum)0x00002d92, (FixedNum)0xfffff765, (FixedNum)0xfffffd2c, (FixedNum)0xfffff85c, (FixedNum)0xffffff27, (FixedNum)0x00000297, (FixedNum)0xfffff9a1, (FixedNum)0xfffff9a2, (FixedNum)0xffffebf4, (FixedNum)0xfffff774, (FixedNum)0x00000414, (FixedNum)0xfffff863, (FixedNum)0xfffff841, (FixedNum)0x00002098, (FixedNum)0xffffe50e, (FixedNum)0x000016c5, (FixedNum)0x00000697, (FixedNum)0x00001516, (FixedNum)0x00000957, (FixedNum)0x000008e7, (FixedNum)0x000007c9, (FixedNum)0xffffe73f, (FixedNum)0x00000740, (FixedNum)0xfffff6a0, (FixedNum)0xfffffb98, (FixedNum)0x00000578, (FixedNum)0x00001361, (FixedNum)0x00000cb0, (FixedNum)0x00000d7f, (FixedNum)0xffffffa4, (FixedNum)0x000002ff, (FixedNum)0xfffffd87, (FixedNum)0xfffffa5b, (FixedNum)0x000009ca, (FixedNum)0xfffffd1f, (FixedNum)0x00000c68, (FixedNum)0xfffffd2d, (FixedNum)0x000003aa, (FixedNum)0x000018f1, (FixedNum)0xfffff7f6, (FixedNum)0x00000795, (FixedNum)0x0000063c, (FixedNum)0xfffffc68, (FixedNum)0x00000a79, (FixedNum)0xffffddef, (FixedNum)0x00001656, (FixedNum)0xfffffcda, (FixedNum)0xfffffc51, (FixedNum)0xfffffeb2, (FixedNum)0xffffffca, (FixedNum)0x000000e3, (FixedNum)0xffffe77b, (FixedNum)0xfffffc6d, (FixedNum)0x00001d90, (FixedNum)0x00000af7, (FixedNum)0x00001675, (FixedNum)0x00000387};
// const int tmp_connections77[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights78[65] = {(FixedNum)0x000000f6, (FixedNum)0xfffff16d, (FixedNum)0x00000a78, (FixedNum)0xfffffd10, (FixedNum)0xfffff9f5, (FixedNum)0xfffffe9b, (FixedNum)0xfffffc55, (FixedNum)0xfffffeb4, (FixedNum)0x000008b2, (FixedNum)0x000001c3, (FixedNum)0xfffffd31, (FixedNum)0xfffffeaa, (FixedNum)0xfffffc27, (FixedNum)0x000001b0, (FixedNum)0xfffffabc, (FixedNum)0xfffffa8d, (FixedNum)0x000006fc, (FixedNum)0x000001b0, (FixedNum)0x000000a9, (FixedNum)0xfffffeba, (FixedNum)0xfffffe99, (FixedNum)0xfffff7ee, (FixedNum)0x000006fe, (FixedNum)0xfffff3d3, (FixedNum)0xffffff3b, (FixedNum)0xfffff3c9, (FixedNum)0xfffffad0, (FixedNum)0xffffff5e, (FixedNum)0xffffff6a, (FixedNum)0xffffff76, (FixedNum)0xffffff87, (FixedNum)0xfffff8b7, (FixedNum)0xfffff6a0, (FixedNum)0xfffffb54, (FixedNum)0x000009db, (FixedNum)0x00000256, (FixedNum)0x00000631, (FixedNum)0x00000503, (FixedNum)0xfffffe6e, (FixedNum)0x000002a6, (FixedNum)0x000000cc, (FixedNum)0xffffff5a, (FixedNum)0x0000000d, (FixedNum)0xfffffbe1, (FixedNum)0xfffffd2a, (FixedNum)0x0000063d, (FixedNum)0x00000052, (FixedNum)0x00000fca, (FixedNum)0x000007b1, (FixedNum)0x00000507, (FixedNum)0x0000008f, (FixedNum)0xffffff37, (FixedNum)0xfffffaac, (FixedNum)0xfffffa87, (FixedNum)0x000002b9, (FixedNum)0x00000d03, (FixedNum)0xfffff9d5, (FixedNum)0xfffffc27, (FixedNum)0xfffffc32, (FixedNum)0x0000011f, (FixedNum)0x00000832, (FixedNum)0xfffff986, (FixedNum)0x00000019, (FixedNum)0xfffffbe4, (FixedNum)0xfffffcc4};
// const int tmp_connections78[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights79[65] = {(FixedNum)0x000003c5, (FixedNum)0xfffff59e, (FixedNum)0x00002248, (FixedNum)0xfffffdb9, (FixedNum)0xfffff87f, (FixedNum)0x0000008f, (FixedNum)0x000008cc, (FixedNum)0xffffec82, (FixedNum)0x00000843, (FixedNum)0x00000290, (FixedNum)0xfffffdb9, (FixedNum)0x00000094, (FixedNum)0x000004cd, (FixedNum)0x0000016d, (FixedNum)0x000008e3, (FixedNum)0x000008ba, (FixedNum)0x0000090b, (FixedNum)0x000002a8, (FixedNum)0xffffffbe, (FixedNum)0x000000a6, (FixedNum)0x000000b1, (FixedNum)0xfffff614, (FixedNum)0x000009c9, (FixedNum)0xffffed57, (FixedNum)0xfffff960, (FixedNum)0xfffff1e9, (FixedNum)0xffffeac9, (FixedNum)0xfffffeb2, (FixedNum)0x0000006e, (FixedNum)0xffffff8d, (FixedNum)0x0000026c, (FixedNum)0xfffffa60, (FixedNum)0xfffffc00, (FixedNum)0x0000062c, (FixedNum)0x000000d4, (FixedNum)0x00000327, (FixedNum)0x0000087e, (FixedNum)0x00000a29, (FixedNum)0xffffffff, (FixedNum)0x0000092c, (FixedNum)0x000002d3, (FixedNum)0xffffef74, (FixedNum)0x00000d99, (FixedNum)0xfffff730, (FixedNum)0xfffffdb6, (FixedNum)0xfffffff4, (FixedNum)0xfffff853, (FixedNum)0xfffffb6b, (FixedNum)0xfffffaa1, (FixedNum)0x0000005d, (FixedNum)0xfffffdde, (FixedNum)0x000007f6, (FixedNum)0xfffff87e, (FixedNum)0xfffff3dd, (FixedNum)0x00000219, (FixedNum)0x0000132a, (FixedNum)0xffffe7cf, (FixedNum)0xfffff3ed, (FixedNum)0xfffffbf6, (FixedNum)0x000004ca, (FixedNum)0xfffffd41, (FixedNum)0xffffea48, (FixedNum)0xfffff75b, (FixedNum)0xfffff9e6, (FixedNum)0xfffffeb0};
// const int tmp_connections79[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights80[65] = {(FixedNum)0xfffffe51, (FixedNum)0x00000540, (FixedNum)0xffffff88, (FixedNum)0xffffff4b, (FixedNum)0xfffffed2, (FixedNum)0xfffffeee, (FixedNum)0xfffffce3, (FixedNum)0xffffff41, (FixedNum)0x00000075, (FixedNum)0xffffff13, (FixedNum)0xffffff24, (FixedNum)0xfffffeff, (FixedNum)0xffffffd1, (FixedNum)0x000000da, (FixedNum)0xffffff97, (FixedNum)0xffffff97, (FixedNum)0xfffffe72, (FixedNum)0xfffffee6, (FixedNum)0x00000028, (FixedNum)0xfffffef8, (FixedNum)0xfffffeac, (FixedNum)0x00000026, (FixedNum)0x00000026, (FixedNum)0x000001f1, (FixedNum)0xffffff1e, (FixedNum)0xffffff53, (FixedNum)0xfffffc2f, (FixedNum)0xfffffeac, (FixedNum)0xfffffe4c, (FixedNum)0x00000467, (FixedNum)0xfffffdbd, (FixedNum)0x00000265, (FixedNum)0xfffffd3f, (FixedNum)0xffffffc6, (FixedNum)0x000000c0, (FixedNum)0xffffff2c, (FixedNum)0xfffffec3, (FixedNum)0x00000121, (FixedNum)0x0000009e, (FixedNum)0xfffffde1, (FixedNum)0xffffff11, (FixedNum)0xfffffee5, (FixedNum)0x000000ca, (FixedNum)0x00000197, (FixedNum)0xffffff53, (FixedNum)0x00000237, (FixedNum)0xfffffd50, (FixedNum)0x000001f7, (FixedNum)0x000000fe, (FixedNum)0x00000188, (FixedNum)0xffffff79, (FixedNum)0x0000001c, (FixedNum)0x00000012, (FixedNum)0x00000130, (FixedNum)0x000002bf, (FixedNum)0x00000191, (FixedNum)0x00000232, (FixedNum)0x00000164, (FixedNum)0xfffffe20, (FixedNum)0x000001c5, (FixedNum)0xffffffb8, (FixedNum)0xfffffdaa, (FixedNum)0xffffffae, (FixedNum)0x00000098, (FixedNum)0xfffffee2};
// const int tmp_connections80[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights81[65] = {(FixedNum)0xffffffbc, (FixedNum)0x00000ea1, (FixedNum)0x000007ac, (FixedNum)0x000001f1, (FixedNum)0x0000039e, (FixedNum)0x0000044c, (FixedNum)0x00000717, (FixedNum)0x00000cb4, (FixedNum)0xfffff7ec, (FixedNum)0x000002ef, (FixedNum)0x000001f6, (FixedNum)0x00000499, (FixedNum)0x00000311, (FixedNum)0xffffff87, (FixedNum)0x0000051e, (FixedNum)0x000004d6, (FixedNum)0x00000087, (FixedNum)0x0000033d, (FixedNum)0x00000700, (FixedNum)0x00000447, (FixedNum)0x00000474, (FixedNum)0x00000283, (FixedNum)0xfffffc26, (FixedNum)0xfffffefc, (FixedNum)0x000003d3, (FixedNum)0x00000207, (FixedNum)0x0000197e, (FixedNum)0xfffff93d, (FixedNum)0xfffffc50, (FixedNum)0x00000695, (FixedNum)0xffffff65, (FixedNum)0x000000aa, (FixedNum)0x00000830, (FixedNum)0xfffffa47, (FixedNum)0x00000687, (FixedNum)0xfffff627, (FixedNum)0xfffff79b, (FixedNum)0xfffffe8e, (FixedNum)0x0000008e, (FixedNum)0xfffffc30, (FixedNum)0xfffffe8f, (FixedNum)0xfffffc65, (FixedNum)0x000004e1, (FixedNum)0x00000315, (FixedNum)0x000001cc, (FixedNum)0xfffff19f, (FixedNum)0xfffff9c1, (FixedNum)0x000008f7, (FixedNum)0x00000554, (FixedNum)0x000001ba, (FixedNum)0x000003aa, (FixedNum)0xfffffbce, (FixedNum)0xfffffc20, (FixedNum)0xfffffcb7, (FixedNum)0x00000452, (FixedNum)0xfffffcd1, (FixedNum)0x0000031d, (FixedNum)0x000007bc, (FixedNum)0xffffff77, (FixedNum)0x000005a9, (FixedNum)0x0000048d, (FixedNum)0xfffff7e6, (FixedNum)0x0000015b, (FixedNum)0x0000052c, (FixedNum)0xfffffb53};
// const int tmp_connections81[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights82[65] = {(FixedNum)0xfffff8c0, (FixedNum)0x0000069d, (FixedNum)0xfffffe77, (FixedNum)0xfffffd14, (FixedNum)0xfffffda5, (FixedNum)0xfffff787, (FixedNum)0xfffff4e7, (FixedNum)0xfffff745, (FixedNum)0xfffff762, (FixedNum)0xffffff83, (FixedNum)0xfffffd34, (FixedNum)0xfffff7aa, (FixedNum)0xfffff70a, (FixedNum)0x00000132, (FixedNum)0xfffff208, (FixedNum)0xfffff200, (FixedNum)0x0000011e, (FixedNum)0xffffff31, (FixedNum)0xffffff1b, (FixedNum)0xfffff7e4, (FixedNum)0xfffff7a0, (FixedNum)0x0000094c, (FixedNum)0xfffff941, (FixedNum)0x000003e6, (FixedNum)0xffffff3c, (FixedNum)0x000003d8, (FixedNum)0xfffff6fd, (FixedNum)0x000001b9, (FixedNum)0xfffffc34, (FixedNum)0xfffff919, (FixedNum)0xfffff6b9, (FixedNum)0xffffff0a, (FixedNum)0xffffe0d3, (FixedNum)0xfffff122, (FixedNum)0xfffff65d, (FixedNum)0x00000254, (FixedNum)0xffffff32, (FixedNum)0x000002f4, (FixedNum)0x000003a8, (FixedNum)0xfffff9fb, (FixedNum)0x000002f6, (FixedNum)0xffffeb73, (FixedNum)0x00000f09, (FixedNum)0x0000002d, (FixedNum)0xfffffd4b, (FixedNum)0xffffee67, (FixedNum)0xfffffbef, (FixedNum)0xfffff868, (FixedNum)0x000006f7, (FixedNum)0x0000022a, (FixedNum)0x00000566, (FixedNum)0xffffff97, (FixedNum)0xfffffdae, (FixedNum)0x00000a8f, (FixedNum)0x000007f6, (FixedNum)0xfffffedf, (FixedNum)0x00000551, (FixedNum)0x0000033c, (FixedNum)0x000004e1, (FixedNum)0x000001c3, (FixedNum)0x00000859, (FixedNum)0x000003ff, (FixedNum)0x00000682, (FixedNum)0xfffffc5b, (FixedNum)0xfffffdb2};
// const int tmp_connections82[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights83[65] = {(FixedNum)0x00000411, (FixedNum)0xfffff417, (FixedNum)0xfffff559, (FixedNum)0x0000036e, (FixedNum)0xfffffffa, (FixedNum)0x000003a5, (FixedNum)0x000019bd, (FixedNum)0x00000a77, (FixedNum)0xffffec42, (FixedNum)0x000000b0, (FixedNum)0x00000354, (FixedNum)0x00000373, (FixedNum)0xfffffe00, (FixedNum)0xffffff8c, (FixedNum)0x0000036d, (FixedNum)0x00000383, (FixedNum)0x000000b4, (FixedNum)0x000000d1, (FixedNum)0xfffff537, (FixedNum)0x0000036a, (FixedNum)0x00000378, (FixedNum)0xfffffd01, (FixedNum)0xfffffe5a, (FixedNum)0x000000f3, (FixedNum)0x0000048e, (FixedNum)0xfffff7ff, (FixedNum)0x0000165c, (FixedNum)0x00000532, (FixedNum)0x00000325, (FixedNum)0xfffff94f, (FixedNum)0x00000071, (FixedNum)0xffffffc7, (FixedNum)0xfffffa1b, (FixedNum)0x0000031a, (FixedNum)0xfffffd05, (FixedNum)0x000004a9, (FixedNum)0x000003f9, (FixedNum)0x000007c6, (FixedNum)0x00000862, (FixedNum)0x0000092a, (FixedNum)0x00000fc7, (FixedNum)0x00000019, (FixedNum)0xfffffea1, (FixedNum)0xffffeee2, (FixedNum)0x00000355, (FixedNum)0x00000526, (FixedNum)0x000001c0, (FixedNum)0xfffff47c, (FixedNum)0xfffffadd, (FixedNum)0xfffffbb4, (FixedNum)0xfffffebc, (FixedNum)0xfffffc29, (FixedNum)0x00000525, (FixedNum)0xfffffeee, (FixedNum)0xfffffd33, (FixedNum)0xfffff6e6, (FixedNum)0xfffffd5a, (FixedNum)0x00000a3d, (FixedNum)0xfffff97d, (FixedNum)0x0000037a, (FixedNum)0x00000006, (FixedNum)0xffffffd1, (FixedNum)0xfffffde0, (FixedNum)0x00000a4f, (FixedNum)0x00000496};
// const int tmp_connections83[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights84[65] = {(FixedNum)0xfffffe13, (FixedNum)0x0000030d, (FixedNum)0x0000012c, (FixedNum)0xffffff59, (FixedNum)0x0000003f, (FixedNum)0xfffffe54, (FixedNum)0xffffffb6, (FixedNum)0xfffffea6, (FixedNum)0x0000029a, (FixedNum)0xffffff01, (FixedNum)0xffffff73, (FixedNum)0xfffffe71, (FixedNum)0xffffff05, (FixedNum)0x00000080, (FixedNum)0xfffffe85, (FixedNum)0xfffffe72, (FixedNum)0xfffffe93, (FixedNum)0xffffff14, (FixedNum)0x000000ba, (FixedNum)0xfffffe5c, (FixedNum)0xfffffe0d, (FixedNum)0x00000121, (FixedNum)0xffffffd0, (FixedNum)0x00000354, (FixedNum)0x000001a4, (FixedNum)0x00000307, (FixedNum)0x00000216, (FixedNum)0x0000003f, (FixedNum)0xffffff6e, (FixedNum)0xfffffeda, (FixedNum)0xffffff3b, (FixedNum)0x00000020, (FixedNum)0xffffffd9, (FixedNum)0xfffffe22, (FixedNum)0x00000000, (FixedNum)0xffffffea, (FixedNum)0xfffffef6, (FixedNum)0x0000008d, (FixedNum)0x0000015e, (FixedNum)0xffffffb1, (FixedNum)0x00000116, (FixedNum)0xfffffd9b, (FixedNum)0x00000286, (FixedNum)0xffffff26, (FixedNum)0xffffff9a, (FixedNum)0xfffffe40, (FixedNum)0xfffffebe, (FixedNum)0xfffffe2f, (FixedNum)0x00000084, (FixedNum)0x000000a5, (FixedNum)0x00000112, (FixedNum)0x0000005e, (FixedNum)0x0000009d, (FixedNum)0x00000222, (FixedNum)0x00000134, (FixedNum)0x000001c9, (FixedNum)0x0000009a, (FixedNum)0x00000076, (FixedNum)0x000000eb, (FixedNum)0xffffffa0, (FixedNum)0xffffffb6, (FixedNum)0x000001bf, (FixedNum)0x0000014f, (FixedNum)0x00000038, (FixedNum)0xffffffe5};
// const int tmp_connections84[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights85[65] = {(FixedNum)0x0000046f, (FixedNum)0x00000dbc, (FixedNum)0xfffffd89, (FixedNum)0x00000177, (FixedNum)0xfffff93c, (FixedNum)0x00000373, (FixedNum)0xfffff7a3, (FixedNum)0x000005f2, (FixedNum)0xffffea66, (FixedNum)0x0000073e, (FixedNum)0x00000175, (FixedNum)0x00000343, (FixedNum)0x00001d9a, (FixedNum)0x00000717, (FixedNum)0x00000608, (FixedNum)0x00000644, (FixedNum)0x00000c9e, (FixedNum)0x00000740, (FixedNum)0x0000112a, (FixedNum)0x0000037c, (FixedNum)0x0000036b, (FixedNum)0x0000029d, (FixedNum)0xfffff84a, (FixedNum)0xffffe787, (FixedNum)0xfffff227, (FixedNum)0xfffff1e5, (FixedNum)0xfffff633, (FixedNum)0xffffff3e, (FixedNum)0xfffffbbf, (FixedNum)0x00000e85, (FixedNum)0xfffff6f3, (FixedNum)0x000012d0, (FixedNum)0xfffff1df, (FixedNum)0x00000aef, (FixedNum)0x00000d54, (FixedNum)0x00000270, (FixedNum)0x00000158, (FixedNum)0x00000b42, (FixedNum)0x000006fc, (FixedNum)0x00000b85, (FixedNum)0x00000dcc, (FixedNum)0x0000013a, (FixedNum)0x00000297, (FixedNum)0xfffff0af, (FixedNum)0x00000154, (FixedNum)0xfffff1ca, (FixedNum)0xfffffa14, (FixedNum)0xfffff273, (FixedNum)0xffffea09, (FixedNum)0xfffff246, (FixedNum)0xffffed04, (FixedNum)0x000007f0, (FixedNum)0xfffffea6, (FixedNum)0xfffffe03, (FixedNum)0xfffff7f0, (FixedNum)0x00000d10, (FixedNum)0x00000b1f, (FixedNum)0xfffff0e1, (FixedNum)0x00000797, (FixedNum)0x0000107e, (FixedNum)0xfffffb3b, (FixedNum)0xffffe933, (FixedNum)0xfffff99f, (FixedNum)0x00000344, (FixedNum)0xfffffd2d};
// const int tmp_connections85[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights86[65] = {(FixedNum)0xfffff685, (FixedNum)0x000030a4, (FixedNum)0x00000284, (FixedNum)0xfffffea6, (FixedNum)0x0000056c, (FixedNum)0xfffff72f, (FixedNum)0x00001db0, (FixedNum)0x00000c59, (FixedNum)0xfffff56f, (FixedNum)0xfffffeb2, (FixedNum)0xfffffe81, (FixedNum)0xfffff72d, (FixedNum)0x000004ad, (FixedNum)0x00000553, (FixedNum)0xffffecd7, (FixedNum)0xffffec95, (FixedNum)0x00000472, (FixedNum)0xfffffebc, (FixedNum)0x00001baa, (FixedNum)0xfffff74f, (FixedNum)0xfffff76d, (FixedNum)0xffffe07e, (FixedNum)0x000020d9, (FixedNum)0x00000cbb, (FixedNum)0x000015a2, (FixedNum)0x0000118d, (FixedNum)0x000012e5, (FixedNum)0x000001ca, (FixedNum)0xffffff5b, (FixedNum)0xffffef75, (FixedNum)0xfffffd41, (FixedNum)0x000002f2, (FixedNum)0x0000186f, (FixedNum)0xfffff0e0, (FixedNum)0xfffff432, (FixedNum)0xfffff84b, (FixedNum)0xffffef93, (FixedNum)0xfffffa31, (FixedNum)0x00000673, (FixedNum)0xfffff93e, (FixedNum)0x000000f1, (FixedNum)0xfffff3cb, (FixedNum)0x00000388, (FixedNum)0x00000560, (FixedNum)0xfffffe8f, (FixedNum)0x00000dc2, (FixedNum)0x00000201, (FixedNum)0x00000434, (FixedNum)0x00000da1, (FixedNum)0x0000094a, (FixedNum)0x00000e21, (FixedNum)0xffffe790, (FixedNum)0xfffffa90, (FixedNum)0x000003f7, (FixedNum)0xfffff8f6, (FixedNum)0x000009e3, (FixedNum)0xffffff81, (FixedNum)0x00000e8e, (FixedNum)0x00000f0b, (FixedNum)0x00000339, (FixedNum)0xfffff522, (FixedNum)0x00000121, (FixedNum)0x0000102e, (FixedNum)0x000002f3, (FixedNum)0x000003de};
// const int tmp_connections86[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights87[65] = {(FixedNum)0xfffff5eb, (FixedNum)0xfffff177, (FixedNum)0x000007e2, (FixedNum)0xfffffc8f, (FixedNum)0x000001a6, (FixedNum)0xfffff350, (FixedNum)0x00001bd8, (FixedNum)0xfffff37c, (FixedNum)0x00000fc6, (FixedNum)0xfffff4ac, (FixedNum)0xfffffc7a, (FixedNum)0xfffff33e, (FixedNum)0xfffff94b, (FixedNum)0xffffffee, (FixedNum)0xfffff34b, (FixedNum)0xfffff355, (FixedNum)0xffffef7e, (FixedNum)0xfffff476, (FixedNum)0xfffffd22, (FixedNum)0xfffff363, (FixedNum)0xfffff382, (FixedNum)0xfffffa49, (FixedNum)0x000009d6, (FixedNum)0x00001d6f, (FixedNum)0x000012f2, (FixedNum)0x00000fc2, (FixedNum)0xfffffa04, (FixedNum)0x000005bd, (FixedNum)0x0000032b, (FixedNum)0xfffff5d1, (FixedNum)0x00000088, (FixedNum)0xffffff32, (FixedNum)0x00000af9, (FixedNum)0xfffff588, (FixedNum)0xfffff915, (FixedNum)0x0000003f, (FixedNum)0xfffff7f7, (FixedNum)0xfffff420, (FixedNum)0xffffff75, (FixedNum)0xfffffd47, (FixedNum)0x00000029, (FixedNum)0x00000eac, (FixedNum)0xfffff7b8, (FixedNum)0xfffffd22, (FixedNum)0xfffffc77, (FixedNum)0x0000084d, (FixedNum)0xfffff922, (FixedNum)0x00000111, (FixedNum)0x00000a6a, (FixedNum)0xfffffcba, (FixedNum)0x000004ca, (FixedNum)0x00000214, (FixedNum)0x00001394, (FixedNum)0x000006f3, (FixedNum)0xfffffee2, (FixedNum)0x00000fef, (FixedNum)0x00000295, (FixedNum)0x000007b9, (FixedNum)0x0000138f, (FixedNum)0x000002a6, (FixedNum)0x00000029, (FixedNum)0x00000365, (FixedNum)0x000005eb, (FixedNum)0xffffffc2, (FixedNum)0x00000514};
// const int tmp_connections87[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights88[65] = {(FixedNum)0x00000f4a, (FixedNum)0xffffe729, (FixedNum)0xffffe41d, (FixedNum)0x0000052f, (FixedNum)0xfffffdb2, (FixedNum)0x00000f3b, (FixedNum)0x000007d5, (FixedNum)0x000023a7, (FixedNum)0xffffe194, (FixedNum)0x00000b30, (FixedNum)0x00000559, (FixedNum)0x00000f0d, (FixedNum)0x0000095b, (FixedNum)0xfffffa6b, (FixedNum)0x0000019f, (FixedNum)0x00000172, (FixedNum)0x00000be3, (FixedNum)0x00000b3f, (FixedNum)0x000001ef, (FixedNum)0x00000f0a, (FixedNum)0x00000f38, (FixedNum)0xffffff5d, (FixedNum)0xfffffba4, (FixedNum)0xffffe736, (FixedNum)0xffffee0f, (FixedNum)0xffffe884, (FixedNum)0xfffff949, (FixedNum)0xfffffc6e, (FixedNum)0x000003dc, (FixedNum)0xffffd04c, (FixedNum)0x00000c08, (FixedNum)0xfffffb44, (FixedNum)0x00000c6a, (FixedNum)0x000010ef, (FixedNum)0x00000099, (FixedNum)0x0000011b, (FixedNum)0x00000bae, (FixedNum)0xfffffc1e, (FixedNum)0xfffff1eb, (FixedNum)0xfffffdde, (FixedNum)0xfffff543, (FixedNum)0x000007a1, (FixedNum)0xfffff975, (FixedNum)0x00000640, (FixedNum)0x00000543, (FixedNum)0xfffffe43, (FixedNum)0xfffffaa5, (FixedNum)0xffffef9c, (FixedNum)0x00001610, (FixedNum)0x00000220, (FixedNum)0xfffffbdd, (FixedNum)0x0000083f, (FixedNum)0xfffff7d9, (FixedNum)0x0000014f, (FixedNum)0x0000012d, (FixedNum)0xfffff521, (FixedNum)0xfffff9df, (FixedNum)0x000002c1, (FixedNum)0xfffffce1, (FixedNum)0x00000206, (FixedNum)0x0000095a, (FixedNum)0x00002aa7, (FixedNum)0x0000056e, (FixedNum)0x000001dc, (FixedNum)0xfffff589};
// const int tmp_connections88[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights89[65] = {(FixedNum)0x000011c0, (FixedNum)0xffffe00e, (FixedNum)0xffffeaaa, (FixedNum)0x000002f4, (FixedNum)0xfffff519, (FixedNum)0x00000c74, (FixedNum)0x0000107b, (FixedNum)0x00000358, (FixedNum)0xffffdfd0, (FixedNum)0x00000767, (FixedNum)0x000002a1, (FixedNum)0x00000cb0, (FixedNum)0x00000aee, (FixedNum)0xfffffcc4, (FixedNum)0x00000664, (FixedNum)0x00000673, (FixedNum)0x00000797, (FixedNum)0x0000074e, (FixedNum)0x000005f1, (FixedNum)0x00000ca5, (FixedNum)0x00000cbc, (FixedNum)0xfffffc15, (FixedNum)0xffffffe3, (FixedNum)0xffffe0bc, (FixedNum)0xffffe203, (FixedNum)0xffffdba8, (FixedNum)0x00001140, (FixedNum)0x000000b5, (FixedNum)0x00000e14, (FixedNum)0xffffe7b3, (FixedNum)0x0000183e, (FixedNum)0xffffe939, (FixedNum)0x000016cd, (FixedNum)0x0000134b, (FixedNum)0xffffe6b0, (FixedNum)0x000002ce, (FixedNum)0x000010ea, (FixedNum)0xfffff701, (FixedNum)0xffffeef5, (FixedNum)0x0000049e, (FixedNum)0xfffff140, (FixedNum)0xfffffa27, (FixedNum)0x0000005c, (FixedNum)0x00000142, (FixedNum)0x000002c6, (FixedNum)0xffffff50, (FixedNum)0x00000ad8, (FixedNum)0xffffd1cf, (FixedNum)0x00001254, (FixedNum)0x00000283, (FixedNum)0xfffff66a, (FixedNum)0xfffff07f, (FixedNum)0x000018e0, (FixedNum)0xfffff705, (FixedNum)0xfffff582, (FixedNum)0x00000132, (FixedNum)0xffffdfa9, (FixedNum)0x00000e01, (FixedNum)0x000010d2, (FixedNum)0xfffff751, (FixedNum)0x0000025a, (FixedNum)0x000018d5, (FixedNum)0xffffff8c, (FixedNum)0x000016d8, (FixedNum)0x00000575};
// const int tmp_connections89[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights90[65] = {(FixedNum)0xfffff197, (FixedNum)0x00002357, (FixedNum)0xfffff2b5, (FixedNum)0xfffff9df, (FixedNum)0x0000013f, (FixedNum)0xfffff263, (FixedNum)0x00000d3c, (FixedNum)0xffffe22c, (FixedNum)0xfffffb7f, (FixedNum)0xfffff609, (FixedNum)0xfffff9b0, (FixedNum)0xfffff253, (FixedNum)0xfffff58a, (FixedNum)0x0000054b, (FixedNum)0xffffee76, (FixedNum)0xffffeeb5, (FixedNum)0xffffee09, (FixedNum)0xfffff610, (FixedNum)0xfffff795, (FixedNum)0xfffff2a2, (FixedNum)0xfffff253, (FixedNum)0xffffff13, (FixedNum)0x00000437, (FixedNum)0x00001bdb, (FixedNum)0x0000234a, (FixedNum)0x00001950, (FixedNum)0x000000d7, (FixedNum)0x00000574, (FixedNum)0xfffffc32, (FixedNum)0x00000225, (FixedNum)0xfffff916, (FixedNum)0x0000000d, (FixedNum)0x000010fd, (FixedNum)0xfffff00b, (FixedNum)0x00001926, (FixedNum)0x00000b52, (FixedNum)0x0000030e, (FixedNum)0x00001060, (FixedNum)0x00000d19, (FixedNum)0xffffff9c, (FixedNum)0x000005a9, (FixedNum)0x000011bb, (FixedNum)0xfffff828, (FixedNum)0xfffff5fc, (FixedNum)0xfffff9d6, (FixedNum)0x000007f1, (FixedNum)0x00001220, (FixedNum)0xfffff787, (FixedNum)0x000007e3, (FixedNum)0x000001e1, (FixedNum)0xfffffbf9, (FixedNum)0x0000082d, (FixedNum)0xfffff300, (FixedNum)0x00000316, (FixedNum)0x00000e31, (FixedNum)0xfffff91d, (FixedNum)0x00000cbb, (FixedNum)0x0000081e, (FixedNum)0x00000655, (FixedNum)0xfffffc5f, (FixedNum)0x00000012, (FixedNum)0x00001e73, (FixedNum)0x0000018b, (FixedNum)0x00000d9e, (FixedNum)0xfffffbf6};
// const int tmp_connections90[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights91[65] = {(FixedNum)0xfffff420, (FixedNum)0xfffffc3d, (FixedNum)0x0000033e, (FixedNum)0xfffffe7b, (FixedNum)0xfffffff4, (FixedNum)0xfffff3f8, (FixedNum)0x00001530, (FixedNum)0xfffffda9, (FixedNum)0x00000688, (FixedNum)0xfffff739, (FixedNum)0xfffffe27, (FixedNum)0xfffff3e1, (FixedNum)0xfffff840, (FixedNum)0x000002cc, (FixedNum)0xfffff35c, (FixedNum)0xfffff316, (FixedNum)0xfffff389, (FixedNum)0xfffff75b, (FixedNum)0xfffffde3, (FixedNum)0xfffff3d2, (FixedNum)0xfffff3bb, (FixedNum)0xfffff7d6, (FixedNum)0x00000cfe, (FixedNum)0x0000195f, (FixedNum)0xffffff47, (FixedNum)0x00000ecc, (FixedNum)0x00000585, (FixedNum)0x00000454, (FixedNum)0xffffff08, (FixedNum)0x000003ce, (FixedNum)0xfffffadf, (FixedNum)0x00000358, (FixedNum)0x000006a6, (FixedNum)0xfffff42d, (FixedNum)0x000002c4, (FixedNum)0xffffff9e, (FixedNum)0xfffff6d0, (FixedNum)0xfffffafa, (FixedNum)0x00000290, (FixedNum)0xfffffaae, (FixedNum)0x0000000c, (FixedNum)0x000009c3, (FixedNum)0xfffff474, (FixedNum)0x00000415, (FixedNum)0xfffffe34, (FixedNum)0xfffff9e3, (FixedNum)0xfffffa0c, (FixedNum)0xffffeef3, (FixedNum)0x00000e39, (FixedNum)0x0000075d, (FixedNum)0x000009b0, (FixedNum)0xfffffb04, (FixedNum)0x00000181, (FixedNum)0x00000ae6, (FixedNum)0x00000a25, (FixedNum)0xfffffe89, (FixedNum)0x00000e5b, (FixedNum)0x00001573, (FixedNum)0x000013c1, (FixedNum)0x0000028e, (FixedNum)0x00000943, (FixedNum)0xfffff9d1, (FixedNum)0x00000258, (FixedNum)0xfffffee8, (FixedNum)0xfffffccf};
// const int tmp_connections91[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights92[65] = {(FixedNum)0x000000a4, (FixedNum)0xfffff232, (FixedNum)0x00000b4b, (FixedNum)0xfffffe33, (FixedNum)0xfffff9ca, (FixedNum)0xffffffd8, (FixedNum)0x000004d6, (FixedNum)0xfffff873, (FixedNum)0x00000000, (FixedNum)0x0000031f, (FixedNum)0xfffffe7a, (FixedNum)0x00000029, (FixedNum)0x00000987, (FixedNum)0x00000262, (FixedNum)0x0000036b, (FixedNum)0x00000358, (FixedNum)0x000005fe, (FixedNum)0x00000323, (FixedNum)0x0000076a, (FixedNum)0xfffffff5, (FixedNum)0x0000001d, (FixedNum)0xfffff7b2, (FixedNum)0x000008fc, (FixedNum)0xfffff09c, (FixedNum)0xfffff102, (FixedNum)0xfffff0f6, (FixedNum)0x0000036c, (FixedNum)0xfffff9b4, (FixedNum)0xfffffcd0, (FixedNum)0x000004e4, (FixedNum)0xffffffb5, (FixedNum)0xfffffe57, (FixedNum)0xfffffea1, (FixedNum)0xfffffe0f, (FixedNum)0xfffffa20, (FixedNum)0xfffffb1a, (FixedNum)0xfffffe75, (FixedNum)0x0000014e, (FixedNum)0x0000000f, (FixedNum)0x0000004f, (FixedNum)0xffffff02, (FixedNum)0x000001f3, (FixedNum)0x00000230, (FixedNum)0x0000004e, (FixedNum)0xfffffe8a, (FixedNum)0xfffff583, (FixedNum)0xfffffe2b, (FixedNum)0xffffff01, (FixedNum)0xfffffb6f, (FixedNum)0x0000009d, (FixedNum)0xfffffc0d, (FixedNum)0x00000711, (FixedNum)0xfffffd70, (FixedNum)0xfffffc63, (FixedNum)0x0000038c, (FixedNum)0x000004ba, (FixedNum)0xfffff7cb, (FixedNum)0x00000080, (FixedNum)0xfffffcac, (FixedNum)0x000002c0, (FixedNum)0xfffffd44, (FixedNum)0xfffff6d7, (FixedNum)0xfffffd0e, (FixedNum)0xfffffbad, (FixedNum)0xfffffe13};
// const int tmp_connections92[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights93[65] = {(FixedNum)0x00000548, (FixedNum)0x00000dd6, (FixedNum)0x0000030c, (FixedNum)0x00000078, (FixedNum)0xfffffd1d, (FixedNum)0x00000522, (FixedNum)0xfffffc0b, (FixedNum)0x00000023, (FixedNum)0xfffff130, (FixedNum)0x00000a1d, (FixedNum)0x0000004a, (FixedNum)0x00000527, (FixedNum)0x0000016b, (FixedNum)0x0000015c, (FixedNum)0x000006b4, (FixedNum)0x000006a6, (FixedNum)0x000016d9, (FixedNum)0x000009ee, (FixedNum)0x000007a3, (FixedNum)0x00000540, (FixedNum)0x00000508, (FixedNum)0xfffffd83, (FixedNum)0xfffffb16, (FixedNum)0xffffe5a3, (FixedNum)0x000002e0, (FixedNum)0xfffff372, (FixedNum)0x00000cf8, (FixedNum)0xfffffce3, (FixedNum)0xfffffd88, (FixedNum)0x000017ef, (FixedNum)0xfffffb19, (FixedNum)0x00000629, (FixedNum)0xffffe9a5, (FixedNum)0x00000614, (FixedNum)0x00000ab6, (FixedNum)0xfffffe91, (FixedNum)0x0000017d, (FixedNum)0x00000374, (FixedNum)0x000001aa, (FixedNum)0x000003a0, (FixedNum)0x00000507, (FixedNum)0x000002be, (FixedNum)0x000003c7, (FixedNum)0xfffffcac, (FixedNum)0x0000008b, (FixedNum)0x000006e2, (FixedNum)0xffffff67, (FixedNum)0xffffe85e, (FixedNum)0xfffff6ab, (FixedNum)0xfffffc95, (FixedNum)0xffffff4f, (FixedNum)0x00000463, (FixedNum)0x00000674, (FixedNum)0xfffff5ab, (FixedNum)0xfffffd97, (FixedNum)0xfffffd18, (FixedNum)0x00000c61, (FixedNum)0x00000d5c, (FixedNum)0x00000732, (FixedNum)0x000005ba, (FixedNum)0x0000138d, (FixedNum)0xfffff165, (FixedNum)0xfffff0f0, (FixedNum)0xfffffcfd, (FixedNum)0x000000e9};
// const int tmp_connections93[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights94[65] = {(FixedNum)0xfffff97a, (FixedNum)0x00000794, (FixedNum)0x00000188, (FixedNum)0xfffffd68, (FixedNum)0xfffffd74, (FixedNum)0xfffff8dd, (FixedNum)0x00000427, (FixedNum)0x0000011d, (FixedNum)0x000009c9, (FixedNum)0xfffffd95, (FixedNum)0xfffffd5c, (FixedNum)0xfffff8f4, (FixedNum)0xfffffccc, (FixedNum)0x0000023c, (FixedNum)0xfffff9bc, (FixedNum)0xfffff9d1, (FixedNum)0xfffffb46, (FixedNum)0xfffffd63, (FixedNum)0x0000000e, (FixedNum)0xfffff8d8, (FixedNum)0xfffff906, (FixedNum)0x00000d4b, (FixedNum)0xfffff5f1, (FixedNum)0x000009b0, (FixedNum)0x00000378, (FixedNum)0x000002d4, (FixedNum)0xfffff95e, (FixedNum)0x0000017d, (FixedNum)0xfffffdfa, (FixedNum)0xfffff990, (FixedNum)0xfffffbe0, (FixedNum)0x00000295, (FixedNum)0x000007c2, (FixedNum)0xfffff642, (FixedNum)0x0000015f, (FixedNum)0xffffff0a, (FixedNum)0xfffff9bc, (FixedNum)0x00000298, (FixedNum)0x00000694, (FixedNum)0xffffffa8, (FixedNum)0x00000754, (FixedNum)0xfffffeb7, (FixedNum)0x000000f4, (FixedNum)0xfffff93f, (FixedNum)0xfffffd27, (FixedNum)0xfffffe2e, (FixedNum)0x000001e5, (FixedNum)0x0000055e, (FixedNum)0x0000077a, (FixedNum)0x00000437, (FixedNum)0x000007a9, (FixedNum)0x0000012f, (FixedNum)0x000008dd, (FixedNum)0x00000a0c, (FixedNum)0x00000010, (FixedNum)0x00000510, (FixedNum)0xfffffcb6, (FixedNum)0x000001df, (FixedNum)0x00000731, (FixedNum)0xffffff0c, (FixedNum)0xfffffabb, (FixedNum)0x00000945, (FixedNum)0x00000414, (FixedNum)0xffffffe9, (FixedNum)0xfffffbbb};
// const int tmp_connections94[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights95[65] = {(FixedNum)0x00000914, (FixedNum)0xffffc94a, (FixedNum)0xfffff717, (FixedNum)0x00000253, (FixedNum)0xfffffd4d, (FixedNum)0x000008af, (FixedNum)0xffffe4cb, (FixedNum)0x00000b8e, (FixedNum)0xffffffe1, (FixedNum)0x0000011d, (FixedNum)0x0000023a, (FixedNum)0x00000892, (FixedNum)0x00000d00, (FixedNum)0xfffffe93, (FixedNum)0x00000386, (FixedNum)0x00000375, (FixedNum)0xfffffc86, (FixedNum)0x000000f5, (FixedNum)0xfffff994, (FixedNum)0x00000886, (FixedNum)0x00000865, (FixedNum)0x000003bf, (FixedNum)0xfffff806, (FixedNum)0xfffffa7b, (FixedNum)0xfffff156, (FixedNum)0xffffec5b, (FixedNum)0xfffff883, (FixedNum)0x000001a7, (FixedNum)0x000005ad, (FixedNum)0xfffff0b9, (FixedNum)0x00000785, (FixedNum)0xfffff268, (FixedNum)0xffffeec6, (FixedNum)0x000006bb, (FixedNum)0xfffff40d, (FixedNum)0x0000052c, (FixedNum)0x00000ccb, (FixedNum)0x00000528, (FixedNum)0xfffffde1, (FixedNum)0x00000eb1, (FixedNum)0x000004ae, (FixedNum)0xffffee44, (FixedNum)0x00000856, (FixedNum)0xfffff9fc, (FixedNum)0x00000235, (FixedNum)0xffffead5, (FixedNum)0x000004e5, (FixedNum)0xfffff593, (FixedNum)0xffffeabb, (FixedNum)0x0000073a, (FixedNum)0x000007ab, (FixedNum)0x00001091, (FixedNum)0x000008cf, (FixedNum)0xfffffcff, (FixedNum)0xfffff374, (FixedNum)0xffffeea7, (FixedNum)0xffffff04, (FixedNum)0xfffffb11, (FixedNum)0xfffff7bc, (FixedNum)0xfffffa15, (FixedNum)0xfffffda2, (FixedNum)0x00000a80, (FixedNum)0x00000521, (FixedNum)0x00000721, (FixedNum)0x000004e5};
// const int tmp_connections95[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights96[65] = {(FixedNum)0xfffffe2f, (FixedNum)0x00001d5a, (FixedNum)0x00000f36, (FixedNum)0xfffffb2f, (FixedNum)0x000004ea, (FixedNum)0xfffff6aa, (FixedNum)0x000009e3, (FixedNum)0x00000e63, (FixedNum)0x000002bc, (FixedNum)0xfffff689, (FixedNum)0xfffffb0d, (FixedNum)0xfffff671, (FixedNum)0xfffff693, (FixedNum)0xfffffbfd, (FixedNum)0xffffee83, (FixedNum)0xffffee69, (FixedNum)0xfffff73c, (FixedNum)0xfffff6a3, (FixedNum)0xffffffd2, (FixedNum)0xfffff6ca, (FixedNum)0xfffff66f, (FixedNum)0xfffff46f, (FixedNum)0x000011a1, (FixedNum)0x00001014, (FixedNum)0x000020ed, (FixedNum)0x00001cb9, (FixedNum)0xfffffecc, (FixedNum)0xfffffc50, (FixedNum)0xfffff3ec, (FixedNum)0xffffe27a, (FixedNum)0xffffee3e, (FixedNum)0x00000f4f, (FixedNum)0xffffecae, (FixedNum)0xfffff8dc, (FixedNum)0x0000066d, (FixedNum)0x00000432, (FixedNum)0x0000017a, (FixedNum)0x00000b0e, (FixedNum)0x0000020c, (FixedNum)0x000005dd, (FixedNum)0x00000e95, (FixedNum)0x00000674, (FixedNum)0xfffffb58, (FixedNum)0xffffe8bc, (FixedNum)0xfffffb0e, (FixedNum)0xfffffc77, (FixedNum)0x000012a9, (FixedNum)0x00000696, (FixedNum)0x00000b1f, (FixedNum)0x000009b8, (FixedNum)0x00000674, (FixedNum)0x00000670, (FixedNum)0xfffff63e, (FixedNum)0x0000007b, (FixedNum)0xffffff85, (FixedNum)0x00000166, (FixedNum)0x000006d4, (FixedNum)0xffffedfc, (FixedNum)0x000000ba, (FixedNum)0xfffff0f9, (FixedNum)0x000003ec, (FixedNum)0x00001abf, (FixedNum)0xfffffb0d, (FixedNum)0x00000ef8, (FixedNum)0xfffff58e};
// const int tmp_connections96[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights97[65] = {(FixedNum)0xfffffc50, (FixedNum)0xffffe866, (FixedNum)0x000006a8, (FixedNum)0xffffff1c, (FixedNum)0xffffff3f, (FixedNum)0xfffffe78, (FixedNum)0x00000593, (FixedNum)0x000000a0, (FixedNum)0x00000914, (FixedNum)0xfffffe98, (FixedNum)0xffffff23, (FixedNum)0xfffffea6, (FixedNum)0xfffffecf, (FixedNum)0x00000283, (FixedNum)0xfffff9f8, (FixedNum)0xfffff9ee, (FixedNum)0xffffface, (FixedNum)0xfffffea0, (FixedNum)0xfffffd44, (FixedNum)0xfffffec1, (FixedNum)0xfffffeab, (FixedNum)0x0000014f, (FixedNum)0xffffffa9, (FixedNum)0x00000588, (FixedNum)0x0000024d, (FixedNum)0x0000012d, (FixedNum)0xfffffff5, (FixedNum)0x00000105, (FixedNum)0xfffffe68, (FixedNum)0xfffffba8, (FixedNum)0xfffffcb6, (FixedNum)0x00000002, (FixedNum)0xfffffd3e, (FixedNum)0xfffffaec, (FixedNum)0xfffffc1f, (FixedNum)0x00000159, (FixedNum)0x00000014, (FixedNum)0x0000036f, (FixedNum)0x0000020d, (FixedNum)0xffffff40, (FixedNum)0x000000dc, (FixedNum)0xffffff5c, (FixedNum)0x000001f9, (FixedNum)0xfffffe2f, (FixedNum)0xffffff61, (FixedNum)0x000001b7, (FixedNum)0x000003ec, (FixedNum)0x00000df1, (FixedNum)0x0000019e, (FixedNum)0x00000278, (FixedNum)0x000002a7, (FixedNum)0xffffff3d, (FixedNum)0xfffffc32, (FixedNum)0x00000159, (FixedNum)0x00000379, (FixedNum)0x00000008, (FixedNum)0x0000038c, (FixedNum)0x0000019a, (FixedNum)0x000000d6, (FixedNum)0x0000028c, (FixedNum)0x00000f4e, (FixedNum)0xffffffe1, (FixedNum)0xfffffe52, (FixedNum)0xfffffce6, (FixedNum)0xfffffdc5};
// const int tmp_connections97[65] = {64, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum tmp_weights98[35] = {(FixedNum)0xfffff74e, (FixedNum)0xffffefff, (FixedNum)0xfffffaf9, (FixedNum)0xffffffdb, (FixedNum)0xfffffa80, (FixedNum)0x00000177, (FixedNum)0xfffffc93, (FixedNum)0xfffffd7e, (FixedNum)0x00000f5d, (FixedNum)0xffffd837, (FixedNum)0xfffff6c9, (FixedNum)0xfffffd98, (FixedNum)0xfffffb99, (FixedNum)0xfffffd9a, (FixedNum)0x000001d2, (FixedNum)0xfffffd0d, (FixedNum)0xfffffee7, (FixedNum)0xfffffa71, (FixedNum)0xfffffcbd, (FixedNum)0xfffff831, (FixedNum)0x00001890, (FixedNum)0xfffff94d, (FixedNum)0x00000f95, (FixedNum)0xfffffc81, (FixedNum)0xfffffd72, (FixedNum)0x000013f6, (FixedNum)0x00000766, (FixedNum)0xfffff4ff, (FixedNum)0xfffffaf2, (FixedNum)0xffffe17f, (FixedNum)0xfffffc22, (FixedNum)0xfffffbc4, (FixedNum)0x00000b9d, (FixedNum)0xfffff962, (FixedNum)0xfffffcad};
// const int tmp_connections98[35] = {34, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97};
//
// const FixedNum tmp_weights99[35] = {(FixedNum)0x00002820, (FixedNum)0xfffff5e5, (FixedNum)0xffffefa8, (FixedNum)0xffffe822, (FixedNum)0x00000533, (FixedNum)0x000020e5, (FixedNum)0xffffde79, (FixedNum)0xffffebe0, (FixedNum)0x00000e06, (FixedNum)0x0000095d, (FixedNum)0x00001c4e, (FixedNum)0xffffee12, (FixedNum)0xfffffc2f, (FixedNum)0xffffe632, (FixedNum)0xffffe14d, (FixedNum)0x000014d1, (FixedNum)0x00001307, (FixedNum)0x000005a8, (FixedNum)0x00000fff, (FixedNum)0xffffe935, (FixedNum)0x00001a08, (FixedNum)0xffffff9e, (FixedNum)0x00001f62, (FixedNum)0xffffe4fc, (FixedNum)0xfffff6eb, (FixedNum)0x00002519, (FixedNum)0x00002575, (FixedNum)0xffffe99e, (FixedNum)0xffffeb2d, (FixedNum)0x00000b22, (FixedNum)0x00001808, (FixedNum)0xffffecbe, (FixedNum)0x0000269b, (FixedNum)0xffffe860, (FixedNum)0xffffe474};
// const int tmp_connections99[35] = {34, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97};
//
// const FixedNum tmp_weights100[35] = {(FixedNum)0xffffd962, (FixedNum)0x00000a38, (FixedNum)0x0000070a, (FixedNum)0x0000177e, (FixedNum)0xfffffa14, (FixedNum)0xffffde5f, (FixedNum)0x00002240, (FixedNum)0x00001445, (FixedNum)0xfffff14d, (FixedNum)0xfffff4cb, (FixedNum)0xffffe3bc, (FixedNum)0x000011e7, (FixedNum)0xfffffdaa, (FixedNum)0x000019b2, (FixedNum)0x00001f05, (FixedNum)0xffffe753, (FixedNum)0xffffed57, (FixedNum)0xfffffae6, (FixedNum)0xfffff017, (FixedNum)0x000017cc, (FixedNum)0xffffe858, (FixedNum)0x00000161, (FixedNum)0xffffe085, (FixedNum)0x00001b7f, (FixedNum)0x000009b0, (FixedNum)0xffffdab2, (FixedNum)0xffffda19, (FixedNum)0x000016a7, (FixedNum)0x00001499, (FixedNum)0xfffff53d, (FixedNum)0xffffe770, (FixedNum)0x00001518, (FixedNum)0xffffd7bc, (FixedNum)0x0000178d, (FixedNum)0xffffe86d};
// const int tmp_connections100[35] = {34, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97};
//
// const FixedNum tmp_weights101[35] = {(FixedNum)0xfffff1e5, (FixedNum)0xfffffc6c, (FixedNum)0x000009d5, (FixedNum)0x00000038, (FixedNum)0xfffffd66, (FixedNum)0xffffffe0, (FixedNum)0xfffffe01, (FixedNum)0xfffffe4e, (FixedNum)0x000003f2, (FixedNum)0xfffffd12, (FixedNum)0xfffffa71, (FixedNum)0xfffffa02, (FixedNum)0xffffff5b, (FixedNum)0xfffffb9e, (FixedNum)0xfffffbea, (FixedNum)0x00000bfe, (FixedNum)0x000003b4, (FixedNum)0xfffffcc2, (FixedNum)0xffffffc0, (FixedNum)0xfffffc5e, (FixedNum)0xfffffced, (FixedNum)0xfffffba0, (FixedNum)0xfffff9bd, (FixedNum)0xfffff5e0, (FixedNum)0x0000046f, (FixedNum)0xfffff8c0, (FixedNum)0xfffff804, (FixedNum)0xfffff46a, (FixedNum)0xfffffc13, (FixedNum)0xfffffeda, (FixedNum)0x0000002d, (FixedNum)0xfffff4de, (FixedNum)0x000003dc, (FixedNum)0x000003a1, (FixedNum)0x00001a0d};
// const int tmp_connections101[35] = {34, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97};
//
// const FixedNum tmp_weights102[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
// const int tmp_connections102[2] = {1, 98};
//
// const FixedNum tmp_weights103[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
// const int tmp_connections103[2] = {1, 99};
//
// const FixedNum tmp_weights104[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
// const int tmp_connections104[2] = {1, 100};
//
// const FixedNum tmp_weights105[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
// const int tmp_connections105[2] = {1, 101};
//
// const bool sigmoids[NUMBER_OF_NEURONS] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, false, false, false, false};
//
// FixedNum m_value[NUMBER_OF_NEURONS];
//
// /* Before every classification, all elements in m_calculated array need to be set to false */
// bool m_calculated[NUMBER_OF_NEURONS];
//
// /* Function calculateOutput description:
//  * Returns the output value from a neuron
//  */
// inline void calculateOutput(){
// 	for (int i = 0; i < INPUT_SIZE; i++){
// 		m_value[i] = instance[i];
// 	}
//
// 	for (int i = INPUT_SIZE; i < NUMBER_OF_NEURONS; i++){
// 		FixedNum value = m_weights[i][0];
// 		for (int j = 0; j < m_connections[i][0]; j++){
// 			value = fxp_sum(value, fxp_mul(m_weights[i][j+1], m_value[m_connections[i][j+1]]));
// 		}
// 		if (sigmoids[i]){
// 			if (value < (FixedNum)0xffff4c00)
// 				value = (FixedNum)0;
// 			else if (value > (FixedNum)0x0000b400)
// 				value = (FixedNum)0x00000400;
// 			else{
// 				value = fxp_div((FixedNum)0x00000400, fxp_sum((FixedNum)0x00000400, fxp_exp(-value)));
// 			}
// 		}
// 		m_value[i] = value;
// 	}
// }
//
// /* Function classify description:
//  * Instance array must be initializated, with appropriated attributes, before calling this function
//  * Output number 0 means that the instance was classified as 'ruim'
//  * Output number 1 means that the instance was classified as 'regular'
//  * Output number 2 means that the instance was classified as 'bom'
//  * Output number 3 means that the instance was classified as 'obstaculos'
//  */
// int classify(){
// 	FixedNum theArray[OUTPUT_SIZE];
// 	for (int i = 0; i < INPUT_SIZE; i++){
// 		if (m_attributeRanges[i] != (FixedNum)0){
// 			instance[i] = fxp_div(fxp_diff(instance[i], m_attributeBases[i]), m_attributeRanges[i]);
// 		}
// 		else{
// 			instance[i] = fxp_diff(instance[i], m_attributeBases[i]);
// 		}
// 	}
// 	calculateOutput();
// 	for (int i = 0; i < OUTPUT_SIZE; i++){
// 		theArray[i] = m_value[m_outputs[i]];
// 	}
// 	FixedNum maxValue = -1;
// 	int indexMax = -1;
// 	for (int i = 0; i < OUTPUT_SIZE; i++){
// 		if (theArray[i] > maxValue){
// 			maxValue = theArray[i];
// 			indexMax = i;
// 		}
// 	}
// 	return indexMax;
// }
//
// void initConnections(){
// 	m_connections[0] = tmp_connections0;
// 	m_connections[1] = tmp_connections1;
// 	m_connections[2] = tmp_connections2;
// 	m_connections[3] = tmp_connections3;
// 	m_connections[4] = tmp_connections4;
// 	m_connections[5] = tmp_connections5;
// 	m_connections[6] = tmp_connections6;
// 	m_connections[7] = tmp_connections7;
// 	m_connections[8] = tmp_connections8;
// 	m_connections[9] = tmp_connections9;
// 	m_connections[10] = tmp_connections10;
// 	m_connections[11] = tmp_connections11;
// 	m_connections[12] = tmp_connections12;
// 	m_connections[13] = tmp_connections13;
// 	m_connections[14] = tmp_connections14;
// 	m_connections[15] = tmp_connections15;
// 	m_connections[16] = tmp_connections16;
// 	m_connections[17] = tmp_connections17;
// 	m_connections[18] = tmp_connections18;
// 	m_connections[19] = tmp_connections19;
// 	m_connections[20] = tmp_connections20;
// 	m_connections[21] = tmp_connections21;
// 	m_connections[22] = tmp_connections22;
// 	m_connections[23] = tmp_connections23;
// 	m_connections[24] = tmp_connections24;
// 	m_connections[25] = tmp_connections25;
// 	m_connections[26] = tmp_connections26;
// 	m_connections[27] = tmp_connections27;
// 	m_connections[28] = tmp_connections28;
// 	m_connections[29] = tmp_connections29;
// 	m_connections[30] = tmp_connections30;
// 	m_connections[31] = tmp_connections31;
// 	m_connections[32] = tmp_connections32;
// 	m_connections[33] = tmp_connections33;
// 	m_connections[34] = tmp_connections34;
// 	m_connections[35] = tmp_connections35;
// 	m_connections[36] = tmp_connections36;
// 	m_connections[37] = tmp_connections37;
// 	m_connections[38] = tmp_connections38;
// 	m_connections[39] = tmp_connections39;
// 	m_connections[40] = tmp_connections40;
// 	m_connections[41] = tmp_connections41;
// 	m_connections[42] = tmp_connections42;
// 	m_connections[43] = tmp_connections43;
// 	m_connections[44] = tmp_connections44;
// 	m_connections[45] = tmp_connections45;
// 	m_connections[46] = tmp_connections46;
// 	m_connections[47] = tmp_connections47;
// 	m_connections[48] = tmp_connections48;
// 	m_connections[49] = tmp_connections49;
// 	m_connections[50] = tmp_connections50;
// 	m_connections[51] = tmp_connections51;
// 	m_connections[52] = tmp_connections52;
// 	m_connections[53] = tmp_connections53;
// 	m_connections[54] = tmp_connections54;
// 	m_connections[55] = tmp_connections55;
// 	m_connections[56] = tmp_connections56;
// 	m_connections[57] = tmp_connections57;
// 	m_connections[58] = tmp_connections58;
// 	m_connections[59] = tmp_connections59;
// 	m_connections[60] = tmp_connections60;
// 	m_connections[61] = tmp_connections61;
// 	m_connections[62] = tmp_connections62;
// 	m_connections[63] = tmp_connections63;
// 	m_weights[64] = tmp_weights64;
// 	m_connections[64] = tmp_connections64;
// 	m_weights[65] = tmp_weights65;
// 	m_connections[65] = tmp_connections65;
// 	m_weights[66] = tmp_weights66;
// 	m_connections[66] = tmp_connections66;
// 	m_weights[67] = tmp_weights67;
// 	m_connections[67] = tmp_connections67;
// 	m_weights[68] = tmp_weights68;
// 	m_connections[68] = tmp_connections68;
// 	m_weights[69] = tmp_weights69;
// 	m_connections[69] = tmp_connections69;
// 	m_weights[70] = tmp_weights70;
// 	m_connections[70] = tmp_connections70;
// 	m_weights[71] = tmp_weights71;
// 	m_connections[71] = tmp_connections71;
// 	m_weights[72] = tmp_weights72;
// 	m_connections[72] = tmp_connections72;
// 	m_weights[73] = tmp_weights73;
// 	m_connections[73] = tmp_connections73;
// 	m_weights[74] = tmp_weights74;
// 	m_connections[74] = tmp_connections74;
// 	m_weights[75] = tmp_weights75;
// 	m_connections[75] = tmp_connections75;
// 	m_weights[76] = tmp_weights76;
// 	m_connections[76] = tmp_connections76;
// 	m_weights[77] = tmp_weights77;
// 	m_connections[77] = tmp_connections77;
// 	m_weights[78] = tmp_weights78;
// 	m_connections[78] = tmp_connections78;
// 	m_weights[79] = tmp_weights79;
// 	m_connections[79] = tmp_connections79;
// 	m_weights[80] = tmp_weights80;
// 	m_connections[80] = tmp_connections80;
// 	m_weights[81] = tmp_weights81;
// 	m_connections[81] = tmp_connections81;
// 	m_weights[82] = tmp_weights82;
// 	m_connections[82] = tmp_connections82;
// 	m_weights[83] = tmp_weights83;
// 	m_connections[83] = tmp_connections83;
// 	m_weights[84] = tmp_weights84;
// 	m_connections[84] = tmp_connections84;
// 	m_weights[85] = tmp_weights85;
// 	m_connections[85] = tmp_connections85;
// 	m_weights[86] = tmp_weights86;
// 	m_connections[86] = tmp_connections86;
// 	m_weights[87] = tmp_weights87;
// 	m_connections[87] = tmp_connections87;
// 	m_weights[88] = tmp_weights88;
// 	m_connections[88] = tmp_connections88;
// 	m_weights[89] = tmp_weights89;
// 	m_connections[89] = tmp_connections89;
// 	m_weights[90] = tmp_weights90;
// 	m_connections[90] = tmp_connections90;
// 	m_weights[91] = tmp_weights91;
// 	m_connections[91] = tmp_connections91;
// 	m_weights[92] = tmp_weights92;
// 	m_connections[92] = tmp_connections92;
// 	m_weights[93] = tmp_weights93;
// 	m_connections[93] = tmp_connections93;
// 	m_weights[94] = tmp_weights94;
// 	m_connections[94] = tmp_connections94;
// 	m_weights[95] = tmp_weights95;
// 	m_connections[95] = tmp_connections95;
// 	m_weights[96] = tmp_weights96;
// 	m_connections[96] = tmp_connections96;
// 	m_weights[97] = tmp_weights97;
// 	m_connections[97] = tmp_connections97;
// 	m_weights[98] = tmp_weights98;
// 	m_connections[98] = tmp_connections98;
// 	m_weights[99] = tmp_weights99;
// 	m_connections[99] = tmp_connections99;
// 	m_weights[100] = tmp_weights100;
// 	m_connections[100] = tmp_connections100;
// 	m_weights[101] = tmp_weights101;
// 	m_connections[101] = tmp_connections101;
// 	m_weights[102] = tmp_weights102;
// 	m_connections[102] = tmp_connections102;
// 	m_weights[103] = tmp_weights103;
// 	m_connections[103] = tmp_connections103;
// 	m_weights[104] = tmp_weights104;
// 	m_connections[104] = tmp_connections104;
// 	m_weights[105] = tmp_weights105;
// 	m_connections[105] = tmp_connections105;
// }
