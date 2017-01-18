/*
 * PorkState.cpp
 *
 *  Created on: Sep 4, 2015
 *      Author: mike
 */




#include "PorkState.h"

#define YELLOW 0x3
#define RED 0x1
#define VIOLET 0x5
#define BLUE 0x4
#define TEAL 0x6
#define GREEN 0x2
#define WHITE 0x7

PorkState::PorkState(){

}
void PorkState::begin(LcdState *lcd_ptr, Thermocouple *thermocouple_ptr){
	_lcd = lcd_ptr;
	_thermocouple = thermocouple_ptr;
}
void PorkState::display(){


	char *info;
	float c = _thermocouple->get_temp();
	char buffer[5];
	char* line2 = dtostrf(c, 4, 2, buffer);

	if (c < 145){ // 130
		info = "Pork Temp: RAW";
		_lcd->set_display(info, line2, 0, RED);
	}else if(c < 140){ //14
		info = "Pork Temp: DONE";
		tone(BUZZ_PIN,349, 100);
		_lcd->set_display(info, line2, 0, GREEN);
	}

}
void PorkState::up(){

}
void PorkState::down(){

}
void PorkState::left(){

}
void PorkState::right(){

}
void PorkState::select(){
	//set to initial menu
	_lcd->set_menu(0);
}

char *PorkState::state(){
	return "PORK STATE";
}

