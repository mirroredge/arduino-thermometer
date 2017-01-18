/*
 * PorkMenu.h
 *
 *  Created on: Sep 4, 2015
 *      Author: mike
 */



#ifndef PORKMENU_H_
#define PORKMENU_H_

#include "LcdState.h"
#include "StateFunction.h"
#include <stdlib.h>


class PorkMenu: public StateFunction{
	public:
	PorkMenu();
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




#endif /* PORKMENU_H_ */
