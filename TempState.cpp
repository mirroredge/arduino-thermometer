/*
 * TempState.cpp
 *
 *  Created on: Sep 2, 2015
 *      Author: mike
 */

#include "TempState.h"

#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

TempState::TempState(){

}
void TempState::begin(LcdState *lcd_ptr, Thermocouple *thermocouple_ptr){
	_lcd = lcd_ptr;
	_thermocouple = thermocouple_ptr;
}
void TempState::display(){
    char *info = "Current Temp";
    float c = _thermocouple->get_temp();
    char buffer[5];
    char* line2 = dtostrf(c, 4, 2, buffer);
    _lcd->set_display(info, line2, 0, WHITE);
}
void TempState::up(){

}
void TempState::down(){

}
void TempState::left(){

}
void TempState::right(){

}
void TempState::select(){
	//set to initial menu
	_lcd->set_menu(0);
}

char *TempState::state(){
  return "TEMP STATE";
}



