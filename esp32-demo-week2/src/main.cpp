#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPin 4
#define DHT_TYPE DHT11

DHT dht(DHTPin, DHT_TYPE);
void updateData();
float temp, humid;
String tempSentence = "Suhu saat ini dalam celcius: ";
String humidSentence = "Humidity saat ini dalam persen: ";
String printData;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  updateData();
  printData = tempSentence + String(temp);
  Serial.println(printData);
  printData = humidSentence + String(humid);
  Serial.println(printData);
  delay(5000);
}

void updateData() {
  temp = dht.readTemperature();
  humid = dht.readHumidity();
}