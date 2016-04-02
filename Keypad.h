// Keypad.h

#ifndef _KEYPAD_h
#define _KEYPAD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Config.h"



char KEYS[] = {
	'1','2','3', 'A',
	'4','5','6', 'B',
	'7','8','9', 'C',
	'*','0','#', 'D'
};

class KeypadClass : LibraryClass
{
protected:
	char lastKeyPress;

 public:
	void init();
	void loop();
	void on();
	void off();
};

extern KeypadClass Keypad;

#endif

