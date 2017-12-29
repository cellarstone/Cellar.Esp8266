#ifndef CELLAREEPROM_h
#define CELLAREEPROM_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

// #include <Arduino.h>
#include <EEPROM.h>
#include <string>

using namespace std;


class EepromStorage{
  public:
    void clear();
    void save_senzorid(string id);
    void save_wifissid(string ssid);
    void save_wifipsswd(string password);
    void save_mqttUrl(string url);
    string get_senzorid();
    string get_wifissid();
    string get_wifipsswd();
    string get_mqttUrl();
};

class EepromUtil {
  public:
    static void    eeprom_erase_all();
    static boolean eeprom_read_bytes(int startAddr, byte array[], int numBytes);
    static boolean eeprom_write_int(int addr, int value);
    static boolean eeprom_read_int(int addr, int* value);
    static boolean eeprom_write_string(int addr, char* string);
    static boolean eeprom_read_string(int addr, char* buffer, int bufSize);
    static boolean eeprom_write_bytes(int startAddr, const byte* array,
                                      int numBytes);

  private:
    static boolean eeprom_is_addr_ok(int addr);
};

#endif