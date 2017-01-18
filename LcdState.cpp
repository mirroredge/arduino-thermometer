/*
 * LcdState.cpp
 *
 *  Created on: Sep 2, 2015
 *      Author: mike
 */

#include "LcdState.h"

LcdState::LcdState(){

	_rand = random(0,1000);
	//_menus[0] = &RangeMenu(0, this);
}

void LcdState::begin(Thermocouple *thermocouple_ref, StateFunction *menus[], int menu_size, StateFunction *states[], int states_size){
	_lcd = Adafruit_RGBLCDShield();

	_current_state = INITIAL_STATE;
	_current_menu = INITIAL_MENU;

	Serial.print("Initial State: ");
	Serial.println(_current_state);
	Serial.print("Initial Menu: ");
	Serial.println(_current_menu);

	_lcd.begin(16, 2);

	for(int i = 0; i < MENU_SIZE; i++){
		_menus[i] = menus[i];
		Serial.print(i);
		Serial.print("::");
		Serial.println(_menus[i]->state());
	}
	for(int i = 0; i < STATES_SIZE; i++){
		_states[i] = states[i];
		Serial.print(i);
		Serial.print("::");
		Serial.println(_states[i]->state());

	}
	Serial.print("Initial State: ");
	Serial.println(LcdState::get_current()->state());
	for(int i = 0; i < MENU_SIZE; i++){
		Serial.print(i);
		Serial.print("::");
		Serial.println(_menus[i]->state());
	}
	for(int i = 0; i < STATES_SIZE; i++){
		Serial.print(i);
		Serial.print("::");
		Serial.println(_states[i]->state());

	}
}

int LcdState::get_state(){
	return _current_state;
}
int LcdState::get_mode(){
	return _current_menu;
}

void LcdState::increment_state(){
	if(_current_state >= 0){
		Serial.print("incrementing state: ");
		_current_state ++;
		if (_current_state >= STATES_SIZE){
			_current_state = 0;
		}
		Serial.println(_current_state);
	}else{
		Serial.print("incrementing menu: ");
		_current_menu ++;
		if (_current_menu >= MENU_SIZE){
			_current_menu = 0;
		}
		Serial.println(_current_menu);
	}
}
void LcdState::decerement_state(){
	if(_current_state >= 0){
		_current_state --;
		if (_current_state < 0){
			_current_state = STATES_SIZE-1;
		}
	}else{
		_current_menu --;
		if (_current_menu < 0){
			_current_menu = MENU_SIZE-1;
		}
	}
}
void LcdState::set_menu(int menu){
	_current_state = -1;
	_current_menu = menu;
}
void LcdState::set_state(int state){
	_current_state = state;
	_current_menu = -1;
}


StateFunction *LcdState::get_current(){
	Serial.print("get_current: ");
	Serial.println(_current_state);
	Serial.println(_current_menu);
	if (_current_state >= 0){
		Serial.print("state: ");
		Serial.println(_current_state);
		return _states[_current_state];
	}else{
		Serial.print("menu: ");
		Serial.println(_menus[_current_menu]->state());
		return _menus[_current_menu];
	}
}


void LcdState::process_input(){
	long start = millis();
	long end = millis();
	int change = 0;
	while(((end-start) <= 1000) && (change == 0)){
		end = millis();
		uint8_t buttons = _lcd.readButtons();
		if (buttons) {
			_lcd.begin(16, 2);
			_lcd.clear();
			_lcd.setCursor(0,0);
			if (buttons & BUTTON_UP) {
				Serial.println("UP PRESSED");
				LcdState::get_current()->up();
				change = 1;
			}
			if (buttons & BUTTON_DOWN) {
				Serial.println("DOWN PRESSED");
				LcdState::get_current()->down();
				change = 1;
			}
			if (buttons & BUTTON_LEFT) {
				Serial.println("LEFT PRESSED");
				LcdState::get_current()->left();
				change = 1;
			}
			if (buttons & BUTTON_RIGHT) {
				Serial.println("RIGHT PRESSED");
				LcdState::get_current()->right();
				change = 1;
			}
			if (buttons & BUTTON_SELECT) {
				Serial.println("SELECT PRESSED");
				LcdState::get_current()->select();
				change = 1;
			}
		}
	}

	Serial.print("In state: ");
	Serial.println(LcdState::get_current()->state());
	LcdState::get_current()->display();
}

void LcdState::set_display(const char *line1, const char *line2, int state_change, int backlight){

	Serial.println("Setting lcd display");
	Serial.print("Line 1: ");
	Serial.println(line1);
	Serial.print("Line 2: ");
	Serial.println(line2);
	//_lcd.begin(16, 2);
	_lcd.clear();
	_lcd.setBacklight(backlight);
	_lcd.setCursor(0, 1);
	_lcd.print(line2);
	_lcd.setCursor(0, 0);
	_lcd.print(line1);

}




