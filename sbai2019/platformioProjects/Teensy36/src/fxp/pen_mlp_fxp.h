//
// #include <Arduino.h>
// #define TOTAL_BITS 32
// #define FIXED_FBITS 10
// #define SIGNED
// #include "FixedNum.h"
//
//
// #define INPUT_SIZE 8
// #define CLASS_INDEX 8
// #define OUTPUT_SIZE 10
// #define NUMBER_OF_NEURONS 37
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
//
// const int m_outputs[OUTPUT_SIZE] = {27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
//
// const FixedNum m_attributeBases[INPUT_SIZE] = {(FixedNum)0x0000c800, (FixedNum)0x0000c800, (FixedNum)0x0000c800, (FixedNum)0x0000c800, (FixedNum)0x0000c800, (FixedNum)0x0000c800, (FixedNum)0x0000c800, (FixedNum)0x0000c800};
// const FixedNum m_attributeRanges[INPUT_SIZE] = {(FixedNum)0x0000c800, (FixedNum)0x0000c800, (FixedNum)0x0000c800, (FixedNum)0x0000c800, (FixedNum)0x0000c800, (FixedNum)0x0000c800, (FixedNum)0x0000c800, (FixedNum)0x0000c800};
//
// const FixedNum *m_weights[NUMBER_OF_NEURONS];
// const int *m_connections[NUMBER_OF_NEURONS];
//
// const int tmp_connections0[1] = {0};
//
// const int tmp_connections1[1] = {0};
//
// const int tmp_connections2[1] = {0};
//
// const int tmp_connections3[1] = {0};
//
// const int tmp_connections4[1] = {0};
//
// const int tmp_connections5[1] = {0};
//
// const int tmp_connections6[1] = {0};
//
// const int tmp_connections7[1] = {0};
//
// const FixedNum tmp_weights8[9] = {(FixedNum)0xfffffd63, (FixedNum)0xffffcee3, (FixedNum)0x00000740, (FixedNum)0x00002343, (FixedNum)0x0000117a, (FixedNum)0xffffe905, (FixedNum)0x00002305, (FixedNum)0xffffa9fe, (FixedNum)0x000022df};
// const int tmp_connections8[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const FixedNum tmp_weights9[9] = {(FixedNum)0xfffffa7a, (FixedNum)0xffffdf4a, (FixedNum)0x000019d3, (FixedNum)0x0000242c, (FixedNum)0x000015d0, (FixedNum)0x00002865, (FixedNum)0xffffa323, (FixedNum)0xffffeb2a, (FixedNum)0x0000435f};
// const int tmp_connections9[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const FixedNum tmp_weights10[9] = {(FixedNum)0xfffffbdc, (FixedNum)0x0000017a, (FixedNum)0x000021d9, (FixedNum)0xffffb82c, (FixedNum)0x000018f9, (FixedNum)0x00000630, (FixedNum)0xfffff469, (FixedNum)0x000004b5, (FixedNum)0xffffed29};
// const int tmp_connections10[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const FixedNum tmp_weights11[9] = {(FixedNum)0x0000134f, (FixedNum)0xffffd2b4, (FixedNum)0x00003895, (FixedNum)0xffffd42e, (FixedNum)0xfffff4db, (FixedNum)0x00003355, (FixedNum)0x00000116, (FixedNum)0xffffd7f8, (FixedNum)0xfffff8b2};
// const int tmp_connections11[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const FixedNum tmp_weights12[9] = {(FixedNum)0x000021a2, (FixedNum)0xfffff5c5, (FixedNum)0x000037fb, (FixedNum)0xffffb03a, (FixedNum)0x00000848, (FixedNum)0x00000988, (FixedNum)0xffffd68a, (FixedNum)0xffffcac4, (FixedNum)0x000034ed};
// const int tmp_connections12[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const FixedNum tmp_weights13[9] = {(FixedNum)0xfffff6b6, (FixedNum)0x00002d29, (FixedNum)0xffffdb91, (FixedNum)0xfffff71d, (FixedNum)0xffffddef, (FixedNum)0x00001ed1, (FixedNum)0xfffff98f, (FixedNum)0xffffcaba, (FixedNum)0x0000298a};
// const int tmp_connections13[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const FixedNum tmp_weights14[9] = {(FixedNum)0xfffffd08, (FixedNum)0x00000058, (FixedNum)0x000003ed, (FixedNum)0x0000020a, (FixedNum)0xfffff36a, (FixedNum)0xffffe52d, (FixedNum)0x0000135c, (FixedNum)0xffffe388, (FixedNum)0x000000a5};
// const int tmp_connections14[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const FixedNum tmp_weights15[9] = {(FixedNum)0x00000e23, (FixedNum)0x000017db, (FixedNum)0x00002940, (FixedNum)0x00000306, (FixedNum)0x00002cf1, (FixedNum)0xfffffa6e, (FixedNum)0xffffde80, (FixedNum)0x000046b8, (FixedNum)0xffffe2ce};
// const int tmp_connections15[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const FixedNum tmp_weights16[9] = {(FixedNum)0xfffff91f, (FixedNum)0x00001b1b, (FixedNum)0x00000193, (FixedNum)0x00000b4a, (FixedNum)0xffffee7f, (FixedNum)0xfffff89c, (FixedNum)0x0000316d, (FixedNum)0xffffdbfd, (FixedNum)0x00000285};
// const int tmp_connections16[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const FixedNum tmp_weights17[10] = {(FixedNum)0xffffc0db, (FixedNum)0x00000fd8, (FixedNum)0x00001f76, (FixedNum)0xfffff313, (FixedNum)0x0000190a, (FixedNum)0xfffff00b, (FixedNum)0x000011f0, (FixedNum)0xfffffb48, (FixedNum)0x0000084c, (FixedNum)0x0000051e};
// const int tmp_connections17[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const FixedNum tmp_weights18[10] = {(FixedNum)0xfffff1de, (FixedNum)0x00001ddb, (FixedNum)0xffffe37b, (FixedNum)0x000036a4, (FixedNum)0xffffe23d, (FixedNum)0xffffd529, (FixedNum)0x000015d0, (FixedNum)0xffffa88e, (FixedNum)0xffffd3bd, (FixedNum)0x0000054a};
// const int tmp_connections18[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const FixedNum tmp_weights19[10] = {(FixedNum)0xffffd01e, (FixedNum)0x00002f07, (FixedNum)0xffffdc0b, (FixedNum)0xffffe5d9, (FixedNum)0x00000344, (FixedNum)0xfffffca5, (FixedNum)0xffffe0e5, (FixedNum)0xffffd505, (FixedNum)0x00000121, (FixedNum)0x00002379};
// const int tmp_connections19[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const FixedNum tmp_weights20[10] = {(FixedNum)0xffffc46a, (FixedNum)0x00001313, (FixedNum)0x00001348, (FixedNum)0xffffdaf6, (FixedNum)0xffffe173, (FixedNum)0x00002abe, (FixedNum)0xffffeb00, (FixedNum)0xfffff2d3, (FixedNum)0x000005f4, (FixedNum)0xffffe830};
// const int tmp_connections20[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const FixedNum tmp_weights21[10] = {(FixedNum)0xffffd014, (FixedNum)0x000018f9, (FixedNum)0x00000763, (FixedNum)0x00000171, (FixedNum)0xffffe654, (FixedNum)0xfffff30b, (FixedNum)0x00001b28, (FixedNum)0x0000132e, (FixedNum)0xfffff2a3, (FixedNum)0xfffff308};
// const int tmp_connections21[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const FixedNum tmp_weights22[10] = {(FixedNum)0xffffd905, (FixedNum)0xffffc9a0, (FixedNum)0xffffbed6, (FixedNum)0xffffc084, (FixedNum)0x000029fb, (FixedNum)0x00006246, (FixedNum)0x000006c3, (FixedNum)0xfffff440, (FixedNum)0xffffeebb, (FixedNum)0xffffdd33};
// const int tmp_connections22[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const FixedNum tmp_weights23[10] = {(FixedNum)0xffffda69, (FixedNum)0x00000a8f, (FixedNum)0xffffff6d, (FixedNum)0xfffff9f8, (FixedNum)0x00001683, (FixedNum)0x00000891, (FixedNum)0xfffff007, (FixedNum)0x0000061e, (FixedNum)0xfffff8a7, (FixedNum)0xffffef8f};
// const int tmp_connections23[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const FixedNum tmp_weights24[10] = {(FixedNum)0xffffc8c4, (FixedNum)0xffffd343, (FixedNum)0xffffd41d, (FixedNum)0x00004679, (FixedNum)0xffffd954, (FixedNum)0xffffdca0, (FixedNum)0x00000554, (FixedNum)0x0000400e, (FixedNum)0xffffe250, (FixedNum)0xfffffdce};
// const int tmp_connections24[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const FixedNum tmp_weights25[10] = {(FixedNum)0xffffd1fe, (FixedNum)0xffffd1d4, (FixedNum)0xfffff421, (FixedNum)0xfffff802, (FixedNum)0x00000615, (FixedNum)0x00000c32, (FixedNum)0xffffebb2, (FixedNum)0xffffe355, (FixedNum)0x00001222, (FixedNum)0x00002d52};
// const int tmp_connections25[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const FixedNum tmp_weights26[10] = {(FixedNum)0xfffffdb4, (FixedNum)0xffff8d6f, (FixedNum)0x00004dd3, (FixedNum)0xffffea57, (FixedNum)0xfffffb2c, (FixedNum)0xffffd940, (FixedNum)0x0000046f, (FixedNum)0x00000da0, (FixedNum)0x00001f1f, (FixedNum)0xffffdf1f};
// const int tmp_connections26[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const FixedNum tmp_weights27[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
// const int tmp_connections27[2] = {1, 17};
//
// const FixedNum tmp_weights28[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
// const int tmp_connections28[2] = {1, 18};
//
// const FixedNum tmp_weights29[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
// const int tmp_connections29[2] = {1, 19};
//
// const FixedNum tmp_weights30[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
// const int tmp_connections30[2] = {1, 20};
//
// const FixedNum tmp_weights31[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
// const int tmp_connections31[2] = {1, 21};
//
// const FixedNum tmp_weights32[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
// const int tmp_connections32[2] = {1, 22};
//
// const FixedNum tmp_weights33[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
// const int tmp_connections33[2] = {1, 23};
//
// const FixedNum tmp_weights34[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
// const int tmp_connections34[2] = {1, 24};
//
// const FixedNum tmp_weights35[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
// const int tmp_connections35[2] = {1, 25};
//
// const FixedNum tmp_weights36[2] = {(FixedNum)0x00000000, (FixedNum)0x00000400};
// const int tmp_connections36[2] = {1, 26};
//
// const bool sigmoids[NUMBER_OF_NEURONS] = {false, false, false, false, false, false, false, false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, false, false};
//
// FixedNum m_value[NUMBER_OF_NEURONS];
//
// /* Before every classification, all elements in m_calculated array need to be set to false */
// bool m_calculated[NUMBER_OF_NEURONS];
//
// /* Function calculateOutput description:
//  * Returns the output value from a neuron
//  */
// inline void calculateOutput(){
// 	for (int i = 0; i < INPUT_SIZE; i++){
// 		m_value[i] = instance[i];
// 	}
//
// 	for (int i = INPUT_SIZE; i < NUMBER_OF_NEURONS; i++){
// 		FixedNum value = m_weights[i][0];
// 		for (int j = 0; j < m_connections[i][0]; j++){
// 			value = fxp_sum(value, fxp_mul(m_weights[i][j+1], m_value[m_connections[i][j+1]]));
// 		}
// 		if (sigmoids[i]){
// 			if (value < (FixedNum)0xffff4c00)
// 				value = (FixedNum)0;
// 			else if (value > (FixedNum)0x0000b400)
// 				value = (FixedNum)0x00000400;
// 			else{
// 				value = fxp_div((FixedNum)0x00000400, fxp_sum((FixedNum)0x00000400, fxp_exp(-value)));
// 			}
// 		}
// 		m_value[i] = value;
// 	}
// }
//
// /* Function classify description:
//  * Instance array must be initializated, with appropriated attributes, before calling this function
//  * Output number 0 means that the instance was classified as '1'
//  * Output number 1 means that the instance was classified as '0'
//  * Output number 2 means that the instance was classified as '3'
//  * Output number 3 means that the instance was classified as '2'
//  * Output number 4 means that the instance was classified as '5'
//  * Output number 5 means that the instance was classified as '4'
//  * Output number 6 means that the instance was classified as '7'
//  * Output number 7 means that the instance was classified as '6'
//  * Output number 8 means that the instance was classified as '9'
//  * Output number 9 means that the instance was classified as '8'
//  */
// int classify(){
// 	FixedNum theArray[OUTPUT_SIZE];
// 	for (int i = 0; i < INPUT_SIZE; i++){
// 		if (m_attributeRanges[i] != (FixedNum)0){
// 			instance[i] = fxp_div(fxp_diff(instance[i], m_attributeBases[i]), m_attributeRanges[i]);
// 		}
// 		else{
// 			instance[i] = fxp_diff(instance[i], m_attributeBases[i]);
// 		}
// 	}
// 	calculateOutput();
// 	for (int i = 0; i < OUTPUT_SIZE; i++){
// 		theArray[i] = m_value[m_outputs[i]];
// 	}
// 	FixedNum maxValue = -1;
// 	int indexMax = -1;
// 	for (int i = 0; i < OUTPUT_SIZE; i++){
// 		if (theArray[i] > maxValue){
// 			maxValue = theArray[i];
// 			indexMax = i;
// 		}
// 	}
// 	return map_output[indexMax];
// }
//
// void initConnections(){
// 	m_connections[0] = tmp_connections0;
// 	m_connections[1] = tmp_connections1;
// 	m_connections[2] = tmp_connections2;
// 	m_connections[3] = tmp_connections3;
// 	m_connections[4] = tmp_connections4;
// 	m_connections[5] = tmp_connections5;
// 	m_connections[6] = tmp_connections6;
// 	m_connections[7] = tmp_connections7;
// 	m_weights[8] = tmp_weights8;
// 	m_connections[8] = tmp_connections8;
// 	m_weights[9] = tmp_weights9;
// 	m_connections[9] = tmp_connections9;
// 	m_weights[10] = tmp_weights10;
// 	m_connections[10] = tmp_connections10;
// 	m_weights[11] = tmp_weights11;
// 	m_connections[11] = tmp_connections11;
// 	m_weights[12] = tmp_weights12;
// 	m_connections[12] = tmp_connections12;
// 	m_weights[13] = tmp_weights13;
// 	m_connections[13] = tmp_connections13;
// 	m_weights[14] = tmp_weights14;
// 	m_connections[14] = tmp_connections14;
// 	m_weights[15] = tmp_weights15;
// 	m_connections[15] = tmp_connections15;
// 	m_weights[16] = tmp_weights16;
// 	m_connections[16] = tmp_connections16;
// 	m_weights[17] = tmp_weights17;
// 	m_connections[17] = tmp_connections17;
// 	m_weights[18] = tmp_weights18;
// 	m_connections[18] = tmp_connections18;
// 	m_weights[19] = tmp_weights19;
// 	m_connections[19] = tmp_connections19;
// 	m_weights[20] = tmp_weights20;
// 	m_connections[20] = tmp_connections20;
// 	m_weights[21] = tmp_weights21;
// 	m_connections[21] = tmp_connections21;
// 	m_weights[22] = tmp_weights22;
// 	m_connections[22] = tmp_connections22;
// 	m_weights[23] = tmp_weights23;
// 	m_connections[23] = tmp_connections23;
// 	m_weights[24] = tmp_weights24;
// 	m_connections[24] = tmp_connections24;
// 	m_weights[25] = tmp_weights25;
// 	m_connections[25] = tmp_connections25;
// 	m_weights[26] = tmp_weights26;
// 	m_connections[26] = tmp_connections26;
// 	m_weights[27] = tmp_weights27;
// 	m_connections[27] = tmp_connections27;
// 	m_weights[28] = tmp_weights28;
// 	m_connections[28] = tmp_connections28;
// 	m_weights[29] = tmp_weights29;
// 	m_connections[29] = tmp_connections29;
// 	m_weights[30] = tmp_weights30;
// 	m_connections[30] = tmp_connections30;
// 	m_weights[31] = tmp_weights31;
// 	m_connections[31] = tmp_connections31;
// 	m_weights[32] = tmp_weights32;
// 	m_connections[32] = tmp_connections32;
// 	m_weights[33] = tmp_weights33;
// 	m_connections[33] = tmp_connections33;
// 	m_weights[34] = tmp_weights34;
// 	m_connections[34] = tmp_connections34;
// 	m_weights[35] = tmp_weights35;
// 	m_connections[35] = tmp_connections35;
// 	m_weights[36] = tmp_weights36;
// 	m_connections[36] = tmp_connections36;
// }
