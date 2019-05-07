
#include <Arduino.h>

#define TOTAL_BITS 32
#define FIXED_FBITS 10
#define SIGNED
#define OVERFLOW_DETECT
#include "FixedNum.h"

#define INPUT_SIZE 42
#define NUM_CLASSES 2
#define SELECTED_ATT_SIZE 42
#define NUM_PREDICTORS 42
#define CLASS_INDEX 42

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
const FixedNum m_Par[43][1] = {{(FixedNum)0xfffe8551}, {(FixedNum)0xffffffef}, {(FixedNum)0x00000473}, {(FixedNum)0x00000060}, {(FixedNum)0xffffe0cd}, {(FixedNum)0xfffffa11}, {(FixedNum)0x00000a1c}, {(FixedNum)0x00000001}, {(FixedNum)0xffffffff}, {(FixedNum)0x00000000}, {(FixedNum)0x00000000}, {(FixedNum)0x00000000}, {(FixedNum)0x00000000}, {(FixedNum)0x00000000}, {(FixedNum)0x00012ab4}, {(FixedNum)0xffffff99}, {(FixedNum)0xffffe139}, {(FixedNum)0x0000071a}, {(FixedNum)0xffffe5fd}, {(FixedNum)0xfffff41f}, {(FixedNum)0xffffefa9}, {(FixedNum)0x00000314}, {(FixedNum)0x00004019}, {(FixedNum)0x00001ae3}, {(FixedNum)0x00001d02}, {(FixedNum)0x00001ce5}, {(FixedNum)0x000029ff}, {(FixedNum)0x00001d7a}, {(FixedNum)0x00000ac1}, {(FixedNum)0x000000b3}, {(FixedNum)0xfffff8ec}, {(FixedNum)0xffffd24c}, {(FixedNum)0xfffff701}, {(FixedNum)0xffffebaa}, {(FixedNum)0x000001c6}, {(FixedNum)0xffffdf26}, {(FixedNum)0x00000aca}, {(FixedNum)0xffffdb55}, {(FixedNum)0x00001e15}, {(FixedNum)0xffffb63d}, {(FixedNum)0xffffe8b4}, {(FixedNum)0xffffffec}, {(FixedNum)0xfffffbdd}};
const int m_SelectedAttributes[43] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42};

/* Function classify description:
 * Instance array must be initializated, with appropriated attributes, before calling this function
 * Output number 0 means that the instance was classified as f
 * Output number 1 means that the instance was classified as m
 */
int classify(){
	FixedNum prob[NUM_CLASSES];
	FixedNum newInstance[NUM_PREDICTORS+1];
	newInstance[0] = (FixedNum)0x00000400;
	for (int i = 1; i <= SELECTED_ATT_SIZE; i++){
		if (m_SelectedAttributes[i] <= CLASS_INDEX) {
			newInstance[i] = instance[m_SelectedAttributes[i-1]];
		}
		else {
			newInstance[i] = instance[m_SelectedAttributes[i]];
		}
	}
	FixedNum v[NUM_CLASSES] = {0};
	for (int i = 0; i < NUM_CLASSES-1; i++) {
		for (int j = 0; j <= NUM_PREDICTORS; j++) {
			v[i] = fxp_sum(v[i], fxp_mul(m_Par[j][i], newInstance[j]));
		}
	}
	v[NUM_CLASSES-1] = 0;
	for (int i = 0; i < NUM_CLASSES; i++) {
		FixedNum acc = 0;
		for (int j = 0; j < NUM_CLASSES-1; j++) {
			acc = fxp_sum(acc, fxp_exp(fxp_diff(v[j], v[i])));
		}
		prob[i] = fxp_div((FixedNum)0x00000400, fxp_sum(acc, fxp_exp(-v[i])));
	}
	int indexMax = 0;
	for (int i = 1; i < NUM_CLASSES; i++) {
		if (prob[i] > prob[indexMax]) {
			indexMax = i;
		}
	}
	return indexMax;
}
