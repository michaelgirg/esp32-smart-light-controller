# ESP32 Smart Light Controller

## Project Overview
The ESP32 Smart Light Controller is a firmware project designed to control an LED light (RGB or white) using an ESP32 microcontroller. It communicates with Home Assistant via MQTT, supports Over-The-Air (OTA) updates, and integrates with motion or light sensors to automate lighting behavior.

## Features
- **Wi-Fi Connection**: Connects to Wi-Fi using stored credentials and prints connection status to the Serial monitor.
- **MQTT Communication**: Connects to an MQTT broker, subscribes to control topics, and publishes the current light state.
- **LED Control**: Controls LED brightness and color with smooth transitions.
- **Sensor Integration**: Optionally integrates with ambient light or motion sensors to automate light control.
- **OTA Firmware Updates**: Supports OTA updates for easy firmware management.
- **FreeRTOS Tasks**: Utilizes FreeRTOS for efficient task management.
- **Security**: Optional MQTT over TLS for secure communication.
- **Home Assistant Integration**: Compatible with Home Assistant for smart home automation.

## Hardware Requirements
- ESP32 (any variant)
- RGB LED (via PWM) or white LED
- Optional BH1750 (I2C) or PIR motion sensor
- Wi-Fi access and MQTT broker (e.g., Mosquitto)

## File Structure
```
esp32-smart-light-controller
├── src
│   ├── main.cpp          // Entry point of the firmware
│   ├── led_control.cpp   // LED control functions implementation
│   ├── led_control.h     // LED control functions declarations
│   ├── mqtt_client.cpp    // MQTT client implementation
│   ├── mqtt_client.h      // MQTT client declarations
│   ├── ota_update.cpp     // OTA update implementation
│   ├── ota_update.h       // OTA update declarations
│   ├── sensor.cpp         // Sensor integration implementation
│   ├── sensor.h           // Sensor functions declarations
│   ├── config.h           // Configuration constants
│   └── utils.h            // Utility functions and constants
├── platformio.ini         // PlatformIO configuration file
└── README.md              // Project documentation
```

## Setup Instructions
1. Clone the repository or download the project files.
2. Open the project in your preferred IDE.
3. Configure the `src/config.h` file with your Wi-Fi credentials and MQTT broker details.
4. Connect the hardware components as per the pin assignments defined in `config.h`.
5. Compile and upload the firmware to the ESP32 using PlatformIO or Arduino IDE.
6. Monitor the Serial output for connection status and MQTT messages.

## Usage
- Control the LED light by publishing commands to the MQTT topic `home/light1/set`.
- The expected JSON payload format for controlling the light is:
  ```json
  { "state": "ON", "brightness": 150, "color": { "r": 255, "g": 180, "b": 120 } }
  ```
- The ESP32 will publish its current state to the topic `home/light1/state`.

## Contributing
Contributions are welcome! Please feel free to submit issues or pull requests for improvements or bug fixes.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.