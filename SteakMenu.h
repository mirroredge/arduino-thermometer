/*
 * SteakMenu.h
 *
 *  Created on: Sep 3, 2015
 *      Author: mike
 */

#ifndef STEAKMENU_H_
#define STEAKMENU_H_

#include "LcdState.h"
#include "StateFunction.h"

class SteakMenu: public StateFunction{
	public:
	 SteakMenu();
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





#endif /* STEAKMENU_H_ */
