// 
// 
// 

#include "Manager.h"
#include "Display.h"
#include "Ping.h"

void ManagerClass::init()
{
	lastOperationTime = millis();
	state = STATE_IDLE;
}

void ManagerClass::loop()
{
	if(state == STATE_IDLE)
	{
		if(millis() - lastOperationTime >= TIME_BEFORE_DEEPSLEEP)
		{
			Display.goSleep();
			goSleep();
			return;
		}
	}

}

void ManagerClass::awaketouch()
{
	if(isIdle())
	{
		awake();
		return;
	}
	lastOperationTime = millis();
}

void ManagerClass::goSleep()
{
	state = STATE_SLEEPING;
	Display.noBacklight();
	Ping.off();
}

void ManagerClass::awake()
{
	state = STATE_IDLE;
	awaketouch();
	Display.noBacklight();
	Ping.on();
}


bool ManagerClass::isSleeping()
{
	return state == STATE_SLEEPING;
}

bool ManagerClass::isIdle()
{
	return state == STATE_IDLE;
}

bool ManagerClass::isRunning()
{
	return state == STATE_RUNNING;
}

bool ManagerClass::canStart()
{
	return state == STATE_IDLE;
}

bool ManagerClass::canStop()
{
	return state == STATE_RUNNING;
}

ManagerClass::State *ManagerClass::getState()
{
	return &state;
}

ManagerClass Manager;

