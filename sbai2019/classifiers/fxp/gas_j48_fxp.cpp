
#include <Arduino.h>
#define TOTAL_BITS 32
#define FIXED_FBITS 10
#define SIGNED
#include "FixedNum.h"

#define M_ROOT 0
#define NUM_CLASSES 6
#define CLASS_INDEX 128
#define LEN_TREE 315
#define INPUT_SIZE 128

/* Instance array must be global
 * Attributes MUST be sorted in instance array in the following order:
 * V1
 * V2
 * V3
 * V4
 * V5
 * V6
 * V7
 * V8
 * V9
 * V10
 * V11
 * V12
 * V13
 * V14
 * V15
 * V16
 * V17
 * V18
 * V19
 * V20
 * V21
 * V22
 * V23
 * V24
 * V25
 * V26
 * V27
 * V28
 * V29
 * V30
 * V31
 * V32
 * V33
 * V34
 * V35
 * V36
 * V37
 * V38
 * V39
 * V40
 * V41
 * V42
 * V43
 * V44
 * V45
 * V46
 * V47
 * V48
 * V49
 * V50
 * V51
 * V52
 * V53
 * V54
 * V55
 * V56
 * V57
 * V58
 * V59
 * V60
 * V61
 * V62
 * V63
 * V64
 * V65
 * V66
 * V67
 * V68
 * V69
 * V70
 * V71
 * V72
 * V73
 * V74
 * V75
 * V76
 * V77
 * V78
 * V79
 * V80
 * V81
 * V82
 * V83
 * V84
 * V85
 * V86
 * V87
 * V88
 * V89
 * V90
 * V91
 * V92
 * V93
 * V94
 * V95
 * V96
 * V97
 * V98
 * V99
 * V100
 * V101
 * V102
 * V103
 * V104
 * V105
 * V106
 * V107
 * V108
 * V109
 * V110
 * V111
 * V112
 * V113
 * V114
 * V115
 * V116
 * V117
 * V118
 * V119
 * V120
 * V121
 * V122
 * V123
 * V124
 * V125
 * V126
 * V127
 * V128
 */
FixedNum instance[INPUT_SIZE+1];

int m_attIndex[LEN_TREE] = {68, 115, 25, 67, 32, 115, 29, -1, -1, -1, -1, 111, 75, 10, 49, -1, -1, -1, 33, -1, -1, 19, 0, -1, -1, 42, -1, -1, 104, 81, -1, 0, 105, 85, 17, 0, -1, -1, 103, 73, -1, -1, -1, 32, 93, -1, -1, -1, 19, -1, -1, 0, -1, -1, 112, 37, -1, 0, -1, -1, 96, -1, -1, 42, 17, 2, -1, -1, -1, 3, -1, 0, -1, -1, 107, 15, 8, 35, 97, 57, -1, 102, 72, -1, 8, -1, -1, 110, 68, -1, -1, -1, 25, -1, -1, 17, 76, 38, -1, 19, -1, -1, 37, -1, -1, -1, 112, 9, -1, -1, 77, 9, -1, -1, 15, 1, 0, -1, -1, 13, -1, 50, -1, -1, 17, -1, 0, -1, -1, 28, 100, 33, 35, 67, 29, 6, -1, -1, -1, 16, -1, 121, 9, 0, -1, -1, -1, 8, -1, 2, -1, -1, 76, 89, 11, 24, 99, 10, 123, 113, -1, 41, 9, -1, 73, -1, -1, 17, -1, -1, -1, 75, 16, 75, 76, 11, 123, -1, 76, -1, -1, -1, 8, -1, 0, -1, -1, 8, -1, -1, 8, -1, 35, -1, -1, 0, -1, -1, 45, 0, -1, -1, -1, 34, -1, 70, -1, -1, -1, 96, -1, 83, 0, -1, -1, -1, 32, 10, 35, -1, -1, -1, 7, 27, -1, 103, 5, 68, 11, 18, 6, -1, -1, 8, 70, -1, -1, -1, 0, -1, -1, 23, -1, -1, 8, -1, -1, 0, -1, -1, -1, 78, -1, 1, 53, -1, -1, 5, -1, -1, 26, 69, 123, -1, 99, 1, -1, -1, 28, 18, -1, -1, -1, 0, -1, -1, 41, -1, 0, -1, -1, 8, 104, 30, 1, -1, 0, -1, -1, 1, -1, -1, -1, -1, 83, 116, 22, -1, -1, 26, 12, -1, 1, 2, -1, -1, -1, 0, -1, -1, 16, 9, -1, -1, -1};

