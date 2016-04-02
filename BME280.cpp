// 
// 
// 

#include "BME280.h"

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C

void BME280Class::init()
{
	if (!bme.begin(0x76)) {
		//Serial.println("Could not find a valid BME280 sensor, check wiring!");
		return;
	}
	update();
}

void BME280Class::loop()
{
	if(millis() - lastReadTime > BME280_UPDATE_INTERVAL) {
		update();
	}
}

void BME280Class::on()
{
}

void BME280Class::off()
{
}

float BME280Class::readTemperature()
{
	return bme.readTemperature();
}

float BME280Class::readHumidity()
{
	return bme.readHumidity();
}

float BME280Class::readPressure()
{
	return bme.readPressure() / 100.0F;
}

float BME280Class::readAltitude()
{
	return bme.readAltitude(SEALEVELPRESSURE_HPA);
}

void BME280Class::update()
{
	data.temperature = readTemperature();
	data.humidity = readHumidity();
	data.pressure = readPressure();
	data.humidity = readAltitude();
	lastReadTime = millis();
}

BME280Class BME280;

