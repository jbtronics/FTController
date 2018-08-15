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

#include "helpers.h"

unsigned long count = 0;

extern config_struct config;

void init_all()
{
	init_motors();
	SoftPWMBegin();
	init_counter();
}

void init_counter()
{
	pinMode(PIN_COUNT, INPUT_PULLUP);
}

void pcint_handler()
{
	if (config.counter_debounce == 1) //If debounce is enabled we need to check if the func is 
	{
		static long lasttime = millis();
		if (millis() - lasttime > COUNTER_DEBOUNCE)
		{
			count++;
			lasttime = millis();
		}
	}
	else
	{
		count++;
	}

}

unsigned long counter_val()
{
	return count;
}
 
void counter_reset()
{
	count = 0;
}

void init_motors()
{
	pinMode(PWM_LX1, OUTPUT);
	pinMode(PWM_LX2, OUTPUT);
	pinMode(PWM_RX1, OUTPUT);
	pinMode(PWM_RX2, OUTPUT);
	pinMode(PWM_LY1, OUTPUT);
	pinMode(PWM_LY2, OUTPUT);
	pinMode(PWM_RY1, OUTPUT);
	pinMode(PWM_RY2, OUTPUT);
}

void motor_output_digtal(uint8_t motor, uint8_t mode)
{
	static uint8_t motors_state = 0B00000000;
	uint16_t m1,m2;
	switch (motor)
	{
	case MOTOR_LX:
		m1 = PWM_LX1;
		m2 = PWM_LX2;
		break;
	case MOTOR_LY:
		m1 = PWM_LY1;
		m2 = PWM_LY2;
		break;
	case MOTOR_RX:
		m1 = PWM_RX1;
		m2 = PWM_RX2;
		break;
	case MOTOR_RY:
		m1 = PWM_RY1;
		m2 = PWM_RY2;
		break;
	}

	/*
	//Halt the Motor for a short time, so it can change its direction
	//TODO: Dont use delay for that.
	if (bitRead(motors_state, motor) == 1 && mode) //Only wait when we really change the dir
	{
		digitalWrite(m1, LOW);
		digitalWrite(m2, LOW);
		delay(MOTOR_DELAY);
	}
	*/

#ifdef MOTOR_INVERT
#define MOTOR !
#else
#define MOTOR
#endif 

	switch (mode)
	{
	
	case MOTOR_FWD:
		SoftPWMSet(m1, MOTOR 255);
		SoftPWMSet(m2, MOTOR LOW);
		bitSet(motors_state, motor); //Set the bit, that the motor is moving currently
		break;
	case MOTOR_REV:
		SoftPWMSet(m1, MOTOR LOW);
		SoftPWMSet(m2, MOTOR 255);
		bitSet(motors_state, motor); //Set the bit, that the motor is moving currently
		break;
	case MOTOR_HALT:
	default:
		SoftPWMSet(m1, MOTOR LOW);
		SoftPWMSet(m2, MOTOR LOW);
		bitClear(motors_state, motor); //Clear the bit, that the motor is moving currently
	}
}

void motor_output_analog(uint8_t motor, int16_t val)
{
	uint16_t m1, m2;
	switch (motor)
	{
	case MOTOR_LX:
		m1 = PWM_LX1;
		m2 = PWM_LX2;
		break;
	case MOTOR_LY:
		m1 = PWM_LY1;
		m2 = PWM_LY2;
		break;
	case MOTOR_RX:
		m1 = PWM_RX1;
		m2 = PWM_RX2;
		break;
	case MOTOR_RY:
		m1 = PWM_RY1;
		m2 = PWM_RY2;
		break;
	}

	if (val > TOLERANCE_P)
	{
		val = map(val, TOLERANCE_P, MAXIMUM_P, 0, 300);
		if (val > 255) val = 255;
		SoftPWMSet(m1, val);
		SoftPWMSet(m2, 0);
	}
	else if (val < TOLERANCE_N)
	{
		val = map(val, TOLERANCE_N, MAXIMUM_N, 0, 300);
		if (val > 255) val = 255;
		SoftPWMSet(m1, 0);
		SoftPWMSet(m2, val);
	}
	else
	{
		SoftPWMSet(m1, 0);
		SoftPWMSet(m2, 0);
	}
}

void motor_output_analog_raw(uint8_t motor, int16_t val)
{
	uint16_t m1, m2;
	switch (motor)
	{
	case MOTOR_LX:
		m1 = PWM_LX1;
		m2 = PWM_LX2;
		break;
	case MOTOR_LY:
		m1 = PWM_LY1;
		m2 = PWM_LY2;
		break;
	case MOTOR_RX:
		m1 = PWM_RX1;
		m2 = PWM_RX2;
		break;
	case MOTOR_RY:
		m1 = PWM_RY1;
		m2 = PWM_RY2;
		break;
	}

	if (val > 0)
	{
		if (val > 255) val = 255;
		SoftPWMSet(m1, val);
		SoftPWMSet(m2, 0);
	}
	else if (val < 0)
	{
		if (val < -255) val = -255;
		SoftPWMSet(m1, 0);
		SoftPWMSet(m2, -val);
	}
	else
	{
		SoftPWMSet(m1, 0);
		SoftPWMSet(m2, 0);
	}
}

