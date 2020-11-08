EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GND #PWR?
U 1 1 5F57D9B2
P 2150 3150
AR Path="/5F8C807E/5F57D9B2" Ref="#PWR?"  Part="1" 
AR Path="/5F57D9B2" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F57D9B2" Ref="#PWR0102"  Part="1" 
AR Path="/5F57DBA0/5F57D9B2" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5F57D9B2" Ref="#PWR?"  Part="1" 
F 0 "#PWR0102" H 2150 2900 50  0001 C CNN
F 1 "GND" H 2155 2977 50  0000 C CNN
F 2 "" H 2150 3150 50  0001 C CNN
F 3 "" H 2150 3150 50  0001 C CNN
	1    2150 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 3100 2150 3150
$Comp
L power:+5V #PWR?
U 1 1 5F57D9B9
P 2150 1250
AR Path="/5F8C807E/5F57D9B9" Ref="#PWR?"  Part="1" 
AR Path="/5F57D9B9" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F57D9B9" Ref="#PWR0108"  Part="1" 
AR Path="/5F57DBA0/5F57D9B9" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5F57D9B9" Ref="#PWR?"  Part="1" 
F 0 "#PWR0108" H 2150 1100 50  0001 C CNN
F 1 "+5V" V 2165 1378 50  0000 L CNN
F 2 "" H 2150 1250 50  0001 C CNN
F 3 "" H 2150 1250 50  0001 C CNN
	1    2150 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 1250 2150 1300
$Comp
L MCU_Microchip_ATtiny:ATtiny1606-S U3
U 1 1 5F625909
P 2150 2200
AR Path="/5F57C9A4/5F625909" Ref="U3"  Part="1" 
AR Path="/5F63C067/5F625909" Ref="U?"  Part="1" 
F 0 "U3" H 1800 3050 50  0000 C CNN
F 1 "ATtiny1606-S" H 2450 3050 50  0000 C CNN
F 2 "Package_SO:SOIC-20W_7.5x12.8mm_P1.27mm" H 2150 2200 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATtiny806_1606_Data_Sheet_40002029A.pdf" H 2150 2200 50  0001 C CNN
	1    2150 2200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F642967
P 750 7000
AR Path="/5F8C807E/5F642967" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F642967" Ref="#PWR0111"  Part="1" 
AR Path="/5F63C067/5F642967" Ref="#PWR?"  Part="1" 
F 0 "#PWR0111" H 750 6850 50  0001 C CNN
F 1 "+5V" H 765 7173 50  0000 C CNN
F 2 "" H 750 7000 50  0001 C CNN
F 3 "" H 750 7000 50  0001 C CNN
	1    750  7000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F642968
P 750 7400
AR Path="/5F8C807E/5F642968" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F642968" Ref="#PWR0112"  Part="1" 
AR Path="/5F63C067/5F642968" Ref="#PWR?"  Part="1" 
F 0 "#PWR0112" H 750 7150 50  0001 C CNN
F 1 "GND" H 755 7227 50  0000 C CNN
F 2 "" H 750 7400 50  0001 C CNN
F 3 "" H 750 7400 50  0001 C CNN
	1    750  7400
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5F642969
P 750 7200
AR Path="/5F8C807E/5F642969" Ref="C?"  Part="1" 
AR Path="/5F57C9A4/5F642969" Ref="C3"  Part="1" 
AR Path="/5F63C067/5F642969" Ref="C?"  Part="1" 
F 0 "C3" H 842 7246 50  0000 L CNN
F 1 "100n" H 842 7155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 750 7200 50  0001 C CNN
F 3 "~" H 750 7200 50  0001 C CNN
	1    750  7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 7350 1150 7300
Wire Wire Line
	750  7350 750  7300
Wire Wire Line
	750  7400 750  7350
Connection ~ 750  7350
Wire Wire Line
	750  7350 1150 7350
