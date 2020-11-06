EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	1150 4400 950  4400
Wire Wire Line
	1150 4300 950  4300
Wire Wire Line
	1150 4200 950  4200
Wire Wire Line
	1150 4100 950  4100
Wire Wire Line
	1150 4000 950  4000
Wire Wire Line
	1150 3900 950  3900
Wire Wire Line
	1150 3800 950  3800
Wire Wire Line
	1150 3700 950  3700
Wire Wire Line
	1150 3600 950  3600
Wire Wire Line
	1150 3500 950  3500
Wire Wire Line
	1150 3400 950  3400
Wire Wire Line
	950  3300 1150 3300
Text GLabel 3500 4000 2    50   Input ~ 0
NIX_LE
Text GLabel 3500 3900 2    50   Input ~ 0
NIX_DATA
Text GLabel 3500 4300 2    50   Input ~ 0
NIX_CLK
Wire Wire Line
	3350 4300 3500 4300
Wire Wire Line
	3350 4000 3500 4000
Wire Wire Line
	3350 3900 3500 3900
$Comp
L power:+5V #PWR0101
U 1 1 5F1E1656
P 3500 4100
F 0 "#PWR0101" H 3500 3950 50  0001 C CNN
F 1 "+5V" V 3515 4228 50  0000 L CNN
F 2 "" H 3500 4100 50  0001 C CNN
F 3 "" H 3500 4100 50  0001 C CNN
	1    3500 4100
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 5F1E5BAE
P 3500 4400
F 0 "#PWR0103" H 3500 4250 50  0001 C CNN
F 1 "+5V" V 3515 4528 50  0000 L CNN
F 2 "" H 3500 4400 50  0001 C CNN
F 3 "" H 3500 4400 50  0001 C CNN
	1    3500 4400
	0    1    1    0   
$EndComp
Wire Wire Line
	3350 4400 3500 4400
$Comp
L power:+5V #PWR0104
U 1 1 5F211DF5
P 650 7100
F 0 "#PWR0104" H 650 6950 50  0001 C CNN
F 1 "+5V" H 665 7273 50  0000 C CNN
F 2 "" H 650 7100 50  0001 C CNN
F 3 "" H 650 7100 50  0001 C CNN
	1    650  7100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5F2122B0
P 650 7500
F 0 "#PWR0105" H 650 7250 50  0001 C CNN
F 1 "GND" H 655 7327 50  0000 C CNN
F 2 "" H 650 7500 50  0001 C CNN
F 3 "" H 650 7500 50  0001 C CNN
	1    650  7500
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 5F212F41
P 650 7300
F 0 "C1" H 742 7346 50  0000 L CNN
F 1 "100n" H 742 7255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 650 7300 50  0001 C CNN
F 3 "~" H 650 7300 50  0001 C CNN
	1    650  7300
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5F214283
P 1050 7300
F 0 "C2" H 1142 7346 50  0000 L CNN
F 1 "100n" H 1142 7255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1050 7300 50  0001 C CNN
F 3 "~" H 1050 7300 50  0001 C CNN
	1    1050 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  7100 650  7150
Wire Wire Line
	650  7150 1050 7150
Wire Wire Line
	1050 7150 1050 7200
Connection ~ 650  7150
Wire Wire Line
	650  7150 650  7200
Wire Wire Line
	650  7500 650  7450
Wire Wire Line
	650  7450 1050 7450
Wire Wire Line
	1050 7450 1050 7400
Connection ~ 650  7450
Wire Wire Line
	650  7450 650  7400
$Comp
L power:GND #PWR0106
U 1 1 5F54A33E
P 6800 5000
F 0 "#PWR0106" H 6800 4750 50  0001 C CNN
F 1 "GND" H 6805 4827 50  0000 C CNN
F 2 "" H 6800 5000 50  0001 C CNN
F 3 "" H 6800 5000 50  0001 C CNN
	1    6800 5000
	1    0    0    -1  
