/*
 * ChickenState.h
 *
 *  Created on: Sep 4, 2015
 *      Author: mike
 */

#ifndef CHICKENSTATE_H_
#define CHICKENSTATE_H_

#include "Thermocouple.h"

#include "LcdState.h"
#include "StateFunction.h"
#include<stdlib.h>

class ChickenState: public StateFunction{
	public:
	 ChickenState();
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



#endif /* CHICKENSTATE_H_ */
