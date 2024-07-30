#include "WebServerManager.h"
#include "FileSystemManager.h"
#include "SensorManager.h"

AsyncWebServer WebServerManager::server(80);
AsyncEventSource WebServerManager::events("/events");

void WebServerManager::init()
{
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(LittleFS, "/index.html", "text/html"); });

    server.serveStatic("/", LittleFS, "/");

    server.on("/readings", HTTP_GET, [](AsyncWebServerRequest *request)
              {
        String json = SensorManager::getReadings();
        request->send(200, "application/json", json);
        json = String(); });

    events.onConnect([](AsyncEventSourceClient *client)
                     {
        if(client->lastId()){
            Serial.printf("Client reconnected! Last message ID that it got is: %u\n", client->lastId());
        }
        client->send("hello!", NULL, millis(), 10000); });
    server.addHandler(&events);

    server.begin();
}
