/*
 * SteakState.h
 *
 *  Created on: Sep 3, 2015
 *      Author: mike
 */

#ifndef STEAKSTATE_H_
#define STEAKSTATE_H_

#include "Thermocouple.h"

#include "LcdState.h"
#include "StateFunction.h"
#include<stdlib.h>

class SteakState: public StateFunction{
	public:
	 SteakState();
	 void begin(LcdState *, Thermocouple*);
	 void display();
	 void up();
	 void down();
	 void left();
	 void right();
	 void select();
	 char* state();
	private:
	  LcdState *lcd;
	  Thermocouple *_thermocouple;
};

#endif /* STEAKSTATE_H_ */