FixedNum m_splitPoint[LEN_TREE] = {(FixedNum)0x0000205a, (FixedNum)0x00006195, (FixedNum)0x00000821, (FixedNum)0x000008b4, (FixedNum)0x000ae996, (FixedNum)0x00000746, (FixedNum)0xfffffe53, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffff461, (FixedNum)0x00000c59, (FixedNum)0x00000af5, (FixedNum)0x00000496, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000714, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000720, (FixedNum)0x01581908, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000360, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x003ea5c3, (FixedNum)0x0000088c, (FixedNum)0xfffffc00, (FixedNum)0x010952e0, (FixedNum)0x00000ffe, (FixedNum)0xfffffb73, (FixedNum)0x00000ba4, (FixedNum)0x000dcf66, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xffffef08, (FixedNum)0x0000068a, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00146c54, (FixedNum)0xffffff2b, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00001044, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x0279e957, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x012749a2, (FixedNum)0xfffffe5e, (FixedNum)0xfffffc00, (FixedNum)0x00cb2748, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x005e99ee, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000b71, (FixedNum)0x0000115c, (FixedNum)0x00000aca, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00001613, (FixedNum)0xfffffc00, (FixedNum)0x00cc5978, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00001f13, (FixedNum)0xffff1e1a, (FixedNum)0x04db29d7, (FixedNum)0x00000aad, (FixedNum)0x00000c41, (FixedNum)0x000007e4, (FixedNum)0xfffffc00, (FixedNum)0xfffffa50, (FixedNum)0x018aa1dc, (FixedNum)0xfffffc00, (FixedNum)0x03391840, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffb57, (FixedNum)0x0000549c, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000015c3, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000027bb, (FixedNum)0x00008294, (FixedNum)0xfffff98b, (FixedNum)0xfffffc00, (FixedNum)0x000026eb, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffe20, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x0097dddd, (FixedNum)0x00001d22, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xffff78bc, (FixedNum)0x0000276e, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffedf3c, (FixedNum)0x00000a0a, (FixedNum)0x0000fffd, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xffffb1f1, (FixedNum)0xfffffc00, (FixedNum)0x00002b6b, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000017db, (FixedNum)0xfffffc00, (FixedNum)0x064e280a, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00004625, (FixedNum)0x00002290, (FixedNum)0x00001000, (FixedNum)0x000004ed, (FixedNum)0x00000d76, (FixedNum)0xffffff20, (FixedNum)0xfffffc41, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x002a0346, (FixedNum)0xfffffc00, (FixedNum)0x0000112d, (FixedNum)0x000007ed, (FixedNum)0x006b6baa, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x038e18f9, (FixedNum)0xfffffc00, (FixedNum)0x000062dd, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00003e28, (FixedNum)0x000013ee, (FixedNum)0x00006845, (FixedNum)0x008deb65, (FixedNum)0x00001103, (FixedNum)0x00001671, (FixedNum)0x00001c66, (FixedNum)0x00000475, (FixedNum)0xfffffc00, (FixedNum)0x00000854, (FixedNum)0x00001259, (FixedNum)0xfffffc00, (FixedNum)0x00000d22, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000852, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000023a8, (FixedNum)0x006d7f43, (FixedNum)0x00001f06, (FixedNum)0x00003727, (FixedNum)0x00002efa, (FixedNum)0x0000157f, (FixedNum)0xfffffc00, (FixedNum)0x00001c9d, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x01f760ff, (FixedNum)0xfffffc00, (FixedNum)0x00e01e7d, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x025e32cc, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x0253feb8, (FixedNum)0xfffffc00, (FixedNum)0x0000067d, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x026984f0, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffddb, (FixedNum)0x00c6f6e4, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000002ab, (FixedNum)0xfffffc00, (FixedNum)0xffffed1b, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x003a824a, (FixedNum)0xfffffc00, (FixedNum)0x000018cc, (FixedNum)0x02951a67, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x001e71fd, (FixedNum)0x000020b6, (FixedNum)0x000006e8, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xffffefdd, (FixedNum)0x00000b26, (FixedNum)0xfffffc00, (FixedNum)0xfffff5da, (FixedNum)0xfffffbd3, (FixedNum)0x000086f6, (FixedNum)0x0000a9e1, (FixedNum)0x00000711, (FixedNum)0xffffde97, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x024b6d1a, (FixedNum)0xffffd0e9, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x04d2306d, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xffffdb85, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x037ed3ce, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x06009d7b, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xffffc2f5, (FixedNum)0xfffffc00, (FixedNum)0x0000201e, (FixedNum)0xfffff1c6, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffff75b, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x000017f2, (FixedNum)0xfffffe80, (FixedNum)0x0000296e, (FixedNum)0xfffffc00, (FixedNum)0x0000136e, (FixedNum)0x00001cc0, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00002510, (FixedNum)0x000011b5, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x012f289a, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x0000104e, (FixedNum)0xfffffc00, (FixedNum)0x03c2b304, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x08add7d0, (FixedNum)0x0080927c, (FixedNum)0xffffe443, (FixedNum)0x00002edc, (FixedNum)0xfffffc00, (FixedNum)0x037cd73a, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00000945, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00006f28, (FixedNum)0x00006a04, (FixedNum)0xffffe186, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x00003130, (FixedNum)0x0001299a, (FixedNum)0xfffffc00, (FixedNum)0x00002ca5, (FixedNum)0x0000a4ae, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x03e0466a, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0x03476190, (FixedNum)0x000045c9, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00, (FixedNum)0xfffffc00};

