#include <WiFi.h>
#include <PubSubClient/src/PubSubClient.h>
#include <SPI.h> //only required if using an MCU LaunchPad + CC3100 BoosterPack. Not needed for CC3200 LaunchPad
WiFiClient wclient;

char server[] = "broker.hivemq.com";
byte ip[] = { 172, 16, 0, 100 };

char sensorRead[4];

#define WIFI_SSID "MspNet" //Put Wifi name here
#define WIFI_PWD "mspmatteo" // Put Wifi Password here

PubSubClient client(server, 1883, callback, wclient);

void callback(char* inTopic, byte* payload, unsigned int length) {
  Serial.print("Received message for topic ");
  Serial.print(inTopic);
  Serial.print("with length ");
  Serial.println(length);
  Serial.println("Message:");
  Serial.write(payload, length);
  Serial.println();
}

void setup()
{
  //Initialize serial and wait for port to open:
  Serial.begin(115200);

  Serial.println("Start WiFi");
  WiFi.begin(WIFI_SSID, WIFI_PWD);
  while (WiFi.localIP() == INADDR_NONE) {
    Serial.print(".");
    delay(300);
  }
  Serial.println("");

  printWifiStatus();

}

void loop()
{

  // Reconnect if the connection was lost
  if (!client.connected()) {
    Serial.println("Disconnected. Reconnecting....");

    if (!client.connect("energiaClient")) {
      Serial.println("Connection failed");
    } else {
      Serial.println("Connection success");
      if (client.subscribe("inTopic-gas")) {
        Serial.println("Subscription successfull");
      }
    }
  }
  client.loop();
  delay(2000);

//  // read the input on analog pin:
//  int sensorValue = analogRead (12);
//  Serial.println (sensorValue);
//
//  // convert into to char array
//  String str = (String)sensorValue;
//  int str_len = str.length() + 1; // Length (with one extra character for the null terminator)
//  char char_array[str_len]; // Prepare the character array (the buffer)
//  str.toCharArray(char_array, str_len); // Copy it over
//
//  // publish data to MQTT broker
//  if (client.connect ("LaunchPadClient")) {
//    client.publish ("energia-sample-gas", char_array);
//    //client.subscribe("inTopic");
//    Serial.println("Publishing successful!");
//    client.disconnect ();
//  }

}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}
