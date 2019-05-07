//
// #include <Arduino.h>
// #define TOTAL_BITS 32
// #define FIXED_FBITS 10
// #define SIGNED
// #include "FixedNum.h"
//
// #define INPUT_SIZE 64
// #define NUM_CLASSES 4
// #define CLASS_INDEX 64
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
// const FixedNum minArray[65] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x0000000d, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000001, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000001, (FixedNum)0x00000000, (FixedNum)0x00000001, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000001, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000005, (FixedNum)0x00000001, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000006, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000004, (FixedNum)0x00000002, (FixedNum)0x00000001, (FixedNum)0x00000003, INF_POS};
// const FixedNum maxArray[65] = {(FixedNum)0x000003f9, (FixedNum)0x00000231, (FixedNum)0x000002f8, (FixedNum)0x0000037b, (FixedNum)0x00000363, (FixedNum)0x00000400, (FixedNum)0x000003cf, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x000002f8, (FixedNum)0x00000363, (FixedNum)0x00000380, (FixedNum)0x00000382, (FixedNum)0x00000307, (FixedNum)0x00000307, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000363, (FixedNum)0x00000363, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x000003f9, (FixedNum)0x000003f1, (FixedNum)0x00000355, (FixedNum)0x00000400, (FixedNum)0x0000031b, (FixedNum)0x000003b9, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x0000028c, (FixedNum)0x00000400, (FixedNum)0x00000250, (FixedNum)0x000002f3, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x000003ea, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x000003ff, (FixedNum)0x000002f8, (FixedNum)0x00000400, (FixedNum)0x00000386, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x000003e7, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x000002c7, (FixedNum)0x000002ae, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x000003b7, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x000003fb, (FixedNum)0x000002c5, (FixedNum)0x00000000};
//
//
// const FixedNum **m_sparseWeights[4];
//
// const FixedNum *tmp0_sparseWeights1[1];
// const FixedNum tmp1_sparseWeights1_0[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0x000009bd, (FixedNum)0xfffffe61, (FixedNum)0xfffffc2a, (FixedNum)0xfffffd91, (FixedNum)0xfffffcde, (FixedNum)0x00000120, (FixedNum)0xfffffdb5, (FixedNum)0x000001d2, (FixedNum)0xffffff4f, (FixedNum)0xfffffc2a, (FixedNum)0xfffffcde, (FixedNum)0xfffffffe, (FixedNum)0x00000088, (FixedNum)0xfffffb3c, (FixedNum)0xfffffb3c, (FixedNum)0x0000015c, (FixedNum)0xffffff4f, (FixedNum)0x000002ea, (FixedNum)0xfffffcde, (FixedNum)0xfffffcde, (FixedNum)0x000002b1, (FixedNum)0xfffffdbb, (FixedNum)0xfffffe75, (FixedNum)0x0000051b, (FixedNum)0xffffff28, (FixedNum)0x000000a2, (FixedNum)0xfffffe85, (FixedNum)0xffffff50, (FixedNum)0xfffffe0e, (FixedNum)0xfffffffc, (FixedNum)0x00000041, (FixedNum)0xffffff82, (FixedNum)0x0000012d, (FixedNum)0x0000013f, (FixedNum)0xffffff18, (FixedNum)0x00000038, (FixedNum)0x00000059, (FixedNum)0x00000077, (FixedNum)0x0000002c, (FixedNum)0xffffffdd, (FixedNum)0x00000036, (FixedNum)0xfffffebb, (FixedNum)0x000000a4, (FixedNum)0xfffffc2a, (FixedNum)0xfffffd58, (FixedNum)0xfffffb76, (FixedNum)0x00000254, (FixedNum)0x00000186, (FixedNum)0x00000207, (FixedNum)0xfffffefb, (FixedNum)0x0000024e, (FixedNum)0xfffffe9c, (FixedNum)0xfffffd53, (FixedNum)0x0000019c, (FixedNum)0x0000017a, (FixedNum)0x0000005a, (FixedNum)0x000001ef, (FixedNum)0xfffffece, (FixedNum)0xffffffc3, (FixedNum)0x00000381, (FixedNum)0x0000017f, (FixedNum)0xffffff73, (FixedNum)0xfffffbe1, (FixedNum)0x000000c9};
//
// const FixedNum *tmp0_sparseWeights2[2];
// const FixedNum tmp1_sparseWeights2_0[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0x000007c9, (FixedNum)0xffffff18, (FixedNum)0xfffffcdf, (FixedNum)0xfffffee6, (FixedNum)0xfffffcef, (FixedNum)0x00000084, (FixedNum)0xfffffdfd, (FixedNum)0x00000140, (FixedNum)0xfffffcfc, (FixedNum)0xfffffcdf, (FixedNum)0xfffffcef, (FixedNum)0xfffffdc8, (FixedNum)0xffffff2a, (FixedNum)0xfffffc6f, (FixedNum)0xfffffc6f, (FixedNum)0xfffffd54, (FixedNum)0xfffffcfc, (FixedNum)0xfffffe92, (FixedNum)0xfffffcef, (FixedNum)0xfffffcef, (FixedNum)0x0000018a, (FixedNum)0xffffff05, (FixedNum)0x0000044a, (FixedNum)0x000006f0, (FixedNum)0x00000243, (FixedNum)0xffffffc9, (FixedNum)0xfffffe89, (FixedNum)0xfffffe81, (FixedNum)0xffffff03, (FixedNum)0xfffffee2, (FixedNum)0x00000121, (FixedNum)0xffffffdb, (FixedNum)0xffffff7d, (FixedNum)0x0000015e, (FixedNum)0xfffffede, (FixedNum)0xfffffef1, (FixedNum)0x0000002e, (FixedNum)0xfffffff8, (FixedNum)0x0000003d, (FixedNum)0x00000052, (FixedNum)0x000000a7, (FixedNum)0xffffff92, (FixedNum)0xffffff88, (FixedNum)0xfffffcdf, (FixedNum)0x00000166, (FixedNum)0xffffff3a, (FixedNum)0x00000286, (FixedNum)0x0000005d, (FixedNum)0x000000f6, (FixedNum)0x00000046, (FixedNum)0x000000ab, (FixedNum)0xffffff88, (FixedNum)0xffffff9d, (FixedNum)0xffffffe6, (FixedNum)0x00000045, (FixedNum)0x00000256, (FixedNum)0xffffff66, (FixedNum)0xffffff16, (FixedNum)0xffffffe9, (FixedNum)0x000001a7, (FixedNum)0xffffffc1, (FixedNum)0xfffffd04, (FixedNum)0xffffff0c, (FixedNum)0xfffffe9b};
// const FixedNum tmp1_sparseWeights2_1[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0x00000d02, (FixedNum)0xffffffcb, (FixedNum)0xfffffbdd, (FixedNum)0x00000314, (FixedNum)0xfffffb3f, (FixedNum)0x000001f7, (FixedNum)0xfffff936, (FixedNum)0x000007ad, (FixedNum)0xfffff8b7, (FixedNum)0xfffffbdd, (FixedNum)0xfffffb3f, (FixedNum)0xfffff66b, (FixedNum)0xfffffaf7, (FixedNum)0xfffff999, (FixedNum)0xfffff998, (FixedNum)0xfffff5db, (FixedNum)0xfffff8b7, (FixedNum)0xfffffd1e, (FixedNum)0xfffffb3f, (FixedNum)0xfffffb3f, (FixedNum)0xffffff6d, (FixedNum)0x000003b2, (FixedNum)0x00000fb5, (FixedNum)0x00000a3a, (FixedNum)0x00000e85, (FixedNum)0x00000109, (FixedNum)0xfffffddc, (FixedNum)0xfffffcca, (FixedNum)0xfffffc11, (FixedNum)0xfffffcd2, (FixedNum)0x000002b2, (FixedNum)0xffffff4a, (FixedNum)0xfffffe72, (FixedNum)0x000001a8, (FixedNum)0xfffffefa, (FixedNum)0xfffffe99, (FixedNum)0xffffffa2, (FixedNum)0xfffffcac, (FixedNum)0xfffffe67, (FixedNum)0xffffff79, (FixedNum)0x000001f6, (FixedNum)0xffffff37, (FixedNum)0xfffffcbf, (FixedNum)0xfffffbdd, (FixedNum)0x00000152, (FixedNum)0x0000001b, (FixedNum)0xffffff87, (FixedNum)0x000002a1, (FixedNum)0x000001f1, (FixedNum)0x00000380, (FixedNum)0xfffffff1, (FixedNum)0xfffffde2, (FixedNum)0x0000002d, (FixedNum)0xfffffdb1, (FixedNum)0x000000cb, (FixedNum)0x00000064, (FixedNum)0xfffffeea, (FixedNum)0x00000430, (FixedNum)0xfffffa16, (FixedNum)0x000000c9, (FixedNum)0xfffffd94, (FixedNum)0xfffffca9, (FixedNum)0xfffffc1c, (FixedNum)0xfffffe0d};
//
// const FixedNum *tmp0_sparseWeights3[3];
// const FixedNum tmp1_sparseWeights3_0[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0xfffffe16, (FixedNum)0x000000d4, (FixedNum)0xfffffeb0, (FixedNum)0xfffffe59, (FixedNum)0xfffffe56, (FixedNum)0x000000d4, (FixedNum)0xffffffb5, (FixedNum)0x0000012d, (FixedNum)0xfffffef3, (FixedNum)0xfffffeb0, (FixedNum)0xfffffe56, (FixedNum)0xffffff84, (FixedNum)0xffffffdc, (FixedNum)0xfffffe03, (FixedNum)0xfffffe03, (FixedNum)0xffffff71, (FixedNum)0xfffffef3, (FixedNum)0xffffff77, (FixedNum)0xfffffe56, (FixedNum)0xfffffe56, (FixedNum)0x000000c2, (FixedNum)0xffffff34, (FixedNum)0x000000c0, (FixedNum)0x00000074, (FixedNum)0xfffffe6d, (FixedNum)0x000001b7, (FixedNum)0xffffff9a, (FixedNum)0xffffff2f, (FixedNum)0xffffffde, (FixedNum)0xfffffefa, (FixedNum)0x00000071, (FixedNum)0xffffff92, (FixedNum)0xfffffe94, (FixedNum)0xffffff73, (FixedNum)0xffffffb6, (FixedNum)0xffffff70, (FixedNum)0x00000089, (FixedNum)0x0000003a, (FixedNum)0xfffffff2, (FixedNum)0x000000a6, (FixedNum)0xfffffefb, (FixedNum)0x0000011c, (FixedNum)0xffffff13, (FixedNum)0xfffffeb0, (FixedNum)0xffffff3d, (FixedNum)0xffffffeb, (FixedNum)0x000002af, (FixedNum)0x000000a2, (FixedNum)0x00000091, (FixedNum)0x000000a0, (FixedNum)0x0000002f, (FixedNum)0xffffff94, (FixedNum)0xffffff5d, (FixedNum)0xffffffe3, (FixedNum)0x0000009e, (FixedNum)0x00000038, (FixedNum)0xffffffdb, (FixedNum)0xffffff93, (FixedNum)0xffffffd0, (FixedNum)0x0000015b, (FixedNum)0xffffff40, (FixedNum)0xfffffedc, (FixedNum)0xfffffe9c, (FixedNum)0xfffffeee};
// const FixedNum tmp1_sparseWeights3_1[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0xfffff9f3, (FixedNum)0x000000c9, (FixedNum)0xffffff89, (FixedNum)0xffffff19, (FixedNum)0xffffff9e, (FixedNum)0x00000010, (FixedNum)0xfffffe97, (FixedNum)0x000002c0, (FixedNum)0xffffff60, (FixedNum)0xffffff89, (FixedNum)0xffffff9e, (FixedNum)0xffffff9d, (FixedNum)0xfffffff5, (FixedNum)0xfffffe57, (FixedNum)0xfffffe57, (FixedNum)0xfffffe3d, (FixedNum)0xffffff60, (FixedNum)0xfffffe66, (FixedNum)0xffffff9e, (FixedNum)0xffffff9e, (FixedNum)0xffffffec, (FixedNum)0xfffffff4, (FixedNum)0x00000115, (FixedNum)0x0000016a, (FixedNum)0xfffffeae, (FixedNum)0x00000102, (FixedNum)0xffffff8f, (FixedNum)0xffffff01, (FixedNum)0xffffffe6, (FixedNum)0xfffffe73, (FixedNum)0x00000033, (FixedNum)0xfffffbeb, (FixedNum)0xfffffedc, (FixedNum)0xfffffe5c, (FixedNum)0xffffffcc, (FixedNum)0xfffffffa, (FixedNum)0x000000f1, (FixedNum)0x00000038, (FixedNum)0x00000024, (FixedNum)0x000000e6, (FixedNum)0x000000c0, (FixedNum)0xffffff04, (FixedNum)0xfffffe5b, (FixedNum)0xffffff89, (FixedNum)0x00000111, (FixedNum)0x000001cc, (FixedNum)0x0000055b, (FixedNum)0x000001f4, (FixedNum)0x00000168, (FixedNum)0x000000cc, (FixedNum)0x00000038, (FixedNum)0xffffffc2, (FixedNum)0xffffff4c, (FixedNum)0x0000003c, (FixedNum)0xffffff44, (FixedNum)0xffffffd3, (FixedNum)0x00000045, (FixedNum)0xffffff1e, (FixedNum)0x00000004, (FixedNum)0x000004d3, (FixedNum)0xffffff24, (FixedNum)0xfffffe4b, (FixedNum)0xfffffec7, (FixedNum)0xfffffecc};
// const FixedNum tmp1_sparseWeights3_2[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0xfffff912, (FixedNum)0x00000210, (FixedNum)0x00000020, (FixedNum)0x00000009, (FixedNum)0x00000147, (FixedNum)0xfffffec7, (FixedNum)0x00000047, (FixedNum)0x000001b5, (FixedNum)0x000000e3, (FixedNum)0x00000020, (FixedNum)0x00000147, (FixedNum)0x00000057, (FixedNum)0x0000008e, (FixedNum)0xfffffef2, (FixedNum)0xfffffef2, (FixedNum)0x00000073, (FixedNum)0x000000e3, (FixedNum)0xffffff96, (FixedNum)0x00000147, (FixedNum)0x00000147, (FixedNum)0xffffff2e, (FixedNum)0x000000f1, (FixedNum)0xfffffda5, (FixedNum)0xffffffca, (FixedNum)0xfffffe63, (FixedNum)0x00000004, (FixedNum)0xffffffc2, (FixedNum)0xffffff8f, (FixedNum)0xffffff15, (FixedNum)0xffffffbe, (FixedNum)0xfffffe7f, (FixedNum)0xfffffee1, (FixedNum)0xfffffe80, (FixedNum)0x0000000d, (FixedNum)0x0000008e, (FixedNum)0x000000f2, (FixedNum)0x000000d6, (FixedNum)0x00000036, (FixedNum)0x000000a9, (FixedNum)0xfffffff0, (FixedNum)0xffffffe4, (FixedNum)0xffffffca, (FixedNum)0xffffff75, (FixedNum)0x00000020, (FixedNum)0x0000009b, (FixedNum)0x00000090, (FixedNum)0x000001ce, (FixedNum)0x0000001f, (FixedNum)0xffffffe5, (FixedNum)0xffffff3b, (FixedNum)0xffffff57, (FixedNum)0xffffffdb, (FixedNum)0xfffffff8, (FixedNum)0x00000078, (FixedNum)0x00000024, (FixedNum)0x000000f3, (FixedNum)0x00000060, (FixedNum)0x0000001e, (FixedNum)0x000001b4, (FixedNum)0x00000516, (FixedNum)0xfffffe7f, (FixedNum)0xffffff42, (FixedNum)0xfffffee4, (FixedNum)0xffffff0b};
//
// const int **m_sparseIndices[4];
//
// const int *tmp0_sparseIndices1[1];
// const int tmp1_sparseIndices1_0[64] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const int *tmp0_sparseIndices2[2];
// const int tmp1_sparseIndices2_0[64] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
// const int tmp1_sparseIndices2_1[64] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const int *tmp0_sparseIndices3[3];
// const int tmp1_sparseIndices3_0[64] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
// const int tmp1_sparseIndices3_1[64] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
// const int tmp1_sparseIndices3_2[64] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum *m_b[4];
// const FixedNum tmp_m_b1[1] = {(FixedNum)0xfffff132};
// const FixedNum tmp_m_b2[2] = {(FixedNum)0xfffffcea, (FixedNum)0x0000094f};
// const FixedNum tmp_m_b3[3] = {(FixedNum)0xfffff919, (FixedNum)0xfffffeec, (FixedNum)0xffffffc6};
//
// FixedNum SVMOutput(int i, int j){
// 	FixedNum result = (FixedNum)0;
// 	for (int p1 = 0; p1 < m_sparseWeights[i][j][0]; p1++){
// 		int p2 = m_sparseIndices[i][j][p1];
// 		if (p2 != CLASS_INDEX){
// 			result = fxp_sum(result, fxp_mul(instance[p2], m_sparseWeights[i][j][p1+1]));
// 		}
// 	}
// 	result = fxp_diff(result, m_b[i][j]);
// 	return result;
// }
//
// /* Function classify description:
//  * Instance array must be initializated, with appropriated attributes, before calling this function
//  * Output number 0 means that the instance was classified as ruim
//  * Output number 1 means that the instance was classified as regular
//  * Output number 2 means that the instance was classified as bom
//  * Output number 3 means that the instance was classified as obstaculos
//  */
// int classify(){
// 	for (int i = 0; i <= INPUT_SIZE; i++){
// 		if (maxArray[i] == minArray[i] || minArray[i] == INF_POS){
// 			instance[i] = (FixedNum)0;
// 		}
// 		else{
// 			instance[i] = fxp_div(fxp_diff(instance[i], minArray[i]), fxp_diff(maxArray[i], minArray[i]));
// 		}
// 	}
// 	int result[NUM_CLASSES] = {0};
// 	for (int i = 1; i < NUM_CLASSES; i++){
// 		for (int j = 0; j < i; j++){
// 			FixedNum output = SVMOutput(i, j);
// 			if (output > 0){
// 				result[i]++;
// 			}
// 			else{
// 				result[j]++;
// 			}
// 		}
// 	}
// 	int indMax = 0;
// 	for (int i = 1; i < NUM_CLASSES; i++){
// 		if (result[i] > result[indMax]){
// 			indMax = i;
// 		}
// 	}
// 	return indMax;
// }
//
// void initConnections(){
//
// 	m_sparseWeights[0] = NULL;
//
// 	tmp0_sparseWeights1[0] = tmp1_sparseWeights1_0;
// 	m_sparseWeights[1] = tmp0_sparseWeights1;
//
// 	tmp0_sparseWeights2[0] = tmp1_sparseWeights2_0;
// 	tmp0_sparseWeights2[1] = tmp1_sparseWeights2_1;
// 	m_sparseWeights[2] = tmp0_sparseWeights2;
//
// 	tmp0_sparseWeights3[0] = tmp1_sparseWeights3_0;
// 	tmp0_sparseWeights3[1] = tmp1_sparseWeights3_1;
// 	tmp0_sparseWeights3[2] = tmp1_sparseWeights3_2;
// 	m_sparseWeights[3] = tmp0_sparseWeights3;
//
//
// 	m_sparseIndices[0] = NULL;
//
// 	tmp0_sparseIndices1[0] = tmp1_sparseIndices1_0;
// 	m_sparseIndices[1] = tmp0_sparseIndices1;
//
// 	tmp0_sparseIndices2[0] = tmp1_sparseIndices2_0;
// 	tmp0_sparseIndices2[1] = tmp1_sparseIndices2_1;
// 	m_sparseIndices[2] = tmp0_sparseIndices2;
//
// 	tmp0_sparseIndices3[0] = tmp1_sparseIndices3_0;
// 	tmp0_sparseIndices3[1] = tmp1_sparseIndices3_1;
// 	tmp0_sparseIndices3[2] = tmp1_sparseIndices3_2;
// 	m_sparseIndices[3] = tmp0_sparseIndices3;
//
//
// 	m_b[0] = NULL;
// 	m_b[1] = tmp_m_b1;
// 	m_b[2] = tmp_m_b2;
// 	m_b[3] = tmp_m_b3;
// }
