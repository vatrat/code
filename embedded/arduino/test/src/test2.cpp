#include "Arduino.h"

int led1 = 6;
int led2 = 9;
int led3 = 10;
int led4 = 11;
int ledDelay = 5000;
int minFreq = 2200;
int maxFreq = 4400;
int duration = 50;
int pwm = 50;

void setup() {
  pinMode(led1, OUTPUT);
  // pinMode(led2, OUTPUT);
  // pinMode(led3, OUTPUT);
  // pinMode(led4, OUTPUT);
}

void loop() {
  analogWrite(led2, random(5,255));
  analogWrite(led3, random(5,255));
  analogWrite(led4, random(5,255));
  analogWrite(led1, HIGH);
  analogWrite(led1, LOW);
  delay(500);
}
