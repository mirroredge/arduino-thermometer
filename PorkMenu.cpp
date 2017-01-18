/*
 * PorkMenu.cpp
 *
 *  Created on: Sep 4, 2015
 *      Author: mike
 */


#include "PorkMenu.h"

PorkMenu::PorkMenu(){

}
void PorkMenu::begin(LcdState *lcd_ptr){
	_lcd = lcd_ptr;
}
void PorkMenu::display(){
	 char *line1 = "Check Pork Temp";
		 	char *line2 = "";
		 	_lcd->set_display(line1, line2, 0, WHITE);

}
void PorkMenu::up(){
	_lcd->increment_state();

}
void PorkMenu::down(){
    _lcd->decerement_state();

}
void PorkMenu::left(){

}
void PorkMenu::right(){

}
void PorkMenu::select(){
    _lcd->set_state(3);
}

char *PorkMenu::state(){
  return "PORK MENU";
}
