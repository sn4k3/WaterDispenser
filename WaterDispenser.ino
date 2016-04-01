#define LiquidCrystal_h

#include <EEPROM.h>
#include <Wire.h> 
#include "LibraryClass.h"
#include <JeeLib.h>
#include "Config.h"
#include "SettingsConfig.h"
#include <LiquidCrystal_I2C.h>
#include "Display.h"

#include <NewPing.h>
#include "Ping.h"
#include "Manager.h"

// must be defined in case we're using the watchdog for low-power waiting
ISR(WDT_vect) { Sleepy::watchdogEvent(); }


void setup()
{
	Display.init();
	delay(1000);
	//Serial.begin(115200);

	SettingsConfig.init();
	Manager.init();
	Ping.init();
	
}

void loop()
{
	Display.loop();
	Ping.loop();
	Manager.loop();

	if(Manager.isSleeping())
	{
		Sleepy::loseSomeTime(DEEP_SLEEP_IDLE);
	}
	else if (Manager.isIdle())
	{
		Sleepy::loseSomeTime(IDLE_SLEEP_DELAY);
	}
}
