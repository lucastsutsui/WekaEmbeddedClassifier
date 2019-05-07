
#include <Arduino.h>

#define M_ROOT 0
#define NUM_CLASSES 6
#define CLASS_INDEX 561
#define LEN_TREE 269
#define INPUT_SIZE 561

/* Instance array must be global
 * Attributes MUST be sorted in instance array in the following order:
 * att1
 * att2
 * att3
 * att4
 * att5
 * att6
 * att7
 * att8
 * att9
 * att10
 * att11
 * att12
 * att13
 * att14
 * att15
 * att16
 * att17
 * att18
 * att19
 * att20
 * att21
 * att22
 * att23
 * att24
 * att25
 * att26
 * att27
 * att28
 * att29
 * att30
 * att31
 * att32
 * att33
 * att34
 * att35
 * att36
 * att37
 * att38
 * att39
 * att40
 * att41
 * att42
 * att43
 * att44
 * att45
 * att46
 * att47
 * att48
 * att49
 * att50
 * att51
 * att52
 * att53
 * att54
 * att55
 * att56
 * att57
 * att58
 * att59
 * att60
 * att61
 * att62
 * att63
 * att64
 * att65
 * att66
 * att67
 * att68
 * att69
 * att70
 * att71
 * att72
 * att73
 * att74
 * att75
 * att76
 * att77
 * att78
 * att79
 * att80
 * att81
 * att82
 * att83
 * att84
 * att85
 * att86
 * att87
 * att88
 * att89
 * att90
 * att91
 * att92
 * att93
 * att94
 * att95
 * att96
 * att97
 * att98
 * att99
 * att100
 * att101
 * att102
 * att103
 * att104
 * att105
 * att106
 * att107
 * att108
 * att109
 * att110
 * att111
 * att112
 * att113
 * att114
 * att115
 * att116
 * att117
 * att118
 * att119
 * att120
 * att121
 * att122
 * att123
 * att124
 * att125
 * att126
 * att127
 * att128
 * att129
 * att130
 * att131
 * att132
 * att133
 * att134
 * att135
 * att136
 * att137
 * att138
 * att139
 * att140
 * att141
 * att142
 * att143
 * att144
 * att145
 * att146
 * att147
 * att148
 * att149
 * att150
 * att151
 * att152
 * att153
 * att154
 * att155
 * att156
 * att157
 * att158
 * att159
 * att160
 * att161
 * att162
 * att163
 * att164
 * att165
 * att166
 * att167
 * att168
 * att169
 * att170
 * att171
 * att172
 * att173
 * att174
 * att175
 * att176
 * att177
 * att178
 * att179
 * att180
 * att181
 * att182
 * att183
 * att184
 * att185
 * att186
 * att187
 * att188
 * att189
 * att190
 * att191
 * att192
 * att193
 * att194
 * att195
 * att196
 * att197
 * att198
 * att199
 * att200
 * att201
 * att202
 * att203
 * att204
 * att205
 * att206
 * att207
 * att208
 * att209
 * att210
 * att211
 * att212
 * att213
 * att214
 * att215
 * att216
 * att217
 * att218
 * att219
 * att220
 * att221
 * att222
 * att223
 * att224
 * att225
 * att226
 * att227
 * att228
 * att229
 * att230
 * att231
 * att232
 * att233
 * att234
 * att235
 * att236
 * att237
 * att238
 * att239
 * att240
 * att241
 * att242
 * att243
 * att244
 * att245
 * att246
 * att247
 * att248
 * att249
 * att250
 * att251
 * att252
 * att253
 * att254
 * att255
 * att256
 * att257
 * att258
 * att259
 * att260
 * att261
 * att262
 * att263
 * att264
 * att265
 * att266
 * att267
 * att268
 * att269
 * att270
 * att271
 * att272
 * att273
 * att274
 * att275
 * att276
 * att277
 * att278
 * att279
 * att280
 * att281
 * att282
 * att283
 * att284
 * att285
 * att286
 * att287
 * att288
 * att289
 * att290
 * att291
 * att292
 * att293
 * att294
 * att295
 * att296
 * att297
 * att298
 * att299
 * att300
 * att301
 * att302
 * att303
 * att304
 * att305
 * att306
 * att307
 * att308
 * att309
 * att310
 * att311
 * att312
 * att313
 * att314
 * att315
 * att316
 * att317
 * att318
 * att319
 * att320
 * att321
 * att322
 * att323
 * att324
 * att325
 * att326
 * att327
 * att328
 * att329
 * att330
 * att331
 * att332
 * att333
 * att334
 * att335
 * att336
 * att337
 * att338
 * att339
 * att340
 * att341
 * att342
 * att343
 * att344
 * att345
 * att346
 * att347
 * att348
 * att349
 * att350
 * att351
 * att352
 * att353
 * att354
 * att355
 * att356
 * att357
 * att358
 * att359
 * att360
 * att361
 * att362
 * att363
 * att364
 * att365
 * att366
 * att367
 * att368
 * att369
 * att370
 * att371
 * att372
 * att373
 * att374
 * att375
 * att376
 * att377
 * att378
 * att379
 * att380
 * att381
 * att382
 * att383
 * att384
 * att385
 * att386
 * att387
 * att388
 * att389
 * att390
 * att391
 * att392
 * att393
 * att394
 * att395
 * att396
 * att397
 * att398
 * att399
 * att400
 * att401
 * att402
 * att403
 * att404
 * att405
 * att406
 * att407
 * att408
 * att409
 * att410
 * att411
 * att412
 * att413
 * att414
 * att415
 * att416
 * att417
 * att418
 * att419
 * att420
 * att421
 * att422
 * att423
 * att424
 * att425
 * att426
 * att427
 * att428
 * att429
 * att430
 * att431
 * att432
 * att433
 * att434
 * att435
 * att436
 * att437
 * att438
 * att439
 * att440
 * att441
 * att442
 * att443
 * att444
 * att445
 * att446
 * att447
 * att448
 * att449
 * att450
 * att451
 * att452
 * att453
 * att454
 * att455
 * att456
 * att457
 * att458
 * att459
 * att460
 * att461
 * att462
 * att463
 * att464
 * att465
 * att466
 * att467
 * att468
 * att469
 * att470
 * att471
 * att472
 * att473
 * att474
 * att475
 * att476
 * att477
 * att478
 * att479
 * att480
 * att481
 * att482
 * att483
 * att484
 * att485
 * att486
 * att487
 * att488
 * att489
 * att490
 * att491
 * att492
 * att493
 * att494
 * att495
 * att496
 * att497
 * att498
 * att499
 * att500
 * att501
 * att502
 * att503
 * att504
 * att505
 * att506
 * att507
 * att508
 * att509
 * att510
 * att511
 * att512
 * att513
 * att514
 * att515
 * att516
 * att517
 * att518
 * att519
 * att520
 * att521
 * att522
 * att523
 * att524
 * att525
 * att526
 * att527
 * att528
 * att529
 * att530
 * att531
 * att532
 * att533
 * att534
 * att535
 * att536
 * att537
 * att538
 * att539
 * att540
 * att541
 * att542
 * att543
 * att544
 * att545
 * att546
 * att547
 * att548
 * att549
 * att550
 * att551
 * att552
 * att553
 * att554
 * att555
 * att556
 * att557
 * att558
 * att559
 * att560
 * att561
 */
