// SettingsConfig.h

#ifndef _SETTINGSCONFIG_h
#define _SETTINGSCONFIG_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Config.h"

struct SettingsStruct {
	char version[3];
	bool watersensor;
	bool ping;
	bool ledstrip;
	bool buzzer;
	bool laser;
};

class SettingsConfigClass
{
 public:
	void init();
	bool load();
	void save();
};

extern SettingsConfigClass SettingsConfig;
extern SettingsStruct Settings;

#endif

