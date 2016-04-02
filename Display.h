// Display.h

#ifndef _DISPLAY_h
#define _DISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <LiquidCrystal_I2C.h>
#include "Config.h"

class DisplayClass : LibraryClass
{
  public:
	 enum State
	 {
		 STATE_IDLE,
		 STATE_PUMPING,
		 STATE_MENU
	 };
	void init();
	void loop();
	void goSleep();
	/*!
	@function
	@abstract   Sets the pin to control the backlight.
	@discussion Sets the pin in the device to control the backlight. The behaviour
	of this method is very dependent on the device. Some controllers support
	dimming some don't. Please read the actual header file for each individual
	device. The setBacklightPin method has to be called before setting the backlight
	or the adequate backlight control constructor.
	@see setBacklightPin.

	NOTE: The prefered methods to control the backlight are "backlight" and
	"noBacklight".

	@param      0..255 - the value is very dependent on the LCD. However,
	BACKLIGHT_OFF will be interpreted as off and BACKLIGHT_ON will drive the
	backlight on.
	*/
	void setBackLight(bool value) const;

	/*!
	@function
	@abstract   Switch-on the LCD backlight.
	@discussion Switch-on the LCD backlight.
	The setBacklightPin has to be called before setting the backlight for
	this method to work. @see setBacklightPin.
	*/
	void backlight() const;

	/*!
	@function
	@abstract   Switch-off the LCD backlight.
	@discussion Switch-off the LCD backlight.
	The setBacklightPin has to be called before setting the backlight for
	this method to work. @see setBacklightPin.
	*/
	void noBacklight() const;

	/*!
	@function
	@abstract   Switch on the LCD module.
	@discussion Switch on the LCD module, it will switch on the LCD controller
	and the backlight. This method has the same effect of calling display and
	backlight. @see display, @see backlight
	*/
	void on();

	/*!
	@function
	@abstract   Switch off the LCD module.
	@discussion Switch off the LCD module, it will switch off the LCD controller
	and the backlight. This method has the same effect of calling noDisplay and
	noBacklight. @see display, @see backlight
	*/
	void off();

	void handleKey(char key);

protected:
	State state;

	// Mililiters on display by user input
	unsigned short mililiters;
};

extern DisplayClass Display;
extern LiquidCrystal_I2C lcd;

#endif

