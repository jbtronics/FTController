EESchema Schematic File Version 4
LIBS:FTController-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title "FTController"
Date "2017-03-30"
Rev "1.1"
Comp "(C) J. Boehmer"
Comment1 "A Two Joystick Controller for FT"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L tinkerforge:JOYSTICK_BUTTON U4
U 1 1 5884F708
P 9850 1700
F 0 "U4" H 10377 1753 60  0000 L CNN
F 1 "JOYSTICK_L" H 10377 1647 60  0000 L CNN
F 2 "Joystick:Joystick_Button" H 9850 1700 60  0001 C CNN
F 3 "" H 9850 1700 60  0000 C CNN
	1    9850 1700
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:JOYSTICK_BUTTON U5
U 1 1 5884F7B6
P 9850 2900
F 0 "U5" H 10378 2953 60  0000 L CNN
F 1 "JOYSTICK_R" H 10378 2847 60  0000 L CNN
F 2 "Joystick:Joystick_Button" H 9850 2900 60  0001 C CNN
F 3 "" H 9850 2900 60  0000 C CNN
	1    9850 2900
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:CONN_01X02 P1
U 1 1 5884F80E
P 950 1200
F 0 "P1" H 869 925 50  0000 C CNN
F 1 "9V IN" H 869 1016 50  0000 C CNN
F 2 "w_conn_mkds:mkds_1,5-2" H 950 1200 50  0001 C CNN
F 3 "" H 950 1200 50  0000 C CNN
F 4 "V" H 950 1200 60  0001 C CNN "Spice_Primitive"
F 5 "dc 9" H 950 1200 60  0001 C CNN "Spice_Model"
F 6 "Y" H 950 1200 60  0001 C CNN "Spice_Netlist_Enabled"
	1    950  1200
	-1   0    0    -1  
$EndComp
$Comp
L device:D D1
U 1 1 5884F885
P 1600 1150
F 0 "D1" H 1600 934 50  0000 C CNN
F 1 "1N4001" H 1600 1025 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-41_SOD81_Vertical_KathodeUp" H 1600 1150 50  0001 C CNN
F 3 "" H 1600 1150 50  0000 C CNN
F 4 "D" H 1600 1150 60  0001 C CNN "Spice_Primitive"
F 5 "1N4001" H 1600 1150 60  0001 C CNN "Spice_Model"
F 6 "N" H 1600 1150 60  0001 C CNN "Spice_Netlist_Enabled"
	1    1600 1150
	-1   0    0    1   
$EndComp
$Comp
L power1:GND #PWR01
U 1 1 5884F936
P 1200 1500
F 0 "#PWR01" H 1200 1250 50  0001 C CNN
F 1 "GND" H 1205 1327 50  0000 C CNN
F 2 "" H 1200 1500 50  0000 C CNN
F 3 "" H 1200 1500 50  0000 C CNN
	1    1200 1500
	1    0    0    -1  
$EndComp
$Comp
L FTController-rescue:LM78L05ACZ U3
U 1 1 5884F9B2
P 2600 1200
F 0 "U3" H 2600 1500 50  0000 C CNN
F 1 "LM78L05ACZ" H 2600 1400 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 2600 1426 50  0001 C CIN
F 3 "" H 2600 1200 50  0000 C CNN
	1    2600 1200
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR02
U 1 1 5884FA0A
P 2600 1500
F 0 "#PWR02" H 2600 1250 50  0001 C CNN
F 1 "GND" H 2605 1327 50  0000 C CNN
F 2 "" H 2600 1500 50  0000 C CNN
F 3 "" H 2600 1500 50  0000 C CNN
	1    2600 1500
	1    0    0    -1  
$EndComp
$Comp
L device:C C2
U 1 1 5884FA2D
P 2050 1350
F 0 "C2" H 2165 1396 50  0000 L CNN
F 1 "100n" H 2165 1305 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2088 1200 50  0001 C CNN
F 3 "" H 2050 1350 50  0000 C CNN
	1    2050 1350
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR03
U 1 1 5884FA7D
P 2050 1500
F 0 "#PWR03" H 2050 1250 50  0001 C CNN
F 1 "GND" H 2055 1327 50  0000 C CNN
F 2 "" H 2050 1500 50  0000 C CNN
F 3 "" H 2050 1500 50  0000 C CNN
	1    2050 1500
	1    0    0    -1  
$EndComp
$Comp
L device:C C3
U 1 1 5884FAF6
P 3100 1350
F 0 "C3" H 3215 1396 50  0000 L CNN
F 1 "100n" H 3215 1305 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3138 1200 50  0001 C CNN
F 3 "" H 3100 1350 50  0000 C CNN
	1    3100 1350
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR04
U 1 1 5884FB3D
P 3100 1500
F 0 "#PWR04" H 3100 1250 50  0001 C CNN
F 1 "GND" H 3105 1327 50  0000 C CNN
F 2 "" H 3100 1500 50  0000 C CNN
F 3 "" H 3100 1500 50  0000 C CNN
	1    3100 1500
	1    0    0    -1  
$EndComp
$Comp
L device:CP C4
U 1 1 5884FB6E
P 3550 1350
F 0 "C4" H 3668 1396 50  0000 L CNN
F 1 "10uF" H 3668 1305 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2.5" H 3588 1200 50  0001 C CNN
F 3 "" H 3550 1350 50  0000 C CNN
	1    3550 1350
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR05
U 1 1 5884FBDA
P 3550 1500
F 0 "#PWR05" H 3550 1250 50  0001 C CNN
F 1 "GND" H 3555 1327 50  0000 C CNN
F 2 "" H 3550 1500 50  0000 C CNN
F 3 "" H 3550 1500 50  0000 C CNN
	1    3550 1500
	1    0    0    -1  
$EndComp
$Comp
L power1:+5V #PWR06
U 1 1 5884FC10
P 3550 1050
F 0 "#PWR06" H 3550 900 50  0001 C CNN
F 1 "+5V" H 3565 1223 50  0000 C CNN
F 2 "" H 3550 1050 50  0000 C CNN
F 3 "" H 3550 1050 50  0000 C CNN
	1    3550 1050
	1    0    0    -1  