float instance[INPUT_SIZE+1];

int m_attIndex[LEN_TREE] = {52, -1, 381, 50, 426, 22, 335, -1, 163, -1, -1, -1, 51, 132, 451, -1, 149, 461, 64, 53, -1, 389, 334, -1, -1, -1, -1, -1, 158, 372, 14, -1, -1, 156, 204, 16, -1, -1, -1, 41, -1, -1, 96, -1, -1, 144, -1, 135, -1, -1, 52, 381, 185, -1, -1, -1, -1, 55, 129, 159, 55, 57, -1, -1, 557, 6, 57, -1, -1, 132, 425, 432, -1, -1, -1, -1, 120, -1, 305, 321, -1, -1, -1, 383, -1, -1, 430, -1, 426, 99, -1, -1, 13, -1, 468, 409, 58, 55, -1, 26, -1, -1, 126, 498, -1, 411, -1, -1, -1, 287, -1, -1, 242, 31, -1, -1, -1, 22, -1, 42, -1, -1, 508, 69, 9, 547, -1, 524, 136, -1, -1, -1, 558, 49, 117, 104, -1, -1, -1, -1, 54, 450, 409, 558, 125, 9, -1, -1, -1, -1, 196, 518, 38, 52, -1, -1, 72, 433, -1, -1, 275, 338, 26, -1, -1, -1, -1, 281, -1, 434, 100, -1, -1, -1, 419, -1, -1, 38, -1, 65, 461, 274, -1, 149, 310, -1, -1, -1, -1, -1, -1, 456, 448, 302, -1, 242, 298, 458, -1, -1, -1, -1, 503, 65, 74, 37, -1, -1, -1, 76, 37, 552, -1, -1, -1, 38, -1, 192, -1, -1, 232, 290, 53, -1, 370, -1, -1, -1, -1, 292, -1, -1, 73, 9, -1, -1, 474, 65, 89, 53, -1, 9, -1, -1, 418, 19, -1, -1, 57, 198, 453, 524, -1, -1, -1, 537, -1, -1, 475, 502, -1, -1, -1, 22, -1, -1, 292, -1, -1};

