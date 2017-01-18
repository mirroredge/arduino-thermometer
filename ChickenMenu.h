/*
 * ChickenMenu.h
 *
 *  Created on: Sep 4, 2015
 *      Author: mike
 */

#ifndef CHICKENMENU_H_
#define CHICKENMENU_H_

#include "LcdState.h"
#include "StateFunction.h"
#include<stdlib.h>

class ChickenMenu: public StateFunction{
	public:
	ChickenMenu();
	 void begin(LcdState *);
	 void display();
	 void up();
	 void down();
	 void left();
	 void right();
	 void select();
	 char* state();
	private:
	  LcdState *_lcd;
};



#endif /* CHICKENMENU_H_ */
