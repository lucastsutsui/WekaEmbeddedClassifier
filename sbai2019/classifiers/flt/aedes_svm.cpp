
#include <Arduino.h>

#define INPUT_SIZE 42
#define NUM_CLASSES 2
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
float instance[INPUT_SIZE+1];
const float minArray[43] = {0.0, 23.0, 108.08823529412, 0.016228436257423, 0.76990904477717, 0.011609977324263, 41.763137658047, 36.312262831307, 35.535848505381, 33.949083230208, 33.538316794915, 34.263696955237, 198.30654758152, 1.0529191581058, 120.31599850115, 0.0042287296363186, 0.0048167355306122, 0.0095126612931275, 0.0074987251379808, 0.006478173498837, 0.0047133745217075, 0.0062615138880925, 0.0060794688713726, 0.0032017864472942, 0.0067155115846878, 0.0057857136940463, 0.0063214891751098, 0.003868980755703, 0.0042517365354591, 0.0066426214897244, 0.0066001450992083, 0.0050128478260213, 0.0064554740721815, 0.0070317270986318, 0.0040342130082114, 0.0051086206575201, 0.0038297104922911, 0.0041894096927192, 0.0038328130210591, 0.0056288103908139, 0.005568002467985, 1.0, NAN};
const float maxArray[43] = {23.0, 34.9, 1225.0, 1.1161659946053, 7.4450008027823, 1.4396371882086, 4653.2829695573, 4861.7877636431, 7875.5487276526, 7802.3722509926, 7879.5422786952, 7840.1421028381, 3042.5206659202, 1.1203880025231, 1361.9494091449, 2.7784514947017, 3.384025994406, 3.6427001061487, 3.6157235336744, 4.1775378332137, 3.7939841090088, 3.1994059961583, 4.1618969342466, 2.8922757216813, 4.3036966129119, 4.9923016970694, 4.5272601422768, 4.3279116702475, 3.830832521897, 3.6930477983058, 3.5975043517975, 3.4015147422985, 3.4911205583037, 2.8668653010719, 2.7961631534471, 2.6748117200339, 2.6038009140372, 3.3807864168709, 3.0676942686009, 2.9045919336556, 2.4199920902231, 6.0, 0.0};


const float **m_sparseWeights[2];

const float *tmp0_sparseWeights1[1];
const float tmp1_sparseWeights1_0[43] = {42, 0.1616433127245948, -3.388075516551295, 5.922297714232017, 0.41420566386979035, 1.1882314125208213, -0.8079312692802129, -0.5153098638208755, 0.5986758296848352, -0.07778311840539343, -0.18405829858738285, -0.2869035908717382, -0.1239905166291159, -0.3578117241036092, -0.3704968800635281, 5.995075622124923, 1.6268002923091684, 0.5157266855881361, 2.0979450439808605, 0.06799306543822974, -1.384244442417773, 0.1611497162004581, -0.7396918912900706, -1.798280661195391, -1.3271328408875478, -2.618121869886302, -3.2328864283736602, -3.1999156360704974, -2.009398500535183, -0.4009388974552937, 0.4414422788484118, 0.9604343872522196, 2.0581708556698044, 2.5367954980481864, 1.9583007880106482, 1.5252628053917692, -0.03606594976254011, 0.8406573674753306, -1.0375814676613127, 0.38903002309941426, 0.033776786811445324, -1.1477838793606032, 0.2426753300495914};

const int **m_sparseIndices[2];

const int *tmp0_sparseIndices1[1];
const int tmp1_sparseIndices1_0[42] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

const float *m_b[2];
const float tmp_m_b1[1] = {4.557927823551324};

float SVMOutput(int i, int j){
	float result = 0.0;
	for (int p1 = 0; p1 < m_sparseWeights[i][j][0]; p1++){
		int p2 = m_sparseIndices[i][j][p1];
		if (p2 != CLASS_INDEX){
			result += instance[p2] * m_sparseWeights[i][j][p1+1];
		}
	}
	result -= m_b[i][j];
	return result;
}

/* Function classify description:
 * Instance array must be initializated, with appropriated attributes, before calling this function
 * Output number 0 means that the instance was classified as f
 * Output number 1 means that the instance was classified as m
 */
int classify(){
	for (int i = 0; i <= INPUT_SIZE; i++){
		if (maxArray[i] == minArray[i] || minArray[i] == NAN){
			instance[i] = 0;
		}
		else{
			instance[i] = (instance[i] - minArray[i]) / (maxArray[i] - minArray[i]);
		}
	}
	int result[NUM_CLASSES] = {0};
	for (int i = 1; i < NUM_CLASSES; i++){
		for (int j = 0; j < i; j++){
			float output = SVMOutput(i, j);
			if (output > 0){
				result[i]++;
			}
			else{
				result[j]++;
			}
		}
	}
	int indMax = 0;
	for (int i = 1; i < NUM_CLASSES; i++){
		if (result[i] > result[indMax]){
			indMax = i;
		}
	}
	return indMax;
}

void initConnections(){

	m_sparseWeights[0] = NULL;

	tmp0_sparseWeights1[0] = tmp1_sparseWeights1_0;
	m_sparseWeights[1] = tmp0_sparseWeights1;


	m_sparseIndices[0] = NULL;

	tmp0_sparseIndices1[0] = tmp1_sparseIndices1_0;
	m_sparseIndices[1] = tmp0_sparseIndices1;


	m_b[0] = NULL;
	m_b[1] = tmp_m_b1;
}
