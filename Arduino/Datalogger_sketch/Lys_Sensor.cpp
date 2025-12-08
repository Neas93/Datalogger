#include "Lys_Sensor.h"

LysSensor::LysSensor(int p) : pin(p)
{ 
    pinMode(pin, INPUT);
}

int LysSensor::readLight()
{
    return analogRead(pin);
}

String LysSensor::getDayOrNight()
{
    int value = readLight();     // filtrer dagtimer vs nattetimer ud fra sensor output
    return (value < 250) ? "Nat" : "Dag";
}