#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoOTA.h>
#include "config.h"
#include "led_control.h"
#include "mqtt_client.h"
#include "ota_update.h"
#include "sensor.h"

WiFiClient espClient;
PubSubClient mqttClient(espClient);

void setup() {
    Serial.begin(115200);
    connectToWiFi();
    mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
    mqttClient.setCallback(mqttCallback);
    ArduinoOTA.begin();
    initSensors();
    initLED();
}

void loop() {
    if (!mqttClient.connected()) {
        reconnectMQTT();
    }
    mqttClient.loop();
    handleOTA();
    pollSensors();
}

void connectToWiFi() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
    handleMQTTMessage(topic, payload, length);
}

void handleOTA() {
    ArduinoOTA.handle();
}

void pollSensors() {
    // Implement sensor polling logic here
}