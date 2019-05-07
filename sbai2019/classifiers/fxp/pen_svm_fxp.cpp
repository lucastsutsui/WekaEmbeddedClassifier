
#include <Arduino.h>
#define TOTAL_BITS 32
#define FIXED_FBITS 10
#define SIGNED
#include "FixedNum.h"

#define INPUT_SIZE 8
#define NUM_CLASSES 10
#define CLASS_INDEX 8

/* Instance array must be global
 * Attributes MUST be sorted in instance array in the following order:
 * channel_0_0
 * channel_0_1
 * channel_0_2
 * channel_0_3
 * channel_0_4
 * channel_0_5
 * channel_0_6
 * channel_0_7
 */
FixedNum instance[INPUT_SIZE+1];
const FixedNum minArray[9] = {(FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, INF_POS};
const FixedNum maxArray[9] = {(FixedNum)0x00019000, (FixedNum)0x00019000, (FixedNum)0x00019000, (FixedNum)0x00019000, (FixedNum)0x00019000, (FixedNum)0x00019000, (FixedNum)0x00019000, (FixedNum)0x00019000, (FixedNum)0x00000000};


const FixedNum **m_sparseWeights[10];

const FixedNum *tmp0_sparseWeights1[1];
const FixedNum tmp1_sparseWeights1_0[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000666, (FixedNum)0xfffffa30, (FixedNum)0xfffff0ba, (FixedNum)0xfffffdae, (FixedNum)0x00000723, (FixedNum)0x0000045f, (FixedNum)0x00000472, (FixedNum)0xfffff52c};

const FixedNum *tmp0_sparseWeights2[2];
const FixedNum tmp1_sparseWeights2_0[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000328, (FixedNum)0xffffffe8, (FixedNum)0x00000731, (FixedNum)0xfffff971, (FixedNum)0x000001aa, (FixedNum)0x00000e5f, (FixedNum)0x00000c40, (FixedNum)0xffffee5e};
const FixedNum tmp1_sparseWeights2_1[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0xfffffa4c, (FixedNum)0x000009a7, (FixedNum)0x0000109d, (FixedNum)0xfffffca4, (FixedNum)0x00000186, (FixedNum)0x000009b5, (FixedNum)0x0000064b, (FixedNum)0xfffffcda};

const FixedNum *tmp0_sparseWeights3[3];
const FixedNum tmp1_sparseWeights3_0[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000206, (FixedNum)0xfffff293, (FixedNum)0x00000fd9, (FixedNum)0x00001071, (FixedNum)0xffffe099, (FixedNum)0xffffffcd, (FixedNum)0x00000643, (FixedNum)0x000008bd};
const FixedNum tmp1_sparseWeights3_1[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0xfffff964, (FixedNum)0xfffffef0, (FixedNum)0x00000565, (FixedNum)0x000001d6, (FixedNum)0xfffffc6f, (FixedNum)0xfffffb6d, (FixedNum)0xfffffc9d, (FixedNum)0x00000b17};
const FixedNum tmp1_sparseWeights3_2[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x0000005c, (FixedNum)0x00000071, (FixedNum)0xffffffcf, (FixedNum)0x00000050, (FixedNum)0xfffffe99, (FixedNum)0xfffffbe3, (FixedNum)0xfffffb12, (FixedNum)0x000009c6};

const FixedNum *tmp0_sparseWeights4[4];
const FixedNum tmp1_sparseWeights4_0[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000946, (FixedNum)0xfffff3fe, (FixedNum)0x00000784, (FixedNum)0xfffff610, (FixedNum)0xffffed6f, (FixedNum)0x0000111d, (FixedNum)0x00000038, (FixedNum)0x0000001b};
const FixedNum tmp1_sparseWeights4_1[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x000001e3, (FixedNum)0x00000a25, (FixedNum)0x000004bf, (FixedNum)0xfffff961, (FixedNum)0xfffff605, (FixedNum)0xfffffcd5, (FixedNum)0xffffefd1, (FixedNum)0xffffffde};
const FixedNum tmp1_sparseWeights4_2[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000972, (FixedNum)0x00000a40, (FixedNum)0xfffff297, (FixedNum)0xfffff690, (FixedNum)0xffffefcb, (FixedNum)0xfffffc99, (FixedNum)0xfffffbe6, (FixedNum)0x000009df};
const FixedNum tmp1_sparseWeights4_3[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000dcb, (FixedNum)0xffffec52, (FixedNum)0x0000052d, (FixedNum)0xffffeeae, (FixedNum)0xfffff9fd, (FixedNum)0x00000935, (FixedNum)0xffffe399, (FixedNum)0xfffff1c3};

const FixedNum *tmp0_sparseWeights5[5];
const FixedNum tmp1_sparseWeights5_0[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x000008a1, (FixedNum)0xfffffcd7, (FixedNum)0xffffebc3, (FixedNum)0x00000016, (FixedNum)0x000001bc, (FixedNum)0x00000597, (FixedNum)0x00000669, (FixedNum)0xfffffd3e};
const FixedNum tmp1_sparseWeights5_1[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0xfffffdad, (FixedNum)0x0000127b, (FixedNum)0xffffef60, (FixedNum)0x000002fd, (FixedNum)0x00000c1b, (FixedNum)0xfffffb91, (FixedNum)0xfffff0a9, (FixedNum)0x000018b4};
const FixedNum tmp1_sparseWeights5_2[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x0000085c, (FixedNum)0xfffffa91, (FixedNum)0xfffff239, (FixedNum)0xffffff72, (FixedNum)0x00000026, (FixedNum)0xfffffd79, (FixedNum)0xfffffcf6, (FixedNum)0x0000073c};
const FixedNum tmp1_sparseWeights5_3[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000536, (FixedNum)0xfffffe7e, (FixedNum)0xfffff719, (FixedNum)0xfffffd89, (FixedNum)0x000005cf, (FixedNum)0x0000088c, (FixedNum)0x000002a1, (FixedNum)0xfffff7ff};
const FixedNum tmp1_sparseWeights5_4[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000091, (FixedNum)0xfffff93c, (FixedNum)0xfffff6f2, (FixedNum)0x00000245, (FixedNum)0x00000b69, (FixedNum)0x00000695, (FixedNum)0x00000bf6, (FixedNum)0x000008ad};

const FixedNum *tmp0_sparseWeights6[6];
const FixedNum tmp1_sparseWeights6_0[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0xfffff3a4, (FixedNum)0xfffff934, (FixedNum)0x00000de8, (FixedNum)0x00000149, (FixedNum)0xffffeb74, (FixedNum)0x00000672, (FixedNum)0xfffffb68, (FixedNum)0x0000060f};
const FixedNum tmp1_sparseWeights6_1[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0xfffff3ba, (FixedNum)0x00000112, (FixedNum)0x00000afa, (FixedNum)0x00000f27, (FixedNum)0xfffff4e3, (FixedNum)0x00000373, (FixedNum)0x0000057d, (FixedNum)0x00000bf4};
const FixedNum tmp1_sparseWeights6_2[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0xfffffb16, (FixedNum)0x00000201, (FixedNum)0xfffff6b1, (FixedNum)0x00000588, (FixedNum)0xfffffb25, (FixedNum)0xfffff4fb, (FixedNum)0x000000e7, (FixedNum)0x00000926};
const FixedNum tmp1_sparseWeights6_3[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0xffffea18, (FixedNum)0x0000127c, (FixedNum)0xfffffc31, (FixedNum)0xfffff17f, (FixedNum)0x000015f8, (FixedNum)0x0000045a, (FixedNum)0xfffff34e, (FixedNum)0xfffff66a};
const FixedNum tmp1_sparseWeights6_4[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0xffffe953, (FixedNum)0x00000e21, (FixedNum)0xffffffe4, (FixedNum)0x00000f4a, (FixedNum)0x00000c20, (FixedNum)0xfffff7d5, (FixedNum)0x00000971, (FixedNum)0x00000383};
const FixedNum tmp1_sparseWeights6_5[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0xfffff4f4, (FixedNum)0x0000016f, (FixedNum)0x00000fea, (FixedNum)0x00000211, (FixedNum)0xfffffdbc, (FixedNum)0xfffffd34, (FixedNum)0xfffffc8b, (FixedNum)0x000000f7};

const FixedNum *tmp0_sparseWeights7[7];
const FixedNum tmp1_sparseWeights7_0[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x000007cc, (FixedNum)0x00000402, (FixedNum)0xfffff88d, (FixedNum)0xfffff881, (FixedNum)0x000000b5, (FixedNum)0x0000059f, (FixedNum)0x00000c99, (FixedNum)0xfffffb86};
const FixedNum tmp1_sparseWeights7_1[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x0000038f, (FixedNum)0xfffffb5a, (FixedNum)0x0000067c, (FixedNum)0xfffff1be, (FixedNum)0xffffeed6, (FixedNum)0x00000565, (FixedNum)0xfffff44a, (FixedNum)0xfffff239};
const FixedNum tmp1_sparseWeights7_2[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x0000094f, (FixedNum)0x00000028, (FixedNum)0xfffff4fd, (FixedNum)0xfffffa96, (FixedNum)0xfffffa3b, (FixedNum)0xfffffe80, (FixedNum)0xfffffc42, (FixedNum)0x000001bb};
const FixedNum tmp1_sparseWeights7_3[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x0000053b, (FixedNum)0xfffffeb8, (FixedNum)0xfffffbec, (FixedNum)0xfffffd1f, (FixedNum)0x000000e7, (FixedNum)0x0000017b, (FixedNum)0x000001c5, (FixedNum)0xfffff80a};
const FixedNum tmp1_sparseWeights7_4[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x000008ef, (FixedNum)0xfffff5d8, (FixedNum)0xfffff9d7, (FixedNum)0xffffff5c, (FixedNum)0xffffefb7, (FixedNum)0x00000a52, (FixedNum)0x00000224, (FixedNum)0xfffff839};
const FixedNum tmp1_sparseWeights7_5[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000287, (FixedNum)0xfffff9ad, (FixedNum)0x000000c0, (FixedNum)0xfffff944, (FixedNum)0xfffff0ff, (FixedNum)0x0000045b, (FixedNum)0xffffff8c, (FixedNum)0xffffece7};
const FixedNum tmp1_sparseWeights7_6[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000901, (FixedNum)0x00000094, (FixedNum)0xfffff958, (FixedNum)0xfffff888, (FixedNum)0xfffffe9b, (FixedNum)0x00000175, (FixedNum)0xfffffdeb, (FixedNum)0xfffffb9f};

const FixedNum *tmp0_sparseWeights8[8];
const FixedNum tmp1_sparseWeights8_0[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000a1d, (FixedNum)0xfffffea9, (FixedNum)0xffffff47, (FixedNum)0xfffffad1, (FixedNum)0xfffffc09, (FixedNum)0x000011e5, (FixedNum)0x0000079c, (FixedNum)0xfffffa68};
const FixedNum tmp1_sparseWeights8_1[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000d59, (FixedNum)0x00000ce5, (FixedNum)0x00001061, (FixedNum)0x00000a5a, (FixedNum)0x00000314, (FixedNum)0x0000120d, (FixedNum)0x0000033b, (FixedNum)0x000002f1};
const FixedNum tmp1_sparseWeights8_2[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x0000169e, (FixedNum)0xfffffa4f, (FixedNum)0xfffff5d5, (FixedNum)0xfffff3a8, (FixedNum)0xfffffb5e, (FixedNum)0xfffff99b, (FixedNum)0x00000a98, (FixedNum)0x00000ebf};
const FixedNum tmp1_sparseWeights8_3[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x0000031f, (FixedNum)0x000003a6, (FixedNum)0x00000134, (FixedNum)0x00000049, (FixedNum)0x00000405, (FixedNum)0x00000afa, (FixedNum)0x000007d3, (FixedNum)0xfffff4e4};
const FixedNum tmp1_sparseWeights8_4[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x0000047d, (FixedNum)0xfffffabe, (FixedNum)0x00000401, (FixedNum)0x0000077d, (FixedNum)0x00000c46, (FixedNum)0x0000081f, (FixedNum)0x00001788, (FixedNum)0x00000745};
const FixedNum tmp1_sparseWeights8_5[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x000004e9, (FixedNum)0x0000078d, (FixedNum)0x00000e7b, (FixedNum)0x0000071b, (FixedNum)0x0000014a, (FixedNum)0x0000078f, (FixedNum)0x00000ce0, (FixedNum)0xfffff405};
const FixedNum tmp1_sparseWeights8_6[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000f88, (FixedNum)0xfffffbf9, (FixedNum)0x0000042a, (FixedNum)0xfffff4c3, (FixedNum)0x000001c9, (FixedNum)0x0000088e, (FixedNum)0xfffffe33, (FixedNum)0x00000186};
const FixedNum tmp1_sparseWeights8_7[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0xfffff7e8, (FixedNum)0x00000614, (FixedNum)0x000009ad, (FixedNum)0x00000dc4, (FixedNum)0x000010a7, (FixedNum)0xfffffc9d, (FixedNum)0x000009b8, (FixedNum)0x000009f0};

const FixedNum *tmp0_sparseWeights9[9];
const FixedNum tmp1_sparseWeights9_0[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000c61, (FixedNum)0xfffffe64, (FixedNum)0xfffff840, (FixedNum)0xfffffc9f, (FixedNum)0xfffffcd8, (FixedNum)0x0000012e, (FixedNum)0x00000d89, (FixedNum)0xfffff972};
const FixedNum tmp1_sparseWeights9_1[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0xfffffe14, (FixedNum)0x000005a8, (FixedNum)0x00000927, (FixedNum)0xfffffd24, (FixedNum)0xfffff952, (FixedNum)0xfffff09f, (FixedNum)0x00000377, (FixedNum)0x0000013c};
const FixedNum tmp1_sparseWeights9_2[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000737, (FixedNum)0x00000053, (FixedNum)0xfffffb99, (FixedNum)0xfffff6fb, (FixedNum)0xffffedb3, (FixedNum)0xfffff5a3, (FixedNum)0x000003f2, (FixedNum)0x000004c9};
const FixedNum tmp1_sparseWeights9_3[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00000c81, (FixedNum)0xffffff69, (FixedNum)0xfffff36e, (FixedNum)0x0000003a, (FixedNum)0x000004b1, (FixedNum)0x0000010f, (FixedNum)0x00000333, (FixedNum)0xffffeb15};
const FixedNum tmp1_sparseWeights9_4[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x000002b1, (FixedNum)0x0000025a, (FixedNum)0xffffff5b, (FixedNum)0x000006ef, (FixedNum)0x00000a37, (FixedNum)0xfffff35c, (FixedNum)0x00001c89, (FixedNum)0xfffffe44};
const FixedNum tmp1_sparseWeights9_5[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0xfffffe16, (FixedNum)0x00000796, (FixedNum)0x00000d78, (FixedNum)0xfffffec9, (FixedNum)0xfffffd1f, (FixedNum)0xffffe926, (FixedNum)0x000007ea, (FixedNum)0xfffffabd};
const FixedNum tmp1_sparseWeights9_6[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0x00001442, (FixedNum)0xfffffc42, (FixedNum)0xfffffcee, (FixedNum)0xfffff4d0, (FixedNum)0xfffffd77, (FixedNum)0xfffffcf9, (FixedNum)0x00000403, (FixedNum)0xfffff4fe};
const FixedNum tmp1_sparseWeights9_7[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0xfffff39a, (FixedNum)0xfffffae9, (FixedNum)0x00001011, (FixedNum)0x000008e6, (FixedNum)0x00000517, (FixedNum)0xfffff8c0, (FixedNum)0x000004f3, (FixedNum)0x00000c74};
const FixedNum tmp1_sparseWeights9_8[9] = {(FixedNum)(0x00002000 >> FIXED_FBITS), (FixedNum)0xfffff904, (FixedNum)0x0000000d, (FixedNum)0xfffffd2e, (FixedNum)0xfffffeb5, (FixedNum)0xfffffa43, (FixedNum)0xffffea1b, (FixedNum)0x00000631, (FixedNum)0xfffff914};

const int **m_sparseIndices[10];

const int *tmp0_sparseIndices1[1];
const int tmp1_sparseIndices1_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices2[2];
const int tmp1_sparseIndices2_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices2_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices3[3];
const int tmp1_sparseIndices3_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices3_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices3_2[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices4[4];
const int tmp1_sparseIndices4_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices4_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices4_2[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices4_3[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices5[5];
const int tmp1_sparseIndices5_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices5_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices5_2[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices5_3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices5_4[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices6[6];
const int tmp1_sparseIndices6_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices6_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices6_2[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices6_3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices6_4[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices6_5[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices7[7];
const int tmp1_sparseIndices7_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices7_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices7_2[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices7_3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices7_4[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices7_5[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices7_6[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices8[8];
const int tmp1_sparseIndices8_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices8_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices8_2[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices8_3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices8_4[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices8_5[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices8_6[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices8_7[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices9[9];
const int tmp1_sparseIndices9_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_2[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_4[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_5[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_6[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_7[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_8[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const FixedNum *m_b[10];
const FixedNum tmp_m_b1[1] = {(FixedNum)0xfffffee4};
const FixedNum tmp_m_b2[2] = {(FixedNum)0x00000f03, (FixedNum)0x000014a6};
const FixedNum tmp_m_b3[3] = {(FixedNum)0x00000d24, (FixedNum)0x0000033c, (FixedNum)0xffffffd4};
const FixedNum tmp_m_b4[4] = {(FixedNum)0xfffffadd, (FixedNum)0xfffff27d, (FixedNum)0xffffed1c, (FixedNum)0xffffde28};
const FixedNum tmp_m_b5[5] = {(FixedNum)0x00000184, (FixedNum)0x00000804, (FixedNum)0xfffff7f4, (FixedNum)0xfffffe12, (FixedNum)0x000011d2};
const FixedNum tmp_m_b6[6] = {(FixedNum)0x00000005, (FixedNum)0x00000f2e, (FixedNum)0xfffff496, (FixedNum)0xfffff3fa, (FixedNum)0x00001291, (FixedNum)0x000000a0};
const FixedNum tmp_m_b7[7] = {(FixedNum)0x00000976, (FixedNum)0xffffedc4, (FixedNum)0xfffff5a3, (FixedNum)0xfffffc5b, (FixedNum)0xfffffe63, (FixedNum)0xfffff275, (FixedNum)0xfffffc30};
const FixedNum tmp_m_b8[8] = {(FixedNum)0x00000c11, (FixedNum)0x00002959, (FixedNum)0xfffff482, (FixedNum)0x00000684, (FixedNum)0x00001fd2, (FixedNum)0x00001768, (FixedNum)0x000004ca, (FixedNum)0x000010ef};
const FixedNum tmp_m_b9[9] = {(FixedNum)0xffffff3d, (FixedNum)0xfffff59f, (FixedNum)0xffffea39, (FixedNum)0xffffeed8, (FixedNum)0x00001201, (FixedNum)0xfffff5c7, (FixedNum)0xfffff3a9, (FixedNum)0xffffffa7, (FixedNum)0xffffe910};

FixedNum SVMOutput(int i, int j){
	FixedNum result = (FixedNum)0;
	for (int p1 = 0; p1 < m_sparseWeights[i][j][0]; p1++){
		int p2 = m_sparseIndices[i][j][p1];
		if (p2 != CLASS_INDEX){
			result = fxp_sum(result, fxp_mul(instance[p2], m_sparseWeights[i][j][p1+1]));
		}
	}
	result = fxp_diff(result, m_b[i][j]);
	return result;
}

/* Function classify description:
 * Instance array must be initializated, with appropriated attributes, before calling this function
 * Output number 0 means that the instance was classified as 1
 * Output number 1 means that the instance was classified as 0
 * Output number 2 means that the instance was classified as 3
 * Output number 3 means that the instance was classified as 2
 * Output number 4 means that the instance was classified as 5
 * Output number 5 means that the instance was classified as 4
 * Output number 6 means that the instance was classified as 7
 * Output number 7 means that the instance was classified as 6
 * Output number 8 means that the instance was classified as 9
 * Output number 9 means that the instance was classified as 8
 */
int classify(){
	for (int i = 0; i <= INPUT_SIZE; i++){
		if (maxArray[i] == minArray[i] || minArray[i] == INF_POS){
			instance[i] = (FixedNum)0;
		}
		else{
			instance[i] = fxp_div(fxp_diff(instance[i], minArray[i]), fxp_diff(maxArray[i], minArray[i]));
		}
	}
	int result[NUM_CLASSES] = {0};
	for (int i = 1; i < NUM_CLASSES; i++){
		for (int j = 0; j < i; j++){
			FixedNum output = SVMOutput(i, j);
			if (output > 0){
				result[i]++;
			}
			else{
				result[j]++;
			}
		}
	}
	int indMax = 0;
	for (int i = 1; i < NUM_CLASSES; i++){
		if (result[i] > result[indMax]){
			indMax = i;
		}
	}
	return indMax;
}

void initConnections(){

	m_sparseWeights[0] = NULL;

	tmp0_sparseWeights1[0] = tmp1_sparseWeights1_0;
	m_sparseWeights[1] = tmp0_sparseWeights1;

	tmp0_sparseWeights2[0] = tmp1_sparseWeights2_0;
	tmp0_sparseWeights2[1] = tmp1_sparseWeights2_1;
	m_sparseWeights[2] = tmp0_sparseWeights2;

	tmp0_sparseWeights3[0] = tmp1_sparseWeights3_0;
	tmp0_sparseWeights3[1] = tmp1_sparseWeights3_1;
	tmp0_sparseWeights3[2] = tmp1_sparseWeights3_2;
	m_sparseWeights[3] = tmp0_sparseWeights3;

	tmp0_sparseWeights4[0] = tmp1_sparseWeights4_0;
	tmp0_sparseWeights4[1] = tmp1_sparseWeights4_1;
	tmp0_sparseWeights4[2] = tmp1_sparseWeights4_2;
	tmp0_sparseWeights4[3] = tmp1_sparseWeights4_3;
	m_sparseWeights[4] = tmp0_sparseWeights4;

	tmp0_sparseWeights5[0] = tmp1_sparseWeights5_0;
	tmp0_sparseWeights5[1] = tmp1_sparseWeights5_1;
	tmp0_sparseWeights5[2] = tmp1_sparseWeights5_2;
	tmp0_sparseWeights5[3] = tmp1_sparseWeights5_3;
	tmp0_sparseWeights5[4] = tmp1_sparseWeights5_4;
	m_sparseWeights[5] = tmp0_sparseWeights5;

	tmp0_sparseWeights6[0] = tmp1_sparseWeights6_0;
	tmp0_sparseWeights6[1] = tmp1_sparseWeights6_1;
	tmp0_sparseWeights6[2] = tmp1_sparseWeights6_2;
	tmp0_sparseWeights6[3] = tmp1_sparseWeights6_3;
	tmp0_sparseWeights6[4] = tmp1_sparseWeights6_4;
	tmp0_sparseWeights6[5] = tmp1_sparseWeights6_5;
	m_sparseWeights[6] = tmp0_sparseWeights6;

	tmp0_sparseWeights7[0] = tmp1_sparseWeights7_0;
	tmp0_sparseWeights7[1] = tmp1_sparseWeights7_1;
	tmp0_sparseWeights7[2] = tmp1_sparseWeights7_2;
	tmp0_sparseWeights7[3] = tmp1_sparseWeights7_3;
	tmp0_sparseWeights7[4] = tmp1_sparseWeights7_4;
	tmp0_sparseWeights7[5] = tmp1_sparseWeights7_5;
	tmp0_sparseWeights7[6] = tmp1_sparseWeights7_6;
	m_sparseWeights[7] = tmp0_sparseWeights7;

	tmp0_sparseWeights8[0] = tmp1_sparseWeights8_0;
	tmp0_sparseWeights8[1] = tmp1_sparseWeights8_1;
	tmp0_sparseWeights8[2] = tmp1_sparseWeights8_2;
	tmp0_sparseWeights8[3] = tmp1_sparseWeights8_3;
	tmp0_sparseWeights8[4] = tmp1_sparseWeights8_4;
	tmp0_sparseWeights8[5] = tmp1_sparseWeights8_5;
	tmp0_sparseWeights8[6] = tmp1_sparseWeights8_6;
	tmp0_sparseWeights8[7] = tmp1_sparseWeights8_7;
	m_sparseWeights[8] = tmp0_sparseWeights8;

	tmp0_sparseWeights9[0] = tmp1_sparseWeights9_0;
	tmp0_sparseWeights9[1] = tmp1_sparseWeights9_1;
	tmp0_sparseWeights9[2] = tmp1_sparseWeights9_2;
	tmp0_sparseWeights9[3] = tmp1_sparseWeights9_3;
	tmp0_sparseWeights9[4] = tmp1_sparseWeights9_4;
	tmp0_sparseWeights9[5] = tmp1_sparseWeights9_5;
	tmp0_sparseWeights9[6] = tmp1_sparseWeights9_6;
	tmp0_sparseWeights9[7] = tmp1_sparseWeights9_7;
	tmp0_sparseWeights9[8] = tmp1_sparseWeights9_8;
	m_sparseWeights[9] = tmp0_sparseWeights9;


	m_sparseIndices[0] = NULL;

	tmp0_sparseIndices1[0] = tmp1_sparseIndices1_0;
	m_sparseIndices[1] = tmp0_sparseIndices1;

	tmp0_sparseIndices2[0] = tmp1_sparseIndices2_0;
	tmp0_sparseIndices2[1] = tmp1_sparseIndices2_1;
	m_sparseIndices[2] = tmp0_sparseIndices2;

	tmp0_sparseIndices3[0] = tmp1_sparseIndices3_0;
	tmp0_sparseIndices3[1] = tmp1_sparseIndices3_1;
	tmp0_sparseIndices3[2] = tmp1_sparseIndices3_2;
	m_sparseIndices[3] = tmp0_sparseIndices3;

	tmp0_sparseIndices4[0] = tmp1_sparseIndices4_0;
	tmp0_sparseIndices4[1] = tmp1_sparseIndices4_1;
	tmp0_sparseIndices4[2] = tmp1_sparseIndices4_2;
	tmp0_sparseIndices4[3] = tmp1_sparseIndices4_3;
	m_sparseIndices[4] = tmp0_sparseIndices4;

	tmp0_sparseIndices5[0] = tmp1_sparseIndices5_0;
	tmp0_sparseIndices5[1] = tmp1_sparseIndices5_1;
	tmp0_sparseIndices5[2] = tmp1_sparseIndices5_2;
	tmp0_sparseIndices5[3] = tmp1_sparseIndices5_3;
	tmp0_sparseIndices5[4] = tmp1_sparseIndices5_4;
	m_sparseIndices[5] = tmp0_sparseIndices5;

	tmp0_sparseIndices6[0] = tmp1_sparseIndices6_0;
	tmp0_sparseIndices6[1] = tmp1_sparseIndices6_1;
	tmp0_sparseIndices6[2] = tmp1_sparseIndices6_2;
	tmp0_sparseIndices6[3] = tmp1_sparseIndices6_3;
	tmp0_sparseIndices6[4] = tmp1_sparseIndices6_4;
	tmp0_sparseIndices6[5] = tmp1_sparseIndices6_5;
	m_sparseIndices[6] = tmp0_sparseIndices6;

	tmp0_sparseIndices7[0] = tmp1_sparseIndices7_0;
	tmp0_sparseIndices7[1] = tmp1_sparseIndices7_1;
	tmp0_sparseIndices7[2] = tmp1_sparseIndices7_2;
	tmp0_sparseIndices7[3] = tmp1_sparseIndices7_3;
	tmp0_sparseIndices7[4] = tmp1_sparseIndices7_4;
	tmp0_sparseIndices7[5] = tmp1_sparseIndices7_5;
	tmp0_sparseIndices7[6] = tmp1_sparseIndices7_6;
	m_sparseIndices[7] = tmp0_sparseIndices7;

	tmp0_sparseIndices8[0] = tmp1_sparseIndices8_0;
	tmp0_sparseIndices8[1] = tmp1_sparseIndices8_1;
	tmp0_sparseIndices8[2] = tmp1_sparseIndices8_2;
	tmp0_sparseIndices8[3] = tmp1_sparseIndices8_3;
	tmp0_sparseIndices8[4] = tmp1_sparseIndices8_4;
	tmp0_sparseIndices8[5] = tmp1_sparseIndices8_5;
	tmp0_sparseIndices8[6] = tmp1_sparseIndices8_6;
	tmp0_sparseIndices8[7] = tmp1_sparseIndices8_7;
	m_sparseIndices[8] = tmp0_sparseIndices8;

	tmp0_sparseIndices9[0] = tmp1_sparseIndices9_0;
	tmp0_sparseIndices9[1] = tmp1_sparseIndices9_1;
	tmp0_sparseIndices9[2] = tmp1_sparseIndices9_2;
	tmp0_sparseIndices9[3] = tmp1_sparseIndices9_3;
	tmp0_sparseIndices9[4] = tmp1_sparseIndices9_4;
	tmp0_sparseIndices9[5] = tmp1_sparseIndices9_5;
	tmp0_sparseIndices9[6] = tmp1_sparseIndices9_6;
	tmp0_sparseIndices9[7] = tmp1_sparseIndices9_7;
	tmp0_sparseIndices9[8] = tmp1_sparseIndices9_8;
	m_sparseIndices[9] = tmp0_sparseIndices9;


	m_b[0] = NULL;
	m_b[1] = tmp_m_b1;
	m_b[2] = tmp_m_b2;
	m_b[3] = tmp_m_b3;
	m_b[4] = tmp_m_b4;
	m_b[5] = tmp_m_b5;
	m_b[6] = tmp_m_b6;
	m_b[7] = tmp_m_b7;
	m_b[8] = tmp_m_b8;
	m_b[9] = tmp_m_b9;
}