$EndComp
$Comp
L device:CP C1
U 1 1 5884FCFE
P 1400 1350
F 0 "C1" H 1518 1396 50  0000 L CNN
F 1 "100u" H 1518 1305 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2.5" H 1438 1200 50  0001 C CNN
F 3 "" H 1400 1350 50  0000 C CNN
F 4 "C" H 1400 1350 60  0001 C CNN "Spice_Primitive"
F 5 "100u" H 1400 1350 60  0001 C CNN "Spice_Model"
F 6 "Y" H 1400 1350 60  0001 C CNN "Spice_Netlist_Enabled"
	1    1400 1350
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR07
U 1 1 5884FD5B
P 1400 1500
F 0 "#PWR07" H 1400 1250 50  0001 C CNN
F 1 "GND" H 1405 1327 50  0000 C CNN
F 2 "" H 1400 1500 50  0000 C CNN
F 3 "" H 1400 1500 50  0000 C CNN
	1    1400 1500
	1    0    0    -1  
$EndComp
$Comp
L FTController-rescue:ATMEGA328-AU IC1
U 1 1 5885053D
P 5750 3950
F 0 "IC1" H 5800 5407 50  0000 C CNN
F 1 "ATMEGA328-AU" H 5800 5316 50  0000 C CNN
F 2 "Housings_QFP:TQFP-32_7x7mm_Pitch0.8mm" H 5800 5225 50  0000 C CIN
F 3 "" H 5750 3950 50  0000 C CNN
	1    5750 3950
	1    0    0    -1  
$EndComp
$Comp
L power1:+5V #PWR08
U 1 1 588506AA
P 4650 2700
F 0 "#PWR08" H 4650 2550 50  0001 C CNN
F 1 "+5V" H 4665 2873 50  0000 C CNN
F 2 "" H 4650 2700 50  0000 C CNN
F 3 "" H 4650 2700 50  0000 C CNN
	1    4650 2700
	1    0    0    -1  
$EndComp
$Comp
L device:C C7
U 1 1 588508BA
P 4650 3450
F 0 "C7" V 4398 3450 50  0000 C CNN
F 1 "100n" V 4489 3450 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4688 3300 50  0001 C CNN
F 3 "" H 4650 3450 50  0000 C CNN
	1    4650 3450
	0    1    1    0   
$EndComp
$Comp
L power1:GND #PWR09
U 1 1 58850934
P 4500 3450
F 0 "#PWR09" H 4500 3200 50  0001 C CNN
F 1 "GND" V 4505 3322 50  0000 R CNN
F 2 "" H 4500 3450 50  0000 C CNN
F 3 "" H 4500 3450 50  0000 C CNN
	1    4500 3450
	0    1    1    0   
$EndComp
$Comp
L power1:GND #PWR010
U 1 1 58850C43
P 4750 5250
F 0 "#PWR010" H 4750 5000 50  0001 C CNN
F 1 "GND" H 4755 5077 50  0000 C CNN
F 2 "" H 4750 5250 50  0000 C CNN
F 3 "" H 4750 5250 50  0000 C CNN
	1    4750 5250
	1    0    0    -1  
$EndComp
$Comp
L power1:+5V #PWR011
U 1 1 58850D93
P 4100 1050
F 0 "#PWR011" H 4100 900 50  0001 C CNN
F 1 "+5V" H 4115 1223 50  0000 C CNN
F 2 "" H 4100 1050 50  0000 C CNN
F 3 "" H 4100 1050 50  0000 C CNN
	1    4100 1050
	1    0    0    -1  
$EndComp
$Comp
L device:C C5
U 1 1 58850DBF
P 4100 1300
F 0 "C5" H 4215 1346 50  0000 L CNN
F 1 "100n" H 4215 1255 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4138 1150 50  0001 C CNN
F 3 "" H 4100 1300 50  0000 C CNN
	1    4100 1300
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR012
U 1 1 58850E50
P 4100 1500
F 0 "#PWR012" H 4100 1250 50  0001 C CNN
F 1 "GND" H 4105 1327 50  0000 C CNN
F 2 "" H 4100 1500 50  0000 C CNN
F 3 "" H 4100 1500 50  0000 C CNN
	1    4100 1500
	1    0    0    -1  
$EndComp
$Comp
L device:C C6
U 1 1 58850ED6
P 4550 1300
F 0 "C6" H 4665 1346 50  0000 L CNN
F 1 "100n" H 4665 1255 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4588 1150 50  0001 C CNN
F 3 "" H 4550 1300 50  0000 C CNN
	1    4550 1300
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR013
U 1 1 58850F4B
P 4550 1500
F 0 "#PWR013" H 4550 1250 50  0001 C CNN
F 1 "GND" H 4555 1327 50  0000 C CNN
F 2 "" H 4550 1500 50  0000 C CNN
F 3 "" H 4550 1500 50  0000 C CNN
	1    4550 1500
	1    0    0    -1  
$EndComp
Text Label 7050 3150 2    60   ~ 0
MOSI
Text Label 7050 3250 2    60   ~ 0
MISO
Text Label 7050 3350 2    60   ~ 0
SCK
$Comp
L device:Crystal Y1
U 1 1 58851569
P 9800 4000
F 0 "Y1" V 9750 3850 50  0000 R CNN
F 1 "16MHz" V 9850 3850 50  0000 R CNN
F 2 "Crystals:Crystal_HC49-U_Vertical" H 9800 4000 50  0001 C CNN
F 3 "" H 9800 4000 50  0000 C CNN
	1    9800 4000
	0    1    -1   0   
