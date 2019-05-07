
#include <Arduino.h>

#define INPUT_SIZE 8
#define NUM_CLASSES 10
#define CLASS_INDEX 8

/* Instance array must be global
 * Attributes MUST be sorted in instance array in the following order:
 * channel_0_0
 * channel_0_1
 * channel_0_2
 * channel_0_3
 * channel_0_4
 * channel_0_5
 * channel_0_6
 * channel_0_7
 */
float instance[INPUT_SIZE+1];
const float minArray[9] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, NAN};
const float maxArray[9] = {100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 0.0};


const float **m_sparseWeights[10];

const float *tmp0_sparseWeights1[1];
const float tmp1_sparseWeights1_0[9] = {8, 1.5998011535406338, -1.45316702759407, -3.818835098038069, -0.5803866407712037, 1.7837665550031927, 1.0924773643658325, 1.1109404425991694, -2.70738074270097};

const float *tmp0_sparseWeights2[2];
const float tmp1_sparseWeights2_0[9] = {8, 0.7890295442391864, -0.022991015309104045, 1.7976919872693102, -1.6400653206583646, 0.4162687258359955, 3.5931593665964816, 3.0629106161152544, -4.4082326821776965};
const float tmp1_sparseWeights2_1[9] = {8, -1.4257644359079968, 2.4127968921350207, 4.153321931655163, -0.839401779880892, 0.3812334436235707, 2.4268235101552484, 1.5734494961306718, -0.7867475313400564};

const float *tmp0_sparseWeights3[3];
const float tmp1_sparseWeights3_0[9] = {8, 0.5056532702529606, -3.3561404688090435, 3.962195178244825, 4.11003356723893, -7.850656114521198, -0.05013182022557375, 1.5653849296004987, 2.1842143230170628};
const float tmp1_sparseWeights3_1[9] = {8, -1.6518609944519413, -0.26557653764586114, 1.3487617999320956, 0.45917265553469777, -0.8914766834674825, -1.1439558748794325, -0.8464900055463346, 2.77216431939554};
const float tmp1_sparseWeights3_2[9] = {8, 0.09030796111817235, 0.10990573152284401, -0.04744783233969482, 0.07790367942253909, -0.350995332786628, -1.0287834400910407, -1.2322095388778032, 2.4430610084983546};

const float *tmp0_sparseWeights4[4];
const float tmp1_sparseWeights4_0[9] = {8, 2.318726923098767, -3.001927008750855, 1.878876395873282, -2.4844786066403657, -4.641114190645043, 4.278145571557832, 0.055125386141555315, 0.0261075509614469};
const float tmp1_sparseWeights4_1[9] = {8, 0.471437758147211, 2.536505832897641, 1.1863652065926145, -1.655703061224912, -2.4949126467144866, -0.7915699445266198, -4.046254303287594, -0.033089780169468626};
const float tmp1_sparseWeights4_2[9] = {8, 2.361396991456352, 2.5624041643902613, -3.3527672596637483, -2.359061356634603, -4.051949851666232, -0.8509419935798438, -1.0251924906785908, 2.4675676736682295};
const float tmp1_sparseWeights4_3[9] = {8, 3.448204650361375, -4.91967609962327, 1.2939925237600138, -4.330535271475707, -1.5024888715686906, 2.3015270519743263, -7.100745819750876, -3.5592839440332993};

const float *tmp0_sparseWeights5[5];
const float tmp1_sparseWeights5_0[9] = {8, 2.1572336473010165, -0.7898734557888509, -5.060039123539122, 0.02128803457486217, 0.4338817217560578, 1.3974953005163764, 1.6023000508347984, -0.6891513583174906};
const float tmp1_sparseWeights5_1[9] = {8, -0.5811778812617773, 4.620152394542823, -4.156719169411405, 0.746899976535932, 3.0262601952319312, -1.108094689334611, -3.83515376075945, 6.175853962056493};
const float tmp1_sparseWeights5_2[9] = {8, 2.089952110344021, -1.358259328894629, -3.444527373324797, -0.13892026644693797, 0.03713472072937245, -0.63139418860376, -0.7596651739072293, 1.8088927285347127};
const float tmp1_sparseWeights5_3[9] = {8, 1.3025085927904319, -0.3769989002683673, -2.225957732472215, -0.6165398404250827, 1.4523591376215337, 2.1363472217575095, 0.6575639561287833, -2.0010158921562438};
const float tmp1_sparseWeights5_4[9] = {8, 0.1419393110833569, -1.6913252038965023, -2.264106990503573, 0.5677162995619152, 2.8526341116365277, 1.6458004263647985, 2.990717669895177, 2.168553614685265};

