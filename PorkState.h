/*
 * PorkState.h
 *
 *  Created on: Sep 4, 2015
 *      Author: mike
 */

#ifndef PORKSTATE_H_
#define PORKSTATE_H_


#include "Thermocouple.h"

#include "LcdState.h"
#include "StateFunction.h"
#include<stdlib.h>

class PorkState: public StateFunction{
	public:
	 PorkState();
	 void begin(LcdState *, Thermocouple *thermocouple_ptr);
	 void display();
	 void up();
	 void down();
	 void left();
	 void right();
	 void select();
	 char* state();
	private:
	  LcdState *_lcd;
	  Thermocouple *_thermocouple;
};


#endif /* PORKSTATE_H_ */