float m_splitPoint[LEN_TREE] = {-0.004372, -1, -0.98461, -0.10867, -0.99657, -0.70674, -0.99977, -1, -0.99799, -1, -1, -1, 0.22303, 0.84503, -0.083296, -1, -0.25509, -0.99936, -0.60931, -0.30189, -1, -0.99954, -0.9998, -1, -1, -1, -1, -1, 0.74521, -0.13553, 0.80242, -1, -1, 0.40095, -0.9988, -0.99997, -1, -1, -1, -0.13835, -1, -1, -0.99994, -1, -1, -0.54265, -1, -0.9847, -1, -1, 0.92493, -0.99966, 0.18363, -1, -1, -1, -1, -0.28548, -0.87341, 0.44593, -0.83172, -0.9997, -1, -1, 0.48934, -0.99876, -0.99935, -1, -1, 0.83982, -0.98359, -0.99307, -1, -1, -1, -1, -0.031934, -1, -0.99992, -0.99975, -1, -1, -1, -0.99985, -1, -1, -0.98806, -1, -0.9832, -0.99275, -1, -1, 0.50464, -1, -0.99735, -0.99786, -0.99241, -0.91951, -1, -0.21559, -1, -1, -0.97572, -0.99989, -1, -0.99903, -1, -1, -1, -0.4512, -1, -1, -0.58301, -0.25926, -1, -1, -1, 0.11772, -1, -0.11622, -1, -1, -0.55216, -0.28834, -0.34562, -0.97863, -1, -0.84127, -0.67529, -1, -1, -1, -0.84516, 0.92039, -0.14511, 0.63351, -1, -1, -1, -1, 0.24267, -0.7931, -0.93853, -0.75586, -0.40277, -0.25803, -1, -1, -1, -1, 0.30634, -0.30246, -0.59677, 0.90015, -1, -1, 0.4176, -0.10837, -1, -1, -0.46287, -0.75904, 0.41217, -1, -1, -1, -1, -0.79885, -1, -0.48307, -0.32852, -1, -1, -1, -0.94249, -1, -1, -0.44045, -1, -0.52613, -0.65452, -0.53146, -1, -0.16056, -0.37713, -1, -1, -1, -1, -1, -1, 0.40476, -1.0, -0.8045, -1, -0.02333, -0.42012, 0.000876, -1, -1, -1, -1, -0.30982, -0.63538, 0.67421, -0.17764, -1, -1, -1, 0.68914, -0.39375, -0.31267, -1, -1, -1, -0.31544, -1, -0.21167, -1, -1, -0.5657, -0.67742, -0.24274, -1, -0.6, -1, -1, -1, -1, -0.84615, -1, -1, -0.65902, 0.45555, -1, -1, -0.1797, -0.33897, -0.46735, -0.1986, -1, 0.23795, -1, -1, -0.95778, -0.22279, -1, -1, -0.84865, 0.62332, -0.33442, -0.77778, -1, -1, -1, -0.64103, -1, -1, -0.74693, 0.022285, -1, -1, -1, 0.35057, -1, -1, -0.69231, -1, -1};

