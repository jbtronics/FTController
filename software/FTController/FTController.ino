/*
Copyright (C) 2017  Jan B�hmer

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


#include <EEPROM.h>
#include <InputDebounce.h>
#include "helpers.h"
#include "config.h"
#include "chars.h"
#include <LiquidCrystal.h>
#include <PinChangeInt.h>
#include "menu.h"

//Global objects
LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
static InputDebounce button;

uint8_t menu = MENU_HIDDEN;

uint8_t mode = MODE_DEFAULT;
uint8_t display_mode = DISPLAY_DEFAULT;
uint8_t config_mode = CONFIG_DEFAULT;
uint8_t emergency_halt;
uint8_t freeze = 0;

uint8_t failsafe = FAILSAFE_OFF;

config_struct config;

int16_t joysticks[4];
int16_t output_val[4];

void setup()
{
	
	init_all();
	analogReference(DEFAULT);
	lcd.begin(8, 2);

	config.emergency_halt = 0; //Disable emergency halt by default

	//Show Startup banner
	startup_banner();

	read_eeprom();
	//Override read modes
	//mode = MODE_DIGITAL;
	//mode = MODE_ANALOG;
	//display_mode = DISPLAY_VOLT;

	PCattachInterrupt(PIN_COUNT, pcint_handler, FALLING);

	button.registerCallbacks(button_pressedCallback, button_releasedCallback, button_pressedDurationCallback);
	button.setup(SW_L);
}

void loop()
{
	//update_volt();

	//First check for failsafe
	failsafe_check();

	//Always read joystick values
	read_joysticks();
	
	if (failsafe == FAILSAFE_OFF)
	{
		if (menu == MENU_HIDDEN) //Only execute Modes if Menu is hidden
		{
			switch (mode)
			{
			case MODE_DIGITAL:
				mode_digital();
				break;
			case MODE_ANALOG:
				mode_analog();
				break;
			case MODE_EXP:
				mode_exp();
				break;
			case MODE_SQUARE:
				mode_square();
				break;
			case MODE_LN:
				mode_log();
				break;
			case MODE_SQRT:
				mode_sqrt();
				break;
			default:
				break;
			}
		}

		update_display();
	}
	button.process(millis());

	//delay(100);
}


/*********************************************
* DISPLAY
**********************************************/
void update_display()
{
	static long lasttime = millis();
	if (millis() - lasttime > 100) //Update every 100ms
	{
		lcd.clear();
		if (menu != MENU_HIDDEN)
		{
			lasttime = millis();
			show_menu();
			return;
		}

		if (freeze == 1)
		{
			lasttime = millis();
			lcd.print("FREEZED");
			return;
		}
		switch (display_mode)
		{
		case DISPLAY_INPUT:
			display_input();
			break;
		case DISPLAY_VOLT:
			display_volt();
			break;
		case DISPLAY_POWER:
			display_power();
			break;
		case DISPLAY_OUT:
			display_out();
			break;
		case DISPLAY_RPM:
			display_rpm();
			break;
		case DISPLAY_COUNT:
			display_counter();
			break;
		case DISPLAY_TEMP:
			display_temp();
			break;
		}

		lasttime = millis();
	}
}

inline void display_input()
{
	//lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print(joysticks[JOYSTICK_LX]);
	lcd.setCursor(4, 0);
	lcd.print(joysticks[JOYSTICK_LY]);
	lcd.setCursor(0, 1);
	lcd.print(joysticks[JOYSTICK_RX]);
	lcd.setCursor(4, 1);
	lcd.print(joysticks[JOYSTICK_RY]);
}

void display_volt()
{
	//Input Voltage
	lcd.setCursor(0, 0);
	lcd.print(F("IN:"));
	uint16_t val = read_input_volt();
	if (val < 10000) //Insert space if only one digit
		lcd.print(" ");
	lcd.print(val / 1000.0, 1);
	lcd.setCursor(7, 0);
	lcd.print(F("V"));

	//5V Voltage
	lcd.setCursor(0, 1);
	lcd.print(F("5V:"));
	val = read_MCU_volt();
	if (val < 10000) //Insert space if only one digit
		lcd.print(" ");
	lcd.print(val / 1000.0, 1);
	lcd.setCursor(7, 1);
	lcd.print(F("V"));
}

void display_power()
{
	//Input Voltage
	lcd.setCursor(0, 0);
	lcd.print(F("U:"));
	uint16_t val = read_input_volt();
	if (val < 10000) //Insert space if only one digit
		lcd.print(" ");
	lcd.print(val / 1000.0, 2);
	lcd.setCursor(7, 0);
	lcd.print(F("V"));

	//Output Current
	lcd.setCursor(0, 1);
	lcd.print(F("I:"));
	val = read_output_current();
	//if (val < 10000) //Insert space if only one digit
		//lcd.print(" ");
	lcd.print(val / 1000.0 , 2);
	lcd.setCursor(6, 1);
	lcd.print(F("mA"));
}

