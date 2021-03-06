#include "cellar_eeprom.h"

EepromUtil myeepromutil;

//SENZOR ID
const int address_senzorid = 10;
const int size_senzorid = 32;

//WIFI SSID
const int address_wifissid = 42;
const int size_wifissid = 32;

//WIFI PASSWORD
const int address_wifipsswd = 74;
const int size_wifipsswd = 32;

//WIFI MQTT URL
const int address_mqttUrl = 106;
const int size_mqttUrl = 32;

//FIRMWARE VERSION
const int address_firmware = 138;
const int size_firmware = 32;


void CellarEeprom::clear()
{
    EEPROM.begin(512);
    myeepromutil.eeprom_erase_all();
    EEPROM.end();
}


void CellarEeprom::save_senzorid(string id)
{
    EEPROM.begin(512);
    char* temp = (char*)id.c_str();
    myeepromutil.eeprom_write_string(address_senzorid, temp);
    EEPROM.commit();
    EEPROM.end();
}

void CellarEeprom::save_wifissid(string ssid)
{
    EEPROM.begin(512);
    char* temp = (char*)ssid.c_str();
    myeepromutil.eeprom_write_string(address_wifissid, temp);
    EEPROM.commit();
    EEPROM.end();
}

void CellarEeprom::save_wifipsswd(string password)
{
    EEPROM.begin(512);
    char* temp = (char*)password.c_str();
    myeepromutil.eeprom_write_string(address_wifipsswd, temp);
    EEPROM.commit();
    EEPROM.end();
}

void CellarEeprom::save_mqttUrl(string url)
{
    EEPROM.begin(512);
    char* temp = (char*)url.c_str();
    myeepromutil.eeprom_write_string(address_mqttUrl, temp);
    EEPROM.commit();
    EEPROM.end();
}

void CellarEeprom::save_firmware(string version)
{
    EEPROM.begin(512);
    char* temp = (char*)version.c_str();
    myeepromutil.eeprom_write_string(address_firmware, temp);
    EEPROM.commit();
    EEPROM.end();
}

string CellarEeprom::get_senzorid()
{
    EEPROM.begin(512);
    char *temp = "x";
    myeepromutil.eeprom_read_string(address_senzorid, temp, size_senzorid);
    EEPROM.end();

    //Serial.println(temp);

    return string(temp);
}

string CellarEeprom::get_wifissid()
{
    EEPROM.begin(512);
    char *temp = "x";
    myeepromutil.eeprom_read_string(address_wifissid, temp, size_wifissid);
    EEPROM.end();

    //Serial.println(temp);

    return string(temp);
}

string CellarEeprom::get_wifipsswd()
{
    EEPROM.begin(512);
    char *temp = "x";
    myeepromutil.eeprom_read_string(address_wifipsswd, temp, size_wifipsswd);
    EEPROM.end();

    //Serial.println(temp);

    return string(temp);
}

string CellarEeprom::get_mqttUrl()
{
    EEPROM.begin(512);
    char *temp = "x";
    myeepromutil.eeprom_read_string(address_mqttUrl, temp, size_mqttUrl);
    EEPROM.end();

    //Serial.println(temp);

    return string(temp);
}

string CellarEeprom::get_firmware()
{
    EEPROM.begin(512);
    char *temp = "x";
    myeepromutil.eeprom_read_string(address_firmware, temp, size_firmware);
    EEPROM.end();

    //Serial.println(temp);

    return string(temp);
}