Wire Wire Line
	1150 7050 1150 7100
Wire Wire Line
	750  7050 750  7100
Wire Wire Line
	750  7000 750  7050
Connection ~ 750  7050
Wire Wire Line
	750  7050 1150 7050
Wire Wire Line
	2750 2000 2850 2000
Text GLabel 2850 2000 2    50   Input ~ 0
NIX_DIM
Wire Wire Line
	2750 2100 2850 2100
Text GLabel 2850 2100 2    50   Input ~ 0
NIX_DATA
Wire Wire Line
	2750 2200 2850 2200
Text GLabel 2850 2200 2    50   Input ~ 0
NIX_LE
Wire Wire Line
	2750 2900 2850 2900
Text GLabel 2850 2900 2    50   Input ~ 0
NIX_CLK
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5F631460
P 8400 3550
AR Path="/5F57C9A4/5F631460" Ref="J1"  Part="1" 
AR Path="/5F63C067/5F631460" Ref="J?"  Part="1" 
F 0 "J1" H 8480 3542 50  0000 L CNN
F 1 "UPDI" H 8480 3451 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8400 3550 50  0001 C CNN
F 3 "~" H 8400 3550 50  0001 C CNN
	1    8400 3550
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5F64296A
P 8400 4150
AR Path="/5F57C9A4/5F64296A" Ref="J2"  Part="1" 
AR Path="/5F63C067/5F64296A" Ref="J?"  Part="1" 
F 0 "J2" H 8480 4192 50  0000 L CNN
F 1 "UART" H 8480 4101 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8400 4150 50  0001 C CNN
F 3 "~" H 8400 4150 50  0001 C CNN
	1    8400 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F635583
P 8200 4300
AR Path="/5F8C807E/5F635583" Ref="#PWR?"  Part="1" 
AR Path="/5F635583" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F635583" Ref="#PWR0113"  Part="1" 
AR Path="/5F57DBA0/5F635583" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5F635583" Ref="#PWR?"  Part="1" 
F 0 "#PWR0113" H 8200 4050 50  0001 C CNN
F 1 "GND" H 8205 4127 50  0000 C CNN
F 2 "" H 8200 4300 50  0001 C CNN
F 3 "" H 8200 4300 50  0001 C CNN
	1    8200 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 4250 8200 4300
$Comp
L power:GND #PWR?
U 1 1 5F635B26
P 8200 3700
AR Path="/5F8C807E/5F635B26" Ref="#PWR?"  Part="1" 
AR Path="/5F635B26" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F635B26" Ref="#PWR0114"  Part="1" 
AR Path="/5F57DBA0/5F635B26" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5F635B26" Ref="#PWR?"  Part="1" 
F 0 "#PWR0114" H 8200 3450 50  0001 C CNN
F 1 "GND" H 8205 3527 50  0000 C CNN
F 2 "" H 8200 3700 50  0001 C CNN
F 3 "" H 8200 3700 50  0001 C CNN
	1    8200 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 3650 8200 3700
Wire Wire Line
	2750 2600 2850 2600
Text GLabel 2850 2600 2    50   Input ~ 0
UART_TxD
Wire Wire Line
	2750 2700 2850 2700
Text GLabel 2850 2700 2    50   Input ~ 0
NMEA_RxD
Text GLabel 8100 4150 0    50   Input ~ 0
UART_TxD
Wire Wire Line
	8100 4150 8200 4150
Wire Wire Line
	2750 1500 2850 1500
Text GLabel 2850 1500 2    50   Input ~ 0
UPDI
Wire Wire Line
	8150 3550 8200 3550
$Comp
L Device:R_Small R5
U 1 1 5F63878F
P 8050 3550
AR Path="/5F57C9A4/5F63878F" Ref="R5"  Part="1" 
AR Path="/5F63C067/5F63878F" Ref="R?"  Part="1" 
F 0 "R5" V 7854 3550 50  0000 C CNN
F 1 "470" V 7945 3550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8050 3550 50  0001 C CNN
F 3 "~" H 8050 3550 50  0001 C CNN
	1    8050 3550
	0    1    1    0   