void display_out()
{
	lcd.print(output_val[JOYSTICK_LX]);
	lcd.setCursor(4, 0);
	lcd.print(output_val[JOYSTICK_LY]);
	lcd.setCursor(0, 1);
	lcd.print(output_val[JOYSTICK_RX]);
	lcd.setCursor(4, 1);
	lcd.print(output_val[JOYSTICK_RY]);
}

void display_temp()
{
	lcd.print("Temp.");
	lcd.setCursor(0, 1);
	lcd.print(GetTemp());
}

void display_rpm()
{
	static long lasttime = millis();
	static float val = 0;
	if (millis() - lasttime > 1000)
	{
		val = (counter_val() * 1000.0) / (millis() - lasttime); // * 60;
		
		if (config.counter_unit == CUNIT_RPM)
			val = val * 60;

		if (config.counter_divide)
		{
			val = val / (config.counter_divide + 1);
		}

		if (config.counter_multi)
		{
			val = val * (config.counter_multi + 1);
		}

		counter_reset();
		lasttime = millis();
	}
	if (config.counter_unit == CUNIT_HZ)
		lcd.print("Hz:");
	else if (config.counter_unit == CUNIT_RPM)
		lcd.print("RPM:");

	if (config.counter_debounce == 1)
		lcd.print(" D");	//Print hint that debounce is activated

	if (config.counter_divide || config.counter_multi)
		lcd.print(" x");

	lcd.setCursor(0,1);

	if (config.counter_unit == CUNIT_HZ)
		lcd.print(val);
	else if (config.counter_unit == CUNIT_RPM)
		lcd.print(val, 0);	//Cut digits after the point, we dont have that precision
}

void display_counter()
{
	lcd.print(F("Counter:"));
	lcd.setCursor(0, 1);
	lcd.print(counter_val());
}


/********************************************
* MODE HANDLING
*********************************************/

inline void mode_digital()
{
	//LX Joystick
	if (joysticks[JOYSTICK_LX] < THRESHOLD_N)
		motor_output_digtal(MOTOR_LX, MOTOR_FWD);
	else if (joysticks[JOYSTICK_LX] > THRESHOLD_P)
		motor_output_digtal(MOTOR_LX, MOTOR_REV);
	else
		motor_output_digtal(MOTOR_LX, MOTOR_HALT);

	//LY Joystick
	if (joysticks[JOYSTICK_LY] < THRESHOLD_N)
		motor_output_digtal(MOTOR_LY, MOTOR_FWD);
	else if (joysticks[JOYSTICK_LY] > THRESHOLD_P)
		motor_output_digtal(MOTOR_LY, MOTOR_REV);
	else
		motor_output_digtal(MOTOR_LY, MOTOR_HALT);

	//RX Joystick
	if (joysticks[JOYSTICK_RX] < THRESHOLD_N)
		motor_output_digtal(MOTOR_RX, MOTOR_FWD);
	else if (joysticks[JOYSTICK_RX] > THRESHOLD_P)
		motor_output_digtal(MOTOR_RX, MOTOR_REV);
	else
		motor_output_digtal(MOTOR_RX, MOTOR_HALT);

	//RY Joystick
	if (joysticks[JOYSTICK_RY] < THRESHOLD_N)
		motor_output_digtal(MOTOR_RY, MOTOR_FWD);
	else if (joysticks[JOYSTICK_RY] > THRESHOLD_P)
		motor_output_digtal(MOTOR_RY, MOTOR_REV);
	else
		motor_output_digtal(MOTOR_RY, MOTOR_HALT);

}

inline void mode_analog()
{
	motor_output_analog(MOTOR_LX, joysticks[JOYSTICK_LX]);
	motor_output_analog(MOTOR_LY, joysticks[JOYSTICK_LY]);
	motor_output_analog(MOTOR_RX, joysticks[JOYSTICK_RX]);
	motor_output_analog(MOTOR_RY, joysticks[JOYSTICK_RY]);
}

