const int trigger =9;
const int echo =10;
const int redlight = 7;
const int greenlight =8;
const int buzzer = 4;
 long duration;
  int distance;
void setup()
{
  pinMode(9,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(10,INPUT);
  Serial.begin(9600);
}
void loop()
{
digitalWrite(9,LOW);
delay(50);
digitalWrite(9,HIGH);
delay(100);
digitalWrite(9,LOW);

duration=pulseIn(echo,HIGH);
distance =duration*0.034/2;
if(distance>50)
{
 digitalWrite(7,LOW);
 digitalWrite(8,LOW);
 tone(buzzer,1000,200);
}
else if(distance<50&& distance>20){
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  noTone(buzzer);
}
else if(distance<20){
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  noTone(buzzer);
}
Serial.print("Distance");
Serial.println(distance);
}
