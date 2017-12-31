#include "cellar_pubsubclient.h"

CellarEeprom pubsubEeprom;

//PubSub settings
string DeviceName = "x";
string MqttHostName = "x";
int MqttPort = 1883;
string MqttUserName = "test"; //test
string MqttUserPass = "test"; //test

// MQTT status IP endpoint
string MqttTopicName_ip = "/ip";

// MQTT senzor endpoints
string MqttTopicName_temperature = "/temperature";
string MqttTopicName_humidity = "/humidity";
string MqttTopicName_pir = "/pir";
string MqttTopicName_relay = "/relay";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
Timer t;

list<string> Subscribe_Topics = list<string>();

//START
void CellarPubSubClient::start()
{
    DeviceName = pubsubEeprom.get_senzorid();
    MqttHostName = pubsubEeprom.get_mqttUrl();

    MqttTopicName_ip = DeviceName + "/ip";
    MqttTopicName_temperature = DeviceName + "/temperature";
    MqttTopicName_humidity = DeviceName + "/humidity";
    MqttTopicName_pir = DeviceName + "/pir";
    MqttTopicName_relay = DeviceName + "/relay";

    mqttClient.setServer(MqttHostName.c_str(), MqttPort);
    mqttClient.setCallback(customCallback);
    reconnect();

    //timing actions
    t.every(60000, send_IP);
}

void CellarPubSubClient::updateTimer()
{
    //update timer
    t.update();

    mqttClient.loop();
}

void CellarPubSubClient::set_Callback(CUSTOM_MQTT_CALLBACK_SIGNATURE)
{
    this->customCallback = customCallback;
}

void CellarPubSubClient::add_Subscribe(string topic)
{
    Subscribe_Topics.push_back(topic);
}

void reconnect()
{
    if (!mqttClient.connected())
    {
        Serial.print("Attempting MQTT connection...");

        if (mqttClient.connect(DeviceName.c_str(), MqttUserName.c_str(), MqttUserPass.c_str()))
        {
            Serial.println("connected");

            for (string item : Subscribe_Topics)
            {
                mqttClient.subscribe(item.c_str());
            }
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.println(mqttClient.state());
        }
    }
}

//************************************************************
void send_IP()
{
    if (!mqttClient.connected())
    {
        reconnect();
    }

    String ip = WiFi.localIP().toString();

    Serial.println("-------------------- IP -------------------");
    Serial.print("Status IP address : ");
    Serial.println(ip.c_str());
    Serial.println("-----------------------------------------------");

    if (mqttClient.connected())
    {
        mqttClient.publish(MqttTopicName_ip.c_str(), ip.c_str(), true);
    }
    else
    {
        Serial.println("Send_IP() - MQTT is not reachable");
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
        Serial.println("Send_Temperature() - MQTT is not reachable");
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
        Serial.println("Send_Humidity() - MQTT is not reachable");
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
        Serial.println("Send_Pir() - MQTT is not reachable");
    }
}

void CellarPubSubClient::send_Relay(string value)
{
    if (!mqttClient.connected())
    {
        reconnect();
    }

    if (mqttClient.connected())
    {
        mqttClient.publish(MqttTopicName_relay.c_str(), value.c_str(), true);
    }
    else
    {
        Serial.println("Send_Relay() - MQTT is not reachable");
    }
}