const float *tmp0_sparseWeights6[6];
const float tmp1_sparseWeights6_0[9] = {8, -3.0899583584067174, -1.699395035276316, 3.4767914076964326, 0.32108093738691496, -5.137071243504195, 1.6116710311635387, -1.1482073128058947, 1.5146141695215483};
const float tmp1_sparseWeights6_1[9] = {8, -3.068372459809029, 0.2672041372475612, 2.744299660466709, 3.787707167428262, -2.778273066280364, 0.8625142007695181, 1.3718224419882579, 2.9879022406843987};
const float tmp1_sparseWeights6_2[9] = {8, -1.2285420574498802, 0.5009820474051262, -2.3271517873123786, 1.3831885568526676, -1.2139871804019484, -2.7547237271510054, 0.22602861521783923, 2.2867885158286776};
const float tmp1_sparseWeights6_3[9] = {8, -5.476635509247937, 4.620939705214298, -0.9518890740628726, -3.625548956843515, 5.492341735721094, 1.087772565430563, -3.1739993019958335, -2.3964291600978536};
const float tmp1_sparseWeights6_4[9] = {8, -5.6691061401411735, 3.532338487791959, -0.02723325922883275, 3.8219129708048607, 3.030862095069065, -2.041967263671905, 2.3607041760578062, 0.8775114808941019};
const float tmp1_sparseWeights6_5[9] = {8, -2.7612915471377644, 0.35859486037096555, 3.9786277257060236, 0.5163562855715751, -0.5660794673519007, -0.699098753131921, -0.8638840597155201, 0.24119521254455561};

const float *tmp0_sparseWeights7[7];
const float tmp1_sparseWeights7_0[9] = {8, 1.9493601378127239, 1.0017332936752965, -1.8625420303674474, -1.8739599688783763, 0.17630754987253108, 1.4055882030304063, 3.149497406771134, -1.1193041370661465};
const float tmp1_sparseWeights7_1[9] = {8, 0.88936351228112, -1.1622695871192366, 1.620838398942216, -3.5642024383959328, -4.2912012984070875, 1.3481935096906432, -2.927711873501268, -3.4441640974738066};
const float tmp1_sparseWeights7_2[9] = {8, 2.3275723171366414, 0.03920712044430941, -2.7530785552440564, -1.3536906518246055, -1.441964507388511, -0.3746383087139184, -0.9353432544477015, 0.4323245990499131};
const float tmp1_sparseWeights7_3[9] = {8, 1.3078571513314314, -0.32022374791608077, -1.0197640463691229, -0.7200568244531775, 0.22557941790081132, 0.37023382709187475, 0.44233000705676107, -1.9898984339314065};
const float tmp1_sparseWeights7_4[9] = {8, 2.2338750639928326, -2.538834113368457, -1.5402852473736763, -0.1604220357490692, -4.071452478505044, 2.5804222358820144, 0.5354007956648859, -1.944171158923898};
const float tmp1_sparseWeights7_5[9] = {8, 0.6316134697660843, -1.5810856663555994, 0.18785780844111408, -1.6833395726726565, -3.7511033930986466, 1.0892061265583493, -0.11364386843787798, -4.774898528692882};
const float tmp1_sparseWeights7_6[9] = {8, 2.251232567529023, 0.14430304938604605, -1.664532492586691, -1.867599430758848, -0.3485119049806471, 0.36449303038189546, -0.5208845825948143, -1.0951517664460164};

