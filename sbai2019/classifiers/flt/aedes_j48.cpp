
#include <Arduino.h>

#define M_ROOT 0
#define NUM_CLASSES 2
#define CLASS_INDEX 42
#define LEN_TREE 183
#define INPUT_SIZE 42

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
float instance[INPUT_SIZE+1];

int m_attIndex[LEN_TREE] = {14, 12, 13, 9, 9, 13, 14, 41, -1, -1, -1, 1, 1, -1, -1, 32, -1, 4, -1, -1, 20, 2, -1, 10, -1, -1, -1, -1, -1, 1, 2, 0, 1, -1, -1, 13, 0, 25, -1, -1, -1, -1, 2, 1, 40, -1, 0, -1, -1, -1, 27, 21, -1, -1, -1, 16, 8, -1, -1, 6, 6, 8, -1, 41, -1, -1, 40, 9, -1, -1, -1, 14, 41, 14, -1, 41, 9, -1, 40, 12, -1, 1, -1, 19, -1, -1, -1, 7, -1, 10, 18, -1, -1, -1, 27, 12, -1, -1, -1, 1, 2, -1, 1, -1, 13, -1, 13, 0, -1, 2, -1, -1, -1, 12, 34, -1, -1, -1, 14, 41, 1, -1, 2, 6, -1, 10, -1, -1, 20, -1, 14, -1, 25, -1, -1, 41, 2, 0, 5, -1, 0, -1, -1, -1, -1, 12, 41, -1, 21, -1, -1, 29, 38, -1, -1, -1, 16, 12, 11, -1, 0, -1, -1, 13, 14, -1, -1, 14, 41, -1, 2, 13, -1, -1, -1, 1, -1, -1, 6, 3, -1, -1, -1};

float m_splitPoint[LEN_TREE] = {721.59752433296, 460.01648469043, 1.1170586528304, 947.26379178002, 217.78556641541, 1.0774343535115, 231.39264102024, 4.0, -1, -1, -1, 24.7, 23.4, -1, -1, 0.23397796363459, -1, 3.3444880770775, -1, -1, 0.23925082301562, 211.00478468899, -1, 1078.3815849079, -1, -1, -1, -1, -1, 23.6, 544.44444444444, 2.0, 23.4, -1, -1, 1.1092791491682, 17.0, 0.61473509832866, -1, -1, -1, -1, 572.72727272727, 23.4, 0.41667676626313, -1, 17.0, -1, -1, -1, 0.2022221462498, 0.18300860161981, -1, -1, -1, 0.027856458717892, 2380.7506854951, -1, -1, 391.03456138354, 131.69346890745, 1219.3655519038, -1, 5.0, -1, -1, 0.08498608147144, 1391.1523031144, -1, -1, -1, 686.94671381743, 2.0, 635.20764238129, -1, 1.0, 87.604408194313, -1, 0.23068083552223, 1066.280964049, -1, 23.9, -1, 0.1549589854219, -1, -1, -1, 1206.074805567, -1, 2405.808090701, 0.10047063057697, -1, -1, -1, 0.030040447893402, 1472.0674531288, -1, -1, -1, 26.8, 621.12676056338, -1, 25.3, -1, 1.0942059260854, -1, 1.1080522867894, 16.0, -1, 630.0, -1, -1, -1, 927.65502038221, 0.12959767472593, -1, -1, -1, 786.34285328014, 2.0, 25.4, -1, 668.18181818182, 1305.8559546309, -1, 58.936940959366, -1, -1, 0.39825941959794, -1, 748.51189591169, -1, 0.29718683130953, -1, -1, 3.0, 700.0, 17.0, 0.046439909297052, -1, 14.0, -1, -1, -1, -1, 891.4102434772, 4.0, -1, 0.13971680546526, -1, -1, 0.25749464204865, 0.048030071164658, -1, -1, -1, 0.76610728833838, 572.83636350118, 1588.4454149738, -1, 12.0, -1, -1, 1.0670583666919, 823.02238071437, -1, -1, 1192.1485400184, 4.0, -1, 801.81818181818, 1.0874832018943, -1, -1, -1, 29.4, -1, -1, 216.23930881274, 0.30410276719251, -1, -1, -1};

