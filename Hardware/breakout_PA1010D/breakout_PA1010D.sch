EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L PA1010D:PA1010D U1
U 1 1 61903BE1
P 5000 3450
F 0 "U1" H 5525 3715 50  0000 C CNN
F 1 "PA1010D" H 5525 3624 50  0000 C CNN
F 2 "PA1010D:PA1010D" H 5000 3700 50  0001 C CNN
F 3 "" H 5000 3700 50  0001 C CNN
	1    5000 3450
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J1
U 1 1 61904C5E
P 4600 3650
F 0 "J1" H 4518 4067 50  0000 C CNN
F 1 "Conn_01x05" H 4518 3976 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 4600 3650 50  0001 C CNN
F 3 "~" H 4600 3650 50  0001 C CNN
	1    4600 3650
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J2
U 1 1 61905E15
P 6450 3650
F 0 "J2" H 6530 3692 50  0000 L CNN
F 1 "Conn_01x05" H 6530 3601 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 6450 3650 50  0001 C CNN
F 3 "~" H 6450 3650 50  0001 C CNN
	1    6450 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 3450 6250 3450
Wire Wire Line
	6050 3550 6250 3550
Wire Wire Line
	6250 3650 6050 3650
Wire Wire Line
	6050 3750 6250 3750
Wire Wire Line
	6250 3850 6050 3850
Wire Wire Line
	5000 3850 4800 3850
Wire Wire Line
	4800 3750 5000 3750
Wire Wire Line
	5000 3650 4800 3650
Wire Wire Line
	4800 3550 5000 3550
Wire Wire Line
	5000 3450 4800 3450
$EndSCHEMATC
