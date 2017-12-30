#include "cellar_server.h"

IPAddress ip(192, 168, 8, 1);
IPAddress gateway(192, 168, 8, 1);
IPAddress subnet(255, 255, 255, 0);

// HTTP server will listen at port 80
ESP8266WebServer server(80);

HomePage temphomepage;
SettingsPage tempsettingspage;

CellarEeprom serverEeprom;

//INPUTS
string firmware = "x";
string senzorid = "x";
string wifissid = "x";
string wifipsswd = "x";
string mqtturl = "x";

//START
void CellarServer::start()
{
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    firmware = serverEeprom.get_firmware();
    senzorid = serverEeprom.get_senzorid();
    wifissid = serverEeprom.get_wifissid();
    wifipsswd = serverEeprom.get_wifipsswd();
    mqtturl = serverEeprom.get_mqttUrl();

    log_Parameters("START");

    //TEST Wifi
    WiFi.disconnect();
    setupSTA(wifissid, wifipsswd);

    int ret;
    int tmp1 = LOW;
    uint8_t timeout = 20; // 20 * 500 ms = 5 sec time out
    while (((ret = WiFi.status()) != WL_CONNECTED) && timeout)
    {
        if (tmp1 == LOW)
        {
            tmp1 = HIGH;
        }
        else
        {
            tmp1 = LOW;
        }
        digitalWrite(LED_BUILTIN, tmp1);

        Serial.print(".");
        Serial.print(WiFi.status());
        delay(500);
        --timeout;
    }

    // connected ?
    if ((ret = WiFi.status()) == WL_CONNECTED)
    {
        Serial.println(WiFi.status());

        //NORMAL WEB SERVER
        Serial.println("------------- WIFI CONNECTED --------------");
        Serial.print("Connected to ");
        Serial.println(wifissid.c_str());
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
        Serial.println("-------------------------------------------");

        //LED will be off
        digitalWrite(LED_BUILTIN, HIGH);
    }
    // not connected ? start AP
    else
    {
        //WEB SERVER in AP MODE
        setupAP();

        Serial.println("------------- AP MODE --------------");
        Serial.print("AP Mode SSID : ");
        Serial.println("Cellarstone ESP8266 Wifi");
        Serial.print("AP Mode Password : ");
        Serial.println("Cllrs123IoT456");
        Serial.print("IP address: ");
        Serial.println(WiFi.softAPIP());
        Serial.println("------------------------------------");

        //LED will be on
        digitalWrite(LED_BUILTIN, LOW);
    }

    // Set up the endpoints for HTTP server
    //
    // Endpoints can be written as inline functions:
    server.on("/", handle_homepage);
    server.on("/home", handle_homepage);
    server.on("/settings", handle_settingspage);
    server.on("/clear", handle_cleareeprom);
    server.on("/restart", handle_restart);
    server.on("/submit", handle_submitpage);

    // Start the server
    server.begin();
    Serial.println("------------- HTTP SERVER --------------");
    Serial.println("HTTP server started");
    Serial.println("----------------------------------------");
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
}

void CellarServer::setupAP()
{
    WiFi.mode(WIFI_AP);
    WiFi.softAP("Cellarstone ESP8266 Wifi", "Cllrs123IoT456");
    WiFi.config(ip, gateway, subnet);
    WiFi.begin();
}

/*******************************************************/
/*                       HANDLER                       */
/*******************************************************/

void handle_homepage()
{
    string temphome = "x";

    firmware = serverEeprom.get_firmware();
    senzorid = serverEeprom.get_senzorid();
    wifissid = serverEeprom.get_wifissid();
    wifipsswd = serverEeprom.get_wifipsswd();
    mqtturl = serverEeprom.get_mqttUrl();

    log_Parameters("HOME");

    temphome = temphomepage.getHTML();

    replace(temphome, "{{firmware}}", firmware);
    replace(temphome, "{{senzorid}}", senzorid);
    replace(temphome, "{{wifissid}}", wifissid);
    replace(temphome, "{{wifipsswd}}", wifipsswd);
    replace(temphome, "{{mqtturl}}", mqtturl);

    server.send(200, "text/html", temphome.c_str());
}

void handle_settingspage()
{
    std::string temp = tempsettingspage.getHTML();
    replace(temp, "{{firmware}}", firmware);
    replace(temp, "{{senzorid}}", senzorid);
    replace(temp, "{{wifissid}}", wifissid);
    replace(temp, "{{wifipsswd}}", wifipsswd);
    replace(temp, "{{mqtturl}}", mqtturl);
    server.send(200, "text/html", temp.c_str());
}

void handle_submitpage()
{

    if (server.args() > 0)
    {
        for (uint8_t i = 0; i < server.args(); i++)
        {
            if (server.argName(i) == "senzorid")
            {
                senzorid = string(server.arg(i).c_str());
            }
            if (server.argName(i) == "wifissid")
            {
                wifissid = string(server.arg(i).c_str());
            }
            if (server.argName(i) == "wifipsswd")
            {
                wifipsswd = string(server.arg(i).c_str());
            }
            if (server.argName(i) == "mqtturl")
            {
                mqtturl = string(server.arg(i).c_str());
            }
        }

        log_Parameters("SUBMIT");
    }

    //CLEAR EEPROM
    serverEeprom.clear();

    //SAVE TO EEPROM
    serverEeprom.save_senzorid(senzorid);
    serverEeprom.save_wifissid(wifissid);
    serverEeprom.save_wifipsswd(wifipsswd);
    serverEeprom.save_mqttUrl(mqtturl);

    server.sendHeader("Location", String("/"), true);
    server.send(302, "text/plain", "");
}

void handle_restart()
{
    ESP.restart();
}

void handle_cleareeprom()
{
    serverEeprom.clear();

    server.sendHeader("Location", String("/"), true);
    server.send(302, "text/plain", "");
}

/*********************************************************/
// HELPERS
/*********************************************************/
bool replace(std::string &str, const std::string &from, const std::string &to)
{
    size_t start_pos = str.find(from);
    if (start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

void log_Parameters(string method)
{
    Serial.print("--------------");
    Serial.print(method.c_str());
    Serial.println("-------------------");
    Serial.print("Firmware : ");
    Serial.print("|");
    Serial.print(firmware.c_str());
    Serial.println("|");
    Serial.print("SenzorID : ");
    Serial.print("|");
    Serial.print(senzorid.c_str());
    Serial.println("|");
    Serial.print("Wifi SSID : ");
    Serial.print("|");
    Serial.print(wifissid.c_str());
    Serial.println("|");
    Serial.print("Wifi Password : ");
    Serial.print("|");
    Serial.print(wifipsswd.c_str());
    Serial.println("|");
    Serial.print("MQTT Url : ");
    Serial.print("|");
    Serial.print(mqtturl.c_str());
    Serial.println("|");
    Serial.println("---------------------------------");
}
