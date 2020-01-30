 #define BLYNK_PRINT Serial
#include <Blynk.h>
#include<BlynkSimpleESP8266.h>
#include<Servo.h>
#include<ESP8266WiFi.h>
uint8_t ServoMotorpin=D2;
char auth[]="ISBvKRwpFItZyYY9k5Jx_2K7I0dv4s00";
const char* ssid="OnePlue 6T";
const char* password="Difficult";

void setup() {
  // put your setup code here, to run once:
Blynk.begin(auth,ssid,password);
analogWrite(ServoMotorpin,512); 
analogWriteFreq(50);
Serial.begin(9600);
pinMode(D2,OUTPUT);
digitalWrite(D2,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
uint16_t dutycycle=analogRead(A0);
if(dutycycle>1023) 
dutycycle=1023;
dutycycle=25+((85*dutycycle)/1023);
analogWrite(ServoMotorpin,dutycycle);
delay(100);
Blynk.run();
}
