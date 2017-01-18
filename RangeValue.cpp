/*
 * RangeValue.cpp
 *
 *  Created on: Sep 4, 2015
 *      Author: mike
 */

#include "RangeValue.h"

RangeValue::RangeValue(){

}
void RangeValue::set_range(int r){
	_range = r;
}
void RangeValue::set_temp(int t){
	_tmp = t;
}
int RangeValue::get_temp(){
	return _tmp;
}
int RangeValue::get_range(){
    return _range;
}


