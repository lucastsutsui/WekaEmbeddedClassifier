
#include <Arduino.h>
#define TOTAL_BITS 32
#define FIXED_FBITS 10
#define SIGNED
#include "FixedNum.h"

#define INPUT_SIZE 128
#define NUM_CLASSES 6
#define CLASS_INDEX 128

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
const FixedNum minArray[129] = {(FixedNum)0xfefa299b, (FixedNum)0x000000b5, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0xfffdf2ab, (FixedNum)0xfffc717d, (FixedNum)0xffe5fd0f, (FixedNum)0xff042228, (FixedNum)0x000000be, (FixedNum)0x00000005, (FixedNum)0x00000020, (FixedNum)0x00000000, (FixedNum)0xfffe9de8, (FixedNum)0xfffc8ec1, (FixedNum)0xffe353b1, (FixedNum)0xfea68518, (FixedNum)0x000000e8, (FixedNum)0x00000002, (FixedNum)0x00000008, (FixedNum)0x0000006a, (FixedNum)0xffffb587, (FixedNum)0xfffec2e4, (FixedNum)0xfffa721a, (FixedNum)0xfe8e4d76, (FixedNum)0x000001d7, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0xffff5764, (FixedNum)0xfff9a5b2, (FixedNum)0xffd1f613, (FixedNum)0xffeb5070, (FixedNum)0x000002c9, (FixedNum)0x00000003, (FixedNum)0x00000029, (FixedNum)0x00000118, (FixedNum)0xffffcdc0, (FixedNum)0xfffdf135, (FixedNum)0xfff23f9b, (FixedNum)0xffe3fb2c, (FixedNum)0x00000294, (FixedNum)0x00000005, (FixedNum)0x00000023, (FixedNum)0x00000124, (FixedNum)0xfffff07c, (FixedNum)0xffff8333, (FixedNum)0xfffd493e, (FixedNum)0xfeed1714, (FixedNum)0x00000227, (FixedNum)0x00000002, (FixedNum)0x00000012, (FixedNum)0x0000007a, (FixedNum)0xffff9591, (FixedNum)0xffff0d3f, (FixedNum)0xfffabb78, (FixedNum)0xfed78a60, (FixedNum)0x00000228, (FixedNum)0x00000005, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0xffff8eca, (FixedNum)0xfffef33c, (FixedNum)0xfff9548d, (FixedNum)0xffba9ad4, (FixedNum)0x00000224, (FixedNum)0x00000002, (FixedNum)0x00000004, (FixedNum)0x00000024, (FixedNum)0xfffebe86, (FixedNum)0xfffdaa7e, (FixedNum)0xffebe977, (FixedNum)0xffc9803f, (FixedNum)0x00000260, (FixedNum)0x00000003, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0xfffeaa46, (FixedNum)0xfffdc86f, (FixedNum)0xfff02a70, (FixedNum)0xff6460bc, (FixedNum)0x000002c0, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0x00000000, (FixedNum)0xffffa299, (FixedNum)0xffff3be9, (FixedNum)0xfffc40bc, (FixedNum)0xff7c191a, (FixedNum)0x000002bc, (FixedNum)0x00000003, (FixedNum)0x00000022, (FixedNum)0x00000000, (FixedNum)0xffffb7cc, (FixedNum)0xffff662e, (FixedNum)0xfffd9930, (FixedNum)0xffefaaa5, (FixedNum)0x00000351, (FixedNum)0x00000008, (FixedNum)0x0000003d, (FixedNum)0x00000140, (FixedNum)0xffffef0a, (FixedNum)0xffffd26f, (FixedNum)0xfffe8893, (FixedNum)0xffedb1c1, (FixedNum)0x00000348, (FixedNum)0x00000002, (FixedNum)0x00000038, (FixedNum)0x00000186, (FixedNum)0xfffff0db, (FixedNum)0xffffd331, (FixedNum)0xfffec35a, (FixedNum)0xff6fc386, (FixedNum)0x000002df, (FixedNum)0x00000002, (FixedNum)0x00000017, (FixedNum)0x00000189, (FixedNum)0xffff6f58, (FixedNum)0xfffecfb9, (FixedNum)0xfff876e3, (FixedNum)0xff7e59ce, (FixedNum)0x000002d9, (FixedNum)0x00000003, (FixedNum)0x0000000c, (FixedNum)0x0000007a, (FixedNum)0xffff872d, (FixedNum)0xffff14a0, (FixedNum)0xfff99764, INF_POS};
const FixedNum maxArray[129] = {(FixedNum)0x28ef7d64, (FixedNum)0x0014ef84, (FixedNum)0x00029c52, (FixedNum)0x00038a7a, (FixedNum)0x000f866c, (FixedNum)0xfffffff9, (FixedNum)0x000058ce, (FixedNum)0x0001cd18, (FixedNum)0x1ea6eb40, (FixedNum)0x001a2174, (FixedNum)0x00020dcc, (FixedNum)0x00050501, (FixedNum)0x001ef451, (FixedNum)0xffffffef, (FixedNum)0x00002cb9, (FixedNum)0x0001d206, (FixedNum)0x0447f1f1, (FixedNum)0x00009125, (FixedNum)0x0000c891, (FixedNum)0x0005a2d4, (FixedNum)0x00327cf4, (FixedNum)0xfffffff4, (FixedNum)0x0000113f, (FixedNum)0x00001554, (FixedNum)0x0418f18d, (FixedNum)0x0002420e, (FixedNum)0x0002a4fe, (FixedNum)0x000b6bb2, (FixedNum)0x00bb967a, (FixedNum)0x00000000, (FixedNum)0x00000e25, (FixedNum)0x00001247, (FixedNum)0x00dc8953, (FixedNum)0x00056115, (FixedNum)0x00004f3d, (FixedNum)0x0001a163, (FixedNum)0x00078590, (FixedNum)0xfffffffc, (FixedNum)0x00000634, (FixedNum)0x00000864, (FixedNum)0x00d7a0e1, (FixedNum)0x01e6f4ae, (FixedNum)0x0000586f, (FixedNum)0x0001d855, (FixedNum)0x0006d4b9, (FixedNum)0xfffffffb, (FixedNum)0x00000688, (FixedNum)0x00000896, (FixedNum)0x05038f37, (FixedNum)0x008092dd, (FixedNum)0x0000985b, (FixedNum)0x0002cf7e, (FixedNum)0x00062a17, (FixedNum)0xfffffff0, (FixedNum)0x00001b65, (FixedNum)0x000023a1, (FixedNum)0x053918d2, (FixedNum)0x00fdc964, (FixedNum)0x0000ae2e, (FixedNum)0x00033c42, (FixedNum)0x000542c3, (FixedNum)0xffffffee, (FixedNum)0x00001f3d, (FixedNum)0x00002849, (FixedNum)0x1c4fc87c, (FixedNum)0x0001b795, (FixedNum)0x0001e080, (FixedNum)0x0002a499, (FixedNum)0x00062e14, (FixedNum)0xfffffff3, (FixedNum)0x00001f92, (FixedNum)0x00010b5f, (FixedNum)0x1de89018, (FixedNum)0x000188ca, (FixedNum)0x0001ee45, (FixedNum)0x0002ab11, (FixedNum)0x0004ec9b, (FixedNum)0xfffffffe, (FixedNum)0x00002391, (FixedNum)0x000126de, (FixedNum)0x05429aa2, (FixedNum)0x0000a81a, (FixedNum)0x00006ac9, (FixedNum)0x0000dcd1, (FixedNum)0x000296ad, (FixedNum)0xfffffff2, (FixedNum)0x0000104d, (FixedNum)0x000014cd, (FixedNum)0x041a7131, (FixedNum)0x00009558, (FixedNum)0x000049f9, (FixedNum)0x0000abbd, (FixedNum)0x0002e73d, (FixedNum)0xfffffff0, (FixedNum)0x00000c6a, (FixedNum)0x0000109b, (FixedNum)0x00ef0cfa, (FixedNum)0x000033b2, (FixedNum)0x00001a2f, (FixedNum)0x0000c845, (FixedNum)0x0003122d, (FixedNum)0xfffffffe, (FixedNum)0x000006c6, (FixedNum)0x00000988, (FixedNum)0x00e2f2ff, (FixedNum)0x000035ff, (FixedNum)0x000015f7, (FixedNum)0x0000d201, (FixedNum)0x000344d5, (FixedNum)0xfffffff8, (FixedNum)0x00000726, (FixedNum)0x00000c39, (FixedNum)0x068ebeb8, (FixedNum)0x0000af5d, (FixedNum)0x00009d57, (FixedNum)0x00018ac0, (FixedNum)0x00054ff1, (FixedNum)0xfffffff6, (FixedNum)0x00002515, (FixedNum)0x00002e11, (FixedNum)0x0583628d, (FixedNum)0x0000a94e, (FixedNum)0x000080d0, (FixedNum)0x0004a4e7, (FixedNum)0x00030cf8, (FixedNum)0xfffffffc, (FixedNum)0x00001b68, (FixedNum)0x0000216f, (FixedNum)0x00000000};


const FixedNum **m_sparseWeights[6];

