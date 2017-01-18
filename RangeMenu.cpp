/*
 * range_setting.cpp
 *
 *  Created on: Sep 2, 2015
 *      Author: mike
 */

#include "RangeMenu.h"
#define TEAL 0x6
RangeMenu::RangeMenu()
{

}

void RangeMenu::begin(LcdState *s,RangeValue *rv){
	_range = 5;
	_tmp = 100;
	_lcd = s;
	_pos = 0;
	_rv = rv;
}

void RangeMenu::display(){
	char *line1 = "Select Range";
	//char *line2 = "R: 5   T: 100 ";
	//char line2[16] = "R: 5   T: 100 ";
	String line2 = String();
	line2.concat("R:");
	line2.concat(_range);
	line2.concat(" T:");
	line2.concat(_tmp);

	//String range_s = String(_range);
	//String tmp_s = String(_tmp);
	//String s = String();
	//s.concat(&range_s, &tmp_s);



	_lcd->set_display(line1, line2.c_str(), 0, TEAL);
}

void RangeMenu::up(){
	_lcd->increment_state();
}
void RangeMenu::down(){
    _lcd->decerement_state();
}
void RangeMenu::left(){
	if (_pos == 0){
   _range--;
	}else{
		_tmp--;
	}
}
void RangeMenu::right(){
	if(_pos == 0){
	    _range++;
	}else{
		_tmp++;
	}
}
void RangeMenu::select(){
	_pos++;
	if(_pos > 1){
		//selected both range and temp now update range state and go to that state
		_rv->set_range(_range);
		_rv->set_temp(_tmp);
		_lcd->set_state(4);
		_pos = 0;
	}
}
char * RangeMenu::state(){
	return "RANGE MENU";
}