const int *tree[LEN_TREE];
int tree_0[2] = {1, 2};
int tree_2[2] = {3, 122};
int tree_3[2] = {4, 57};
int tree_4[2] = {5, 12};
int tree_5[2] = {6, 11};
int tree_6[2] = {7, 8};
int tree_8[2] = {9, 10};
int tree_12[2] = {13, 50};
int tree_13[2] = {14, 45};
int tree_14[2] = {15, 16};
int tree_16[2] = {17, 28};
int tree_17[2] = {18, 27};
int tree_18[2] = {19, 26};
int tree_19[2] = {20, 21};
int tree_21[2] = {22, 25};
int tree_22[2] = {23, 24};
int tree_28[2] = {29, 42};
int tree_29[2] = {30, 33};
int tree_30[2] = {31, 32};
int tree_33[2] = {34, 39};
int tree_34[2] = {35, 38};
int tree_35[2] = {36, 37};
int tree_39[2] = {40, 41};
int tree_42[2] = {43, 44};
int tree_45[2] = {46, 47};
int tree_47[2] = {48, 49};
int tree_50[2] = {51, 56};
int tree_51[2] = {52, 55};
int tree_52[2] = {53, 54};
int tree_57[2] = {58, 117};
int tree_58[2] = {59, 86};
int tree_59[2] = {60, 83};
int tree_60[2] = {61, 64};
int tree_61[2] = {62, 63};
int tree_64[2] = {65, 76};
int tree_65[2] = {66, 69};
int tree_66[2] = {67, 68};
int tree_69[2] = {70, 75};
int tree_70[2] = {71, 74};
int tree_71[2] = {72, 73};
int tree_76[2] = {77, 78};
int tree_78[2] = {79, 82};
int tree_79[2] = {80, 81};
int tree_83[2] = {84, 85};
int tree_86[2] = {87, 88};
int tree_88[2] = {89, 92};
int tree_89[2] = {90, 91};
int tree_92[2] = {93, 94};
int tree_94[2] = {95, 112};
int tree_95[2] = {96, 109};
int tree_96[2] = {97, 102};
int tree_97[2] = {98, 99};
int tree_99[2] = {100, 101};
int tree_102[2] = {103, 108};
int tree_103[2] = {104, 105};
int tree_105[2] = {106, 107};
int tree_109[2] = {110, 111};
int tree_112[2] = {113, 116};
int tree_113[2] = {114, 115};
int tree_117[2] = {118, 119};
int tree_119[2] = {120, 121};
int tree_122[2] = {123, 232};
int tree_123[2] = {124, 191};
int tree_124[2] = {125, 132};
int tree_125[2] = {126, 127};
int tree_127[2] = {128, 131};
int tree_128[2] = {129, 130};
int tree_132[2] = {133, 140};
int tree_133[2] = {134, 139};
int tree_134[2] = {135, 138};
int tree_135[2] = {136, 137};
int tree_140[2] = {141, 190};
int tree_141[2] = {142, 177};
int tree_142[2] = {143, 150};
int tree_143[2] = {144, 149};
int tree_144[2] = {145, 148};
int tree_145[2] = {146, 147};
int tree_150[2] = {151, 174};
int tree_151[2] = {152, 167};
int tree_152[2] = {153, 156};
int tree_153[2] = {154, 155};
int tree_156[2] = {157, 160};
int tree_157[2] = {158, 159};
int tree_160[2] = {161, 166};
int tree_161[2] = {162, 165};
int tree_162[2] = {163, 164};
int tree_167[2] = {168, 169};
int tree_169[2] = {170, 173};
int tree_170[2] = {171, 172};
int tree_174[2] = {175, 176};
int tree_177[2] = {178, 179};
int tree_179[2] = {180, 189};
int tree_180[2] = {181, 188};
int tree_181[2] = {182, 183};
int tree_183[2] = {184, 187};
int tree_184[2] = {185, 186};
int tree_191[2] = {192, 229};
int tree_192[2] = {193, 202};
int tree_193[2] = {194, 195};
int tree_195[2] = {196, 201};
int tree_196[2] = {197, 200};
int tree_197[2] = {198, 199};
int tree_202[2] = {203, 220};
int tree_203[2] = {204, 209};
int tree_204[2] = {205, 208};
int tree_205[2] = {206, 207};
int tree_209[2] = {210, 215};
int tree_210[2] = {211, 214};
int tree_211[2] = {212, 213};
int tree_215[2] = {216, 217};
int tree_217[2] = {218, 219};
int tree_220[2] = {221, 228};
int tree_221[2] = {222, 227};
int tree_222[2] = {223, 224};
int tree_224[2] = {225, 226};
int tree_229[2] = {230, 231};
int tree_232[2] = {233, 236};
int tree_233[2] = {234, 235};
int tree_236[2] = {237, 266};
int tree_237[2] = {238, 263};
int tree_238[2] = {239, 244};
int tree_239[2] = {240, 241};
int tree_241[2] = {242, 243};
int tree_244[2] = {245, 248};
int tree_245[2] = {246, 247};
int tree_248[2] = {249, 258};
int tree_249[2] = {250, 255};
int tree_250[2] = {251, 254};
int tree_251[2] = {252, 253};
int tree_255[2] = {256, 257};
int tree_258[2] = {259, 262};
int tree_259[2] = {260, 261};
int tree_263[2] = {264, 265};
int tree_266[2] = {267, 268};