$EndComp
Text GLabel 6850 4000 2    50   Input ~ 0
NIX_LE
Text GLabel 6850 4300 2    50   Input ~ 0
NIX_CLK
Wire Wire Line
	6700 4200 6800 4200
Wire Wire Line
	6700 4300 6850 4300
Wire Wire Line
	6700 4000 6850 4000
$Comp
L power:+5V #PWR0107
U 1 1 5F54A366
P 6850 4100
F 0 "#PWR0107" H 6850 3950 50  0001 C CNN
F 1 "+5V" V 6865 4228 50  0000 L CNN
F 2 "" H 6850 4100 50  0001 C CNN
F 3 "" H 6850 4100 50  0001 C CNN
	1    6850 4100
	0    1    1    0   
$EndComp
Wire Wire Line
	6850 4100 6700 4100
Wire Wire Line
	6700 3800 6850 3800
$Comp
L power:+5V #PWR0109
U 1 1 5F54A37C
P 6850 4400
F 0 "#PWR0109" H 6850 4250 50  0001 C CNN
F 1 "+5V" V 6865 4528 50  0000 L CNN
F 2 "" H 6850 4400 50  0001 C CNN
F 3 "" H 6850 4400 50  0001 C CNN
	1    6850 4400
	0    1    1    0   
$EndComp
Wire Wire Line
	6700 4400 6850 4400
Wire Wire Line
	3750 5400 7450 5400
Wire Wire Line
	6700 3900 7450 3900
Text Label 1000 3300 0    50   ~ 0
N1_4
Text Label 1000 3400 0    50   ~ 0
N1_5
Text Label 1000 3500 0    50   ~ 0
N1_6
Text Label 1000 3600 0    50   ~ 0
N1_7
Text Label 1000 3700 0    50   ~ 0
N1_8
Text Label 1000 3800 0    50   ~ 0
N1_9
Text Label 1000 3900 0    50   ~ 0
N1_0
Text Label 1000 4000 0    50   ~ 0
N1_R
Text Label 1000 4100 0    50   ~ 0
N1_L
Text Label 1000 4200 0    50   ~ 0
N1_1
Text Label 1000 4300 0    50   ~ 0
N1_2
Text Label 1000 4400 0    50   ~ 0
N1_3
NoConn ~ 400  4550
NoConn ~ 100  3600
$Comp
L HV_Shift_Register:HV5530 U1
U 1 1 5F15D56D
P 1150 2700
F 0 "U1" H 2250 3087 60  0000 C CNN
F 1 "HV5530" H 2250 2981 60  0000 C CNN
F 2 "Package_QFP:PQFP-44_10x10mm_P0.8mm" H 2250 2940 60  0001 C CNN
F 3 "" H 1150 2700 60  0000 C CNN
	1    1150 2700
	1    0    0    -1  
$EndComp
Text Label 3500 3200 0    50   ~ 0
N2_9
Text Label 3500 3300 0    50   ~ 0
N2_8
$Comp
L nixies-us:IN-14 N1
U 1 1 5F163085
P 1450 1300
F 0 "N1" V 1800 1500 45  0000 R CNN
F 1 "IN-14" H 1450 1300 45  0001 L BNN
F 2 "Nixies:IN-14" H 1480 1450 20  0001 C CNN
F 3 "" H 1450 1300 50  0001 C CNN
	1    1450 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 900  950  900 
Text Label 950  900  0    50   ~ 0
N1_1
Wire Wire Line
	1150 1000 950  1000
Text Label 950  1000 0    50   ~ 0
N1_2
Wire Wire Line
	1150 1100 950  1100
Text Label 950  1100 0    50   ~ 0
N1_3
Wire Wire Line
	1150 1200 950  1200
Text Label 950  1200 0    50   ~ 0
N1_4
Wire Wire Line
	1150 1300 950  1300
