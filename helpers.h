// helpers_c.h

#ifndef _HELPERS_C_h
#define _HELPERS_C_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "config.h"
#include "chars.h"

#include <SoftPWM.h>

/********************************
* Lookup Tables
*********************************/
//Square lookup (f(x)=51/125x^2)
const PROGMEM uint8_t TABLE_SQUARE[26] = {0, 0, 2, 4, 7,  10, 15, 20, 26, 33, 41, 49, 59, 69, 80, 92, 104, 118, 132, 147, 163, 180, 198, 216, 235, 255};
//Exponential lookup(f(x) = e^0.2216505418)
const PROGMEM uint8_t TABLE_EXP[26] = {0, 1, 1, 2, 2, 2, 3, 4, 6, 7, 9, 11, 14, 18, 22, 28, 35, 43, 54, 67, 84, 105, 131, 164, 204, 255};
//Logarithmic lookup(f(x) = 78.26655748 * ln(x+1)
const PROGMEM uint8_t TABLE_LOG[26] = { 0, 54, 86, 109, 126, 140, 152, 163, 172, 180, 188, 194, 201, 207, 212, 217, 222, 226, 230, 234, 238, 242, 245, 249, 252, 255 };
//Square root lookup(f(x) = 51 * SQRT(x))
const PROGMEM uint8_t TABLE_SQRT[26] = { 0, 51, 72, 88, 102, 114, 125, 135, 144, 153, 161, 169, 177, 184, 191, 198, 204, 210, 216, 222, 228, 233, 239, 245, 250, 255 };

/*********************************
*	Pin Defines
**********************************/

//PWM Outputs
#define PWM_LX1		9	//PB1
#define PWM_LX2		10	//PB2
#define PWM_LY1		5	//PD5
#define PWM_LY2		6	//PD6
#define PWM_RX1		A2	//PC2
#define PWM_RX2		A3	//PC3
#define PWM_RY1		3	//PD3
#define PWM_RY2		4	//PD4

//Joystick inputs
#define PIN_JOYL_X		A0
#define PIN_JOYL_Y		A1
#define PIN_JOYR_X		A6
#define PIN_JOYR_Y		A7
#define SW_L		2	//Joystick button on PD2

//Counter
#define PIN_COUNT		7	//PD

//LCD
#define LCD_RS		0	//PD0
#ifdef DISPLAY_FIX
#define LCD_E		MEAS_VOLT
#else
#define LCD_E		8	//PB0
#endif
#define LCD_D4		13	//PB5
#define LCD_D5		11	//PB3
#define LCD_D6		12	//PB4
#define LCD_D7		1	//PD1

//Measurement
#define	MEAS_VOLT	A5
#define MEAS_CURR	A4

/**************************
* Helper defines
***************************/
//Motors
#define MOTOR_LX	0
#define MOTOR_LY	1
#define MOTOR_RX	2
#define MOTOR_RY	3

#define MOTOR_HALT	0
#define MOTOR_FWD	1
#define MOTOR_REV	2

#define MOTOR_LX1	PWM_LX1
#define MOTOR_LX2	PWM_LX2
#define MOTOR_LY1	PWM_LY1
#define MOTOR_LY2	PWM_LY2
#define MOTOR_RX1	PWM_RX1
#define MOTOR_RX2	PWM_RX2
#define MOTOR_RY1	PWM_RY1
#define MOTOR_RY2	PWM_RY2

//Joysticks
//X and Y axis has to be switched
#define JOYL_X		PIN_JOYL_Y
#define JOYL_Y		PIN_JOYL_X
#define JOYR_X		PIN_JOYR_Y
#define JOYR_Y		PIN_JOYR_X


#define JOYSTICK_LX		0
#define JOYSTICK_LY		1
#define JOYSTICK_RX		2
#define JOYSTICK_RY		3

/*************************
* Modes
*************************/
#define MODE_NOTHING	0	//Dont react to input of the joysticks
#define MODE_DIGITAL	1	
#define MODE_ANALOG		2
#define MODE_EXP		3
#define MODE_SQUARE		4
#define MODE_LN			5
#define MODE_SQRT		6

#define MODE_MAX_VAL	6	//Whats the index of the Mode with the highest value
#define MODE_DEFAULT	MODE_DIGITAL

//Display mode
#define DISPLAY_INPUT	0	//Shows the input values of the joysticks
#define DISPLAY_VOLT	1	//Shows the input and MCU voltage
#define DISPLAY_OUT		2	//Shows the output values

#define DISPLAY_MAX_VAL	2
#define DISPLAY_DEFAULT	DISPLAY_VOLT

//Menu states
#define MENU_HIDDEN		0
#define MENU_SHOW		1

#define THRESHOLD_TIME	50

/************************
* EEPROM Adress defines
************************/
#define EEPROM_MODE		0x00
#define EEPROM_DISPLAY	0x01

/*************************
* Makros
*************************** */
#define motor_output_analog_table(motor, value, table) motor_output_analog_no_thre(motor, map_joy_with_table(value, table));


/*************************
* Functions declarations
**************************/
void init_all();
void init_motors();
void motor_output_digtal(uint8_t motor, uint8_t mode);
void motor_output_analog(uint8_t motor, int16_t value);
void motor_output_analog_raw(uint8_t motor, int16_t value);
uint16_t read_MCU_volt();	//Gets the voltage of the AVR (should be around 5V)
uint16_t read_input_volt();	//Gets the voltage of the input
int16_t map_joy_with_table(int16_t val, const uint8_t[25]); //Map the value using the given lookup table
void stop_motors();	//Halt all motors


#endif