inline void mode_exp()
{
	output_val[JOYSTICK_LX] = map_joy_with_table(joysticks[JOYSTICK_LX], TABLE_EXP);
	output_val[JOYSTICK_LY] = map_joy_with_table(joysticks[JOYSTICK_LY], TABLE_EXP);
	output_val[JOYSTICK_RX] = map_joy_with_table(joysticks[JOYSTICK_RX], TABLE_EXP);
	output_val[JOYSTICK_RY] = map_joy_with_table(joysticks[JOYSTICK_RY], TABLE_EXP);

	motor_output_analog_raw(MOTOR_LX ,output_val[JOYSTICK_LX]);
	motor_output_analog_raw(MOTOR_LY, output_val[JOYSTICK_LY]);
	motor_output_analog_raw(MOTOR_RX, output_val[JOYSTICK_RX]);
	motor_output_analog_raw(MOTOR_RY, output_val[JOYSTICK_RY]);
}

inline void mode_square()
{
	output_val[JOYSTICK_LX] = map_joy_with_table(joysticks[JOYSTICK_LX], TABLE_SQUARE);
	output_val[JOYSTICK_LY] = map_joy_with_table(joysticks[JOYSTICK_LY], TABLE_SQUARE);
	output_val[JOYSTICK_RX] = map_joy_with_table(joysticks[JOYSTICK_RX], TABLE_SQUARE);
	output_val[JOYSTICK_RY] = map_joy_with_table(joysticks[JOYSTICK_RY], TABLE_SQUARE);

	motor_output_analog_raw(MOTOR_LX, output_val[JOYSTICK_LX]);
	motor_output_analog_raw(MOTOR_LY, output_val[JOYSTICK_LY]);
	motor_output_analog_raw(MOTOR_RX, output_val[JOYSTICK_RX]);
	motor_output_analog_raw(MOTOR_RY, output_val[JOYSTICK_RY]);
}

inline void mode_log()
{
	output_val[JOYSTICK_LX] = map_joy_with_table(joysticks[JOYSTICK_LX], TABLE_LOG);
	output_val[JOYSTICK_LY] = map_joy_with_table(joysticks[JOYSTICK_LY], TABLE_LOG);
	output_val[JOYSTICK_RX] = map_joy_with_table(joysticks[JOYSTICK_RX], TABLE_LOG);
	output_val[JOYSTICK_RY] = map_joy_with_table(joysticks[JOYSTICK_RY], TABLE_LOG);

	motor_output_analog_raw(MOTOR_LX, output_val[JOYSTICK_LX]);
	motor_output_analog_raw(MOTOR_LY, output_val[JOYSTICK_LY]);
	motor_output_analog_raw(MOTOR_RX, output_val[JOYSTICK_RX]);
	motor_output_analog_raw(MOTOR_RY, output_val[JOYSTICK_RY]);
}

inline void mode_sqrt()
{
	output_val[JOYSTICK_LX] = map_joy_with_table(joysticks[JOYSTICK_LX], TABLE_SQRT);
	output_val[JOYSTICK_LY] = map_joy_with_table(joysticks[JOYSTICK_LY], TABLE_SQRT);
	output_val[JOYSTICK_RX] = map_joy_with_table(joysticks[JOYSTICK_RX], TABLE_SQRT);
	output_val[JOYSTICK_RY] = map_joy_with_table(joysticks[JOYSTICK_RY], TABLE_SQRT);

	motor_output_analog_raw(MOTOR_LX, output_val[JOYSTICK_LX]);
	motor_output_analog_raw(MOTOR_LY, output_val[JOYSTICK_LY]);
	motor_output_analog_raw(MOTOR_RX, output_val[JOYSTICK_RX]);
	motor_output_analog_raw(MOTOR_RY, output_val[JOYSTICK_RY]);
}


/******************************************************
* HELPER FUNCTIONS
******************************************************/
void read_joysticks()
{
	if (freeze == 0) //Dont read the joysticks if the freeze mode is activated
	{
		//Calculate 
		joysticks[JOYSTICK_LX] = analogRead(JOYL_X) - MID_LX;
		joysticks[JOYSTICK_LY] = analogRead(JOYL_Y) - MID_LY;
		joysticks[JOYSTICK_RX] = analogRead(JOYR_X) - MID_RX;
		joysticks[JOYSTICK_RY] = analogRead(JOYR_Y) - MID_RY;
	}
}

void startup_banner()
{
	//Show Product name
	lcd.print(F("FTContr-"));
	lcd.setCursor(0, 1);
	lcd.print(F("oller"));
	delay(750);
	lcd.clear();
	//Show Version
	lcd.print(F("Version:"));
	lcd.setCursor(0, 1);
	lcd.print(F(VERSION));
	delay(750);
	lcd.clear();
	//Show Copyright
	lcd.print(F("(C)J.Bo-"));
	lcd.setCursor(0, 1);
	lcd.print(F("ehmer"));
	delay(750);
	lcd.clear();
}