$EndComp
Text Label 7050 3450 2    60   ~ 0
XTAL1
Text Label 7050 3550 2    60   ~ 0
XTAL2
Text Label 9450 3750 0    60   ~ 0
XTAL1
Text Label 9450 4250 0    60   ~ 0
XTAL2
$Comp
L device:C C8
U 1 1 58852E94
P 10050 3750
F 0 "C8" V 9798 3750 50  0000 C CNN
F 1 "15p" V 9889 3750 50  0000 C CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 10088 3600 50  0001 C CNN
F 3 "" H 10050 3750 50  0000 C CNN
	1    10050 3750
	0    1    1    0   
$EndComp
$Comp
L device:C C9
U 1 1 58852EF7
P 10050 4250
F 0 "C9" V 9798 4250 50  0000 C CNN
F 1 "15p" V 9889 4250 50  0000 C CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 10088 4100 50  0001 C CNN
F 3 "" H 10050 4250 50  0000 C CNN
	1    10050 4250
	0    1    1    0   
$EndComp
$Comp
L power1:GND #PWR014
U 1 1 5885309A
P 10400 4050
F 0 "#PWR014" H 10400 3800 50  0001 C CNN
F 1 "GND" H 10405 3877 50  0000 C CNN
F 2 "" H 10400 4050 50  0000 C CNN
F 3 "" H 10400 4050 50  0000 C CNN
	1    10400 4050
	1    0    0    -1  
$EndComp
Text Label 7050 4300 2    60   ~ 0
RST
Text Label 8850 1400 0    60   ~ 0
JOYL_Y
Text Label 8850 1750 0    60   ~ 0
JOYL_X
Text Label 8850 2600 0    60   ~ 0
JOYR_Y
Text Label 8850 2950 0    60   ~ 0
JOYR_X
$Comp
L power1:+5V #PWR015
U 1 1 588522C1
P 9100 1250
F 0 "#PWR015" H 9100 1100 50  0001 C CNN
F 1 "+5V" H 9115 1423 50  0000 C CNN
F 2 "" H 9100 1250 50  0001 C CNN
F 3 "" H 9100 1250 50  0001 C CNN
	1    9100 1250
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR016
U 1 1 58852376
P 9050 1500
F 0 "#PWR016" H 9050 1250 50  0001 C CNN
F 1 "GND" V 9055 1372 50  0000 R CNN
F 2 "" H 9050 1500 50  0001 C CNN
F 3 "" H 9050 1500 50  0001 C CNN
	1    9050 1500
	0    1    1    0   
$EndComp
$Comp
L power1:+5V #PWR017
U 1 1 5885257C
P 8800 1650
F 0 "#PWR017" H 8800 1500 50  0001 C CNN
F 1 "+5V" V 8815 1778 50  0000 L CNN
F 2 "" H 8800 1650 50  0001 C CNN
F 3 "" H 8800 1650 50  0001 C CNN
	1    8800 1650
	0    -1   -1   0   
$EndComp
$Comp
L power1:GND #PWR018
U 1 1 5885266E
P 9050 1850
F 0 "#PWR018" H 9050 1600 50  0001 C CNN
F 1 "GND" V 9055 1722 50  0000 R CNN
F 2 "" H 9050 1850 50  0001 C CNN
F 3 "" H 9050 1850 50  0001 C CNN
	1    9050 1850
	0    1    1    0   
$EndComp
Text Label 7100 3700 2    60   ~ 0
JOYL_X
Text Label 7100 3800 2    60   ~ 0
JOYL_Y
Text Label 4500 4200 0    60   ~ 0
JOYR_X
Text Label 4500 4300 0    60   ~ 0
JOYR_Y
$Comp
L power1:GND #PWR019
U 1 1 58894915
P 10400 6050
F 0 "#PWR019" H 10400 5800 50  0001 C CNN
F 1 "GND" H 10405 5877 50  0000 C CNN
F 2 "" H 10400 6050 50  0000 C CNN
F 3 "" H 10400 6050 50  0000 C CNN
	1    10400 6050
	1    0    0    -1  
$EndComp
$Comp
L power1:+5V #PWR020
U 1 1 58895338
P 10400 5750
F 0 "#PWR020" H 10400 5600 50  0001 C CNN
F 1 "+5V" H 10415 5923 50  0000 C CNN
F 2 "" H 10400 5750 50  0000 C CNN
F 3 "" H 10400 5750 50  0000 C CNN
	1    10400 5750
	1    0    0    -1  
$EndComp
Text Label 9300 5800 0    60   ~ 0
MISO
Text Label 9300 5900 0    60   ~ 0
SCK
Text Label 9300 6000 0    60   ~ 0
RST
Text Label 7050 4100 2    60   ~ 0
SDA
Text Label 7050 4200 2    60   ~ 0
SCL
$Comp
L power1:+5V #PWR021
U 1 1 58895B18
P 8800 2500
F 0 "#PWR021" H 8800 2350 50  0001 C CNN
F 1 "+5V" H 8815 2673 50  0000 C CNN
F 2 "" H 8800 2500 50  0001 C CNN
F 3 "" H 8800 2500 50  0001 C CNN
	1    8800 2500
	0    -1   -1   0   
$EndComp
$Comp
L power1:GND #PWR022
U 1 1 58895DEA
P 8850 2700
F 0 "#PWR022" H 8850 2450 50  0001 C CNN
F 1 "GND" V 8855 2572 50  0000 R CNN
F 2 "" H 8850 2700 50  0001 C CNN
F 3 "" H 8850 2700 50  0001 C CNN
	1    8850 2700
	0    1    1    0   
$EndComp
$Comp
L power1:+5V #PWR023
U 1 1 588960B3
P 8800 2850
F 0 "#PWR023" H 8800 2700 50  0001 C CNN
F 1 "+5V" H 8815 3023 50  0000 C CNN
F 2 "" H 8800 2850 50  0001 C CNN
F 3 "" H 8800 2850 50  0001 C CNN
	1    8800 2850
	0    -1   -1   0   
$EndComp
$Comp
L power1:GND #PWR024
U 1 1 58896263
P 8850 3050
F 0 "#PWR024" H 8850 2800 50  0001 C CNN
F 1 "GND" V 8855 2922 50  0000 R CNN
F 2 "" H 8850 3050 50  0001 C CNN
F 3 "" H 8850 3050 50  0001 C CNN
	1    8850 3050
	0    1    1    0   
