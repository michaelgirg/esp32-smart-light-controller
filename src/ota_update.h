#ifndef OTA_UPDATE_H
#define OTA_UPDATE_H

#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoOTA.h>

void initOTA(const char* hostname);
void handleOTA();

#endif // OTA_UPDATE_H