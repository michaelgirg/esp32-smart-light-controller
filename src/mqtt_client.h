#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "config.h"

// MQTT topics
const char* const MQTT_TOPIC_SET = "home/light1/set";
const char* const MQTT_TOPIC_STATE = "home/light1/state";

// Function declarations
void mqttConnect();
void mqttSubscribe();
void mqttPublishState(const String& state, int brightness, int r, int g, int b);
void mqttCallback(char* topic, byte* payload, unsigned int length);

#endif // MQTT_CLIENT_H