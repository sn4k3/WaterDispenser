// Ping.h

#ifndef _PING_h
#define _PING_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Config.h"
#include <NewPing.h>

class PingClass : LibraryClass
{
 protected:


 public:
	void init();
	void loop();

	void on();
	void off();
	void disable();
	void enable();
	unsigned long getDistanceCm();
};

extern PingClass Ping;

#endif