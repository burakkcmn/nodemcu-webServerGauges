#include <Arduino.h>
#include "WiFiHandler.h"
#include "FileSystemManager.h"
#include "SensorManager.h"
#include "WebServerManager.h"

// Replace with your network credentials
const char *ssid = "REPLACE_WITH_YOUR_SSID";
const char *password = "REPLACE_WITH_YOUR_PASSWORD";

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 30000;

void setup()
{
  Serial.begin(115200);
  SensorManager::init();
  WifiHandler::init(ssid, password);
  FileSystemManager::init();
  WebServerManager::init();
}

void loop()
{
  if ((millis() - lastTime) > timerDelay)
  {
    // Send Events to the client with the Sensor Readings Every 30 seconds
    WebServerManager::events.send("ping", NULL, millis());
    WebServerManager::events.send(SensorManager::getReadings().c_str(), "new_readings", millis());
    lastTime = millis();
  }
}
