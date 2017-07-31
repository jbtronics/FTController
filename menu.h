// menu.h

#ifndef _MENU_h
#define _MENU_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

//Functions declarations

void show_menu();
void menu_config();
void menu_modes();
void menu_display();
static char menu_action_lx();
static char menu_action_ly();
static char menu_action_rx();
static char menu_action_ry();


#endif