$EndComp
Text GLabel 7850 3550 0    50   Input ~ 0
UPDI
Wire Wire Line
	7850 3550 7950 3550
Wire Wire Line
	1550 2600 1450 2600
$Comp
L Connector_Generic:Conn_01x06 J3
U 1 1 5F66ADDC
P 8400 5050
AR Path="/5F57C9A4/5F66ADDC" Ref="J3"  Part="1" 
AR Path="/5F63C067/5F66ADDC" Ref="J?"  Part="1" 
AR Path="/5F645C82/5F66ADDC" Ref="J?"  Part="1" 
F 0 "J3" H 8480 5092 50  0000 L CNN
F 1 "NMEA" H 8480 5001 50  0000 L CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_1x06_P1.27mm_Vertical" H 8400 5050 50  0001 C CNN
F 3 "~" H 8400 5050 50  0001 C CNN
	1    8400 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F66ADE2
P 7600 5450
AR Path="/5F8C807E/5F66ADE2" Ref="#PWR?"  Part="1" 
AR Path="/5F66ADE2" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F66ADE2" Ref="#PWR0117"  Part="1" 
AR Path="/5F57DBA0/5F66ADE2" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5F66ADE2" Ref="#PWR?"  Part="1" 
AR Path="/5F645C82/5F66ADE2" Ref="#PWR?"  Part="1" 
F 0 "#PWR0117" H 7600 5200 50  0001 C CNN
F 1 "GND" H 7605 5277 50  0000 C CNN
F 2 "" H 7600 5450 50  0001 C CNN
F 3 "" H 7600 5450 50  0001 C CNN
	1    7600 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 4950 8200 4950
$Comp
L power:+5V #PWR?
U 1 1 5F66ADEB
P 7950 4750
AR Path="/5F8C807E/5F66ADEB" Ref="#PWR?"  Part="1" 
AR Path="/5F66ADEB" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F66ADEB" Ref="#PWR0118"  Part="1" 
AR Path="/5F57DBA0/5F66ADEB" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5F66ADEB" Ref="#PWR?"  Part="1" 
AR Path="/5F645C82/5F66ADEB" Ref="#PWR?"  Part="1" 
F 0 "#PWR0118" H 7950 4600 50  0001 C CNN
F 1 "+5V" V 7965 4878 50  0000 L CNN
F 2 "" H 7950 4750 50  0001 C CNN
F 3 "" H 7950 4750 50  0001 C CNN
	1    7950 4750
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C6
U 1 1 5F68340D
P 4100 4750
F 0 "C6" H 4192 4796 50  0000 L CNN
F 1 "330n" H 4192 4705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4100 4750 50  0001 C CNN
F 3 "~" H 4100 4750 50  0001 C CNN
	1    4100 4750
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C7
U 1 1 5F685524
P 5200 4750
F 0 "C7" H 5292 4796 50  0000 L CNN
F 1 "100n" H 5292 4705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5200 4750 50  0001 C CNN
F 3 "~" H 5200 4750 50  0001 C CNN
	1    5200 4750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F686EE2
P 4650 5050
AR Path="/5F8C807E/5F686EE2" Ref="#PWR?"  Part="1" 
AR Path="/5F686EE2" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F686EE2" Ref="#PWR0123"  Part="1" 
AR Path="/5F57DBA0/5F686EE2" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5F686EE2" Ref="#PWR?"  Part="1" 
F 0 "#PWR0123" H 4650 4800 50  0001 C CNN
F 1 "GND" H 4655 4877 50  0000 C CNN
F 2 "" H 4650 5050 50  0001 C CNN
F 3 "" H 4650 5050 50  0001 C CNN
	1    4650 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 4650 5200 4450
