#include <WiFi.h>
#include <PubSubClient.h>
#include "config.h"
#include "mqtt_client.h"
#include "utils.h"

WiFiClient espClient;
PubSubClient mqttClient(espClient);

void mqttReconnect() {
    while (!mqttClient.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (mqttClient.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
            Serial.println("connected");
            mqttClient.subscribe(MQTT_TOPIC_SET);
        } else {
            Serial.print("failed, rc=");
            Serial.print(mqttClient.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
    String message;
    for (int i = 0; i < length; i++) {
        message += (char)payload[i];
    }
    handleMqttMessage(topic, message);
}

void setupMqtt() {
    mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
    mqttClient.setCallback(mqttCallback);
}

void mqttLoop() {
    if (!mqttClient.connected()) {
        mqttReconnect();
    }
    mqttClient.loop();
}

void publishLightState(const String& state, int brightness, const String& color) {
    String payload = "{\"state\":\"" + state + "\",\"brightness\":" + String(brightness) + ",\"color\":" + color + "}";
    mqttClient.publish(MQTT_TOPIC_STATE, payload.c_str());
}