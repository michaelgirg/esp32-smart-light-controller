#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <Arduino.h>

// Constants for LED control
const int LED_PIN = 23; // Change this to your LED pin
const int PWM_CHANNEL = 0;
const int PWM_FREQUENCY = 5000;
const int PWM_RESOLUTION = 8; // 8-bit resolution (0-255)

// Function declarations
void turnOn();
void turnOff();
void setBrightness(int brightness);
void setColor(int red, int green, int blue);

#endif // LED_CONTROL_H