/*
 * SteakState.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: mike
 */


/*
 * TempState.cpp
 *
 *  Created on: Sep 2, 2015
 *      Author: mike
 */

#include "SteakState.h"

#define YELLOW 0x3
#define RED 0x1
#define VIOLET 0x5
#define BLUE 0x4
#define TEAL 0x6
#define GREEN 0x2
#define WHITE 0x7

SteakState::SteakState(){

}
void SteakState::begin(LcdState *lcd_ptr, Thermocouple *thermocouple_ptr){
	lcd = lcd_ptr;
	_thermocouple = thermocouple_ptr;
}
void SteakState::display(){
    char *info;
    float c = _thermocouple->get_temp();
    char buffer[5];
    char* line2 = dtostrf(c, 4, 2, buffer);

    if (c < 130){ // 130
    	info = "Steak Temp: RAW";
        lcd->set_display(info, line2, 0, RED);
    }else if(c < 140){ //14
    	info = "Steak Temp: RARE";
        lcd->set_display(info, line2, 0, VIOLET);
    }else if(c < 145){ //150
    	info = "Steak Temp: MED RARE";
        lcd->set_display(info, line2, 0, BLUE);
    }else if(c < 160){ //155
    	info = "Steak Temp: MED";
        lcd->set_display(info, line2, 0, TEAL);
    }else{ // 160
    	info = "Steak Temp: WELL";
        lcd->set_display(info, line2, 0, GREEN);
    }
}
void SteakState::up(){

}
void SteakState::down(){

}
void SteakState::left(){

}
void SteakState::right(){

}
void SteakState::select(){
	//set to initial menu
	lcd->set_menu(0);
}

char *SteakState::state(){
  return "STEAK STATE";
}





