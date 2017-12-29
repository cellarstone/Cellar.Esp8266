#include "cellar_pubsubclient.h"

EepromStorage myeeprom;

//nazev zarizeni - bude pouzito i pro pojmenovani zarizeni v siti a vychoziho access pointu
string DeviceName = "x";

//IP adresa MQTT serveru
string MqttHostName = "x";

//Port MQTT serveru
int MqttPort = 1883;

//uzivatel MQTT serveru
string MqttUserName = "test"; //test

//heslo MQTT uzivatele
string MqttUserPass = "test"; //test

//nazev MQTT fronty
string MqttTopicName_temperature = DeviceName + "/temperature";
string MqttTopicName_humidity = DeviceName + "/humidity";
string MqttTopicName_pir = DeviceName + "/pir";
string MqttTopicName_status = DeviceName + "/status";
string MqttTopicName_ip = DeviceName + "/ip";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
Timer t;

//START
void CellarPubSubClient::Start()
{
    DeviceName = myeeprom.get_senzorid();
    MqttHostName = myeeprom.get_mqttUrl();

    Serial.println(DeviceName.c_str());
    Serial.println(MqttHostName.c_str());

    Serial.println(WiFi.status());

    mqttClient.setServer(MqttHostName.c_str(), MqttPort);

    //casovane akce
    t.every(60000, send_Status);
}

void CellarPubSubClient::UpdateTimer()
{
    //update timer
    t.update();
}

void Reconnect()
{
    if (!mqttClient.connected())
    {
        Serial.print("Attempting MQTT connection...");

        if (mqttClient.connect(DeviceName.c_str(), MqttUserName.c_str(), MqttUserPass.c_str()))
        {
            Serial.println("connected");
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.println(mqttClient.state());
            // Serial.println(" try again in 5 seconds");

            Serial.println(MqttHostName.c_str());
            Serial.println(MqttPort);
            Serial.println(MqttTopicName_temperature.c_str());
            Serial.println(MqttTopicName_humidity.c_str());
            Serial.println(MqttTopicName_status.c_str());
            Serial.println(MqttTopicName_ip.c_str());
            Serial.println(MqttUserName.c_str());
            Serial.println(MqttUserPass.c_str());

            // Wait 5 seconds before retrying
            //delay(5000);
        }
    }
}

//************************************************************
long randNumber;
void send_Status()
{
    if (!mqttClient.connected())
    {
        Reconnect();
    }
    //mqttClient.loop();

    randNumber = random(0, 10);
    Serial.println(String(randNumber).c_str());

    //Get actual IP address
    String ip = WiFi.localIP().toString();
    Serial.println(ip.c_str());

    if (mqttClient.connected())
    {
        mqttClient.publish(MqttTopicName_status.c_str(), String(randNumber).c_str(), true);
        mqttClient.publish(MqttTopicName_ip.c_str(), ip.c_str(), true);
        Serial.println("STATUS OK");
    }
    else
    {
        Serial.println("STATUS BAD - MQTT is not reachable");
    }
}
//************************************************************

void CellarPubSubClient::send_Temperature(string value)
{
    if (!mqttClient.connected())
    {
        Reconnect();
    }

    if (mqttClient.connected())
    {
        mqttClient.publish(MqttTopicName_temperature.c_str(), value.c_str(), true);
    }
    else
    {
        Serial.println("STATUS BAD - MQTT is not reachable");
    }
}

void CellarPubSubClient::send_Humidity(string value)
{
    if (!mqttClient.connected())
    {
        Reconnect();
    }

    if (mqttClient.connected())
    {
        mqttClient.publish(MqttTopicName_humidity.c_str(), value.c_str(), true);
    }
    else
    {
        Serial.println("STATUS BAD - MQTT is not reachable");
    }
}

void CellarPubSubClient::send_Pir(string value)
{
    if (!mqttClient.connected())
    {
        Reconnect();
    }

    if (mqttClient.connected())
    {
        mqttClient.publish(MqttTopicName_pir.c_str(), value.c_str(), true);
    }
    else
    {
        Serial.println("STATUS BAD - MQTT is not reachable");
    }
}