/*
 * Thermocouple.cpp
 *
 *  Created on: Sep 2, 2015
 *      Author: mike
 */

#include "Thermocouple.h"

Thermocouple::Thermocouple(){

}
void Thermocouple::begin(int8_t thermoCLK, int8_t thermoCS, int8_t thermoDO){
	thermocouple = new Adafruit_MAX31855(thermoCLK, thermoCS, thermoDO);
}
float Thermocouple::get_temp(){
	return thermocouple->readFarenheit();
}