Wire Wire Line
	5200 4450 4950 4450
Wire Wire Line
	4100 4650 4100 4450
Wire Wire Line
	3400 4350 3400 4450
Connection ~ 5200 4450
$Comp
L power:+5V #PWR?
U 1 1 5F69255D
P 5200 4350
AR Path="/5F8C807E/5F69255D" Ref="#PWR?"  Part="1" 
AR Path="/5F69255D" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F69255D" Ref="#PWR0124"  Part="1" 
AR Path="/5F57DBA0/5F69255D" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5F69255D" Ref="#PWR?"  Part="1" 
F 0 "#PWR0124" H 5200 4200 50  0001 C CNN
F 1 "+5V" V 5215 4478 50  0000 L CNN
F 2 "" H 5200 4350 50  0001 C CNN
F 3 "" H 5200 4350 50  0001 C CNN
	1    5200 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 4750 4650 4950
Wire Wire Line
	4100 4850 4100 4950
Wire Wire Line
	4100 4950 4650 4950
Connection ~ 4650 4950
Wire Wire Line
	4650 4950 4650 5050
Wire Wire Line
	4650 4950 5200 4950
Wire Wire Line
	5200 4950 5200 4850
$Comp
L power:GND #PWR?
U 1 1 5F6A2A76
P 9950 4650
AR Path="/5F8C807E/5F6A2A76" Ref="#PWR?"  Part="1" 
AR Path="/5F6A2A76" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F6A2A76" Ref="#PWR0125"  Part="1" 
AR Path="/5F57DBA0/5F6A2A76" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5F6A2A76" Ref="#PWR?"  Part="1" 
F 0 "#PWR0125" H 9950 4400 50  0001 C CNN
F 1 "GND" H 9955 4477 50  0000 C CNN
F 2 "" H 9950 4650 50  0001 C CNN
F 3 "" H 9950 4650 50  0001 C CNN
	1    9950 4650
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 5F6A2A6C
P 10150 3550
AR Path="/5F57C9A4/5F6A2A6C" Ref="J4"  Part="1" 
AR Path="/5F63C067/5F6A2A6C" Ref="J?"  Part="1" 
F 0 "J4" H 10230 3542 50  0000 L CNN
F 1 "Vin" H 10230 3451 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 10150 3550 50  0001 C CNN
F 3 "~" H 10150 3550 50  0001 C CNN
	1    10150 3550
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 5F6A9905
P 9600 3500
AR Path="/5F8C807E/5F6A9905" Ref="#PWR?"  Part="1" 
AR Path="/5F6A9905" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F6A9905" Ref="#PWR0126"  Part="1" 
AR Path="/5F57DBA0/5F6A9905" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5F6A9905" Ref="#PWR?"  Part="1" 
F 0 "#PWR0126" H 9600 3350 50  0001 C CNN
F 1 "+12V" V 9615 3628 50  0000 L CNN
F 2 "" H 9600 3500 50  0001 C CNN
F 3 "" H 9600 3500 50  0001 C CNN
	1    9600 3500
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 5F693F88
P 3400 4350
AR Path="/5F8C807E/5F693F88" Ref="#PWR?"  Part="1" 
AR Path="/5F693F88" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F693F88" Ref="#PWR0127"  Part="1" 
AR Path="/5F57DBA0/5F693F88" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5F693F88" Ref="#PWR?"  Part="1" 
F 0 "#PWR0127" H 3400 4200 50  0001 C CNN
F 1 "+12V" V 3415 4478 50  0000 L CNN
F 2 "" H 3400 4350 50  0001 C CNN
F 3 "" H 3400 4350 50  0001 C CNN
	1    3400 4350
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 5F6B75B9
P 9950 4350
AR Path="/5F8C807E/5F6B75B9" Ref="#PWR?"  Part="1" 
AR Path="/5F6B75B9" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F6B75B9" Ref="#PWR0128"  Part="1" 
AR Path="/5F57DBA0/5F6B75B9" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5F6B75B9" Ref="#PWR?"  Part="1" 
F 0 "#PWR0128" H 9950 4200 50  0001 C CNN
F 1 "+12V" V 9965 4478 50  0000 L CNN
F 2 "" H 9950 4350 50  0001 C CNN
F 3 "" H 9950 4350 50  0001 C CNN
	1    9950 4350
	1    0    0    -1  
