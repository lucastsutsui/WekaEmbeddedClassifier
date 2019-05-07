
#include <Arduino.h>
#include <math.h>

#define INPUT_SIZE 128
#define NUM_CLASSES 6
#define SELECTED_ATT_SIZE 128
#define NUM_PREDICTORS 128
#define CLASS_INDEX 128

/* Instance array must be global
 * Attributes MUST be sorted in instance array in the following order:
 * V1
 * V2
 * V3
 * V4
 * V5
 * V6
 * V7
 * V8
 * V9
 * V10
 * V11
 * V12
 * V13
 * V14
 * V15
 * V16
 * V17
 * V18
 * V19
 * V20
 * V21
 * V22
 * V23
 * V24
 * V25
 * V26
 * V27
 * V28
 * V29
 * V30
 * V31
 * V32
 * V33
 * V34
 * V35
 * V36
 * V37
 * V38
 * V39
 * V40
 * V41
 * V42
 * V43
 * V44
 * V45
 * V46
 * V47
 * V48
 * V49
 * V50
 * V51
 * V52
 * V53
 * V54
 * V55
 * V56
 * V57
 * V58
 * V59
 * V60
 * V61
 * V62
 * V63
 * V64
 * V65
 * V66
 * V67
 * V68
 * V69
 * V70
 * V71
 * V72
 * V73
 * V74
 * V75
 * V76
 * V77
 * V78
 * V79
 * V80
 * V81
 * V82
 * V83
 * V84
 * V85
 * V86
 * V87
 * V88
 * V89
 * V90
 * V91
 * V92
 * V93
 * V94
 * V95
 * V96
 * V97
 * V98
 * V99
 * V100
 * V101
 * V102
 * V103
 * V104
 * V105
 * V106
 * V107
 * V108
 * V109
 * V110
 * V111
 * V112
 * V113
 * V114
 * V115
 * V116
 * V117
 * V118
 * V119
 * V120
 * V121
 * V122
 * V123
 * V124
 * V125
 * V126
 * V127
 * V128
 */