const int *tree[LEN_TREE];
int tree_0[2] = {1, 118};
int tree_1[2] = {2, 29};
int tree_2[2] = {3, 28};
int tree_3[2] = {4, 27};
int tree_4[2] = {5, 20};
int tree_5[2] = {6, 11};
int tree_6[2] = {7, 10};
int tree_7[2] = {8, 9};
int tree_11[2] = {12, 15};
int tree_12[2] = {13, 14};
int tree_15[2] = {16, 17};
int tree_17[2] = {18, 19};
int tree_20[2] = {21, 26};
int tree_21[2] = {22, 23};
int tree_23[2] = {24, 25};
int tree_29[2] = {30, 55};
int tree_30[2] = {31, 42};
int tree_31[2] = {32, 35};
int tree_32[2] = {33, 34};
int tree_35[2] = {36, 41};
int tree_36[2] = {37, 40};
int tree_37[2] = {38, 39};
int tree_42[2] = {43, 50};
int tree_43[2] = {44, 49};
int tree_44[2] = {45, 46};
int tree_46[2] = {47, 48};
int tree_50[2] = {51, 54};
int tree_51[2] = {52, 53};
int tree_55[2] = {56, 59};
int tree_56[2] = {57, 58};
int tree_59[2] = {60, 71};
int tree_60[2] = {61, 66};
int tree_61[2] = {62, 63};
int tree_63[2] = {64, 65};
int tree_66[2] = {67, 70};
int tree_67[2] = {68, 69};
int tree_71[2] = {72, 99};
int tree_72[2] = {73, 94};
int tree_73[2] = {74, 75};
int tree_75[2] = {76, 87};
int tree_76[2] = {77, 78};
int tree_78[2] = {79, 86};
int tree_79[2] = {80, 81};
int tree_81[2] = {82, 83};
int tree_83[2] = {84, 85};
int tree_87[2] = {88, 89};
int tree_89[2] = {90, 93};
int tree_90[2] = {91, 92};
int tree_94[2] = {95, 98};
int tree_95[2] = {96, 97};
int tree_99[2] = {100, 113};
int tree_100[2] = {101, 102};
int tree_102[2] = {103, 104};
int tree_104[2] = {105, 106};
int tree_106[2] = {107, 112};
int tree_107[2] = {108, 109};
int tree_109[2] = {110, 111};
int tree_113[2] = {114, 117};
int tree_114[2] = {115, 116};
int tree_118[2] = {119, 156};
int tree_119[2] = {120, 135};
int tree_120[2] = {121, 122};
int tree_122[2] = {123, 128};
int tree_123[2] = {124, 125};
int tree_125[2] = {126, 127};
int tree_128[2] = {129, 130};
int tree_130[2] = {131, 132};
int tree_132[2] = {133, 134};
int tree_135[2] = {136, 145};
int tree_136[2] = {137, 144};
int tree_137[2] = {138, 143};
int tree_138[2] = {139, 140};
int tree_140[2] = {141, 142};
int tree_145[2] = {146, 151};
int tree_146[2] = {147, 148};
int tree_148[2] = {149, 150};
int tree_151[2] = {152, 155};
int tree_152[2] = {153, 154};
int tree_156[2] = {157, 178};
int tree_157[2] = {158, 163};
int tree_158[2] = {159, 160};
int tree_160[2] = {161, 162};
int tree_163[2] = {164, 167};
int tree_164[2] = {165, 166};
int tree_167[2] = {168, 175};
int tree_168[2] = {169, 170};
int tree_170[2] = {171, 174};
int tree_171[2] = {172, 173};
int tree_175[2] = {176, 177};
int tree_178[2] = {179, 182};
int tree_179[2] = {180, 181};