uint16_t read_MCU_volt()
{
	long result; // Read 1.1V reference against AVcc 
	ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1); 
	delay(5); // Wait for Vref to settle 
	ADCSRA |= _BV(ADSC); // Convert 
	while (bit_is_set(ADCSRA,ADSC)); 
	result = ADCL; 
	result |= ADCH<<8; 
	result = VOLT_REF_CAL / result; // Back-calculate AVcc in mV 
	return result;
}

uint16_t read_input_volt()
{
#ifdef DISPLAY_FIX
	pinMode(MEAS_VOLT, INPUT);
	pinMode(MEAS_VOLT, LOW);
#endif
	// Use 1.1V Reference
	analogReference(INTERNAL);
	analogRead(MEAS_VOLT);	//Really change it
	delay(8); //Wait until ref settles
	long volt = analogRead(MEAS_VOLT);
	if (volt == 1023) //If maxed out change Reference for bigger measure frame
	{
		uint16_t vcc = read_MCU_volt();	//Read 5V value
		volt = analogRead(MEAS_VOLT);
		volt = (volt * vcc) / 1023;
	}
	else // Value is in ADC range-> use precision Reference
	{
		//Calculate voltage on ADC input
		volt = (volt * REF_1V1) / 1023;
	}
	

	//Calculate voltage before divider
	volt = volt * (VOLT_DIV1 + VOLT_DIV2) / VOLT_DIV2;
	//Add offset
	volt = volt + VOLT_OFFSET;

	analogReference(DEFAULT);
#ifdef DISPLAY_FIX
	pinMode(MEAS_VOLT, OUTPUT);
#endif // DISPLAY_FIX
	return volt;
}

uint16_t read_output_current()
{
	static uint16_t old = 0;
	static uint8_t count = 1;
	static uint32_t avg = 0;

	// Use 1.1V Reference
	analogReference(INTERNAL);
	analogRead(MEAS_CURR);	//Really change it
	delay(8); //Wait until ref settles
	unsigned long volt = analogRead(MEAS_CURR);

	//Calculate voltage on ADC input
	volt = (volt * C_REF_1V1) / 1023L;
	//volt = volt + CURRENT_V_OFFSET;

	//Calculate voltage before divider
	volt = 1000L * volt / SHUNT_R;
	//Add offset
	//volt = volt + CURRENT_OFFSET;

	analogReference(DEFAULT);

	avg = avg + volt;
	count++;

	//Calculate the new avg value
	if (count >= CURRENT_AVG_N)
	{
		old = avg / CURRENT_AVG_N;
		count = 1;
		avg = 0;
	}

	return old;
}


int16_t map_joy_with_table(int16_t val, const uint8_t table[25])
{
	if (val > 0 && val < TOLERANCE_P)
		return 0;
	if (val < 0 && val > TOLERANCE_N)
		return 0;

	int16_t pwm;
	if (val > 0)
	{
		pwm = map(val, TOLERANCE_P, MAXIMUM_P, 0, 300);
	}
	else if (val < 0)
	{
		pwm = map(val, TOLERANCE_N, MAXIMUM_N, 0, 300);
	}
	
	if (pwm > 255) pwm = 255;

	uint8_t index = pwm / 10;

	if (val > 0)
		return pgm_read_byte(&(table[index]));
	else
		return - pgm_read_byte(&(table[index]));
}

void stop_motors()
{
	SoftPWMSet(MOTOR_LX1, 0);
	SoftPWMSet(MOTOR_LX2, 0);
	SoftPWMSet(MOTOR_LY1, 0);
	SoftPWMSet(MOTOR_LY2, 0);
	SoftPWMSet(MOTOR_RX1, 0);
	SoftPWMSet(MOTOR_RX2, 0);
	SoftPWMSet(MOTOR_RY1, 0);
	SoftPWMSet(MOTOR_RY2, 0);
}

double GetTemp(void)
{
	unsigned int wADC;
	double t;

	// The internal temperature has to be used
	// with the internal reference of 1.1V.
	// Channel 8 can not be selected with
	// the analogRead function yet.

	// Set the internal reference and mux.
	ADMUX = (_BV(REFS1) | _BV(REFS0) | _BV(MUX3));
	ADCSRA |= _BV(ADEN);  // enable the ADC

	delay(20);            // wait for voltages to become stable.

	ADCSRA |= _BV(ADSC);  // Start the ADC

						  // Detect end-of-conversion
	while (bit_is_set(ADCSRA, ADSC));

	// Reading register "ADCW" takes care of how to read ADCL and ADCH.
	wADC = ADCW;

	// The offset of 324.31 could be wrong. It is just an indication.
	t = (wADC - 324.31) / 1.22;

	// The returned temperature is in degrees Celsius.
	analogReference(DEFAULT);
	return t;
}
