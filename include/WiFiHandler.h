#ifndef WIFI_HANDLER_H
#define WIFI_HANDLER_H

#include <ESP8266WiFi.h>

class WifiHandler {
public:
    static void init(const char* ssid, const char* password);
};

#endif // WIFI_HANDLER_H
