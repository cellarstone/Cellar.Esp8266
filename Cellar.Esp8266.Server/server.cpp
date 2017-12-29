#include "cellar_server.h"

IPAddress ip(192, 168, 8, 1);
IPAddress gateway(192, 168, 8, 1);
IPAddress subnet(255, 255, 255, 0);

// HTTP server will listen at port 80
ESP8266WebServer server(80);

HomePage temphomepage;
SettingsPage tempsettingspage;

EepromStorage myeeprom;

//INPUTS
string senzorid = "x";
string wifissid = "x";
string wifipsswd = "x";
string mqtturl = "x";

//START
void CellarServer::start()
{
    senzorid = myeeprom.get_senzorid();
    wifissid = myeeprom.get_wifissid();
    wifipsswd = myeeprom.get_wifipsswd();
    mqtturl = myeeprom.get_mqttUrl();

    Serial.println(senzorid.c_str());
    Serial.println(wifissid.c_str());
    Serial.println(wifipsswd.c_str());
    Serial.println(mqtturl.c_str());

    //TEST Wifi
    WiFi.disconnect();
    setupSTA(wifissid, wifipsswd);

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
    server.on("/restart", handle_restart);
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

    senzorid = myeeprom.get_senzorid();
    wifissid = myeeprom.get_wifissid();
    wifipsswd = myeeprom.get_wifipsswd();
    mqtturl = myeeprom.get_mqttUrl();

    Serial.println(senzorid.c_str());
    Serial.println(wifissid.c_str());
    Serial.println(wifipsswd.c_str());
    Serial.println(mqtturl.c_str());
    Serial.println("---------------------------------");

    temphome = temphomepage.getHTML();


    Serial.println(temphome.c_str());


    replace(temphome, "{{senzorid}}", senzorid);
    replace(temphome, "{{wifissid}}", wifissid);
    replace(temphome, "{{wifipsswd}}", wifipsswd);
    replace(temphome, "{{mqtturl}}", mqtturl);

    //Serial.println(temphome.c_str());

    server.send(200, "text/html", temphome.c_str());
}

void handle_settingspage()
{
    std::string temp = tempsettingspage.getHTML();
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

        Serial.println(senzorid.c_str());
        Serial.println(wifissid.c_str());
        Serial.println(wifipsswd.c_str());
        Serial.println(mqtturl.c_str());
    }
    //************************************
    //convert from std::string to char*
    //************************************

    // //CLEAR EEPROM
    // myeeprom.eeprom_erase_all();

    // //WRITE STRING
    // myeeprom.eeprom_write_string(0, convert(senzorid));
    // myeeprom.eeprom_write_string(100, convert(wifissid));
    // myeeprom.eeprom_write_string(200, convert(wifipsswd));
    // myeeprom.eeprom_write_string(300, convert(mqtturl));

    // string result = temphomepage.getHTML();
    // replace(result, "{{senzorid}}", senzorid);
    // replace(result, "{{wifissid}}", wifissid);
    // replace(result, "{{wifipsswd}}", wifipsswd);
    // replace(result, "{{mqtturl}}", mqtturl);
    // server.send(200, "text/html", result.c_str());

    //CLEAR EEPROM
    myeeprom.clear();

    //SAVE TO EEPROM
    myeeprom.save_senzorid(senzorid);
    myeeprom.save_wifissid(wifissid);
    myeeprom.save_wifipsswd(wifipsswd);
    myeeprom.save_mqttUrl(mqtturl);

    server.sendHeader("Location", String("/"), true);
    server.send(302, "text/plain", "");
}

void handle_restart()
{
    ESP.restart(); 
}

void handle_cleareeprom()
{
    myeeprom.clear();

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

// char *convert(std::string value)
// {
//     vector<char> tempData(value.c_str(), value.c_str() + value.size() + 1);
//     char *tempData2 = &tempData[0];
//     return tempData2;
// }