$EndComp
$Comp
L power1:GND #PWR025
U 1 1 58896A83
P 9150 2000
F 0 "#PWR025" H 9150 1750 50  0001 C CNN
F 1 "GND" V 9155 1872 50  0000 R CNN
F 2 "" H 9150 2000 50  0001 C CNN
F 3 "" H 9150 2000 50  0001 C CNN
	1    9150 2000
	0    1    1    0   
$EndComp
Text Label 8600 2100 0    60   ~ 0
SW_L
$Sheet
S 5350 6900 850  450 
U 588DAB03
F0 "Drivers" 60
F1 "Drivers.sch" 60
$EndSheet
Text GLabel 7150 4750 2    60   Input ~ 0
PWM_RY1
Text GLabel 7150 4850 2    60   Input ~ 0
PWM_RY2
Text GLabel 7150 4950 2    60   Input ~ 0
PWM_LY1
Text GLabel 7150 5050 2    60   Input ~ 0
PWM_LY2
Text GLabel 7100 2950 2    60   Input ~ 0
PWM_LX1
Text GLabel 7100 3050 2    60   Input ~ 0
PWM_LX2
Text GLabel 7150 3900 2    60   Input ~ 0
PWM_RX1
Text GLabel 7150 4000 2    60   Input ~ 0
PWM_RX2
Text Label 7050 4650 2    60   ~ 0
SW_L
Text Label 7100 2850 2    60   ~ 0
LCD_E
$Comp
L device:LED D2
U 1 1 588EF705
P 5600 1200
F 0 "D2" V 5638 1082 50  0000 R CNN
F 1 "PWR" V 5547 1082 50  0000 R CNN
F 2 "LEDs:LED-3MM" H 100 -50 50  0001 C CNN
F 3 "" H 100 -50 50  0001 C CNN
	1    5600 1200
	0    -1   -1   0   
$EndComp
$Comp
L power1:GND #PWR026
U 1 1 588EF7C4
P 5600 1450
F 0 "#PWR026" H 5600 1200 50  0001 C CNN
F 1 "GND" H 5605 1277 50  0000 C CNN
F 2 "" H 5600 1450 50  0000 C CNN
F 3 "" H 5600 1450 50  0000 C CNN
	1    5600 1450
	1    0    0    -1  
$EndComp
$Comp
L device:R R4
U 1 1 588EF8D1
P 5400 1000
F 0 "R4" V 5193 1000 50  0000 C CNN
F 1 "470" V 5284 1000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 80  -50 50  0001 C CNN
F 3 "" H 150 -50 50  0001 C CNN
	1    5400 1000
	0    1    1    0   
$EndComp
$Comp
L power1:+5V #PWR027
U 1 1 588EFD7A
P 5200 950
F 0 "#PWR027" H 5200 800 50  0001 C CNN
F 1 "+5V" H 5215 1123 50  0000 C CNN
F 2 "" H 5200 950 50  0000 C CNN
F 3 "" H 5200 950 50  0000 C CNN
	1    5200 950 
	1    0    0    -1  
$EndComp
Text Label 1750 3700 0    60   ~ 0
V_MEAS
$Comp
L device:R R2
U 1 1 588F1597
P 2250 4000
F 0 "R2" H 2320 4046 50  0000 L CNN
F 1 "R" H 2320 3955 50  0000 L CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 580 300 50  0001 C CNN
F 3 "" H 650 300 50  0001 C CNN
	1    2250 4000
	1    0    0    -1  
$EndComp
$Comp
L device:R R3
U 1 1 588F1787
P 2250 4400
F 0 "R3" H 2320 4446 50  0000 L CNN
F 1 "R" H 2320 4355 50  0000 L CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 580 700 50  0001 C CNN
F 3 "" H 650 700 50  0001 C CNN
	1    2250 4400
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR028
U 1 1 588F1B91
P 2250 4600
F 0 "#PWR028" H 2250 4350 50  0001 C CNN
F 1 "GND" H 2255 4427 50  0000 C CNN
F 2 "" H 2250 4600 50  0000 C CNN
F 3 "" H 2250 4600 50  0000 C CNN
	1    2250 4600
	1    0    0    -1  
$EndComp
Text Label 2550 4200 2    60   ~ 0
SCL
Text Notes 3400 4950 2    60   Italic 0
Optional (Voltage Measurement)
$Comp
L power1:+5V #PWR029
U 1 1 588F3E0A
P 9100 3200
F 0 "#PWR029" H 9100 3050 50  0001 C CNN
F 1 "+5V" H 9115 3373 50  0000 C CNN
F 2 "" H 9100 3200 50  0001 C CNN
F 3 "" H 9100 3200 50  0001 C CNN
	1    9100 3200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1150 1150 1400 1150
Wire Wire Line
	2600 1450 2600 1500
Wire Wire Line
	1750 1150 2050 1150
Wire Wire Line
	3100 1200 3100 1150
Wire Wire Line
	3000 1150 3100 1150
Connection ~ 3100 1150
Wire Wire Line
	1150 1250 1200 1250
Wire Wire Line
	1200 1250 1200 1500
Wire Wire Line
	1400 800  1400 1150
Connection ~ 1400 1150
Wire Wire Line
	3550 1050 3550 1150
Connection ~ 3550 1150
Wire Wire Line
	4650 2950 4850 2950
Wire Wire Line
	4850 2850 4650 2850
Connection ~ 4650 2850
Wire Wire Line
	4650 2700 4650 2850
Wire Wire Line
	4650 3150 4850 3150
Connection ~ 4650 2950
Wire Wire Line
	4850 3450 4800 3450
Wire Wire Line
	4850 4950 4750 4950
Wire Wire Line
	4850 5050 4750 5050
Connection ~ 4750 5050
Wire Wire Line
	4750 5150 4850 5150
Connection ~ 4750 5150
Wire Wire Line
	4750 4950 4750 5050
