/*
 * TempMenu.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: mike
 */

#include "TempMenu.h"

#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

TempMenu::TempMenu(){

}
void TempMenu::begin(LcdState *lcd_ptr){
	_lcd = lcd_ptr;
}
void TempMenu::display(){
	char *line1 = "Get Current Temp";
	char *line2 = "";
	_lcd->set_display(line1, line2, 0, WHITE);
}
void TempMenu::up(){
	_lcd->increment_state();
}
void TempMenu::down(){
    _lcd->decerement_state();
}
void TempMenu::left(){

}
void TempMenu::right(){

}
void TempMenu::select(){
	Serial.println("Setting state to temp state");
	//0 is the position of TempState in the array
    _lcd->set_state(0);
}
char * TempMenu::state(){
    return "TEMP MENU";
}
