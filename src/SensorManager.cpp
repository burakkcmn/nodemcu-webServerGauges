#include "SensorManager.h"

Adafruit_BME280 SensorManager::bme;
JSONVar SensorManager::readings;

void SensorManager::init()
{
    if (!bme.begin(0x76))
    {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1)
            ;
    }
}

String SensorManager::getReadings()
{
    readings["temperature"] = String(bme.readTemperature());
    readings["humidity"] = String(bme.readHumidity());
    String jsonString = JSON.stringify(readings);
    return jsonString;
}
