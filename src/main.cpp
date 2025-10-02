#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoOTA.h>
#include "config.h"
#include "led_control.h"
#include "mqtt_client.h"
#include "ota_update.h"
#include "sensor.h"

// Forward declarations for local functions used before definition
void connectToWiFi();
void pollSensors();

void setup() {
    Serial.begin(115200);
    connectToWiFi();
    initOTA();
    setupMqtt();
    setupLED();
    initSensor();
    pinMode(SENSOR_PIN, INPUT);
    setAutoMode(AUTO_MODE);
}

void loop() {
    mqttLoop();
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

void pollSensors() {
    if (isAutoMode()) {
        float lux = readLightLevel();
        // Simple threshold-based control; tune as needed
        if (lux < 50.0f) {
            turnOn();
        } else {
            turnOff();
        }
        // Optional: motion-triggered on
        checkMotionSensor(SENSOR_PIN, [](){ turnOn(); });
    }
}