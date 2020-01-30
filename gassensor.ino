int redLed=12;
int greenLed=13;
int buzzer=11;
int smokeA0=A1;
int sensorThres=400;
void setup() {
  // put your setup code here, to run once:
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(11,OUTPUT);
pinMode(A0,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensor=analogRead(smokeA0);
Serial.print("pin A0:");
Serial.println(sensor);
if(sensor>sensorThres)
{
  digitalWrite(redLed,HIGH);
  digitalWrite(greenLed,LOW);
  tone(buzzer,1000,200);
}
else 
{
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,HIGH);
  noTone(buzzer);
}
delay(1000);
}
