/*
 * Thermocouple.h
 *
 *  Created on: Sep 2, 2015
 *      Author: mike
 */

#ifndef THERMOCOUPLE_H_
#define THERMOCOUPLE_H_

#include <SPI.h>
#include "Adafruit_MAX31855.h"

class Thermocouple{
	public:
	  Thermocouple();
	  void begin(int8_t,int8_t,int8_t);
	  float get_temp();
	private:
	  Adafruit_MAX31855 *thermocouple;

};



#endif /* THERMOCOUPLE_H_ */
