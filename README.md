# WaterDispenser


## Consuptions
### LCD

Each option is based on a good initialized lcd module. A line of text is printed to the LCD on setup.

###### Code

Probe LCD VCC with a multimeter or a ampmeter.

```cpp 
void loop(){
	DELAY_FUNC(3000);
	on();

	DELAY_FUNC(5000);
	lcd.noBacklight();

	DELAY_FUNC(3000);
	off();
	
}
```

###### Results

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
