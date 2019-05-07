//
// #include <Arduino.h>
//
// #define M_ROOT 0
// #define NUM_CLASSES 4
// #define CLASS_INDEX 64
// #define LEN_TREE 171
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
// float instance[INPUT_SIZE+1];
//
// int m_attIndex[LEN_TREE] = {8, 8, 0, 59, 61, 54, -1, 5, -1, -1, -1, -1, 23, 0, -1, 11, -1, -1, -1, 0, 59, 26, 11, 6, 25, -1, 25, 17, -1, -1, -1, -1, 20, 2, -1, -1, 40, -1, 46, -1, -1, -1, -1, 30, 62, -1, 46, -1, 0, -1, -1, 11, 62, 60, 7, 20, -1, 7, 0, 28, -1, 8, -1, 20, -1, 44, -1, -1, -1, -1, 39, 23, -1, -1, -1, 60, -1, 55, -1, -1, 23, 20, -1, 61, -1, 5, -1, 26, -1, -1, -1, 61, 52, -1, 33, -1, 28, 1, -1, 53, -1, -1, -1, 26, -1, -1, 24, 34, 8, 0, -1, 11, 23, 13, -1, 28, -1, 62, 44, 45, 1, 8, -1, -1, -1, -1, 40, 20, -1, -1, -1, -1, 53, -1, 34, 57, -1, -1, -1, -1, 61, 25, 17, -1, 40, -1, 0, -1, -1, 33, -1, 31, -1, 59, -1, -1, 6, -1, -1, 0, 13, 23, -1, -1, -1, 44, -1, 0, -1, -1, -1};
//
// float m_splitPoint[LEN_TREE] = {0.1988099699, 0.137356295, 0.3548329473, 0.1208056088, 0.06857016, 0.028126882, -1, 0.5350263429, -1, -1, -1, -1, 0.7664003159, 0.4754585457, -1, 0.2301163362, -1, -1, -1, 0.5717871907, 0.2531087764, 0.1419426951, 0.1676551759, 0.6498820525, 0.0274509804, -1, 0.7803921569, 0.1847758123, -1, -1, -1, -1, 0.2965517241, 0.0923595583, -1, -1, 0.6875, -1, 0.0298507463, -1, -1, -1, -1, 0.4925012259, 0.1449874801, -1, 0.2388059701, -1, 0.8369683129, -1, -1, 0.1928688039, 0.1987626294, 0.1011154981, 0.5884773663, 0.5103448276, -1, 0.5843621399, 0.8697348541, 0.4019826248, -1, 0.1436884259, -1, 0.6413793103, -1, 0.3055555556, -1, -1, -1, -1, 0.0973680225, 0.8869205413, -1, -1, -1, 0.2612142788, -1, 0.0782671604, -1, -1, 0.8831538592, 0.2896551724, -1, 0.0845377967, -1, 0.2809215845, -1, 0.1391622374, -1, -1, -1, 0.0838238377, 0.0128123613, -1, 0.2678571429, -1, 0.50051412, 0.0395693571, -1, 0.0497703713, -1, -1, -1, 0.0514393319, -1, -1, 0.6069391681, 0.2075474691, 0.2401292874, 0.6326978947, -1, 0.2340293105, 0.812258213, 0.15948666, -1, 0.3109013272, -1, 0.208739361, 0.4444444444, 0.4353858588, 0.0446918013, 0.2043481837, -1, -1, -1, -1, 0.53125, 0.4344827586, -1, -1, -1, -1, 0.0508750011, -1, 0.13917134, 0.0419310365, -1, -1, -1, -1, 0.2935774187, 0.0039215686, 0.146343628, -1, 0.625, -1, 0.6656262381, -1, -1, 0.7857142857, -1, 0.6586230457, -1, 0.0756224927, -1, -1, 0.5802368181, -1, -1, 0.7246334967, 0.4353783939, 0.6465453441, -1, -1, -1, 0.6388888889, -1, 0.7975729527, -1, -1, -1};
//
// const int *tree[LEN_TREE];
// int tree_0[2] = {1, 106};
// int tree_1[2] = {2, 19};
// int tree_2[2] = {3, 12};
// int tree_3[2] = {4, 11};
// int tree_4[2] = {5, 10};
// int tree_5[2] = {6, 7};
// int tree_7[2] = {8, 9};
// int tree_12[2] = {13, 18};
// int tree_13[2] = {14, 15};
// int tree_15[2] = {16, 17};
// int tree_19[2] = {20, 43};
// int tree_20[2] = {21, 42};
// int tree_21[2] = {22, 41};
// int tree_22[2] = {23, 32};
// int tree_23[2] = {24, 31};
// int tree_24[2] = {25, 26};
// int tree_26[2] = {27, 30};
// int tree_27[2] = {28, 29};
// int tree_32[2] = {33, 36};
// int tree_33[2] = {34, 35};
// int tree_36[2] = {37, 38};
// int tree_38[2] = {39, 40};
// int tree_43[2] = {44, 51};
// int tree_44[2] = {45, 46};
// int tree_46[2] = {47, 48};
// int tree_48[2] = {49, 50};
// int tree_51[2] = {52, 91};
// int tree_52[2] = {53, 80};
// int tree_53[2] = {54, 75};
// int tree_54[2] = {55, 70};
// int tree_55[2] = {56, 57};
// int tree_57[2] = {58, 69};
// int tree_58[2] = {59, 68};
// int tree_59[2] = {60, 61};
// int tree_61[2] = {62, 63};
// int tree_63[2] = {64, 65};
// int tree_65[2] = {66, 67};
// int tree_70[2] = {71, 74};
// int tree_71[2] = {72, 73};
// int tree_75[2] = {76, 77};
// int tree_77[2] = {78, 79};
// int tree_80[2] = {81, 90};
// int tree_81[2] = {82, 83};
// int tree_83[2] = {84, 85};
// int tree_85[2] = {86, 87};
// int tree_87[2] = {88, 89};
// int tree_91[2] = {92, 103};
// int tree_92[2] = {93, 94};
// int tree_94[2] = {95, 96};
// int tree_96[2] = {97, 102};
// int tree_97[2] = {98, 99};
// int tree_99[2] = {100, 101};
// int tree_103[2] = {104, 105};
// int tree_106[2] = {107, 170};
// int tree_107[2] = {108, 159};
// int tree_108[2] = {109, 140};
// int tree_109[2] = {110, 111};
// int tree_111[2] = {112, 139};
// int tree_112[2] = {113, 132};
// int tree_113[2] = {114, 115};
// int tree_115[2] = {116, 117};
// int tree_117[2] = {118, 131};
// int tree_118[2] = {119, 126};
// int tree_119[2] = {120, 125};
// int tree_120[2] = {121, 124};
// int tree_121[2] = {122, 123};
// int tree_126[2] = {127, 130};
// int tree_127[2] = {128, 129};
// int tree_132[2] = {133, 134};
// int tree_134[2] = {135, 138};
// int tree_135[2] = {136, 137};
// int tree_140[2] = {141, 156};
// int tree_141[2] = {142, 149};
// int tree_142[2] = {143, 144};
// int tree_144[2] = {145, 146};
// int tree_146[2] = {147, 148};
// int tree_149[2] = {150, 151};
// int tree_151[2] = {152, 153};
// int tree_153[2] = {154, 155};
// int tree_156[2] = {157, 158};
// int tree_159[2] = {160, 165};
// int tree_160[2] = {161, 164};
// int tree_161[2] = {162, 163};
// int tree_165[2] = {166, 167};
// int tree_167[2] = {168, 169};
//
// float *classProb1[LEN_TREE];
// float classProb1_6[4] = {0.0, 0.012195121951219513, 0.9878048780487805, 0.0};
// float classProb1_8[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_9[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_10[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_11[4] = {0.0, 0.0, 0.0, 1.0};
// float classProb1_14[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_16[4] = {0.0, 0.017543859649122806, 0.9824561403508771, 0.0};
// float classProb1_17[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_18[4] = {0.0, 0.004098360655737705, 0.9959016393442623, 0.0};
// float classProb1_25[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_28[4] = {0.0, 0.9, 0.1, 0.0};
// float classProb1_29[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_30[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_31[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_34[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_35[4] = {0.0, 0.75, 0.25, 0.0};
// float classProb1_37[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_39[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_40[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_41[4] = {0.6666666666666666, 0.3333333333333333, 0.0, 0.0};
// float classProb1_42[4] = {0.0, 0.0, 0.0, 1.0};
// float classProb1_45[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_47[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_49[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_50[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_56[4] = {0.0, 0.11486486486486487, 0.8851351351351351, 0.0};
// float classProb1_60[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_62[4] = {0.0, 0.125, 0.875, 0.0};
// float classProb1_64[4] = {0.0, 0.9375, 0.0625, 0.0};
// float classProb1_66[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_67[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_68[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_69[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_72[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_73[4] = {0.0, 0.8, 0.2, 0.0};
// float classProb1_74[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_76[4] = {0.0, 0.0228310502283105, 0.9771689497716894, 0.0};
// float classProb1_78[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_79[4] = {0.0, 0.8333333333333334, 0.16666666666666666, 0.0};
// float classProb1_82[4] = {0.0, 0.08333333333333333, 0.9166666666666666, 0.0};
// float classProb1_84[4] = {0.0, 0.125, 0.875, 0.0};
// float classProb1_86[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_88[4] = {0.0, 0.9411764705882353, 0.058823529411764705, 0.0};
// float classProb1_89[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_90[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_93[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_95[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_98[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_100[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_101[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_102[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_104[4] = {0.0, 0.3333333333333333, 0.6666666666666666, 0.0};
// float classProb1_105[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_110[4] = {0.022222222222222223, 0.9111111111111111, 0.044444444444444446, 0.022222222222222223};
// float classProb1_114[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_116[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_122[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_123[4] = {0.0, 0.875, 0.125, 0.0};
// float classProb1_124[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_125[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_128[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_129[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_130[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_131[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_133[4] = {0.0, 0.27058823529411763, 0.7294117647058823, 0.0};
// float classProb1_136[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_137[4] = {0.0, 0.9047619047619048, 0.09523809523809523, 0.0};
// float classProb1_138[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_139[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_143[4] = {1.0, 0.0, 0.0, 0.0};
// float classProb1_145[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_147[4] = {0.8, 0.2, 0.0, 0.0};
// float classProb1_148[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_150[4] = {0.012345679012345678, 0.9711934156378601, 0.01646090534979424, 0.0};
// float classProb1_152[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_154[4] = {0.0, 0.0, 1.0, 0.0};
// float classProb1_155[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_157[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_158[4] = {0.9090909090909091, 0.09090909090909091, 0.0, 0.0};
// float classProb1_162[4] = {0.8333333333333334, 0.16666666666666666, 0.0, 0.0};
// float classProb1_163[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_164[4] = {1.0, 0.0, 0.0, 0.0};
// float classProb1_166[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_168[4] = {0.0, 1.0, 0.0, 0.0};
// float classProb1_169[4] = {1.0, 0.0, 0.0, 0.0};
// float classProb1_170[4] = {1.0, 0.0, 0.0, 0.0};
//
//
// float getProbs(int i, int classIndex, float weight){
// 	if (m_attIndex[i] == -1){
// 		return (weight * classProb1[i][classIndex]);
// 	}
// 	int treeIndex = (instance[m_attIndex[i]] <= m_splitPoint[i] ? 0 : 1);
// 	return getProbs(tree[i][treeIndex], classIndex, weight);
// }
//
// /* Function classify description:
//  * Instance array must be initializated, with appropriated attributes, before calling this function
//  * Output number 0 means that the instance was classified as ruim
//  * Output number 1 means that the instance was classified as regular
//  * Output number 2 means that the instance was classified as bom
//  * Output number 3 means that the instance was classified as obstaculos
//  */
// int classify(){
// 	float doubles[NUM_CLASSES];
// 	for (int i = 0; i < NUM_CLASSES; i++){
// 		doubles[i] = getProbs(M_ROOT, i, 1);
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
// 	tree[4] = tree_4;
// 	tree[5] = tree_5;
// 	tree[7] = tree_7;
// 	tree[12] = tree_12;
// 	tree[13] = tree_13;
// 	tree[15] = tree_15;
// 	tree[19] = tree_19;
// 	tree[20] = tree_20;
// 	tree[21] = tree_21;
// 	tree[22] = tree_22;
// 	tree[23] = tree_23;
// 	tree[24] = tree_24;
// 	tree[26] = tree_26;
// 	tree[27] = tree_27;
// 	tree[32] = tree_32;
// 	tree[33] = tree_33;
// 	tree[36] = tree_36;
// 	tree[38] = tree_38;
// 	tree[43] = tree_43;
// 	tree[44] = tree_44;
// 	tree[46] = tree_46;
// 	tree[48] = tree_48;
// 	tree[51] = tree_51;
// 	tree[52] = tree_52;
// 	tree[53] = tree_53;
// 	tree[54] = tree_54;
// 	tree[55] = tree_55;
// 	tree[57] = tree_57;
// 	tree[58] = tree_58;
// 	tree[59] = tree_59;
// 	tree[61] = tree_61;
// 	tree[63] = tree_63;
// 	tree[65] = tree_65;
// 	tree[70] = tree_70;
// 	tree[71] = tree_71;
// 	tree[75] = tree_75;
// 	tree[77] = tree_77;
// 	tree[80] = tree_80;
// 	tree[81] = tree_81;
// 	tree[83] = tree_83;
// 	tree[85] = tree_85;
// 	tree[87] = tree_87;
// 	tree[91] = tree_91;
// 	tree[92] = tree_92;
// 	tree[94] = tree_94;
// 	tree[96] = tree_96;
// 	tree[97] = tree_97;
// 	tree[99] = tree_99;
// 	tree[103] = tree_103;
// 	tree[106] = tree_106;
// 	tree[107] = tree_107;
// 	tree[108] = tree_108;
// 	tree[109] = tree_109;
// 	tree[111] = tree_111;
// 	tree[112] = tree_112;
// 	tree[113] = tree_113;
// 	tree[115] = tree_115;
// 	tree[117] = tree_117;
// 	tree[118] = tree_118;
// 	tree[119] = tree_119;
// 	tree[120] = tree_120;
// 	tree[121] = tree_121;
// 	tree[126] = tree_126;
// 	tree[127] = tree_127;
// 	tree[132] = tree_132;
// 	tree[134] = tree_134;
// 	tree[135] = tree_135;
// 	tree[140] = tree_140;
// 	tree[141] = tree_141;
// 	tree[142] = tree_142;
// 	tree[144] = tree_144;
// 	tree[146] = tree_146;
// 	tree[149] = tree_149;
// 	tree[151] = tree_151;
// 	tree[153] = tree_153;
// 	tree[156] = tree_156;
// 	tree[159] = tree_159;
// 	tree[160] = tree_160;
// 	tree[161] = tree_161;
// 	tree[165] = tree_165;
// 	tree[167] = tree_167;
//
// 	classProb1[6] = classProb1_6;
// 	classProb1[8] = classProb1_8;
// 	classProb1[9] = classProb1_9;
// 	classProb1[10] = classProb1_10;
// 	classProb1[11] = classProb1_11;
// 	classProb1[14] = classProb1_14;
// 	classProb1[16] = classProb1_16;
// 	classProb1[17] = classProb1_17;
// 	classProb1[18] = classProb1_18;
// 	classProb1[25] = classProb1_25;
// 	classProb1[28] = classProb1_28;
// 	classProb1[29] = classProb1_29;
// 	classProb1[30] = classProb1_30;
// 	classProb1[31] = classProb1_31;
// 	classProb1[34] = classProb1_34;
// 	classProb1[35] = classProb1_35;
// 	classProb1[37] = classProb1_37;
// 	classProb1[39] = classProb1_39;
// 	classProb1[40] = classProb1_40;
// 	classProb1[41] = classProb1_41;
// 	classProb1[42] = classProb1_42;
// 	classProb1[45] = classProb1_45;
// 	classProb1[47] = classProb1_47;
// 	classProb1[49] = classProb1_49;
// 	classProb1[50] = classProb1_50;
// 	classProb1[56] = classProb1_56;
// 	classProb1[60] = classProb1_60;
// 	classProb1[62] = classProb1_62;
// 	classProb1[64] = classProb1_64;
// 	classProb1[66] = classProb1_66;
// 	classProb1[67] = classProb1_67;
// 	classProb1[68] = classProb1_68;
// 	classProb1[69] = classProb1_69;
// 	classProb1[72] = classProb1_72;
// 	classProb1[73] = classProb1_73;
// 	classProb1[74] = classProb1_74;
// 	classProb1[76] = classProb1_76;
// 	classProb1[78] = classProb1_78;
// 	classProb1[79] = classProb1_79;
// 	classProb1[82] = classProb1_82;
// 	classProb1[84] = classProb1_84;
// 	classProb1[86] = classProb1_86;
// 	classProb1[88] = classProb1_88;
// 	classProb1[89] = classProb1_89;
// 	classProb1[90] = classProb1_90;
// 	classProb1[93] = classProb1_93;
// 	classProb1[95] = classProb1_95;
// 	classProb1[98] = classProb1_98;
// 	classProb1[100] = classProb1_100;
// 	classProb1[101] = classProb1_101;
// 	classProb1[102] = classProb1_102;
// 	classProb1[104] = classProb1_104;
// 	classProb1[105] = classProb1_105;
// 	classProb1[110] = classProb1_110;
// 	classProb1[114] = classProb1_114;
// 	classProb1[116] = classProb1_116;
// 	classProb1[122] = classProb1_122;
// 	classProb1[123] = classProb1_123;
// 	classProb1[124] = classProb1_124;
// 	classProb1[125] = classProb1_125;
// 	classProb1[128] = classProb1_128;
// 	classProb1[129] = classProb1_129;
// 	classProb1[130] = classProb1_130;
// 	classProb1[131] = classProb1_131;
// 	classProb1[133] = classProb1_133;
// 	classProb1[136] = classProb1_136;
// 	classProb1[137] = classProb1_137;
// 	classProb1[138] = classProb1_138;
// 	classProb1[139] = classProb1_139;
// 	classProb1[143] = classProb1_143;
// 	classProb1[145] = classProb1_145;
// 	classProb1[147] = classProb1_147;
// 	classProb1[148] = classProb1_148;
// 	classProb1[150] = classProb1_150;
// 	classProb1[152] = classProb1_152;
// 	classProb1[154] = classProb1_154;
// 	classProb1[155] = classProb1_155;
// 	classProb1[157] = classProb1_157;
// 	classProb1[158] = classProb1_158;
// 	classProb1[162] = classProb1_162;
// 	classProb1[163] = classProb1_163;
// 	classProb1[164] = classProb1_164;
// 	classProb1[166] = classProb1_166;
// 	classProb1[168] = classProb1_168;
// 	classProb1[169] = classProb1_169;
// 	classProb1[170] = classProb1_170;
// }
