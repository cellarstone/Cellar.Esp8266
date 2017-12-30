#ifndef CELLARSERVER_H
#define CELLARSERVER_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

//External libraries
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <string>
#include <vector>

//Cellar External libraries
#include <cellar_eeprom.h>

using namespace std;

void handle_homepage();
void handle_settingspage();
void handle_submitpage();
void handle_cleareeprom();
void handle_restart();

bool replace(string &str,
             const string &from,
             const string &to);

void log_Parameters(string method);

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

//PAGES
class HomePage
{
public:
  std::string getHTML();

private:
  std::string setHeader();
  std::string setBody();
};

class SettingsPage
{
public:
  std::string getHTML();

private:
  std::string setHeader();
  std::string setBody();
};

#endif