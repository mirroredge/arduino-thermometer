/*
 * states.h
 *
 *  Created on: Sep 2, 2015
 *      Author: mike
 */


#ifndef LCDSTATE_H_
#define LCDSTATE_H_

#include "arduino.h"
#include "Thermocouple.h"

#include <Wire.h>
#include <utility/Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>

#include "StateFunction.h"


#define STATES_SIZE 5
#define MENU_SIZE 5
#define INITIAL_STATE -1
#define INITIAL_MENU 0

#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7


/*
 * State maps
 * 0 -> temp
 * 1 -> range
 *
 * Menu maps
 * 0 -> range setting
 */
class LcdState{
	public:
	  int _rand;

	  LcdState();
	  void begin(Thermocouple *, StateFunction *[], int , StateFunction *[], int);
	  int get_state();
	  int get_mode();
	  void increment_state();
	  void decerement_state();
	  void set_menu(int);
	  void set_state(int);
	  void process_input();
	  void set_display(const char *line1, const char * line2, int state_change, int backlight);


	private:

	  StateFunction *get_current();

	  int _current_state;
	  int _current_menu;
	  Adafruit_RGBLCDShield _lcd;
	  Thermocouple _thermocouple;
	  StateFunction *_states[STATES_SIZE];
	  StateFunction *_menus[MENU_SIZE];
};



#endif /* STATE_H_ */