const int *tree[LEN_TREE];
int tree_0[2] = {1, 74};
int tree_1[2] = {2, 63};
int tree_2[2] = {3, 28};
int tree_3[2] = {4, 11};
int tree_4[2] = {5, 10};
int tree_5[2] = {6, 9};
int tree_6[2] = {7, 8};
int tree_11[2] = {12, 21};
int tree_12[2] = {13, 18};
int tree_13[2] = {14, 17};
int tree_14[2] = {15, 16};
int tree_18[2] = {19, 20};
int tree_21[2] = {22, 25};
int tree_22[2] = {23, 24};
int tree_25[2] = {26, 27};
int tree_28[2] = {29, 54};
int tree_29[2] = {30, 31};
int tree_31[2] = {32, 51};
int tree_32[2] = {33, 48};
int tree_33[2] = {34, 43};
int tree_34[2] = {35, 38};
int tree_35[2] = {36, 37};
int tree_38[2] = {39, 42};
int tree_39[2] = {40, 41};
int tree_43[2] = {44, 47};
int tree_44[2] = {45, 46};
int tree_48[2] = {49, 50};
int tree_51[2] = {52, 53};
int tree_54[2] = {55, 60};
int tree_55[2] = {56, 57};
int tree_57[2] = {58, 59};
int tree_60[2] = {61, 62};
int tree_63[2] = {64, 69};
int tree_64[2] = {65, 68};
int tree_65[2] = {66, 67};
int tree_69[2] = {70, 71};
int tree_71[2] = {72, 73};
int tree_74[2] = {75, 294};
int tree_75[2] = {76, 129};
int tree_76[2] = {77, 106};
int tree_77[2] = {78, 95};
int tree_78[2] = {79, 92};
int tree_79[2] = {80, 81};
int tree_81[2] = {82, 87};
int tree_82[2] = {83, 84};
int tree_84[2] = {85, 86};
int tree_87[2] = {88, 91};
int tree_88[2] = {89, 90};
int tree_92[2] = {93, 94};
int tree_95[2] = {96, 105};
int tree_96[2] = {97, 102};
int tree_97[2] = {98, 99};
int tree_99[2] = {100, 101};
int tree_102[2] = {103, 104};
int tree_106[2] = {107, 110};
int tree_107[2] = {108, 109};
int tree_110[2] = {111, 114};
int tree_111[2] = {112, 113};
int tree_114[2] = {115, 124};
int tree_115[2] = {116, 119};
int tree_116[2] = {117, 118};
int tree_119[2] = {120, 121};
int tree_121[2] = {122, 123};
int tree_124[2] = {125, 126};
int tree_126[2] = {127, 128};
int tree_129[2] = {130, 281};
int tree_130[2] = {131, 260};
int tree_131[2] = {132, 251};
int tree_132[2] = {133, 152};
int tree_133[2] = {134, 139};
int tree_134[2] = {135, 138};
int tree_135[2] = {136, 137};
int tree_139[2] = {140, 141};
int tree_141[2] = {142, 147};
int tree_142[2] = {143, 146};
int tree_143[2] = {144, 145};
int tree_147[2] = {148, 149};
int tree_149[2] = {150, 151};
int tree_152[2] = {153, 216};
int tree_153[2] = {154, 209};
int tree_154[2] = {155, 208};
int tree_155[2] = {156, 203};
int tree_156[2] = {157, 198};
int tree_157[2] = {158, 171};
int tree_158[2] = {159, 170};
int tree_159[2] = {160, 161};
int tree_161[2] = {162, 167};
int tree_162[2] = {163, 164};
int tree_164[2] = {165, 166};
int tree_167[2] = {168, 169};
int tree_171[2] = {172, 195};
int tree_172[2] = {173, 190};
int tree_173[2] = {174, 187};
int tree_174[2] = {175, 182};
int tree_175[2] = {176, 181};
int tree_176[2] = {177, 178};
int tree_178[2] = {179, 180};
int tree_182[2] = {183, 184};
int tree_184[2] = {185, 186};
int tree_187[2] = {188, 189};
int tree_190[2] = {191, 192};
int tree_192[2] = {193, 194};
int tree_195[2] = {196, 197};
int tree_198[2] = {199, 202};
int tree_199[2] = {200, 201};
int tree_203[2] = {204, 205};
int tree_205[2] = {206, 207};
int tree_209[2] = {210, 211};
int tree_211[2] = {212, 215};
int tree_212[2] = {213, 214};
int tree_216[2] = {217, 222};
int tree_217[2] = {218, 221};
int tree_218[2] = {219, 220};
int tree_222[2] = {223, 250};
int tree_223[2] = {224, 225};
int tree_225[2] = {226, 247};
int tree_226[2] = {227, 244};
int tree_227[2] = {228, 241};
int tree_228[2] = {229, 238};
int tree_229[2] = {230, 233};
int tree_230[2] = {231, 232};
int tree_233[2] = {234, 237};
int tree_234[2] = {235, 236};
int tree_238[2] = {239, 240};
int tree_241[2] = {242, 243};
int tree_244[2] = {245, 246};
int tree_247[2] = {248, 249};
int tree_251[2] = {252, 253};
int tree_253[2] = {254, 257};
int tree_254[2] = {255, 256};
int tree_257[2] = {258, 259};
int tree_260[2] = {261, 276};
int tree_261[2] = {262, 273};
int tree_262[2] = {263, 264};
int tree_264[2] = {265, 268};
int tree_265[2] = {266, 267};
int tree_268[2] = {269, 272};
int tree_269[2] = {270, 271};
int tree_273[2] = {274, 275};
int tree_276[2] = {277, 278};
int tree_278[2] = {279, 280};
int tree_281[2] = {282, 293};
int tree_282[2] = {283, 292};
int tree_283[2] = {284, 289};
int tree_284[2] = {285, 286};
int tree_286[2] = {287, 288};
int tree_289[2] = {290, 291};
int tree_294[2] = {295, 310};
int tree_295[2] = {296, 299};
int tree_296[2] = {297, 298};
int tree_299[2] = {300, 307};
int tree_300[2] = {301, 302};
int tree_302[2] = {303, 306};
int tree_303[2] = {304, 305};
int tree_307[2] = {308, 309};
int tree_310[2] = {311, 314};
int tree_311[2] = {312, 313};