Text Label 950  1300 0    50   ~ 0
N1_5
Wire Wire Line
	1150 1400 950  1400
Text Label 950  1400 0    50   ~ 0
N1_6
Wire Wire Line
	1150 1500 950  1500
Text Label 950  1500 0    50   ~ 0
N1_7
Wire Wire Line
	1150 1600 950  1600
Text Label 950  1600 0    50   ~ 0
N1_8
Wire Wire Line
	1150 1700 950  1700
Text Label 950  1700 0    50   ~ 0
N1_9
Wire Wire Line
	1150 1800 950  1800
Text Label 950  1800 0    50   ~ 0
N1_0
Wire Wire Line
	2050 900  1850 900 
Text Label 1850 900  0    50   ~ 0
N1_L
Wire Wire Line
	2050 1800 1850 1800
Text Label 1850 1800 0    50   ~ 0
N1_R
Text GLabel 2100 1400 2    50   Input ~ 0
170V
$Comp
L Device:R_Small R1
U 1 1 5F5BC5A3
P 1950 1400
F 0 "R1" V 1754 1400 50  0000 C CNN
F 1 "10k" V 1845 1400 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 1950 1400 50  0001 C CNN
F 3 "~" H 1950 1400 50  0001 C CNN
	1    1950 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	2050 1400 2100 1400
$Comp
L nixies-us:IN-14 N2
U 1 1 5F5C0787
P 3100 1300
F 0 "N2" V 3450 1500 45  0000 R CNN
F 1 "IN-14" H 3100 1300 45  0001 L BNN
F 2 "Nixies:IN-14" H 3130 1450 20  0001 C CNN
F 3 "" H 3100 1300 50  0001 C CNN
	1    3100 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 900  2600 900 
Text Label 2600 900  0    50   ~ 0
N2_1
Wire Wire Line
	2800 1000 2600 1000
Text Label 2600 1000 0    50   ~ 0
N2_2
Wire Wire Line
	2800 1100 2600 1100
Text Label 2600 1100 0    50   ~ 0
N2_3
Wire Wire Line
	2800 1200 2600 1200
Text Label 2600 1200 0    50   ~ 0
N2_4
Wire Wire Line
	2800 1300 2600 1300
Text Label 2600 1300 0    50   ~ 0
N2_5
Wire Wire Line
	2800 1400 2600 1400
Text Label 2600 1400 0    50   ~ 0
N2_6
Wire Wire Line
	2800 1500 2600 1500
Text Label 2600 1500 0    50   ~ 0
N2_7
Wire Wire Line
	2800 1600 2600 1600
Text Label 2600 1600 0    50   ~ 0
N2_8
Wire Wire Line
	2800 1700 2600 1700
Text Label 2600 1700 0    50   ~ 0
N2_9
Wire Wire Line
	2800 1800 2600 1800
Text Label 2600 1800 0    50   ~ 0
N2_0
Wire Wire Line
	3700 900  3500 900 
Text Label 3500 900  0    50   ~ 0
N2_L
Wire Wire Line
	3700 1800 3500 1800
Text Label 3500 1800 0    50   ~ 0
N2_R
Text GLabel 3750 1400 2    50   Input ~ 0
170V
$Comp
L Device:R_Small R2
U 1 1 5F5C07AA
P 3600 1400
F 0 "R2" V 3404 1400 50  0000 C CNN
F 1 "10k" V 3495 1400 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3600 1400 50  0001 C CNN
F 3 "~" H 3600 1400 50  0001 C CNN
	1    3600 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	3700 1400 3750 1400
$Comp
L nixies-us:IN-14 N3
U 1 1 5F5C7EA2
P 4750 1300
F 0 "N3" V 5100 1500 45  0000 R CNN
F 1 "IN-14" H 4750 1300 45  0001 L BNN
F 2 "Nixies:IN-14" H 4780 1450 20  0001 C CNN
F 3 "" H 4750 1300 50  0001 C CNN
	1    4750 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 900  4250 900 
