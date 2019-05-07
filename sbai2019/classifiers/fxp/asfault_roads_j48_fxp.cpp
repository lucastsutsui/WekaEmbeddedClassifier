
#include <Arduino.h>
#define TOTAL_BITS 32
#define FIXED_FBITS 10
#define SIGNED
#include "FixedNum.h"

#define M_ROOT 0
#define NUM_CLASSES 4
#define CLASS_INDEX 64
#define LEN_TREE 171
#define INPUT_SIZE 64

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

int m_attIndex[LEN_TREE] = {8, 8, 0, 59, 61, 54, -1, 5, -1, -1, -1, -1, 23, 0, -1, 11, -1, -1, -1, 0, 59, 26, 11, 6, 25, -1, 25, 17, -1, -1, -1, -1, 20, 2, -1, -1, 40, -1, 46, -1, -1, -1, -1, 30, 62, -1, 46, -1, 0, -1, -1, 11, 62, 60, 7, 20, -1, 7, 0, 28, -1, 8, -1, 20, -1, 44, -1, -1, -1, -1, 39, 23, -1, -1, -1, 60, -1, 55, -1, -1, 23, 20, -1, 61, -1, 5, -1, 26, -1, -1, -1, 61, 52, -1, 33, -1, 28, 1, -1, 53, -1, -1, -1, 26, -1, -1, 24, 34, 8, 0, -1, 11, 23, 13, -1, 28, -1, 62, 44, 45, 1, 8, -1, -1, -1, -1, 40, 20, -1, -1, -1, -1, 53, -1, 34, 57, -1, -1, -1, -1, 61, 25, 17, -1, 40, -1, 0, -1, -1, 33, -1, 31, -1, 59, -1, -1, 6, -1, -1, 0, 13, 23, -1, -1, -1, 44, -1, 0, -1, -1, -1};

FixedNum m_splitPoint[LEN_TREE] = {(FixedNum)0x000000cc, (FixedNum)0x0000008d, (FixedNum)0x0000016b, (FixedNum)0x0000007c, (FixedNum)0x00000046, (FixedNum)0x0000001d, (FixedNum)0xfffffc00, (FixedNum)0x00000224, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000311, (FixedNum)0x000001e7, (FixedNum)0xfffffc00, (FixedNum)0x000000ec, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x0000024a, (FixedNum)0x00000103, (FixedNum)0x00000091, (FixedNum)0x000000ac, (FixedNum)0x00000299, (FixedNum)0x0000001c, (FixedNum)0xfffffc00, (FixedNum)0x0000031f, (FixedNum)0x000000bd, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000130, (FixedNum)0x0000005f, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000002c0, (FixedNum)0xfffffc00, (FixedNum)0x0000001f, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000001f8, (FixedNum)0x00000094, (FixedNum)0xfffffc00, (FixedNum)0x000000f5, (FixedNum)0xfffffc00, (FixedNum)0x00000359, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000000c5, (FixedNum)0x000000cc, (FixedNum)0x00000068, (FixedNum)0x0000025b, (FixedNum)0x0000020b, (FixedNum)0xfffffc00, (FixedNum)0x00000256, (FixedNum)0x0000037b, (FixedNum)0x0000019c, (FixedNum)0xfffffc00, (FixedNum)0x00000093, (FixedNum)0xfffffc00, (FixedNum)0x00000291, (FixedNum)0xfffffc00, (FixedNum)0x00000139, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000064, (FixedNum)0x0000038c, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x0000010b, (FixedNum)0xfffffc00, (FixedNum)0x00000050, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000388, (FixedNum)0x00000129, (FixedNum)0xfffffc00, (FixedNum)0x00000057, (FixedNum)0xfffffc00, (FixedNum)0x00000120, (FixedNum)0xfffffc00, (FixedNum)0x0000008f, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000056, (FixedNum)0x0000000d, (FixedNum)0xfffffc00, (FixedNum)0x00000112, (FixedNum)0xfffffc00, (FixedNum)0x00000201, (FixedNum)0x00000029, (FixedNum)0xfffffc00, (FixedNum)0x00000033, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000035, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x0000026e, (FixedNum)0x000000d5, (FixedNum)0x000000f6, (FixedNum)0x00000288, (FixedNum)0xfffffc00, (FixedNum)0x000000f0, (FixedNum)0x00000340, (FixedNum)0x000000a3, (FixedNum)0xfffffc00, (FixedNum)0x0000013e, (FixedNum)0xfffffc00, (FixedNum)0x000000d6, (FixedNum)0x000001c7, (FixedNum)0x000001be, (FixedNum)0x0000002e, (FixedNum)0x000000d1, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000220, (FixedNum)0x000001bd, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000034, (FixedNum)0xfffffc00, (FixedNum)0x0000008f, (FixedNum)0x0000002b, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x0000012d, (FixedNum)0x00000004, (FixedNum)0x00000096, (FixedNum)0xfffffc00, (FixedNum)0x00000280, (FixedNum)0xfffffc00, (FixedNum)0x000002aa, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000325, (FixedNum)0xfffffc00, (FixedNum)0x000002a2, (FixedNum)0xfffffc00, (FixedNum)0x0000004d, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000252, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000002e6, (FixedNum)0x000001be, (FixedNum)0x00000296, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x0000028e, (FixedNum)0xfffffc00, (FixedNum)0x00000331, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00};

