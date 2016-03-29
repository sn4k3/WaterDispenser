#include "LibraryClass.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "Macros.h"
#include "Display.h"

void setup()
{
	delay(1000);
  /* add setup code here */
	Display.init();
}

void loop()
{
	Display.loop();
  /* add main program code here */

}
