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
// #define NUM_CLASSES 5
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
// const FixedNum m_Par[65][4] = {{(FixedNum)0x000053a3, (FixedNum)0xffffe55b, (FixedNum)0xfee4f6e6, (FixedNum)0x00007112}, {(FixedNum)0xffffd7a8, (FixedNum)0x00001654, (FixedNum)0xff8b6983, (FixedNum)0x00002591}, {(FixedNum)0xffffecba, (FixedNum)0x000003da, (FixedNum)0xffe382c1, (FixedNum)0x00000d69}, {(FixedNum)0x0012d54c, (FixedNum)0x000945ba, (FixedNum)0x00fdf12e, (FixedNum)0xfffac01d}, {(FixedNum)0xffffb376, (FixedNum)0x000066d5, (FixedNum)0xff830d23, (FixedNum)0x00008ad7}, {(FixedNum)0xfffbc5c4, (FixedNum)0xffff18d3, (FixedNum)0xffb01545, (FixedNum)0xfffe3d7a}, {(FixedNum)0x000004cf, (FixedNum)0x00000fb5, (FixedNum)0x00019408, (FixedNum)0x00000438}, {(FixedNum)0x0000136f, (FixedNum)0xfffffe7e, (FixedNum)0x00062ea5, (FixedNum)0xfffff167}, {(FixedNum)0x000000ca, (FixedNum)0x00002723, (FixedNum)0xfffe300d, (FixedNum)0x0000298a}, {(FixedNum)0xfffeb1d8, (FixedNum)0xffffac9a, (FixedNum)0xffb867e1, (FixedNum)0x00007a8d}, {(FixedNum)0x0012d54c, (FixedNum)0x000945ba, (FixedNum)0x00fdf12e, (FixedNum)0xfffac01d}, {(FixedNum)0xfffbc5c4, (FixedNum)0xffff18d3, (FixedNum)0xffb01545, (FixedNum)0xfffe3d7a}, {(FixedNum)0x000061a1, (FixedNum)0x0000740e, (FixedNum)0x002da8f2, (FixedNum)0x000031bc}, {(FixedNum)0xffff9446, (FixedNum)0xffffb0d4, (FixedNum)0xfff7aee5, (FixedNum)0xffffb069}, {(FixedNum)0x000002d8, (FixedNum)0x00004972, (FixedNum)0xffd53a5c, (FixedNum)0xffffc439}, {(FixedNum)0x000002d8, (FixedNum)0x00004972, (FixedNum)0xffd53a5c, (FixedNum)0xffffc439}, {(FixedNum)0x00019d71, (FixedNum)0x0000b180, (FixedNum)0x002af3d1, (FixedNum)0x000045e9}, {(FixedNum)0xfffeb1d8, (FixedNum)0xffffac9a, (FixedNum)0xffb867e1, (FixedNum)0x00007a8d}, {(FixedNum)0xffffb9a0, (FixedNum)0xffffb1f6, (FixedNum)0x003efbb7, (FixedNum)0xffffda9b}, {(FixedNum)0xfffbc5c4, (FixedNum)0xffff18d3, (FixedNum)0xffb01545, (FixedNum)0xfffe3d7a}, {(FixedNum)0xfffbc5c4, (FixedNum)0xffff18d3, (FixedNum)0xffb01545, (FixedNum)0xfffe3d7a}, {(FixedNum)0xffff69d7, (FixedNum)0xffff7f41, (FixedNum)0xff59a553, (FixedNum)0xffff9911}, {(FixedNum)0xffff8b5f, (FixedNum)0xffffaca7, (FixedNum)0xff62e280, (FixedNum)0xffffbaa0}, {(FixedNum)0x0000d844, (FixedNum)0x00004f2e, (FixedNum)0x006a3748, (FixedNum)0x00007622}, {(FixedNum)0xffffee74, (FixedNum)0x00000f6c, (FixedNum)0x00081bbf, (FixedNum)0x00002e04}, {(FixedNum)0xffffd3d0, (FixedNum)0xffff7cb1, (FixedNum)0x001083a0, (FixedNum)0xffff879a}, {(FixedNum)0xfffffe4b, (FixedNum)0x00000082, (FixedNum)0xfffdbbad, (FixedNum)0xfffffbad}, {(FixedNum)0xffd1705f, (FixedNum)0xffece0e7, (FixedNum)0x00b3a8d1, (FixedNum)0x001a3f7d}, {(FixedNum)0x00094ac5, (FixedNum)0xfffc1f6d, (FixedNum)0xff1ef30c, (FixedNum)0x00018a1d}, {(FixedNum)0xffffffdb, (FixedNum)0xffffd2f4, (FixedNum)0x0053cd32, (FixedNum)0xfffffc57}, {(FixedNum)0x000000e6, (FixedNum)0x00015f24, (FixedNum)0x027e44e1, (FixedNum)0xfffee0f9}, {(FixedNum)0x00007360, (FixedNum)0x00011330, (FixedNum)0x0043c96a, (FixedNum)0x0000fe60}, {(FixedNum)0x00005e9a, (FixedNum)0x0000553b, (FixedNum)0xff6cffb9, (FixedNum)0x00005a3d}, {(FixedNum)0xffff9f80, (FixedNum)0xffff515c, (FixedNum)0x0005dfce, (FixedNum)0xffff2689}, {(FixedNum)0x00000e0b, (FixedNum)0x00001fc4, (FixedNum)0xfff30b96, (FixedNum)0x0000048d}, {(FixedNum)0xfff74bfa, (FixedNum)0xfff60e59, (FixedNum)0xfe377521, (FixedNum)0xfff7d9c6}, {(FixedNum)0x000c57dd, (FixedNum)0x00070b1e, (FixedNum)0xff5d53f0, (FixedNum)0x0005c4a8}, {(FixedNum)0xfffd34e6, (FixedNum)0xfffe0a41, (FixedNum)0x021f7854, (FixedNum)0xfffe2701}, {(FixedNum)0x00031d2d, (FixedNum)0x0001f2c9, (FixedNum)0xfe18219f, (FixedNum)0x0001ccc3}, {(FixedNum)0xffffa1a9, (FixedNum)0x00009543, (FixedNum)0xffee8825, (FixedNum)0x0001ecde}, {(FixedNum)0xffff383e, (FixedNum)0xfffee966, (FixedNum)0x01117c9a, (FixedNum)0xfffe9e6e}, {(FixedNum)0xffff8772, (FixedNum)0xffffad03, (FixedNum)0xfff86618, (FixedNum)0xffffb83b}, {(FixedNum)0xffff78ab, (FixedNum)0xffffab3f, (FixedNum)0xffebbbcc, (FixedNum)0xffffa641}, {(FixedNum)0xffff0592, (FixedNum)0xffff3ab3, (FixedNum)0x00ef60a9, (FixedNum)0xffff533a}, {(FixedNum)0x0012d54c, (FixedNum)0x000945ba, (FixedNum)0x00fdf12e, (FixedNum)0xfffac01d}, {(FixedNum)0xfffff722, (FixedNum)0xfffff94d, (FixedNum)0x00071aa8, (FixedNum)0x0000011b}, {(FixedNum)0x00002cf0, (FixedNum)0x00001e1b, (FixedNum)0xffd8a406, (FixedNum)0xffff5662}, {(FixedNum)0xffffbe84, (FixedNum)0xffffce06, (FixedNum)0x000578d8, (FixedNum)0xffffcfd0}, {(FixedNum)0xffffeedc, (FixedNum)0xfffffbd0, (FixedNum)0x00073b90, (FixedNum)0xfffffd37}, {(FixedNum)0x000088b9, (FixedNum)0x000075d2, (FixedNum)0xffd96683, (FixedNum)0x00006ff8}, {(FixedNum)0xfffff750, (FixedNum)0x000016f6, (FixedNum)0xfff0be2d, (FixedNum)0x0000182d}, {(FixedNum)0xfffff2af, (FixedNum)0xffffe647, (FixedNum)0x00089a99, (FixedNum)0xffffe293}, {(FixedNum)0x0000040a, (FixedNum)0x00000a94, (FixedNum)0xfffef1c0, (FixedNum)0x00000a31}, {(FixedNum)0x00008b56, (FixedNum)0x00007de3, (FixedNum)0xffb37ec5, (FixedNum)0x00005d27}, {(FixedNum)0x0000d472, (FixedNum)0x0000a211, (FixedNum)0x001dbe76, (FixedNum)0x00014929}, {(FixedNum)0x0000ea4d, (FixedNum)0x0000c0ca, (FixedNum)0x000b6999, (FixedNum)0x0000e2fb}, {(FixedNum)0x00004906, (FixedNum)0x000034ed, (FixedNum)0x0011421b, (FixedNum)0xffffe171}, {(FixedNum)0x0000585a, (FixedNum)0x00002477, (FixedNum)0xfffee5c5, (FixedNum)0x0000205e}, {(FixedNum)0xffffef97, (FixedNum)0xffffe079, (FixedNum)0xffcb3043, (FixedNum)0x0000b0ab}, {(FixedNum)0xfffef803, (FixedNum)0xffff275d, (FixedNum)0xffd0043e, (FixedNum)0xfffe16e3}, {(FixedNum)0xfffd2fa1, (FixedNum)0xfffd7a0b, (FixedNum)0xffe66a07, (FixedNum)0xfffabe10}, {(FixedNum)0xffff87e0, (FixedNum)0xfffee4af, (FixedNum)0x00514b8e, (FixedNum)0xfffeb18d}, {(FixedNum)0x000008da, (FixedNum)0xfffff381, (FixedNum)0xfffde069, (FixedNum)0xffffeb45}, {(FixedNum)0x00002fef, (FixedNum)0xffffdb2a, (FixedNum)0x000a20e7, (FixedNum)0xffffa3ab}, {(FixedNum)0x00002d37, (FixedNum)0x000074c1, (FixedNum)0x002d8db8, (FixedNum)0x00000a6f}};
// const int m_SelectedAttributes[65] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64};
//
// /* Function classify description:
//  * Instance array must be initializated, with appropriated attributes, before calling this function
//  * Output number 0 means that the instance was classified as ruim
//  * Output number 1 means that the instance was classified as regular
//  * Output number 2 means that the instance was classified as pessimo
//  * Output number 3 means that the instance was classified as bom
//  * Output number 4 means that the instance was classified as obstaculos
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