const FixedNum *tmp0_sparseWeights1[1];
const FixedNum tmp1_sparseWeights1_0[129] = {(FixedNum)(0x00020000 >> FIXED_FBITS), (FixedNum)0xfffffbdf, (FixedNum)0xffffffc7, (FixedNum)0xfffffc42, (FixedNum)0xfffffba7, (FixedNum)0xffffff50, (FixedNum)0x00000404, (FixedNum)0x00000201, (FixedNum)0xfffffe50, (FixedNum)0xfffffe9c, (FixedNum)0xffffffec, (FixedNum)0xffffff16, (FixedNum)0xfffffeda, (FixedNum)0xffffff61, (FixedNum)0x00000336, (FixedNum)0x00000235, (FixedNum)0xfffffdb9, (FixedNum)0x00000646, (FixedNum)0x00000811, (FixedNum)0x00000210, (FixedNum)0x00000145, (FixedNum)0x000000bf, (FixedNum)0xfffff806, (FixedNum)0xfffffc72, (FixedNum)0xfffffc59, (FixedNum)0x00000654, (FixedNum)0x0000009b, (FixedNum)0x00000116, (FixedNum)0xfffffe2f, (FixedNum)0x00000004, (FixedNum)0xfffffeeb, (FixedNum)0x00000267, (FixedNum)0x000002d6, (FixedNum)0x00000154, (FixedNum)0x00000000, (FixedNum)0xfffffd20, (FixedNum)0xfffffdc4, (FixedNum)0x00000077, (FixedNum)0x0000027d, (FixedNum)0x000002b0, (FixedNum)0x0000027d, (FixedNum)0xfffffe22, (FixedNum)0x00000000, (FixedNum)0xfffffd63, (FixedNum)0xfffffe41, (FixedNum)0x0000009c, (FixedNum)0x00000321, (FixedNum)0x00000257, (FixedNum)0x000000cb, (FixedNum)0x0000040b, (FixedNum)0x00000002, (FixedNum)0x000001de, (FixedNum)0xfffffe8f, (FixedNum)0x00000081, (FixedNum)0xfffffc86, (FixedNum)0xfffffd0e, (FixedNum)0xfffffcaf, (FixedNum)0x000004f2, (FixedNum)0x00000001, (FixedNum)0x0000022b, (FixedNum)0xfffffeb2, (FixedNum)0x000000cc, (FixedNum)0xfffffc0d, (FixedNum)0xfffffc01, (FixedNum)0xfffffb85, (FixedNum)0xfffffa20, (FixedNum)0xfffffd2e, (FixedNum)0xfffffa41, (FixedNum)0xfffff91a, (FixedNum)0xfffffa6d, (FixedNum)0x00000610, (FixedNum)0x0000028a, (FixedNum)0xfffffd52, (FixedNum)0xfffff91d, (FixedNum)0xfffffcd7, (FixedNum)0xfffffa53, (FixedNum)0xfffff9b7, (FixedNum)0xfffffa45, (FixedNum)0x000006d8, (FixedNum)0x000003f0, (FixedNum)0xfffffe43, (FixedNum)0x00000505, (FixedNum)0x000004a7, (FixedNum)0x00000584, (FixedNum)0xfffffeb1, (FixedNum)0x000001fa, (FixedNum)0xfffffc01, (FixedNum)0xfffffca4, (FixedNum)0xfffffbd5, (FixedNum)0x00000565, (FixedNum)0x0000031b, (FixedNum)0x0000057f, (FixedNum)0xfffffe34, (FixedNum)0x0000016a, (FixedNum)0xfffffc11, (FixedNum)0xfffffcb8, (FixedNum)0xfffffc02, (FixedNum)0xfffffe5b, (FixedNum)0x0000010e, (FixedNum)0xfffff152, (FixedNum)0xfffff739, (FixedNum)0xfffffe8a, (FixedNum)0x0000038f, (FixedNum)0x00000527, (FixedNum)0x0000011f, (FixedNum)0xfffffe97, (FixedNum)0x0000026f, (FixedNum)0xfffff3b8, (FixedNum)0xfffffa34, (FixedNum)0xffffff9f, (FixedNum)0x00000362, (FixedNum)0x0000031d, (FixedNum)0x000000b0, (FixedNum)0x000002d3, (FixedNum)0xffffffce, (FixedNum)0x00000079, (FixedNum)0xfffffa08, (FixedNum)0xffffff19, (FixedNum)0xfffffe84, (FixedNum)0xffffff61, (FixedNum)0xffffff45, (FixedNum)0x00000216, (FixedNum)0xffffff51, (FixedNum)0xfffffea5, (FixedNum)0xfffffdad, (FixedNum)0xfffffd85, (FixedNum)0xfffffebf, (FixedNum)0xffffff97, (FixedNum)0xffffffd6};

const FixedNum *tmp0_sparseWeights2[2];
const FixedNum tmp1_sparseWeights2_0[129] = {(FixedNum)(0x00020000 >> FIXED_FBITS), (FixedNum)0xfffffa4d, (FixedNum)0xffffff91, (FixedNum)0xfffffc26, (FixedNum)0xfffffcfd, (FixedNum)0xffffff4b, (FixedNum)0x00000479, (FixedNum)0x00000300, (FixedNum)0xffffff63, (FixedNum)0xfffffe86, (FixedNum)0xffffffd4, (FixedNum)0x0000002f, (FixedNum)0x000000ba, (FixedNum)0x00000009, (FixedNum)0x00000017, (FixedNum)0x00000012, (FixedNum)0xfffffe4c, (FixedNum)0x0000066d, (FixedNum)0x000002cf, (FixedNum)0x00000081, (FixedNum)0xffffff72, (FixedNum)0xffffffdd, (FixedNum)0xfffffd3e, (FixedNum)0xfffffe3e, (FixedNum)0xfffffcff, (FixedNum)0x000007a3, (FixedNum)0x0000001d, (FixedNum)0x00000015, (FixedNum)0xfffffe4c, (FixedNum)0xffffff78, (FixedNum)0xffffffa9, (FixedNum)0x000000f7, (FixedNum)0x00000119, (FixedNum)0x00000560, (FixedNum)0x00000010, (FixedNum)0xfffffda3, (FixedNum)0xfffffd55, (FixedNum)0x00000045, (FixedNum)0x00000143, (FixedNum)0x00000128, (FixedNum)0x000000ec, (FixedNum)0x000003b2, (FixedNum)0x00000000, (FixedNum)0xfffffdf4, (FixedNum)0xfffffdd9, (FixedNum)0x00000052, (FixedNum)0x000000ea, (FixedNum)0x000000dd, (FixedNum)0xffffffd4, (FixedNum)0x000004f6, (FixedNum)0xfffffffd, (FixedNum)0xfffffe5a, (FixedNum)0xfffffc2f, (FixedNum)0xffffff86, (FixedNum)0x0000001d, (FixedNum)0xffffff54, (FixedNum)0xfffffd8d, (FixedNum)0x000005c8, (FixedNum)0xffffffff, (FixedNum)0xffffff24, (FixedNum)0xfffffcc3, (FixedNum)0xffffffac, (FixedNum)0xffffff95, (FixedNum)0xffffff27, (FixedNum)0xfffffdfb, (FixedNum)0xfffff887, (FixedNum)0xfffffbda, (FixedNum)0xfffff9df, (FixedNum)0xfffff9b8, (FixedNum)0xfffffbd4, (FixedNum)0x00000603, (FixedNum)0x00000398, (FixedNum)0xfffffffc, (FixedNum)0xfffff751, (FixedNum)0xfffffb60, (FixedNum)0xfffff964, (FixedNum)0xfffff973, (FixedNum)0xfffffb56, (FixedNum)0x0000077c, (FixedNum)0x0000050d, (FixedNum)0x000000a9, (FixedNum)0x00000428, (FixedNum)0xffffff2e, (FixedNum)0x000000e0, (FixedNum)0xfffffaab, (FixedNum)0x000001c4, (FixedNum)0xfffffec0, (FixedNum)0xfffffe43, (FixedNum)0xfffffd1e, (FixedNum)0x0000056e, (FixedNum)0xfffffe4a, (FixedNum)0x000000c9, (FixedNum)0xfffff992, (FixedNum)0x0000016b, (FixedNum)0xffffff12, (FixedNum)0xfffffe6e, (FixedNum)0xfffffc09, (FixedNum)0x00000739, (FixedNum)0x00000390, (FixedNum)0xfffff778, (FixedNum)0xfffff948, (FixedNum)0x00000028, (FixedNum)0xffffffef, (FixedNum)0x000000dd, (FixedNum)0xfffffe8a, (FixedNum)0x000008da, (FixedNum)0x000004f6, (FixedNum)0xfffffa62, (FixedNum)0xfffffb2d, (FixedNum)0x000000ea, (FixedNum)0xffffff08, (FixedNum)0x00000014, (FixedNum)0xfffffe6c, (FixedNum)0x00000358, (FixedNum)0xfffffb31, (FixedNum)0xfffffc48, (FixedNum)0xfffff5c4, (FixedNum)0xfffffe5f, (FixedNum)0x00000023, (FixedNum)0xffffffee, (FixedNum)0xffffff1a, (FixedNum)0x000002e4, (FixedNum)0xfffffa9f, (FixedNum)0xfffffa5f, (FixedNum)0xfffffc6a, (FixedNum)0xfffffc38, (FixedNum)0x000000df, (FixedNum)0x0000006e, (FixedNum)0xffffff02};
const FixedNum tmp1_sparseWeights2_1[129] = {(FixedNum)(0x00020000 >> FIXED_FBITS), (FixedNum)0x000000e8, (FixedNum)0xffffffd8, (FixedNum)0x0000023c, (FixedNum)0x00000340, (FixedNum)0x000000aa, (FixedNum)0xfffffeca, (FixedNum)0xffffff3b, (FixedNum)0x00000064, (FixedNum)0x00000254, (FixedNum)0xffffffcd, (FixedNum)0x00000452, (FixedNum)0x0000034b, (FixedNum)0x000000b2, (FixedNum)0xfffffcf0, (FixedNum)0xffffffac, (FixedNum)0x0000000b, (FixedNum)0x00000083, (FixedNum)0xfffff8aa, (FixedNum)0xfffffd58, (FixedNum)0xffffff24, (FixedNum)0xffffffff, (FixedNum)0x000006d1, (FixedNum)0x000001a8, (FixedNum)0xffffff39, (FixedNum)0x000002e0, (FixedNum)0xfffffebc, (FixedNum)0xffffff73, (FixedNum)0xffffffa6, (FixedNum)0x00000001, (FixedNum)0x000002af, (FixedNum)0x00000054, (FixedNum)0xffffffe4, (FixedNum)0x00000529, (FixedNum)0x00000037, (FixedNum)0x0000000e, (FixedNum)0xffffff98, (FixedNum)0xffffffb3, (FixedNum)0x000000f2, (FixedNum)0x00000041, (FixedNum)0x00000035, (FixedNum)0x000007b2, (FixedNum)0x00000001, (FixedNum)0x00000072, (FixedNum)0xffffffc0, (FixedNum)0xffffffce, (FixedNum)0x00000015, (FixedNum)0x00000042, (FixedNum)0x00000082, (FixedNum)0x0000021d, (FixedNum)0xfffffff9, (FixedNum)0xfffffc4d, (FixedNum)0xfffffddd, (FixedNum)0xffffffa2, (FixedNum)0x00000400, (FixedNum)0x000001fe, (FixedNum)0xffffff31, (FixedNum)0x000002f5, (FixedNum)0xfffffffd, (FixedNum)0xfffffd0f, (FixedNum)0xfffffe37, (FixedNum)0xffffffcd, (FixedNum)0x000003b5, (FixedNum)0x000001c8, (FixedNum)0xffffff1d, (FixedNum)0x000000fd, (FixedNum)0xfffffe95, (FixedNum)0x00000210, (FixedNum)0x00000279, (FixedNum)0x0000014f, (FixedNum)0xfffffdd8, (FixedNum)0xffffff1c, (FixedNum)0x00000093, (FixedNum)0x000000e3, (FixedNum)0xfffffeba, (FixedNum)0x00000166, (FixedNum)0x000001af, (FixedNum)0x00000176, (FixedNum)0xfffffe8f, (FixedNum)0xffffff34, (FixedNum)0x0000009c, (FixedNum)0xfffffac5, (FixedNum)0xfffff402, (FixedNum)0xfffff537, (FixedNum)0xfffff69f, (FixedNum)0xfffffde6, (FixedNum)0x000006cb, (FixedNum)0x00000390, (FixedNum)0xffffffed, (FixedNum)0x0000000c, (FixedNum)0xfffff842, (FixedNum)0xfffff78b, (FixedNum)0xfffff7e9, (FixedNum)0xffffff5a, (FixedNum)0x00000549, (FixedNum)0x00000280, (FixedNum)0xfffffed4, (FixedNum)0x000010a4, (FixedNum)0x00000992, (FixedNum)0x00000919, (FixedNum)0x000001cd, (FixedNum)0x00000091, (FixedNum)0xfffffa27, (FixedNum)0xfffffd2d, (FixedNum)0xfffffee4, (FixedNum)0x0000123e, (FixedNum)0x000009b3, (FixedNum)0x00000b01, (FixedNum)0x00000142, (FixedNum)0x0000008a, (FixedNum)0xfffff90d, (FixedNum)0xfffffd72, (FixedNum)0xffffff58, (FixedNum)0xfffffe5c, (FixedNum)0xfffff7a9, (FixedNum)0xfffff8e2, (FixedNum)0xfffff9d2, (FixedNum)0xfffffea6, (FixedNum)0x00000352, (FixedNum)0x000001dc, (FixedNum)0xffffff94, (FixedNum)0xffffff74, (FixedNum)0xfffff864, (FixedNum)0xfffff973, (FixedNum)0xfffffe50, (FixedNum)0xfffffe45, (FixedNum)0x000002fb, (FixedNum)0x000001cc, (FixedNum)0xffffff94};

