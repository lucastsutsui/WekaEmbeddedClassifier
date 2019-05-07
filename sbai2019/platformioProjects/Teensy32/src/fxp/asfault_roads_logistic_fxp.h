//
// #include <Arduino.h>
//
// #define TOTAL_BITS 32
// #define FIXED_FBITS 10
// #define SIGNED
// #define OVERFLOW_DETECT
// #include "FixedNum.h"
//
// #define INPUT_SIZE 64
// #define NUM_CLASSES 4
// #define SELECTED_ATT_SIZE 64
// #define NUM_PREDICTORS 64
// #define CLASS_INDEX 64
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
// FixedNum instance[INPUT_SIZE+1];
// const FixedNum m_Par[65][3] = {{(FixedNum)0xffa38832, (FixedNum)0x003997ef, (FixedNum)0x00399034}, {(FixedNum)0xfff96eac, (FixedNum)0x00124840, (FixedNum)0x00125c8a}, {(FixedNum)0x00054650, (FixedNum)0x000ba730, (FixedNum)0x000ba0c7}, {(FixedNum)0x00031e0d, (FixedNum)0x0011b8c9, (FixedNum)0x000ad4b9}, {(FixedNum)0xffb449f7, (FixedNum)0x001bed00, (FixedNum)0x001ce7f5}, {(FixedNum)0xffff94ed, (FixedNum)0xfff02277, (FixedNum)0xffece4ed}, {(FixedNum)0xfff5dece, (FixedNum)0xfff9fcf8, (FixedNum)0xfffa008a}, {(FixedNum)0x00046ba2, (FixedNum)0x000475f2, (FixedNum)0x00046025}, {(FixedNum)0xffde664e, (FixedNum)0xfffaddfd, (FixedNum)0xfffafaba}, {(FixedNum)0xffedc45a, (FixedNum)0xfff9c769, (FixedNum)0xfff9d568}, {(FixedNum)0x00031e15, (FixedNum)0x0011bb65, (FixedNum)0x000ad215}, {(FixedNum)0xffff94f2, (FixedNum)0xfff0240a, (FixedNum)0xffece356}, {(FixedNum)0x0039e6e3, (FixedNum)0xffce6f88, (FixedNum)0xffce53a4}, {(FixedNum)0xffbffe37, (FixedNum)0x002f72f0, (FixedNum)0x002f7c85}, {(FixedNum)0x00359716, (FixedNum)0xfff4ae8c, (FixedNum)0xffff7981}, {(FixedNum)0x0035b519, (FixedNum)0xffffcd99, (FixedNum)0xfff43afb}, {(FixedNum)0x005a0224, (FixedNum)0xffd9dc23, (FixedNum)0xffd98e8f}, {(FixedNum)0xffedc45a, (FixedNum)0xfff9c769, (FixedNum)0xfff9d568}, {(FixedNum)0xffe292af, (FixedNum)0x001c11e1, (FixedNum)0x001c1d27}, {(FixedNum)0xffff94ed, (FixedNum)0xfff02277, (FixedNum)0xffece4ed}, {(FixedNum)0xffff8310, (FixedNum)0xffea013a, (FixedNum)0xfff318d0}, {(FixedNum)0xffb79664, (FixedNum)0x00252c4a, (FixedNum)0x00258657}, {(FixedNum)0xffbafd3a, (FixedNum)0x0028f15d, (FixedNum)0x00294e5a}, {(FixedNum)0x00381ced, (FixedNum)0xfff0952d, (FixedNum)0xfff09003}, {(FixedNum)0xfffac37b, (FixedNum)0xfff4c169, (FixedNum)0xfff4d4e8}, {(FixedNum)0x0017ebde, (FixedNum)0xffef131b, (FixedNum)0xffef4fff}, {(FixedNum)0xffffb02d, (FixedNum)0xffffad4e, (FixedNum)0xffffaf91}, {(FixedNum)0x00152739, (FixedNum)0xfffdffd7, (FixedNum)0xfffddd40}, {(FixedNum)0x000752ba, (FixedNum)0xfffa01d9, (FixedNum)0xfff9cb1d}, {(FixedNum)0x0001335d, (FixedNum)0x00131563, (FixedNum)0x00130691}, {(FixedNum)0x002bc6f5, (FixedNum)0xffe38a17, (FixedNum)0xffe38a5f}, {(FixedNum)0x00562ff7, (FixedNum)0xffdc4ad3, (FixedNum)0xffdc191f}, {(FixedNum)0xfff77090, (FixedNum)0xfffc5e13, (FixedNum)0xfffc5e17}, {(FixedNum)0xffc29845, (FixedNum)0x00165741, (FixedNum)0x001666eb}, {(FixedNum)0x00041b32, (FixedNum)0xfffa456e, (FixedNum)0xfffa50e2}, {(FixedNum)0xffbd8d50, (FixedNum)0x002d75fd, (FixedNum)0x002ea460}, {(FixedNum)0x00727389, (FixedNum)0xffb1b19f, (FixedNum)0xffb0da92}, {(FixedNum)0xffdeb433, (FixedNum)0xfff868b7, (FixedNum)0xfff87f3b}, {(FixedNum)0xffe00576, (FixedNum)0x00106bc4, (FixedNum)0x00104b97}, {(FixedNum)0xffe9b29f, (FixedNum)0x0004f6b8, (FixedNum)0x0004eea8}, {(FixedNum)0x002b94a2, (FixedNum)0xffee4f7b, (FixedNum)0xffee5330}, {(FixedNum)0x0018262b, (FixedNum)0xfff0f8d0, (FixedNum)0xfff0f680}, {(FixedNum)0x00152c3c, (FixedNum)0xffedb8c6, (FixedNum)0xffedb3ca}, {(FixedNum)0x00095fe5, (FixedNum)0xfff56fbe, (FixedNum)0xfff56728}, {(FixedNum)0x0002ff7f, (FixedNum)0x00078eaa, (FixedNum)0x00151e97}, {(FixedNum)0x0001d82e, (FixedNum)0xfffee5f3, (FixedNum)0xfffee91b}, {(FixedNum)0x0010b8ae, (FixedNum)0x00142c80, (FixedNum)0x00142556}, {(FixedNum)0xfff2e2f1, (FixedNum)0xfffa3762, (FixedNum)0xfffa3831}, {(FixedNum)0x000de428, (FixedNum)0x00038ccc, (FixedNum)0x00039a8b}, {(FixedNum)0xfffd20bb, (FixedNum)0x0000bb5b, (FixedNum)0x0000b2aa}, {(FixedNum)0x000b1b28, (FixedNum)0x0001d102, (FixedNum)0x0001d45b}, {(FixedNum)0xfff82ffc, (FixedNum)0xfffcbadf, (FixedNum)0xfffcbb8b}, {(FixedNum)0x00029f9a, (FixedNum)0x0005ac47, (FixedNum)0x0005a999}, {(FixedNum)0x004b96f8, (FixedNum)0x003f63a5, (FixedNum)0x003f5ed3}, {(FixedNum)0x003f930a, (FixedNum)0x003588f0, (FixedNum)0x00359302}, {(FixedNum)0x002590eb, (FixedNum)0x00219c56, (FixedNum)0x0021a89f}, {(FixedNum)0x001f7e2d, (FixedNum)0x002cf5ec, (FixedNum)0x002d050d}, {(FixedNum)0x001bd1ee, (FixedNum)0x0014694f, (FixedNum)0x00147470}, {(FixedNum)0x001d4d83, (FixedNum)0x0016c6d5, (FixedNum)0x0016d339}, {(FixedNum)0xffde6b8d, (FixedNum)0xffe0c02b, (FixedNum)0xffe0713d}, {(FixedNum)0xffc3b796, (FixedNum)0xffbe3d67, (FixedNum)0xffbe16eb}, {(FixedNum)0x00082892, (FixedNum)0x000b3cca, (FixedNum)0x000b3abc}, {(FixedNum)0x003a63b4, (FixedNum)0x0031eea5, (FixedNum)0x0031d694}, {(FixedNum)0x000e4244, (FixedNum)0x0013b99b, (FixedNum)0x0013b133}, {(FixedNum)0xfff4679a, (FixedNum)0x0007315e, (FixedNum)0x000742fd}};
// const int m_SelectedAttributes[65] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64};
//
// /* Function classify description:
//  * Instance array must be initializated, with appropriated attributes, before calling this function
//  * Output number 0 means that the instance was classified as ruim
//  * Output number 1 means that the instance was classified as regular
//  * Output number 2 means that the instance was classified as bom
//  * Output number 3 means that the instance was classified as obstaculos
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
// 	return indexMax;
// }