Wire Wire Line
	4100 1050 4100 1100
Wire Wire Line
	4100 1450 4100 1500
Wire Wire Line
	4550 1150 4550 1100
Wire Wire Line
	4550 1100 4100 1100
Connection ~ 4100 1100
Wire Wire Line
	4550 1500 4550 1450
Wire Wire Line
	6750 3150 7050 3150
Wire Wire Line
	6750 3250 7050 3250
Wire Wire Line
	6750 3350 7050 3350
Wire Wire Line
	6750 3450 7050 3450
Wire Wire Line
	6750 3550 7050 3550
Wire Wire Line
	9800 3850 9800 3750
Wire Wire Line
	9450 3750 9800 3750
Wire Wire Line
	9800 4150 9800 4250
Wire Wire Line
	9450 4250 9800 4250
Connection ~ 9800 3750
Connection ~ 9800 4250
Wire Wire Line
	10200 3750 10300 3750
Wire Wire Line
	10300 3750 10300 4000
Wire Wire Line
	10300 4250 10200 4250
Wire Wire Line
	10400 4050 10400 4000
Wire Wire Line
	10400 4000 10300 4000
Connection ~ 10300 4000
Wire Wire Line
	6750 4300 7050 4300
Wire Wire Line
	8850 1400 9200 1400
Wire Wire Line
	8850 1750 9200 1750
Wire Wire Line
	8850 2600 9200 2600
Wire Wire Line
	9200 2950 8850 2950
Wire Wire Line
	9100 1300 9200 1300
Wire Wire Line
	9200 1500 9050 1500
Wire Wire Line
	9100 1300 9100 1250
Wire Wire Line
	9200 1650 8800 1650
Wire Wire Line
	9200 1850 9050 1850
Wire Wire Line
	7100 3700 6750 3700
Wire Wire Line
	6750 3800 7100 3800
Wire Wire Line
	4850 4200 4500 4200
Wire Wire Line
	4850 4300 4500 4300
Wire Wire Line
	6750 4100 7050 4100
Wire Wire Line
	6750 4200 7050 4200
Wire Wire Line
	9200 2500 8800 2500
Wire Wire Line
	9200 2700 8850 2700
Wire Wire Line
	8800 2850 9200 2850
Wire Wire Line
	9200 3050 8850 3050
Wire Wire Line
	9100 3200 9200 3200
Wire Wire Line
	9150 2000 9200 2000
Wire Wire Line
	8600 2100 9200 2100
Wire Wire Line
	7100 2950 6750 2950
Wire Wire Line
	7100 3050 6750 3050
Wire Wire Line
	7150 3900 6750 3900
Wire Wire Line
	7150 4000 6750 4000
Wire Wire Line
	7150 4750 6750 4750
Wire Wire Line
	7150 4850 6750 4850
Wire Wire Line
	7150 4950 6750 4950
Wire Wire Line
	7150 5050 6750 5050
Wire Wire Line
	7050 4650 6750 4650
Wire Wire Line
	6750 2850 7100 2850
Wire Wire Line
	6750 5150 7150 5150
Wire Notes Line
	900  1800 3400 1800
Wire Notes Line
	3400 1800 3400 3200
Wire Notes Line
	900  1800 900  3200
Wire Wire Line
	5600 1350 5600 1450
Wire Wire Line
	5600 1050 5600 1000
Wire Wire Line
	5600 1000 5550 1000
Wire Wire Line
	5200 950  5200 1000
Wire Wire Line
	5200 1000 5250 1000
Wire Wire Line
	1750 3700 2250 3700
Wire Wire Line
	2250 3700 2250 3850
Wire Wire Line
	2250 4150 2250 4200
Wire Wire Line
	2250 4550 2250 4600
Wire Wire Line
	2250 4200 2550 4200
Connection ~ 2250 4200
Wire Notes Line
	900  3550 3400 3550
Wire Notes Line
	900  4850 3400 4850
Wire Notes Line
	900  4850 900  3550
Wire Notes Line
	3400 4850 3400 3550
$Comp
L avr-isp:AVR-ISP P4
U 1 1 588F5532
P 9950 5850
F 0 "P4" H 9950 6165 50  0000 C CNN
F 1 "AVR-ISP" H 9950 6074 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03" H 150 -1250 50  0001 C CNN
F 3 "" H 150 -1250 50  0000 C CNN
	1    9950 5850
	1    0    0    -1  
$EndComp
Text Label 10550 5900 2    60   ~ 0
MOSI
Wire Wire Line
	10300 5800 10400 5800
Wire Wire Line
	10400 5800 10400 5750
Wire Wire Line
	10300 5900 10550 5900
Wire Wire Line
	10400 6050 10400 6000
Wire Wire Line
	10400 6000 10300 6000
Wire Wire Line
	9300 5800 9600 5800
Wire Wire Line
	9300 5900 9600 5900
Wire Wire Line
	9300 6000 9600 6000
Text GLabel 8800 3300 0    60   Input ~ 0
SW_R
Wire Wire Line
	9200 3300 8800 3300
Text Label 7150 5150 2    60   ~ 0
COUNT
Text GLabel 5750 6600 2    60   Input Italic 0
I_MEAS
Text Label 5450 6600 0    60   ~ 0
SDA
Wire Wire Line
	5450 6600 5750 6600
$Comp
L FTController-rescue:CNY17-1 U2
U 1 1 58912859
P 2000 5650
F 0 "U2" H 2000 5975 50  0000 C CNN
F 1 "CNY17-1" H 2000 5884 50  0000 C CNN
F 2 "Housings_DIP:DIP-6_W7.62mm_LongPads" H -650 -1750 50  0001 L CNN
F 3 "" H -650 -1750 50  0001 L CNN
	1    2000 5650
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:CONN_01X02 P2
U 1 1 589130A1
P 1050 5600
F 0 "P2" H 969 5325 50  0000 C CNN
F 1 "COUNTER" H 969 5416 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H -1250 -300 50  0001 C CNN
F 3 "" H -1250 -300 50  0001 C CNN
	1    1050 5600
	-1   0    0    -1  
