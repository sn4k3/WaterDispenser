// 
// 
// 

#include "Ping.h"



NewPing sonar(PING_TRIGGER_PIN, PING_ECHO_PIN, PING_MAX_DISTANCE);

void PingClass::init()
{
	
}

void PingClass::loop()
{

}

void PingClass::on()
{

}

void PingClass::off()
{


}

void PingClass::disable()
{
	if (!Settings.ping) return;
	Settings.ping = false;
	SettingsConfig.save();
}

void PingClass::enable()
{
	if (Settings.ping) return;
	Settings.ping = true;
	SettingsConfig.save();
}

unsigned long PingClass::getDistanceCm()
{
	if (!Settings.ping) return 0;
	return sonar.ping_cm();
}

PingClass Ping;

