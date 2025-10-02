#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include "config.h"

// Sensor types
enum SensorType {
    LIGHT_SENSOR,
    MOTION_SENSOR
};

// Function declarations (aligned with implementation)
void initSensor();
float readLightLevel();
void checkMotionSensor(int motionPin, void (*onMotionDetected)());
void setAutoMode(bool mode);
bool isAutoMode();

#endif // SENSOR_H