$EndComp
Text GLabel 9750 4500 0    50   Input ~ 0
170V
Wire Wire Line
	9950 4600 9950 4650
$Comp
L Device:C_Small C?
U 1 1 5F6CCED4
P 1150 7200
AR Path="/5F8C807E/5F6CCED4" Ref="C?"  Part="1" 
AR Path="/5F57C9A4/5F6CCED4" Ref="C8"  Part="1" 
AR Path="/5F63C067/5F6CCED4" Ref="C?"  Part="1" 
F 0 "C8" H 1242 7246 50  0000 L CNN
F 1 "10u" H 1242 7155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1150 7200 50  0001 C CNN
F 3 "~" H 1150 7200 50  0001 C CNN
	1    1150 7200
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H4
U 1 1 5F72DA2D
P 4200 6750
F 0 "H4" V 4200 6950 50  0000 C CNN
F 1 "Hole" V 4200 7150 50  0000 C CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5_Pad_Via" H 4200 6750 50  0001 C CNN
F 3 "~" H 4200 6750 50  0001 C CNN
	1    4200 6750
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 5F72E39D
P 3900 6750
F 0 "H2" V 3900 6950 50  0000 C CNN
F 1 "Hole" V 3900 7150 50  0000 C CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5_Pad_Via" H 3900 6750 50  0001 C CNN
F 3 "~" H 3900 6750 50  0001 C CNN
	1    3900 6750
	0    -1   -1   0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H3
U 1 1 5F730333
P 4200 6550
F 0 "H3" V 4200 6750 50  0000 C CNN
F 1 "Hole" V 4200 6950 50  0000 C CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5_Pad_Via" H 4200 6550 50  0001 C CNN
F 3 "~" H 4200 6550 50  0001 C CNN
	1    4200 6550
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 5F73033D
P 3900 6550
F 0 "H1" V 3900 6750 50  0000 C CNN
F 1 "Hole" V 3900 6950 50  0000 C CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5_Pad_Via" H 3900 6550 50  0001 C CNN
F 3 "~" H 3900 6550 50  0001 C CNN
	1    3900 6550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4000 6550 4050 6550
Wire Wire Line
	4050 6750 4000 6750
Connection ~ 4050 6550
Wire Wire Line
	4050 6550 4100 6550
Wire Wire Line
	4050 6750 4100 6750
Connection ~ 4050 6750
Wire Wire Line
	4050 6550 4050 6750
$Comp
L power:GND #PWR?
U 1 1 5F743FCA
P 4050 6800
AR Path="/5F8C807E/5F743FCA" Ref="#PWR?"  Part="1" 
AR Path="/5F743FCA" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F743FCA" Ref="#PWR0129"  Part="1" 
AR Path="/5F57DBA0/5F743FCA" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5F743FCA" Ref="#PWR?"  Part="1" 
F 0 "#PWR0129" H 4050 6550 50  0001 C CNN
F 1 "GND" H 4055 6627 50  0000 C CNN
F 2 "" H 4050 6800 50  0001 C CNN
F 3 "" H 4050 6800 50  0001 C CNN
	1    4050 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 6750 4050 6800
