


#define BLYNK_PRINT Serial
//#include <ESP8266WiFi.h>
#include <Blynk.h>
#include<BlynkSimpleEsp8266.h>;

char auth[]= "f666RHqfPFwah5l5vtBYUZLpT1848q2v";
const char* ssid="OnePlue 6T";
const char* pass="Difficult";


long duration;
int distance;
int led =D0;
int sensor=D1;
const int trig=D4;
const int echop=D3;
const int buzzer=D7;
int state =LOW;
int val=0;
WidgetLCD lcd(V1);

voidCD lcd(V1); setup() 
{
 pinMode(led,OUTPUT);
pinMode(sensor,INPUT);
pinMode(trig,OUTPUT);
Serial.begin(9600);
Blynk.begin(auth,ssid,pass);
lcd.clear();
}

void loop() 
{
val=digitalRead(sensor);
if (val==HIGH)
{
  lcd.clear();
  digitalWrite(led,HIGH);
 
  if (state==LOW)
  {
    Serial.println("Motion detected");
   
    
    digitalWrite(trig,LOW);
    delay(100);
    digitalWrite(trig,HIGH);
    delay(500);
    digitalWrite(trig,LOW);
    duration=pulseIn(echop,HIGH);
    distance=duration*0.034/2;
    Serial.print("Distance:");
    Serial.print(distance);
    lcd.print(0,0,"distance in cm");
    lcd.print(0,1,"animal intrusion");
    tone(buzzer,1000,2000);
    Blynk.run();
    state=HIGH;
    
  }
}
else
{
  digitalWrite(led,LOW);
 
  if (state==HIGH)
  {
    Serial.println("Motion stopped");
    lcd.print(0,1,"no animal intrusion");
    state=LOW;
    Blynk.run();
    
  }
}
}



  
