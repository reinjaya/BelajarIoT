#include <Arduino.h>
#define LED_PIN2 4
#define LED_PIN3 16
#define LED_PIN4 17

void setup() {
  // put your setup code here, to run once:
  pinMode(BUILTIN_LED, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char data = Serial.read();

    if (data == '1') {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(2000);
      digitalWrite(LED_BUILTIN, LOW);
    }

    else if (data == '2') {
      digitalWrite(LED_PIN2, HIGH);
      delay(2000);
      digitalWrite(LED_PIN2, LOW);
    }

    else if (data == '3') {
      digitalWrite(LED_PIN3, HIGH);
      delay(2000);
      digitalWrite(LED_PIN3, LOW);
    }

    else if (data == '4') {
      digitalWrite(LED_PIN4, HIGH);
      delay(2000);
      digitalWrite(LED_PIN4, LOW);
    }

    Serial.print("No. LED yang menyala: ");
    Serial.println(data);
  }
}