#include <Arduino.h>
byte data[2];
int counter = 0;
unsigned short dataShort;
float realData;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    data[counter] = Serial.read();
    counter++;
    if (counter > 1) {
      counter = 0;
      dataShort = (unsigned short)data[0] << 8;
      dataShort = dataShort | ((unsigned)data[1]);
      realData = (float)dataShort / 100.00;

      String printData = "Nilai sensor" + String(realData);
      Serial.println(printData);
    }
  }
}