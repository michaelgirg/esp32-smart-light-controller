#ifndef UTILS_H
#define UTILS_H

#include <ArduinoJson.h>

// Function to log messages to Serial
void logMessage(const char* message) {
    Serial.println(message);
}

// Function to parse JSON payload
bool parseJsonPayload(const String& payload, JsonObject& jsonObject) {
    StaticJsonDocument<256> doc;
    DeserializationError error = deserializeJson(doc, payload);
    if (error) {
        logMessage("Failed to parse JSON");
        return false;
    }
    jsonObject = doc.as<JsonObject>();
    return true;
}

// Function to format state JSON for publishing
String formatStateJson(const String& state, int brightness, int r, int g, int b, bool sensorTriggered) {
    StaticJsonDocument<256> doc;
    JsonObject jsonObject = doc.to<JsonObject>();
    jsonObject["state"] = state;
    jsonObject["brightness"] = brightness;
    jsonObject["color"]["r"] = r;
    jsonObject["color"]["g"] = g;
    jsonObject["color"]["b"] = b;
    jsonObject["sensor_triggered"] = sensorTriggered;

    String output;
    serializeJson(doc, output);
    return output;
}

#endif // UTILS_H