$EndComp
$Comp
L power1:GND #PWR030
U 1 1 58913D79
P 2350 5850
F 0 "#PWR030" H 2350 5600 50  0001 C CNN
F 1 "GND" H 2355 5677 50  0000 C CNN
F 2 "" H 2350 5850 50  0000 C CNN
F 3 "" H 2350 5850 50  0000 C CNN
	1    2350 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 5750 2350 5750
Wire Wire Line
	2350 5750 2350 5850
$Comp
L device:R R1
U 1 1 58914120
P 1500 5550
F 0 "R1" V 1293 5550 50  0000 C CNN
F 1 "1k" V 1384 5550 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" V -870 -400 50  0001 C CNN
F 3 "" H -800 -400 50  0001 C CNN
	1    1500 5550
	0    1    1    0   
$EndComp
Wire Wire Line
	1250 5550 1350 5550
Wire Wire Line
	1650 5550 1700 5550
Text Label 2650 5650 2    60   Italic 0
COUNT
Wire Notes Line
	900  5150 900  6150
Wire Notes Line
	900  6150 3400 6150
Wire Notes Line
	3400 6150 3400 5150
Wire Notes Line
	3400 5150 900  5150
Text Notes 2150 6250 0    60   Italic 0
Optional (Frequency Count)
Wire Wire Line
	6750 4450 7100 4450
Wire Wire Line
	6750 4550 7150 4550
Text Label 7100 4450 2    60   ~ 0
LCD_RS
Text Label 7150 4550 2    60   ~ 0
LCD_DB7
$Comp
L FTController-rescue:Mounting_Hole MK1
U 1 1 5891E513
P 7200 800
F 0 "MK1" H 7300 846 50  0000 L CNN
F 1 "Mounting_Hole" H 7300 755 50  0000 L CNN
F 2 "Mounting_Holes:MountingHole_3mm" H 5600 -6550 50  0001 C CNN
F 3 "" H 5600 -6550 50  0001 C CNN
	1    7200 800 
	1    0    0    -1  
$EndComp
$Comp
L FTController-rescue:Mounting_Hole MK2
U 1 1 5891E76A
P 7200 1000
F 0 "MK2" H 7300 1046 50  0000 L CNN
F 1 "Mounting_Hole" H 7300 955 50  0000 L CNN
F 2 "Mounting_Holes:MountingHole_3mm" H 5600 -6350 50  0001 C CNN
F 3 "" H 5600 -6350 50  0001 C CNN
	1    7200 1000
	1    0    0    -1  
$EndComp
$Comp
L FTController-rescue:Mounting_Hole MK3
U 1 1 5891E7D8
P 7200 1200
F 0 "MK3" H 7300 1246 50  0000 L CNN
F 1 "Mounting_Hole" H 7300 1155 50  0000 L CNN
F 2 "Mounting_Holes:MountingHole_3mm" H 5600 -6150 50  0001 C CNN
F 3 "" H 5600 -6150 50  0001 C CNN
	1    7200 1200
	1    0    0    -1  
$EndComp
$Comp
L FTController-rescue:Mounting_Hole MK4
U 1 1 5891E849
P 7200 1400
F 0 "MK4" H 7300 1446 50  0000 L CNN
F 1 "Mounting_Hole" H 7300 1355 50  0000 L CNN
F 2 "Mounting_Holes:MountingHole_3mm" H 5600 -5950 50  0001 C CNN
F 3 "" H 5600 -5950 50  0001 C CNN
	1    7200 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 5650 1450 5650
Wire Wire Line
	1450 5650 1450 5750
Wire Wire Line
	1450 5750 1700 5750
$Comp
L device:R R24
U 1 1 58938B04
P 10100 5100
F 0 "R24" H 10170 5146 50  0000 L CNN
F 1 "10k" H 10170 5055 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 8430 1400 50  0001 C CNN
F 3 "" H 8500 1400 50  0001 C CNN
	1    10100 5100
	1    0    0    -1  
$EndComp
$Comp
L power1:+5V #PWR031
U 1 1 58938C6A
P 10100 4950
F 0 "#PWR031" H 10100 4800 50  0001 C CNN
F 1 "+5V" H 10115 5123 50  0000 C CNN
F 2 "" H 10100 4950 50  0000 C CNN
F 3 "" H 10100 4950 50  0000 C CNN
	1    10100 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 5250 10100 5350
Wire Wire Line
	10100 5350 9700 5350
Text Label 9700 5350 0    60   ~ 0
RST
$Comp
L FTController-rescue:CONN_02X05 P3
U 1 1 58939E24
P 2100 2400
F 0 "P3" H 2100 2815 50  0000 C CNN
F 1 "LCD" H 2100 2724 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x05" H 200 -1800 50  0001 C CNN
F 3 "" H 200 -1800 50  0001 C CNN
	1    2100 2400
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR032
U 1 1 5893A082
P 1800 2200
F 0 "#PWR032" H 100 -1000 50  0001 C CNN
F 1 "GND" V 1805 2072 50  0000 R CNN
F 2 "" H 100 -750 50  0001 C CNN
F 3 "" H 100 -750 50  0001 C CNN
	1    1800 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	2350 2200 2800 2200
Wire Wire Line
	1800 2200 1850 2200
$Comp
L FTController-rescue:POT_TRIM RV1
U 1 1 5893A344
P 1400 2300
F 0 "RV1" H 1330 2346 50  0000 R CNN
F 1 "CONTRAST" H 1330 2255 50  0000 R CNN
F 2 "Potentiometers:Potentiometer_VishaySpectrol-Econtrim-Type36X" H 100 -750 50  0001 C CNN
F 3 "" H 100 -750 50  0001 C CNN
	1    1400 2300
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR033
U 1 1 5893A5CA
P 1400 2450
F 0 "#PWR033" H -300 -750 50  0001 C CNN
F 1 "GND" H 1405 2277 50  0000 C CNN
F 2 "" H -300 -500 50  0001 C CNN
F 3 "" H -300 -500 50  0001 C CNN
	1    1400 2450
	1    0    0    -1  