$Comp
L power:GND #PWR?
U 1 1 5F9BF234
P 9600 3700
AR Path="/5F8C807E/5F9BF234" Ref="#PWR?"  Part="1" 
AR Path="/5F9BF234" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5F9BF234" Ref="#PWR0130"  Part="1" 
AR Path="/5F57DBA0/5F9BF234" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5F9BF234" Ref="#PWR?"  Part="1" 
F 0 "#PWR0130" H 9600 3450 50  0001 C CNN
F 1 "GND" H 9605 3527 50  0000 C CNN
F 2 "" H 9600 3700 50  0001 C CNN
F 3 "" H 9600 3700 50  0001 C CNN
	1    9600 3700
	1    0    0    -1  
$EndComp
NoConn ~ 2750 2800
NoConn ~ 2750 1800
NoConn ~ 1550 2700
NoConn ~ 1550 2500
NoConn ~ 1550 2400
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5F9D98C2
P 9950 3500
F 0 "#FLG0101" H 9950 3575 50  0001 C CNN
F 1 "PWR_FLAG" H 9950 3673 50  0000 C CNN
F 2 "" H 9950 3500 50  0001 C CNN
F 3 "~" H 9950 3500 50  0001 C CNN
	1    9950 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9950 3550 9950 3500
Wire Wire Line
	9950 3550 9600 3550
Wire Wire Line
	9600 3550 9600 3500
Connection ~ 9950 3550
Wire Wire Line
	9600 3700 9600 3650
Wire Wire Line
	9600 3650 9950 3650
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5F9EF2B6
P 9950 3700
F 0 "#FLG0102" H 9950 3775 50  0001 C CNN
F 1 "PWR_FLAG" H 9950 3873 50  0000 C CNN
F 2 "" H 9950 3700 50  0001 C CNN
F 3 "~" H 9950 3700 50  0001 C CNN
	1    9950 3700
	-1   0    0    1   
$EndComp
Wire Wire Line
	9950 3650 9950 3700
Connection ~ 9950 3650
Wire Wire Line
	9950 4400 9950 4350
Wire Wire Line
	5200 4350 5200 4450
$Comp
L Connector_Generic:Conn_01x03 REG1
U 1 1 5F7A5348
P 10150 4500
AR Path="/5F57C9A4/5F7A5348" Ref="REG1"  Part="1" 
AR Path="/5F63C067/5F7A5348" Ref="J?"  Part="1" 
F 0 "REG1" H 10230 4542 50  0000 L CNN
F 1 "HVReg" H 10230 4451 50  0000 L CNN
F 2 "Nixies:NCH8200HV" H 10150 4500 50  0001 C CNN
F 3 "~" H 10150 4500 50  0001 C CNN
	1    10150 4500
	1    0    0    -1  
$EndComp
NoConn ~ 2750 1600
$Comp
L Device:Fuse_Small F2
U 1 1 5F7EA45C
P 3750 4450
F 0 "F2" H 3750 4635 50  0000 C CNN
F 1 "200mA" H 3750 4544 50  0000 C CNN
F 2 "Fuse:Fuse_0603_1608Metric" H 3750 4450 50  0001 C CNN
F 3 "~" H 3750 4450 50  0001 C CNN
	1    3750 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 4450 3650 4450
Wire Wire Line
	3850 4450 4100 4450
Text GLabel 1450 2600 0    50   Input ~ 0
NMEA_SYNC
Text GLabel 8150 5350 0    50   Input ~ 0
NMEA_SYNC
Text GLabel 7000 4900 0    50   Input ~ 0
NMEA_RxD
Wire Wire Line
	8200 5350 8150 5350
NoConn ~ 8200 4850
$Comp
L Device:R_Small R7
U 1 1 5FA68E9C
P 7950 4950
AR Path="/5F57C9A4/5FA68E9C" Ref="R7"  Part="1" 
AR Path="/5F63C067/5FA68E9C" Ref="R?"  Part="1" 
F 0 "R7" V 7754 4950 50  0000 C CNN
F 1 "100k" V 7845 4950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7950 4950 50  0001 C CNN
F 3 "~" H 7950 4950 50  0001 C CNN
	1    7950 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 5450 7600 5250