const FixedNum *tmp0_sparseWeights3[3];
const FixedNum tmp1_sparseWeights3_0[129] = {(FixedNum)(0x00020000 >> FIXED_FBITS), (FixedNum)0xfffffd02, (FixedNum)0x000001a9, (FixedNum)0xfffffd61, (FixedNum)0xfffffc48, (FixedNum)0xfffffb6a, (FixedNum)0x00000174, (FixedNum)0x00000146, (FixedNum)0x00000151, (FixedNum)0x00000fd7, (FixedNum)0x00000217, (FixedNum)0x00001507, (FixedNum)0x00000eb9, (FixedNum)0x0000002c, (FixedNum)0xfffff3f8, (FixedNum)0xfffffbbb, (FixedNum)0xffffff81, (FixedNum)0x000000ce, (FixedNum)0xfffff9fb, (FixedNum)0x00000686, (FixedNum)0xffffff4b, (FixedNum)0xffffffde, (FixedNum)0xfffff90f, (FixedNum)0xfffffcd6, (FixedNum)0xfffffbad, (FixedNum)0x000000ed, (FixedNum)0xfffffe08, (FixedNum)0x00000185, (FixedNum)0xffffff02, (FixedNum)0xffffffc2, (FixedNum)0xfffffdec, (FixedNum)0x00000088, (FixedNum)0x000000ab, (FixedNum)0x00000c04, (FixedNum)0xffffffce, (FixedNum)0xffffff09, (FixedNum)0xfffffe06, (FixedNum)0x0000008e, (FixedNum)0xffffff9d, (FixedNum)0x000000a5, (FixedNum)0x0000004a, (FixedNum)0x00000411, (FixedNum)0x00000000, (FixedNum)0xfffffe8e, (FixedNum)0xfffffe20, (FixedNum)0x0000009b, (FixedNum)0x0000048b, (FixedNum)0x0000012b, (FixedNum)0xfffffe03, (FixedNum)0x0000010c, (FixedNum)0xfffffff2, (FixedNum)0xfffffee5, (FixedNum)0xfffff8e2, (FixedNum)0xfffffd78, (FixedNum)0x00000051, (FixedNum)0x0000010b, (FixedNum)0xfffffdea, (FixedNum)0x000001f8, (FixedNum)0xfffffff9, (FixedNum)0x00000056, (FixedNum)0xfffffa7b, (FixedNum)0xfffffda1, (FixedNum)0xfffffe9e, (FixedNum)0xffffff6a, (FixedNum)0xfffffdda, (FixedNum)0x00000227, (FixedNum)0x00000e76, (FixedNum)0x000003c0, (FixedNum)0x00000115, (FixedNum)0xfffff350, (FixedNum)0x00000368, (FixedNum)0x00000532, (FixedNum)0x000002d6, (FixedNum)0xfffff8b6, (FixedNum)0x00000981, (FixedNum)0xfffffb13, (FixedNum)0xfffff953, (FixedNum)0xffffefcb, (FixedNum)0x00000ca6, (FixedNum)0x00000b72, (FixedNum)0x00000377, (FixedNum)0x0000057b, (FixedNum)0xfffffea0, (FixedNum)0x00000ee3, (FixedNum)0xfffffacb, (FixedNum)0x000002ff, (FixedNum)0xfffff7e7, (FixedNum)0xfffffa28, (FixedNum)0xfffff931, (FixedNum)0x00000390, (FixedNum)0xfffff4a7, (FixedNum)0x000008ce, (FixedNum)0xfffff1d1, (FixedNum)0x00000055, (FixedNum)0xfffffa28, (FixedNum)0xfffffc0b, (FixedNum)0xfffff943, (FixedNum)0x000003eb, (FixedNum)0x0000042a, (FixedNum)0xffffee9d, (FixedNum)0xfffff374, (FixedNum)0xffffff54, (FixedNum)0x0000069a, (FixedNum)0x000002f8, (FixedNum)0xfffffc0e, (FixedNum)0x000004c8, (FixedNum)0x0000027f, (FixedNum)0xfffffddf, (FixedNum)0xfffffad7, (FixedNum)0x00000120, (FixedNum)0x00000719, (FixedNum)0x000003b0, (FixedNum)0xfffffbfd, (FixedNum)0x000001f6, (FixedNum)0xfffff411, (FixedNum)0xfffffde3, (FixedNum)0xffffe402, (FixedNum)0xfffff7b4, (FixedNum)0xfffffe00, (FixedNum)0x0000005e, (FixedNum)0xfffffedf, (FixedNum)0x000003af, (FixedNum)0xfffff541, (FixedNum)0xfffff9f9, (FixedNum)0xfffff675, (FixedNum)0xfffff0eb, (FixedNum)0xfffffedf, (FixedNum)0x00000139, (FixedNum)0xfffffeb6};
const FixedNum tmp1_sparseWeights3_1[129] = {(FixedNum)(0x00020000 >> FIXED_FBITS), (FixedNum)0x00000132, (FixedNum)0x00000016, (FixedNum)0x0000007a, (FixedNum)0x000001cc, (FixedNum)0x0000002f, (FixedNum)0xffffff78, (FixedNum)0x00000095, (FixedNum)0x00000336, (FixedNum)0x00000555, (FixedNum)0x0000000a, (FixedNum)0x0000087c, (FixedNum)0x00000686, (FixedNum)0x00000149, (FixedNum)0xfffff959, (FixedNum)0xffffff9c, (FixedNum)0x000002d2, (FixedNum)0xfffff73e, (FixedNum)0xfffff14c, (FixedNum)0xfffffb20, (FixedNum)0xffffff62, (FixedNum)0xffffffc1, (FixedNum)0x00000740, (FixedNum)0x0000040e, (FixedNum)0x000003b1, (FixedNum)0xfffff660, (FixedNum)0xfffffc50, (FixedNum)0xfffffe7a, (FixedNum)0xffffff75, (FixedNum)0xffffffd7, (FixedNum)0x00000367, (FixedNum)0x000000de, (FixedNum)0x00000088, (FixedNum)0x000000a5, (FixedNum)0xffffffc8, (FixedNum)0x0000062e, (FixedNum)0x000004ab, (FixedNum)0x0000001a, (FixedNum)0xfffffde0, (FixedNum)0xffffffea, (FixedNum)0x00000062, (FixedNum)0xffffff0a, (FixedNum)0xffffffff, (FixedNum)0x00000442, (FixedNum)0x0000033b, (FixedNum)0xffffffd7, (FixedNum)0xfffffbca, (FixedNum)0x00000057, (FixedNum)0x000001e9, (FixedNum)0xfffffc31, (FixedNum)0xfffffff2, (FixedNum)0xffffff7e, (FixedNum)0x00000129, (FixedNum)0xffffff96, (FixedNum)0x00000136, (FixedNum)0x00000203, (FixedNum)0x000001f7, (FixedNum)0xfffffaf8, (FixedNum)0xfffffff9, (FixedNum)0xffffff71, (FixedNum)0x00000190, (FixedNum)0xffffff71, (FixedNum)0x000001c2, (FixedNum)0x0000041a, (FixedNum)0x00000587, (FixedNum)0x00000abe, (FixedNum)0x0000036a, (FixedNum)0x000009ff, (FixedNum)0x00000b57, (FixedNum)0x000008a5, (FixedNum)0xfffff6e9, (FixedNum)0xfffffb2b, (FixedNum)0x000001ca, (FixedNum)0x000006db, (FixedNum)0x000002a4, (FixedNum)0x0000052c, (FixedNum)0x000005fb, (FixedNum)0x00000635, (FixedNum)0xfffffb50, (FixedNum)0xfffffd6d, (FixedNum)0x00000217, (FixedNum)0xfffff9a6, (FixedNum)0xfffff762, (FixedNum)0xfffff7a5, (FixedNum)0xfffffa1d, (FixedNum)0xfffffbe0, (FixedNum)0x000003eb, (FixedNum)0x0000046f, (FixedNum)0x00000403, (FixedNum)0xfffff932, (FixedNum)0xfffff5dc, (FixedNum)0xfffff7d0, (FixedNum)0xfffffad3, (FixedNum)0xfffffd46, (FixedNum)0x00000387, (FixedNum)0x000003a3, (FixedNum)0x00000381, (FixedNum)0x00000553, (FixedNum)0xfffff8b6, (FixedNum)0x00001af4, (FixedNum)0x00000ebd, (FixedNum)0x000002ff, (FixedNum)0xfffff58c, (FixedNum)0xfffffb20, (FixedNum)0x00000039, (FixedNum)0x000001c9, (FixedNum)0xfffff5e0, (FixedNum)0x00001952, (FixedNum)0x00000ae3, (FixedNum)0x0000020a, (FixedNum)0xfffff7e2, (FixedNum)0xfffffe08, (FixedNum)0x00000163, (FixedNum)0xfffffe96, (FixedNum)0xfffffa4b, (FixedNum)0xfffffdac, (FixedNum)0xffffff2b, (FixedNum)0xfffffef3, (FixedNum)0xffffffa8, (FixedNum)0x00000091, (FixedNum)0x0000014d, (FixedNum)0x000000d7, (FixedNum)0xfffffab6, (FixedNum)0x00000191, (FixedNum)0x0000009e, (FixedNum)0xffffffc8, (FixedNum)0xfffffe36, (FixedNum)0xffffff69, (FixedNum)0xffffff51};
const FixedNum tmp1_sparseWeights3_2[129] = {(FixedNum)(0x00020000 >> FIXED_FBITS), (FixedNum)0x00000225, (FixedNum)0x00000045, (FixedNum)0xffffffb1, (FixedNum)0xffffff3e, (FixedNum)0x00000049, (FixedNum)0x0000012f, (FixedNum)0x00000047, (FixedNum)0x0000013f, (FixedNum)0x00000400, (FixedNum)0x00000037, (FixedNum)0x00000309, (FixedNum)0x00000208, (FixedNum)0x000000f4, (FixedNum)0xfffffe4f, (FixedNum)0xffffff91, (FixedNum)0x000001bd, (FixedNum)0xfffff718, (FixedNum)0xfffffc92, (FixedNum)0xfffffe55, (FixedNum)0x00000091, (FixedNum)0xffffffd6, (FixedNum)0x00000230, (FixedNum)0x00000152, (FixedNum)0x00000280, (FixedNum)0xfffff449, (FixedNum)0xfffffebc, (FixedNum)0xffffff32, (FixedNum)0x00000037, (FixedNum)0xfffffff4, (FixedNum)0x0000016c, (FixedNum)0x00000058, (FixedNum)0x00000053, (FixedNum)0xfffffddf, (FixedNum)0xffffffd4, (FixedNum)0x00000416, (FixedNum)0x000003fe, (FixedNum)0x00000068, (FixedNum)0xfffffd02, (FixedNum)0xffffff8e, (FixedNum)0x00000006, (FixedNum)0xfffff9b1, (FixedNum)0xffffffff, (FixedNum)0x0000024d, (FixedNum)0x000002b9, (FixedNum)0x00000045, (FixedNum)0xfffffbe4, (FixedNum)0xffffffa4, (FixedNum)0x00000071, (FixedNum)0xfffffc40, (FixedNum)0xffffffff, (FixedNum)0x000004a5, (FixedNum)0x000004e8, (FixedNum)0x00000108, (FixedNum)0xfffffe27, (FixedNum)0xffffff54, (FixedNum)0x00000114, (FixedNum)0xfffffa79, (FixedNum)0xffffffff, (FixedNum)0x000003bd, (FixedNum)0x000004cc, (FixedNum)0x00000133, (FixedNum)0xfffffec2, (FixedNum)0xffffffd0, (FixedNum)0x000001a5, (FixedNum)0x00000b71, (FixedNum)0x00000450, (FixedNum)0x00000882, (FixedNum)0x0000088a, (FixedNum)0x0000076a, (FixedNum)0xfffffad9, (FixedNum)0xfffffc93, (FixedNum)0xffffffd9, (FixedNum)0x0000072a, (FixedNum)0x00000369, (FixedNum)0x000004b3, (FixedNum)0x000004d8, (FixedNum)0x00000569, (FixedNum)0xfffffef5, (FixedNum)0xffffff67, (FixedNum)0x00000090, (FixedNum)0x00000089, (FixedNum)0x000001ee, (FixedNum)0x00000303, (FixedNum)0x00000596, (FixedNum)0xfffffeef, (FixedNum)0xffffffcf, (FixedNum)0x000000a0, (FixedNum)0x00000138, (FixedNum)0xfffffcab, (FixedNum)0x0000006b, (FixedNum)0x000002c2, (FixedNum)0x00000671, (FixedNum)0xfffffeac, (FixedNum)0xffffff8a, (FixedNum)0x00000085, (FixedNum)0x000002bc, (FixedNum)0xfffff554, (FixedNum)0xfffff6c6, (FixedNum)0x000008d3, (FixedNum)0x00000893, (FixedNum)0x00000115, (FixedNum)0xfffffd9b, (FixedNum)0xfffffeef, (FixedNum)0x0000013b, (FixedNum)0xffffeda3, (FixedNum)0xfffff29c, (FixedNum)0x00000287, (FixedNum)0x0000059b, (FixedNum)0x00000015, (FixedNum)0x0000029d, (FixedNum)0x00000157, (FixedNum)0x000001bf, (FixedNum)0x00000311, (FixedNum)0x0000033c, (FixedNum)0x000007c1, (FixedNum)0x00000967, (FixedNum)0x00000192, (FixedNum)0xfffffe29, (FixedNum)0xfffffefc, (FixedNum)0xffffffa0, (FixedNum)0x00000469, (FixedNum)0x00000345, (FixedNum)0x00000acf, (FixedNum)0x00000341, (FixedNum)0x00000394, (FixedNum)0xfffffca3, (FixedNum)0xfffffdd5, (FixedNum)0xffffff53};

