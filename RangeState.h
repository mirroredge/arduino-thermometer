/*
 * RangeState.h
 *
 *  Created on: Sep 4, 2015
 *      Author: mike
 */

#ifndef RANGESTATE_H_
#define RANGESTATE_H_

#include "RangeValue.h"
#include "LcdState.h"
#include "StateFunction.h"
#include <stdlib.h>

class RangeState: public StateFunction{
	public:
	 RangeState();
	 void begin(LcdState *, Thermocouple *, RangeValue *);
	 void display();
	 void up();
	 void down();
	 void left();
	 void right();
	 void select();
	 char *state();
	private:
	  LcdState *_lcd;
	  Thermocouple *_thermocouple;
	  RangeValue *_range_value;
};

#endif /* RANGESTATE_H_ */
