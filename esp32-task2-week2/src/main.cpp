#include <Arduino.h>
#define POT_PIN 4
#define LED_PIN1 5
#define LED_PIN2 18
#define LED_PIN3 19
#define LED_PIN4 21

int adcValue;
float temp;

void initLed();
float tempSensor();
void ledOn();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initLed();
}

void loop() {
  // put your main code here, to run repeatedly:
  String printData = "Nilai temperatur: " + String(tempSensor()) + " C";
  Serial.println(printData);
  ledOn();
  delay(2000);
}

void initLed() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);
}

void ledOn() {
  if ( temp < 15) {
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    digitalWrite(LED_PIN4, LOW);
  }

  else if ( temp > 15 && temp < 25) {
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, LOW);
    digitalWrite(LED_PIN4, LOW);
  }

  else if ( temp > 25 && temp < 30) {
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, HIGH);
    digitalWrite(LED_PIN4, LOW);
  }

  else if ( temp > 30) {
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    digitalWrite(LED_PIN4, HIGH);
  }
}

float tempSensor() {
  adcValue = analogRead(POT_PIN);
  temp = ((float)adcValue / 4095) * 100;
  return temp;
}