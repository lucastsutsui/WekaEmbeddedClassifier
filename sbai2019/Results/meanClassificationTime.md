The tables below show mean classification time (in microseconds) for each combination of embedded platform, dataset and classification models. In some cases, it was impossible to run the classifier due to the limitation of memory imposed by the microcontroler.

#### Arduino Mega 2560 (floating point representation)
|                   |    SVM   |   J48  |   MLP   | Logistic |
|-------------------|:--------:|:------:|:-------:|:--------:|
| Aedes aegypti-sex |  3406.17 | 134.13 |    -    |  1572.27 |
| Asfault-roads     | 14476.21 | 219.97 |    -    |  4998.66 |
| Asfault-streets   | 21931.17 | 305.74 |    -    |  8142.92 |
| GasSensorArray    |     -    |    -   |    -    | 16063.28 |
| PenDigits         | 11645.75 |    -   | 7942.12 | 19535.26 |
| HAR               |     -    |    -   |    -    |     -    |

#### Arduino Mega 2560  (fixed-point representation)
|                   |    SVM   |   J48  |   MLP   | Logistic |
|-------------------|:--------:|:------:|:-------:|:--------:|
| Aedes aegypti-sex |  2961.84 | 100.61 |    -    |  1423.00 |
| Asfault-roads     | 13222.65 | 151.09 |    -    |  5570.29 |
| Asfault-streets   | 19799.19 | 200.36 |    -    |  7726.81 |
| GasSensorArray    |     -    |    -   |    -    | 18016.12 |
| PenDigits         |  9364.36 |    -   | 5095.91 |  9337.86 |
| HAR               |     -    |    -   |    -    |     -    |

#### Teensy 3.2 (floating point representation)
|                   |    SVM   |   J48  |    MLP   | Logistic |
|-------------------|:--------:|:------:|:--------:|:--------:|
| Aedes aegypti-sex |  422.76  |  21.50 |  3928.62 |  248.67  |
| Asfault-roads     |  1878.07 |  37.07 |  7871.60 |  817.35  |
| Asfault-streets   |  2754.24 |  52.64 |  7976.84 |  1414.73 |
| GasSensorArray    |  8644.65 |  76.81 | 23414.52 |  3069.91 |
| PenDigits         |  1663.43 | 131.69 |  1659.13 |  5316.46 |
| HAR               | 35358.45 |  70.91 |     -    |  7655.66 |

#### Teensy 3.2 (fixed-point representation)
|                   |   SVM   |  J48  |   MLP   | Logistic |
|-------------------|:-------:|:-----:|:-------:|:--------:|
| Aedes aegypti-sex |  121.93 |  6.87 |  563.43 |   52.14  |
| Asfault-roads     |  325.41 | 11.31 | 1161.12 |  183.70  |
| Asfault-streets   |  437.92 | 14.95 | 1174.55 |  253.20  |
| GasSensorArray    | 1131.57 | 22.22 | 3756.17 |  532.22  |
| PenDigits         |  220.01 | 38.02 |  169.81 |  368.81  |
| HAR               | 4875.58 | 20.34 |    -    |  2070.38 |

#### Teensy 3.6 (floating point representation)
|                   |   SVM   |  J48  |   MLP   | Logistic |
|-------------------|:-------:|:-----:|:-------:|:--------:|
| Aedes aegypti-sex |  14.82  |  2.72 |  584.95 |   51.37  |
| Asfault-roads     |  69.37  |  4.68 | 1020.67 |  138.37  |
| Asfault-streets   |  110.29 |  6.64 | 1039.96 |  272.89  |
| GasSensorArray    |  346.96 |  9.74 | 2064.72 |  545.12  |
| PenDigits         |  68.56  | 16.47 |  382.14 |  1474.78 |
| HAR               | 1525.52 |  8.85 |    -    |  819.36  |

#### Teensy 3.6 (fixed-point representation)
|                   |   SVM   |  J48  |   MLP   | Logistic |
|-------------------|:-------:|:-----:|:-------:|:--------:|
| Aedes aegypti-sex |  38.21  |  2.59 |  208.34 |   19.29  |
| Asfault-roads     |  111.83 |  4.49 |  463.42 |   68.30  |
| Asfault-streets   |  159.60 |  6.25 |  469.83 |   92.30  |
| GasSensorArray    |  451.05 |  8.80 | 1568.42 |  199.24  |
| PenDigits         |  79.88  | 15.00 |  52.11  |  124.15  |
| HAR               | 1957.42 |  8.50 |    -    |  855.15  |
