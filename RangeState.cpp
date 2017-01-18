/*
 * RangeState.cpp
 *
 *  Created on: Sep 4, 2015
 *      Author: mike
 */

#include "RangeState.h"
#define RED 0x1
#define GREEN 0x2

#define BUZZ_PIN 2

RangeState::RangeState()
{

}

void RangeState::begin(LcdState *s, Thermocouple *t, RangeValue * rv){
	_lcd = s;
	_thermocouple = t;
	_range_value = rv;
}

void RangeState::display(){
	int range = _range_value->get_range();
	int temp = _range_value->get_temp();
	String line1 = String();
	line1.concat("Range:");
	line1.concat(range);
	line1.concat(" Tmp:");
	line1.concat(temp);
	float c = _thermocouple->get_temp();
	char line2[5];
	dtostrf(c, 4, 2, line2);

	if((c <= (temp + range)) && (c >= (temp - range))){
		_lcd->set_display(line1.c_str(), line2, 0, GREEN);
	}else{
		_lcd->set_display(line1.c_str(), line2, 0, RED);
		tone(BUZZ_PIN,349, 100);
	}
}

void RangeState::up(){
	_lcd->increment_state();
}
void RangeState::down(){
    _lcd->decerement_state();
}
void RangeState::left(){
}
void RangeState::right(){
}
void RangeState::select(){
	_lcd->set_menu(0);
}
char * RangeState::state(){
	return "RANGE STATE";
}

