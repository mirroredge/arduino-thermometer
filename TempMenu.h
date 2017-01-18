/*
 * TempMenu.h
 *
 *  Created on: Sep 3, 2015
 *      Author: mike
 */

#ifndef TEMPMENU_H_
#define TEMPMENU_H_

#include "LcdState.h"
#include "StateFunction.h"

class TempMenu: public StateFunction{
	public:
	 TempMenu();
	 void begin(LcdState *);
	 void display();
	 void up();
	 void down();
	 void left();
	 void right();
	 void select();
	 char * state();
	private:
	  LcdState *_lcd;
};




#endif /* TEMPMENU_H_ */
