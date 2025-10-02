#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "config.h"

// MQTT topics (use config.h definitions)
#define MQTT_TOPIC_SET LIGHT_CONTROL_TOPIC
#define MQTT_TOPIC_STATE LIGHT_STATE_TOPIC

// Function declarations
void setupMqtt();
void mqttLoop();
void publishLightState(const String& state, int brightness, const String& colorJson);
void mqttCallback(char* topic, byte* payload, unsigned int length);
void handleMqttMessage(const char* topic, const String& message);

#endif // MQTT_CLIENT_H