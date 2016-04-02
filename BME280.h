// BME280.h

#ifndef _BME280_h
#define _BME280_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Config.h"

struct BME280Data
{
	float temperature;
	float humidity;
	float pressure;
	float altitude;
};

class BME280Class : LibraryClass
{

protected:
	unsigned long lastReadTime;

 public:
	 BME280Data data;

	void init();
	void loop();
	void on();
	void off();
	float readTemperature();
	float readHumidity();
	float readPressure();
	float readAltitude();

	void update();
};

extern BME280Class BME280;

#endif

