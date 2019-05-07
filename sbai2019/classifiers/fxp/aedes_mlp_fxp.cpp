
#include <Arduino.h>
#define TOTAL_BITS 32
#define FIXED_FBITS 10
#define SIGNED
#include "FixedNum.h"


#define INPUT_SIZE 42
#define OUTPUT_SIZE 2
#define NUMBER_OF_NEURONS 68

/* Instance array must be global
 * Attributes MUST be sorted in instance array in the following order:
 * hour
 * temperature
 * wbf
 * complexity
 * complexity_znorm
 * time_length
 * peaks_freq_1
 * peaks_freq_2
 * peaks_freq_3
 * peaks_freq_4
 * peaks_freq_5
 * peaks_freq_6
 * inharmonicity
 * rho
 * rho_wbf
 * eh_1
 * eh_2
 * eh_3
 * eh_4
 * eh_5
 * eh_6
 * eh_7
 * eh_8
 * eh_9
 * eh_10
 * eh_11
 * eh_12
 * eh_13
 * eh_14
 * eh_15
 * eh_16
 * eh_17
 * eh_18
 * eh_19
 * eh_20
 * eh_21
 * eh_22
 * eh_23
 * eh_24
 * eh_25
 * eh_26
 * temp_range
 */
FixedNum instance[INPUT_SIZE+1];

const int m_outputs[OUTPUT_SIZE] = {67, 66};

const FixedNum m_attributeBases[INPUT_SIZE] = {(FixedNum)0x00002e00, (FixedNum)0x000073cd, (FixedNum)0x000a6a2d, (FixedNum)0x00000244, (FixedNum)0x0000106e, (FixedNum)0x000002e7, (FixedNum)0x0024ae18, (FixedNum)0x00264433, (FixedNum)0x003dce2b, (FixedNum)0x003d38a5, (FixedNum)0x003dd229, (FixedNum)0x003d84d0, (FixedNum)0x001951a8, (FixedNum)0x00000459, (FixedNum)0x000b9488, (FixedNum)0x00000591, (FixedNum)0x000006c7, (FixedNum)0x0000074e, (FixedNum)0x0000073f, (FixedNum)0x0000085e, (FixedNum)0x00000799, (FixedNum)0x00000669, (FixedNum)0x00000856, (FixedNum)0x000005ca, (FixedNum)0x0000089f, (FixedNum)0x000009ff, (FixedNum)0x00000911, (FixedNum)0x000008aa, (FixedNum)0x000007ac, (FixedNum)0x00000766, (FixedNum)0x00000735, (FixedNum)0x000006d0, (FixedNum)0x000006ff, (FixedNum)0x000005bf, (FixedNum)0x0000059a, (FixedNum)0x0000055c, (FixedNum)0x00000537, (FixedNum)0x000006c5, (FixedNum)0x00000625, (FixedNum)0x000005d2, (FixedNum)0x000004da, (FixedNum)0x00000e00};
const FixedNum m_attributeRanges[INPUT_SIZE] = {(FixedNum)0x00002e00, (FixedNum)0x000017cd, (FixedNum)0x0008b9d3, (FixedNum)0x00000233, (FixedNum)0x00000d5a, (FixedNum)0x000002db, (FixedNum)0x0024070a, (FixedNum)0x0025b2f3, (FixedNum)0x003d4007, (FixedNum)0x003cb0d9, (FixedNum)0x003d4c02, (FixedNum)0x003cfbc2, (FixedNum)0x0016386e, (FixedNum)0x00000023, (FixedNum)0x0009b344, (FixedNum)0x0000058c, (FixedNum)0x000006c2, (FixedNum)0x00000744, (FixedNum)0x00000737, (FixedNum)0x00000858, (FixedNum)0x00000794, (FixedNum)0x00000663, (FixedNum)0x00000850, (FixedNum)0x000005c7, (FixedNum)0x00000898, (FixedNum)0x000009f9, (FixedNum)0x0000090b, (FixedNum)0x000008a6, (FixedNum)0x000007a7, (FixedNum)0x0000075f, (FixedNum)0x0000072f, (FixedNum)0x000006cb, (FixedNum)0x000006f8, (FixedNum)0x000005b8, (FixedNum)0x00000596, (FixedNum)0x00000557, (FixedNum)0x00000533, (FixedNum)0x000006c1, (FixedNum)0x00000621, (FixedNum)0x000005cc, (FixedNum)0x000004d4, (FixedNum)0x00000a00};

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

