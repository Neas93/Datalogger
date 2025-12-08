/*<<<<<<< HEAD
#include "Mic.h"
#include <Arduino.h>

MicSensor::MicSensor(int p) : pin(p) {
    pinMode(pin, INPUT);   t
}

// Returnerer true, hvis der registreres lydaktivitet
bool MicSensor::aktivitet() {
    return digitalRead(pin) == HIGH;
}

=======

const int microphonePin = A0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  int mn = 1024;
  int mx = 0;

  for (int i = 0; i < 10000; ++i) {

    int val = analogRead(microphonePin);

    mn = min(mn, val);
    mx = max(mx, val);
  }

  int  = mx - mn;

  Serial.print("Min=");
  Serial.print(mn);
  Serial.print(" Max=");
  Serial.print(mx);
  Serial.print(" Delta=");
  Serial.println(delta);
  
>>>>>>> 39c0c19 (OLED integreret)
*/