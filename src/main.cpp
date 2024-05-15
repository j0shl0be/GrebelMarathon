#include <Arduino.h>
#include "SevSeg.h"

SevSeg sevseg;
const int8_t buttonPin = 2;

int numLaps = 0;

void count();

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  byte numDigits = 4;
  byte digitPins[] = {3,4,5,6};
  byte segmentPins[] = {7, 9, 13, 11, 10, 8, 1};
  bool resisorsOnSement = 0;
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resisorsOnSement);
  sevseg.setBrightness(90);

  attachInterrupt(digitalPinToInterrupt(buttonPin), count, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  sevseg.setNumber(numLaps);
  sevseg.refreshDisplay();
} 

void count(){
  numLaps++;
}