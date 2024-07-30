#ifndef WEB_SERVER_MANAGER_H
#define WEB_SERVER_MANAGER_H

#include <ESPAsyncWebServer.h>

class WebServerManager
{
public:
    static void init();
    static AsyncEventSource events;

private:
    static AsyncWebServer server;
};

#endif // WEB_SERVER_MANAGER_H
