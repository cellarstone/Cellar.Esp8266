#ifndef TESTPACKAGE1_H
#define TESTPACKAGE1_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include <string>

using namespace std;

void handle_homepage();
void handle_settingspage();
void handle_submitpage();
void handle_cleareeprom();

//SERVER
class CellarServer
{
public:
  void start();
  void handle();

private:
  void setupAP();
  void setupSTA(string wifissid,
                string wifipsswd);
};

#endif