Wire Wire Line
	7600 5250 8200 5250
Wire Wire Line
	8100 4800 8100 4950
Wire Wire Line
	7950 4850 7950 4800
Wire Wire Line
	7950 4800 8100 4800
$Comp
L Device:R_Small R6
U 1 1 5FA77B0D
P 7100 4750
AR Path="/5F57C9A4/5FA77B0D" Ref="R6"  Part="1" 
AR Path="/5F63C067/5FA77B0D" Ref="R?"  Part="1" 
F 0 "R6" V 6904 4750 50  0000 C CNN
F 1 "10k" V 6995 4750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7100 4750 50  0001 C CNN
F 3 "~" H 7100 4750 50  0001 C CNN
	1    7100 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 5050 8200 5050
NoConn ~ 2750 2500
NoConn ~ 2750 2400
NoConn ~ 2750 1700
$Comp
L Transistor_BJT:S8050 Q1
U 1 1 5FA6306F
P 7200 5150
F 0 "Q1" H 7391 5196 50  0000 L CNN
F 1 "S8050" H 7391 5105 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7400 5075 50  0001 L CIN
F 3 "http://www.unisonic.com.tw/datasheet/S8050.pdf" H 7200 5150 50  0001 L CNN
	1    7200 5150
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_Small R8
U 1 1 5FA67166
P 7550 5150
AR Path="/5F57C9A4/5FA67166" Ref="R8"  Part="1" 
AR Path="/5F63C067/5FA67166" Ref="R?"  Part="1" 
F 0 "R8" V 7354 5150 50  0000 C CNN
F 1 "10k" V 7445 5150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7550 5150 50  0001 C CNN
F 3 "~" H 7550 5150 50  0001 C CNN
	1    7550 5150
	0    1    1    0   
$EndComp
Wire Wire Line
	7100 4900 7000 4900
$Comp
L power:GND #PWR?
U 1 1 5FA6D91E
P 7100 5400
AR Path="/5F8C807E/5FA6D91E" Ref="#PWR?"  Part="1" 
AR Path="/5FA6D91E" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5FA6D91E" Ref="#PWR0115"  Part="1" 
AR Path="/5F57DBA0/5FA6D91E" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5FA6D91E" Ref="#PWR?"  Part="1" 
AR Path="/5F645C82/5FA6D91E" Ref="#PWR?"  Part="1" 
F 0 "#PWR0115" H 7100 5150 50  0001 C CNN
F 1 "GND" H 7105 5227 50  0000 C CNN
F 2 "" H 7100 5400 50  0001 C CNN
F 3 "" H 7100 5400 50  0001 C CNN
	1    7100 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 5150 8200 5150
Wire Wire Line
	7450 5150 7400 5150
Wire Wire Line
	7100 4850 7100 4900
$Comp
L power:+5V #PWR?
U 1 1 5FA89842
P 7100 4600
AR Path="/5F8C807E/5FA89842" Ref="#PWR?"  Part="1" 
AR Path="/5FA89842" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5FA89842" Ref="#PWR0116"  Part="1" 
AR Path="/5F57DBA0/5FA89842" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5FA89842" Ref="#PWR?"  Part="1" 
AR Path="/5F645C82/5FA89842" Ref="#PWR?"  Part="1" 
F 0 "#PWR0116" H 7100 4450 50  0001 C CNN
F 1 "+5V" V 7115 4728 50  0000 L CNN
F 2 "" H 7100 4600 50  0001 C CNN
F 3 "" H 7100 4600 50  0001 C CNN
	1    7100 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 4600 7100 4650
Wire Wire Line
	7950 4750 7950 4800
Connection ~ 7950 4800
Wire Wire Line
	7100 5350 7100 5400
Connection ~ 7100 4900
Wire Wire Line
	7100 4900 7100 4950
