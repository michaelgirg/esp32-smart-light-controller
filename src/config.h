#define WIFI_SSID "your_wifi_ssid"
#define WIFI_PASSWORD "your_wifi_password"

#define MQTT_BROKER "mqtt_broker_address"
#define MQTT_PORT 1883 //reccomend to use 8883 which will require setup for certificate
//This port will allow for secure connection to the broker
#define MQTT_USER "mqtt_username"
#define MQTT_PASSWORD "mqtt_password"
#define MQTT_CLIENT_ID "esp32-smart-light-1"

#define LIGHT_CONTROL_TOPIC "home/light1/set"
#define LIGHT_STATE_TOPIC "home/light1/state"

#define LED_PIN 23
#define SENSOR_PIN 34 // Example pin for sensor input (change depending on your setup)

#define AUTO_MODE true // Set to true for automatic control based on sensor input (change as needed)
#define MANUAL_MODE false // Set to false for manual control (change as needed)

#define OTA_HOSTNAME "esp32-smart-light-controller" // mDNS hostname for OTA updates

#define BRIGHTNESS_MAX 255
#define BRIGHTNESS_MIN 0

#define DEFAULT_BRIGHTNESS 150
#define DEFAULT_COLOR_R 255
#define DEFAULT_COLOR_G 255
#define DEFAULT_COLOR_B 255
