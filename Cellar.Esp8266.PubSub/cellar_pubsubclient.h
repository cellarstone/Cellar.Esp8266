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
#include <list>

//Cellar External libraries
#include <cellar_eeprom.h>

using namespace std;



#ifdef ESP8266
#include <functional>
#define CUSTOM_MQTT_CALLBACK_SIGNATURE std::function<void(char*, uint8_t*, unsigned int)> customCallback
#else
#define CUSTOM_MQTT_CALLBACK_SIGNATURE void (*customCallback)(char*, uint8_t*, unsigned int)
#endif


//PubSub client
class CellarPubSubClient
{
private:
  CUSTOM_MQTT_CALLBACK_SIGNATURE;

public:
  void start();
  void updateTimer();

  void send_Temperature(string value);
  void send_Humidity(string value);
  void send_Pir(string value);
  void send_Relay(string value);

  void set_Callback(CUSTOM_MQTT_CALLBACK_SIGNATURE);
  void add_Subscribe(string topic);
};

//void mycallback(char* topic, byte* payload, unsigned int length);
void reconnect();
void send_IP();

#endif