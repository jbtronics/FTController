#pragma once

#ifndef _CHARS_h
#define _CHARS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

extern byte copyright_char[8];

#define CHAR_COPYRIGHT (uint8_t)0

#endif