
#include <Arduino.h>
#include <math.h>

#define INPUT_SIZE 8
#define NUM_CLASSES 10
#define SELECTED_ATT_SIZE 8
#define NUM_PREDICTORS 8
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
const float m_Par[9][9] = {{-2.0615571162693334, 2.9120937029627596, -15.57756340367969, -11.916858596790508, 5.600837512668749, -2.769394988723481, -1.9210249710379432, 5.938755721015268, -10.097122830522904}, {-0.06455169301353914, -0.012753604599622673, -0.04867742047568097, -0.07583705716486634, -0.00708876433672459, -0.020993775425026128, -0.13805260725260993, 0.03570450914616796, 0.03372628424035856}, {0.05487013274891701, -0.07216907134769092, -0.0023814917131551433, 0.04980866164203806, -0.010516205955830726, -0.004285791218348456, 0.0711460083485724, -0.026574999068165805, -0.006755633295929356}, {-0.014315221636343307, -0.03359916729797881, 0.09470023636228297, 0.011086602529613566, -0.0019045352938152492, -0.08256829659581846, -0.006477172412971419, -0.08182227227762004, 0.01910078596541086}, {0.0461948574274147, -0.025019568879724927, 0.016439640144881855, 0.0795852801171051, -0.023304427837701192, 0.00730364146128768, 0.04721994865322439, -0.026718028285702983, 0.013212341964834234}, {0.00692655810475255, 0.00423130861799747, 0.0552429873534777, -0.06838138149040386, -0.050230424969515165, 0.0012462387622596436, -0.018358929556503045, -0.14236362796856075, 0.006659256805307318}, {0.023323129189080295, 0.0729706790143184, 0.1265484122637862, -0.004644839762031125, 0.07612000536664644, 0.12257096192673414, 0.029111901648924157, 0.1424611707122603, 0.1124102694710941}, {-0.058925756185167225, -0.05270701790967629, -0.08236465952025872, 0.014488611097067719, -0.12256692946238783, -0.10863823548790097, -0.07329213400736201, -0.11773710488793203, -0.040979261958960525}, {0.02876243175434329, -0.006678119710201236, -0.022422172998164853, 0.0976478575739349, 0.02586634571311834, 0.07571396887857752, 0.04140071744619785, -0.03050514956714274, 0.030090620636068013}};
const int m_SelectedAttributes[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

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
	float prob[NUM_CLASSES];
	float newInstance[NUM_PREDICTORS+1];
	newInstance[0] = 1.0;
	for (int i = 1; i <= SELECTED_ATT_SIZE; i++){
		if (m_SelectedAttributes[i] <= CLASS_INDEX) {
			newInstance[i] = instance[m_SelectedAttributes[i-1]];
		}
		else {
			newInstance[i] = instance[m_SelectedAttributes[i]];
		}
	}
	float v[NUM_CLASSES] = {0};
	for (int i = 0; i < NUM_CLASSES-1; i++) {
		for (int j = 0; j <= NUM_PREDICTORS; j++) {
			v[i] += m_Par[j][i] * newInstance[j];
		}
	}
	v[NUM_CLASSES-1] = 0;
	for (int i = 0; i < NUM_CLASSES; i++) {
		float acc = 0.0;
		for (int j = 0; j < NUM_CLASSES-1; j++) {
			acc += exp(v[j]-v[i]);
		}
		prob[i] = 1.0 / (acc + exp(-v[i]));
	}
	int indexMax = 0;
	for (int i = 1; i < NUM_CLASSES; i++) {
		if (prob[i] > prob[indexMax]) {
			indexMax = i;
		}
	}
	return indexMax;
}
