/*
 * range_setting.h
 *
 *  Created on: Sep 2, 2015
 *      Author: mike
 */

#ifndef RANGEMENU_H_
#define RANGEMENU_H_

#include "RangeValue.h"
#include "LcdState.h"
#include "StateFunction.h"

#include <stdlib.h>


class RangeMenu: public StateFunction{
	public:
	 RangeMenu();
	 void begin(LcdState*, RangeValue *);
	 void display();
	 void up();
	 void down();
	 void left();
	 void right();
	 void select();
	 char * state();
	private:
	 int _pos;
	  int _range;
	  int _tmp;
	  LcdState *_lcd;
	  RangeValue *_rv;
};


#endif /* RANGEMENU_H_ */
