//
// #include <Arduino.h>
// #include <math.h>
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
// float instance[INPUT_SIZE+1];
//
// const int m_outputs[OUTPUT_SIZE] = {27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
//
// const float m_attributeBases[INPUT_SIZE] = {50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0};
// const float m_attributeRanges[INPUT_SIZE] = {50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0};
//
// const float *m_weights[NUMBER_OF_NEURONS];
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
// const float tmp_weights8[9] = {-0.653499737528, -12.2780380103, 1.81231539189, 8.8158545182, 4.369447418, -5.74513825834, 8.75475331427, -21.501885938, 8.71755411188};
// const int tmp_connections8[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const float tmp_weights9[9] = {-1.38042040539, -8.17734001017, 6.45599012702, 9.04305799998, 5.45269640076, 10.0984785851, -23.2153659068, -5.20894593715, 16.842525667};
// const int tmp_connections9[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const float tmp_weights10[9] = {-1.03491423962, 0.369118487223, 8.46147433369, -17.9567918142, 6.24321219436, 1.54656236452, -2.89738115446, 1.17645437267, -4.70988441689};
// const int tmp_connections10[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const float tmp_weights11[9] = {4.82738758535, -11.3237891639, 14.1454320609, -10.9546902257, -2.78630788814, 12.833122073, 0.271600628748, -10.0073516003, -1.8261253133};
// const int tmp_connections11[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const float tmp_weights12[9] = {8.40848984888, -2.55725880036, 13.9948652998, -19.9434964204, 2.07079769114, 2.3825362871, -10.3655915933, -13.3090550307, 13.2310551536};
// const int tmp_connections12[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const float tmp_weights13[9] = {-2.32221341943, 11.2899165939, -9.10868638977, -2.22130938257, -8.51655832294, 7.70386391731, -1.61043305692, -13.3183271976, 10.3850068974};
// const int tmp_connections13[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const float tmp_weights14[9] = {-0.741751059336, 0.0860325852415, 0.981593765254, 0.509339782511, -3.1463263504, -6.7059531572, 4.83969887481, -7.11763322781, 0.1613112898};
// const int tmp_connections14[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const float tmp_weights15[9] = {3.53465559197, 5.96434718439, 10.312719244, 0.755638806967, 11.2351849209, -1.39250364922, -8.37480974479, 17.6793037452, -7.29864934748};
// const int tmp_connections15[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const float tmp_weights16[9] = {-1.71967274998, 6.77623086184, 0.393749511628, 2.82183053883, -4.37599759226, -1.84731892625, 12.3568941615, -9.00308588983, 0.629514027306};
// const int tmp_connections16[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//
// const float tmp_weights17[10] = {-15.7856450222, 3.96082386815, 7.86527012693, -3.23159150318, 6.26004264162, -3.98959165797, 4.48436815008, -1.17986268627, 2.07390337082, 1.27905192038};
// const int tmp_connections17[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const float tmp_weights18[10] = {-3.53362334486, 7.46351717561, -7.12994176255, 13.6601634308, -7.44060902403, -10.7100670665, 5.45313254639, -21.8616260441, -11.0652838525, 1.32239298881};
// const int tmp_connections18[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const float tmp_weights19[10] = {-11.9707031606, 11.7564944305, -8.98930689431, -6.53838089567, 0.816851641354, -0.838829716015, -7.77597993615, -10.7453907117, 0.281841375231, 8.8685224394};
// const int tmp_connections19[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const float tmp_weights20[10] = {-14.8965000054, 4.76814251818, 4.82032565491, -9.26006212085, -7.63795529257, 10.6858283186, -5.24970343855, -3.29434379527, 1.48873742144, -5.95286218559};
// const int tmp_connections20[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const float tmp_weights21[10] = {-11.9807198912, 6.24300397757, 1.84648783744, 0.360530865104, -6.41794299648, -3.23925932691, 6.78881500675, 4.79500395528, -3.3403375318, -3.24264626114};
// const int tmp_connections21[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const float tmp_weights22[10] = {-9.74493892787, -13.5936734172, -16.2909870502, -15.8709326709, 10.4950770229, 24.5686253972, 1.6905249245, -2.93769884145, -4.31700484359, -8.70016179539};
// const int tmp_connections22[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const float tmp_weights23[10] = {-9.39734940788, 2.63986036174, -0.143828308423, -1.50753564484, 5.62761379579, 2.14164994911, -3.99275663643, 1.52926911511, -1.83644014187, -4.11046113387};
// const int tmp_connections23[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const float tmp_weights24[10] = {-13.8089501323, -11.1845889291, -10.9717769754, 17.6184514907, -9.66798100645, -8.84409254489, 1.33163107508, 16.0139543011, -7.42194431445, -0.548536975383};
// const int tmp_connections24[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const float tmp_weights25[10] = {-11.5015858323, -11.5428443209, -2.96776142797, -1.99762095796, 1.52051657544, 3.04877100882, -5.0764433027, -7.16727847358, 4.53310721818, 11.3305169193};
// const int tmp_connections25[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const float tmp_weights26[10] = {-0.573830464935, -28.6418256804, 19.4565138023, -5.41525956015, -1.20658324532, -9.68756146927, 1.10877670697, 3.40613590971, 7.78029454379, -8.21979269356};
// const int tmp_connections26[10] = {9, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//
// const float tmp_weights27[2] = {0, 1};
// const int tmp_connections27[2] = {1, 17};
//
// const float tmp_weights28[2] = {0, 1};
// const int tmp_connections28[2] = {1, 18};
//
// const float tmp_weights29[2] = {0, 1};
// const int tmp_connections29[2] = {1, 19};
//
// const float tmp_weights30[2] = {0, 1};
// const int tmp_connections30[2] = {1, 20};
//
// const float tmp_weights31[2] = {0, 1};
// const int tmp_connections31[2] = {1, 21};
//
// const float tmp_weights32[2] = {0, 1};
// const int tmp_connections32[2] = {1, 22};
//
// const float tmp_weights33[2] = {0, 1};
// const int tmp_connections33[2] = {1, 23};
//
// const float tmp_weights34[2] = {0, 1};
// const int tmp_connections34[2] = {1, 24};
//
// const float tmp_weights35[2] = {0, 1};
// const int tmp_connections35[2] = {1, 25};
//
// const float tmp_weights36[2] = {0, 1};
// const int tmp_connections36[2] = {1, 26};
//
// const bool sigmoids[NUMBER_OF_NEURONS] = {false, false, false, false, false, false, false, false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, false, false};
//
// float m_value[NUMBER_OF_NEURONS];
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
// 		float value = m_weights[i][0];
// 		for (int j = 0; j < m_connections[i][0]; j++){
// 			value += m_weights[i][j+1] * m_value[m_connections[i][j+1]];
// 		}
// 		if (sigmoids[i]){
// 			if (value < -45.0)
// 				value = 0.0;
// 			else if (value > 45.0)
// 				value = 1.0;
// 			else{
// 				value = 1.0 / (1.0 + exp(-value));
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
// 	float theArray[OUTPUT_SIZE];
// 	for (int i = 0; i < INPUT_SIZE; i++){
// 		if (m_attributeRanges[i] != 0){
// 			instance[i] = (instance[i] - m_attributeBases[i]) / m_attributeRanges[i];
// 		}
// 		else{
// 			instance[i] = (instance[i] - m_attributeBases[i]);
// 		}
// 	}
// 	calculateOutput();
// 	for (int i = 0; i < OUTPUT_SIZE; i++){
// 		theArray[i] = m_value[m_outputs[i]];
// 	}
// 	float maxValue = -1.0;
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