float *classProb1[LEN_TREE];
float classProb1_8[2] = {0.0, 1.0};
float classProb1_9[2] = {0.8, 0.2};
float classProb1_10[2] = {1.0, 0.0};
float classProb1_13[2] = {0.0, 1.0};
float classProb1_14[2] = {1.0, 0.0};
float classProb1_16[2] = {0.030303030303030304, 0.9696969696969697};
float classProb1_18[2] = {1.0, 0.0};
float classProb1_19[2] = {0.0, 1.0};
float classProb1_22[2] = {0.0, 1.0};
float classProb1_24[2] = {1.0, 0.0};
float classProb1_25[2] = {0.0, 1.0};
float classProb1_26[2] = {0.019230769230769232, 0.9807692307692307};
float classProb1_27[2] = {0.875, 0.125};
float classProb1_28[2] = {1.0, 0.0};
float classProb1_33[2] = {0.1111111111111111, 0.8888888888888888};
float classProb1_34[2] = {1.0, 0.0};
float classProb1_38[2] = {1.0, 0.0};
float classProb1_39[2] = {0.3333333333333333, 0.6666666666666666};
float classProb1_40[2] = {0.0, 1.0};
float classProb1_41[2] = {0.9911764705882353, 0.008823529411764706};
float classProb1_45[2] = {0.0, 1.0};
float classProb1_47[2] = {1.0, 0.0};
float classProb1_48[2] = {0.0, 1.0};
float classProb1_49[2] = {1.0, 0.0};
float classProb1_52[2] = {0.0, 1.0};
float classProb1_53[2] = {1.0, 0.0};
float classProb1_54[2] = {0.0, 1.0};
float classProb1_57[2] = {1.0, 0.0};
float classProb1_58[2] = {0.0, 1.0};
float classProb1_62[2] = {1.0, 0.0};
float classProb1_64[2] = {0.0, 1.0};
float classProb1_65[2] = {1.0, 0.0};
float classProb1_68[2] = {0.0, 1.0};
float classProb1_69[2] = {1.0, 0.0};
float classProb1_70[2] = {0.9285714285714286, 0.07142857142857142};
float classProb1_74[2] = {0.995945945945946, 0.004054054054054054};
float classProb1_77[2] = {0.0, 1.0};
float classProb1_80[2] = {0.0, 1.0};
float classProb1_82[2] = {0.0, 1.0};
float classProb1_84[2] = {0.3333333333333333, 0.6666666666666666};
float classProb1_85[2] = {1.0, 0.0};
float classProb1_86[2] = {1.0, 0.0};
float classProb1_88[2] = {0.9901960784313726, 0.00980392156862745};
float classProb1_91[2] = {0.875, 0.125};
float classProb1_92[2] = {0.0, 1.0};
float classProb1_93[2] = {1.0, 0.0};
float classProb1_96[2] = {1.0, 0.0};
float classProb1_97[2] = {0.0, 1.0};
float classProb1_98[2] = {0.9990644004366132, 0.0009355995633868704};
float classProb1_101[2] = {1.0, 0.0};
float classProb1_103[2] = {0.0, 1.0};
float classProb1_105[2] = {0.0, 1.0};
float classProb1_108[2] = {1.0, 0.0};
float classProb1_110[2] = {0.0, 1.0};
float classProb1_111[2] = {0.8, 0.2};
float classProb1_112[2] = {0.0, 1.0};
float classProb1_115[2] = {0.9583333333333334, 0.041666666666666664};
float classProb1_116[2] = {0.0, 1.0};
float classProb1_117[2] = {0.9979296066252588, 0.002070393374741201};
float classProb1_121[2] = {0.0024875621890547263, 0.9975124378109452};
float classProb1_124[2] = {0.0, 1.0};
float classProb1_126[2] = {0.0, 1.0};
float classProb1_127[2] = {0.8888888888888888, 0.1111111111111111};
float classProb1_129[2] = {0.0, 1.0};
float classProb1_131[2] = {1.0, 0.0};
float classProb1_133[2] = {0.07142857142857142, 0.9285714285714286};
float classProb1_134[2] = {1.0, 0.0};
float classProb1_139[2] = {1.0, 0.0};
float classProb1_141[2] = {0.0, 1.0};
float classProb1_142[2] = {1.0, 0.0};
float classProb1_143[2] = {0.1111111111111111, 0.8888888888888888};
float classProb1_144[2] = {0.0, 1.0};
float classProb1_147[2] = {0.0, 1.0};
float classProb1_149[2] = {0.0, 1.0};
float classProb1_150[2] = {1.0, 0.0};
float classProb1_153[2] = {0.95, 0.05};
float classProb1_154[2] = {0.0, 1.0};
float classProb1_155[2] = {1.0, 0.0};
float classProb1_159[2] = {0.057692307692307696, 0.9423076923076923};
float classProb1_161[2] = {0.0, 1.0};
float classProb1_162[2] = {1.0, 0.0};
float classProb1_165[2] = {1.0, 0.0};
float classProb1_166[2] = {0.0, 1.0};
float classProb1_169[2] = {0.0024544179523141654, 0.9975455820476858};
float classProb1_172[2] = {0.04054054054054054, 0.9594594594594594};
float classProb1_173[2] = {1.0, 0.0};
float classProb1_174[2] = {0.0, 1.0};
float classProb1_176[2] = {0.8, 0.2};
float classProb1_177[2] = {0.0, 1.0};
float classProb1_180[2] = {0.05263157894736842, 0.9473684210526315};
float classProb1_181[2] = {1.0, 0.0};
float classProb1_182[2] = {0.875, 0.125};


