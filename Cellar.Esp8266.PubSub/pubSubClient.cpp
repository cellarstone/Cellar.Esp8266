#include "cellar_pubsubclient.h"

CellarEeprom pubsubEeprom;

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
string MqttTopicName_temperature = "/temperature";
string MqttTopicName_humidity = "/humidity";
string MqttTopicName_pir = "/pir";
string MqttTopicName_status = "/status";
string MqttTopicName_ip = "/ip";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
Timer t;

string Subscribe_Topic = "xxx";


// void customCallback(char* topic, byte* payload, unsigned int length) {
 
//   Serial.print("Message arrived in topic: ");
//   Serial.println(topic);
 
//   Serial.print("Message:");
//   for (int i = 0; i < length; i++) {
//     Serial.print((char)payload[i]);
//   }
 
//   Serial.println();
//   Serial.println("-----------------------");
 
// }


//START
void CellarPubSubClient::start()
{
    //Serial.begin(115200);

    DeviceName = pubsubEeprom.get_senzorid();
    MqttHostName = pubsubEeprom.get_mqttUrl();

    MqttTopicName_temperature = DeviceName + "/temperature";
    MqttTopicName_humidity = DeviceName + "/humidity";
    MqttTopicName_pir = DeviceName + "/pir";
    MqttTopicName_status = DeviceName + "/status";
    MqttTopicName_ip = DeviceName + "/ip";

    mqttClient.setServer(MqttHostName.c_str(), MqttPort);
    mqttClient.setCallback(customCallback);
    reconnect();

    //casovane akce
    t.every(60000, send_Status);
}

void CellarPubSubClient::updateTimer()
{
    //update timer
    t.update();

    mqttClient.loop();
}


void CellarPubSubClient::set_Callback(CUSTOM_MQTT_CALLBACK_SIGNATURE){
    this->customCallback = customCallback;
}

void CellarPubSubClient::set_Subscribe(string topic){
    Subscribe_Topic = topic;
}



void reconnect()
{
    if (!mqttClient.connected())
    {
        Serial.print("Attempting MQTT connection...");

        if (mqttClient.connect(DeviceName.c_str(), MqttUserName.c_str(), MqttUserPass.c_str()))
        {
            Serial.println("connected");

            mqttClient.subscribe(Subscribe_Topic.c_str());
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.println(mqttClient.state());
            // Serial.println(" try again in 5 seconds");

            // Serial.println(MqttHostName.c_str());
            // Serial.println(MqttPort);
            // Serial.println(MqttTopicName_temperature.c_str());
            // Serial.println(MqttTopicName_humidity.c_str());
            // Serial.println(MqttTopicName_status.c_str());
            // Serial.println(MqttTopicName_ip.c_str());
            // Serial.println(MqttUserName.c_str());
            // Serial.println(MqttUserPass.c_str());

            // Wait 5 seconds before retrying
            //delay(5000);
        }
    }
}

//************************************************************
void send_Status()
{
    if (!mqttClient.connected())
    {
        reconnect();
    }
    //mqttClient.loop();

    long randNumber = random(0, 10);
    String ip = WiFi.localIP().toString();
    
    Serial.println("-------------------- STATUS -------------------");
    Serial.print("Status random number : ");
    Serial.println(String(randNumber).c_str());
    Serial.print("Status IP address : ");
    Serial.println(ip.c_str());
    Serial.println("-----------------------------------------------");

    if (mqttClient.connected())
    {
        mqttClient.publish(MqttTopicName_status.c_str(), String(randNumber).c_str(), true);
        mqttClient.publish(MqttTopicName_ip.c_str(), ip.c_str(), true);
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
        reconnect();
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
        reconnect();
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
        reconnect();
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