const FixedNum *tmp0_sparseWeights4[4];
const FixedNum tmp1_sparseWeights4_0[129] = {(FixedNum)(0x00020000 >> FIXED_FBITS), (FixedNum)0xffffff07, (FixedNum)0x00000002, (FixedNum)0xfffffdb3, (FixedNum)0xfffffd34, (FixedNum)0xffffff38, (FixedNum)0x00000506, (FixedNum)0x0000009a, (FixedNum)0xfffffd7d, (FixedNum)0x000014bb, (FixedNum)0x0000004a, (FixedNum)0x000013ea, (FixedNum)0x00000ccc, (FixedNum)0x0000023e, (FixedNum)0xfffffa99, (FixedNum)0xfffff93f, (FixedNum)0xfffff8e9, (FixedNum)0x0000045f, (FixedNum)0x00000056, (FixedNum)0x000001be, (FixedNum)0xffffff8a, (FixedNum)0x0000001d, (FixedNum)0xfffffe92, (FixedNum)0xfffffe7b, (FixedNum)0xfffffc1e, (FixedNum)0x000004d6, (FixedNum)0xffffffde, (FixedNum)0x00000082, (FixedNum)0xffffffb3, (FixedNum)0x00000006, (FixedNum)0xffffff05, (FixedNum)0xffffffa9, (FixedNum)0xffffff87, (FixedNum)0x000003c3, (FixedNum)0xffffffd4, (FixedNum)0xfffffe6f, (FixedNum)0xfffffda2, (FixedNum)0x0000001d, (FixedNum)0x000002d9, (FixedNum)0x0000000f, (FixedNum)0xffffff46, (FixedNum)0x000000c8, (FixedNum)0xffffffff, (FixedNum)0xfffffe27, (FixedNum)0xfffffdf7, (FixedNum)0x0000003c, (FixedNum)0x00000c34, (FixedNum)0x000000a6, (FixedNum)0xfffffc9b, (FixedNum)0x00000527, (FixedNum)0xfffffffa, (FixedNum)0x00000059, (FixedNum)0xfffffd17, (FixedNum)0xffffffcc, (FixedNum)0x000000b1, (FixedNum)0xffffff6c, (FixedNum)0xfffffb7f, (FixedNum)0x000005aa, (FixedNum)0xfffffffd, (FixedNum)0x000000c8, (FixedNum)0xfffffd7b, (FixedNum)0x0000004b, (FixedNum)0x00000020, (FixedNum)0xffffff09, (FixedNum)0xfffffc50, (FixedNum)0x0000053b, (FixedNum)0x000000d2, (FixedNum)0x00000282, (FixedNum)0x000000f9, (FixedNum)0xfffffe83, (FixedNum)0x000003d0, (FixedNum)0x00000053, (FixedNum)0xfffffb72, (FixedNum)0xfffffc6b, (FixedNum)0xffffff5b, (FixedNum)0xfffffbb4, (FixedNum)0xfffffae2, (FixedNum)0xfffffa54, (FixedNum)0x000008ff, (FixedNum)0x000004a1, (FixedNum)0xfffffde3, (FixedNum)0x0000058b, (FixedNum)0x000000fa, (FixedNum)0x0000033b, (FixedNum)0xfffffc0e, (FixedNum)0x00000006, (FixedNum)0xffffff37, (FixedNum)0xffffff15, (FixedNum)0xfffffd3c, (FixedNum)0x000005ae, (FixedNum)0xfffffe2c, (FixedNum)0x000000eb, (FixedNum)0xfffff7dd, (FixedNum)0xffffff74, (FixedNum)0xffffffed, (FixedNum)0xffffff61, (FixedNum)0xfffffc49, (FixedNum)0x00000737, (FixedNum)0xfffffc9f, (FixedNum)0xfffff979, (FixedNum)0xfffff889, (FixedNum)0xfffffeac, (FixedNum)0x000007b3, (FixedNum)0x000003c2, (FixedNum)0xfffffe29, (FixedNum)0x000005c0, (FixedNum)0xfffffbee, (FixedNum)0xfffff9c3, (FixedNum)0xfffffa0c, (FixedNum)0xffffff19, (FixedNum)0x00000784, (FixedNum)0x000002ae, (FixedNum)0xfffffd24, (FixedNum)0x00000455, (FixedNum)0xfffffadf, (FixedNum)0xfffffe92, (FixedNum)0xfffff4f0, (FixedNum)0xfffffcdc, (FixedNum)0x0000012b, (FixedNum)0x000000fd, (FixedNum)0xffffff03, (FixedNum)0x000004c7, (FixedNum)0xfffffa55, (FixedNum)0xfffffc73, (FixedNum)0xfffffbe8, (FixedNum)0xfffff91e, (FixedNum)0x000001dc, (FixedNum)0x000001dc, (FixedNum)0xfffffec3};
const FixedNum tmp1_sparseWeights4_1[129] = {(FixedNum)(0x00020000 >> FIXED_FBITS), (FixedNum)0x000002cf, (FixedNum)0x0000000b, (FixedNum)0x000000e7, (FixedNum)0x00000175, (FixedNum)0x000000d8, (FixedNum)0x00000132, (FixedNum)0x000000c8, (FixedNum)0x000001d2, (FixedNum)0x0000115f, (FixedNum)0x0000002e, (FixedNum)0x00000bdc, (FixedNum)0x000006df, (FixedNum)0x0000026e, (FixedNum)0xfffff682, (FixedNum)0xfffffb1e, (FixedNum)0xfffffeb5, (FixedNum)0xfffffe4d, (FixedNum)0xfffff6ce, (FixedNum)0xfffffbb2, (FixedNum)0xffffff35, (FixedNum)0xffffffe8, (FixedNum)0x000005e7, (FixedNum)0x000001a7, (FixedNum)0xffffff5e, (FixedNum)0xfffffd89, (FixedNum)0xfffffdac, (FixedNum)0xfffffea3, (FixedNum)0xffffff95, (FixedNum)0xfffffff9, (FixedNum)0x000002f6, (FixedNum)0x00000067, (FixedNum)0xfffffff8, (FixedNum)0x0000059e, (FixedNum)0xffffffe5, (FixedNum)0xffffffb2, (FixedNum)0xffffffff, (FixedNum)0xffffffd2, (FixedNum)0x000000ed, (FixedNum)0x00000003, (FixedNum)0xffffffbf, (FixedNum)0x000006e4, (FixedNum)0x00000000, (FixedNum)0x00000029, (FixedNum)0x0000001e, (FixedNum)0xffffffe4, (FixedNum)0x0000012b, (FixedNum)0xffffffbd, (FixedNum)0xfffffe84, (FixedNum)0x000002f8, (FixedNum)0xfffffffa, (FixedNum)0xfffffabc, (FixedNum)0xfffffe0c, (FixedNum)0xffffff1b, (FixedNum)0x000002ef, (FixedNum)0x00000106, (FixedNum)0xfffffd6d, (FixedNum)0x00000247, (FixedNum)0xfffffffc, (FixedNum)0xfffffb06, (FixedNum)0xfffffe5a, (FixedNum)0xfffffef0, (FixedNum)0x00000348, (FixedNum)0x00000106, (FixedNum)0xfffffdb2, (FixedNum)0x00000c36, (FixedNum)0x00000238, (FixedNum)0x00000796, (FixedNum)0x000006b3, (FixedNum)0x00000650, (FixedNum)0xfffffa9d, (FixedNum)0xfffffc3a, (FixedNum)0x00000098, (FixedNum)0x0000068b, (FixedNum)0x00000122, (FixedNum)0x000003f3, (FixedNum)0x000003aa, (FixedNum)0x00000484, (FixedNum)0xfffffee8, (FixedNum)0xffffff44, (FixedNum)0x0000012f, (FixedNum)0xffffffef, (FixedNum)0xfffff8f2, (FixedNum)0xfffff723, (FixedNum)0xfffff927, (FixedNum)0xfffffbe4, (FixedNum)0x000003f3, (FixedNum)0x000002ee, (FixedNum)0x00000172, (FixedNum)0xffffffb5, (FixedNum)0xfffff916, (FixedNum)0xfffff5b4, (FixedNum)0xfffff884, (FixedNum)0xfffffcfb, (FixedNum)0x0000045b, (FixedNum)0x000002f9, (FixedNum)0x00000169, (FixedNum)0x000010c9, (FixedNum)0xfffffd49, (FixedNum)0x000006a5, (FixedNum)0x000001bc, (FixedNum)0xffffff29, (FixedNum)0xfffffd3b, (FixedNum)0xfffffee1, (FixedNum)0xffffff85, (FixedNum)0x0000101a, (FixedNum)0xfffffb4b, (FixedNum)0x0000066d, (FixedNum)0x00000138, (FixedNum)0xffffff39, (FixedNum)0xfffffda0, (FixedNum)0xffffff61, (FixedNum)0xffffffca, (FixedNum)0x00000435, (FixedNum)0xfffffc54, (FixedNum)0xfffffa58, (FixedNum)0xfffffbcd, (FixedNum)0xfffffe1d, (FixedNum)0x0000015e, (FixedNum)0x000000bf, (FixedNum)0xffffff0e, (FixedNum)0x0000055b, (FixedNum)0xfffffc66, (FixedNum)0xfffffb12, (FixedNum)0xfffffede, (FixedNum)0xfffffce7, (FixedNum)0x00000106, (FixedNum)0x000000be, (FixedNum)0xfffffef8};
const FixedNum tmp1_sparseWeights4_2[129] = {(FixedNum)(0x00020000 >> FIXED_FBITS), (FixedNum)0x0000057a, (FixedNum)0x00000062, (FixedNum)0x000000d4, (FixedNum)0xffffffff, (FixedNum)0x00000113, (FixedNum)0x00000084, (FixedNum)0xffffff24, (FixedNum)0x00000060, (FixedNum)0x00001790, (FixedNum)0x00000080, (FixedNum)0x00000c2b, (FixedNum)0x000002ee, (FixedNum)0x00000178, (FixedNum)0xfffff4ee, (FixedNum)0xfffffa40, (FixedNum)0xfffffe37, (FixedNum)0xfffffde7, (FixedNum)0xfffffcbf, (FixedNum)0xfffffcde, (FixedNum)0xffffffcf, (FixedNum)0xfffffff1, (FixedNum)0x000000c5, (FixedNum)0xfffffff7, (FixedNum)0xfffffee8, (FixedNum)0xfffffba5, (FixedNum)0xfffffed4, (FixedNum)0xfffffecd, (FixedNum)0xffffffd4, (FixedNum)0xfffffffc, (FixedNum)0x000000a4, (FixedNum)0x00000009, (FixedNum)0xffffffdb, (FixedNum)0xfffffe90, (FixedNum)0xffffffc3, (FixedNum)0xfffffdd1, (FixedNum)0xffffff90, (FixedNum)0x0000000d, (FixedNum)0x000000ab, (FixedNum)0xffffffbe, (FixedNum)0xffffff63, (FixedNum)0xfffffe37, (FixedNum)0xffffffff, (FixedNum)0xfffffe5f, (FixedNum)0xffffffc1, (FixedNum)0x00000031, (FixedNum)0x00000230, (FixedNum)0xffffff0f, (FixedNum)0xfffffcee, (FixedNum)0x0000026b, (FixedNum)0xffffffff, (FixedNum)0xfffffd4e, (FixedNum)0x0000003c, (FixedNum)0x00000019, (FixedNum)0xffffffa3, (FixedNum)0xfffffee2, (FixedNum)0xfffffc6f, (FixedNum)0x00000113, (FixedNum)0xffffffff, (FixedNum)0xfffffcee, (FixedNum)0x00000014, (FixedNum)0x0000000f, (FixedNum)0xfffffff7, (FixedNum)0xfffffeda, (FixedNum)0xfffffcf4, (FixedNum)0x00001137, (FixedNum)0x00000521, (FixedNum)0x0000090f, (FixedNum)0x00000707, (FixedNum)0x00000781, (FixedNum)0xfffff8e2, (FixedNum)0xfffffac6, (FixedNum)0xffffff11, (FixedNum)0x0000092b, (FixedNum)0x000003a7, (FixedNum)0x00000406, (FixedNum)0x000002ee, (FixedNum)0x000003f8, (FixedNum)0xfffffe91, (FixedNum)0xfffffec5, (FixedNum)0x00000050, (FixedNum)0x0000046a, (FixedNum)0x0000006a, (FixedNum)0xfffffec6, (FixedNum)0x0000008d, (FixedNum)0xfffffd3f, (FixedNum)0xffffff76, (FixedNum)0x00000073, (FixedNum)0x00000087, (FixedNum)0x000001fb, (FixedNum)0xffffff7b, (FixedNum)0xfffffc9f, (FixedNum)0xffffffbd, (FixedNum)0xfffffd4e, (FixedNum)0xffffffbb, (FixedNum)0x000000cf, (FixedNum)0x000001ce, (FixedNum)0x0000032b, (FixedNum)0xfffff771, (FixedNum)0xfffffc14, (FixedNum)0xfffffed2, (FixedNum)0xfffffdf5, (FixedNum)0x00000246, (FixedNum)0x00000136, (FixedNum)0x00000080, (FixedNum)0xfffffeab, (FixedNum)0xfffff4de, (FixedNum)0xfffff89b, (FixedNum)0xfffffeca, (FixedNum)0xfffffddf, (FixedNum)0x00000481, (FixedNum)0x000001d6, (FixedNum)0x00000088, (FixedNum)0x00000690, (FixedNum)0x000001a7, (FixedNum)0xffffff7e, (FixedNum)0x000000f9, (FixedNum)0xffffff1c, (FixedNum)0xffffffa5, (FixedNum)0xffffffe2, (FixedNum)0xffffff28, (FixedNum)0x000007b8, (FixedNum)0x000001ad, (FixedNum)0x00000038, (FixedNum)0x0000005d, (FixedNum)0xfffffeef, (FixedNum)0xffffff2e, (FixedNum)0xffffffc3, (FixedNum)0xffffff17};
const FixedNum tmp1_sparseWeights4_3[129] = {(FixedNum)(0x00020000 >> FIXED_FBITS), (FixedNum)0x0000009e, (FixedNum)0xffffff9d, (FixedNum)0x00000076, (FixedNum)0x00000154, (FixedNum)0x00000430, (FixedNum)0x000007f2, (FixedNum)0x0000013c, (FixedNum)0xfffffa1c, (FixedNum)0x00001aa5, (FixedNum)0x00000014, (FixedNum)0x00001166, (FixedNum)0x0000090e, (FixedNum)0x0000042b, (FixedNum)0xfffffc06, (FixedNum)0xfffffa11, (FixedNum)0xfffff209, (FixedNum)0x00000895, (FixedNum)0xfffffe74, (FixedNum)0xfffffeb0, (FixedNum)0xffffff63, (FixedNum)0x00000025, (FixedNum)0x00000232, (FixedNum)0xffffffff, (FixedNum)0xfffffcca, (FixedNum)0x00000914, (FixedNum)0xffffff92, (FixedNum)0xffffffaa, (FixedNum)0xffffffab, (FixedNum)0x0000000b, (FixedNum)0x000000dc, (FixedNum)0x00000001, (FixedNum)0xffffff9c, (FixedNum)0x000003b3, (FixedNum)0xffffff9f, (FixedNum)0xfffffb40, (FixedNum)0xfffffbb3, (FixedNum)0xfffffff6, (FixedNum)0x0000066d, (FixedNum)0x0000009c, (FixedNum)0xffffff58, (FixedNum)0x0000043c, (FixedNum)0xffffffff, (FixedNum)0xfffffc4d, (FixedNum)0xfffffcae, (FixedNum)0x00000037, (FixedNum)0x000013a9, (FixedNum)0x0000020e, (FixedNum)0xfffffca4, (FixedNum)0x00000a59, (FixedNum)0xfffffffa, (FixedNum)0xfffffd49, (FixedNum)0xfffffd10, (FixedNum)0x00000013, (FixedNum)0x000002d6, (FixedNum)0x0000011c, (FixedNum)0xfffffcc9, (FixedNum)0x00000ad2, (FixedNum)0xfffffffd, (FixedNum)0xfffffd4a, (FixedNum)0xfffffc90, (FixedNum)0xfffffff8, (FixedNum)0x0000032f, (FixedNum)0x000000b8, (FixedNum)0xfffffc2d, (FixedNum)0x000004e5, (FixedNum)0xfffffcc6, (FixedNum)0x000000d9, (FixedNum)0x0000009c, (FixedNum)0x00000b53, (FixedNum)0x0000076c, (FixedNum)0xfffffe2c, (FixedNum)0xfffff3e5, (FixedNum)0xfffffa78, (FixedNum)0xfffffb82, (FixedNum)0xfffff946, (FixedNum)0xfffff94b, (FixedNum)0x00000624, (FixedNum)0x00000c1a, (FixedNum)0x000003b5, (FixedNum)0xfffff7c3, (FixedNum)0x00000749, (FixedNum)0xffffff54, (FixedNum)0xfffffcf8, (FixedNum)0xfffffc62, (FixedNum)0x000000d3, (FixedNum)0x000000f9, (FixedNum)0x000000b4, (FixedNum)0xfffffe09, (FixedNum)0x0000097b, (FixedNum)0xfffffec8, (FixedNum)0xfffffc32, (FixedNum)0xfffffb73, (FixedNum)0x00000123, (FixedNum)0x000001b1, (FixedNum)0x0000010d, (FixedNum)0xfffffd48, (FixedNum)0x000010b0, (FixedNum)0xfffff8c8, (FixedNum)0xfffff870, (FixedNum)0xfffff69f, (FixedNum)0xfffffead, (FixedNum)0x00000e01, (FixedNum)0x00000762, (FixedNum)0xfffffd28, (FixedNum)0x00000f03, (FixedNum)0xfffff94c, (FixedNum)0xfffff2e3, (FixedNum)0xfffff787, (FixedNum)0xfffffe95, (FixedNum)0x000010a6, (FixedNum)0x00000683, (FixedNum)0xfffffbe5, (FixedNum)0x0000089e, (FixedNum)0xfffffb83, (FixedNum)0xfffffef1, (FixedNum)0xfffffe6b, (FixedNum)0x000000c2, (FixedNum)0x0000007a, (FixedNum)0x000000a6, (FixedNum)0xffffff77, (FixedNum)0x000007bf, (FixedNum)0xfffffb0d, (FixedNum)0xfffffc07, (FixedNum)0xfffffefe, (FixedNum)0x00000005, (FixedNum)0x000001e7, (FixedNum)0x000001d8, (FixedNum)0x00000079};

