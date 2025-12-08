#include "Lys_Sensor.h"

LysSensor::LysSensor(int p) : pin(p) { 
    pinMode(pin, INPUT);
}

int LysSensor::readLight() {
    return analogRead(pin);
}