const float *tmp0_sparseWeights8[8];
const float tmp1_sparseWeights8_0[9] = {8, 2.528282999928874, -0.33527332065793436, -0.18027574068089855, -1.2962877170038696, -0.9915817036085346, 4.473422203651582, 1.9023767753926646, -1.3985889855410047};
const float tmp1_sparseWeights8_1[9] = {8, 3.3371121218971136, 3.223717444376232, 4.094473544198994, 2.587913366469921, 0.7695002389487146, 4.5129071349104874, 0.8078195349404372, 0.7356457779412521};
const float tmp1_sparseWeights8_2[9] = {8, 5.654747248722339, -1.4230784827102718, -2.541794915145455, -3.0862048560339046, -1.157908583682802, -1.59832703783308, 2.6486128383774443, 3.6864778494162755};
const float tmp1_sparseWeights8_3[9] = {8, 0.779871606560478, 0.9117121615524924, 0.3008287026038145, 0.07169358744555007, 1.0049048920247419, 2.7442555447296453, 1.9560616405516724, -2.7773788220247777};
const float tmp1_sparseWeights8_4[9] = {8, 1.122159971791614, -1.3144547767654042, 1.0014402379690217, 1.872057362165215, 3.0682983788277007, 2.030188931805981, 5.8829023058293535, 1.8169630406286248};
const float tmp1_sparseWeights8_5[9] = {8, 1.2274409786152123, 1.8872621825869265, 3.6201409318390505, 1.7761580668162242, 0.32181926195287025, 1.8893170958941385, 3.219039518920026, -2.9949037179856677};
const float tmp1_sparseWeights8_6[9] = {8, 3.8826364901026307, -1.006516961160125, 1.0412347086755558, -2.8091541884622893, 0.44623999216852456, 2.138858710466125, -0.4501605027938796, 0.3812814982371598};
const float tmp1_sparseWeights8_7[9] = {8, -2.023293483820508, 1.5196202268641499, 2.4185372540415853, 3.441565502426446, 4.1631474458690585, -0.8464591972813168, 2.4299612192621987, 2.4845809629147926};

const float *tmp0_sparseWeights9[9];
const float tmp1_sparseWeights9_0[9] = {8, 3.0945733714043353, -0.4020619510103166, -1.937126687753988, -0.8449469467732365, -0.7893094811635369, 0.2948187546504516, 3.38332209323264, -1.638565422024606};
const float tmp1_sparseWeights9_1[9] = {8, -0.4807387756829855, 1.4144915499859607, 2.2877527535944724, -0.7151884206613683, -1.669533948969858, -3.844262387951032, 0.8663532543163244, 0.30827773504540873};
const float tmp1_sparseWeights9_2[9] = {8, 1.8040678517162645, 0.08092075914795056, -1.1001917285267437, -2.2548682848054415, -4.57501940590094, -2.5904780417295936, 0.9861047249196292, 1.1964161590086704};
const float tmp1_sparseWeights9_3[9] = {8, 3.1262063196489276, -0.14740179554449961, -3.1429052621651117, 0.057047639468719796, 1.1724483299029447, 0.2651106322445323, 0.7997393195186814, -5.229949735692185};
const float tmp1_sparseWeights9_4[9] = {8, 0.6728291159976898, 0.5875581525234627, -0.16147212908718492, 1.7329260036448584, 2.5537813424512747, -3.159834290681069, 7.1340979490186225, -0.43380262310870854};
const float tmp1_sparseWeights9_5[9] = {8, -0.47869435862495985, 1.8965711047445135, 3.3675257690102054, -0.30361577695585884, -0.7200041865250226, -5.713052509250976, 1.9786839919467487, -1.315406966437122};
const float tmp1_sparseWeights9_6[9] = {8, 5.064802984082017, -0.9360226209088425, -0.7673230379495503, -2.7972420822337796, -0.6341837637667129, -0.7567987247951716, 1.0033423119120317, -2.7519479394571644};
const float tmp1_sparseWeights9_7[9] = {8, -3.0995317851615103, -1.2720080265532085, 4.01681289798554, 2.2245202177721044, 1.272457039935003, -1.812481349955098, 1.2370623700643728, 3.113297500733568};
const float tmp1_sparseWeights9_8[9] = {8, -1.745858692503719, 0.012289099018069056, -0.7046875004400933, -0.32344900691336215, -1.434973274656229, -5.473286859963866, 1.5475124273469012, -1.7308678631269585};

