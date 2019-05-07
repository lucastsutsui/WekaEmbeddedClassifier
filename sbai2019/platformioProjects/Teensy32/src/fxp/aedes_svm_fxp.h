//
// #include <Arduino.h>
// #define TOTAL_BITS 32
// #define FIXED_FBITS 10
// #define SIGNED
// #include "FixedNum.h"
//
// #define INPUT_SIZE 42
// #define NUM_CLASSES 2
// #define CLASS_INDEX 42
//
// /* Instance array must be global
//  * Attributes MUST be sorted in instance array in the following order:
//  * hour
//  * temperature
//  * wbf
//  * complexity
//  * complexity_znorm
//  * time_length
//  * peaks_freq_1
//  * peaks_freq_2
//  * peaks_freq_3
//  * peaks_freq_4
//  * peaks_freq_5
//  * peaks_freq_6
//  * inharmonicity
//  * rho
//  * rho_wbf
//  * eh_1
//  * eh_2
//  * eh_3
//  * eh_4
//  * eh_5
//  * eh_6
//  * eh_7
//  * eh_8
//  * eh_9
//  * eh_10
//  * eh_11
//  * eh_12
//  * eh_13
//  * eh_14
//  * eh_15
//  * eh_16
//  * eh_17
//  * eh_18
//  * eh_19
//  * eh_20
//  * eh_21
//  * eh_22
//  * eh_23
//  * eh_24
//  * eh_25
//  * eh_26
//  * temp_range
//  */
// FixedNum instance[INPUT_SIZE+1];
// const FixedNum minArray[43] = {(FixedNum)0x00000000, (FixedNum)0x00005c00, (FixedNum)0x0001b05a, (FixedNum)0x00000011, (FixedNum)0x00000314, (FixedNum)0x0000000c, (FixedNum)0x0000a70d, (FixedNum)0x00009140, (FixedNum)0x00008e25, (FixedNum)0x000087cc, (FixedNum)0x00008627, (FixedNum)0x0000890e, (FixedNum)0x0003193a, (FixedNum)0x00000436, (FixedNum)0x0001e144, (FixedNum)0x00000004, (FixedNum)0x00000005, (FixedNum)0x0000000a, (FixedNum)0x00000008, (FixedNum)0x00000007, (FixedNum)0x00000005, (FixedNum)0x00000006, (FixedNum)0x00000006, (FixedNum)0x00000003, (FixedNum)0x00000007, (FixedNum)0x00000006, (FixedNum)0x00000006, (FixedNum)0x00000004, (FixedNum)0x00000004, (FixedNum)0x00000007, (FixedNum)0x00000007, (FixedNum)0x00000005, (FixedNum)0x00000007, (FixedNum)0x00000007, (FixedNum)0x00000004, (FixedNum)0x00000005, (FixedNum)0x00000004, (FixedNum)0x00000004, (FixedNum)0x00000004, (FixedNum)0x00000006, (FixedNum)0x00000006, (FixedNum)0x00000400, INF_POS};
// const FixedNum maxArray[43] = {(FixedNum)0x00005c00, (FixedNum)0x00008b9a, (FixedNum)0x00132400, (FixedNum)0x00000477, (FixedNum)0x00001dc8, (FixedNum)0x000005c2, (FixedNum)0x0048b522, (FixedNum)0x004bf727, (FixedNum)0x007b0e32, (FixedNum)0x0079e97d, (FixedNum)0x007b1e2b, (FixedNum)0x007a8092, (FixedNum)0x002f8a15, (FixedNum)0x0000047b, (FixedNum)0x001547cc, (FixedNum)0x00000b1d, (FixedNum)0x00000d89, (FixedNum)0x00000e92, (FixedNum)0x00000e77, (FixedNum)0x000010b6, (FixedNum)0x00000f2d, (FixedNum)0x00000ccc, (FixedNum)0x000010a6, (FixedNum)0x00000b92, (FixedNum)0x00001137, (FixedNum)0x000013f8, (FixedNum)0x0000121c, (FixedNum)0x00001150, (FixedNum)0x00000f53, (FixedNum)0x00000ec6, (FixedNum)0x00000e64, (FixedNum)0x00000d9b, (FixedNum)0x00000df7, (FixedNum)0x00000b78, (FixedNum)0x00000b2f, (FixedNum)0x00000ab3, (FixedNum)0x00000a6a, (FixedNum)0x00000d86, (FixedNum)0x00000c45, (FixedNum)0x00000b9e, (FixedNum)0x000009ae, (FixedNum)0x00001800, (FixedNum)0x00000000};
//
//
// const FixedNum **m_sparseWeights[2];
//
// const FixedNum *tmp0_sparseWeights1[1];
// const FixedNum tmp1_sparseWeights1_0[43] = {(FixedNum)(0x0000a800 >> FIXED_FBITS), (FixedNum)0x000000a6, (FixedNum)0xfffff273, (FixedNum)0x000017b0, (FixedNum)0x000001a8, (FixedNum)0x000004c1, (FixedNum)0xfffffcc5, (FixedNum)0xfffffdf0, (FixedNum)0x00000265, (FixedNum)0xffffffb0, (FixedNum)0xffffff44, (FixedNum)0xfffffeda, (FixedNum)0xffffff81, (FixedNum)0xfffffe92, (FixedNum)0xfffffe85, (FixedNum)0x000017fb, (FixedNum)0x00000682, (FixedNum)0x00000210, (FixedNum)0x00000864, (FixedNum)0x00000046, (FixedNum)0xfffffa77, (FixedNum)0x000000a5, (FixedNum)0xfffffd0b, (FixedNum)0xfffff8cf, (FixedNum)0xfffffab1, (FixedNum)0xfffff587, (FixedNum)0xfffff312, (FixedNum)0xfffff333, (FixedNum)0xfffff7f6, (FixedNum)0xfffffe65, (FixedNum)0x000001c4, (FixedNum)0x000003d7, (FixedNum)0x0000083c, (FixedNum)0x00000a26, (FixedNum)0x000007d5, (FixedNum)0x0000061a, (FixedNum)0xffffffdb, (FixedNum)0x0000035d, (FixedNum)0xfffffbda, (FixedNum)0x0000018e, (FixedNum)0x00000023, (FixedNum)0xfffffb69, (FixedNum)0x000000f8};
//
// const int **m_sparseIndices[2];
//
// const int *tmp0_sparseIndices1[1];
// const int tmp1_sparseIndices1_0[42] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};
//
// const FixedNum *m_b[2];
// const FixedNum tmp_m_b1[1] = {(FixedNum)0x0000123b};
//
// FixedNum SVMOutput(int i, int j){
// 	FixedNum result = (FixedNum)0;
// 	for (int p1 = 0; p1 < m_sparseWeights[i][j][0]; p1++){
// 		int p2 = m_sparseIndices[i][j][p1];
// 		if (p2 != CLASS_INDEX){
// 			result = fxp_sum(result, fxp_mul(instance[p2], m_sparseWeights[i][j][p1+1]));
// 		}
// 	}
// 	result = fxp_diff(result, m_b[i][j]);
// 	return result;
// }
//
// /* Function classify description:
//  * Instance array must be initializated, with appropriated attributes, before calling this function
//  * Output number 0 means that the instance was classified as f
//  * Output number 1 means that the instance was classified as m
//  */
// int classify(){
// 	for (int i = 0; i <= INPUT_SIZE; i++){
// 		if (maxArray[i] == minArray[i] || minArray[i] == INF_POS){
// 			instance[i] = (FixedNum)0;
// 		}
// 		else{
// 			instance[i] = fxp_div(fxp_diff(instance[i], minArray[i]), fxp_diff(maxArray[i], minArray[i]));
// 		}
// 	}
// 	int result[NUM_CLASSES] = {0};
// 	for (int i = 1; i < NUM_CLASSES; i++){
// 		for (int j = 0; j < i; j++){
// 			FixedNum output = SVMOutput(i, j);
// 			if (output > 0){
// 				result[i]++;
// 			}
// 			else{
// 				result[j]++;
// 			}
// 		}
// 	}
// 	int indMax = 0;
// 	for (int i = 1; i < NUM_CLASSES; i++){
// 		if (result[i] > result[indMax]){
// 			indMax = i;
// 		}
// 	}
// 	return indMax;
// }
//
// void initConnections(){
//
// 	m_sparseWeights[0] = NULL;
//
// 	tmp0_sparseWeights1[0] = tmp1_sparseWeights1_0;
// 	m_sparseWeights[1] = tmp0_sparseWeights1;
//
//
// 	m_sparseIndices[0] = NULL;
//
// 	tmp0_sparseIndices1[0] = tmp1_sparseIndices1_0;
// 	m_sparseIndices[1] = tmp0_sparseIndices1;
//
//
// 	m_b[0] = NULL;
// 	m_b[1] = tmp_m_b1;
// }