float instance[INPUT_SIZE+1];
const float m_Par[129][5] = {{35.80722843017708, -37.405801995045636, -82.89074558742499, -22.533837107871175, 43.41327987186285}, {-0.0010108572821844028, -5.6166222083961976e-05, -0.0017650358954278988, 0.0004087252223899146, -0.00028908994220718166}, {2.416345503120779, 5.357715451140506, -0.6264829304597351, 5.0985342595716405, 4.312516397621522}, {7.392273728764188, 9.24706272504444, -0.7544428195727938, -16.490437482387904, 10.191336683846417}, {2.896667373014126, -3.5623812316661296, 1.6145930534936028, 7.989282595537297, -2.9039022668553796}, {-3.027388503660271, -1.2344183974769602, -2.464605965064717, -3.309047502281754, -1.7836390905857071}, {5.537594884888924, 5.525913772625019, -18.649991330623763, -2.3655514981189794, 3.706297215668658}, {-2.357600440352957, -1.2567415847682382, 2.3848396042394464, -1.4146489263272455, -3.1159250934945404}, {0.318439794852418, 0.004668939688310469, 0.6980459410788316, 0.39779794197817325, 0.8811421402129709}, {-0.0005927094132268844, 0.0010871788564715222, 0.004081251600869129, -0.002770160654345569, 0.0026788591546677283}, {-1.4018863250032594, 0.08775809694444446, -12.132532780683272, -3.7989842618842595, 0.3153377721204986}, {-8.44321113771593, -0.7357585882486734, -5.8883712153270436, -8.357715536471984, -12.642634192734517}, {-4.329709031935972, -1.864579547552715, 1.1425714825742397, -4.210131445816915, -1.9196565757650745}, {1.464816636466081, 1.010565755694363, 0.6003334845500096, 2.7310280712032866, 2.7557428425361734}, {-18.797058805051893, -3.649078307505932, 0.9586323614500764, -28.243352648597376, -4.211872219680913}, {3.211213480905823, 0.9287446264167363, 0.023965499318660266, 5.093844590287217, 1.8279101668668005}, {-0.13559326002577254, 0.1786501393409832, 0.022908698448540855, -0.2832297751653096, -0.45613306168925105}, {0.0034955744984585635, -0.008685558217319193, -0.015830367529371548, 0.0028676079088119145, 0.008617380597841569}, {17.749690106305543, 32.76762611786957, -29.58547699480562, 13.332859950348194, 15.092361047403886}, {34.71843065458937, -49.90542370219, 7.802044820647886, -17.552082263862385, 14.45330048911099}, {12.326255923935827, 41.980311047873705, 19.11517799442185, 5.988471290763902, 22.11503017425014}, {2.270709219598084, -0.882364586394073, 0.7044217407468504, -0.8038468618483161, -0.7370055592084436}, {22.467998190355026, 102.64041805839976, 15.912130753418717, 38.69842664435206, 25.903547445813306}, {47.615322179413965, 15.73389226029355, 13.547731775599502, -21.374104349743025, -4.757369399194761}, {2.696319799666508, 1.9793742109082133, -0.857836730390854, 1.371902889842285, 2.594829392482939}, {0.0006392803392022548, -0.013140382985921005, 0.014907703635750372, 0.03176428330430373, 0.007765201050952679}, {-0.4211647577504641, 17.936416004771534, 48.76793851482118, -31.357021986824783, 32.61478871425648}, {-21.328620370015454, 29.191235030589493, 105.9266474852468, 47.31654345809616, 1.1095762423347255}, {25.127007090898825, 20.389629887232605, 9.363769944002359, -1.0433664333959367, 10.78445312631967}, {-0.36481218332696963, -0.5164121298386379, -0.7907097190935627, -1.1814379820010765, -2.3627129782445904}, {44.7702931282491, -24.104974812416497, -55.095019539411624, 18.169181941384227, 50.83643799970062}, {12.917476068285502, -10.498019231181516, 1.0964129791224277, -9.08711549854199, -0.6744063525898818}, {-2.612720544192748, 1.0190671092299994, 1.0076385276472797, 2.420642152393411, 0.147597358457782}, {0.06347968360516798, 0.18213568827548127, -0.04019442689386378, 0.008132051983878999, 0.01520034225229963}, {4.975901392848515, 44.337770195349385, 43.596520133698284, -62.151334505740024, -27.737650400737763}, {-133.7718233297554, -234.20356333386266, 335.9545052563467, -372.5556682435245, 105.2999668000661}, {16.52262393295365, -33.282004729285276, -23.440132964878647, 96.87160700068839, 41.15039370425505}, {-3.014822532664291, 0.8479427240766635, -5.3157936267588415, -4.737792559990097, -3.2530976236287636}, {17.3998938464474, 385.2015661255889, 228.4542983760067, -119.7079295580323, 443.78524226831877}, {82.13557656751414, 27.248789962326946, 68.62415003086525, -30.54078189413099, -51.103903397773834}, {-1.3746271540576183, 0.34341187825867403, -3.8998813218692474, 0.8254474631991314, -4.316423663922839}, {-0.010766641030235207, -0.10866379108315946, -0.10462756534776767, 0.03642450225108739, 0.057559414244155824}, {0.007983085672609842, -0.6642711285316106, -0.2361412115595506, 0.3215160859928055, -0.09724165569397948}, {-289.7263590311134, 293.80824872986534, -227.49741052878758, 94.44680052123151, -277.8529266820035}, {42.30406033075269, 26.904936921477987, 31.07069368889879, 16.575311228239965, 30.386362674475045}, {-6.569180403884435, 1.3321650641241165, -2.254075585629163, -8.26277294271852, 1.3452473969535181}, {-218.52326863359147, -176.71502447238808, -516.8530373082552, 227.8275872721911, 27.86922926326659}, {28.217589632303593, -6.276429817937806, 36.49800143844676, -33.22289368343904, -2.2893266351903367}, {-5.8980239861785355, -7.775616901524903, 1.8356449592956174, -6.026361738972174, 4.847373979460038}, {0.01928620516756477, 0.0006030702743816823, 0.002398420932299059, -0.014662032414701584, -0.013697243758372158}, {-2.514046929567541, -1.3440833186917263, -1.5357696395958167, 0.5530909841485374, -0.6730388104191375}, {37.331261135568134, 5.246680862478519, 19.998061601439147, -36.530420626747905, 43.877593806899114}, {-2.7179230336219247, -26.296484694824283, -12.297205421221195, 0.24407619595961416, 1.6154539354346322}, {-1.568480734366511, 5.04658273878479, 6.43085831052248, 0.30116821507497166, -1.0287821637957104}, {-31.63674081125909, -63.163488096964066, 32.46169593575103, -6.856947592388717, -37.32054545046}, {-30.776564169231836, -7.657887925572011, -26.17419988661148, -5.697258228927523, -24.064801067281874}, {-4.025508806135913, -5.780564029651661, -0.9203074516795527, -3.8550718403132187, -4.745192037233522}, {-0.0022357874043117624, 0.004572810702372508, -0.0009927763795983334, -0.003987812402680833, -0.010494002000776114}, {-0.11123145623334646, -0.9549540094236391, -0.6764374652761217, 0.47316943569090203, -0.2553982217836661}, {-36.73615803400087, 4.0636133925896, 20.345506942892886, 13.415567299256779, -7.888681017016482}, {-32.88671095397417, -18.300290063504363, -18.536858203693463, 15.117409184891374, -28.12006738251635}, {4.492588894918015, 4.538532609645083, 1.7280021133626933, -1.0462587628000897, 1.9031795069385506}, {3.095835852993894, -51.99611773123815, 44.529405195471554, -45.901718286631294, 12.896009337132506}, {1.1957037867143672, -32.36867462064456, 5.187499127177544, -16.55223442626948, 6.235302949193502}, {0.7034323187488448, 3.1403883846803744, 2.4908771438301867, 6.9611277321589915, 0.1297324379367343}, {0.001407931936737747, -0.003032693174775448, -0.0058004203907398065, 0.002231269585392559, -0.0007509404176486682}, {-47.96755123591288, -56.15244892787916, -2.929636986745282, -43.288351800892315, -35.59076449839465}, {-7.862904411116127, 13.646515253651426, 8.73976532695649, 1.4928367282331036, -8.962931115362869}, {-9.430257794664922, -8.390432393302598, -0.30943650227244157, -6.144761859227072, -2.180648638466301}, {0.625017645126204, 2.060516520379529, -2.0284163161077573, 1.5487787106522188, -1.22188701380187}, {29.450194074866243, 23.221893921650594, 19.686386813546935, -1.1892944203487827, -6.462199646983667}, {4.200057585066736, -1.0526209220859886, 7.145614813226621, 8.869527072775032, -1.645099250017172}, {-0.0733416807634915, -1.2620104063284385, -1.2157833775428215, 0.4237089412197386, -0.11894963977808252}, {0.0010811462905993387, -0.0015170969602995642, -0.0012579773883042785, 6.622972483251515e-05, -0.0007420469847086046}, {48.89848490351179, 44.77367534114883, 1.6666265924918242, 45.23586898694375, 26.52752683832216}, {4.49827105336684, 19.808941312658014, 17.501730490464528, 13.552799204267513, 2.3017361687572793}, {10.978434228453875, -12.586719844934263, -13.423510336788663, 9.200602818985253, 11.035466586348022}, {2.254879781989241, -2.9734645499581998, 3.579176210879612, 0.7157231149363841, 2.668005128099654}, {4.681544885019102, -22.047210217429434, -29.051280499112774, 29.33154350053108, 25.18285659374909}, {-15.72405428941872, -0.6388254841960676, -1.8230124720092666, -15.78165165625439, -7.521121484012838}, {-0.4628071072619758, -0.07369204017491343, 0.1402017328420076, 0.7345783807570798, -0.35296612203575656}, {-0.01011872083158976, 0.051633869215587665, 0.01351679802021701, 0.01670602886173949, -0.002057380747813073}, {34.834114211937354, 51.199303694382294, -17.53322744739546, 115.64542658191792, 43.00136966503834}, {47.38578089309079, -26.803702822473774, 38.39079657557513, 65.77042316381188, 59.3044379197878}, {30.17528359050367, -1.1686071970292444, 8.060695225078495, 74.3074549377743, 23.21238301317032}, {1.4009658292009088, -1.5667003684246437, -5.101375401246679, 2.253036337099831, 1.3578469794445414}, {-0.913279535274489, -20.145588765950077, -32.362875740314045, 21.441512287218657, 3.8189768698714226}, {-6.156813878019237, -18.374282988190863, -3.088686038698007, 16.23902539862379, -14.321176772602676}, {-2.324714303137411, -4.772202529283603, 3.18790719947374, -8.653640005158811, -2.7274711720116973}, {-0.02975380106997206, -0.0061586292133027284, -0.03816059834839545, -0.06492839541963422, -0.011065106432222228}, {-79.77452426320134, -80.17455636968344, 52.19268345960196, -157.52278144290736, -53.227252449177215}, {-31.007062835250434, -62.462789292865594, -124.44019834833895, -55.27562785465366, -59.38580295682695}, {-3.018649278691139, -5.532210796073916, -30.271962661246302, -66.71583963550756, -0.9151090197494536}, {-9.610916234628387, 2.1129506382683045, 2.8407034429897005, -5.443263593838914, -3.7496441658956283}, {29.405142624511818, 40.266207675586784, 97.49719101068887, 99.71016064555225, 143.95772505874686}, {36.2061540815063, 38.32571336771402, 15.192240747161577, 19.132790037509967, 48.447892610319634}, {4.647059391278857, -0.002507480978214664, -7.470080363120072, -4.750441050252622, 0.7116697382612124}, {0.0031916330595033325, -0.08766087572627762, 0.1978488493756993, -0.009778555260151905, 0.041507099157078405}, {-82.77398870679637, -5.14063330639864, -116.48984180099085, 49.45215443087249, 35.985016136089264}, {386.23144753246373, -62.23575624119052, -139.58775530111856, -140.7006958888675, 12.06982184561992}, {34.344867922315935, -8.896118317670325, 26.967784384308732, 61.81779023609893, -43.244009905069774}, {2.3827621513560917, 13.39455733013766, 9.274095101146862, -0.31140467798074273, 9.69738488721496}, {291.0738763514924, -135.54098448963674, 132.32626586453017, -332.01273014619613, 55.069655480951184}, {-114.66362983669562, 73.44288028876649, -57.20341519660476, -0.7814555811884335, -34.580653868729605}, {6.770866893399362, 14.216606196537608, 1.0242934750260435, 7.673896163021994, 5.691967226783914}, {0.030986386056874416, 0.0697964572328677, -0.013207740238075655, -0.058608847519524714, 0.061592252312876725}, {69.99629886332814, -56.13978080330315, 107.55035586333798, 67.82766161393468, -51.26137189478305}, {-331.2719118537883, -167.27793116600435, -213.58393434911346, 47.24346027145849, -308.4993598187277}, {-41.01736066133195, -6.124684213580396, -19.67141658566804, -55.836265169964484, 41.88613890821662}, {-0.36342747302914297, 5.199065421605427, 14.37800387829162, 7.347079145060318, -14.83544682623331}, {13.64297272885997, 7.959550196642038, 194.84478364385214, 272.9192015683412, -80.6837389444025}, {-123.33450815720586, -77.86727534279218, -66.55258261694242, -81.39108391051384, -26.64754553764749}, {10.819142630157375, -7.609465882672459, -0.25636581577866313, 12.298456950035996, -0.9739533180745102}, {0.014210242618691228, -0.020607195479403508, 0.0211101117137063, 0.0076115283826654065, -0.001144031561592906}, {39.933165363536936, -12.780988656673388, 7.039289049998159, 7.745332116391196, -15.220411603724429}, {17.556855056631992, 34.54430826861268, 25.25326511497995, 4.267980569361948, 7.411566374384809}, {-18.845711026416193, 11.191214148675487, -4.521568008854034, -49.66413983680332, -11.630032976105706}, {-0.6648775770028731, -4.675715922558667, -0.5178557417218895, -2.633395504755085, 1.8734579150333528}, {-31.244761108683406, 62.89961468946832, -17.562904643666432, -7.886128536564562, -34.83910527703384}, {-12.567529628227385, 23.246814711780715, -4.5012294670822275, 27.341527546716343, -3.819934923180645}, {0.9784942058699336, 2.209130655185833, 1.8703212901395745, -2.757382044580815, -0.608280545990386}, {-0.01274453465820497, -0.007612649077080427, -0.0024357313607920416, 0.018873441452637127, 0.00853566189295206}, {-17.00735535190673, 18.165814192293734, -48.75356935576845, 11.069590489935631, -9.410040987004285}, {25.69103313135414, 83.62140162261619, -15.50993935868761, 107.60286433099027, 63.53787168534031}, {21.40193582669702, -7.13116688591374, 5.466068051596655, -4.725089587975391, -1.3149084058992833}, {-0.25574488887126434, 0.4935816984679224, -7.598884952311813, 2.475466524710307, -5.792892593813208}, {0.47530915151597847, 12.316870860224158, 5.008105477243677, -38.545393070060925, -57.66304343337187}, {5.062829114249014, -22.8837683028144, -5.692729208407682, 8.44053078292707, 5.674039203593476}, {2.9585910710294336, 2.8809355535010517, -2.145745741388108, 0.5948483183121147, 5.150029687618825}};
const int m_SelectedAttributes[129] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128};

/* Function classify description:
 * Instance array must be initializated, with appropriated attributes, before calling this function
 * Output number 0 means that the instance was classified as 1
 * Output number 1 means that the instance was classified as 2
 * Output number 2 means that the instance was classified as 3
 * Output number 3 means that the instance was classified as 4
 * Output number 4 means that the instance was classified as 5
 * Output number 5 means that the instance was classified as 6
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
	return indexMax+1;
}