Connection ~ 4100 4450
Wire Wire Line
	4100 4450 4350 4450
$Comp
L Regulator_Linear:LF50_TO252 U4
U 1 1 5FA94124
P 4650 4450
F 0 "U4" H 4650 4692 50  0000 C CNN
F 1 "L78M05ABDT-TR" H 4650 4601 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 4650 4675 50  0001 C CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/c4/0e/7e/2a/be/bc/4c/bd/CD00000546.pdf/files/CD00000546.pdf/jcr:content/translations/en.CD00000546.pdf" H 4650 4400 50  0001 C CNN
	1    4650 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 4500 9950 4500
Text GLabel 2850 2000 2    50   Input ~ 0
NIX_DIM
Text GLabel 2850 1900 2    50   Input ~ 0
TIME_ZONE
Wire Wire Line
	2750 1900 2850 1900
$Comp
L Connector_Generic:Conn_01x02 J5
U 1 1 5FB947CD
P 8400 2650
AR Path="/5F57C9A4/5FB947CD" Ref="J5"  Part="1" 
AR Path="/5F63C067/5FB947CD" Ref="J?"  Part="1" 
F 0 "J5" H 8480 2642 50  0000 L CNN
F 1 "TIME_ZONE" H 8480 2551 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8400 2650 50  0001 C CNN
F 3 "~" H 8400 2650 50  0001 C CNN
	1    8400 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FB947E7
P 8000 2750
AR Path="/5F8C807E/5FB947E7" Ref="#PWR?"  Part="1" 
AR Path="/5FB947E7" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5FB947E7" Ref="#PWR0119"  Part="1" 
AR Path="/5F57DBA0/5FB947E7" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5FB947E7" Ref="#PWR?"  Part="1" 
F 0 "#PWR0119" H 8000 2500 50  0001 C CNN
F 1 "GND" H 8005 2577 50  0000 C CNN
F 2 "" H 8000 2750 50  0001 C CNN
F 3 "" H 8000 2750 50  0001 C CNN
	1    8000 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 2750 8000 2750
$Comp
L Device:R_Small R9
U 1 1 5FB947F3
P 8000 2400
AR Path="/5F57C9A4/5FB947F3" Ref="R9"  Part="1" 
AR Path="/5F63C067/5FB947F3" Ref="R?"  Part="1" 
F 0 "R9" V 7804 2400 50  0000 C CNN
F 1 "100k" V 7895 2400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8000 2400 50  0001 C CNN
F 3 "~" H 8000 2400 50  0001 C CNN
	1    8000 2400
	-1   0    0    1   
$EndComp
Text GLabel 7850 2650 0    50   Input ~ 0
TIME_ZONE
Wire Wire Line
	7850 2650 8000 2650
Wire Wire Line
	8000 2500 8000 2650
Connection ~ 8000 2650
Wire Wire Line
	8000 2650 8200 2650
$Comp
L power:+5V #PWR?
U 1 1 5FB9E23E
P 8000 2250
AR Path="/5F8C807E/5FB9E23E" Ref="#PWR?"  Part="1" 
AR Path="/5FB9E23E" Ref="#PWR?"  Part="1" 
AR Path="/5F57C9A4/5FB9E23E" Ref="#PWR0120"  Part="1" 
AR Path="/5F57DBA0/5FB9E23E" Ref="#PWR?"  Part="1" 
AR Path="/5F63C067/5FB9E23E" Ref="#PWR?"  Part="1" 
AR Path="/5F645C82/5FB9E23E" Ref="#PWR?"  Part="1" 
F 0 "#PWR0120" H 8000 2100 50  0001 C CNN
F 1 "+5V" V 8015 2378 50  0000 L CNN
F 2 "" H 8000 2250 50  0001 C CNN
F 3 "" H 8000 2250 50  0001 C CNN
	1    8000 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 2300 8000 2250
$EndSCHEMATC
