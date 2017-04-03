#pragma once

#ifndef _CONFIG_H
#define _CONFIG_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define MOTOR_DELAY		40

#define VERSION			"0.1a"
#define VOLT_REF_CAL	1126400L

#define JOY_MID			512
#define MID_LX			JOY_MID
#define MID_LY			JOY_MID
#define MID_RX			JOY_MID
#define MID_RY			JOY_MID
#define TOLERANCE		50
#define TOLERANCE_P		TOLERANCE
#define TOLERANCE_N		-TOLERANCE
#define THRESHOLD		300			//When a joystick input should be treated as logic 1
#define THRESHOLD_P		THRESHOLD	//positive threshold
#define THRESHOLD_N		-THRESHOLD	//negative threshold
#define MAXIMUM			520
#define MAXIMUM_P		MAXIMUM
#define MAXIMUM_N		-MAXIMUM

#define VOLT_DIV1		965		
#define VOLT_DIV2		100
#define VOLT_OFFSET		150
#define REF_1V1			1100

#define DOUBLECLICK_TIME	300

#define DISPLAY_FIX				//Define this if you want to use the VOLT_MEASURE PIN for DISPLAY_E

#endif