void eeprom_save()
{
	//Save Mode
	EEPROM.update(EEPROM_MODE, mode);
	//Save display mode
	EEPROM.update(EEPROM_DISPLAY, display_mode);
	//Save emergency halt option
	EEPROM.update(EEPROM_HALT, config.emergency_halt);
	//Save Counter unit setting
	EEPROM.update(EEPROM_CUNIT, config.counter_unit);
	//Save Counter Debountce setting
	EEPROM.update(EEPROM_CDEB, config.counter_debounce);
	//Save Counter Multiplier
	EEPROM.update(EEPROM_CMULTI, config.counter_multi);
	//Save Counter Divider
	EEPROM.update(EEPROM_CDIVIDE, config.counter_divide);
}

void read_eeprom()
{
	uint8_t tmp = EEPROM.read(EEPROM_MODE);
	if (tmp > MODE_MAX_VAL) //IF we dont know the read mode, then set it to the default one
		mode = MODE_DEFAULT;
	else
		mode = tmp;

	//Display mode
	tmp = EEPROM.read(EEPROM_DISPLAY);
	if (tmp > DISPLAY_MAX_VAL) //IF we dont know the read mode, then set it to the default one
		display_mode = DISPLAY_DEFAULT;
	else
		display_mode = tmp;

	tmp = EEPROM.read(EEPROM_HALT);
	if (tmp > 1)
		config.emergency_halt = 0;
	else
		config.emergency_halt = tmp;

	tmp = EEPROM.read(EEPROM_CUNIT);
	if (tmp > 1)
		config.counter_unit = 0;
	else
		config.counter_unit = tmp;

	tmp = EEPROM.read(EEPROM_CDEB);
	if (tmp > 1)
		config.counter_debounce = 0;
	else
		config.counter_debounce = tmp;
	
	tmp = EEPROM.read(EEPROM_CMULTI);
	if (tmp == 0xFF)
		config.counter_multi = 0;
	else
		config.counter_multi = tmp;

	tmp = EEPROM.read(EEPROM_CDIVIDE);
	if (tmp == 0xFF)
		config.counter_divide = 0;
	else
		config.counter_divide = tmp;
}

inline void failsafe_check()
{
	if (config.emergency_halt  && display_mode != DISPLAY_COUNT)
	{
		if (bitRead(PIND, 7) == 0)	//When Count input low, then activate the failsafe mode
		{
			failsafe = FAILSAFE_HALT;
		}
	}

	if (failsafe != FAILSAFE_OFF)
	{
		stop_motors();

		uint8_t tmp = 0;
		
		lcd.home();

		switch (failsafe)
		{
		case FAILSAFE_HALT:
			lcd.print(F("Em.Halt "));
			break;
		default:
			lcd.print(F("FAILSAFE"));
			break;
		}

		lcd.setCursor(0, 1);
		lcd.print(F("PressBTN"));
		
	}
}


/***************************************************
* BUTTON HANDLERS
****************************************************/

void button_pressedCallback()
{
	static long lasttime = 0;
	
	if (failsafe == FAILSAFE_OFF)
	{
		if (menu != MENU_HIDDEN)	//Toggle menu visibility
		{
			menu = MENU_HIDDEN;
			eeprom_save();
		}
		else
		{
			menu = MENU_SHOW;
			stop_motors();
		}

		if (millis() - lasttime < DOUBLECLICK_TIME) //If button was double clicked, activate FREEZE mode
		{
			if (display_mode == DISPLAY_COUNT)
			{
				counter_reset();
				menu = MENU_HIDDEN;
			}
			else
			{
				if (freeze == 0)
					freeze = 1;
				else
					freeze = 0;
				menu = MENU_HIDDEN;		//Hide menu
			}
			
		}
	}
	else
	{
		//Only switch of failsafe mode, when joysticks are not giving an output val, or the freeze mode is activated (because then the joystick vals donte become updated)
		if (joysticks[JOYSTICK_LX] < THRESHOLD_P && joysticks[JOYSTICK_LX] > THRESHOLD_N
			&& joysticks[JOYSTICK_LY] < THRESHOLD_P && joysticks[JOYSTICK_LY] > THRESHOLD_N
			&& joysticks[JOYSTICK_RX] < THRESHOLD_P && joysticks[JOYSTICK_RX] > THRESHOLD_N
			&& joysticks[JOYSTICK_RY] < THRESHOLD_P && joysticks[JOYSTICK_RY] > THRESHOLD_N 
			|| freeze == 1)
		{
			failsafe = FAILSAFE_OFF;
		}
	}

	lasttime = millis();
}

void button_releasedCallback()
{
	
}

void button_pressedDurationCallback(unsigned long duration)
{

}
