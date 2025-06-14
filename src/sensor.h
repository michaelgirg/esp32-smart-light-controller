#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

// Sensor types
enum SensorType {
    LIGHT_SENSOR,
    MOTION_SENSOR
};

// Function declarations
void initSensor(SensorType type);
float readLightSensor();
bool readMotionSensor();
void handleSensorInput();

#endif // SENSOR_H