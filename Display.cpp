// 
// 
// 

#include "Display.h"

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void DisplayClass::init()
{
	lcd.begin(20, 4);               // initialize the lcd 
	lcd.home();                   // go home
	lcd.println("HELLO TIAGO");
}

void DisplayClass::loop()
{
	DELAY_FUNC(2000);
	on();
	DELAY_FUNC(2000);
	off();
	
}

void DisplayClass::setBackLight(uint8_t value) const
{
	lcd.setBacklight(value);
}

void DisplayClass::backlight() const
{
	lcd.backlight();
}

void DisplayClass::noBacklight() const
{
	lcd.noBacklight();
}

void DisplayClass::on() const
{
	lcd.on();
}

void DisplayClass::off() const
{
	lcd.off();
}

DisplayClass Display;