$EndComp
$Comp
L power1:+5V #PWR034
U 1 1 5893A6A1
P 1400 2150
F 0 "#PWR034" H -1000 -950 50  0001 C CNN
F 1 "+5V" V 1400 2300 50  0000 L CNN
F 2 "" H -1000 -800 50  0001 C CNN
F 3 "" H -1000 -800 50  0001 C CNN
	1    1400 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 2300 1850 2300
Text Label 2700 2300 2    60   ~ 0
LCD_RS
Wire Wire Line
	2700 2300 2350 2300
$Comp
L power1:+5V #PWR035
U 1 1 5893AE61
P 2800 2200
F 0 "#PWR035" H 400 -900 50  0001 C CNN
F 1 "+5V" V 2800 2350 50  0000 L CNN
F 2 "" H 400 -750 50  0001 C CNN
F 3 "" H 400 -750 50  0001 C CNN
	1    2800 2200
	0    1    1    0   
$EndComp
$Comp
L power1:GND #PWR036
U 1 1 5893B1A4
P 1800 2400
F 0 "#PWR036" H 100 -800 50  0001 C CNN
F 1 "GND" V 1805 2272 50  0000 R CNN
F 2 "" H 100 -550 50  0001 C CNN
F 3 "" H 100 -550 50  0001 C CNN
	1    1800 2400
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 2400 1850 2400
Wire Wire Line
	2350 2400 2700 2400
Text Label 2700 2400 2    60   ~ 0
LCD_E
Wire Wire Line
	1850 2500 1550 2500
Wire Wire Line
	2350 2500 2700 2500
Wire Wire Line
	2350 2600 2700 2600
Wire Wire Line
	1550 2600 1850 2600
Text Label 2700 2500 2    39   ~ 0
MOSI
Text Label 1550 2600 0    39   ~ 0
MISO
$Comp
L power1:+5V #PWR037
U 1 1 5893C33B
P 1800 2800
F 0 "#PWR037" H -600 -300 50  0001 C CNN
F 1 "+5V" V 1800 2950 50  0000 L CNN
F 2 "" H -600 -150 50  0001 C CNN
F 3 "" H -600 -150 50  0001 C CNN
	1    1800 2800
	0    -1   -1   0   
$EndComp
$Comp
L device:R R5
U 1 1 5893C99E
P 1950 2800
F 0 "R5" H 2020 2846 50  0000 L CNN
F 1 "470" H 2020 2755 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 280 -900 50  0001 C CNN
F 3 "" H 350 -900 50  0001 C CNN
	1    1950 2800
	0    1    1    0   
$EndComp
$Comp
L tinkerforge:CONN_01X02 P10
U 1 1 5893CB53
P 2350 2850
F 0 "P10" H 2427 2891 50  0000 L CNN
F 1 "LCD_BACKLIGHT" H 2427 2800 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 50  -700 50  0001 C CNN
F 3 "" H 50  -700 50  0001 C CNN
	1    2350 2850
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR038
U 1 1 5893CBDF
P 2100 2950
F 0 "#PWR038" H 400 -250 50  0001 C CNN
F 1 "GND" H 2105 2777 50  0000 C CNN
F 2 "" H 400 0   50  0001 C CNN
F 3 "" H 400 0   50  0001 C CNN
	1    2100 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 2800 2150 2800
Wire Wire Line
	2150 2900 2100 2900
Wire Wire Line
	2100 2900 2100 2950
Wire Notes Line
	900  3200 3400 3200
Text Notes 3400 3300 2    60   ~ 0
LCD (HD44780 compatible)
Text Label 2700 2600 2    39   ~ 0
LCD_DB7
Text Label 1550 2500 0    39   ~ 0
SCK
$Comp
L nrf24l01-connector:NRF24L01 U6
U 1 1 5898A9B8
P 2800 7000
F 0 "U6" H 2750 7637 60  0000 C CNN
F 1 "NRF24L01" H 2750 7531 60  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_2x04" H -6150 6250 60  0001 C CNN
F 3 "" H -6150 6250 60  0000 C CNN
	1    2800 7000
	1    0    0    -1  
$EndComp
$Comp
L FTController-rescue:LD1117S33TR U1
U 1 1 5898B92E
P 1150 6800
F 0 "U1" H 1150 7117 50  0000 C CNN
F 1 "LD1117S33TR" H 1150 7026 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-223" H -400 -100 50  0001 C CNN
F 3 "" H -400 -200 50  0001 C CNN
	1    1150 6800
	1    0    0    -1  
$EndComp
$Comp
L device:C C10
U 1 1 5898BA78
P 1600 6950
F 0 "C10" H 1715 6996 50  0000 L CNN
F 1 "100n" H 1715 6905 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H -612 -550 50  0001 C CNN
F 3 "" H -650 -400 50  0001 C CNN
	1    1600 6950
	1    0    0    -1  
$EndComp
$Comp
L device:CP C11
U 1 1 5898BAFC
P 2050 6950
F 0 "C11" H 2168 6996 50  0000 L CNN
F 1 "10u" H 2168 6905 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2.5" H 638 -550 50  0001 C CNN
F 3 "" H 600 -400 50  0001 C CNN
	1    2050 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 6750 2050 6750
Wire Wire Line
	1600 6800 1600 6750
Connection ~ 1600 6750
Wire Wire Line
	1150 7050 1150 7250
Wire Wire Line
	1150 7250 1600 7250
Wire Wire Line
	1600 7100 1600 7250
Connection ~ 1600 7250
$Comp
L power1:GND #PWR039
U 1 1 5898C292
P 1750 7300
F 0 "#PWR039" H -50 -250 50  0001 C CNN
F 1 "GND" H 1755 7127 50  0000 C CNN
F 2 "" H -50 0   50  0001 C CNN
F 3 "" H -50 0   50  0001 C CNN
	1    1750 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 7300 1750 7250