FixedNum *classProb1[LEN_TREE];
FixedNum classProb1_7[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x000000cd, (FixedNum)0x00000000, (FixedNum)0x00000333, (FixedNum)0x00000000};
FixedNum classProb1_8[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_9[6] = {(FixedNum)0x00000000, (FixedNum)0x000003f3, (FixedNum)0x0000000d, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_10[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_15[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_16[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_17[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_19[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_20[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_23[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_24[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_26[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_27[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_30[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_36[6] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_37[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_40[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_41[6] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_42[6] = {(FixedNum)0x00000003, (FixedNum)0x000003f7, (FixedNum)0x00000003, (FixedNum)0x00000000, (FixedNum)0x00000003, (FixedNum)0x00000000};
FixedNum classProb1_45[6] = {(FixedNum)0x00000000, (FixedNum)0x000003e6, (FixedNum)0x0000000d, (FixedNum)0x0000000d, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_46[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_47[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x000003de, (FixedNum)0x00000000, (FixedNum)0x00000022, (FixedNum)0x00000000};
FixedNum classProb1_49[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_50[6] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_52[6] = {(FixedNum)0x000003b7, (FixedNum)0x00000049, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_53[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x000002ab, (FixedNum)0x00000155};
FixedNum classProb1_56[6] = {(FixedNum)0x00000000, (FixedNum)0x00000001, (FixedNum)0x000003ff, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_58[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_59[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_61[6] = {(FixedNum)0x00000000, (FixedNum)0x000003f1, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x0000000f, (FixedNum)0x00000000};
FixedNum classProb1_62[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_66[6] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_67[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_68[6] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_70[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_72[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_73[6] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_80[6] = {(FixedNum)0x000000ab, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000355};
FixedNum classProb1_83[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_85[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_86[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_89[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x000002ab, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000155};
FixedNum classProb1_90[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_91[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_93[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_94[6] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_98[6] = {(FixedNum)0x00000000, (FixedNum)0x00000018, (FixedNum)0x00000000, (FixedNum)0x000003e8, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_100[6] = {(FixedNum)0x00000000, (FixedNum)0x000002ab, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000155};
FixedNum classProb1_101[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_103[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_104[6] = {(FixedNum)0x00000155, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x000002ab, (FixedNum)0x00000000};
FixedNum classProb1_105[6] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_108[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x000002ab, (FixedNum)0x00000155, (FixedNum)0x00000000};
FixedNum classProb1_109[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_112[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_113[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x000003b1, (FixedNum)0x0000004f, (FixedNum)0x00000000};
FixedNum classProb1_117[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000355, (FixedNum)0x00000000, (FixedNum)0x000000ab, (FixedNum)0x00000000};
FixedNum classProb1_118[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000039, (FixedNum)0x00000000, (FixedNum)0x000003c7, (FixedNum)0x00000000};
FixedNum classProb1_120[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000003, (FixedNum)0x00000001, (FixedNum)0x000003fc, (FixedNum)0x00000000};
FixedNum classProb1_122[6] = {(FixedNum)0x00000000, (FixedNum)0x00000005, (FixedNum)0x0000000b, (FixedNum)0x00000000, (FixedNum)0x000003f0, (FixedNum)0x00000000};
FixedNum classProb1_123[6] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_125[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_127[6] = {(FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_128[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_136[6] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_137[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_138[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_140[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000015, (FixedNum)0x00000000, (FixedNum)0x000003eb};
FixedNum classProb1_144[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_145[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000200, (FixedNum)0x00000200, (FixedNum)0x00000000};
FixedNum classProb1_146[6] = {(FixedNum)0x00000000, (FixedNum)0x00000005, (FixedNum)0x00000000, (FixedNum)0x00000005, (FixedNum)0x000003f6, (FixedNum)0x00000000};
FixedNum classProb1_148[6] = {(FixedNum)0x000003b1, (FixedNum)0x0000004f, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_150[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x000002ab, (FixedNum)0x00000155, (FixedNum)0x00000000};
FixedNum classProb1_151[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_160[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_163[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x000003fb, (FixedNum)0x00000000, (FixedNum)0x00000005};
FixedNum classProb1_165[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000066, (FixedNum)0x0000039a};
FixedNum classProb1_166[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_168[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_169[6] = {(FixedNum)0x00000000, (FixedNum)0x00000200, (FixedNum)0x00000000, (FixedNum)0x00000200, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_170[6] = {(FixedNum)0x000003c0, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000040};
FixedNum classProb1_177[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000015, (FixedNum)0x00000000, (FixedNum)0x000003eb};
FixedNum classProb1_179[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000155, (FixedNum)0x00000000, (FixedNum)0x000002ab};
FixedNum classProb1_180[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_181[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000002, (FixedNum)0x000003fe};
FixedNum classProb1_183[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_185[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_186[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_188[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_189[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_191[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_193[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_194[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_196[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_197[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_200[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_201[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_202[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_204[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_206[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000004, (FixedNum)0x000003fc, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_207[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_208[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000003, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x000003fd};
FixedNum classProb1_210[6] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_213[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_214[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_215[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000010, (FixedNum)0x000003f0, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_219[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000200, (FixedNum)0x00000000, (FixedNum)0x00000200};
FixedNum classProb1_220[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_221[6] = {(FixedNum)0x00000000, (FixedNum)0x0000002f, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x000003d1, (FixedNum)0x00000000};
FixedNum classProb1_224[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_231[6] = {(FixedNum)0x00000100, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000300};
FixedNum classProb1_232[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_235[6] = {(FixedNum)0x00000333, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x000000cd, (FixedNum)0x00000000};
FixedNum classProb1_236[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_237[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000004, (FixedNum)0x000003fc, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_239[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_240[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_242[6] = {(FixedNum)0x00000080, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000300, (FixedNum)0x00000080, (FixedNum)0x00000000};
FixedNum classProb1_243[6] = {(FixedNum)0x000003e0, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000020, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_245[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400};
FixedNum classProb1_246[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_248[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_249[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_250[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_252[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_255[6] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_256[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_258[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_259[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_263[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x000003b7, (FixedNum)0x00000049, (FixedNum)0x00000000};
FixedNum classProb1_266[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_267[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_270[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_271[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_272[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_274[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_275[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_277[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_279[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_280[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_285[6] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_287[6] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_288[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_290[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_291[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_292[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_293[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_297[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_298[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_301[6] = {(FixedNum)0x000003ff, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000001, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_304[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};
FixedNum classProb1_305[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000200, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000200};
FixedNum classProb1_306[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_308[6] = {(FixedNum)0x00000000, (FixedNum)0x000000cd, (FixedNum)0x00000333, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_309[6] = {(FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_312[6] = {(FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000};
FixedNum classProb1_313[6] = {(FixedNum)0x000002ab, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000155, (FixedNum)0x00000000};
FixedNum classProb1_314[6] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000400, (FixedNum)0x00000000};


FixedNum getProbs(int i, int classIndex, FixedNum weight){
	if (m_attIndex[i] == -1){
		return fxp_mul(weight, classProb1[i][classIndex]);
	}
	int treeIndex = (instance[m_attIndex[i]] <= m_splitPoint[i] ? 0 : 1);
	return getProbs(tree[i][treeIndex], classIndex, weight);
}

/* Function classify description:
 * Instance array must be initializated, with appropriated attributes, before calling this function
 * Output number 0 means that the instance was classified as 1
 * Output number 1 means that the instance was classified as 2
 * Output number 2 means that the instance was classified as 3
 * Output number 3 means that the instance was classified as 4
 * Output number 4 means that the instance was classified as 5
 * Output number 5 means that the instance was classified as 6
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
	tree[6] = tree_6;
	tree[11] = tree_11;
	tree[12] = tree_12;
	tree[13] = tree_13;
	tree[14] = tree_14;
	tree[18] = tree_18;
	tree[21] = tree_21;
	tree[22] = tree_22;
	tree[25] = tree_25;
	tree[28] = tree_28;
	tree[29] = tree_29;
	tree[31] = tree_31;
	tree[32] = tree_32;
	tree[33] = tree_33;
	tree[34] = tree_34;
	tree[35] = tree_35;
	tree[38] = tree_38;
	tree[39] = tree_39;
	tree[43] = tree_43;
	tree[44] = tree_44;
	tree[48] = tree_48;
	tree[51] = tree_51;
	tree[54] = tree_54;
	tree[55] = tree_55;
	tree[57] = tree_57;
	tree[60] = tree_60;
	tree[63] = tree_63;
	tree[64] = tree_64;
	tree[65] = tree_65;
	tree[69] = tree_69;
	tree[71] = tree_71;
	tree[74] = tree_74;
	tree[75] = tree_75;
	tree[76] = tree_76;
	tree[77] = tree_77;
	tree[78] = tree_78;
	tree[79] = tree_79;
	tree[81] = tree_81;
	tree[82] = tree_82;
	tree[84] = tree_84;
	tree[87] = tree_87;
	tree[88] = tree_88;
	tree[92] = tree_92;
	tree[95] = tree_95;
	tree[96] = tree_96;
	tree[97] = tree_97;
	tree[99] = tree_99;
	tree[102] = tree_102;
	tree[106] = tree_106;
	tree[107] = tree_107;
	tree[110] = tree_110;
	tree[111] = tree_111;
	tree[114] = tree_114;
	tree[115] = tree_115;
	tree[116] = tree_116;
	tree[119] = tree_119;
	tree[121] = tree_121;
	tree[124] = tree_124;
	tree[126] = tree_126;
	tree[129] = tree_129;
	tree[130] = tree_130;
	tree[131] = tree_131;
	tree[132] = tree_132;
	tree[133] = tree_133;
	tree[134] = tree_134;
	tree[135] = tree_135;
	tree[139] = tree_139;
	tree[141] = tree_141;
	tree[142] = tree_142;
	tree[143] = tree_143;
	tree[147] = tree_147;
	tree[149] = tree_149;
	tree[152] = tree_152;
	tree[153] = tree_153;
	tree[154] = tree_154;
	tree[155] = tree_155;
	tree[156] = tree_156;
	tree[157] = tree_157;
	tree[158] = tree_158;
	tree[159] = tree_159;
	tree[161] = tree_161;
	tree[162] = tree_162;
	tree[164] = tree_164;
	tree[167] = tree_167;
	tree[171] = tree_171;
	tree[172] = tree_172;
	tree[173] = tree_173;
	tree[174] = tree_174;
	tree[175] = tree_175;
	tree[176] = tree_176;
	tree[178] = tree_178;
	tree[182] = tree_182;
	tree[184] = tree_184;
	tree[187] = tree_187;
	tree[190] = tree_190;
	tree[192] = tree_192;
	tree[195] = tree_195;
	tree[198] = tree_198;
	tree[199] = tree_199;
	tree[203] = tree_203;
	tree[205] = tree_205;
	tree[209] = tree_209;
	tree[211] = tree_211;
	tree[212] = tree_212;
	tree[216] = tree_216;
	tree[217] = tree_217;
	tree[218] = tree_218;
	tree[222] = tree_222;
	tree[223] = tree_223;
	tree[225] = tree_225;
	tree[226] = tree_226;
	tree[227] = tree_227;
	tree[228] = tree_228;
	tree[229] = tree_229;
	tree[230] = tree_230;
	tree[233] = tree_233;
	tree[234] = tree_234;
	tree[238] = tree_238;
	tree[241] = tree_241;
	tree[244] = tree_244;
	tree[247] = tree_247;
	tree[251] = tree_251;
	tree[253] = tree_253;
	tree[254] = tree_254;
	tree[257] = tree_257;
	tree[260] = tree_260;
	tree[261] = tree_261;
	tree[262] = tree_262;
	tree[264] = tree_264;
	tree[265] = tree_265;
	tree[268] = tree_268;
	tree[269] = tree_269;
	tree[273] = tree_273;
	tree[276] = tree_276;
	tree[278] = tree_278;
	tree[281] = tree_281;
	tree[282] = tree_282;
	tree[283] = tree_283;
	tree[284] = tree_284;
	tree[286] = tree_286;
	tree[289] = tree_289;
	tree[294] = tree_294;
	tree[295] = tree_295;
	tree[296] = tree_296;
	tree[299] = tree_299;
	tree[300] = tree_300;
	tree[302] = tree_302;
	tree[303] = tree_303;
	tree[307] = tree_307;
	tree[310] = tree_310;
	tree[311] = tree_311;

	classProb1[7] = classProb1_7;
	classProb1[8] = classProb1_8;
	classProb1[9] = classProb1_9;
	classProb1[10] = classProb1_10;
	classProb1[15] = classProb1_15;
	classProb1[16] = classProb1_16;
	classProb1[17] = classProb1_17;
	classProb1[19] = classProb1_19;
	classProb1[20] = classProb1_20;
	classProb1[23] = classProb1_23;
	classProb1[24] = classProb1_24;
	classProb1[26] = classProb1_26;
	classProb1[27] = classProb1_27;
	classProb1[30] = classProb1_30;
	classProb1[36] = classProb1_36;
	classProb1[37] = classProb1_37;
	classProb1[40] = classProb1_40;
	classProb1[41] = classProb1_41;
	classProb1[42] = classProb1_42;
	classProb1[45] = classProb1_45;
	classProb1[46] = classProb1_46;
	classProb1[47] = classProb1_47;
	classProb1[49] = classProb1_49;
	classProb1[50] = classProb1_50;
	classProb1[52] = classProb1_52;
	classProb1[53] = classProb1_53;
	classProb1[56] = classProb1_56;
	classProb1[58] = classProb1_58;
	classProb1[59] = classProb1_59;
	classProb1[61] = classProb1_61;
	classProb1[62] = classProb1_62;
	classProb1[66] = classProb1_66;
	classProb1[67] = classProb1_67;
	classProb1[68] = classProb1_68;
	classProb1[70] = classProb1_70;
	classProb1[72] = classProb1_72;
	classProb1[73] = classProb1_73;
	classProb1[80] = classProb1_80;
	classProb1[83] = classProb1_83;
	classProb1[85] = classProb1_85;
	classProb1[86] = classProb1_86;
	classProb1[89] = classProb1_89;
	classProb1[90] = classProb1_90;
	classProb1[91] = classProb1_91;
	classProb1[93] = classProb1_93;
	classProb1[94] = classProb1_94;
	classProb1[98] = classProb1_98;
	classProb1[100] = classProb1_100;
	classProb1[101] = classProb1_101;
	classProb1[103] = classProb1_103;
	classProb1[104] = classProb1_104;
	classProb1[105] = classProb1_105;
	classProb1[108] = classProb1_108;
	classProb1[109] = classProb1_109;
	classProb1[112] = classProb1_112;
	classProb1[113] = classProb1_113;
	classProb1[117] = classProb1_117;
	classProb1[118] = classProb1_118;
	classProb1[120] = classProb1_120;
	classProb1[122] = classProb1_122;
	classProb1[123] = classProb1_123;
	classProb1[125] = classProb1_125;
	classProb1[127] = classProb1_127;
	classProb1[128] = classProb1_128;
	classProb1[136] = classProb1_136;
	classProb1[137] = classProb1_137;
	classProb1[138] = classProb1_138;
	classProb1[140] = classProb1_140;
	classProb1[144] = classProb1_144;
	classProb1[145] = classProb1_145;
	classProb1[146] = classProb1_146;
	classProb1[148] = classProb1_148;
	classProb1[150] = classProb1_150;
	classProb1[151] = classProb1_151;
	classProb1[160] = classProb1_160;
	classProb1[163] = classProb1_163;
	classProb1[165] = classProb1_165;
	classProb1[166] = classProb1_166;
	classProb1[168] = classProb1_168;
	classProb1[169] = classProb1_169;
	classProb1[170] = classProb1_170;
	classProb1[177] = classProb1_177;
	classProb1[179] = classProb1_179;
	classProb1[180] = classProb1_180;
	classProb1[181] = classProb1_181;
	classProb1[183] = classProb1_183;
	classProb1[185] = classProb1_185;
	classProb1[186] = classProb1_186;
	classProb1[188] = classProb1_188;
	classProb1[189] = classProb1_189;
	classProb1[191] = classProb1_191;
	classProb1[193] = classProb1_193;
	classProb1[194] = classProb1_194;
	classProb1[196] = classProb1_196;
	classProb1[197] = classProb1_197;
	classProb1[200] = classProb1_200;
	classProb1[201] = classProb1_201;
	classProb1[202] = classProb1_202;
	classProb1[204] = classProb1_204;
	classProb1[206] = classProb1_206;
	classProb1[207] = classProb1_207;
	classProb1[208] = classProb1_208;
	classProb1[210] = classProb1_210;
	classProb1[213] = classProb1_213;
	classProb1[214] = classProb1_214;
	classProb1[215] = classProb1_215;
	classProb1[219] = classProb1_219;
	classProb1[220] = classProb1_220;
	classProb1[221] = classProb1_221;
	classProb1[224] = classProb1_224;
	classProb1[231] = classProb1_231;
	classProb1[232] = classProb1_232;
	classProb1[235] = classProb1_235;
	classProb1[236] = classProb1_236;
	classProb1[237] = classProb1_237;
	classProb1[239] = classProb1_239;
	classProb1[240] = classProb1_240;
	classProb1[242] = classProb1_242;
	classProb1[243] = classProb1_243;
	classProb1[245] = classProb1_245;
	classProb1[246] = classProb1_246;
	classProb1[248] = classProb1_248;
	classProb1[249] = classProb1_249;
	classProb1[250] = classProb1_250;
	classProb1[252] = classProb1_252;
	classProb1[255] = classProb1_255;
	classProb1[256] = classProb1_256;
	classProb1[258] = classProb1_258;
	classProb1[259] = classProb1_259;
	classProb1[263] = classProb1_263;
	classProb1[266] = classProb1_266;
	classProb1[267] = classProb1_267;
	classProb1[270] = classProb1_270;
	classProb1[271] = classProb1_271;
	classProb1[272] = classProb1_272;
	classProb1[274] = classProb1_274;
	classProb1[275] = classProb1_275;
	classProb1[277] = classProb1_277;
	classProb1[279] = classProb1_279;
	classProb1[280] = classProb1_280;
	classProb1[285] = classProb1_285;
	classProb1[287] = classProb1_287;
	classProb1[288] = classProb1_288;
	classProb1[290] = classProb1_290;
	classProb1[291] = classProb1_291;
	classProb1[292] = classProb1_292;
	classProb1[293] = classProb1_293;
	classProb1[297] = classProb1_297;
	classProb1[298] = classProb1_298;
	classProb1[301] = classProb1_301;
	classProb1[304] = classProb1_304;
	classProb1[305] = classProb1_305;
	classProb1[306] = classProb1_306;
	classProb1[308] = classProb1_308;
	classProb1[309] = classProb1_309;
	classProb1[312] = classProb1_312;
	classProb1[313] = classProb1_313;
	classProb1[314] = classProb1_314;
}
