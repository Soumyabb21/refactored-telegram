#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include<BlynkSimpleESP8266.h>


char auth[]="ISBvKRwpFItZyYY9k5Jx_2K7I0dv4s00";
const char* ssid="OnePlue 6T";
const char* password="Difficult";
int Swt=D7;
 
 
 void setup()
{
   Blynk.begin(auth,ssid,password);
  pinMode(D7,OUTPUT);
  digitalWrite(D7,LOW);
  Serial.begin(9600);

  
}
void loop()
{ 
  Blynk.run();
}



 
