
#include <SPI.h>
#include "Adafruit_MAX31855.h"
#include <Wire.h>
#include <utility/Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>

#include "RangeState.h"
#include "LcdState.h"
#include "RangeMenu.h"
#include "TempMenu.h"
#include "SteakMenu.h"
#include "SteakState.h"
#include "TempState.h"
#include "RangeValue.h"
#include "ChickenMenu.h"
#include "ChickenState.h"
#include "PorkMenu.h"
#include "PorkState.h"


#include "Thermocouple.h"
int thermoCLK = 5;
int thermoCS = 4;
int thermoDO = 3;

// Initialize the Thermocouple
//Adafruit_MAX31855 thermocouple = Adafruit_MAX31855(thermoCLK, thermoCS, thermoDO);
// initialize the library with the numbers of the interface pins
//Adafruit_RGBLCDShield lcd_screen = Adafruit_RGBLCDShield();
Thermocouple thermocouple = Thermocouple();

LcdState lcd = LcdState();

TempMenu tm = TempMenu();
SteakMenu sm = SteakMenu();
ChickenMenu cm = ChickenMenu();
PorkMenu pm = PorkMenu();
RangeMenu rm = RangeMenu();


TempState ts = TempState();
SteakState ss = SteakState();
ChickenState cs = ChickenState();
PorkState ps = PorkState();
RangeState rs = RangeState();

RangeValue rv = RangeValue();


// These #defines make it easy to set the backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

#define BUZZ_PIN 2

void setup() {
	Serial.begin(9600);
	pinMode(BUZZ_PIN, OUTPUT);
	thermocouple.begin(thermoCLK, thermoCS, thermoDO);

	// wait for MAX chip to stabilize

	ts.begin(&lcd, &thermocouple);
	ss.begin(&lcd, &thermocouple);
	cs.begin(&lcd, &thermocouple);
	ps.begin(&lcd, &thermocouple);
	rs.begin(&lcd, &thermocouple, &rv);

	StateFunction * states[5] = {&ts, &ss, &cs, &ps, &rs};
	
	tm.begin(&lcd);
	sm.begin(&lcd);
	cm.begin(&lcd);
	pm.begin(&lcd);
	rm.begin(&lcd, &rv);

	StateFunction * menus[5] = {&tm, &sm, &cm, &pm, &rm};

	lcd.begin(&thermocouple, menus, 3, states, 3);
	//Default range to 5


}

void loop() {
	lcd.process_input();
}
