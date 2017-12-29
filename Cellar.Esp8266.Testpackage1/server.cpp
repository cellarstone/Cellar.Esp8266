
//Internal libraries
#include "testpackage1.h"

using namespace std;

// HTTP server will listen at port 80
ESP8266WebServer server(80);

string wifissid = "CellarstoneDevicesWifi";
string wifipsswd = "Cllrs123IoT456";

//START
void CellarServer::start()
{
   
    //TEST Wifi
    WiFi.disconnect();
    setupSTA(wifissid.c_str(), wifipsswd.c_str());

    int ret;
    uint8_t timeout = 20; // 20 * 500 ms = 5 sec time out
    while (((ret = WiFi.status()) != WL_CONNECTED) && timeout)
    {
        Serial.print(".");
        Serial.print(WiFi.status());
        delay(500);
        --timeout;
    }

    // connected ?
    if ((ret = WiFi.status()) == WL_CONNECTED)
    {
        Serial.print(WiFi.status());

        //NORMAL WEB SERVER
        Serial.println("");
        Serial.print("Connected to ");
        Serial.println(wifissid.c_str());
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    }
    // not connected ? start AP
    else
    {
        //WEB SERVER in AP MODE
        setupAP();

        Serial.println("");
        Serial.print("AP Mode SSID : ");
        Serial.println("Cellarstone ESP8266 Wifi");
        Serial.print("AP Mode Password : ");
        Serial.println("Cllrs123IoT456");
        Serial.print("IP address: ");
        Serial.println(WiFi.softAPIP());
    }

    // Set up the endpoints for HTTP server
    //
    // Endpoints can be written as inline functions:
    server.on("/", handle_homepage);
    server.on("/home", handle_homepage);
    server.on("/settings", handle_settingspage);
    server.on("/clear", handle_cleareeprom);
    server.on("/submit", handle_submitpage);

    // Start the server
    server.begin();
    Serial.println("HTTP server started");
}

//HANDLE
void CellarServer::handle()
{
    // check for incomming client connections frequently in the main loop:
    server.handleClient();
}

/*******************************************************/
/*                       AP MODE                       */
/*******************************************************/
void CellarServer::setupSTA(string wifissid, string wifipsswd)
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(wifissid.c_str(), wifipsswd.c_str());

    Serial.println(wifissid.c_str());
    Serial.println(wifipsswd.c_str());
}


void CellarServer::setupAP()
{
    // WiFi.mode(WIFI_AP);
    // WiFi.softAP("Cellarstone ESP8266 Wifi", "Cllrs123IoT456");
    // WiFi.config(ip, gateway, subnet);
    // WiFi.begin();
}

/*******************************************************/
/*                       HANDLER                       */
/*******************************************************/

void handle_homepage()
{
    server.send(200, "text/plain", "HOME");
}

void handle_settingspage()
{
    server.send(200, "text/plain", "SETTINGS");
}

void handle_submitpage()
{
    server.send(302, "text/plain", "SUBMIT");
}

void handle_cleareeprom()
{
    server.send(302, "text/plain", "CLEAR");
}
