// 
// 
// 

#include "Display.h"

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
//PortI2C myI2C(1);
//LiquidCrystalI2C lcd(myI2C);

void DisplayClass::init()
{
	lcd.begin(20, 4);               // initialize the lcd 
	lcd.home();                   // go home
	lcd.print(F("  WATER DISPENSER"));
	lcd.setCursor(0, 1);
	lcd.print(F("    Version: "VERSION""));
	lcd.setCursor(0, 2);
	lcd.print(F("   INITALIZING..."));
	lcd.setCursor(0, 3);
	lcd.print(F("  Tiago Conceicao"));
}

void DisplayClass::loop()
{
	state = STATE_IDLE;
}

void DisplayClass::goSleep()
{
	lcd.clear();
	lcd.home();
	lcd.print(F("Low Power Mode"));
	lcd.setCursor(0, 1);
	lcd.print(F("Going to sleep in:"));
	lcd.setCursor(0, 2);
	lcd.print(F("3"));
	DELAY_FUNC(333);
	for (uint8_t i = 0; i < 3; i++)
	{
		lcd.print(F("."));
		DELAY_FUNC(333);

	}

	lcd.print(F("2"));
	DELAY_FUNC(333);
	for (uint8_t i = 0; i < 3; i++)
	{
		lcd.print(F("."));
		DELAY_FUNC(333);

	}

	lcd.print(F("1"));
	DELAY_FUNC(333);
	for (uint8_t i = 0; i < 3; i++)
	{
		lcd.print(F("."));
		DELAY_FUNC(333);

	}
	lcd.print(F("0!"));
	DELAY_FUNC(333);

	for (uint8_t i = 0; i < 3; i++)
	{
		noBacklight();
		DELAY_FUNC(500);
		backlight();
		DELAY_FUNC(500);

	}
}

void DisplayClass::setBackLight(bool value) const
{
	if (value)
		backlight();
	else
		noBacklight();
}

void DisplayClass::backlight() const
{
	lcd.backlight();
}

void DisplayClass::noBacklight() const
{
	lcd.noBacklight();
}

void DisplayClass::on()
{
	lcd.on();
}

void DisplayClass::off()
{
	lcd.off();
}

void DisplayClass::handleKey(char key)
{

}

DisplayClass Display;

