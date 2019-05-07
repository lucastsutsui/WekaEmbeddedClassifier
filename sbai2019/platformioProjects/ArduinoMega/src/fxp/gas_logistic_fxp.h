//
// #include <Arduino.h>
//
// #define TOTAL_BITS 32
// #define FIXED_FBITS 10
// #define SIGNED
// #define OVERFLOW_DETECT
// #include "FixedNum.h"
//
// #define INPUT_SIZE 128
// #define NUM_CLASSES 6
// #define SELECTED_ATT_SIZE 128
// #define NUM_PREDICTORS 128
// #define CLASS_INDEX 128
//
// /* Instance array must be global
//  * Attributes MUST be sorted in instance array in the following order:
//  * V1
//  * V2
//  * V3
//  * V4
//  * V5
//  * V6
//  * V7
//  * V8
//  * V9
//  * V10
//  * V11
//  * V12
//  * V13
//  * V14
//  * V15
//  * V16
//  * V17
//  * V18
//  * V19
//  * V20
//  * V21
//  * V22
//  * V23
//  * V24
//  * V25
//  * V26
//  * V27
//  * V28
//  * V29
//  * V30
//  * V31
//  * V32
//  * V33
//  * V34
//  * V35
//  * V36
//  * V37
//  * V38
//  * V39
//  * V40
//  * V41
//  * V42
//  * V43
//  * V44
//  * V45
//  * V46
//  * V47
//  * V48
//  * V49
//  * V50
//  * V51
//  * V52
//  * V53
//  * V54
//  * V55
//  * V56
//  * V57
//  * V58
//  * V59
//  * V60
//  * V61
//  * V62
//  * V63
//  * V64
//  * V65
//  * V66
//  * V67
//  * V68
//  * V69
//  * V70
//  * V71
//  * V72
//  * V73
//  * V74
//  * V75
//  * V76
//  * V77
//  * V78
//  * V79
//  * V80
//  * V81
//  * V82
//  * V83
//  * V84
//  * V85
//  * V86
//  * V87
//  * V88
//  * V89
//  * V90
//  * V91
//  * V92
//  * V93
//  * V94
//  * V95
//  * V96
//  * V97
//  * V98
//  * V99
//  * V100
//  * V101
//  * V102
//  * V103
//  * V104
//  * V105
//  * V106
//  * V107
//  * V108
//  * V109
//  * V110
//  * V111
//  * V112
//  * V113
//  * V114
//  * V115
//  * V116
//  * V117
//  * V118
//  * V119
//  * V120
//  * V121
//  * V122
//  * V123
//  * V124
//  * V125
//  * V126
//  * V127
//  * V128
//  */
// FixedNum instance[INPUT_SIZE+1];
// const FixedNum m_Par[129][5] = {{(FixedNum)0x00008f3b, (FixedNum)0xffff6a60, (FixedNum)0xfffeb470, (FixedNum)0xffffa5dd, (FixedNum)0x0000ada7}, {(FixedNum)0xffffffff, (FixedNum)0x00000000, (FixedNum)0xfffffffe, (FixedNum)0x00000000, (FixedNum)0x00000000}, {(FixedNum)0x000009aa, (FixedNum)0x0000156e, (FixedNum)0xfffffd7e, (FixedNum)0x00001465, (FixedNum)0x00001140}, {(FixedNum)0x00001d92, (FixedNum)0x000024fd, (FixedNum)0xfffffcfb, (FixedNum)0xffffbe0a, (FixedNum)0x000028c4}, {(FixedNum)0x00000b96, (FixedNum)0xfffff1c0, (FixedNum)0x00000675, (FixedNum)0x00001ff5, (FixedNum)0xfffff462}, {(FixedNum)0xfffff3e4, (FixedNum)0xfffffb10, (FixedNum)0xfffff624, (FixedNum)0xfffff2c4, (FixedNum)0xfffff8de}, {(FixedNum)0x00001626, (FixedNum)0x0000161b, (FixedNum)0xffffb566, (FixedNum)0xfffff68a, (FixedNum)0x00000ed3}, {(FixedNum)0xfffff692, (FixedNum)0xfffffaf9, (FixedNum)0x0000098a, (FixedNum)0xfffffa57, (FixedNum)0xfffff389}, {(FixedNum)0x00000146, (FixedNum)0x00000005, (FixedNum)0x000002cb, (FixedNum)0x00000197, (FixedNum)0x00000386}, {(FixedNum)0xffffffff, (FixedNum)0x00000001, (FixedNum)0x00000004, (FixedNum)0xfffffffd, (FixedNum)0x00000003}, {(FixedNum)0xfffffa64, (FixedNum)0x0000005a, (FixedNum)0xffffcf78, (FixedNum)0xfffff0ce, (FixedNum)0x00000143}, {(FixedNum)0xffffde3a, (FixedNum)0xfffffd0f, (FixedNum)0xffffe872, (FixedNum)0xffffde92, (FixedNum)0xffffcd6e}, {(FixedNum)0xffffeeae, (FixedNum)0xfffff88b, (FixedNum)0x00000492, (FixedNum)0xffffef29, (FixedNum)0xfffff852}, {(FixedNum)0x000005dc, (FixedNum)0x0000040b, (FixedNum)0x00000267, (FixedNum)0x00000aed, (FixedNum)0x00000b06}, {(FixedNum)0xffffb4d0, (FixedNum)0xfffff167, (FixedNum)0x000003d6, (FixedNum)0xffff8f07, (FixedNum)0xffffef27}, {(FixedNum)0x00000cd8, (FixedNum)0x000003b7, (FixedNum)0x00000019, (FixedNum)0x00001460, (FixedNum)0x00000750}, {(FixedNum)0xffffff75, (FixedNum)0x000000b7, (FixedNum)0x00000017, (FixedNum)0xfffffede, (FixedNum)0xfffffe2d}, {(FixedNum)0x00000004, (FixedNum)0xfffffff7, (FixedNum)0xfffffff0, (FixedNum)0x00000003, (FixedNum)0x00000009}, {(FixedNum)0x00004700, (FixedNum)0x00008312, (FixedNum)0xffff89a8, (FixedNum)0x00003555, (FixedNum)0x00003c5f}, {(FixedNum)0x00008ae0, (FixedNum)0xffff3861, (FixedNum)0x00001f35, (FixedNum)0xffffb9cb, (FixedNum)0x000039d0}, {(FixedNum)0x0000314e, (FixedNum)0x0000a7ec, (FixedNum)0x00004c76, (FixedNum)0x000017f4, (FixedNum)0x00005876}, {(FixedNum)0x00000915, (FixedNum)0xfffffc78, (FixedNum)0x000002d1, (FixedNum)0xfffffcc9, (FixedNum)0xfffffd0d}, {(FixedNum)0x000059df, (FixedNum)0x00019a90, (FixedNum)0x00003fa6, (FixedNum)0x00009acb, (FixedNum)0x0000679d}, {(FixedNum)0x0000be76, (FixedNum)0x00003ef0, (FixedNum)0x00003631, (FixedNum)0xffffaa81, (FixedNum)0xffffecf8}, {(FixedNum)0x00000ac9, (FixedNum)0x000007eb, (FixedNum)0xfffffc92, (FixedNum)0x0000057d, (FixedNum)0x00000a61}, {(FixedNum)0x00000001, (FixedNum)0xfffffff3, (FixedNum)0x0000000f, (FixedNum)0x00000021, (FixedNum)0x00000008}, {(FixedNum)0xfffffe51, (FixedNum)0x000047bf, (FixedNum)0x0000c312, (FixedNum)0xffff8292, (FixedNum)0x00008276}, {(FixedNum)0xffffaaaf, (FixedNum)0x000074c4, (FixedNum)0x0001a7b5, (FixedNum)0x0000bd44, (FixedNum)0x00000470}, {(FixedNum)0x00006482, (FixedNum)0x0000518f, (FixedNum)0x00002575, (FixedNum)0xfffffbd4, (FixedNum)0x00002b23}, {(FixedNum)0xfffffe8a, (FixedNum)0xfffffdef, (FixedNum)0xfffffcd6, (FixedNum)0xfffffb46, (FixedNum)0xfffff68d}, {(FixedNum)0x0000b315, (FixedNum)0xffff9f95, (FixedNum)0xffff239f, (FixedNum)0x000048ad, (FixedNum)0x0000cb59}, {(FixedNum)0x000033ab, (FixedNum)0xffffd602, (FixedNum)0x00000463, (FixedNum)0xffffdba7, (FixedNum)0xfffffd4d}, {(FixedNum)0xfffff58d, (FixedNum)0x00000414, (FixedNum)0x00000408, (FixedNum)0x000009af, (FixedNum)0x00000097}, {(FixedNum)0x00000041, (FixedNum)0x000000bb, (FixedNum)0xffffffd7, (FixedNum)0x00000008, (FixedNum)0x00000010}, {(FixedNum)0x000013e7, (FixedNum)0x0000b15a, (FixedNum)0x0000ae63, (FixedNum)0xffff0765, (FixedNum)0xffff910d}, {(FixedNum)0xfffde8ea, (FixedNum)0xfffc5730, (FixedNum)0x00053fd1, (FixedNum)0xfffa2dc7, (FixedNum)0x0001a533}, {(FixedNum)0x00004217, (FixedNum)0xffff7adf, (FixedNum)0xffffa23d, (FixedNum)0x0001837d, (FixedNum)0x0000a49a}, {(FixedNum)0xfffff3f1, (FixedNum)0x00000364, (FixedNum)0xffffeabd, (FixedNum)0xffffed0d, (FixedNum)0xfffff2fd}, {(FixedNum)0x00004599, (FixedNum)0x000604ce, (FixedNum)0x000391d1, (FixedNum)0xfffe212b, (FixedNum)0x0006ef24}, {(FixedNum)0x0001488b, (FixedNum)0x00006cff, (FixedNum)0x0001127f, (FixedNum)0xffff85d6, (FixedNum)0xffff3396}, {(FixedNum)0xfffffa80, (FixedNum)0x00000160, (FixedNum)0xfffff067, (FixedNum)0x0000034d, (FixedNum)0xffffeebc}, {(FixedNum)0xfffffff5, (FixedNum)0xffffff91, (FixedNum)0xffffff95, (FixedNum)0x00000025, (FixedNum)0x0000003b}, {(FixedNum)0x00000008, (FixedNum)0xfffffd58, (FixedNum)0xffffff0e, (FixedNum)0x00000149, (FixedNum)0xffffff9c}, {(FixedNum)0xfffb7918, (FixedNum)0x0004973c, (FixedNum)0xfffc7203, (FixedNum)0x000179ca, (FixedNum)0xfffba897}, {(FixedNum)0x0000a937, (FixedNum)0x00006b9f, (FixedNum)0x00007c48, (FixedNum)0x0000424d, (FixedNum)0x0000798c}, {(FixedNum)0xffffe5b9, (FixedNum)0x00000554, (FixedNum)0xfffff6fc, (FixedNum)0xffffdef3, (FixedNum)0x00000562}, {(FixedNum)0xfffc95e8, (FixedNum)0xfffd3d24, (FixedNum)0xfff7ec96, (FixedNum)0x00038f4f, (FixedNum)0x00006f7a}, {(FixedNum)0x000070df, (FixedNum)0xffffe6e5, (FixedNum)0x000091fe, (FixedNum)0xffff7b1c, (FixedNum)0xfffff6d8}, {(FixedNum)0xffffe868, (FixedNum)0xffffe0e6, (FixedNum)0x00000758, (FixedNum)0xffffe7e5, (FixedNum)0x00001364}, {(FixedNum)0x00000014, (FixedNum)0x00000001, (FixedNum)0x00000002, (FixedNum)0xfffffff1, (FixedNum)0xfffffff2}, {(FixedNum)0xfffff5f2, (FixedNum)0xfffffaa0, (FixedNum)0xfffff9db, (FixedNum)0x00000236, (FixedNum)0xfffffd4f}, {(FixedNum)0x00009553, (FixedNum)0x000014fd, (FixedNum)0x00004ffe, (FixedNum)0xffff6de1, (FixedNum)0x0000af83}, {(FixedNum)0xfffff521, (FixedNum)0xffff96d0, (FixedNum)0xffffced0, (FixedNum)0x000000fa, (FixedNum)0x00000676}, {(FixedNum)0xfffff9ba, (FixedNum)0x00001430, (FixedNum)0x000019b9, (FixedNum)0x00000134, (FixedNum)0xfffffbe3}, {(FixedNum)0xffff8174, (FixedNum)0xffff0359, (FixedNum)0x000081d9, (FixedNum)0xffffe492, (FixedNum)0xffff6ab8}, {(FixedNum)0xffff84e5, (FixedNum)0xffffe15e, (FixedNum)0xffff974e, (FixedNum)0xffffe936, (FixedNum)0xffff9fbe}, {(FixedNum)0xffffefe6, (FixedNum)0xffffe8e1, (FixedNum)0xfffffc52, (FixedNum)0xfffff094, (FixedNum)0xffffed05}, {(FixedNum)0xfffffffe, (FixedNum)0x00000005, (FixedNum)0xffffffff, (FixedNum)0xfffffffc, (FixedNum)0xfffffff5}, {(FixedNum)0xffffff8e, (FixedNum)0xfffffc2e, (FixedNum)0xfffffd4b, (FixedNum)0x000001e5, (FixedNum)0xfffffefa}, {(FixedNum)0xffff6d0e, (FixedNum)0x00001041, (FixedNum)0x00005162, (FixedNum)0x000035aa, (FixedNum)0xffffe072}, {(FixedNum)0xffff7c74, (FixedNum)0xffffb6cd, (FixedNum)0xffffb5da, (FixedNum)0x00003c78, (FixedNum)0xffff8f85}, {(FixedNum)0x000011f8, (FixedNum)0x00001227, (FixedNum)0x000006e9, (FixedNum)0xfffffbd1, (FixedNum)0x0000079d}, {(FixedNum)0x00000c62, (FixedNum)0xffff3004, (FixedNum)0x0000b21e, (FixedNum)0xffff4865, (FixedNum)0x00003396}, {(FixedNum)0x000004c8, (FixedNum)0xffff7e86, (FixedNum)0x000014c0, (FixedNum)0xffffbdcb, (FixedNum)0x000018f1}, {(FixedNum)0x000002d0, (FixedNum)0x00000c90, (FixedNum)0x000009f7, (FixedNum)0x00001bd8, (FixedNum)0x00000085}, {(FixedNum)0x00000001, (FixedNum)0xfffffffd, (FixedNum)0xfffffffa, (FixedNum)0x00000002, (FixedNum)0xffffffff}, {(FixedNum)0xffff4021, (FixedNum)0xffff1f64, (FixedNum)0xfffff448, (FixedNum)0xffff52d9, (FixedNum)0xffff71a3}, {(FixedNum)0xffffe08c, (FixedNum)0x00003696, (FixedNum)0x000022f6, (FixedNum)0x000005f9, (FixedNum)0xffffdc26}, {(FixedNum)0xffffda47, (FixedNum)0xffffde70, (FixedNum)0xfffffec3, (FixedNum)0xffffe76c, (FixedNum)0xfffff747}, {(FixedNum)0x00000280, (FixedNum)0x0000083e, (FixedNum)0xfffff7e3, (FixedNum)0x00000632, (FixedNum)0xfffffb1d}, {(FixedNum)0x000075cd, (FixedNum)0x00005ce3, (FixedNum)0x00004ebf, (FixedNum)0xfffffb3e, (FixedNum)0xffffe627}, {(FixedNum)0x000010cd, (FixedNum)0xfffffbca, (FixedNum)0x00001c95, (FixedNum)0x0000237a, (FixedNum)0xfffff96b}, {(FixedNum)0xffffffb5, (FixedNum)0xfffffaf4, (FixedNum)0xfffffb23, (FixedNum)0x000001b2, (FixedNum)0xffffff86}, {(FixedNum)0x00000001, (FixedNum)0xfffffffe, (FixedNum)0xffffffff, (FixedNum)0x00000000, (FixedNum)0xffffffff}, {(FixedNum)0x0000c398, (FixedNum)0x0000b318, (FixedNum)0x000006ab, (FixedNum)0x0000b4f2, (FixedNum)0x00006a1c}, {(FixedNum)0x000011fe, (FixedNum)0x00004f3c, (FixedNum)0x00004602, (FixedNum)0x00003636, (FixedNum)0x00000935}, {(FixedNum)0x00002bea, (FixedNum)0xffffcda7, (FixedNum)0xffffca4e, (FixedNum)0x000024cd, (FixedNum)0x00002c24}, {(FixedNum)0x00000905, (FixedNum)0xfffff41b, (FixedNum)0x00000e51, (FixedNum)0x000002dd, (FixedNum)0x00000aac}, {(FixedNum)0x000012ba, (FixedNum)0xffffa7d0, (FixedNum)0xffff8bcb, (FixedNum)0x00007554, (FixedNum)0x000064bb}, {(FixedNum)0xffffc11b, (FixedNum)0xfffffd72, (FixedNum)0xfffff8b5, (FixedNum)0xffffc0e0, (FixedNum)0xffffe1ea}, {(FixedNum)0xfffffe26, (FixedNum)0xffffffb5, (FixedNum)0x00000090, (FixedNum)0x000002f0, (FixedNum)0xfffffe97}, {(FixedNum)0xfffffff6, (FixedNum)0x00000035, (FixedNum)0x0000000e, (FixedNum)0x00000011, (FixedNum)0xfffffffe}, {(FixedNum)0x00008b56, (FixedNum)0x0000cccc, (FixedNum)0xffffb9de, (FixedNum)0x0001ce95, (FixedNum)0x0000ac01}, {(FixedNum)0x0000bd8b, (FixedNum)0xffff94c9, (FixedNum)0x00009990, (FixedNum)0x00010715, (FixedNum)0x0000ed38}, {(FixedNum)0x000078b3, (FixedNum)0xfffffb53, (FixedNum)0x0000203e, (FixedNum)0x0001293b, (FixedNum)0x00005cd9}, {(FixedNum)0x0000059b, (FixedNum)0xfffff9bc, (FixedNum)0xffffeb98, (FixedNum)0x00000903, (FixedNum)0x0000056e}, {(FixedNum)0xfffffc59, (FixedNum)0xffffaf6b, (FixedNum)0xffff7e8c, (FixedNum)0x000055c4, (FixedNum)0x00000f47}, {(FixedNum)0xffffe75f, (FixedNum)0xffffb681, (FixedNum)0xfffff3a5, (FixedNum)0x000040f5, (FixedNum)0xffffc6b7}, {(FixedNum)0xfffff6b3, (FixedNum)0xffffece9, (FixedNum)0x00000cc0, (FixedNum)0xffffdd63, (FixedNum)0xfffff517}, {(FixedNum)0xffffffe2, (FixedNum)0xfffffffa, (FixedNum)0xffffffd9, (FixedNum)0xffffffbe, (FixedNum)0xfffffff5}, {(FixedNum)0xfffec0e7, (FixedNum)0xfffebf4d, (FixedNum)0x0000d0c5, (FixedNum)0xfffd89e9, (FixedNum)0xffff2b17}, {(FixedNum)0xffff83f9, (FixedNum)0xffff0626, (FixedNum)0xfffe0e3d, (FixedNum)0xffff22e6, (FixedNum)0xffff1275}, {(FixedNum)0xfffff3ed, (FixedNum)0xffffe9df, (FixedNum)0xffff86ea, (FixedNum)0xfffef523, (FixedNum)0xfffffc57}, {(FixedNum)0xffffd98e, (FixedNum)0x00000874, (FixedNum)0x00000b5d, (FixedNum)0xffffea3a, (FixedNum)0xfffff100}, {(FixedNum)0x0000759f, (FixedNum)0x0000a111, (FixedNum)0x000185fd, (FixedNum)0x00018ed7, (FixedNum)0x00023fd5}, {(FixedNum)0x000090d3, (FixedNum)0x0000994e, (FixedNum)0x00003cc5, (FixedNum)0x00004c88, (FixedNum)0x0000c1cb}, {(FixedNum)0x00001297, (FixedNum)0xfffffffd, (FixedNum)0xffffe21f, (FixedNum)0xffffed00, (FixedNum)0x000002d9}, {(FixedNum)0x00000003, (FixedNum)0xffffffa6, (FixedNum)0x000000cb, (FixedNum)0xfffffff6, (FixedNum)0x0000002b}, {(FixedNum)0xfffeb4e7, (FixedNum)0xffffeb70, (FixedNum)0xfffe2e0a, (FixedNum)0x0000c5cf, (FixedNum)0x00008ff1}, {(FixedNum)0x000608ed, (FixedNum)0xffff070f, (FixedNum)0xfffdd1a6, (FixedNum)0xfffdcd32, (FixedNum)0x00003047}, {(FixedNum)0x00008961, (FixedNum)0xffffdc6a, (FixedNum)0x00006bdf, (FixedNum)0x0000f745, (FixedNum)0xffff5306}, {(FixedNum)0x00000988, (FixedNum)0x00003594, (FixedNum)0x00002519, (FixedNum)0xfffffec1, (FixedNum)0x000026ca}, {(FixedNum)0x00048c4c, (FixedNum)0xfffde1d6, (FixedNum)0x0002114e, (FixedNum)0xfffacff3, (FixedNum)0x0000dc47}, {(FixedNum)0xfffe3558, (FixedNum)0x000125c6, (FixedNum)0xffff1b30, (FixedNum)0xfffffce0, (FixedNum)0xffff75ad}, {(FixedNum)0x00001b15, (FixedNum)0x000038de, (FixedNum)0x00000419, (FixedNum)0x00001eb2, (FixedNum)0x000016c5}, {(FixedNum)0x00000020, (FixedNum)0x00000047, (FixedNum)0xfffffff2, (FixedNum)0xffffffc4, (FixedNum)0x0000003f}, {(FixedNum)0x000117fc, (FixedNum)0xffff1f71, (FixedNum)0x0001ae34, (FixedNum)0x00010f50, (FixedNum)0xffff32f4}, {(FixedNum)0xfffad2ea, (FixedNum)0xfffd62e3, (FixedNum)0xfffca9aa, (FixedNum)0x0000bcf9, (FixedNum)0xfffb2e01}, {(FixedNum)0xffff5bee, (FixedNum)0xffffe780, (FixedNum)0xffffb150, (FixedNum)0xffff20a8, (FixedNum)0x0000a78b}, {(FixedNum)0xfffffe8c, (FixedNum)0x000014cc, (FixedNum)0x00003983, (FixedNum)0x00001d63, (FixedNum)0xffffc4a9}, {(FixedNum)0x00003692, (FixedNum)0x00001fd7, (FixedNum)0x00030b61, (FixedNum)0x000443ad, (FixedNum)0xfffebd44}, {(FixedNum)0xfffe12a9, (FixedNum)0xfffec888, (FixedNum)0xfffef5ca, (FixedNum)0xfffeba70, (FixedNum)0xffff9569}, {(FixedNum)0x00002b47, (FixedNum)0xffffe190, (FixedNum)0xfffffef9, (FixedNum)0x00003132, (FixedNum)0xfffffc1b}, {(FixedNum)0x0000000f, (FixedNum)0xffffffeb, (FixedNum)0x00000016, (FixedNum)0x00000008, (FixedNum)0xffffffff}, {(FixedNum)0x00009fbc, (FixedNum)0xffffcce0, (FixedNum)0x00001c28, (FixedNum)0x00001efb, (FixedNum)0xffffc31e}, {(FixedNum)0x0000463a, (FixedNum)0x00008a2d, (FixedNum)0x00006503, (FixedNum)0x00001112, (FixedNum)0x00001da5}, {(FixedNum)0xffffb49e, (FixedNum)0x00002cc4, (FixedNum)0xffffedea, (FixedNum)0xffff3958, (FixedNum)0xffffd17b}, {(FixedNum)0xfffffd57, (FixedNum)0xffffed4c, (FixedNum)0xfffffdee, (FixedNum)0xfffff577, (FixedNum)0x0000077e}, {(FixedNum)0xffff8305, (FixedNum)0x0000fb99, (FixedNum)0xffffb9c0, (FixedNum)0xffffe075, (FixedNum)0xffff74a5}, {(FixedNum)0xffffcdbb, (FixedNum)0x00005cfd, (FixedNum)0xffffedff, (FixedNum)0x00006d5e, (FixedNum)0xfffff0b8}, {(FixedNum)0x000003ea, (FixedNum)0x000008d6, (FixedNum)0x0000077b, (FixedNum)0xfffff4f8, (FixedNum)0xfffffd91}, {(FixedNum)0xfffffff3, (FixedNum)0xfffffff8, (FixedNum)0xfffffffe, (FixedNum)0x00000013, (FixedNum)0x00000009}, {(FixedNum)0xffffbbf8, (FixedNum)0x000048aa, (FixedNum)0xffff3cfc, (FixedNum)0x00002c47, (FixedNum)0xffffda5c}, {(FixedNum)0x000066c4, (FixedNum)0x00014e7c, (FixedNum)0xffffc1f6, (FixedNum)0x0001ae69, (FixedNum)0x0000fe27}, {(FixedNum)0x0000559c, (FixedNum)0xffffe37a, (FixedNum)0x000015dd, (FixedNum)0xffffed1a, (FixedNum)0xfffffabe}, {(FixedNum)0xfffffefa, (FixedNum)0x000001f9, (FixedNum)0xffffe19b, (FixedNum)0x000009e7, (FixedNum)0xffffe8d4}, {(FixedNum)0x000001e7, (FixedNum)0x00003144, (FixedNum)0x00001408, (FixedNum)0xffff65d2, (FixedNum)0xffff1959}, {(FixedNum)0x00001440, (FixedNum)0xffffa477, (FixedNum)0xffffe93b, (FixedNum)0x000021c3, (FixedNum)0x000016b2}, {(FixedNum)0x00000bd6, (FixedNum)0x00000b86, (FixedNum)0xfffff76b, (FixedNum)0x00000261, (FixedNum)0x0000149a}};
// const int m_SelectedAttributes[129] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128};
//
// /* Function classify description:
//  * Instance array must be initializated, with appropriated attributes, before calling this function
//  * Output number 0 means that the instance was classified as 1
//  * Output number 1 means that the instance was classified as 2
//  * Output number 2 means that the instance was classified as 3
//  * Output number 3 means that the instance was classified as 4
//  * Output number 4 means that the instance was classified as 5
//  * Output number 5 means that the instance was classified as 6
//  */
// int classify(){
// 	FixedNum prob[NUM_CLASSES];
// 	FixedNum newInstance[NUM_PREDICTORS+1];
// 	newInstance[0] = (FixedNum)0x00000400;
// 	for (int i = 1; i <= SELECTED_ATT_SIZE; i++){
// 		if (m_SelectedAttributes[i] <= CLASS_INDEX) {
// 			newInstance[i] = instance[m_SelectedAttributes[i-1]];
// 		}
// 		else {
// 			newInstance[i] = instance[m_SelectedAttributes[i]];
// 		}
// 	}
// 	FixedNum v[NUM_CLASSES] = {0};
// 	for (int i = 0; i < NUM_CLASSES-1; i++) {
// 		for (int j = 0; j <= NUM_PREDICTORS; j++) {
// 			v[i] = fxp_sum(v[i], fxp_mul(m_Par[j][i], newInstance[j]));
// 		}
// 	}
// 	v[NUM_CLASSES-1] = 0;
// 	for (int i = 0; i < NUM_CLASSES; i++) {
// 		FixedNum acc = 0;
// 		for (int j = 0; j < NUM_CLASSES-1; j++) {
// 			acc = fxp_sum(acc, fxp_exp(fxp_diff(v[j], v[i])));
// 		}
// 		prob[i] = fxp_div((FixedNum)0x00000400, fxp_sum(acc, fxp_exp(-v[i])));
// 	}
// 	int indexMax = 0;
// 	for (int i = 1; i < NUM_CLASSES; i++) {
// 		if (prob[i] > prob[indexMax]) {
// 			indexMax = i;
// 		}
// 	}
// 	return indexMax+1;
// }