const int *tree[LEN_TREE];
int tree_0[2] = {1, 106};
int tree_1[2] = {2, 19};
int tree_2[2] = {3, 12};
int tree_3[2] = {4, 11};
int tree_4[2] = {5, 10};
int tree_5[2] = {6, 7};
int tree_7[2] = {8, 9};
int tree_12[2] = {13, 18};
int tree_13[2] = {14, 15};
int tree_15[2] = {16, 17};
int tree_19[2] = {20, 43};
int tree_20[2] = {21, 42};
int tree_21[2] = {22, 41};
int tree_22[2] = {23, 32};
int tree_23[2] = {24, 31};
int tree_24[2] = {25, 26};
int tree_26[2] = {27, 30};
int tree_27[2] = {28, 29};
int tree_32[2] = {33, 36};
int tree_33[2] = {34, 35};
int tree_36[2] = {37, 38};
int tree_38[2] = {39, 40};
int tree_43[2] = {44, 51};
int tree_44[2] = {45, 46};
int tree_46[2] = {47, 48};
int tree_48[2] = {49, 50};
int tree_51[2] = {52, 91};
int tree_52[2] = {53, 80};
int tree_53[2] = {54, 75};
int tree_54[2] = {55, 70};
int tree_55[2] = {56, 57};
int tree_57[2] = {58, 69};
int tree_58[2] = {59, 68};
int tree_59[2] = {60, 61};
int tree_61[2] = {62, 63};
int tree_63[2] = {64, 65};
int tree_65[2] = {66, 67};
int tree_70[2] = {71, 74};
int tree_71[2] = {72, 73};
int tree_75[2] = {76, 77};
int tree_77[2] = {78, 79};
int tree_80[2] = {81, 90};
int tree_81[2] = {82, 83};
int tree_83[2] = {84, 85};
int tree_85[2] = {86, 87};
int tree_87[2] = {88, 89};
int tree_91[2] = {92, 103};
int tree_92[2] = {93, 94};
int tree_94[2] = {95, 96};
int tree_96[2] = {97, 102};
int tree_97[2] = {98, 99};
int tree_99[2] = {100, 101};
int tree_103[2] = {104, 105};
int tree_106[2] = {107, 170};
int tree_107[2] = {108, 159};
int tree_108[2] = {109, 140};
int tree_109[2] = {110, 111};
int tree_111[2] = {112, 139};
int tree_112[2] = {113, 132};
int tree_113[2] = {114, 115};
int tree_115[2] = {116, 117};
int tree_117[2] = {118, 131};
int tree_118[2] = {119, 126};
int tree_119[2] = {120, 125};
int tree_120[2] = {121, 124};
int tree_121[2] = {122, 123};
int tree_126[2] = {127, 130};
int tree_127[2] = {128, 129};
int tree_132[2] = {133, 134};
int tree_134[2] = {135, 138};
int tree_135[2] = {136, 137};
int tree_140[2] = {141, 156};
int tree_141[2] = {142, 149};
int tree_142[2] = {143, 144};
int tree_144[2] = {145, 146};
int tree_146[2] = {147, 148};
int tree_149[2] = {150, 151};
int tree_151[2] = {152, 153};
int tree_153[2] = {154, 155};
int tree_156[2] = {157, 158};
int tree_159[2] = {160, 165};
int tree_160[2] = {161, 164};
int tree_161[2] = {162, 163};
int tree_165[2] = {166, 167};
int tree_167[2] = {168, 169};

