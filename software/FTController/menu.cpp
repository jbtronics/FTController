/*
Copyright (C) 2017  Jan Böhmer

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

#include "menu.h"
#include "helpers.h"
#include <LiquidCrystal.h>

extern LiquidCrystal lcd;
extern uint8_t menu;

extern uint8_t mode;
extern uint8_t display_mode;
extern uint8_t config_mode;
extern uint8_t emergency_halt;
extern uint8_t freeze;

extern config_struct config;

extern int16_t joysticks[4];
extern int16_t output_val[4];

/*******************************************
* MENU
*******************************************/

void show_menu()
{
	switch (menu)
	{
	case MENU_MODES:
		menu_modes();
		break;
	case MENU_DISPLAY:
		menu_display();
		break;
	case MENU_CONFIG:
		menu_config();
		break;
	default:
		lcd.print(F("ERROR"));
	}

	//Check if we should change the sub menu
	char action = menu_action_ly();
	if (action != 0)
	{
		if (menu + action > MENU_MAX_VAL) //When at end of the modes jump to the first one
			menu = 1;
		else if (menu + action < 1)
			menu = MENU_MAX_VAL;
		else
			menu += action;
	}
}

void menu_config()
{
	

	switch (config_mode)
	{
	case CONFIG_SPLASH:
		lcd.print(F("CONFIG"));
		lcd.setCursor(0, 1);
		lcd.print(F("MENU"));
		break;
	case CONFIG_HALT:
		lcd.print(F("EM.HALT:"));
		lcd.setCursor(0, 1);
		if (config.emergency_halt == 0)
			lcd.print("OFF");
		else
			lcd.print("ON");

		if (menu_action_rx() || menu_action_ry()) //Check if we should change value
			TOGGLE_SETTING(config.emergency_halt);
		break;
	case CONFIG_CUNIT:
		lcd.print(F("C.UNIT:"));
		lcd.setCursor(0, 1);
		if (config.counter_unit == CUNIT_HZ)
			lcd.print("Hz");
		else if (config.counter_unit == CUNIT_RPM)
			lcd.print("RPM");
		else
			lcd.print("Unknown");

		if (menu_action_rx() || menu_action_ry()) //Check if we should change value
			TOGGLE_SETTING(config.counter_unit);
		break;
	case CONFIG_CDEBOUNCE:
		lcd.print(F("I.DEBNC:"));
		lcd.setCursor(0, 1);
		if (config.counter_debounce == 0)
			lcd.print("OFF");
		else
			lcd.print("ON");

		if (menu_action_rx() || menu_action_ry()) //Check if we should change value
			TOGGLE_SETTING(config.counter_debounce);
		break;
	case CONFIG_CMULTI:
		lcd.print(F("C.MULTI:"));
		lcd.setCursor(0, 1);
		lcd.print(config.counter_multi + 1);
		config.counter_multi += menu_action_rx();
		config.counter_multi += 10 * menu_action_ry();
		break;
	case CONFIG_CDIVIDE:
		lcd.print(F("C.DIVIDE:"));
		lcd.setCursor(0, 1);
		lcd.print(config.counter_divide + 1);
		config.counter_divide += menu_action_rx();
		config.counter_divide += 10 * menu_action_ry();
		break;
	case CONFIG_VERSION1:
		lcd.print(F("VERSION:"));
		lcd.setCursor(0, 1);
		lcd.print(VERSION);
		break;
	case CONFIG_CREDIT:
		lcd.print(F("(C)J.Bo-"));
		lcd.setCursor(0, 1);
		lcd.print(F("ehmer"));
		break;
	default:
		lcd.print(F("Unknown"));
		break;
	}

	//Check if we should change the sub menu
	char action = menu_action_lx();
	if (action != 0)
	{
		if (config_mode + action > CONFIG_MAX_VAL) //When at end of the modes jump to the first one
			config_mode = 1;
		else if (config_mode + action < 1)
			config_mode = CONFIG_MAX_VAL;
		else
			config_mode += action;
	}
}

void menu_modes()
{
	lcd.print(F("MODE:"));
	lcd.setCursor(0, 1);
	switch (mode)
	{
	case MODE_NOTHING:
		lcd.print(F("None"));
		break;
	case MODE_DIGITAL:
		lcd.print(F("Digital"));
		break;
	case MODE_ANALOG:
		lcd.print(F("Linear"));
		break;
	case MODE_EXP:
		lcd.print(F("Exp"));
		break;
	case MODE_SQUARE:
		lcd.print(F("Square"));
		break;
	case MODE_LN:
		lcd.print(F("Log"));
		break;
	case MODE_SQRT:
		lcd.print(F("Sqrt"));
		break;
	default:
		lcd.print(F("UNKNOWN"));
		break;
	}

	//Change the mode
	char mode_action = menu_action_lx();
	if (mode_action != 0)
	{
		if (mode + mode_action > MODE_MAX_VAL) //When at end of the modes jump to the first one
			mode = 0;
		else if (mode_action + mode < 0)
			mode = MODE_MAX_VAL;
		else
			mode += mode_action;
	}
}