Text Label 4250 900  0    50   ~ 0
N3_1
Wire Wire Line
	4450 1000 4250 1000
Text Label 4250 1000 0    50   ~ 0
N3_2
Wire Wire Line
	4450 1100 4250 1100
Text Label 4250 1100 0    50   ~ 0
N3_3
Wire Wire Line
	4450 1200 4250 1200
Text Label 4250 1200 0    50   ~ 0
N3_4
Wire Wire Line
	4450 1300 4250 1300
Text Label 4250 1300 0    50   ~ 0
N3_5
Wire Wire Line
	4450 1400 4250 1400
Text Label 4250 1400 0    50   ~ 0
N3_6
Wire Wire Line
	4450 1500 4250 1500
Text Label 4250 1500 0    50   ~ 0
N3_7
Wire Wire Line
	4450 1600 4250 1600
Text Label 4250 1600 0    50   ~ 0
N3_8
Wire Wire Line
	4450 1700 4250 1700
Text Label 4250 1700 0    50   ~ 0
N3_9
Wire Wire Line
	4450 1800 4250 1800
Text Label 4250 1800 0    50   ~ 0
N3_0
Wire Wire Line
	5350 900  5150 900 
Text Label 5150 900  0    50   ~ 0
N3_L
Wire Wire Line
	5350 1800 5150 1800
Text Label 5150 1800 0    50   ~ 0
N3_R
Text GLabel 5400 1400 2    50   Input ~ 0
170V
$Comp
L Device:R_Small R3
U 1 1 5F5C7EC5
P 5250 1400
F 0 "R3" V 5054 1400 50  0000 C CNN
F 1 "10k" V 5145 1400 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 5250 1400 50  0001 C CNN
F 3 "~" H 5250 1400 50  0001 C CNN
	1    5250 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	5350 1400 5400 1400
$Comp
L nixies-us:IN-14 N4
U 1 1 5F5CF5B2
P 6400 1300
F 0 "N4" V 6750 1500 45  0000 R CNN
F 1 "IN-14" H 6400 1300 45  0001 L BNN
F 2 "Nixies:IN-14" H 6430 1450 20  0001 C CNN
F 3 "" H 6400 1300 50  0001 C CNN
	1    6400 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 900  5900 900 
Text Label 5900 900  0    50   ~ 0
N4_1
Wire Wire Line
	6100 1000 5900 1000
Text Label 5900 1000 0    50   ~ 0
N4_2
Wire Wire Line
	6100 1100 5900 1100
Text Label 5900 1100 0    50   ~ 0
N4_3
Wire Wire Line
	6100 1200 5900 1200
Text Label 5900 1200 0    50   ~ 0
N4_4
Wire Wire Line
	6100 1300 5900 1300
Text Label 5900 1300 0    50   ~ 0
N4_5
Wire Wire Line
	6100 1400 5900 1400
Text Label 5900 1400 0    50   ~ 0
N4_6
Wire Wire Line
	6100 1500 5900 1500
Text Label 5900 1500 0    50   ~ 0
N4_7
Wire Wire Line
	6100 1600 5900 1600
Text Label 5900 1600 0    50   ~ 0
N4_8
Wire Wire Line
	6100 1700 5900 1700
Text Label 5900 1700 0    50   ~ 0
N4_9
Wire Wire Line
	6100 1800 5900 1800
Text Label 5900 1800 0    50   ~ 0
N4_0
Wire Wire Line
	7000 900  6800 900 
Text Label 6800 900  0    50   ~ 0
N4_L
Wire Wire Line
	7000 1800 6800 1800
