#include <DHT.h>
#include <DHT_U.h>
const int DHT11_PIN=2;
void setup()
{
  Serial.begin(9600);
  Serial.println("  :::::::::::::::::  ");
  Serial.println(" Welcome to Temp and Humidity Det :: ");
  Serial.println("  :::::::::::::::::  ");
  Serial.println("");
}

void loop()
{
  int result=DHT.read11(DHT11_PIN);
Serial.print("Humidity - ");
Serial.print(DHT.humidity);
Serial.print("q/m^3");
Serial.print("  \tTemperature - ");
Serial.print(DHT.temperature);
Serial.println("degrees");

delay(2000);
  }
