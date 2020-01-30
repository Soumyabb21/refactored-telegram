#include "ThingSpeak.h"
#include <ESP8266WiFi.h>


const char* ssid     = "Lumos";
const char* password = "Neon1303";


unsigned long channel = 953641;


unsigned int app1 = 1;
unsigned int app2 = 2;
unsigned int app3 = 3;
unsigned int app4 = 4;

WiFiClient  client;


void setup() {
  Serial.begin(9600);
  delay(100);
  
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  digitalWrite(D1, 0);
  digitalWrite(D2, 0);
  digitalWrite(D3, 0);
  digitalWrite(D4, 0);
  
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);

}

 
 
 
void loop() {

  //get the last data of the fields
  int app_1 = ThingSpeak.readFloatField(channel, app1);
  int app_2 = ThingSpeak.readFloatField(channel, app2);
  int app_3 = ThingSpeak.readFloatField(channel, app3);
  int app_4 = ThingSpeak.readFloatField(channel, app4);

  if(app_1 == 1)
  {
    digitalWrite(D1, 1);
    Serial.println("D1 is On..!");
  }
  else if(app_1 == 0)
  {
    digitalWrite(D1, 0);
    Serial.println("D1 is Off..!");
  }

  if(app_2 == 1){
    digitalWrite(D2, 1);
    Serial.println("D2 is On..!");
  }
  else if(app_2 == 0){
    digitalWrite(D2, 0);
    Serial.println("D2 is Off..!");
  }

  if(app_3 == 1){
    digitalWrite(D3, 1);
    Serial.println("D3 is On..!");
  }
  else if(app_3 == 0){
    digitalWrite(D3, 0);
    Serial.println("D3 is Off..!");
  }
    if(app_4 == 1){
    digitalWrite(D3, 1);
    Serial.println("D4 is On..!");
  }
  else if(app_4 == 0){
    digitalWrite(D4, 0);
    Serial.println("D4 is Off..!");
  }
  Serial.println(app_1);
  Serial.println(app_2);
  Serial.println(app_3);
  Serial.println(app_4);
  delay(5000);

}
