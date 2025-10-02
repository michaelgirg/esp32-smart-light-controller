#include "led_control.h"
#include <Arduino.h>
#include <driver/ledc.h>

#define LED_CHANNEL 0 // Define the LED channel
#define LED_FREQUENCY 5000 // Define the LED frequency
#define LED_RESOLUTION LEDC_TIMER_8_BIT // Define the LED resolution

void setupLED() {
    ledcSetup(LED_CHANNEL, LED_FREQUENCY, LED_RESOLUTION);
    ledcAttachPin(LED_PIN, LED_CHANNEL);
}

void setBrightness(uint8_t brightness) {
    ledcWrite(LED_CHANNEL, brightness);
}

void setColor(uint8_t r, uint8_t g, uint8_t b) {
    // Assuming RGB LED is connected with common anode
    setBrightness(r);
    delay(10);
    setBrightness(g);
    delay(10);
    setBrightness(b);
}

void turnOn() {
    setBrightness(255); // Set to maximum brightness
}

void turnOff() {
    setBrightness(0); // Turn off the LED
}