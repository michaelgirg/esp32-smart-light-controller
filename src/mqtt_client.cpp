#include <WiFi.h>
#include <PubSubClient.h>
#include "config.h"
#include "mqtt_client.h"
#include "utils.h"
#include "led_control.h"

WiFiClient espClient;
PubSubClient mqttClient(espClient);

void mqttReconnect() {
    while (!mqttClient.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (mqttClient.connect(MQTT_CLIENT_ID, MQTT_USER, MQTT_PASSWORD)) {
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

void handleMqttMessage(const char* topic, const String& message) {
    StaticJsonDocument<256> doc;
    DeserializationError err = deserializeJson(doc, message);
    if (err) {
        Serial.println("MQTT JSON parse error");
        return;
    }
    JsonObject obj = doc.as<JsonObject>();

    // Handle state
    if (obj.containsKey("state")) {
        String s = obj["state"].as<String>();
        if (s.equalsIgnoreCase("ON")) {
            turnOn();
        } else if (s.equalsIgnoreCase("OFF")) {
            turnOff();
        }
    }

    // Handle brightness
    if (obj.containsKey("brightness")) {
        int b = obj["brightness"].as<int>();
        if (b < BRIGHTNESS_MIN) b = BRIGHTNESS_MIN;
        if (b > BRIGHTNESS_MAX) b = BRIGHTNESS_MAX;
        setBrightness(b);
    }

    // Handle color (best-effort; single-channel fallback)
    if (obj.containsKey("color")) {
        int r = obj["color"]["r"] | DEFAULT_COLOR_R;
        int g = obj["color"]["g"] | DEFAULT_COLOR_G;
        int b = obj["color"]["b"] | DEFAULT_COLOR_B;
        setColor(r, g, b);
    }
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