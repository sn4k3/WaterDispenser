# WaterDispenser


# Consuptions
## LCD

Each option is based on a good initialized lcd module. A line of text is printed to the LCD on setup.

###### Code

Upload this code and do the proper connections to the hardware.

```cpp 
void loop(){
	// Idle, backlight on
	DELAY_FUNC(3000);
	on();

	// Idle, backlight off
	DELAY_FUNC(5000);
	lcd.noBacklight();

	// Idle, backlight off, lcd off
	DELAY_FUNC(3000);
	off();
	
}
```

###### Results

Probe LCD VCC with a multimeter or a ampmeter.<br>
All values are not 100% correct (+/- mA)

1. **Idle, backlight on:** 33.10mA
	1. `lcd.backlight();`
	1. `lcd.display();`
	1. Same as `lcd.on();`
1. **Idle, backlight off:** 5.35mA
	1. `lcd.noBacklight();`
1. **Idle, backlight off, lcd off:** 5.23mA
	1. `lcd.noBacklight();`
	1. `lcd.noDisplay();`
	1. Same as `lcd.off();`  


###### Power Optimization

Works with a transistor, but requires a Initalize every ON operation (Slow).<br>
The LCD will be always ON with a timeout on backlight, if user don't perform any action for about X seconds MCU will cut the backlight power.<br>
Since this project shows usefull information as temperature and humidity, the LCD will be in passive mode, allowing the people read some information on the LCD. Still it will require a good level of environment light.<br>
Also a fast feedback from operations are required, without a big delay in a Resume operation.<br>
Awake and User operations must be fluid.


## Ping

Each option is based on a good initialized ping module.

###### Code

Upload this code and do the proper connections to the hardware.

```cpp 
void loop()
{
	// Idle
	Serial.println("Idle");
	delay(5000);

	// Active
	Serial.println("Active");
	for (int i = 0; i <= 10000; i++) {
		sonar.ping_cm();
	}
}
```

###### Results

Probe sensor VCC with a multimeter or a ampmeter.<br>
All values are not 100% correct (+/- mA)

1. **Active:** 8mA
1. **Idle:** 5.55mA

###### Power Optimization

Works great with a transistor.<br>
This sensor is only used when needed or when user perform an action, a transistor will be used to control power ON or OFF in order to spare power.<br>
Awake operation is almost instantaneous without requiring a preheat.
