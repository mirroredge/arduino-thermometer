/*
 * SteakMenu.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: mike
 */

#include "SteakMenu.h"


#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

SteakMenu::SteakMenu(){

}
void SteakMenu::begin(LcdState *lcd_ptr){
	_lcd = lcd_ptr;
}
void SteakMenu::display(){
	char *line1 = "Check Steak Temp";
	char *line2 = "";
	_lcd->set_display(line1, line2, 0, WHITE);
}
void SteakMenu::up(){
	_lcd->increment_state();
}
void SteakMenu::down(){
    _lcd->decerement_state();
}

void SteakMenu::left(){

}
void SteakMenu::right(){

}
void SteakMenu::select(){
	Serial.println("Setting state to steak state");
	//0 is the position of TempState in the array
    _lcd->set_state(1);
}
char * SteakMenu::state(){
    return "STEAK MENU";
}
