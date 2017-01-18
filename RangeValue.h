/*
 * RangeValue.h
 *
 *  Created on: Sep 4, 2015
 *      Author: mike
 */

#ifndef RANGEVALUE_H_
#define RANGEVALUE_H_

class RangeValue{
public:
	RangeValue();
	void set_range(int);
	void set_temp(int);
	int get_temp();
	int get_range();
private:
	int _range;
	int _tmp;
};



#endif /* RANGEVALUE_H_ */
