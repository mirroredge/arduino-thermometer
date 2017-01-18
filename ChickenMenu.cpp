/*
 * ChickenMenu.cpp
 *
 *  Created on: Sep 4, 2015
 *      Author: mike
 */



#include "ChickenMenu.h"

#define YELLOW 0x3
#define RED 0x1
#define VIOLET 0x5
#define BLUE 0x4
#define TEAL 0x6
#define GREEN 0x2
#define WHITE 0x7

ChickenMenu::ChickenMenu(){

}
void ChickenMenu::begin(LcdState *lcd_ptr){
	_lcd = lcd_ptr;
}
void ChickenMenu::display(){
	 char *line1 = "Check Chk Temp";
		 	char *line2 = "";
		 	_lcd->set_display(line1, line2, 0, WHITE);

}
void ChickenMenu::up(){
	_lcd->increment_state();

}
void ChickenMenu::down(){
    _lcd->decerement_state();

}
void ChickenMenu::left(){

}
void ChickenMenu::right(){

}
void ChickenMenu::select(){
    _lcd->set_state(2);
}

char *ChickenMenu::state(){
  return "CHICKEN MENU";
}
