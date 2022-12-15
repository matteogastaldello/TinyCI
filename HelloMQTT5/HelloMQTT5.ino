/*******************************************************************************
 * Copyright (c) 2014 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution. 
 *
 * The Eclipse Public License is available at 
 *   http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at 
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Ian Craggs - initial contribution
 *******************************************************************************/

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

char outputBuffer[256];

void jsonfirst()
{
    Json_Handle templateHandle;
    Json_Handle objectHandle;
    uint16_t bufsize = 256;

    // The name must be quoted to access the corresponding JSON field
    char *fieldName = "\"age\"";
    int32_t ageVal = 42;
    bool citizenship = true;

    // Create an internal representation of the template for the library's use
    Json_createTemplate(&templateHandle, EXAMPLE_TEMPLATE,
                        strlen(EXAMPLE_TEMPLATE));

    // Allocate memory needed for an object matching the generated template
    Json_createObject(&objectHandle, templateHandle, 0);

    // To fill in the object with actual data, call Json_setValue
    Json_setValue(objectHandle, fieldName, &ageVal, sizeof(ageVal));
    fieldName = "\"citizen\"";
    Json_setValue(objectHandle, fieldName, &citizenship, sizeof(uint16_t));

    // Output data from the JSON objectHandle into the outputBuffer
    Json_build(objectHandle, outputBuffer, &bufsize);
    // Any fields not set will not be part of the output
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
    // Create an internal representation of the template for the library's use
    Json_createTemplate(&templateHandle, EXAMPLE_TEMPLATE_2,
                        strlen(EXAMPLE_TEMPLATE_2));
    // Allocate memory needed for an object matching the generated template
    Json_createObject(&objectHandle, templateHandle, 0);
    // Parse the JSON and fill in the object
    Json_parse(objectHandle, payload, strlen(payload));
    // Retrieve a value from the parsed json
    Json_getValue(objectHandle, fieldName, outputBuffer, &bufsize);
    fieldName = "\"citizen\"";
    Json_getValue(objectHandle, fieldName, &boolBuffer, &boolBufSize);
    Serial.print(outputBuffer);
}

// your network name also called SSID
char ssid[] = "MspNet";
// your network password
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
    // attempt to connect to Wifi network:
    Serial.print("Attempting to connect to Network named: ");
    // print the network name (SSID);
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        // print dots while we wait to connect
        Serial.print(".");
        delay(300);
    }

    Serial.println("\nYou're connected to the network");
    Serial.println("Waiting for an ip address");

    while (WiFi.localIP() == INADDR_NONE)
    {
        // print dots while we wait for an ip addresss
        Serial.print(".");
        delay(300);
    }

    Serial.println("\nIP Address obtained");
    // We are connected and have an IP address.
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

    //jsonfirst();

//  // Send and receive QoS 0 message
//  char buf[100];
//  //sprintf(outputBuffer, "Hello World! QoS 0 message");
//  Serial.println(outputBuffer);
//  message.qos = MQTT::QOS0;
//  message.retained = false;
//  message.dup = false;
//  message.payload = (void*)outputBuffer;
//  message.payloadlen = strlen(outputBuffer)+1;
//  int rc = client.publish(topic, message);
//  while (arrivedcount == 0)
//    client.yield(1000);
//
//  // Send and receive QoS 1 message
//  sprintf(buf, "Hello World!  QoS 1 message");
//  Serial.println(buf);
//  message.qos = MQTT::QOS1;
//  message.payloadlen = strlen(buf)+1;
//  rc = client.publish(topic, message);
//  while (arrivedcount == 1)
//    client.yield(1000);
//
//  // Send and receive QoS 2 message
//  sprintf(buf, "Hello World!  QoS 2 message");
//  Serial.println(buf);
//  message.qos = MQTT::QOS2;
//  message.payloadlen = strlen(buf)+1;
//  rc = client.publish(topic, message);
//  while (arrivedcount == 2)
//    client.yield(1000);

    do
    {
        client.yield(1000);
    }
    while (arrivedcount == (arrivedcount + 1));

    delay(2000);
}
