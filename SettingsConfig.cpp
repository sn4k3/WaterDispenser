#include "SettingsConfig.h"
#include <EEPROM.h>

SettingsStruct Settings = {
	CONFIG_VERSION,
	true,
	true,
	true,
	true,
	true
};

void SettingsConfigClass::init()
{
	load();
}

bool SettingsConfigClass::load() {
	for (unsigned int i = 0; i < strlen(CONFIG_VERSION); i++)
	{
		if (EEPROM.read(CONFIG_START + i) != CONFIG_VERSION[i])
			return false;
	}

	for (unsigned int t = 0; t<sizeof(Settings); t++)
		*((char*)&Settings + t) = EEPROM.read(CONFIG_START + t);

	return true;
}

void SettingsConfigClass::save() {
	for (unsigned int t = 0; t<sizeof(Settings); t++)
		EEPROM.write(CONFIG_START + t, *((char*)&Settings + t));
}


SettingsConfigClass SettingsConfig;

