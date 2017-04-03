#include <EEPROM.h>
#include <InputDebounce.h>
#include "helpers.h"
#include "config.h"
#include "chars.h"
#include <LiquidCrystal.h>

//Global objects
LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
static InputDebounce button;

uint8_t menu = MENU_HIDDEN;

uint8_t mode;
uint8_t display_mode;

int16_t joysticks[4];
int16_t output_val[4];

void setup()
{
	
	init_all();
	analogReference(DEFAULT);
	lcd.begin(8, 2);
	
	//Show Startup banner
	startup_banner();

	read_eeprom();
	//Override read modes
	//mode = MODE_DIGITAL;
	//mode = MODE_ANALOG;
	display_mode = DISPLAY_VOLT;

	button.registerCallbacks(button_pressedCallback, button_releasedCallback, button_pressedDurationCallback);
	button.setup(SW_L);
}

void loop()
{
	//update_volt();

	//Always read joystick values
	read_joysticks();
	
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
		switch (display_mode)
		{
		case DISPLAY_INPUT:
			display_input();
			break;
		case DISPLAY_VOLT:
			display_volt();
			break;
		case DISPLAY_OUT:
			display_out();
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

/*******************************************
* MENU
*******************************************/

inline void show_menu()
{
	static char lx_laststate = 0;
	static char lx_action = 0;
	static long lasttime = millis();

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

char menu_action_lx()
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
	//Calculate 
	joysticks[JOYSTICK_LX] = analogRead(JOYL_X) - MID_LX;
	joysticks[JOYSTICK_LY] = analogRead(JOYL_Y) - MID_LY;
	joysticks[JOYSTICK_RX] = analogRead(JOYR_X) - MID_RX;
	joysticks[JOYSTICK_RY] = analogRead(JOYR_Y) - MID_RY;
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
}

/***************************************************
* BUTTON HANDLERS
****************************************************/

void button_pressedCallback()
{
	if (menu == MENU_SHOW)	//Toggle menu visibility
	{
		menu = MENU_HIDDEN;
		eeprom_save();
	}
	else
		menu = MENU_SHOW;
}

void button_releasedCallback()
{
	
}

void button_pressedDurationCallback(unsigned long duration)
{
	
}