#include <Wire.h>

#define DIN_PIN 4

//SDA on RoboRIO to A4
//SCL on RoboRIO to A5

void setup() {
  Serial.begin(9600);
  Wire.begin(4);
  Wire.onReceive(writeLeds);
}

void loop() {

}

void writeLeds(int bytes){
  int ledCount=bytes/7;
  int colors[ledCount];
  String current="";
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();
}

