// Manager.h

#ifndef _MANAGER_h
#define _MANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Config.h"

class ManagerClass
{
 public:
	 enum State
	 {
		 STATE_SLEEPING,	// Deep sleep, all sensors are disabled and big delay in loop
		 STATE_IDLE,	// Waiting for an action. In this case sensors are working before enter in sleep mode after a while
		 //STATE_WATTING, // Special mode, reserved
		 STATE_RUNNING, // While working (Pumping water)
		 //STATE_READY	// NOT USED
	 };

	void init();
	void loop();
	void awaketouch();
	void goSleep();
	void awake();
	bool isIdle();
	bool isSleeping();
	bool canStart();
	bool canStop();
	State *getState();

protected:
	State state;
	unsigned long lastOperationTime;
};

extern ManagerClass Manager;

#endif