const FixedNum *tmp0_sparseWeights5[5];
const FixedNum tmp1_sparseWeights5_0[129] = {(FixedNum)(0x00020000 >> FIXED_FBITS), (FixedNum)0x0000006c, (FixedNum)0x000000a3, (FixedNum)0x000001b5, (FixedNum)0x0000028f, (FixedNum)0xfffffed7, (FixedNum)0x000003dc, (FixedNum)0x00000241, (FixedNum)0xffffff4e, (FixedNum)0x00000f71, (FixedNum)0x000000ff, (FixedNum)0x0000154f, (FixedNum)0x00000ecb, (FixedNum)0x0000012f, (FixedNum)0xfffff87f, (FixedNum)0xfffffb9a, (FixedNum)0xfffffe01, (FixedNum)0xfffffaf6, (FixedNum)0xfffff1d6, (FixedNum)0xffffffea, (FixedNum)0xfffffe6a, (FixedNum)0x00000022, (FixedNum)0xfffffbe8, (FixedNum)0xfffffd36, (FixedNum)0xfffffa41, (FixedNum)0xfffffa57, (FixedNum)0xfffffc6a, (FixedNum)0xffffffbe, (FixedNum)0xfffffefb, (FixedNum)0x00000006, (FixedNum)0xfffffe67, (FixedNum)0xffffff83, (FixedNum)0xffffff57, (FixedNum)0x000006cc, (FixedNum)0xffffffe5, (FixedNum)0x000000c0, (FixedNum)0xfffffe17, (FixedNum)0x00000088, (FixedNum)0xfffffe6a, (FixedNum)0xffffff7f, (FixedNum)0xfffffef5, (FixedNum)0x000003d2, (FixedNum)0x00000000, (FixedNum)0x00000051, (FixedNum)0xfffffe85, (FixedNum)0x000000a6, (FixedNum)0xffffff54, (FixedNum)0xfffffe85, (FixedNum)0xfffffb9c, (FixedNum)0xfffffdd0, (FixedNum)0xfffffff4, (FixedNum)0xfffffc1b, (FixedNum)0xfffffa97, (FixedNum)0xffffff3f, (FixedNum)0x0000003f, (FixedNum)0xffffff36, (FixedNum)0xfffffaad, (FixedNum)0xfffffe46, (FixedNum)0xfffffff8, (FixedNum)0xfffffd4e, (FixedNum)0xfffffb86, (FixedNum)0xffffffd6, (FixedNum)0xffffff83, (FixedNum)0xfffffee8, (FixedNum)0xfffffb69, (FixedNum)0x00000365, (FixedNum)0x00000550, (FixedNum)0x0000013b, (FixedNum)0xfffffff9, (FixedNum)0xfffff655, (FixedNum)0x0000047e, (FixedNum)0x00000465, (FixedNum)0x000001b9, (FixedNum)0xfffff9be, (FixedNum)0x00000113, (FixedNum)0xfffff9f0, (FixedNum)0xfffff999, (FixedNum)0xfffff281, (FixedNum)0x00000cba, (FixedNum)0x00000a51, (FixedNum)0x00000317, (FixedNum)0x000001d1, (FixedNum)0xfffff750, (FixedNum)0xffffffba, (FixedNum)0xfffff2df, (FixedNum)0xfffffe09, (FixedNum)0xfffffd80, (FixedNum)0xfffffe0d, (FixedNum)0xfffffc9c, (FixedNum)0x000007ea, (FixedNum)0xfffff7bb, (FixedNum)0x000003ae, (FixedNum)0xfffff4fb, (FixedNum)0xffffffcd, (FixedNum)0xfffff8ba, (FixedNum)0xfffffb19, (FixedNum)0xfffffa4e, (FixedNum)0x00000590, (FixedNum)0x00000222, (FixedNum)0xfffffabe, (FixedNum)0xfffff6af, (FixedNum)0xfffffdd1, (FixedNum)0x000000b4, (FixedNum)0x000003fe, (FixedNum)0x000000b7, (FixedNum)0x00000615, (FixedNum)0x0000002e, (FixedNum)0x00000663, (FixedNum)0xfffffc37, (FixedNum)0xffffff50, (FixedNum)0xffffff54, (FixedNum)0x000002c3, (FixedNum)0x000000c3, (FixedNum)0x00000198, (FixedNum)0xfffff583, (FixedNum)0xfffff971, (FixedNum)0xffffee7d, (FixedNum)0xfffffadf, (FixedNum)0x00000090, (FixedNum)0x000000ea, (FixedNum)0xfffffefe, (FixedNum)0x00000218, (FixedNum)0xfffff6db, (FixedNum)0xfffff594, (FixedNum)0xfffff98b, (FixedNum)0xfffff577, (FixedNum)0x00000125, (FixedNum)0x0000018d, (FixedNum)0xffffff0b};
const FixedNum tmp1_sparseWeights5_1[129] = {(FixedNum)(0x00020000 >> FIXED_FBITS), (FixedNum)0x0000016c, (FixedNum)0x0000005c, (FixedNum)0x000002a9, (FixedNum)0x000002fb, (FixedNum)0xffffffaa, (FixedNum)0xffffff14, (FixedNum)0x0000008a, (FixedNum)0x00000238, (FixedNum)0x000007db, (FixedNum)0x0000005a, (FixedNum)0x00000e03, (FixedNum)0x00000994, (FixedNum)0x000001c9, (FixedNum)0xfffff7a7, (FixedNum)0xfffffe1d, (FixedNum)0x000000a7, (FixedNum)0xfffff56d, (FixedNum)0xfffff2b4, (FixedNum)0xfffffb86, (FixedNum)0xffffff5c, (FixedNum)0xffffffdd, (FixedNum)0x00000721, (FixedNum)0x00000303, (FixedNum)0x000002cc, (FixedNum)0xfffff520, (FixedNum)0xfffffccb, (FixedNum)0xfffffea6, (FixedNum)0xffffff93, (FixedNum)0xffffffec, (FixedNum)0x00000325, (FixedNum)0x0000009c, (FixedNum)0x0000005b, (FixedNum)0xffffff85, (FixedNum)0xffffffdc, (FixedNum)0x00000646, (FixedNum)0x000003ce, (FixedNum)0x0000004f, (FixedNum)0xfffffddd, (FixedNum)0xffffffd1, (FixedNum)0x0000001f, (FixedNum)0xfffffff0, (FixedNum)0x00000000, (FixedNum)0x000004b6, (FixedNum)0x000002a4, (FixedNum)0x00000016, (FixedNum)0xfffff9f8, (FixedNum)0xffffff5e, (FixedNum)0x000000c3, (FixedNum)0xfffffa05, (FixedNum)0xfffffff5, (FixedNum)0xfffffe99, (FixedNum)0x000000ab, (FixedNum)0xffffffda, (FixedNum)0x000002a6, (FixedNum)0x00000212, (FixedNum)0x0000022c, (FixedNum)0xfffff980, (FixedNum)0xfffffffb, (FixedNum)0xfffffea6, (FixedNum)0x000000de, (FixedNum)0xffffffdf, (FixedNum)0x000002d0, (FixedNum)0x0000028d, (FixedNum)0x000002bc, (FixedNum)0x000006c3, (FixedNum)0x000003b3, (FixedNum)0x000008fe, (FixedNum)0x000009f6, (FixedNum)0x000004a4, (FixedNum)0xfffffa1e, (FixedNum)0xfffffcd0, (FixedNum)0x000000c8, (FixedNum)0x000002d7, (FixedNum)0x0000029c, (FixedNum)0x000003ad, (FixedNum)0x0000044e, (FixedNum)0x000001f8, (FixedNum)0xfffffdc9, (FixedNum)0xfffffef9, (FixedNum)0x0000012b, (FixedNum)0xfffff5d4, (FixedNum)0xfffff448, (FixedNum)0xfffff76e, (FixedNum)0xfffffac5, (FixedNum)0xfffffde7, (FixedNum)0x00000499, (FixedNum)0x0000034f, (FixedNum)0x0000036f, (FixedNum)0xfffffacd, (FixedNum)0xfffff639, (FixedNum)0xfffffc0d, (FixedNum)0xffffff00, (FixedNum)0xffffffc4, (FixedNum)0x00000117, (FixedNum)0x000000e3, (FixedNum)0x000001c4, (FixedNum)0x00000297, (FixedNum)0xfffffcf9, (FixedNum)0x000015ba, (FixedNum)0x0000094e, (FixedNum)0x00000222, (FixedNum)0xfffff7de, (FixedNum)0xfffffbed, (FixedNum)0xffffffe1, (FixedNum)0xffffff74, (FixedNum)0xfffffa9e, (FixedNum)0x00001552, (FixedNum)0x00000700, (FixedNum)0x00000191, (FixedNum)0xfffff990, (FixedNum)0xfffffd55, (FixedNum)0xffffffdb, (FixedNum)0xfffffad5, (FixedNum)0xfffff7d9, (FixedNum)0xfffffdb3, (FixedNum)0x00000009, (FixedNum)0xffffffd0, (FixedNum)0x0000018e, (FixedNum)0x00000162, (FixedNum)0x00000155, (FixedNum)0xfffffd8f, (FixedNum)0xfffff8d0, (FixedNum)0x0000000a, (FixedNum)0x0000008c, (FixedNum)0x000000a3, (FixedNum)0x00000009, (FixedNum)0x00000067, (FixedNum)0x000000ae};
const FixedNum tmp1_sparseWeights5_2[129] = {(FixedNum)(0x00020000 >> FIXED_FBITS), (FixedNum)0x000003cb, (FixedNum)0x0000010c, (FixedNum)0x00000221, (FixedNum)0x00000181, (FixedNum)0x00000012, (FixedNum)0x0000005f, (FixedNum)0x000000d1, (FixedNum)0x00000192, (FixedNum)0x00000c3d, (FixedNum)0x00000106, (FixedNum)0x00000c32, (FixedNum)0x000004f4, (FixedNum)0x00000115, (FixedNum)0xfffff904, (FixedNum)0xffffff5b, (FixedNum)0x00000150, (FixedNum)0xfffff08d, (FixedNum)0xfffff7b9, (FixedNum)0xfffffb7c, (FixedNum)0xffffffc4, (FixedNum)0xffffffd8, (FixedNum)0x000004a0, (FixedNum)0x00000277, (FixedNum)0x00000328, (FixedNum)0xffffedda, (FixedNum)0xfffffd8f, (FixedNum)0xfffffe46, (FixedNum)0xffffffc2, (FixedNum)0xfffffff3, (FixedNum)0x00000267, (FixedNum)0x0000008f, (FixedNum)0x00000065, (FixedNum)0x00000069, (FixedNum)0xffffffe5, (FixedNum)0x000004d6, (FixedNum)0x000003f9, (FixedNum)0x000000c0, (FixedNum)0xfffffcef, (FixedNum)0xffffffaa, (FixedNum)0x00000002, (FixedNum)0xfffffc5b, (FixedNum)0x00000000, (FixedNum)0x000002c3, (FixedNum)0x00000286, (FixedNum)0x00000080, (FixedNum)0xfffffd0c, (FixedNum)0x0000003a, (FixedNum)0x0000008d, (FixedNum)0xfffff91f, (FixedNum)0xfffffffe, (FixedNum)0x0000014b, (FixedNum)0x00000344, (FixedNum)0x000000b5, (FixedNum)0xffffff2f, (FixedNum)0x000000a8, (FixedNum)0x000001d6, (FixedNum)0xfffff7c9, (FixedNum)0xfffffffe, (FixedNum)0x00000093, (FixedNum)0x00000311, (FixedNum)0x0000011d, (FixedNum)0xffffff88, (FixedNum)0x000000c7, (FixedNum)0x000001c1, (FixedNum)0x00000b33, (FixedNum)0x00000991, (FixedNum)0x00000933, (FixedNum)0x0000092c, (FixedNum)0x0000045e, (FixedNum)0xfffffac5, (FixedNum)0xfffffd09, (FixedNum)0x00000028, (FixedNum)0x00000407, (FixedNum)0x000006c0, (FixedNum)0x00000264, (FixedNum)0x0000029b, (FixedNum)0x00000079, (FixedNum)0x0000004d, (FixedNum)0x000000d9, (FixedNum)0x00000131, (FixedNum)0xfffff784, (FixedNum)0xfffffb8e, (FixedNum)0xfffffc60, (FixedNum)0xffffffdb, (FixedNum)0xfffffe4b, (FixedNum)0x00000238, (FixedNum)0x0000025d, (FixedNum)0x00000259, (FixedNum)0xfffffc1f, (FixedNum)0xfffffd81, (FixedNum)0x0000016b, (FixedNum)0x0000053b, (FixedNum)0xffffffe5, (FixedNum)0xfffffd46, (FixedNum)0xffffff9d, (FixedNum)0x000001d2, (FixedNum)0xfffffaa9, (FixedNum)0xfffffecf, (FixedNum)0x00000c28, (FixedNum)0x000007c4, (FixedNum)0x0000011b, (FixedNum)0xfffffc62, (FixedNum)0x0000003f, (FixedNum)0x0000018a, (FixedNum)0xfffff2bf, (FixedNum)0xfffff9e9, (FixedNum)0x000007eb, (FixedNum)0x000005b9, (FixedNum)0x00000093, (FixedNum)0x0000015e, (FixedNum)0x00000231, (FixedNum)0x00000141, (FixedNum)0xfffffdc2, (FixedNum)0xffffff40, (FixedNum)0x000003ea, (FixedNum)0x00000682, (FixedNum)0x0000014f, (FixedNum)0xffffff5b, (FixedNum)0x00000055, (FixedNum)0x000000a7, (FixedNum)0x00000179, (FixedNum)0x000000f2, (FixedNum)0x000006b1, (FixedNum)0x00000277, (FixedNum)0x00000348, (FixedNum)0xfffffcfa, (FixedNum)0xfffffeb3, (FixedNum)0x00000029};
const FixedNum tmp1_sparseWeights5_3[129] = {(FixedNum)(0x00020000 >> FIXED_FBITS), (FixedNum)0x00000072, (FixedNum)0x000000ec, (FixedNum)0x0000038f, (FixedNum)0x0000034e, (FixedNum)0x000000c9, (FixedNum)0x00000453, (FixedNum)0x000002da, (FixedNum)0x00000064, (FixedNum)0x000018b5, (FixedNum)0x00000174, (FixedNum)0x0000257c, (FixedNum)0x0000195e, (FixedNum)0x00000506, (FixedNum)0xfffff250, (FixedNum)0xfffff832, (FixedNum)0xfffffbb7, (FixedNum)0xffffe9d1, (FixedNum)0xffffe728, (FixedNum)0xfffff67c, (FixedNum)0xfffffca8, (FixedNum)0x0000000d, (FixedNum)0x000004eb, (FixedNum)0x00000189, (FixedNum)0xffffff64, (FixedNum)0xffffe9d3, (FixedNum)0xfffffa3e, (FixedNum)0xfffffd23, (FixedNum)0xfffffe18, (FixedNum)0x00000000, (FixedNum)0x00000207, (FixedNum)0x0000004e, (FixedNum)0xffffffe7, (FixedNum)0xfffffce2, (FixedNum)0x00000009, (FixedNum)0xffffff06, (FixedNum)0xfffffb28, (FixedNum)0xffffffea, (FixedNum)0x0000008a, (FixedNum)0x00000024, (FixedNum)0xffffff3e, (FixedNum)0x000000dc, (FixedNum)0x00000000, (FixedNum)0xffffffda, (FixedNum)0xfffffc86, (FixedNum)0x00000020, (FixedNum)0x00000045, (FixedNum)0xffffff54, (FixedNum)0xfffffb4f, (FixedNum)0xfffff9fb, (FixedNum)0xfffffff5, (FixedNum)0xfffff7f2, (FixedNum)0xfffffa2e, (FixedNum)0x0000000c, (FixedNum)0xffffff3c, (FixedNum)0x0000010c, (FixedNum)0xfffffd73, (FixedNum)0xffffface, (FixedNum)0xfffffff9, (FixedNum)0xfffff826, (FixedNum)0xfffff9ca, (FixedNum)0xffffffdb, (FixedNum)0xfffffe3d, (FixedNum)0xffffffe2, (FixedNum)0xfffffb8b, (FixedNum)0x00000010, (FixedNum)0x000003b2, (FixedNum)0xffffff6d, (FixedNum)0x000000ad, (FixedNum)0xfffffbf0, (FixedNum)0x000003e3, (FixedNum)0x0000030e, (FixedNum)0x0000005c, (FixedNum)0xfffff024, (FixedNum)0xfffffa25, (FixedNum)0xfffff103, (FixedNum)0xfffff29e, (FixedNum)0xfffff217, (FixedNum)0x00000d2d, (FixedNum)0x00000a18, (FixedNum)0x0000045e, (FixedNum)0xfffff13c, (FixedNum)0xfffff09b, (FixedNum)0xffffef70, (FixedNum)0xffffe942, (FixedNum)0xfffffbaf, (FixedNum)0x000004c4, (FixedNum)0x0000055c, (FixedNum)0x000006e1, (FixedNum)0x00000fdd, (FixedNum)0xfffffcdd, (FixedNum)0x00000417, (FixedNum)0xfffffa60, (FixedNum)0x00000274, (FixedNum)0xffffefdd, (FixedNum)0xfffff7f4, (FixedNum)0xffffff06, (FixedNum)0x00000dd7, (FixedNum)0x00000826, (FixedNum)0x00000b09, (FixedNum)0xfffff818, (FixedNum)0xfffffe63, (FixedNum)0xfffff6b6, (FixedNum)0x00000412, (FixedNum)0x000000dd, (FixedNum)0x0000097b, (FixedNum)0x0000053a, (FixedNum)0x0000106c, (FixedNum)0xfffffcb8, (FixedNum)0xffffff92, (FixedNum)0xfffff8dc, (FixedNum)0x00000330, (FixedNum)0xffffffa5, (FixedNum)0xfffffc75, (FixedNum)0xfffff7b1, (FixedNum)0xfffff71c, (FixedNum)0xfffff5ce, (FixedNum)0xfffffe6e, (FixedNum)0x00000251, (FixedNum)0x0000054b, (FixedNum)0x0000037f, (FixedNum)0x0000043d, (FixedNum)0xfffffcad, (FixedNum)0xfffff4e2, (FixedNum)0xfffffc39, (FixedNum)0xfffffba0, (FixedNum)0xfffffe43, (FixedNum)0x0000037c, (FixedNum)0x00000376};
const FixedNum tmp1_sparseWeights5_4[129] = {(FixedNum)(0x00020000 >> FIXED_FBITS), (FixedNum)0xfffffbe1, (FixedNum)0x00000149, (FixedNum)0x000002f2, (FixedNum)0x00000475, (FixedNum)0xfffffd51, (FixedNum)0xfffffcad, (FixedNum)0xffffff10, (FixedNum)0x000006e4, (FixedNum)0xfffff1b1, (FixedNum)0x000000b2, (FixedNum)0x00000676, (FixedNum)0x0000079f, (FixedNum)0xffffff68, (FixedNum)0xfffffd43, (FixedNum)0x00000477, (FixedNum)0x000009b3, (FixedNum)0xffffea80, (FixedNum)0xfffff947, (FixedNum)0xfffff94a, (FixedNum)0xfffffdfc, (FixedNum)0xffffffcb, (FixedNum)0x00000a4d, (FixedNum)0x00000315, (FixedNum)0x000002c9, (FixedNum)0xffffebe5, (FixedNum)0xfffffea1, (FixedNum)0xfffffe28, (FixedNum)0xffffff04, (FixedNum)0xfffffff1, (FixedNum)0x0000041a, (FixedNum)0x00000095, (FixedNum)0x00000051, (FixedNum)0xfffff027, (FixedNum)0x0000002d, (FixedNum)0x00000006, (FixedNum)0x0000009f, (FixedNum)0xffffffbc, (FixedNum)0xfffffd8c, (FixedNum)0xffffffea, (FixedNum)0x00000059, (FixedNum)0xfffff5dd, (FixedNum)0x00000001, (FixedNum)0x000001b4, (FixedNum)0x0000014f, (FixedNum)0xffffffce, (FixedNum)0xfffff425, (FixedNum)0xffffff01, (FixedNum)0x000001b4, (FixedNum)0xfffff5cd, (FixedNum)0x00000005, (FixedNum)0xfffffe89, (FixedNum)0xffffff26, (FixedNum)0xffffff93, (FixedNum)0xffffff5d, (FixedNum)0xfffffebf, (FixedNum)0x00000149, (FixedNum)0xfffff670, (FixedNum)0x00000003, (FixedNum)0xffffff09, (FixedNum)0xffffff96, (FixedNum)0xffffff92, (FixedNum)0xfffffe28, (FixedNum)0xfffffe51, (FixedNum)0x00000108, (FixedNum)0xfffffb7e, (FixedNum)0x0000065e, (FixedNum)0x00000485, (FixedNum)0x00000787, (FixedNum)0xfffff86f, (FixedNum)0xfffffc55, (FixedNum)0x000002c1, (FixedNum)0x0000088e, (FixedNum)0xfffffae3, (FixedNum)0x000004aa, (FixedNum)0x00000078, (FixedNum)0x0000025c, (FixedNum)0xfffff606, (FixedNum)0x0000009c, (FixedNum)0x00000493, (FixedNum)0x00000865, (FixedNum)0xffffed4b, (FixedNum)0xfffff846, (FixedNum)0xfffff70b, (FixedNum)0xfffff631, (FixedNum)0xfffffcf2, (FixedNum)0x0000066c, (FixedNum)0x000003ae, (FixedNum)0x0000036d, (FixedNum)0x0000075a, (FixedNum)0x000003d5, (FixedNum)0x00000c27, (FixedNum)0x00000438, (FixedNum)0x00000117, (FixedNum)0xfffff2d9, (FixedNum)0xfffff6e1, (FixedNum)0xfffffdda, (FixedNum)0xfffff971, (FixedNum)0x00000cc9, (FixedNum)0x00000d88, (FixedNum)0x00000564, (FixedNum)0x00000063, (FixedNum)0xffffeeea, (FixedNum)0xfffffae0, (FixedNum)0x000003ad, (FixedNum)0xfffff447, (FixedNum)0x000009a9, (FixedNum)0x00000fae, (FixedNum)0x000003e0, (FixedNum)0x00000024, (FixedNum)0xfffff0e7, (FixedNum)0xfffffc8e, (FixedNum)0x0000057d, (FixedNum)0xfffff743, (FixedNum)0xffffff3a, (FixedNum)0xffffff66, (FixedNum)0xfffffcf6, (FixedNum)0xfffffecc, (FixedNum)0x0000006d, (FixedNum)0xffffff9b, (FixedNum)0x00000114, (FixedNum)0x0000011a, (FixedNum)0x000003b8, (FixedNum)0x00000407, (FixedNum)0xffffffc3, (FixedNum)0x0000002f, (FixedNum)0xfffffaaf, (FixedNum)0xfffffb5c, (FixedNum)0xffffffa6};

