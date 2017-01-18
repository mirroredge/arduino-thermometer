/*
 * TempState.h
 *
 *  Created on: Sep 2, 2015
 *      Author: mike
 */

#ifndef TEMPSTATE_H_
#define TEMPSTATE_H_

#include "LcdState.h"
#include "Thermocouple.h"
#include "StateFunction.h"
#include <stdlib.h>


class TempState: public StateFunction{
	public:
	 TempState();
	 void begin(LcdState *, Thermocouple *);
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



#endif /* TEMPSTATE_H_ */