float *classProb1[LEN_TREE];
float classProb1_1[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 1.0};
float classProb1_7[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_9[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_10[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_11[6] = {0.0, 0.0, 0.0, 0.037037037037037035, 0.9629629629629629, 0.0};
float classProb1_15[6] = {0.0, 0.0, 0.0, 0.9891745602165088, 0.010825439783491205, 0.0};
float classProb1_20[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_23[6] = {0.0, 0.0, 0.0, 0.75, 0.25, 0.0};
float classProb1_24[6] = {0.0, 0.0, 0.0, 0.03125, 0.96875, 0.0};
float classProb1_25[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_26[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_27[6] = {0.0, 0.0, 0.0, 0.9705882352941176, 0.029411764705882353, 0.0};
float classProb1_31[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_32[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_36[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_37[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_38[6] = {0.0, 0.0, 0.0, 0.9958847736625515, 0.00411522633744856, 0.0};
float classProb1_40[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_41[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_43[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_44[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_46[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_48[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_49[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_53[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_54[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_55[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_56[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_62[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_63[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_67[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_68[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_72[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_73[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_74[6] = {0.0, 0.0, 0.0, 0.007246376811594203, 0.9927536231884058, 0.0};
float classProb1_75[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_77[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_80[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_81[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_82[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_84[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_85[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_87[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_90[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_91[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_93[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_98[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_100[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_101[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_104[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_106[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_107[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_108[6] = {0.0, 0.0, 0.0, 0.9803921568627451, 0.0196078431372549, 0.0};
float classProb1_110[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_111[6] = {0.0, 0.0, 0.0, 0.75, 0.25, 0.0};
float classProb1_114[6] = {0.0, 0.0, 0.0, 0.25, 0.75, 0.0};
float classProb1_115[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_116[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_118[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_120[6] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
float classProb1_121[6] = {0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
float classProb1_126[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_129[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_130[6] = {0.0, 0.6666666666666666, 0.3333333333333333, 0.0, 0.0, 0.0};
float classProb1_131[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_136[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_137[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_138[6] = {0.9705882352941176, 0.029411764705882353, 0.0, 0.0, 0.0, 0.0};
float classProb1_139[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_146[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_147[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_148[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_149[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_154[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_155[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_158[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_159[6] = {0.8571428571428571, 0.0, 0.14285714285714285, 0.0, 0.0, 0.0};
float classProb1_163[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_164[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_165[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_166[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_168[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_171[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_172[6] = {0.2, 0.0, 0.8, 0.0, 0.0, 0.0};
float classProb1_173[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_175[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_176[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_178[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_182[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_185[6] = {0.031746031746031744, 0.015873015873015872, 0.9523809523809523, 0.0, 0.0, 0.0};
float classProb1_186[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_187[6] = {0.2, 0.8, 0.0, 0.0, 0.0, 0.0};
float classProb1_188[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_189[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_190[6] = {0.05, 0.95, 0.0, 0.0, 0.0, 0.0};
float classProb1_194[6] = {0.9230769230769231, 0.0, 0.07692307692307693, 0.0, 0.0, 0.0};
float classProb1_198[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_199[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_200[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_201[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_206[6] = {0.0, 0.8888888888888888, 0.1111111111111111, 0.0, 0.0, 0.0};
float classProb1_207[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_208[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_212[6] = {0.0, 0.25, 0.75, 0.0, 0.0, 0.0};
float classProb1_213[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_214[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_216[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_218[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_219[6] = {0.9696969696969697, 0.0, 0.030303030303030304, 0.0, 0.0, 0.0};
float classProb1_223[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_225[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_226[6] = {0.043478260869565216, 0.9130434782608695, 0.043478260869565216, 0.0, 0.0, 0.0};
float classProb1_227[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_228[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_230[6] = {0.0, 0.041666666666666664, 0.9583333333333334, 0.0, 0.0, 0.0};
float classProb1_231[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_234[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_235[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_240[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_242[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_243[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_246[6] = {0.0, 0.1, 0.9, 0.0, 0.0, 0.0};
float classProb1_247[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_252[6] = {0.058823529411764705, 0.9411764705882353, 0.0, 0.0, 0.0, 0.0};
float classProb1_253[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_254[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_256[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_257[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_260[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_261[6] = {0.0, 0.9846153846153847, 0.015384615384615385, 0.0, 0.0, 0.0};
float classProb1_262[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_264[6] = {0.0, 1.0, 0.0, 0.0, 0.0, 0.0};
float classProb1_265[6] = {0.9333333333333333, 0.06666666666666667, 0.0, 0.0, 0.0, 0.0};
float classProb1_267[6] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0};
float classProb1_268[6] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};


float getProbs(int i, int classIndex, float weight){
	if (m_attIndex[i] == -1){
		return weight * classProb1[i][classIndex]);
	}
	int treeIndex = (instance[m_attIndex[i]] <= m_splitPoint[i] ? 0 : 1);
	return getProbs(tree[i][treeIndex], classIndex, weight);
}

/* Function classify description:
 * Instance array must be initializated, with appropriated attributes, before calling this function
 * Output number 0 means that the instance was classified as 1
 * Output number 1 means that the instance was classified as 3
 * Output number 2 means that the instance was classified as 2
 * Output number 3 means that the instance was classified as 5
 * Output number 4 means that the instance was classified as 4
 * Output number 5 means that the instance was classified as 6
 */
int classify(){
	float doubles[NUM_CLASSES];
	for (int i = 0; i < NUM_CLASSES; i++){
		doubles[i] = getProbs(M_ROOT, i, 1);
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
	tree[2] = tree_2;
	tree[3] = tree_3;
	tree[4] = tree_4;
	tree[5] = tree_5;
	tree[6] = tree_6;
	tree[8] = tree_8;
	tree[12] = tree_12;
	tree[13] = tree_13;
	tree[14] = tree_14;
	tree[16] = tree_16;
	tree[17] = tree_17;
	tree[18] = tree_18;
	tree[19] = tree_19;
	tree[21] = tree_21;
	tree[22] = tree_22;
	tree[28] = tree_28;
	tree[29] = tree_29;
	tree[30] = tree_30;
	tree[33] = tree_33;
	tree[34] = tree_34;
	tree[35] = tree_35;
	tree[39] = tree_39;
	tree[42] = tree_42;
	tree[45] = tree_45;
	tree[47] = tree_47;
	tree[50] = tree_50;
	tree[51] = tree_51;
	tree[52] = tree_52;
	tree[57] = tree_57;
	tree[58] = tree_58;
	tree[59] = tree_59;
	tree[60] = tree_60;
	tree[61] = tree_61;
	tree[64] = tree_64;
	tree[65] = tree_65;
	tree[66] = tree_66;
	tree[69] = tree_69;
	tree[70] = tree_70;
	tree[71] = tree_71;
	tree[76] = tree_76;
	tree[78] = tree_78;
	tree[79] = tree_79;
	tree[83] = tree_83;
	tree[86] = tree_86;
	tree[88] = tree_88;
	tree[89] = tree_89;
	tree[92] = tree_92;
	tree[94] = tree_94;
	tree[95] = tree_95;
	tree[96] = tree_96;
	tree[97] = tree_97;
	tree[99] = tree_99;
	tree[102] = tree_102;
	tree[103] = tree_103;
	tree[105] = tree_105;
	tree[109] = tree_109;
	tree[112] = tree_112;
	tree[113] = tree_113;
	tree[117] = tree_117;
	tree[119] = tree_119;
	tree[122] = tree_122;
	tree[123] = tree_123;
	tree[124] = tree_124;
	tree[125] = tree_125;
	tree[127] = tree_127;
	tree[128] = tree_128;
	tree[132] = tree_132;
	tree[133] = tree_133;
	tree[134] = tree_134;
	tree[135] = tree_135;
	tree[140] = tree_140;
	tree[141] = tree_141;
	tree[142] = tree_142;
	tree[143] = tree_143;
	tree[144] = tree_144;
	tree[145] = tree_145;
	tree[150] = tree_150;
	tree[151] = tree_151;
	tree[152] = tree_152;
	tree[153] = tree_153;
	tree[156] = tree_156;
	tree[157] = tree_157;
	tree[160] = tree_160;
	tree[161] = tree_161;
	tree[162] = tree_162;
	tree[167] = tree_167;
	tree[169] = tree_169;
	tree[170] = tree_170;
	tree[174] = tree_174;
	tree[177] = tree_177;
	tree[179] = tree_179;
	tree[180] = tree_180;
	tree[181] = tree_181;
	tree[183] = tree_183;
	tree[184] = tree_184;
	tree[191] = tree_191;
	tree[192] = tree_192;
	tree[193] = tree_193;
	tree[195] = tree_195;
	tree[196] = tree_196;
	tree[197] = tree_197;
	tree[202] = tree_202;
	tree[203] = tree_203;
	tree[204] = tree_204;
	tree[205] = tree_205;
	tree[209] = tree_209;
	tree[210] = tree_210;
	tree[211] = tree_211;
	tree[215] = tree_215;
	tree[217] = tree_217;
	tree[220] = tree_220;
	tree[221] = tree_221;
	tree[222] = tree_222;
	tree[224] = tree_224;
	tree[229] = tree_229;
	tree[232] = tree_232;
	tree[233] = tree_233;
	tree[236] = tree_236;
	tree[237] = tree_237;
	tree[238] = tree_238;
	tree[239] = tree_239;
	tree[241] = tree_241;
	tree[244] = tree_244;
	tree[245] = tree_245;
	tree[248] = tree_248;
	tree[249] = tree_249;
	tree[250] = tree_250;
	tree[251] = tree_251;
	tree[255] = tree_255;
	tree[258] = tree_258;
	tree[259] = tree_259;
	tree[263] = tree_263;
	tree[266] = tree_266;

	classProb1[1] = classProb1_1;
	classProb1[7] = classProb1_7;
	classProb1[9] = classProb1_9;
	classProb1[10] = classProb1_10;
	classProb1[11] = classProb1_11;
	classProb1[15] = classProb1_15;
	classProb1[20] = classProb1_20;
	classProb1[23] = classProb1_23;
	classProb1[24] = classProb1_24;
	classProb1[25] = classProb1_25;
	classProb1[26] = classProb1_26;
	classProb1[27] = classProb1_27;
	classProb1[31] = classProb1_31;
	classProb1[32] = classProb1_32;
	classProb1[36] = classProb1_36;
	classProb1[37] = classProb1_37;
	classProb1[38] = classProb1_38;
	classProb1[40] = classProb1_40;
	classProb1[41] = classProb1_41;
	classProb1[43] = classProb1_43;
	classProb1[44] = classProb1_44;
	classProb1[46] = classProb1_46;
	classProb1[48] = classProb1_48;
	classProb1[49] = classProb1_49;
	classProb1[53] = classProb1_53;
	classProb1[54] = classProb1_54;
	classProb1[55] = classProb1_55;
	classProb1[56] = classProb1_56;
	classProb1[62] = classProb1_62;
	classProb1[63] = classProb1_63;
	classProb1[67] = classProb1_67;
	classProb1[68] = classProb1_68;
	classProb1[72] = classProb1_72;
	classProb1[73] = classProb1_73;
	classProb1[74] = classProb1_74;
	classProb1[75] = classProb1_75;
	classProb1[77] = classProb1_77;
	classProb1[80] = classProb1_80;
	classProb1[81] = classProb1_81;
	classProb1[82] = classProb1_82;
	classProb1[84] = classProb1_84;
	classProb1[85] = classProb1_85;
	classProb1[87] = classProb1_87;
	classProb1[90] = classProb1_90;
	classProb1[91] = classProb1_91;
	classProb1[93] = classProb1_93;
	classProb1[98] = classProb1_98;
	classProb1[100] = classProb1_100;
	classProb1[101] = classProb1_101;
	classProb1[104] = classProb1_104;
	classProb1[106] = classProb1_106;
	classProb1[107] = classProb1_107;
	classProb1[108] = classProb1_108;
	classProb1[110] = classProb1_110;
	classProb1[111] = classProb1_111;
	classProb1[114] = classProb1_114;
	classProb1[115] = classProb1_115;
	classProb1[116] = classProb1_116;
	classProb1[118] = classProb1_118;
	classProb1[120] = classProb1_120;
	classProb1[121] = classProb1_121;
	classProb1[126] = classProb1_126;
	classProb1[129] = classProb1_129;
	classProb1[130] = classProb1_130;
	classProb1[131] = classProb1_131;
	classProb1[136] = classProb1_136;
	classProb1[137] = classProb1_137;
	classProb1[138] = classProb1_138;
	classProb1[139] = classProb1_139;
	classProb1[146] = classProb1_146;
	classProb1[147] = classProb1_147;
	classProb1[148] = classProb1_148;
	classProb1[149] = classProb1_149;
	classProb1[154] = classProb1_154;
	classProb1[155] = classProb1_155;
	classProb1[158] = classProb1_158;
	classProb1[159] = classProb1_159;
	classProb1[163] = classProb1_163;
	classProb1[164] = classProb1_164;
	classProb1[165] = classProb1_165;
	classProb1[166] = classProb1_166;
	classProb1[168] = classProb1_168;
	classProb1[171] = classProb1_171;
	classProb1[172] = classProb1_172;
	classProb1[173] = classProb1_173;
	classProb1[175] = classProb1_175;
	classProb1[176] = classProb1_176;
	classProb1[178] = classProb1_178;
	classProb1[182] = classProb1_182;
	classProb1[185] = classProb1_185;
	classProb1[186] = classProb1_186;
	classProb1[187] = classProb1_187;
	classProb1[188] = classProb1_188;
	classProb1[189] = classProb1_189;
	classProb1[190] = classProb1_190;
	classProb1[194] = classProb1_194;
	classProb1[198] = classProb1_198;
	classProb1[199] = classProb1_199;
	classProb1[200] = classProb1_200;
	classProb1[201] = classProb1_201;
	classProb1[206] = classProb1_206;
	classProb1[207] = classProb1_207;
	classProb1[208] = classProb1_208;
	classProb1[212] = classProb1_212;
	classProb1[213] = classProb1_213;
	classProb1[214] = classProb1_214;
	classProb1[216] = classProb1_216;
	classProb1[218] = classProb1_218;
	classProb1[219] = classProb1_219;
	classProb1[223] = classProb1_223;
	classProb1[225] = classProb1_225;
	classProb1[226] = classProb1_226;
	classProb1[227] = classProb1_227;
	classProb1[228] = classProb1_228;
	classProb1[230] = classProb1_230;
	classProb1[231] = classProb1_231;
	classProb1[234] = classProb1_234;
	classProb1[235] = classProb1_235;
	classProb1[240] = classProb1_240;
	classProb1[242] = classProb1_242;
	classProb1[243] = classProb1_243;
	classProb1[246] = classProb1_246;
	classProb1[247] = classProb1_247;
	classProb1[252] = classProb1_252;
	classProb1[253] = classProb1_253;
	classProb1[254] = classProb1_254;
	classProb1[256] = classProb1_256;
	classProb1[257] = classProb1_257;
	classProb1[260] = classProb1_260;
	classProb1[261] = classProb1_261;
	classProb1[262] = classProb1_262;
	classProb1[264] = classProb1_264;
	classProb1[265] = classProb1_265;
	classProb1[267] = classProb1_267;
	classProb1[268] = classProb1_268;
}