const FixedNum tmp_weights42[43] = {(FixedNum)0xfffff54a, (FixedNum)0x0000106b, (FixedNum)0x00001c5f, (FixedNum)0x000025a5, (FixedNum)0xfffff021, (FixedNum)0x000004d7, (FixedNum)0x000001d7, (FixedNum)0x00000209, (FixedNum)0xffffedc4, (FixedNum)0x000003be, (FixedNum)0x0000038c, (FixedNum)0x00000c64, (FixedNum)0xfffff53d, (FixedNum)0x0000063c, (FixedNum)0xfffffbf3, (FixedNum)0x000024da, (FixedNum)0x000022bf, (FixedNum)0x00000285, (FixedNum)0x00000896, (FixedNum)0xfffffe8b, (FixedNum)0x000006f4, (FixedNum)0xffffeaf3, (FixedNum)0xffffee7e, (FixedNum)0x000004ae, (FixedNum)0xfffff195, (FixedNum)0x000006a9, (FixedNum)0x00000a52, (FixedNum)0xfffffa1a, (FixedNum)0xffffeda6, (FixedNum)0xffffe254, (FixedNum)0xffffd4ea, (FixedNum)0xfffff4e0, (FixedNum)0x00001533, (FixedNum)0x0000144f, (FixedNum)0x00001036, (FixedNum)0x00000f29, (FixedNum)0x00000bbb, (FixedNum)0x00000c22, (FixedNum)0x00000733, (FixedNum)0x0000051b, (FixedNum)0x000007b8, (FixedNum)0x000000c6, (FixedNum)0x000009a6};
const int tmp_connections42[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights43[43] = {(FixedNum)0x0000113c, (FixedNum)0x00000300, (FixedNum)0x0000054a, (FixedNum)0xfffff92e, (FixedNum)0x000013f0, (FixedNum)0x00000780, (FixedNum)0xfffff2af, (FixedNum)0xfffffedf, (FixedNum)0xfffff464, (FixedNum)0xffffed5e, (FixedNum)0xffffeecd, (FixedNum)0x00000b69, (FixedNum)0xfffffc3d, (FixedNum)0xfffffcbf, (FixedNum)0xffffefe8, (FixedNum)0xfffff81e, (FixedNum)0x0000150c, (FixedNum)0x00001413, (FixedNum)0x00001a20, (FixedNum)0x00000a25, (FixedNum)0x000004b2, (FixedNum)0x0000043d, (FixedNum)0x000011a4, (FixedNum)0x00000b18, (FixedNum)0x00000de0, (FixedNum)0x00000a0d, (FixedNum)0xfffffeb4, (FixedNum)0x00000077, (FixedNum)0xffffffc8, (FixedNum)0xfffffaff, (FixedNum)0xfffff7b6, (FixedNum)0x000007b9, (FixedNum)0x00000548, (FixedNum)0xffffffa1, (FixedNum)0xfffffc16, (FixedNum)0xfffff8d7, (FixedNum)0xfffffc02, (FixedNum)0xfffff9b1, (FixedNum)0xfffff90a, (FixedNum)0xfffff812, (FixedNum)0xfffffc62, (FixedNum)0xffffff08, (FixedNum)0x00000a61};
const int tmp_connections43[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights44[43] = {(FixedNum)0xffffff1c, (FixedNum)0xfffffc65, (FixedNum)0x0000017e, (FixedNum)0x00000380, (FixedNum)0x00000057, (FixedNum)0xfffffdf1, (FixedNum)0x0000014a, (FixedNum)0xffffff69, (FixedNum)0x000000e6, (FixedNum)0x00000044, (FixedNum)0x0000017d, (FixedNum)0x00000123, (FixedNum)0xfffffe82, (FixedNum)0xffffff21, (FixedNum)0xfffffea8, (FixedNum)0x00000328, (FixedNum)0x00000082, (FixedNum)0x000000fc, (FixedNum)0x00000030, (FixedNum)0xffffffdb, (FixedNum)0x000000a1, (FixedNum)0x000000fe, (FixedNum)0xffffffd0, (FixedNum)0x0000006d, (FixedNum)0x000000c7, (FixedNum)0xffffffe3, (FixedNum)0x00000141, (FixedNum)0x000000fb, (FixedNum)0x000000fc, (FixedNum)0x00000113, (FixedNum)0x000001a6, (FixedNum)0xffffffe7, (FixedNum)0xfffffffd, (FixedNum)0x00000072, (FixedNum)0x0000007b, (FixedNum)0x000000a2, (FixedNum)0x000000c3, (FixedNum)0x00000058, (FixedNum)0x00000112, (FixedNum)0x000000d1, (FixedNum)0x000000d2, (FixedNum)0x000000e5, (FixedNum)0x0000038e};
const int tmp_connections44[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights45[43] = {(FixedNum)0xfffffd61, (FixedNum)0x00002274, (FixedNum)0xffffe6ab, (FixedNum)0x0000083a, (FixedNum)0x00000366, (FixedNum)0x00000ab9, (FixedNum)0x00000350, (FixedNum)0xffffffb8, (FixedNum)0x00000a29, (FixedNum)0x000019ab, (FixedNum)0x000012e7, (FixedNum)0xfffff7f2, (FixedNum)0xfffff640, (FixedNum)0xfffffcad, (FixedNum)0xfffff49e, (FixedNum)0x000007ec, (FixedNum)0xfffff682, (FixedNum)0xfffffec4, (FixedNum)0xffffff89, (FixedNum)0xfffff98a, (FixedNum)0xfffffe12, (FixedNum)0x000003a7, (FixedNum)0x00000450, (FixedNum)0xffffface, (FixedNum)0x00000712, (FixedNum)0xfffffffb, (FixedNum)0xfffffd4e, (FixedNum)0xfffffe1b, (FixedNum)0x000000e6, (FixedNum)0x00000c38, (FixedNum)0x00000df1, (FixedNum)0x00000a42, (FixedNum)0x00000096, (FixedNum)0x00000248, (FixedNum)0xfffffe4b, (FixedNum)0x000004f2, (FixedNum)0x0000006e, (FixedNum)0x000000ec, (FixedNum)0xfffffa85, (FixedNum)0xfffffd37, (FixedNum)0x000001fe, (FixedNum)0xfffff8d4, (FixedNum)0xfffffda8};
const int tmp_connections45[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights46[43] = {(FixedNum)0xfffff9ea, (FixedNum)0x00000994, (FixedNum)0xffffa989, (FixedNum)0x00003efa, (FixedNum)0xfffff4ae, (FixedNum)0x000019fa, (FixedNum)0xfffffd17, (FixedNum)0x000014c1, (FixedNum)0x000001fb, (FixedNum)0xffffff0f, (FixedNum)0x00000d36, (FixedNum)0x00000e94, (FixedNum)0x000002fc, (FixedNum)0xfffff2f3, (FixedNum)0xffffd754, (FixedNum)0x00003d16, (FixedNum)0x00000519, (FixedNum)0x000002f3, (FixedNum)0xfffffe41, (FixedNum)0xfffff051, (FixedNum)0x000000f9, (FixedNum)0x0000048d, (FixedNum)0x000005bd, (FixedNum)0xffffef05, (FixedNum)0xfffffac8, (FixedNum)0xfffff67c, (FixedNum)0xffffea6e, (FixedNum)0xfffffd12, (FixedNum)0xffffebd4, (FixedNum)0x000019e7, (FixedNum)0x00000f0e, (FixedNum)0x00001f79, (FixedNum)0x00001772, (FixedNum)0x00000f3a, (FixedNum)0x00000aec, (FixedNum)0x000002ac, (FixedNum)0xfffff510, (FixedNum)0xfffffd9c, (FixedNum)0xffffece2, (FixedNum)0xfffff2aa, (FixedNum)0x00000371, (FixedNum)0x000001b0, (FixedNum)0xffffde64};
const int tmp_connections46[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights47[43] = {(FixedNum)0x000007f7, (FixedNum)0x00000ac6, (FixedNum)0x000008c6, (FixedNum)0xffffeebf, (FixedNum)0x000001b2, (FixedNum)0x00000097, (FixedNum)0xfffff8fb, (FixedNum)0x000006ea, (FixedNum)0xfffff8c6, (FixedNum)0xfffffbaf, (FixedNum)0xfffff86a, (FixedNum)0xffffea92, (FixedNum)0xfffffa72, (FixedNum)0x000009d6, (FixedNum)0xfffff9d8, (FixedNum)0xffffee9e, (FixedNum)0x0000090a, (FixedNum)0xffffff5b, (FixedNum)0x0000025f, (FixedNum)0x00000d14, (FixedNum)0x0000020a, (FixedNum)0xfffffac4, (FixedNum)0x00000eff, (FixedNum)0xfffffdae, (FixedNum)0x00000406, (FixedNum)0xfffffe91, (FixedNum)0x0000019f, (FixedNum)0x00000089, (FixedNum)0xfffff734, (FixedNum)0xfffff281, (FixedNum)0x00000d48, (FixedNum)0x00000543, (FixedNum)0xfffffc4e, (FixedNum)0xfffff9e7, (FixedNum)0xfffffa9f, (FixedNum)0xfffff7ac, (FixedNum)0xfffffc84, (FixedNum)0xfffff75a, (FixedNum)0xfffffeae, (FixedNum)0x00000067, (FixedNum)0xfffffdb2, (FixedNum)0x0000019b, (FixedNum)0x000006f6};
const int tmp_connections47[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights48[43] = {(FixedNum)0xfffffe2f, (FixedNum)0xfffff74f, (FixedNum)0x00000153, (FixedNum)0x00000032, (FixedNum)0x00000011, (FixedNum)0xfffff85f, (FixedNum)0x000003a5, (FixedNum)0xfffffe13, (FixedNum)0x00000458, (FixedNum)0xffffffc3, (FixedNum)0x000005ff, (FixedNum)0xfffffcdd, (FixedNum)0xfffff08f, (FixedNum)0xfffffbd2, (FixedNum)0xffffffa1, (FixedNum)0x00000032, (FixedNum)0xfffffd1d, (FixedNum)0x0000005d, (FixedNum)0xfffffc38, (FixedNum)0xffffff9c, (FixedNum)0x000000da, (FixedNum)0x00000300, (FixedNum)0xfffffd52, (FixedNum)0x0000004c, (FixedNum)0x000002a5, (FixedNum)0xfffffe37, (FixedNum)0x000004fc, (FixedNum)0x00000391, (FixedNum)0x000002ce, (FixedNum)0x0000033e, (FixedNum)0x000006fc, (FixedNum)0xfffffb73, (FixedNum)0xfffffb1a, (FixedNum)0xfffffe77, (FixedNum)0xffffff72, (FixedNum)0xfffffffd, (FixedNum)0x0000014d, (FixedNum)0xffffffb8, (FixedNum)0x000002f6, (FixedNum)0x0000036e, (FixedNum)0x0000022a, (FixedNum)0x00000291, (FixedNum)0x00000630};
const int tmp_connections48[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights49[43] = {(FixedNum)0x000008f1, (FixedNum)0x00000dad, (FixedNum)0x00002a10, (FixedNum)0xffffb599, (FixedNum)0x00000c5e, (FixedNum)0x00001594, (FixedNum)0x00001406, (FixedNum)0x000022aa, (FixedNum)0xffffe5f1, (FixedNum)0xfffff858, (FixedNum)0x000020b7, (FixedNum)0x00000ab4, (FixedNum)0x000008b8, (FixedNum)0xfffff904, (FixedNum)0x00001a7d, (FixedNum)0xffffb6d8, (FixedNum)0xffffe6e2, (FixedNum)0xffffffee, (FixedNum)0xfffff2b8, (FixedNum)0xfffff91e, (FixedNum)0x00000352, (FixedNum)0x00001a02, (FixedNum)0xfffff2c0, (FixedNum)0x00000b53, (FixedNum)0xffffff96, (FixedNum)0xfffffa21, (FixedNum)0x000016d5, (FixedNum)0x00000970, (FixedNum)0x000023ee, (FixedNum)0x000019e8, (FixedNum)0xffffeb18, (FixedNum)0xffffdc3e, (FixedNum)0xffffe300, (FixedNum)0xfffff07c, (FixedNum)0xffffeb11, (FixedNum)0xfffff6c6, (FixedNum)0x00000088, (FixedNum)0xfffff96f, (FixedNum)0x00000697, (FixedNum)0x0000113d, (FixedNum)0x00000c4c, (FixedNum)0xfffffdcc, (FixedNum)0xfffff36d};
const int tmp_connections49[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights50[43] = {(FixedNum)0x00000757, (FixedNum)0x0000043f, (FixedNum)0x00001d3d, (FixedNum)0xffffd616, (FixedNum)0xfffff762, (FixedNum)0xfffffad2, (FixedNum)0xfffff80f, (FixedNum)0x000005ea, (FixedNum)0x00000ed6, (FixedNum)0xfffffdf4, (FixedNum)0x00001b30, (FixedNum)0xfffff466, (FixedNum)0xfffffd62, (FixedNum)0x000010f3, (FixedNum)0xffffec1a, (FixedNum)0xffffd60d, (FixedNum)0xfffff94d, (FixedNum)0xfffff9ee, (FixedNum)0x00000990, (FixedNum)0x000000a5, (FixedNum)0x00000563, (FixedNum)0xfffff42b, (FixedNum)0x00000ea7, (FixedNum)0x000004ba, (FixedNum)0xfffff6ca, (FixedNum)0x0000010c, (FixedNum)0xffffffcf, (FixedNum)0x00000964, (FixedNum)0x00000a06, (FixedNum)0xfffff238, (FixedNum)0x00000040, (FixedNum)0x00000730, (FixedNum)0xfffffc7b, (FixedNum)0xfffffb79, (FixedNum)0x00000029, (FixedNum)0xfffff991, (FixedNum)0xfffff746, (FixedNum)0xfffffa72, (FixedNum)0x00000018, (FixedNum)0x00000587, (FixedNum)0x0000023c, (FixedNum)0x000009c9, (FixedNum)0xfffff0dd};
const int tmp_connections50[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights51[43] = {(FixedNum)0x000001a0, (FixedNum)0x00001791, (FixedNum)0x00002f96, (FixedNum)0xffffb2f7, (FixedNum)0xfffff5d2, (FixedNum)0x0000005f, (FixedNum)0x00001914, (FixedNum)0x00003f04, (FixedNum)0x000000f7, (FixedNum)0x00000232, (FixedNum)0x0000045d, (FixedNum)0x00000036, (FixedNum)0xffffeef7, (FixedNum)0x00001025, (FixedNum)0x00000ecb, (FixedNum)0xffffb48b, (FixedNum)0xffffdf02, (FixedNum)0xfffff778, (FixedNum)0xffffeef6, (FixedNum)0x000003c3, (FixedNum)0x00000895, (FixedNum)0x00001a9a, (FixedNum)0xfffffb0c, (FixedNum)0xfffff9db, (FixedNum)0x00000137, (FixedNum)0xfffffe09, (FixedNum)0x00001b88, (FixedNum)0x00000c78, (FixedNum)0x00001a0d, (FixedNum)0x00001b3b, (FixedNum)0xfffffef8, (FixedNum)0xffffe600, (FixedNum)0xffffdced, (FixedNum)0xfffff180, (FixedNum)0xffffeac2, (FixedNum)0xfffff0b5, (FixedNum)0x000002ea, (FixedNum)0xfffffe34, (FixedNum)0x00000c73, (FixedNum)0x000015b6, (FixedNum)0x0000120b, (FixedNum)0x00000034, (FixedNum)0xfffffe99};
const int tmp_connections51[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights52[43] = {(FixedNum)0x000003fa, (FixedNum)0xfffff4ee, (FixedNum)0xfffffec9, (FixedNum)0x00000681, (FixedNum)0xfffffd4e, (FixedNum)0xfffff3a9, (FixedNum)0xfffffbcd, (FixedNum)0xfffffb09, (FixedNum)0xfffff1de, (FixedNum)0xfffff72b, (FixedNum)0x00000075, (FixedNum)0x000005d1, (FixedNum)0xfffff612, (FixedNum)0xfffff62d, (FixedNum)0xfffffec3, (FixedNum)0x0000060a, (FixedNum)0x0000189a, (FixedNum)0x00000e76, (FixedNum)0x0000089f, (FixedNum)0x00000dd3, (FixedNum)0x0000027b, (FixedNum)0xffffff77, (FixedNum)0x00000460, (FixedNum)0x00000b65, (FixedNum)0x000018e0, (FixedNum)0x00000cc9, (FixedNum)0x0000091c, (FixedNum)0x000001cb, (FixedNum)0xfffff966, (FixedNum)0xfffff313, (FixedNum)0xfffff8c4, (FixedNum)0xfffff8a4, (FixedNum)0xfffffbfc, (FixedNum)0xfffffe6f, (FixedNum)0x0000021e, (FixedNum)0x000000e4, (FixedNum)0xffffffb2, (FixedNum)0xfffffd4d, (FixedNum)0x000001f3, (FixedNum)0x0000019e, (FixedNum)0x00000088, (FixedNum)0x00000138, (FixedNum)0xfffffffc};
const int tmp_connections52[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights53[43] = {(FixedNum)0xffffff52, (FixedNum)0xfffff628, (FixedNum)0x0000054c, (FixedNum)0x000004a7, (FixedNum)0x00000289, (FixedNum)0xfffffbb6, (FixedNum)0x000001cc, (FixedNum)0xfffffded, (FixedNum)0x00000342, (FixedNum)0xffffff10, (FixedNum)0x000003cd, (FixedNum)0xffffffd0, (FixedNum)0xfffffd81, (FixedNum)0x00000011, (FixedNum)0xfffff8c9, (FixedNum)0x000003e7, (FixedNum)0x000001b7, (FixedNum)0x00000324, (FixedNum)0x00000230, (FixedNum)0xffffff39, (FixedNum)0x00000155, (FixedNum)0x0000021e, (FixedNum)0x0000019a, (FixedNum)0x0000025f, (FixedNum)0x0000041b, (FixedNum)0x0000005c, (FixedNum)0x0000029c, (FixedNum)0x0000035e, (FixedNum)0x000001db, (FixedNum)0x00000258, (FixedNum)0x000002e2, (FixedNum)0xffffff74, (FixedNum)0xffffff27, (FixedNum)0xffffffb1, (FixedNum)0xffffffdd, (FixedNum)0xfffffed4, (FixedNum)0xfffffe7c, (FixedNum)0xfffffeb9, (FixedNum)0x000000c7, (FixedNum)0x00000136, (FixedNum)0x00000190, (FixedNum)0x00000338, (FixedNum)0x00000973};
const int tmp_connections53[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights54[43] = {(FixedNum)0x000000b0, (FixedNum)0x000011d0, (FixedNum)0x0000031f, (FixedNum)0xfffff871, (FixedNum)0x0000078a, (FixedNum)0x0000036f, (FixedNum)0xffffffb4, (FixedNum)0xfffffe3a, (FixedNum)0x00000823, (FixedNum)0xffffff54, (FixedNum)0xfffff7da, (FixedNum)0x00000005, (FixedNum)0xffffef86, (FixedNum)0xfffffb9f, (FixedNum)0xfffff8c3, (FixedNum)0xfffff867, (FixedNum)0xfffffcaa, (FixedNum)0xfffffefa, (FixedNum)0xffffff7f, (FixedNum)0xfffffecb, (FixedNum)0x00000061, (FixedNum)0x000001a6, (FixedNum)0x00000247, (FixedNum)0x000001f7, (FixedNum)0x00000418, (FixedNum)0x0000014b, (FixedNum)0x00000287, (FixedNum)0x00000350, (FixedNum)0x0000019a, (FixedNum)0x00000399, (FixedNum)0x000004fa, (FixedNum)0x000002f4, (FixedNum)0x00000036, (FixedNum)0x00000162, (FixedNum)0x0000014d, (FixedNum)0xffffff05, (FixedNum)0x00000016, (FixedNum)0x00000080, (FixedNum)0x000001a5, (FixedNum)0x00000211, (FixedNum)0x000002b1, (FixedNum)0x00000318, (FixedNum)0x000006db};
const int tmp_connections54[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights55[43] = {(FixedNum)0x000006a7, (FixedNum)0x00000d66, (FixedNum)0x000014c8, (FixedNum)0xffffdb57, (FixedNum)0xfffffff0, (FixedNum)0x0000080e, (FixedNum)0xfffff9bc, (FixedNum)0x000008be, (FixedNum)0x00000024, (FixedNum)0x000008c8, (FixedNum)0x0000027a, (FixedNum)0xfffffc4d, (FixedNum)0xffffff09, (FixedNum)0x00000ae1, (FixedNum)0xffffeae5, (FixedNum)0xffffdb76, (FixedNum)0x00000030, (FixedNum)0xfffffc8d, (FixedNum)0x00000371, (FixedNum)0x0000018d, (FixedNum)0x00000138, (FixedNum)0xfffff8c1, (FixedNum)0x00000cea, (FixedNum)0x0000026c, (FixedNum)0xfffffe25, (FixedNum)0x00000261, (FixedNum)0x00000202, (FixedNum)0x00000219, (FixedNum)0x0000012e, (FixedNum)0xfffff70f, (FixedNum)0x000004a2, (FixedNum)0x00000619, (FixedNum)0xfffffc65, (FixedNum)0xfffffc0d, (FixedNum)0xfffffec6, (FixedNum)0xfffffa9b, (FixedNum)0xfffff7e6, (FixedNum)0xfffffd61, (FixedNum)0x00000487, (FixedNum)0x00000792, (FixedNum)0x00000382, (FixedNum)0x000005c3, (FixedNum)0xfffff9ed};
const int tmp_connections55[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights56[43] = {(FixedNum)0xfffff60b, (FixedNum)0xffffe63b, (FixedNum)0xffffcf2c, (FixedNum)0x000041a0, (FixedNum)0xfffff407, (FixedNum)0x00000513, (FixedNum)0xfffff39c, (FixedNum)0x000027b7, (FixedNum)0xfffff911, (FixedNum)0x00000b41, (FixedNum)0x00000041, (FixedNum)0x00001a86, (FixedNum)0x00000dae, (FixedNum)0x00002556, (FixedNum)0x00003378, (FixedNum)0x000042e3, (FixedNum)0x00000b45, (FixedNum)0x00000d3a, (FixedNum)0x000009a1, (FixedNum)0xfffff0e3, (FixedNum)0xfffff3e6, (FixedNum)0xffffff9e, (FixedNum)0xfffff878, (FixedNum)0xffffff60, (FixedNum)0xffffe6a8, (FixedNum)0x000005b4, (FixedNum)0xfffff605, (FixedNum)0xfffff2ee, (FixedNum)0x000000c3, (FixedNum)0x000000b2, (FixedNum)0xfffff731, (FixedNum)0x0000072e, (FixedNum)0x0000125b, (FixedNum)0x00000bb7, (FixedNum)0x00000c5a, (FixedNum)0x000005ac, (FixedNum)0x00000ead, (FixedNum)0xffffff84, (FixedNum)0xfffffe42, (FixedNum)0xffffffee, (FixedNum)0x000000b5, (FixedNum)0xfffffda4, (FixedNum)0x00000ac2};
const int tmp_connections56[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights57[43] = {(FixedNum)0xfffff547, (FixedNum)0x000014de, (FixedNum)0x00001ec1, (FixedNum)0x00001ffd, (FixedNum)0xffffe726, (FixedNum)0x00000e22, (FixedNum)0x000015dd, (FixedNum)0xffffcde3, (FixedNum)0xffffe7ee, (FixedNum)0x00001319, (FixedNum)0x00000c54, (FixedNum)0xfffff4a3, (FixedNum)0x000005dd, (FixedNum)0xffffed24, (FixedNum)0xffffc4c6, (FixedNum)0x00001d6e, (FixedNum)0x00001298, (FixedNum)0x00000544, (FixedNum)0x00000fca, (FixedNum)0xfffff6fe, (FixedNum)0x00000609, (FixedNum)0xfffffd0d, (FixedNum)0xffffedd6, (FixedNum)0x00000d9e, (FixedNum)0xfffff520, (FixedNum)0xfffff9d5, (FixedNum)0xfffffc7b, (FixedNum)0xfffff5aa, (FixedNum)0xfffff475, (FixedNum)0xfffff636, (FixedNum)0xffffd2fa, (FixedNum)0xfffffab4, (FixedNum)0x00001c53, (FixedNum)0x00001b46, (FixedNum)0x00001789, (FixedNum)0x00001080, (FixedNum)0x000010fc, (FixedNum)0x000004d0, (FixedNum)0xfffffa53, (FixedNum)0xfffff73c, (FixedNum)0x00000435, (FixedNum)0xfffff6e0, (FixedNum)0xfffff603};
const int tmp_connections57[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights58[43] = {(FixedNum)0x0000058c, (FixedNum)0x00000b8e, (FixedNum)0xfffffb16, (FixedNum)0x00001edb, (FixedNum)0xfffffbcd, (FixedNum)0x000008a7, (FixedNum)0xfffff81c, (FixedNum)0xfffffdf1, (FixedNum)0xfffff97f, (FixedNum)0xfffffa88, (FixedNum)0x00000b14, (FixedNum)0x000001f6, (FixedNum)0x0000027c, (FixedNum)0xfffffd3b, (FixedNum)0xfffff06e, (FixedNum)0x00001d31, (FixedNum)0x000005f4, (FixedNum)0x0000099d, (FixedNum)0x00000f31, (FixedNum)0xfffffa19, (FixedNum)0x000003e8, (FixedNum)0xfffff8f1, (FixedNum)0x0000021a, (FixedNum)0x0000032b, (FixedNum)0xffffebe2, (FixedNum)0x000005da, (FixedNum)0xfffffc0f, (FixedNum)0xffffff56, (FixedNum)0x00000070, (FixedNum)0xfffffa6e, (FixedNum)0xffffdd2d, (FixedNum)0x00000661, (FixedNum)0x00001285, (FixedNum)0x00000801, (FixedNum)0x0000045f, (FixedNum)0x000001f0, (FixedNum)0x00000001, (FixedNum)0x0000028a, (FixedNum)0xfffff63c, (FixedNum)0xfffff8b3, (FixedNum)0x000002fd, (FixedNum)0xfffffec5, (FixedNum)0xffffead6};
const int tmp_connections58[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights59[43] = {(FixedNum)0x00000a3d, (FixedNum)0x000005e2, (FixedNum)0x00001495, (FixedNum)0xffffc5bf, (FixedNum)0xfffff0b2, (FixedNum)0x00000a3c, (FixedNum)0xfffff376, (FixedNum)0xfffff2c1, (FixedNum)0x0000040e, (FixedNum)0xfffffd6a, (FixedNum)0x00000717, (FixedNum)0x000017ab, (FixedNum)0x00000c2c, (FixedNum)0x00000c80, (FixedNum)0xffffd7be, (FixedNum)0xffffc53a, (FixedNum)0x0000074f, (FixedNum)0x0000093f, (FixedNum)0x000011bb, (FixedNum)0xfffffc9d, (FixedNum)0x000005a3, (FixedNum)0xfffff753, (FixedNum)0x000008f6, (FixedNum)0x000005b4, (FixedNum)0xfffffeeb, (FixedNum)0x000001f8, (FixedNum)0xfffffae5, (FixedNum)0x000005aa, (FixedNum)0x00000db7, (FixedNum)0xfffff603, (FixedNum)0xffffff9c, (FixedNum)0x00000736, (FixedNum)0xfffff529, (FixedNum)0xfffff8ce, (FixedNum)0x00000167, (FixedNum)0xfffffb7f, (FixedNum)0xfffff0d0, (FixedNum)0xfffffa7b, (FixedNum)0x000001be, (FixedNum)0x0000054b, (FixedNum)0x00000211, (FixedNum)0x00000d9f, (FixedNum)0xfffff3e1};
const int tmp_connections59[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights60[43] = {(FixedNum)0xffffed87, (FixedNum)0x00001626, (FixedNum)0xffff7949, (FixedNum)0x00002f07, (FixedNum)0xfffff976, (FixedNum)0xfffffc7c, (FixedNum)0xffffe759, (FixedNum)0x00003924, (FixedNum)0x00002665, (FixedNum)0x000000ab, (FixedNum)0x00000913, (FixedNum)0x0000037e, (FixedNum)0x00000eff, (FixedNum)0x00001787, (FixedNum)0xffffe1ab, (FixedNum)0x00002e17, (FixedNum)0xfffff319, (FixedNum)0xffffef6c, (FixedNum)0xfffffa06, (FixedNum)0xffffea37, (FixedNum)0x0000014a, (FixedNum)0xfffff725, (FixedNum)0xfffffab5, (FixedNum)0xfffff1cd, (FixedNum)0xfffffa2e, (FixedNum)0x000001f8, (FixedNum)0xfffff72f, (FixedNum)0xfffffe3d, (FixedNum)0xffffec52, (FixedNum)0x00000d4e, (FixedNum)0x00001cfb, (FixedNum)0x00001ee2, (FixedNum)0x00001178, (FixedNum)0x00000b29, (FixedNum)0x00000140, (FixedNum)0x00000be5, (FixedNum)0x00000ba1, (FixedNum)0x00000310, (FixedNum)0xfffff5d3, (FixedNum)0xfffffb0c, (FixedNum)0xfffffdf1, (FixedNum)0x000002fd, (FixedNum)0x00001dfc};
const int tmp_connections60[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights61[43] = {(FixedNum)0xffffff9f, (FixedNum)0x000001d6, (FixedNum)0x0000289c, (FixedNum)0xffffd15d, (FixedNum)0xfffff612, (FixedNum)0x000015bc, (FixedNum)0x00000881, (FixedNum)0xfffff608, (FixedNum)0xfffffd86, (FixedNum)0x0000026e, (FixedNum)0x0000063c, (FixedNum)0x000029a2, (FixedNum)0x000012c8, (FixedNum)0xfffffe26, (FixedNum)0xfffffe5c, (FixedNum)0xffffd21a, (FixedNum)0x00000cca, (FixedNum)0xfffff6eb, (FixedNum)0xfffffa4d, (FixedNum)0x00000443, (FixedNum)0xfffff5c6, (FixedNum)0xfffffdb8, (FixedNum)0xffffff3d, (FixedNum)0x00000688, (FixedNum)0x000011b7, (FixedNum)0x00000784, (FixedNum)0x000005cf, (FixedNum)0xfffff082, (FixedNum)0xfffff79f, (FixedNum)0xfffff949, (FixedNum)0xffffeeb8, (FixedNum)0xfffff4b3, (FixedNum)0xfffffc34, (FixedNum)0xffffff85, (FixedNum)0x000002f1, (FixedNum)0xffffffe5, (FixedNum)0xfffff910, (FixedNum)0x000006ec, (FixedNum)0x000010db, (FixedNum)0x00000d74, (FixedNum)0x00000343, (FixedNum)0xfffff9e6, (FixedNum)0xffffd388};
const int tmp_connections61[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights62[43] = {(FixedNum)0x0000013e, (FixedNum)0xfffff40a, (FixedNum)0x00005ebb, (FixedNum)0xffffb279, (FixedNum)0xfffffe1f, (FixedNum)0xfffff4dc, (FixedNum)0x00001511, (FixedNum)0x00000cb9, (FixedNum)0xfffffc16, (FixedNum)0x0000194c, (FixedNum)0xfffff897, (FixedNum)0x00000636, (FixedNum)0x00000dc9, (FixedNum)0x000028b7, (FixedNum)0x00003425, (FixedNum)0xffffb5b6, (FixedNum)0xffffeb1c, (FixedNum)0xfffff1e9, (FixedNum)0xffffe354, (FixedNum)0x000006b7, (FixedNum)0xfffffc42, (FixedNum)0x00000b33, (FixedNum)0x00000798, (FixedNum)0xfffff083, (FixedNum)0xfffff606, (FixedNum)0x00000558, (FixedNum)0x00000901, (FixedNum)0x00000765, (FixedNum)0x00000280, (FixedNum)0x00000229, (FixedNum)0x000003cf, (FixedNum)0xfffff3fd, (FixedNum)0xffffe282, (FixedNum)0xffffe421, (FixedNum)0xfffff1a9, (FixedNum)0xfffff10e, (FixedNum)0xfffffe8d, (FixedNum)0x000003bd, (FixedNum)0x00000f67, (FixedNum)0x00001396, (FixedNum)0x0000081f, (FixedNum)0x00000d33, (FixedNum)0xfffff740};
const int tmp_connections62[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights63[43] = {(FixedNum)0x000001e3, (FixedNum)0xfffffbac, (FixedNum)0x0000037e, (FixedNum)0xffffdc19, (FixedNum)0x00000016, (FixedNum)0xffffeb35, (FixedNum)0x000000c9, (FixedNum)0x00000388, (FixedNum)0x000007ba, (FixedNum)0x000007d9, (FixedNum)0xfffff417, (FixedNum)0xfffff773, (FixedNum)0xffffec73, (FixedNum)0x00000afe, (FixedNum)0x00000d48, (FixedNum)0xffffdd65, (FixedNum)0xfffffbbe, (FixedNum)0xfffff98d, (FixedNum)0xfffff1a0, (FixedNum)0x000000ce, (FixedNum)0xfffffd4c, (FixedNum)0x00000087, (FixedNum)0xfffffcc5, (FixedNum)0xfffff383, (FixedNum)0x00000572, (FixedNum)0xfffffad4, (FixedNum)0x00000458, (FixedNum)0x0000035d, (FixedNum)0x000002d5, (FixedNum)0xffffff95, (FixedNum)0x00001ebf, (FixedNum)0xfffff728, (FixedNum)0xffffe44c, (FixedNum)0xffffecdb, (FixedNum)0xfffff1f5, (FixedNum)0xfffff81f, (FixedNum)0xfffffc23, (FixedNum)0xfffff97b, (FixedNum)0x00000742, (FixedNum)0x000007f2, (FixedNum)0x0000008d, (FixedNum)0x000000df, (FixedNum)0x00001ba4};
const int tmp_connections63[43] = {42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const FixedNum tmp_weights64[23] = {(FixedNum)0xfffffdbb, (FixedNum)0xffffdcb6, (FixedNum)0x0000188f, (FixedNum)0x0000032f, (FixedNum)0xfffff3d7, (FixedNum)0xffffed41, (FixedNum)0x000009de, (FixedNum)0x00000766, (FixedNum)0x00001971, (FixedNum)0x000009c2, (FixedNum)0x000013d9, (FixedNum)0x0000206a, (FixedNum)0x00000a50, (FixedNum)0x0000106d, (FixedNum)0x00000e26, (FixedNum)0xffffe480, (FixedNum)0xffffe952, (FixedNum)0xffffe5ec, (FixedNum)0x0000181a, (FixedNum)0xffffe864, (FixedNum)0x00000ff0, (FixedNum)0x00001134, (FixedNum)0x00000c89};
const int tmp_connections64[23] = {22, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights65[23] = {(FixedNum)0x00000248, (FixedNum)0x00002346, (FixedNum)0xffffe76c, (FixedNum)0xfffffd0a, (FixedNum)0x00000c28, (FixedNum)0x000012c0, (FixedNum)0xfffff621, (FixedNum)0xfffff894, (FixedNum)0xffffe68e, (FixedNum)0xfffff63d, (FixedNum)0xffffec26, (FixedNum)0xffffdf92, (FixedNum)0xfffff5b5, (FixedNum)0xffffef8c, (FixedNum)0xfffff1df, (FixedNum)0x00001b81, (FixedNum)0x000016af, (FixedNum)0x00001a10, (FixedNum)0xffffe7e6, (FixedNum)0x0000179c, (FixedNum)0xfffff00f, (FixedNum)0xffffeeca, (FixedNum)0xfffff37a};
const int tmp_connections65[23] = {22, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

const FixedNum tmp_weights66[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
const int tmp_connections66[2] = {1, 64};

const FixedNum tmp_weights67[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
const int tmp_connections67[2] = {1, 65};

const bool sigmoids[NUMBER_OF_NEURONS] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, false, false};

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
 * Output number 0 means that the instance was classified as 'm'
 * Output number 1 means that the instance was classified as 'f'
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
	m_weights[42] = tmp_weights42;
	m_connections[42] = tmp_connections42;
	m_weights[43] = tmp_weights43;
	m_connections[43] = tmp_connections43;
	m_weights[44] = tmp_weights44;
	m_connections[44] = tmp_connections44;
	m_weights[45] = tmp_weights45;
	m_connections[45] = tmp_connections45;
	m_weights[46] = tmp_weights46;
	m_connections[46] = tmp_connections46;
	m_weights[47] = tmp_weights47;
	m_connections[47] = tmp_connections47;
	m_weights[48] = tmp_weights48;
	m_connections[48] = tmp_connections48;
	m_weights[49] = tmp_weights49;
	m_connections[49] = tmp_connections49;
	m_weights[50] = tmp_weights50;
	m_connections[50] = tmp_connections50;
	m_weights[51] = tmp_weights51;
	m_connections[51] = tmp_connections51;
	m_weights[52] = tmp_weights52;
	m_connections[52] = tmp_connections52;
	m_weights[53] = tmp_weights53;
	m_connections[53] = tmp_connections53;
	m_weights[54] = tmp_weights54;
	m_connections[54] = tmp_connections54;
	m_weights[55] = tmp_weights55;
	m_connections[55] = tmp_connections55;
	m_weights[56] = tmp_weights56;
	m_connections[56] = tmp_connections56;
	m_weights[57] = tmp_weights57;
	m_connections[57] = tmp_connections57;
	m_weights[58] = tmp_weights58;
	m_connections[58] = tmp_connections58;
	m_weights[59] = tmp_weights59;
	m_connections[59] = tmp_connections59;
	m_weights[60] = tmp_weights60;
	m_connections[60] = tmp_connections60;
	m_weights[61] = tmp_weights61;
	m_connections[61] = tmp_connections61;
	m_weights[62] = tmp_weights62;
	m_connections[62] = tmp_connections62;
	m_weights[63] = tmp_weights63;
	m_connections[63] = tmp_connections63;
	m_weights[64] = tmp_weights64;
	m_connections[64] = tmp_connections64;
	m_weights[65] = tmp_weights65;
	m_connections[65] = tmp_connections65;
	m_weights[66] = tmp_weights66;
	m_connections[66] = tmp_connections66;
	m_weights[67] = tmp_weights67;
	m_connections[67] = tmp_connections67;
}
