#include <Arduino.h>

#define POT_PIN 4

int adcValue = 0;
float voltage = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  adcValue = analogRead(POT_PIN);
  String printData = "Nilai data ADC: " + String(adcValue);
  voltage = ((float)adcValue / 4095) * 3.3;
  Serial.println(adcValue);
  Serial.println(voltage);
  delay(1000);
}