Text Label 6800 1800 0    50   ~ 0
N4_R
Text GLabel 7050 1400 2    50   Input ~ 0
170V
$Comp
L Device:R_Small R4
U 1 1 5F5CF5D5
P 6900 1400
F 0 "R4" V 6704 1400 50  0000 C CNN
F 1 "10k" V 6795 1400 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 6900 1400 50  0001 C CNN
F 3 "~" H 6900 1400 50  0001 C CNN
	1    6900 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	7000 1400 7050 1400
Text Label 3700 3100 2    50   ~ 0
N2_0
Text Label 3700 3000 2    50   ~ 0
N2_R
Text Label 3700 2900 2    50   ~ 0
N2_L
Text Label 3700 2800 2    50   ~ 0
N2_1
Text Label 3700 2700 2    50   ~ 0
N2_2
Text Label 1000 2700 0    50   ~ 0
N2_3
Text Label 1000 2800 0    50   ~ 0
N2_4
Text Label 1000 2900 0    50   ~ 0
N2_5
Wire Wire Line
	3350 3300 3750 3300
Wire Wire Line
	3350 3200 3750 3200
Wire Wire Line
	4500 4000 4300 4000
Wire Wire Line
	4500 3900 4300 3900
Wire Wire Line
	4500 3800 4300 3800
Wire Wire Line
	4500 3700 4300 3700
Wire Wire Line
	4500 3600 4300 3600
Wire Wire Line
	4500 3500 4300 3500
Wire Wire Line
	4500 3400 4300 3400
Wire Wire Line
	4500 3300 4300 3300
Wire Wire Line
	4500 4400 4300 4400
Wire Wire Line
	4500 4300 4300 4300
Wire Wire Line
	4500 4200 4300 4200
Wire Wire Line
	4300 4100 4500 4100
Text Label 4350 4100 0    50   ~ 0
N3_L
Text Label 4350 4200 0    50   ~ 0
N3_1
Text Label 4350 4300 0    50   ~ 0
N3_2
Text Label 4350 4400 0    50   ~ 0
N3_3
Text Label 4350 3300 0    50   ~ 0
N3_4
Text Label 4350 3400 0    50   ~ 0
N3_5
Text Label 4350 3500 0    50   ~ 0
N3_6
Text Label 4350 3600 0    50   ~ 0
N3_7
Text Label 4350 3700 0    50   ~ 0
N3_8
Text Label 4350 3800 0    50   ~ 0
N3_9
Text Label 4350 3900 0    50   ~ 0
N3_0
Text Label 4350 4000 0    50   ~ 0
N3_R
Text Label 7050 2700 2    50   ~ 0
N4_2
Text Label 4350 2700 0    50   ~ 0
N4_3
Text Label 4350 2800 0    50   ~ 0
N4_4
Text Label 4350 2900 0    50   ~ 0
N4_5
Text Label 4350 3000 0    50   ~ 0
N4_6
Text Label 4350 3100 0    50   ~ 0
N4_7
Text Label 7050 3300 2    50   ~ 0
N4_8
Text Label 7050 3200 2    50   ~ 0
N4_9
Text Label 7050 3100 2    50   ~ 0
N4_0
Text Label 7050 3000 2    50   ~ 0
N4_R
Text Label 6850 2800 0    50   ~ 0
N4_1
Text Label 6850 2900 0    50   ~ 0
N4_L
Wire Wire Line
	6700 2900 7100 2900
Wire Wire Line
	6700 2800 7100 2800
Wire Wire Line
	1150 2900 950  2900
Wire Wire Line
	1150 2800 950  2800
Wire Wire Line
	1150 2700 950  2700
Wire Wire Line
	3350 2700 3750 2700
Wire Wire Line
	3350 2800 3750 2800
Wire Wire Line
	3350 2900 3750 2900
Wire Wire Line
	3350 3000 3750 3000
Wire Wire Line
	3350 3100 3750 3100
NoConn ~ 1150 3200
NoConn ~ 1150 4800
Wire Wire Line
	6700 3200 7100 3200
