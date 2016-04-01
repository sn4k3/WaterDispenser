#ifndef _CONFIG_h
#define _CONFIG_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Macros.h"
#include "SettingsConfig.h"

#define TIME_BEFORE_DEEPSLEEP 60000 // 1 Minute

#define DEEP_SLEEP_IDLE 500
#define IDLE_SLEEP_DELAY 50

#define BUTTONS_ANALOG_PIN  A0
#define LIGHTSENSOR_ANALOG_PIN  A1
#define KEYPAD_ANALOG_PIN  A2


#define WATERMETER_DATA_PIN  DD2
#define WATERSENSOR_DATA_PIN  DD3
#define LEDSTRIP_DATA_PIN  DD4
#define LASERSENSOR_DATA_PIN  DD5

#define PING_SR_PIN  2
#define PING_TRIGGER_PIN  DD7
#define PING_ECHO_PIN     DD6
#define PING_MAX_DISTANCE 200

#define PUMBVALVE_SR_PIN  0
#define LASER_SR_PIN  4
#define LASER_LED_R_PIN  5
#define LASER_LED_G_PIN  6
#define LASER_LED_B_PIN  7



#define PHOTORESISTOR_REPEAT_INTERVAL 2000


#define MQ2_REPEAT_INTERVAL 10000 // 10 seconds
#define MQ2_THRESHOLD 700

#define DHT_TYPE 22   // DHT 22  (AM2302)
#define DHT_REPEAT_INTERVAL 300000 // 5 minutes


#define CONFIG_VERSION "WD"
#define CONFIG_START 0

#define VERSION "0.1"


#endif