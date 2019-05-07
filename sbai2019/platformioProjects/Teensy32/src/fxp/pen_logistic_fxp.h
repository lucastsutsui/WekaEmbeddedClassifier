//
// #include <Arduino.h>
//
// #define TOTAL_BITS 32
// #define FIXED_FBITS 10
// #define SIGNED
// #define OVERFLOW_DETECT
// #include "FixedNum.h"
//
// #define INPUT_SIZE 8
// #define NUM_CLASSES 10
// #define SELECTED_ATT_SIZE 8
// #define NUM_PREDICTORS 8
// #define CLASS_INDEX 8
//
// static int map_output[10] = {1, 0, 3, 2, 5, 4, 7, 6, 9, 8};
//
// /* Instance array must be global
//  * Attributes MUST be sorted in instance array in the following order:
//  * channel_0_0
//  * channel_0_1
//  * channel_0_2
//  * channel_0_3
//  * channel_0_4
//  * channel_0_5
//  * channel_0_6
//  * channel_0_7
//  */
// FixedNum instance[INPUT_SIZE+1];
// const FixedNum m_Par[9][9] = {{(FixedNum)0xfffff7c1, (FixedNum)0x00000ba6, (FixedNum)0xffffc1b1, (FixedNum)0xffffd055, (FixedNum)0x00001667, (FixedNum)0xfffff4ec, (FixedNum)0xfffff851, (FixedNum)0x000017c1, (FixedNum)0xffffd79d}, {(FixedNum)0xffffffbe, (FixedNum)0xfffffff3, (FixedNum)0xffffffce, (FixedNum)0xffffffb2, (FixedNum)0xfffffff9, (FixedNum)0xffffffeb, (FixedNum)0xffffff73, (FixedNum)0x00000025, (FixedNum)0x00000023}, {(FixedNum)0x00000038, (FixedNum)0xffffffb6, (FixedNum)0xfffffffe, (FixedNum)0x00000033, (FixedNum)0xfffffff5, (FixedNum)0xfffffffc, (FixedNum)0x00000049, (FixedNum)0xffffffe5, (FixedNum)0xfffffff9}, {(FixedNum)0xfffffff1, (FixedNum)0xffffffde, (FixedNum)0x00000061, (FixedNum)0x0000000b, (FixedNum)0xfffffffe, (FixedNum)0xffffffab, (FixedNum)0xfffffff9, (FixedNum)0xffffffac, (FixedNum)0x00000014}, {(FixedNum)0x0000002f, (FixedNum)0xffffffe6, (FixedNum)0x00000011, (FixedNum)0x00000051, (FixedNum)0xffffffe8, (FixedNum)0x00000007, (FixedNum)0x00000030, (FixedNum)0xffffffe5, (FixedNum)0x0000000e}, {(FixedNum)0x00000007, (FixedNum)0x00000004, (FixedNum)0x00000039, (FixedNum)0xffffffba, (FixedNum)0xffffffcd, (FixedNum)0x00000001, (FixedNum)0xffffffed, (FixedNum)0xffffff6e, (FixedNum)0x00000007}, {(FixedNum)0x00000018, (FixedNum)0x0000004b, (FixedNum)0x00000082, (FixedNum)0xfffffffb, (FixedNum)0x0000004e, (FixedNum)0x0000007e, (FixedNum)0x0000001e, (FixedNum)0x00000092, (FixedNum)0x00000073}, {(FixedNum)0xffffffc4, (FixedNum)0xffffffca, (FixedNum)0xffffffac, (FixedNum)0x0000000f, (FixedNum)0xffffff82, (FixedNum)0xffffff91, (FixedNum)0xffffffb5, (FixedNum)0xffffff87, (FixedNum)0xffffffd6}, {(FixedNum)0x0000001d, (FixedNum)0xfffffff9, (FixedNum)0xffffffe9, (FixedNum)0x00000064, (FixedNum)0x0000001a, (FixedNum)0x0000004e, (FixedNum)0x0000002a, (FixedNum)0xffffffe1, (FixedNum)0x0000001f}};
// const int m_SelectedAttributes[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
//
// /* Function classify description:
//  * Instance array must be initializated, with appropriated attributes, before calling this function
//  * Output number 0 means that the instance was classified as 1
//  * Output number 1 means that the instance was classified as 0
//  * Output number 2 means that the instance was classified as 3
//  * Output number 3 means that the instance was classified as 2
//  * Output number 4 means that the instance was classified as 5
//  * Output number 5 means that the instance was classified as 4
//  * Output number 6 means that the instance was classified as 7
//  * Output number 7 means that the instance was classified as 6
//  * Output number 8 means that the instance was classified as 9
//  * Output number 9 means that the instance was classified as 8
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
// 	return map_output[indexMax];
// }