float getProbs(int i, int classIndex, float weight){
	if (m_attIndex[i] == -1){
		return weight * classProb1[i][classIndex]);
	}
	int treeIndex = (instance[m_attIndex[i]] <= m_splitPoint[i] ? 0 : 1);
	return getProbs(tree[i][treeIndex], classIndex, weight);
}

/* Function classify description:
 * Instance array must be initializated, with appropriated attributes, before calling this function
 * Output number 0 means that the instance was classified as f
 * Output number 1 means that the instance was classified as m
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
	tree[1] = tree_1;
	tree[2] = tree_2;
	tree[3] = tree_3;
	tree[4] = tree_4;
	tree[5] = tree_5;
	tree[6] = tree_6;
	tree[7] = tree_7;
	tree[11] = tree_11;
	tree[12] = tree_12;
	tree[15] = tree_15;
	tree[17] = tree_17;
	tree[20] = tree_20;
	tree[21] = tree_21;
	tree[23] = tree_23;
	tree[29] = tree_29;
	tree[30] = tree_30;
	tree[31] = tree_31;
	tree[32] = tree_32;
	tree[35] = tree_35;
	tree[36] = tree_36;
	tree[37] = tree_37;
	tree[42] = tree_42;
	tree[43] = tree_43;
	tree[44] = tree_44;
	tree[46] = tree_46;
	tree[50] = tree_50;
	tree[51] = tree_51;
	tree[55] = tree_55;
	tree[56] = tree_56;
	tree[59] = tree_59;
	tree[60] = tree_60;
	tree[61] = tree_61;
	tree[63] = tree_63;
	tree[66] = tree_66;
	tree[67] = tree_67;
	tree[71] = tree_71;
	tree[72] = tree_72;
	tree[73] = tree_73;
	tree[75] = tree_75;
	tree[76] = tree_76;
	tree[78] = tree_78;
	tree[79] = tree_79;
	tree[81] = tree_81;
	tree[83] = tree_83;
	tree[87] = tree_87;
	tree[89] = tree_89;
	tree[90] = tree_90;
	tree[94] = tree_94;
	tree[95] = tree_95;
	tree[99] = tree_99;
	tree[100] = tree_100;
	tree[102] = tree_102;
	tree[104] = tree_104;
	tree[106] = tree_106;
	tree[107] = tree_107;
	tree[109] = tree_109;
	tree[113] = tree_113;
	tree[114] = tree_114;
	tree[118] = tree_118;
	tree[119] = tree_119;
	tree[120] = tree_120;
	tree[122] = tree_122;
	tree[123] = tree_123;
	tree[125] = tree_125;
	tree[128] = tree_128;
	tree[130] = tree_130;
	tree[132] = tree_132;
	tree[135] = tree_135;
	tree[136] = tree_136;
	tree[137] = tree_137;
	tree[138] = tree_138;
	tree[140] = tree_140;
	tree[145] = tree_145;
	tree[146] = tree_146;
	tree[148] = tree_148;
	tree[151] = tree_151;
	tree[152] = tree_152;
	tree[156] = tree_156;
	tree[157] = tree_157;
	tree[158] = tree_158;
	tree[160] = tree_160;
	tree[163] = tree_163;
	tree[164] = tree_164;
	tree[167] = tree_167;
	tree[168] = tree_168;
	tree[170] = tree_170;
	tree[171] = tree_171;
	tree[175] = tree_175;
	tree[178] = tree_178;
	tree[179] = tree_179;

	classProb1[8] = classProb1_8;
	classProb1[9] = classProb1_9;
	classProb1[10] = classProb1_10;
	classProb1[13] = classProb1_13;
	classProb1[14] = classProb1_14;
	classProb1[16] = classProb1_16;
	classProb1[18] = classProb1_18;
	classProb1[19] = classProb1_19;
	classProb1[22] = classProb1_22;
	classProb1[24] = classProb1_24;
	classProb1[25] = classProb1_25;
	classProb1[26] = classProb1_26;
	classProb1[27] = classProb1_27;
	classProb1[28] = classProb1_28;
	classProb1[33] = classProb1_33;
	classProb1[34] = classProb1_34;
	classProb1[38] = classProb1_38;
	classProb1[39] = classProb1_39;
	classProb1[40] = classProb1_40;
	classProb1[41] = classProb1_41;
	classProb1[45] = classProb1_45;
	classProb1[47] = classProb1_47;
	classProb1[48] = classProb1_48;
	classProb1[49] = classProb1_49;
	classProb1[52] = classProb1_52;
	classProb1[53] = classProb1_53;
	classProb1[54] = classProb1_54;
	classProb1[57] = classProb1_57;
	classProb1[58] = classProb1_58;
	classProb1[62] = classProb1_62;
	classProb1[64] = classProb1_64;
	classProb1[65] = classProb1_65;
	classProb1[68] = classProb1_68;
	classProb1[69] = classProb1_69;
	classProb1[70] = classProb1_70;
	classProb1[74] = classProb1_74;
	classProb1[77] = classProb1_77;
	classProb1[80] = classProb1_80;
	classProb1[82] = classProb1_82;
	classProb1[84] = classProb1_84;
	classProb1[85] = classProb1_85;
	classProb1[86] = classProb1_86;
	classProb1[88] = classProb1_88;
	classProb1[91] = classProb1_91;
	classProb1[92] = classProb1_92;
	classProb1[93] = classProb1_93;
	classProb1[96] = classProb1_96;
	classProb1[97] = classProb1_97;
	classProb1[98] = classProb1_98;
	classProb1[101] = classProb1_101;
	classProb1[103] = classProb1_103;
	classProb1[105] = classProb1_105;
	classProb1[108] = classProb1_108;
	classProb1[110] = classProb1_110;
	classProb1[111] = classProb1_111;
	classProb1[112] = classProb1_112;
	classProb1[115] = classProb1_115;
	classProb1[116] = classProb1_116;
	classProb1[117] = classProb1_117;
	classProb1[121] = classProb1_121;
	classProb1[124] = classProb1_124;
	classProb1[126] = classProb1_126;
	classProb1[127] = classProb1_127;
	classProb1[129] = classProb1_129;
	classProb1[131] = classProb1_131;
	classProb1[133] = classProb1_133;
	classProb1[134] = classProb1_134;
	classProb1[139] = classProb1_139;
	classProb1[141] = classProb1_141;
	classProb1[142] = classProb1_142;
	classProb1[143] = classProb1_143;
	classProb1[144] = classProb1_144;
	classProb1[147] = classProb1_147;
	classProb1[149] = classProb1_149;
	classProb1[150] = classProb1_150;
	classProb1[153] = classProb1_153;
	classProb1[154] = classProb1_154;
	classProb1[155] = classProb1_155;
	classProb1[159] = classProb1_159;
	classProb1[161] = classProb1_161;
	classProb1[162] = classProb1_162;
	classProb1[165] = classProb1_165;
	classProb1[166] = classProb1_166;
	classProb1[169] = classProb1_169;
	classProb1[172] = classProb1_172;
	classProb1[173] = classProb1_173;
	classProb1[174] = classProb1_174;
	classProb1[176] = classProb1_176;
	classProb1[177] = classProb1_177;
	classProb1[180] = classProb1_180;
	classProb1[181] = classProb1_181;
	classProb1[182] = classProb1_182;
}
