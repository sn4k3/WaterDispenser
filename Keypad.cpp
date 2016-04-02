// 
// 
// 

#include "Keypad.h"
#include <OnewireKeypad.h>

OnewireKeypad <Print, 12 > kp(Serial, KEYS, 4, 3, A3, 4700, 1000);

void KeypadClass::init() {}

void KeypadClass::loop()
{
	if(!Manager.isRunning())
	{
		char key = kp.Getkey();
		if (key) {
			lastKeyPress = key;
			uint8_t keystate = kp.Key_State();
			kp.LatchKey();

			if (!Manager.isSleeping()) {
				Display.handleKey(key);
			}

			Manager.awaketouch();
		}
	}
}

void KeypadClass::on() {}
void KeypadClass::off() {}

KeypadClass Keypad;