Connection ~ 1750 7250
$Comp
L power1:+5V #PWR040
U 1 1 5898C70D
P 700 6700
F 0 "#PWR040" H -150 -50 50  0001 C CNN
F 1 "+5V" H 715 6873 50  0000 C CNN
F 2 "" H -150 100 50  0001 C CNN
F 3 "" H -150 100 50  0001 C CNN
	1    700  6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	700  6700 700  6750
Wire Wire Line
	700  6750 750  6750
Wire Wire Line
	2050 6800 2050 6750
Connection ~ 2050 6750
Wire Wire Line
	2050 7100 2050 7250
Connection ~ 2050 7250
$Comp
L tinkerforge:CONN_01X02 J1
U 1 1 5898D388
P 3850 6800
F 0 "J1" H 3928 6841 50  0000 L CNN
F 1 "RF" H 3928 6750 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 350 -50 50  0001 C CNN
F 3 "" H 350 -50 50  0001 C CNN
	1    3850 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 6950 3650 6950
Text Label 3650 6950 2    60   ~ 0
SCK
Wire Wire Line
	3350 7050 3650 7050
Wire Wire Line
	3350 7150 3650 7150
Text Label 3650 7050 2    60   ~ 0
MOSI
Text Label 3650 7150 2    60   ~ 0
MISO
Wire Wire Line
	3650 6750 3350 6750
Wire Wire Line
	3350 6850 3650 6850
NoConn ~ 3350 7250
$Comp
L tinkerforge:CONN_01X02 J2
U 1 1 58A22804
P 4150 7150
F 0 "J2" H 4228 7191 50  0000 L CNN
F 1 "RF_A" H 4228 7100 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 650 300 50  0001 C CNN
F 3 "" H 650 300 50  0001 C CNN
	1    4150 7150
	-1   0    0    -1  
$EndComp
$Comp
L tinkerforge:CONN_01X02 J3
U 1 1 58A22F3B
P 4150 7400
F 0 "J3" H 4228 7441 50  0000 L CNN
F 1 "RF_B" H 4228 7350 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 650 550 50  0001 C CNN
F 3 "" H 650 550 50  0001 C CNN
	1    4150 7400
	-1   0    0    -1  
$EndComp
Text GLabel 4400 7100 2    60   Input ~ 0
PWM_RX1
Text GLabel 4400 7200 2    60   Input ~ 0
PWM_RX2
Wire Wire Line
	4400 7100 4350 7100
Wire Wire Line
	4400 7200 4350 7200
Wire Wire Line
	4350 7350 4850 7350
Wire Wire Line
	4350 7450 4850 7450
Text Label 4850 7350 2    60   ~ 0
JOYL_X
Text Label 4850 7450 2    60   ~ 0
JOYL_Y
$Comp
L power1:+9V #PWR041
U 1 1 58A2802F
P 2350 750
F 0 "#PWR041" H 2350 600 50  0001 C CNN
F 1 "+9V" H 2365 923 50  0000 C CNN
F 2 "" H 2350 750 50  0000 C CNN
F 3 "" H 2350 750 50  0000 C CNN
	1    2350 750 
	1    0    0    -1  
$EndComp
$Comp
L device:D D3
U 1 1 58A28106
P 2050 800
F 0 "D3" H 2050 584 50  0000 C CNN
F 1 "SB560" H 2050 675 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-41_SOD81_Vertical_KathodeUp" H 2050 800 50  0001 C CNN
F 3 "" H 2050 800 50  0000 C CNN
F 4 "D" H 2050 800 60  0001 C CNN "Spice_Primitive"
F 5 "1N4001" H 2050 800 60  0001 C CNN "Spice_Model"
F 6 "N" H 2050 800 60  0001 C CNN "Spice_Netlist_Enabled"
	1    2050 800 
	-1   0    0    1   
$EndComp
Connection ~ 2050 1150
Wire Wire Line
	2050 1200 2050 1150
Wire Wire Line
	2350 800  2350 750 
Wire Wire Line
	1450 800  1400 800 
Text Label 2750 800  2    60   ~ 0
V_MEAS
Connection ~ 2350 800 
Wire Wire Line
	2200 800  2350 800 
$Comp
L device:Polyfuse F1
U 1 1 58A83F95
P 1600 800
F 0 "F1" V 1375 800 50  0000 C CNN
F 1 "1.5A" V 1466 800 50  0000 C CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7_W2.5_P5" H -1700 -100 50  0001 L CNN
F 3 "" H -1750 100 50  0001 C CNN
	1    1600 800 
	0    1    1    0   
$EndComp
Wire Wire Line
	1900 800  1750 800 
Wire Wire Line
	2300 5650 2650 5650
NoConn ~ 2300 5550
Text Notes 2450 5450 0    60   ~ 0
Changes to V1.0:\nCollector and Basis\nwere switched
Wire Wire Line
	3100 1150 3550 1150
Wire Wire Line
	1400 1150 1450 1150
Wire Wire Line
	1400 1150 1400 1200
Wire Wire Line
	3550 1150 3550 1200
Wire Wire Line
	4650 2850 4650 2950
Wire Wire Line
	4650 2950 4650 3150
Wire Wire Line
	4750 5050 4750 5150
Wire Wire Line
	4750 5150 4750 5250
Wire Wire Line
	4100 1100 4100 1150
Wire Wire Line
	9800 3750 9900 3750
Wire Wire Line
	9800 4250 9900 4250
Wire Wire Line
	10300 4000 10300 4250
Wire Wire Line
	2250 4200 2250 4250
Wire Wire Line
	1600 6750 1550 6750
Wire Wire Line
	1600 7250 1750 7250
Wire Wire Line
	1750 7250 2050 7250
Wire Wire Line
	2050 6750 1600 6750
Wire Wire Line
	2050 7250 2150 7250
Wire Wire Line
	2050 1150 2200 1150
Wire Wire Line
	2350 800  2750 800 
$EndSCHEMATC
