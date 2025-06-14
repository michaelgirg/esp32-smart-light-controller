#include "sensor.h"
#include <Wire.h>
#include <BH1750.h>

BH1750 lightSensor;
bool autoMode = false;

void initSensor() {
    Wire.begin();
    lightSensor.begin();
}

float readLightLevel() {
    return lightSensor.readLightLevel();
}

void checkMotionSensor(int motionPin, void (*onMotionDetected)()) {
    if (digitalRead(motionPin) == HIGH) {
        onMotionDetected();
    }
}

void setAutoMode(bool mode) {
    autoMode = mode;
}

bool isAutoMode() {
    return autoMode;
}