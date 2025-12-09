//Replace your wifi credentials here
const char* ssid     = "Redmi 9"; // Mobile Hostpot Name (Works only with 4G Mobiles)
const char* password = "12345678"; // Enter Mobile Hospot Password
//chennel ID
unsigned long channel = 2640113;

int field1 = 1;
int field2 = 2;
int field3 = 3;
WiFiClient  client;
void setup() {
  Serial.begin(115200);
  delay(100);

  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);

}

void loop() {

  //get the last data of the fields
  int LED = ThingSpeak.readFloatField(channel, field1);
  int Buzzer = ThingSpeak.readFloatField(channel, field2);
  int Relay = ThingSpeak.readFloatField(channel, field3);

  if (LED == 1) {
    digitalWrite(D1, 1);
    Serial.println("LED is On..!");
  }
  else if (LED == 0) {
    digitalWrite(D1, 0);
    Serial.println("LED is Off..!");
  }
  if (Buzzer == 1) {
    digitalWrite(D2, 1);
    Serial.println("Buzzer is On..!");
  }
  else if (Buzzer == 0) {
    digitalWrite(D2, 0);
    Serial.println("Buzzer is Off..!");
  }
  if (Relay == 1) {
    digitalWrite(D3, 1);
    Serial.println("Relay is On..!");
  }
  else if (Relay == 0) {
    digitalWrite(D3, 0);
    Serial.println("Relay is Off..!");
  }
  Serial.println(LED);
  Serial.println(Buzzer);
  Serial.println(Relay);
  delay(5000);
}#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
