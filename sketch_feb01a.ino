#include "DHT.h"
#define DHTPIN 2     
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();}

void loop()
{  char c; 
if(Serial.available())  
  {  
   c = Serial.read();  
   if(c=='t')
   readSensor();
  }}
void readSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Nie udało się odczytać z czujnika!");
    return;
  }
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print("Wilgotność: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("\n");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print("*C\n");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print("*C");
}
