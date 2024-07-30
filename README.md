# ESP8266 Web Server with BME280 Sensor and LittleFS

This project sets up a web server on an ESP8266 to display sensor readings from a BME280 sensor. The web server serves a web page stored in the LittleFS file system and provides real-time sensor readings via a JSON API and Server-Sent Events (SSE).

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Hardware Required](#hardware-required)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Introduction

This project demonstrates how to create a web server on the ESP8266 using the ESPAsyncWebServer library. The server reads data from a BME280 sensor and serves this data on a web page. The web page is stored in the LittleFS file system and is served over HTTP.

## Features

- **WiFi Connectivity**: Connects to a specified WiFi network.
- **File System**: Uses LittleFS to store and serve the web page.
- **Sensor Readings**: Reads temperature and humidity data from a BME280 sensor.
- **Web Server**: Serves a web page that displays real-time sensor readings.
- **JSON API**: Provides a JSON API to get the latest sensor readings.
- **Server-Sent Events (SSE)**: Sends real-time sensor readings to connected clients.

## Hardware Required

- ESP8266 Module
- BME280 Sensor
- Connecting wires

## Installation

1. **Install PlatformIO**: Ensure you have PlatformIO installed in your development environment.

2. **Clone the Repository**:
    ```bash
    git clone https://github.com/burakkcmn/nodemcu-webServerGauges.git
    cd nodemcu-webServerGauges
    ```

3. **Upload Files to LittleFS**:
    - Place your `index.html` file in the `data` directory.
    - Use PlatformIO to upload the files to LittleFS:
    ```bash
    pio run --target uploadfs
    ```

4. **Upload the Code**:
    - Open the project in your PlatformIO environment.
    - Upload the code to your ESP8266.

## Usage

1. **Power the ESP8266**: Connect your ESP8266 to a power source.

2. **Monitor the Serial Output**: Open the Serial Monitor in your development environment to see the connection status and IP address.

3. **Access the Web Page**: Open a web browser and go to the IP address displayed in the Serial Monitor.

4. **View Sensor Data**: The web page will display real-time temperature and humidity readings from the BME280 sensor.

## Project Structure
```
├── include
│ ├── WiFiHandler.h
│ ├── FileSystemManager.h
│ └── WebServerManager.h
│ └── SensorManager.h
├── src
│ ├── WiFiHandler.cpp
│ ├── FileSystemManager.cpp
│ ├── WebServerManager.cpp
│ ├── SensorManager.cpp
│ └── main.cpp
├── platformio.ini
└── README.md
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- This project is based on tutorials by Rui Santos & Sara Santos - [Random Nerd Tutorials](https://RandomNerdTutorials.com/)