const int **m_sparseIndices[10];

const int *tmp0_sparseIndices1[1];
const int tmp1_sparseIndices1_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices2[2];
const int tmp1_sparseIndices2_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices2_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices3[3];
const int tmp1_sparseIndices3_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices3_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices3_2[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices4[4];
const int tmp1_sparseIndices4_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices4_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices4_2[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices4_3[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices5[5];
const int tmp1_sparseIndices5_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices5_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices5_2[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices5_3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices5_4[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices6[6];
const int tmp1_sparseIndices6_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices6_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices6_2[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices6_3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices6_4[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices6_5[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices7[7];
const int tmp1_sparseIndices7_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices7_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices7_2[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices7_3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices7_4[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices7_5[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices7_6[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices8[8];
const int tmp1_sparseIndices8_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices8_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices8_2[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices8_3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices8_4[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices8_5[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices8_6[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices8_7[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const int *tmp0_sparseIndices9[9];
const int tmp1_sparseIndices9_0[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_2[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_3[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_4[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_5[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_6[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_7[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const int tmp1_sparseIndices9_8[8] = {0, 1, 2, 3, 4, 5, 6, 7};

const float *m_b[10];
const float tmp_m_b1[1] = {-0.2772746856075212};
const float tmp_m_b2[2] = {3.7525136718423546, 5.162199281383197};
const float tmp_m_b3[3] = {3.284724554241617, 0.8090699793937688, -0.04284526861813375};
const float tmp_m_b4[4] = {-1.2845454958857876, -3.3778067980868665, -4.7223984484080415, -8.460657105668574};
const float tmp_m_b5[5] = {0.3792472225116644, 2.0034403576152884, -2.0113190517108377, -0.482098178101861, 4.4546571481044985};
const float tmp_m_b6[6] = {0.005166056768424073, 3.7946799429879867, -2.853986390173163, -3.005394136347047, 4.641428666049057, 0.1561753222865886};
const float tmp_m_b7[7] = {2.364833496682879, -4.5581980387611, -2.590481241080357, -0.9110895794095848, -0.40292127081167806, -3.3854935869558656, -0.952875910655849};
const float tmp_m_b8[8] = {3.0165771998294444, 10.336901507927397, -2.8732452613885937, 1.6286796014001217, 7.955123986070407, 5.851563626709854, 1.1972596868822483, 4.2338829951305375};
const float tmp_m_b9[9] = {-0.1903227582278249, -2.594353984644616, -5.444109254633, -4.289320283939576, 4.501416125014073, -2.555666965422983, -3.0846823756872506, -0.08734106528838653, -5.734743165017502};

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
 * Output number 0 means that the instance was classified as 1
 * Output number 1 means that the instance was classified as 0
 * Output number 2 means that the instance was classified as 3
 * Output number 3 means that the instance was classified as 2
 * Output number 4 means that the instance was classified as 5
 * Output number 5 means that the instance was classified as 4
 * Output number 6 means that the instance was classified as 7
 * Output number 7 means that the instance was classified as 6
 * Output number 8 means that the instance was classified as 9
 * Output number 9 means that the instance was classified as 8
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

	tmp0_sparseWeights2[0] = tmp1_sparseWeights2_0;
	tmp0_sparseWeights2[1] = tmp1_sparseWeights2_1;
	m_sparseWeights[2] = tmp0_sparseWeights2;

	tmp0_sparseWeights3[0] = tmp1_sparseWeights3_0;
	tmp0_sparseWeights3[1] = tmp1_sparseWeights3_1;
	tmp0_sparseWeights3[2] = tmp1_sparseWeights3_2;
	m_sparseWeights[3] = tmp0_sparseWeights3;

	tmp0_sparseWeights4[0] = tmp1_sparseWeights4_0;
	tmp0_sparseWeights4[1] = tmp1_sparseWeights4_1;
	tmp0_sparseWeights4[2] = tmp1_sparseWeights4_2;
	tmp0_sparseWeights4[3] = tmp1_sparseWeights4_3;
	m_sparseWeights[4] = tmp0_sparseWeights4;

	tmp0_sparseWeights5[0] = tmp1_sparseWeights5_0;
	tmp0_sparseWeights5[1] = tmp1_sparseWeights5_1;
	tmp0_sparseWeights5[2] = tmp1_sparseWeights5_2;
	tmp0_sparseWeights5[3] = tmp1_sparseWeights5_3;
	tmp0_sparseWeights5[4] = tmp1_sparseWeights5_4;
	m_sparseWeights[5] = tmp0_sparseWeights5;

	tmp0_sparseWeights6[0] = tmp1_sparseWeights6_0;
	tmp0_sparseWeights6[1] = tmp1_sparseWeights6_1;
	tmp0_sparseWeights6[2] = tmp1_sparseWeights6_2;
	tmp0_sparseWeights6[3] = tmp1_sparseWeights6_3;
	tmp0_sparseWeights6[4] = tmp1_sparseWeights6_4;
	tmp0_sparseWeights6[5] = tmp1_sparseWeights6_5;
	m_sparseWeights[6] = tmp0_sparseWeights6;

	tmp0_sparseWeights7[0] = tmp1_sparseWeights7_0;
	tmp0_sparseWeights7[1] = tmp1_sparseWeights7_1;
	tmp0_sparseWeights7[2] = tmp1_sparseWeights7_2;
	tmp0_sparseWeights7[3] = tmp1_sparseWeights7_3;
	tmp0_sparseWeights7[4] = tmp1_sparseWeights7_4;
	tmp0_sparseWeights7[5] = tmp1_sparseWeights7_5;
	tmp0_sparseWeights7[6] = tmp1_sparseWeights7_6;
	m_sparseWeights[7] = tmp0_sparseWeights7;

	tmp0_sparseWeights8[0] = tmp1_sparseWeights8_0;
	tmp0_sparseWeights8[1] = tmp1_sparseWeights8_1;
	tmp0_sparseWeights8[2] = tmp1_sparseWeights8_2;
	tmp0_sparseWeights8[3] = tmp1_sparseWeights8_3;
	tmp0_sparseWeights8[4] = tmp1_sparseWeights8_4;
	tmp0_sparseWeights8[5] = tmp1_sparseWeights8_5;
	tmp0_sparseWeights8[6] = tmp1_sparseWeights8_6;
	tmp0_sparseWeights8[7] = tmp1_sparseWeights8_7;
	m_sparseWeights[8] = tmp0_sparseWeights8;

	tmp0_sparseWeights9[0] = tmp1_sparseWeights9_0;
	tmp0_sparseWeights9[1] = tmp1_sparseWeights9_1;
	tmp0_sparseWeights9[2] = tmp1_sparseWeights9_2;
	tmp0_sparseWeights9[3] = tmp1_sparseWeights9_3;
	tmp0_sparseWeights9[4] = tmp1_sparseWeights9_4;
	tmp0_sparseWeights9[5] = tmp1_sparseWeights9_5;
	tmp0_sparseWeights9[6] = tmp1_sparseWeights9_6;
	tmp0_sparseWeights9[7] = tmp1_sparseWeights9_7;
	tmp0_sparseWeights9[8] = tmp1_sparseWeights9_8;
	m_sparseWeights[9] = tmp0_sparseWeights9;


	m_sparseIndices[0] = NULL;

	tmp0_sparseIndices1[0] = tmp1_sparseIndices1_0;
	m_sparseIndices[1] = tmp0_sparseIndices1;

	tmp0_sparseIndices2[0] = tmp1_sparseIndices2_0;
	tmp0_sparseIndices2[1] = tmp1_sparseIndices2_1;
	m_sparseIndices[2] = tmp0_sparseIndices2;

	tmp0_sparseIndices3[0] = tmp1_sparseIndices3_0;
	tmp0_sparseIndices3[1] = tmp1_sparseIndices3_1;
	tmp0_sparseIndices3[2] = tmp1_sparseIndices3_2;
	m_sparseIndices[3] = tmp0_sparseIndices3;

	tmp0_sparseIndices4[0] = tmp1_sparseIndices4_0;
	tmp0_sparseIndices4[1] = tmp1_sparseIndices4_1;
	tmp0_sparseIndices4[2] = tmp1_sparseIndices4_2;
	tmp0_sparseIndices4[3] = tmp1_sparseIndices4_3;
	m_sparseIndices[4] = tmp0_sparseIndices4;

	tmp0_sparseIndices5[0] = tmp1_sparseIndices5_0;
	tmp0_sparseIndices5[1] = tmp1_sparseIndices5_1;
	tmp0_sparseIndices5[2] = tmp1_sparseIndices5_2;
	tmp0_sparseIndices5[3] = tmp1_sparseIndices5_3;
	tmp0_sparseIndices5[4] = tmp1_sparseIndices5_4;
	m_sparseIndices[5] = tmp0_sparseIndices5;

	tmp0_sparseIndices6[0] = tmp1_sparseIndices6_0;
	tmp0_sparseIndices6[1] = tmp1_sparseIndices6_1;
	tmp0_sparseIndices6[2] = tmp1_sparseIndices6_2;
	tmp0_sparseIndices6[3] = tmp1_sparseIndices6_3;
	tmp0_sparseIndices6[4] = tmp1_sparseIndices6_4;
	tmp0_sparseIndices6[5] = tmp1_sparseIndices6_5;
	m_sparseIndices[6] = tmp0_sparseIndices6;

	tmp0_sparseIndices7[0] = tmp1_sparseIndices7_0;
	tmp0_sparseIndices7[1] = tmp1_sparseIndices7_1;
	tmp0_sparseIndices7[2] = tmp1_sparseIndices7_2;
	tmp0_sparseIndices7[3] = tmp1_sparseIndices7_3;
	tmp0_sparseIndices7[4] = tmp1_sparseIndices7_4;
	tmp0_sparseIndices7[5] = tmp1_sparseIndices7_5;
	tmp0_sparseIndices7[6] = tmp1_sparseIndices7_6;
	m_sparseIndices[7] = tmp0_sparseIndices7;

	tmp0_sparseIndices8[0] = tmp1_sparseIndices8_0;
	tmp0_sparseIndices8[1] = tmp1_sparseIndices8_1;
	tmp0_sparseIndices8[2] = tmp1_sparseIndices8_2;
	tmp0_sparseIndices8[3] = tmp1_sparseIndices8_3;
	tmp0_sparseIndices8[4] = tmp1_sparseIndices8_4;
	tmp0_sparseIndices8[5] = tmp1_sparseIndices8_5;
	tmp0_sparseIndices8[6] = tmp1_sparseIndices8_6;
	tmp0_sparseIndices8[7] = tmp1_sparseIndices8_7;
	m_sparseIndices[8] = tmp0_sparseIndices8;

	tmp0_sparseIndices9[0] = tmp1_sparseIndices9_0;
	tmp0_sparseIndices9[1] = tmp1_sparseIndices9_1;
	tmp0_sparseIndices9[2] = tmp1_sparseIndices9_2;
	tmp0_sparseIndices9[3] = tmp1_sparseIndices9_3;
	tmp0_sparseIndices9[4] = tmp1_sparseIndices9_4;
	tmp0_sparseIndices9[5] = tmp1_sparseIndices9_5;
	tmp0_sparseIndices9[6] = tmp1_sparseIndices9_6;
	tmp0_sparseIndices9[7] = tmp1_sparseIndices9_7;
	tmp0_sparseIndices9[8] = tmp1_sparseIndices9_8;
	m_sparseIndices[9] = tmp0_sparseIndices9;


	m_b[0] = NULL;
	m_b[1] = tmp_m_b1;
	m_b[2] = tmp_m_b2;
	m_b[3] = tmp_m_b3;
	m_b[4] = tmp_m_b4;
	m_b[5] = tmp_m_b5;
	m_b[6] = tmp_m_b6;
	m_b[7] = tmp_m_b7;
	m_b[8] = tmp_m_b8;
	m_b[9] = tmp_m_b9;
}
