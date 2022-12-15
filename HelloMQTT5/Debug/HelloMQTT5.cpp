#include "Energia.h"

#line 1 "/Users/matteo/workspace_v10/HelloMQTT5/HelloMQTT5.ino"
















#define MQTTCLIENT_QOS2 1

#include <SPI.h>
#include <WiFi.h>
#include <WifiIPStack.h>
#include <Countdown.h>
#include <MQTTClient.h>
#include <json/json.h>

#define EXAMPLE_TEMPLATE    \
"{"                         \
    "\"name\": string,"     \
    "\"age\": int32,"       \
    "\"job\": string,"      \
    "\"citizen\": boolean"  \
"}"
#define EXAMPLE_TEMPLATE_2    \
"{"                         \
    "\"msg\": string"     \
"}"

void jsonfirst();
void jsonParse(char* payload);
void connect();
void setup();
void loop();

#line 38
char outputBuffer[256];

void jsonfirst()
{
    Json_Handle templateHandle;
    Json_Handle objectHandle;
    uint16_t bufsize = 256;

    
    char *fieldName = "\"age\"";
    int32_t ageVal = 42;
    bool citizenship = true;

    
    Json_createTemplate(&templateHandle, EXAMPLE_TEMPLATE,
                        strlen(EXAMPLE_TEMPLATE));

    
    Json_createObject(&objectHandle, templateHandle, 0);

    
    Json_setValue(objectHandle, fieldName, &ageVal, sizeof(ageVal));
    fieldName = "\"citizen\"";
    Json_setValue(objectHandle, fieldName, &citizenship, sizeof(uint16_t));

    
    Json_build(objectHandle, outputBuffer, &bufsize);
    
}



void jsonParse(char* payload)
{
    Json_Handle templateHandle;
    Json_Handle objectHandle;
    uint16_t bufsize = 32;
    char outputBuffer[bufsize];
    char *fieldName = "\"msg\"";
    bool boolBuffer;
    uint16_t boolBufSize = sizeof(uint16_t);
    
    Json_createTemplate(&templateHandle, EXAMPLE_TEMPLATE_2,
                        strlen(EXAMPLE_TEMPLATE_2));
    
    Json_createObject(&objectHandle, templateHandle, 0);
    
    Json_parse(objectHandle, payload, strlen(payload));
    
    Json_getValue(objectHandle, fieldName, outputBuffer, &bufsize);
    fieldName = "\"citizen\"";
    Json_getValue(objectHandle, fieldName, &boolBuffer, &boolBufSize);
    Serial.print(outputBuffer);
}


char ssid[] = "MspNet";

char password[] = "mspmatteo";

char printbuf[100];

int arrivedcount = 0;

void messageArrived(MQTT::MessageData &md)
{
    MQTT::Message &message = md.message;

    sprintf(printbuf,
            "Message %d arrived: qos %d, retained %d, dup %d, packetid %d\n",
            ++arrivedcount, message.qos, message.retained, message.dup,
            message.id);
    Serial.print(printbuf);
    sprintf(printbuf, "Payload %s\n", (char*) message.payload);
    Serial.print(printbuf);
    Serial.print(message.payloadlen);
    jsonParse((char *) message.payload);
}

WifiIPStack ipstack;
MQTT::Client<WifiIPStack, Countdown, (10*1024)> client = MQTT::Client<WifiIPStack,
        Countdown, (10*1024)>(ipstack);

const char *topic = "energia-sample-gas";

void connect()
{
    char hostname[] = "broker.hivemq.com";
    int port = 1883;
    sprintf(printbuf, "Connecting to %s:%d\n", hostname, port);
    Serial.print(printbuf);
    int rc = ipstack.connect(hostname, port);
    if (rc != 1)
    {
        sprintf(printbuf, "rc from TCP connect is %d\n", rc);
        Serial.print(printbuf);
    }

    Serial.println("MQTT connecting");
    MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
    data.MQTTVersion = 3;
    data.clientID.cstring = (char*) "energia-sample";
    rc = client.connect(data);
    if (rc != 0)
    {
        sprintf(printbuf, "rc from MQTT connect is %d\n", rc);
        Serial.print(printbuf);
    }
    Serial.println("MQTT connected");

    rc = client.subscribe(topic, MQTT::QOS2, messageArrived);
    if (rc != 0)
    {
        sprintf(printbuf, "rc from MQTT subscribe is %d\n", rc);
        Serial.print(printbuf);
    }
    Serial.println("MQTT subscribed");
}

void setup()
{
    Serial.begin(115200);
    
    Serial.print("Attempting to connect to Network named: ");
    
    Serial.println(ssid);
    
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        
        Serial.print(".");
        delay(300);
    }

    Serial.println("\nYou're connected to the network");
    Serial.println("Waiting for an ip address");

    while (WiFi.localIP() == INADDR_NONE)
    {
        
        Serial.print(".");
        delay(300);
    }

    Serial.println("\nIP Address obtained");
    
    Serial.println(WiFi.localIP());

    Serial.println("MQTT Hello example");
    connect();
}

void loop()
{
    if (!client.isConnected())
        connect();

    MQTT::Message message;

    arrivedcount = 0;

    
































    do
    {
        client.yield(1000);
    }
    while (arrivedcount == (arrivedcount + 1));

    delay(2000);
}



