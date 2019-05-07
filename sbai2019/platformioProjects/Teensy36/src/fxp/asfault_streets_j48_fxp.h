//
// #include <Arduino.h>
// #define TOTAL_BITS 32
// #define FIXED_FBITS 10
// #define SIGNED
// #include "FixedNum.h"
//
// #define M_ROOT 0
// #define NUM_CLASSES 5
// #define CLASS_INDEX 64
// #define LEN_TREE 215
// #define INPUT_SIZE 64
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
// int m_attIndex[LEN_TREE] = {26, 22, 27, 13, -1, -1, 50, 33, 23, -1, -1, -1, -1, 58, 26, -1, 12, 11, 44, 31, -1, 34, -1, 28, -1, 47, 25, -1, -1, -1, -1, 3, 51, -1, 0, 37, -1, -1, -1, 0, -1, -1, 5, -1, -1, 0, -1, -1, 3, 36, 3, 27, 12, 6, 29, 5, 24, 57, -1, -1, 2, -1, 45, -1, -1, -1, -1, 33, 1, -1, -1, -1, -1, 59, -1, 58, 17, 6, 44, 6, -1, -1, -1, 62, -1, -1, -1, 31, -1, 59, -1, 47, -1, 49, -1, 37, -1, -1, 28, 54, -1, 36, -1, 62, -1, 46, 53, 40, -1, -1, -1, -1, 15, 56, -1, 32, -1, 20, -1, -1, 49, -1, -1, 25, 25, -1, 31, -1, 40, 2, -1, -1, -1, 8, -1, -1, 28, 39, -1, 44, -1, -1, 24, 60, 54, 23, -1, 0, 63, -1, 57, 15, -1, -1, -1, -1, 11, -1, 0, -1, -1, 36, 0, 24, -1, 32, 0, 47, -1, 32, 8, -1, -1, -1, -1, -1, 24, 54, -1, 0, 23, -1, 0, -1, 57, -1, -1, 34, -1, -1, -1, 15, 32, 54, -1, -1, 63, -1, -1, -1, 0, -1, 24, 0, 27, -1, -1, 29, -1, 36, -1, -1, 20, -1, -1};
//
// FixedNum m_splitPoint[LEN_TREE] = {(FixedNum)0x00000025, (FixedNum)0x00000232, (FixedNum)0x00000063, (FixedNum)0x00000020, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000299, (FixedNum)0x00000221, (FixedNum)0x00000346, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000031, (FixedNum)0x0000001c, (FixedNum)0xfffffc00, (FixedNum)0x0000001f, (FixedNum)0x0000008c, (FixedNum)0x0000014d, (FixedNum)0x000002b9, (FixedNum)0xfffffc00, (FixedNum)0x00000013, (FixedNum)0xfffffc00, (FixedNum)0x000001ea, (FixedNum)0xfffffc00, (FixedNum)0x0000010f, (FixedNum)0x00000373, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x0000009a, (FixedNum)0x00000058, (FixedNum)0xfffffc00, (FixedNum)0x0000010f, (FixedNum)0x00000013, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000000c7, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000110, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x0000019f, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000141, (FixedNum)0x00000107, (FixedNum)0x00000114, (FixedNum)0x000000a2, (FixedNum)0x00000022, (FixedNum)0x0000025b, (FixedNum)0x0000014b, (FixedNum)0x00000266, (FixedNum)0x000000bc, (FixedNum)0x0000004a, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000029, (FixedNum)0xfffffc00, (FixedNum)0x00000131, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x0000022c, (FixedNum)0x00000103, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000011, (FixedNum)0xfffffc00, (FixedNum)0x00000039, (FixedNum)0x000000c7, (FixedNum)0x00000251, (FixedNum)0x00000080, (FixedNum)0x00000213, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000045, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000001f6, (FixedNum)0xfffffc00, (FixedNum)0x00000019, (FixedNum)0xfffffc00, (FixedNum)0x0000003f, (FixedNum)0xfffffc00, (FixedNum)0x0000005e, (FixedNum)0xfffffc00, (FixedNum)0x0000004b, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000001cc, (FixedNum)0x0000000d, (FixedNum)0xfffffc00, (FixedNum)0x00000096, (FixedNum)0xfffffc00, (FixedNum)0x00000039, (FixedNum)0xfffffc00, (FixedNum)0x00000068, (FixedNum)0x00000087, (FixedNum)0x0000029e, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000000d3, (FixedNum)0x00000017, (FixedNum)0xfffffc00, (FixedNum)0x0000010d, (FixedNum)0xfffffc00, (FixedNum)0x00000289, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000020, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x0000002c, (FixedNum)0x0000000c, (FixedNum)0xfffffc00, (FixedNum)0x000002a7, (FixedNum)0xfffffc00, (FixedNum)0x00000262, (FixedNum)0x00000044, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x0000003e, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x0000013a, (FixedNum)0x000000ce, (FixedNum)0xfffffc00, (FixedNum)0x0000004d, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000209, (FixedNum)0x00000021, (FixedNum)0x00000023, (FixedNum)0x0000027f, (FixedNum)0xfffffc00, (FixedNum)0x00000222, (FixedNum)0x00000117, (FixedNum)0xfffffc00, (FixedNum)0x00000030, (FixedNum)0x00000131, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000000b6, (FixedNum)0xfffffc00, (FixedNum)0x00000160, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000000d1, (FixedNum)0x0000014d, (FixedNum)0x000001b3, (FixedNum)0xfffffc00, (FixedNum)0x000001f7, (FixedNum)0x00000106, (FixedNum)0x00000059, (FixedNum)0xfffffc00, (FixedNum)0x000001ae, (FixedNum)0x00000098, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000164, (FixedNum)0x00000007, (FixedNum)0xfffffc00, (FixedNum)0x00000275, (FixedNum)0x000002f5, (FixedNum)0xfffffc00, (FixedNum)0x000001a7, (FixedNum)0xfffffc00, (FixedNum)0x00000057, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000059, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000001c3, (FixedNum)0x0000014e, (FixedNum)0x000000c8, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000173, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000131, (FixedNum)0xfffffc00, (FixedNum)0x0000028e, (FixedNum)0x00000189, (FixedNum)0x000001d2, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000002eb, (FixedNum)0xfffffc00, (FixedNum)0x00000044, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000002ab, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00};
//
// const int *tree[LEN_TREE];
// int tree_0[2] = {1, 48};
// int tree_1[2] = {2, 13};
// int tree_2[2] = {3, 6};
// int tree_3[2] = {4, 5};
// int tree_6[2] = {7, 12};
// int tree_7[2] = {8, 11};
// int tree_8[2] = {9, 10};
// int tree_13[2] = {14, 45};
// int tree_14[2] = {15, 16};
// int tree_16[2] = {17, 42};
// int tree_17[2] = {18, 31};
// int tree_18[2] = {19, 30};
// int tree_19[2] = {20, 21};
// int tree_21[2] = {22, 23};
// int tree_23[2] = {24, 25};
// int tree_25[2] = {26, 29};
// int tree_26[2] = {27, 28};
// int tree_31[2] = {32, 39};
// int tree_32[2] = {33, 34};
// int tree_34[2] = {35, 38};
// int tree_35[2] = {36, 37};
// int tree_39[2] = {40, 41};
// int tree_42[2] = {43, 44};
// int tree_45[2] = {46, 47};
// int tree_48[2] = {49, 136};
// int tree_49[2] = {50, 123};
// int tree_50[2] = {51, 98};
// int tree_51[2] = {52, 73};
// int tree_52[2] = {53, 72};
// int tree_53[2] = {54, 67};
// int tree_54[2] = {55, 66};
// int tree_55[2] = {56, 65};
// int tree_56[2] = {57, 60};
// int tree_57[2] = {58, 59};
// int tree_60[2] = {61, 62};
// int tree_62[2] = {63, 64};
// int tree_67[2] = {68, 71};
// int tree_68[2] = {69, 70};
// int tree_73[2] = {74, 75};
// int tree_75[2] = {76, 87};
// int tree_76[2] = {77, 86};
// int tree_77[2] = {78, 83};
// int tree_78[2] = {79, 82};
// int tree_79[2] = {80, 81};
// int tree_83[2] = {84, 85};
// int tree_87[2] = {88, 89};
// int tree_89[2] = {90, 91};
// int tree_91[2] = {92, 93};
// int tree_93[2] = {94, 95};
// int tree_95[2] = {96, 97};
// int tree_98[2] = {99, 112};
// int tree_99[2] = {100, 101};
// int tree_101[2] = {102, 103};
// int tree_103[2] = {104, 105};
// int tree_105[2] = {106, 111};
// int tree_106[2] = {107, 110};
// int tree_107[2] = {108, 109};
// int tree_112[2] = {113, 120};
// int tree_113[2] = {114, 115};
// int tree_115[2] = {116, 117};
// int tree_117[2] = {118, 119};
// int tree_120[2] = {121, 122};
// int tree_123[2] = {124, 133};
// int tree_124[2] = {125, 126};
// int tree_126[2] = {127, 128};
// int tree_128[2] = {129, 132};
// int tree_129[2] = {130, 131};
// int tree_133[2] = {134, 135};
// int tree_136[2] = {137, 142};
// int tree_137[2] = {138, 139};
// int tree_139[2] = {140, 141};
// int tree_142[2] = {143, 200};
// int tree_143[2] = {144, 161};
// int tree_144[2] = {145, 156};
// int tree_145[2] = {146, 147};
// int tree_147[2] = {148, 155};
// int tree_148[2] = {149, 150};
// int tree_150[2] = {151, 154};
// int tree_151[2] = {152, 153};
// int tree_156[2] = {157, 158};
// int tree_158[2] = {159, 160};
// int tree_161[2] = {162, 191};
// int tree_162[2] = {163, 176};
// int tree_163[2] = {164, 165};
// int tree_165[2] = {166, 175};
// int tree_166[2] = {167, 174};
// int tree_167[2] = {168, 169};
// int tree_169[2] = {170, 173};
// int tree_170[2] = {171, 172};
// int tree_176[2] = {177, 190};
// int tree_177[2] = {178, 179};
// int tree_179[2] = {180, 187};
// int tree_180[2] = {181, 182};
// int tree_182[2] = {183, 184};
// int tree_184[2] = {185, 186};
// int tree_187[2] = {188, 189};
// int tree_191[2] = {192, 199};
// int tree_192[2] = {193, 196};
// int tree_193[2] = {194, 195};
// int tree_196[2] = {197, 198};
// int tree_200[2] = {201, 202};
// int tree_202[2] = {203, 212};
// int tree_203[2] = {204, 207};
// int tree_204[2] = {205, 206};
// int tree_207[2] = {208, 209};
// int tree_209[2] = {210, 211};
// int tree_212[2] = {213, 214};
//
// FixedNum *classProb1[LEN_TREE];
// FixedNum classProb1_4[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
// FixedNum classProb1_5[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_9[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_10[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_11[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_12[5] = {(FixedNum)0x00000000, (FixedNum)0x00000100, (FixedNum)0x00000000, (FixedNum)0x00000300, (FixedNum)0x00000000};
// FixedNum classProb1_15[5] = {(FixedNum)0x00000000, (FixedNum)0x00000005, (FixedNum)0x00000000, (FixedNum)0x000003fb, (FixedNum)0x00000000};
// FixedNum classProb1_20[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_22[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_24[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_27[5] = {(FixedNum)0x00000000, (FixedNum)0x000003a3, (FixedNum)0x00000000, (FixedNum)0x0000005d, (FixedNum)0x00000000};
// FixedNum classProb1_28[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_29[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_30[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_33[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_36[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_37[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_38[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_40[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_41[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_43[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_44[5] = {(FixedNum)0x00000000, (FixedNum)0x000003b7, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000049};
// FixedNum classProb1_46[5] = {(FixedNum)0x00000000, (FixedNum)0x00000066, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x0000039a};
// FixedNum classProb1_47[5] = {(FixedNum)0x00000000, (FixedNum)0x00000066, (FixedNum)0x00000000, (FixedNum)0x0000039a, (FixedNum)0x00000000};
// FixedNum classProb1_58[5] = {(FixedNum)0x00000000, (FixedNum)0x000003c0, (FixedNum)0x00000000, (FixedNum)0x00000040, (FixedNum)0x00000000};
// FixedNum classProb1_59[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_61[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_63[5] = {(FixedNum)0x00000000, (FixedNum)0x000000ab, (FixedNum)0x00000000, (FixedNum)0x00000355, (FixedNum)0x00000000};
// FixedNum classProb1_64[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_65[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_66[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_69[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_70[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_71[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_72[5] = {(FixedNum)0x00000000, (FixedNum)0x000003e9, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000017};
// FixedNum classProb1_74[5] = {(FixedNum)0x00000005, (FixedNum)0x000003ef, (FixedNum)0x00000000, (FixedNum)0x0000000c, (FixedNum)0x00000000};
// FixedNum classProb1_80[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_81[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_82[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_84[5] = {(FixedNum)0x000000cd, (FixedNum)0x00000333, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_85[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_86[5] = {(FixedNum)0x00000000, (FixedNum)0x000003df, (FixedNum)0x00000000, (FixedNum)0x00000010, (FixedNum)0x00000010};
// FixedNum classProb1_88[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
// FixedNum classProb1_90[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_92[5] = {(FixedNum)0x00000000, (FixedNum)0x000003c4, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x0000003c};
// FixedNum classProb1_94[5] = {(FixedNum)0x00000000, (FixedNum)0x00000092, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x0000036e};
// FixedNum classProb1_96[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_97[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
// FixedNum classProb1_100[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_102[5] = {(FixedNum)0x000003e2, (FixedNum)0x0000001e, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_104[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_108[5] = {(FixedNum)0x000003ab, (FixedNum)0x00000055, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_109[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_110[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
// FixedNum classProb1_111[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
// FixedNum classProb1_114[5] = {(FixedNum)0x00000000, (FixedNum)0x000003b1, (FixedNum)0x00000000, (FixedNum)0x0000004f, (FixedNum)0x00000000};
// FixedNum classProb1_116[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_118[5] = {(FixedNum)0x000003c0, (FixedNum)0x00000040, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_119[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_121[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_122[5] = {(FixedNum)0x00000026, (FixedNum)0x000003da, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_125[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_127[5] = {(FixedNum)0x00000000, (FixedNum)0x00000013, (FixedNum)0x0000000a, (FixedNum)0x00000000, (FixedNum)0x000003e3};
// FixedNum classProb1_130[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_131[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
// FixedNum classProb1_132[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_134[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
// FixedNum classProb1_135[5] = {(FixedNum)0x00000000, (FixedNum)0x0000039a, (FixedNum)0x00000000, (FixedNum)0x00000033, (FixedNum)0x00000033};
// FixedNum classProb1_138[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_140[5] = {(FixedNum)0x000002ab, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000155};
// FixedNum classProb1_141[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
// FixedNum classProb1_146[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_149[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_152[5] = {(FixedNum)0x00000333, (FixedNum)0x000000cd, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_153[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_154[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_155[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_157[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
// FixedNum classProb1_159[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_160[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_164[5] = {(FixedNum)0x000003e4, (FixedNum)0x00000000, (FixedNum)0x0000001c, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_168[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_171[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_172[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_173[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_174[5] = {(FixedNum)0x000003d1, (FixedNum)0x00000000, (FixedNum)0x0000002f, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_175[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_178[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_181[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_183[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_185[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_186[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_188[5] = {(FixedNum)0x00000092, (FixedNum)0x0000036e, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_189[5] = {(FixedNum)0x00000355, (FixedNum)0x000000ab, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_190[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_194[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
// FixedNum classProb1_195[5] = {(FixedNum)0x00000200, (FixedNum)0x00000000, (FixedNum)0x00000200, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_197[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_198[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_199[5] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_201[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_205[5] = {(FixedNum)0x000003c4, (FixedNum)0x00000000, (FixedNum)0x0000003c, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_206[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_208[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_210[5] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_211[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_213[5] = {(FixedNum)0x00000023, (FixedNum)0x00000000, (FixedNum)0x000003dd, (FixedNum)0x00000000, (FixedNum)0x00000000};
// FixedNum classProb1_214[5] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
//
//
// FixedNum getProbs(int i, int classIndex, FixedNum weight){
// 	if (m_attIndex[i] == -1){
// 		return fxp_mul(weight, classProb1[i][classIndex]);
// 	}
// 	int treeIndex = (instance[m_attIndex[i]] <= m_splitPoint[i] ? 0 : 1);
// 	return getProbs(tree[i][treeIndex], classIndex, weight);
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
// 	FixedNum doubles[NUM_CLASSES];
// 	for (int i = 0; i < NUM_CLASSES; i++){
// 		doubles[i] = getProbs(M_ROOT, i, (FixedNum)0x00000400);
// 	}
// 	int indMax = 0;
// 	for (int i = 1; i < NUM_CLASSES; i++){
// 		if (doubles[i] > doubles[indMax]){
// 			indMax = i;
// 		}
// 	}
// 	return indMax;
// }
//
// void initConnections(){
// 	tree[0] = tree_0;
// 	tree[1] = tree_1;
// 	tree[2] = tree_2;
// 	tree[3] = tree_3;
// 	tree[6] = tree_6;
// 	tree[7] = tree_7;
// 	tree[8] = tree_8;
// 	tree[13] = tree_13;
// 	tree[14] = tree_14;
// 	tree[16] = tree_16;
// 	tree[17] = tree_17;
// 	tree[18] = tree_18;
// 	tree[19] = tree_19;
// 	tree[21] = tree_21;
// 	tree[23] = tree_23;
// 	tree[25] = tree_25;
// 	tree[26] = tree_26;
// 	tree[31] = tree_31;
// 	tree[32] = tree_32;
// 	tree[34] = tree_34;
// 	tree[35] = tree_35;
// 	tree[39] = tree_39;
// 	tree[42] = tree_42;
// 	tree[45] = tree_45;
// 	tree[48] = tree_48;
// 	tree[49] = tree_49;
// 	tree[50] = tree_50;
// 	tree[51] = tree_51;
// 	tree[52] = tree_52;
// 	tree[53] = tree_53;
// 	tree[54] = tree_54;
// 	tree[55] = tree_55;
// 	tree[56] = tree_56;
// 	tree[57] = tree_57;
// 	tree[60] = tree_60;
// 	tree[62] = tree_62;
// 	tree[67] = tree_67;
// 	tree[68] = tree_68;
// 	tree[73] = tree_73;
// 	tree[75] = tree_75;
// 	tree[76] = tree_76;
// 	tree[77] = tree_77;
// 	tree[78] = tree_78;
// 	tree[79] = tree_79;
// 	tree[83] = tree_83;
// 	tree[87] = tree_87;
// 	tree[89] = tree_89;
// 	tree[91] = tree_91;
// 	tree[93] = tree_93;
// 	tree[95] = tree_95;
// 	tree[98] = tree_98;
// 	tree[99] = tree_99;
// 	tree[101] = tree_101;
// 	tree[103] = tree_103;
// 	tree[105] = tree_105;
// 	tree[106] = tree_106;
// 	tree[107] = tree_107;
// 	tree[112] = tree_112;
// 	tree[113] = tree_113;
// 	tree[115] = tree_115;
// 	tree[117] = tree_117;
// 	tree[120] = tree_120;
// 	tree[123] = tree_123;
// 	tree[124] = tree_124;
// 	tree[126] = tree_126;
// 	tree[128] = tree_128;
// 	tree[129] = tree_129;
// 	tree[133] = tree_133;
// 	tree[136] = tree_136;
// 	tree[137] = tree_137;
// 	tree[139] = tree_139;
// 	tree[142] = tree_142;
// 	tree[143] = tree_143;
// 	tree[144] = tree_144;
// 	tree[145] = tree_145;
// 	tree[147] = tree_147;
// 	tree[148] = tree_148;
// 	tree[150] = tree_150;
// 	tree[151] = tree_151;
// 	tree[156] = tree_156;
// 	tree[158] = tree_158;
// 	tree[161] = tree_161;
// 	tree[162] = tree_162;
// 	tree[163] = tree_163;
// 	tree[165] = tree_165;
// 	tree[166] = tree_166;
// 	tree[167] = tree_167;
// 	tree[169] = tree_169;
// 	tree[170] = tree_170;
// 	tree[176] = tree_176;
// 	tree[177] = tree_177;
// 	tree[179] = tree_179;
// 	tree[180] = tree_180;
// 	tree[182] = tree_182;
// 	tree[184] = tree_184;
// 	tree[187] = tree_187;
// 	tree[191] = tree_191;
// 	tree[192] = tree_192;
// 	tree[193] = tree_193;
// 	tree[196] = tree_196;
// 	tree[200] = tree_200;
// 	tree[202] = tree_202;
// 	tree[203] = tree_203;
// 	tree[204] = tree_204;
// 	tree[207] = tree_207;
// 	tree[209] = tree_209;
// 	tree[212] = tree_212;
//
// 	classProb1[4] = classProb1_4;
// 	classProb1[5] = classProb1_5;
// 	classProb1[9] = classProb1_9;
// 	classProb1[10] = classProb1_10;
// 	classProb1[11] = classProb1_11;
// 	classProb1[12] = classProb1_12;
// 	classProb1[15] = classProb1_15;
// 	classProb1[20] = classProb1_20;
// 	classProb1[22] = classProb1_22;
// 	classProb1[24] = classProb1_24;
// 	classProb1[27] = classProb1_27;
// 	classProb1[28] = classProb1_28;
// 	classProb1[29] = classProb1_29;
// 	classProb1[30] = classProb1_30;
// 	classProb1[33] = classProb1_33;
// 	classProb1[36] = classProb1_36;
// 	classProb1[37] = classProb1_37;
// 	classProb1[38] = classProb1_38;
// 	classProb1[40] = classProb1_40;
// 	classProb1[41] = classProb1_41;
// 	classProb1[43] = classProb1_43;
// 	classProb1[44] = classProb1_44;
// 	classProb1[46] = classProb1_46;
// 	classProb1[47] = classProb1_47;
// 	classProb1[58] = classProb1_58;
// 	classProb1[59] = classProb1_59;
// 	classProb1[61] = classProb1_61;
// 	classProb1[63] = classProb1_63;
// 	classProb1[64] = classProb1_64;
// 	classProb1[65] = classProb1_65;
// 	classProb1[66] = classProb1_66;
// 	classProb1[69] = classProb1_69;
// 	classProb1[70] = classProb1_70;
// 	classProb1[71] = classProb1_71;
// 	classProb1[72] = classProb1_72;
// 	classProb1[74] = classProb1_74;
// 	classProb1[80] = classProb1_80;
// 	classProb1[81] = classProb1_81;
// 	classProb1[82] = classProb1_82;
// 	classProb1[84] = classProb1_84;
// 	classProb1[85] = classProb1_85;
// 	classProb1[86] = classProb1_86;
// 	classProb1[88] = classProb1_88;
// 	classProb1[90] = classProb1_90;
// 	classProb1[92] = classProb1_92;
// 	classProb1[94] = classProb1_94;
// 	classProb1[96] = classProb1_96;
// 	classProb1[97] = classProb1_97;
// 	classProb1[100] = classProb1_100;
// 	classProb1[102] = classProb1_102;
// 	classProb1[104] = classProb1_104;
// 	classProb1[108] = classProb1_108;
// 	classProb1[109] = classProb1_109;
// 	classProb1[110] = classProb1_110;
// 	classProb1[111] = classProb1_111;
// 	classProb1[114] = classProb1_114;
// 	classProb1[116] = classProb1_116;
// 	classProb1[118] = classProb1_118;
// 	classProb1[119] = classProb1_119;
// 	classProb1[121] = classProb1_121;
// 	classProb1[122] = classProb1_122;
// 	classProb1[125] = classProb1_125;
// 	classProb1[127] = classProb1_127;
// 	classProb1[130] = classProb1_130;
// 	classProb1[131] = classProb1_131;
// 	classProb1[132] = classProb1_132;
// 	classProb1[134] = classProb1_134;
// 	classProb1[135] = classProb1_135;
// 	classProb1[138] = classProb1_138;
// 	classProb1[140] = classProb1_140;
// 	classProb1[141] = classProb1_141;
// 	classProb1[146] = classProb1_146;
// 	classProb1[149] = classProb1_149;
// 	classProb1[152] = classProb1_152;
// 	classProb1[153] = classProb1_153;
// 	classProb1[154] = classProb1_154;
// 	classProb1[155] = classProb1_155;
// 	classProb1[157] = classProb1_157;
// 	classProb1[159] = classProb1_159;
// 	classProb1[160] = classProb1_160;
// 	classProb1[164] = classProb1_164;
// 	classProb1[168] = classProb1_168;
// 	classProb1[171] = classProb1_171;
// 	classProb1[172] = classProb1_172;
// 	classProb1[173] = classProb1_173;
// 	classProb1[174] = classProb1_174;
// 	classProb1[175] = classProb1_175;
// 	classProb1[178] = classProb1_178;
// 	classProb1[181] = classProb1_181;
// 	classProb1[183] = classProb1_183;
// 	classProb1[185] = classProb1_185;
// 	classProb1[186] = classProb1_186;
// 	classProb1[188] = classProb1_188;
// 	classProb1[189] = classProb1_189;
// 	classProb1[190] = classProb1_190;
// 	classProb1[194] = classProb1_194;
// 	classProb1[195] = classProb1_195;
// 	classProb1[197] = classProb1_197;
// 	classProb1[198] = classProb1_198;
// 	classProb1[199] = classProb1_199;
// 	classProb1[201] = classProb1_201;
// 	classProb1[205] = classProb1_205;
// 	classProb1[206] = classProb1_206;
// 	classProb1[208] = classProb1_208;
// 	classProb1[210] = classProb1_210;
// 	classProb1[211] = classProb1_211;
// 	classProb1[213] = classProb1_213;
// 	classProb1[214] = classProb1_214;
// }
