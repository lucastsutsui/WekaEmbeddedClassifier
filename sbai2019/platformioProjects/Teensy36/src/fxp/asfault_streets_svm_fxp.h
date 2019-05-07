//
// #include <Arduino.h>
// #define TOTAL_BITS 32
// #define FIXED_FBITS 10
// #define SIGNED
// #include "FixedNum.h"
//
// #define INPUT_SIZE 64
// #define NUM_CLASSES 5
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
// const FixedNum minArray[65] = {(FixedNum)0x0000001c, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000003, (FixedNum)0x00000001, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000001, (FixedNum)0x00000016, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000001, (FixedNum)0x00000001, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000003, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000001, (FixedNum)0x00000000, (FixedNum)0x00000001, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000027, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000006, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000001, (FixedNum)0x00000003, INF_POS};
// const FixedNum maxArray[65] = {(FixedNum)0x00000400, (FixedNum)0x000003c4, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x000003d2, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x000003f9, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x000003bd, (FixedNum)0x000003ed, (FixedNum)0x00000400, (FixedNum)0x000003cd, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x000003af, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000323, (FixedNum)0x00000400, (FixedNum)0x00000400, (FixedNum)0x00000000};
//
//
// const FixedNum **m_sparseWeights[5];
//
// const FixedNum *tmp0_sparseWeights1[1];
// const FixedNum tmp1_sparseWeights1_0[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0x00000e81, (FixedNum)0x000003d1, (FixedNum)0xfffffc37, (FixedNum)0xfffff6b7, (FixedNum)0xfffff97e, (FixedNum)0x000001ce, (FixedNum)0xfffffc93, (FixedNum)0x0000069c, (FixedNum)0xfffffecc, (FixedNum)0xfffffc37, (FixedNum)0xfffff97e, (FixedNum)0x00000395, (FixedNum)0x000001b4, (FixedNum)0xfffffc39, (FixedNum)0xfffffc39, (FixedNum)0x000005a0, (FixedNum)0xfffffecc, (FixedNum)0x000004fb, (FixedNum)0xfffff97e, (FixedNum)0xfffff97e, (FixedNum)0x000000b3, (FixedNum)0x000000f9, (FixedNum)0xfffff6ba, (FixedNum)0x0000036a, (FixedNum)0xfffff469, (FixedNum)0x000002a0, (FixedNum)0xfffffc31, (FixedNum)0xfffff8d7, (FixedNum)0x000006d8, (FixedNum)0xfffff7a6, (FixedNum)0x0000043b, (FixedNum)0xfffffd43, (FixedNum)0xfffff7b8, (FixedNum)0x00000189, (FixedNum)0xfffffea0, (FixedNum)0xfffffc91, (FixedNum)0x00000386, (FixedNum)0x0000012e, (FixedNum)0xfffffe17, (FixedNum)0x000002d6, (FixedNum)0x00000006, (FixedNum)0x000000d6, (FixedNum)0xfffffbf3, (FixedNum)0xfffffc37, (FixedNum)0x00000059, (FixedNum)0xfffffe75, (FixedNum)0x00000315, (FixedNum)0x00000091, (FixedNum)0xffffff5c, (FixedNum)0x000002e0, (FixedNum)0xffffff23, (FixedNum)0xffffffeb, (FixedNum)0x0000001f, (FixedNum)0xffffffc2, (FixedNum)0xfffffd63, (FixedNum)0xfffff8c2, (FixedNum)0xfffff8fc, (FixedNum)0xfffffbd1, (FixedNum)0xffffff8b, (FixedNum)0xfffffe40, (FixedNum)0xfffffc02, (FixedNum)0xfffffa6b, (FixedNum)0xfffff6ac, (FixedNum)0xfffffa59};
//
// const FixedNum *tmp0_sparseWeights2[2];
// const FixedNum tmp1_sparseWeights2_0[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0xffffea11, (FixedNum)0xfffffbc0, (FixedNum)0x000002ae, (FixedNum)0x00000527, (FixedNum)0x000002f7, (FixedNum)0x00000332, (FixedNum)0x0000050b, (FixedNum)0x00000022, (FixedNum)0x000000b9, (FixedNum)0x000002ae, (FixedNum)0x000002f7, (FixedNum)0xfffffec0, (FixedNum)0xffffffaf, (FixedNum)0x000002f0, (FixedNum)0x000002f0, (FixedNum)0xfffffe62, (FixedNum)0x000000b9, (FixedNum)0xfffffff9, (FixedNum)0x000002f7, (FixedNum)0x000002f7, (FixedNum)0xfffffe11, (FixedNum)0x0000002d, (FixedNum)0x00000343, (FixedNum)0x000002a2, (FixedNum)0x000008a1, (FixedNum)0xffffff54, (FixedNum)0x000002b6, (FixedNum)0x000003db, (FixedNum)0x000000e6, (FixedNum)0x000003b5, (FixedNum)0xffffff88, (FixedNum)0x000003ba, (FixedNum)0x0000055e, (FixedNum)0xfffffc78, (FixedNum)0xffffffe8, (FixedNum)0x00000066, (FixedNum)0xffffff0f, (FixedNum)0x00000024, (FixedNum)0x000000cf, (FixedNum)0xffffff73, (FixedNum)0x00000105, (FixedNum)0xfffffe96, (FixedNum)0x000001c1, (FixedNum)0x000002ae, (FixedNum)0x00000223, (FixedNum)0x000000d7, (FixedNum)0x000000e9, (FixedNum)0x000000de, (FixedNum)0x00000083, (FixedNum)0x0000000c, (FixedNum)0xfffffd17, (FixedNum)0x000002e1, (FixedNum)0xfffff90f, (FixedNum)0x00000449, (FixedNum)0x0000026d, (FixedNum)0x000003c6, (FixedNum)0x000001b8, (FixedNum)0xfffffd5a, (FixedNum)0xfffffeee, (FixedNum)0x00000184, (FixedNum)0x000001e4, (FixedNum)0xfffffc1b, (FixedNum)0x00000401, (FixedNum)0x00000102};
// const FixedNum tmp1_sparseWeights2_1[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0xfffff70a, (FixedNum)0xffffff53, (FixedNum)0x000001e9, (FixedNum)0x000003d9, (FixedNum)0x000002e5, (FixedNum)0xfffffeeb, (FixedNum)0x00000055, (FixedNum)0xfffffcb4, (FixedNum)0x00000011, (FixedNum)0x000001e9, (FixedNum)0x000002e5, (FixedNum)0xfffffed2, (FixedNum)0xffffff77, (FixedNum)0x00000209, (FixedNum)0x00000209, (FixedNum)0xfffffd5e, (FixedNum)0x00000011, (FixedNum)0xfffffd95, (FixedNum)0x000002e5, (FixedNum)0x000002e5, (FixedNum)0xfffffe5e, (FixedNum)0x00000077, (FixedNum)0x0000034a, (FixedNum)0xffffff1a, (FixedNum)0x0000047e, (FixedNum)0xffffff86, (FixedNum)0x000001e9, (FixedNum)0x0000030f, (FixedNum)0xfffffe70, (FixedNum)0x0000037f, (FixedNum)0xfffffe8c, (FixedNum)0x0000024a, (FixedNum)0x00000423, (FixedNum)0x00000047, (FixedNum)0x000000d0, (FixedNum)0x000001a9, (FixedNum)0xfffffffa, (FixedNum)0x00000054, (FixedNum)0x00000161, (FixedNum)0xffffff8d, (FixedNum)0x000000a3, (FixedNum)0xffffff68, (FixedNum)0x000000eb, (FixedNum)0x000001e9, (FixedNum)0x000001ed, (FixedNum)0x00000000, (FixedNum)0x0000007e, (FixedNum)0xffffffd6, (FixedNum)0x00000013, (FixedNum)0x0000012b, (FixedNum)0xffffff62, (FixedNum)0x0000003a, (FixedNum)0x0000008c, (FixedNum)0x000000a1, (FixedNum)0x00000127, (FixedNum)0x000002c2, (FixedNum)0x000001e3, (FixedNum)0x00000198, (FixedNum)0x0000019e, (FixedNum)0x000000e3, (FixedNum)0x00000108, (FixedNum)0x0000013d, (FixedNum)0x00000273, (FixedNum)0x000001ff};
//
// const FixedNum *tmp0_sparseWeights3[3];
// const FixedNum tmp1_sparseWeights3_0[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0x0000069e, (FixedNum)0x000001fe, (FixedNum)0xfffffe29, (FixedNum)0xfffffbbb, (FixedNum)0xfffffc08, (FixedNum)0x00000169, (FixedNum)0xfffffca9, (FixedNum)0x00000180, (FixedNum)0xfffffe82, (FixedNum)0xfffffe29, (FixedNum)0xfffffc08, (FixedNum)0xffffff32, (FixedNum)0xffffffdf, (FixedNum)0xfffffcce, (FixedNum)0xfffffcce, (FixedNum)0x000001b5, (FixedNum)0xfffffe82, (FixedNum)0x00000189, (FixedNum)0xfffffc08, (FixedNum)0xfffffc08, (FixedNum)0xffffff37, (FixedNum)0x000000b0, (FixedNum)0xfffffda4, (FixedNum)0x000002c3, (FixedNum)0xfffffc71, (FixedNum)0x000001ab, (FixedNum)0xfffffe28, (FixedNum)0xfffffc04, (FixedNum)0x00000124, (FixedNum)0xfffffa6f, (FixedNum)0x000003f0, (FixedNum)0xfffffe9a, (FixedNum)0xfffffb95, (FixedNum)0xffffff50, (FixedNum)0xfffffefd, (FixedNum)0xfffffd3c, (FixedNum)0x000000bb, (FixedNum)0x0000000b, (FixedNum)0xfffffdf6, (FixedNum)0x000000cc, (FixedNum)0x00000047, (FixedNum)0xffffff81, (FixedNum)0xfffffebe, (FixedNum)0xfffffe29, (FixedNum)0xffffff40, (FixedNum)0xffffff94, (FixedNum)0x0000007c, (FixedNum)0x00000018, (FixedNum)0xffffffcd, (FixedNum)0x0000008f, (FixedNum)0xffffff31, (FixedNum)0x00000031, (FixedNum)0xffffffa0, (FixedNum)0xffffff11, (FixedNum)0xffffff43, (FixedNum)0xfffffd41, (FixedNum)0xfffffe26, (FixedNum)0xffffff29, (FixedNum)0xffffff0a, (FixedNum)0xffffff42, (FixedNum)0xfffffefe, (FixedNum)0xfffffe60, (FixedNum)0xfffffd22, (FixedNum)0xfffffc2c};
// const FixedNum tmp1_sparseWeights3_1[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0x000004ef, (FixedNum)0x000002ef, (FixedNum)0xfffffcf8, (FixedNum)0xfffff852, (FixedNum)0xfffff751, (FixedNum)0xfffffe0f, (FixedNum)0xfffffcd7, (FixedNum)0x000001fe, (FixedNum)0xfffffade, (FixedNum)0xfffffcf8, (FixedNum)0xfffff751, (FixedNum)0xfffff70c, (FixedNum)0xfffffdc7, (FixedNum)0xfffff8ce, (FixedNum)0xfffff8ce, (FixedNum)0xfffffb3f, (FixedNum)0xfffffade, (FixedNum)0xfffffd14, (FixedNum)0xfffff751, (FixedNum)0xfffff751, (FixedNum)0xfffffff1, (FixedNum)0xffffffd3, (FixedNum)0x00000942, (FixedNum)0x000006bc, (FixedNum)0xfffffae5, (FixedNum)0xfffffe7b, (FixedNum)0xfffffcf9, (FixedNum)0xfffff7e6, (FixedNum)0x000004ea, (FixedNum)0xfffff29d, (FixedNum)0x00000b91, (FixedNum)0xfffffe8f, (FixedNum)0xfffff69d, (FixedNum)0xfffffa99, (FixedNum)0xfffffde7, (FixedNum)0xfffff8a8, (FixedNum)0xfffffed0, (FixedNum)0x0000003f, (FixedNum)0xfffffae4, (FixedNum)0x000000c5, (FixedNum)0x00000253, (FixedNum)0xfffffd7f, (FixedNum)0xfffffec6, (FixedNum)0xfffffcf8, (FixedNum)0x0000015a, (FixedNum)0xfffffefe, (FixedNum)0x000000c7, (FixedNum)0x00000145, (FixedNum)0x000000d7, (FixedNum)0x00000176, (FixedNum)0xffffff65, (FixedNum)0x00000091, (FixedNum)0xffffff9a, (FixedNum)0xffffff02, (FixedNum)0xfffffeec, (FixedNum)0xfffffb4f, (FixedNum)0xfffffca1, (FixedNum)0xffffff94, (FixedNum)0xfffffdb7, (FixedNum)0xfffffeb4, (FixedNum)0xfffffee4, (FixedNum)0xfffffd4f, (FixedNum)0xfffffdd8, (FixedNum)0xfffff7a0};
// const FixedNum tmp1_sparseWeights3_2[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0x00000418, (FixedNum)0xffffffa4, (FixedNum)0xfffffed4, (FixedNum)0xfffffdb3, (FixedNum)0xfffffdf0, (FixedNum)0x00000087, (FixedNum)0xfffffeef, (FixedNum)0x000000b8, (FixedNum)0xffffff4d, (FixedNum)0xfffffed4, (FixedNum)0xfffffdf0, (FixedNum)0xffffffcd, (FixedNum)0x00000019, (FixedNum)0xfffffe4a, (FixedNum)0xfffffe4a, (FixedNum)0x000000e2, (FixedNum)0xffffff4d, (FixedNum)0x00000013, (FixedNum)0xfffffdf0, (FixedNum)0xfffffdf0, (FixedNum)0xffffffea, (FixedNum)0x00000017, (FixedNum)0xffffff20, (FixedNum)0x0000015e, (FixedNum)0xfffffdc6, (FixedNum)0x000000da, (FixedNum)0xfffffed3, (FixedNum)0xfffffdfa, (FixedNum)0x00000037, (FixedNum)0xfffffd8e, (FixedNum)0x0000018b, (FixedNum)0xffffff8c, (FixedNum)0xfffffd80, (FixedNum)0xfffffff0, (FixedNum)0xffffff57, (FixedNum)0xfffffe86, (FixedNum)0x0000002f, (FixedNum)0xffffffee, (FixedNum)0xfffffec8, (FixedNum)0x00000035, (FixedNum)0x000000de, (FixedNum)0xffffff3c, (FixedNum)0xffffffa2, (FixedNum)0xfffffed4, (FixedNum)0xffffff76, (FixedNum)0xffffffdb, (FixedNum)0xfffffec5, (FixedNum)0x00000078, (FixedNum)0x0000002a, (FixedNum)0x00000059, (FixedNum)0x00000086, (FixedNum)0xffffff79, (FixedNum)0xffffffbb, (FixedNum)0xffffffbb, (FixedNum)0xffffff80, (FixedNum)0xfffffe4b, (FixedNum)0xfffffe75, (FixedNum)0xffffff98, (FixedNum)0xffffff47, (FixedNum)0xffffff8b, (FixedNum)0xffffff7a, (FixedNum)0xffffff34, (FixedNum)0xfffffeb5, (FixedNum)0xfffffde7};
//
// const FixedNum *tmp0_sparseWeights4[4];
// const FixedNum tmp1_sparseWeights4_0[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0x00000430, (FixedNum)0x000002fe, (FixedNum)0xffffffad, (FixedNum)0xfffffde8, (FixedNum)0xffffff07, (FixedNum)0xfffffed7, (FixedNum)0xfffffc57, (FixedNum)0x000002ff, (FixedNum)0xffffff4f, (FixedNum)0xffffffad, (FixedNum)0xffffff07, (FixedNum)0x0000014a, (FixedNum)0x000000ca, (FixedNum)0xfffffc5c, (FixedNum)0xfffffc5c, (FixedNum)0x000000c8, (FixedNum)0xffffff4f, (FixedNum)0x00000056, (FixedNum)0xffffff07, (FixedNum)0xffffff07, (FixedNum)0x000003db, (FixedNum)0xfffffddc, (FixedNum)0xfffffd5b, (FixedNum)0x0000021f, (FixedNum)0xfffffd5c, (FixedNum)0x000000cd, (FixedNum)0xffffffaf, (FixedNum)0xfffffd11, (FixedNum)0xfffffae4, (FixedNum)0xfffffb75, (FixedNum)0xfffffcf3, (FixedNum)0xfffff66d, (FixedNum)0xfffff9f6, (FixedNum)0xfffffc4f, (FixedNum)0x000001c8, (FixedNum)0x00000287, (FixedNum)0x00000637, (FixedNum)0x000001aa, (FixedNum)0x0000017b, (FixedNum)0x000002bf, (FixedNum)0xffffffea, (FixedNum)0x0000009d, (FixedNum)0xfffffb25, (FixedNum)0xffffffad, (FixedNum)0x00000122, (FixedNum)0xfffffcde, (FixedNum)0x000001dd, (FixedNum)0x0000007f, (FixedNum)0xffffff95, (FixedNum)0xffffffa3, (FixedNum)0xffffffb4, (FixedNum)0x00000176, (FixedNum)0xfffffe65, (FixedNum)0x0000005a, (FixedNum)0x0000029a, (FixedNum)0x00000031, (FixedNum)0xfffffc9e, (FixedNum)0x000000bb, (FixedNum)0x00000ac6, (FixedNum)0x000001ef, (FixedNum)0xfffffebf, (FixedNum)0xfffffd2c, (FixedNum)0xfffffc75, (FixedNum)0xfffffbc5};
// const FixedNum tmp1_sparseWeights4_1[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0xfffffd15, (FixedNum)0x000004d0, (FixedNum)0x00000157, (FixedNum)0x0000014b, (FixedNum)0x000001ba, (FixedNum)0xfffffd8a, (FixedNum)0x000001a1, (FixedNum)0xfffffef5, (FixedNum)0x000000ae, (FixedNum)0x00000157, (FixedNum)0x000001ba, (FixedNum)0xfffffbb1, (FixedNum)0xffffff70, (FixedNum)0xfffffd3c, (FixedNum)0xfffffd3c, (FixedNum)0x00000087, (FixedNum)0x000000ae, (FixedNum)0xfffffe77, (FixedNum)0x000001ba, (FixedNum)0x000001ba, (FixedNum)0x000002bc, (FixedNum)0xfffffc9a, (FixedNum)0xffffff60, (FixedNum)0x00000248, (FixedNum)0x00000025, (FixedNum)0xfffffa4d, (FixedNum)0x00000159, (FixedNum)0x00000081, (FixedNum)0xfffff6e3, (FixedNum)0xffffff38, (FixedNum)0xfffff942, (FixedNum)0xfffff84f, (FixedNum)0xfffffc2f, (FixedNum)0xffffff84, (FixedNum)0x000001e0, (FixedNum)0x00000362, (FixedNum)0x00000583, (FixedNum)0x00000065, (FixedNum)0x00000209, (FixedNum)0x000001d5, (FixedNum)0x000000c2, (FixedNum)0xfffffe15, (FixedNum)0xfffff979, (FixedNum)0x00000157, (FixedNum)0x0000022a, (FixedNum)0xfffffbed, (FixedNum)0x0000048f, (FixedNum)0xffffffdb, (FixedNum)0xffffff1a, (FixedNum)0xffffff14, (FixedNum)0xffffff5e, (FixedNum)0x00000174, (FixedNum)0xfffffd0e, (FixedNum)0x000003d6, (FixedNum)0x00000311, (FixedNum)0x0000028b, (FixedNum)0x00000152, (FixedNum)0x00000309, (FixedNum)0x00000afa, (FixedNum)0x000002f4, (FixedNum)0x00000008, (FixedNum)0xffffff98, (FixedNum)0x000000ed, (FixedNum)0xfffffde8};
// const FixedNum tmp1_sparseWeights4_2[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0x000004f7, (FixedNum)0x0000042a, (FixedNum)0xffffff4a, (FixedNum)0xfffffd03, (FixedNum)0xfffffe73, (FixedNum)0xfffffdf6, (FixedNum)0xffffffbd, (FixedNum)0xffffff6b, (FixedNum)0x00000047, (FixedNum)0xffffff4a, (FixedNum)0xfffffe73, (FixedNum)0x000000da, (FixedNum)0x00000111, (FixedNum)0xfffffc94, (FixedNum)0xfffffc94, (FixedNum)0x00000190, (FixedNum)0x00000047, (FixedNum)0x00000105, (FixedNum)0xfffffe73, (FixedNum)0xfffffe73, (FixedNum)0x0000022b, (FixedNum)0xfffffea1, (FixedNum)0xfffffe3e, (FixedNum)0x00000027, (FixedNum)0xfffffb49, (FixedNum)0x0000001d, (FixedNum)0xffffff4a, (FixedNum)0xfffffd8a, (FixedNum)0xfffffcfe, (FixedNum)0xfffffcf4, (FixedNum)0xffffffec, (FixedNum)0xfffffbe6, (FixedNum)0xfffffc09, (FixedNum)0x00000012, (FixedNum)0x000000e5, (FixedNum)0x00000074, (FixedNum)0x000002ce, (FixedNum)0x000000de, (FixedNum)0x00000045, (FixedNum)0x000001ae, (FixedNum)0x0000002d, (FixedNum)0xffffffda, (FixedNum)0xfffffd2e, (FixedNum)0xffffff4a, (FixedNum)0xfffffefb, (FixedNum)0xfffffe7b, (FixedNum)0xffffffb4, (FixedNum)0xffffff04, (FixedNum)0xffffff56, (FixedNum)0x00000003, (FixedNum)0xffffff37, (FixedNum)0xffffff49, (FixedNum)0xffffff43, (FixedNum)0xffffffb4, (FixedNum)0x0000015e, (FixedNum)0xffffff7f, (FixedNum)0x00000060, (FixedNum)0x000001ea, (FixedNum)0x00000400, (FixedNum)0x000001a6, (FixedNum)0x0000005f, (FixedNum)0xfffffec8, (FixedNum)0xfffffefa, (FixedNum)0xfffffd8c};
// const FixedNum tmp1_sparseWeights4_3[65] = {(FixedNum)(0x00010000 >> FIXED_FBITS), (FixedNum)0xfffffaf1, (FixedNum)0x0000022b, (FixedNum)0x00000141, (FixedNum)0x00000232, (FixedNum)0x0000033c, (FixedNum)0xffffffbe, (FixedNum)0x000002dd, (FixedNum)0xfffffdb1, (FixedNum)0x0000020d, (FixedNum)0x00000141, (FixedNum)0x0000033c, (FixedNum)0x000003e9, (FixedNum)0x0000015b, (FixedNum)0x0000000d, (FixedNum)0x0000000d, (FixedNum)0x000000e7, (FixedNum)0x0000020d, (FixedNum)0x00000212, (FixedNum)0x0000033c, (FixedNum)0x0000033c, (FixedNum)0x000003db, (FixedNum)0xfffffb41, (FixedNum)0xfffffc46, (FixedNum)0xfffffe65, (FixedNum)0x000000ba, (FixedNum)0xfffffc16, (FixedNum)0x00000143, (FixedNum)0x0000021f, (FixedNum)0xfffff5c5, (FixedNum)0x000002c6, (FixedNum)0xfffff82e, (FixedNum)0xfffff8de, (FixedNum)0x00000069, (FixedNum)0xffffffb8, (FixedNum)0x00000168, (FixedNum)0x00000427, (FixedNum)0x00000350, (FixedNum)0xffffff12, (FixedNum)0x000002d0, (FixedNum)0x00000061, (FixedNum)0xffffff2f, (FixedNum)0x000000c5, (FixedNum)0xfffffc11, (FixedNum)0x00000141, (FixedNum)0xffffffcf, (FixedNum)0xffffff21, (FixedNum)0x000001cd, (FixedNum)0x00000139, (FixedNum)0x000000b4, (FixedNum)0xffffffde, (FixedNum)0xfffffe99, (FixedNum)0x0000008c, (FixedNum)0xffffff87, (FixedNum)0x00000220, (FixedNum)0x00000214, (FixedNum)0x00000496, (FixedNum)0x000002a1, (FixedNum)0x000000e0, (FixedNum)0x0000044f, (FixedNum)0x000001e3, (FixedNum)0x0000009b, (FixedNum)0x0000001c, (FixedNum)0xffffffeb, (FixedNum)0x00000102};
//
// const int **m_sparseIndices[5];
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
// const int *tmp0_sparseIndices4[4];
// const int tmp1_sparseIndices4_0[64] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
// const int tmp1_sparseIndices4_1[64] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
// const int tmp1_sparseIndices4_2[64] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
// const int tmp1_sparseIndices4_3[64] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};
//
// const FixedNum *m_b[5];
// const FixedNum tmp_m_b1[1] = {(FixedNum)0xffffeb4a};
// const FixedNum tmp_m_b2[2] = {(FixedNum)0x00001f44, (FixedNum)0x00000e48};
// const FixedNum tmp_m_b3[3] = {(FixedNum)0xfffff6b7, (FixedNum)0xfffffc11, (FixedNum)0xfffff93c};
// const FixedNum tmp_m_b4[4] = {(FixedNum)0xffffed06, (FixedNum)0xfffff4fd, (FixedNum)0xffffee51, (FixedNum)0xfffff387};
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
//  * Output number 2 means that the instance was classified as pessimo
//  * Output number 3 means that the instance was classified as bom
//  * Output number 4 means that the instance was classified as obstaculos
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
// 	tmp0_sparseWeights4[0] = tmp1_sparseWeights4_0;
// 	tmp0_sparseWeights4[1] = tmp1_sparseWeights4_1;
// 	tmp0_sparseWeights4[2] = tmp1_sparseWeights4_2;
// 	tmp0_sparseWeights4[3] = tmp1_sparseWeights4_3;
// 	m_sparseWeights[4] = tmp0_sparseWeights4;
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
// 	tmp0_sparseIndices4[0] = tmp1_sparseIndices4_0;
// 	tmp0_sparseIndices4[1] = tmp1_sparseIndices4_1;
// 	tmp0_sparseIndices4[2] = tmp1_sparseIndices4_2;
// 	tmp0_sparseIndices4[3] = tmp1_sparseIndices4_3;
// 	m_sparseIndices[4] = tmp0_sparseIndices4;
//
//
// 	m_b[0] = NULL;
// 	m_b[1] = tmp_m_b1;
// 	m_b[2] = tmp_m_b2;
// 	m_b[3] = tmp_m_b3;
// 	m_b[4] = tmp_m_b4;
// }
