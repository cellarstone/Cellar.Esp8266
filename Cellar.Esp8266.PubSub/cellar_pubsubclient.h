#ifndef CELLARPUBSUBCLIENT_H
#define CELLARPUBSUBCLIENT_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

//External libraries
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Timer.h>
#include <string>
#include <vector>

//Cellar External libraries
#include <cellar_eeprom.h>

using namespace std;

//PubSub client
class CellarPubSubClient
{
  public:
    void Start();
    void UpdateTimer();
    
    void send_Temperature(string value);
    void send_Humidity(string value);
    void send_Pir(string value);

};

void Reconnect();
void send_Status();

#endif