The tables below show maximum classification time (in microseconds) for each combination of embedded platform, dataset and classification models. In some cases, it was impossible to run the classifier due to the limitation of memory imposed by the microcontroler.

#### Arduino Mega 2560  (floating point representation)
|                   |  SVM  | J48 |  MLP | Logistic |
|-------------------|:-----:|:---:|:----:|:--------:|
| Aedes aegypti-sex |  3452 | 240 |   -  |   1620   |
| Asfault-roads     | 14584 | 508 |   -  |   5632   |
| Asfault-streets   | 22176 | 556 |   -  |   9516   |
| GasSensorArray    |   -   |  -  |   -  |   18888  |
| PenDigits         | 11976 |  -  | 8436 |   20072  |
| HAR               |   -   |  -  |   -  |     -    |

#### Arduino Mega 2560  (fixed-point representation)
|                   |  SVM  | J48 |  MLP | Logistic |
|-------------------|:-----:|:---:|:----:|:--------:|
| Aedes aegypti-sex |  3160 | 168 |   -  |   1444   |
| Asfault-roads     | 13556 | 312 |   -  |   5792   |
| Asfault-streets   | 20164 | 340 |   -  |   8276   |
| GasSensorArray    |   -   |  -  |   -  |   18756  |
| PenDigits         |  9640 |  -  | 5928 |   9960   |
| HAR               |   -   |  -  |   -  |     -    |

#### Teensy 3.2  (floating point representation)
|                   |  SVM  | J48 |  MLP  | Logistic |
|-------------------|:-----:|:---:|:-----:|:--------:|
| Aedes aegypti-sex |  432  |  40 |  3964 |    258   |
| Asfault-roads     |  1888 |  78 |  7933 |   1149   |
| Asfault-streets   |  2763 |  90 |  8075 |   1772   |
| GasSensorArray    |  8667 | 148 | 24034 |   3184   |
| PenDigits         |  1674 | 230 |  1712 |   5420   |
| HAR               | 35543 | 127 |   -   |   7718   |

#### Teensy 3.2  (fixed-point representation)
|                   |  SVM | J48 |  MLP | Logistic |
|-------------------|:----:|:---:|:----:|:--------:|
| Aedes aegypti-sex |  131 |  15 |  572 |    62    |
| Asfault-roads     |  329 |  24 | 1168 |    193   |
| Asfault-streets   |  441 |  26 | 1183 |    275   |
| GasSensorArray    | 1137 |  43 | 3794 |    554   |
| PenDigits         |  222 |  66 |  174 |    385   |
| HAR               | 4924 |  36 |   -  |   2090   |

#### Teensy 3.6  (floating point representation)
|                   |  SVM | J48 |  MLP | Logistic |
|-------------------|:----:|:---:|:----:|:--------:|
| Aedes aegypti-sex |  17  |  5  |  594 |    54    |
| Asfault-roads     |  74  |  10 | 1034 |    234   |
| Asfault-streets   |  117 |  11 | 1060 |    376   |
| GasSensorArray    |  355 |  19 | 2265 |    578   |
| PenDigits         |  74  |  29 |  397 |   1503   |
| HAR               | 1529 |  16 |   -  |    838   |

#### Teensy 3.6  (fixed-point representation)
|                   |  SVM | J48 |  MLP | Logistic |
|-------------------|:----:|:---:|:----:|:--------:|
| Aedes aegypti-sex |  40  |  5  |  216 |    21    |
| Asfault-roads     |  117 |  9  |  468 |    72    |
| Asfault-streets   |  165 |  11 |  476 |    100   |
| GasSensorArray    |  459 |  17 | 1583 |    209   |
| PenDigits         |  86  |  26 |  56  |    131   |
| HAR               | 1979 |  15 |   -  |    865   |
