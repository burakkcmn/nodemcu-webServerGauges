#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <Adafruit_BME280.h>
#include <Arduino_JSON.h>

class SensorManager
{
public:
    static void init();
    static String getReadings();

private:
    static Adafruit_BME280 bme;
    static JSONVar readings;
};

#endif // SENSOR_MANAGER_H