Wire Wire Line
	6700 3300 7100 3300
Wire Wire Line
	4500 3100 4300 3100
Wire Wire Line
	4500 3000 4300 3000
Wire Wire Line
	4500 2900 4300 2900
Wire Wire Line
	4500 2800 4300 2800
Wire Wire Line
	4500 2700 4300 2700
Wire Wire Line
	6700 2700 7100 2700
$Comp
L power:GND #PWR0110
U 1 1 5F1C9D78
P 3450 5000
F 0 "#PWR0110" H 3450 4750 50  0001 C CNN
F 1 "GND" H 3455 4827 50  0000 C CNN
F 2 "" H 3450 5000 50  0001 C CNN
F 3 "" H 3450 5000 50  0001 C CNN
	1    3450 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 4200 3450 4200
Text GLabel 6850 3800 2    50   Input ~ 0
NIX_DIM
Wire Wire Line
	3350 3800 3500 3800
Text GLabel 3500 3800 2    50   Input ~ 0
NIX_DIM
$Comp
L Device:Lamp_Neon NE1
U 1 1 5F6E6234
P 8650 1250
F 0 "NE1" H 8778 1296 50  0000 L CNN
F 1 "Lamp_Neon" H 8778 1205 50  0000 L CNN
F 2 "Nixies:Colon" V 8650 1350 50  0001 C CNN
F 3 "~" V 8650 1350 50  0001 C CNN
	1    8650 1250
	0    -1   -1   0   
$EndComp
Text Label 9100 1250 2    50   ~ 0
N_DOT
Wire Wire Line
	8850 1250 9100 1250
Text GLabel 8200 1250 0    50   Input ~ 0
170V
$Comp
L Device:R_Small R10
U 1 1 5F6FBFC0
P 8350 1250
F 0 "R10" V 8154 1250 50  0000 C CNN
F 1 "100k" V 8245 1250 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 8350 1250 50  0001 C CNN
F 3 "~" H 8350 1250 50  0001 C CNN
	1    8350 1250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8250 1250 8200 1250
Text Label 3700 3400 2    50   ~ 0
N_DOT
Wire Wire Line
	1150 3100 950  3100
Wire Wire Line
	1150 3000 950  3000
Text Label 1000 3000 0    50   ~ 0
N2_6
Text Label 1000 3100 0    50   ~ 0
N2_7
NoConn ~ 3350 3600
NoConn ~ 1150 4600
NoConn ~ 1150 4700
$Comp
L HV_Shift_Register:HV5530 U2
U 1 1 5F664441
P 4500 2700
F 0 "U2" H 5600 3087 60  0000 C CNN
F 1 "HV5530" H 5600 2981 60  0000 C CNN
F 2 "Package_QFP:PQFP-44_10x10mm_P0.8mm" H 5600 2940 60  0001 C CNN
F 3 "" H 4500 2700 60  0000 C CNN
	1    4500 2700
	1    0    0    -1  
$EndComp
NoConn ~ 4500 4600
NoConn ~ 4500 4700
NoConn ~ 4500 4800
Wire Wire Line
	6700 3100 7100 3100
Wire Wire Line
	6700 3000 7100 3000
NoConn ~ 6700 3500
NoConn ~ 6700 3600
NoConn ~ 4500 3200
NoConn ~ 4500 4500
Wire Wire Line
	3350 3400 3750 3400
NoConn ~ 1150 4500
NoConn ~ 3350 3500
Wire Wire Line
	3350 4100 3500 4100
Wire Wire Line
	3350 4800 3750 4800
Wire Wire Line
	3450 4200 3450 5000
Wire Wire Line
	3750 4800 3750 5400
NoConn ~ 6700 3400
Wire Wire Line
	7450 3900 7450 5400
NoConn ~ 6700 4800
Wire Wire Line
	6800 4200 6800 5000
$EndSCHEMATC