const int **m_sparseIndices[6];

const int *tmp0_sparseIndices1[1];
const int tmp1_sparseIndices1_0[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};

const int *tmp0_sparseIndices2[2];
const int tmp1_sparseIndices2_0[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
const int tmp1_sparseIndices2_1[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};

const int *tmp0_sparseIndices3[3];
const int tmp1_sparseIndices3_0[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
const int tmp1_sparseIndices3_1[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
const int tmp1_sparseIndices3_2[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};

const int *tmp0_sparseIndices4[4];
const int tmp1_sparseIndices4_0[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
const int tmp1_sparseIndices4_1[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
const int tmp1_sparseIndices4_2[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
const int tmp1_sparseIndices4_3[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};

const int *tmp0_sparseIndices5[5];
const int tmp1_sparseIndices5_0[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
const int tmp1_sparseIndices5_1[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
const int tmp1_sparseIndices5_2[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
const int tmp1_sparseIndices5_3[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
const int tmp1_sparseIndices5_4[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};

const FixedNum *m_b[6];
const FixedNum tmp_m_b1[1] = {(FixedNum)0xfffffb93};
const FixedNum tmp_m_b2[2] = {(FixedNum)0x00000bd6, (FixedNum)0x00001c96};
const FixedNum tmp_m_b3[3] = {(FixedNum)0xffffe9b5, (FixedNum)0x00000544, (FixedNum)0xffffeb89};
const FixedNum tmp_m_b4[4] = {(FixedNum)0x000007f7, (FixedNum)0x00000c27, (FixedNum)0xffffe046, (FixedNum)0x00003ff5};
const FixedNum tmp_m_b5[5] = {(FixedNum)0xffffe1a8, (FixedNum)0xfffffbc9, (FixedNum)0xfffff712, (FixedNum)0xfffffcb5, (FixedNum)0xffffde99};

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
 * Output number 1 means that the instance was classified as 2
 * Output number 2 means that the instance was classified as 3
 * Output number 3 means that the instance was classified as 4
 * Output number 4 means that the instance was classified as 5
 * Output number 5 means that the instance was classified as 6
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
	return indMax+1;
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


	m_b[0] = NULL;
	m_b[1] = tmp_m_b1;
	m_b[2] = tmp_m_b2;
	m_b[3] = tmp_m_b3;
	m_b[4] = tmp_m_b4;
	m_b[5] = tmp_m_b5;
}