FixedNum *classProb1[LEN_TREE];
FixedNum classProb1_6[4] = {(FixedNum)0x00000000, (FixedNum)0x0000000c, (FixedNum)0x000003f4, (FixedNum)0x00000000};
FixedNum classProb1_8[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_9[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_10[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_11[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_14[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_16[4] = {(FixedNum)0x00000000, (FixedNum)0x00000012, (FixedNum)0x000003ee, (FixedNum)0x00000000};
FixedNum classProb1_17[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_18[4] = {(FixedNum)0x00000000, (FixedNum)0x00000004, (FixedNum)0x000003fc, (FixedNum)0x00000000};
FixedNum classProb1_25[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_28[4] = {(FixedNum)0x00000000, (FixedNum)0x0000039a, (FixedNum)0x00000066, (FixedNum)0x00000000};
FixedNum classProb1_29[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_30[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_31[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_34[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_35[4] = {(FixedNum)0x00000000, (FixedNum)0x00000300, (FixedNum)0x00000100, (FixedNum)0x00000000};
FixedNum classProb1_37[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_39[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_40[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_41[4] = {(FixedNum)0x000002ab, (FixedNum)0x00000155, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_42[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_45[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_47[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_49[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_50[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_56[4] = {(FixedNum)0x00000000, (FixedNum)0x00000076, (FixedNum)0x0000038a, (FixedNum)0x00000000};
FixedNum classProb1_60[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_62[4] = {(FixedNum)0x00000000, (FixedNum)0x00000080, (FixedNum)0x00000380, (FixedNum)0x00000000};
FixedNum classProb1_64[4] = {(FixedNum)0x00000000, (FixedNum)0x000003c0, (FixedNum)0x00000040, (FixedNum)0x00000000};
FixedNum classProb1_66[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_67[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_68[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_69[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_72[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_73[4] = {(FixedNum)0x00000000, (FixedNum)0x00000333, (FixedNum)0x000000cd, (FixedNum)0x00000000};
FixedNum classProb1_74[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_76[4] = {(FixedNum)0x00000000, (FixedNum)0x00000017, (FixedNum)0x000003e9, (FixedNum)0x00000000};
FixedNum classProb1_78[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_79[4] = {(FixedNum)0x00000000, (FixedNum)0x00000355, (FixedNum)0x000000ab, (FixedNum)0x00000000};
FixedNum classProb1_82[4] = {(FixedNum)0x00000000, (FixedNum)0x00000055, (FixedNum)0x000003ab, (FixedNum)0x00000000};
FixedNum classProb1_84[4] = {(FixedNum)0x00000000, (FixedNum)0x00000080, (FixedNum)0x00000380, (FixedNum)0x00000000};
FixedNum classProb1_86[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_88[4] = {(FixedNum)0x00000000, (FixedNum)0x000003c4, (FixedNum)0x0000003c, (FixedNum)0x00000000};
FixedNum classProb1_89[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_90[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_93[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_95[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_98[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_100[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_101[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_102[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_104[4] = {(FixedNum)0x00000000, (FixedNum)0x00000155, (FixedNum)0x000002ab, (FixedNum)0x00000000};
FixedNum classProb1_105[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_110[4] = {(FixedNum)0x00000017, (FixedNum)0x000003a5, (FixedNum)0x0000002e, (FixedNum)0x00000017};
FixedNum classProb1_114[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_116[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_122[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_123[4] = {(FixedNum)0x00000000, (FixedNum)0x00000380, (FixedNum)0x00000080, (FixedNum)0x00000000};
FixedNum classProb1_124[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_125[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_128[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_129[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_130[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_131[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_133[4] = {(FixedNum)0x00000000, (FixedNum)0x00000115, (FixedNum)0x000002eb, (FixedNum)0x00000000};
FixedNum classProb1_136[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_137[4] = {(FixedNum)0x00000000, (FixedNum)0x0000039e, (FixedNum)0x00000062, (FixedNum)0x00000000};
FixedNum classProb1_138[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_139[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_143[4] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_145[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_147[4] = {(FixedNum)0x00000333, (FixedNum)0x000000cd, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_148[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_150[4] = {(FixedNum)0x0000000d, (FixedNum)0x000003e3, (FixedNum)0x00000011, (FixedNum)0x00000000};
FixedNum classProb1_152[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_154[4] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_155[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_157[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_158[4] = {(FixedNum)0x000003a3, (FixedNum)0x0000005d, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_162[4] = {(FixedNum)0x00000355, (FixedNum)0x000000ab, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_163[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_164[4] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_166[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_168[4] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_169[4] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_170[4] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};


FixedNum getProbs(int i, int classIndex, FixedNum weight){
	if (m_attIndex[i] == -1){
		return fxp_mul(weight, classProb1[i][classIndex]);
	}
	int treeIndex = (instance[m_attIndex[i]] <= m_splitPoint[i] ? 0 : 1);
	return getProbs(tree[i][treeIndex], classIndex, weight);
}

/* Function classify description:
 * Instance array must be initializated, with appropriated attributes, before calling this function
 * Output number 0 means that the instance was classified as ruim
 * Output number 1 means that the instance was classified as regular
 * Output number 2 means that the instance was classified as bom
 * Output number 3 means that the instance was classified as obstaculos
 */
int classify(){
	FixedNum doubles[NUM_CLASSES];
	for (int i = 0; i < NUM_CLASSES; i++){
		doubles[i] = getProbs(M_ROOT, i, (FixedNum)0x00000400);
	}
	int indMax = 0;
	for (int i = 1; i < NUM_CLASSES; i++){
		if (doubles[i] > doubles[indMax]){
			indMax = i;
		}
	}
	return indMax;
}

void initConnections(){
	tree[0] = tree_0;
	tree[1] = tree_1;
	tree[2] = tree_2;
	tree[3] = tree_3;
	tree[4] = tree_4;
	tree[5] = tree_5;
	tree[7] = tree_7;
	tree[12] = tree_12;
	tree[13] = tree_13;
	tree[15] = tree_15;
	tree[19] = tree_19;
	tree[20] = tree_20;
	tree[21] = tree_21;
	tree[22] = tree_22;
	tree[23] = tree_23;
	tree[24] = tree_24;
	tree[26] = tree_26;
	tree[27] = tree_27;
	tree[32] = tree_32;
	tree[33] = tree_33;
	tree[36] = tree_36;
	tree[38] = tree_38;
	tree[43] = tree_43;
	tree[44] = tree_44;
	tree[46] = tree_46;
	tree[48] = tree_48;
	tree[51] = tree_51;
	tree[52] = tree_52;
	tree[53] = tree_53;
	tree[54] = tree_54;
	tree[55] = tree_55;
	tree[57] = tree_57;
	tree[58] = tree_58;
	tree[59] = tree_59;
	tree[61] = tree_61;
	tree[63] = tree_63;
	tree[65] = tree_65;
	tree[70] = tree_70;
	tree[71] = tree_71;
	tree[75] = tree_75;
	tree[77] = tree_77;
	tree[80] = tree_80;
	tree[81] = tree_81;
	tree[83] = tree_83;
	tree[85] = tree_85;
	tree[87] = tree_87;
	tree[91] = tree_91;
	tree[92] = tree_92;
	tree[94] = tree_94;
	tree[96] = tree_96;
	tree[97] = tree_97;
	tree[99] = tree_99;
	tree[103] = tree_103;
	tree[106] = tree_106;
	tree[107] = tree_107;
	tree[108] = tree_108;
	tree[109] = tree_109;
	tree[111] = tree_111;
	tree[112] = tree_112;
	tree[113] = tree_113;
	tree[115] = tree_115;
	tree[117] = tree_117;
	tree[118] = tree_118;
	tree[119] = tree_119;
	tree[120] = tree_120;
	tree[121] = tree_121;
	tree[126] = tree_126;
	tree[127] = tree_127;
	tree[132] = tree_132;
	tree[134] = tree_134;
	tree[135] = tree_135;
	tree[140] = tree_140;
	tree[141] = tree_141;
	tree[142] = tree_142;
	tree[144] = tree_144;
	tree[146] = tree_146;
	tree[149] = tree_149;
	tree[151] = tree_151;
	tree[153] = tree_153;
	tree[156] = tree_156;
	tree[159] = tree_159;
	tree[160] = tree_160;
	tree[161] = tree_161;
	tree[165] = tree_165;
	tree[167] = tree_167;

	classProb1[6] = classProb1_6;
	classProb1[8] = classProb1_8;
	classProb1[9] = classProb1_9;
	classProb1[10] = classProb1_10;
	classProb1[11] = classProb1_11;
	classProb1[14] = classProb1_14;
	classProb1[16] = classProb1_16;
	classProb1[17] = classProb1_17;
	classProb1[18] = classProb1_18;
	classProb1[25] = classProb1_25;
	classProb1[28] = classProb1_28;
	classProb1[29] = classProb1_29;
	classProb1[30] = classProb1_30;
	classProb1[31] = classProb1_31;
	classProb1[34] = classProb1_34;
	classProb1[35] = classProb1_35;
	classProb1[37] = classProb1_37;
	classProb1[39] = classProb1_39;
	classProb1[40] = classProb1_40;
	classProb1[41] = classProb1_41;
	classProb1[42] = classProb1_42;
	classProb1[45] = classProb1_45;
	classProb1[47] = classProb1_47;
	classProb1[49] = classProb1_49;
	classProb1[50] = classProb1_50;
	classProb1[56] = classProb1_56;
	classProb1[60] = classProb1_60;
	classProb1[62] = classProb1_62;
	classProb1[64] = classProb1_64;
	classProb1[66] = classProb1_66;
	classProb1[67] = classProb1_67;
	classProb1[68] = classProb1_68;
	classProb1[69] = classProb1_69;
	classProb1[72] = classProb1_72;
	classProb1[73] = classProb1_73;
	classProb1[74] = classProb1_74;
	classProb1[76] = classProb1_76;
	classProb1[78] = classProb1_78;
	classProb1[79] = classProb1_79;
	classProb1[82] = classProb1_82;
	classProb1[84] = classProb1_84;
	classProb1[86] = classProb1_86;
	classProb1[88] = classProb1_88;
	classProb1[89] = classProb1_89;
	classProb1[90] = classProb1_90;
	classProb1[93] = classProb1_93;
	classProb1[95] = classProb1_95;
	classProb1[98] = classProb1_98;
	classProb1[100] = classProb1_100;
	classProb1[101] = classProb1_101;
	classProb1[102] = classProb1_102;
	classProb1[104] = classProb1_104;
	classProb1[105] = classProb1_105;
	classProb1[110] = classProb1_110;
	classProb1[114] = classProb1_114;
	classProb1[116] = classProb1_116;
	classProb1[122] = classProb1_122;
	classProb1[123] = classProb1_123;
	classProb1[124] = classProb1_124;
	classProb1[125] = classProb1_125;
	classProb1[128] = classProb1_128;
	classProb1[129] = classProb1_129;
	classProb1[130] = classProb1_130;
	classProb1[131] = classProb1_131;
	classProb1[133] = classProb1_133;
	classProb1[136] = classProb1_136;
	classProb1[137] = classProb1_137;
	classProb1[138] = classProb1_138;
	classProb1[139] = classProb1_139;
	classProb1[143] = classProb1_143;
	classProb1[145] = classProb1_145;
	classProb1[147] = classProb1_147;
	classProb1[148] = classProb1_148;
	classProb1[150] = classProb1_150;
	classProb1[152] = classProb1_152;
	classProb1[154] = classProb1_154;
	classProb1[155] = classProb1_155;
	classProb1[157] = classProb1_157;
	classProb1[158] = classProb1_158;
	classProb1[162] = classProb1_162;
	classProb1[163] = classProb1_163;
	classProb1[164] = classProb1_164;
	classProb1[166] = classProb1_166;
	classProb1[168] = classProb1_168;
	classProb1[169] = classProb1_169;
	classProb1[170] = classProb1_170;
}
