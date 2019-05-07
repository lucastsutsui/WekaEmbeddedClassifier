//
// #include <Arduino.h>
// #include <math.h>
//
// #define INPUT_SIZE 42
// #define NUM_CLASSES 2
// #define SELECTED_ATT_SIZE 42
// #define NUM_PREDICTORS 42
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
// float instance[INPUT_SIZE+1];
// const float m_Par[43][1] = {{-94.67075350650151}, {-0.016754422937290746}, {1.1127181207741481}, {0.09347223284340353}, {-7.799906185901545}, {-1.4835550231147134}, {2.527533869699127}, {0.0006929430963333084}, {-0.0005496983854681976}, {-6.501080942644589e-05}, {6.142528796137873e-05}, {0.00013803676130765384}, {8.775981333651874e-05}, {0.0004777699714412879}, {74.6753380268056}, {-0.10063383796230013}, {-7.694533894162529}, {1.775059861816044}, {-6.502668030142161}, {-2.9694116133450903}, {-4.085433691218777}, {0.7700170335960915}, {16.023933655490445}, {6.721576272267307}, {7.251503049961402}, {7.223800621311377}, {10.498734852889212}, {7.368900715923832}, {2.6889643506834813}, {0.17477090839154888}, {-1.76912799194201}, {-11.426110672398503}, {-2.2493144373141063}, {-5.0840562484393415}, {0.44355307684819495}, {-8.21287403166338}, {2.697510780588321}, {-9.166773839940362}, {7.520795933913288}, {-18.44078564010191}, {-5.824355544574433}, {-0.019955001644183883}, {-1.034597577460541}};
// const int m_SelectedAttributes[43] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42};
//
// /* Function classify description:
//  * Instance array must be initializated, with appropriated attributes, before calling this function
//  * Output number 0 means that the instance was classified as f
//  * Output number 1 means that the instance was classified as m
//  */
// int classify(){
// 	float prob[NUM_CLASSES];
// 	float newInstance[NUM_PREDICTORS+1];
// 	newInstance[0] = 1.0;
// 	for (int i = 1; i <= SELECTED_ATT_SIZE; i++){
// 		if (m_SelectedAttributes[i] <= CLASS_INDEX) {
// 			newInstance[i] = instance[m_SelectedAttributes[i-1]];
// 		}
// 		else {
// 			newInstance[i] = instance[m_SelectedAttributes[i]];
// 		}
// 	}
// 	float v[NUM_CLASSES] = {0};
// 	for (int i = 0; i < NUM_CLASSES-1; i++) {
// 		for (int j = 0; j <= NUM_PREDICTORS; j++) {
// 			v[i] += m_Par[j][i] * newInstance[j];
// 		}
// 	}
// 	v[NUM_CLASSES-1] = 0;
// 	for (int i = 0; i < NUM_CLASSES; i++) {
// 		float acc = 0.0;
// 		for (int j = 0; j < NUM_CLASSES-1; j++) {
// 			acc += exp(v[j]-v[i]);
// 		}
// 		prob[i] = 1.0 / (acc + exp(-v[i]));
// 	}
// 	int indexMax = 0;
// 	for (int i = 1; i < NUM_CLASSES; i++) {
// 		if (prob[i] > prob[indexMax]) {
// 			indexMax = i;
// 		}
// 	}
// 	return indexMax;
// }