void menu_display()
{
	lcd.print(F("DISPLAY:"));
	lcd.setCursor(0, 1);
	switch (display_mode)
	{
	case DISPLAY_VOLT:
		lcd.print(F("Voltages"));
		break;
	case DISPLAY_INPUT:
		lcd.print(F("In Vals"));
		break;
	case DISPLAY_OUT:
		lcd.print(F("Out Vals"));
		break;
	case DISPLAY_RPM:
		lcd.print(F("RPM"));
		break;
	case DISPLAY_COUNT:
		lcd.print(F("Counter"));
		break;
	case DISPLAY_TEMP:
		lcd.print(F("Temp."));
		break;
	default:
		lcd.print(F("UNKNOWN"));
	}

	//Change the mode
	char mode_action = menu_action_lx();
	if (mode_action != 0)
	{
		if (display_mode + mode_action > DISPLAY_MAX_VAL) //When at end of the modes jump to the first one
			display_mode = 0;
		else if (mode_action + display_mode < 0)
			display_mode = DISPLAY_MAX_VAL;
		else
			display_mode += mode_action;
	}
}

static char menu_action_lx()
{
	static char lx_laststate = 0;
	static char lx_action = 0;
	static long lasttime = millis();

	if (joysticks[JOYSTICK_LX] > THRESHOLD_P)
	{
		if (millis() - lasttime > THRESHOLD_TIME && lx_laststate != -1)
		{
			lx_action = -1;
		}
		lx_laststate = -1;
	}
	else if (joysticks[JOYSTICK_LX] < THRESHOLD_N)
	{
		if (millis() - lasttime > THRESHOLD_TIME && lx_laststate != 1)
		{
			lx_action = 1;
		}
		lx_laststate = 1;
	}
	else
	{
		lx_laststate = 0;
	}

	if (lx_action != 0)
	{
		uint8_t tmp = lx_action;
		lx_action = 0;
		return tmp;
	}
	return 0;
}

static char menu_action_ly()
{
	static char lx_laststate = 0;
	static char lx_action = 0;
	static long lasttime = millis();

	if (joysticks[JOYSTICK_LY] > THRESHOLD_P)
	{
		if (millis() - lasttime > THRESHOLD_TIME && lx_laststate != -1)
		{
			lx_action = -1;
		}
		lx_laststate = -1;
	}
	else if (joysticks[JOYSTICK_LY] < THRESHOLD_N)
	{
		if (millis() - lasttime > THRESHOLD_TIME && lx_laststate != 1)
		{
			lx_action = 1;
		}
		lx_laststate = 1;
	}
	else
	{
		lx_laststate = 0;
	}

	if (lx_action != 0)
	{
		uint8_t tmp = lx_action;
		lx_action = 0;
		return tmp;
	}
	return 0;
}

static char menu_action_rx()
{
	static char lx_laststate = 0;
	static char lx_action = 0;
	static long lasttime = millis();

	if (joysticks[JOYSTICK_RX] > THRESHOLD_P)
	{
		if (millis() - lasttime > THRESHOLD_TIME && lx_laststate != -1)
		{
			lx_action = -1;
		}
		lx_laststate = -1;
	}
	else if (joysticks[JOYSTICK_RX] < THRESHOLD_N)
	{
		if (millis() - lasttime > THRESHOLD_TIME && lx_laststate != 1)
		{
			lx_action = 1;
		}
		lx_laststate = 1;
	}
	else
	{
		lx_laststate = 0;
	}

	if (lx_action != 0)
	{
		uint8_t tmp = lx_action;
		lx_action = 0;
		return tmp;
	}
	return 0;
}

static char menu_action_ry()
{
	static char lx_laststate = 0;
	static char lx_action = 0;
	static long lasttime = millis();

	if (joysticks[JOYSTICK_RY] > THRESHOLD_P)
	{
		if (millis() - lasttime > THRESHOLD_TIME && lx_laststate != -1)
		{
			lx_action = -1;
		}
		lx_laststate = -1;
	}
	else if (joysticks[JOYSTICK_RY] < THRESHOLD_N)
	{
		if (millis() - lasttime > THRESHOLD_TIME && lx_laststate != 1)
		{
			lx_action = 1;
		}
		lx_laststate = 1;
	}
	else
	{
		lx_laststate = 0;
	}

	if (lx_action != 0)
	{
		uint8_t tmp = lx_action;
		lx_action = 0;
		return tmp;
	}
	return 0;
}
