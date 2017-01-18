/*
 * StateFunction.h
 *
 *  Created on: Sep 2, 2015
 *      Author: mike
 */

#ifndef STATEFUNCTION_H_
#define STATEFUNCTION_H_

class StateFunction{
	public:
	  virtual void display();
	  virtual void up();
	  virtual void down();
	  virtual void left();
	  virtual void right();
	  virtual void select();
	  virtual char* state();

	private:
};





#endif /* STATEFUNCTION_H_ */
