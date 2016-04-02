#include <EEPROM.h>
#include <Wire.h> 
#include <SPI.h>
#include "LibraryClass.h"
#include <JeeLib.h>
#include "Config.h"
#include "SettingsConfig.h"
#include <LiquidCrystal_I2C.h>
#include "Display.h"

#include <NewPing.h>
#include "Ping.h"
#include "Manager.h"

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "BME280.h"

#include <OnewireKeypad.h>
#include "Keypad.h"

// must be defined in case we're using the watchdog for low-power waiting
ISR(WDT_vect) { Sleepy::watchdogEvent(); }


void setup()
{
	Serial.begin(115200);
	Display.init();
	delay(1000);

	SettingsConfig.init();
	Manager.init();
	Ping.init();
	BME280.init();
	
}

void loop()
{
	Display.loop();
	Ping.loop();
	Manager.loop();
	BME280.loop();
	lcd.clear();
	BME280.update();
	lcd.print(BME280.data.temperature);
	lcd.print(" ");
	lcd.print(BME280.data.humidity);
	lcd.print(" ");
	lcd.print(BME280.data.altitude);
	lcd.print(" ");
	lcd.print(BME280.data.pressure);
	delay(2000);
	

	if(Manager.isSleeping())
	{
		Sleepy::loseSomeTime(DEEP_SLEEP_IDLE);
	}
	else if (Manager.isIdle())
	{
		Sleepy::loseSomeTime(IDLE_SLEEP_DELAY);
	}
	else if (Manager.isRunning())
	{
		if(RUNNING_SLEEP_DELAY > 0)
		{
			Sleepy::loseSomeTime(RUNNING_SLEEP_DELAY);
		}
	}
}

/*
void i2cScan()
{
	byte error, address;
	int nDevices;

	Serial.println("Scanning...");

	nDevices = 0;
	for (address = 1; address < 127; address++)
	{
		// The i2c_scanner uses the return value of
		// the Write.endTransmisstion to see if
		// a device did acknowledge to the address.
		Wire.beginTransmission(address);
		error = Wire.endTransmission();

		if (error == 0)
		{
			Serial.print("I2C device found at address 0x");
			if (address<16)
				Serial.print("0");
			Serial.print(address, HEX);
			Serial.println("  !");

			nDevices++;
		}
		else if (error == 4)
		{
			Serial.print("Unknow error at address 0x");
			if (address<16)
				Serial.print("0");
			Serial.println(address, HEX);
		}
	}
	if (nDevices == 0)
		Serial.println("No I2C devices found\n");
	else
		Serial.println("done\n");
}*/